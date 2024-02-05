#include <ultra64.h>
#include "common.h"

#include "fox.h"

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

extern Gfx D_04004090_CBAC0[];
extern Gfx D_04004200_CBC30[];
extern Gfx D_04004330_CBD60[];
extern Gfx D_04004590_CBFC0[];
extern Gfx D_040046D0_CC100[];
extern Gfx D_040046F0_CC120[];
extern Gfx D_04004A20_CC450[];
extern Gfx D_04004D10_CC740[];
extern Gfx D_04005030_CCA60[];
extern u8  D_040050D0_CCB00[];
extern u8  D_040052D0_CCD00[];

// FOX
#ifdef NON_MATCHING
// CURRENT (391)
void func_802E5000_6F66B0(void) {
    u8 temp_v0;
    u16 ticks_remaining;
    s16 temp_v0_6;

    struct061 spC8;
    s16 spC6;
    s16 spC2;

    s16 spBC;
    s16 spBA;
    s16 spB8;

    s16 spB6;
    s16 spB4;
    s16 spB2;

    s16 var_s0;

    s16 spAE;
    s16 spAC;
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 spA4;
    s16 spA2;

    s32 sp68;
    s32 sp70;


    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spC6 = 0;
        D_803F2EDD = 0;
    } else {
        spC6 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0xCB0, 3, 0x9E, 0x14, 0, 1, CHECK_SEGMENT == 0);
    }

    if (spC6 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035D734_76EDE4();

        spA8 = 0;
        spAA = 0;
        switch (D_803D552C->unk365) {

        case ATTACK_FOX_TAIL:
#pragma _permuter sameline start
            // same line for regalloc
            if ((D_803D5530->unk4A != 0) && (D_803F2D10.unk0 == 0)) {D_803D552C->unk32A++;}
#pragma _permuter sameline end
            D_803D5528->unk3C0.unk0 = 0xF;
            D_803D5528->unk3C0.unk2 = 0;

            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 9) {
                spAA = ticks_remaining * 16;
            } else {
                spA8 = -(SIN((ticks_remaining - 8) << 5) >> 7) >> 3;
                spAA = ((SIN((ticks_remaining - 8) << 5) >> 7) >> 4) + 128;
                if (ticks_remaining >= 0xE) {
                    D_803D552C->unk32A += 8;
                }
                if ((ticks_remaining == 0xA) && (D_803D5530->unk4A == 0)) {
                    if (func_803224C4_733B74(0xF, 0x2A, 0, 0x17, 9, 0, 0, 3) != 0) {
                        play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_59, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                }
            }
            break;
        case ATTACK_FOX_3:
            if (D_803D5530->unk4A != 0) {
                D_803D552C->unk32A++;
            }
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 9) {
                spAA = 128 - (ticks_remaining * 16);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_FOX_DASH:
            if (D_803D5530->unk4A != 0) {
                D_803D552C->unk32A++;
            }

            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 9) {
                temp_v0_6 = 32 - (ticks_remaining * 2);
                D_803F2EB4 = (temp_v0_6 * D_803F2EB4) >> 5;
                D_803F2EB0 = ((64 - temp_v0_6) * D_803F2EB0) >> 5;
                D_803F2EB8 = ((64 - temp_v0_6) * D_803F2EB8) >> 5;
                if (ticks_remaining == 8) {

                    if (D_803D5530->unk4A == 0) {
                        spBC = D_803D5530->position.xPos.h;
                        spBA = D_803D5530->position.zPos.h;
                        spB8 = D_803D5530->position.yPos.h;

                        spC2 = func_8037F07C_79072C(0x180, D_803D552C->heading);
                        play_sound_effect_at_location(SFX_FOX_DASH, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

                        if (spC2 >= 0x11) {
                            temp_v0_6 = spC2 >> 4;

                            spB6 = (D_803D5530->position.xPos.h - spBC) / temp_v0_6;
                            spB4 = (D_803D5530->position.zPos.h - spBA) / temp_v0_6;
                            spB2 = (D_803D5530->position.yPos.h - spB8) / temp_v0_6;

                            var_s0 = temp_v0_6 - 1; // need to force regswap
                            for (; var_s0 > 0; var_s0--) {
                                if (spB2 >= (func_8031124C_7228FC(spB6, spB4) >> 0x10)) {
                                    spB2 = (func_8031124C_7228FC(spB6, spB4) >> 0x10);
                                }

                                sp70 = spBC + (var_s0 * spB6);
                                sp68 = spBA + (var_s0 * spB4);

                                create_particle_effect(
                                    sp70,
                                    sp68,
                                    MAX(func_8031124C_7228FC(sp70, sp68) >> 0x10, spB8 + (var_s0 * spB2)) + 6,
                                    21,
                                    0,
                                    0,
                                    0,
                                    0x28,
                                    GPACK_RGBA5551(248, 32, 0, 1),
                                    GPACK_RGBA5551(248, 248, 248, 1),
                                    0);
                            }

                            if (func_80322D68_734418(spBC, spBA, spB8 + D_803D5530->unk42, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h + D_803D5530->unk42, &spA6, &spA4, &spA2, 0x14, 0xA, 1, 0)) {
                                play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

                                for (var_s0 = 0; var_s0 < 4; var_s0++) {
                                    create_particle_effect(
                                        spA6,
                                        spA4,
                                        spA2,
                                        0x18,
                                        (SSSV_RAND(16) - 7) << 0x10,
                                        (SSSV_RAND(16) - 7) << 0x10,
                                        SSSV_RAND(16) << 0x10,
                                        SSSV_RAND(4) + 4,
                                        GPACK_RGBA5551(248, 32, 0, 1),    // red
                                        GPACK_RGBA5551(248, 248, 248, 1), // white
                                        0);
                                }
                            }
                        }
                    }
                }
            } else if (ticks_remaining < 0x10) {
                temp_v0_6 = (((ticks_remaining - 8) << 1) + 16);
                D_803F2EB4 = (ticks_remaining * D_803F2EB4) >> 5;
                D_803F2EB0 = ((64 - temp_v0_6) * D_803F2EB0) >> 5;
                D_803F2EB8 = ((64 - temp_v0_6) * D_803F2EB8) >> 5;

            } else {
                D_803D552C->unk365 = ATTACK_NONE;
                func_8033F300_7509B0();
            }
            break;
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spC8, 0x186, 0x96, 0x1F4, 0x64);
            func_802BF3C0_6D0A70(0x1F4, 0x64, 0, 0x80, 0, 0x80, &D_803A44D0_7B5B80, &D_803A4500_7B5BB0, &D_803A4530_7B5BE0,
                                 0x1F4, 0x64, 0, 0x80, 0x80, 0, &D_803A4544_7B5BF4, &D_803A4574_7B5C24, &D_803A45A4_7B5C54,
                                 &spC8);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x258, 0x190, 0);
            func_802BBC90_6CD340(0x366);
            func_803033D4_714A84(0x1A, 2, spA8);
            func_8034B3A8_75CA58(0);
            func_8038CCF0_79E3A0(0xC8, 0x14, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A45B8_7B5C68, D_803A45C8_7B5C78, D_803A45D8_7B5C88, D_803A45F4_7B5CA4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A45B8_7B5C68, D_803A45C8_7B5C78, D_803A45D8_7B5C88, D_803A4630_7B5CE0);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0 = D_803F2AA2, (temp_v0 == 0)) || (temp_v0 == 2) || ((temp_v0 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (spAA - D_803D552C->heading) & 0xFF, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);

            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.22f); // D_803BCA00_7CE0B0
            func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04004D10_CC740);
            func_802C78B0_6D8F60(1,  2, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04004090_CBAC0);
            func_802C78B0_6D8F60(2, 26, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04004200_CBC30);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04004330_CBD60); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04004330_CBD60); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 1, 0, D_04004330_CBD60); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 1, 0, D_04004330_CBD60); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spAE, &spAC);
                func_8031A278_72B928(&D_803D552C->unk326, &spAE, &spAC);
