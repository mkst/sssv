#include <ultra64.h>
#include "common.h"

extern u8 D_803A5340_7B69F0[];
extern u8 D_803A534C_7B69FC[];
extern s16 D_803A5358_7B6A08[];
extern s16 D_803A536C_7B6A1C[];
extern s16 D_803A5398_7B6A48[];

extern Gfx D_040001F0_DD7B0[];

void func_80300210_7118C0(void) {
    s16 temp_t8;
    u8 var_a0;
    s16 sp9A;
    struct061 sp90;
    s16 sp8E;
    s16 sp8C;
    s16 sp8A;
    s16 sp88;
    s16 sp86;
    u16 ticks_remaining;
    s16 sp82;
    s16 sp80;
    s16 sp7E;


    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp88 = 0;
        D_803F2EDD = 0;
    } else {
        sp88 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x900, 6, 0x9B, 0x9B, 0x9B, 1, CHECK_SEGMENT == 0);
    }

    if (sp88 == 0) {
        func_8038C768_79DE18();
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0xE, 0xF, 0xA);
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xC8);

        sp86 = 8; // default scale => (8 << 13) == 0x10000 == FTOFIX32(1.0)

        if (D_803D552C->unk365 == ATTACK_RABBIT_1) {
            if (D_803D5530->unk162 == 1) {
                ticks_remaining = D_803D5544 - D_803D552C->unk32A;
                if (ticks_remaining < 0xA) {
                    temp_t8 = SSSV_RAND(512) << 5;
                    sp86 = MAX(0, ticks_remaining - 2) + 8;
                    D_803F2EB0 += temp_t8;
                    D_803F2EB4 += temp_t8;
                    D_803F2EB8 += temp_t8;
                    if (ticks_remaining == 1) {
                        play_sound_effect_at_location(SFX_UNKNOWN_83, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                } else if (ticks_remaining == 0xA) {
                    D_803D5528->unk398.unk10 = 1;
                    D_803D5528->unk398.unk12 = 0;
                } else if ((D_803D5528->unk398.unk10 == 1) && (D_803D5530->unk162 == 1)) {
                    ticks_remaining -= 10;
                    sp86 = 0x10;
                    if ((ticks_remaining & 7) == 0) { // b00000111
                        func_8037D340_78E9F0(9, 0x100);
                        play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

                        sp82 = ((((COS(D_803D552C->heading) * D_80203FE0[15].unk0) / 16) + ((SIN(D_803D552C->heading) * D_80203FE0[15].unk2) / 16)) >> 0x10) + D_803D5530->position.xPos.h;
                        sp80 = ((((COS(D_803D552C->heading) * D_80203FE0[15].unk2) / 16) - ((SIN(D_803D552C->heading) * D_80203FE0[15].unk0) / 16)) >> 0x10) + D_803D5530->position.zPos.h;

                        for (sp7E = 0; sp7E < 3; sp7E++) {
                            create_particle_effect(
                                sp82,
                                sp80,
                                D_803D5530->position.yPos.h,
                                0x18,
                                (SSSV_RAND(16) - 7) << 0xF,
                                (SSSV_RAND(16) - 7) << 0xF,
                                SSSV_RAND(16) << 0xF,
                                SSSV_RAND(4) + 4,
                                GPACK_RGBA5551(248, 248, 248, 1),
                                GPACK_RGBA5551(200, 200, 200, 1), // grey
                                0);
                        }

                        create_particle_effect(
                            sp82,
                            sp80,
                            D_803D5530->position.yPos.h,
                            0x15,
                            0,
                            0,
                            0x20000,
                            0x32,
                            GPACK_RGBA5551(152, 152, 152, 1), // dark grey
                            GPACK_RGBA5551(96, 96, 96, 1), // darker grey
                            0);
                        if ((D_803D552C->unk366 != MOVEMENT_MODE_NORMAL) && (D_803D552C->unk366 != MOVEMENT_MODE_INJURED)) {
                            D_803D552C->unk365 = 0;
                        }
                    }
                } else {
                    D_803D552C->unk365 = 0;
                }
            } else {
                D_803D552C->unk365 = 0;
            }
        } else {
            D_803D552C->unk365 = 0;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B96D0_6CAD80(&sp90, 0x177, 0, 0);
            func_802C1A88_6D3138(0x339, &sp90);
            func_802C5EF4_6D75A4(0x1C2, 0x12C);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A5340_7B69F0, D_803A534C_7B69FC, D_803A5358_7B6A08, D_803A536C_7B6A1C);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5340_7B69F0, D_803A534C_7B69FC, D_803A5358_7B6A08, D_803A5398_7B6A48);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || ((var_a0 = D_803F2AA2) == 0) || (var_a0 == 2) || ((var_a0 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (u32) ((s32) D_803F2EB8 / 4), (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0(((D_803D5524->unkBA * 4) / 5), 1, 2, 2, -0.35f);

            sp9A = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
            if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803F2D10.unk0 == 0)) {
                func_80300130_7117E0(&sp9A, &D_803D552C->unk30A, 0x14, -0x14, 2, 2, D_803D5530->yVelocity.h * 0x10, 3);
            } else {
                D_803D552C->unk30A = 0;
                sp9A = D_803D552C->unk30A;
            }
            D_803D552C->unk308 = sp9A;
            if ((D_803D5530->state < 0x2C) && (D_803D5530->state >= 0x29)) {
                D_80203FE0[1].unk2 += D_803D552C->unk30E << 6;
                D_80203FE0[19].unk2 += D_803D552C->unk30E << 6;
                D_80203FE0[20].unk2 += D_803D552C->unk30E << 6;

                D_80203FE0[1].unk4 -= D_803D552C->unk30E << 6;
                D_80203FE0[19].unk4 -= D_803D552C->unk30E << 6;
                D_80203FE0[20].unk4 -= D_803D552C->unk30E << 6;
            }
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040000E0_DD6A0);

            if (D_803D5542 < 0x78) {
                sp8E = ((SIN(D_803D5542 << 5) >> 7) * 0x96) >> 8;
            } else {
                sp8E = 0;
            }
            if (D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) {
                sp8E = 0;
            }

            D_80203FE0[1].unk4 += sp8E;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000900_DDEC0); }
            D_80203FE0[1].unk4 -= sp8E;

            // scale of right foot?
            func_802C78B0_6D8F60(2, 0xF, (sp86 << 0x13) >> 6, (sp86 << 0x13) >> 6, (sp86 << 0x13) >> 6, D_803F2ED0, 0, 0, 0, D_040002D0_DD890);
            func_802C78B0_6D8F60(2, 0x12, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 1, 0, D_040002D0_DD890);

            D_80203FE0[1].unk4 -= sp9A * 8;
            D_80203FE0[19].unk4 -= sp9A * 8;
            D_80203FE0[20].unk4 -= sp9A * 8;

            func_802C6FF4_6D86A4(0x96, 0x258);

            if (D_803D552C->unk316 != 0) {
                guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D552C->unk316, 0.0f, 0.0f, 1.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }
            func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040005A0_DDB60);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x1A, 0x1B, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040001F0_DD7B0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0x1C, 0x1D, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 1, 0, D_040001F0_DD7B0); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp8C, &sp8A);
                func_8031A278_72B928(&D_803D552C->unk326, &sp8C, &sp8A);
                sp8C = D_803BD530_7CEBE0.eyes[2][sp8C];sp8A = D_803BD600_7CECB0.eyes[1][sp8A];
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes2_ci4__png, sp8C);
                func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000AE0_DE0A0);
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes2_ci4__png, sp8A);
                func_802C78B0_6D8F60(1, 0x13, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000B40_DE100);
                gDPPipeSync(D_801D9E88++);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp88 == 0) || (sp88 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (s16) (D_803D552C->position.yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 0xF, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp88 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 1, 0x177, 1);
        func_80303820_714ED0(D_803D552C, 0x13, 0x14, 0x14C, 0);
        func_80303D50_715400(D_803D552C, 2);
        return;
    }
    func_80303D00_7153B0(D_803D552C, 0x465, 0x177);
}

