#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/initialise_audio.s")

void func_80132044(s32 arg0);
// some kind of de-init? remove sound?
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132044.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_80132174.s")

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

    D_80286320 = NULL;
    D_8028631C = NULL;

    if (1) {}
    return *bar;
}

void *func_80132580(s32 arg0, s16 id) {
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
    if (gAudioInitialized == 0) {
        return;
    }

    if (func_8013266C(arg1) == 0) {
        f32 temp_f0;
        s16 volume;
        func_801325E8(arg0, arg1);
        alSeqpSetBank(D_802863C8[arg1], D_802862F8->bankArray[0]);
        alCSeqNew(D_802863CC[arg1], D_80286314[arg1]);
        alSeqpSetSeq(D_802863C8[arg1], (ALSeq*)D_802863CC[arg1]);
        if (D_801546A8[arg1] == 0) {
            volume = D_801550F8[arg0] * gMusicVolume * D_8015517C;
        } else {
            temp_f0 = D_801550F8[D_8015516C[arg1]];
            volume = ((D_801546B4[arg1] * temp_f0) +
                      ((D_801546B8[arg1] * (temp_f0 * D_801546AC[arg1])) / D_801546B0[arg1])) * gMusicVolume * D_8015517C;
        }

        alSeqpSetVol(D_802863C8[arg1], volume * (2048.0f / D_801546D8));
        alSeqpPlay(D_802863C8[arg1]);

        D_80155168[arg1] = 1;
        D_8015516C[arg1] = arg0;
        D_801546E4 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801326A8.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio/func_801328F8.s")

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
