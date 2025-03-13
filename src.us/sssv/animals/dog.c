#include <ultra64.h>
#include "common.h"

#include "dog.h"

extern u8 D_01038220_71AF0[];
extern u8 D_01038A20_722F0[];
extern u8 D_01039220_72AF0[];
extern u8 D_01039A20_732F0[];
extern u8 D_0103A220_73AF0[];

extern Gfx D_040001A0_C7BD0[]; // flying_dog_body
extern Gfx D_04000420_C7E50[]; // (racing)_dog_body
extern Gfx D_04000870_C82A0[]; // dog_head
extern Gfx D_04000DD0_C8800[]; // racing dog head?
extern Gfx D_04000FB0_C89E0[]; // dog thigh?
extern Gfx D_04001080_C8AB0[]; // dog leg?
extern Gfx D_04001150_C8B80[];
extern Gfx D_04001220_C8C50[];
extern Gfx D_04001320_C8D50[];
extern Gfx D_040013A0_C8DD0[];
extern Gfx D_040014F0_C8F20[]; // racing_dog_leg
extern Gfx D_040018B0_C92E0[];
extern Gfx D_04001A20_C9450[];
extern Gfx D_04001A40_C9470[];

extern Gfx D_04002720_CA150[]; // missile
extern Gfx D_04002810_CA240[];
extern Gfx D_04002888_CA2B8[];
extern Gfx D_04002910_CA340[];
extern Gfx D_040029A0_CA3D0[];


void func_8037FCA8_791358(void);

