#include <ultra64.h>
#include "common.h"

extern u8 D_803B4200_7C58B0[];
extern u8 D_803B4208_7C58B8[];

extern s16 D_803B4210_7C58C0[];
extern s16 D_803B4218_7C58C8[];
extern s16 D_803B4230_7C58E0[];

extern u8 D_04001750[];
extern u8 D_04001330[];
extern u8 D_04001730[];

extern Gfx D_04001010_DE5D0[];
extern Gfx D_04001220_C8C50[];
extern Gfx D_04001890_DEE50[];
extern Gfx D_040012E0_DE8A0[];
extern Gfx D_04001A60_DF020[];
extern Gfx D_04001B60_DF120[];

#if 0
void func_80364780_775E30(void) {
    s16 spA8;
    s16 spA2;
    s16 spA0;
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;
    f32 sp88;
    f32 sp84;
    s32 sp5C;
    // Animal *temp_v0_10;
    // Animal *temp_v0_11;
    // Animal *temp_v0_12;
    // Animal *temp_v0_13;
    // Animal *temp_v0_16;
    // Animal *temp_v0_6;
    // Animal *temp_v0_7;
    Animal *target;
    // Animal *temp_v0_9;
    // Animal *temp_v1;
    // Animal *temp_v1_10;
    // Animal *temp_v1_2;
    // Animal *temp_v1_3;
    // Animal *temp_v1_4;
    // Animal *temp_v1_9;
    // Camera *temp_v0_15;
    // DisplayList *temp_t0;
    // DisplayList *temp_t0_2;
    // DisplayList *temp_t0_3;
    // Gfx *temp_v0_17;
    // Gfx *temp_v0_18;
    // Gfx *temp_v0_19;
    // Gfx *temp_v0_20;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f2;
    f32 var_f0_2;
    f32 var_f14;
    f64 temp_f2_2;
    f64 var_f0;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s16 temp_a0_6;
    s16 temp_t6;
    s16 temp_v0;
    s16 temp_v0_21;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_5;
    s16 temp_v1_7;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_lo;
    s32 temp_t1;
    s32 temp_t4;
    u16 temp_t5;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_v0;
    // u16 temp_a0;
    u16 temp_a0_4;
    u16 temp_a0_7;
    u16 var_v0_2;
    u8 temp_a0_5;
    u8 temp_a0_8;
    u8 temp_v0_14;
    u8 temp_v0_4;

    // temp_a0 = D_803D5524->unk9C;
    switch (D_803D5524->unk9C) {                              /* irregular */
    case PENGUIN:
        spA0 = 1;
        break;
    case KING_PENGUIN:
        spA0 = 2;  // scale>
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        }
        break;
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_a0 = 1;
        } else {
            var_a0 = 0;
        }
        if (var_a0 != 0) {
            spA2 = 0;
            D_803F2EDD = 0;
            goto block_15;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    spA2 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        ((spA0 * 0x300) << 6) / 32,
        (u8) 6,
        0x28,
        0x28,
        0x50,
        spA0 - 1,
        var_v0 == 0);

