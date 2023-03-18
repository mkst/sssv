#include <ultra64.h>
#include "common.h"

extern s16 D_803B4A20_7C60D0[];
extern s16 D_803B4A50_7C6100[];
extern s16 D_803B4A80_7C6130[];
extern s16 D_803B4A94_7C6144[];
extern s16 D_803B4AC4_7C6174[];
extern s16 D_803B4AF4_7C61A4[];

extern u8 D_803B4B08_7C61B8[];
extern u8 D_803B4B20_7C61D0[];
extern s16 D_803B4B38_7C61E8[];
extern s16 D_803B4B64_7C6214[];
extern s16 D_803B4BC4_7C6274[];

extern Gfx D_01003548[];

extern Gfx D_04000F90_E8540[];
extern Gfx D_04001300_E88B0[];
extern Gfx D_040014D0_E8A80[];
extern Gfx D_040015C0_E8B70[];
extern Gfx D_04001650_E8C00[];
extern Gfx D_04001760_E8D10[];
extern Gfx D_040019F0_E8FA0[];
extern Gfx D_04001E50_E9400[];
extern Gfx D_04002020_E95D0[];
extern Gfx D_040020F0_E96A0[];
extern Gfx D_04002820_E9DD0[];
extern Gfx D_04002840_E9DF0[];
extern Gfx D_040029C0_E9F70[];

extern u8 D_04002780[];
extern u8 D_04002560_E9B10[];

#if 0
// CURRENT (18788)
void func_8036D700_77EDB0(void) {
    struct061 spE0;
    s16 spDE;
    s16 spDC;
    s16 spDA;
    s16 spCE;
    s16 spCC;
    s16 spC8;
    s16 spC6;
    u16 sp80;

    Animal *temp_v0_6;
    Animal *var_v1;

    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_t0_2;
    s16 temp_t1;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_v0_4;
    s16 temp_v0_8;
    s32 var_a3;
    s16 var_s1;
    s16 i;
    s16 var_v0_2;
    s16 var_v0_3;
    s32 temp_a0_5;
    s32 temp_a1_2;
    s32 temp_a2_2;
    s32 temp_lo_2;
    s32 temp_s1;
    s32 temp_t5;
    s32 temp_t7_2;
    s32 temp_t9;
    u8 var_v0;
    u8 temp_a0_6;
    u8 temp_v0_10;

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spDA = 0;
            D_803F2EDD = 0;
            goto block_9;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    spDA = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x1900, (u8) 6, (s16) 0x97, (s16) 0x65, (s16) 0x37, (s8) 2, var_v0 == 0);

