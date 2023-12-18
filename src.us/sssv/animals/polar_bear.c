#include <ultra64.h>
#include "common.h"

extern u8  D_0103AA20_742F0[];
extern u8  D_0103AC20_744F0[];
extern u8  D_0103B440[];
extern u8  D_0103AC40[];


extern s16 D_803B4250_7C5900[];
extern s16 D_803B4280_7C5930[];
extern s16 D_803B42B0_7C5960[];
extern f32 D_803B4338_7C59E8[]; // tbd
extern f32 D_803B4378_7C5A28[]; // tbd
extern u8  D_803B43A0_7C5A50[];
extern u8  D_803B43B0_7C5A60[];
extern s16 D_803B43C0_7C5A70[];
extern s16 D_803B43D8_7C5A88[];
extern s16 D_803B4410_7C5AC0[];

extern u8  D_803B4448_7C5AF8[];
extern u8  D_803B4458_7C5B08[];
extern s16 D_803B4468_7C5B18[];
extern s16 D_803B4480_7C5B30[];
extern s16 D_803B44B8_7C5B68[];

extern Gfx D_01003548[];
extern Gfx D_04002C30_E01F0[];
extern Gfx D_04002D78_E0338[];
extern Gfx D_04003250_E0810[];
extern Gfx D_040034B0_E0A70[];
extern Gfx D_04003740_E0D00[];
extern Gfx D_04003760_E0D20[];
extern Gfx D_04003880_E0E40[];
extern Gfx D_04003630_E0BF0[];


