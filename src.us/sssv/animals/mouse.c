#include <ultra64.h>
#include "common.h"

#include "mouse.h"

extern Gfx D_040053D0_CCE00[];
extern Gfx D_04005480_CCEB0[];
extern Gfx D_04005580_CCFB0[];
extern Gfx D_040056C0_CD0F0[];
extern Gfx D_04005A50_CD480[];
extern Gfx D_04005CA0_CD6D0[];
extern Gfx D_04006040_CDA70[];
extern Gfx D_04006040_CDA70[];
extern Gfx D_04006B00_CE530[];
extern Gfx D_04006B60_CE590[];

// MOUSE/MOUSE2
void func_8031C7A0_72DE50(void) {
    s32 pad[1];
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s16 sp96;
    s16 sp94;
    struct061 sp8C;
    s16 sp8A;
    s16 sp88;
    s16 sp86;

    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t2;
    s16 temp_t3;

    u8 var_v0;
    u8 var_v1;
    u8 tmp;

    if (D_803D5524->unk9C == MOUSE2) {
        func_8037E6DC_78FD8C(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0x1C0, 0xA);
    }
    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            sp86 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }
    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    sp86 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x640, (u8) 7, (s16) 0x3F, (s16) 0x51, (s16) 0x9E, (s8) 1, var_v1 == 0);

done:
    if (sp86 == 0) {
        if (D_803D552C->unk30A != 0) {
            D_803D552C->unk30A = D_803D552C->unk30A - 1;
        } else {
            if (((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED)) && SSSV_RAND(64) == 0) {
                D_803D552C->unk30A = 0xA;
            }
        }
        if (D_803D552C->unk312 != 0) {
            D_803D552C->unk312 = D_803D552C->unk312 - 1;
        } else {
            if (((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED)) && SSSV_RAND(16129) == 0) {
                D_803D552C->unk312 = 0xA;
            }
        }
        func_8038C768_79DE18();
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED) || ((D_803D5538 != 0) && (D_803F2D30.unk4 >= 0x11))) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 4;
            }
        } else {
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 3;
            }
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B975C_6CAE0C(&sp8C, 0x7D, 0);
            func_802C23F8_6D3AA8(0x157);
            func_802C6468_6D7B18(0xBB, 0xDA, 0x177);
            func_8034B3A8_75CA58(0);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A5D20_7B73D0, D_803A5D2C_7B73DC, D_803A5D38_7B73E8, D_803A5D48_7B73F8);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5D20_7B73D0, D_803A5D2C_7B73DC, D_803A5D38_7B73E8, D_803A5D70_7B7420);
                break;
            }
        }
        func_802BB840_6CCEF0(0x3EU);
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || (tmp = D_803F2AA2, tmp == 0) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 > 10))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 17)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((s16) ((s32) (D_803D5524->unkBA * 8) / 5), 2, 3, 3, -0.32f);
            gSPDisplayList(D_801D9E88++, &D_01003548_3CE18);

            func_802C78B0_6D8F60(2U, 0xFU, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005580_CCFB0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(2U, 0x12U, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 1, 0, D_04005580_CCFB0);
            add_hilite();
            func_802C78B0_6D8F60(1U, 2U, (D_803F2EBC * 0xA) >> 6, (D_803F2EC0 * 0xA) >> 6, (D_803F2EC4 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_040056C0_CD0F0);
            if (D_803D552C->unk316 != 0) {
                guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D552C->unk316, 0.0f, 0.0f, 1.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }
            func_8038CCF0_79E3A0(0x2E, 1, 0x14, 0x13, 0x16, 0x17);
            func_802C78B0_6D8F60(1U, 0x14U, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005A50_CD480);
            if (D_803D5524->unk9C == MOUSE) {
                func_802C78B0_6D8F60(19, 22, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, D_803A5E84_7B7534[D_803D552C->unk30A], 0, 0, D_040053D0_CCE00);
                func_802C78B0_6D8F60(19, 23, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, D_803A5E84_7B7534[D_803D552C->unk312], 1, 0, D_040053D0_CCE00);
            }
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp8A, &sp88);
                func_8031A278_72B928(&D_803D552C->unk326, &sp8A, &sp88);
                sp8A = D_803BD530_7CEBE0.eyes[5][sp8A];sp88 = D_803BD600_7CECB0.eyes[4][sp88];
                func_80356BD8_768288(&img_eyes_TLUT1_pal, img_eyes5_ci4__png, sp8A);
                func_802C78B0_6D8F60(1U, 0x14U, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B00_CE530);
                func_80356BD8_768288(&img_eyes_TLUT1_pal, img_eyes5_ci4__png, sp88);
                func_802C78B0_6D8F60(1U, 0x14U, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B60_CE590);
                gDPPipeSync(D_801D9E88++);

            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp86 == 0) || (sp86 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (s16) (D_803D552C->position.yPos.h + ((s32) (D_803D5524->unkBA * 7) >> 3)), D_803D552C->heading, img_D_01033190_6CA60_i4__png, (s16) 7, (s16) 7, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }

    sp96 = D_803D5528->unk3C8.unk2;
    if (sp96 != 0) {
        if ((sp86 == 0) && (D_803F2EDB != 0)) {
            temp_t0 = D_80203FE0[26].unk2;
            temp_t1 = SIN(D_803D552C->heading);
            temp_t2 = COS(D_803D552C->heading);
            temp_t3 = D_80203FE0[26].unk0;
            temp_t4 = (((temp_t0 * temp_t1) / 32) + D_803D5530->position.xPos.w) + ((temp_t2 * temp_t3) / 32);
            temp_t5 = (D_803D5530->position.zPos.w + ((temp_t2 * temp_t0) / 32)) - ((temp_t3 * temp_t1) / 32);
            temp_t6 = ((D_80203FE0[26].unk4 << 0x10) / 32) + D_803D5530->position.yPos.w;
            func_802DE914_6EFFC4(
                sp96,
                temp_t4,
                temp_t5,
                temp_t6,
                D_803D552C->heading);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                if (D_803E00C0[D_803D5528->unk3C8.unk2].tailType == 3) {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3B4C_7B51FC);
                } else {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3BAC_7B525C);
                }
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (sp86 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 0x13, 436, 0);
        func_80303D50_715400(D_803D552C, 1);
    } else {
        func_80303D00_7153B0(D_803D552C, 0xFA, 0x7D);
    }
    if ((D_803D5538 == 0) && (D_803D5524->unk9C == MOUSE2)) {
        if (D_803D552C->unk2EC <= 0) {
            load_animal(MOUSE);
        } else {
            D_803D552C->unk2EC--;
        }
    }
}

