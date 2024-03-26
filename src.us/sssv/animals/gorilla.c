#include <ultra64.h>
#include "common.h"

extern u8 D_803B5514_7C6BC4[];
extern u8 D_803B54FC_7C6BAC[];
extern u8 D_803B54E4_7C6B94[];

extern u8 D_803B5330_7C69E0[];
extern u8 D_803B5344_7C69F4[];

extern s16 D_803B5358_7C6A08[];
extern s16 D_803B5378_7C6A28[];

extern s16 D_803B53C0_7C6A70[];
extern s16 D_803B5408_7C6AB8[];
extern s16 D_803B5450_7C6B00[];

extern s16 D_803B54B4_7C6B64[];
extern s16 D_803B54CC_7C6B7C[];
extern s16 D_803B552C_7C6BDC[];
extern s16 D_803B5544_7C6BF4[];

extern Gfx D_040044B0_F5510[];
extern Gfx D_04004820_F5880[];
extern Gfx D_04004A50_F5AB0[];
extern Gfx D_04004B20_F5B80[];
extern Gfx D_04004BB0_F5C10[];
extern Gfx D_04004C40_F5CA0[];
extern Gfx D_04004CB0_F5D10[];
extern Gfx D_04004D10_CC740[];
extern Gfx D_04004DE0_F5E40[];
extern Gfx D_04004F30_F5F90[];
extern Gfx D_04004FF0_F6050[];