block_9:
    if (spDA == 0) {
        func_8038C98C_79E03C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        switch (D_803D5524->unk9C) {
        case CANNON_CAMEL:
            switch (D_803D552C->unk365) {
            case ATTACK_CAMEL_DASH:
                sp80 = (D_803D5544 - D_803D552C->unk32A);
                if (sp80 <= 0x40) {
                    if (sp80 == 0x20) {
                        if (D_803D5538 != 0) {
                            func_8037F07C_79072C(0x200, D_803D552C->unk302);
                        } else {
                            func_8037F07C_79072C(0x200, D_803D552C->unk338);
                        }
                        play_sound_effect_at_location(SFX_FOX_DASH, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
                    }
                    if (sp80 > 0x20) {
                        sp80 = (0x40 - sp80);
                    }
                    if (D_803D5530->unk4A == 0) {
                        func_8032CD70_73E420(
                            D_803D5530,
                            SFX_UNKNOWN_51,
                            (((sp80 * -0x7000) + 0xE0000) >> 5),
                            0,
                            (((sp80 * sp80) * 0.03125) + 1.0),
                            D_803D5530->xPos.h,
                            D_803D5530->zPos.h,
                            D_803D5530->yPos.h);
                    }
                    if ((s16)sp80 >= 9) {
                        var_s1 = 1;
                        for (spC8 = sp80; spC8 > 8; spC8 -= 8) {
                            create_particle_effect(
                                D_803D5530->xPos.h + (s16)(((SSSV_RAND(256) - 0x80) * var_s1) >> 3),
                                D_803D5530->zPos.h + (s16)(((SSSV_RAND(256) - 0x80) * var_s1) >> 3),
                                D_803D5530->yPos.h + (s16)(((SSSV_RAND(32) + (var_s1 << 5)) * D_803D5530->unk42) >> 7),
                                0x15,
                                0,
                                0,
                                0,
                                0x28,
                                GPACK_RGBA5551(248, 248, 0, 1),  // yellow
                                GPACK_RGBA5551(248, 168, 88, 1), // pale orange
                                0);
                            var_s1 += 1;
                        }
                    }

                    create_particle_effect(
                        D_803D5530->xPos.h + (s16) (((D_80152C78[(SSSV_RAND(32) + ((sp80 & 7) << 5)) & 0xFF] >> 7) * sp80) >> 8),
                        D_803D5530->zPos.h + (s16) (((D_80152C78[(SSSV_RAND(32) + ((sp80 & 7) << 5) + 0x40) & 0xFF] >> 7) * sp80) >> 8),
                        D_803D5530->yPos.h + ((sp80 * D_803D5530->unk42) >> 5),
                        0x15,
                        0,
                        0,
                        0,
                        0x28,
                        GPACK_RGBA5551(248, 248, 0, 1),
                        GPACK_RGBA5551(248, 168, 88, 1),
                        0);
                } else {
                    D_803D5530->xVelocity.w = 0;
                    D_803D5530->zVelocity.w = 0;
                    D_803D5530->yVelocity.w = 0;
                    D_803D552C->unk365 = 0;
                    func_802B34B8_6C4B68(D_803D5530);
                }
                break;
            default:
                D_803D552C->unk365 = 0;
                break;
            }
            break;
        case CAMEL:
            switch (D_803D552C->unk365) {
            case ATTACK_CAMEL_WATER_CANNON:
                D_803D5528->unk3C0.unk0 = 0;
                sp80 = (D_803D5544 - D_803D552C->unk32A); // & 0xFFFF;
                func_802DC6A4_6EDD54(0x10);
                if (sp80 == 1) {
                    play_sound_effect_at_location(SFX_UNKNOWN_62, 0x4800, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                }
                if (sp80 == 11) {
                    play_sound_effect_at_location(SFX_UNKNOWN_30, 0x5000, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                }
                if (sp80 == 0xC) {
                    if (D_803D5538 != 0) {
                        for (i = 0; i < 4; i++) {
                            func_80322064_733714(
                                0x27,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() & 3) + 0x12),
                                (((guRandom() & 0xF) + D_803D5530->yRotation) - 7),
                                2,
                                4,
                                8);
                        }
                        for (i = 0; i < 4; i++) {
                            func_80322064_733714(
                                0x27,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() & 0xF) + 4),
                                (((guRandom() & 0xF) + D_803D5530->yRotation) - 7),
                                2,
                                4,
                                8);
                        }
                    } else {
                        for (i = 0; i < 4; i++) {
                            func_80322064_733714(
                                0x27,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() % 4) + 0x12),
                                (((guRandom() % 19) + D_803D5530->yRotation) - 9),
                                D_803D552C->unk338,
                                4,
                                8);
                        }
                        for (i = 0; i < 4; i++) {
                            func_80322064_733714(
                                0x27,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() & 0xF) + 4),
                                (((guRandom() & 0xF) + D_803D5530->yRotation) - 7),
                                2,
                                4,
                                8);
                        }
                    }
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        }


        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spE0, 0x138, 0xC3, 0x668, 0x75);
            func_802BD40C_6CEABC(0x2BF, 0x271, 0x138, 0x75, 0x28, 0xA8, 0, 0x80, &D_803B4A20_7C60D0, &D_803B4A50_7C6100, &D_803B4A80_7C6130, (s16) 0x2BF, (s16) 0x271, (s16) 0x138, (s16) 0x75, (s16) 0, (s16) 0x80, (s16) 0, (s16) 0x80, &D_803B4A94_7C6144, &D_803B4AC4_7C6174, &D_803B4AF4_7C61A4, &spE0, (s16) 0);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x493, 0x1D4, 5);
            func_8038CCF0_79E3A0(0x75, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            temp_v0_4 = D_80203FE0[20].unk0 - D_80203FE0[19].unk0;
            temp_a1 = D_80203FE0[20].unk2 - D_80203FE0[19].unk2;
            // temp_a3 = &D_80152350.unk0[D_803D552C->unk316];
            temp_t0_2 = D_80152350.unk2D0[D_803D552C->unk316];
            temp_t1 = D_80152350.unk384[D_803D552C->unk316];
            temp_t3 = D_80203FE0[1].unk4;
            temp_t4 = D_80203FE0[2].unk4;
            temp_t5 = ((s32) (temp_t0_2 * temp_a1) >> 8) + ((s32) (temp_v0_4 * temp_t1) >> 8);
            D_80203FE0[20].unk2 = (s16) (D_80203FE0[19].unk2 + (((s32) (temp_a1 * temp_t1) >> 8) - ((s32) (temp_t0_2 * temp_v0_4) >> 8)));
            D_80203FE0[20].unk0 = (s16) (D_80203FE0[19].unk0 + temp_t5);
            temp_t9 = (s32) ((temp_t3 - temp_t4) * 3) >> 3;
            D_80203FE0[1].unk4 -= temp_t9;
            D_80203FE0[2].unk4 += temp_t9;

            if (D_803D5524->unk9C == CANNON_CAMEL) {
                if (D_803F2D10.unk0 == 0) {
                    switch (D_803D552C->unk366) {
                    default:
                        D_803D552C->unk30A -= 1;
                        if (D_803D552C->unk30A < 0) {
                            D_803D552C->unk30A = 0;
                        }
                        if (D_803D5538 != 0) {
                            if ((D_803F28E0[D_803F2A98].cameraMode == 3) || (D_803F28E0[D_803F2A98].cameraMode == 0x11)) {
                                var_v0_2 = (D_803F28E0[D_803F2A98].unk20 * 256.0) / 360.0;
                            } else {
                                var_v0_2 = D_803F28E0[D_803F2A98].unk20;
                            }
                            if (var_v0_2 != D_803D552C->unk308) {
                                if ((s16) ((var_v0_2 - D_803D552C->unk308) & 0xFF) < 0x80) {
                                    D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                                } else {
                                    D_803D552C->unk308 = (D_803D552C->unk308 - 1) & 0xFF;
                                }
                            }
                        }
                        break;
                    case 2:
                    case 5:
                        if (D_803D552C->unk2CC != NULL) {
                            var_v0_2 = (func_801284B8((s16) (D_803D552C->unk2CC->xPos.h - D_803D5530->xPos.h), (s16) (D_803D552C->unk2CC->zPos.h - D_803D5530->zPos.h)) << 8) / 360;
                            if (D_803D552C->unk308 != var_v0_2) {
                                if ((s16) ((var_v0_2 - D_803D552C->unk308) & 0xFF) < 0x80) {
                                    D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                                } else {
                                    D_803D552C->unk308 = (D_803D552C->unk308 - 1) & 0xFF;
                                }
                            }
                        } else {
                            D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                        }
                        break;
                    }
                }

                var_v0_3 = (D_803D552C->unk308 - D_803D552C->unk302) & 0xFF;;
                if (var_v0_3 > 0x80) {
                    var_v0_3 = 0x100 - var_v0_3;
                }
                temp_v0_8 = 0x20 - var_v0_3;
                if (temp_v0_8 > 0) {
                    temp_a0_5 = temp_v0_8 * 0x493;
                    temp_a1_2 = temp_a0_5 >> 5;
                    temp_a2_2 = temp_a0_5 >> 7;
                    D_80203FE0[19].unk4 = (s16) (D_80203FE0[19].unk4 - temp_a1_2);
                    D_80203FE0[20].unk4 = (s16) (D_80203FE0[20].unk4 - temp_a1_2);
                    D_80203FE0[19].unk2 = (s16) (D_80203FE0[19].unk2 + temp_a2_2);
                    D_80203FE0[20].unk2 = (s16) (D_80203FE0[20].unk2 + temp_a2_2);
                    var_v0_3 = (D_803D552C->unk308 - D_803D552C->unk302) & 0xFF;
                }
                temp_t7_2 = (s32) (D_803D552C->unk30A * 0x271) >> 5;
                D_80203FE0[26].unk0 = (D_80203FE0[0].unk0 - ((s32) (((s16) D_80152C78[var_v0_3 & 0xFF] >> 7) * (s16) temp_t7_2) >> 8));
                D_80203FE0[26].unk2 = (D_80203FE0[0].unk2 - ((s32) (((s16) D_80152C78[((D_803D552C->unk308 - D_803D552C->unk302) + 0x40) & 0xFF] >> 7) * (s16) temp_t7_2) >> 8));
                D_80203FE0[26].unk4 = D_80203FE0[0].unk4;
                D_80203FE0[27].unk4 = D_80203FE0[26].unk4 + 0x445;
                D_80203FE0[27].unk0 = D_80203FE0[26].unk0;
                D_80203FE0[27].unk2 = D_80203FE0[26].unk2;
            }
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(&D_803B4B08_7C61B8, &D_803B4B20_7C61D0, &D_803B4B38_7C61E8, &D_803B4B64_7C6214);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803B4B08_7C61B8, &D_803B4B20_7C61D0, &D_803B4B38_7C61E8, &D_803B4BC4_7C6274);
                break;
            }
        }

        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((temp_a0_6 = D_803D5538, (temp_a0_6 != 0)) || (temp_v0_10 = D_803F2AA2, (temp_v0_10 == 0)) || (temp_v0_10 == 2) || ((temp_v0_10 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((*D_803F2C18 != 0) || (temp_a0_6 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, 0.19f);

            D_803F2EBC = FTOFIX32(1.0) + ((D_803F2EBC - FTOFIX32(1.0)) >> 2);
            D_803F2EC0 = FTOFIX32(1.0) + ((D_803F2EC0 - FTOFIX32(1.0)) >> 2);
            D_803F2EC4 = FTOFIX32(1.0) + ((D_803F2EC4 - FTOFIX32(1.0)) >> 2);

            switch (D_803D5524->unk9C) {                   /* switch 1; irregular */
            case CAMEL:                                /* switch 1 */
                if ((D_803D5538 == 0) && (D_803F2DA2 == 3)) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x37, 0x37, 0xFF, 0xFF);
                } else {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
                }
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040029C0_E9F70);
                load_1_tile(D_04002780, (s32) D_04002560_E9B10);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04001300_E88B0);
                break;
            case CANNON_CAMEL:                                /* switch 1 */
                if ((D_803D5538 == 0) && (D_803F2DA2 == 3)) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x37, 0x37, 0xFF, 0xFF);
                } else {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xF0, 0xA0, 0xFF);
                }
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04001E50_E9400);
                break;
            }

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_040014D0_E8A80); }

            switch (D_803D5524->unk9C) {                   /* switch 2; irregular */
            case CAMEL:                                /* switch 2 */
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04000F90_E8540);
                break;
            case CANNON_CAMEL:                                /* switch 2 */
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040019F0_E8FA0);
                func_802C78B0_6D8F60(0x1B, 0x1A, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, (s16) (((D_803D552C->unk308 - D_803D552C->unk302) + 0x40) & 0xFF), (u8) 0, (u8) 0, D_04001760_E8D10);
                break;
            }
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040015C0_E8B70);
            }

            gSPDisplayList(D_801D9E88++, D_01003548);