#ifdef NON_MATCHING
// RACING_MOUSE
// CURRENT (214)
void func_8031D624_72ECD4(void) {
    s16 spAE;

    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;

    struct061 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp90;

    f32 phi_f0;
    f32 temp_f12;
    s16 phi_a1;
    u8  tmp;
    s16 pad[6];

    if (D_803D552C->unk366 == MOVEMENT_MODE_NORMAL) {
        if (D_803D554C != 0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CD70_73E420(
                    D_803D5530,
                    SFX_UNKNOWN_100,
                    (((D_803D554C / 60.0) + 0.7) * 14848.0), // D_803BD9B8_7CF068
                    0,
                    (f32) ((D_803D554C / 30.0) + 1.0),
                    D_803D5530->position.xPos.h,
                    D_803D5530->position.zPos.h,
                    D_803D5530->position.yPos.h);
            }
        }
    }

    if ((sp92 != 4) && (sp92 != 1) && (D_803D5530->unk162 == 1)) {
        temp_f12 = sqrtf(SQ((f32)D_803D552C->xVelocity.w) + SQ((f32)D_803D552C->zVelocity.w)) / (D_803D5524->unkA4 << 0xA);
        if (temp_f12 < 0.2) { // D_803BD9C0_7CF070
            phi_f0 = 0.0f;
        } else if (0.6 < temp_f12) { // D_803BD9C8_7CF078
            phi_f0 = 1.0f;
        } else {
            phi_f0 = (temp_f12 - 0.2) * 2.5; // D_803BD9C0_7CF070
        }
        if (phi_f0 > 0.0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CED0_73E580(
                    D_803D5530,
                    SFX_UNKNOWN_13,
                    (12288.0f * phi_f0) * 0.5,
                    2.0 * temp_f12,
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
    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            (SSSV_RAND(2) + 25),
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625), // 1024 / 625
            (SSSV_RAND(FTOFIX32(0.5)) << 1) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 0xA,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(16) + 0xF);

        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp92 = 0;
        D_803F2EDD = 0;
    } else {
        sp92 = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x640,
            7,
            0x3F,
            0x51,
            0x9E,
            1,
            CHECK_SEGMENT == 0);
    }

    if (sp92 == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 4;
            }
        } else if ((D_803D5538 != 0) && (D_803F2D30.unk4 > 16)) {
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 4;
            }
        } else {
            if (D_803D5528->unk3C8.unk2 != 0) {
                D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 3;
            }
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            if (D_803D5538 != 0) {
                sp90 = ((D_803D554C * 0x9C) >> 1) / 20;
            } else {
                sp90 = 0;
            }
            func_802B9130_6CA7E0(&sp98, 0x7D, 0x46, 0xEA, 0);
            func_802C1830_6D2EE0(0x9C, &sp98);
            func_802B964C_6CACFC();
            D_80203FE0[7].unk4  += sp90;
            D_80203FE0[10].unk4 += sp90;
            D_80203FE0[8].unk4  += sp90;
            D_80203FE0[11].unk4 += sp90;
            D_80203FE0[1].unk4  += sp90;
            D_80203FE0[0].unk4  += sp90 >> 1;
            func_802C6468_6D7B18(0xBB, 0xDA, 0x177);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {                      /* irregular */
            case 1:
                func_802DB670_6ECD20(D_803A5D98_7B7448, D_803A5DAC_7B745C, D_803A5DC0_7B7470, D_803A5DE4_7B7494);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5D98_7B7448, D_803A5DAC_7B745C, D_803A5DC0_7B7470, D_803A5E34_7B74E4);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || (tmp = D_803F2AA2, tmp == 0) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 > 10))) &&
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

            func_8038C230_79D8E0(((D_803D5524->unkBA * 8) / 5), 2, 3, 3, -0.32f); // D_803BD9D0_7CF080
            func_802C78B0_6D8F60(2, 1, D_803F2EBC * 0xA >> 6, D_803F2EC0 * 0xA >> 6, D_803F2EC4 * 0xA >> 6, D_803F2ED0, 0, 0, 0, D_04006040_CDA70);
            D_80203FE0[1].unk2  += 0x3E;
            D_80203FE0[19].unk2 += 0x3E;
            D_80203FE0[20].unk2 += 0x3E;
            D_80203FE0[22].unk2 += 0x3E;
            D_80203FE0[23].unk2 += 0x3E;
            func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005A50_CD480);
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); }
#pragma _permuter sameline end
            func_802C78B0_6D8F60(10, 11, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0);
            func_802C78B0_6D8F60(13, 14, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0);
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(16, 17, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); }
#pragma _permuter sameline end
            func_802C78B0_6D8F60(19, 22, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_040053D0_CCE00);
            func_802C78B0_6D8F60(19, 23, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 1, 0, D_040053D0_CCE00);

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp96, &sp94);
                func_8031A278_72B928(&D_803D552C->unk326, &sp96, &sp94);
