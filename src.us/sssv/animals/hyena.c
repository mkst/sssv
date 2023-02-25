#include <ultra64.h>
#include "common.h"

extern s16 D_803B3B28_7C51D8[];

extern u8 D_803B3A50_7C5100[];
extern u8 D_803B3A64_7C5114[];
extern s16 D_803B3A78_7C5128[];
extern s16 D_803B3A98_7C5148[];
extern s16 D_803B3AE0_7C5190[];

extern Gfx D_04006C50[];
extern Gfx D_04006D70[];
extern Gfx D_040071C0_F8220[];
extern Gfx D_040073C0_F8420[];
extern Gfx D_040074B0_F8510[];
extern Gfx D_040076E0_F8740[];
extern u8  D_04007780_F87E0[];
extern u8  D_04007980_F89E0[];
extern Gfx D_04007B60_F8BC0[];
extern Gfx D_04007CE0_F8D40[];
extern Gfx D_04007EA0_F8F00[];
extern Gfx D_040080A0_F9100[];
extern u8  D_04008120_F9180[];
extern u8  D_04008320_F9380[];
extern u8  D_04008340_F93A0[];
extern u8  D_04008540_F95A0[];

extern Gfx D_01002C40[];
extern Gfx D_010025A0[];
extern Gfx D_04007A20_F8A80[];
extern Gfx D_04007A40_F8AA0[];


// HYENA_BIKER
#if 0
void func_803574E0_768B90(void) {
    s32 spAC;
    s32 spA8;
    s32 spA4;
    struct061 sp9C;
    s16 sp9A;
    s16 sp98;
    s16 sp96;
    s16 sp94;
    s16 sp92;
    s16 sp8C;
    s16 sp8A;
    s16 sp88;
    s16 sp86;

    s16 temp_t6_4;
    s16 temp_t7_2;
    s16 var_a0;
    s32 var_t1_4;
    s16 var_t2;
    s16 var_v0;
    s16 var_v0_4;
    s16 i;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_a0_4;
    u8 temp_t0;
    s32 temp_t1;
    s32 temp_t6;
    s32 temp_t6_2;
    s32 temp_t8;
    s32 temp_t9_2;
    s32 var_a1;
    s32 var_t1;
    u8 var_t1_2;
    u8 var_v0_3;
    s8 var_v0_2;
    s8 var_v1;

    u8 temp_a1;
    u8 temp_v0_2;
    u8 temp_v0_7;


    var_v1 = (s8) (D_803D552C->unk310 >> 8);
    temp_t0 = D_803D552C->unk310;
    if (D_803D5538 != 0) {
        var_v0 = D_801D9ED8.unkFFDA;
    } else {
        var_v0 = MIN(D_803D552C->unk368 >> 2, 24);
    }

    switch (var_v0) {
    case 0:
        var_v0_2 = -5;
        var_a1 = 0;
        var_t1 = temp_t0;
        break;
    case 1:
        var_v0_2 = 2;
        var_a1 = 0;
        var_t1 = temp_t0;
        break;
    case 2:
        var_v0_2 = 5;
        var_a1 = 0xA;
        var_t1 = temp_t0;
        break;
    case 3:
        var_v0_2 = 8;
        var_a1 = 0x14;
        var_t1 = temp_t0;
        if (temp_t0 < 0x5F) {
            var_t1 = 0x5F;
        }
        break;
    case 4:
    default:
        var_v0_2 = 11;
        var_a1 = 30;
        var_t1 = temp_t0;
        if (temp_t0 < 110) {
            var_t1 = 110;
        }
        break;
    }

    if (var_v1 < var_v0_2) {
        var_v1 = MIN(var_v1 + 5, var_v0_2);
    } else {
        if (var_v0_2 < var_v1) {
            var_v1 = MAX(var_v1 - 1, var_v0_2);
        }
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

    if ((var_a1 + 110) < var_t1) {
        var_v1 -= ((var_t1 - var_a1) - 110) / 5;
    }
    if (var_t1 < 20) {
        var_v1 += (20 - var_t1) / 2;
    }
    temp_t1 = (var_t1 + var_v1) & 0xFF;
    D_803D552C->unk310 = (var_v1 << 8) | temp_t1;
    if (D_803D5538 != 0) {
        var_v1_2 = D_803D554C * 4;
    } else {
        var_v1_2 = 0;
    }

    if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                SFX_UNKNOWN_100,
                ((temp_t1 / 300.0) + 0.25) * 21504.0,
                0,
                (((temp_t1 + var_v1_2) / 300.0) + 0.2),
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0_3 = 1;
        } else {
            var_v0_3 = 0;
        }
        if (var_v0_3 != 0) {
            sp96 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_t1_2 = 1;
    } else {
        var_t1_2 = 0;
    }
    sp96 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x980, (u8) 0, (s16) 0x8A, (s16) 0x43, (s16) 0x5A, (s8) 1, (u8) (var_t1_2 == 0));

