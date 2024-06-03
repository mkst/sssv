#include <ultra64.h>
#include "common.h"


extern u8 D_803B5028_7C66D8[];
extern u8 D_803B5034_7C66E4[];

extern s16 D_803B5040_7C66F0[];
extern s16 D_803B5054_7C6704[];
extern s16 D_803B5080_7C6730[];

extern Gfx D_04005E50_E3410[];
extern  u8 D_04006DE0[];
extern  u8 D_04006BD0_E4190[];

extern Gfx D_04006860[];
extern Gfx D_040070F0_E46B0[];
extern Gfx D_040062D0_E3890[];
extern Gfx D_04006170_E3730[];
extern Gfx D_04006B80_E4140[];

#if 0
// CURRENT (1633)
void func_80374C70_786320(void) {
    s32 pad[0x2];

    struct061 sp120;
    s16 sp11E;

    s32 pad2[0x2];

    s16 temp_v1_8;
    s32 var_a0;

    s16 pad3[2];

    s16 sp106;

    s32 temp_a1_2;
    f32 spFC;

    s16 var_v0_6;
    s16 var_v0_8;
    s16 var_v1_5;

    u8 temp_v0_7;

    f32 var_f16;
    f32 temp_f0_2;

    if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) > 10) {
        if ((D_803D5530->position.yPos.h + 0x60) < (func_8031124C_7228FC(D_803D5530->position.xPos.h + ((D_803D5530->xVelocity.h * 3) >> 1), D_803D5530->position.zPos.h + ((D_803D5530->zVelocity.h * 3) >> 1)) >> 0x10)) {
            // rebound
            D_803D5530->xVelocity.h = -D_803D5530->xVelocity.h >> 1;
            D_803D5530->zVelocity.h = -D_803D5530->zVelocity.h >> 1;
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }
    if (D_803F2D50.unk52 != 2) {
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
                  (0.7 + (D_803D554C / 60.0)) * 20992.0,
                  0,
                  ((.7 + (D_803D554C / 30.0)) + ((SIN(D_803D5540 << 5) >> 7) / 2048.0)) / 1.5,
                  D_803D5530->position.xPos.h,
                  D_803D5530->position.zPos.h,
                  D_803D5530->position.yPos.h);
            }
        }
    }
    if (D_803D5538 != 0) {
        if ((D_803D5530->unk162 == 5) && (D_803D5530->unk4A == 0)) {
            temp_f0_2 = (f32)(MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w)) + (MIN(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w)) / 2));
            temp_f0_2 = temp_f0_2 / 1000000.0;
            func_8032CD70_73E420(
                (u8*) D_803D5530 + 0x14,
                0xC,
                (temp_f0_2 * 20480.0f) / 3.0,
                0,
                temp_f0_2 + 1.0,
                D_803D5530->position.xPos.h,
                D_803D5530->position.zPos.h,
                D_803D5530->position.yPos.h);
        }
    }
    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        if (!(D_803D5540 & 1)) {
            create_particle_effect(
                D_803D5530->position.xPos.h,
                D_803D5530->position.zPos.h,
                D_803D5530->position.yPos.h,
                0x40,
                ((SSSV_RAND(0x8000) * 2) - FTOFIX32(0.6103515625)),
                ((SSSV_RAND(0x8000) * 2) - FTOFIX32(0.6103515625)),
                0,
                (SSSV_RAND(4) + 0x1F),
                GPACK_RGBA5551(0, 0, 0, 0),
                GPACK_RGBA5551(0, 0, 0, 0),
                (SSSV_RAND(16) + 0x44));
        }

        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
        }
    }

    if ((D_803D5538 != 0) && (CHECK_SEGMENT != 0)) {
        sp11E = 0;
        D_803F2EDD = 0;
    } else {
        sp11E = func_802E89F0_6FA0A0(D_803D552C->position.xPos.w, D_803D552C->position.zPos.w, D_803D552C->position.yPos.w + (D_803D5524->unkBA << 0xF), 0x1570, 5, 0x32, 0x32, 0x78, 1, CHECK_SEGMENT == 0);
    }

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
        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp120, 0x23E, 0x132, 0x2FD, 0);
            func_802C1830_6D2EE0(0x2FD, &sp120);
            func_802B964C_6CACFC();
            func_802C4A70_6D6120(0x396, 0x264, 6);

