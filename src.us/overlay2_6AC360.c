#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

u16 D_803A0510_7B1BC0[] = {
    0x0206, 0xBA26, 0x0206, 0x0000, 0x0000,
    0xAE26, 0x0200, 0x0200, 0x0200, 0x0000,
    0x0200, 0x0000, 0x0200, 0x0206, 0x0202,
    0x0000,
};

// ========================================================
// .bss
// ========================================================

struct063 D_803C0740[65+8][97+32]; // data is [65][97]

// ========================================================
// .text
// ========================================================

void func_8029ACB0_6AC360(void) {
}

s32 func_8029ACB8_6AC368(s32 arg0, s32 arg1) {
    return 1;
}

extern struct063 D_80100000_X[][0x81];

// loops, initialising vertexes / level data
#if 0
void func_8029ACC8_6AC378(void) {
#if 0
    ? *var_a0_2;
    ? *var_s1;
    s32 *var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s8 temp_t7;
    struct063 (*var_a1)[0x81];
    struct063 (*var_a1_2)[0x81];
    struct063 (*var_a2)[0x81];
    struct063 (*var_v1_2)[0x81];
    struct063 (*var_v1_3)[0x81];
    struct063 *temp_a2;
    struct063 *var_a3;
    struct063 *var_t0;
    struct063 *var_t2;
    struct063 *var_t5;
    u8 temp_t8;
    u8 temp_t9;
    void *var_a0;
    void *var_t1;
    void *var_t3;
    void *var_t4;
#endif

    struct063 (*var_s0)[97];

    s32 i;
    s32 j;

#if 0
    var_a1 = D_803C0740;
    var_s1 = &D_803C17A0;
    var_s0 = &D_80100000;
    var_v1 = 0;
    do {
        var_s1->unk4 = (unaligned s32) var_s0->unk4;
        temp_a2 = &var_a1[0][1];
        var_a0 = (var_v1 * 8) + 8 + &D_80100000;
        var_s1->unk0 = (unaligned s32) var_s0->unk0;
        var_t1 = var_a0 + 8;
        var_t3 = var_a0 + 0x10;
        var_t4 = var_a0 + 0x18;
        var_a3 = temp_a2 + 0x1060;
        var_t0 = temp_a2 + 0x1068;
        var_t2 = temp_a2 + 0x1070;
        var_t5 = temp_a2 + 0x1078;
        var_v0 = 1;
    loop_2:
        var_a3->unk0 = (unaligned s32) var_a0->unk0;
        var_a3->unk4 = (unaligned s32) var_a0->unk4;
        var_t0->unk0 = (unaligned s32) var_t1->unk0;
        var_t0->unk4 = (unaligned s32) var_t1->unk4;
        var_t2->unk0 = (unaligned s32) var_t3->unk0;
        var_t2->unk4 = (unaligned s32) var_t3->unk4;
        var_v0 += 4;
        var_t5->unk4 = (unaligned s32) var_t4->unk4;
        var_t5->unk0 = (unaligned s32) var_t4->unk0;
        var_a0 += 0x20;
        var_a3 += 0x20;
        var_t0 += 0x20;
        var_t1 += 0x20;
        var_t2 += 0x20;
        var_t3 += 0x20;
        var_t4 += 0x20;
        var_t5 += 0x20;
        if (var_v0 != 0x61) {
            goto loop_2;
        }
        var_s1 += 0x408;
        var_v1 += 0x61;
        var_a1 += 0x408;
        var_s0 += 0x308;
    } while ((u32) var_s1 < (u32) &D_803D1DA8);
#endif

    var_s0 = &D_80100000;
    for (i = 0; i < 65+8; i++) {
        for (j = 0; j < (129-32); j++) {
            D_803C0740[i+4][j+8] = var_s0[i][j];
        }
    }

#if 0
    var_a1_2 = D_803C0740;
    do {
        var_v0_2 = 0;
        var_a2 = var_a1_2;
    loop_6:
        var_v0_2 += 1;
        temp_t7 = var_a2[0][0].unk6 * 2;
        var_a2 += 8;
        var_a2->unk-2 = temp_t7;
        if (var_v0_2 < 0x80) {
            goto loop_6;
        }
        var_a1_2 += 0x408;
    } while ((u32) var_a1_2 < (u32) &D_803D2980);
#endif

    for (i = 0; i < 73-1; i++) {
        for (j = 0; j < 129-1; j++) {
            D_803C0740[i][j].unk6 = D_803C0740[i][0].unk6 * 2;
        }
    }

#if 0
    var_a0_2 = &D_803D0740;
    var_v1_2 = D_803C0740;
    do {
        var_v1_2[0][0].unk0 = 0xFF;
        var_v1_2->unk408 = 0xFFU;
        var_v1_2->unk810 = 0xFFU;
        var_v1_2->unkC18 = 0xFFU;
        var_a0_2->unk1628 = 0xFFU;
        var_a0_2->unk1A30 = 0xFFU;
        var_a0_2->unk1E38 = 0xFFU;
        var_a0_2->unk2240 = 0xFFU;
        var_v1_2->unkC20 = 0xFFU;
        var_v1_2->unk818 = 0xFFU;
        var_v1_2->unk410 = 0xFFU;
        var_v1_2[0][1].unk0 = 0xFF;
        var_a0_2->unk2248 = 0xFFU;
        var_a0_2->unk1E40 = 0xFFU;
        var_a0_2->unk1A38 = 0xFFU;
        var_a0_2->unk1630 = 0xFFU;
        var_v1_2->unkC28 = 0xFFU;
        var_v1_2->unk820 = 0xFFU;
        var_v1_2->unk418 = 0xFFU;
        var_v1_2[0][2].unk0 = 0xFF;
        var_a0_2->unk2250 = 0xFFU;
        var_a0_2->unk1E48 = 0xFFU;
        var_a0_2->unk1A40 = 0xFFU;
        var_a0_2->unk1638 = 0xFFU;
        var_v1_2->unkC30 = 0xFFU;
        var_v1_2->unk828 = 0xFFU;
        var_v1_2->unk420 = 0xFFU;
        var_v1_2[0][3].unk0 = 0xFF;
        var_a0_2 += 0x20;
        var_a0_2->unk2238 = 0xFFU;
        var_a0_2->unk1E30 = 0xFFU;
        var_a0_2->unk1A28 = 0xFFU;
        var_a0_2->unk1620 = 0xFFU;
        var_v1_2 += 0x20;
    } while (var_a0_2 != &D_803D0B40);
    D_803E1D30->unkB41 = 0xFFU;
    D_803E1D30->unkB42 = 0xFFU;
    D_803E1D30->unkB4D = 0xFFU;
    D_803E1D30->unkB59 = 0xFFU;
    D_803E1D30->unkB5A = 0xFFU;
    D_803E1D30->unkB4E = 0;
#endif

    // fuck knows what this is
    // i thought maybe filling in borders, but...?

#if 0
var_v1_3 = D_803C0740;
do {
    temp_t9 = var_v1_3[0][7].unk5;
    temp_t8 = var_v1_3[0][0x68].unk5;
    var_v1_3 += 0x1020;
    var_v1_3->unk-FE3 = (s8) (temp_t9 | 0x88); // unk2003
    var_v1_3->unk-CDB = (s8) (temp_t8 | 0x44);
    var_v1_3->unk-BDB = (u8) (var_v1_3->unk-BDB | 0x88);
    var_v1_3->unk-8D3 = (u8) (var_v1_3->unk-8D3 | 0x44);
    var_v1_3->unk-4CB = (u8) (var_v1_3->unk-4CB | 0x44);
    var_v1_3->unk-7D3 = (u8) (var_v1_3->unk-7D3 | 0x88);
    var_v1_3->unk-3CB = (u8) (var_v1_3->unk-3CB | 0x88);
    var_v1_3->unk-C3 = (u8) (var_v1_3->unk-C3 | 0x44);
    var_v1_3->unk-BD7 = 0x80;
    var_v1_3->unk-BDD = 0xF0;
    var_v1_3->unk-8D7 = 0x80;
    var_v1_3->unk-8D5 = 0xF0;
    var_v1_3->unk-7CF = 0x80;
    var_v1_3->unk-7D5 = 0xF0;
    var_v1_3->unk-4CF = 0x80;
    var_v1_3->unk-4CD = 0xF0;
    var_v1_3->unk-3C7 = 0x80;
    var_v1_3->unk-3CD = 0xF0;
    var_v1_3->unk-C7 = 0x80;
    var_v1_3->unk-C5 = 0xF0;
    var_v1_3->unk-FDF = 0x80;
    var_v1_3->unk-FE5 = 0xF0;
    var_v1_3->unk-CDF = 0x80;
    var_v1_3->unk-CDD = 0xF0;
} while (var_v1_3 != &D_803D2980);
#endif

    for (i = 0; i < 73; i++) {
        // ??
    }

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029ACC8_6AC378.s")
#endif

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

#if 0
// absolute shambles.
// ESA: func_800397B0
u8 func_8029B000_6AC6B0(s16 arg0, s16 arg1, s32 yPos, Animal *arg3, Animal *arg4, Animal **arg5, s32 *arg6,
                                                                    Animal *arg7, Animal **arg8, s32 *arg9) {
    s32 sp9C;
    s32 sp98;
    s32 pad[6];

    s32 temp_v1_2;
    s32 temp_v0_5;
    s32 temp_t5;
    s16 temp_v0;
    Animal *animal;
    s32 minDist;
    s32 do_check;
    s32 maxDist;

    struct065 *var_s2;
    struct035 *temp_a1;
    struct035 *tmp;

    *arg6 = -1;
    *arg9 = -1;

    *arg5 = NULL;
    *arg8 = NULL;

    maxDist = 0;
    minDist = 0x40000000;

    temp_v0 = (s16)(arg0 >> 0xA) + ((s16) (arg1 >> 0xA) * 5);
    var_s2 = D_803DA110[temp_v0].next;

    if ((temp_v0 < 0) || (temp_v0 >= 40)) {
        return 0;
    }

    for (; var_s2 != NULL; var_s2 = var_s2->next) {
        animal = var_s2->animal;

        if (animal == arg3) {
            if ((arg3->unk16C->objectType != (256+63)) || (arg3->unk365 != 9)) {

                temp_a1 = arg3->unk16C;
                tmp = animal->unk16C;
                temp_t5 = tmp->unk2;

                if (((D_803A0510_7B1BC0[5]             & (1 << (0xF - tmp->unk2))) != 0) ||
                    ((D_803A0510_7B1BC0[temp_a1->unk2] & (1 << (0xF - temp_t5))) == 0)) {

                    var_s2 = var_s2->next; // not correct... urgh

                } else if ((temp_a1->unk2 == 5) && (animal == arg3->unk320)) {

                    var_s2 = var_s2->next; // not correct... urgh

                } else if (((animal->unk15C != 0) && (arg3 == animal->owner)) ||
                           ((arg3->unk15C != 0) && (animal == arg3->owner))) {

                     var_s2 = var_s2->next; // not correct... urgh

                } else {
                    do_check = 0;
                    if ((tmp->unk2 == 5) && (temp_a1->unk2 == 5)) {
                        if ((tmp->unkE6 < temp_a1->unkE6) || (func_8030AA08_71C0B8(animal, arg3) != 0) || (animal->unk366 == 5) || (arg3->unk366 == 5)) {
                            if (animal->unk16C->unkE6 >= arg3->unk16C->unkE6) {
                                if (((arg0 >= (animal->position.xPos.h - animal->unk34)) && (arg0 < (animal->position.xPos.h + animal->unk34))) &&
                                    ((arg1 >= (animal->position.zPos.h - animal->unk34)) && (arg1 < (animal->position.zPos.h + animal->unk34)))) {
                                    do_check = func_8030400C_7156BC(animal, arg0, arg1, &sp9C, &sp98);
                                }
                            } else if ((((arg3->unk162 != 1) || (arg3->unk68 != NULL)) && (arg3->yVelocity.w < FTOFIX32(-6.0))) || ((animal->unk366 == 5)) || (animal->unk366 == 2)) {

                                temp_v0_5 = arg0 - animal->position.xPos.h;
                                temp_v1_2 = arg1 - animal->position.zPos.h;
                                temp_t5 = animal->unk30 * 2;

                                if ((SQ(temp_v0_5) + SQ(temp_v1_2)) <= SQ(temp_t5)) {
                                    do_check = 1;
                                    sp9C = animal->position.yPos.w + (animal->unk42 << 0x10);
                                    sp98 = animal->position.yPos.w;
                                }
                            }
                        }
                    } else {
                        if (((arg0 >= (animal->position.xPos.h - animal->unk30)) && (arg0 < (animal->position.xPos.h + animal->unk30))) &&
                           ((arg1 >= (animal->position.zPos.h - animal->unk32)) && (arg1 < (animal->position.zPos.h + animal->unk32)))) {
                            do_check = func_8032B1E0_73C890(animal, arg0, arg1, &sp9C, &sp98);
                        }
                    }

                    if (do_check != 0) {

                        animal->unk4C.unk19 = 1;
                        if (animal == arg4) {
                            if (sp9C >= maxDist) {
                                maxDist = *arg6 = sp9C;
                                *arg5 = arg4;
                            }
                        } else if (animal == arg7) {
                            if (minDist >= sp98) {
                                *arg9 = minDist = sp98;
                                *arg8 = arg7;
                            }
                        } else if (arg3 == animal->unk68) {
                            if (sp98 < minDist) {
                                *arg9 = minDist = sp98;
                                *arg8 = animal;
                            }
                        } else if (arg3 == animal->unk70) {
                            if (maxDist < sp9C) {
                                maxDist = *arg6 = sp9C;
                                *arg5 = animal;
                            }
                        } else if (yPos < ((sp98 + sp9C) >> 1)) {
                            if (sp98 < minDist) {
                                *arg9 = minDist = sp98;
                                *arg8 = animal;
                            }
                        } else if (maxDist < sp9C) {
                            maxDist = *arg6 = sp9C;
                            *arg5 = animal;
                        }
                    }
                }
            }
        }
    }

    return (*arg5 != NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B000_6AC6B0.s")
#endif

s32 func_8029B56C_6ACC1C(s16 arg0, s16 arg1, s16 *arg2, struct063 arg3[73][129]) {
    s16 temp_t3;
    s16 temp_t5;

    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_v1;

    s32 changed;

    s16 a0 = arg0 >> 6;
    s16 a1 = arg1 >> 6;

    if ((a0 < 0) || (a0 >= 72) || (a1 < 0) || (a1 >= 128)) {
        return 0;
    }

    if (arg3[a0][a1].unk3 != 0) {
        temp_v1 = arg3[(a0) + 0][(a1) + 0].unk1 << 3;
        temp_a3 = arg3[(a0) + 0][(a1) + 1].unk1 << 3;
        temp_t0 = arg3[(a0) + 1][(a1) + 1].unk1 << 3;
        temp_t1 = arg3[(a0) + 1][(a1) + 0].unk1 << 3;

        temp_t3 = arg0 & 0x3F;
        temp_t5 = arg1 & 0x3F;

        if ((D_803C0740[(a0)][(a1)].unk4 & 1)) {
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
        changed = 1;
        *arg2 -= D_803E1D30[D_803C0740[a0][a1].unk3].unk2 << 3;
    } else {
        changed = 0;
    }

    return changed;
}
