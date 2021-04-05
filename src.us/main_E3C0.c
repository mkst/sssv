#include <ultra64.h>

#include "common.h"


// more audio funcs

void func_80132CC0(s32 arg0) {
    struct017 *snd;

    snd = D_8028631C;
    rmonPrintf(D_8015AD90); // "----------------- Active sounds\n"

    while (snd != NULL) {
        rmonPrintf(D_8015ADB4, // "sndState:%d sndSlot:%d sndID:%d object:%p counter:%d sndSlotState[sndSlot]:%d"
            snd->sndState, snd->sndSlot, snd->sndID, snd->unk28, snd->counter, D_802863B0[snd->sndSlot]);
        snd = snd->next;
    }
}

// count used sounds
s16 func_80132D54(void) {
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

    if (D_80155154 == 0) {
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

// bit odd, copy values into some structs?
#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80132F70.s")

typedef struct {
    s16 unk0;      // 4C
    s16 unk2;      // 4E
    u8  unk4;      // 50
    u8  pad5[0x3];
    f32 unk8;      // 54
    s16 unkC;      // 58
    u8  padE[0x2]; // 5A
    u16 unk10;     // 5C
    u8  pad12[0x2];
    s16 unk14;     // 60
    u8  pad16[0x2];
    s32 unk18;     // 64
    s16 unk1C;     // 68
    u8  pad1E[0x4];
    s16 unk22;     // 6E
    u8  pad24[0x4];
    s16 unk28;     // 74
    s32 unk30;
} foo;

// play a sound effect?
#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/play_sound_effect.s")
// wth is this?
// void play_sound_effect(s16 arg0, s16 arg1, s16 arg2, f32 arg3, u8 arg4) {
//     foo tmp;
//
//     s16 *temp_t5;
//     s16 *temp_t5_2;
//     s32 temp_v0;
//     void *temp_t9;
//     foo  *phi_t5;
//     void *phi_t9;
//
//     if (D_80155154 != 0) {
//         if (arg0 != 10000) {
//             tmp.unk0 = D_80154C4C[arg0];
//             tmp.unk2 = arg0;
//             tmp.unk14 = 0;
//             tmp.unk18 = 0;
//             tmp.unk8 = D_801546E8[arg0] * arg3; // + temp_v0) * arg3;
//             tmp.unk28 = 0;
//             tmp.unk22 = -1;
//             tmp.unk1C = arg1;
//             tmp.unk4 = arg4;
//             tmp.unkC = arg2;
//             tmp.unk10 = D_80241D0E;
//             // phi_t9 = sp;
//             phi_t5 = &tmp;
//             while(phi_t5->unkC != phi_t5->unk30) {
//                 // ?
//             }
// // loop_3:
// //             temp_t5_2 = phi_t5 + 0xC;
// //             temp_t9 = phi_t9 + 0xC;
// //             temp_t9->unk-C = (s32) *phi_t5;
// //             temp_t9->unk-8 = (s32) temp_t5_2->unk-8;
// //             temp_t9->unk-4 = (s32) temp_t5_2->unk-4;
// //             phi_t5 = temp_t5_2;
// //             phi_t9 = temp_t9;
// //             if (temp_t5_2 != (temp_t5 + 0x30)) {
// //                 goto loop_3;
// //             }
//             // temp_t9->unk0 = (s32) temp_t5_2->unk0;
//             // func_80132174(arg3, subroutine_arg0, subroutine_arg1, subroutine_arg2, subroutine_arg3, &D_8028631C, &D_80286320);
//             func_80132174(arg3, phi_t5->unk0, &D_8028631C, &D_80286320);
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133188.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_8013328C.s")

void func_80133528(u8 arg0, s16 vol) {
    struct017 *snd = func_80132414(arg0);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpSetVol(D_80286310, vol);
        }
    }
}

void func_8013359C(u8 arg0) {
    struct017 *snd = func_80132414(arg0);
    if (snd != NULL) {
        if ((snd->sndSlot >= 0) && (D_802863B0[snd->sndSlot] != 1)) {
            alSndpSetSound(D_80286310, snd->sndSlot);
            alSndpStop(D_80286310);
        }
    }
}

void func_80133608(s16 slot) {
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

void func_80133738(void) {
    s8 i;

    if (D_80155154) {
        for (i = 0; i < 20; i++) {
            if (func_801323B8(i)) {
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
            ((D_801546B4[arg0] * tmp) + ((D_801546B8[arg0] * (tmp * D_801546AC[arg0])) / D_801546B0[arg0])) * D_801546D0 * D_8015517C);
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

    if (D_80155154 != 0) {
        for (snd = D_8028631C; snd != NULL; snd = snd->next) {
            if ((snd->sndSlot >= 0) && (D_801546BC == 1)) {
                vol = ((snd->unkC * D_801546C8) + ((D_801546CC * (snd->unkC * D_801546C0)) / D_801546C4)) * D_801546D4;
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

void func_80133B74(s16 arg0) {
    D_801546D4 = arg0 / 20.0f;
}

void func_80133BA0(s16 arg0) {
    D_801546D0 = arg0 / 20.0f;
    func_80133C50();
}

void func_80133BE4(void) {
    ALSndPlayer *sndp;
    struct017 *snd;

    if (D_80155154 != 0) {
        for (snd = D_8028631C; snd != NULL; snd = snd->next) {
            if (snd->sndSlot >= 0) {
                alSndpSetSound(sndp, snd->sndSlot);
                alSndpGetState(sndp);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_E3C0/func_80133C50.s")
// needs some love
// void func_80133C50(void) {
//     f32 tmp;
//     s16 temp_v1;
//     s16 i;
//     s16 phi_a1;
//
//     for (i = 0; i < 1; i++) {
//         temp_v1 = D_8015516C[i];
//         if ((temp_v1 != -1) && (D_80155168[i] == 1)) {
//             if ((s16)D_801546A8[0] == 1.0f) { // ??
//                 tmp = D_801550F8[temp_v1];
//                 // phi_a1 = ((((D_801546B8[i] * (tmp * D_801546AC[i]))) / D_801546B0[i]) + (D_801546B4[i] * tmp)) * D_801546D0 * D_8015517C;
//                 phi_a1 = ((D_801546B4[i] * tmp) + ((D_801546B8[i] * (tmp * D_801546AC[i])) / D_801546B0[i])) * D_801546D0 * D_8015517C;
//             } else {
//                 phi_a1 = D_801550F8[temp_v1] * (D_8015517C * D_801546D0);
//             }
//             alSeqpSetVol(D_802863C8[i], phi_a1 * (D_801546D8 / 2048.0f));
//         }
//     }
// }

void func_80133E44(void) {
    alCSeqGetLoc(D_802863CC, &D_80286460);
    D_80155180 = D_8028645C;
    D_80155184 = 0;
}

void func_80133E84(void) {
    if ((D_80155180 == D_8028645C) && (D_8028645C != 0)) {
        if (++D_80155184 >= 3) {
            alCSeqSetLoc(D_802863CC, &D_80286460);
            D_80155180 = 0;
        }
    }
}
