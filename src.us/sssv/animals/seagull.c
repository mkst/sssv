#include <ultra64.h>
#include "common.h"

extern s16 D_803B5770_7C6E20[];
extern s16 D_803B5784_7C6E34[];
extern s16 D_803B5798_7C6E48[];
extern s16 D_803B57BC_7C6E6C[];
extern s16 D_803B580C_7C6EBC[];

extern Gfx D_04001D70_DF330[];
extern Gfx D_04001F80_DF540[];
extern Gfx D_04002090_DF650[];
extern Gfx D_040021C0_DF780[];
extern Gfx D_04002320_DF8E0[];
extern Gfx D_04002410_DF9D0[];
extern Gfx D_040024F0_DFAB0[];
extern Gfx D_04002510_DFAD0[];
extern Gfx D_040025D0_DFB90[];


void func_80380920_791FD0(void) {
    s32 sp94;
    s32 var_t0;
    s16 temp_a3;
    s16 unused;
    s16 var_a0; // er?
    u8 temp_v0_10;
    s16 sp86;
    s16 sp84;
    s16 sp82;

    s16 temp_a2;
    s16 temp_a1;
    s16 var_a0_2;
    s16 var_v0;

    if (D_803D553A == 4) {
        if (D_803D5524->unk9C == SEAGULL2) {
            play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.4f);
        } else {
            play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp82 = 0;
        D_803F2EDD = 0;
    } else {
        sp82 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0xA00, 0, 20, 20, 20, 1, CHECK_SEGMENT == 0);
    }

    if (sp82 == 0) {
        func_8038C98C_79E03C();
        func_8035D120_76E7D0();
        if ((D_803D5524->unk9C == SEAGULL2) && (((D_803D552C->unk320 == NULL)) ||
            ((D_803D552C->unk320 != NULL) && (D_803D552C->unk320->unk26C != 0)))) {
            play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.1892f);
            D_803D552C->unk320 = NULL;
            D_803D552C->position.yPos.h += D_803D552C->unk308;
            D_803D552C->newPosition.yPos.h += D_803D552C->unk308;
            load_animal(SEAGULL);
        }

        switch (D_803D552C->unk365) {
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_BITE: // 18
            if ((D_803D5544 - D_803D552C->unk32A) >= 9) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_NONE: // 0
            break;
        }

        func_8035DA60_76F110();
        func_8034B64C_75CCFC(15, 25, 10);
        func_8035D734_76EDE4();

        if (D_803D5528->unk3C0.unk4 == 12) {
            sp94 = FTOFIX32(1.0) - ((D_803D5528->unk3C0.unk6 << 0x10) / 20);
        } else {
            sp94 = FTOFIX32(1.0);
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802BAD60_6CC410(0x138, 0x32C);
            func_802C5F34_6D75E4(0x232, 0x177, 1);
            func_802BB1F0_6CC8A0(0x465, 0x7D);
            func_802BC1F4_6CD8A4(0x2EE);
            func_802C44E8_6D5B98(0x32C, 0xFA, 0x138, 0x138);
            func_8038CCF0_79E3A0(0x5D, 0x13, 0x14, -1, -1, -1);
            func_8038CCF0_79E3A0(-0x5E, 0x1A, -1, -1, -1, -1);

            var_a0_2 = D_80203FE0[20].unk0 - D_80203FE0[19].unk0;
            temp_a2 = D_80203FE0[20].unk2 - D_80203FE0[19].unk2;

            temp_a1 = (((var_a0_2 * D_80152350.unk384[D_803D552C->unk316]) >> 8) + ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a2) >> 8));
            temp_a3 = (((temp_a2 * D_80152350.unk384[D_803D552C->unk316]) >> 8) - ((D_80152350.unk2D0[D_803D552C->unk316] * var_a0_2) >> 8));
            D_80203FE0[20].unk0 = D_80203FE0[19].unk0 + temp_a1;
            D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + temp_a3;
        }

        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B5770_7C6E20, D_803B5784_7C6E34, D_803B5798_7C6E48, D_803B57BC_7C6E6C);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B5770_7C6E20, D_803B5784_7C6E34, D_803B5798_7C6E48, D_803B580C_7C6EBC);
                break;
            }
        }
        func_8038064C_791CFC();
        if (D_803D5524->unk9C == SEAGULL2) {
            D_80203FE0[0].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[1].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[2].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[19].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[20].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[26].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[27].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[22].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[24].unk4 += D_803D552C->unk308 << 5;

            D_80203FE0[3].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[4].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[7].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[8].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[9].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[13].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[10].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[11].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[12].unk4 += D_803D552C->unk308 << 5;
            D_80203FE0[14].unk4 += D_803D552C->unk308 << 5;

            D_80203FE0[3].unk4 -= 304;
            D_80203FE0[7].unk4 -= 304;
            D_80203FE0[8].unk4 -= 304;
            D_80203FE0[9].unk4 -= 304;
            D_80203FE0[13].unk4 -= 304;
            D_80203FE0[4].unk4 -= 304;
            D_80203FE0[10].unk4 -= 304;
            D_80203FE0[11].unk4 -= 304;
            D_80203FE0[12].unk4 -= 304;
            D_80203FE0[14].unk4 -= 304;
        }

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) &&
            ((D_803D5538 != 0) || (temp_v0_10 = D_803F2AA2, (temp_v0_10 == 0)) || (temp_v0_10 == 2) || ((temp_v0_10 == 1) && (D_803F2AA3 >= 0xB))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading,
                D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if (D_803D5524->unk9C == SEAGULL) {
                func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.25f);
            } else {
                func_8038C230_79D8E0((D_803D5524->unkBA * 16) / 5, 2, 3, 3, 0.1f);
            }

            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x50) >> 6, (D_803F2EC0 * 0x50) >> 6, (D_803F2EC4 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04001D70_DF330);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x7D, 0x33, 0xFF, 0xFF);

