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

extern u8 D_04002780_E9D30[];
extern u8 D_04002560_E9B10[];


void func_8036D700_77EDB0(void) {

    struct061 spE0;
    s16 spDE;
    s16 spDC;
    s16 spDA;

    u16 ticks_remaining;
    s16 temp_t7;
    s16 new_var;
    s16 temp_t9;

    // s16 spCE;
    s16 spCC;
    s16 spCA;
    s16 spC8;
    s16 spC6;
    s16 spC4;

    // s16 spC6;

    s16 var_s1; // spBC?
    s16 i;

    s16 temp_a1;
    s16 temp_v0;
    s16 temp_t3;
    s16 temp_t4;
    u8  temp_v0_10;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spDA = 0;
        D_803F2EDD = 0;
    } else {
        spDA = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            6400,
            FOV_VERTICAL_DIAMOND,
            151,
            101,
            55,
            2,
            CHECK_SEGMENT == 0);
    }

    if (spDA == 0) {
        func_8038C98C_79E03C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        switch (D_803D5524->unk9C) {
        case CANNON_CAMEL:
            switch (D_803D552C->unk365) {
            case ATTACK_CAMEL_DASH:
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                if (ticks_remaining <= 0x40) {
                    if (ticks_remaining == 0x20) {
                        if (D_803D5538 != 0) {
                            func_8037F07C_79072C(0x200, D_803D552C->heading);
                        } else {
                            func_8037F07C_79072C(0x200, D_803D552C->unk338);
                        }
                        play_sound_effect_at_location(SFX_FOX_DASH, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                    if (ticks_remaining > 0x20) {
                        ticks_remaining = (0x40 - ticks_remaining);
                    }
                    if (D_803D5530->unk4A == 0) {
                        func_8032CD70_73E420(
                            D_803D5530,
                            SFX_UNKNOWN_51,
                            (((-ticks_remaining * 0x7000) + 0xE0000) >> 5),
                            0,
                            (((ticks_remaining * ticks_remaining) * 0.03125) + 1.0),
                            D_803D5530->position.xPos.h,
                            D_803D5530->position.zPos.h,
                            D_803D5530->position.yPos.h);
                    }

                    spC4 = ticks_remaining;
                    for (var_s1 = 0; spC4 > 8;) {
                        var_s1++;
                        spC4 -= 8;

                        spCA = SSSV_RAND(256) - 0x80;
                        spC8 = SSSV_RAND(256) - 0x80;

                        spCA = (spCA * (var_s1+1)) >> 3;
                        spC8 = (spC8 * (var_s1+1)) >> 3;
                        spC6 = ((SSSV_RAND(32) + ((var_s1+0) << 5)) * D_803D5530->unk42) >> 7;

                        create_particle_effect(
                            D_803D5530->position.xPos.h + spCA,
                            D_803D5530->position.zPos.h + spC8,
                            D_803D5530->position.yPos.h + spC6,
                            21,
                            0,
                            0,
                            0,
                            0x28,
                            GPACK_RGBA5551(248, 248, 0, 1),  // yellow
                            GPACK_RGBA5551(248, 168, 88, 1), // pale orange
                            0);
                    }

                    spCA = SIN(SSSV_RAND(32) + ((ticks_remaining & 7) << 5)) >> 7;
                    spC8 = COS(SSSV_RAND(32) + ((ticks_remaining & 7) << 5)) >> 7;

                    spCA = (spCA * ticks_remaining) >> 8;
                    spC8 = (spC8 * ticks_remaining) >> 8;

                    create_particle_effect(
                        D_803D5530->position.xPos.h + spCA,
                        D_803D5530->position.zPos.h + spC8,
                        D_803D5530->position.yPos.h + ((ticks_remaining * D_803D5530->unk42) >> 5),
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
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                func_802DC6A4_6EDD54(0x10);
                if (ticks_remaining == 1) {
                    play_sound_effect_at_location(SFX_UNKNOWN_62, 0x4800, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
                if (ticks_remaining == 11) {
                    play_sound_effect_at_location(SFX_UNKNOWN_30, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
                if (ticks_remaining == 12) {
                    if (D_803D5538 != 0) {
                        for (i = 0; i < 4; i++) {
                            fire_cannonball_2(
                                OBJECT_WATER_CANNON_1,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() & 3) + 0x12),
                                (((guRandom() & 0xF) + D_803D5530->yRotation) - 7),
                                2,
                                4,
                                8);

                        }
                        for (i = 0; i < 2; i++) {
                            fire_cannonball_2(
                                OBJECT_WATER_CANNON_1,
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
                            fire_cannonball_2(
                                OBJECT_WATER_CANNON_1,
                                0x3C,
                                0,
                                0x50,
                                ((guRandom() % 4) + 0x12),
                                (((guRandom() % 19) + D_803D5530->yRotation) - 9),
                                D_803D552C->unk338,
                                4,
                                8);
                        }
                        for (i = 0; i < 2; i++) {
                            fire_cannonball_2(
                                OBJECT_WATER_CANNON_1,
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
            func_802BD40C_6CEABC(
                0x2BF, 0x271, 0x138, 0x75, 0x28, 0xA8, 0, 0x80, D_803B4A20_7C60D0, D_803B4A50_7C6100, D_803B4A80_7C6130,
                0x2BF, 0x271, 0x138, 0x75,    0, 0x80, 0, 0x80, D_803B4A94_7C6144, D_803B4AC4_7C6174, D_803B4AF4_7C61A4,
                &spE0, 0);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x493, 0x1D4, 5);
            func_8038CCF0_79E3A0(0x75, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            temp_v0 = D_80203FE0[20].unk0 - D_80203FE0[19].unk0;
            temp_a1 = D_80203FE0[20].unk2 - D_80203FE0[19].unk2;

            temp_t3 = ((temp_v0 * D_80152350.unk384[D_803D552C->unk316]) >> 8) + ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a1) >> 8);
            temp_t4 = ((temp_a1 * D_80152350.unk384[D_803D552C->unk316]) >> 8) - ((D_80152350.unk2D0[D_803D552C->unk316] * temp_v0) >> 8);

            D_80203FE0[20].unk0 = D_80203FE0[19].unk0 + temp_t3;
            D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + temp_t4;

            temp_t9 = ((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) * 3) >> 3;
            D_80203FE0[1].unk4 -= temp_t9;
            D_80203FE0[2].unk4 += temp_t9;

            if (D_803D5524->unk9C == CANNON_CAMEL) {
                if (D_803F2D10.unk0 == 0) {
                    switch (D_803D552C->unk366) {
                    case 2:
                    case 5:
                        break;
                    default:
                        D_803D552C->unk30A--;
                        if (D_803D552C->unk30A < 0) {
                            D_803D552C->unk30A = 0;
                        }
                        if (D_803D5538 != 0) {
                            if ((gCameras[gCameraId].cameraMode == 3) || (gCameras[gCameraId].cameraMode == 0x11)) {
                                temp_v0 = (gCameras[gCameraId].unk20 * 256.0) / 360.0;
                            } else {
                                temp_v0 = gCameras[gCameraId].unk20;
                            }
                            if (D_803D552C->unk308 != temp_v0) {
                                new_var = (temp_v0 - D_803D552C->unk308) & 0xFF;
                                if (new_var < 0x80) {
                                    D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                                } else {
                                    D_803D552C->unk308 = (D_803D552C->unk308 - 1) & 0xFF;
                                }
                            }
                        } else if (D_803D552C->unk2CC != NULL) {
                            temp_v0 = (func_801284B8(D_803D552C->unk2CC->position.xPos.h - D_803D5530->position.xPos.h, D_803D552C->unk2CC->position.zPos.h - D_803D5530->position.zPos.h) << 8) / 360;
                            if (temp_v0 != D_803D552C->unk308) {
                                new_var = (temp_v0 - D_803D552C->unk308) & 0xFF;
                                if (new_var < 128) {
                                    D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                                } else {
                                    D_803D552C->unk308 = (D_803D552C->unk308 - 1) & 0xFF;
                                }
                            }
                        } else {
                            D_803D552C->unk308 = (D_803D552C->unk308 + 1) & 0xFF;
                        }
                    }
                }

                temp_v0 = (D_803D552C->unk308 - D_803D552C->heading) & 0xFF;
                if (temp_v0 > 128) {
                    temp_v0 = 256 - temp_v0;
                }

                temp_v0 = 32 - temp_v0;
                if ((temp_v0) > 0) {
                    D_80203FE0[19].unk4 -= (temp_v0 * 0x493) >> 5;
                    D_80203FE0[20].unk4 -= (temp_v0 * 0x493) >> 5;
                    D_80203FE0[19].unk2 += (temp_v0 * 0x493) >> 7;
                    D_80203FE0[20].unk2 += (temp_v0 * 0x493) >> 7;
                }

                temp_t7 = (D_803D552C->unk30A * 0x271) >> 5;
                D_80203FE0[26].unk0 = (D_80203FE0[0].unk0 - (((SIN((D_803D552C->unk308 - D_803D552C->heading) & 0xFF) >> 7) * temp_t7) >> 8));
                D_80203FE0[26].unk2 = (D_80203FE0[0].unk2 - (((COS((D_803D552C->unk308 - D_803D552C->heading) & 0xFF) >> 7) * temp_t7) >> 8));
                D_80203FE0[26].unk4 = D_80203FE0[0].unk4;
                D_80203FE0[27].unk0 = D_80203FE0[26].unk0;
                D_80203FE0[27].unk2 = D_80203FE0[26].unk2;
                D_80203FE0[27].unk4 = D_80203FE0[26].unk4 + 0x445;
            }
        }

        if (D_803F2ECC != 0) {
            backup_joint_positions();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4B08_7C61B8, D_803B4B20_7C61D0, D_803B4B38_7C61E8, D_803B4B64_7C6214);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4B08_7C61B8, D_803B4B20_7C61D0, D_803B4B38_7C61E8, D_803B4BC4_7C6274);
                break;
            }
        }

        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_10 = D_803F2AA2, (temp_v0_10 == 0)) || (temp_v0_10 == 2) || ((temp_v0_10 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading,  D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, 0.19f);

            D_803F2EBC = FTOFIX32(1.0) + ((D_803F2EBC - FTOFIX32(1.0)) >> 2);
            D_803F2EC0 = FTOFIX32(1.0) + ((D_803F2EC0 - FTOFIX32(1.0)) >> 2);
            D_803F2EC4 = FTOFIX32(1.0) + ((D_803F2EC4 - FTOFIX32(1.0)) >> 2);

            switch (D_803D5524->unk9C) {
            case CAMEL:
                if ((D_803D5538 == 0) && (D_803F2D50.unk52 == 3)) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x37, 0x37, 0xFF, 0xFF);
                } else {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
                }
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040029C0_E9F70);
                load_1_tile(D_04002780_E9D30, (s32) D_04002560_E9B10);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04001300_E88B0);
                break;
            case CANNON_CAMEL:
                if ((D_803D5538 == 0) && (D_803F2D50.unk52 == 3)) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x37, 0x37, 0xFF, 0xFF);
                } else {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xF0, 0xA0, 0xFF);
                }
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04001E50_E9400);
                break;
            }
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 0, 0, D_040014D0_E8A80); }
#pragma _permuter sameline end
            switch (D_803D5524->unk9C) {
            case CAMEL:
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04000F90_E8540);
                break;
            case CANNON_CAMEL:
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040019F0_E8FA0);
                func_802C78B0_6D8F60(0x1B, 0x1A, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, (s16) (((D_803D552C->unk308 - D_803D552C->heading) + 0x40) & 0xFF), (u8) 0, (u8) 0, D_04001760_E8D10);
                break;
            }
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x64) >> 6, (D_803F2EC0 * 0x64) >> 6, (D_803F2EC4 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_040015C0_E8B70);
            }

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

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
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_040020F0_E96A0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(10, 11, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_04002020_E95D0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(16, 17, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_04002020_E95D0); }
#pragma _permuter sameline end

            func_802C78B0_6D8F60(0xB, 0xC, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_04001650_E8C00);
            func_802C78B0_6D8F60(0x11, 0x12, 0x19000, 0x19000, 0x19000, D_803F2ED0, 0, 1, 0, D_04001650_E8C00);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spDE, &spDC);
                func_8031A278_72B928(&D_803D552C->unk326, &spDE, &spDC);
