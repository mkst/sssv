#include <ultra64.h>
#include "common.h"

void func_802C23F8_6D3AA8(s16 arg0);

extern Gfx D_010039F8_3D2C8[];

extern u8 D_010226B0_5BF80[];
extern u8 D_010224B0_5BD80[];

extern u8 D_803A5EA0_7B7550[];
extern u8 D_803A5EB0_7B7560[];
extern s16 D_803A5EC0_7B7570[];
extern u8 D_803A5ED8_7B7588[];
extern u8 D_803A5EE0_7B7590[];
extern s16 D_803A5EE8_7B7598[];
extern u8 D_803A5EF8_7B75A8[];
extern u8 D_803A5F04_7B75B4[];
extern s16 D_803A5F10_7B75C0[];
extern s16 D_803A5F24_7B75D4[];
extern s16 D_803A5F5C_7B760C[];
extern s16 D_803A5F94_7B7644[];
extern s16 D_803A5FB0_7B7660[];
extern s16 D_803A5FCC_7B767C[];
extern s16 D_803A5FE8_7B7698[];
extern s16 D_803A6004_7B76B4[];
extern s16 D_803A6034_7B76E4[];

extern Gfx D_04007BC0_CF5F0[];

extern u8  D_010025A0[];
extern u8  D_01002C40[];
extern Gfx D_01003548[];
extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

extern f32 D_803BDAB4_7CF164;

extern Gfx D_040077C0_CF1F0[];
extern Gfx D_04007EC0_CF8F0[];
extern Gfx D_040082C0_CFCF0[];
extern Gfx D_04008490_CFEC0[];
extern Gfx D_040084A8_CFED8[];
extern Gfx D_04008A20[];
extern Gfx D_04008E30_D0860[];
extern u8  D_040096E0_D1110[];
extern u8  D_04009760[];

extern Gfx D_04009540_D0F70[];

