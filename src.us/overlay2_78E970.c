#include <ultra64.h>
#include "common.h"
#include "pp.h"

void func_8037E6DC_78FD8C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4);


void func_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D2E4_78E994(s32 arg0) {
    u8 *nonsense;
    UnpackRNC((RNC_fileptr)nonsense, (u8*)D_800DF220);
}

void func_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8037D320_78E9D0(s32 arg0, s32 arg1) {
}

void func_8037D32C_78E9DC(s32 arg0, u8 arg1, s32 arg2, u16 arg3, s32 arg4) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037D340_78E9F0.s")
// void func_8037D340_78E9F0(s16 arg0, s16 arg1) {
//     s16 sp9C;
//     s16 sp9A;
//     s16 sp98;
//     s16 sp90;
//     s16 sp8E;
//     s16 sp8C;
//     s32 sp60;
//     s32 sp5C;
//     s32 sp54;
//     s32 sp50;
//     s32 sp4C;
//     s16 temp_a0;
//     s16 temp_a0_2;
//     s16 temp_a1;
//     s16 temp_a2;
//     s16 temp_t7_2;
//     s16 temp_t9;
//     s16 temp_v0;
//     s16 temp_v0_3;
//     s16 temp_v1_2;
//     s32 temp_t3;
//     s32 temp_t4;
//     s16 temp_t5;
//     s32 temp_t5_2;
//     s16 temp_t7;
//     s32 temp_t8;
//     s32 temp_t9_3;
//     s32 temp_v0_4;
//     s32 temp_v0_6;
//     s32 temp_v1_4;
//     s32 temp_v1_5;
//     s32 temp_v1_6;
//     s32 temp_v1_7;
//     s32 temp_v1_8;
//     u16 temp_v0_5;
//     // u8 temp_t9_2;
//     u8 temp_v1;
//
//     Animal *temp_v0_2;
//
//     s32 phi_a2;
//     s32 phi_a3;
//     s32 phi_t0;
//     s16 phi_t2;
//     struct065 *phi_s1;
//     s32 phi_v0;
//     s32 phi_a0;
//     s32 phi_v1;
//     s32 phi_v1_2;
//     s32 phi_a1;
//
//     if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk162 == 1) {
//         if (arg0 > 20) {
//             do_rumble(0, 25, 55, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h)); //, temp_a3));
//         } else {
//             do_rumble(0, 13, 25, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h)); //, temp_a3_2));
//         }
//     }
//     sp8E = D_803D5530->xPos.h;
//     sp8C = D_803D5530->zPos.h;
//     func_80374C38_7862E8(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h); //, temp_a3_3);
//     temp_t5 = sp8E >> 0xA;
//     temp_t7 = sp8C >> 0xA;
//     sp9C = temp_t7;
//
//     phi_a2 = -1;
//     phi_a3 = 1;
//     phi_t0 = -1;
//     phi_t2 = 1;
//
//     if ((temp_t5 + 1) >= 5) {
//         phi_a3 = 0;
//     }
//     if (temp_t5 <= 0) {
//         phi_a2 = 0;
//     }
//     if ((temp_t7 + 1) >= 8) {
//         phi_t2 = 0;
//     }
//     if (temp_t7 <= 0) {
//         phi_t0 = 0;
//     }
//
//     // temp_v0 = temp_t5 + phi_a2;
//     sp9A = temp_t5 + phi_a2;
//     sp60 = temp_t5 + phi_a3;
//     sp54 = temp_t7 + phi_t0;
//     // sp50 = temp_t7 + phi_t2;
//     sp90 = phi_t2;
//     while (sp9A <= sp60) {
//         sp98 = sp54;
//         while (sp98 <= (sp9C + sp90)) {
//             for (phi_s1 = D_803DA110[(s16) (sp9A + (sp98 * 5))].next; phi_s1 != NULL; phi_s1 = phi_s1->next) {
//                 temp_v0_2 = phi_s1->animal;
//                 if (phi_s1 == temp_v0_2->unk11C) {
//                     if ((D_803D5530 != temp_v0_2) &&
//                         ((temp_v0_2->unk162 == 6) || (temp_v0_2->unk162 == 1))) {
//                         temp_v0_3 = sp8E - temp_v0_2->xPos.h;
//                         temp_v1_2 = temp_v0_2->zPos.h;
//                         temp_v1_2 = sp8C - temp_v1_2;
//                         temp_a2 = D_803D5530->zPos.h;
//                         phi_a0 = ABS(temp_v0_3);
//                         phi_v0 = ABS(temp_v1_2);
//
//                         phi_v1_2 = MAX(phi_v0, phi_a0);
//                         phi_a1 = MIN(phi_v0, phi_a0);
//
//                         phi_v1 = ABS(temp_a2 - temp_v0_2->yPos.h);
//                         if (phi_v1 < 128) {
//                             temp_a0_2 = (phi_v1_2 >> 1) + phi_a1;
//                             if (temp_a0_2 < arg1) {
//                                 if (temp_v0_2->unk16C->unk80.bit) {
//                                     if ((temp_v0_2->unk16C->unk9C != EVO_TRANSFER) &&
//                                         (temp_v0_2->unk16C->unk9C != D_803D5524->unk9C) &&
//                                         (temp_v0_2->unk16C->unk9C != RACING_TORTOISE_DEFENDING) &&
//                                         (temp_v0_2->unk16C->unk9C != TORTOISE_TANK_DEFENDING)) {
//
//                                         temp_v0_2->yVelocity.w += FTOFIX32(10.0);
//                                         switch (temp_v0_2->unk16C->unkE6) {
//                                         case 0:
//                                             temp_t3 = (arg0 * 8) >> 3;
//                                             temp_v0_2->health = MAX(temp_v0_2->health - temp_t3, 0);
//                                             func_80349280_75A930(temp_v0_2, temp_t3);
//                                             break;
//                                         case 1:
//                                             temp_t3 = (arg0 * 6) >> 3;
//                                             temp_v0_2->health = MAX(temp_v0_2->health - temp_t3, 0);
//                                             func_80349280_75A930(temp_v0_2, temp_t3);
//                                             break;
//                                         case 2:
//                                             temp_t3 = (arg0 * 4) >> 3;
//                                             temp_v0_2->health = MAX(temp_v0_2->health - temp_t3, 0);
//                                             func_80349280_75A930(temp_v0_2, temp_t3);
//                                             break;
//                                         case 3:
//                                             temp_t3 = (arg0 * 3) >> 3;
//                                             temp_v0_2->health = MAX(temp_v0_2->health - temp_t3, 0);
//                                             func_80349280_75A930(temp_v0_2, temp_t3);
//                                             break;
//                                         case 4:
//                                             temp_t3 = (arg0 * 2) >> 3;
//                                             temp_v0_2->health = MAX(temp_v0_2->health - temp_t3, 0);
//                                             func_80349280_75A930(temp_v0_2, temp_t3);
//                                             break;
//                                         }
//                                         if (D_803D5538 != 0) {
//                                             temp_v0_2->unk2EB++;
//                                         }
//                                     }
//                                 } else {
//                                     if ((temp_v0_2->unk4A == 0) && (temp_v0_2->unk4C.pad0 & 4)) {
//                                         temp_v0_2->yVelocity.w += FTOFIX32(10.0); // (s32) (temp_v0_2->yVelocity.w + 0xA0000);
//                                         // temp_v0_2->unk4F = (u8) (temp_v0_2->unk4F | 0x40);
//                                         temp_v0_2->unk4C.unk24 = 1;
//                                     }
//                                     if ((temp_v0_2->unk4A == 0) && (temp_v0_2->unk4C.unk25)) { // (temp_v0_2->unk4C << 0x1A) >= 0)
//                                         temp_v0_2->health = MIN(temp_v0_2->health - 1, 0);
//                                     }
//                                 }
//                                 temp_v0_2->unk57 = 21;
//                             } else if ((temp_a0_2 < (arg1 * 2)) &&
//                                        (temp_v0_2->unk4A == 0) &&
//                                        (temp_v0_2->unk4C.pad0 & 4)) {
//                                 temp_v0_2->yVelocity.w += FTOFIX32(6.0);
//                                 // temp_v0_2->unk4F = (u8) (temp_v0_2->unk4F | 0x40);
//                                 temp_v0_2->unk4C.unk24 = 1;
//                             }
//                         }
//                     }
//                 }
//             }
//             sp98++;
//         }
//         sp9A++;
//     }
//     func_8034220C_7538BC(0xF, sp8E, sp8C, D_803D5530->yPos.h);
// }