// POLAR_BEAR
#ifdef NON_MATCHING
// reg + stack
void func_80365F10_7775C0(void) {
    struct061 spB8;
    s16 spB6;                                       /* compiler-managed */
    s16 spB4;                                       /* compiler-managed */
    s16 spB2;
    s16 spB0;
    s16 spAE;
    u16 spAC;
    s16 spAA;
    f32 spA4;

    u16 ticks_remaining;
    u8 temp_v0_11;

    if (D_803D5538 == 0) {
        if ((D_803D552C->unk364 == 3) && (D_803D5530->unk162 == 1)) {
            D_803D552C->unk369 = 0;
            D_803D552C->unk364 = 0;
        }
    }

    if ((D_803D5530->unk162 == 3) && (D_803D5524->unk9C != POLAR_BEAR_DEFENDING)) {
        if (D_803D5538 != 0) {
            if (D_803D552C->unk369 == 0) {
                if (D_801E9E8A == 0) {
                    D_803D552C->unk369 = 1;
                }
            } else if (D_803D552C->unk369 == 1) {
                if ((D_801E9E8A != 0) && (D_803D552C->unk36D >= 6)) {
                    D_803D552C->unk369 = 2;
                    func_802DBA58_6ED108(3, D_803D552C);

                    D_803D5530->yVelocity.h = MAX(14, D_803D5530->yVelocity.h + 9);
                    play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
                }
            } else if (D_803D5530->unk54 & 8) {
                D_803D552C->unk369 = 0;
            }
        } else {
            if ((D_803D552C->unk369 == 1) && (D_803D552C->yVelocity.h < -2)) {
                D_803D552C->unk369 = 2;
                func_802DBA58_6ED108(3, D_803D552C);
                D_803D5530->yVelocity.h = MAX(14, D_803D5530->yVelocity.h + 9);
                play_sound_effect_at_location(SFX_UNKNOWN_32, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
            }
            if ((D_803D552C->unk369 == 1) && (D_803D5530->unk54 & 8)) {
                D_803D552C->unk369 = 0;
            }
        }
    } else if (D_803D552C->unk360 == 0) {
        D_803D552C->unk369 = 0;
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spB2 = 0;
        D_803F2EDD = 0;
    } else {
        spB2 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x17E8, 5, 0xB4, 0xB4, 0xB4, 2, CHECK_SEGMENT == 0);
    }

block_39:
    if (spB2 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0x1C, 0x1E, 8);

        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);

        if (D_803D5524->unk9C == POLAR_BEAR_DEFENDING) {
            D_803F2EBC = D_803F2EC0 = D_803F2EC4 = 0x10000;
        }
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        spB0 = 0;
        spAE = 0x100;

        switch (D_803D5524->unk9C) {
        case POLAR_BEAR:
            switch (D_803D552C->unk365) {
            case ATTACK_POLAR_BEAR_2:
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                spB0 = ticks_remaining;
                if (ticks_remaining < 9) {
                    func_80368840_779EF0(spB0);
                    if (ticks_remaining > 4) {
                        spAE = (8 - ticks_remaining) * 64;
                    }
                } else {
                    load_animal(POLAR_BEAR_DEFENDING);
                    D_803D552C->unk365 = ATTACK_NONE;
                    D_803D552C->unk308 = D_803D552C->unk302;
                }
                break;
            case ATTACK_POLAR_BEAR_3:
                ticks_remaining = (D_803D5544 - D_803D552C->unk32A);
                spB0 = 32 - ticks_remaining;
                if (ticks_remaining < 33) {
                    func_80368840_779EF0(spB0);
                    if (ticks_remaining < 16) {
                        spAE = ticks_remaining * 16;
                    }
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                }
                break;
            default:
                D_803D552C->unk365 = ATTACK_NONE;
                break;
            }
            break;
        case POLAR_BEAR_DEFENDING:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            D_803F2F00 = 0;
            func_802B9130_6CA7E0(&spB8, 0x1DE, 0xEF, 0x344, 0x2F);
            func_802BF3C0_6D0A70(0x344, 0x2F,    0, 0x64,     0, 0x80, D_803B4250_7C5900, D_803B4280_7C5930, &D_803B42B0_7C5960,
                                 0x344, 0x2F, 0x64,     0, 0x80,    0, D_803B4250_7C5900, D_803B4280_7C5930, D_803B42B0_7C5960,
                                 &spB8);
            func_802B964C_6CACFC();
            func_802C58E4_6D6F94(0x77, 0x1DE);
            func_8038CCF0_79E3A0(0x77, 0x14, -1, -1, -1, -1);
            func_802C7600_6D8CB0(0x3BC, 8);

            D_80203FE0[19].unk2 -= (spB0 * 0x3BC) >> 5;
            D_80203FE0[20].unk2 -= (spB0 * 0x3BC) >> 5;

            D_80203FE0[3].unk4 += (spB0 * 0x344) >> 5;
            D_80203FE0[7].unk4 += (spB0 * 0x344) >> 5;

            D_80203FE0[4].unk4 += (spB0 * 0x344) >> 5;
            D_80203FE0[10].unk4 += (spB0 * 0x344) >> 5;

            D_80203FE0[5].unk4 += (spB0 * 0x344) >> 5;
            D_80203FE0[13].unk4 += (spB0 * 0x344) >> 5;

            D_80203FE0[6].unk4 += (spB0 * 0x344) >> 5;
            D_80203FE0[16].unk4 += (spB0 * 0x344) >> 5;

            if (D_803D5524->unk9C != POLAR_BEAR_DEFENDING) {

                switch (D_803F2F00) {                /* irregular */
                case 1:
                    func_80374660_785D10(-0xE, 0, 0x9C4);
                    break;
                case 2:
                    func_80374660_785D10(0xE, 0, 0x9C4);
                    break;
                case 3:
                    func_80374660_785D10(-0xE, 0, 0x9C4);
                    break;
                case 4:
                    func_80374660_785D10(0xE, 0, 0x9C4);
                    break;
                }
            }
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B43A0_7C5A50, D_803B43B0_7C5A60, D_803B43C0_7C5A70, D_803B43D8_7C5A88);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B43A0_7C5A50, D_803B43B0_7C5A60, D_803B43C0_7C5A70, D_803B4410_7C5AC0);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_11 = D_803F2AA2, (temp_v0_11 == 0)) || (temp_v0_11 == 2) || ((temp_v0_11 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            if (D_803D5524->unk9C == POLAR_BEAR) {
                spAA = D_803D552C->unk302;
            } else {
                spAA = D_803D552C->unk308;
            }
            if (D_803D552C->unk364 == 3) {
                ticks_remaining = (D_803D5544 - D_803D552C->unk334);
                spA4 = D_803B4338_7C59E8[MIN(ticks_remaining, 15)];
                create_particle_effect(
                    (SSSV_RAND(64) + D_803D5530->position.xPos.h) - 0x20,
                    (SSSV_RAND(64) + D_803D5530->position.zPos.h) - 0x20,
                    (SSSV_RAND(64) + D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1)) - 0x20,
                    0x15,
                    0,
                    0,
                    0,
                    0x1E,
                    GPACK_RGBA5551(200, 200, 200, 1), // grey
                    GPACK_RGBA5551(248, 248, 248, 1), // white
                    0);
            } else if (D_803D552C->unk364 == 4) {
                spAC = D_803D5544 - D_803D552C->unk334;
                func_802DC2AC_6ED95C(10);
                spA4 = D_803B4378_7C5A28[spAC];
            } else {
                spA4 = 0.0f;
            }

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (s16) (s32) -spAA, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            if (spA4 != 0.0) {
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.0f, 0.0f, 128.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], spA4, 1.0f, 0.0f, 0.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.0f, 0.0f, -128.0f);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }

            switch (D_803D5524->unk9C) {                   /* switch 2; irregular */
            case POLAR_BEAR:                                /* switch 2 */
                if ((D_803D552C->unk365 == ATTACK_POLAR_BEAR_2) || (D_803D552C->unk365 == ATTACK_POLAR_BEAR_3)) {
                    func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x99) >> 6, (D_803F2EC0 * 0x99) >> 6, (D_803F2EC4 * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04002D78_E0338);
                } else {
                    func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x99) >> 6, (D_803F2EC0 * 0x99) >> 6, (D_803F2EC4 * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04002C30_E01F0);
                }
                func_802C78B0_6D8F60(0x13, 0x14, (((s32) (spAE * D_803F2EC8) >> 8) * 0x99) >> 6, (((s32) (spAE * D_803F2EC8) >> 8) * 0x99) >> 6, (((s32) (spAE * D_803F2EC8) >> 8) * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04003250_E0810);

                gDPSetPrimColor(D_801D9E88++, 0, 0, 0x14, 0x14, 0x14, 0xFF);
                gSPDisplayList(D_801D9E88++, D_01003548);

                func_802C78B0_6D8F60(3, 7, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, 0, 0, 0, D_040034B0_E0A70);
                func_802C78B0_6D8F60(5, 13, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, 0, 0, 0, D_040034B0_E0A70);

                gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
                gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

                func_802C78B0_6D8F60(4, 10, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_040034B0_E0A70);
                func_802C78B0_6D8F60(6, 16, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, (s16) 0, (u8) 1, (u8) 0, D_040034B0_E0A70);
                if (D_803F2EDD == 0) {
                    func_8031A150_72B800(D_803D552C->unk326++, &spB6, &spB4);
                    func_8031A278_72B928(&D_803D552C->unk326, &spB6, &spB4);
#pragma _permuter sameline start
                    spB6 = D_803BD5B2_7CEC62[spB6]; spB4 = D_803BD66A_7CED1A[spB4];
#pragma _permuter sameline end
                    func_80356BD8_768288(&D_01000CA0, &D_01002100, spB6);
                    func_802C78B0_6D8F60(19, 20, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, 0, 0, 0, D_04003740_E0D00);
                    func_80356BD8_768288(&D_01000CA0, &D_01002100, spB4);
                    func_802C78B0_6D8F60(19, 20, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, (spAE * 0x9900) >> 6, D_803F2ED0, 0, 0, 0, D_04003760_E0D20);
                }
                break;
            case POLAR_BEAR_DEFENDING:                                 /* switch 2 */
                func_80368840_779EF0(32);
                func_802C78B0_6D8F60(2, 1, (s32) (D_803F2EBC * 0x99) >> 6, (s32) (D_803F2EC0 * 0x99) >> 6, (s32) (D_803F2EC4 * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04002D78_E0338);
                if (D_803D5540 < 0x50) {
                    D_80203FE0[19].unk0 = 0;
                    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 - 0xEF;
                    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 - 0x2CD;
                    D_80203FE0[20].unk0 = 0;
                    D_80203FE0[20].unk2 = D_80203FE0[1].unk2;
                    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
                    if (D_803F2EDD == 0) {
                        func_8031A150_72B800(D_803D552C->unk326++, &spB6, &spB4);
                        func_8031A278_72B928(&D_803D552C->unk326, &spB6, &spB4);
#pragma _permuter sameline start
                        spB6 = D_803BD5B2_7CEC62[spB6]; spB4 = D_803BD66A_7CED1A[spB4];
#pragma _permuter sameline end
                        func_80356BD8_768288(&D_01000CA0, &D_01002100, spB6);
                        func_802C78B0_6D8F60(0x13, 0x14, 0x1CB00, 0x1CB00, 0x1CB00, D_803F2ED0, 0, 0, 0, D_04003740_E0D00);
                        func_80356BD8_768288(&D_01000CA0, &D_01002100, spB4);
                        func_802C78B0_6D8F60(0x13, 0x14, 0x1CB00, 0x1CB00, 0x1CB00, D_803F2ED0, 0, 0, 0, D_04003760_E0D20);
                    }
                }
                if (D_803D5540 != 0) {
                    if ((D_803D5530->state == 2) && (D_803D5530->xVelocity.h == 0) && (D_803D5530->zVelocity.h == 0)) {
                        if (ABS(D_803D5530->yVelocity.h) < 6) {
                            if ((D_803D5540 == 0x78) || (D_803D5540 == 0xAA)) {
                                play_sound_effect_at_location(SFX_UNKNOWN_24, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
                                create_particle_effect(
                                    D_803D5530->position.xPos.h,
                                    D_803D5530->position.zPos.h,
                                    D_803D5530->position.yPos.h + D_803D5530->unk42,
                                    0x26,
                                    0,
                                    0,
                                    (func_8012826C() + 0x30000) & 0x7FFF,
                                    0xA,
                                    GPACK_RGBA5551(0, 0, 0, 1),
                                    GPACK_RGBA5551(0, 0, 0, 1),
                                    0);
                            }
                            if ((D_803D5540 == 0x91) || (D_803D5540 == 0xC3)) {
                                play_sound_effect_at_location(SFX_UNKNOWN_25, 0x5000, 0, D_803D5530->position.xPos.h, (s16) (s32) D_803D5530->position.zPos.h, (s16) (s32) D_803D5530->position.yPos.h, 1.0f);
                                create_particle_effect(
                                    D_803D5530->position.xPos.h,
                                    D_803D5530->position.zPos.h,
                                    D_803D5530->position.yPos.h + D_803D5530->unk42,
                                    0x26,
                                    0,
                                    0,
                                    (func_8012826C() + 0x30000) & 0x7FFF,
                                    0xA,
                                    GPACK_RGBA5551(0, 0, 0, 1),
                                    GPACK_RGBA5551(0, 0, 0, 1),
                                    0);
                            }
                        }
                    }
                }
                break;
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        } else {
            // need this apparently?
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spB2 == 0) || (spB2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (s16) (D_803D552C->position.yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, (s16) 0x22, (s16) 0x22, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (spB2 == 0) {
        D_80203FE0[19].unk0 = D_80203FE0[1].unk0 + ((D_80203FE0[19].unk0 - D_80203FE0[1].unk0) * 3);
        D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + ((D_80203FE0[19].unk2 - D_80203FE0[1].unk2) * 3);
        D_80203FE0[19].unk4 += 0x77;

        D_80203FE0[33].unk0 = D_80203FE0[1].unk0 + ((D_80203FE0[33].unk0 - D_80203FE0[1].unk0) * 3);
        D_80203FE0[33].unk2 = D_80203FE0[1].unk2 + ((D_80203FE0[33].unk2 - D_80203FE0[1].unk2) * 3);
        D_80203FE0[33].unk4 += 0x77;
        func_803034D0_714B80(D_803D552C, 0x59A, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x2CD, 0);
        D_803D5530->unkC4[0].unk8.h += 22;
        D_803D5530->unkC4[1].unk8.h += 22;
        D_803D5530->unkC4[2].unk8.h += 22;
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x3BC, 0x344);
    }
    if ((D_803D5538 == 0) && (D_803D5524->unk9C == POLAR_BEAR_DEFENDING)) {
        if (D_803D552C->unk2EC == 0) {
            load_animal(POLAR_BEAR);
            func_802A4390_6B5A40();
            func_802B2834_6C3EE4();
            D_803D552C->unk32A = D_803D5544;
            D_803D552C->unk365 = ATTACK_POLAR_BEAR_3;
        } else if (D_803D552C->unk2EC > 0) {
            D_803D552C->unk2EC--;
        }
    }

    if ((D_803D5524->unk9C == POLAR_BEAR_DEFENDING)) {
        if ((((D_803D552C->unk366 == 2)) || (D_803D552C->unk366 == 5))) {
            load_animal(POLAR_BEAR);
            func_802A4390_6B5A40();
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_80365F10_7775C0.s")
#endif

void func_803677C4_778E74(void) {
    struct061 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 var_t0;
    s16 var_t1;

    s32 pad;

    u8 var_a2;
    u8 var_a0;
    s16 var_v0;
    u16 ticks_remaining;
    s16 pad2;
    s8 var_v1;
    u8 temp_v0_8;

    var_a0 = D_803D552C->unk310;
    var_v1 = D_803D552C->unk310 >> 8;

    if (D_803D5538 != 0) {
        var_v0 = D_801D9ED8.unkFFDA;
    } else {
        var_v0 = MIN(D_803D552C->unk368 >> 2, 24);
    }

    switch (var_v0) {
    case 0: // L80367848_778EF8
        var_v0 = -5;
        var_a2 = 0;
        break;
    case 1: // L80367858_778F08
        var_v0 = 2;
        var_a2 = 0;
        break;
    case 2: // L80367868_778F18
        var_v0 = 5;
        var_a2 = 10;
        break;
    case 3: // L80367878_778F28
        var_v0 = 8;
        var_a2 = 20;
        if (var_a0 < 70) {
            var_a0 = 70;
        }
        break;
    case 4: // L80367894_778F44
    default:
        var_v0 = 11;
        var_a2 = 30;
        if (var_a0 < 80) {
            var_a0 = 80;
        }
        break;
    }

    if (var_v1 < var_v0) {
        var_v1 = MIN(var_v1 + 5, var_v0);
    } else if (var_v0 < var_v1) {
        var_v1 = MAX(var_v1 - 1, var_v0);
    }

    if (var_v1 > 3) {
        var_v1 -= 1;
    }

    if (var_v1 > 6) {
        var_v1 -= 1;
    }
    if (var_v1 < -3) {
        var_v1 += 1;
    }
    if (var_v1 < -6) {
        var_v1 += 1;
    }

    if ((var_a2 + 80) < var_a0) {
        var_v1 -= ((var_a0 - (var_a2 + 80))) / 5;
    }
    if (var_a0 < 20) {
        var_v1 += (20 - var_a0) / 2;
    }

    var_a0 = var_a0 + var_v1;
    D_803D552C->unk310 = ((var_v1 & 0xFF) << 8) | var_a0;

    if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                SFX_UNKNOWN_129,
                ((var_a0 / 250.0) + 0.4) * 16384.0,
                0,
                (var_a0 / 300.0) + 0.2,
                D_803D5530->position.xPos.h,
                D_803D5530->position.zPos.h,
                D_803D5530->position.yPos.h);
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        D_803F2EDD = sp92 = 0;
    } else {
        sp92 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x17E8, 5, 0xB4, 0xB4, 0xB4, 2, CHECK_SEGMENT == 0);
    }

    if (sp92 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0x1C, 0x1E, 8);
        D_803F2EBC = FTOFIX32(1.0) + ((D_803F2EBC - FTOFIX32(1.0)) >> 2);
        D_803F2EC0 = FTOFIX32(1.0) + ((D_803F2EC0 - FTOFIX32(1.0)) >> 2);
        D_803F2EC4 = FTOFIX32(1.0) + ((D_803F2EC4 - FTOFIX32(1.0)) >> 2);
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);

        if (D_803F2D10.unk0 == 0) {
            if (D_803D552C->unk308 < 0) {
                D_803D552C->unk308++;
            } else if (D_803D552C->unk308 > 0) {
                D_803D552C->unk308--;
            }
        }

        if (D_803D552C->unk365 == 0x1A) {
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803D5528->unk3C0.unk0 = 0;
            if (ticks_remaining < 6) {
                D_803D552C->unk308 -= 3;
                if (ticks_remaining == 5) {
                    fire_cannonball_1(0x11, 0x5A, 0, 0x34, 0x17, 0, 2, 0x1E);
                    D_803D552C->unk308 = MIN(0x2E, D_803D552C->unk308 + 0x1E);
                    func_803421E0_753890(0x14);
                    play_sound_effect_at_location(SFX_UNKNOWN_27, 0x7FFF, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
            } else {
                D_803D552C->unk365 = 0;
            }
        } else {
            D_803D552C->unk365 = 0;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp98, 0x1DE, 0x219, 0x344, 0);
            func_802C1830_6D2EE0(0x2CD, &sp98);
            func_802B964C_6CACFC();
            func_802C58E4_6D6F94(0x77, 0x1DE);

            D_80203FE0[19].unk2 -= (D_803D552C->unk308 * 956) >> 5;
            D_80203FE0[20].unk2 -= (D_803D552C->unk308 * 956) >> 5;
            func_802C7600_6D8CB0(0x3BC, 8);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B4448_7C5AF8, D_803B4458_7C5B08, D_803B4468_7C5B18, D_803B4480_7C5B30);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B4448_7C5AF8, D_803B4458_7C5B08, D_803B4468_7C5B18, D_803B44B8_7C5B68);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_8 = D_803F2AA2, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w,  (-D_803D552C->unk302) & 0xFF, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x99) >> 6, (D_803F2EC0 * 0x99) >> 6, (D_803F2EC4 * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04002C30_E01F0);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x99) >> 6, (D_803F2EC8 * 0x99) >> 6, (D_803F2EC8 * 0x99) >> 6, D_803F2ED0, 0, 0, 0, D_04003250_E0810);
            load_1_tile(D_0103AC20_744F0, D_0103AA20_742F0);

            var_t0 = (D_803D552C->unk30A >> 8) & 0xFF;
            var_t1 = D_803D552C->unk30A & 0xFF;
            if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1)) {
                if ((D_803D5530->unk4A == 0) && (D_803F2D10.unk0 == 0)) {
                    switch (D_803D5530->state) {
                    case 0x16:
                    case 0xCA:
                        var_t0 += 2;
                        var_t1 += 2;
                        break;
                    case 0x17:
                    case 0xCB:
                        var_t0 += 5;
                        var_t1 += 5;
                        break;
                    case 0x18:
                    case 0xCC:
                        var_t0 -= 2;
                        var_t1 -= 2;
                        break;
                    }
                }
            }

            var_v0 = D_803D552C->unk302 - D_803D552C->yRotation;
            if (var_v0 != 0) {
                if (var_v0 < 0) {
                    var_v0 += 0x100;
                }
                if (var_v0 < 0x80) {
                    var_t0 -= 3;
                    var_t1 += 3;
                } else {
                    var_t0 += 3;
                    var_t1 -= 3;
                }
            }

            // max 127
            var_t0 = var_t0 & 0x7F;
            var_t1 = var_t1 & 0x7F;

            D_803D552C->unk30A = (var_t0 << 8) | var_t1;

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, var_t0, 0, 0);
            func_802C78B0_6D8F60(8, 0xE, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003880_E0E40);

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, var_t1, 0, 0);
            func_802C78B0_6D8F60(0xB, 0x11, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003880_E0E40);

            func_80356D84_768434(D_0103B440, D_0103AC40);

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*63, 4*31);
            gDPSetTileSize(D_801D9E88++, 1, 0, 0, 4*63, 4*31);

            func_802C78B0_6D8F60(8, 0xE, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003630_E0BF0);
            func_802C78B0_6D8F60(0xB, 0x11, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003630_E0BF0);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, (u16*)&sp96, (u16*)&sp94);
                func_8031A278_72B928(&D_803D552C->unk326, &sp96, &sp94);