//BEAR
#ifdef NON_MATCHING
// CURRENT (4026)
void func_80323680_734D30(void) {
    u8 var_v0;
    u8 temp_v0_10;
    u16 ticks_remaining;
    s16 temp_s0_3;
    Animal *temp_v0_15;

    s16 spC8;

    s32 spC4;
    s32 spC0;
    s32 spBC;

    s16 spB8;
    s16 spB6;
    s16 spB4;
    s16 spB2;
    s16 spB0;

    s16 idx;

    spB2 = 0x3B;
    spB0 = 0x1F;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spB4 = 0;
        D_803F2EDD = 0;
    } else {
        spB4 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x18A4, 6, 0x6D, 0x27, 0, 2, CHECK_SEGMENT == 0);
    }

    if (spB4 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        D_803F2EBC = ((D_803F2EBC - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EC0 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EC4 - FTOFIX32(1.0)) >> 1) + FTOFIX32(1.0);
        func_8035D734_76EDE4();

        if (D_803D5530->state == 0xDD) {
            if (ABS(D_801D9ED8.unkFFDE) > 7) {
                D_803D552C->unk30C = (D_803D552C->unk30C + 4) & 0x3F;
            } else {
                D_803D552C->unk30C = 0;
            }
            D_803F2ECC = MIN(0x20, ((COS(D_803D552C->unk30C << 2) >> 7) >> 4) + 0x11);
            D_803F2ECE = 11;
        }

        if ((D_803D552C->unk320 != NULL) && (D_803D552C->unk320->unk26C != 0)) {
            D_803D552C->unk320 = NULL;
            D_803D552C->unk365 = ATTACK_BEAR_3;
            D_803D552C->unk32A = D_803D5544;
        }

        switch (D_803D552C->unk365) {
        case ATTACK_GRAB:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803F2ECE = 3;
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
                    spB2 += 0xF;
                    spB0 -= 0xF;
                    D_803D552C->unk365 = ATTACK_BEAR_1;
                    D_803D552C->unk32A = D_803D5544;
                }
            }
            break;
        case ATTACK_HOLD:                                    /* switch 1 */
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803F2ECE = 3;
            D_803F2ECC = 0x20 - (ticks_remaining << 1);
            if (ticks_remaining == 16) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_BEAR_1:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            D_803F2ECE = 7;
            D_803F2ECC = 0x20 - (ticks_remaining * 2);
            spB2 += (D_803F2ECC * 0xF) / 32;
            spB0 -= (D_803F2ECC * 0xF) / 32;
            if (ticks_remaining == 16) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        case ATTACK_BEAR_2:
            ticks_remaining = D_803D5544 - D_803D552C->unk32A;
            if (ticks_remaining < 21) {
                // NOTE: different (better) regalloc with +=
                spB0 = spB0 + (((SIN(ticks_remaining << 2) >> 7) * (spB2 + 0xF)) >> 8);
                spB2 = (((COS(ticks_remaining << 2) >> 7) * spB2) >> 8);

                D_803F2ECE = 9;
                D_803F2ECC = MAX(1, (ticks_remaining << 5) / 20);
                if (ticks_remaining == 20) {
                    temp_v0_15 = D_803D552C->unk320;
                    if (D_803D5530->state < 8) {
                        func_802A4390_6B5A40();
                    }
                    func_80321920_732FD0(D_803D552C->unk320, 25, 2);
                    temp_v0_15->newPosition.xPos.w += temp_v0_15->xVelocity.w;
                    temp_v0_15->newPosition.zPos.w += temp_v0_15->zVelocity.w;
                    temp_v0_15->newPosition.yPos.w += temp_v0_15->yVelocity.w;

                    temp_v0_15->owner = D_803D5530;
                    temp_v0_15->unk15C = 6;
                }
            } else if (ticks_remaining < 30) {
                D_803F2ECE = 10;
                D_803F2ECC = 32 - (((ticks_remaining - 20) * 32) / 10);
            } else if (ticks_remaining < 40) {
                D_803F2ECE = 3;
                D_803F2ECC = 32 - (((ticks_remaining - 30) * 32) / 10);
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
                    if (D_803D5530->state < 8) {
                        func_802A4390_6B5A40();
                    }
                    func_80321920_732FD0(D_803D552C->unk320, 0, 0);
                }
            }
            if (ticks_remaining < 9) {
                D_803F2ECE = 6;
                D_803F2ECC = ticks_remaining << 2;
            } else if (ticks_remaining < 25) {
                D_803F2ECE = 5;
                D_803F2ECC = 32 - ((ticks_remaining - 8) << 1);
            } else {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            break;
        default:                                    /* switch 1 */
            D_803D552C->unk365 = ATTACK_NONE;
            break;
        }

        if ((D_803D552C->unk320 != NULL) && (D_803D552C->unk365 != ATTACK_BEAR_2) && (D_803D552C->unk365 != ATTACK_BEAR_1)) {
            D_803F2ECC = 0x20;
            D_803F2ECE = 8;
        }

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F) || (D_803F2ECE >= 3)) {
            func_802B9A5C_6CB10C(&spC8, 0x510);
            func_802C23F8_6D3AA8(0x614);
            func_8032066C_731D1C(0x40D, 0x91E);
            if (D_803D5530->unk162 == 5) {
                idx = D_803D5540 << 4;
                D_80203FE0[8].unk2 =  D_80203FE0[7].unk2 + (((COS(idx) >> 7) * 0x91E) >> 8);
                D_80203FE0[8].unk4 =  D_80203FE0[7].unk4 - (((SIN(idx) >> 7) * 0x91E) >> 8);

                idx += 0x50;
                D_80203FE0[11].unk2 = D_80203FE0[10].unk2 + (((COS(idx) >> 7) * 0x91E) >> 8);
                D_80203FE0[11].unk4 = D_80203FE0[10].unk4 - (((SIN(idx) >> 7) * 0x91E) >> 8);

                func_8034B3A8_75CA58(0);
            }
            spB0 += D_80203FE0[2].unk4 / 32;
            func_802C652C_6D7BDC(0x81, 0x30A);
            func_8038CCF0_79E3A0(0x247, 0x14, -1, -1, -1, -1);
            func_802BAE24_6CC4D4(&spB2, &spB0, 0x2C);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {                    /* switch 2 */
            case 1:                                 /* switch 2 */
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F24_7B75D4);
                break;
            case 2:                                 /* switch 2 */
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F5C_7B760C);
                break;
            case 3:                                 /* switch 2 */
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5F94_7B7644);
                break;
            case 4:                                 /* switch 2 */
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FB0_7B7660);
                break;
            case 5:                                 /* switch 2 */
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FCC_7B767C);
                break;
            case 6:                                 /* switch 2 */
                temp_s0_3 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FE8_7B7698);
                D_803F2ECC = temp_s0_3;
                func_802DB8DC_6ECF8C();
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FCC_7B767C);
                break;
            case 7:                                 /* switch 2 */
                temp_s0_3 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FE8_7B7698);
                D_803F2ECC = temp_s0_3;
                func_802DB8DC_6ECF8C();
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5F94_7B7644);
                break;
            case 8:                                 /* switch 2 */
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FE8_7B7698);
                break;
            case 9:                                 /* switch 2 */
                temp_s0_3 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FE8_7B7698);
                D_803F2ECC = temp_s0_3;
                func_802DB8DC_6ECF8C();
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FB0_7B7660);
                break;
            case 10:                                /* switch 2 */
                temp_s0_3 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5F94_7B7644);
                D_803F2ECC = temp_s0_3;
                func_802DB8DC_6ECF8C();
                func_802DB7C4_6ECE74(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5FB0_7B7660);
                break;
            case 11:
                // store used joints?
                temp_s0_3 = D_803F2ECC;
                D_803F2ECC = 0x20;
                func_802DB670_6ECD20(D_803A5EF8_7B75A8, D_803A5F04_7B75B4, D_803A5F10_7B75C0, D_803A6004_7B76B4);
                D_803F2ECC = temp_s0_3;
                func_802DB8DC_6ECF8C();
                func_802DB670_6ECD20(D_803A5EF8_7B75A8, D_803A5F04_7B75B4, D_803A5F10_7B75C0, D_803A6034_7B76E4);
                break;
            }
        }

        if (D_803D552C->unk318 != 0) {
            D_80203FE0[1].unk2  -= (D_803D552C->unk318 * 0x14);
            D_80203FE0[20].unk2 -= (D_803D552C->unk318 * 0x1E);
            D_80203FE0[10].unk2 -= (D_803D552C->unk318 * 0x14);
            D_80203FE0[11].unk2 -= (D_803D552C->unk318 * 0x14);
            D_80203FE0[7].unk2  -= (D_803D552C->unk318 * 0x14);
            D_80203FE0[8].unk2  -= (D_803D552C->unk318 * 0x14);
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_10 = D_803F2AA2, (temp_v0_10 == 0)) || (temp_v0_10 == 2) || ((temp_v0_10 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            if (D_803D5530->state == 0xDD) {
                func_802E497C_6F602C(D_803D552C->unk308, &spC4, &spC0, &spBC);
                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w / 65536.0, D_803D5530->position.zPos.w / 65536.0, D_803D5530->position.yPos.w / 65536.0);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                func_80127994(spC4, spC0, spBC, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]);
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (-D_803D5530->position.xPos.w / 65536.0), (-D_803D5530->position.zPos.w / 65536.0), (-D_803D5530->position.yPos.w / 65536.0));
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            }

            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (u32) ((s32) D_803F2EB8 / 4), (s16) (s32) D_803F2ED2, D_803F2ED4);
            if (D_803D5530->state != 0xDD) {
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            } else {
                gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }
            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.22f);

            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0xA6) >> 6, (D_803F2EC0 * 0xA6) >> 6, (D_803F2EC4 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_040082C0_CFCF0);
            load_1_tile(D_010226B0_5BF80, D_010224B0_5BD80);
            func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_04007BC0_CF5F0);
            gSPDisplayList(D_801D9E88++, D_01003548);

            func_802C78B0_6D8F60(2, 0xF, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_04007EC0_CF8F0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(2, 0x12, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 1, 0, D_04007EC0_CF8F0);
            gSPDisplayList(D_801D9E88++, D_01003548);

            func_802C78B0_6D8F60(7, 8, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_040077C0_CF1F0);
            gSPDisplayList(D_801D9E88++, D_01003548);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            func_802C78B0_6D8F60(0xA, 0xB, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 1, 0, D_040077C0_CF1F0);

            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spB8, &spB6);
                func_8031A278_72B928(&D_803D552C->unk326, &spB8, &spB6);