// HELI_RABBIT
#ifdef NON_MATCHING
void func_80301248_7128F8(void) {
    u8 tmp;
    f32 temp_f14;
    s16 idx;
    s32 z_scale;

    s16 sp96;    // sp96
    s16 heading; // sp94?
    s32 x_scale; // sp90
    s16 sp8E;
    s16 sp8C;
    s16 var_t0; // sp8A
    s16 sp88;
    s16 sp86;
    s16 sp84;

    s32 pad; // sp80?
    f32 temp_f16; // sp7C
    s16 pad2[2];


    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp84 = 0;
        D_803F2EDD = 0;
    } else {
      sp84 = func_802E89F0_6FA0A0(
          D_803D552C->position.xPos.w,
          D_803D552C->position.zPos.w,
          D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
          0x900,
          6,
          0x9B,
          0x9B,
          0x9B,
          1,
          CHECK_SEGMENT == 0);
    }

    if ((sp84 != 4) && (sp84 != 1) && ((D_803D552C->unk366 == MOVEMENT_MODE_INJURED) || (D_803D552C->unk366 == MOVEMENT_MODE_NORMAL) || (D_803D552C->unk366 == MOVEMENT_MODE_CRITICAL))) {
        temp_f16 = D_803D552C->unk30E / 100.0;
        if (temp_f16 < 0.6) {
            temp_f14 = (temp_f16 * 1.666);
        } else {
            temp_f14 = 1.0f;
        }
        if (temp_f14 > 0.0) {
            func_8013328C(D_803D5530,          SFX_UNKNOWN_31, 64, temp_f16 * 1.2,  (20480.0f * temp_f14) * (0.5 + ((1.0 - temp_f16) / 2.0)), 0);
            func_8013328C((u8*)D_803D5530 + 2, SFX_UNKNOWN_28, 64, temp_f16 * 1.2, ((20480.0f * temp_f14) * temp_f16) / 3.0, 0);
        }
    }
    if (sp84 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(14, 15, 10);
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B96D0_6CAD80(&sp8C, 375, 0, 0);
            func_802C1A88_6D3138(825, &sp8C);
            func_802C5EF4_6D75A4(450, 300);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A53C4_7B6A74, D_803A53CC_7B6A7C, D_803A53D4_7B6A84, &D_803A53E0_7B6A90);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A53C4_7B6A74, D_803A53CC_7B6A7C, D_803A53D4_7B6A84, &D_803A53FC_7B6AAC);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            (((D_803D5538 != 0)) || (((tmp = D_803F2AA2) == 0)) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.35f);

            if ((D_803D5530->state == 0x7A) || (D_803D5530->state == 0x7B)) {
#if 1
                // better regalloc but worse instructions
                heading = D_803D552C->heading;
                idx = -(heading * 360) / 256;

                x_scale = ((D_803D5530->xVelocity.w * D_80152350.unk384[idx]) + (D_803D5530->zVelocity.w * D_80152350.unk2D0[idx])) / 256;
                z_scale = ((D_803D5530->zVelocity.w * D_80152350.unk384[idx]) - (D_803D5530->xVelocity.w * D_80152350.unk2D0[idx])) / 256;

                x_scale = (x_scale >> 14);
                z_scale = (z_scale >> 14);

                x_scale = -x_scale;
                z_scale = -z_scale;
#else
                // worse regalloc but better instructions
                x_scale = ((D_80152350.unk2D0[(s16) (-(D_803D552C->heading * 360) / 256)] * D_803D5530->zVelocity.w));
                x_scale = (x_scale + (D_80152350.unk384[(s16) (-(D_803D552C->heading * 360) / 256)] * D_803D5530->xVelocity.w));
                x_scale /= 256;

                z_scale = ((D_80152350.unk2D0[(s16) (-(D_803D552C->heading * 360) / 256)] * D_803D5530->xVelocity.w));
                z_scale = ((D_80152350.unk384[(s16) (-(D_803D552C->heading * 360) / 256)] * D_803D5530->zVelocity.w) - z_scale);
                z_scale /= 256;

                x_scale = -((x_scale) >> 14);
                z_scale = -((z_scale) >> 14);
#endif
                x_scale = MIN(30, x_scale);
                x_scale = MAX(-30, x_scale);
                z_scale = MIN(30, z_scale);
                z_scale = MAX(-30, z_scale);

                guRotateRPY(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], z_scale, x_scale, 0.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }
            sp96 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
            if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803F2D10.unk0 == 0)) {
                func_80300130_7117E0(&sp96, &D_803D552C->unk30A, 0x14, -0x14, 2, 2, D_803D5530->yVelocity.h * 0x10, 3);
            } else {
                D_803D552C->unk30A = 0;
                sp96 = D_803D552C->unk30A;
            }
            D_803D552C->unk308 = sp96;
            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, D_803D552C->unk30C, 0, 0, D_04000840_DDE00);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040000E0_DD6A0);

            if (D_803D5542 < 0x78) {
                var_t0 = (((SIN(D_803D5542 << 5) >> 7) * 0x96)) >> 8;
            } else {
                var_t0 = 0;
            }
            if (D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) {
                var_t0 = 0;
            }
            D_80203FE0[1].unk4 += var_t0;

            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(1, 2, (D_803F2EBC << 6) >> 6, (D_803F2EC0 << 6) >> 6, (D_803F2EC4 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000900_DDEC0);
            }
            D_80203FE0[1].unk4 -= var_t0;
            D_80203FE0[1].unk4 -= sp96 * 4;
            D_80203FE0[19].unk4 -=  sp96 * 4;
            D_80203FE0[20].unk4 -=  sp96 * 4;
            func_802C78B0_6D8F60(1, 19, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_040005A0_DDB60);
            func_802C78B0_6D8F60(2, 15, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040002D0_DD890);
            func_802C78B0_6D8F60(2, 18, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 1, 0, D_040002D0_DD890);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp88, &sp86);
                func_8031A278_72B928(&D_803D552C->unk326, &sp88, &sp86);
