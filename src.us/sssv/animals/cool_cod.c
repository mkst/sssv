#include <ultra64.h>
#include "common.h"

u8 D_803B58A0_7C6F50[4] = { 0, 1, 2, 0 };
u8 D_803B58A4_7C6F54[4] = { 1, 2, 3, 0 };
s16 D_803B58A8_7C6F58[4] = { 500, 500, 500, 0 };
s16 D_803B58B0_7C6F60[10] = { 0, 360, 310,  90,  254, 90, 176, 78, 112, 0 };
s16 D_803B58C4_7C6F74[10] = { 0, 640, 1310, 130, 180, 90, 180, 48, 180, 0 };

#ifdef NON_MATCHING
// CURRENT (92)
void func_80382CF0_7943A0(void) {
    s32 pad3[2];
    f32 temp_f2;

    s16 sp8A;
    s16 pad; // pad88
    s16 sp86;
    s16 sp84;

    s16 sp6C;
    s16 sp68;

    s16 pad2[2];

    if (D_803D5538 != 0) {
        if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) > 10) {
            if ((D_803D5530->position.yPos.h + 0x60) < (sample_ground_height_at_xz(
                D_803D5530->position.xPos.h + ((D_803D5530->xVelocity.h * 3) >> 1),
                D_803D5530->position.zPos.h + ((D_803D5530->zVelocity.h * 3) >> 1)) >> 16)) {
                D_803D5530->xVelocity.h = -D_803D5530->xVelocity.h >> 1;
                D_803D5530->zVelocity.h = -D_803D5530->zVelocity.h >> 1;
                do_rumble(0, 0xD, 0x19, 5, 0);
            }
        }
    }
    if (D_803D553A == 8) {
        play_sound_effect_at_location(SFX_UNKNOWN_9, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
    if (D_803D553A == 9) {
        play_sound_effect_at_location(SFX_UNKNOWN_10, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
    if ((D_803D5530->movementState == 3) && (D_803D5538 != 0)) {
        if (D_803D552C->unk369 == 0) {
            if (gAnimalState.curBButton == 0) {
                D_803D552C->unk369 = 1;
            }
        } else if ((D_803D552C->unk369 == 1) && (gAnimalState.curBButton != 0) && (D_803D5530->yVelocity.h < 5)) {
            D_803D552C->unk369 = 2;
            D_803D5530->xVelocity.w += SIN(D_803D552C->heading) * 19;
            D_803D5530->zVelocity.w += COS(D_803D552C->heading) * 19;
            temp_f2 = sqrtf((D_803D5530->xVelocity.w / 65536.0) * (D_803D5530->xVelocity.w / 65536.0) + (D_803D5530->zVelocity.w / 65536.0) * (D_803D5530->zVelocity.w / 65536.0));
            if (temp_f2 > 20.0) {
                D_803D5530->xVelocity.w = (D_803D5530->xVelocity.w * 20.0) / temp_f2;
                D_803D5530->zVelocity.w = (D_803D5530->zVelocity.w * 20.0) / temp_f2;
            }
            D_803D5530->yVelocity.h = MAX(7, D_803D5530->yVelocity.h + 4);
            D_803D552C->unk308 = MAX(0, D_803D552C->unk308 - 25);

            play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp8A = VISIBILITY_VISIBLE;
        gLodDetailState = 0;
    } else {
        sp8A = classify_object_visibility_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x800,
            0,
            60,
            60,
            120,
            1,
            CHECK_SEGMENT == 0);
    }

    if (sp8A == VISIBILITY_VISIBLE) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_80302E50_714500(500, 500, 500);
            if (D_803D5530->state == 0x3F) {
                sp68 = 40 - (MIN(40, D_803D552C->unk308++) * 2);
                func_8030322C_7148DC(0, -sp68);
                func_8030322C_7148DC(1, -sp68);
                func_8030322C_7148DC(2, -sp68);
                func_8030322C_7148DC(3, -sp68);
            }
        }
        if (D_803F2ECC != 0) {

            backup_joint_positions();
            switch (D_803F2ECE) {
                case 1:
                    func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, D_803B58A8_7C6F58, D_803B58B0_7C6F60);
                    break;
                case 2:
                    func_802DB670_6ECD20(D_803B58A0_7C6F50, D_803B58A4_7C6F54, D_803B58A8_7C6F58, D_803B58C4_7C6F74);
                    break;
            }
        }
        func_8038064C_791CFC();
        if ((((gDisplayListContext->usedModelViewMtxs + 30) < 250)) &&
            (D_803F2EDA != 0) &&
            (((D_803D5538 != 0)) || (gCameraUiState == 0) || (gCameraUiState == 2) || ((gCameraUiState == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(
                &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs],
                D_803D5530->position.xPos.w,
                D_803D5530->position.zPos.w,
                D_803D5530->position.yPos.w,
                -D_803D552C->heading,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);

            gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            load_1_tile(img_cool_cod_pal, img_cool_cod_ci4__png);
            func_802C78B0_6D8F60(0, 1, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007500_E4AC0);
            func_802C78B0_6D8F60(1, 2, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_040077E0_E4DA0);
            func_802C78B0_6D8F60(2, 3, FTOFIX32(1.0), FTOFIX32(1.0), FTOFIX32(1.0), D_803F2ED0, 0, 0, 0, D_04007AE0_E50A0);
            if (gLodDetailState == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, (u16*)&sp86, (u16*)&sp84);
                func_8031A278_72B928(&D_803D552C->unk326, (u16*)&sp86, (u16*)&sp84);
#pragma _permuter sameline start
                sp86 = D_803BD530_7CEBE0.eyes[1][sp86];sp84 = D_803BD600_7CECB0.eyes[0][sp84];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT4_pal, (u8 (*)[128])img_eyes_ci4__png, sp86);
                func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E70_E5430);
                func_80356BD8_768288(img_eyes_TLUT4_pal, (u8 (*)[128])img_eyes_ci4__png, sp84);
                func_802C78B0_6D8F60(1, 0, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, (D_803F2EC8 << 6) >> 6, D_803F2ED0, 0, 0, 0, D_04007E90_E5450);
            }
            gSPPopMatrix(gOpaqueDL++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp8A == VISIBILITY_VISIBLE) || (sp8A == VISIBILITY_OUT_OF_BOUNDS_X)) {
        func_8034BD20_75D3D0(
            D_803D552C->position.xPos.h,
            D_803D552C->position.zPos.h,
            (D_803D552C->position.yPos.h + D_803D5524->unkBA),
            D_803D552C->heading,
            img_D_01033190_6CA60_i4__png,
            21,
            9,
            155,
            0, // r
            0, // g
            0, // b
            0,
            D_803D5538);
    }
    func_80303D00_7153B0(D_803D552C, 500, 500);

    if (0) {
        if (sp84 == 1 ? sp84 == 2 ? sp84 == 3 ? sp84 == 4 ? 1 : 2 : 3 : 4 : 5);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/cool_cod/func_80382CF0_7943A0.s")
#endif

void func_80383804_794EB4(void) {
}

void func_8038380C_794EBC(s32 arg0, s32 arg1, s32 arg2) {
}

void func_8038381C_794ECC(void) {
}