done:
    if (sp96 == 0) {
        func_8034B298_75C948(0);
        func_8037FCA8_791358();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        if ((D_803F2ECE == 0) || ((s32) D_803F2ECC < 0x1F)) {
            if (D_803D5538 != 0) {
                var_v0_4 = ((D_803D554C * 0x607) / 20);
            } else {
                var_v0_4 = 0;
            }
            sp86 = var_v0_4;
            func_802B9130_6CA7E0(&sp9C, 0x1DB, 0x128, 0x607, (s16) 0);
            func_802C1830_6D2EE0(0x607, &sp9C);
            func_802B964C_6CACFC();
            D_80203FE0[7].unk4 += sp86;
            D_80203FE0[10].unk4 += sp86;
            D_80203FE0[8].unk4 += sp86;
            D_80203FE0[11].unk4 += sp86;
            D_80203FE0[1].unk4 += sp86;
            D_80203FE0[0].unk4 += sp86 >> 1;
            func_802C4A70_6D6120(712, 0x1DB, 0);
            func_802C56D0_6D6D80(0x28);
            if (D_803D5528->unk3C0.unk0 == 0x10) {
                if (D_803D5528->unk3C0.unk2 < 7) {
                    D_80203FE0[19].unk2 -= (D_803D5528->unk3C0.unk2 * 712) / 6;
                    D_80203FE0[20].unk2 -= (D_803D5528->unk3C0.unk2 * 712) / 6;
                } else if (D_803D5528->unk3C0.unk2 < 0x11) {
                    D_80203FE0[19].unk2 -= ((16 - D_803D5528->unk3C0.unk2) * 712) / 10;
                    D_80203FE0[20].unk2 -= ((16 - D_803D5528->unk3C0.unk2) * 712) / 10;
                }
            }
            func_802C7310_6D89C0();
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(&D_803B3A50_7C5100, &D_803B3A64_7C5114, &D_803B3A78_7C5128, &D_803B3A98_7C5148);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803B3A50_7C5100, &D_803B3A64_7C5114, &D_803B3A78_7C5128, &D_803B3AE0_7C5190);
                break;
            }
        }

        D_80203FE0[7].unk0 = (D_80203FE0[10].unk0 + D_80203FE0[7].unk0) >> 1;
        D_80203FE0[7].unk2 = (D_80203FE0[10].unk2 + D_80203FE0[7].unk2) >> 1;
        D_80203FE0[7].unk4 = (D_80203FE0[10].unk4 + D_80203FE0[7].unk4) >> 1;
        D_80203FE0[8].unk0 = (D_80203FE0[11].unk0 + D_80203FE0[8].unk0) >> 1;
        D_80203FE0[8].unk2 = (D_80203FE0[11].unk2 + D_80203FE0[8].unk2) >> 1;
        D_80203FE0[8].unk4 = (D_80203FE0[11].unk4 + D_80203FE0[8].unk4) >> 1;
        D_80203FE0[13].unk0 = (D_80203FE0[16].unk0 + D_80203FE0[13].unk0) >> 1;
        D_80203FE0[13].unk2 = (D_80203FE0[16].unk2 + D_80203FE0[13].unk2) >> 1;
        D_80203FE0[13].unk4 = (D_80203FE0[16].unk4 + D_80203FE0[13].unk4) >> 1;
        D_80203FE0[14].unk0 = (D_80203FE0[17].unk0 + D_80203FE0[14].unk0) >> 1;
        D_80203FE0[14].unk2 = (D_80203FE0[17].unk2 + D_80203FE0[14].unk2) >> 1;
        D_80203FE0[14].unk4 = (D_80203FE0[17].unk4 + D_80203FE0[14].unk4) >> 1;
        D_80203FE0[0].unk4 -= 0x94;

        func_8038064C_791CFC();
        temp_t8 = (D_803F63E0 * 712) >> 7;
        D_80203FE0[19].unk4 -= ABS(temp_t8);
        D_80203FE0[20].unk4 -= ABS(temp_t8);


        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_7 = D_803F2AA2, (temp_v0_7 == 0)) || (temp_v0_7 == 2) || ((temp_v0_7 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || ((D_803F28E0[D_803F2A98].cameraMode != 3) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (u32) D_803D5530->xPos.w, (u32) D_803D5530->zPos.w, (u32) D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (u32) ((s32) D_803F2EB8 / 4), (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0((s16) ((s32) (D_803D5524->unkBA * 0xC) / 5), 2, 4, 3, 0.08f);

            var_t2 = 0;
            switch (D_803D5530->state) {                   /* switch 2; irregular */
            default:                                /* switch 2 */
                spA4 = FTOFIX32(1.0);
                spA8 = FTOFIX32(1.0);
                break;
            case 22:                                /* switch 2 */
            case 24:                                /* switch 2 */
                temp_t6 = D_803D5540 << 4;
                temp_t9_2 = (temp_t6 & 0xFF) << 5;
                if (temp_t9_2 == 0) {
                    var_t2 = -9;
                }
                temp_a0_4 = ((temp_t6 + 0x80) & 0xFF) << 5;
                if (temp_a0_4 == 0) {
                    var_t2 = 9;
                }
                spA4 = temp_a0_4 + FTOFIX32(1.0);
                spA8 = temp_t9_2 + FTOFIX32(1.0);
                break;
            case 23:                                /* switch 2 */
                temp_t6_2 = D_803D5540 << 6;
                spA8 = (temp_t6_2 & 0xFF) << 6;
                spA4 = ((temp_t6_2 + 0x80) & 0xFF) << 6;
                if (spA8 == 0) {
                    var_t2 = -9;
                }
                if (spA4 == 0) {
                    var_t2 = 9;
                }
                spA8 += FTOFIX32(1.0);
                spA4 += FTOFIX32(1.0);
                break;
            }
            if (var_t2 != 0) {
                temp_t7_2 = -D_803D552C->unk302;
                sp8C = (s16) D_80152C78[(temp_t7_2 + 0x40) & 0xFF] >> 7;
                sp8A = (s16) ((s16) D_80152C78[temp_t7_2 & 0xFF] >> 7);
                sp88 = var_t2;
                create_particle_effect(
                  D_803D5530->xPos.h + ((s32) (((s32) (sp8A * 0x1644) / 304) + (sp8C * var_t2)) >> 8),
                  D_803D5530->zPos.h + ((s32) (((s32) (-sp8C * 0x1644) / 304) + (sp8A * var_t2)) >> 8),
                  D_803D5530->yPos.h + 0x2C,
                  0x15,
                  0,
                  0,
                  (func_8012826C() + 0x30000) & 0x7FFF,
                  30,
                  GPACK_RGBA5551(0, 0, 0, 1),
                  GPACK_RGBA5551(0, 0, 0, 1),
                  0);
            }

            var_t1_4 = MAX(ABS(D_803D5530->xVelocity.h), ABS(D_803D5530->zVelocity.h));
            // temp_t2_4 = D_803D552C;
            sp94 = (D_803D552C->unk308 + D_803D552C->unk30A) - (D_803D5530->yVelocity.h * 0x10);
            if ((D_803D552C->unk366 != 5) && (D_803F2D10.unk0 == 0)) {
                spAC = (s32) var_t1_4;
                func_80300130_7117E0(&sp94, &D_803D552C->unk30A, 0x28, -0x28, (s16) 2, (s16) 2, (s16) (D_803D5530->yVelocity.h * 0x10), (s16) 3);
                var_t1_4 = (s16) spAC;
            } else {
                D_803D552C->unk30A = 0;
                sp94 = D_803D552C->unk30A;
            }
            D_803D552C->unk308 = sp94;
            sp94 = (sp94 - var_t1_4) - (var_t1_4 >> 1);
            D_80203FE0[1].unk4 += (sp94 * 0x3B6) >> 7;
            D_80203FE0[0].unk4 += (sp94 * 0x3B6) >> 8;
            D_80203FE0[19].unk4 += (sp94 * 0x3B6) >> 7;
            D_80203FE0[20].unk4 += (sp94 * 0x3B6) >> 7;
            load_1_tile(D_04007980_F89E0, D_04007780_F87E0);
            func_802C78B0_6D8F60(0, 1, (D_803F2EBC * 0x4C) >> 6, (D_803F2EC0 * 0x4C) >> 6, (D_803F2EC4 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04006C50);
            func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040071C0_F8220);
            func_802C78B0_6D8F60(0, 2, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, &D_04006D70);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) * 0x4C) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) * 0x4C) >> 6, (s32) (((s32) ((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040088F0_F9950); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleRight + 8) * D_803F2EBC) >> 4) * 0x4C) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC0) >> 4) * 0x4C) >> 6, (s32) (((s32) ((D_803D552C->missileScaleRight + 8) * D_803F2EC4) >> 4) * 0x4C) >> 6, D_803F2ED0, 0, 1, 0, &D_040088F0_F9950); }

            i = 0;
            while (D_803B3B28_7C51D8[i] <= D_803D5540) {
              i++;
            }

            var_a0 = MIN(4, D_803D5540 - D_803B3B28_7C51D8[i - 2]);
            if (i & 1) {
                var_v1_3 = ((var_a0 * 0x1DB) >> 4);
            } else {
                var_v1_3 = 0x76 - ((var_a0 * 0x1DB) >> 4);
            }
            // temp_v0_14 = D_803D552C->unk366;
            if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
                var_v1_3 = 0;
            }
            sp92 = ((var_v1_3 * 3) >> 1) - 0x2C;
            D_80203FE0[20].unk4 += sp92;
            if (D_803F2EDD == 0) {
                func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040073C0_F8420);
            }
            D_80203FE0[20].unk4 -= sp92;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, &D_040076E0_F8740); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 0x13, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, &D_040074B0_F8510); }
            gDPSetPrimColor(D_801D9E88++, 0, 0, 0x19, 0x19, 0x19, 0xFF);
            load_1_tile(D_04008540_F95A0, D_04008340_F93A0);
            gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);
            func_802C78B0_6D8F60(7, 8, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, &D_04007CE0_F8D40);
            func_802C78B0_6D8F60(0xD, 0xE, FTOFIX32(1.1875), FTOFIX32(1.1875), FTOFIX32(1.1875), D_803F2ED0, 0, 0, 0, &D_04007B60_F8BC0);
            load_1_tile(D_04008320_F9380, D_04008120_F9180);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(7, 8, FTOFIX32(1.1875), FTOFIX32(1.1875), (((sp94 << 0xA) + FTOFIX32(1.0)) * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040080A0_F9100); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (spA8 * 0x4C) >> 6, (spA8 * 0x4C) >> 6, (spA8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04007EA0_F8F00); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (spA4 * 0x4C) >> 6, (spA4 * 0x4C) >> 6, (spA4 * 0x4C) >> 6, D_803F2ED0, 0, 1, 0, &D_04007EA0_F8F00); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &sp9A, &sp98);
                func_8031A278_72B928(&D_803D552C->unk326, &sp9A, &sp98);

                sp9A = D_803BD5CC_7CEC7C[sp9A];sp98 = D_803BD684_7CED34[sp98];
                func_80356BD8_768288(&D_01002C40, &D_010025A0, sp9A);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04007A20_F8A80);
                func_80356BD8_768288(&D_01002C40, &D_010025A0, sp98);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04007A40_F8AA0);
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp96 == 0) || (sp96 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, (s16) 0x19, (s16) 0xF, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (sp96 == 0) {
        if ((D_803D5528->unk3C0.unk0 == 0x10) && (D_803D5528->unk3C0.unk2 < 0x11)) {
            func_803034D0_714B80(D_803D552C, 1425, 0, 0);
            func_80303D50_715400(D_803D552C, 2);
        } else {
            func_803034D0_714B80(D_803D552C, 1425, 0, 1);
            func_80303990_715040(D_803D552C, 32, 33, 19, 20, 534, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 0x3B6, 712);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/hyena/func_803574E0_768B90.s")
#endif


extern u8 D_803B3948_7C4FF8[];
extern u8 D_803B3960_7C5010[];
extern s16 D_803B3978_7C5028[];
extern s16 D_803B39A0_7C5050[];
extern s16 D_803B39F8_7C50A8[];

extern s16 D_803B3890_7C4F40[];
extern s16 D_803B38C0_7C4F70[];
extern s16 D_803B38D4_7C4F84[];
extern s16 D_803B3904_7C4FB4[];
extern s16 D_803B3934_7C4FE4[];
extern s16 D_803B3860_7C4F10[];


extern Gfx D_04006EE0[];
extern Gfx D_04006AC0[];
extern Gfx D_04006E30[];
extern Gfx D_040069D0[];
extern Gfx D_04008650_F96B0[];
extern Gfx D_040068F0_F7950[];

// HYENA
void func_80358E3C_76A4EC(void) {
    struct061 spA8;
    s16 spA6;
    s16 spA4;
    s16 spA2;
    s16 spA0;

    s16 i;
    s16 var_v1;
    u8 var_v0;
    u8 temp_v0_5;

    s32 scale = FTOFIX32(1.1875);

    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
              D_803D5530->xPos.h,
              D_803D5530->zPos.h,
              D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
              21,
              0,
              0,
              (func_8012826C() + 0x30000) & 0x7FFF,
              30,
              GPACK_RGBA5551(0, 0, 0, 1),
              GPACK_RGBA5551(0, 0, 0, 1),
              0);
        }
        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
        }
    }
    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 != 0) {
            spA2 = 0;
            D_803F2EDD = 0;
            goto done;
          }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    spA2 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x980, 0, 0x8A, 0x43, 0x5A, 1, var_v0 == 0);