#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04001F80_DF540); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 26, 0x14000, 0x14000, 0x14000, D_803F2ED0, 0, 0, 0, D_040021C0_DF780); }
#pragma _permuter sameline end

            if (sp94 != 0) {
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0, 0x16, (sp94 * 0x50) >> 6, (sp94 * 0x50) >> 6, (sp94 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002320_DF8E0); }
#pragma _permuter sameline end
                func_802C78B0_6D8F60(0, 0x18, (sp94 * 0x50) >> 6, (sp94 * 0x50) >> 6, (sp94 * 0x50) >> 6, D_803F2ED0, 0, 1, 0, D_04002320_DF8E0);
            }
            if (D_803D5524->unk9C == SEAGULL2) {
                var_t0 = FTOFIX32(2.0);
            } else {
                var_t0 = FTOFIX32(1.0);
            }

            var_a0 = 0;
            if (D_803D552C->unk365 == ATTACK_BITE) {

                switch (D_803D5544 - D_803D552C->unk32A) {
                case 1:
                case 5:
                    var_t0 = FTOFIX32(2.0);
                    var_a0 = 468;
                    break;
                case 2:
                case 4:
                    var_t0 = FTOFIX32(2.5);
                    var_a0 = 781;
                    break;
                case 3:
                    var_t0 = FTOFIX32(3.0);
                    var_a0 = 937;
                    break;
                }
            }
            D_80203FE0[3].unk4 -= var_a0;
            D_80203FE0[7].unk4 -= var_a0;
            D_80203FE0[8].unk4 -= var_a0;
            D_80203FE0[9].unk4 -= var_a0;
            D_80203FE0[13].unk4 -= var_a0;
            D_80203FE0[4].unk4 -= var_a0;
            D_80203FE0[10].unk4 -= var_a0;
            D_80203FE0[11].unk4 -= var_a0;
            D_80203FE0[12].unk4 -= var_a0;
            D_80203FE0[14].unk4 -= var_a0;

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 0xD, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_040025D0_DFB90); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0); }
#pragma _permuter sameline end

            func_802C78B0_6D8F60(3, 8, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0);

#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 9, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xE, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_040025D0_DFB90); }
#pragma _permuter sameline end
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0); }
#pragma _permuter sameline end
            func_802C78B0_6D8F60(4, 0xB, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0);
#pragma _permuter sameline start
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xC, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, (var_t0 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002410_DF9D0); }
#pragma _permuter sameline end

            if (D_803D5524->unk9C == SEAGULL) {
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 5, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04002090_DF650); }
#pragma _permuter sameline end
#pragma _permuter sameline start
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 27, FTOFIX32(1.25), FTOFIX32(1.25), FTOFIX32(1.25), D_803F2ED0, 0, 0, 0, D_04002090_DF650); }
#pragma _permuter sameline end
            }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp86, &sp84);
                func_8031A278_72B928(&D_803D552C->unk326, &sp86, &sp84);
