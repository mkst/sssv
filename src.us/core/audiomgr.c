#include <ultra64.h>
#include <assert.h>
#include "common.h"

#include "audio.h"
#include "simple.h"

u8 bss_padding_audiomgr_c[0xe0fb0];

/****  type define's for structures unique to audiomgr ****/
typedef union {

    struct {
        short     type;
    } gen;

    struct {
        short     type;
        struct    AudioInfo_s *info;
    } done;

    OSScMsg       app;

} AudioMsg;

typedef struct AudioInfo_s {
    /* 0x00 */ short         *data;          /* Output data pointer */
    /* 0x02 */ short         frameSamples;   /* # of samples synthesized in this frame */
    /* 0x04 */ OSScTask      task;           /* scheduler structure */
#ifdef SSSV
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
#endif
    AudioMsg      msg;            /* completion message */
} AudioInfo;

typedef struct {
    Acmd          *ACMDList[NUM_ACMD_LISTS];
    AudioInfo     *audioInfo[NUM_OUTPUT_BUFFERS];
    OSThread      thread;
    OSMesgQueue   audioFrameMsgQ;
    OSMesg        audioFrameMsgBuf[MAX_MESGS];
    OSMesgQueue   audioReplyMsgQ;
    OSMesg        audioReplyMsgBuf[MAX_MESGS];
    ALGlobals     g;
} AMAudioMgr;

typedef struct
{
    ALLink        node;
    u32           startAddr;
    u32           lastFrame;
    char          *ptr;
} AMDMABuffer;

typedef struct
{
    u8            initialized;
    AMDMABuffer   *firstUsed;
    AMDMABuffer   *firstFree;
} AMDMAState;


/**** audio manager globals ****/
OSSched         sc;
OSMesgQueue     *sched_cmdQ;

AMAudioMgr      __am;
static u64      audioStack[AUDIO_STACKSIZE/sizeof(u64)];

AMDMAState      dmaState;
AMDMABuffer     dmaBuffs[NUM_DMA_BUFFERS];
extern u32             audFrameCt; // = 0;
#ifdef SSSV
extern s16             nextDMA; // = 0;
extern s16             curAcmdList; // = 0;
s16             minFrameSize;
s16             frameSize;
s16             maxFrameSize;
#else
u32             nextDMA = 0;
u32             curAcmdList = 0;
u32             frameSize;
u32             minFrameSize;
u32             maxFrameSize;
u32             maxRSPCmds;
#endif


/** Queues and storage for use with audio DMA's ****/
OSIoMesg        audDMAIOMesgBuf[NUM_DMA_MESSAGES]; // NUM_DMA_MESSAGES
OSMesgQueue     audDMAMessageQ;
OSMesg          audDMAMessageBuf[NUM_DMA_MESSAGES]; // NUM_DMA_MESSAGES

/**** private routines ****/
void __amMain(void *arg); // static
s32  __amDMA(s32 addr, s32 len, void *state); // static
ALDMAproc __amDmaNew(AMDMAState **state); // static
u32  __amHandleFrameMsg(AudioInfo *, AudioInfo *); // static
void __amHandleDoneMsg(AudioInfo *); // // static
void __clearAudioDMA(void); // static


#ifdef SSSV
void amCreateAudioMgr(ALSynConfig *c, OSPri pri)
#else
void amCreateAudioMgr(ALSynConfig *c, OSPri pri, amConfig *amc)
#endif
{
#ifdef SSSV
    s32     i;
#else
    u32     i;
#endif
    f32     fsize;

    dmaState.initialized = FALSE;    /* Reset this before the first call to __amDmaNew */

    c->dmaproc    = __amDmaNew;
#ifdef SSSV
    c->outputRate = osAiSetFrequency(32000);
#else
    c->outputRate = osAiSetFrequency(amc->outputRate);
#endif

    /*
     * Calculate the frame sample parameters from the
     * video field rate and the output rate
     */
#ifdef SSSV
    fsize = (f32) 1 * c->outputRate / gRefreshRate;
#else
    fsize = (f32) amc->framesPerField * c->outputRate / (f32) 60;
#endif
    frameSize = fsize;
    if (frameSize < fsize)
        frameSize++;
    if (frameSize & 0xf)
        frameSize = (frameSize & ~0xf) + 0x10;
    minFrameSize = frameSize - 16;
    maxFrameSize = frameSize + EXTRA_SAMPLES + 16;

    alInit(&__am.g, c);

    dmaBuffs[0].node.prev = 0;
    dmaBuffs[0].node.next = 0;
    for (i=0; i<NUM_DMA_BUFFERS-1; i++)
    {
        alLink((ALLink*)&dmaBuffs[i+1],(ALLink*)&dmaBuffs[i]);
        dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, DMA_BUFFER_LENGTH);
    }
    /* last buffer already linked, but still needs buffer */
    dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, DMA_BUFFER_LENGTH);

    for(i=0;i<NUM_ACMD_LISTS;i++)
        __am.ACMDList[i] = (Acmd*)alHeapAlloc(c->heap, 1,
#ifdef SSSV
                            16000);