#pragma _permuter sameline start
                spB8 = D_803BD5CC_7CEC7C[spB8];spB6 = D_803BD684_7CED34[spB6];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01002C40, D_010025A0, spB8);
                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_04008490_CFEC0);
                func_80356BD8_768288(D_01002C40, D_010025A0, spB6);
                func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_040084A8_CFED8);
                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
                gDPPipeSync(D_801D9E88++);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if (D_803D552C->unk320 != NULL) {
        func_80321B70_733220(0, spB2, spB0);
    }
    if ((spB4 == 0) || (spB4 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->unk302, D_01033190, (s16) 0x19, (s16) 0x19, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (spB4 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x3CC, 0);
        func_80303820_714ED0(D_803D552C, 1, 19, 0x30A, 1);
        if (D_803D552C->unk320 != NULL) {
            func_80303C44_7152F4(D_803D552C, 2, spB2, spB0);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303D50_715400(D_803D552C, 2);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 0xF31, 0x510);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80323680_734D30.s")
#endif

// CRAZY_BEAR
#if 0
// CURRENT (3553)
void func_803250A8_736758(void) {
    s16 spC6; // pad
    s16 spC4;
    s16 spC2;
    s16 spC0; // pad
    s32 spBC;
    s32 spB8;
    s32 spB4;
    s32 spB0; // pad
    s32 spCC; // pad

    s16 var_v1_2;

    u8 angle;
    u8 var_v0;
    u8 var_v1;
    u8 temp_v0_9;

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spC2 = 0;
        D_803F2EDD = 0;
    } else {
        spC2 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x18A4, 6, 0x6D, 0x27, 0, 2, CHECK_SEGMENT == 0);
    }

    if (spC2 == 0) {
        if (D_803D552C->unk30E > 0) {
            D_803D552C->unk30E--;
        }
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9A5C_6CB10C(&spC4, 0x510);
            func_802C23F8_6D3AA8(0x614);
            D_803D553A = 0;
            func_80320B04_7321B4(0x40D, 0x91E);
            if (D_803D553A == 3) {
                if (D_803D5530->unk4A == 0) {
                    play_sound_effect_at_location(SFX_UNKNOWN_0, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
            }
            func_802C5824_6D6ED4(0x81, 0x30A, 0x14);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F24_7B75D4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F5C_7B760C);
                break;
            case 3:
                func_802DB670_6ECD20(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5F94_7B7644);
                break;
            }
        }

        D_80203FE0[27].unk0 = D_80203FE0[20].unk0;
        D_80203FE0[27].unk2 = D_80203FE0[20].unk2;
        D_80203FE0[27].unk4 = D_80203FE0[20].unk4;

        D_80203FE0[27].unk4 += (((0x100 - (SIN((D_803D5540 << 4) % 255) >> 7)) * 0x30A)) >> 0xC;
        D_80203FE0[20].unk4 -= (((0x100 - (SIN((D_803D5540 << 4) % 255) >> 7)) * 0x30A)) >> 0xC;

        if ((D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4)) {
            if (D_803D5530->unk4A == 0) {
                var_v1_2 = 0;
                angle = (D_803D5540 << 4);
                if (angle == 0) {
                    var_v1_2 = func_803224C4_733B74(60, -40,  40, 48, 5, 0, 0, 12);
                } else if (angle == 0x40) {
                    var_v1_2 = func_803224C4_733B74(60, -40, -40, 48, 5, 0, 0, 12);
                } else if (angle == 0x80) {
                    var_v1_2 = func_803224C4_733B74(60,  40,  40, 48, 5, 0, 0, 12);
                } else if (angle == 0xC0) {
                    var_v1_2 = func_803224C4_733B74(60,  40, -40, 48, 5, 0, 0, 12);
                }
                if (var_v1_2 & 2) {
                    play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                }
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (temp_v0_9 = D_803F2AA2, (temp_v0_9 == 0)) || (temp_v0_9 == 2) || ((temp_v0_9 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, (D_803F2EB8 / 4), D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, D_803BDAB4_7CF164);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0xA6) >> 6, (D_803F2EC0 * 0xA6) >> 6, (D_803F2EC4 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_040082C0_CFCF0);
            load_1_tile(D_010226B0_5BF80, D_010224B0_5BD80);
            func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_04008A20);
            func_802C78B0_6D8F60(1, 0x1B, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_04008E30_D0860);
            func_802C78B0_6D8F60(2, 0xF, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_04007EC0_CF8F0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(2, 0x12, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 1, 0, D_04007EC0_CF8F0);
            func_802C78B0_6D8F60(7, 8, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_040077C0_CF1F0);
            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            func_802C78B0_6D8F60(0xA, 0xB, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 1, 0, D_040077C0_CF1F0);
            func_8034B008_75C6B8(1, 0x14, 0x5C, &spBC, &spB8, &spB4);

            gDPLoadTextureBlock_4b(
              /* pkt */    D_801D9E88++,
              /* timg */   D_040096E0_D1110,
              /* fmt */    G_IM_FMT_CI,
              /* width */  16,
              /* height */ 16,
              /* pal */    0,
              /* cms */    G_TX_NOMIRROR | G_TX_WRAP,
              /* cmt */    G_TX_NOMIRROR | G_TX_WRAP,
              /* masks */  G_TX_NOMASK,
              /* maskt */  G_TX_NOMASK,
              /* shifts */ G_TX_NOLOD,
              /* shiftt */ G_TX_NOLOD
            );
            gSPDisplayList(D_801D9E88++, D_010039F8_3D2C8);

            gDPLoadTLUT_pal16(
                D_801D9E88++,
                16,
                D_04009760
            );

            // regalloc helper (ish)
            do {
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC + (SIN(D_803D5540 << 3) * 11),
                    spB8 + (COS(D_803D5540 << 3) * 9),
                    spB4 - (SIN(D_803D5540 << 5) * 4),
                    0x10,
                    0x10,
                    0x898);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC - (SIN((D_803D5540 << 3) + 0x80) * 12),
                    spB8 + (SIN((D_803D5540 << 3) + 0x40) * 9),
                    spB4 + (SIN((D_803D5540 << 5) + 0x80) * 4),
                    0x10,
                    0x10,
                    0x898);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC + (COS(D_803D5540 << 3) * 9),
                    spB8 + (SIN(D_803D5540 << 3) * 12),
                    spB4 + (SIN(D_803D5540 << 4) * 4),
                    0x10,
                    0x10,
                    0x898);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC - (SIN((D_803D5540 << 3) + 0x40) * 10),
                    spB8 - (SIN((D_803D5540 << 3) + 0x80) * 11),
                    spB4 - (SIN(D_803D5540 << 4) * 4),
                    0x10,
                    0x10,
                    0x898);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC + (SIN(D_803D5540 << 3) * 11),
                    spB8 + (SIN(D_803D5540 << 3) * 10),
                    spB4 + (COS(D_803D5540 << 5) * 3),
                    0x10,
                    0x10,
                    0x898);
                func_8032E150_73F800(
                    &D_801D9EB8,
                    spBC - (COS(D_803D5540 << 3) * 10),
                    spB8 - (COS(D_803D5540 << 3) * 10),
                    spB4 + (COS((D_803D5540 << 4) + 0x80) * 4),
                    0x10,
                    0x10,
                    0x898);
            }  while (0);

            if (((D_803D5540 & 3) == 0) && (SSSV_RAND(8)) == 0) {
                create_particle_effect(
                    spBC >> 16,
                    spB8 >> 16,
                    spB4 >> 16,
                    37,
                    D_803D5530->xVelocity.w >> 1,
                    D_803D5530->zVelocity.w >> 1,
                    D_803D5530->yVelocity.w >> 1,
                    8,
                    GPACK_RGBA5551(255, 255, 255, 1),
                    GPACK_RGBA5551(255, 255, 255, 1),
                    0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }

    if ((spC2 == 0) || (spC2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, D_01033190, 0x19, 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spC2 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2,  0x3CC, 0);
        func_80303820_714ED0(D_803D552C, 1, 19, 0x30A, 1);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0xF31, 0x510);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            load_animal(BEAR);
        } else {
            D_803D552C->unk2EC--;
        }
    }
    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        load_animal(BEAR);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803250A8_736758.s")
