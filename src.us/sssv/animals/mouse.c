#include <ultra64.h>
#include "common.h"

#include "structs.h"
#include "variables.us.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031C7A0_72DE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031D624_72ECD4.s")
// void func_8031D624_72ECD4(void) {
//     struct061 sp98;
//     s16 sp96;
//     s16 sp94;
//     s16 sp92;
//     s16 sp90;
//
//     f32 temp_f12;
//     s16 temp_t0_5;
//     s16 temp_t1_2;
//     s16 temp_t2;
//     s16 temp_t3;
//     f32 phi_f0;
//     s32 phi_a1;
//     s32 phi_v0;
//
//     s32 pad[6];
//
//     if (D_803D552C->unk366 == 1) {
//         if (D_803D554C != 0) {
//             if (D_803D5530->unk4A == 0) {
//                 func_8032CD70_73E420(
//                     D_803D5530,
//                     100,
//                     (((D_803D554C / 60.0) + D_803BD9B8_7CF068) * 14848.0),
//                     0,
//                     (f32) ((D_803D554C / 30.0) + 1.0),
//                     D_803D5530->xPos.h,
//                     D_803D5530->zPos.h,
//                     D_803D5530->yPos.h);
//             }
//         }
//     }
//     if ((sp92 != 4) && (sp92 != 1) && (D_803D5530->unk162 == 1)) {
//         temp_f12 = sqrtf(((f32)D_803D552C->xVelocity.w * (f32)D_803D552C->xVelocity.w) + ((f32)D_803D552C->zVelocity.w * (f32)D_803D552C->zVelocity.w)) / (D_803D5524->unkA4 << 0xA);
//         if (temp_f12 < 0.2) { // D_803BD9C0_7CF070
//             phi_f0 = 0.0f;
//         } else if (0.6 < temp_f12) { // D_803BD9C8_7CF078
//             phi_f0 = 1.0f;
//         } else {
//             phi_f0 = (temp_f12 - 0.2) * 2.5; // D_803BD9C0_7CF070
//         }
//         if (phi_f0 > 0.0) {
//             if (D_803D5530->unk4A == 0) {
//                 func_8032CED0_73E580(
//                     D_803D5530,
//                     13,
//                     (12288.0f * phi_f0) * 0.5,
//                     (2.0 * temp_f12),
//                     0,
//                     (s32) D_803D5538,
//                     (s32) D_803D552C->xPos.h,
//                     (s32) D_803D552C->zPos.h,
//                     (s32) D_803D552C->yPos.h,
//                     D_803D552C->xVelocity.w,
//                     D_803D552C->zVelocity.w,
//                     D_803D552C->yVelocity.w);
//             }
//         }
//     }
//     if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
//         create_particle_effect(
//             D_803D5530->xPos.h,
//             D_803D5530->zPos.h,
//             D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
//             (SSSV_RAND(2) + 25),
//             (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625), // 1024 / 625
//             (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
//             0,
//             SSSV_RAND(16) + 0xA,
//             GPACK_RGBA5551(0, 0, 0, 1),
//             GPACK_RGBA5551(0, 0, 0, 1),
//             SSSV_RAND(16) + 0xF);
//
//         if (D_803D552C->unk2EC-- <= 0) {
//             D_803D552C->unk36E = 0;
//         }
//     }
//
//     switch (D_803D5538) {
//     case 1:
//     default:
//         if ((D_803F2D50.segment == D_803D5524->biome) ||
//             ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
//             phi_a1 = 1;
//         } else {
//             phi_a1 = 0;
//         }
//         if (phi_a1 != 0) {
//             sp92 = 0;
//             D_803F2EDD = 0;
//             break;
//         }
//         temp_t3 = D_803D5524->biome;
//     case 0:
//         if ((D_803F2D50.segment == D_803D5524->biome) ||
//             ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
//             phi_v0 = 1;
//         } else {
//             phi_v0 = 0;
//         }
//         sp92 = func_802E89F0_6FA0A0(
//             D_803D552C->xPos.w,
//             D_803D552C->zPos.w,
//             D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
//             0x640,
//             7,
//             0x3F,
//             0x51,
//             0x9E,
//             1,
//             phi_v0 == 0);
//     }
//
//     if (sp92 == 0) {
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if (D_803D552C->unk366 == 5) {
//             if (D_803D5528->unk3C8.unk2 != 0) {
//                 D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 4;
//             }
//         } else if ((D_803D5538 != 0) && (D_803F2D30.unk4 > 16)) {
//             if (D_803D5528->unk3C8.unk2 != 0) {
//                 D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 4;
//             }
//         } else {
//             if (D_803D5528->unk3C8.unk2 != 0) {
//                 D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 4;
//             }
//         }
//         if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
//             if (D_803D5538 != 0) {
//                 sp90 = (((D_803D554C * 0x9C) >> 1) / 20);
//             } else {
//                 sp90 = 0;
//             }
//             // sp90 = phi_v0_2;
//             func_802B9130_6CA7E0(&sp98, 0x7D, 0x46, 0xEA, 0);
//             func_802C1830_6D2EE0(0x9C, &sp98);
//             func_802B964C_6CACFC();
//             D_80203FE0[7].unk4  += sp90; // (s16) (D_80203FE0.unk3C + sp90);
//             D_80203FE0[10].unk4 += sp90; // (s16) (D_80203FE0.unk54 + sp90);
//             D_80203FE0[8].unk4  += sp90; // (s16) (D_80203FE0.unk44 + sp90);
//             D_80203FE0[11].unk4 += sp90; // (s16) (D_80203FE0.unk5C + sp90);
//             D_80203FE0[1].unk4  += sp90; // (s16) (D_80203FE0.unkC + sp90);
//             D_80203FE0[0].unk4  += sp90 >> 1; // (s16) (D_80203FE0.unk4 + ((s32) sp90 >> 1));
//             func_802C6468_6D7B18(0xBB, 0xDA, 0x177);
//             // phi_v0_3 = D_803F2ECC;
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {                      /* irregular */
//             case 1:
//                 func_802DB670_6ECD20(D_803A5D98_7B7448, D_803A5DAC_7B745C, D_803A5DC0_7B7470, D_803A5DE4_7B7494);
//                 break;
//             case 2:
//                 func_802DB670_6ECD20(D_803A5D98_7B7448, D_803A5DAC_7B745C, D_803A5DC0_7B7470, D_803A5E34_7B74E4);
//                 break;
//             }
//         }
//         func_8038064C_791CFC();
//         // temp_t0_2 = D_80204278;
//         // temp_t1 = D_80204278->unk38918;
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
//             (D_803F2EDA != 0) &&
//             ((D_803D5538 != 0) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) &&
//             ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
//             // temp_v1_7 = D_803D5530;
//             func_80127640(
//                 &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
//                 D_803D5530->xPos.w,
//                 D_803D5530->zPos.w,
//                 D_803D5530->yPos.w,
//                 -(s32) D_803D552C->unk302,
//                 (s32) D_803F2EB0 / 4,
//                 (s32) D_803F2EB4 / 4,
//                 (s32) D_803F2EB8 / 4,
//                 (s32) D_803F2ED2,
//                 D_803F2ED4);
//             gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//             D_80204278->usedModelViewMtxs +=1 ;// = (s32) (temp_t0_4->unk38918 + 1);
//
//             func_8038C230_79D8E0(((D_803D5524->unkBA * 8) / 5), 2, 3, 3, -0.32); // D_803BD9D0_7CF080
//             func_802C78B0_6D8F60(2, 1, (s32) (D_803F2EBC * 0xA) >> 6, (s32) (D_803F2EC0 * 0xA) >> 6, (s32) (D_803F2EC4 * 0xA) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_04006040_105D90);
//             D_80203FE0[1].unk2  += 0x3E; //(s16) (D_80203FE0.unkA + 0x3E);
//             D_80203FE0[19].unk2 += 0x3E; //(s16) (D_80203FE0.unk9A + 0x3E);
//             D_80203FE0[20].unk2 += 0x3E; //(s16) (D_80203FE0.unkA2 + 0x3E);
//             D_80203FE0[22].unk2 += 0x3E; //(s16) (D_80203FE0.unkB2 + 0x3E);
//             D_80203FE0[23].unk2 += 0x3E; //(s16) (D_80203FE0.unkBA + 0x3E);
//             // temp_a3 = (s32) (D_803F2EC8 * 0xA) >> 6;
//             func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_04005A50_1057A0);
//             if (D_803F2EDD == 0) {
//                 func_802C78B0_6D8F60(7, 8, 0x2800, 0x2800, 0x2800, (s32) D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0);
//             }
//             func_802C78B0_6D8F60(10, 11, 0x2800, 0x2800, 0x2800, (s32) D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0);
//             func_802C78B0_6D8F60(13, 14, 0x2800, 0x2800, 0x2800, (s32) D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0);
//             if (D_803F2EDD == 0) {
//                 func_802C78B0_6D8F60(16, 17, 0x2800, 0x2800, 0x2800, (s32) D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0);
//             }
//             // temp_a3_2 = (s32) (D_803F2EC8 * 0xA) >> 6;
//             func_802C78B0_6D8F60(19, 22, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_040053D0_105120);
//             // temp_a3_3 = (s32) (D_803F2EC8 * 0xA) >> 6;
//             func_802C78B0_6D8F60(19, 23, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (s32) D_803F2ED0, 0, 1, 0, D_040053D0_105120);
//             if (D_803F2EDD == 0) {
//                 func_8031A150_72B800(D_803D552C->unk326++, &sp96, &sp94);
//                 func_8031A278_72B928(&D_803D552C->unk326, &sp96, &sp94);
//
//                 sp96 = D_803BD5B2_7CEC62[sp96];
//                 sp94 = D_803BD66A_7CED1A[sp94]; // * 2));
//                 func_80356BD8_768288(D_01000CA0, D_01002100, sp96);
//                 func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_04006B00_106850);
//
//                 func_80356BD8_768288(D_01000CA0, D_01002100, sp94);
//                 func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (s32) D_803F2ED0, 0, 0, 0, D_04006B60_1068B0);
//             }
//             gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((sp92 == 0) || (sp92 == 2)) {
//         func_8034BD20_75D3D0(
//             D_803D552C->xPos.h,
//             D_803D552C->zPos.h,
//             D_803D552C->yPos.h + ((s32) (D_803D5524->unkBA * 7) >> 3),
//             D_803D552C->unk302,
//             D_01033190,
//             7,
//             7,
//             0x9B,
//             0,
//             0,
//             0,
//             0,
//             (s32) D_803D5538);
//     }
//
//     if (D_803D5528->unk3C8.unk2 != 0) {
//         if ((sp92 == 0) && (D_803F2EDB != 0)) {
//             temp_t0_5 = D_80203FF2;
//             temp_t1_2 = D_80152C78[D_803D552C->unk302 & 0xFF]; // + ((temp_v0_7 & 0xFF) * 2));
//             temp_t3 = D_80203FF0;
//             temp_t2 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF]; // + (((temp_v0_7 + 0x40) & 0xFF) * 2));
//             func_802DE914_6EFFC4(
//                 D_803D5528->unk3C8.unk2,
//                 D_803D5530->xPos.w + ((s32) (temp_t0_5 * temp_t1_2) / 32) + ((s32) (temp_t2 * temp_t3) / 32),
//                 (D_803D5530->zPos.w + ((s32) (temp_t2 * temp_t0_5) / 32)) - ((s32) (temp_t3 * temp_t1_2) / 32),
//                 D_803D5530->yPos.w + ((s32) (D_80203FF4 << 0x10) / 32),
//                 D_803D552C->unk302);
//             if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
//                 if (D_803E00C0[D_803D5528->unk3C8.unk2].unk2E == 3) {
//                     func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3B4C_7B51FC);
//                 } else {
//                     func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3BAC_7B525C);
//                 }
//             }
//             D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
//         } else {
//             D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
//         }
//     }
//     if (sp92 == 0) {
//         func_803034D0_714B80(D_803D552C, 0xFA, 0x75, 1);
//         func_80303820_714ED0(D_803D552C, 0x13, 0x14, 0x9C, 0);
//         func_80303D50_715400(D_803D552C, 3);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 0x177, 0x7D);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031E6A0_72FD50.s")
// void func_8031E6A0_72FD50(void) {
//     struct061 spB0; //[11]; // tbd
//     s16 spAA;
//     s16 spA6;
//     s16 temp_t0_11;
//     s16 temp_t1_4;
//     s16 temp_v1_4;
//     s32 temp_t2;
//     s32 temp_t3;
//     s16 phi_v1;
//     s16 phi_v0;
//     s16 phi_t6;
//
//     switch (D_803D5538) {
//     case 1:
//     default:
//         if ((D_803F2D50.segment == D_803D5524->biome) ||
//             ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
//             phi_v1 = 1;
//         } else {
//             phi_v1 = 0;
//         }
//         if (phi_v1 != 0) {
//             spA6 = 0;
//             D_803F2EDD = 0;
//             break;
//         }
//         // fallthru
//     case 0:
//         if ((D_803F2D50.segment == D_803D5524->biome) ||
//             ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
//             phi_v0 = 1;
//         } else {
//             phi_v0 = 0;
//         }
//         spA6 = func_802E89F0_6FA0A0(
//             D_803D552C->xPos.w,
//             D_803D552C->zPos.w,
//             D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
//             0x640,
//             7,
//             0x3F,
//             0x51,
//             0x9E,
//             1,
//             phi_v0 == 0);
//     }
//
//     if (spA6 == 0) {
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if (D_803D5528->unk3C8.unk2 != 0) {
//             D_803E00C0[D_803D5528->unk3C8.unk2].unk2E = 5;
//         }
//         if ((D_803D552C->unk365 == ATTACK_NONE) && (SSSV_RAND(32) == 0xC)) {
//             D_803D552C->unk365 = 46;
//             D_803D552C->unk32A = D_803D5544;
//         }
//         func_803224C4_733B74(5, 5, 0, 0x10, 0, 0, 0, 0x10);
//
//         spAA = 128;
//         switch (D_803D552C->unk365) {                        /* irregular */
//         case ATTACK_MOUSE_TAIL:
//             temp_v1_4 = D_803D5544 - D_803D552C->unk32A;
//             spAA = temp_v1_4 * 21;
//             if (temp_v1_4 >= 6) {
//                 D_803D552C->unk365 = 46;
//                 D_803D552C->unk32A = (u16) D_803D5544;
//             }
//             break;
//         case ATTACK_MOUSE_2:
//             temp_v1_4 = D_803D5544 - D_803D552C->unk32A;
//             spAA = 128 - (temp_v1_4 * 21);
//             if (temp_v1_4 >= 6) {
//                 D_803D552C->unk365 = ATTACK_NONE;
//                 load_animal(RACING_MOUSE);
//             }
//             break;
//         // is this mouse radar?
//         case 46:
//             temp_v1_4 = D_803D5544 - D_803D552C->unk32A;
//             if (temp_v1_4 == 1) {
//                 play_sound_effect_at_location(SFX_CHEAT_ENABLED, 0x2400, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
//             }
//             if (temp_v1_4 < 7) {
//                 if (temp_v1_4 < 4) {
//                     phi_t6 = temp_v1_4 << 3;
//                 } else {
//                     phi_t6 = (7 - temp_v1_4) << 3;
//                 }
//                 create_particle_effect(
//                     D_803D5530->xPos.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * 3) >> 5),
//                     D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * 3) >> 5),
//                     D_803D5530->yPos.h + 0xA,
//                     0x58,
//                     D_803D5530->xVelocity.w,
//                     D_803D5530->zVelocity.w,
//                     D_803D5530->yVelocity.w,
//                     phi_t6,
//                     GPACK_RGBA5551(248, 248, 0, 1),   // yellow
//                     GPACK_RGBA5551(248, 248, 128, 1), // pale yellow
//                     0);
//             } else {
//                 D_803D552C->unk365 = 0;
//             }
//             break;
//         }
//         if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
//             func_802B9130_6CA7E0(&spB0, 0x7D, 0x46, 0xEA, 0);
//             func_802C1830_6D2EE0(0x9C, &spB0);
//             func_802B964C_6CACFC();
//             func_802C6468_6D7B18(0xBB, 0xDA, 0x177);
//         }
//         func_8038064C_791CFC();
//
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
//             (D_803F2EDA != 0) &&
//             ((D_803D5538 != 0) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 > 10))) &&
//             ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
//
//             func_80127640(
//                 &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
//                 D_803D5530->xPos.w,
//                 D_803D5530->zPos.w,
//                 D_803D5530->yPos.w,
//                 (spAA - D_803D552C->unk302) & 0xFF,
//                 D_803F2EB0 / 4,
//                 D_803F2EB4 / 4,
//                 D_803F2EB8 / 4,
//                 D_803F2ED2,
//                 D_803F2ED4);
//
//             gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//
//             D_80204278->usedModelViewMtxs += 1;
//             func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, D_803BD9D4_7CF084);
//             func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0xA) >> 6, (D_803F2EC0 * 0xA) >> 6, (D_803F2EC4 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006040_105D90);
//             D_80203FE0[1].unk2  += 0x3E;
//             D_80203FE0[19].unk2 += 0x3E;
//             D_80203FE0[20].unk2 += 0x3E;
//             D_80203FE0[22].unk2 += 0x3E;
//             D_80203FE0[23].unk2 += 0x3E;
//             func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005A50_1057A0); // mouse head
//
//             gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);
//
//             if (D_803F2EDD == 0) {
//                 func_802C78B0_6D8F60(7, 8, 0x2800, 0x2800, 0x2800, D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0); // racing mouse wheel
//             }
//             func_802C78B0_6D8F60(10, 11, 0x2800, 0x2800, 0x2800, D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0); // racing mouse wheel
//             func_802C78B0_6D8F60(13, 14, 0x2800, 0x2800, 0x2800, D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0); // racing mouse wheel
//             if (D_803F2EDD == 0) {
//                 func_802C78B0_6D8F60(16, 17, 0x2800, 0x2800, 0x2800, D_803F2ED0, 0, 0, 0, D_04005CA0_1059F0); // racing mouse wheel
//             }
//             func_802C78B0_6D8F60(19, 22, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_040053D0_105120); // mouse ear
//             func_802C78B0_6D8F60(19, 23, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 1, 0, D_040053D0_105120); // mouse ear
//
//             if (D_803F2EDD == 0) {
//                 func_80356BD8_768288(D_01000CA0, D_01002100, *D_803BD5B6_7CEC66);
//                 func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B00_106850);
//
//                 func_80356BD8_768288(D_01000CA0, D_01002100, *D_803BD66E_7CED1E);
//                 func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B60_1068B0);
//             }
//
//             guLookAtReflect(
//                 &D_80204278->unk38CD0[D_80204278->unk39310],
//                 &D_80204278->unk38A50[D_80204278->unk39310],
//                 D_803F2C44,
//                 D_803F2C48,
//                 D_803F2C4C,
//                 (f32) D_803D5530->xPos.w / 65536.0,
//                 (f32) D_803D5530->zPos.w / 65536.0,
//                 (f32) D_803D5530->yPos.w / 65536.0,
//                 D_80204200,
//                 D_80204204,
//                 D_80204208);
//
//             gDPSetTextureLUT(D_801D9E88++, G_TT_NONE);
//             gSPLookAtX(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[0]);
//             gSPLookAtY(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[1]);
//             gDPPipeSync(D_801D9E88++);
//             D_80204278->unk39310 += 1;
//
//             gSPDisplayList(D_801D9E88++, D_01004270);
//             gSPDisplayList(D_801D9E88++, D_01004AF8);
//             gDPSetRenderMode(D_801D9E88++, D_803C0640_7D1CF0, G_RM_AA_ZB_OPA_SURF2);
//             gDPSetTextureImage(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_01030810);
//             gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//             gDPLoadSync(D_801D9E88++);
//             gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1023, 256);
//             gDPPipeSync(D_801D9E88++);
//             gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//             gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
//
//             func_802C78B0_6D8F60(2, 1, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005480_1051D0); // mouse tail
//             gSPDisplayList(D_801D9E88++, D_01003460);
//             gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((spA6 == 0) || (spA6 == 2)) {
//         func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (D_803D552C->yPos.h + ((D_803D5524->unkBA * 7) >> 3)), D_803D552C->unk302, D_01033190, 7, 7, 0x9B, 0, 0, 0, 0, D_803D5538);
//     }
//
//     if (D_803D5528->unk3C8.unk2 != 0) {
//         if ((spA6 == 0) && (D_803F2EDB != 0)) {
//             temp_t0_11 = D_80152C78[D_803D552C->unk302 & 0xFF];
//             temp_t2 = -D_80203FF2;
//             temp_t1_4 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF];
//             temp_t3 = -D_80203FF0;
//             func_802DE914_6EFFC4(
//                 D_803D5528->unk3C8.unk2,
//                 D_803D5530->xPos.h + ((temp_t2 * temp_t0_11) / 32) + ((temp_t1_4 * temp_t3) / 32),
//                 D_803D5530->zPos.h + ((temp_t1_4 * temp_t2) / 32) - ((temp_t3 * temp_t0_11) / 32),
//                 D_803D5530->yPos.h + ((D_80203FF4 << 0x10) / 32),
//                 D_803D552C->unk302);
//
//             if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
//                 if (D_803E00C0[D_803D5528->unk3C8.unk2].unk2E == 3) {
//                     func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3B4C_7B51FC);
//                 } else {
//                     func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3BAC_7B525C);
//                 }
//             }
//             D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
//         } else {
//             D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
//         }
//     }
//     if (spA6 == 0) {
//         func_803034D0_714B80(D_803D552C, 250, 117, 1);
//         func_80303820_714ED0(D_803D552C, 19, 20, 156, 0);
//         func_80303D50_715400(D_803D552C, 3);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 375, 125);
//     }
//     if (D_803D5538 == 0) {
//         if (D_803D552C->unk2EC <= 0) {
//             switch (D_803D552C->unk365) {
//             case ATTACK_MOUSE_2:
//                 D_803D552C->unk365 = ATTACK_MOUSE_2;
//                 break;
//             case ATTACK_MOUSE_TAIL:
//                 D_803D552C->unk32A = D_803D5544;
//                 break;
//             }
//         } else {
//             D_803D552C->unk2EC--;
//         }
//     }
//     if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
//         load_animal(RACING_MOUSE);
//     }
// }

void func_8031F858_730F08(void) {
    rmonPrintf("Helimouse is gone\n");
}

void func_8031F87C_730F2C(void) {
    load_animal(MOUSE2);
}

void func_8031F89C_730F4C(void) {
    load_animal(MOUSE);
}

void func_8031F8BC_730F6C(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 10,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(16) + 0xF);
    } else {
        func_8037D994_78F044(16); // not animal id
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 10,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(16) + 0xF);
    }
}

// load racing mouse?
void func_8031FA84_731134(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    load_animal(HARD_MOUSE);
    D_803D552C->unk365 = ATTACK_MOUSE_TAIL;
    D_803D552C->unk32A = D_803D5544;
}

void func_8031FAD8_731188(void) {
    if (D_803D552C->unk365 != ATTACK_MOUSE_2) {
        if ((D_803D5544 - (u16)D_803D552C->unk32A) >= 8) {
            if (D_803D552C->unk365 != ATTACK_MOUSE_TAIL) {
                D_803D552C->unk32A = D_803D5544;
            }
            D_803D552C->unk365 = ATTACK_MOUSE_2;
        }
    }
}

void func_8031FB30_7311E0(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == MOUSE) {
        load_animal(MOUSE2);
    }
}

void func_8031FB78_731228(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_MOUSE) {
        load_animal(HARD_MOUSE);
        D_803D552C->unk365 = ATTACK_MOUSE_TAIL;
        D_803D552C->unk32A = D_803D5544;
    }
}

void racing_mouse_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