#pragma _permuter sameline start
                sp88 = D_803BD530_7CEBE0.eyes[2][sp88]; sp86 = D_803BD600_7CECB0.eyes[1][sp86];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes2_ci4__png, sp88);
                func_802C78B0_6D8F60(1, 19, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000AE0_DE0A0);
                func_80356BD8_768288(img_eyes_TLUT4_pal, img_eyes2_ci4__png, sp86);
                func_802C78B0_6D8F60(1, 19, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04000B40_DE100);
                gDPPipeSync(D_801D9E88++);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp84 == 0) || (sp84 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 0xF, 0xF, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp84 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 1, 375, 1);
        func_80303820_714ED0(D_803D552C, 19, 20, 332, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 1125, 375);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/rabbit/func_80301248_7128F8.s")
#endif

// rabbit
void func_80302018_7136C8(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D552C->unk365 == ATTACK_NONE)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_RABBIT_1;
    } else {
        recharge_skill(1);
    }
}

// heli-rabbit
void func_80302080_713730(void) {
    if (D_803D5530->unk162 != 1) {
        fire_cannonball_1(OBJECT_CANNONBALL, 0, 0, -30, 0, 0, -9, 24);
        play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    } else {
        recharge_skill(1);
    }
}

void heli_rabbit_drop_bomb(s32 arg0, s32 arg1, s32 arg2) {
    fire_cannonball_1(OBJECT_CANNONBALL, 0, 0, -30, 0, 0, -9, 20);
    play_sound_effect_at_location(SFX_DROP_BOMB, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_803021A8_713858(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D552C->unk365 == ATTACK_NONE)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_RABBIT_1;
    }
}