#pragma _permuter sameline start
                sp96 = D_803BD530_7CEBE0.eyes[5][sp96]; sp94 = D_803BD600_7CECB0.eyes[4][sp94];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, sp96);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B00_CE530);

                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, sp94);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B60_CE590);
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
            D_803D552C->position.yPos.h + ((D_803D5524->unkBA * 7) >> 3),
            D_803D552C->heading,
            img_D_01033190_6CA60_i4__png,
            7,
            7,
            0x9B,
            0,
            0,
            0,
            0,
            D_803D5538);
    }

    spAE = D_803D5528->unk3C8.unk2;
    if (spAE != 0) {
        if ((sp92 == 0) && (D_803F2EDB != 0)) {

            temp_t4 = D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * (D_80203FE0[2].unk0)) / 32) + ((SIN(D_803D552C->heading) * (D_80203FE0[2].unk2)) / 32);
            temp_t5 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * (D_80203FE0[2].unk2)) / 32) - ((SIN(D_803D552C->heading) * (D_80203FE0[2].unk0)) / 32);
            temp_t6 = D_803D5530->position.yPos.w + ((D_80203FE0[2].unk4 << 0x10) / 32);
            func_802DE914_6EFFC4(
                spAE,
                temp_t4,
                temp_t5,
                temp_t6,
                D_803D552C->heading);
            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                if (D_803E00C0[D_803D5528->unk3C8.unk2].tailType == 3) {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, D_803A3B4C_7B51FC);
                } else {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, D_803A3BAC_7B525C);
                }
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (sp92 == 0) {
        func_803034D0_714B80(D_803D552C, 0xFA, 0x75, 1);
        func_80303820_714ED0(D_803D552C, 0x13, 0x14, 0x9C, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x177, 0x7D);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031D624_72ECD4.s")
#endif

// HARD_MOUSE
void func_8031E6A0_72FD50(void) {
    s16 spC6;
    u8 tmp;
    s32 temp_t4; // spC0 ?
    s32 temp_t5; // spBC ?
    s32 temp_t6; // spB8 ?
    struct061 spB0;
    s16 spAE;
    s16 spAC;
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 phi_t6;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spA6 = 0;
        D_803F2EDD = 0;
    } else {
        spA6 = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x640,
            7,
            0x3F,
            0x51,
            0x9E,
            1,
            CHECK_SEGMENT == 0);
    }

    if (spA6 == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if (D_803D5528->unk3C8.unk2 != 0) {
            D_803E00C0[D_803D5528->unk3C8.unk2].tailType = 5;
        }
        if ((D_803D552C->unk365 == ATTACK_NONE) && (SSSV_RAND(32) == 0xC)) {
            D_803D552C->unk365 = ATTACK_MOUSE_3;
            D_803D552C->unk32A = D_803D5544;
        }
        func_803224C4_733B74(5, 5, 0, 0x10, 0, 0, 0, 0x10);

        spAA = 128;
        switch (D_803D552C->unk365) {                        /* irregular */
        case ATTACK_MOUSE_TAIL:
            spA8 = D_803D5544 - D_803D552C->unk32A;
            spAA = spA8 * 21;
            if (spA8 >= 6) {
                D_803D552C->unk365 = ATTACK_MOUSE_3;
                D_803D552C->unk32A = D_803D5544;
            }
            break;
        case ATTACK_MOUSE_2:
            spA8 = D_803D5544 - D_803D552C->unk32A;
            spAA = 128 - (spA8 * 21);
            if (spA8 >= 6) {
                D_803D552C->unk365 = ATTACK_NONE;
                load_animal(RACING_MOUSE);
            }
            break;
        // is this mouse radar?
        case 46:
            spA8 = D_803D5544 - D_803D552C->unk32A;
            if (spA8 == 1) {
                play_sound_effect_at_location(SFX_CHEAT_ENABLED, 0x2400, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            }
            if (spA8 < 7) {
                if (spA8 < 4) {
                    phi_t6 = spA8 << 3;
                } else {
                    phi_t6 = (7 - spA8) << 3;
                }
                create_particle_effect(
                    D_803D5530->position.xPos.h + (((SIN(D_803D552C->heading) >> 7) * 3) >> 5),
                    D_803D5530->position.zPos.h + (((COS(D_803D552C->heading) >> 7) * 3) >> 5),
                    D_803D5530->position.yPos.h + 0xA,
                    0x58,
                    D_803D5530->xVelocity.w,
                    D_803D5530->zVelocity.w,
                    D_803D5530->yVelocity.w,
                    phi_t6,
                    GPACK_RGBA5551(248, 248, 0, 1),   // yellow
                    GPACK_RGBA5551(248, 248, 128, 1), // pale yellow
                    0);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spB0, 0x7D, 0x46, 0xEA, 0);
            func_802C1830_6D2EE0(0x9C, &spB0);
            func_802B964C_6CACFC();
            func_802C6468_6D7B18(0xBB, 0xDA, 0x177);
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || (tmp = D_803F2AA2, tmp == 0) || (tmp == 2) || ((tmp == 1) && (D_803F2AA3 > 10))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 17)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                D_803D5530->position.xPos.w,
                D_803D5530->position.zPos.w,
                D_803D5530->position.yPos.w,
                (spAA - D_803D552C->heading) & 0xFF,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.32f);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0xA) >> 6, (D_803F2EC0 * 0xA) >> 6, (D_803F2EC4 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006040_CDA70);
            D_80203FE0[1].unk2  += 0x3E;
            D_80203FE0[19].unk2 += 0x3E;
            D_80203FE0[20].unk2 += 0x3E;
            D_80203FE0[22].unk2 += 0x3E;
            D_80203FE0[23].unk2 += 0x3E;
            func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005A50_CD480); // mouse head

            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); } // racing mouse wheel
            func_802C78B0_6D8F60(10, 11, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); // racing mouse wheel
            func_802C78B0_6D8F60(13, 14, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); // racing mouse wheel
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(16, 17, FTOFIX32(0.15625), FTOFIX32(0.15625), FTOFIX32(0.15625), D_803F2ED0, 0, 0, 0, D_04005CA0_CD6D0); } // racing mouse wheel
            func_802C78B0_6D8F60(19, 22, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_040053D0_CCE00); // mouse ear
            func_802C78B0_6D8F60(19, 23, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 1, 0, D_040053D0_CCE00); // mouse ear

            if (D_803F2EDD == 0) {
                spAE = D_803BD530_7CEBE0.eyes[5][2]; spAC = D_803BD600_7CECB0.eyes[4][2];
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spAE);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B00_CE530);
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spAC);
                func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04006B60_CE590);
            }

            guLookAtReflect(
                &D_80204278->unk38CD0[D_80204278->unk39310],
                &D_80204278->unk38A50[D_80204278->unk39310],
                D_803F2C44,
                D_803F2C48,
                D_803F2C4C,
                (f32) D_803D5530->position.xPos.w / 65536.0,
                (f32) D_803D5530->position.zPos.w / 65536.0,
                (f32) D_803D5530->position.yPos.w / 65536.0,
                D_80204200,
                D_80204204,
                D_80204208);

            gDPSetTextureLUT(D_801D9E88++, G_TT_NONE);
            gSPLookAtX(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[0]);
            gSPLookAtY(D_801D9E88++, &D_80204278->unk38A50[D_80204278->unk39310].l[1]);
            gDPPipeSync(D_801D9E88++);
            D_80204278->unk39310++;

            gSPDisplayList(D_801D9E88++, D_01004270_3DB40);
            gSPDisplayList(D_801D9E88++, D_01004AF8_3E3C8);
            gDPSetRenderMode(D_801D9E88++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);
            gDPSetTextureImage(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img_silver_rgba16__png);
            gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPLoadSync(D_801D9E88++);
            gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1023, 256);
            gDPPipeSync(D_801D9E88++);
            gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

            func_802C78B0_6D8F60(2, 1, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, (D_803F2EC8 * 0xA) >> 6, D_803F2ED0, 0, 0, 0, D_04005480_CCEB0); // mouse tail
            gSPDisplayList(D_801D9E88++, D_01003460_3CD30);
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA6 == 0) || (spA6 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + ((D_803D5524->unkBA * 7) >> 3)), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 7, 7, 0x9B, 0, 0, 0, 0, D_803D5538);
    }

    spC6 = D_803D5528->unk3C8.unk2;
    if (spC6 != 0) {
        if ((spA6 == 0) && (D_803F2EDB != 0)) {

            temp_t4 = D_803D5530->position.xPos.w + ((COS(D_803D552C->heading) * (-D_80203FE0[2].unk0)) / 32) + ((SIN(D_803D552C->heading) * (-D_80203FE0[2].unk2)) / 32);
            temp_t5 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * (-D_80203FE0[2].unk2)) / 32) - ((SIN(D_803D552C->heading) * (-D_80203FE0[2].unk0)) / 32);
            temp_t6 = D_803D5530->position.yPos.w + ((D_80203FE0[2].unk4 << 0x10) / 32);
            func_802DE914_6EFFC4(
                spC6,
                temp_t4,
                temp_t5,
                temp_t6,
                D_803D552C->heading);

            if (D_803E00C0[D_803D5528->unk3C8.unk2].unk34 == 1) {
                if (D_803E00C0[D_803D5528->unk3C8.unk2].tailType == 3) {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3B4C_7B51FC);
                } else {
                    func_802DD244_6EE8F4(D_803D5528->unk3C8.unk2, &D_803A3BAC_7B525C);
                }
            }
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 0;
        } else {
            D_803E00C0[D_803D5528->unk3C8.unk2].unk34 = 1;
        }
    }
    if (spA6 == 0) {
        func_803034D0_714B80(D_803D552C, 250, 117, 1);
        func_80303820_714ED0(D_803D552C, 19, 20, 156, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 375, 125);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            if (D_803D552C->unk365 != ATTACK_MOUSE_2) {
                if (D_803D552C->unk365 != ATTACK_MOUSE_TAIL) {
                    D_803D552C->unk32A = D_803D5544;
                }
                D_803D552C->unk365 = ATTACK_MOUSE_2;
            }
        } else {
            D_803D552C->unk2EC--;
        }
    }
    if ((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED)) {
        load_animal(RACING_MOUSE);
    }
}

// HELI_MOUSE
void func_8031F858_730F08(void) {
    osSyncPrintf("Helimouse is gone\n");
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
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 10,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(16) + 0xF);
    } else {
        set_target_speed(16); // speed
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
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
        if ((D_803D5544 - D_803D552C->unk32A) >= 8) {
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
