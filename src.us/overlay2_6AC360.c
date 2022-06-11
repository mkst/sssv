#include <ultra64.h>
#include "common.h"


void func_8029ACB0_6AC360(void) {
}

s32 func_8029ACB8_6AC368(s32 arg0, s32 arg1) {
    return 1;
}

extern struct063 D_80100000_X[][0x81];

// loops, initialising vertexes / level data
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029ACC8_6AC378.s")
// void func_8029ACC8_6AC378(void) {
//     s32 i, j;
//
//     // writes to 803C17A0
//     // 00280000 03000000 00280000 03000000
//     // 00280000 03000000 00280000 03000000
//
//     // copy in the vertexes
//     // D_803C0740 to D_803D1DA8 == ?
//     for (i = 0; i < 4; i++) {
//         for (j = 1; j < 0x81; j++) {
//             D_803C0740[i+4][j+8] = D_80100000_X[i][j];
//         }
//     }
//     // D_803C0740 to D_803D2980 == 72 lots of 0x408
//     for (i = 0; i < 72; i++) {
//         for (j = 0; j < 0x80; j++) {
//             D_803C0740[i][j].unk6 *= 2;//D_803C0740[i][j].unk6 * 2;
//         }
//     }
//
//     // force some opacity?
//     // D_803D0740 to D_803D0B40 == 1 iteration?
//     for (j = 0; j < 0x80; j++) {
//         D_803C0740[i][j].unk0 = 0xFF;
//     }
//
//     // who knows
//     // D_803C0740 to D_803D2980 (+ 0x1020) is 18 loops
//     for (i = 0; i < 18; i += 4) {
//         for (j = 0; j < 0x81; j++) {
//             // 63 =
//             D_803C0740[i][j].unk7 = D_803C0740[i][j].unk7 | 0x44;
//             D_803C0740[i][j+1].unk7 = D_803C0740[i][j+1].unk7 | 0x88;
//             D_803C0740[i][j+2].unk7 = 0x80;
//             D_803C0740[i][j+3].unk7 = 0xF0;
//         }
//     }
// }