// GORILLA
void update_gorilla(void) {
    u8 temp_v0_18;
    s16 spFA; // pad
    s16 i;    // spF8
    u8  temp_t6_2;        // F8
    Animal *temp_v1;      // F4
    s16 pad;              // F2

    s16 spF0;
    s16 spEE;
    s16 spEC;
    s16 spEA;
    s16 pad5;             // E8
    u16 ticks_remaining;  // E6
    s16 pad3;             // E4

    s32 spE0;
    s32 spDC;
    s32 spD8;
    s16 spD6;
    u16 rand; // spD2
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s16 spC6;
    s16 spC4;
    s16 spC2;

    s16 var_v0_7;   // BE
    s16 temp_t6;    // BC
    s32 pad2;       // B8
    s32 temp_t9;    // B4
    s32 temp_t7;    // B0
    s32 temp_t7_2;  // AC
    Animal *spA8;
    s16 *spA4;
    s16 temp_v0_14; // C0

    spC2 = 0;
    spC6 = 0x2B;
    spC4 = 0x35;

    if (D_803D552C->unk320 != NULL) {
        if (D_803D552C->unk320->unk40 > 0xB00) {
            spA4 = D_803B5514_7C6BC4;
        } else if (D_803D552C->unk320->unk40 > 0x700) {
            spA4 = D_803B54FC_7C6BAC;
        } else {
            spA4 = D_803B54E4_7C6B94;
        }
    } else {
        spA4 = D_803B54E4_7C6B94;
    }

    if (D_803D5530->unk162 == 3) {
        if (D_803D5538 != 0) {
            if (D_803D552C->unk369 == 0) {
                if (D_801E9E8A == 0) {
                    D_803D552C->unk369 = 1;
                }
            } else if (D_803D552C->unk369 == 1) {
                if ((D_801E9E8A != 0) && (D_803D552C->unk320 == NULL) && ((((D_803D552C->unk36D >= 8))) || (D_803D552C->unk36D == 0))) {
                    D_803D552C->unk369 = 2;

                    D_803D5530->yVelocity.h = MAX(9, MIN(12, D_803D5530->yVelocity.h + 9));

                    func_802DBA58_6ED108(0xF, D_803D552C);
                    for (i = 0; i < 20; i++) {
                        rand = func_8012826C();
                        temp_t7 = (rand & 0x1F) << 1;
                        temp_t9 = (rand & 0x3E0) >> 4;
                        temp_t7_2 = (rand & 0xFC00) >> 9;
                        create_particle_effect(
                            (D_803D5530->position.xPos.h + temp_t7) - 0x20,
                            (D_803D5530->position.zPos.h + temp_t9) - 0x20,
                            (D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1) + temp_t7_2) - 0x40,
                            0x15,
                            D_803D5530->xVelocity.w + ((temp_t7 - 0x20) << 0xC),
                            D_803D5530->zVelocity.w + ((temp_t9 - 0x20) << 0xC),
                            D_803D5530->yVelocity.w + ((temp_t7_2 - 0x40) << 0xC),
                            0x1E,
                            0x681F,
                            0x8065,
                            0);
                    }
                }
            } else if (D_803D5530->unk54.unk0 & 1) {
                D_803D552C->unk369 = 0;
            }
        } else if ((D_803D552C->unk369 == 1) && (D_803D552C->yVelocity.h < -2)) {
            D_803D552C->unk369 = 2;
            D_803D5530->yVelocity.h = MAX(14, D_803D5530->yVelocity.h + 9);
            func_802DBA58_6ED108(0xF, D_803D552C);
            for (i = 0; i < 20; i++) {
                rand = func_8012826C();
                temp_t7 = (rand & 0x1F) << 1;     // 0000 0000 0001 1111 << 1 -> 0000 0000 0011 1110
                temp_t9 = (rand & 0x3E0) >> 4;    // 0000 0011 1110 0000 >> 4 -> 0000 0000 0011 1110
                temp_t7_2 = (rand & 0xFC00) >> 9; // 1111 1100 0000 0000 >> 9 -> 0000 0000 0111 1110
                create_particle_effect(
                    (D_803D5530->position.xPos.h + temp_t7) - 0x20,
                    (D_803D5530->position.zPos.h + temp_t9) - 0x20,
                    (D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1) + temp_t7_2) - 0x40,
                    0x15,
                    D_803D5530->xVelocity.w + ((temp_t7 - 0x20) << 0xC),
                    D_803D5530->zVelocity.w + ((temp_t9 - 0x20) << 0xC),
                    D_803D5530->yVelocity.w + ((temp_t7_2 - 0x40) << 0xC),
                    0x1E,
                    0x681F,
                    0x8065,
                    0);
            }
        }
    } else if (D_803D552C->unk360 == 0) {
        D_803D552C->unk369 = 0;
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spEA = 0;
        D_803F2EDD = 0;
    } else {
        spEA = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x1340, 6, 0x49, 0, 0x54, 1, CHECK_SEGMENT == 0);
    }

    if (spEA == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0x96);

        if (D_803F2ECC == 0) {
            if ((D_803D5544 & 0x7FF) < 0x100) {
                if ((D_803D552C->unk366 != 2) && (D_803D552C->unk366 != 5)) {
                    if ((D_803D5530->state != 0x8D) && (D_803D5530->state != 0xDD) && (D_803D5530->state != 0x8E) && (D_803D5530->state != 0x90) && (D_803D5530->state != 0x8F)) {
                        temp_t6 = (D_803D5544 & 0x7FF);
                        if (temp_t6 < 8) {
                            D_803F2ECC = temp_t6 << 2;
                            D_803F2ECE = 5;
                        } else if (temp_t6 > 0xF8) {
                            D_803F2ECC = (0x100 - temp_t6) << 2;
                            D_803F2ECE = 5;
                        } else {
                            D_803F2ECC = MIN(32, ((SIN(D_803D5540 << 4) >> 7) >> 4) + 0x11);
                            D_803F2ECE = 6;
                            if (((temp_t6 & 7) == 3) && (D_803D552C->unk320 == NULL) && (D_803D552C->unk365 == ATTACK_NONE)) {
                                play_sound_effect_at_location(
                                    0x3C,
                                    0x3C00,
                                    0,
                                    D_803D5530->position.xPos.h,
                                    D_803D5530->position.zPos.h,
                                    D_803D5530->position.yPos.h,
                                    (func_8012826C() / 655360.0) + 0.5);
                            }
                        }
                    }
                }
            }
        }

        if (D_803D5530->state == 0xDD) {
            if (ABS(D_801D9ED8.unkFFDE) > 7) { // D_801E9EB6
                D_803D552C->unk30C = (D_803D552C->unk30C + 4) & 0x3F;
            } else {
                D_803D552C->unk30C = 0;
            }
            D_803F2ECC = MIN(32, ((COS(D_803D552C->unk30C << 2) >> 7) >> 4) + 0x11);
            D_803F2ECE = 4;
        }

        if ((D_803D552C->unk320 != NULL) && (D_803D552C->unk320->unk26C != 0)) {
            D_803D552C->unk320 = NULL;
            D_803D552C->unk365 = ATTACK_BEAR_3;
            D_803D552C->unk32A = D_803D5544;
        }

        switch (D_803D552C->unk365) {
        default:
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        case ATTACK_GRAB:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803F2ECE = 7;
            D_803F2ECC = ticks_remaining << 2;
            if (ticks_remaining == 8) {
                if (D_803D5538 != 0) {
                    D_803D552C->unk320 = func_803215DC_732C8C(0x32, 0x32);
                } else {
                    D_803D552C->unk320 = func_803218D8_732F88(D_803D552C->unk330);
                }

                if (D_803D552C->unk320 == NULL) {
                    D_803D552C->unk365 = ATTACK_HOLD;
                    D_803D552C->unk32A = D_803D5544;
                } else {
                    if (D_803D5530->state < 8) {
                        func_802A4390_6B5A40();
                    }
                    D_803D552C->unk365 = ATTACK_NONE;
                }
            }
            break;
        case ATTACK_HOLD:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803F2ECE = 7;
            D_803F2ECC = 0x20 - (ticks_remaining << 1);
            if (ticks_remaining == 16) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_BEAR_2:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining == 0x16) {
                play_sound_effect_at_location(0x3D, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            }
            if (ticks_remaining < 0x14) {
                temp_v0_14 = ticks_remaining << 2;
                spC4 = spC4 + (((SIN(temp_v0_14) >> 7) * spC6) >> 8); // different regalloc with +=
                spC6 = (((COS(temp_v0_14) >> 7) * spC6) >> 8);
                D_803F2ECE = 8;
                D_803F2ECC = MAX(1, (ticks_remaining << 5) / 20);
            } else if (ticks_remaining < 0x19) {
                temp_v0_14 = (40 - ticks_remaining) << 2;
                spC4 = spC4 + (((SIN(temp_v0_14) >> 7) * spC6) >> 8); // different regalloc with +=
                spC6 = (((COS(temp_v0_14) >> 7) * spC6) >> 8);
                D_803F2ECE = 8;
                D_803F2ECC = MAX(1, 32 - (((ticks_remaining << 5) - 0x280) / 4));

                if (ticks_remaining == 22) {
                    spA8 = D_803D552C->unk320;
                    if (D_803D5530->state < 8) {
                        func_802A4390_6B5A40();
                    }

                    func_80321920_732FD0(D_803D552C->unk320, 0x14, 2);
                    spA8->newPosition.xPos.w += spA8->xVelocity.w;
                    spA8->newPosition.zPos.w += spA8->zVelocity.w;
                    spA8->newPosition.yPos.w += spA8->yVelocity.w;
                    spA8->owner = D_803D5530;
                    spA8->unk15C = 6;
                }
            } else if (ticks_remaining < 0x2C) {
                D_803F2ECE = 7;
                D_803F2ECC = 32 - (((ticks_remaining << 5) - 0x300) / 20);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_BEAR_3:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining == 4) {
                if (func_8033C9CC_74E07C(
                    D_803D5530->position.xPos.h,
                    D_803D5530->position.zPos.h,
                    D_803D5530->position.yPos.h + (D_803D5524->unkBA >> 1),
                    D_803D5530->unk160,
                    ((D_803D552C->unk320->position.xPos.h * 3) >> 1) - (D_803D5530->position.xPos.h >> 1),
                    ((D_803D552C->unk320->position.zPos.h * 3) >> 1) - (D_803D5530->position.zPos.h >> 1),
                    (((D_803D552C->unk320->position.yPos.h * 3) >> 1) - (D_803D5530->position.yPos.h >> 1)) + (D_803D552C->unk320->unk42 >> 1),
                    0x7F,
                    0,
                    0) == 0) {

                    func_80321920_732FD0(D_803D552C->unk320, 0, 0);
                    if (D_803D5530->state < 8) {
                        func_802A4390_6B5A40();
                    }
                } else {
                    D_803D552C->unk365 = ATTACK_NONE;
                    func_8032C508_73DBB8(0x10, 0x4000, 0, 1.0f);
                }
            }

            if (ticks_remaining < 9) {
                D_803F2ECE = 9;
                D_803F2ECC = ticks_remaining << 2;
            } else if (ticks_remaining < 0x19) {
                D_803F2ECE = 0xA;
                D_803F2ECC = 0x20 - ((ticks_remaining - 8) << 1);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        }

        if ((D_803D552C->unk320 != NULL) && (D_803D552C->unk365 != ATTACK_BEAR_2)) {
            D_803F2ECE = 7;
            D_803F2ECC = 0x20;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECE >= 5) || (((D_803F2ECC < 0x1F)))) {
            func_802B9D20_6CB3D0(&spF0, 0x386, 0x2D1, 0x386, 0x1E1);
            func_802C2D98_6D4448(0x2D1, 0x2D1);
            func_80320E70_732520(0x386, 0x386, 0, 0);
            func_802C4A70_6D6120(0x78, 0x2D1, 7);
            func_8038CCF0_79E3A0(0xB4, 0x14, -1, -1, (s16) -1, (s16) -1);
            spC4 += ((D_80203FE0[2].unk4 - 0x5A2) / 32) + 0x1E;
            spC2 = D_80203FE0[1].unk0 / 32;
            func_802BAE24_6CC4D4(&spC6, &spC4, 0x1E);
        }
        if (D_803F2ECC != 0) {
            backup_joint_positions();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803B5330_7C69E0, D_803B5344_7C69F4, D_803B5358_7C6A08, D_803B5378_7C6A28);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B5330_7C69E0, D_803B5344_7C69F4, D_803B5358_7C6A08, D_803B53C0_7C6A70);
                break;
            case 3:
                func_802DB670_6ECD20(D_803B5330_7C69E0, D_803B5344_7C69F4, D_803B5358_7C6A08, D_803B5408_7C6AB8);
                break;
            case 4:
                spD6 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB670_6ECD20(D_803B5330_7C69E0, D_803B5344_7C69F4, D_803B5358_7C6A08, D_803B5450_7C6B00);
                D_803F2ECC = spD6;
                backup_joint_positions();
                func_802DB670_6ECD20(D_803B5330_7C69E0, D_803B5344_7C69F4, D_803B5358_7C6A08, D_803B5408_7C6AB8);
                break;
            case 5:
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B54B4_7C6B64);
                break;
            case 6:
                spD6 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B54B4_7C6B64);
                D_803F2ECC = spD6;
                backup_joint_positions();
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B54CC_7C6B7C);
                break;
            case 7:
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, spA4);
                break;
            case 8:
                spD6 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, spA4);
                D_803F2ECC = spD6;
                backup_joint_positions();
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B552C_7C6BDC);
                break;
            case 9:
                spD6 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, spA4);
                D_803F2ECC = spD6;
                backup_joint_positions();
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5544_7C6BF4);
                break;
            case 10:
                func_802DB7C4_6ECE74(D_803B5498_7C6B48, D_803B54A0_7C6B50, D_803B54A8_7C6B58, D_803B5544_7C6BF4);
                break;
            }
        }

        if (D_803D552C->unk318 != 0) {
            D_80203FE0[1].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[2].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[3].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[7].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[8].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[4].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[10].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[11].unk2 -= (D_803D552C->unk318 * 0x15);
            D_80203FE0[20].unk2 -= (D_803D552C->unk318 * 0x1E);
            D_80203FE0[19].unk2 -= (D_803D552C->unk318 * 0x1E);
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_18 = D_803F2AA2, (temp_v0_18 == 0)) || (temp_v0_18 == 2) || ((temp_v0_18 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((gCameras[gCameraId].cameraMode != 3)) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            if (D_803D5530->state == 0xDD) {
                func_802E497C_6F602C(D_803D552C->unk308, &spD0, &spCC, &spC8);
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (D_803D5530->position.xPos.w / 65536.0), (D_803D5530->position.zPos.w / 65536.0), (D_803D5530->position.yPos.w / 65536.0));
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                func_80127994(spD0, spCC, spC8, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (-D_803D5530->position.xPos.w / 65536.0), (-D_803D5530->position.zPos.w / 65536.0), (-D_803D5530->position.yPos.w / 65536.0));
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }

            if (D_803D552C->unk369 == 2) {
                var_v0_7 = D_803D5540 << 4;
            } else {
                var_v0_7 = 0;
            }
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (s16) ((var_v0_7 - D_803D552C->heading) & 0xFF), D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            if (D_803D5530->state != 0xDD) {
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            } else {
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }
            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 3, 3, -0.25f);

            spD8 = 0x10000;
            spDC = 0x10000;
            spE0 = 0x10000;

            if (D_803D5530->state == 2) {
                if ((D_803D552C->unk366 != 5) && (D_803D552C->unk366 != 2)) {
                    temp_t6_2 = D_803D5540 & 0x3F;
                    if (temp_t6_2 < 20) {
                        spE0 = FTOFIX32(0.6875);
                        spE0 += ABS(temp_t6_2 - 10) << 11;
                    }
                    if ((temp_t6_2 < 30) && (temp_t6_2 > 10)) {
                        spDC = FTOFIX32(0.6875);
                        spDC += ABS(temp_t6_2 - 20) << 11;
                    }
                    if ((temp_t6_2 < 40) && (temp_t6_2 > 20)) {
                        spD8 = FTOFIX32(0.6875);
                        spD8 += ABS(temp_t6_2 - 30) << 11;
                    }
                }
            }

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0xE6, 0x87, 0xB0, 0xFF); // pink

            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004820_F5880);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x9A) >> 6, (D_803F2EC0 * 0x9A) >> 6, (D_803F2EC4 * 0x9A) >> 6, D_803F2ED0,0, 0, 1, D_040044B0_F5510);

            gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 0, 0, D_04004F30_F5F90); }
            func_802C78B0_6D8F60(7, 8, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 0, 0, D_04004DE0_F5E40);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 0xD, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 0, 0, D_04004FF0_F6050); }
            func_802C78B0_6D8F60(0xD, 0xE, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 0, 0, D_04004A50_F5AB0);

            if (D_803D5524->unk9C == GORILLA) {
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, (spE0 * 0x9A) >> 6, (spE0 * 0x9A) >> 6, (spE0 * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004B20_F5B80); }
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, (spD8 * 0x9A) >> 6, (spD8 * 0x9A) >> 6, (spD8 * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004BB0_F5C10); }
                if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, (spDC * 0x9A) >> 6, (spDC * 0x9A) >> 6, (spDC * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004C40_F5CA0); }
            }

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 0xA, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004F30_F5F90); }
            func_802C78B0_6D8F60(0xA, 0xB, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004DE0_F5E40);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 0x10, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004FF0_F6050); }
            func_802C78B0_6D8F60(0x10, 0x11, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004A50_F5AB0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xA, 0xB, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004B20_F5B80); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xA, 0xB, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004BB0_F5C10); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xA, 0xB, 0x26800, 0x26800, 0x26800, D_803F2ED0, 0, 1, 0, D_04004C40_F5CA0); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spEE, &spEC);
                func_8031A278_72B928(&D_803D552C->unk326, &spEE, &spEC);
                spEE = D_803BD5CC_7CEC7C[spEE]; spEC = D_803BD684_7CED34[spEC];
                func_80356BD8_768288(D_01002C40_3C510, D_010025A0_3BE70, spEE);

                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004CB0_F5D10);
                func_80356BD8_768288(D_01002C40_3C510, D_010025A0_3BE70, spEC);
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, (D_803F2EC8 * 0x9A) >> 6, D_803F2ED0, 0, 0, 0, D_04004D10_CC740);

                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((D_803D552C->unk320 != NULL) && (D_803D5524->unk9C == GORILLA)) {
        func_80321B70_733220(spC2, spC6, spC4);
    }
    if ((spEA == 0) || (spEA == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->heading, D_01033190_6CA60, 0x15, 0x15, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spEA == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x467, 1);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x2D1, 0);

        if (D_803D552C->unk320 != NULL) {
            func_80303C44_7152F4(D_803D552C, 2, spC6, spC4);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303D50_715400(D_803D552C, 2);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 0x549, 0x386);
    }
}

