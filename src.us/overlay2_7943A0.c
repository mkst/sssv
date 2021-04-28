#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7943A0/func_80382CF0_7943A0.s")
// 50% of the way there...
// void func_80382CF0_7943A0(void) {
//     s16 sp8A;
//     s16 sp86;
//     s16 sp84;
//     s32 sp6A;
//     s32 sp68;
//     f64 temp_f0;
//     f64 temp_f2;
//     f64 temp_f2_2;
//     s16 temp_a0_4;
//     s16 temp_a1_2;
//     s16 temp_a2;
//     s16 temp_a2_3;
//     s16 temp_a3;
//     s16 temp_v0;
//     s16 temp_v1_16;
//     s32 temp_a3_2;
//     s32 temp_a3_3;
//     s32 temp_t1_2;
//     u16 temp_a2_2;
//     u8 temp_a0;
//     u8 temp_a1;
//     u8 temp_a1_3;
//     u8 temp_v0_9;
//     struct025 *temp_v0_10;
//
//     s32 phi_a2;
//     s32 phi_t0;
//     s16 phi_v0;
//     u8 phi_a1;
//     s32 phi_a2_2;
//     s32 phi_t0_2;
//     s16 phi_a2_3;
//
//     if (D_803D5538 != 0) {
//         temp_a3 = D_803D5530->xVelocity;
//         if (temp_a3 < 0) {
//             phi_t0 = -temp_a3;
//         } else {
//             phi_t0 = temp_a3;
//         }
//
//         temp_v0 = D_803D5530->zVelocity;
//         if (temp_v0 < 0) {
//             phi_a2 = -temp_v0;
//         } else {
//             phi_a2 = temp_v0;
//         }
//         if ((phi_a2 + phi_t0) >= 0xB) {
//             if ((D_803D5530->yPos + 0x60) < (func_8031124C_7228FC((s16) (D_803D5530->xPos + ((s32) (temp_a3 * 3) >> 1)), (s16) (D_803D5530->zPos + ((s32) (temp_v0 * 3) >> 1)), 3, temp_a3) >> 0x10)) {
//                 D_803D5530->xVelocity = -D_803D5530->xVelocity >> 1;
//                 D_803D5530->zVelocity = -D_803D5530->zVelocity >> 1;
//                 func_801373CC(0, 0xD, 0x19, 5, 0);
//             }
//         }
//     }
//     if (D_803D553A == 8) {
//         play_sound_effect_at_location(9, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//     }
//     if (D_803D553A == 9) {
//         play_sound_effect_at_location(10, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//     }
//     if (D_803D5530->unk162 == 3) {
//         if (D_803D5538 != 0) {
//             if (D_803D552C->unk369 == 0) {
//                 if (D_801E9E8E == 0) {
//                     D_803D552C->unk369 = (u8)1U;
//                 }
//             } else {
//                 if (D_803D552C->unk369 == 1) {
//                     if (D_801E9E8E != 0) {
//                         if (D_803D5530->yVelocity < 5) {
//                             D_803D552C->unk369 = (u8)2U;
//                             D_803D5530->xVelocity +=  (D_80152C78[((D_803D552C->unk302 & 0xFF))]) * 0x13;
//                             D_803D5530->zVelocity +=  (D_80152C78[((((D_803D552C)->unk302 + 0x40) & 0xFF))]) * 0x13;
//                             temp_f0 = D_803D5530->xVelocity / 65536.0;
//                             temp_f2 = D_803D5530->zVelocity / 65536.0;
//                             temp_f2_2 = sqrtf(temp_f0 * temp_f0 + temp_f2 * temp_f2);
//                             if (temp_f2_2 > 20.0) {
//                                 D_803D5530->xVelocity =  (D_803D5530->xVelocity * 20.0) / temp_f2_2;
//                                 D_803D5530->zVelocity =  (D_803D5530->zVelocity * 20.0) / temp_f2_2;
//                             }
//                             if ((D_803D5530->yVelocity + 4) < 7) {
//                                 D_803D5530->yVelocity = 7;
//                             } else {
//                                 D_803D5530->yVelocity += 4;
//                             }
//                             if ((D_803D552C->unk308 - 25) < 0) {
//                                 D_803D552C->unk308 = 0;
//                             } else {
//                                 D_803D552C->unk308 -= 25;
//                             }
//                             play_sound_effect_at_location(0x20, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     if (D_803D5538 != 0) {
//         if (D_803F2D70 != D_803D5524->unkD6) {
//             if (D_803D5524->unkD6 == 0) {
//                 if ((D_803F2D70 == 4) || (D_803F2D70 == 5)) {
// block_35:
//                     phi_a2_2 = 1;
//                 } else {
// block_36:
//                     phi_a2_2 = 0;
//                 }
//             } else {
//                 goto block_36;
//             }
//         } else {
//             goto block_35;
//         }
//         if (phi_a2_2 != 0) {
//             sp8A = 0;
//             D_803F2EDD = (u8)0;
//         } else {
// block_39:
//             if (D_803F2D70 != D_803D5524->unkD6) {
//                 if (D_803D5524->unkD6 == 0) {
//                     if ((D_803F2D70 == 4) || (D_803F2D70 == 5)) {
// block_43:
//                         phi_t0_2 = 1;
//                     } else {
// block_44:
//                         phi_t0_2 = 0;
//                     }
//                 } else {
//                     goto block_44;
//                 }
//             } else {
//                 goto block_43;
//             }
//             sp8A = func_802E89F0_6FA0A0(D_803D552C->xPos, D_803D552C->zPos, D_803D552C->yPos + (D_803D5524->unkBA << 0xF), 0x800, 0, 0x3C, 0x3C, 0x78, 1, phi_t0_2 == 0);
//         }
//     } else {
//         goto block_39;
//     }
//     if (sp8A == 0) {
//         func_8034B45C_75CB0C();
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if ((D_803F2ECE == 0) || ((s32) D_803F2ECC < 0x1F)) {
//             func_80302E50_714500(0x1F4, 0x1F4, 0x1F4);
//             if (D_803D5530->state == 0x3F) {
//                 D_803D552C->unk308 = (s16) (D_803D552C->unk308 + 1);
//                 if ((s32) D_803D552C->unk308 >= 0x29) {
//                     phi_a2_3 = (u16)0x28;
//                 } else {
//                     temp_a2 = D_803D552C->unk308;
//                     D_803D552C->unk308 = (s16) (D_803D552C->unk308 + 1);
//                     phi_a2_3 = temp_a2;
//                 }
//                 temp_a1_2 = (s16) -(s32) (0x28 - (phi_a2_3 * 2));
//                 func_8030322C_7148DC(0, temp_a1_2);
//                 func_8030322C_7148DC(1, sp6A);
//                 func_8030322C_7148DC(2, sp6A);
//                 func_8030322C_7148DC(3, sp6A);
//             }
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//                 case 1:
//                     func_802DB670_6ECD20(&D_803B58A0, &D_803B58A4, &D_803B58A8, &D_803B58B0);
//                     break;
//                 case 2:
//                     func_802DB670_6ECD20(&D_803B58A0, &D_803B58A4, &D_803B58A8, &D_803B58C4);
//                     break;
//             }
//         }
//         func_8038064C_791CFC();
//         if (((D_80204278->unk38918 + 0x1E) < 0xFA) && (D_803F2EDA != 0)) {
//             if ((D_803D5538 == 0) && ((D_803F2AA2 != 0)) && (D_803F2AA2 != 2)) {
//                 if ((D_803F2AA2 == 1) && ((s32) D_803F2AA3 >= 0xB)) {
// block_67:
//                     if ((D_803F2C18 == 0) && (D_803D5538 != 0)) {
//                         temp_v0_10 = &D_803F28E0[D_803F2A98]; // * 0xDC) + &;
//                         temp_v1_16 = temp_v0_10->unk0;
//                         if ((temp_v1_16 == 3) || (temp_v1_16 == 0x11)) {
//                             if (temp_v0_10->unk64 != -3) {
// block_72:
//                                 func_80127640(&D_80204278->unk33590[D_80204278->unk38918], D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, -(s32) D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
//                                 gSPMatrix(D_801D9E88++, &D_80204278->unk33590[D_80204278->unk38918], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//                                 D_80204278->unk38918 += 1;
//                                 func_80356410_767AC0(0x4007DD0, 0x4007BD0);
//                                 func_802C78B0_6D8F60(0, 1, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, 0x4007500);
//                                 func_802C78B0_6D8F60(1, 2, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, 0x40077E0);
//                                 func_802C78B0_6D8F60(2, 3, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, 0x4007AE0);
//                                 if (D_803F2EDD == 0) {
//                                     temp_a0_4 = D_803D552C->unk326;
//                                     D_803D552C->unk326 = (s16) (D_803D552C->unk326 + 1);
//                                     func_8031A150_72B800(D_803D552C->unk326, &sp86, &sp84);
//                                     func_8031A278_72B928(D_803D552C->unk326, &sp86, &sp84);
//                                     temp_a2_3 = D_803BD54A[sp86];
//                                     sp86 = temp_a2_3;
//                                     sp84 = D_803BD602[sp84]; //((sp84 * 2) + 0x803C0000)->unk-29FE;
//                                     func_80356BD8_768288(0x1000D00, 0x1000620, temp_a2_3);
//                                     temp_a3_2 = (s32) (D_803F2EC8 << 6) >> 6;
//                                     func_802C78B0_6D8F60(1, 0, temp_a3_2, temp_a3_2, temp_a3_2,  D_803F2ED0, 0, 0, 0, 0x4007E70);
//                                     func_80356BD8_768288(0x1000D00, 0x1000620, sp84);
//                                     temp_a3_3 = (s32) (D_803F2EC8 << 6) >> 6;
//                                     func_802C78B0_6D8F60(1, 0, temp_a3_3, temp_a3_3, temp_a3_3,  D_803F2ED0, 0, 0, 0, 0x4007E90);
//                                 }
//                                 gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//                             }
//                         } else {
//                             goto block_72;
//                         }
//                     } else {
//                         goto block_72;
//                     }
//                 }
//             } else {
//                 goto block_67;
//             }
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((sp8A == 0) || (sp8A == 2)) {
//         func_8034BD20_75D3D0(D_803D552C->xPos, D_803D552C->zPos, (s16) (D_803D552C->yPos + D_803D5524->unkBA), D_803D552C->unk302, 0x1033190, 0x15, 9, 0x9B, 0, 0, 0, 0,  D_803D5538);
//     }
//     func_80303D00_7153B0(D_803D552C, 0x1F4, 0x1F4);
// }

void func_80383804_794EB4(void) {
}

void func_8038380C_794EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8038381C_794ECC(void) {
}
