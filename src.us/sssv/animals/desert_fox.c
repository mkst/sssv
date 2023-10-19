#include <ultra64.h>
#include "common.h"


extern u8 D_803B4E78_7C6528[];
extern u8 D_803B4E84_7C6534[];

extern s16 D_803B4E90_7C6540[];
extern s16 D_803B4EA4_7C6554[];
extern s16 D_803B4ED0_7C6580[];
extern s16 D_803B4EFC_7C65AC[];

extern Gfx D_04004A00_EBFB0[];
extern Gfx D_04004530_EBAE0[];
extern Gfx D_04004D70_EC320[];
extern Gfx D_04005770_ECD20[];
extern Gfx D_04005050_EC600[];
extern Gfx D_04004150_EB700[];
extern Gfx D_04004C90_EC240[];
extern Gfx D_04004330_CBD60[];

// ARMED_DESERT_FOX
#ifdef NON_MATCHING
//CURRENT (88)
void func_803726E0_783D90(void) {
    s32 pad[4];

    s32 spB4; // tbd
    s16 spB0[2];
    s16 spAE;
    s16 spAC; // pad
    s16 spAA;
    s16 var_a1; // spA8 ?

    Animal *target; // sp58

    s16 temp_a1;
    s16 temp_t3;
    s16 temp_t6;
    s32 temp_t8;

    u8 temp_v0_9;
    s16 temp_v0;
    s16 var_a0;
    u16 ticks_remaining;

    f32 var_f14;
    f32 sp88;
    f32 var_f0;
    f32 xDist;
    f32 yDist;


    if (D_803D552C->unk348 >= 0x191) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                ((u8*)D_803D5530) + 2,
                0x3A,
                ((0, (f32) ((D_803D552C->unk348 - 400.0) / 120.0))) * 20480.0f, // macro?
                0,
                0.5f,
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spAE = 0;
        D_803F2EDD = 0;
    } else {
        spAE = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0xB28, 6, 0x66, 0x33, 0, 0, (CHECK_SEGMENT == 0));
    }

    if (spAE == 0) {
        func_8038C98C_79E03C();
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B975C_6CAE0C(&spB4, 0x127, 1);
            func_802C23F8_6D3AA8(0x2D1);
            if (D_803D5524->unk9C == ARMED_DESERT_FOX) {
                D_80203FE0[0].unk4 += 0x148;
                D_80203FE0[1].unk4 += 0x148;
                D_80203FE0[2].unk4 += 0x148;
                D_80203FE0[15].unk4 += 0x148;
                D_80203FE0[18].unk4 += 0x148;
            }
            func_802C4A70_6D6120(0x20D, 0x83, 6);
            func_802BBFA0_6CD650(0x41A);
            func_8034B3A8_75CA58(0);
            func_8038CCF0_79E3A0(0x83, 0x13, 0x14, -1, -1, -1);
        }
        spAA = 0;
        var_a1 = 1;

        switch (D_803D5524->unk9C) {
        case DESERT_FOX:
            switch (D_803D552C->unk365) {
            case ATTACK_DESERT_FOX_1:
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                if (ticks_remaining < 8) {
                    D_803F2ECE = 3;
                    D_803F2ECC = ticks_remaining * 4;
                    spAA = ticks_remaining * 8;
                } else {
                    if (1) {};
                    D_803D552C->unk365 = ATTACK_NONE;
                    load_animal(DESERT_FOX_ATTACKING);
                    D_803D552C->unk30A = D_803D552C->unk348;
                    D_803D552C->unk348 = 1;
                    D_803D552C->unk34A = 1;
                }
                break;
            case ATTACK_DESERT_FOX_SPIN:
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                if (ticks_remaining < 0x10) {
                    D_803F2ECE = 3;
                    D_803F2ECC = 32 - (ticks_remaining * 2);
                    spAA = 64 - (ticks_remaining * 4);
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            break;
        case ARMED_DESERT_FOX:
            if (D_803D552C->unk365 == ATTACK_BEAR_2) { // ? ATTACK_SPIN/SWING_ARMS?
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                if (ticks_remaining < 8) {
                    temp_t8 = (8 - ticks_remaining) << 3;
                    if (temp_t8 > 0) {
                        var_a1 = temp_t8;
                    }

                    if ((ticks_remaining == 0) || (ticks_remaining == 1) || (ticks_remaining == 2)) {
                        if (ticks_remaining == 1) {
                            D_803D552C->unk302 += 5;
                        }
                        if (ticks_remaining == 2) {
                            D_803D552C->unk302 -= 5;
                        }
                        D_803D552C->unk302 &= 0xFF;

                        target = func_8037E9AC_79005C();
                        if (target != NULL) {

                            xDist = (f32) (D_803D5530->xPos.h - target->xPos.h); // f0
                            yDist = (f32) (D_803D5530->zPos.h - target->zPos.h); // f2
                            var_a0 = (s32) (target->unk42 * 3) >> 2;
                            if (target->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+SCORPION)) {
                                var_a0 = 5;
                            }

                            sp88 = (((D_803D5530->yPos.h - target->yPos.h) - var_a0) + 0x1E);
                            var_f0 = sqrtf((xDist * xDist) + (yDist * yDist));
                            var_f14 = func_801286B8(-sp88, var_f0) + SQ(((f64)var_f0 / 224.0));

                            while (var_f14 > 180.0) {
                                var_f14 -= 360.0;
                            }

                            // clamp between -45/+45
                            var_f14 = MIN(MAX(var_f14, -45.0f), 45.0f);
                        } else {
                            var_f14 = 0.0f;
                        }

                        fire_cannonball_1(OBJECT_CANNONBALL_2, 0x14, 9, 0x1E, 0x16, ((var_f14 * 256.0f) / 360.0f), 2, 8);
                        if (ticks_remaining == 1) {
                            D_803D552C->unk302 -= 5;
                        }
                        if (ticks_remaining == 2) {
                            D_803D552C->unk302 += 5;
                        } else if (ticks_remaining == 0) {
                            play_sound_effect_at_location(SFX_UNKNOWN_74, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                        }
                        D_803D552C->unk302 &= 0xFF;
                    }
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }

            D_80203FE0[27].unk0 = D_80203FE0[2].unk0;
            D_80203FE0[27].unk2 = D_80203FE0[2].unk2;
            D_80203FE0[27].unk4 = D_80203FE0[2].unk4 + 0x24E;

            D_80203FE0[28].unk0 = D_80203FE0[27].unk0;
            D_80203FE0[28].unk2 = D_80203FE0[27].unk2 + (((D_80152C78[var_a1 & 0xFF] >> 7) * 0x24E) >> 0xA);
            D_80203FE0[28].unk4 = D_80203FE0[27].unk4 + (((D_80152C78[(var_a1 + 0x40) & 0xFF] >> 7) * 0x24E) >> 0xA);
            break;
        }

        temp_v0 = D_80203FE0[20].unk0 - D_80203FE0[19].unk0;
        temp_a1 = D_80203FE0[20].unk2 - D_80203FE0[19].unk2;

        temp_t3 = (((temp_v0 * D_80152350.unk384[D_803D552C->unk316]) >> 8) + ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a1) >> 8));
        temp_t6 = (((temp_a1 * D_80152350.unk384[D_803D552C->unk316]) >> 8) - ((D_80152350.unk2D0[D_803D552C->unk316] * temp_v0) >> 8));

        D_80203FE0[20].unk0 = D_80203FE0[19].unk0 + temp_t3;
        D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + temp_t6;

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(D_803B4E78_7C6528, D_803B4E84_7C6534, D_803B4E90_7C6540, D_803B4EA4_7C6554);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4E78_7C6528, D_803B4E84_7C6534, D_803B4E90_7C6540, D_803B4ED0_7C6580);
                break;
            case 3:
                func_802DB670_6ECD20(D_803B4E78_7C6528, D_803B4E84_7C6534, D_803B4E90_7C6540, D_803B4EFC_7C65AC);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_9 = D_803F2AA2, (temp_v0_9 == 0)) || (temp_v0_9 == 2) || ((temp_v0_9 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, spAA - D_803D552C->unk302, D_803F2EB0 / 4,  D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.4f);

            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x54) >> 6, (D_803F2EC8 * 0x54) >> 6, (D_803F2EC8 * 0x54) >> 6, D_803F2ED0, 0, 0, 0, D_04004A00_EBFB0);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x54) >> 6, (D_803F2EC0 * 0x54) >> 6, (D_803F2EC4 * 0x54) >> 6, D_803F2ED0, 0, 0, 0, D_04004530_EBAE0);
            func_802C78B0_6D8F60(2, 26, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004D70_EC320);

            switch (D_803D5524->unk9C) {
            case ARMED_DESERT_FOX:
                func_802C78B0_6D8F60(19, 20, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04005770_ECD20);
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x1B, 0x1C, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04005050_EC600); }
                func_802C78B0_6D8F60(2, 15, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004150_EB700);
                func_802C78B0_6D8F60(2, 18, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 1, 0, D_04004150_EB700);
                break;
            case DESERT_FOX:
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x13, 0x14, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004C90_EC240); }
                func_802C78B0_6D8F60(2, 15, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004330_CBD60);
                gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
                gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
                func_802C78B0_6D8F60(2, 18, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 1, 0, D_04004330_CBD60);
                break;
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spAE == 0) || (spAE == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, D_01033190, 0xC, 0xC, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spAE == 0) {
        func_80303820_714ED0(D_803D552C, 1, 1, 0x1BA, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x189, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x375, 0x127);
  }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_803726E0_783D90.s")