#endif

// MYSTERY_BEAR
#ifdef NON_MATCHING
// CURRENT (1792)
void func_80326260_737910(void) {
    f32 temp_f2_2;
    s32 temp_lo;
    s32 tmp1;
    s32 tmp2;

    s16 spC8;

    s32 spBC;
    s32 spB8;

    f32 var_f0;

    s16 var_t0; // spB4
    s16 spB2;
    s16 spB0;
    s16 spAE;

    s16 var_a2;
    s16 i;
    u8 temp_v0_8;
    s32 var_a3;

    s32 sp5C;
    s32 sp4C;
    s16 new_var;

    trigger_contagious_laughter();

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        spB2 = 0;
    } else if ((ABS(D_803D552C->position.xPos.h - (s16) D_803F28E0[D_803F2A98].unk74) < 0x3C0) && (ABS(D_803D552C->position.zPos.h - (s16) D_803F28E0[D_803F2A98].unk78) < 0x3C0)) {
        spB2 = 0;
    } else {
        spB2 = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x18A4, (u8) 6, (s16) 0x6D, (s16) 0x27, (s16) 0, (s8) 2, CHECK_SEGMENT == 0);
    }

    if ((spB2 != 4) && (spB2 != 1) && (D_803D5530->unk162 == 1)) {
        temp_f2_2 = (sqrtf(SQ((f32)D_803D552C->xVelocity.w) + SQ((f32)D_803D552C->zVelocity.w)) / (f32) (D_803D5524->unkA4 << 0xA));
        if (temp_f2_2 < 0.2) {
            var_f0 = 0.0f;
        } else if (temp_f2_2 > 0.6) {
            var_f0 = 1.0f;
        } else {
            var_f0 = (temp_f2_2 - 0.2) * 2.5;
        }
        if (var_f0 > 0.0) {
            // temp regalloc hack
            // var_a3 = D_803D5530->unk4A;
            if (D_803D5530->unk4A == 0) {
                func_8032CED0_73E580(
                    D_803D5530,
                    SFX_UNKNOWN_13,
                    (12288.0f * var_f0) / 2.0,
                    2.0 * temp_f2_2,
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
    if (spB2 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        D_803D552C->unk365 = ATTACK_NONE;

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9A5C_6CB10C(&spC8, 0x510);

            var_a2 = SIN((D_803D5540 << 3) & 0xFF) >> 7;
            switch (D_803D5530->state) {
            case 0x16:
            case 0x17:
                temp_lo = MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w));
                temp_lo = (temp_lo * -0x400) / ((D_803D5524->unkA4 << 0x10) >> 6);
                if (temp_lo < var_a2) {
                    var_a2 = temp_lo;
                }
                break;
            case 0x15:
                temp_lo = MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w));
                temp_lo = (temp_lo * 0x400) / ((D_803D5524->unkA4 << 0x10) >> 6);
                if ((var_a2 < temp_lo) && (temp_lo != 0)) {
                    var_a2 = temp_lo;
                }
                break;
            }

            if (var_a2 > 0x400) {
                var_a2 = 0x400;
            }
            if (var_a2 < -0x400) {
                var_a2 = -0x400;
            }

            if (ABS(D_803D552C->unk30C - var_a2) < 0xC8) {
                D_803D552C->unk30C = var_a2;
            } else if (D_803D552C->unk30C < var_a2) {
                D_803D552C->unk30C += 200;
            } else {
                D_803D552C->unk30C -= 200;
            }

            D_80203FE0[2].unk2 += (D_803D552C->unk30C * 0x592) >> 0xA;
            D_80203FE0[1].unk2 -= (D_803D552C->unk30C * 0x592) >> 0xB;
            D_80203FE0[1].unk4 -= ABS((D_803D552C->unk30C * 0x592) >> 0xC);

            // D_80203FE0->unkD4 = D_80203FE0->unk14;
            D_80203FE0[26].unk4 = D_80203FE0[2].unk4;

            // D_80203FE0->unk14 = D_80203FE0->unk14 + 0x592
            D_80203FE0[2].unk4 = D_80203FE0[2].unk4 + 0x592;
            // D_80203FE0->unk4 += 0x592
            D_80203FE0[0].unk4 = D_80203FE0[0].unk4 + 0x592;
            // D_80203FE0->unkC = (s16) (D_80203FE0->unkC + 0x592);
            D_80203FE0[1].unk4 = D_80203FE0[1].unk4 + 0x592;

            // D_80203FE0->unkD0 = D_80203FE0->unk10
            D_80203FE0[26].unk0 = D_80203FE0[2].unk0;
            // D_80203FE0->unkD8 =  D_80203FE0->unk10;
            D_80203FE0[27].unk0 = D_80203FE0[2].unk0;
            // D_80203FE0->unkD2 = (s16) D_80203FE0->unk12;
            D_80203FE0[26].unk2 = D_80203FE0[2].unk2;
            // D_80203FE0->unkDA = (s16) D_80203FE0->unk12;
            D_80203FE0[27].unk2 = D_80203FE0[2].unk2;
            // D_80203FE0->unkDC = (s16) D_80203FE0->unk14;
            D_80203FE0[27].unk4 = D_80203FE0[2].unk4;

            var_a3 = D_803D5530->yVelocity.w >> 5;
            if (var_a3 > 0) {
                var_a3 = 0;
            }
            if (var_a3 < -0x2000) {
                var_a3 = -0x2000;
            }
            D_80203FE0[1].unk4 -= (var_a3 / 32);
            D_80203FE0[0].unk4 -= (var_a3 / 32);
            D_80203FE0[2].unk4 -= (var_a3 / 32);

            func_80320C84_732334(0x40D, 0x91E);
            func_802C652C_6D7BDC(0x81, 0x30A);
        }
        if ((D_803D552C->unk320 == NULL) && (D_801E9E8E != 0) && (((D_803D5530->state == 2)) || (D_803D5530->state == 3))) {
            D_803F2ECC = 0x20;
            D_803F2ECE = 3;
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F24_7B75D4);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A5EA0_7B7550, D_803A5EB0_7B7560, D_803A5EC0_7B7570, D_803A5F5C_7B760C);
                break;
            case 3:
                func_802DB670_6ECD20(D_803A5ED8_7B7588, D_803A5EE0_7B7590, D_803A5EE8_7B7598, D_803A5F94_7B7644);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_8 = D_803F2AA2, (temp_v0_8 == 0)) || (temp_v0_8 == 2) || ((temp_v0_8 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 8) / 5, 2, 3, 3, -0.22f);
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0xA6) >> 6, (D_803F2EC0 * 0xA6) >> 6, (D_803F2EC4 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_040082C0_CFCF0);
            load_1_tile(D_010226B0_5BF80, D_010224B0_5BD80);
            func_802C78B0_6D8F60(1, 0x14, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, (D_803F2EC8 * 0xA6) >> 6, D_803F2ED0, 0, 0, 0, D_04007BC0_CF5F0);
            func_802C78B0_6D8F60(7, 8, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_040077C0_CF1F0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            func_802C78B0_6D8F60(0xA, 0xB, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 1, 0, D_040077C0_CF1F0);
            func_802C78B0_6D8F60(0x1B, 0x1A, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_04009540_D0F70);
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spB0, &spAE);
                func_8031A278_72B928(&D_803D552C->unk326, &spB0, &spAE);