#pragma _permuter sameline start
                sp96 = D_803BD5B2_7CEC62[sp96];sp94 = D_803BD66A_7CED1A[sp94];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01000CA0, D_01002100, sp96);
                func_802C78B0_6D8F60(0x13, 0x14, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003740_E0D00);
                func_80356BD8_768288(D_01000CA0, D_01002100, sp94);
                func_802C78B0_6D8F60(0x13, 0x14, 0x26400, 0x26400, 0x26400, D_803F2ED0, 0, 0, 0, D_04003760_E0D20);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp92 == 0) || (sp92 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->unk302, (Gfx*)D_01033190, (s16) 0x28, (s16) 0x1F, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (sp92 == 0) {
        D_80203FE0[19].unk0 = ((D_80203FE0[19].unk0 - D_80203FE0[1].unk0) * 4) + D_80203FE0[1].unk0;
        D_80203FE0[19].unk2 = ((D_80203FE0[19].unk2 - D_80203FE0[1].unk2) * 4) + D_80203FE0[1].unk2;
        D_80203FE0[19].unk4 += 0x166;
        D_80203FE0[33].unk0 = ((D_80203FE0[33].unk0 - D_80203FE0[1].unk0) * 4) + D_80203FE0[1].unk0;
        D_80203FE0[33].unk2 = ((D_80203FE0[33].unk2 - D_80203FE0[1].unk2) * 4) + D_80203FE0[1].unk2;
        D_80203FE0[33].unk4 += 0x166;
        func_80303D00_7153B0(D_803D552C, 0x433, 0x611);

        if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
            D_803D5530->unkC4[0].unk8.h -= 0x1D;
        }
        D_803D5530->unkC4[1].unk0.h = D_803D5530->unkC4[0].unk0.h;
        D_803D5530->unkC4[1].unk4.h = D_803D5530->unkC4[0].unk4.h;
        D_803D5530->unkC4[1].unk8.h = D_803D5530->unkC4[0].unk8.h;
        D_803D5530->unkC4[1].unkC = D_803D5530->unkC4[0].unkC;

        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x2CD, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x3BC, 0x344);
    }
}