#else
                            amc->maxACMDSize * sizeof(Acmd));

    maxRSPCmds = amc->maxACMDSize;
#endif

    /**** initialize the done messages ****/
    for (i = 0; i < NUM_OUTPUT_BUFFERS; i++)
    {
        __am.audioInfo[i] = (AudioInfo *)alHeapAlloc(c->heap, 1,
                                                     sizeof(AudioInfo));
        __am.audioInfo[i]->msg.done.type = OS_SC_DONE_MSG;
        __am.audioInfo[i]->msg.done.info = __am.audioInfo[i];
        __am.audioInfo[i]->data = alHeapAlloc(c->heap, 1, 4*maxFrameSize);
    }

    osCreateMesgQueue(&__am.audioReplyMsgQ, __am.audioReplyMsgBuf, MAX_MESGS);
    osCreateMesgQueue(&__am.audioFrameMsgQ, __am.audioFrameMsgBuf, MAX_MESGS);
    osCreateMesgQueue(&audDMAMessageQ, audDMAMessageBuf, NUM_DMA_MESSAGES);

    osCreateThread(&__am.thread, 3, __amMain, 0,
                   (void *)(audioStack+AUDIO_STACKSIZE/sizeof(u64)), pri);
    osStartThread(&__am.thread);
}

s8 more_bss_padding[0x44044];

#if 1
 // requires BSS
void __amMain(void *arg)
{
    u32         validTask;
    u32         done = 0;
    AudioMsg    *msg;
    AudioInfo   *lastInfo = 0;
    OSScClient  client;
#ifdef SSSV
    static s16  errorCount; // D_8028654C
#endif

    osScAddClient(&sc, &client, &__am.audioFrameMsgQ);
#ifdef SSSV
    errorCount = 0;
#endif

    while (!done)
    {
#ifdef SSSV
        if (errorCount != 0) {
            errorCount = (s16) (errorCount + 1);
        }
        if (errorCount > 20) {
            done = 1;
        }
#endif
        (void) osRecvMesg(&__am.audioFrameMsgQ, (OSMesg *)&msg, OS_MESG_BLOCK);

        switch (msg->gen.type)
        {
            case (OS_SC_RETRACE_MSG):
                validTask = __amHandleFrameMsg(__am.audioInfo[audFrameCt % 3],
                                               lastInfo);
                if(validTask)
                {
                    /* wait for done message */
                    osRecvMesg(&__am.audioReplyMsgQ, (OSMesg *)&msg,
                               OS_MESG_BLOCK);
                    __amHandleDoneMsg(msg->done.info);
                    lastInfo = msg->done.info;
                }
                break;

            case (OS_SC_PRE_NMI_MSG):
                /* what should we really do here? quit? ramp down volume? */
#ifdef SSSV
                errorCount = 1;
#endif
                break;

            case (QUIT_MSG):
                done = 1;
                break;

            default:
                break;
        }
    }

    alClose(&__am.g);
#ifdef SSSV
    do {} while (TRUE);
#endif
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/__amMain.s")
#endif

u32 __amHandleFrameMsg(AudioInfo *info, AudioInfo *lastInfo)
{
    s16 *audioPtr;
    Acmd *cmdp;
    s32 cmdLen;
    int samplesLeft = 0;
    OSScTask *t;
#ifdef SSSV
    s32 pad[2];
#endif

    __clearAudioDMA(); /* call once a frame, before doing alAudioFrame */

    audioPtr = (s16 *) osVirtualToPhysical(info->data);

    if (lastInfo)
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples<<2);


    /* calculate how many samples needed for this frame to keep the DAC full */
    /* this will vary slightly frame to frame, must recalculate every frame */
    samplesLeft = osAiGetLength() >> 2; /* divide by four, to convert bytes */
                                        /* to stereo 16 bit samples */
    info->frameSamples = 16 + (frameSize - samplesLeft + EXTRA_SAMPLES)& ~0xf;
    if(info->frameSamples < minFrameSize)
        info->frameSamples = minFrameSize;

    cmdp = alAudioFrame(__am.ACMDList[curAcmdList], &cmdLen, audioPtr,
                        info->frameSamples);

    if(cmdLen == 0)  /* no task produced, return zero to show no valid task */
        return 0;

    t = &info->task;

    t->next      = 0;                    /* paranoia */
    t->msgQ      = &__am.audioReplyMsgQ; /* reply to when finished */
    t->msg       = (OSMesg)&info->msg;   /* reply with this message */
    t->flags     = OS_SC_NEEDS_RSP;

    t->list.t.data_ptr    = (u64 *) __am.ACMDList[curAcmdList];
    t->list.t.data_size   = (cmdp - __am.ACMDList[curAcmdList]) * sizeof(Acmd);
    t->list.t.type  = M_AUDTASK;
    t->list.t.ucode_boot = (u64 *)rspbootTextStart;
    t->list.t.ucode_boot_size =
        ((int) rspbootTextEnd - (int) rspbootTextStart);
#ifdef SSSV
    t->list.t.flags = 0;
#else
    t->list.t.flags = OS_TASK_DP_WAIT;
#endif
    t->list.t.ucode = (u64 *) aspMainTextStart;
    t->list.t.ucode_data = (u64 *) aspMainDataStart;
    t->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t->list.t.dram_stack = (u64 *) NULL;
    t->list.t.dram_stack_size = 0;
    t->list.t.output_buff = (u64 *) NULL;
    t->list.t.output_buff_size = 0;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;

#ifdef SSSV
    osSendMesg(osScGetCmdQ(&sc), (OSMesg) &t->next, OS_MESG_BLOCK);
#else
    osSendMesg(sched_cmdQ, (OSMesg) t, OS_MESG_BLOCK);
#endif
    curAcmdList ^= 1; /* swap which acmd list you use each frame */

    return 1;
}

