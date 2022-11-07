#include <ultra64.h>
#include "common.h"


extern u8 D_803B5028_7C66D8[];
extern u8 D_803B5034_7C66E4[];

extern s16 D_803B5040_7C66F0[];
extern s16 D_803B5054_7C6704[];
extern s16 D_803B5080_7C6730[];

extern Gfx D_04005E50_E3410[];
extern  u8 D_04006DE0[];
extern  u8 D_04006BD0[];

extern Gfx D_04006860[];
extern Gfx D_040070F0_E46B0[];
extern Gfx D_040062D0_E3890[];
extern Gfx D_04006170_E3730[];
extern Gfx D_04006B80_E4140[];

#if 0
void func_80374C70_786320(void) {
    struct061 sp120;
    s16 sp11E;
    s16 sp106;
    f32 spFC;

    f32 temp_f0_2;
    f32 var_f16;
    f64 temp_f0;

    s16 temp_a0_2;
    s16 temp_a0_3;

    s16 xPos;
    s16 temp_t2_2;
    s16 zPos;
    s16 temp_t5;

    s16 temp_v0_5;

    s16 temp_v1_8;
    s32 var_a0;

    s16 var_v0_6;
    s16 var_v0_8;
    s16 var_v1_5;

    s32 temp_a1_2;

    s32 temp_t5_2;
    s32 temp_t7;
    s32 temp_t9;

    s32 var_t1_3;
    s32 var_v0_3;

    u8 temp_v0_7;
    u8 temp_v1_5;
    s32 var_v0_12;



    if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) > 10) {
        if ((D_803D5530->yPos.h + 0x60) < (func_8031124C_7228FC(D_803D5530->xPos.h + ((D_803D5530->xVelocity.h * 3) >> 1), D_803D5530->zPos.h + ((D_803D5530->zVelocity.h * 3) >> 1)) >> 0x10)) {
            // rebound
            D_803D5530->xVelocity.h = -D_803D5530->xVelocity.h >> 1;
            D_803D5530->zVelocity.h = -D_803D5530->zVelocity.h >> 1;
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }
    if (D_803F2DA2 != 2) {
        if (D_803D5530->yVelocity.h >= 0x3D) {
            D_803D5530->yVelocity.h -= 2;
        }
        if (D_803D5530->yVelocity.h >= 0x33) {
            D_803D5530->yVelocity.h -= 2;
        }
        if (D_803D5530->yVelocity.h >= 0x29) {
            D_803D5530->yVelocity.h -= 2;
        }
        if (D_803D5530->yVelocity.h >= 0x1F) {
            D_803D5530->yVelocity.h -= 2;
        }
        if (D_803D5530->yVelocity.h >= 0x15) {
            D_803D5530->yVelocity.h -= 2;
        }
    }
    if (D_803D552C->unk366 == 1) {
        if (D_803D554C != 0) {
            if (D_803D5530->unk4A == 0) {
                func_8032CD70_73E420(
                  (u8*)D_803D5530 + 0x13,
                  100,
                  ((D_803D554C / 60.0) + .7) * 20992.0,
                  0,
                  (((D_80152C78[(s16)(D_803D5540 << 5) & 0xFF] >> 7) / 2048.0) + (0.7 + (D_803D554C / 30.0))) / 1.5,
                  D_803D5530->xPos.h,
                  D_803D5530->zPos.h,
                  D_803D5530->yPos.h);
            }
        }
    }
    if (D_803D5538 != 0) {
        if ((D_803D5530->unk162 == 5) && (D_803D5530->unk4A == 0)) {

            temp_f0_2 = (f32)((MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w)) / 2) + MIN(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w))) / 1000000.0;
            func_8032CD70_73E420(
                (u8*) D_803D5530 + 0x14,
                0xC,
                (temp_f0_2 * 20480.0f) / 3.0,
                0,
                temp_f0_2 + 1.0,
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }
    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        if (!(D_803D5540 & 1)) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h,
                0x40,
                ((SSSV_RAND(0x8000) * 2) - FTOFIX32(0.6103515625)),
                ((SSSV_RAND(0x8000) * 2) - FTOFIX32(0.6103515625)),
                0,
                (SSSV_RAND(4) + 0x1F),
                0,
                0,
                (SSSV_RAND(16) + 0x44));
        }

        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
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
            sp11E = 0;
            D_803F2EDD = 0;
            goto block_63;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_t1_3 = 1;
    } else {
        var_t1_3 = 0;
    }
    sp11E = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x1570, (u8) 5, (s16) 0x32, (s16) 0x32, (s16) 0x78, (s8) 1, var_t1_3 == 0);