// jump-thump animation?
void func_80368840_779EF0(s16 arg0) {
    s32 pad;

    f32 temp_s1f;
    f32 temp_s7f;
    f32 temp_s2f;

    s16 temp_s1;
    s16 temp_s2;
    Vtx *phi_a1;
    Vtx *sp44;
    Vtx *tmp;
    s16 temp_s3;
    s16 temp_s7;
    s16 temp_v0;

    s16 i;

    sp44 = (Vtx*)(D_801D9EC4 + SEGMENT_OFFSET(D_04002930_DFEF0));
    phi_a1 = tmp = (Vtx*)(D_801D9EC4 + SEGMENT_OFFSET(D_04002630_DFBF0));

    for (i = 0; i < 48; i++) {
        temp_s1 = sp44[i].v.ob[0];
        temp_s2 = sp44[i].v.ob[1];
        temp_s3 = sp44[i].v.ob[2];

        temp_s1f = temp_s1;
        temp_s2f = temp_s2;
        temp_s7f = temp_s7 = temp_s3 + ((temp_s3 + 75) / 2);

        temp_v0 = (s32) sqrtf((temp_s1f * temp_s1f) + (temp_s2f * temp_s2f) + (temp_s7f * temp_s7f));

        phi_a1[i].v.ob[0] = ((((s16)  ((temp_s1 * 50) / temp_v0)       * arg0) + (temp_s1 * (32 - arg0))) >> 5);
        phi_a1[i].v.ob[1] = ((((s16)  ((temp_s2 * 50) / temp_v0)       * arg0) + (temp_s2 * (32 - arg0))) >> 5);
        phi_a1[i].v.ob[2] = ((((s16) (((temp_s7 * 50) / temp_v0) - 15) * arg0) + (temp_s3 * (32 - arg0))) >> 5);
    }
}