done:
    if (spA2 == 0) {
        func_8034B298_75C948(0);
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(0xC8);
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&spA8, 0x1DB, 0x128, 0x468, 0x128);
            func_802BD40C_6CEABC(0x216, 0x164, 0xED, 0x128, 0, 0x78, 0, 0x20, &D_803B3860_7C4F10, &D_803B3890_7C4F40, &D_803B38C0_7C4F70, 0x28D, 0xED, 0xED, 0x128, 0x64, 0xE4, 0x64, 0x84, &D_803B38D4_7C4F84, &D_803B3904_7C4FB4, &D_803B3934_7C4FE4, &spA8, 1);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(712, 0x1DB, 0);
            func_802C56D0_6D6D80(0x28);
            func_8038CCF0_79E3A0(0x164, 0x13, 0x14, -1, -1, -1);
            func_802C7310_6D89C0();

            if (D_803D5528->unk3C0.unk0 == 16) {
                if (D_803D5528->unk3C0.unk2 < 7) {
                    D_80203FE0[19].unk2 -= (D_803D5528->unk3C0.unk2 * 712) / 6;
                    D_80203FE0[20].unk2 -= (D_803D5528->unk3C0.unk2 * 712) / 6;
                } else if (D_803D5528->unk3C0.unk2 < 17) {
                    D_80203FE0[19].unk2 -= (-(D_803D5528->unk3C0.unk2 - 16) * 712) / 10;
                    D_80203FE0[20].unk2 -= (-(D_803D5528->unk3C0.unk2 - 16) * 712) / 10;
                }
            }
        }

        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(&D_803B3948_7C4FF8, &D_803B3960_7C5010, &D_803B3978_7C5028, &D_803B39A0_7C5050);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803B3948_7C4FF8, &D_803B3960_7C5010, &D_803B3978_7C5028, &D_803B39F8_7C50A8);
                break;
            }
        }
        func_8038064C_791CFC();

        D_80203FE0[19].unk4 -= ABS((D_803F63E0 * 712) >> 7);
        D_80203FE0[20].unk4 -= ABS((D_803F63E0 * 712) >> 7);

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) && (D_803F2EDA != 0) && ((D_803D5538 != 0) || (((temp_v0_5 = D_803F2AA2) == 0)) || (temp_v0_5 == 2) || ((temp_v0_5 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            func_8038C230_79D8E0((D_803D5524->unkBA * 0xC) / 5, 2, 4, 3, 0.11f);
            load_1_tile(D_04007980_F89E0, D_04007780_F87E0);
            func_802C78B0_6D8F60(0, 1, (D_803F2EBC * 0x4C) >> 6, (s32) (D_803F2EC0 * 0x4C) >> 6, (s32) (D_803F2EC4 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04006C50);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040071C0_F8220);
            func_802C78B0_6D8F60(0, 2, scale, scale, scale, D_803F2ED0, 0, 0, 0, &D_04006D70);

            i = 0;
            while (D_803D5540 >= D_803B3B28_7C51D8[i]) { i += 1; }

            var_v1 = MIN(4, D_803D5540 - D_803B3B28_7C51D8[i - 1]);
            if (i & 1) {
                spA0 = (       (var_v1 * 475) >> 4);
            } else {
                spA0 = (118 - ((var_v1 * 475) >> 4));
            }
            spA0 = (((spA0) * 3) >> 1) - 0x2C;
            D_80203FE0[20].unk4 += spA0;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_040073C0_F8420); }
            D_80203FE0[20].unk4 -= spA0;
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_040076E0_F8740); }
            func_802C78B0_6D8F60(1, 19, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_040074B0_F8510);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(3, 7, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_04006EE0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(5, 13, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_04006AC0); }

            func_802C78B0_6D8F60(7,   8, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_04006E30);
            func_802C78B0_6D8F60(13, 14, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_040069D0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(4, 10, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_04006EE0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(6, 16, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_04006AC0); }
            func_802C78B0_6D8F60(10, 11, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_04006E30);
            func_802C78B0_6D8F60(16, 17, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_040069D0);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(8,  9,  scale, scale, scale, D_803F2ED0, 0, 0, 0, D_04008650_F96B0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(14, 15, scale, scale, scale, D_803F2ED0, 0, 0, 0, D_040068F0_F7950); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(11, 12, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_04008650_F96B0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(17, 18, scale, scale, scale, D_803F2ED0, 0, 1, 0, D_040068F0_F7950); }
            if (D_803F2EDD == 0) {
                func_8031A150_72B800(D_803D552C->unk326++, &spA6, &spA4);
                func_8031A278_72B928(&D_803D552C->unk326,  &spA6,  &spA4);
                spA6 = D_803BD5CC_7CEC7C[spA6]; spA4 = D_803BD684_7CED34[spA4];
                func_80356BD8_768288(&D_01002C40, &D_010025A0, spA6);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04007A20_F8A80);
                func_80356BD8_768288(&D_01002C40, &D_010025A0, spA4);
                func_802C78B0_6D8F60(19, 20, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, (D_803F2EC8 * 0x4C) >> 6, D_803F2ED0, 0, 0, 0, &D_04007A40_F8AA0);
            }
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((spA2 == 0) || (spA2 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, (s16) 0x19, (s16) 0xF, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (spA2 == 0) {
        func_803034D0_714B80(D_803D552C, 1425, 0, 1);
        if ((D_803D5528->unk3C0.unk0 == 0x10) && (((D_803D5528->unk3C0.unk2 < 9)))) {
            func_80303820_714ED0(D_803D552C, 19, 20, (-(D_803D5528->unk3C0.unk2 - 9) * 356) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else if ((D_803D5528->unk3C0.unk0 == 0x10) && (((D_803D5528->unk3C0.unk2 < 0x10)))) {
            func_80303820_714ED0(D_803D552C, 19, 20, ((D_803D5528->unk3C0.unk2 - 7) * 356) >> 3, 0);
            func_80303D50_715400(D_803D552C, 3);
        } else {
            func_80303990_715040(D_803D552C, 32, 33, 19, 20, 356, 0);
            func_80303D50_715400(D_803D552C, 3);
        }
    } else {
        func_80303D00_7153B0(D_803D552C, 0x3B6, 712);
    }
    if ((D_803D5538 == 0) && (D_803D552C->unk2EC > 0)) {
        func_8037E1C4_78F874();
        func_80380620_791CD0(D_803D552C, 15, 12, 40, 10);
        D_803D552C->unk2EC--;
    }
}

// hyena
void func_8035A130_76B7E0(void) {
    func_8037E1C4_78F874();
    func_80380620_791CD0(D_803D552C, 15, 12, 40, 10);
}

void func_8035A170_76B820(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
    } else {
        func_8037D994_78F044(24);
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
    }
}

// hyena biker
void func_8035A2A8_76B958(void) {
    Animal *animal;
    s16 tmp;

    animal = func_8037E9AC_79005C();

    if (func_8037FBBC_79126C()) {
        tmp = 712;
    } else {
        tmp = -713;
    }

    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        5,
        ((u8)D_803D552C->unk302 * 360) >> 8,
        animal,
        2,
        40,
        0.25f,
        200,
        8,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void biker_hyena_fire_missile(Animal *animal) {
    s16 tmp;

    if (func_8037FBBC_79126C()) {
        tmp = 712;
    } else {
        tmp = -713;
    }

    fire_homing_missile(
        D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
        D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
        D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
        5,
        ((u8)D_803D552C->unk302 * 360) >> 8,
        animal,
        3,
        40,
        0.25f,
        200,
        8,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
}

void func_8035A590_76BC40(s16 arg0) {
    D_803D552C->unk2EC = arg0;
}

void func_8035A5A4_76BC54(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 24;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
