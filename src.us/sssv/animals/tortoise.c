#include <ultra64.h>
#include "common.h"

extern u8 D_803A843C_7B9AEC[]; // tbd
extern u8 D_803A8450_7B9B00[];

extern u8 D_803A8380_7B9A30[];
extern u8 D_803A8390_7B9A40[];

extern s16 D_803A83A0_7B9A50[];
extern s16 D_803A83BC_7B9A6C[];
extern s16 D_803A83FC_7B9AAC[];

extern Gfx D_0103AA20[];
extern Gfx D_0103AC20[];
extern Gfx D_0103AC40[];
extern Gfx D_0103B440[];
extern Gfx D_04003030_EA5E0[];
extern Gfx D_040032B0[];
extern Gfx D_040037C0[];
extern Gfx D_040041D0_F5230[];
extern Gfx D_01003AD0_3D3A0[];

extern u8 D_01036C90[];
extern u8 D_01036D90[];
extern u8 D_01036E90[];



// TORTOISE_TANK
#if 0
// 57k away
void func_80352380_763A30(void) {
    s32 sp14C;
    s32 sp148;
    struct061 sp140;
    s16 sp13A;
    s16 sp138;
    s16 sp136;
    s16 sp134;
    s16 sp132;
    s16 sp12E;
    s16 sp12A;
    s16 sp128;
    s16 sp126;

    s16 temp_t9_3;
    s16 temp_v0_7;
    s16 temp_v1_9;

    s16 var_t1;
    s16 var_t2;

    s16 var_v0;
    s32 temp_t0;
    u8  temp_t8;
    s32 temp_t8_4;

    s32 var_a1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t8;
    s32 var_t9;
    s32 var_v1;

    s8 var_a0;
    s8 var_v0_2;
    u8 temp_v0_4;

    s32 xl;
    s32 yl;
    s32 xh;
    s32 yh;
    s32 s;
    s32 t;

    D_803D552C->unk312 = 0;

    var_a0 = D_803D552C->unk310 >> 8;
    temp_t0 = D_803D552C->unk310 & 0xFF;

    if (D_803D5538 != 0) {
        var_v0 = D_801E9EB2;
    } else {
        var_v0 = MIN(D_803D552C->unk368 >> 2, 24);
    }

    switch (var_v0) {
    case 0:
        var_v0_2 = -5;
        var_a2 = 0;
        var_a1 = temp_t0;
        break;
    case 1:
        var_v0_2 = 2;
        var_a2 = 0;
        var_a1 = temp_t0;
        break;
    case 2:
        var_v0_2 = 5;
        var_a2 = 10;
        var_a1 = temp_t0;
        break;
    case 3:
        var_v0_2 = 8;
        var_a2 = 20;
        var_a1 = temp_t0;
        if (var_a1 < 70) {
            var_a1 = 70;
        }
        break;
    case 4: // tbd
    default:
        var_v0_2 = 11;
        var_a2 = 30;
        var_a1 = temp_t0;
        if (var_a1 < 80) {
            var_a1 = 80;
        }
        break;
    }

    if (var_a0 < var_v0_2) {
        var_a0 = MIN(var_a0 + 5, var_v0_2);
    } else if (var_v0_2 < var_a0) {
        var_a0 = MAX(var_a0 - 1, var_v0_2);
    }

    if (var_a0 > 3) {
        var_a0 -= 1;
    }
    if (var_a0 > 6) {
        var_a0 -= 1;
    }
    if (var_a0 < -3) {
        var_a0 += 1;
    }
    if (var_a0 < -6) {
        var_a0 += 1;
    }

    if ((var_a2 + 80) < var_a1) {
        var_a0 -= ((var_a1 - var_a2) - 80) / 5U; // help
    }
    if (var_a1 < 20) {
        var_a0 += (20 - var_a1) / 2;
    }

    temp_t8 = (var_a1 & 0xFF) + var_a0;
    D_803D552C->unk310 = (var_a0 << 8) | temp_t8;

    if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                SFX_UNKNOWN_129,
                ((temp_t8 / 300.0) + 0.3) * 16384.0,
                0,
                (temp_t8 / 200.0) + 0.3,
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
        if (var_v1 != 0) {
            sp128 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        var_t0 = 1;
    } else {
        var_t0 = 0;
    }
    sp128 = func_802E89F0_6FA0A0(D_803D552C->xPos.w, D_803D552C->zPos.w, D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF), 0x740, (u8) 0, (s16) 0, (s16) 0x5A, (s16) 0, (s8) 1, var_t0 == 0);