#endif

// DESERT_FOX_ATTACKING
void func_80373788_784E38(void) {
    s32 pad2[0x5];
    s16 sp72;

    s32 var_v1;
    s32 var_v0;

    if (D_803D5530->unk4A == 0) {
        func_8032CD70_73E420(
            D_803D5530,
            0x23,
            0x5000,
            0,
            ((D_80152C78[(s16)(D_803D5540 << 4) & 0xFF] >> 7) / 400.0) + 1.0,
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h);
        func_8032CD70_73E420(
            ((u8*)D_803D5530) + 4,
            0x1F,
            0x5000,
            0,
            ((D_80152C78[((s16)(D_803D5540 << 5) + 0x40) & 0xFF] >> 7) / 100.0) + 4.0,
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h);
    }
    if (D_803D5530->unk4A == 0) {
        func_803224C4_733B74(0x18, 0, 0, 0x18, 1, 0, 0, 3);
    }
    if (D_803D5538 == 0) {
        D_803D552C->unk348 = 0x200;
        D_803D552C->unk34A = 0x32;
    }
    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            sp72 = 0;
            D_803F2EDD = 0;
            goto block_15;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    sp72 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0xB28, 6, 0x66, 0x33, 0, 0, var_v1 == 0);

block_15:
    if (sp72 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        D_803F2ECC = 0x20;
        func_802DB670_6ECD20(D_803B4E78_7C6528, D_803B4E84_7C6534, D_803B4E90_7C6540, D_803B4EFC_7C65AC);

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((var_v0 = D_803D5538) != 0) || ( ((var_v1 = D_803F2AA2) == 0)) || (var_v1 == 2) || ((var_v1 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (var_v0 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (D_803D5540 << 5) - D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, 0, 0);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.35f);

            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x54) >> 6, (D_803F2EC8 * 0x54) >> 6, (D_803F2EC8 * 0x54) >> 6, D_803F2ED0, 0, 0, 0, D_04004A00_EBFB0);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x54) >> 6, (D_803F2EC0 * 0x54) >> 6, (D_803F2EC4 * 0x54) >> 6, D_803F2ED0, 0, 0, 0, D_04004530_EBAE0);
            func_802C78B0_6D8F60(2, 26, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004D70_EC320);
            func_802C78B0_6D8F60(2, 15, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 0, 0, D_04004330_CBD60);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(2, 18, 0x15000, 0x15000, 0x15000, D_803F2ED0, 0, 1, 0, D_04004330_CBD60);

            if (func_8012826C() & 1) {
                create_particle_effect(
                    D_803D5530->xPos.h,
                    D_803D5530->zPos.h,
                    D_803D5530->yPos.h,
                    0x15,
                    SSSV_RAND(0x10000) - 0x8000,
                    SSSV_RAND(0x10000) - 0x8000,
                    0x10000,
                    0x1E,
                    GPACK_RGBA5551(248, 248, 0, 1), // yellow
                    GPACK_RGBA5551(248, 48, 0, 1),  // red
                    0);
            }
            if (SSSV_RAND(2)) {
                create_particle_effect(
                    D_803D5530->xPos.h,
                    D_803D5530->zPos.h,
                    D_803D5530->yPos.h,
                    0x18,
                    (SSSV_RAND(16) - 7) << 0xF,
                    (SSSV_RAND(16) - 7) << 0xF,
                    SSSV_RAND(16) << 0xF,
                    6,
                    GPACK_RGBA5551(248, SSSV_RAND(256), 0, 1),
                    GPACK_RGBA5551(248, SSSV_RAND(256), 0, 1),
                    0);
            }

            create_particle_effect(
                D_803D5530->xPos.h + (SSSV_RAND(16) - 8),
                D_803D5530->zPos.h + (SSSV_RAND(16) - 8),
                D_803D5530->yPos.h + (SSSV_RAND(64) + 16),
                0x15,
                SSSV_RAND(0x10000) - 0x8000,
                SSSV_RAND(0x10000) - 0x8000,
                SSSV_RAND(0x10000) - 0x8000,
                0x1E,
                GPACK_RGBA5551(168, 80, 0, 1),    // brown
                GPACK_RGBA5551(168, 104, 16, 1),  // lighter brown
                0);

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if (D_803F2D10.unk0 == 0) {
        if (D_803D5530->unk4A == 0) {
            if (D_803D5538 != 0) {
                D_803D5530->xVelocity.w += (((D_80152C78[ (s16)(D_803D5540 << 2)         & 0xFF] >> 7) * 7) << 4) + (((D_80152C78[ (s16)(D_803D5540 << 3)         & 0xFF] >> 7) * 3) << 4);
                D_803D5530->zVelocity.w += (((D_80152C78[((s16)(D_803D5540 << 2) + 0x40) & 0xFF] >> 7) * 7) << 4) - (((D_80152C78[((s16)(D_803D5540 << 3) + 0x40) & 0xFF] >> 7) * 2) << 4);
            } else {
                D_803D5530->xVelocity.w += (((D_80152C78[ (s16)(D_803D5540 << 2)         & 0xFF] >> 7) * 7) << 3) + (((D_80152C78[ (s16)(D_803D5540 << 3)         & 0xFF] >> 7) * 3) << 3);
                D_803D5530->zVelocity.w += (((D_80152C78[((s16)(D_803D5540 << 2) + 0x40) & 0xFF] >> 7) * 7) << 3) - (((D_80152C78[((s16)(D_803D5540 << 3) + 0x40) & 0xFF] >> 7) * 2) << 3);
            }
            D_803D5530->xVelocity.w += (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) << 6;
            D_803D5530->zVelocity.w += (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) << 6;
        }
    }
    if ((sp72 == 0) || (sp72 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, D_01033190, 0xC, 0xC, 0x9B, 0, 0, 0,0, D_803D5538);
    }
    if (sp72 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 1, 0x24E, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x83, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x375, 0x127);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            load_animal(DESERT_FOX);
        } else {
            D_803D552C->unk2EC--;
        }
    }
    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        load_animal(DESERT_FOX);
        D_803D552C->unk348 = 1;
        D_803D552C->unk34A = 1;
    }
}

void func_80374470_785B20(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_DESERT_FOX_1;
    } else {
        recharge_skill(1);
    }
}

void func_803744C4_785B74(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_BEAR_2;
    } else {
        recharge_skill(1);
    }
}

//Desert fox dizziness function
void func_80374518_785BC8(void) {
    load_animal(DESERT_FOX);

    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_DESERT_FOX_SPIN;

    if (D_803D5528->energy[1].unk0 < 900) {
        D_803D552C->unk348 = 512;
        D_803D552C->unk34A = 50;
    } else {
        D_803D552C->unk348 = MAX(D_803D552C->unk30A, D_803D552C->unk348);
        D_803D552C->unk30A = 0;
    }
}

void func_803745BC_785C6C(void) {
}

void func_803745C4_785C74(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == DESERT_FOX) {
        load_animal(DESERT_FOX_ATTACKING);
    }
}

void func_8037460C_785CBC(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_BEAR_2;
    } else {
        recharge_skill(1);
    }
}