// file split?
s32 func_8030400C_7156BC(Animal*, s16, s16, s32*, s32*);
s32 func_8032B1E0_73C890(Animal*, s16, s16, s32*, s32*);

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B000_6AC6B0.s")
#if 0
u8 func_8029B000_6AC6B0(s16 arg0, s16 arg1, s32 arg2, Animal *arg3, void *arg4, void **arg5, s32 *arg6, void *arg7, void **arg8, s32 *arg9) {
    s32 sp9C;
    s32 sp98;
    s32 sp64;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v1;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s32 temp_t5;
    s32 temp_v0_5;
    s32 temp_v1_2;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_v0_4;
    struct035 *temp_a1;
    Animal *temp_s0;
    struct065 *phi_s2;
    u8 phi_a0;
    s32 phi_a3;
    s32 phi_s5;
    s32 phi_s6;

    *arg6 = -1;
    *arg9 = -1;
    *arg5 = NULL;
    *arg8 = NULL;
    phi_s5 = 0;
    phi_s6 = 0x40000000; // FTOFIX32(16384.0) ?

    temp_v0 = (s16)(arg0 >> 0xA) + ((s16) (arg1 >> 0xA)) * 5;
    if ((temp_v0 < 0) || (temp_v0 >= 40)) {
        return 0;
    }

    for (phi_s2 = D_803DA110[temp_v0].next; phi_s2 != NULL; phi_s2 = phi_s2->next) { // + (temp_v0 * 0xC));
        temp_s0 = phi_s2->animal;
        if (temp_s0 != arg3) {
            temp_a1 = arg3->unk16C;
            temp_t5 = temp_a1->unk0;
            if ((temp_t5 == OB_TYPE_ANIMAL_OFFSET + EVO) && (arg3->unk365 == 9)) {
                // temp_a1->unk2 somehow?
                if ((D_803A0510_7B1BC0[5] & (1 << (0xF - temp_s0->unk16C->unk2)))) {
                    goto block_13;
                }
            } else {
                if ((D_803A0510_7B1BC0[temp_a1->unk2] & (1 << (0xF - temp_s0->unk16C->unk2))) == 0) {

                } else {
block_13:
                    if ((temp_a1->unk2 == 5) && (temp_s0 == arg3->unk320)) {

                    } else if (((temp_s0->unk15C != 0) && (arg3 == temp_s0->unk168)) || ((arg3->unk15C != 0) && (temp_s0 == arg3->unk168))) {
                        phi_s6 = sp98; // regalloc?
                    } else {
                        phi_a3 = 0;
                        if ((temp_s0->unk16C->unk2 == 5) && (temp_a1->unk2 == 5)) {
                            if ((temp_s0->unk16C->unkE6 < temp_a1->unkE6) || (func_8030AA08_71C0B8(temp_s0, arg3) != 0) || (temp_s0->unk366 == 5) || (arg3->unk366 == 5)) {
                                if (temp_s0->unk16C->unkE6 >= arg3->unk16C->unkE6) {
                                    if ((arg0 >= (temp_s0->xPos.h - temp_s0->unk34)) && (arg0 < (temp_s0->xPos.h + temp_s0->unk34))) {
                                        if ((arg1 >= (temp_s0->zPos.h - temp_s0->unk34)) && (arg1 < (temp_s0->zPos.h + temp_s0->unk34))) {
                                            phi_a3 = func_8030400C_7156BC(temp_s0, arg0, arg1, &sp9C, &sp98);
                                        }
                                    }
                                } else if ((((arg3->unk162 != 1) || (arg3->unk68 != 0)) && (arg3->yVelocity.w < -FTOFIX32(6.0))) || (temp_s0->unk366 == 5) || (temp_s0->unk366 == 2)) {
                                    temp_t5 = temp_s0->unk30 * 2;
                                    temp_v0_5 = arg0 - temp_s0->xPos.h;
                                    temp_v1_2 = arg1 - temp_s0->zPos.h;
                                    if ((temp_t5 * temp_t5) >= ((temp_v0_5 * temp_v0_5) + (temp_v1_2 * temp_v1_2))) {
                                        sp9C = *(s32*)&temp_s0->yPos.h + (temp_s0->unk42 << 0x10);
                                        sp98 = *(s32*)&temp_s0->yPos.h;
                                        phi_a3 = 1;
                                    }
                                }
                            }
                        } else {
                            if ((arg0 >= (temp_s0->xPos.h - temp_s0->unk30)) && (arg0 < (temp_s0->xPos.h + temp_s0->unk30))) {
                                if ((arg1 >= (temp_s0->zPos.h - temp_s0->unk32)) && (arg1 < (temp_s0->zPos.h + temp_s0->unk32))) {
                                    phi_a3 = func_8032B1E0_73C890(temp_s0, arg0, arg1, &sp9C, &sp98);
                                }
                            }
                        }
                        if (phi_a3 != 0) {
                            temp_s0->unk4C.unk25 = 1;
                            if (temp_s0 == arg4) {
                                if (sp9C >= phi_s5) {
                                    *arg6 = sp9C;
                                    *arg5 = arg4;
                                    phi_s5 = sp9C;
                                }
                            } else if (temp_s0 == arg7) {
                                if (phi_s6 >= sp98) {
                                    *arg9 = sp98;
                                    *arg8 = arg7;
                                    phi_s6 = sp98;
                                }
                            } else if (arg3 == temp_s0->unk68) {
                                if (sp98 < phi_s6) {
                                    *arg9 = sp98;
                                    *arg8 = temp_s0;
                                    phi_s6 = sp98;
                                }
                            } else if (arg3 == temp_s0->unk70) {
                                if (phi_s5 < sp9C) {
                                    *arg6 = sp9C;
                                    *arg5 = temp_s0;
                                    phi_s5 = sp9C;
                                }
                            } else if (arg2 < ((sp98 + sp9C) >> 1)) {
                                if (sp98 < phi_s6) {
                                    *arg9 = sp98;
                                    *arg8 = temp_s0;
                                    phi_s6 = sp98;
                                }
                            } else if (phi_s5 < sp9C) {
                                *arg6 = sp9C;
                                *arg5 = temp_s0;
                                phi_s5 = sp9C;
                            }
                        }
                    }
                }
            }
        }
    }

    return *arg5 != 0;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B56C_6ACC1C.s")
#if 0
// 4169 (miles) away
s32 func_8029B56C_6ACC1C(s16 arg0, s16 arg1, s16 *arg2, struct063 arg3[73][129]) {
    s16 temp_t3;
    s16 temp_t5;

    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_v1;

    s16 changed;

    if (((s16)(arg0 >> 6) < 0) || ((((s16)(arg0 >> 6) >= 72))) ||
        ((s16)(arg1 >> 6) < 0) || ((((s16)(arg1 >> 6) >= 128)))) {
        return 0;
    }

    changed = 0;
    if (arg3[arg0 >> 6][arg1 >> 6].unk3) { // ->unk3 != 0) {
        temp_t3 = arg0 & 0x3F;
        temp_t5 = arg1 & 0x3F;
        temp_v1 = arg3[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk1 << 3;
        temp_a3 = arg3[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk1 << 3;
        temp_t1 = arg3[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk1 << 3;
        temp_t0 = arg3[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk1 << 3;

        if ((D_803C0740[arg0 >> 6][arg1 >> 6].unk4 & 1)) {
            if (temp_t3 < temp_t5) {
                *arg2 = temp_v1 + ((((temp_t0 - temp_a3) * temp_t3) + ((temp_a3 - temp_v1) * temp_t5)) >> 6);
            } else {
                *arg2 = temp_v1 + ((((temp_t1 - temp_v1) * temp_t3) + ((temp_t0 - temp_t1) * temp_t5)) >> 6);
            }
        } else {
            if ((temp_t3 + temp_t5) < 64) {
                *arg2 = (((temp_v1 << 6) + ((temp_t1 - temp_v1) * temp_t3) + ((temp_a3 - temp_v1) * temp_t5)) >> 6);
            } else {
                *arg2 = (((temp_t0 << 6) + ((temp_a3 - temp_t0) * (0x40 - temp_t3)) + ((temp_t1 - temp_a3) * (0x40 - temp_t5))) >> 6);
            }
        }
        *arg2 -= D_803E1D32[D_803C0740[arg0 >> 6][arg1 >> 6].unk3 * 0xC] << 3;
        changed = 1;
    }
    return changed;
}
#endif

s16 distance_from_player(s16 x, s16 z, s16 y) {
    Animal *a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    return ABS(x - a->xPos.h) + ABS(z - a->zPos.h) + ABS(y - a->yPos.h);
}