#pragma _permuter sameline start
                spB0 = D_803BD5CC_7CEC7C[spB0];spAE = D_803BD684_7CED34[spAE];
#pragma _permuter sameline end
                func_80356BD8_768288(D_01002C40, D_010025A0, spB0);

                gSPDisplayList(D_801D9E88++, D_010037F0_3D0C0);

                func_802C78B0_6D8F60(1, 0x14, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_04008490_CFEC0);
                func_80356BD8_768288(D_01002C40, D_010025A0, spAE);
                func_802C78B0_6D8F60(1, 0x14, 0x29800, 0x29800, 0x29800, D_803F2ED0, 0, 0, 0, D_040084A8_CFED8);

                gSPDisplayList(D_801D9E88++, D_01003840_3D110);
                gDPPipeSync(D_801D9E88++);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

            // draw spotlights?
            func_8034C8F8_75DFA8(
                D_803D552C->position.xPos.h + ((COS(D_803D5540) >> 7) >> 1),
                D_803D552C->position.zPos.h + ((SIN(D_803D5540) >> 7) >> 2),
                D_803D552C->position.yPos.h + 0x100,
                0,
                D_01033190,
                0x7D,
                0x7D,
                0x4D,
                0xFF, // r?
                0,    // g?
                0xFF, // b?
                2,
                D_803D5538);
            func_8034C8F8_75DFA8(
                D_803D552C->position.xPos.h + ((COS(D_803D5540 + 0x1E) >> 7) >> 2),
                D_803D552C->position.zPos.h - ((SIN(D_803D5540) >> 7) >> 1),
                D_803D552C->position.yPos.h + 0x100,
                0,
                D_01033190,
                0x7D,
                0x7D,
                0x4D,
                0,    // r?
                0xFF, // g?
                0xFF, // b?
                2,
                D_803D5538);

            if ((D_803D552C->unk366 != 2) && (D_803D552C->unk366 != 5)) {
                // add yellow light (r+g)
                add_light_at_location(
                    D_803D552C->position.xPos.h + ((COS(D_803D5540) >> 7) >> 1),
                    D_803D552C->position.zPos.h + ((SIN(D_803D5540) >> 7) >> 2),
                    D_803D552C->position.yPos.h - 0x20,
                    0xFF,
                    0xFF,
                    0,
                    0xFF);
                // add pink light (r+b)
                add_light_at_location(
                    D_803D552C->position.xPos.h + ((COS(D_803D5540 + 0x1E) >> 7) >> 2),
                    D_803D552C->position.zPos.h - ((SIN(D_803D5540) >> 7) >> 1),
                    D_803D552C->position.yPos.h - 0x20,
                    0xFF,
                    0,
                    0xFF,
                    0xFF);

                spB8 = COS(-D_803D552C->unk302) >> 7;
                spBC = SIN(-D_803D552C->unk302) >> 7;

                sp5C = spBC * 0x33E0;
                sp4C = spB8 * 0x33E0;

                for (i = 0; i < 3; i++) {
                    switch (i) {
                    case 0:
                        var_t0 = D_803D5540;
                        break;
                    case 1:
                        var_t0 = (D_803D5540 + 85) & 0xFF;
                        break;
                    case 2:
                        var_t0 = (D_803D5540 + 171) & 0xFF;
                        break;
                    }

                    if (((var_t0 & 0x1F) == 10) || ((var_t0 & 0x1F) == 20)) {
                        play_sound_effect_at_location(0, 0x4000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }

                    // help
                    tmp1 = (SIN(var_t0 << 3) >> 7) * 0xA6;
                    tmp1 = (tmp1 * 0x180) / 4;

                    tmp2 = (SIN(var_t0 << 2) >> 7) * 0xA6;
                    tmp2 = (tmp2 / 4);

                    func_8029CEF0_6AE5A0(
                        D_803D5530->position.xPos.w + (spB8 * tmp2) - sp5C,
                        D_803D5530->position.zPos.w + (spBC * tmp2) + sp4C,
                        D_803D5530->position.yPos.w + (tmp1) + 0xADC800,
                        612,
                        i + 3,
                        &D_803D2E08,
                        i + 3,
                        0,  // r
                        0,  // g
                        0); // b
                }
            }
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spB2 == 0) || (spB2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1), D_803D552C->unk302, (Gfx *) D_01033190, 0x19, 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (spB2 == 0) {
        func_80303820_714ED0(D_803D552C, 1, 2, 0x3CC, 0);
        func_80303820_714ED0(D_803D552C, 1, 0x13, 0x30A, 1);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0xF31, 0x510);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80326260_737910.s")