// RACING_DOG
#ifdef NON_MATCHING
// CURRENT (112) - stack
void func_802EA7F0_6FBEA0(void) {
    struct061 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp90;
    s16 sp8E;

    f32 var_f0;
    f32 tmp2;

    s16 pad[4];
    u8  tmp;

    if (((D_803D552C->unk366 == MOVEMENT_MODE_INJURED) || (D_803D552C->unk366 == MOVEMENT_MODE_CRITICAL)) && (SSSV_RAND(256) == 0x9C) && (D_803F6450 != 0)) {
        play_sound_effect_at_location(SFX_UNKNOWN_182, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
    if (D_803D552C->unk366 == MOVEMENT_MODE_NORMAL) {
        if (D_803D554C != 0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CD70_73E420(
                    D_803D5530,
                    SFX_UNKNOWN_100,
                    ((D_803D554C / 60.0) + .7) * 15104.0,
                    0,
                    (D_803D554C / 30.0) + 0.7,
                    D_803D5530->position.xPos.h,
                    D_803D5530->position.zPos.h,
                    D_803D5530->position.yPos.h);
            }
        }
    }
    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 0x19,
            (SSSV_RAND(32768) * 2) + FTOFIX32(-0.6103515625),
            (SSSV_RAND(32768) * 2) + FTOFIX32(-0.6103515625),
            0,
            SSSV_RAND(16) + 0xF,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 0xF);

        if (D_803D552C->unk2EC-- < 1) {
            D_803D552C->unk36E = 0;
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        D_803F2EDD = sp92 = 0;
    } else {
        sp92 = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x800,
            0,
            0x9E,
            0x9E,
            0x4F,
            1,
            CHECK_SEGMENT == 0);
    }

    if ((sp92 != 4) && (sp92 != 1) && (D_803D5530->unk162 == 1)) {
        var_f0 = sqrtf(SQ((f32)D_803D552C->xVelocity.w) + SQ((f32)D_803D552C->zVelocity.w)) / (D_803D5524->unkA4 << 0xA);
        if (var_f0 < 0.2) {
            tmp2 = 0.0f;
        } else if (var_f0 > 0.6) {
            tmp2 = 1.0f;
        } else {
            tmp2 = 2.5f * (var_f0 - 0.2);
        }
        if (tmp2 > 0.0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CED0_73E580(
                    D_803D5530,
                    SFX_UNKNOWN_13,
                    (12288.0f * tmp2) / 2.0,
                    var_f0 * 2.0,
                    0,
                    D_803D5538,
                    D_803D552C->position.xPos.h,
                    D_803D552C->position.zPos.h,
                    D_803D552C->position.yPos.h,
                    D_803D552C->xVelocity.w,
                    D_803D552C->zVelocity.w,
                    D_803D552C->yVelocity.w);
            }
        }
    }
    if (sp92 == 0) {
        func_8034B298_75C948(0);
        func_8037FCA8_791358();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            if (D_803D5538 != 0) {
                sp90 = ((D_803D554C * 900) >> 1) / 20;
            } else {
                sp90 = 0;
            }

            func_802B9130_6CA7E0(&sp98, 0x12C, 0x96, 900,  0);
            func_802C1830_6D2EE0(600, &sp98);
            func_802B964C_6CACFC();
            D_80203FE0[7].unk4 += sp90;
            D_80203FE0[10].unk4 += sp90;
            D_80203FE0[8].unk4 += sp90;
            D_80203FE0[11].unk4 += sp90;
            D_80203FE0[1].unk4 += sp90;
            D_80203FE0[0].unk4 += sp90 >> 1;
            func_802C4A70_6D6120(0x22C, 0x1BB, 0);
            D_80203FE0[19].unk2 -= sp90;
            D_80203FE0[20].unk2 -= sp90;
            func_8038CCF0_79E3A0(0xDD, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            if (D_803D5528->unk3C0.unk0 == 16) {
                if (D_803D5528->unk3C0.unk2 < 7) {
                    D_80203FE0[19].unk2 -= (D_803D5528->unk3C0.unk2 * 0x22C) / 6;
                    D_80203FE0[20].unk2 -= (D_803D5528->unk3C0.unk2 * 0x22C) / 6;
                } else if (D_803D5528->unk3C0.unk2 < 17) {
                    D_80203FE0[19].unk2 -= ((16 - D_803D5528->unk3C0.unk2) * 0x22C) / 10;
                    D_80203FE0[20].unk2 -= ((16 - D_803D5528->unk3C0.unk2) * 0x22C) / 10;
                }
            }
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A4DB0_7B6460, D_803A4DC4_7B6474, D_803A4DD8_7B6488, D_803A4DF8_7B64A8);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A4DB0_7B6460, D_803A4DC4_7B6474, D_803A4DD8_7B6488, D_803A4E40_7B64F0);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (tmp = D_803F2AA2, tmp == 0) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 >= 0xB))) && ((*D_803F2C18 != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.15f);
            load_1_tile(img_dog_body_pal, img_dog_body_ci4__png);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000420_C7E50);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) << 6) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) << 6) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04002720_CA150); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleRight + 8) * D_803F2EBC) >> 4) << 6) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC0) >> 4) << 6) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC4) >> 4) << 6) >> 6, D_803F2ED0, 0, 1, 0, D_04002720_CA150); }
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000870_C82A0);

            if ((D_803D5540 >= 0xB5) && (((D_803D552C->unk366 == MOVEMENT_MODE_INJURED)) || (D_803D552C->unk366 == MOVEMENT_MODE_NORMAL))) {
                sp8E = ((SIN(D_803D5540 << 6) >> 7) * 600) >> 0xC;
            } else {
                sp8E = 0;
            }
            D_80203FE0[2].unk0 += sp8E;
            D_80203FE0[1].unk0 += sp8E;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040013A0_C8DD0); }
            D_80203FE0[2].unk0 -= sp8E;
            D_80203FE0[1].unk0 -= sp8E;

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001220_C8C50); }
            func_802C78B0_6D8F60(7, 8, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040014F0_C8F20);
            func_802C78B0_6D8F60(0xA, 0xB, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0,0, 1, 0, D_040014F0_C8F20);
            func_802C78B0_6D8F60(0xD, 0xE, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040014F0_C8F20);
            func_802C78B0_6D8F60(0x10, 0x11, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0,0, 1, 0, D_040014F0_C8F20);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp96, &sp94);
                func_8031A278_72B928(&D_803D552C->unk326, &sp96, &sp94);
