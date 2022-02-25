#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/cool_cod/func_80382CF0_7943A0.s")
// 70% of the way there...
// void func_80382CF0_7943A0(void) {
//     s16 sp8A;
//     s16 sp86;
//     s16 sp84;
//     s16 sp6A;
//     s32 sp68;
//     f64 temp_f0;
//     f64 temp_f2;
//     f64 temp_f2_2;
//     s16 temp_a1_2;
//     u8 phi_t0_2;
//     s16 phi_a2;
//
//     if (D_803D5538 != 0) {
//         if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) >= 0xB) {
//             if ((D_803D5530->yPos + 0x60) < (func_8031124C_7228FC(D_803D5530->xPos + ((D_803D5530->xVelocity.h * 3) >> 1), (D_803D5530->zPos + ((D_803D5530->zVelocity.h * 3) >> 1))) >> 0x10)) {
//                 D_803D5530->xVelocity.h = -D_803D5530->xVelocity.h >> 1;
//                 D_803D5530->zVelocity.h = -D_803D5530->zVelocity.h >> 1;
//                 do_rumble(0, 0xD, 0x19, 5, 0);
//             }
//         }
//     }
//     if (D_803D553A == 8) {
//         play_sound_effect_at_location(SFX_UNKNOWN_9, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//     }
//     if (D_803D553A == 9) {
//         play_sound_effect_at_location(SFX_UNKNOWN_10, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//     }
//     if ((D_803D5530->unk162 == 3) && (D_803D5538 != 0)) {
//         if (D_803D552C->unk369 == 0) {
//             if (D_801E9E8E == 0) {
//                 D_803D552C->unk369 = 1U;
//             }
//         } else if ((D_803D552C->unk369 == 1) && (D_801E9E8E != 0) && (D_803D5530->yVelocity.h < 5)) {
//             D_803D552C->unk369 = 2U;
//             D_803D5530->xVelocity.w += D_80152C78[D_803D552C->unk302 & 0xFF] * 19;
//             D_803D5530->zVelocity.w += D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * 19;
//             temp_f0 = D_803D5530->xVelocity.w / 65536.0;
//             temp_f2 = D_803D5530->zVelocity.w / 65536.0;
//             temp_f2_2 = sqrtf(temp_f0 * temp_f0 + temp_f2 * temp_f2);
//             if (temp_f2_2 > 20.0) {
//                 D_803D5530->xVelocity.w = (D_803D5530->xVelocity.w * 20.0) / temp_f2_2;
//                 D_803D5530->zVelocity.w = (D_803D5530->zVelocity.w * 20.0) / temp_f2_2;
//             }
//             D_803D5530->yVelocity.h = MAX(7, D_803D5530->yVelocity.h + 4);
//             D_803D552C->unk308 = MAX(0, D_803D552C->unk308 - 25);
//
//             play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//         }
//     }
//
//     switch (D_803D5538) {
//     case 1:
//     default:
//         if ((D_803F2D70 == D_803D5524->biome) || ((D_803D5524->biome == 0) && ((D_803F2D70 == 4) || (D_803F2D70 == 5)))) {
//             phi_t0_2 = 1;
//         } else {
//             phi_t0_2 = 0;
//         }
//         if (phi_t0_2 != 0) {
//             sp8A = 0;
//             D_803F2EDD = 0;
//             break;
//         }
//         // fallthrough
//     case 0:
//         if ((D_803F2D70 == D_803D5524->biome) || ((D_803D5524->biome == 0) && ((D_803F2D70 == 4) || (D_803F2D70 == 5)))) {
//             phi_t0_2 = 1;
//         } else {
//             phi_t0_2 = 0;
//         }
//         sp8A = func_802E89F0_6FA0A0(
//             *(s32*)&D_803D552C->xPos,
//             *(s32*)&D_803D552C->zPos,
//             *(s32*)&D_803D552C->yPos + (D_803D5524->unkBA << 0xF),
//             0x800,
//             0,
//             60,
//             60,
//             120,
//             1,
//             phi_t0_2 == 0);
//     }
//
//     if (sp8A == 0) {
//         func_8034B45C_75CB0C();
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
//             func_80302E50_714500(500, 500, 500);
//             if (D_803D5530->state == 31) {
//                 // stuff is wrong around here
//                 D_803D552C->unk308++;
//                 if (D_803D552C->unk308++ > 40) {
//                     // D_803D552C->unk308 += 1;
//                     phi_a2 = 40;
//                 } else {
//                     phi_a2 = D_803D552C->unk308;
//                 }
//
//                 func_8030322C_7148DC(0, -(((phi_a2 * 2) - 40)));
//                 func_8030322C_7148DC(1, -(((phi_a2 * 2) - 40)));
//                 func_8030322C_7148DC(2, -(((phi_a2 * 2) - 40)));
//                 func_8030322C_7148DC(3, -(((phi_a2 * 2) - 40)));
//             }
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//                 case 1:
//                     func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, &D_803B58A8_7C6F58, &D_803B58B0_7C6F60);
//                     break;
//                 case 2:
//                     func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, &D_803B58A8_7C6F58, &D_803B58C4_7C6F74);
//                     break;
//             }
//         }
//         func_8038064C_791CFC();
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0)) {
//             if ((D_803D5538 == 0) && ((D_803F2AA2 != 0)) && (D_803F2AA2 != 2)) {
//                 if (((D_803F2AA2 == 1) && (D_803F2AA3 > 10)) ||
//                     ((D_803F2C18[0] == 0) && (D_803D5538 != 0)) ||
//                     ((D_803F28E0[D_803F2A98].cameraMode == 3) || (D_803F28E0[D_803F2A98].cameraMode != 0x11)) ||
//                      (D_803F28E0[D_803F2A98].unk64 != -3)) {
//                     func_80127640(
//                         &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
//                         *(s32*)&D_803D5530->xPos,
//                         *(s32*)&D_803D5530->zPos,
//                         *(s32*)&D_803D5530->yPos,
//                         -(s32) D_803D552C->unk302,
//                         D_803F2EB0 / 4,
//                         D_803F2EB4 / 4,
//                         D_803F2EB8 / 4,
//                         D_803F2ED2,
//                         D_803F2ED4);
//
//                     gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//
//                     D_80204278->usedModelViewMtxs++;
//                     load_1_tile(D_04007DD0, D_04007BD0);
//                     func_802C78B0_6D8F60(0, 1, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007500_E4AC0);
//                     func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040077E0_E4DA0);
//                     func_802C78B0_6D8F60(2, 3, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007AE0_E50A0);
//                     if (D_803F2EDD == 0) {
//                         // D_803D552C->unk326++;
//                         func_8031A150_72B800(D_803D552C->unk326, (u16*)&sp86, (u16*)&sp84);
//                         func_8031A278_72B928(&D_803D552C->unk326, (u16*)&sp86, (u16*)&sp84);
//
//                         sp86 = D_803BD54A[sp86]; // D_803BD530_7CEBE0[5 + sp86];
//                         sp84 = D_803BD602[sp84]; // D_803BD530_7CEBE0[105 + sp84];
//                         // load eyes?
//                         func_80356BD8_768288(D_01000D00, D_01000620, sp86);
//                         func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E70);
//                         func_80356BD8_768288(D_01000D00, D_01000620, sp84);
//                         func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E90);
//                     }
//                     gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//                 }
//             }
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if ((sp8A == 0) || (sp8A == 2)) {
//         func_8034BD20_75D3D0(
//             D_803D552C->xPos,
//             D_803D552C->zPos,
//             (D_803D552C->yPos + D_803D5524->unkBA),
//             D_803D552C->unk302,
//             D_01033190,
//             21,
//             9,
//             155,
//             0, // r
//             0, // g
//             0, // b
//             0,
//             D_803D5538);
//     }
//     func_80303D00_7153B0(D_803D552C, 500, 500);
// }

void func_80383804_794EB4(void) {
}

void func_8038380C_794EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8038381C_794ECC(void) {
}
