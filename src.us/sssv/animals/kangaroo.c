#include <ultra64.h>
#include "common.h"

extern u8 D_803B4C30_7C62E0[];
extern u8 D_803B4C40_7C62F0[];

extern Gfx D_803B4C50_7C6300[];
extern Gfx D_803B4C70_7C6320[];
extern Gfx D_803B4CB4_7C6364[];

extern Gfx D_04003780_EAD30[];
extern Gfx D_01003588_3CE58[];

extern Gfx D_040038A0_EAE50[];
extern Gfx D_04002E30_EA3E0[];
extern Gfx D_04003270_EA820[];
extern Gfx D_04003030_EA5E0[];
extern Gfx D_04002B30_EA0E0[];
extern Gfx D_04003FF0_EB5A0[];
extern Gfx D_04004010_EB5C0[];


extern u8 D_803B4CF8_7C63A8[];
extern u8 D_803B4D04_7C63B4[];

extern s16 D_803B4D10_7C63C0[];
extern s16 D_803B4D24_7C63D4[];
extern s16 D_803B4D54_7C6404[];

extern Gfx D_04003470_EAA20[];
extern Gfx D_04003C60_EB210[];
extern Gfx D_04003EB0_EB460[];
extern Gfx D_04003F40_EB4F0[];


// BOXING_KANGAROO
void func_8036F7A0_780E50(void) {
    u16 ticks_remaining;
    s16 tmp3;
    s16 tmp4;
    s16 temp_a3;
    u8 temp_a0;
    u8 var_v0;
    s16 temp_a1;

    s32 spB8;
    s32 spB4;
    s32 spB0; // pad
    s16 spAE;
    struct061 spA4;
    s16 spA2;
    s16 spA0;
    s16 sp9E;


    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp9E = 0;
        D_803F2EDD = 0;
    } else {
        sp9E = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x2080, 8, 0x64, 0x50, 0, 1, CHECK_SEGMENT == 0);
    }

    if (sp9E == 0) {
        func_8038C98C_79E03C();
        ticks_remaining = D_803D5544 - D_803D552C->unk35E;
        if (((ticks_remaining & 0xFF) < 0x50) && (ticks_remaining >= 0x100) && ((D_803D552C->unk366 == MOVEMENT_MODE_NORMAL) || (D_803D552C->unk366 == MOVEMENT_MODE_INJURED))) {
            if ((func_8012826C() & 0x1F00) == 0x1900) {
                D_803D5530->yRotation = ((SSSV_RAND(64) + D_803D5530->yRotation) - 0x20) % 360;
            }
            if ((D_803D552C->unk364 != 7) && (SSSV_RAND(16) == 7)) {
                func_802DBA58_6ED108(7, D_803D552C);
            }
            if (D_803D552C->unk365 == ATTACK_NONE) {
                D_803D552C->unk32A = D_803D5544;
                if (SSSV_RAND(2) == 0) {
                    D_803D552C->unk365 = ATTACK_KANGAROO_1;
                } else {
                    D_803D552C->unk365 = ATTACK_KANGAROO_2;
                }
            }
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        func_8035D734_76EDE4();

        spB8 = spB4 = FTOFIX32(1.0);

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            switch (D_803D552C->unk365) {
            case ATTACK_KANGAROO_1:
                func_802DCCAC_6EE35C(0xC);
                if ((D_803D5544 - D_803D552C->unk32A) == 3) {
                    if (func_803224C4_733B74(0x2D, 0x2D, -0xB, 0x16, 0xC, 0, 0, 0x12) != 0) {
                        if ((D_803D5538 == 0) && (D_803F2D50.unk52 == 3)) {
                            play_sound_effect_at_location(SFX_UNKNOWN_26, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0.75f);
                        } else {
                            play_sound_effect_at_location(SFX_UNKNOWN_26, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                        }
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_14, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                }
                break;
            case ATTACK_KANGAROO_2:
                func_802DCCAC_6EE35C(0xC);
                if ((D_803D5544 - D_803D552C->unk32A) == 3) {
                    if (func_803224C4_733B74(0x2D, 0x2D, 0xB, 0x16, 0xC, 0, 0, 0x12) != 0) {
                        if ((D_803D5538 == 0) && (D_803F2D50.unk52 == 3)) {
                            play_sound_effect_at_location(SFX_UNKNOWN_26, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0.75f);
                        } else {
                            play_sound_effect_at_location(SFX_UNKNOWN_26, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                        }
                    } else {
                        play_sound_effect_at_location(SFX_UNKNOWN_14, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                }
                break;
            case ATTACK_NONE:
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            func_802BA614_6CBCC4(&spA4, 0x2DB);
            func_802C3C64_6D5314(0x1E7, 0x28A, 0x3CF);
            func_80320DF8_7324A8(0x1E7, 0x32C);
            func_802BB840_6CCEF0(0x196);
            D_80203FE0[26].unk4 += 182;
            func_802C4A70_6D6120(0x1E7, 0x28A, 8);
            func_8038CCF0_79E3A0(0x65, 3, 7, 0x13, 0x14, -1);
            func_8038CCF0_79E3A0(-0x66, 4, 0xA, -1, -1, -1);

            temp_a1 = D_80203FE0[20].unk0 - D_80203FE0[19].unk0;
            temp_a3 = D_80203FE0[20].unk2 - D_80203FE0[19].unk2;

            tmp3 = (((temp_a1 * D_80152350.unk384[D_803D552C->unk316]) >> 8) + ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a3) >> 8));
            tmp4 = (((temp_a3 * D_80152350.unk384[D_803D552C->unk316]) >> 8) - ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a1) >> 8));

            D_80203FE0[20].unk0 = D_80203FE0[19].unk0 + tmp3;
            D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + tmp4;

            if (D_803D552C->unk365 == ATTACK_KANGAROO_1) {
                D_80203FE0[7].unk2 += (D_803F2ED8 * 0x32C) >> 5;
                spB8 = (D_803F2ED8 << 0xB) + 0x10000;

                D_80203FE0[1].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[19].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[20].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[3].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[4].unk2 -= (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[10].unk2 -= (D_803F2ED8 * 0x5B6) >> 8;
            } else if (D_803D552C->unk365 == ATTACK_KANGAROO_2) {
                D_80203FE0[10].unk2 += (D_803F2ED8 * 0x32C) >> 5;
                spB4 = (D_803F2ED8 << 0xB) + 0x10000;

                D_80203FE0[1].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[19].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[20].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[4].unk2 += (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[3].unk2 -= (D_803F2ED8 * 0x5B6) >> 8;
                D_80203FE0[7].unk2 -= (D_803F2ED8 * 0x5B6) >> 8;
            }
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4C30_7C62E0, D_803B4C40_7C62F0, D_803B4C50_7C6300, D_803B4C70_7C6320);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4C30_7C62E0, D_803B4C40_7C62F0, D_803B4C50_7C6300, D_803B4CB4_7C6364);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (var_v0 = D_803F2AA2, (var_v0 == 0)) || (var_v0 == 2) || ((var_v0 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
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

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 2, -0.2f);

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, FTOFIX32(0.8125), (spB8 * 0x34) >> 6, FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04003780_EAD30); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, FTOFIX32(0.8125), (spB4 * 0x34) >> 6, FTOFIX32(0.8125), D_803F2ED0, 0, 1, 0, D_04003780_EAD30); }
            if (D_803D552C->unk365 == ATTACK_KANGAROO_1) {
                D_80203FE0[7].unk2 += (D_803F2ED8 * 0x32C) >> 5;
            } else if (D_803D552C->unk365 == ATTACK_KANGAROO_2) {
                D_80203FE0[10].unk2 +=  (D_803F2ED8 * 0x32C) >> 5;
            }
            add_hilite();
            gSPDisplayList(D_801D9E88++, D_01003588_3CE58);

            if ((D_803D5538 == 0) && (D_803F2D50.unk52 == 3)) {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0x37, 0x37, 0xFF, 0xFF);
            } else {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
            }
            func_802C78B0_6D8F60(3, 7, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_040038A0_EAE50);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(4, 0xA, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 1, 0, D_040038A0_EAE50);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04002E30_EA3E0);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x34) >> 6, (D_803F2EC0 * 0x34) >> 6, (D_803F2EC4 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04003270_EA820);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xD, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04003030_EA5E0); }
            func_802C78B0_6D8F60(0xD, 0xE, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04002B30_EA0E0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x10, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 1, 0, D_04003030_EA5E0); }
            func_802C78B0_6D8F60(0x10, 0x11, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 1, 0, D_04002B30_EA0E0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spA2, &spA0);
                func_8031A278_72B928(&D_803D552C->unk326, &spA2, &spA0);
                spA2 = D_803BD530_7CEBE0.eyes[5][spA2]; spA0 = D_803BD600_7CECB0.eyes[4][spA0];
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spA2);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04003FF0_EB5A0);
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spA0);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04004010_EB5C0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp9E == 0) || (sp9E == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, img_D_01033190_6CA60_i4__png, (s16) 0x1F, (s16) 0x1F, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }

    spAE = D_803D5528->unk3C8.unk2;
    if (spAE != 0) {
        if ((sp9E == 0) && (D_803F2EDB != 0)) {
            s32 a1 = D_803D5530->position.xPos.w + ((SIN(D_803D552C->heading) * D_80203FE0[26].unk2) / 16);
            s32 a2 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * D_80203FE0[26].unk2) / 16);
            s32 a3 = D_803D5530->position.yPos.w + ((D_80203FE0[26].unk4 << 0x10) / 32);

            func_802DE914_6EFFC4(
                spAE,
                a1,
                a2,
                a3,
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
    if (sp9E == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x391, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x28A, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x891, 0x2DB);
    }
}

