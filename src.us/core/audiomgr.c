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

#if 0

s16 D_8015468C = 0;
u8  D_80154690[24] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};
u8  D_801546A8[1] = {0};
f32 D_801546AC[1] = {0};
f32 D_801546B0[1] = {0};
f32 D_801546B4[1] = {0};
f32 D_801546B8[1] = {0};
u8  D_801546BC[1] = {0};
f32 D_801546C0 = 0;
f32 D_801546C4 = 0;
f32 D_801546C8 = 0;
f32 D_801546CC = 0;
f32 gMusicVolume = 1.0f;
f32 gSfxVolume = 1.0f;
s16 D_801546D8 = 2048;
s16 D_801546DC = 2048;
s16 D_801546E0 = 0;
s32 D_801546E4 = 0;
#include "pitch.h" // D_801546E8
#include "unk0.h"  // D_80154C4C
#include "volume.h" // D_801550F8
s32 gAudioInitialized = 0;
s32 D_80155158 = -1;
s32 D_8015515C = -1;
s32 D_80155160 = -0;
s8  D_80155164[1] = {-1}; //, 0, 0, 0};
u8  D_80155168[1] = {0}; //, 0, 0, 0};
s16 D_8015516C = -1;
//8015516E ?
s8  D_80155170 = -1;
s8  D_80155174 = -1;
u8  D_80155178 = 0;
f32 D_8015517C = 0;
s16  D_80155180 = 0;
s16  D_80155184 = 0;
s16  D_80155188 = -99;
s32  D_8015518C = 1;
// D_80155190[] = {};
// f32  D_8015529C = 110.0f;
f32  D_801552A0 = 0.0f;
f32  D_801552A4 = 0.0f;
u16  D_801552A8 = 100;
u8   D_801552B0 = 0;
u8   D_801552B4 = 0;
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

#ifdef NON_MATCHING