done:
    if (sp128 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        D_803F2EBC = FTOFIX32(1.0) + ((D_803F2EBC - FTOFIX32(1.0)) >> 1);
        D_803F2EC0 = FTOFIX32(1.0) + ((D_803F2EC0 - FTOFIX32(1.0)) >> 1);
        D_803F2EC4 = FTOFIX32(1.0) + ((D_803F2EC4 - FTOFIX32(1.0)) >> 1);

        if ((D_803F2ECE == 0) || (D_803F2ECC < 0x1F)) {
            func_802B9130_6CA7E0(&sp140, 0x1C5, 0x134, 0x1F2, 0);
            func_802C1830_6D2EE0(0x1F2, &sp140);
            func_802B964C_6CACFC();
            D_803D552C->unk312 = func_8012844C((((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) << 5) / (s32) (D_80203FE0[1].unk2 - D_80203FE0[2].unk2)));
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();

            switch (D_803F2ECE) {                    /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                func_802DB670_6ECD20(D_803A8380_7B9A30, D_803A8390_7B9A40, D_803A83A0_7B9A50, D_803A83BC_7B9A6C);
                break;
            case 2:                                 /* switch 1 */
                func_802DB670_6ECD20(D_803A8380_7B9A30, D_803A8390_7B9A40, D_803A83A0_7B9A50, D_803A83FC_7B9AAC);
                break;
            }
        }
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) && (D_803F2EDA != 0) && (((D_803D5538 != 0)) || (temp_v0_4 = D_803F2AA2, (temp_v0_4 == 0)) || (temp_v0_4 == 2) || ((temp_v0_4 == 1) && ((s32) D_803F2AA3 >= 0xB))) && ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 0x11)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {
            func_80127640(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, -D_803D552C->unk302, (s32) D_803F2EB0 / 4, (s32) D_803F2EB4 / 4, (u32) ((s32) D_803F2EB8 / 4), (s16) (s32) D_803F2ED2, D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            sp136 = 0;
            switch (D_803D5530->state) {
            case 0x16:
            case 0x18:
                sp14C = ((D_803D5540 * 8) & 0xFF) << 5;
                sp148 = (((D_803D5540 * 8) + 0x80) & 0xFF) << 5;
                if (sp14C == 0) {
                    sp136 = -5;
                }
                if (sp148 == 0) {
                    sp136 = 5;
                }
                sp14C += FTOFIX32(1.0);
                sp148 += FTOFIX32(1.0);
                break;
            case 0x17:
                sp14C = ((D_803D5540 * 0x10) & 0xFF) << 6;
                sp148 = (((D_803D5540 * 0x10) + 0x80) & 0xFF) << 6;
                if (sp14C == 0) {
                    sp136 = -5;
                }
                if (sp148 == 0) {
                    sp136 = 5;
                }
                sp14C += FTOFIX32(1.0);
                sp148 += FTOFIX32(1.0);
                break;
            default:
                sp148 = FTOFIX32(1.0);
                break;
            }


            if (sp136 != 0) {
                play_sound_effect_at_location(SFX_UNKNOWN_71, 0x2800, 0, D_803D5530->xPos.h, (s16) (s32) D_803D5530->zPos.h, (s16) (s32) D_803D5530->yPos.h, 1.0f);
                sp13A = D_80152C78[((temp_t9_3 = -D_803D552C->unk302) + 0x40) & 0xFF] >> 7;
                sp138 = D_80152C78[temp_t9_3 & 0xFF] >> 7;
                create_particle_effect(
                  D_803D5530->xPos.h + ((((sp138 * 0xA9E) / 232) + (sp13A * sp136)) >> 8),
                  D_803D5530->zPos.h + ((((-sp13A * 0xA9E) / 232) + (sp138 * sp136)) >> 8),
                  D_803D5530->yPos.h + 0xC,
                  0x15,
                  0,
                  0,
                  (func_8012826C() + 0x30000) & 0x7FFF,
                  0x19,
                  GPACK_RGBA5551(96, 96, 96, 1), // grey
                  GPACK_RGBA5551(96, 96, 96, 1), // grey
                  0);
            }
            // sp14C = sp14C;
            // sp148 = var_t3;
            load_1_tile(&D_04003A50, &D_04003850);
            func_802C78B0_6D8F60(2, 1, (s32) (D_803F2EBC * 0x3A) >> 6, (s32) (D_803F2EC0 * 0x3A) >> 6, (s32) (D_803F2EC4 * 0x3A) >> 6,D_803F2ED0, 0, 0, 0, &D_04002D70);
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (sp14C * 0x3A) >> 6, (sp14C * 0x3A) >> 6, (sp14C * 0x3A) >> 6,D_803F2ED0, 0, 0, 0, &D_04003140); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (sp148 * 0x3A) >> 6, (sp148 * 0x3A) >> 6, (sp148 * 0x3A) >> 6,D_803F2ED0, 0, 1, 0, &D_04003140); }
            if (D_803F2D10.unk0 == 0) {
                D_803D552C->unk308 -= 1;
            }
            if (D_803D552C->unk308 < 0) {
                D_803D552C->unk308 = 0;
            }
            temp_t8_4 = (D_803D552C->unk308 * 0x38A) >> 6;
            temp_v0_7 = D_80203FE0[1].unk2;
            temp_v1_9 = D_80203FE0[2].unk2;

            D_80203FE0[26].unk0 = D_80203FE0[1].unk0;
            D_80203FE0[26].unk4 = D_80203FE0[1].unk4;

            D_80203FE0[2].unk2 -= temp_t8_4;
            D_80203FE0[1].unk2 -= temp_t8_4;

            D_80203FE0[26].unk2 = temp_v0_7;
            D_80203FE0[27].unk2 = temp_v1_9;

            D_80203FE0[27].unk0 = D_80203FE0[2].unk0;
            D_80203FE0[27].unk4 = D_80203FE0[2].unk4;

            if (D_803D552C->unk30E < 0x3C) {
                sp126 = -D_803D552C->unk30E;
            } else {
                sp126 = -0x78 - -D_803D552C->unk30E;
            }

            D_80203FE0[0].unk4 += 0x11B;
            sp12A = (s16) temp_t8_4;
            func_803032DC_71498C(1, 0, sp126);
            func_803032DC_71498C(2, 0, sp126);
            func_803032DC_71498C(26, 0, sp126);
            func_803032DC_71498C(27, 0, sp126);
            func_802C78B0_6D8F60(2, 1, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, &D_04003030_EA5E0);
            func_802C78B0_6D8F60(27, 26, (D_803F2EBC * 0x3A) >> 6, (D_803F2EC0 * 0x3A) >> 6, (D_803F2EC4 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, &D_040041D0_F5230);
            func_803032DC_71498C(1, 0, sp126 * -1);
            func_803032DC_71498C(2, 0, sp126 * -1); //unksp5E);
            func_803032DC_71498C(0x1A, 0, sp126 * -1); //unksp5E);
            func_803032DC_71498C(0x1B, 0, sp126 * -1); //unksp5E);
            D_80203FE0[0].unk4 -= 0x38;
            D_80203FE0[2].unk2 += sp12A;
            D_80203FE0[1].unk2 += sp12A;
            load_1_tile(&D_0103AC20, (s32) &D_0103AA20);
            // temp_t3_7 = D_803D552C;
            // temp_v0_8 = D_803D552C->unk30A;
            // temp_v1_10 = D_803D552C->unk366;

            var_t1 = (D_803D552C->unk30A >> 8) & 0xFF;
            var_t2 = D_803D552C->unk30A & 0xFF;

            if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 4) || (D_803D552C->unk366 == 1)) {
                if (D_803D5530->unk4A == 0) {
                    if (D_803F2D10.unk0 == 0) {
                        switch (D_803D5530->state) {       /* switch 2; irregular */
                        case 0x16:                  /* switch 2 */
                        case 0xCA:                  /* switch 2 */
                            var_t1 += 2;
                            var_t2 += 2;
                            break;
                        case 0x17:                  /* switch 2 */
                        case 0xCB:                  /* switch 2 */
                            var_t1 += 5;
                            var_t2 += 5;
                            break;
                        case 0x18:                  /* switch 2 */
                        case 0xCC:                  /* switch 2 */
                            var_t1 -= 2;
                            var_t2 -= 2;
                            break;
                        }
                    }

                    var_v0 = D_803D552C->unk302 - D_803D552C->yRotation;
                    if (var_v0 != 0) {
                        if (var_v0 < 0) {
                            var_v0 += 0x100;
                        }
                        if (var_v0 < 0x80) {
                            var_t2 += 3;
                            var_t1 -= 3;
                        } else {
                            var_t2 -= 3;
                            var_t1 += 3;
                        }
                    }
                }
            }

            var_t1 = var_t1 & 0x7F; // max 127
            var_t2 = var_t2 & 0x7F; // max 127

            D_803D552C->unk30A = (var_t1 << 8) | var_t2;

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, var_t1, 0, 0); // tbd
            func_802C78B0_6D8F60(8, 0xE, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, &D_040032B0);

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, var_t2, 0, 0); // tbd
            func_802C78B0_6D8F60(0xB, 0x11, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, &D_040032B0);

            func_80356D84_768434(D_0103B440, D_0103AC40);

            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(63), 4*(31));
            gDPSetTileSize(D_801D9E88++, 1, 0, 0, 4*(63), 4*(31));

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(8, 0xE, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, &D_040037C0); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(0xB, 0x11, 0xE800, 0xE800, 0xE800, D_803F2ED0, 0, 0, 0, &D_040037C0); }

            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp128 == 0) || (sp128 == 2)) {
        func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + ((s32) D_803D5524->unkBA >> 1)), D_803D552C->unk302, &D_01033190, (s16) 0x19, (s16) 0x19, (s16) 0x9B, 0, 0, 0, (s16) 0, (s16) (s32) D_803D5538);
    }

    // draw crosshair?
    if ((D_803D5538 != 0) && (((D_803F28E0[D_803F2A98].cameraMode == 3)) || (D_803F28E0[D_803F2A98].cameraMode == 0x11))) {
        sp134 = 14 - ((D_80152C78[(s16)(D_803D5540 << 3) & 0xFF] >> 7) >> 5);
        sp132 = D_803D5530->yRotation - (s32) ((D_803F28E0[D_803F2A98].unk20 * 256.0) / 360.0);

        if (sp132 > 128) {
            sp132 -= 256;
        }
        if (sp132 < -128) {
            sp132 += 256;
        }

        if (ABS(sp132) < 6) {
            sp132 = 0;
        }
        sp132 = sp132 * 4;

        gSPDisplayList(D_801D9E88++, D_01003AD0_3D3A0);
        gDPSetTextureImage(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_01036E90);
        gDPTileSync(D_801D9E88++);
        gDPSetTile(D_801D9E88++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(D_801D9E88++);
        gDPLoadTLUTCmd(D_801D9E88++, G_TX_LOADTILE, 255);
        gDPPipeSync(D_801D9E88++);
        gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0x00);

        gDPSetTextureImage(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, (s32)D_01036C90 & 0x1FFFFFFF);
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(D_801D9E88++);
        gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 127, 1024);
        gDPPipeSync(D_801D9E88++);
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15));
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);

        xl = ((((gScreenWidth >> 1) - sp134) + sp132) - 24) << 2;
        yl = (D_803D552C->unk30C + 112) << 2;
        xh = ((sp132 - sp134) + 112 + 32 + 7) << 2;
        yh = ((gScreenHeight >> 1) + D_803D552C->unk30C + 7) << 2;

        s = MAX(0, ((((gScreenWidth >> 1) - sp134) + sp132) - 24) << 2);
        t = MAX(0, (D_803D552C->unk30C + 112) << 2);

        gSPTextureRectangle(
            /* pkt  */ D_801D9EB8++,
            /* xl   */ MAX(0, xl),
            /* yl   */ MAX(0, yl),
            /* xh   */ MAX(0, xh),
            /* yh   */ MAX(0, yh),
            /* tile */ G_TX_RENDERTILE,
            /* s    */ MAX(0, (s >> 0xA) >> 7),
            /* t    */ MAX(0, (t >> 0xA) >> 7),
            /* dsdx */ 0x400,
            /* dtdy */ 0x400
        );

        xl = ((gScreenWidth >> 1) + sp134 + sp132 + 8) * 4;
        yl = (D_803D552C->unk30C + 112) * 4;
        xh = (sp134 + sp132 + 112 + 32 + 7 + 32) * 4;
        yh = ((gScreenHeight >> 1) + D_803D552C->unk30C + 7) * 4;
        s = MAX(0, ((gScreenWidth >> 1) + sp134 + sp132 + 8) * 4);
        t = MAX(0, (D_803D552C->unk30C + 0x70) * 4);

        gSPTextureRectangle(
            /* pkt  */ D_801D9EB8++,
            /* xl   */ MAX(0, xl),
            /* yl   */ MAX(0, yl),
            /* xh   */ MAX(0, xh),
            /* yh   */ MAX(0, yh),
            /* tile */ G_TX_RENDERTILE,
            /* s    */ -MAX(0, (s << 0xA) >> 7),
            /* t    */ -MAX(0, (t << 0xA) >> 7),
            /* dsdx */ 0x400,
            /* dtdy */ 0x400
        );

        // TODO: replace with single gDPLoadTextureBlock

        gDPSetTextureImage(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, (s32)D_01036D90 & 0x1FFFFFFF);
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(D_801D9E88++);
        gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 127, 1024);
        gDPPipeSync(D_801D9E88++);
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15));
        gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);

        xl = (((gScreenWidth >> 1) + sp132) - 8) * 4;
        yl = ((96 - sp134) + D_803D552C->unk30C) * 4;
        xh = (sp132 + 128 + 7 + 32) * 4;
        yh = ((((gScreenHeight >> 1) + D_803D552C->unk30C) - sp134) - 9) * 4;
        s = MAX(0, (((gScreenWidth >> 1) + sp132) - 8) * 4);
        t = MAX(0, (96 - sp134 + D_803D552C->unk30C) * 4);

        gSPTextureRectangle(
            /* pkt  */ D_801D9E88++,
            /* xl   */ MAX(0, xl),
            /* yl   */ MAX(0, yl),
            /* yh   */ MAX(0, xh),
            /* xh   */ MAX(0, yh),
            /* tile */ G_TX_RENDERTILE,
            /* s    */ MAX(0, (s << 0xA) >> 7),
            /* t    */ MAX(0, (t << 0xA) >> 7),
            /* dsdx */ 0x400,
            /* dtdy */ 0x400
        );

        xl = (((gScreenWidth >> 1) + sp132) - 8) * 4;
        yl = (sp134 + D_803D552C->unk30C + 128) * 4;
        xh = (sp132 + 128 + 7 + 32) * 4;
        yh = ((gScreenHeight >> 1) + sp134 + D_803D552C->unk30C + 23) * 4;
        s = MAX(0, (((gScreenWidth >> 1) + sp132) - 8) * 4);
        t = MAX(0, (sp134 + D_803D552C->unk30C + 128) * 4);

        gSPTextureRectangle(
            /* pkt  */ D_801D9EB8++,
            /* xl   */ MAX(0, xl),
            /* yl   */ MAX(0, yl),
            /* xh   */ MAX(0, xh),
            /* yh   */ MAX(0, yh),
            /* tile */ G_TX_RENDERTILE,
            /* s    */ -MAX(0, (s << 0xA) >> 7),
            /* t    */ -MAX(0, (t << 0xA) >> 7),
            /* dsdx */ 0x400,
            /* dtdy */ 0x400
        );
    }

    if (sp128 == 0) {
        func_803034D0_714B80(D_803D552C, 0x2A7, 0, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x54F, 0x1C5);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80352380_763A30.s")
#endif

// racing tortoise
#ifdef NON_MATCHING
// just the stack?
void func_80354188_765838(void) {

    struct061 sp90;
    s16 sp8C;
    s16 sp88;

    s32 phi_t1;
    s32 new_var;
    s32 temp_t0;
    s16 phi_v0;
    s16 temp_t9_3;
    s16 var_v0_2;

    s16 phi_a1;
    s16 var_v1_6; // sp86 ?
    u8 temp_t1;
    s8  var_v1;
    s16 phi_v0_3;
    s16 phi_t4;
    s32 phi_t3; // scaling?
    s32 phi_t0; // scaling?
    s16 tmp;

    if ((D_803D5538 == 0) && (D_803D552C->unk36E != 0)) {
        if ((D_803D5540 & 1) == 0) {
            create_particle_effect(
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
                21,
                0,
                0,
                (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF, // typo?
                30,
                GPACK_RGBA5551(0, 0, 0, 1),
                GPACK_RGBA5551(0, 0, 0, 1),
                0);
        }
        if (D_803D552C->unk2EC-- <= 0) {
            D_803D552C->unk36E = 0;
        }
    }

    var_v1 = D_803D552C->unk310 >> 8;
    temp_t0 = phi_t0 = D_803D552C->unk310 & 0xFF;

    if (D_803D5538 != 0) {
        phi_v0 = D_801E9EB2;
    } else {
        phi_v0 = MIN(D_803D552C->unk368 >> 2, 24);
    }

    switch (phi_v0) {
    case 0:
        if (!temp_t9_3) {}; // urgh
        var_v0_2 = -5;
        phi_a1 = 0;
        phi_t1 = temp_t0;
        break;
    case 1:
        var_v0_2 = 2;
        phi_a1 = 0;
        phi_t1 = temp_t0;
        break;
    case 2:
        var_v0_2 = 5;
        phi_a1 = 10;
        phi_t1 = temp_t0;
        break;
    case 3:
        var_v0_2 = 8;
        phi_a1 = 20;
        phi_t1 = temp_t0;
        if (phi_t1 < 95) {
            phi_t1 = 95;
        }
        break;
    case 4:
    default:
        var_v0_2 = 11;
        phi_a1 = 30;
        phi_t1 = temp_t0;
        if (phi_t1 < 110) {
            phi_t1 = 110;
        }
        break;
    }
    new_var = phi_t1;

    if (var_v1 < var_v0_2) {
        var_v1 = MIN(var_v1 + 5, var_v0_2);
    } else if (var_v0_2 < var_v1) {
        var_v1 = MAX(var_v1 - 1, var_v0_2);
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

    if ((phi_a1 + 110) < new_var) {
        var_v1 -= ((new_var - phi_a1) - 110) / 5;
    }
    if (new_var < 20) {
        var_v1 += (20 - new_var) / 2;
    }

    temp_t1 = (new_var & 0xFF) + var_v1;
    D_803D552C->unk310 = (var_v1 << 8) | temp_t1;

    if (D_803D5538 != 0) {
        var_v1_6 = D_803D554C << 1; // (s32) (D_803D554C << 17) >> 16;
    } else {
        var_v1_6 = 0;
    }
    if ((D_803D552C->unk366 == 3) || (D_803D552C->unk366 == 1) || (D_803D552C->unk366 == 4)) {
        if (D_803D5530->unk4A == 0) {
            func_8032CD70_73E420(
                D_803D5530,
                100,
                ((temp_t1 / 300.0) + 0.3) * 20480.0,
                0,
                ((temp_t1 + var_v1_6) / 200.0) + 0.3,
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
        if (var_v1 != 0) {
            sp88 = 0;
            D_803F2EDD = 0;
            goto block_57;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        phi_v0_3 = 1;
    } else {
        phi_v0_3 = 0;
    }
    sp88 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        0x740,
        0,
        0,
        0x5A,
        0,
        1,
        phi_v0_3 == 0);

block_57:
    if (sp88 == 0) {
        func_8034B45C_75CB0C();
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();

        if ((D_803F2ECE == 0) || (((D_803F2ECC < 31)))) {
            if (D_803D5538 != 0) {
                var_v1_6 = ((D_803D554C * 362) / 20);
            } else {
                var_v1_6 = 0;
            }

            func_802B9130_6CA7E0(&sp90, 453, 308, 498, 0);
            D_80203FE0[5].unk4 += 271;
            D_80203FE0[6].unk4 += 271;
            D_80203FE0[0].unk4 += 135;
            func_802C18FC_6D2FAC(var_v1_6 + 362, 634, &sp90);
            func_802B964C_6CACFC();
            D_80203FE0[1].unk4 += var_v1_6;
            D_80203FE0[0].unk4 += var_v1_6 >> 1;
            func_802C5EF4_6D75A4(181, 362);
            func_8038CCF0_79E3A0(90, 20, -1, -1, -1, -1);
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A8484_7B9B34);
                break;
            case 2:
                func_802DB670_6ECD20(&D_803A843C_7B9AEC, &D_803A8450_7B9B00, &D_803A8464_7B9B14, &D_803A84CC_7B9B7C);
                break;
            }
        }
        func_8038064C_791CFC();
        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
             (D_803F2EDA != 0) &&
             (((D_803D5538 != 0)) || ((D_803F2AA2 == 0)) || (D_803F2AA2 == 2) || ((D_803F2AA2 == 1) && (D_803F2AA3 > 10))) &&
             ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)],
                D_803D5530->xPos.w,
                D_803D5530->zPos.w,
                D_803D5530->yPos.w,
                -D_803D552C->unk302,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            phi_t4 = 0;
            switch (D_803D5530->state) {
            case 22:
            case 24:
                phi_t0 = ((D_803D5540 << 3) & 0xFF) << 5;
                phi_t3 = (((D_803D5540 << 3) + 0x80) & 0xFF) << 5;
                if (phi_t0 == 0) {
                    phi_t4 = -5;
                }
                if (phi_t3 == 0) {
                    phi_t4 = 5;
                }
                phi_t0 += FTOFIX32(1.0);
                phi_t3 += FTOFIX32(1.0);
                break;
            case 23:
                phi_t0 = ((D_803D5540 << 4) & 0xFF) << 6;
                phi_t3 = (((D_803D5540 << 4) + 0x80) & 0xFF) << 6;

                if (phi_t0 == 0) {
                    phi_t4 = -5;
                }
                if (phi_t3 == 0) {
                    phi_t4 = 5;
                }
                phi_t0 += FTOFIX32(1.0);
                phi_t3 += FTOFIX32(1.0);
                break;
            default:
                phi_t0 = phi_t3 = FTOFIX32(1.0);
                break;
            }

            if (phi_t4 != 0) {
                temp_t9_3 = D_80152C78[((tmp = -D_803D552C->unk302) + 64) & 0xFF] >> 7;
                sp8C = D_80152C78[tmp & 0xFF] >> 7;

                create_particle_effect(
                    D_803D5530->xPos.h + ((((sp8C * 0xA9E) / 0xE8) + (temp_t9_3 * phi_t4)) >> 8),
                    D_803D5530->zPos.h + ((((-temp_t9_3 * 0xA9E) / 0xE8) + (sp8C * phi_t4)) >> 8),
                    D_803D5530->yPos.h + 0xC,
                    21,
                    0,
                    0,
                    (func_8012826C() + FTOFIX32(3.0)) & 0x7FFF,
                    25,
                    GPACK_RGBA5551(96, 96, 96, 1),
                    GPACK_RGBA5551(96, 96, 96, 1),
                    0);
            }

            load_1_tile(D_04003A50, D_04003850);
            func_802C78B0_6D8F60(
                2,
                1,
                (D_803F2EBC * 0x3A) >> 6,
                (D_803F2EC0 * 0x3A) >> 6,
                (D_803F2EC4 * 0x3A) >> 6,
                D_803F2ED0,
                0,
                0,
                0,
                D_04002D70);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (phi_t0 * 58) >> 6, (phi_t0 * 58) >> 6, (phi_t0 * 58) >> 6, D_803F2ED0, 0, 0, 0, D_04003140); }
            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(2, 1, (phi_t3 * 58) >> 6, (phi_t3 * 58) >> 6, (phi_t3 * 58) >> 6, D_803F2ED0, 0, 1, 0, D_04003140); }
            func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_040033C0);

            gSPClearGeometryMode(D_801D9E88++, G_CULL_BOTH);

            if (D_803F2EDD == 0) { func_802C78B0_6D8F60(1, 20, FTOFIX32(0.90625), FTOFIX32(0.90625), FTOFIX32(0.90625), D_803F2ED0, 0, 0, 0, D_04003530); }
            load_1_tile(D_04004070, D_04003E70);

            gSPDisplayList(D_801D9E88++, D_010034C0_3CD90);
            gDPSetTile(D_801D9E88++, G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 1, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

            func_802C78B0_6D8F60(7,   8, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(10, 11, FTOFIX32(0.90625),   FTOFIX32(0.90625),   FTOFIX32(0.90625),   D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(13, 14, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
            func_802C78B0_6D8F60(16, 17, FTOFIX32(1.1328125), FTOFIX32(1.1328125), FTOFIX32(1.1328125), D_803F2ED0, 0, 0, 0, D_04003650);
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if ((sp88 == 0) || (sp88 == 2)) {
        func_8034BD20_75D3D0(
            D_803D552C->xPos.h,
            D_803D552C->zPos.h,
            (D_803D552C->yPos.h + (D_803D5524->unkBA >> 1)),
            D_803D552C->unk302,
            D_01033190,
            25,
            25,
            155,
            0,
            0,
            0,
            0,
            D_803D5538);
    }
    if (sp88 == 0) {
        func_803034D0_714B80(D_803D552C, 679, 0, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 1359, 453);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80354188_765838.s")
#endif

#ifdef NON_MATCHING
// TORTOISE_TANK_DEFENDING/RACING_TORTOISE_DEFENDING
void func_80355130_7667E0(void) {
    struct061 sp88;
    s16 sp86;
    f32 temp_f0;
    u8 tmp;
    u8 tmp2;

    if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
        func_8032CD70_73E420(D_803D5530, SFX_UNKNOWN_175, 0x6000, 0, 1.0f, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
    }

    if (D_803D5530->unk162 == 1) {
        temp_f0 = ((0, ABS(D_803D5530->xVelocity.w)) + ABS(D_803D5530->zVelocity.w)) / (65536.0 * 10);
        if (temp_f0 > 0.2) {
            func_8032CD70_73E420(
                (u8*)D_803D5530 + 0x22, // unaligned?
                SFX_UNKNOWN_63,
                MIN(1.3, temp_f0 - 0.2) * 8192.0,
                0,
                (temp_f0 / 2.0) + .2, // !!!
                D_803D5530->xPos.h,
                D_803D5530->zPos.h,
                D_803D5530->yPos.h);
        }
    }

    if (D_803D5538 != 0) {
        if ((D_803D5524->biome == D_803F2D50.segment) ||
            ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
            tmp = 1;
        } else {
            tmp = 0;
        }

        if (D_803F2D50.segment) {}; // helps a little but messes things up too

        if (tmp) {
            sp86 = 0;
            D_803F2EDD = 0;
            goto done;
        }
    }

    if ((D_803D5524->biome == D_803F2D50.segment) ||
        ((D_803D5524->biome == 0) && ((D_803F2D50.segment == 4) || (D_803F2D50.segment == 5)))) {
        tmp = 1;
    } else {
        tmp = 0;
    }
    sp86 = func_802E89F0_6FA0A0(
        D_803D552C->xPos.w,
        D_803D552C->zPos.w,
        D_803D552C->yPos.w + (D_803D5524->unkBA << 0xF),
        0x740,
        0,
        0,
        0x5A,
        0,
        1,
        tmp == 0);
done:
    if (sp86 == 0) {
        func_8035D120_76E7D0();
        func_8035DA60_76F110();
        func_8035D734_76EDE4();
        if ((D_803F2ECE == 0) || (D_803F2ECC < 31)) {
            func_802B9130_6CA7E0(&sp88, 0x1C5, 0x134, 0xB5, 0);
            func_802B964C_6CACFC();
        }
        if (D_803F2ECC != 0) {
            func_802DB8DC_6ECF8C();
            switch (D_803F2ECE) {
            case 1:
                func_802DB670_6ECD20(D_803A8514_7B9BC4, D_803A8518_7B9BC8, D_803A8464_7B9B14, D_803A8484_7B9B34);
                break;
            case 2:
                func_802DB670_6ECD20(D_803A8514_7B9BC4, D_803A8518_7B9BC8, D_803A8464_7B9B14, D_803A84CC_7B9B7C);
                break;
            }
        }
        func_803224C4_733B74(0x15, 0x15, 0, 0x10, 0, 0, 0, 0x10);
        func_8038064C_791CFC();

        if (((D_80204278->usedModelViewMtxs + 30) < 250) &&
            (D_803F2EDA != 0) && ((D_803D5538 != 0) || ((tmp2 = D_803F2AA2, tmp2 == 0)) || (tmp2 == 2) || ((tmp2 == 1) && (D_803F2AA3 >= 11))) &&
            ((D_803F2C18[0] != 0) || (D_803D5538 == 0) || (((D_803F28E0[D_803F2A98].cameraMode != 3)) && (D_803F28E0[D_803F2A98].cameraMode != 17)) || (D_803F28E0[D_803F2A98].unk64 != -3))) {

            func_80127640(
                &D_80204278->modelViewMtx[(D_80204278->usedModelViewMtxs)],
                D_803D5530->xPos.w,
                D_803D5530->zPos.w,
                D_803D5530->yPos.w,
                -D_803D552C->unk302,
                D_803F2EB0 / 4,
                D_803F2EB4 / 4,
                D_803F2EB8 / 4,
                D_803F2ED2,
                D_803F2ED4);
            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            load_1_tile(D_04003A50, D_04003850);
            func_802C78B0_6D8F60(2, 1, (D_803F2EBC * 0x3A) >> 6, (D_803F2EC0 * 0x3A) >> 6, (D_803F2EC4 * 0x3A) >> 6, D_803F2ED0, 0, 0, 0, D_04002D70);
            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

            func_8034BD20_75D3D0(D_803D552C->xPos.h, D_803D552C->zPos.h, (s16) (D_803D552C->yPos.h + D_803D5524->unkBA), D_803D552C->unk302, D_01033190, 0x19, 0x19, 0x9B, 0, 0, 0, 0, D_803D5538);
        }
        func_8035D6A0_76ED50();
    } else {
        func_8035D6D0_76ED80();
    }
    if (sp86 == 0) {
        func_803034D0_714B80(D_803D552C, 0x7F6, 0, 0);
        func_80303D50_715400(D_803D552C, 2);
    } else {
        func_80303D00_7153B0(D_803D552C, 0x54F, 0x1C5);
    }
    if (D_803D5538 == 0) {
        if (D_803D552C->unk2EC <= 0) {
            play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
            if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
                load_animal(TORTOISE_TANK);
            } else {
                load_animal(RACING_TORTOISE);
            }
        } else {
            D_803D552C->unk2EC -= 1;
        }
    }
    if ((D_803D552C->unk366 == 2) || (D_803D552C->unk366 == 5)) {
        if (D_803D5524->unk9C == TORTOISE_TANK_DEFENDING) {
            load_animal(TORTOISE_TANK);
        } else if (D_803D5524->unk9C == RACING_TORTOISE_DEFENDING) {
            load_animal(RACING_TORTOISE);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355130_7667E0.s")
#endif

#ifdef NON_MATCHING
// is this equivalent?
void func_80355918_766FC8(void) {
    s16 temp_t0;
    s16 temp_v1;
    s16 phi_v1;

    if ((D_803F28E0[D_803F2A98].cameraMode == 3) || (D_803F28E0[D_803F2A98].cameraMode == 17)) {
        D_803D552C->unk30E = 0;
        if (D_801D9ED8.unkFFC6 != 0) {
            D_803D552C->unk30C -= 4;
        }
        if (D_801D9ED8.unkFFC8 != 0) {
            D_803D552C->unk30C += 4;
        }

        D_803D552C->unk30C = MAX(-100, D_803D552C->unk30C);
        D_803D552C->unk30C = MIN(100, D_803D552C->unk30C);

        if ((D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {
            func_80321E60_733510(
                OBJECT_CANNONBALL,
                32,
                0,
                20,
                25 - (D_803D552C->unk30C >> 3),
                (25 - (D_803D552C->unk30C >> 2)) + (D_803F2A9E / 3),
                2,
                45);
            func_803421E0_753890(17);

            D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
    } else {
        if ((D_801D9ED8.unkFFB2 == 0) && (D_801D9ED8.unkFFB8 != 0) && (func_8035E344_76F9F4(D_803D5520, 0))) {

            if (D_803D552C->unk30E < 60) {
                phi_v1 = -D_803D552C->unk30E;
            } else {
                phi_v1 = (-120 - -D_803D552C->unk30E);
            }
            temp_v1 = phi_v1 - ((D_803D552C->unk312 * 360) >> 8);
            temp_t0 = -temp_v1;

            phi_v1 = (((D_80152C78[(temp_v1 + 64) & 0xFF] >> 7) << 5) >> 8);

            func_80321E60_733510(
                OBJECT_CANNONBALL,
                (phi_v1),
                0,
                (s16) (((((D_80152C78[temp_t0 & 0xFF]) >> 7) << 5) >> 8) + 16),
                10 - (temp_v1 / 3),
                temp_t0,
                2,
                45);
            func_803421E0_753890(17);

            D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
        }
        if (D_801D9ED8.unkFFB2 != 0) {
            D_803D552C->unk30E = ((D_803D552C->unk30E + 1) % 120);
            if ((D_803D552C->unk30E < 60) && (D_803D5530->unk4A == 0)) {
                func_8032CD70_73E420(&D_803D5530->unk2, SFX_UNKNOWN_85, 0x3C00, 0, 0.8f, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
            } else {
                func_8032CD70_73E420(&D_803D5530->unk2, SFX_UNKNOWN_85, 0x3C00, 0, 0.7f, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
            }
        } else {
            D_803D552C->unk30E = (u16)0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/tortoise/func_80355918_766FC8.s")
#endif

void func_80355E14_7674C4(void) {
    func_80321E60_733510(OBJECT_CANNONBALL, 32, 0, 30, 10, 0, 2, 45);
    func_8034220C_7538BC(17, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);
    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_80355EDC_76758C(void) {
    recharge_skill(0);
}

// tortoise tank
void func_80355EFC_7675AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h,  D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(TORTOISE_TANK_DEFENDING);
}

void func_80355F64_767614(void) {
    func_8037D994_78F044(20);
    if ((D_803D5540 & 1) == 0) {
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            21,
            0,
            0,
            (func_8012826C() + FTOFIX32(3.0)) & (FTOFIX32(0.5) - 1),
            30,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            0);
    }
}

// racing tortoise
void func_80355FFC_7676AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(RACING_TORTOISE_DEFENDING);
}

// tortoise tank
void func_80356064_767714(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(TORTOISE_TANK);
}

// racing tortoise
void func_803560CC_76777C(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
    load_animal(RACING_TORTOISE);
}

void func_80356134_7677E4(Animal *a) {
    s32 temp_v0;
    s16 rot;

    temp_v0 = func_802F8160_709810(D_803D5530, a, 32, 20, 30, 0x59, -4, 3, (f32)D_803A05B0 / 65536.0);
    if (temp_v0 == -1) {
        rot = 32;
    } else {
        rot = (temp_v0 * 256) / 360;
    }
    func_80322064_733714(OBJECT_CANNONBALL, 32, 0, 20, 30, D_803D5530->yRotation, rot, 2, 45);
    do_rumble(0, 10, 40, 5, distance_from_player(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h));
    func_8034220C_7538BC(14, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h);
    D_803D552C->unk308 = MIN(46, D_803D552C->unk308 + 30);

    play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_803562C8_767978(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == TORTOISE_TANK) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
        load_animal(TORTOISE_TANK_DEFENDING);
    }
}

void func_80356348_7679F8(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_TORTOISE) {
        play_sound_effect_at_location(SFX_UNKNOWN_123, 0x7FFF, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.8f);
        load_animal(RACING_TORTOISE_DEFENDING);
    }
}

void racing_tortoise_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 20;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