#pragma _permuter sameline start
                sp96 = D_803BD530_7CEBE0.eyes[1][sp96]; sp94 = D_803BD600_7CECB0.eyes[0][sp94];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, sp96);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A20_C9450);
                func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, sp94);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A40_C9470);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp92 == 0) || (sp92 == 2)) {
        func_8034BD20_75D3D0(
            D_803D552C->position.xPos.h,
            D_803D552C->position.zPos.h,
            D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1),
            D_803D552C->heading,
            img_D_01033190_6CA60_i4__png,
            0x19,
            0x12,
            0x9B,
            0,
            0,
            0,
            0,
            D_803D5538);
    }
    if (sp92 == 0) {
        if ((D_803D5528->unk3C0.unk0 == 16) && (D_803D5528->unk3C0.unk2 < 17)) {
            func_803034D0_714B80(D_803D552C, 600, 0, 0);
            func_80303D50_715400(D_803D552C, 2);
        } else {
            func_803034D0_714B80(D_803D552C, 600, 0, 1);
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, 0x1BB, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
        func_803034D0_714B80(D_803D552C, 600, 0, 1);
        if ((D_803D5528->unk3C0.unk0 == 16) && (D_803D5528->unk3C0.unk2 < 9)) {
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((9 - D_803D5528->unk3C0.unk2) * 0x1BB) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else if ((D_803D5528->unk3C0.unk0 == 16) && (D_803D5528->unk3C0.unk2 < 16)) {
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((D_803D5528->unk3C0.unk2 - 7) * 0x1BB) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1BB, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 600, 900);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802EA7F0_6FBEA0.s")
#endif

// FLYING_DOG
void update_flying_dog(void) {
    s32 pad[2];

    s16 spDE;
    s16 spDC;
    s16 spDA;
    s16 spD8;
    s16 spD6; // pad
    s16 spD4;
    s16 spD2;
    s16 spD0; // pad
    s16 spCE;
    s16 spCC;
    s16 spCA;
    s16 spC8;

    s16 xPos;
    s16 zPos;
    s16 yPos;
    s16 var_a2;

    s16 xPos2;
    s16 zPos2;
    u16 ticks_remaining;
    u8 var_v0_4;

    u8 *img;

    f32 spB0;

    if ((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED)) {
        if ((D_803D5530->unk162 == 3) && (D_803D5530->unk4A == 0)) {
            func_8032CED0_73E580((u8*)D_803D5530 + 3, SFX_UNKNOWN_128, (MIN(1.0, ABS(D_803D5530->yVelocity.w) / 655360.0) * 28672.0), 1.6f, 0, D_803D5538, D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h, D_803D552C->xVelocity.w, D_803D552C->zVelocity.w, D_803D552C->yVelocity.w);
        }
    }
    var_a2 = 0x5000;
    spB0 = ((SIN((D_803D5540 + D_803D552C->unk31C) << 3) >> 7) / 16384.0) + (1.15 + (D_803D5530->yVelocity.h / 30.0));
    if (D_803D552C->unk365 == 0x2F) {
        spB0 += (SSSV_RAND(0x8000) - 16384.0) / 65536.0;
        var_a2 = 0x4600 - SSSV_RAND(4092);
    }

    spB0 = MAX(0.2, spB0);

    if (D_803D5538 == 0) {
        var_a2 = var_a2 / 2;
    }
    if (D_803D552C->unk365 == 0x30) {
        var_a2 += (var_a2 * (SIN((D_803D5544 - D_803D552C->unk32A) * 6) >> 7)) / 512.0;
        spB0 += (spB0 * (SIN((D_803D5544 - D_803D552C->unk32A) * 6) >> 7)) / 1024.0;
    }
    if ((D_803D5538 != 0) || (D_803F2D50.segment != 0)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CED0_73E580(D_803D5530, SFX_UNKNOWN_125, var_a2, spB0, 0, D_803D5538, D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h, D_803D552C->xVelocity.w, D_803D552C->zVelocity.w, D_803D552C->yVelocity.w);
        }
    }

    D_803D552C->unk312 = MAX(0, D_803D552C->unk312 - 1);

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0_4 = 1;
        } else {
            var_v0_4 = 0;
        }
        if (var_v0_4 != 0) {
            spD8 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0_4 = 1;
    } else {
        var_v0_4 = 0;
    }
    spD8 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x800, 0, 0x9E,0x9E, 0x4F, 1, var_v0_4 == 0);

done:
    if (spD8 == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        spD4 = 0;spD2 = 0;
        if (D_803D552C->unk365 == ATTACK_DOG_1) {
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining == 0) {
                D_803D5530->yRotation = (D_803D5530->yRotation + 0x80) & 0xFF;
                D_803D552C->heading = D_803D5530->yRotation;
            }
            if (ticks_remaining > 24) {
                D_803D552C->unk365 = ATTACK_NONE;
            }

            if (ticks_remaining < 16) {
                spD4 = 180 - ((ticks_remaining * 180) / 16);
            } else {
                spD4 = 0;
            }

            if (ticks_remaining > 8) {
                spD2 = 180 - (((ticks_remaining - 8) * 180) / 16);
            } else {
                spD2 = 180;
            }
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802BAA38_6CC0E8(0x12C, 0x96);
            func_802C4A70_6D6120(0x22C, 0x1BB, 0);
            func_802BB70C_6CCDBC(0x12C, 0x2BC);
            func_8038CCF0_79E3A0(0xDD, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();
        }

        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A4E88_7B6538, D_803A4E90_7B6540, D_803A4E98_7B6548, D_803A4EA4_7B6554);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A4E88_7B6538, D_803A4E90_7B6540, D_803A4E98_7B6548, D_803A4EC4_7B6574);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (var_v0_4 = D_803F2AA2, (var_v0_4 == 0)) || (var_v0_4 == 2) || ((var_v0_4 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D5530->yRotation, 0x4000, 0x4000, 0x4000, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if ((spD4 != 0) || (spD2 != 0)) {
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.0f, 0.0f, D_803D5530->unk42);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], spD4, 1.0f, 0.0f, 0.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], spD2, 0.0f, 1.0f, 0.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.0f, 0.0f, -D_803D5530->unk42);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.22f);
            load_1_tile(img_flying_dog_body_pal, img_flying_dog_body_ci4__png);
            func_802C78B0_6D8F60(2, 1, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040001A0_C7BD0);
            func_802C78B0_6D8F60(0x13, 0x14, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000DD0_C8800);

            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0x00, 0xFF);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001220_C8C50); }

            if (D_803F2D10.unk0 != 0) {
                spDA = 0x34;
            } else {
                spDA = (SSSV_RAND(16) * 0x22C) >> 5;
            }

            D_80203FE0[1].unk4 -= spDA;
            func_802C78B0_6D8F60(1, 0x13, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001320_C8D50);
            D_80203FE0[1].unk4 += spDA;
            func_80356F64_768614(img_flying_dog_wing_TLUT1_pal, img_flying_dog_wing_TLUT2_pal, img_flying_dog_wing_ci4__png);
            func_802C78B0_6D8F60(0, 0x17, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040018B0_C92E0);
            func_802C78B0_6D8F60(0, 0x19, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040018B0_C92E0);

            if (D_803D552C->unk312 == 2) {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, (SSSV_RAND(0x80) + 0x80), 0x00, 0xFF);
                if (D_803D552C->missileSide != 0) {
                    gSPDisplayList(D_801D9E88++, D_04002910_CA340);
                } else {
                    gSPDisplayList(D_801D9E88++, D_040029A0_CA3D0);
                }
            }

            if (D_803D552C->unk30E != 0) {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, SSSV_RAND(0x80) + 0x80, 0x00, 0xFF);
                if (D_803D552C->missileSide != 0) {
                    gSPDisplayList(D_801D9E88++, D_04002810_CA240);
                } else {
                    gSPDisplayList(D_801D9E88++, D_04002888_CA2B8);
                }

                xPos = D_803D5530->position.xPos.h;
                zPos = D_803D5530->position.zPos.h;
                yPos = D_803D5530->position.yPos.h;

                if (D_803D5538 != 0) {
                    xPos2 = (((COS(64 - D_803D552C->heading) >> 7) * 6) >> 2) + xPos;
                    zPos2 = (((SIN(64 - D_803D552C->heading) >> 7) * 6) >> 2) + zPos;
                } else {
                    xPos2 = (((COS(64 - D_803D552C->heading) >> 7) * 4) >> 2) + xPos;
                    zPos2 = (((SIN(64 - D_803D552C->heading) >> 7) * 4) >> 2) + zPos;
                }
                if (func_80322D68_734418(xPos, zPos, yPos, xPos2, zPos2, yPos, &spCE, &spCC, &spCA, 0x32, 1, 1, 0xE) == 2) {
                    for (spC8 = 0; spC8 < 4; spC8++) {
                        create_particle_effect(
                          spCE,
                          spCC,
                          spCA,
                          24,
                          (SSSV_RAND(16) - 7) << 0x10,
                          (SSSV_RAND(16) - 7) << 0x10,
                          SSSV_RAND(16) << 0x10,
                          SSSV_RAND(4) + 4,
                          GPACK_RGBA5551(248, 128, 0, 1), // orange
                          GPACK_RGBA5551(248, 128, 0, 1), // orange
                          0);
                    }

                    if (D_803D5538 == 0) {
                        if ((ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.xPos.h - spCE) < 0x60) &&
                            (ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.zPos.h - spCC) < 0x60) &&
                            (ABS(D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.yPos.h - spCA) < 0x60)) {
                            play_sound_effect_at_location(SFX_UNKNOWN_26, 0x5000, 0, spCE, spCC, spCA, 1.0f);
                        }
                    }
                }
                D_803D552C->unk30E = 0;
            }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spDE, &spDC);
                func_8031A278_72B928(&D_803D552C->unk326, &spDE, &spDC);
                spDE = D_803BD530_7CEBE0.eyes[1][spDE]; spDC = D_803BD600_7CECB0.eyes[0][spDC];
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes_ci4__png, spDE);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A20_C9450);
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes_ci4__png, spDC);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A40_C9470);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spD8 == 0) || (spD8 == 2)) {
        // get barrel roll image
        if (ABS(D_803D552C->unk30C) > 52) {
            img = D_0103A220_73AF0;
        } else if (ABS(D_803D552C->unk30C) > 37) {
            img = D_01039A20_732F0;
        } else if (ABS(D_803D552C->unk30C) > 22) {
            img = D_01039220_72AF0;
        } else if (ABS(D_803D552C->unk30C) > 7) {
            img = D_01038A20_722F0;
        } else {
            img = D_01038220_71AF0;
        }
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, img, 37 - ((ABS(D_803D5530->unk28) * 0x25) / 100), 0x25, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spD8 == 0) {
        func_803034D0_714B80(D_803D552C, 600, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1BB, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 600, 900);
    }
}