block_63:
    if (sp11E == 0) {
        func_8037FCA8_791358();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8034B64C_75CCFC(0x17, 0x1C, 0xB);
        D_803F2EBC = ((D_803F2EB0 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC0 = ((D_803F2EB4 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        D_803F2EC4 = ((D_803F2EB8 - FTOFIX32(1.0)) >> 2) + FTOFIX32(1.0);
        func_8035D734_76EDE4();
        func_8034BB38_75D1E8(200);
        if ((D_803F2ECE == 0) || ((s32) D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp120, 0x23E, 0x132, 0x2FD, (s16) 0);
            func_802C1830_6D2EE0(0x2FD, &sp120);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x396, 0x264, 6);

            D_80203FE0[19].unk2 = (((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3) + D_80203FE0[1].unk2;
            D_80203FE0[19].unk4 = (((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4;

            D_80203FE0[20].unk2 = (D_80203FE0[20].unk2 + ((((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3) + D_80203FE0[1].unk2)) - D_80203FE0[19].unk2;
            D_80203FE0[20].unk4 = (D_80203FE0[20].unk4 + ((((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4)) - D_80203FE0[19].unk4;

            func_8038CCF0_79E3A0(0x72, 0x13, 0x14, -1, -1, -1);

            D_80203FE0[26].unk0 = (D_80203FE0[8].unk0 + D_80203FE0[11].unk0) >> 1;
            D_80203FE0[26].unk2 = (D_80203FE0[8].unk2 + D_80203FE0[11].unk2) >> 1;
            D_80203FE0[26].unk4 = (D_80203FE0[8].unk4 + D_80203FE0[11].unk4) >> 1;

            D_80203FE0[14].unk2 += (D_80203FE0[3].unk4 - D_80203FE0[5].unk4) >> 1;
            D_80203FE0[5].unk2 -= (D_80203FE0[3].unk4 - D_80203FE0[5].unk4) >> 1;

            D_80203FE0[17].unk2 += (D_80203FE0[4].unk4 - D_80203FE0[6].unk4) >> 1;
            D_80203FE0[6].unk2 -= (D_80203FE0[4].unk4 - D_80203FE0[6].unk4) >> 1;

            D_80203FE0[26].unk2 += (D_80203FE0[1].unk4 - D_80203FE0[2].unk4) >> 1;
            D_80203FE0[1].unk2 -= (D_80203FE0[1].unk4 - D_80203FE0[2].unk4) >> 1;
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(&D_803B5028_7C66D8, &D_803B5034_7C66E4, &D_803B5040_7C66F0, &D_803B5054_7C6704);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803B5028_7C66D8, &D_803B5034_7C66E4, &D_803B5040_7C66F0, &D_803B5080_7C6730);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 0x1E) < 0xFA) &&
            (D_803F2EDA != 0) && ((temp_v0_7 = D_803D5538, (temp_v0_7 != 0)) || (temp_v1_5 = D_803F2AA2, (temp_v1_5 == 0)) || (temp_v1_5 == 2) || ((temp_v1_5 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (temp_v0_7 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, (s16) (s32) -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (s32) D_803F2EB8 / 4, (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 4) / 5, 1, 2, 2, 0.4f);
            if ((D_803F2DA2 == 4) && (D_803D5538 == 0)) {
                if (D_803D553C == 1) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x5C, 0xAA, 0x79, 0xFF); // greenish
                } else if (D_803D553C == 2) {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xC8, 0x8C, 0x00, 0xFF); // orangeish
                } else {
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x5C, 0x5C, 0xD7, 0xFF); // purpleish
                }
            } else {
                gDPSetPrimColor(D_801D9E88++, 0, 0, 0x5C, 0x5C, 0xD7, 0xFF);
            }
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x62) >> 6, (D_803F2EC0 * 0x62) >> 6, (D_803F2EC4 * 0x62) >> 6, D_803F2ED0, 0, 0, 0, &D_04005E50_E3410);
            load_1_tile(&D_04006DE0, &D_04006BD0);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x62) >> 6, (D_803F2EC8 * 0x62) >> 6, (D_803F2EC8 * 0x62) >> 6, D_803F2ED0, 0, 0, 0, &D_04006860);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) * 0x62) >> 6, D_803F2ED0, 0, 0, 0, &D_040070F0_E46B0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleRight + 8) * D_803F2EBC) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC0) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC4) >> 4) * 0x62) >> 6, D_803F2ED0, 0, 1, 0, &D_040070F0_E46B0); }

            if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) >= 3) {

                var_v0_6 = D_803D552C->zVelocity.h;
                temp_v1_8 = D_803D552C->xVelocity.h;
                if (var_v0_6 == 0) {
                    var_v0_6 = 1; // avoid divide by zero
                }
                if (temp_v1_8 > 0) {
                    if (var_v0_6 > 0) {
                        var_a0 = 180 - func_8012844C((temp_v1_8 << 6) / var_v0_6);
                    } else {
                        var_a0 = 0 - func_8012844C((temp_v1_8 << 6) / var_v0_6);
                    }
                } else if (var_v0_6 > 0) {
                    var_a0 = 180 - func_8012844C((temp_v1_8 << 6) / var_v0_6);
                } else {
                    var_a0 = 360 - func_8012844C((temp_v1_8 << 6) / var_v0_6);
                }
                var_v1_5 = ((((((var_a0 - 0x21C) * -0x100)) / 360) & 0xFF) - D_803D552C->unk302) >> 1;
            } else {
                var_v1_5 = 0;
            }

            if (D_803D552C->unk30C < var_v1_5) {
                D_803D552C->unk30C = MIN(D_803D552C->unk30C + 3, var_v1_5);
            } else if (var_v1_5 < D_803D552C->unk30C) {
                D_803D552C->unk30C = MAX(D_803D552C->unk30C - 3, var_v1_5);
            }
            if (D_803D552C->unk30C > 32) {
                D_803D552C->unk30C = 32;
            }
            if (D_803D552C->unk30C < -32) {
                D_803D552C->unk30C = -32;
            }
            func_802C78B0_6D8F60(1, 0x1A, 0x18800, 0x18800, 0x18800, D_803F2ED0, (-D_803D552C->unk30C & 0xFF), 0, 0, &D_040062D0_E3890);
            func_802C78B0_6D8F60(5, 0xE, 0x18800, 0x18800, 0x18800, D_803F2ED0, 0, 0, 0, &D_04006170_E3730);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            func_802C78B0_6D8F60(6, 0x11, 0x18800, 0x18800, 0x18800, D_803F2ED0, 0, 1, 0, &D_04006170_E3730);

            switch (D_803D5530->state) {                   /* switch 1; irregular */
            case 0x16:                              /* switch 1 */
            case 0x8E:                              /* switch 1 */
                var_v0_8 = 0x40;
                break;
            case 0x17:                              /* switch 1 */
            case 0x8F:                              /* switch 1 */
                var_v0_8 = 0x60;
                break;
            case 0x18:                              /* switch 1 */
                var_v0_8 = -0x30;
                break;
            default:                                /* switch 1 */
                var_v0_8 = 8;
                if (D_803D552C->unk308 < 0) {
                    var_v0_8 = -8;
                }
                break;
            }

            if (D_803D552C->unk308 < var_v0_8) {
                D_803D552C->unk308 = MIN(var_v0_8, D_803D552C->unk308 + 3);
            } else if (var_v0_8 < D_803D552C->unk308) {
                D_803D552C->unk308 = MAX(var_v0_8, D_803D552C->unk308 - 1);
            }

            spFC = MAX(0.0, MIN(1.0, (ABS(D_803D552C->unk308) - 8) / 88.0));

            sp106 = D_803D552C->unk30A;

            D_803D552C->unk30A += (ABS(D_803D552C->unk308) >> 2);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 2, 0x18800, 0x18800, 0x18800, D_803F2ED0, D_803D552C->unk30A, (u8) 0, (u8) 0, &D_04006B80_E4140); }

            // Error: Unable to determine a value for double-precision register $f16 whose second half is non-static. This is a m2c restriction which may be lifted in the future.
            // At instruction: c.eq.d $f16, $f12
            // if (M2C_ERROR()) {

            if (spFC == 0.0) {
                if ((D_803D5530->unk4A == 0) && ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1))) {
                    func_8032CED0_73E580(D_803D5530, 0x1F, (spFC * 14336.0f), MAX(0.1, ABS(D_803D552C->unk308 / 40.0)), (s16) 0, (s16) (s32) D_803D5538, (s16) (s32) D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, (s16) D_803D5530->xVelocity.w, (s16) D_803D5530->zVelocity.w, (s16) D_803D5530->yVelocity.w);
                }
            }
            if (spFC != 0.0) {
                var_f16 = (0.0 - spFC);
                if (var_f16 > 0.8) {
                    var_f16 = (f32) (0.0 - ((var_f16 - 0.8) * 4.0));
                }
                if ((((D_803D552C->unk30A * 4) & 0xFF) < ((sp106 * 4) & 0xFF)) && (((D_803D552C->unk366 == 3)) || (D_803D552C->unk366 == 1))) {
                    play_sound_effect_at_location(0, (var_f16 * 20480.0f), 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, ((ABS(D_803D552C->unk308) - 8) * 0.02) + 0.7);
                }
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

            xPos = D_803D5530->xPos.h;
            zPos = D_803D5530->zPos.h;

            var_v0_12 = MAX(MAX(D_803C0740[(xPos >> 6) + 0][(zPos >> 6) + 0].unk6, D_803C0740[(xPos >> 6) + 1][(zPos >> 6) + 0].unk6),
                            MAX(D_803C0740[(xPos >> 6) + 0][(zPos >> 6) + 1].unk6, D_803C0740[(xPos >> 6) + 1][(zPos >> 6) + 1].unk6));

            temp_a1_2 = ((D_803C0430.unk0[((xPos * zPos) & 7)][((D_803C0430.unk204 + (((xPos * zPos) + (xPos * xPos)) * 8)) & 0x3F)]) + (var_v0_12 * 4)) - D_803D5530->yPos.h;

            if (ABS(temp_a1_2) < 0x30) {
                func_8039DFD4_7AF684(D_803D5530, 1, 0xA, 0x10, 0, -0xA, 0, 0xFF, 0xFF, 0xFF, 0, 0xB9, 0xFF, 1, 2, D_803D5530);
                func_8039DFD4_7AF684(D_803D5530, 2, 0xA, 0x10, 0, -0xA, 0, 0xFF, 0xFF, 0xFF, 0, 0xB9, 0xFF, 1, 2, (Animal *) &D_803D5530->unk270);
            }
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp11E == 0) || (sp11E == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, (s16) 0x1F, (s16) 0x15, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }
    if (sp11E == 0) {
        func_803034D0_714B80(D_803D552C, 0x47C, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, (u16) 0x14, (u16) 0x1CB, (u16) 0);
        func_80303D50_715400(D_803D552C, 3);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x6BA, 0x264);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/walrus/func_80374C70_786320.s")