// velocity related?
void func_8037D994_78F044(s8 arg0) {
    D_803D554B = arg0;
    D_803D554C = MIN(D_803D554C + 2, 20);
}

void func_8037D9D4_78F084(void) {
    D_803D554C = MIN(D_803D554C + 1, 5);
}

// jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037DA08_78F0B8.s")

// some loops
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E1C4_78F874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037E6DC_78FD8C.s")

Animal *func_8037E9AC_79005C(void) {
    s32 pad2[4];
    s16 sp56;
    s16 sp54;
    s32 pad[2];
    s16 xPosDelta, zPosDelta;
    Animal *ret;
    Animal *a;
    s16 temp_f6;
    s16 temp_lo;
    s16 phi_v0;
    s16 phi_v1;
    s16 phi_s5;
    s16 phi_v1_3;
    s16 i;

    s16 tmp;

    s16 xPos;
    s16 zPos;


    ret = NULL;
    phi_s5 = 0; // best distance?

    xPos = D_803D5530->xPos.h;
    zPos = D_803D5530->zPos.h;

    sp56 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 9;
    sp54 = D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 9;

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != 0) && (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER)) {
            if ((D_801D9ED8.animals[i].animal->unk366 != 6) && (D_801D9ED8.animals[i].animal->unk366 != 2) && (D_801D9ED8.animals[i].animal->unk366 != 5)) {
                if ((D_803D5530 != D_801D9ED8.animals[i].animal) && (func_802EA3E0_6FBA90(D_803D5530->unk16C->objectType, D_801D9ED8.animals[i].animal->unk16C->objectType) != 7)) {

                    a = D_801D9ED8.animals[i].animal;

                    xPosDelta = xPos - a->xPos.h;
                    zPosDelta = zPos - a->zPos.h;

                    phi_v0 = ABS(xPosDelta);
                    phi_v1 = ABS(zPosDelta);

                    if ((s16) (MAX(phi_v0, phi_v1) + (MIN(phi_v0, phi_v1) >> 1)) < 0x500) {
                        temp_f6 = sqrtf((xPosDelta * xPosDelta) + (zPosDelta * zPosDelta));
                        tmp = temp_f6;
                        if (temp_f6 == 0) {
                            tmp = 1;
                        }
                        temp_lo = -((xPosDelta * sp56) + (zPosDelta * sp54)) / tmp;
                        if (temp_lo > 32) {
                            phi_v1_3 = ((temp_lo * 3) / 4) + 16;
                        } else {
                            phi_v1_3 = 0;
                        }
                        temp_lo = (s16) (((0x500 - temp_f6) << 6) / 1280) * phi_v1_3;
                        if (phi_s5 < temp_lo) {
                            phi_s5 = temp_lo;
                            ret = a;
                        }
                    }
                }
            }
        }
    }

    return ret;
}