block_15:
    if (spA2 == 0) {
        if ((D_803D5538 != 0) && (D_803D5524->unk9C == 0x40) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 5))) {
            // temp_v1_3 = D_803D552C;
            // temp_v0_5 = D_803D552C->energy[0].unk0 + 0x32;
            // if (temp_v0_5 >= 0x401) {
            //     D_803D552C->energy[0].unk0 = 0x400;
            // } else {
            //     D_803D552C->energy[0].unk0 = temp_v0_5;
            // }
            D_803D552C->energy[0].unk0 = MIN(0x400, D_803D552C->energy[0].unk0 + 0x32);
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034B64C_75CCFC(0xC, 0x1A, 0xC);

        sp9E = 0;
        sp9C = 0;
        sp9A = 0;

        switch (D_803D5524->unk9C) {                        /* switch 1; irregular */
        case KING_PENGUIN:                                  /* switch 1 */
            break;
        case PENGUIN:                                  /* switch 1 */
            switch (D_803D552C->unk365) {                    /* switch 2; irregular */
            case ATTACK_PENGUIN_1:                                /* switch 2 */
                temp_t5 = (D_803D5544 - D_803D552C->unk32A); // & 0xFFFF;
                if (temp_t5 == 2) {
                    play_sound_effect_at_location(SFX_UNKNOWN_174, 0x5000, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                }
                if (temp_t5 < 8) {
                    sp9E = temp_t5 * 2;
                } else {
                    sp9E = 0x10;
                }
                if ((D_803D5530->unk162 != 3) || ((D_803D5538 != 0) && (D_801E9E8A == 0))) {
                    D_803D552C->unk32A = D_803D5544;
                    D_803D552C->unk365 = ATTACK_PENGUIN_2;
                }
                break;
            case ATTACK_PENGUIN_2:                                /* switch 2 */
                temp_t5 = (D_803D5544 - D_803D552C->unk32A); // & 0xFFFF;
                if (temp_t5 < 0x10) {
                    sp9E = 0x10;
                    sp9C = temp_t5;
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            case ATTACK_SNOWBALL:                                /* switch 2 */
                temp_t5 = (D_803D5544 - D_803D552C->unk32A); // & 0xFFFF;
                if (temp_t5 < 8) {
                    sp9A = temp_t5 * 2;
                } else {
                    play_sound_effect_at_location(0, 0x6000, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                    if (D_803D5538 != 0) {
                        target = func_8037E9AC_79005C();
                        if (target != NULL) {
                            temp_f0 = D_803D5530->xPos.h - target->xPos.h;
                            temp_f2 = D_803D5530->zPos.h - target->zPos.h;
                            sp88 = (f32) (((D_803D5530->yPos.h - target->yPos.h) - (s16) ((s32) (target->unk42 * 3) >> 2)) + 0x14);
                            sp84 = sqrtf(SQ(temp_f0) + SQ(temp_f2));
                            temp_f2_2 = (f64) sp84 / 64.0;
                            var_f14 = func_801286B8(-sp88, sp84) + SQ(sp84 / 64.0);

                            while (var_f14 > 180.0) {
                                var_f14 -= 360.0;
                            }

                            var_f0_2 = MAX(var_f14, -45.0f);

                            if (var_f0_2 < 45.0f) {
                                var_f14 = MAX(var_f14, -45.0f);
                            } else {
                                var_f14 = 45.0f;
                            }
                        } else {
                            var_f14 = 0.0f;
                        }
                        func_80321E60_733510(0x3D, 0xA, 0, 0x14, (s16) 0x19, (s16) (s32) ((var_f14 * 256.0f) / 360.0f), (s16) 2, (s16) 6);
                    } else {
                        func_80322064_733714(0x3D, 0xA, 0, 0x14, (s16) 0x23, (s16) (s32) D_803D5530->yRotation, (s16) D_803D552C->unk338, (s16) 2, (s16) 6);
                    }
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            default:                                /* switch 2 */
                D_803D552C->unk365 = ATTACK_NONE;
                if ((D_803D5530->yVelocity.h < -0xA) && ((D_803D5530->unk162 & 0xF) == 3) && ((D_803D5530->yPos.h - (func_80310EE4_722594(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->unk160) >> 0x10)) >= 0x31) && ((D_803D5538 == 0) || (D_801E9E8A != 0))) {
                    D_803D552C->unk365 = ATTACK_PENGUIN_1;
                    D_803D552C->unk32A = D_803D5544;
                }
                break;
            }
            break;
        }
        if (sp9E >= 9) {

            if (D_803D5530->yVelocity.w < FTOFIX32(-1.0)) {
                D_803D5530->xVelocity.w += (D_80152C78[(D_803D5540 << 3) & 0xFF] >> 7) << 8;
                D_803D5530->zVelocity.w += (D_80152C78[((D_803D5540 << 2) + 0x40) & 0xFF] >> 7) << 8;
                D_803D5530->yVelocity.w = MAX(D_803D5530->yVelocity.w + FTOFIX32(4.0), FTOFIX32(-1.0));
            }
        }
        if ((D_803F2ECE == 0) || ((((s32) D_803F2ECC < 0x1F) != 0))) {
            D_803F2F00 = 0;
            func_802B975C_6CAE0C(&spA8, (s16) (spA0 * 0x96), 1);
            func_802C23F8_6D3AA8((s16) ((spA0 * 0x4E) + 0x2F));
            D_80203FE0[27].unk0 = 0;
            D_80203FE0[1].unk2 += (sp9A * 0x12C) >> 5;
            D_80203FE0[26].unk4 = 0x96;
            D_80203FE0[0].unk2 += (sp9A * 0x12C) >> 5;
            D_80203FE0[2].unk2 += (sp9A * 0x12C) >> 5;
            D_80203FE0[27].unk2 =  -(sp9A * 0x12C) >> 4;
            D_80203FE0[26].unk2 =  -(sp9A * 0x12C) >> 4;
            D_80203FE0[27].unk4 += 0x10;
            D_80203FE0[26].unk0 = D_80203FE0[27].unk0;

            switch (D_803F2F00) {                    /* switch 3; irregular */
            case 1:                                 /* switch 3 */
                func_80374660_785D10((s16) ((s32) (spA0 * -0xAA) / 32), 0, (s16) ((spA0 * 0x12C) + 0x12C));
                break;
            case 2:                                 /* switch 3 */
                func_80374660_785D10((s16) ((s32) (spA0 * 0xAA) / 32), 0, (s16) ((spA0 * 0x12C) + 0x12C));
                break;
            }
            // var_v0_2 = D_803F2ECC;
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* switch 4; irregular */
            case 1:                                 /* switch 4 */
                func_802DB670_6ECD20(&D_803B4200_7C58B0, &D_803B4208_7C58B8, &D_803B4210_7C58C0, &D_803B4218_7C58C8);
                break;
            case 2:                                 /* switch 4 */
                func_802DB670_6ECD20(&D_803B4200_7C58B0, &D_803B4208_7C58B8, &D_803B4210_7C58C0, &D_803B4230_7C58E0);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((temp_a0_8 = D_803D5538, (temp_a0_8 != 0)) || (temp_v0_14 = D_803F2AA2, (temp_v0_14 == 0)) || (temp_v0_14 == 2) || ((temp_v0_14 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((*D_803F2C18 != 0) || (temp_a0_8 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) (spA0 * D_803F2EB0) / 4, (s32) (spA0 * D_803F2EB4) / 4, (s32) (spA0 * D_803F2EB8) / 4, (s16) (s32) D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.4f);
            load_2_tiles(&D_04001730, &D_04001750, (s32) &D_04001330);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 1, &D_04001010_DE5D0);
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 1, &D_04001220_C8C50);
            }
            if (D_803D5524->unk9C == 0x40) {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 1, &D_04001890_DEE50);
            }
            func_802C78B0_6D8F60(2, 0xF, 0x10000, 0x10000, 0x10000, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 0, &D_040012E0_DE8A0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 0x12, 0x10000, 0x10000, 0x10000, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, &D_040012E0_DE8A0);
            }
            if (sp9E != 0) {
                temp_a3 = (MAX(0, (sp9E << 0xC) - (sp9C << 0xC)) << 6) >> 6;
                func_802C78B0_6D8F60(1, 2, temp_a3, temp_a3, (s32) ((sp9C * -0x40000) + 0x400000) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 1, &D_04001A60_DF020);
            }
            if ((sp9A != 0) && (D_803F2EDD == 0)) {
                func_802C78B0_6D8F60(0x1A, 0x1B, (sp9A << 0x12) >> 6, (sp9A << 0x12) >> 6, (sp9A << 0x12) >> 6, (s16) (s32) D_803F2ED0, (s16) 0, (u8) 0, (u8) 1, &D_04001B60_DF120);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA2 == 0) || (spA2 == 2)) {
        temp_t4 = (s32) (spA0 * 0x15E) / 32;
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) (D_803D5524->unkBA * 3) >> 2)), D_803D552C->unk302, &D_01033190, (s16) (s32) (s16) temp_t4, (s16) (s32) (s16) temp_t4, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (spA2 == 0) {
        sp5C = spA0 * 0x12C;
        func_80303820_714ED0(D_803D552C, 1, 1, ((spA0 * 0x258) >> 1), (u16) 0);
        func_80303B18_7151C8(D_803D552C, 1, ((spA0 * 0x5DC) >> 3), ((spA0 * 0x834) >> 3), (u16) 1);
        func_80303D50_715400(D_803D552C, 2U);
    } else {
        func_80303D00_7153B0(D_803D552C, ((s32) (spA0 * 0x384) >> 1), 0x96U);
    }
    if ((D_803D5538 == 0) && (D_803D5524->unk9C == KING_PENGUIN)) {
        if (D_803D552C->unk2EC <= 0) {
            D_803D552C->unk2B4.unk4 = 0;
        } else {
            D_803D552C->unk2EC--;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80364780_775E30.s")
#endif

// king_penguin_jetpack
void func_80365954_777004(void) {
    if ((D_803D5530->unk162 != 1) && (D_803D5530->unk4A == 0)) {
        func_8032CD70_73E420(
            (void*)D_803D5530,
            SFX_UNKNOWN_103,
            0x7000,
            0,
            0.25f,
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            D_803D552C->yPos.h
            );

        if (D_803D5530->yVelocity.w > FTOFIX32(4.0)) {
            D_803D5530->yVelocity.w += FTOFIX32(1.0);
        } else {
            D_803D5530->yVelocity.w += FTOFIX32(2.5);
        }

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->zPos.h) - 8,
            D_803D5530->yPos.h,
            (SSSV_RAND(2) + 25),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (D_803D5530->yVelocity.w >> 1) - FTOFIX32(3.0517578125),
            SSSV_RAND(13),
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(56, 56, 56, 1),
            SSSV_RAND(16) + 20);

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->zPos.h) - 8,
            D_803D5530->yPos.h,
            63,
            (D_803D5530->xVelocity.w >> 2) * -1,
            (D_803D5530->zVelocity.w >> 2) * -1,
            (D_803D5530->yVelocity.w >> 1) - FTOFIX32(4.57763671875),
            SSSV_RAND(32) + 30,
            GPACK_RGBA5551(SSSV_RAND(64) + 192, SSSV_RAND(64) + 192, 0, 1),
            GPACK_RGBA5551(SSSV_RAND(64) + 192, 0, 0, 1),
            0);

    } else {
        recharge_skill(0);
    }
}