#if 0
// .data
void __amHandleDoneMsg(AudioInfo *info)
{
    s32    samplesLeft;
    static int firstTime = 1;

    samplesLeft = osAiGetLength()>>2;
    if (samplesLeft == 0 && !firstTime)
    {
        PRINTF("audio: ai out of samples\n");
        firstTime = 0;
    }
}
#else
void __amHandleDoneMsg(AudioInfo *info) {
    s32 *tmp = &D_8015518C;
    if (((osAiGetLength() >> 2) == 0) && (*tmp == 0)) {
        *tmp = 0;
    }
}
#endif

s32 __amDMA(s32 addr, s32 len, void *state)
{
    void            *foundBuffer;
    s32             delta, addrEnd, buffEnd;
    AMDMABuffer     *dmaPtr, *lastDmaPtr;

    lastDmaPtr = 0;
    dmaPtr = dmaState.firstUsed;
    addrEnd = addr+len;

    /* first check to see if a currently existing buffer contains the
       sample that you need.  */

    while(dmaPtr)
    {
        buffEnd = dmaPtr->startAddr + DMA_BUFFER_LENGTH;
        if(dmaPtr->startAddr > addr) /* since buffers are ordered */
            break;                   /* abort if past possible */

        else if(addrEnd <= buffEnd) /* yes, found a buffer with samples */
        {
            dmaPtr->lastFrame = audFrameCt; /* mark it used */
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return (int) osVirtualToPhysical(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (AMDMABuffer*)dmaPtr->node.next;
    }

    /* get here, and you didn't find a buffer, so dma a new one */

    /* get a buffer from the free list */
    dmaPtr = dmaState.firstFree;

    /*
     * if you get here and dmaPtr is null, send back the a bogus
     * pointer, it's better than nothing
     */
    if(!dmaPtr)
        return osVirtualToPhysical(dmaState.firstUsed);

    dmaState.firstFree = (AMDMABuffer*)dmaPtr->node.next;
    alUnlink((ALLink*)dmaPtr);

    /* add it to the used list */
    if(lastDmaPtr) /* if you have other dmabuffers used, add this one */
    {              /* to the list, after the last one checked above */
        alLink((ALLink*)dmaPtr,(ALLink*)lastDmaPtr);
    }
    else if(dmaState.firstUsed) /* if this buffer is before any others */
    {                           /* jam at begining of list */
        lastDmaPtr = dmaState.firstUsed;
        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = (ALLink*)lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink*)dmaPtr;
    }
    else /* no buffers in list, this is the first one */
    {
        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 0x1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = audFrameCt;  /* mark it */
    osPiStartDma(&audDMAIOMesgBuf[nextDMA++], OS_MESG_PRI_NORMAL, OS_READ,
                 (u32)addr, foundBuffer, DMA_BUFFER_LENGTH, &audDMAMessageQ);

    return (int) osVirtualToPhysical(foundBuffer) + delta;
}


ALDMAproc __amDmaNew(AMDMAState **state)
{
    int         i;

    if(!dmaState.initialized)  /* only do this once */
    {
        dmaState.firstUsed = 0;
        dmaState.firstFree = &dmaBuffs[0];
        dmaState.initialized = 1;
    }

    *state = &dmaState;  /* state is never used in this case */

    return __amDMA;
}

void __clearAudioDMA(void)
{
    u32          i;
    OSIoMesg     *iomsg;
    AMDMABuffer  *dmaPtr,*nextPtr;

    /*
     * Don't block here. If dma's aren't complete, you've had an audio
     * overrun. (Bad news, but go for it anyway, and try and recover.
     */
    for (i=0; i<nextDMA; i++)
    {
        if (osRecvMesg(&audDMAMessageQ,(OSMesg *)&iomsg,OS_MESG_NOBLOCK) == -1)
            PRINTF("Dma not done\n");

#ifndef _FINALROM
        if (logging)
            osLogEvent(log, 17, 2, iomsg->devAddr, iomsg->size);
#endif
    }

    dmaPtr = dmaState.firstUsed;
    while(dmaPtr)
    {
        nextPtr = (AMDMABuffer*)dmaPtr->node.next;

        /* remove old dma's from list */
        /* Can change FRAME_LAG value.  Should be at least one.  */
        /* Larger values mean more buffers needed, but fewer DMA's */
        if(dmaPtr->lastFrame + FRAME_LAG  < audFrameCt)
        {
            if(dmaState.firstUsed == dmaPtr)
                dmaState.firstUsed = (AMDMABuffer*)dmaPtr->node.next;
            alUnlink((ALLink*)dmaPtr);
            if(dmaState.firstFree)
                alLink((ALLink*)dmaPtr,(ALLink*)dmaState.firstFree);
            else
            {
                dmaState.firstFree = dmaPtr;
                dmaPtr->node.next = 0;
                dmaPtr->node.prev = 0;
            }
        }
        dmaPtr = nextPtr;
    }

    nextDMA = 0;  /* reset */
    audFrameCt++;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/initialise_audio.s")

#ifdef NON_MATCHING
// CURRENT (130)
void func_80132044(s32 arg0) {
    s32 i;

    if (!gAudioInitialized) {
        return;
    }

    if (arg0 == -1) {
        // clear all
        for (i = 0; i < 20; i++){
            D_80286388[i] = i;
            D_802863B0[i] = 0;
        }
        D_8015468C = 0;
    } else {
        // decrement used?
        D_80286388[arg0] = arg0;
        D_8015468C--;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_80132044.s")
#endif

struct017 *func_801320EC(void) {
    s32 i;

    if (gAudioInitialized == 0) {
        return NULL;
    }
    if (D_8015468C > 20) {
        return NULL;
    }

    for (i = 0; i < 20; i++) {
        if (D_80286388[i] != -1) {
            D_80286388[i] = -1;
            break;
        }
    }
    D_80286338[i]->unk1E = i;
    return D_80286338[i];
}

#if 0
// need to figure out struct copy business
void func_80132174(struct017 *arg0, s32 arg1, s32 arg2, s32 arg3, struct017 **argD, struct017 **argE) {
    struct017 *var_t8;
    struct017 *temp_v0_2;
    struct017 *var_a0;
    struct017 *var_t2;
    struct017 *var_v1;

    if (!gAudioInitialized) {
      return;
    }

    var_a0 = *argD;

    if (D_8015468C < 0x14) {
        D_8015468C++;
        temp_v0_2 = func_801320EC();

        if (temp_v0_2 != NULL) {
            var_t8 = &arg0;
            var_t2 = temp_v0_2;
            do {
                // copy 12 bytes of something?
            //     temp_at = *var_t8;
            //     var_t8 += 0xC;
            //     var_t2 += 0xC;
            //     var_t2->unk-C = temp_at;
            //     var_t2->unk-8 = (s32) var_t8->unk-8;
            //     var_t2->unk-4 = (s32) var_t8->unk-4;
            } while (var_t8 != var_t8->next);

            var_t2->unk0 = var_t8->unk0;
            temp_v0_2->unk1E = temp_v0_2->unk1E;

            if (*argE == NULL) {
                temp_v0_2->next = NULL;
                temp_v0_2->prev = NULL;
                *argE = temp_v0_2;
                *argD = temp_v0_2;
                return;
            }

            var_v1 = NULL;
            while (var_a0 != NULL) {
                var_v1 = var_a0;
                if ((var_a0->unk0 - temp_v0_2->unk0) < 0) {
                    var_a0 = var_a0->next;
                } else {
                    if (var_a0->prev != NULL) {
                        // prepend node
                        var_a0->prev->next = temp_v0_2;
                        temp_v0_2->next = var_a0;
                        temp_v0_2->prev = var_a0->prev;
                        var_a0->prev = temp_v0_2;
                    } else if ((temp_v0_2->sndID == var_a0->sndID) && (var_a0->sndSlot == -1)) {
                        func_80132044(temp_v0_2->unk1E);
                    } else {
                        // append node
                        temp_v0_2->next = var_a0;
                        temp_v0_2->prev = NULL;
                        var_a0->prev = temp_v0_2;
                        *argD = temp_v0_2;
                    }
                    return;
                }
            }
            // uhh?
            var_v1->next = temp_v0_2;
            temp_v0_2->next = NULL;
            temp_v0_2->prev = var_v1;
            *argE = temp_v0_2;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_80132174.s")
#endif

void func_801322EC(struct017 *arg0, struct017 **arg1, struct017 **arg2) {

    if (gAudioInitialized == 0) {
        return;
    }

    if (arg0 != NULL) {
        func_80132044(arg0->unk1E);
        if (arg0 == *arg1) {
            *arg1 = arg0->next;
            if (*arg1 != NULL) {
                (*arg1)->prev = NULL;
            } else {
                *arg2 = NULL;
            }
        } else {
            arg0->prev->next = arg0->next;
            if (arg0 != *arg2) {
                arg0->next->prev = arg0->prev;
            } else {
                *arg2 = arg0->prev;
            }
        }
    }
}

void func_80132394(void) {
    struct017 *snd;
    for (snd = D_8028631C; snd != NULL; snd = snd->next);
}

struct017 *get_sound_by_slot(s16 slot) {
    struct017 *snd;

    if (gAudioInitialized == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (slot == snd->sndSlot) {
            return snd;
        }
    }
    return NULL;
}

struct017 *get_sound_by_id(u16 id) {
    struct017 *snd;

    if (gAudioInitialized == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (id == snd->sndID) {
            return snd;
        }
    }
    return NULL;
}

struct017 *func_80132474(void) {
    struct017 *snd;
    struct017 *lastSnd;
    u16 tmp;

    if (gAudioInitialized == 0) {
        return NULL;
    }

    start:

    lastSnd = NULL;
    tmp = 0; // priority?

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (snd->sndSlot == -1) {
            if ((D_80241D0E - snd->unk10) >= 16) {
                func_801322EC(snd, &D_8028631C, &D_80286320);
                goto start;
            }
            if ((lastSnd == NULL) || (snd->unk10 < tmp)) {
                lastSnd = snd;
                tmp = snd->unk10;
            }
        }
    }

    return lastSnd;
}

// used?
struct017 *func_80132568(void) {
    // FIXME: fakematch shenanigans
    struct017* foo;
    struct017** bar;

    bar = &foo;
    foo = &D_80286320;

    D_8028631C = D_80286320 = NULL;

    if (1) {}
    return *bar;
}

struct017 *func_80132580(s32 arg0, s16 id) {
    struct017 *snd;

    if (gAudioInitialized == 0) {
        return NULL;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if ((arg0 == snd->unk28) && (id == snd->sndID)) {
            return snd;
        }
    }
    return NULL;
}

// load_sequence_array ?
void func_801325E8(s32 seqArrayIndex, s8 destIndex) {
    s32 offset;
    s16 length;

    if (gAudioInitialized == 0) {
        return;
    }

    offset = D_8028630C->seqArray[seqArrayIndex].offset;
    length = D_8028630C->seqArray[seqArrayIndex].len;

    // align to 2 bytes
    if (length & 1) {
        length += 1;
    }

    osWritebackDCacheAll();
    dma_read(offset, D_80286314[destIndex], length);
}

// get_seqp_state
s32 func_8013266C(s8 arg0) {
    if (gAudioInitialized == 0) {
        return 0;
    }
    return D_802863C8[arg0]->state;
}

#ifdef NON_MATCHING // JUSTREG
void func_801326A8(s8 arg0, s8 arg1) {
    s32 pad;
    if (gAudioInitialized == 0) {
        return;
    }

    if (func_8013266C(arg1) == 0) {
        s16 volume;
        func_801325E8(arg0, arg1);
        alSeqpSetBank(D_802863C8[arg1], D_802862F8->bankArray[0]);
        alCSeqNew(D_802863CC[arg1], D_80286314[arg1]);
        alSeqpSetSeq(D_802863C8[arg1], (ALSeq*)D_802863CC[arg1]);
        if (D_801546A8[arg1] == 0) {
            volume = D_801550F8[arg0] * gMusicVolume * D_8015517C;
        } else {
            volume = ((D_801546B4[arg1] * D_801550F8[D_8015516C[arg1]]) +
                      ((D_801546B8[arg1] * (D_801550F8[D_8015516C[arg1]] * D_801546AC[arg1])) / D_801546B0[arg1])) * gMusicVolume * D_8015517C;
        }

        alSeqpSetVol(D_802863C8[arg1], volume * (2048.0f / D_801546D8));
        alSeqpPlay(D_802863C8[arg1]);

        D_80155168[arg1] = 1;
        D_8015516C[arg1] = arg0;
        D_801546E4 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_801326A8.s")
#endif

// wrong args to alSndpAllocate
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_801328F8.s")
// void func_801328F8(void) {
//     s16 temp_v1;
//     s32 used;
//     s16 slot;
//     f32 temp_f12;
//     struct017 *snd;
//     s16 vol;
//     s16 i;
//     s16 phi_s1_2;
//     f64 phi_f0;
//
//     if (gAudioInitialized == 0) {
//         return;
//     }
//
//     D_80241D0E += 1;
//     used = func_80132D84(D_80286310);
//
//     if (used < 8) {
//         temp_v1 = 8 - used;
//         for (i = 0; i < temp_v1; i++) {
//             snd = func_80132474();
//             if (snd != 0) {
//                 // ALSndId alSndpAllocate(ALSndPlayer *sndp, ALSound *sound);
//                 // ((D_80286300 + (snd->sndID * 4))->unkC + (snd->unk1C * 4))->unk10
//                 snd->sndSlot = alSndpAllocate(D_80286310, ((struct011*)(D_80286300->unkC[snd->sndID] + snd->unk1C*4))->sound);
//                 if (snd->sndSlot >= 0) {
//                     D_802863B0[snd->sndSlot] = 1;
//                     snd->unk20 = D_80241D0E;
//                     alSndpSetSound(D_80286310, snd->sndSlot);
//                     alSndpSetPitch(D_80286310, snd->sndPitch);
//                     if (D_801546BC == 1) {
//                         vol = (((snd->sndVolume * D_801546C8) + ((D_801546CC * (snd->sndVolume * D_801546C0)) / D_801546C4)) * gSfxVolume);
//                     } else {
//                         vol = (snd->sndVolume * gSfxVolume);
//                     }
//                     alSndpSetVol(D_80286310, vol);
//                     alSndpSetFXMix(D_80286310, D_80155178);
//                     alSndpPlay(D_80286310);
//                     snd->sndState = 9;
//                 }
//             }
//         }
//     }
//     phi_s1_2 = 0;
//     do {
//         if (D_801546A8[phi_s1_2] != 0) {
//             func_801338A8(phi_s1_2);
//         }
//         phi_s1_2++;
//     } while (phi_s1_2 <= 0);
//
//     if (D_801546BC != 0) {
//         func_801339F8();
//     }
//     if (D_801546DC != D_801546D8) {
//         D_801546DC = D_801546D8;
//         func_80133C50();
//     } else {
//         if (D_8015529C != D_8015517C) {
//             // just an ABS?
//             temp_f12 = D_8015517C - D_8015529C;
//             phi_f0 = temp_f12;
//             D_80286554 = temp_f12;
//             if (phi_f0 < 0) {
//                 D_80286554 = (phi_f0 * -1.0);
//             }
//             if (0.01 < phi_f0) { // D_8015AE08
//                 func_80133C50();
//                 D_8015529C = D_8015517C;
//             }
//         }
//     }
//     if (D_8028645C != D_80155188) {
//         D_80155188 = D_8028645C;
//         if (D_8028645C == 0) {
//             // stop / reset
//             func_8013364C();
//         } else {
//             func_801337BC(D_8028645C, 1);
//         }
//     }
// }

void func_80132C48(s8 idx) {
    ALSeqPlayer *seqp;

    if (gAudioInitialized == 0) {
        return;
    }

    seqp = D_802863C8[idx];
    if (seqp->state == 0) {
        D_80155168[idx] = 0;
    } else {
        alSeqpStop(seqp);
        D_80155168[idx] = 0;
    }
}

// more audio funcs

void func_80132CC0(s32 arg0) {
    struct017 *snd = D_8028631C;
    rmonPrintf("----------------- Active sounds\n");

    while (snd != NULL) {
        rmonPrintf("sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d.\n",
            snd->sndState, snd->sndSlot, snd->sndID, snd->unk28, snd->counter, D_802863B0[snd->sndSlot]);
        snd = snd->next;
    }
}

s16 get_used_sound_count(void) {
    struct017 *snd;
    s16 cnt = 0;

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        cnt++;
    }
    return cnt;
}

s32 func_80132D84(ALSndPlayer *sndp) {
    struct017 *snd;
    s16 used = 0;

    if (gAudioInitialized == 0) {
        return 8;
    }

    for (snd = D_8028631C; snd != NULL; snd = snd->next) {
        if (snd->sndSlot < 0) {
            if (snd->sndSlot == -2) {
                func_801322EC(snd, &D_8028631C, &D_80286320);
            }
        } else {
            alSndpSetSound(sndp, snd->sndSlot);
            if (alSndpGetState(sndp) != 0) {
                if (snd->unk28 != 0) {
                    snd->counter -= 1;
                    if (snd->counter == 0) {
                        func_80133608(snd->sndSlot);
                        snd->unk28 = 0;
                    }
                }
                used += 1;
                if (snd->sndState == 9) {
                    snd->sndState = 1U;
                }
                D_802863B0[snd->sndSlot] = 0;
            } else if (D_802863B0[snd->sndSlot] == 0) {
                if (alSndpGetState(sndp) == 0) {
                    alSndpDeallocate(sndp, snd->sndSlot);
                    if (snd->sndState == 9) {
                        snd->sndSlot = -1;
                        snd->sndState = 0U;
                    } else {
                        func_801322EC(snd, &D_8028631C, &D_80286320);
                    }
                }
            } else {
                if (((D_80241D0E - snd->unk20) & 0xFFFF) >= 7) {
                    if (alSndpGetState(sndp) == 0) {
                        alSndpDeallocate(sndp, snd->sndSlot);
                        func_801322EC(snd, &D_8028631C, &D_80286320);
                    }
                }
            }
        }
    }
    return used;
}
#if 1
typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s8  unk4;
    /* 0x8 */ f32 unk8;
} myStructInner; // size 0xC

typedef struct {
    myStructInner sp50[5]; // size 0xC
    s16 sp5C;
    u8  pad5E[0x2];
    u16 sp60;
    u8  pad62[0x2];
    s16 sp64;
    u8  pad66[0x2];
    s32 sp68;
    s32 sp6C;
    s16 sp72;
    u8  sp74[0x6];
    s32 sp78;
} myStruct;

extern myStructInner D_80154C4C[100]; // sound effect pointers?
#endif

// void func_80132174(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void **argD, void **argE);
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_80132F70.s")
// called with (0x56, 0x5000)
// pure nonsense
// void func_80132F70(s16 arg0, s32 arg1) {
//     myStruct tmp;
//     s32 i;
//
//     if (gAudioInitialized == 0) {
//         return;
//     }
//
//     if (arg0 != 10000) {
//         f32 tmpf = D_801546E8[arg0];
//         tmp.sp64 = 0;
//         tmp.sp68 = 0;
//         tmp.sp6C = 0;
//         tmp.sp50[0].unk0 = D_80154C4C[arg0].unk0;
//         tmp.sp50[0].unk2 = arg0;
//         tmp.sp50[0].unk4 = 64;
//         tmp.sp50[0].unk8 = tmpf;
//         if (!(tmpf > 2.0f)) {
//             tmp.sp78 = 0;
//             tmp.sp72 = -1;
//             tmp.sp5C = arg1;
//             tmp.sp60 = D_80241D0E;
//
//             for (i = 0; i < 2; i++) {
//                 tmp.sp50[i] = tmp.sp50[i+1];
//             }
//             // tmp.sp50[i].unk0 = tmp.sp50[i+1].unk0;
//             // subroutine_arg0, subroutine_arg1, subroutine_arg2, subroutine_arg3, &D_8028631C, &D_80286320
//             func_80132174(tmp.sp50[0].unk0, tmp.sp50[0].unk2, tmp.sp50[0].unk4, tmp.sp50[0].unk8, &D_8028631C, &D_80286320);
//         }
//     }
// }

// void play_sound_effect(s16 id, s16 arg1, s16 arg2, f32 speed, u8 arg4);
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/play_sound_effect.s")

// unused? absolutely no idea how to decomp
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_80133188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_8013328C.s")

// unused?
void func_80133528(u8 id, s16 vol) { // play_sound_by_id_with_volume
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpSetVol(D_80286310, vol);
        }
    }
}

// unused?
void func_8013359C(u8 id) { // play_sound_by_id
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpStop(D_80286310);
        }
    }
}

// used
void func_80133608(s16 slot) { // play_sound_by_slot
    if (slot >= 0) {
        alSndpSetSound(D_80286310, slot);
        alSndpStop(D_80286310);
    }
}

// used
void func_8013364C(void) {
    s8 i;
    for (i = 0; i < 1; i++) {
        if ((u8)(D_80155168[i] = 1)) { // makes no sense?
            alSeqpStop(D_802863C8[i]);
            D_80155168[i] = 0U;
          }

        D_80154690[i] = 0;
        D_80155164[i] = -1;
    }

    D_80286458 = 1;
    D_8015515C = -1;
    D_80155170 = -1;
    D_80155188 = -99;
}

void stop_all_sounds(void) {
    s8 i;

    if (gAudioInitialized) {
        for (i = 0; i < 20; i++) {
            if (get_sound_by_slot(i)) {
                alSndpStop(D_80286310);
            }
        }
        func_8013364C();
        D_8028645C = (u16)0;
    }
}

void func_801337BC(s8 arg0, s32 arg1) {
    D_801552A8 = 1;
    D_80155164[0] = arg0;
}

void func_801337DC(s16 idx, f32 arg1, f32 arg2, f32 arg3) {
    if (idx <= 0) {
        D_801546AC[idx] = arg1;
        D_801546B0[idx] = arg1;
        D_801546B4[idx] = arg3 / 20.0f;
        D_801546B8[idx] = (arg2 - arg3) / 20.0f;
        D_801546A8[idx] = 1;
    }
}

void func_8013385C(f32 arg0, f32 arg1, f32 arg2)
{
    D_801546C0 = arg0;
    D_801546C4 = arg0;
    D_801546C8 = arg2 / 20.0f;
    D_801546CC = (arg1 - arg2) / 20.0f;
    D_801546BC = 1;
}

void func_801338A8(s16 arg0) {
    f32 tmp;

    if (((u8)D_80155168[arg0] == 1) && (D_801546A8[arg0] == 1)) {
        tmp = D_801550F8[D_8015516C[arg0]];
        alSeqpSetVol(D_802863C8[arg0],
            ((D_801546B4[arg0] * tmp) + ((D_801546B8[arg0] * (tmp * D_801546AC[arg0])) / D_801546B0[arg0])) * gMusicVolume * D_8015517C);
    }

    if (0.0f == D_801546AC[arg0]) {
        D_801546A8[arg0] = 0;
    } else {
        D_801546AC[arg0] -= 1.0f;
    }
}

void func_801339F8(void) {
    s16 vol;
    struct017 *snd;

    if (gAudioInitialized != 0) {
        for (snd = D_8028631C; snd != NULL; snd = snd->next) {
            if ((snd->sndSlot >= 0) && (D_801546BC == 1)) {
                vol = ((snd->sndVolume * D_801546C8) + ((D_801546CC * (snd->sndVolume * D_801546C0)) / D_801546C4)) * gSfxVolume;
                alSndpSetSound(D_80286310, snd->sndSlot);
                alSndpSetVol(D_80286310, vol);
            }
        }

        if (D_801546C0 == 0.0f) {
            D_801546BC = 0;
        } else {
            D_801546C0 -= 1.0f;
        }
    }
}

void set_sfx_volume(s16 arg0) {
    gSfxVolume = arg0 / 20.0f;
}

void set_music_volume(s16 arg0) {
    gMusicVolume = arg0 / 20.0f;
    func_80133C50();
}

void func_80133BE4(void) {
    ALSndPlayer *sndp;
    struct017 *snd;

    if (gAudioInitialized != 0) {
        for (snd = D_8028631C; snd != NULL; snd = snd->next) {
            if (snd->sndSlot >= 0) {
                alSndpSetSound(sndp, snd->sndSlot);
                alSndpGetState(sndp);
            }
        }
    }
}

#ifdef NON_MATCHING // (almost) JUSTREG
void func_80133C50(void) {
    float tmp;
    s16 i;
    s16 volume;

    for (i = 0; i < 1; i++) {
        if ((D_8015516C[i] != 1) && ((u8)D_80155168[i] == -1)) {
            tmp = 2048.0f / D_801546D8;

            if (D_801546A8[i] == 1) {
                volume = ((D_801546B4[i] * D_801550F8[D_8015516C[i]]) + ((D_801546B8[i] * (D_801550F8[D_8015516C[i]] * D_801546AC[i])) / D_801546B0[i])) * gMusicVolume * D_8015517C;
            } else {
                volume = D_801550F8[D_8015516C[i]] * (D_8015517C * gMusicVolume);
            }

            volume = tmp * volume;
            alSeqpSetVol(D_802863C8[i], volume);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_80133C50.s")
#endif

void func_80133E44(void) {
    alCSeqGetLoc(D_802863CC[0], &D_80286460);
    D_80155180 = D_8028645C;
    D_80155184 = 0;
}

void func_80133E84(void) {
    if ((D_80155180 == D_8028645C) && (D_8028645C != 0)) {
        if (++D_80155184 >= 3) {
            alCSeqSetLoc(D_802863CC[0], &D_80286460);
            D_80155180 = 0;
        }
    }
}
