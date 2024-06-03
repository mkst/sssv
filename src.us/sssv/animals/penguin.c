#include <ultra64.h>
#include "common.h"

extern u8 D_803B4200_7C58B0[];
extern u8 D_803B4208_7C58B8[];

extern s16 D_803B4210_7C58C0[];
extern s16 D_803B4218_7C58C8[];
extern s16 D_803B4230_7C58E0[];

extern u8 D_04001330_DE8F0[];
extern u8 D_04001730[]; // palette
extern u8 D_04001750[]; // palette

extern Gfx D_04001010_DE5D0[];
extern Gfx D_04001220_C8C50[];
extern Gfx D_04001890_DEE50[];
extern Gfx D_040012E0_DE8A0[];
extern Gfx D_04001A60_DF020[];
extern Gfx D_04001B60_DF120[];

#ifdef NON_MATCHING
void func_80364780_775E30(void) {
    s32 pad[0x7];

    u8 temp_v0_14;
    s16 spA8;

    Animal *target;
    s16 spA2;
    s16 scale; // spA0
    s16 sp9E;
    s16 sp9C;
    s16 sp9A;

    f32 xDist;
    f32 zDist;
    f32 var_f14;

    f32 sp88;
    f32 sp84;

    u16 ticks_remaining;
    s16 var_t5;
    s32 temp_a3;

    switch (D_803D5524->unk9C) {                              /* irregular */
    case PENGUIN:
        scale = 1;
        break;
    case KING_PENGUIN:
        scale = 2;  // scale
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        }
        break;
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spA2 = 0;
        D_803F2EDD = 0;
    } else {
        spA2 = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            (((scale * 24) << 5) << 6) / 32,
            6,
            0x28,
            0x28,
            0x50,
            scale - 1,
            CHECK_SEGMENT == 0);
    }

    if (spA2 == 0) {
        if ((D_803D5538 != 0) && (D_803D5524->unk9C == KING_PENGUIN) && (((D_803D5530->unk162 == 1)) || (D_803D5530->unk162 == 5))) {
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

        switch (D_803D5524->unk9C) {
        case KING_PENGUIN:
            break;
        case PENGUIN:
            switch (D_803D552C->unk365) {
            case ATTACK_PENGUIN_1:
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                if (ticks_remaining == 2) {
                    play_sound_effect_at_location(SFX_UNKNOWN_174, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
                if (ticks_remaining < 8) {
                    sp9E = ticks_remaining * 2;
                } else {
                    sp9E = 0x10;
                }
                if ((D_803D5530->unk162 != 3) || ((D_803D5538 != 0) && (D_801E9E8A == 0))) {
                    D_803D552C->unk32A = D_803D5544;
                    D_803D552C->unk365 = ATTACK_PENGUIN_2;
                }
                break;
            case ATTACK_PENGUIN_2:
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                if (ticks_remaining < 0x10) {
                    sp9E = 0x10;
                    sp9C = ticks_remaining;
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            case ATTACK_SNOWBALL:
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                if (ticks_remaining < 8) {
                    sp9A = ticks_remaining * 2;
                } else {
                    play_sound_effect_at_location(0, 0x6000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    if (D_803D5538 != 0) {

                        target = func_8037E9AC_79005C();
                        if (target != NULL) {
                            xDist = D_803D5530->position.xPos.h - target->position.xPos.h;
                            zDist = D_803D5530->position.zPos.h - target->position.zPos.h;
                            var_t5 = (target->unk42 * 3) >> 2;
                            sp88 = (D_803D5530->position.yPos.h - target->position.yPos.h) - var_t5 + 20;
                            sp84 = sqrtf(SQ(xDist) + SQ(zDist));
                            var_f14 = func_801286B8(-sp88, sp84) + SQ(64.0 / (f64)sp84);
                            while (var_f14 > 180.0) {
                                var_f14 -= 360.0;
                            }
                            var_f14 = MIN(MAX(var_f14, -45), 45);
                        } else {
                            var_f14 = 0.0f;
                        }
                        fire_cannonball_1(0x3D, 0xA, 0, 0x14, 0x19, (var_f14 * 256) / 360, 2, 6);
                    } else {
                        fire_cannonball_2(0x3D, 0xA, 0, 0x14, 0x23, D_803D5530->yRotation, D_803D552C->unk338, 2, 6);
                    }
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                if ((D_803D5530->yVelocity.h < -0xA) && ((D_803D5530->unk162 & 0xF) == 3) &&
                    ((D_803D5530->position.yPos.h - (func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10)) >= 0x31) &&
                    ((D_803D5538 == 0) || (D_801D9ED8.curAButton != 0))) {
                    D_803D552C->unk365 = ATTACK_PENGUIN_1;
                    D_803D552C->unk32A = D_803D5544;
                }
                break;
            }
            break;
        }
        if (sp9E >= 9) {
            if (D_803D5530->yVelocity.w < FTOFIX32(-0.99999)) {
                D_803D5530->xVelocity.w += (SIN(D_803D5540 << 3) >> 7) << 8;
                D_803D5530->zVelocity.w += (COS(D_803D5540 << 2) >> 7) << 8;

                D_803D5530->yVelocity.w = MIN(FTOFIX32(-1.0), D_803D5530->yVelocity.w + FTOFIX32(4.0));
            }
        }
        if ((D_803F2ECE == 0) || ((D_803F2ECC <= 30))) {

            D_803F2F00 = 0;
            func_802B975C_6CAE0C(&spA8, (scale * 150), 1);
            func_802C23F8_6D3AA8((scale * 78) + 47);

            D_80203FE0[0].unk2 += (sp9A * 0x12C) >> 5;
            D_80203FE0[1].unk2 += (sp9A * 0x12C) >> 5;
            D_80203FE0[2].unk2 += (sp9A * 0x12C) >> 5;

            D_80203FE0[26].unk0 = D_80203FE0[27].unk0 = 0;
            D_80203FE0[27].unk2 = -(sp9A * 0x12C) >> 4;
            D_80203FE0[26].unk2 = -(sp9A * 0x12C) >> 4;

            D_80203FE0[26].unk4 = 0x96;
            D_80203FE0[27].unk4 = D_80203FE0[26].unk4 + 0x10;

            switch (D_803F2F00) {
            case 1:
                func_80374660_785D10((scale * -170) / 32, 0, (scale * 300) + 300);
                break;
            case 2:
                func_80374660_785D10((scale * 170) / 32, 0, (scale * 300) + 300);
                break;
            }
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4200_7C58B0, D_803B4208_7C58B8, D_803B4210_7C58C0, D_803B4218_7C58C8);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4200_7C58B0, D_803B4208_7C58B8, D_803B4210_7C58C0, D_803B4230_7C58E0);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_14 = D_803F2AA2, (temp_v0_14 == 0)) || (temp_v0_14 == 2) || ((temp_v0_14 == 1) && ( D_803F2AA3 >= 0xB))) && ((*D_803F2C18 != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w,  -D_803D552C->heading, (scale * D_803F2EB0) / 4, (scale * D_803F2EB4) / 4, (scale * D_803F2EB8) / 4, D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.4f);
            load_2_tiles(D_04001730, D_04001750, D_04001330_DE8F0);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 1, D_04001010_DE5D0);
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 1, D_04001220_C8C50);
            }
            if (D_803D5524->unk9C == KING_PENGUIN) {
                // add crown
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 1, D_04001890_DEE50);
            }
            func_802C78B0_6D8F60(2, 0xF, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 0, 0, D_040012E0_DE8A0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(2, 0x12, 0x10000, 0x10000, 0x10000, D_803F2ED0, 0, 1, 0, D_040012E0_DE8A0);
            }
            if (sp9E != 0) {
                temp_a3 = MAX(0, (sp9E << 0xC) - (sp9C << 0xC));
                func_802C78B0_6D8F60(1, 2, (temp_a3 << 6) >> 6, (temp_a3 << 6) >> 6, ((((0x10 << 12) << 6) + (-(sp9C << 12) << 6))) >> 6, D_803F2ED0, 0, 0, 1, D_04001A60_DF020);
            }
            if ((sp9A != 0) && (D_803F2EDD == 0)) {
                temp_a3 = sp9A << 0xC;
                func_802C78B0_6D8F60(26, 27, (temp_a3 << 0x6) >> 6, (temp_a3 << 0x6) >> 6, (temp_a3 << 0x6) >> 6, D_803F2ED0, 0, 0, 1, D_04001B60_DF120);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA2 == 0) || (spA2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2), D_803D552C->heading, D_01033190_6CA60, (scale * 0x15E) / 32, (scale * 0x15E) / 32, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spA2 == 0) {
        func_80303820_714ED0(
            D_803D552C,
            1,
            1,
            ((scale * 300) * 2) >> 1,
            0);
        func_80303B18_7151C8(
            D_803D552C,
            1,
            ((scale * 300) * 5) >> 3,
            ((scale * 300) * 7) >> 3,
            1);
        func_80303D50_715400(
            D_803D552C,
            2);
    } else {
        func_80303D00_7153B0(D_803D552C, ((scale * 150) * 6) >> 1, 0x96);
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
            D_803D552C->position.xPos.h,
            D_803D552C->position.zPos.h,
            D_803D552C->position.yPos.h
            );

        if (D_803D5530->yVelocity.w > FTOFIX32(4.0)) {
            D_803D5530->yVelocity.w += FTOFIX32(1.0);
        } else {
            D_803D5530->yVelocity.w += FTOFIX32(2.5);
        }

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->position.xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->position.zPos.h) - 8,
            D_803D5530->position.yPos.h,
            (SSSV_RAND(2) + 25),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            (D_803D5530->yVelocity.w >> 1) - FTOFIX32(3.0517578125),
            SSSV_RAND(13),
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(56, 56, 56, 1),
            SSSV_RAND(16) + 20);

        create_particle_effect(
            (SSSV_RAND(16) + D_803D5530->position.xPos.h) - 8,
            (SSSV_RAND(16) + D_803D5530->position.zPos.h) - 8,
            D_803D5530->position.yPos.h,
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
            play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.3f);
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
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 0xA, 0x14, 0x23, 0x59, 0, 3, (f32) gGravity / 65536.0);
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
        play_sound_effect_at_location(SFX_BUGEL_CALL, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.3f);
        D_803D552C->unk308 = 50;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk2B4.unk4 = 1;
}