void func_80365C28_7772D8(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk365 = ATTACK_SNOWBALL;
        D_803D552C->unk32A = D_803D5544;
    } else {
        recharge_skill(1);
    }
}

void func_80365C7C_77732C(void) {
    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x7000, 0, 1.3f);
            D_803D552C->unk308 = 80;
        }
    }
    if (D_803D552C->unk2CC = func_8037E9AC_79005C()) {
        D_803D552C->unk2B4.unk4 = 1;
    } else {
        D_803D552C->unk2B4.unk4 = 0;
    }
}

// king penguin
void func_80365D74_777424(void) {
    D_803D552C->unk2B4.unk4 = 0;
}

// penguin?
void penguin_throw_snowball(Animal *arg0) {
    if (D_803D552C->unk365 != ATTACK_SNOWBALL) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 0xA, 0x14, 0x23, 0x59, 0, 3, (f32) D_803A05B0 / 65536.0);
        if (tmp == -1) {
            tmp = 32;
        } else {
            tmp = (s16) ((tmp * 256) / 360);
        }
        D_803D552C->unk365 = ATTACK_SNOWBALL;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk338 = tmp;
    }
}

// king penguin attack
void func_80365E70_777520(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.3f);
        D_803D552C->unk308 = 50;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk2B4.unk4 = 1;
}