#if 0
{
            D_80203FE0[19].unk2 = (((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3) + D_80203FE0[1].unk2;
            D_80203FE0[19].unk4 = (((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4;

            D_80203FE0[20].unk2 = (D_80203FE0[20].unk2 + ((((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3) + D_80203FE0[1].unk2)) - D_80203FE0[19].unk2;
            D_80203FE0[20].unk4 = (D_80203FE0[20].unk4 + ((((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4)) - D_80203FE0[19].unk4;

}
#else
            D_80203FE0[20].unk2 += (D_80203FE0[1].unk2 + (((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3)) - D_80203FE0[19].unk2;
            D_80203FE0[20].unk4 += ((((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4) - D_80203FE0[19].unk4;

            D_80203FE0[19].unk2 = (((D_80203FE0[2].unk4 - D_80203FE0[1].unk4) * 6) >> 3) + D_80203FE0[1].unk2;
            D_80203FE0[19].unk4 = (((D_80203FE0[1].unk2 - D_80203FE0[2].unk2) * 6) >> 3) + D_80203FE0[1].unk4;
#endif
            func_8038CCF0_79E3A0(114, 19, 20, -1, -1, -1);

            D_80203FE0[26].unk0 = (D_80203FE0[8].unk0 + D_80203FE0[11].unk0) >> 1;
            D_80203FE0[26].unk2 = (D_80203FE0[8].unk2 + D_80203FE0[11].unk2) >> 1;
            D_80203FE0[26].unk4 = (D_80203FE0[8].unk4 + D_80203FE0[11].unk4) >> 1;

            D_80203FE0[14].unk2 += (D_80203FE0[3].unk4 - D_80203FE0[5].unk4) >> 1;
            D_80203FE0[5].unk2  -= (D_80203FE0[3].unk4 - D_80203FE0[5].unk4) >> 1;

            D_80203FE0[17].unk2 += (D_80203FE0[4].unk4 - D_80203FE0[6].unk4) >> 1;
            D_80203FE0[6].unk2  -= (D_80203FE0[4].unk4 - D_80203FE0[6].unk4) >> 1;

            D_80203FE0[26].unk2 += (D_80203FE0[1].unk4 - D_80203FE0[2].unk4) >> 1;
            D_80203FE0[1].unk2  -= (D_80203FE0[1].unk4 - D_80203FE0[2].unk4) >> 1;
        }

        if (D_803F2ECC != 0) {
            backup_joint_positions();

            switch (D_803F2ECE) {                    /* irregular */
            case 1:
                func_802DB670_6ECD20(D_803B5028_7C66D8, D_803B5034_7C66E4, D_803B5040_7C66F0, D_803B5054_7C6704);
                break;
            case 2:
                func_802DB670_6ECD20(D_803B5028_7C66D8, D_803B5034_7C66E4, D_803B5040_7C66F0, D_803B5080_7C6730);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) && ((temp_v0_7 = D_803D5538, (temp_v0_7 != 0)) || (D_803F2AA2 == 0) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (temp_v0_7 == 0) || ((gCameras[gCameraId].cameraMode != 3) && (gCameras[gCameraId].cameraMode != 0x11)) || (gCameras[gCameraId].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->position.xPos.w, D_803D5530->position.zPos.w, D_803D5530->position.yPos.w, -D_803D552C->heading, D_803F2EB0 / 4, D_803F2EB4 / 4, D_803F2EB8 / 4, D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            func_8038C230_79D8E0((D_803D5524->unkBA * 4) / 5, 1, 2, 2, 0.4f);
            if ((D_803F2D50.unk52 == 4) && (D_803D5538 == 0)) {
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
            func_802C78B0_6D8F60(1, 2, (D_803F2EBC * 0x62) >> 6, (D_803F2EC0 * 0x62) >> 6, (D_803F2EC4 * 0x62) >> 6, D_803F2ED0, 0, 0, 0, D_04005E50_E3410);
            load_1_tile(D_04006DE0, D_04006BD0_E4190);
            func_802C78B0_6D8F60(0x13, 0x14, (D_803F2EC8 * 0x62) >> 6, (D_803F2EC8 * 0x62) >> 6, (D_803F2EC8 * 0x62) >> 6, D_803F2ED0, 0, 0, 0, D_04006860);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EBC) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC0) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleLeft + 8) * D_803F2EC4) >> 4) * 0x62) >> 6, D_803F2ED0, 0, 0, 0, D_040070F0_E46B0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, ((((D_803D552C->missileScaleRight + 8) * D_803F2EBC) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC0) >> 4) * 0x62) >> 6, ((((D_803D552C->missileScaleRight + 8) * D_803F2EC4) >> 4) * 0x62) >> 6, D_803F2ED0, 0, 1, 0, D_040070F0_E46B0); }

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
                var_a0 = (((-(var_a0 - 540) * 256)) / 360) & 0xFF;
                var_v1_5 = (var_a0 - D_803D552C->heading) >> 1;
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
            func_802C78B0_6D8F60(1, 0x1A, 0x18800, 0x18800, 0x18800, D_803F2ED0, (-D_803D552C->unk30C & 0xFF), 0, 0, D_040062D0_E3890);
            func_802C78B0_6D8F60(5, 0xE, 0x18800, 0x18800, 0x18800, D_803F2ED0, 0, 0, 0, D_04006170_E3730);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BACK);
            gSPSetGeometryMode(D_801D9E88++, G_CULL_FRONT);
            func_802C78B0_6D8F60(6, 0x11, 0x18800, 0x18800, 0x18800, D_803F2ED0, 0, 1, 0, D_04006170_E3730);

            switch (D_803D5530->state) {
            case 0x16:
            case 0x8E:
                var_v0_8 = 0x40;
                break;
            case 0x17:
            case 0x8F:
                var_v0_8 = 0x60;
                break;
            case 0x18:
                var_v0_8 = -0x30;
                break;
            default:
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

            D_803D552C->unk30A += ABS(D_803D552C->unk308) >> 2;

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 2, 0x18800, 0x18800, 0x18800, D_803F2ED0, D_803D552C->unk30A, 0, 0, D_04006B80_E4140); }
            spFC = SQ(spFC);
            if ((spFC != 0.0) && (D_803D5530->unk4A == 0) && ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1))) {
                func_8032CED0_73E580(D_803D5530, SFX_UNKNOWN_31, (spFC * 14336.0f), MAX(0.1, ABS(D_803D552C->unk308 / 40.0)), 0, D_803D5538, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->xVelocity.w, D_803D5530->zVelocity.w, D_803D5530->yVelocity.w);
            }

            if ((spFC != 1.0)) {
                var_f16 = (1.0 - spFC);
                if (var_f16 > 0.8) {
                    var_f16 = (f32) (1.0 - ((var_f16 - 0.8) * 4.0));
                }
                if ((((D_803D552C->unk30A * 4) & 0xFF) < ((sp106 * 4) & 0xFF)) && (((D_803D552C->unk366 == 3)) || (D_803D552C->unk366 == 1))) {
                    play_sound_effect_at_location(0, (var_f16 * 20480.0f), 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, ((ABS(D_803D552C->unk308) - 8) * 0.02) + 0.7);
                }
            }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

            temp_a1_2 = (4 * GET_WATER_LEVEL(D_803C0740, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h)) + (D_803C0430.unk0[(D_803D5530->position.xPos.h * D_803D5530->position.zPos.h) & 7][(u16)(D_803C0430.unk204 + (((D_803D5530->position.xPos.h * D_803D5530->position.zPos.h) + (D_803D5530->position.xPos.h * D_803D5530->position.xPos.h)) << 3)) & 63])  ;
            if (ABS(temp_a1_2 - D_803D5530->position.yPos.h) < 0x30) {
                add_walrus_wake(D_803D5530, 1, 0xA, 0x10, 0, -0xA, 0, 0xFF, 0xFF, 0xFF, 0, 0xB9, 0xFF, 1, 2, D_803D5530);
                add_walrus_wake(D_803D5530, 2, 0xA, 0x10, 0, -0xA, 0, 0xFF, 0xFF, 0xFF, 0, 0xB9, 0xFF, 1, 2, &D_803D5530->unk270);
            }
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp11E == 0) || (sp11E == 2)) {
        func_8034BD20_75D3D0(D_803D552C->position.xPos.h, D_803D552C->position.zPos.h, (D_803D552C->position.yPos.h + (D_803D5524->unkBA >> 1)), D_803D552C->heading, D_01033190_6CA60, 0x1F, 0x15, 0x9B, 0, 0, 0, 0, D_803D5538);
    }
    if (sp11E == 0) {
        func_803034D0_714B80(D_803D552C, 0x47C, 0, 1);
        func_80303990_715040(D_803D552C, 0x20, 0x21, 0x13, 0x14, 0x1CB, 0);
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
            set_target_speed(24);
        }
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->position.xPos.h,
                D_803D5530->position.zPos.h,
                D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 2),
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
            set_target_speed(16);
        }

        phi_v1 = GET_WATER_LEVEL(D_803C0740, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
        tmp = D_803C0430.unk0[(D_803D5530->position.xPos.h * D_803D5530->position.zPos.h) & 7][(u16)(D_803C0430.unk204 + (((D_803D5530->position.xPos.h * D_803D5530->position.zPos.h) + (D_803D5530->position.xPos.h * D_803D5530->position.xPos.h)) << 3)) & 63] + (4 * phi_v1);
        phi_v1 = ABS(tmp - D_803D5530->position.yPos.h);
        if (phi_v1 < 48) {
            add_walrus_wake(D_803D5530, 1, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, D_803D5530);
            add_walrus_wake(D_803D5530, 2, 10, 16, 0, -10, 0, 0xFF, 0xFF, 0xFF, 0, 185, 0xFF, 1, 2, ((struct071*)D_803D5530) + 1);
        }
    }
}

void func_803769E0_788090(void) {
    Animal *target;
    s16 offset;

    target = func_8037E9AC_79005C();

    if (get_missile_side() != 0) {
        offset = 861;
    } else {
        offset = -861;
    }

    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1),
        20,
        ((D_803D552C->heading & 0xFF) * 360) >> 8, // divide by 256
        target,
        1,
        17,
        0.7f,
        110,
        96,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
    apply_recoil(2);
    do_rumble(0, 25, 30, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
}

void walrus_fire_missile(Animal *target) {
    s16 offset;

    if (get_missile_side() != 0) {
        offset = 861;
    } else {
        offset = -861;
    }

    fire_homing_missile(
        D_803D5530->position.xPos.h + ((((COS(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.zPos.h - ((((SIN(D_803D552C->heading) >> 7) * offset) / 32) >> 8),
        D_803D5530->position.yPos.h + (D_803D5530->unk42 >> 1),
        20,
        ((D_803D552C->heading & 0xFF) * 360) >> 8, // divide by 256
        target,
        2,
        17,
        0.7f,
        120,
        96,
        D_803D5530->xVelocity.h,
        D_803D5530->zVelocity.h,
        D_803D5530->yVelocity.h,
        D_803D5530);
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
