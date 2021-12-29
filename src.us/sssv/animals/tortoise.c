#include <ultra64.h>
#include "common.h"

s32 func_8035E344_76F9F4(struct037 *arg0, s16 arg1);

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355130_7667E0.s")
// void func_80355130_7667E0(void) {
//     s32 sp88;
//     s16 sp86;
//     f64 temp_f0;
//
//     s32 temp_v1;
//
//     u8 temp_v0_6;
//
//     struct025 *temp_v0_7;
//
//     f64 phi_f2;
//     s32 phi_v1_2;
//     s32 phi_t0_2;
//
//     if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//         func_8032CD70_73E420(D_803D5530, 175, 0x6000, 0, 1.0f, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
//     }
//
//     if (D_803D5530->unk162 == 1) {
//         temp_f0 = (f32) ((ABS(D_803D5530->xVelocity.w) + ABS(D_803D5530->zVelocity.w)) / 655360.0);
//         if (D_803BEAE8 < temp_f0) {
//             phi_f2 = MIN(temp_f0 - D_803BEAE8, D_803BEAF0);
//             func_8032CD70_73E420(
//                 D_803D5530 + 0x22,
//                 0x3F,
//                 (phi_f2 * 8192.0),
//                 0,
//                 (temp_f0 * 0.5) + D_803BEAF8_7D01A8,
//                 D_803D5530->xPos,
//                 D_803D5530->zPos,
//                 D_803D5530->yPos);
//         }
//     }
//     if (D_803D5538 != 0) {
//         if (D_803F2D70 != D_803D5524->unkD6) {
//             if (D_803D5524->unkD6 == 0) {
//                 if ((D_803F2D70 == 4) || (D_803F2D70 == 5)) {
// block_17:
//                     phi_v1_2 = 1;
//                 } else {
// block_18:
//                     phi_v1_2 = 0;
//                 }
//             } else {
//                 goto block_18;
//             }
//         } else {
//             goto block_17;
//         }
//         if (phi_v1_2 != 0) {
//             sp86 = 0;
//             D_803F2EDD = (u8)0;
//         } else {
// block_21:
//             if (D_803F2D70 != D_803D5524->unkD6) {
//                 if (D_803F2D70 == 0) {
//                     if ((D_803F2D70 == 4) || (D_803F2D70 == 5)) {
// block_25:
//                         phi_t0_2 = 1;
//                     } else {
// block_26:
//                         phi_t0_2 = 0;
//                     }
//                 } else {
//                     goto block_26;
//                 }
//             } else {
//                 goto block_25;
//             }
//             sp86 = func_802E89F0_6FA0A0(D_803D552C->xPos, D_803D552C->zPos, D_803D552C->yPos + (D_803D5524->unkBA << 0xF), 0x740, 0, 0, 0x5A, 0, 1, phi_t0_2 == 0);
//         }
//     } else {
//         goto block_21;
//     }
//     if (sp86 == 0) {
//         func_8035D120_76E7D0();
//         func_8035DA60_76F110();
//         func_8035D734_76EDE4();
//         if ((D_803F2ECE == 0) || (((D_803F2ECC < 31)))) {
//             func_802B9130_6CA7E0(&sp88, 0x1C5, 0x134, 0xB5, 0);
//             func_802B964C_6CACFC();
//         }
//         if (D_803F2ECC != 0) {
//             func_802DB8DC_6ECF8C();
//             switch (D_803F2ECE) {
//             case 1:
//                 func_802DB670_6ECD20(&D_803A8514_7B9BC4, &D_803A8518_7B9BC8, &D_803A8464_7B9B14, &D_803A8484_7B9B34);
//                 break;
//             case 2:
//                 func_802DB670_6ECD20(&D_803A8514_7B9BC4, &D_803A8518_7B9BC8, &D_803A8464_7B9B14, &D_803A84CC_7B9B7C);
//                 break;
//             }
//         }
//         func_803224C4_733B74(0x15, 0x15, 0, 0x10, 0, 0, 0, 0x10);
//         func_8038064C_791CFC();
//
//         if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0)) {
//             if ((D_803D5538 == 0) && (D_803F2AA2 != 0) && (D_803F2AA2 != 2)) {
//                 if ((D_803F2AA2 == 1) && ((s32) D_803F2AA3 >= 0xB)) {
// block_45:
//                     if ((D_803F2C18 == 0) && (D_803D5538 != 0)) {
//                         temp_v0_7 = &D_803F28E0[D_803F2A98];
//                         if ((temp_v0_7->unk0 == 3) || (temp_v0_7->unk0 == 17)) {
//                             if (temp_v0_7->unk64 != -3) {
// block_50:
//                                 func_80127640(D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)], D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, -(s32) D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
//                                 gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//                                 D_80204278->usedModelViewMtxs += 1;
//                                 func_80356410_767AC0(D_04003A50, D_04003850);
//                                 func_802C78B0_6D8F60(2, 1, (s32) (D_803F2EBC * 0x3A) >> 6, (s32) (D_803F2EC0 * 0x3A) >> 6, (s32) (D_803F2EC4 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04002D70);
//                                 gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
//
//                                 func_8034BD20_75D3D0(D_803D552C->xPos, D_803D552C->zPos, (s16) (D_803D552C->yPos + D_803D5524->unkBA), D_803D552C->unk302, D_01033190, 0x19, 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
//                             }
//                         } else {
//                             goto block_50;
//                         }
//                     } else {
//                         goto block_50;
//                     }
//                 }
//             } else {
//                 goto block_45;
//             }
//         }
//         func_8035D6A0_76ED50();
//     } else {
//         func_8035D6D0_76ED80();
//     }
//     if (sp86 == 0) {
//         func_803034D0_714B80(D_803D552C, 0x7F6, 0, 0);
//         func_80303D50_715400(D_803D552C, 2);
//     } else {
//         func_80303D00_7153B0(D_803D552C, 0x54F, 0x1C5);
//     }
//     if (D_803D5538 == 0) {
//         if (D_803D552C->unk2EC <= 0) {
//             play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB00_7D01B0);
//             if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//                 load_animal(TORTOISE_TANK);
//             } else {
//                 load_animal(RACING_TORTOISE);
//             }
//         } else {
//             D_803D552C->unk2EC -= 1;
//         }
//     }
//     if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
//         if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
//             load_animal(TORTOISE_TANK);
//         } else if (D_803D5524->unk9C == RACING_TORTOISE_ATTACKING) {
//             load_animal(RACING_TORTOISE);
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355918_766FC8.s")
// NON-MATCHING: still a fair bit to work out
// void func_80355918_766FC8(void) {
//     s16 temp_t0;
//     s16 temp_v1;
//     s16 phi_v1;
//
//     if ((D_803F28E0[D_803F2A98].unk0 == 3) || (D_803F28E0[D_803F2A98].unk0 == 17)) {
//         D_803D552C->unk30E = 0;
//         if (D_801D9ED8.unkFFC6 != 0) {
//             D_803D552C->unk30C -= 4;
//         }
//         if (D_801D9ED8.unkFFC8 != 0) {
//             D_803D552C->unk30C += 4;
//         }
//
//         D_803D552C->unk30C = MAX(-100, D_803D552C->unk30C);
//         D_803D552C->unk30C = MIN(100, D_803D552C->unk30C);
//
//         if ((D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {
//             func_80321E60_733510(
//                 OBJECT_CANNONBALL,
//                 32,
//                 0,
//                 20,
//                 25 - (D_803D552C->unk30C >> 3),
//                 (25 - (D_803D552C->unk30C >> 2)) + (D_803F2A9E / 3),
//                 2,
//                 45);
//             func_803421E0_753890(17);
//
//             D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
//
//             play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//             do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
//         }
//     } else {
//         if ((D_801D9ED8.unkFFB2 == 0) && (D_801D9ED8.unkFFB8 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {
//
//             if (D_803D552C->unk30E < 60) {
//                 phi_v1 = -D_803D552C->unk30E;
//             } else {
//                 phi_v1 = (-120 - -D_803D552C->unk30E);
//             }
//             temp_v1 = phi_v1 - ((D_803D552C->unk312 * 360) >> 8);
//             temp_t0 = -temp_v1;
//
//             phi_v1 = (((D_80152C78[(temp_v1 + 64) & 0xFF] >> 7) << 5) >> 8);
//
//             func_80321E60_733510(
//                 OBJECT_CANNONBALL,
//                 (phi_v1),
//                 0,
//                 (s16) (((((D_80152C78[temp_t0 & 0xFF]) >> 7) << 5) >> 8) + 16),
//                 10 - (temp_v1 / 3),
//                 temp_t0,
//                 2,
//                 45);
//             func_803421E0_753890(17);
//
//             D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
//
//             play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
//             do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
//         }
//         if (D_801D9ED8.unkFFB2 != 0) {
//             D_803D552C->unk30E = ((D_803D552C->unk30E + 1) % 120);
//             if ((D_803D552C->unk30E >= 60) || (D_803D5530->unk4A == 0)) {
//                 func_8032CD70_73E420(D_803D5530 + 2, 0x55, 0x3C00, 0, D_803BEB08_7D01B8, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
//             } else {
//                 func_8032CD70_73E420(D_803D5530 + 2, 0x55, 0x3C00, 0, D_803BEB04_7D01B4, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
//             }
//         } else {
//             D_803D552C->unk30E = (u16)0;
//         }
//     }
// }