// POGO_KANGAROO
#if 0
// CURRENT (9850)
// esa: func_8009A794 ?
void func_80370C84_782334(void) {
    s16 temp_t1;
    s32 temp_t8;
    s16 temp_v0;
    s16 var_v1_2;
    s16 temp_t0;
    u16 ticks_remaining;
    u8  temp_v0_15;
    s32 a0, a1, a2;

    s32 var_s1;
    s32 var_s2;

    s16 temp_a0;
    s16 temp_t9;
    s16 tmp5;

    s16 tmp1;
    s16 tmp2;

    s16 spE8;
    s16 spE6;
    s16 spE4; //pad
    s16 spE2;
    s16 spE0;

    s16 spDE;
    s16 spDC;
    s16 spDA; // pad
    s16 spD8;

    s32 spC8; // this isnt initialised...
    s32 spC4; // this isnt initialised...

    Animal *spC0;
    s8  spBF;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spDE = 0;
        D_803F2EDD = 0;
    } else {
        spDE = func_802E89F0_6FA0A0(
            D_803D552C->position.xPos.w,
            D_803D552C->position.zPos.w,
            D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF),
            0x820,
            8,
            0x64,
            0x51,
            0,
            1,
            CHECK_SEGMENT == 0);
    }

    if (spDE == 0) {
        func_8038C98C_79E03C();
        if ((D_803D5538 != 0) && (((D_803D5544 - D_803D552C->unk35E) & 0x1FF) == 0xAA)) {
            func_80372698_783D48();
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B96D0_6CAD80(&spE8, 0x2DB, 0x565, 0);
            func_802C1A44_6D30F4(0x3CF, 0, &spE8);
            func_802C4A70_6D6120(0x1E7, 0x28A, 6);
            func_80320DF8_7324A8(0x1E7, 0x32C);
            func_802BB840_6CCEF0(0x196);

            D_80203FE0[26].unk4 += 365;

            temp_v0 = (D_80203FE0[20].unk0 - D_80203FE0[19].unk0);
            temp_a0 = (D_80203FE0[20].unk2 - D_80203FE0[19].unk2);

            tmp1 = ((temp_v0 * D_80152350.unk384[D_803D552C->unk316]) >> 8) + ((D_80152350.unk2D0[D_803D552C->unk316] * temp_a0) >> 8);
            tmp2 = ((temp_a0 * D_80152350.unk384[D_803D552C->unk316]) >> 8) - ((D_80152350.unk2D0[D_803D552C->unk316] * temp_v0) >> 8);

            D_80203FE0[20].unk0 = D_80203FE0[19].unk0 + tmp1;
            D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + tmp2;
        }

        switch (D_803D552C->unk365) {
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;

        case ATTACK_KANGAROO_5:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 8) {
                D_80203FE0[7].unk4 += (ticks_remaining * 0x32C) >> 3;
                D_80203FE0[7].unk2 -= (ticks_remaining * 0x32C) >> 3;
            } else {
                D_803D552C->unk35C = -0x1F4;
                D_803D552C->unk365 = ATTACK_KANGAROO_3;
                D_803D552C->unk32A = D_803D5544;
            }
            break;

        case ATTACK_KANGAROO_3:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if ((ticks_remaining < 0x26) && ((D_803D5530->unk4A == 0))) {

                func_8032CD70_73E420(
                    D_803D5530,
                    0x1F,
                    0x5000,
                    0,
                    (((SIN(ticks_remaining << 3) >> 7) / 400.0) + 1.0),
                    D_803D5530->position.xPos.h,
                    D_803D5530->position.zPos.h,
                    D_803D5530->position.yPos.h);

                if ((D_80204278->usedModelViewMtxs + 6) < 0xFA) {

                    for (spD8 = 0; spD8 < 6; spD8++) {

                        var_s2 = spC4; // wtf?
                        var_s1 = spC8; // wtf?

                        temp_t1 = (ticks_remaining + spD8) - 6;
                        if ((temp_t1 >= 0) && (temp_t1 < 32)) {
                            temp_t0 = D_803D552C->unk32C - (temp_t1 << 3);

                            var_s1 = ((SIN(D_803D552C->unk32C) >> 7) - (SIN(temp_t0) >> 7));
                            var_s2 = ((COS(D_803D552C->unk32C) >> 7) - (COS(temp_t0) >> 7));

                            var_s1 = (var_s1 * 21) >> 5;
                            var_s2 = (var_s2 * 21) >> 5;

                            func_80127640(
                                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                                D_803D5530->position.xPos.w + (var_s1 << 0x10),
                                D_803D5530->position.zPos.w + (var_s2 << 0x10),
                                D_803D5530->position.yPos.w + ((D_803D5524->unkBA * 3) * 0x4000),
                                (temp_t1 << 4) & 0xFF,
                                FTOFIX32(1.0) / 4,
                                FTOFIX32(1.0) / 4,
                                FTOFIX32(1.0) / 4,
                                0,
                                0);
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gDPSetPrimColor(D_801D9E88++, 0, 0, ((spD8 << 5) + 0x40), ((spD8 << 5) + 0x40), 0, 0xFF); // which variable is the color?
                            gSPDisplayList(D_801D9E88++, D_04003EB0_EB460);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                  }

                  spBF = 0;
                  if (func_80322A58_734108(
                        D_803D5530->position.xPos.h + var_s1,
                        D_803D5530->position.zPos.h + var_s2,
                        D_803D5530->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2),
                        0x14,
                        0x1E,
                        &spC0,
                        NULL,
                        8)) {
                      spBF = 1;
                      play_sound_effect_at_location(SFX_UNKNOWN_97, 0x7FFF, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                  }

                  tmp5 = func_8033C9CC_74E07C(
                      D_803D5530->position.xPos.h,
                      D_803D5530->position.zPos.h,
                      D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
                      D_803D5530->unk160,
                      D_803D5530->position.xPos.h + var_s1,
                      D_803D5530->position.zPos.h + var_s2,
                      D_803D5530->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2),
                      func_803136FC_724DAC(
                          D_803D5530->position.xPos.h + var_s1,
                          D_803D5530->position.zPos.h + var_s2,
                          D_803D5530->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2)),
                      0,
                      0);

                  if ((tmp5 != 0) || ((((D_803D5530->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2)) < (func_8031124C_7228FC((D_803D5530->position.xPos.h + var_s1), (D_803D5530->position.zPos.h + var_s2)) >> 0x10)) != 0))) {
                      spBF = 1;
                      play_sound_effect_at_location(SFX_UNKNOWN_38, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                  }

                  if (spBF != 0) {
                      D_803D552C->unk365 = ATTACK_KANGAROO_4;
                      D_803D552C->unk32A = D_803D5544;
                      D_803D552C->unk32C = ((var_s1 << 6) & ~0xFF) | ((var_s2 >> 2) & 0xFF);

                      for (spDC = 0; spDC < 4; spDC++) {
                          create_particle_effect(
                              D_803D5530->position.xPos.h + var_s1,
                              D_803D5530->position.zPos.h + var_s2,
                              D_803D5530->position.yPos.h + ((D_803D5524->unkBA * 3) >> 2),
                              0x18,
                              (SSSV_RAND(16) - 7) << 0x10,
                              (SSSV_RAND(16) - 7) << 0x10,
                              SSSV_RAND(16) << 0x10,
                              SSSV_RAND(4) + 4,
                              GPACK_RGBA5551(248, 248, 0, 1), // yellow
                              GPACK_RGBA5551(128, 128, 0, 1), // greenish yellow
                              0);
                        }
                    }
                }
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;

        case 34:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 0x10) {
                func_8013328C(
                    D_803D5530,
                    SFX_UNKNOWN_31,
                    0x40,
                    (((SIN(-ticks_remaining << 3) >> 7) / 400.0) + 1.0),
                    0x5000,
                    0);

                if ((D_80204278->usedModelViewMtxs + 6) < 0xFA) {

                    for (spD8 = 0; spD8 < 6; spD8++) {

                        temp_t1 = (ticks_remaining + spD8) - 3;
                        if ((temp_t1 >= 0) && (temp_t1 < 16)) {
                            temp_t8 = D_803D552C->unk32C;
                            temp_t0 = (COS((temp_t1 << 3) & 0xFF) >> 7) + 0x100;

                            // taking top 2 bits from both?
                            a0 = ((temp_t0 * (((temp_t8 & ~0xFF)) >> 6) & 0xFF) >> 9);
                            a1 = ((temp_t0 * ((temp_t8 << 8) >> 6) & 0xFF) >> 9);

                            func_80127640(
                                &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
                                D_803D5530->position.xPos.w + (a0 << 0x10),
                                D_803D5530->position.zPos.w + (a1 << 0x10),
                                D_803D5530->position.yPos.w + ((D_803D5524->unkBA * 3) * 0x4000),
                                (temp_t1 << 3) & 0xFF,
                                FTOFIX32(1.0) / 4,
                                FTOFIX32(1.0) / 4,
                                FTOFIX32(1.0) / 4,
                                0,
                                0);
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gDPSetPrimColor(D_801D9E88++, 0, 0, ((spD8 << 5) + 0x40), ((spD8 << 5) + 0x40), 0, 0xFF);
                            gSPDisplayList(D_801D9E88++, D_04003EB0_EB460);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                    }
                }
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
                D_803D552C->unk35A = -2500;
            }
            break;

        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4CF8_7C63A8, D_803B4D04_7C63B4, D_803B4D10_7C63C0, D_803B4D24_7C63D4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4CF8_7C63A8, D_803B4D04_7C63B4, D_803B4D10_7C63C0, D_803B4D54_7C6404);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_15 = D_803F2AA2, (temp_v0_15 == 0)) || (temp_v0_15 == 2) || ((temp_v0_15 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
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

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.4f);
            func_8038C484_79DB34(2, 1, 3, -0.18f, 0);
            if ((D_803D552C->unk366 != MOVEMENT_MODE_DEACTIVATED) && (D_803D552C->unk366 != MOVEMENT_MODE_2) && (D_803F2D10.unk0 == 0)) {
                spE6 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
                func_80300130_7117E0(&spE6, &D_803D552C->unk30A, 0x60, -0x100,  3, 3, (D_803D5530->yVelocity.h * 0x10), 4);
            } else {
                spE6 = D_803D552C->unk308;
            }
            D_803D552C->unk308 = spE6;
            func_802C78B0_6D8F60(2, 0xE, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04003C60_EB210);

            var_v1_2 = spE6 << 7;
            if (var_v1_2 > 8000) {
                var_v1_2 = ((var_v1_2 - 8000) >> 1) + 8000;
            }
            if (var_v1_2 < -8000) {
                var_v1_2 = ((var_v1_2 + 8000) >> 1) - 8000;
            }

            D_80203FE0[2].unk4 += var_v1_2 / 32;
            D_80203FE0[1].unk4 += var_v1_2 / 32;

            var_v1_2 = var_v1_2 >> 1;
            D_80203FE0[3].unk4 += var_v1_2 / 32;
            D_80203FE0[7].unk4 += var_v1_2 / 32;
            D_80203FE0[4].unk4 += var_v1_2 / 32;
            D_80203FE0[10].unk4 += var_v1_2 / 32;
            D_80203FE0[26].unk4 += var_v1_2 / 32;

            var_v1_2 = (var_v1_2 + (var_v1_2 >> 1)) ;
            D_80203FE0[19].unk4 += var_v1_2 / 32;
            D_80203FE0[20].unk4 += var_v1_2 / 32;

            // usual scale is 0xD000 => FTOFIX32(0.8125)
            // (0x10000 * 52) / 0xd000 == 64
            func_802C78B0_6D8F60(
                1,
                2,
                ((0x10000 - (spE6 << 4)) * 52) >> 6,
                ((0x10000 - (spE6 << 4)) * 52) >> 6,
                (((spE6 + 0x10) << 5) * 52) >> 6,
                D_803F2ED0,
                0,
                0,
                0,
                D_04003270_EA820);

            func_802C78B0_6D8F60(19, 20, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04002E30_EA3E0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04003470_EAA20); }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 1, 0, D_04003470_EAA20); }
            if ((D_803D552C->unk365 != ATTACK_KANGAROO_4) && (D_803D552C->unk365 != ATTACK_KANGAROO_3)) {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0x00, 0xFF);
                func_802C78B0_6D8F60(3, 7, FTOFIX32(0.8125), FTOFIX32(0.8125), FTOFIX32(0.8125), D_803F2ED0, 0, 0, 0, D_04003F40_EB4F0);
            }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spE2, &spE0);
                func_8031A278_72B928(&D_803D552C->unk326, &spE2, &spE0);