#pragma _permuter sameline start
                spAE = D_803BD5B2_7CEC62[spAE]; spAC = D_803BD66A_7CED1A[spAC];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CA0, D_01002100, spAE);
                gSPDisplayList(D_801D9E88++, &D_010037F0_3D0C0);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046D0_CC100);
                func_80356BD8_768288(D_01000CA0, D_01002100, spAC);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046F0_CC120);
                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spC6 == 0) || (spC6 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + D_803D5524->unkBA, (D_803D552C->heading - spAA) & 0xFF, D_01033190, 0x25, 9, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spC6 == 0) {
        func_803034D0_714B80(D_803D552C, 0x30C, 0, 1);
        func_80303990_715040(D_803D552C, 1, 33, 1, 20, 0x190, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x492, 0x1F4);
    }

    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            if (D_803D552C->unk365 == ATTACK_FOX_TAIL) {
                D_803D552C->unk365 = ATTACK_FOX_3;
                D_803D552C->unk32A = D_803D5544;
            }
        } else {
            D_803D552C->unk2EC--;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/fox/func_802E5000_6F66B0.s")
#endif

// FIRE_FOX
void func_802E620C_6F78BC(void) {
    s32 var_v0_3;
    s16 var_v1;
    s16 sp98;
    f32 var_f0;
    s16 sp92;
    u16 ticks_remaining;
    s16 sp8E;
    s16 sp8C;
    f32 var_f12;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp98 = 0;
        D_803F2EDD = 0;
    } else {
        sp98 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0xFDC, 3, 0x9E, 0x14, 0, 1, CHECK_SEGMENT == 0);
    }

    if ((sp98 != 4) && (sp98 != 1)) {
        var_f0 = (f32) (((D_803F2C3C * 0.7111111111111111) - D_803D5530->yRotation) - 64.0);

        while (var_f0 < -128.0) { var_f0 += 256.0; };
        while (var_f0 > 128.0) { var_f0 -= 256.0; }

        if (var_f0 < 0.0f) {
            var_f0 = -var_f0;
        }

        var_f12 = 1.0f;
        if (D_803D5538 != 0) {
            var_f12 = (D_803D554C * 0.0625) + 1;
        }
        if (D_803D552C->unk365 == ATTACK_FOX_4) {
            var_f12 += (func_8012826C() - 32768.0) / 65536.0;
        }

        var_v0_3 = MIN(32767.0, (28672.0f * var_f12) * (0.6 + (0.4 * var_f0 * 0.0078125)));
        if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
            var_v0_3 = MAX(0, var_v0_3 - ((D_803D5544 - D_803D552C->unk328) << 9));
        }
        if ((D_803D5538 != 0) || (D_803F2D50.segment != 0)) {
            func_8032CED0_73E580(
                D_803D5530,
                SFX_UNKNOWN_103,
                var_v0_3,
                0.3f,
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
    if (sp98 == 0) {
        func_8037FE24_7914D4();
        func_8035D120_76E7D0();
        func_8035D734_76EDE4();
        if ((D_803D552C->unk365 == ATTACK_FOX_4)) {
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining >= 0x33) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802BAA38_6CC0E8(0x186, 0x96);
            func_802C4A70_6D6120(0x258, 0x190, 0);
            func_802BBA10_6CD0C0(0x366);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A4750_7B5E00, D_803A4758_7B5E08, D_803A4760_7B5E10, D_803A476C_7B5E1C);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A4758_7B5E08, D_803A4758_7B5E08, D_803A4760_7B5E10, D_803A4788_7B5E38);
                break;
            }
        }

        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (s32) -D_803D5530->yRotation, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.22f);
            func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04004D10_CC740);
            func_802C78B0_6D8F60(1, 2, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04004090_CBAC0);
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(
                    2,
                    1,
                    ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) * 0x3A) >> 6,
                    ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) * 0x3A) >> 6,
                    ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) * 0x3A) >> 6,
                    D_803F2ED0,
                    0,
                    0,
                    0,
                    D_04005030_CCA60);
            }
            if ((D_803F2ECE != 1) || (D_803F2ECC == 0)) {
                load_1_tile(D_040052D0_CCD00, D_040050D0_CCB00);
                if (D_803F2D10.unk0 != 0) {
                    func_802C78B0_6D8F60(2, 0x1A, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04004A20_CC450);
                } else if (D_803D5538 != 0) {
                    func_802C78B0_6D8F60(
                        2,
                        0x1A,
                        (((((SSSV_RAND(256) << 7) + FTOFIX32(1.0)) * (D_803D554C + 0x10)) >> 4) * 0x3A) >> 6,
                        (((((SSSV_RAND(256) << 7) + FTOFIX32(1.0)) * (D_803D554C + 0x10)) >> 4) * 0x3A) >> 6,
                        (((((SSSV_RAND(256) << 7) + FTOFIX32(1.0)) * (D_803D554C + 0x10)) >> 4) * 0x3A) >> 6,
                        D_803F2ED0,
                        0,
                        0,
                        0,
                        D_04004A20_CC450);
                } else {
                    func_802C78B0_6D8F60(
                        2,
                        0x1A,
                        (((SSSV_RAND(256) << 7) * 58) + FTOFIX32(58.0)) >> 6,
                        (((SSSV_RAND(256) << 7) * 58) + FTOFIX32(58.0)) >> 6,
                        (((SSSV_RAND(256) << 7) * 58) + FTOFIX32(58.0)) >> 6,
                        D_803F2ED0,
                        0,
                        0,
                        0,
                        D_04004A20_CC450);
                }
            }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp8E, &sp8C);
                func_8031A278_72B928(&D_803D552C->unk326, &sp8E, &sp8C);
                sp8E = D_803BD5B2_7CEC62[sp8E]; sp8C = D_803BD66A_7CED1A[sp8C];
                func_80356BD8_768288(D_01000CA0, D_01002100, sp8E);
                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);

                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046D0_CC100);
                func_80356BD8_768288(D_01000CA0, D_01002100, sp8C);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046F0_CC120);
                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

            if ((D_803F2ECE != 1) || (D_803F2ECC == 0)) {
                create_particle_effect(
                    D_803D5530->position.xPos.h + ((((SIN(-D_803D552C->heading) >> 7) * 1560) / 0x3A) >> 8),
                    D_803D5530->position.zPos.h - ((((COS(D_803D552C->heading) >> 7) * 1560) / 0x3A) >> 8),
                    D_803D5530->position.yPos.h + 8,
                    25 + SSSV_RAND(2),
                    (SSSV_RAND(32768) * 2) + FTOFIX32(-0.6103515625),
                    (SSSV_RAND(32768) * 2) + FTOFIX32(-0.6103515625),
                    0,
                    SSSV_RAND(16),
                    GPACK_RGBA5551(0, 0, 0, 1),
                    GPACK_RGBA5551(0, 0, 0, 1),
                    SSSV_RAND(32) + 0x19);

                if ((D_803D5538 != 0) && (D_803D554C >= 9)) {
                    var_v1 = SSSV_RAND(2);
                } else {
                    var_v1 = SSSV_RAND(4);
                }
                if (var_v1 == 0) {
                    if (D_803D5538 != 0) {
                        sp92 = D_803D554C;
                    } else {
                        sp92 = 0;
                    }

                    create_particle_effect(
                        D_803D5530->position.xPos.h + ((((SIN(-D_803D552C->heading) >> 7) * 0x618) / 0x3A) >> 8),
                        D_803D5530->position.zPos.h - ((((COS(D_803D552C->heading) >> 7) * 0x618) / 0x3A) >> 8),
                        D_803D5530->position.yPos.h + 8,
                        25 + SSSV_RAND(2),
                        SSSV_RAND(32768) * 2,
                        SSSV_RAND(32768) * 2,
                        0,
                        SSSV_RAND(16) + sp92,
                        GPACK_RGBA5551(0, 0, 0, 1),
                        GPACK_RGBA5551(0, 0, 0, 1),
                        SSSV_RAND(32) + 0x19);
                }
            }
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp98 == 0) || (sp98 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + D_803D5524->unkBA), D_803D552C->heading, D_01033190, 0x25, 9, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp98 == 0) {
        func_803034D0_714B80(D_803D552C, 0x30C, 0, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x14, 0x190, 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x492, 0x1F4);
    }
}

