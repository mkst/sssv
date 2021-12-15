#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/frog/func_80302200_7138B0.s")
// void func_80302200_7138B0(void) {
//     u8 sp74[10];
//     s16 sp72;
//     s16 sp70;
//     s16 sp6E;
//     s16 sp6A;
//     s16 *temp_a0_2;
//     s16 temp_t0_5;
//     s16 temp_t4;
//     s16 temp_t5;
//     s16 temp_t7;
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s16 temp_v0_4;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     s16 temp_v1_5;
//     s32 temp_a0_3;
//     s32 temp_a0_4;
//     s32 temp_a3;
//     s32 temp_a3_2;
//     s32 temp_a3_3;
//     s32 temp_t1;
//     s32 temp_t5_2;
//     s32 temp_t8;
//     s32 temp_v0_16;
//     s32 temp_v0_17;
//     s32 temp_v0_19;
//     s32 temp_v0_5;
//     u16 temp_v0_12;
//     u16 temp_v0_15;
//     u16 temp_v0_7;
//     u16 temp_v0_8;
//     u8 temp_a0;
//     u8 temp_v0_13;
//     u8 temp_v0_18;
//     u8 temp_v0_3;
//     u8 temp_v0_9;
//     void *temp_t0;
//     s32 phi_v0;
//     s32 phi_v0_2;
//     s16 phi_v1;
//     s32 phi_t0;
//
//     switch (D_803D5538) {
//     case 0:
//         if (((D_803F2D70 == D_803D5524->unkD6) || (D_803D5524->unkD6 == 0)) && ((D_803F2D70 == 4) || (D_803F2D70 == 5))) {
//             phi_v0 = 1;
//         } else {
//             phi_v0 = 0;
//         }
//         if (phi_v0 != 0) {
//             sp70 = 0;
//             D_803F2EDD = (u8)0;
//             break;
//         }
//     default:
//         if (((D_803F2D70 == D_803D5524->unkD6) || (D_803D5524->unkD6 == 0)) && ((D_803F2D70 == 4) || (D_803F2D70 == 5))) {
//             phi_v0 = 1;
//         } else {
//             phi_v0 = 0;
//         }
//         sp70 = func_802E89F0_6FA0A0(*(s32*)&D_803D552C->xPos, *(s32*)&D_803D552C->zPos, *(s32*)&D_803D552C->yPos + (D_803D5524->unkBA << 0xF), 0x730, 0, 0, 0x9E, 0, 1, phi_v0 == 0);
//         break;
//     }
//
//     if (sp70 == 0) {
//         func_8034B298_75C948(0);
//         func_8035D120_76E7D0();
//         func_8035D734_76EDE4();
//         if (D_803D552C->unk365 != ATTACK_NONE) {
//             if (D_803D552C->unk365 != ATTACK_FROG_TONGUE) {
//                 D_803D552C->unk365 = ATTACK_NONE;
//             } else {
//                 func_802DCCAC_6EE35C(16);
//                 if ((D_803D5544 - D_803D552C->unk32A) == 4) {
//                     phi_v1 = func_803224C4_733B74(0x16, 0x54, 0, 0x1A, 0xF, 0, 0, 4);
//                     if (phi_v1 != 2) {
//                         phi_v1 |= func_803224C4_733B74(0x16, 0x38, 0, 0x1A, 0xF, 0, 0, 4);
//                         if (phi_v1 != 2) {
//                             phi_v1 |= func_803224C4_733B74(0x16, 0x1C, 0, 0x1A, 0xF, 0, 0, 4);
//                         }
//                     }
//                     if ((phi_v1 & 2) != 0) {
//                         play_sound_effect_at_location(68, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//                     }
//                 }
//             }
//         }
//         if ((D_803F2ECE == 0) || (((D_803F2ECC < 0x1F) != 0))) {
//             func_802B96D0_6CAD80(&sp74, 0x167, 0x262, 0);
//             func_802C1A44_6D30F4(0x262, 0x6B, &sp74);
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//             case 1:
//                 func_802DB670_6ECD20(&D_803A5520_7B6BD0, &D_803A5524_7B6BD4, &D_803A5528_7B6BD8, &D_803A5530_7B6BE0);
//                 break;
//             case 2:
//                 func_802DB670_6ECD20(&D_803A5520_7B6BD0, &D_803A5524_7B6BD4, &D_803A5528_7B6BD8, &D_803A5544_7B6BF4);
//                 break;
//             }
//         }
//         func_8038064C_791CFC();
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0)) {
//             if ((D_803D5538 == 0) && ((D_803F2AA2 != 0)) && (D_803F2AA2 != 2)) {
//                 if ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB)) {
// block_42:
//                     if ((D_803F2C18 == 0) && (D_803D5538 != 0)) {
//                         if ((D_803F28E0[D_803F2A98].unk0 == 3) || (D_803F28E0[D_803F2A98].unk0 == 0x11)) {
//                             if (D_803F28E0[D_803F2A98].unk64 != -3) {
// block_47:
//                                 func_80127640(&D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)], D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, -(s32) D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
//                                 gSPMatrix(D_801D9E88++, OS_PHYSICAL_TO_K0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//                                 D_80204278->usedModelViewMtxs = (s32) (D_80204278->usedModelViewMtxs + 1);
//
//                                 func_8038C230_79D8E0((s16) ((s32) ((D_803D5524)->unkBA * 8) / 5), 2, 3, 3, D_803BCFD0_7CE680);
//                                 func_8038C484_79DB34(2, 1, 3, 0xBEC28F5C, -0xBB8);
//                                 if (((s32) D_803D5530->state < 0x2C) && ((s32) D_803D5530->state >= 0x29)) {
//                                     D_803D552C->unk30A = (s16) (D_803D552C->unk30A - (D_803D552C->unk30E * 7));
//                                 }
//                                 if ((D_803F2D10.unk0 == 0) && ((D_803D552C->unk366 != 5)) && ((D_803D552C->unk366 != 2))) {
//                                     sp72 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.w * 0x10);
//                                     func_80300130_7117E0(&sp72, D_803D552C + 0x30A, 0x60, -0x100, 3, 3, D_803D5530->yVelocity.w * 0x10, 4);
//                                 } else {
//                                     sp72 = D_803D552C->unk308;
//                                 }
//                                 D_803D552C->unk308 = sp72;
//                                 if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90)) {
//                                     sp6E = (D_803D5540 << 5) & 0xFF;
//                                     func_8034B848_75CEF8(0);
//                                 } else if (D_803D5530->state == 0x8F) {
//                                     sp6E = (D_803D5540 << 6) & 0xFF;
//                                     func_8034B848_75CEF8(0);
//                                 } else {
//                                     sp6E = 0;
//                                 }
//                                 if (D_803F2EDD == 0) {
//                                     func_802C78B0_6D8F60(2, 0xE, 0xB800, 0xB800, (s32) ((sp72 * 0x2E0 * 2) + 0x2E0000) >> 6, D_803F2ED0, sp6E, 0, 0, D_040088F0);
//                                 }
//                                 D_80203FE0[2].unk4 += sp72 * 3;
//                                 D_80203FE0[1].unk4 += sp72 * 3;
//                                 if (D_803F2ED8 != 0) {
//                                     temp_v0_17 = D_803F2ED8 << 0xB;
//                                     temp_a3 = (s32) ((temp_v0_17 - (sp72 << 5)) * 0x2E) >> 6;
//                                     func_802C78B0_6D8F60(1, 2, temp_a3, temp_a3, (s32) ((temp_v0_17 + (sp72 << 6)) * 0x2E) >> 6, D_803F2ED0, 0, 0, 0, D_040089E0);
//                                 }
//                                 func_80356410_767AC0(D_04008C10, D_04008A10);
//                                 temp_a3_2 = (s32) ((0x10000 - (sp72 << 5)) * 0x2E) >> 6;
//                                 func_802C78B0_6D8F60(1, 2, temp_a3_2, temp_a3_2, (s32) (((sp72 << 6) * 0x2E) + 0x2E0000) >> 6, D_803F2ED0, 0, 0, 0, D_04008290);
//                                 temp_t8 = D_803D5540 & 0x7F;
//                                 temp_t5 = D_803D552C->unk30E * 50;
//                                 if (temp_t8 < 8) {
//                                     temp_a0_3 = temp_t8 << 5;
//                                     phi_t0 = (s32) temp_t5;
//                                     if (temp_a0_3 >= (s32) temp_t5) {
//                                         phi_t0 = (s32) (s16) temp_a0_3;
//                                     }
//                                 } else if (temp_t8 < 16) {
//                                     phi_t0 = 0x100;
//                                 } else {
//                                     phi_t0 = (s32) temp_t5;
//                                     if (temp_t8 < 0x18) {
//                                         temp_a0_4 = 0x300 - (temp_t8 << 5);
//                                         phi_t0 = (s32) temp_t5;
//                                         if (temp_a0_4 >= (s32) temp_t5) {
//                                             phi_t0 = (s32) (s16) temp_a0_4;
//                                         }
//                                     }
//                                 }
//                                 if ((D_803D552C->unk366 == 5) || (D_803D552C->unk366 == 2)) {
//                                     phi_t0 = 0xFF;
//                                 }
//                                 temp_t5_2 = (s32) (((((((((phi_t0 * 4) - phi_t0) * 4) - phi_t0) * 4) + phi_t0) * 8) - phi_t0) * 8) >> 0xC;
//                                 D_80203FE0[1].unk4 += temp_t5_2;
//                                 D_80203FE0[2].unk4 += temp_t5_2;
//                                 if (phi_t0 < 256) {
//                                     temp_a3_3 = (s32) ((D_803F2EC8 - (sp72 << 5)) * 0x2E) >> 6;
//                                     func_802C78B0_6D8F60(1, 2, temp_a3_3, temp_a3_3, (s32) (((s32) ((0x100 - phi_t0) * (D_803F2EC8 + (sp72 << 6))) >> 8) * 0x2E) >> 6, D_803F2ED0, 0, 0, 0, D_04008420);
//                                 }
//
//                                 gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//
//                             }
//                         } else {
//                             goto block_47;
//                         }
//                     } else {
//                         goto block_47;
//                     }
//                 }
//             } else {
//                 goto block_42;
//             }
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((sp70 == 0) || (sp70 == 2)) {
//         func_8034BD20_75D3D0(D_803D552C->xPos, D_803D552C->zPos, (s16) (D_803D552C->yPos + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, D_01033190, 0xF, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
//     }
//     if (sp70 == 0) {
//         func_80303820_714ED0(D_803D552C, 1, 2, 0x21A, 0);
//         func_80303D50_715400(D_803D552C, 1);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 0x21A, 0x262);
//     }
// }

void func_80302D5C_71440C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_FROG_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void frog_croak(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_FROG_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}