Animal *func_8037ED1C_7903CC(void) {
    s32 pad[4];
    s16 temp_fp;
    s16 var_a3;
    s32 pad2[2];

    s16 xPosDelta, zPosDelta;

    Animal *ret;
    Animal *animal;

    s16 temp_f6;
    s16 temp_lo;

    s16 var_a0;
    s16 var_s4;
    s16 var_v0;
    s16 var_v1_3;
    s16 var_v1_4;

    s16 i;

    s16 xPos;
    s16 zPos;

    var_s4 = 0;
    ret = NULL;

    xPos = D_803D5530->xPos.h;
    zPos = D_803D5530->zPos.h;

    temp_fp = D_80152C78[D_803D552C->unk302 & 0xFF] >> 9;
    var_a3 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 9;

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) && (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) && (D_801D9ED8.animals[i].animal->unk366 != 6)) {
            if (D_803D5530 != D_801D9ED8.animals[i].animal) {

                animal = D_801D9ED8.animals[i].animal;
                xPosDelta = xPos - animal->xPos.h;
                zPosDelta = zPos - animal->zPos.h;

                var_a0 = ABS(xPosDelta);
                var_v0 = ABS(zPosDelta);

                if ((s16) ((MAX(var_a0, var_v0)) + (MIN(var_a0, var_v0) >> 1)) < 320) {
                    if (ABS(D_803D5530->yPos.h - animal->yPos.h) < 320) {
                        temp_f6 = sqrtf((xPosDelta * xPosDelta) + (zPosDelta * zPosDelta));
                        var_v1_3 = temp_f6;
                        if (temp_f6 == 0) {
                            var_v1_3 = 1;
                        }
                        temp_lo = -((xPosDelta * temp_fp) + (zPosDelta * var_a3)) / var_v1_3;
                        if (temp_lo > 20) {
                            var_v1_4 = temp_lo;
                        } else {
                            var_v1_4 = 0;
                        }

                        temp_lo = (s16) (((0x500 - temp_f6) << 6) / 1280) * var_v1_4;
                        if (var_s4 < temp_lo) {
                            var_s4 = temp_lo;
                            ret = animal;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

// used by fox + camel (warp?)
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F07C_79072C.s")
// s16 func_8037F07C_79072C(s16 arg0, s32 arg1) {
//     s16 sp88;
//     s16 sp86;
//     s16 zPos; // sp7C
//     s16 sp7A;
//     s16 sp76;
//     s16 sp74;
//     s16 sp72;
//     s16 temp_a2;
//     s16 xPos;
//     s16 temp_v0_5;
//     s16 var_a3;
//     s16 var_s0;
//     s16 var_s3;
//     s16 var_s4;
//     s16 var_s5;
//     s16 var_v0;
//     u8 temp_s1;
//     s16 temp_v1_2;
//     s16 var_v0_3;
//     u8 temp_v0_3;
//     u8 temp_v1;
//
//     sp88 = D_80152C78[arg1 & 0xFF] >> 7;
//     sp86 = D_80152C78[(arg1 + 0x40) & 0xFF] >> 7;
//
//     xPos = D_803D5530->xPos.h;
//     zPos = D_803D5530->zPos.h;
//     sp7A = D_803D5530->yPos.h;
//
//     for (var_s5 = 0x20; var_s5 < arg0; var_s5 += 0x20) {
//         if (D_803D5530->unk162 != 1) {
//             var_s3 = xPos + ((sp88 * var_s5) >> 8);
//             var_s4 = zPos + ((sp86 * var_s5) >> 8);
//             var_s0 = MIN(sp7A, func_8031124C_7228FC(var_s3, var_s4) >> 0x10) + 8;
//         } else {
//             if ((D_803D5530->unk160 == 0) || (D_803D5530->unk160 == 1)) {
//                 var_s3 = xPos + ((sp88 * var_s5) >> 8);
//                 var_s4 = zPos + ((sp86 * var_s5) >> 8);
//                 var_s0 = (func_8031124C_7228FC(var_s3, var_s4) + 8) >> 0x10;
//             } else {
//                 var_s3 = xPos + ((sp88 * var_s5) >> 8);
//                 var_s4 = zPos + ((sp86 * var_s5) >> 8);
//                 temp_v1_2 = func_80310F58_722608(var_s3, var_s4) >> 0x10;
//                 if (temp_v1_2 == 0x4000) {
//                     var_s0 = (func_8031124C_7228FC(var_s3, var_s4) + 8) >> 0x10;
//                 } else {
//                     var_s0 = temp_v1_2 + 8;
//                 }
//             }
//         }
//
//         temp_s1 = func_803136FC_724DAC(var_s3, var_s4, var_s0); // & 0xFF;
//         if (((temp_s1 == 1) && (D_803D5530->unk160 == 2)) ||
//             ((temp_s1 == 2) && (D_803D5530->unk160 == 1))) {
//
//             func_80311A2C_7230DC(var_s3, var_s4, &sp76, &sp74, temp_s1);
//
//             if (func_8033C9CC_74E07C(xPos, zPos, sp7A + 0x10, D_803D5530->unk160, var_s3, var_s4, var_s0, temp_s1, 0, 0) == 0) {
//                 if (((ABS(var_s0 - sp7A) < 0x50) && (func_802B75CC_6C8C7C(D_803D5530, 0, var_s3 << 0x10, var_s4 << 0x10, var_s0 << 0x10, &sp72, 1) == 0)) && ((ABS(sp76) < 0x18) && (ABS(sp74) < 0x18))) {
//                     break;
//                 }
//             }
//         }
//     }
//
//     temp_v0_5 = var_s5 - 0x30;
//     var_s5 = arg0;
//     if (temp_v0_5 < arg0) {
//         var_s5 = temp_v0_5;
//     }
//
//     if (var_s5 > 16) {
//         if (D_803D5530->unk160 == 2) {
//             var_s3 = xPos + ((sp88 * var_s5) >> 8);
//             var_s4 = zPos + ((sp86 * var_s5) >> 8);
//
//             temp_v1_2 = func_80310F58_722608(var_s3, var_s4) >> 0x10;
//             if (temp_v1_2 == 0x4000) {
//                 var_a3 = MAX(sp7A, func_8031124C_7228FC(var_s3, var_s4) >> 0x10);
//             } else {
//                 var_a3 = MAX(temp_v1_2, sp7A);
//             }
//         } else {
//             var_s3 = xPos + ((sp88 * var_s5) >> 8);
//             var_s4 = zPos + ((sp86 * var_s5) >> 8);
//             var_a3 = MAX(sp7A, func_8031124C_7228FC(var_s3, var_s4) >> 0x10);
//         }
//
//         temp_a2 = var_a3 + 0x10;
//         D_803D5530->xPos.h = var_s3;
//         D_803D5530->zPos.h = var_s4;
//         D_803D5530->yPos.h = temp_a2;
//
//         D_803D5530->xVelocity.h = 0;
//         D_803D5530->zVelocity.h = 0;
//         D_803D5530->yVelocity.h = 0;
//
//         D_803D5530->unk160 = func_803136FC_724DAC(var_s3, var_s4, temp_a2);
//         return var_s5;
//     }
//     return 0;
// }

// used by rat
#ifdef NON_MATCHING
// just the stack to fix up
void func_8037F6CC_790D7C(s32 arg0, s16 arg1, s16 damage) {
    s16 pad[4];
    s16 sp9A;
    s16 sp98;
    s16 sp90;
    s16 temp_a2;
    s16 temp_a3_2;
    s16 temp_v1;
    s16 var_a0;
    s16 var_t1;
    s16 var_t2;
    s16 var_v1;
    s16 temp_a3;
    s16 temp_v0;
    s16 var_t3;
    s16 var_t4;
    s16 var_t5;

    Animal *animal;
    struct065 *var_s2;

    // temp_t0 = D_803D5530;
    var_t1 = D_803D5530->xPos.h;
    temp_v0 = var_t1 >> 0xA;
    var_t2 = D_803D5530->zPos.h;
    temp_a3 = var_t2 >> 0xA;

    var_t5 = -1;
    var_t3 = -1;
    sp90 = 1;
    var_t4 = 1;

    if ((temp_v0 + 1) >= 5) {
        var_t4 = 0;
    }
    if (temp_v0 <= 0) {
        var_t3 = 0;
    }
    if ((temp_a3 + 1) >= 8) {
        sp90 = 0;
    }
    if (temp_a3 <= 0) {
        var_t5 = 0;
    }

    for (sp9A = temp_v0 + var_t3; sp9A <= (temp_v0 + var_t4); sp9A++) {
        for (sp98 = temp_a3 + var_t5; sp98 <= (temp_a3 + sp90); sp98++) {

            for (var_s2 = D_803DA110[(s16) (sp9A + (sp98 * 5))].next; var_s2 != NULL; var_s2 = var_s2->next) {
                if (var_s2 == &var_s2->animal->unk11C) {
                    if (var_s2->animal != D_803D5530) {
                        animal = var_s2->animal;

                        if (1) { } if (1) { } // regalloc!

                        temp_a2 = var_t1 - animal->xPos.h;
                        temp_a3_2 = var_t2 - animal->zPos.h;

                        var_a0 = ABS(temp_a2);
                        var_v1 = ABS(temp_a3_2);

                        temp_v1 = MAX(var_a0, var_v1) + (MIN(var_a0, var_v1) >> 1);
                        if (animal->unk16C->unk80.bit) {
                            if ((animal->unk16C->unk9C != EVO_TRANSFER) && (animal->unk16C->unk9C != KING_RAT) && (animal->unk16C->unk9C != RAT)) {
                                if (temp_v1 < arg1 * 2) {
                                    if (ABS(D_803D5530->yPos.h - animal->yPos.h) < arg1) {
                                        if (temp_v1 < arg1) {
                                            animal->xVelocity.w -= (temp_a2 << 0x10) / temp_v1;
                                            animal->zVelocity.w -= (temp_a3_2 << 0x10) / temp_v1;
                                            if ((D_803D5544 & 3) == 0) {

                                                animal->health = MAX(animal->health - damage, 0);
                                                func_80349280_75A930(animal, damage);

                                                animal->unk348 = MAX(100, animal->unk348);
                                                animal->unk34A = MAX(40, animal->unk34A);
                                            }
                                        } else {
                                            animal->xVelocity.w -= (temp_a2 << 0xF) / temp_v1;
                                            animal->zVelocity.w -= (temp_a3_2 << 0xF) / temp_v1;
                                        }
                                    }
                                }
                            }
                        }
                        if (temp_v1 < arg1 * 2) {
                            if (ABS(D_803D5530->yPos.h - animal->yPos.h) < arg1) {
                                animal->unk57 = 6;
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037F6CC_790D7C.s")
#endif

//missile model (on animal) disappearing and left-right missile selector function
u8 func_8037FBBC_79126C(void) {
    switch (D_803D5524->unk9C) {
    case RACING_DOG:
    case SKI_HUSKY:
    case WALRUS:
    case HYENA_BIKER:
        if ((D_803D552C->missileScaleLeft == 8) && (D_803D552C->missileScaleRight == 8)) {
            if (D_803D552C->missileSide != 0) {
                D_803D552C->missileSide = 0; // *next* missile should come from right side
                D_803D552C->missileScaleLeft = 0;
            } else {
                D_803D552C->missileSide = 1; // *next* missile should come from left side
                D_803D552C->missileScaleRight = 0;
            }
        } else if (D_803D552C->missileScaleRight < D_803D552C->missileScaleLeft) {
            D_803D552C->missileSide = 0;
            D_803D552C->missileScaleLeft = 0;
        } else {
            D_803D552C->missileSide = 1;
            D_803D552C->missileScaleRight = 0;
        }
        break;
    case FIRE_FOX:
        D_803D552C->missileScaleLeft = 0;
    }

    return D_803D552C->missileSide;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78E970/func_8037FCA8_791358.s")
// NON-MATCHING: almost...
// void func_8037FCA8_791358(void) {
//     s32 phi_a0;
//     s16 tmp;
//
//     if (D_803D552C->missileScaleLeft != 0) {
//         D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
//     }
//     if (D_803D552C->missileScaleRight != 0) {
//         D_803D552C->missileScaleRight = MIN(D_803D552C->missileScaleRight + 1, 8);
//     }
//     if (D_803D5524->unk9C == POLAR_TANK) {
//         phi_a0 = 0;
//     } else {
//         phi_a0 = 1;
//     }
//     // this isnt right
//     phi_a0 = (phi_a0 << 2) - phi_a0;
//     tmp = ((D_803D552C->skillAEnergy[phi_a0 * 2] + (D_803D5524->unkDA[1+phi_a0] * 8)) / D_803D5524->unkDA[0+phi_a0]);
//     if (tmp == 1) {
//         if ((D_803D552C->missileScaleLeft == 0) && (D_803D552C->missileScaleRight == 0)) {
//             if (D_803D552C->missileSide == 0) {
//                 D_803D552C->missileScaleRight = 1;
//             } else {
//                 D_803D552C->missileScaleLeft = 1;
//             }
//         }
//     } else if (tmp >= 2) {
//         if (D_803D552C->missileScaleLeft == 0) {
//             D_803D552C->missileScaleLeft += 1;
//         }
//         if (D_803D552C->missileScaleRight == 0) {
//             D_803D552C->missileScaleRight += 1;
//         }
//     }
// }

void func_8037FE24_7914D4(void) {
    s16 tmp;

    if (D_803D552C->missileScaleLeft != 0) {
        D_803D552C->missileScaleLeft = MIN(D_803D552C->missileScaleLeft + 1, 8);
    }
    tmp = ((D_803D552C->skillBEnergy[0] + (D_803D5524->unkE0[1] * 8)) / D_803D5524->unkE0[0]);
    if ((tmp > 0) && (D_803D552C->missileScaleLeft == 0)) {
        D_803D552C->missileScaleLeft = 1;
    }
}

// used by sheep
void func_8037FEDC_79158C(void) {
    s16 i;
    s16 zPosDelta;
    s16 xPosDelta;

    play_sound_effect_at_location(SFX_SHEEP_BAA, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);

    // iterate over all animals in the level
    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != NULL) &&
            (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) &&
            (D_801D9ED8.animals[i].animal->unk366 != 6) &&
            (D_801D9ED8.animals[i].animal != D_803D5530) &&
            ((u8)D_801D9ED8.animals[i].animal->unk2A0 == 0) &&
            ((D_801D9ED8.animals[i].unk0->unk9C == SHEEP) || (D_801D9ED8.animals[i].unk0->unk9C == SPRINGY_THINGY))) {
            xPosDelta = ABS(D_801D9ED8.animals[i].animal->xPos.h - D_803D5530->xPos.h);
            if (xPosDelta < 200) {
                zPosDelta = ABS(D_801D9ED8.animals[i].animal->zPos.h - D_803D5530->zPos.h);
                if (zPosDelta < 200) {
                    if ((D_801D9ED8.animals[i].animal->unk287 == 0) && (D_803D552C->unk28A == 0)) {
                        D_801D9ED8.animals[i].animal->unk287 = 1;
                        if (D_803D5530) {};
                        D_801D9ED8.animals[i].animal->unk288 = (xPosDelta + zPosDelta) >> 3;
                        // swarm? follow?
                        func_80363E88_775538(D_801D9ED8.animals[i].animal, D_803D5530);
                    }
                }
            }
        }
    }
    func_8037E6DC_78FD8C(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 200, 15);
}