void initialise_audio(s32 *arg0) {
    s32 pad2[2];
    ALSynConfig synConfig;   // sp1EC
    ALSndpConfig sndpConfig; // sp1E0
    ALSeqpConfig sp170[4];
    u8 **var_s0_3;
    s32 i;
    s16 maxSeqArrayLen;
    s32 seqCount;
    s32 pad[4];
    struct121 params; // sp48
    int seqBytesNeeded;

    // struct copy
    params = D_80155190;

    gAudioInitialized = 1;

    for (i = 0; i < (AUDIO_HEAP_SIZE / 4); i++) {
        D_80242508[i] = 0;
    }
    alHeapInit(&D_80286328, D_80242508, AUDIO_HEAP_SIZE);

    D_802862F8 = (ALBankFile *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, alTable1_bin - alBankFile1_bin);
    dma_read(alBankFile1_bin, D_802862F8, alTable1_bin - alBankFile1_bin);
    if ((var_s0_3 && var_s0_3) && var_s0_3) {};
    alBnkfNew(D_802862F8, alTable1_bin);

    D_802862FC = (ALBankFile *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, alTable2_bin - alBankFile2_bin);
    dma_read(alBankFile2_bin, D_802862FC, alTable2_bin - alBankFile2_bin);
    alBnkfNew(D_802862FC, alTable2_bin);

    D_80286300 = D_802862FC->bankArray[0];
    D_80286304 = D_802862F8->bankArray[0];

    synConfig.maxVVoices = 0x18;
    synConfig.maxPVoices = 0x14;
    synConfig.maxUpdates = 0xB4;
    synConfig.dmaproc = NULL;
    synConfig.fxType = 6;
    synConfig.outputRate = osAiSetFrequency(32000);
    synConfig.heap = &D_80286328;
    synConfig.params = &params;
    amCreateAudioMgr(&synConfig, /* priority */ 12);

    for (i = 0; i < 4; i++) {
        sp170[i].maxVoices = MAX_VOICES;
        sp170[i].maxEvents = 0x100;
        sp170[i].maxChannels = 0x10;
        sp170[i].heap = &D_80286328;
        sp170[i].initOsc = NULL;
        sp170[i].updateOsc = NULL;
        sp170[i].stopOsc = NULL;

        D_802863C8[i] = (ALCSPlayer *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, sizeof(ALCSPlayer));
        alCSPNew(D_802863C8[i], &sp170[i]);
        D_802863C8[i]->state = 0;

        D_802863CC[i] = (ALCSeq *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, sizeof(ALCSeq));
    }

    sndpConfig.maxSounds = 8;
    sndpConfig.maxEvents = 0x100;
    sndpConfig.heap = &D_80286328;
    D_80286310 = alHeapDBAlloc(NULL, 0, &D_80286328, 1, sizeof(ALSndPlayer));
    alSndpNew(D_80286310, &sndpConfig);

    for (i = 0; i < 20; i++) {
        D_80286338[i] = (struct017 *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, sizeof(struct017));
    }

    D_80286320 = D_8028631C = NULL;

    func_80132044(-1);

    D_80286308 = (ALSeqFile *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, 4); // allocations are aligned to 16 bytes
    // if (i && i) {};
    osWritebackDCacheAll();
    dma_read(alSeqFile_bin, D_80286308, 8);

    seqBytesNeeded = (D_80286308->seqCount << 3) + 4;

    if (!seqBytesNeeded) {};

    D_8028630C = (ALSeqFile *) alHeapDBAlloc(NULL, 0, &D_80286328, 1, (s16)seqBytesNeeded);
    osWritebackDCacheAll();
    dma_read(alSeqFile_bin, D_8028630C, (s16)seqBytesNeeded);
    alSeqFileNew(D_8028630C, alSeqFile_bin);

    if (!D_8028630C->seqArray[seqCount].len) {};

    maxSeqArrayLen = 0;
    for (seqCount = 0; seqCount < D_8028630C->seqCount; seqCount++) {
        if (maxSeqArrayLen < D_8028630C->seqArray[seqCount].len) {
            maxSeqArrayLen = D_8028630C->seqArray[seqCount].len;
        }
    }
    // align to 2 bytes
    if (maxSeqArrayLen & 1) {
        maxSeqArrayLen += 1;
    }
    for (i = 0; i < 1; i++) {
        D_80286314[i] = alHeapDBAlloc(NULL, 0, &D_80286328, 1, maxSeqArrayLen);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/initialise_audio.s")
#endif

#ifdef NON_MATCHING
// CURRENT (130)
void func_80132044(s32 arg0) {
    s32 i;

    if (gAudioInitialized == 0) {
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
// CURRENT (835)
void func_80132174(struct struct017 arg0, struct017 **arg1, struct017 **arg2) {
    s32 pad;
    struct017 *temp_a0;
    struct017 *cur;
    struct017 *var_a0;
    struct017 *prev_node;

    if (gAudioInitialized == 0) {
        return;
    }

    temp_a0 = *arg1;

    if (D_8015468C < 20) {
        D_8015468C++;
        cur = func_801320EC();
        if (cur != NULL) {
            // struct copy
            *cur = arg0;
            cur->unk1E = cur->unk1E; // help


            if (*arg2 == NULL) {
                cur->next = NULL;
                cur->prev = NULL;
                *arg2 = cur;
                *arg1 = cur;
                return;
            }

            var_a0 = temp_a0;
            prev_node = NULL;

            // shuffle some nodes about?
            while (var_a0 != NULL) {
                prev_node = var_a0;
                if ((var_a0->unk0 - cur->unk0) < 0) {
                    var_a0 = var_a0->next;
                } else  {
                    if (var_a0->prev != NULL) {
                        // insert
                        var_a0->prev->next = cur;
                        cur->next = var_a0;
                        cur->prev = var_a0->prev;
                        var_a0->prev = cur;
                    } else if ((cur->sndID == var_a0->sndID) && (var_a0->sndSlot == -1)) {
                        func_80132044(cur->unk1E);
                    } else {
                        cur->next = var_a0;
                        cur->prev = NULL;
                        var_a0->prev = cur;
                        *arg1 = cur;
                    }
                    return;
                }
            }
            // simple insertion?
            prev_node->next = cur;
            cur->next = NULL;
            cur->prev = prev_node;
            *arg2 = cur;
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
    // FIXME: fakematch shenanigans, static vars?
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
        if ((arg0 == snd->object) && (id == snd->sndID)) {
            return snd;
        }
    }
    return NULL;
}

void load_sequence(s32 seqArrayIndex, s8 destIndex) {
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

s32 get_seqp_state(s8 arg0) {
    if (gAudioInitialized == 0) {
        return 0;
    }
    return D_802863C8[arg0]->state;
}

#ifdef NON_MATCHING // JUSTREG
void func_801326A8(s8 src, s8 dest) {
    s32 pad;
    if (gAudioInitialized == 0) {
        return;
    }

    if (get_seqp_state(dest) == 0) {
        s16 volume;
        load_sequence(src, dest);
        alSeqpSetBank(D_802863C8[dest], D_802862F8->bankArray[0]);
        alCSeqNew(D_802863CC[dest], D_80286314[dest]);
        alSeqpSetSeq(D_802863C8[dest], (ALSeq*)D_802863CC[dest]);
        if (D_801546A8[dest] == 0) {
            volume = D_801550F8[src] * gMusicVolume * D_8015517C;
        } else {
            volume = ((D_801546B4[dest] * D_801550F8[D_8015516C[dest]]) +
                      ((D_801546B8[dest] * (D_801550F8[D_8015516C[dest]] * D_801546AC[dest])) / D_801546B0[dest])) * gMusicVolume * D_8015517C;
        }

        alSeqpSetVol(D_802863C8[dest], volume * (2048.0f / D_801546D8));
        alSeqpPlay(D_802863C8[dest]);

        D_80155168[dest] = 1;
        D_8015516C[dest] = src;
        D_801546E4 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_801326A8.s")
#endif

#if 0
// need to migrate bss and data
void func_801328F8(void) {
    s16 i;
    s16 temp_v1;
    s16 volume;
    s32 used;
    struct017 *sound;
    ALInstrument *inst;
    static f32 D_80286554; // .bss
    static f32 D_8015529C = 110.0f; // .data

    if (gAudioInitialized == 0) {
        return;
    }

    D_80241D0E++;

    used = func_80132D84(D_80286310);
    if (used < 8) {
        temp_v1 = 8 - used;

        for (i = 0; i < temp_v1; i++) {
            sound = func_80132474();
            if (sound == NULL) {
                break;
            }

            inst = D_80286300->instArray[sound->sndID];
            sound->sndSlot = alSndpAllocate(D_80286310, inst->soundArray[sound->sndArrayIndex]);
            if (sound->sndSlot >= 0) {
                D_802863B0[sound->sndSlot] = 1; // used
                sound->unk20 = D_80241D0E;
                alSndpSetSound(D_80286310, sound->sndSlot);
                alSndpSetPitch(D_80286310, sound->sndPitch);
                if (D_801546BC == 1) {
                    volume = (((sound->sndVolume * D_801546C8) + ((D_801546CC * (sound->sndVolume * D_801546C0)) / D_801546C4)) * gSfxVolume);
                } else {
                    volume = (sound->sndVolume * gSfxVolume);
                }
                alSndpSetVol(D_80286310, volume);
                alSndpSetFXMix(D_80286310, D_80155178);
                alSndpPlay(D_80286310);
                sound->sndState = 9;
            }

        }
    }


    for (i = 0; i < 1; i++) {
        if (D_801546A8[i] != 0) {
            func_801338A8(i);
        }
    }

    if (D_801546BC != 0) {
        func_801339F8();
    }
    if (D_801546D8 != D_801546DC) {
        D_801546DC = D_801546D8;
        func_80133C50();
    } else if (D_8015529C != D_8015517C) {
        D_80286554 = D_8015517C - D_8015529C;
        if (D_80286554 < 0.0) {
            D_80286554 = D_80286554 * -1.0;
        }
        if (D_80286554 > 0.01) {
            func_80133C50();
            D_8015529C = D_8015517C;
        }
    }

    if (D_80155188 != D_8028645C) {
        D_80155188 = D_8028645C;
        if (D_8028645C == 0) {
            func_8013364C();
        } else {
            func_801337BC(D_8028645C, 1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_801328F8.s")
#endif

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

void func_80132CC0(s32 arg0) {
    struct017 *snd = D_8028631C;
    rmonPrintf("----------------- Active sounds\n");

    while (snd != NULL) {
        rmonPrintf("sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d.\n",
            snd->sndState, snd->sndSlot, snd->sndID, snd->object, snd->counter, D_802863B0[snd->sndSlot]);
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
                if (snd->object != 0) {
                    snd->counter -= 1;
                    if (snd->counter == 0) {
                        play_sound_by_slot(snd->sndSlot);
                        snd->object = 0;
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

void func_80132F70(s16 id, s16 volume) {
    s32 pad[3];
    struct017 sp50;

    if (gAudioInitialized == 0) {
        return;
    }

    if (id != SFX_INVALID) {
        sp50.unk0 = D_80154C4C[id];
        sp50.sndID = id;
        sp50.unk14 = 0;
        sp50.unk18 = 0;
        sp50.sndArrayIndex = 0;
        sp50.sndPan = 0x40;
        sp50.sndPitch = D_801546E8[id];
        if (!(sp50.sndPitch > 2.0f)) {
            sp50.object = NULL;
            sp50.sndVolume = volume;
            sp50.unk10 = D_80241D0E;
            sp50.sndSlot = -1;
            func_80132174(sp50, &D_8028631C, &D_80286320);
        }
    }
}

void play_sound_effect(s16 id, s16 arg1, s16 volume, f32 pitch, u8 pan) {
    struct017 sound;

    if (gAudioInitialized == 0) {
        return;
    }

    if (id != SFX_INVALID) {

        if (1) {}; // required!

        sound.unk0 = D_80154C4C[id];
        sound.sndID = id;
        sound.sndArrayIndex = arg1;
        sound.sndPan = pan;
        sound.sndVolume = volume;
        sound.unk14 = 0;
        sound.unk18 = 0;
        sound.sndPitch = D_801546E8[id] * pitch;
        sound.object = NULL;
        sound.unk10 = D_80241D0E;
        sound.sndSlot = -1;
        func_80132174(sound, &D_8028631C, &D_80286320);
    }
}

void func_80133188(s16 id, s16 volume, s16 arg2) {
    struct017 sound;

    if (gAudioInitialized == 0) {
        return;
    }

    if (id != SFX_INVALID) {

        if (1) {}; // required!

        sound.unk0 = D_80154C4C[id];
        sound.sndID = id;
        sound.sndArrayIndex = arg2;
        sound.unk14 = 0;
        sound.unk18 = 0;
        sound.sndPan = 0x40; // middle
        sound.object = 0;
        sound.sndPitch = D_801546E8[id];
        sound.sndVolume = volume;
        sound.unk10 = D_80241D0E;
        sound.sndSlot = -1;
        func_80132174(sound, &D_8028631C, &D_80286320);
    }
}

#ifdef NON_MATCHING
void func_8013328C(void *object, s16 id, s16 pan, f32 pitch, s16 volume, s16 arg5) {
    struct017 *var_v1;
    struct017 sp58;
    s16 vol;

    var_v1 = func_80132580(object, id);
    if (var_v1 != NULL) {
        if (var_v1->sndSlot >= 0) {

            alSndpSetSound(D_80286310, var_v1->sndSlot);

            if ((pan != var_v1->sndPan)) {
                alSndpSetPan(D_80286310, pan);
                var_v1->sndPan = pan;
            }

            if ((D_801546E8[id] * pitch) != var_v1->sndPitch) {
                alSndpSetPitch(D_80286310, (D_801546E8[id] * pitch));
                var_v1->sndPitch = D_801546E8[id] * pitch;
            }

            if (!volume) {}; // helps/hinders

            if (var_v1->sndVolume != volume) {
                if (D_801546BC == 1) {
                    vol = ((var_v1->sndVolume * D_801546C8) + ((D_801546CC * (var_v1->sndVolume * D_801546C0)) / D_801546C4)) * gSfxVolume;
                } else {
                    vol = var_v1->sndVolume * gSfxVolume;
                }
                alSndpSetVol(D_80286310, vol);
                var_v1->sndVolume = volume;
            }
        }
        var_v1->counter = 6;
        return;
    }

    // create a new sound?
    sp58.unk0 = arg5;
    sp58.unk14 = 0;
    sp58.unk18 = 0;
    sp58.sndPan = pan;
    sp58.sndPitch = D_801546E8[id] * pitch;
    if (1) {};
    sp58.sndArrayIndex = 0;
    sp58.sndID = id;
    sp58.sndVolume = volume;
    sp58.object = object;
    sp58.counter = 6;
    sp58.unk10 = D_80241D0E;
    sp58.sndSlot = -1;

    func_80132174(sp58, &D_8028631C, &D_80286320);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audiomgr/func_8013328C.s")
#endif

void play_sound_by_id_with_volume(u8 id, s16 vol) {
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpSetVol(D_80286310, vol);
        }
    }
}

void play_sound_by_id(u8 id) {
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpStop(D_80286310);
        }
    }
}

void play_sound_by_slot(s16 slot) {
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

    if (gAudioInitialized == 0) {
        return;
    }

    for (i = 0; i < 20; i++) {
        if (get_sound_by_slot(i)) {
            alSndpStop(D_80286310);
        }
    }
    func_8013364C();
    D_8028645C = NO_MUSIC;
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

    if (gAudioInitialized == 0) {
        return;
    }

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
    if ((D_80155180 == D_8028645C) && (D_8028645C != NO_MUSIC)) {
        if (++D_80155184 >= 3) {
            alCSeqSetLoc(D_802863CC[0], &D_80286460);
            D_80155180 = 0;
        }
    }
}