void func_8037B590_78CC40(void) {
    if ((D_803D552C->unk320 == 0) && (D_803D552C->unk365 != ATTACK_GRAB) && (D_803D5530->unk162 == 1)) {
        // fakematch
        if (D_803D5530) {};

        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_GRAB;
    } else if (D_803D552C->unk320 != 0) {
        if ((D_803D552C->unk365 != ATTACK_BEAR_2) && (D_803D552C->unk365 != ATTACK_BEAR_3) && (D_803D552C->unk318 == 0)) {
            D_803D552C->unk32A = D_803D5544;
            if ((D_803D552C->unk320->unk16C->objectType == OBJECT_BOULDER) || (D_803D552C->unk320->unk16C->objectType == 61)) {
                D_803D552C->unk365 = ATTACK_BEAR_2;
            } else {
                D_803D552C->unk365 = ATTACK_BEAR_3;
            }
        }
    }
}

void func_8037B660_78CD10(void) {
    s16 sp2E;
    s8  sp2D;

    if ((D_803D5530->state != 0xDD) && (D_803D552C->unk320 == 0)) {
        if (func_802E414C_6F57FC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, &sp2E, &sp2D) != 0) {
             func_802A623C_6B78EC(sp2E, sp2D);
        }
    } else if (D_803D5530->state == 0xDD) {
        if ((D_801D9ED8.prevAButton == 0) && (D_801D9ED8.curAButton != 0)) {
            func_802A628C_6B793C();
        }
    }
}

void func_8037B70C_78CDBC(void) {
    if (D_803D5530->unk162 == 1) {
        func_802A63C0_6B7A70();
        D_803D552C->unk369 = 1;
    }
}

void func_8037B754_78CE04(Animal *animal, Animal *object) {
    if (animal->unk365 != ATTACK_GRAB) {
        animal->unk330 = object;
        animal->unk32A = D_803D5544;
        animal->unk365 = ATTACK_GRAB;
    }
}

void func_8037B784_78CE34(Animal *arg0) {
    if (arg0->unk320 != NULL) {
        if ((arg0->unk365 != ATTACK_BEAR_2) && (arg0->unk365 != ATTACK_BEAR_3) &&
            (D_803D552C->unk318 == 0)) {
            arg0->unk32A = D_803D5544;
            if ((arg0->unk320->unk16C->objectType == OBJECT_BOULDER) ||
                (arg0->unk320->unk16C->objectType == 61)) {
                arg0->unk365 = ATTACK_BEAR_2;
            } else {
                arg0->unk365 = ATTACK_BEAR_3;
            }
        }
    }
}
