#include <ultra64.h>

#include "common.h"


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
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio2/func_80132F70.s")
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

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio2/play_sound_effect.s")
// void play_sound_effect(s16 id, s16 arg1, s16 arg2, f32 speed, u8 arg4) {

// unused? absolutely no idea how to decomp
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio2/func_80133188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/audio2/func_8013328C.s")

void func_80133528(u8 id, s16 vol) { // play_sound_by_id_with_volume
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpSetVol(D_80286310, vol);
        }
    }
}

void func_8013359C(u8 id) { // play_sound_by_id
    struct017 *snd = get_sound_by_id(id);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpStop(D_80286310);
        }
    }
}

void func_80133608(s16 slot) { // play_sound_by_slot
    if (slot >= 0) {
        alSndpSetSound(D_80286310, slot);
        alSndpStop(D_80286310);
    }
}

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
    s16 i;

    for (i = 0; i < 1; i++) {
        if ((D_8015516C[i] != 1) && (D_80155168[i] == -1)) {
            s16 volume;
            float tmp;
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
#pragma GLOBAL_ASM("asm/nonmatchings/core/audio2/func_80133C50.s")
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