// RACING_FOX
void func_802E7394_6F8A44(void) {
    struct061 spB0;
    s16 spAE;
    s16 spAC; // pad
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;
    s16 sp9E;
    s16 sp9C; // pad
    s16 sp9A;
    s16 sp98;
    s16 sp96; // pad
    s16 sp94;
    s16 sp92;

    s16 temp_a0_3;
    s16 var_s0;
    u16 ticks_remaining;

    u8  temp_v0_11;

    f32 var_f0;
    f32 temp_f2_2;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spAE = 0;
        D_803F2EDD = 0;
    } else {
        spAE = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0xCB0, 3, 0x9E, 0x14, 0, 1, CHECK_SEGMENT == 0);
    }

    if ((spAE != 4) && (spAE != 1) && (D_803D5530->unk162 == 1)) {

        temp_f2_2 = sqrtf(SQ((f32)D_803D552C->xVelocity.w) + SQ((f32)D_803D552C->zVelocity.w)) / (D_803D5524->unkA4 << 0xA);
        if (temp_f2_2 < 0.2) {
            var_f0 = 0.0f;
        } else if (temp_f2_2 > 0.6) {
            var_f0 = 1.0f;
        } else {
            var_f0 = 2.5f * (temp_f2_2 - 0.2);
        }
        if (var_f0 > 0.0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CED0_73E580(
                    D_803D5530,
                    SFX_UNKNOWN_13,
                    (12288.0f * var_f0) / 2.0,
                    temp_f2_2 * 2.0,
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
    if (spAE == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        sp98 = 0;
        sp9A = 0;
        switch (D_803D552C->unk365) {                        /* irregular */
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_FOX_TAIL:
            // same line for regalloc
#pragma _permuter sameline start
            if ((D_803D5530->unk4A != 0) && (D_803F2D10.unk0 == 0)) { D_803D552C->unk32A++;}
#pragma _permuter sameline end
            D_803D5528->unk3C0.unk0 = 0xF;
            D_803D5528->unk3C0.unk2 = 0;

            ticks_remaining = D_803D5544 - D_803D552C->unk32A; // & 0xFFFF;
            if (ticks_remaining < 9) {
                sp9A = ticks_remaining * 0x10;
            } else {
                sp98 = -(SIN((ticks_remaining - 8) << 5) >> 7) >> 3;
                sp9A = ((SIN((ticks_remaining - 8) << 5) >> 7) >> 4) + 0x80;
                if (ticks_remaining >= 0xE) {
                    D_803D552C->unk32A += 8;
                }
                if ((ticks_remaining == 0xA) && (D_803D5530->unk4A == 0)) {
                    if (func_803224C4_733B74(0xF, 0x2A, 0, 0x17, 9, 0, 0, 3)) {
                        play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_59, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
                    }
                }
            }
            break;
        case ATTACK_FOX_3:
            if (D_803D5530->unk4A != 0) {
                D_803D552C->unk32A += 1;
            }
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 9) {
                sp9A = 0x80 - (ticks_remaining * 0x10);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_FOX_DASH:
            if (D_803D5530->unk4A != 0) {
                D_803D552C->unk32A++;
            }
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;

            if (ticks_remaining < 0x11) {
                temp_a0_3 = 0x20 - ticks_remaining;
                D_803F2EB4 = (temp_a0_3 * D_803F2EB4) >> 5;
                D_803F2EB0 = ((0x40 - temp_a0_3) * D_803F2EB0) >> 5;
                D_803F2EB8 = ((0x40 - temp_a0_3) * D_803F2EB8) >> 5;
                if (ticks_remaining == 0x10) {

                    if (D_803D5530->unk4A == 0) {
                        spA8 = D_803D5530->position.xPos.h;
                        spA6 = D_803D5530->position.zPos.h;
                        spA4 = D_803D5530->position.yPos.h;

                        spAA = func_8037F07C_79072C(0x180, D_803D552C->heading);
                        play_sound_effect_at_location(SFX_FOX_DASH, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                        // do warp if moved far enough
                        if (spAA >= 0x11) {

                            spA2 = (D_803D5530->position.xPos.h - spA8) / (s16)(spAA >> 4);
                            spA0 = (D_803D5530->position.zPos.h - spA6) / (s16)(spAA >> 4);
                            sp9E = (D_803D5530->position.yPos.h - spA4) / (s16)(spAA >> 4);

                            var_s0 = (s16)(spAA >> 4) - 1; // outside loop for regswap
                            for (; var_s0 > 0; var_s0--) {

                                sp9E = MIN(sp9E, func_8031124C_7228FC(spA2, spA0) >> 0x10);

                                create_particle_effect(
                                    spA8 + (var_s0 * spA2),
                                    spA6 + (var_s0 * spA0),
                                    MAX(func_8031124C_7228FC(spA8 + (var_s0 * spA2), spA6 + (var_s0 * spA0)) >> 0x10, spA4 + (var_s0 * sp9E)) + 6,
                                    0x15,
                                    0,
                                    0,
                                    0,
                                    0x28,
                                    GPACK_RGBA5551(248, 32, 0, 1), // red
                                    GPACK_RGBA5551(248, 248, 248, 1), // white
                                    0);
                            }
                        }
                    }
                }
            } else if (ticks_remaining < 32) {
                temp_a0_3 = ticks_remaining;
                D_803F2EB4 = (ticks_remaining * D_803F2EB4) >> 5;
                D_803F2EB0 = ((64 - temp_a0_3) * D_803F2EB0) >> 5;
                D_803F2EB8 = ((64 - temp_a0_3) * D_803F2EB8) >> 5;
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
                func_8033F300_7509B0();
            }
            break;
        }
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spB0, 0x186, 0x96, 0x1F4, 0);
            func_802C1830_6D2EE0(0x190, &spB0);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x258, 0x190, 0);
            func_802BBC90_6CD340(0x366);
            func_803033D4_714A84(0x1A, 2, sp98);
            func_8034B3A8_75CA58(0);
            func_8038CCF0_79E3A0(0xC8, 0x14, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {                    /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                func_802DB670_6ECD20(D_803A466C_7B5D1C, D_803A4680_7B5D30, D_803A4694_7B5D44, D_803A46B8_7B5D68);
                break;
            case 2:                                 /* switch 1 */
                func_802DB670_6ECD20(D_803A466C_7B5D1C, D_803A4680_7B5D30, D_803A4694_7B5D44, D_803A4704_7B5DB4);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_11 = D_803F2AA2, (temp_v0_11 == 0)) || (temp_v0_11 == 2) || ((temp_v0_11 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (sp9A - D_803D552C->heading) & 0xFF, D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, 0.22f);
            func_802C78B0_6D8F60(1, 20, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04004D10_CC740);
            func_802C78B0_6D8F60(1, 2,   0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004090_CBAC0);
            func_802C78B0_6D8F60(2, 26,  0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004200_CBC30);
            func_802C78B0_6D8F60(7, 8,   0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004590_CBFC0);
            func_802C78B0_6D8F60(10, 11, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004590_CBFC0);
            func_802C78B0_6D8F60(13, 14, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004590_CBFC0);
            func_802C78B0_6D8F60(16, 17, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, D_04004590_CBFC0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp94, &sp92);
                func_8031A278_72B928(&D_803D552C->unk326, &sp94, &sp92);
#pragma _permuter sameline start
                sp94 = D_803BD5B2_7CEC62[sp94]; sp92 = D_803BD66A_7CED1A[sp92];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CA0, D_01002100, sp94);
                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046D0_CC100);
                func_80356BD8_768288(D_01000CA0, D_01002100, sp92);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, (D_803F2EC8 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_040046F0_CC120);
                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spAE == 0) || (spAE == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + D_803D5524->unkBA, (D_803D552C->heading - sp9A) & 0xFF, D_01033190, (s16) 0x25, (s16) 9, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (spAE == 0) {
        func_803034D0_714B80(D_803D552C, 0x30C, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, (u16) 0x14, (u16) 0x1F4, (u16) 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x492, 0x1F4);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            if (D_803D552C->unk365 == ATTACK_FOX_TAIL) {
                D_803D552C->unk365 = ATTACK_FOX_3;
                D_803D552C->unk32A = D_803D5544;
            }
        } else {
            D_803D552C->unk2EC--;
        }
    }
}

void func_802E84E0_6F9B90(void) {
    set_target_speed(16);
}

// fire_fox_fire_missile2 ?
void func_802E8500_6F9BB0(void) {
    Animal *animal = func_8037E9AC_79005C();
    if (animal != NULL) {
        play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
    // scale missile to zero
    get_missile_side();
    // fire missile
    fire_homing_missile(
        D_803D5530->position.xPos.h,
        D_803D5530->position.zPos.h,
        D_803D5530->position.yPos.h - D_803D5530->unk42,
        0x161,
        D_803D552C->heading*360 >> 8,
        animal,
        1,
        16,
        0.5f,
        0xC8,
        0x60,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_802E864C_6F9CFC(void) {
    if (D_803D552C->unk365 != ATTACK_FOX_DASH) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_FOX_DASH;
        func_8033F2EC_75099C();
        func_8033F294_750944(2);
    } else {
        D_803D5528->energy[0].unk0 += D_803D5524->unkDA[0][0];
    }
}

void func_802E86C8_6F9D78(void) {
    if (D_803D552C->unk365 == ATTACK_FOX_3) {
        D_803D552C->unk365 = ATTACK_FOX_TAIL;
    } else if (D_803D552C->unk365 != ATTACK_FOX_TAIL) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_FOX_TAIL;
        play_sound_effect_at_location(SFX_UNKNOWN_0, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
}

// racing fox
void func_802E8760_6F9E10(void) {
    if (((D_803D5544 - D_803D552C->unk32A) >= 13) && (D_803D552C->unk365 == ATTACK_FOX_TAIL)) {
        D_803D552C->unk365 = ATTACK_FOX_3;
        D_803D552C->unk32A = D_803D5544;
    }
}

void fire_fox_fire_missile(Animal *animal) {
    play_sound_effect_at_location(SFX_UNKNOWN_2, 0x3700, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    // scale missile to zero
    get_missile_side();
    // fire missile
    fire_homing_missile(
        D_803D5530->position.xPos.h,
        D_803D5530->position.zPos.h,
        D_803D5530->position.yPos.h - D_803D5530->unk42,
        353,
        D_803D552C->heading * 360 >> 8,
        animal,
        2,
        16,
        0.5f,
        200,
        96,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
}

// fox_tail_attack
void func_802E88C0_6F9F70(s16 arg0) {
    if (D_803D552C->unk365 == ATTACK_FOX_TAIL) {
        D_803D552C->unk2EC = MAX(D_803D552C->unk2EC, arg0);
    } else if (D_803D552C->unk365 == ATTACK_FOX_3) {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk365 = ATTACK_FOX_TAIL;
        D_803D552C->unk32A -= 8;
    } else {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_FOX_TAIL;
        play_sound_effect_at_location(SFX_UNKNOWN_0, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
}

void fox_warp(void) {
    if (D_803D552C->unk365 != ATTACK_FOX_DASH) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_FOX_DASH;
    }
}