#pragma _permuter sameline start
                sp86 = D_803BD530_7CEBE0.eyes[1][sp86]; sp84 = D_803BD600_7CECB0.eyes[0][sp84];
#pragma _permuter sameline end
                func_80356BD8_768288(&img_eyes_TLUT1_pal, img_eyes_ci4__png, sp86);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_040024F0_DFAB0);
                func_80356BD8_768288(&img_eyes_TLUT1_pal, img_eyes_ci4__png, sp84);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, (D_803F2EC8 * 0x50) >> 6, D_803F2ED0, 0, 0, 0, D_04002510_DFAD0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if (D_803D552C->unk320 != NULL) {
        func_80321B70_733220(0, 0, 0);
        D_803D552C->unk320->unk68 = D_803D5530->unk68;
        D_803D552C->unk320->unk70 = D_803D5530;
    }
    func_8034BD20_75D3D0(
        D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1),
        D_803D552C->heading, img_D_01033190_6CA60_i4__png, 18, 18, 0x9B, 0, 0, 0, 0, D_803D5538);
    if (sp82 == 0) {
        func_80303820_714ED0(D_803D552C, 0, 1, 0x3A9, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x119, 0);

        if (D_803D552C->unk320 != NULL) {
            func_80303C44_7152F4(D_803D552C, 2, 0, -D_803D552C->unk308 / 64);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303D50_715400(D_803D552C, 2);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 937, 0);
    }
    if ((D_803D5524->unk9C == SEAGULL2) && ((D_803D552C->unk366 == MOVEMENT_MODE_2) || (D_803D552C->unk366 == MOVEMENT_MODE_DEACTIVATED))) {
        load_animal(SEAGULL);
    }
}

void func_80381C60_793310(void) {
    if (D_803D552C->unk320 == NULL) {
        D_803D552C->unk320 = try_pickup_animal();
        if (D_803D552C->unk320 != 0) {
            D_803D552C->unk308 = (u16) D_803D552C->unk320->unk42;
            load_animal(SEAGULL2);
            D_803D552C->position.yPos.h -= D_803D552C->unk308;
            if (D_803D5530->unk160 == 2) {
                D_803D552C->position.yPos.h = MAX(D_803D552C->position.yPos.h, func_80310F58_722608(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h) >> 16);
            } else {
                D_803D552C->position.yPos.h = MAX(D_803D552C->position.yPos.h, func_8031124C_7228FC(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h) >> 16);
            }
        }
        if (D_803D5530->unk162 == 2) {
            if (D_803D5528->energy[1].unk0 > 400) {
                D_803D5528->energy[1].unk0 -= 400;
                if (func_803224C4_733B74(-58, 0, 0, 29, 20, 0, 0, 11) != 0) {
                    play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    D_803D5530->yVelocity.h += 2;
                } else {
                    play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
                if (D_803D552C->unk365 == ATTACK_NONE) {
                    D_803D552C->unk365 = ATTACK_BITE;
                    D_803D552C->unk32A = D_803D5544;
                }
            }
        }
    } else {
        func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        play_sound_effect_at_location(SFX_BIRD_HURT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.1892f);
        D_803D552C->position.yPos.h += D_803D552C->unk308;
        D_803D552C->newPosition.yPos.h += D_803D552C->unk308;
        load_animal(SEAGULL);
    }
}

void func_80381F14_7935C4(void) {
    // check object is an animal?
    if ((D_803D5530->unk162 == 2) || ((D_803D5530->unk6C != 0) && (D_803D5530->unk6C->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET))) {
        if (func_803224C4_733B74(-78, 0, 0, 58, 20, 0, 0, 19) != 0) {
            play_sound_effect_at_location(SFX_BIRD_CLAW_ATTACK, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            D_803D5530->yVelocity.h += 2;
        } else {
            play_sound_effect_at_location(SFX_UNKNOWN_79, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
        if (D_803D552C->unk365 == ATTACK_NONE) {
            D_803D552C->unk365 = ATTACK_BITE;
            D_803D552C->unk32A = D_803D5544;
        }
    }
}