#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xD, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_04002020_E95D0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xD, 0xE, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_04002020_E95D0); }
#pragma _permuter sameline end

            func_802C78B0_6D8F60(8, 9, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_04001650_E8C00);
            func_802C78B0_6D8F60(0xE, 0xF, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_04001650_E8C00);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x10, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xA, 0xB, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04002020_E95D0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x10, 0x11, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04002020_E95D0); }
#pragma _permuter sameline end

            func_802C78B0_6D8F60(0xB, 0xC, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04001650_E8C00);
            func_802C78B0_6D8F60(0x11, 0x12, 0x19000, 0x19000, 0x19000, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_04001650_E8C00);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spDE, &spDC);
                func_8031A278_72B928(&D_803D552C->unk326, &spDE, &spDC);
#pragma _permuter sameline start
                spDE = D_803BD54A_7CEBFA[spDE]; spDC = D_803BD602_7CECB2[spDC];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CA0, D_01000620, spDE);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04002820_E9DD0);
                func_80356BD8_768288(D_01000CA0, D_01000620, spDC);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04002840_E9DF0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spDA == 0) || (spDA == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, D_803D552C->yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, D_01033190, (s16) 0x19, (s16) 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spDA == 0) {
        func_8034B298_75C948(0);
        func_803034D0_714B80(D_803D552C, 0x61A, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x20E, 0);
        D_803D5530->unkC4[0].unk8.h -= 10;
        func_80303B18_7151C8(D_803D552C, 0, -0x1D4, 0x1D4, 3);
        func_80303D50_715400(D_803D552C, 4);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x271, 0x1D4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/camel/func_8036D700_77EDB0.s")
#endif

void func_8036F3AC_780A5C(void) {
    if (D_803D552C->unk365 != ATTACK_CAMEL_WATER_CANNON) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CAMEL_WATER_CANNON;
    } else {
        recharge_skill(1);
    }
}