// polar bear
void func_80368AC4_77A174(void) {
    if ((D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) &&
        (D_803D552C->unk365 != ATTACK_POLAR_BEAR_3)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_2;
    }
}

// polar bear defending
void func_80368B04_77A1B4(void) {
    if ((D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) &&
        (D_803D552C->unk365 != ATTACK_POLAR_BEAR_3)) {
        load_animal(POLAR_BEAR);
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_3;
        func_802A4390_6B5A40();
        func_802B2834_6C3EE4();
    }
}

void func_80368B78_77A228(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_POLAR_BEAR_1;
}

// polar tank
void func_80368BA0_77A250(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0x599, 0xB4, D_803D5530, 50, OBJECT_MINE);
        play_sound_effect_at_location(SFX_UNKNOWN_38, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    } else {
        recharge_skill(1);
    }
}

void polar_tank_drop_mine(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0x599, 0xDC, D_803D5530, 50, OBJECT_MINE);
        play_sound_effect_at_location(SFX_UNKNOWN_38, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
    }
}

void polar_tank_fire_cannon(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_POLAR_BEAR_1;
}

void polar_bear_jump_thump(void) {
    if (D_803D5530->unk162 == 1) {
        func_802A467C_6B5D2C(0);
        D_803D552C->unk369 = 1;
    }
}

void func_80368D60_77A410(s16 arg0) {
    if (arg0 == 0) {
        D_803D552C->unk2EC = 0;
    } else if (D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_2;
    } else {
        D_803D552C->unk2EC = arg0;
    }
}