#pragma _permuter sameline start
                spE2 = D_803BD530_7CEBE0.eyes[5][spE2]; spE0 = D_803BD600_7CECB0.eyes[4][spE0];
#pragma _permuter sameline end
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spE2);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04003FF0_EB5A0);
                func_80356BD8_768288(img_eyes_TLUT1_pal, img_eyes5_ci4__png, spE0);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, (D_803F2EC8 * 0x34) >> 6, D_803F2ED0, 0, 0, 0, D_04004010_EB5C0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spDE == 0) || (spDE == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->heading, img_D_01033190_6CA60_i4__png, 0x15, 0x15, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    temp_t9 = D_803D5528->unk3C8.unk2;
    if (temp_t9 != 0) {
        if ((spDE == 0) && (D_803F2EDB != 0)) {
            a0 = D_803D5530->position.xPos.w + ((SIN(D_803D552C->heading) * D_80203FE0[26].unk2) / 16);
            a1 = D_803D5530->position.zPos.w + ((COS(D_803D552C->heading) * D_80203FE0[26].unk2) / 16);
            a2 = D_803D5530->position.yPos.w + ((D_80203FE0[26].unk4 << 0x10) / 32);
            func_802DE914_6EFFC4(
                temp_t9,
                a0,
                a1,
                a2,
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
    if (spDE == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x391, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x28A, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x448, 0x3CF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/kangaroo/func_80370C84_782334.s")
#endif

void func_80372510_783BC0(void) {
    D_803D552C->unk32A = D_803D5544;
    if (SSSV_RAND(2) == 0) {
        D_803D552C->unk365 = ATTACK_KANGAROO_1;
    } else {
        D_803D552C->unk365 = ATTACK_KANGAROO_2;
    }
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_803725A4_783C54(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_KANGAROO_5;
        D_803D552C->unk32C = D_803D552C->heading;
    } else {
        recharge_skill(1);
    }
}

void func_80372604_783CB4(void) {
    D_803D552C->unk32A = D_803D5544;
    if (SSSV_RAND(2) == 0) {
        D_803D552C->unk365 = ATTACK_KANGAROO_1;
    } else {
        D_803D552C->unk365 = ATTACK_KANGAROO_2;
    }
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_80372698_783D48(void) {
    if (D_803D552C->unk365 == ATTACK_NONE) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_KANGAROO_5;
        D_803D552C->unk32C = D_803D552C->heading;
    }
}