void func_8036F404_780AB4(void) {
    func_80322064_733714(OBJECT_CANNONBALL, 60, 0, 60, 22, D_803D552C->unk308, 4, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_8036F4CC_780B7C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CAMEL_DASH;
    func_802B342C_6C4ADC();
}

// water cannon?
void func_8036F50C_780BBC(Animal *arg0) {
    if (D_803D552C->unk365 != ATTACK_CAMEL_WATER_CANNON) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 80, 18, 80, -80, 3, (f32)D_803A05B0 / 65536.0);
        if (tmp == -1) {
            tmp = 32;
        } else {
            tmp = (s16) ((tmp * 256) / 360);
        }
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CAMEL_WATER_CANNON;
        D_803D552C->unk338 = tmp;
    }
}

void camel_cannon_fire_cannon(Animal *arg0) {
    s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 60, 22, 32, -12, 0, (f32)D_803A05B0 / 65536.0);
    if (tmp == -1) {
        tmp = 2;
    } else {
        tmp = (s16) ((tmp * 256) / 360);
    }
    // fire cannon
    func_80322064_733714(OBJECT_CANNONBALL, 60, 0, 60, 22, D_803D552C->unk308, tmp, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_8036F740_780DF0(u16 arg0) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CAMEL_DASH;
    D_803D552C->unk338 = arg0;
    func_802B33D0_6C4A80(D_803D5530);
}