void func_80355E14_7674C4(void) {
    func_80321E60_733510(OBJECT_CANNONBALL, 32, 0, 30, 10, 0, 2, 45);
    func_8034220C_7538BC(17, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_80355EDC_76758C(void) {
    recharge_skill(0);
}

// tortoise tank
void func_80355EFC_7675AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos,  D_803D5530->zPos, D_803D5530->yPos, D_803BEB0C);
    load_animal(TORTOISE_TANK_DEFENDING);
}

void func_80355F64_767614(void) {
    func_8037D994_78F044(20);
    if ((D_803D5540 & 1) == 0) {
        create_particle_effect(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    }
}

// racing tortoise
void func_80355FFC_7676AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB10);
    load_animal(RACING_TORTOISE_ATTACKING);
}

// tortoise tank
void func_80356064_767714(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB14);
    load_animal(TORTOISE_TANK);
}

// racing tortoise
void func_803560CC_76777C(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB18);
    load_animal(RACING_TORTOISE);
}

void func_80356134_7677E4(Animal *a) {
    s32 temp_v0;
    s16 rot;

    temp_v0 = func_802F8160_709810(D_803D5530, a, 32, 20, 30, 0x59, -4, 3, (f32)D_803A05B0 / 65536.0);
    if (temp_v0 == -1) {
        rot = 32;
    } else {
        rot = (temp_v0 * 256) / 360;
    }
    func_80322064_733714(OBJECT_CANNONBALL, 32, 0, 20, 30, D_803D5530->yRotation, rot, 2, 45);
    do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
    func_8034220C_7538BC(14, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_803562C8_767978(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == TORTOISE_TANK) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB1C);
        load_animal(TORTOISE_TANK_DEFENDING);
    }
}

void func_80356348_7679F8(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_TORTOISE) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB20);
        load_animal(RACING_TORTOISE_ATTACKING);
    }
}

void racing_tortoise_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 20;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