#endif

#ifdef NON_MATCHING // JUSTREG
// esa: func_8008D654
// CURRENT (10)
void func_803277B4_738E64(void) {
    // struct035 *tmp;

    if ((D_803D552C->unk320 == NULL) && (D_803D552C->unk365 != ATTACK_GRAB)) {
        D_803D552C->unk32A = D_803D5544 & 0xFFFF;
        D_803D552C->unk365 = ATTACK_GRAB;
    } else if ((D_803D552C->unk320 != NULL) &&
               (D_803D552C->unk365 != ATTACK_BEAR_2) &&
               (D_803D552C->unk365 != ATTACK_BEAR_3) &&
               (D_803D552C->unk318 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        // this temp is required to match ESA:
        // tmp = D_803D552C->unk320->unk16C;

        // object is a bolder or ?
        if ((D_803D552C->unk320->unk16C->objectType == OBJECT_BOULDER) ||
            (D_803D552C->unk320->unk16C->objectType == 61)) {
            D_803D552C->unk365 = ATTACK_BEAR_2;
        } else {
            D_803D552C->unk365 = ATTACK_BEAR_3;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803277B4_738E64.s")
#endif

void func_8032786C_738F1C(void) {
    if ((D_803D552C->unk320 == 0) &&
        (D_803D552C->unk365 == ATTACK_NONE) &&
        (D_803D5530->state != 0xDD)) {
        load_animal(CRAZY_BEAR);
        D_803D552C->unk30E = 20;
    }
}

void func_803278D4_738F84(void) {
    if (D_803D552C->unk30E <= 0) {
        load_animal(BEAR);
    }
}

void func_80327908_738FB8(void) {
    s16 sp2E;
    s8 sp2D;

    if ((D_803D5530->state != 0xDD) && (D_803D552C->unk320 == 0)) {
        if (func_802E414C_6F57FC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, &sp2E, &sp2D)) {
            func_802A623C_6B78EC(sp2E, sp2D);
            D_803D552C->unk365 = ATTACK_NONE;
        }
    } else if ((D_803D5530->state == 0xDD) && (D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) {
        func_802A628C_6B793C();
    }
}

void func_803279BC_73906C(void) {
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
            SSSV_RAND(16) + 0xF,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 0xF);
    } else {
        func_8037D994_78F044(16);
        create_particle_effect(
            D_803D5530->position.xPos.h,
            D_803D5530->position.zPos.h,
            D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 0xF,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 0xF);
    }
}

void func_80327B84_739234(s32 arg0, s32 arg1, s32 arg2) {
}

void func_80327B94_739244(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == BEAR) {
        load_animal(CRAZY_BEAR);
    }
}