#endif

void func_803766E8_787D98(void) {
    s32 phi_v1;
    s16 tmp;

    if (D_803D5530->state < 26) {
        if (D_803D5530->state == 21) {
            func_8037D9D4_78F084();
        } else {
            func_8037D994_78F044(24);
        }
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
                1,
                1,
                0);
        }
    } else {
        if (D_803D5530->state == 141) {
            func_8037D9D4_78F084();
        } else {
            func_8037D994_78F044(16);
        }

        phi_v1 = MAX(MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 0].unk6,
                         D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 0].unk6),
                     MAX(D_803C0740[(D_803D5530->xPos.h >> 6) + 0][(D_803D5530->zPos.h >> 6) + 1].unk6,
                         D_803C0740[(D_803D5530->xPos.h >> 6) + 1][(D_803D5530->zPos.h >> 6) + 1].unk6));

        tmp = D_803C0430.unk0[(D_803D5530->xPos.h * D_803D5530->zPos.h) & 7][(u16)(D_803C0430.unk204 + (((D_803D5530->xPos.h * D_803D5530->zPos.h) + (D_803D5530->xPos.h * D_803D5530->xPos.h)) << 3)) & 63] + (4 * phi_v1);
        phi_v1 = ABS(tmp - D_803D5530->yPos.h);
        if (phi_v1 < 48) {
            func_8039DFD4_7AF684(D_803D5530, 1, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, D_803D5530);
            func_8039DFD4_7AF684(D_803D5530, 2, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, ((struct071*)D_803D5530) + 1);
        }
    }
}

void func_803769E0_788090(void) {
    Animal *animal;
    s32 tmp;

    animal = func_8037E9AC_79005C();
    // twist animal Z based on missile side fired?
    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    fire_homing_missile(D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8, // divide by 256
                         animal,
                         1, 17, 0.7f, 110, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    apply_recoil(2);
    do_rumble(0, 25, 30, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
}

void walrus_fire_missile(Animal *arg0) {
    s32 tmp;

    if (func_8037FBBC_79126C() != 0) {
        tmp = 861;
    } else {
        tmp = -861;
    }

    fire_homing_missile(D_803D5530->xPos.h + ((((D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->zPos.h - ((((D_80152C78[(u8)D_803D552C->unk302] >> 7) * tmp) / 32) >> 8),
                         D_803D5530->yPos.h + (D_803D5530->unk42 >> 1),
                         20,
                         ((u8)D_803D552C->unk302 * 360) >> 8,
                         arg0,
                         2, 17, 0.7f, 120, 96,
                         D_803D5530->xVelocity.h, D_803D5530->zVelocity.h, D_803D5530->yVelocity.h, D_803D5530);
    apply_recoil(2);
}

void walrus_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 24;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