#pragma _permuter sameline start
                spDE = D_803BD54A_7CEBFA[spDE]; spDC = D_803BD602_7CECB2[spDC];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CA0_3A570, D_01000620_39EF0, spDE);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04002820_E9DD0);
                func_80356BD8_768288(D_01000CA0_3A570, D_01000620_39EF0, spDC);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, (D_803F2EC8 * 0x64) >> 6, D_803F2ED0, 0, 0, 0, D_04002840_E9DF0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spDA == 0) || (spDA == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, D_01033190_6CA60, (s16) 0x19, (s16) 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spDA == 0) {
        func_8034B298_75C948(0);
        func_803034D0_714B80(D_803D552C, 0x61A, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x20E, 0);
        D_803D5530->unkC4[0].pos.yPos.h -= 10;
        func_80303B18_7151C8(D_803D552C, 0, -0x1D4, 0x1D4, 3);
        func_80303D50_715400(D_803D552C, 4);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x271, 0x1D4);
    }
}

void func_8036F3AC_780A5C(void) {
    if (D_803D552C->unk365 != ATTACK_CAMEL_WATER_CANNON) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CAMEL_WATER_CANNON;
    } else {
        recharge_skill(1);
    }
}

void func_8036F404_780AB4(void) {
    fire_cannonball_2(OBJECT_CANNONBALL, 60, 0, 60, 22, D_803D552C->unk308, 4, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_8036F4CC_780B7C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CAMEL_DASH;
    func_802B342C_6C4ADC();
}

// water cannon?
void camel_fire_water_cannon(Animal *arg0) {
    if (D_803D552C->unk365 != ATTACK_CAMEL_WATER_CANNON) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 80, 18, 80, -80, 3, (f32)gGravity / 65536.0);
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

void cannon_camel_fire_cannon(Animal *arg0) {
    s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 60, 22, 32, -12, 0, (f32)gGravity / 65536.0);
    if (tmp == -1) {
        tmp = 2;
    } else {
        tmp = (s16) ((tmp * 256) / 360);
    }
    // fire cannon
    fire_cannonball_2(OBJECT_CANNONBALL, 60, 0, 60, 22, D_803D552C->unk308, tmp, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void cannon_camel_dash(u16 arg0) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CAMEL_DASH;
    D_803D552C->unk338 = arg0;
    func_802B33D0_6C4A80(D_803D5530);
}