// DOG
#ifdef NON_MATCHING
// just the stack
void func_802ED108_6FE7B8(void) {

    struct061 spB8;
    s16 spB6;
    s16 spB4;
    s16 spB2;
    s16 spB0;
    // s16 spAE;
    u16 temp_t6;
    s16 spAC;
    s16 spAA;

    u16 ticks_remaining; // sp78?
    u8 tmp;
    s32 pad;

    spB0 = ticks_remaining * 4; // what?

    if (((D_803D552C->unk366 == MOVEMENT_MODE_INJURED) || (D_803D552C->unk366 == MOVEMENT_MODE_CRITICAL)) && (SSSV_RAND(256) == 0x9C) && (D_803F6450 != 0)) {
        play_sound_effect_at_location(SFX_UNKNOWN_182, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spB2 = 0;
        D_803F2EDD = 0;
    } else {
        spB2 = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x800,
            0,
            0x9E,
            0x9E,
            0x4F,
            1,
            CHECK_SEGMENT == 0);
    }

    if (spB2 == 0) {
        temp_t6 = D_803D5544 - D_803D552C->unk35E;
        if ((D_803F6450 != 0) && (D_803F2D10.unk0 == 0) && (D_803D5530->unk4A == 0) && (temp_t6 != 0) && ((D_803D552C->unk366 == MOVEMENT_MODE_NORMAL) || (D_803D552C->unk366 == MOVEMENT_MODE_INJURED))) {
            if (D_803D552C->unk30A != 0) {
                D_803D552C->unk30A--;
                D_803D5530->yRotation = (D_803D5530->yRotation + D_803D552C->unk308) % 255;
            }
            if (D_803D552C->unk30A == 0) {
                if ((((temp_t6 & 0xFF) == 0xFA) || ((temp_t6 & 0xFF) == 0x8C) || ((temp_t6 & 0xFF) == 0xA0) || ((temp_t6 & 0xFF) == 0xAA) || ((temp_t6 & 0xFF) == 0xB4) || ((temp_t6 & 0xFF) == 0xC8) || (((temp_t6 & 0xFF) == 0xDC) && (((D_803D552C->unk366 == MOVEMENT_MODE_NORMAL)) || (D_803D552C->unk366 == MOVEMENT_MODE_INJURED)))) && ((D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11) && (gCameras[gCameraId].cameraMode != 5) && (gCameras[gCameraId].cameraMode != 6) && (gCameras[gCameraId].cameraMode != 7) && (gCameras[gCameraId].cameraMode != 0x1C) && (gCameras[gCameraId].cameraMode != 0x1A)))) {
                    if (((temp_t6 & 0xFF) == 0x8C) || ((temp_t6 & 0xFF) == 0xDC)) {
                        play_sound_effect_at_location(SFX_UNKNOWN_8, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                    D_803D552C->unk308 = SSSV_RAND(8) - 4;
                    D_803D552C->unk30A = 7;
                    if (D_803D552C->unk308 <= 0) {
                        D_803D5528->unk370.unk4 = 25;
                        D_803D5528->unk3AC.unk4 = 25;
                        D_803D5528->unk384.unk6 = -25;
                        D_803D5528->unk398.unk6 = -25;
                    } else {
                        D_803D5528->unk370.unk4 = -25;
                        D_803D5528->unk3AC.unk4 = -25;
                        D_803D5528->unk384.unk6 = 25;
                        D_803D5528->unk398.unk6 = 25;
                    }
                }
                func_802C7BB4_6D9264(8);
            }
        } else {
            D_803D552C->unk30A = 0;
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DEC4_76F574();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spB8, 0x12C, 0x96, 0x3CE, 0x96);
            func_802BD40C_6CEABC(0x1DA, 0xC8, 0x12C, 0x96, 0, 0x34, 0, 0x20, &D_803A4C34_7B62E4, &D_803A4C64_7B6314, &D_803A4C94_7B6344, 0x1DA, 0xC8, 0x12C, 0x96, 0x64, 0xE4, 0x64, 0x84, &D_803A4C34_7B62E4, &D_803A4C64_7B6314, &D_803A4C94_7B6344, &spB8, 1);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x22C, 0x1BB, 0);
            func_8038CCF0_79E3A0(0xDD, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            if (D_803D5528->unk3C0.unk0 == 16) {
                if (D_803D5528->unk3C0.unk2 < 7) {
                    D_80203FE0[19].unk2 -= (D_803D5528->unk3C0.unk2 * 556) / 6;
                    D_80203FE0[20].unk2 -= (D_803D5528->unk3C0.unk2 * 556) / 6;
                } else if (D_803D5528->unk3C0.unk2 < 17) {
                    D_80203FE0[19].unk2 -= ((-D_803D5528->unk3C0.unk2 * 556) + 8896) / 10;
                    D_80203FE0[20].unk2 -= ((-D_803D5528->unk3C0.unk2 * 556) + 8896) / 10;
                }
            }
        }

        spAC = 0;
        switch (D_803D552C->unk365) {
        case ATTACK_BITE:
            D_803D5528->unk3C0.unk0 = 0;
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining == 4) {
                if (func_803224C4_733B74(0x1E, 0x45, 0, 0x22, 7, 0, 0, 0xE) != 0) {
                    // enemy close enough to bite
                    play_sound_effect_at_location(SFX_RAT_BITE, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                } else {
                    // bark?
                    play_sound_effect_at_location(SFX_UNKNOWN_182, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
            } else if (ticks_remaining >= 12) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            if (ticks_remaining < 5) {
                spB0 = ticks_remaining << 2;
                if (ticks_remaining == 1) {
                    apply_recoil(-3); // push dog forward as part of bark
                }
            } else {
                spB0 = (12 - ticks_remaining) << 1;
            }

            D_80203FE0[19].unk2 += (spB0 * 0x22C) >> 4;
            D_80203FE0[19].unk4 -= (spB0 * 0x22C) >> 5;

            D_80203FE0[20].unk2 += (spB0 * 0x22C) >> 4;
            D_80203FE0[20].unk4 -= (spB0 * 0x22C) >> 6;
            break;
        case ATTACK_DOG_2:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining == 1) {
                play_sound_effect_at_location(SFX_UNKNOWN_34, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            }
            if (ticks_remaining < 60) {
                if ((D_803D5538 != 0) && (ticks_remaining == 1)) {
                    D_803D554A++;
                }
                spAC = (SIN(ticks_remaining << 5) >> 7) >> 2;

                create_particle_effect(
                    (SSSV_RAND(32) + D_803D5530->position.xPos.h) - 0x10,
                    (SSSV_RAND(32) + D_803D5530->position.zPos.h) - 0x10,
                    D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
                    0x18,
                    ((SSSV_RAND(64) - 32) << 0xC) + D_803D5530->xVelocity.w,
                    ((SSSV_RAND(64) - 32) << 0xC) + D_803D5530->zVelocity.w,
                    D_803D5530->yVelocity.w + FTOFIX32(6.0),
                    SSSV_RAND(4) + 2,
                    GPACK_RGBA5551(0, 0, 0, 0),
                    GPACK_RGBA5551(0, 0, 0, 0),
                    0);
                D_803D5530->xVelocity.w += (SSSV_RAND(64) - 32) << 12;
                D_803D5530->zVelocity.w += (SSSV_RAND(64) - 32) << 12;
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
                if (D_803D5538 != 0) {
                    D_803D554A -= 1;
                }
            }
            break;
        default:
            if ((D_803D552C->unk36C != 0) && (D_803D5530->state == 2) && ((D_803D5544 - D_803D552C->unk35E) >= 0x51) && (SSSV_RAND(64) == 0x1B)) {
                D_803D552C->unk36C = 0;
                D_803D552C->unk32A = D_803D5544;
                D_803D552C->unk365 = ATTACK_DOG_2;
                D_803D5528->unk3C0.unk0 = 17;
                D_803D5528->unk3C0.unk2 = 0;
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A4CA8_7B6358, D_803A4CC0_7B6370, D_803A4CD8_7B6388, D_803A4D00_7B63B0);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A4CA8_7B6358, D_803A4CC0_7B6370, D_803A4CD8_7B6388, D_803A4D58_7B6408);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs +  30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || (((tmp = D_803F2AA2) == 0)) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 17)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                D_803D5530->position.xPos.w,
                D_803D5530->position.zPos.w,
                D_803D5530->position.yPos.w,
                -D_803D552C->heading,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0((D_803D5524->unkBA * 8 / 5), 2, 3, 3, 0.22f);
            load_1_tile(img_dog_body_pal, img_dog_body_ci4__png);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, spAC, 0, 0, D_04000420_C7E50);
            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000870_C82A0);
            if ((D_803D5540 >= 0xB5) && ((D_803D552C->unk366 == MOVEMENT_MODE_INJURED) || (D_803D552C->unk366 == MOVEMENT_MODE_NORMAL))) {
                spAA = ((SIN(D_803D5540 << 6) >> 7) * 600) >> 0xC;
            } else {
                spAA = 0;
            }
            D_80203FE0[2].unk0 += spAA;
            D_80203FE0[1].unk0 += spAA;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040013A0_C8DD0); }
            D_80203FE0[2].unk0 -= spAA;
            D_80203FE0[1].unk0 -= spAA;

            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x14, 0x14, 0x14, 0xFF);
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 19, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001220_C8C50); }
#pragma _permuter sameline end
            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7,  FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04000FB0_C89E0); }
            func_802C78B0_6D8F60(7,  8,  FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(10, 11, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(13, 14, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            func_802C78B0_6D8F60(16, 17, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001080_C8AB0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(8,  9,  FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(11, 12, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(14, 15, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(17, 18, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04001150_C8B80); }

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spB6, &spB4);
                func_8031A278_72B928(&D_803D552C->unk326, &spB6, &spB4);
#pragma _permuter sameline start
                spB6 = D_803BD530_7CEBE0.eyes[1][spB6]; spB4 = D_803BD600_7CECB0.eyes[0][spB4];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, spB6);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A20_C9450);
                func_80356BD8_768288(img_eyes_TLUT2_pal, img_eyes_ci4__png, spB4);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04001A40_C9470);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spB2 == 0) || (spB2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 0x15, 0x12, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spB2 == 0) {
        if ((D_803D5528->unk3C0.unk0 == 0x10) && (D_803D5528->unk3C0.unk2 < 9)) {
            func_803034D0_714B80(D_803D552C, 900, 0, 0);
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((-D_803D5528->unk3C0.unk2 * 0x1BB) + 0xF93) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else if ((D_803D5528->unk3C0.unk0 == 0x10) && (D_803D5528->unk3C0.unk2 < 0x10)) {
            func_803034D0_714B80(D_803D552C, 900, 0, 1);
            func_80303820_714ED0(D_803D552C, 0x13, 0x14, ((D_803D5528->unk3C0.unk2 * 0x1BB) - 0xC1D) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_803034D0_714B80(D_803D552C, 900, 0, 1);
            func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1BB, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 600, 900);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/dog/func_802ED108_6FE7B8.s")
#endif

void func_802EE89C_6FFF4C(void) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    if (D_803D5538 != 0) {
        play_sound_effect_at_location(SFX_UNKNOWN_148, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;

    if (D_803D552C->unk310 == 0) {
        play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        fire_cannonball_1(OBJECT_CANNONBALL, 0, 0, -28, 0, 0, -9, 8);
        D_803D552C->unk310 = 20;
    }
    D_803D552C->unk310 = MAX(3, D_803D552C->unk310 - 1);
}

void func_802EE9EC_70009C(void) {
    D_803D552C->unk310 = MAX(0, D_803D552C->unk310 - 1);
}

void func_802EEA18_7000C8(void) {
    if (D_803D552C->unk365 != ATTACK_DOG_1) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_DOG_1;
    }
}

void func_802EEA54_700104(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
}

void func_802EEA7C_70012C(void) {

    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 15,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 15
        );
    } else {
        set_target_speed(16);
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 15,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 15
        );
    }
}

void func_802EEC44_7002F4(void) {
    Animal * animal;
    s16 offset;

    animal = func_8037E9AC_79005C();
    if (animal == NULL) {
        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
    }
    if (get_missile_side()) {
        offset = 450;
    } else {
        offset = -450;
    }
    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + ((D_803D5530->unk42 * 3) >> 2),
        0,
        ((D_803D552C->heading & 0xFF) * 360) >> 8,
        animal,
        3,
        30,
        0.23f,
        23,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void racing_dog_fire_missile(Animal *animal) {
    s16 offset;

    if (animal == NULL) {
        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
    }
    if (get_missile_side() != 0) {
        offset = 450;
    } else {
        offset = -450;
    }
    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + ((D_803D5530->unk42 * 3) >> 2),
        10,
        ((D_803D552C->heading & 0xFF) * 360) >> 8,
        animal,
        4,
        30,
        0.23f,
        35,
        15,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void dog_bite(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_BITE;
}

void flying_dog_fire_gun(s32 arg0, s32 arg1, s32 arg2) {
    if (D_803D552C->missileSide != 0) {
        D_803D552C->missileSide = 0;
    } else {
        D_803D552C->missileSide = 1;
    }
    D_803D552C->unk30E = 1;
    D_803D552C->unk312 = 4;
}

void flying_dog_drop_bomb(s32 arg0, s32 arg1, s32 arg2) {
    fire_cannonball_1(OBJECT_CANNONBALL, 0, 0, -28, 0, 0, -9, 8);
    play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void racing_dog_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
