#include <ultra64.h>
#include "common.h"

void func_8029C8F0_6ADFA0(Gfx **dl);

void func_8029B870_6ACF20(Animal *arg0, Animal *arg1) {
    s32 dist = ((arg0->xPos.h - arg1->xPos.h) * (arg0->xPos.h - arg1->xPos.h)) +
               ((arg0->zPos.h - arg1->zPos.h) * (arg0->zPos.h - arg1->zPos.h));
    if ((arg1->state == 1) &&
        (D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) &&
        (dist < 800) && (arg0->unk16C->unk80.bit) &&
        (arg1->unk248[1] != NULL) && (arg0->unk320 == 0)) {
        Animal *tmp;
        arg1->unk158 = 1;
        arg0->xPos.h = arg1->xPos.h;
        arg0->zPos.h = arg1->zPos.h;
        D_803D2D90.unk4C = arg1->xPos.h;
        D_803D2D90.unk4E = arg1->zPos.h;
        D_803D2D90.unk50 = arg1->yPos.h;
        D_803D2D90.unk2 = 54;
        tmp = arg1->unk248[1];
        D_803D2D90.unk60 = tmp;
        D_803D2D90.unk5C = arg1;
        D_803D2D90.unk52 = tmp->xPos.h;
        D_803D2D90.unk54 = tmp->zPos.h;
        D_803D2D90.unk56 = tmp->yPos.h;
        D_803D2D90.unk58 = arg0;
        D_803D2D90.unk0 = 1;
        D_803D2D90.unk46 = D_803D2D90.unk4C;
        D_803D2D90.unk48 = D_803D2D90.unk4E;
        D_803D2D90.unk4A = D_803D2D90.unk50;
        func_802B33D0_6C4A80(arg0);
        arg0->unk364 = 16;
        arg0->unk334 = D_803D5544;
    }
}

void func_8029B9B8_6AD068(Animal *arg0, Animal *arg1) {
    D_803D2D90.unk5C = 0;
    D_803D2D90.unk60 = arg1;
    D_803D2D90.unk52 = arg1->xPos.h;
    D_803D2D90.unk54 = arg1->zPos.h;
    D_803D2D90.unk56 = arg1->yPos.h;
    D_803D2D90.unk58 = arg0;
    D_803D2D90.unk58->xPos.h = D_803D2D90.unk52;
    D_803D2D90.unk58->zPos.h = D_803D2D90.unk54;
    D_803D2D90.unk58->yPos.h = D_803D2D90.unk56 + 8;
    D_803D2D90.unk58->xVelocity.w = 0;
    D_803D2D90.unk58->zVelocity.w = 0;
    D_803D2D90.unk58->yVelocity.w = 0;
    D_803D2D90.unk58->unk68 = D_803D2D90.unk60;
    D_803D2D90.unk58->unk70 = 0;
    D_803D2D90.unk58->unk160 = D_803D2D90.unk60->unk160;
    D_803D2D90.unk0 = 3;
    D_803D2D90.unk2 = 55;
    arg0->unk364 = 16;
    arg0->unk334 = D_803D5544 - 150;
}

void func_8029BA70_6AD120(Animal *arg0, Animal *arg1) {
    if (arg1->state != 0) {
        s32 dist = ((arg0->xPos.h - arg1->xPos.h) * (arg0->xPos.h - arg1->xPos.h)) +
                   ((arg0->zPos.h - arg1->zPos.h) * (arg0->zPos.h - arg1->zPos.h));
        if ((D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) && (dist < 0x320)) {
            arg1->unk158 = 1;
            D_803D2D90.unk5C = arg1;
            D_803D2D90.unk60 = 0;
            D_803D2D90.unk4C = arg1->xPos.h;
            D_803D2D90.unk4E = arg1->zPos.h;
            D_803D2D90.unk50 = arg1->yPos.h;
            D_803D2D90.unk46 = D_803D2D90.unk4C;
            D_803D2D90.unk48 = D_803D2D90.unk4E;
            D_803D2D90.unk4A = D_803D2D90.unk50;
            D_803D2D90.unk52 = arg1->xPos.h;
            D_803D2D90.unk54 = arg1->zPos.h;
            D_803D2D90.unk56 = arg1->yPos.h;
            D_803D2D90.unk58 = arg0;
            arg0->xPos.h = arg1->xPos.h;
            arg0->zPos.h = arg1->zPos.h;
            D_803D2D90.unk0 = 1;
            D_803D2D90.unk2 = 56;
            func_802B33D0_6C4A80(arg0);
            arg0->unk364 = 17;
            arg0->unk334 = D_803D5544;
            func_8035739C_768A4C();
        }
    }
}

#ifdef NON_MATCHING
void func_8029BB94_6AD244(void) {
    s16 pad;
    s16 sp8C;
    s16 var_s7;
    s16 var_s0;
    s16 i;
    s16 sp84;

    if (D_803D2D90.unk64 != 0) {
        D_803D2D90.unk64--;
    }
    if (D_803D2D90.unk0 != 0) {
        if (D_803D2D90.unk2 == 53) {}; // helps regalloc a bit
        if (D_803D2D90.unk2 == 54) {
            add_light_at_location(D_803D2D90.unk5C->xPos.h, D_803D2D90.unk5C->zPos.h, D_803D2D90.unk5C->yPos.h + 0x80, 0xFF, 0, 0, 0);
            add_light_at_location(D_803D2D90.unk60->xPos.h, D_803D2D90.unk60->zPos.h, D_803D2D90.unk60->yPos.h + 0x80, 0xFF, 0, 0, 0);
        }
        if (D_803F2D10.unk0 == 0) {
            if (D_803D2D90.unk0 == 1) {
                D_803D2D90.unk0 = 2;
                D_803D2D90.unk4 = 0;
                for (i = 0; i < 12; i++) {
                    D_803D2D90.unk6[i] = 0;
                    D_803D2D90.unk1E[i] = 0;
                }
                D_803D2D90.unk40 = 0;
                D_803D2D90.unk42 = 0;
                D_803D2D90.unk44 = 0;
                D_803D2DFC = 0x4000;
                D_803D2D90.unk38 = 0.0f;
                D_803D2D90.unk3C = 0.0f;
                D_803D2DF8 = 0.25f;
                do_rumble(0, 40, 8, 0x20, distance_from_player(D_803D2D90.unk4C, D_803D2D90.unk4E, D_803D2D90.unk50));
            }
            if (D_803D2D90.unk0 == 3) {
                D_803D2D90.unk0 = 4;
                D_803D2D90.unk4 = 0;
                D_803D2D90.unk46 = D_803D2D90.unk52;
                D_803D2D90.unk48 = D_803D2D90.unk54;
                D_803D2D90.unk4A = D_803D2D90.unk56;
                for (i = 0; i < 12; i++) {
                    D_803D2D90.unk6[i] = 0;
                    D_803D2D90.unk1E[i] = 0;
                }
                D_803D2D90.unk40 = 0;
                D_803D2D90.unk44 = 0;
                D_803D2D90.unk42 = 0;
                D_803D2DFC = 0x4000;
                D_803D2D90.unk38 = 0.0f;
                D_803D2D90.unk3C = 0.0f;
                D_803D2DF8 = 0.25f;
                do_rumble(0, 40, 8, 32, distance_from_player(D_803D2D90.unk52, D_803D2D90.unk54, D_803D2D90.unk56));
            }
            if (D_803D2D90.unk0 == 2) {
                D_803D2D90.unk42 += 1;
                if (D_803D2D90.unk42 < 115) {
                    if (D_803D2D90.unk42 < 40) {
                        if (D_803D2DF8 < 0.75) {
                            D_803D2DF8 += 0.04;
                        }
                        D_803D2D90.unk40 -= 1;
                    } else {
                        if (D_803D2D90.unk42 == 40) {
                            do_rumble(0, 0x46, 32, 0x2D, distance_from_player(D_803D2D90.unk4C, D_803D2D90.unk4E, D_803D2D90.unk50));
                        }
                        if (D_803D2DF8 < 2.0) {
                            D_803D2DF8 += func_801283AC(D_803D2D90.unk42 - 0x32) / 8000.0f;
                            if (D_803D2D90.unk42 < 0x50) {
                                D_803D2D90.unk40 -= 2;
                            } else {
                                D_803D2D90.unk40 -= 4;
                            }
                        }
                    }
                    if (D_803D2D90.unk42 >= 0x6E) {
                        D_803D2DFC -= 0x800;
                    }
                    D_803D2DFE = 51;
                    func_8032CD70_73E420(&D_803D2D90, D_803D2DFE, D_803D2DFC, 0, D_803D2DF8, D_803D2D90.unk4C, D_803D2D90.unk4E, D_803D2D90.unk50);
                }
                if (D_803D2D90.unk42 == 0x6E) {
                    play_sound_effect_at_location(0x34, 0x4000, 0x80, D_803D2D90.unk46, D_803D2D90.unk48, D_803D2D90.unk4A, 1.0f);
                    do_rumble(0, 0x10, 0x2D, 0, distance_from_player(D_803D2D90.unk4C, D_803D2D90.unk4E, D_803D2D90.unk50));
                }
                if (D_803D2D90.unk42 < 0x50) {
                    if ((D_803D2D90.unk42 < 40) && (D_803D2D90.unk38 < 5.0f)) {
                        D_803D2D90.unk38 += 0.18;
                    } else {
                        if (D_803D2D90.unk38 > 1.0f) {
                            D_803D2D90.unk38 -= 0.18;
                        }
                    }
                    D_803D2D90.unk3C += D_803D2D90.unk38;
                }
            }
            if (D_803D2D90.unk0 == 4) {
                D_803D2D90.unk44 += 1;
                if (D_803D2D90.unk44 < 115) {
                    if (D_803D2D90.unk44 < 40) {
                        if (D_803D2DF8 < 0.75) {
                            D_803D2DF8 += 0.04;
                        }
                    } else {
                        if (D_803D2D90.unk44 < 0x50) {
                            D_803D2D90.unk40 -= 2;
                        } else {
                            D_803D2D90.unk40 -= 4;
                        }
                        if (D_803D2D90.unk44 == 40) {
                            do_rumble(0, 0x46, 32, 0x2D, distance_from_player(D_803D2D90.unk52, D_803D2D90.unk54, D_803D2D90.unk56));
                        }
                        if (D_803D2DF8 < 2.0) {
                            D_803D2DF8 += func_801283AC((s16) (D_803D2D90.unk44 - 0x32)) / 8000.0f;
                        }
                    }
                    if (D_803D2D90.unk44 >= 0x6E) {
                        D_803D2DFC -= 0x800;
                    }
                    D_803D2DFE = 0x33;
                    func_8032CD70_73E420(&D_803D2D90, D_803D2DFE, D_803D2DFC, 0, D_803D2DF8, D_803D2D90.unk52, D_803D2D90.unk54, D_803D2D90.unk56);
                }
                if (D_803D2D90.unk44 == 0x6E) {
                    play_sound_effect_at_location(0x34, 0x4000, 0x80, D_803D2D90.unk46, D_803D2D90.unk48, D_803D2D90.unk4A, 1.0f);
                    do_rumble(0, 0x10, 0x2D, 0, distance_from_player(D_803D2D90.unk52, D_803D2D90.unk54, D_803D2D90.unk56));
                }
                if (D_803D2D90.unk44 < 80) {
                    if ((D_803D2D90.unk44 < 40) && (D_803D2D90.unk38 < 5.0f)) {
                        D_803D2D90.unk38 += 0.18;
                    } else if (D_803D2D90.unk38 > 1.0f) {
                        D_803D2D90.unk38 -= 0.18;
                    }
                    D_803D2D90.unk3C += D_803D2D90.unk38;
                }
            }

            if (D_803D2D90.unk42 == 150) {
                D_803D2D90.unk5C->unk158 = 0;
                D_803D2D90.unk58->xPos.h = D_803D2D90.unk52;
                D_803D2D90.unk58->zPos.h = D_803D2D90.unk54;
                D_803D2D90.unk58->yPos.h = D_803D2D90.unk56 + 8;
                D_803D2D90.unk58->xVelocity.w = 0;
                D_803D2D90.unk58->zVelocity.w = 0;
                D_803D2D90.unk58->yVelocity.w = 0;
                D_803D2D90.unk58->unk68 = D_803D2D90.unk60;
                D_803D2D90.unk58->unk70 = NULL;
                if (D_803D2D90.unk2 != 56) {
                    D_803D2D90.unk0 = 3;
                } else {
                    D_803D2D90.unk0 = 0;
                    if (D_803F2D50.unkC6 == 0) {
                        D_803F2D50.unkC6 = 1;
                    }
                }
            }
            if (D_803D2D90.unk44 == 150) {
                D_803D2D90.unk0 = 0;
                D_803D2D90.unk64 = 100;
                if (1) {};
                if (D_803D2D90.unk2 == 0x37) {
                    func_802B34B8_6C4B68(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
                    D_803D2D90.unk60->state = 0;
                } else {
                    func_802B34B8_6C4B68(D_803D2D90.unk58);
                }
            }
            D_803D2D90.unk4 += 2;
            if (D_803D2D90.unk40 < 0) {
                D_803D2D90.unk40 = D_803D2D90.unk40 + 0xF;
            }

            for (sp8C = 0; sp8C < 12; sp8C++) {
                if (D_803D2D90.unk6[sp8C] < (sp8C * 3)) {
                    D_803D2D90.unk6[sp8C] = D_803D2D90.unk3C;
                    var_s7 = D_80152350.unk2D0[(s16) (D_803D2D90.unk3C + (sp8C * 0xA))] >> 3;
                    D_803D2D90.unk1E[sp8C] = var_s7;
                } else {
                    var_s7 = D_803D2D90.unk1E[sp8C];
                }

                for (var_s0 = 0; var_s0 < 6; var_s0++) {
                    sp84 = D_80152350.unk2D0[D_803D2D90.unk6[sp8C]];
                    if ((D_803D2D90.unk44 >= 0x6F) || (D_803D2D90.unk42 >= 0x6F)) {
                        if (SSSV_RAND(32) == 0) {
                            create_particle_effect(
                                D_803D2D90.unk46 + ((D_80152350.unk2D0[(s16)((var_s0 * 60) + 30)] * var_s7) >> 7),
                                D_803D2D90.unk48 + ((D_80152350.unk384[(s16)((var_s0 * 60) + 30)] * var_s7) >> 7),
                                D_803D2D90.unk4A + sp84,
                                35,
                                (func_8012826C() * 3) - FTOFIX32(1.5),
                                (func_8012826C() * 3) - FTOFIX32(1.5),
                                -(func_8012826C() & 0x3FFF),
                                (SSSV_RAND(2) + 1),
                                0xFFFF,
                                0xFFFF,
                                0);
                        }
                        // breathing in & out?
                        if (D_803D2D90.unk1E[sp8C] >= 2) {
                            D_803D2D90.unk1E[sp8C] -= 2;
                        }
                        if (D_803D2D90.unk6[sp8C] < 100) {
                            D_803D2D90.unk6[sp8C] += 1;
                        }
                    } else if (sp8C < 4) {
                        var_s7 = 21;
                    }
                    if (sp8C == 11) {
                        var_s7 = 0;
                    }
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.ob[0] = D_803D2D90.unk46 + ((D_80152350.unk2D0[(s16) ((var_s0 * 60) + 30)] * var_s7) >> 7);
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.ob[1] = D_803D2D90.unk48 + ((D_80152350.unk384[(s16) ((var_s0 * 60) + 30)] * var_s7) >> 7);
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.ob[2] = D_803D2D90.unk4A + sp84;
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.cn[0] = (var_s0 * 42) - 0x7F;
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.cn[1] = 0;
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.cn[2] = (D_803D2D90.unk6[sp8C] << 1) - 0x7F;
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.cn[3] = 0xFF;
                    if (var_s0 != 5) {
                        D_80204278->unk303F0[(sp8C * 6) + var_s0].v.tc[0] = var_s0 * 170;
                    } else {
                        // final iteration
                        D_80204278->unk303F0[(sp8C * 6) + var_s0].v.tc[0] = 0;
                    }
                    D_80204278->unk303F0[(sp8C * 6) + var_s0].v.tc[1] = (sp8C * 6) << 5;
                }
            }
        }

        if ((D_803D2D90.unk44 < 120) && (D_803D2D90.unk42 < 120)) {
            func_8029C8F0_6ADFA0(&D_801D9E7C);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029BB94_6AD244.s")
#endif

extern u8  D_01006C60[];
extern Gfx D_010047D0[];

void func_8029C8F0_6ADFA0(Gfx **dl) {
    s16 k;
    s16 j;
    s16 i;

    s32 var_t3;

    gDPPipeSync((*dl)++);
    gSPDisplayList((*dl)++, D_01004270_3DB40);
    gSPClearGeometryMode((*dl)++, G_CULL_BACK | G_LIGHTING);
    gSPSetGeometryMode((*dl)++, G_SHADE | G_SHADING_SMOOTH);

    // light blue
    gDPSetPrimColor((*dl)++, 0, 0, 0xB9, 0xB9, 0xFF, 0xFF);
    // darker blue
    gDPSetEnvColor((*dl)++, 0x64, 0x64, 0xBE, 0x00);
    gDPSetCombineLERP((*dl)++,
        TEXEL1, TEXEL0, TEXEL1, TEXEL0,
        TEXEL1, TEXEL0, TEXEL1, TEXEL0,
        TEXEL1, TEXEL0, TEXEL1, TEXEL0,
        TEXEL1, TEXEL0, TEXEL1, TEXEL0);
    gDPSetTextureLOD((*dl)++, G_TL_TILE);

    gDPLoadTextureBlock2(
        (*dl)++,
        D_01006C60,
        G_IM_FMT_I,
        2,
        G_IM_SIZ_16b,
        32,
        32,
        0,
        G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMIRROR | G_TX_WRAP,
        G_TX_NOMASK,
        G_TX_NOMASK,
        G_TX_NOLOD,
        G_TX_NOLOD
    );

    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, SSSV_RAND(16) * 16 + (s32)&D_01006C60 + 0x200);

    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0040, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 255, 1024);
    gDPPipeSync((*dl)++);

    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, 1, 0, 0, 124, 124);

    gDPPipeSync((*dl)++);

    gSPDisplayList((*dl)++, D_010047D0);

    gDPSetDepthSource((*dl)++, G_ZS_PIXEL);
    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, TEXEL1, TEXEL0, TEXEL1, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
    gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    gDPSetTileSize(
        (*dl)++,
        G_TX_RENDERTILE,
        0,
        D_803D2D90.unk40,
        0x7C,
        (D_803D2D90.unk40 + 31) << 2);

    gDPSetTileSize((*dl)++, 1, 0, 0, 124, 124);

    gDPSetCycleType((*dl)++, G_CYC_2CYCLE);
    gDPSetRenderMode((*dl)++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);

    gDPTileSync((*dl)++);

    for (i = 0; i < 3; i++) {
        gSPVertex((*dl)++, (s32)&D_80204278->unk303F0[(i * 30) - (i * 6)] & 0x1FFFFFFF, 30, 0);

        if (i == 2) {
            var_t3 = 3;
        } else {
            var_t3 = 4;
        }

        for (j = 0; j < var_t3; j++) {
            for (k = 0; k < 5; k++) {
                gSP2Triangles(
                    /* gdl   */ (*dl)++,
                    /* v00   */ ((j * 6) + k) + 6,
                    /* v01   */ ((j * 6) + k) + 1,
                    /* v02   */ ((j * 6) + k) + 0,
                    /* flag0 */ 0,
                    /* v10   */ ((j * 6) + k) + 1,
                    /* v11   */ ((j * 6) + k) + 6,
                    /* v12   */ ((j * 6) + k) + 7,
                    /* flag1 */ 0);
            }

            gSP2Triangles(
                /* gdl   */ (*dl)++,
                /* v00   */ (j * 6) + 6,
                /* v01   */ (j * 6) + 0,
                /* v02   */ (j * 6) + 5,
                /* flag0 */ 0,
                /* v10   */ (j * 6) + 6,
                /* v11   */ (j * 6) + 5,
                /* v12   */ (j * 6) + 11,
                /* flag1 */ 0);
        }
    }

    gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync((*dl)++);

}

void func_8029CEF0_6AE5A0(s32 arg0, s32 arg1, s32 arg2, u16 arg3, u8 arg4, struct059 *arg5, s8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s8 tmp;

    arg5->unk1++;
    if (arg5->unk1 < 75) {
        arg5->unk44[arg5->unk1].unk0 = arg0; // x
        arg5->unk44[arg5->unk1].unk4 = arg1; // z
        arg5->unk44[arg5->unk1].unk8 = arg2; // y
        arg5->unk44[arg5->unk1].unkC = arg3; // ?
        arg5->unk44[arg5->unk1].unkE = arg4; // ?
        arg5->unk44[arg5->unk1].unk10 = arg6; // ?
        arg5->unk44[arg5->unk1].unk11 = arg7; // red
        arg5->unk44[arg5->unk1].unk12 = arg8; // green
        arg5->unk44[arg5->unk1].unk13 = arg9; // blue

        tmp = arg5->unk2[arg4];

        if (tmp == -1) {
            arg5->unk44[arg5->unk1].unkF = -1;
            arg5->unk2[arg4] = arg5->unk1;
            if (arg5->unk0 != -1) {
                arg5->unk44[arg5->unk0].unkF = arg5->unk1;
            }
            arg5->unk0 = arg5->unk1;
        } else {
            arg5->unk44[arg5->unk1].unkF = arg5->unk44[tmp].unkF;
            arg5->unk44[tmp].unkF = arg5->unk1;

            arg5->unk2[arg4] = arg5->unk1;
            if (arg5->unk44[arg5->unk1].unkF == -1) {
                arg5->unk0 = arg5->unk1;
            }
        }
    }
}

void func_8032E150_73F800(void **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6);

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D0A8_6AE758.s")
// void func_8029D0A8_6AE758(void) {
//     u8 sp56;
//     s16 var_fp;
//     s8 var_v0;
//     u8 var_t3;
//
//     sp56 = 0xFF;
//     var_fp = 0xFF;
//     D_803D2E00 += 1;
//     D_803D2E00 &= 0xF;
//
//     if ((guRandom() % 20) == 1) {
//         if (D_803D342C == 5) {
//             D_803D342C = 1;
//         } else {
//             D_803D342C = 5;
//         }
//     }
//
//     D_803D3428 += D_803D342C;
//     D_803D3428 %= 9;
//
//     gSPDisplayList(D_801D9E90++, D_01004308);
//     gSPDisplayList(D_801D9E88++, D_01004B98);
//
//     var_v0 = 0;
//     do {
//         struct059a *tmp = &D_803D2E08.unk44[var_v0];
//         // temp_s4 = (var_v0 * 0x14) + &D_803D2E08;
//         // temp_s2 = temp_s4 + 0x44;
//         if (tmp->unk12 < 0x20) { // (s32) temp_s4->unk52
//             // temp_s2_2 = temp_s4 + 0x44;
//             // D_803D2E08.unk44[var_v0]
//             if (var_fp != tmp->unkE) {
//                 if (var_fp != 0xFF) {
//                     D_803D2E08.unk2[var_fp] = -1;
//                 }
//                 var_fp = tmp->unkE & 0xFF;
//                 if (var_fp == 0) {
//                     func_8029D8D8_6AEF88(&D_801D9EB8, (var_fp + (D_803D3428 / 3)));
//                 } else {
//                     func_8029D8D8_6AEF88(&D_801D9EB8, var_fp);
//                 }
//             }
//             if (tmp->unk10 == 127) {
//                 func_8032E150_73F800(&D_801D9EB8, tmp->unk0, tmp->unk4, tmp->unk8, 0x1F, 0x3F, tmp->unkC * 3);
//             } else {
//                 func_8032E150_73F800(&D_801D9EB8, tmp->unk0, tmp->unk4, tmp->unk8, 0x1F, 0x1F, tmp->unkC * 3);
//             }
//             gDPPipeSync(D_801D9E88++);
//         } else {
//             var_t3 = sp56;
//             if (tmp->unkE < 0x30) {
//                 gDPSetPrimColor(D_801D9E90++, 0, 0,
//                     tmp->unk11,
//                     tmp->unk12,
//                     tmp->unk13,
//                     0xFF);
//                 gDPSetEnvColor(D_801D9E90++, 0x11, 0x22, 0x33, 0x44);
//             }
//             if (var_t3 != tmp->unkE) {
//                 if (var_t3 != 0xFF) {
//                     D_803D2E08.unk2[sp56] = -1;
//                 }
//
//                 var_t3 = tmp->unkE & 0xFF;
//                 sp56 = var_t3;
//                 if (var_t3 < 0x30) {
//                     // i4/i8/i16?
//
//                     gDPSetCombineLERP(D_801D9E90++,
//                         PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
//                         PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
//                         0, 0, 0, COMBINED,
//                         0, 0, 0, COMBINED);
//
//                     gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, ((var_t3 << 0xA) + 0x7FFF8000 + (s32)&D_01029E10));
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPLoadSync(D_801D9E90++);
//                     gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 511, 512);
//                     gDPPipeSync(D_801D9E90++);
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);
//
//                 } else if (var_t3 == 0x30) {
//                     // rgba32
//
//                     // 0x80000000 + -0xc000
//                     gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (((((var_t3 + ((s16) D_803D2E00 >> 1)) << 0xA) + 0xFFFF4000) * 2) + 0x80000000 + (s32)&D_01040CB0));
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPLoadSync(D_801D9E90++);
//                     gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 256);
//                     gDPPipeSync(D_801D9E90++);
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);
//
//                     // 0x80000000 - 0xC000
//                     gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 32, (((var_t3 + ((s16) D_803D2E00 >> 1)) << 0xA) + 0x7FFF4000 + (s32)&D_0103ECB0));
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPLoadSync(D_801D9E90++);
//                     gDPLoadTile(D_801D9E90++, G_TX_LOADTILE, 0, 0, 124, 124);
//                     gDPPipeSync(D_801D9E90++);
//                     gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//                     gDPSetTileSize(D_801D9E90++, 1, 0, 0, 124, 124);
//                     gDPSetCombineLERP(D_801D9E90++,
//                         PRIMITIVE, 0, TEXEL0, 0,
//                         PRIMITIVE, 0, TEXEL1, 0,
//                         0, 0, 0, COMBINED,
//                         0, 0, 0, COMBINED);
//                 }
//             }
//             if (var_t3 == 0x30) {
//                 if (tmp->unk10 == 60) {
//                     gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF); // white
//                 }
//                 if (tmp->unk10 == 59) {
//                     gDPSetPrimColor(D_801D9E90++, 0, 0, 255, 160, 255, 0xFF);    // light pink
//                 }
//                 if (tmp->unk10 == 58) {
//                     gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0x00, 0xFF, 0xFF); // bright pink
//                 }
//             }
//
//             gDPSetDepthSource(D_801D9E90++, G_ZS_PRIM);
//             gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);
//
//             func_8032DACC_73F17C(
//                 &D_801D9E90,
//                 tmp->unk0,
//                 tmp->unk4,
//                 tmp->unk8,
//                 0x1F,
//                 0x1F,
//                 tmp->unkC * 3);
//             gDPPipeSync(D_801D9E90++);
//         }
//         var_v0 = tmp->unkF; //unk53; (0x44 + 0xF)
//     } while (var_v0 != -1);
//
//     D_803D2E08.unk0 = -1;
//     D_803D2E08.unk1 = -1;
// }

void func_8029D89C_6AEF4C(void) {
    s16 i;
    // struct059
    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
    for (i = 0; i < 64; i++) {
        D_803D2E08.unk2[i] = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D8D8_6AEF88.s")
// void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1) {
//     u8 *phi_a2;
//     u8 *phi_v1;
//     s32 phi_at;
//     // this is currently nonsense
//     if (arg1 < 8) {
//         // offset is 120000
//         phi_a2 = &D_800BA760->unk1D4C0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9);
//         phi_at = 0x214C0;
//     } else {
//         // 2048 size?
//         arg1 = arg1 - 8;
//         // offset is 109760
//         phi_a2 = &D_800BA760->unk1ACC0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9); // 512 size?
//         phi_at = 0x1CCC0;
//     }
//
//     gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, (s32)phi_a2 + 0x80000000);
//     gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync((*arg0)++);
//     gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 4*31, 4*31);
//     gDPPipeSync((*arg0)++);
//     gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);
//
//     gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, (s32)phi_v1 + phi_at + 0x80000000);
//     gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync((*arg0)++);
//     gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 4*31);
//     gDPPipeSync((*arg0)++);
//     gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize((*arg0)++, 1, 0, 0, 4*31, 4*31);
// }

void func_8029DB20_6AF1D0(u8 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s32 arg7) {
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_f8;
    s32 temp_t1;
    s16 idx;
    s16 phi_v1;

    temp_f16 = D_803F2C44 - (arg2 >> 16);
    temp_f10 = D_803F2C48 - (arg3 >> 16);
    temp_f8 = D_803F2C4C - (arg4 >> 16);

    temp_t1 = sqrtf((temp_f16 * temp_f16) + (temp_f10 * temp_f10) + (temp_f8 * temp_f8));
    if (D_803D5508 == 0) {
        D_803D5188[0].unk14 = arg7;
        D_803D5188[0].unk18 = arg0;
        D_803D5188[0].unk4 = arg2;
        D_803D5188[0].unk8 = arg3;
        D_803D5188[0].unkC = arg4;
        D_803D5188[0].unk10 = arg5;
        D_803D5188[0].unk12 = arg6;
        D_803D5188[0].unk2 = arg1;
        D_803D5188[0].unk0 = temp_t1;
        D_803D5508++;
        return;
    }

    if (D_803D5508 < 32) {

        for (idx = 0; ((idx < D_803D5508) && (temp_t1 < D_803D5188[idx].unk0)); idx++) {};

        for (phi_v1 = D_803D5508; phi_v1 > idx; phi_v1--) {
            D_803D5188[phi_v1] = D_803D5188[phi_v1 - 1];
        }

        D_803D5188[idx].unk18 = arg0;
        D_803D5188[idx].unk14 = arg7;
        D_803D5188[idx].unk4 = arg2;
        D_803D5188[idx].unk8 = arg3;
        D_803D5188[idx].unkC = arg4;
        D_803D5188[idx].unk0 = temp_t1;
        D_803D5188[idx].unk10 = arg5;
        D_803D5188[idx].unk12 = arg6;
        D_803D5188[idx].unk2 = arg1;
        D_803D5508++;
    }
}

void func_8029DD84_6AF434(void) {
    u8 current_texture;
    u8 loaded_texture;
    s16 i;

    gSPDisplayList(D_801D9E90++, &D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E90++, D_803C0650_7D1D00);
    gSPDisplayList(D_801D9E90++, &D_01004510);

    gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
    gDPSetCombineLERP(D_801D9E90++, SHADE, 0, COMBINED, 0, 0, 0, 0, PRIMITIVE, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0, 0, PRIMITIVE);
    gDPSetPrimColor(D_801D9E90++, 0, 0, 0, 0, 0, 128);

    loaded_texture = 255;
    for (i = 0; i < D_803D5508; i++) {
        current_texture = D_803D5188[i].unk18 & 0x3F;
        // if we need to load a new texture, do so?
        if (current_texture != loaded_texture) {
            loaded_texture = current_texture;
            // are these "europe" textures, or just intro or first level? or biome specific?
            gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_800BA760[current_texture ^ 0]); // regalloc fix
            gDPTileSync(D_801D9E90++);
            gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPTileSync(D_801D9E90++);
            gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1372, 0);
            gDPTileSync(D_801D9E90++);
        }

        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D5188[i].unk4,
            D_803D5188[i].unk8,
            D_803D5188[i].unkC,
            D_803D5188[i].unk10,
            D_803D5188[i].unk12,
            D_803D5188[i].unk2 << 5,
            D_803D5188[i].unk2 << 5,
            D_803D5188[i].unk2 << 5);

        gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        gSPClearGeometryMode(D_801D9E90++, G_CULL_BACK);
        gSPDisplayList(D_801D9E90++, D_803D5188[i].unk14);
        gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
    }

    D_803D5508 = 0;
    gSPSetGeometryMode(D_801D9E90++, G_CULL_BACK);
}

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA32;

#if 0
{
    // 007b1bf0
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0xff }, // #ffffff
    { 0xff, 0x00, 0x00, 0x00 }, // #ff0000
    { 0xff, 0x00, 0x00, 0xff }, // #ff0000
    // 007b1c00
    { 0x00, 0xff, 0x00, 0x00 }, // #00ff00
    { 0x00, 0xff, 0x00, 0xff }, // #00ff00
    { 0x00, 0x00, 0xff, 0x00 }, // #0000ff
    { 0x00, 0x00, 0xff, 0xff }, // #0000ff
    // 007b1c10
    { 0x50, 0x50, 0x50, 0x00 }, // #505050
    { 0x50, 0x50, 0x50, 0xff }, // #505050
    { 0xff, 0xff, 0x00, 0x00 }, // #ffff00
    { 0xff, 0xff, 0x00, 0xff }, // #ffff00
    // 007b1c20
    { 0x00, 0x00, 0x00, 0x00 }, // #000000
    { 0x00, 0x00, 0x00, 0xff }, // #000000
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0xff }, // #ffffff
    // 007b1c30
    { 0xff, 0xd9, 0x00, 0x1b }, // #ffd900
    { 0x00, 0x00, 0x00, 0x2a }, // #000000
    { 0xff, 0xa0, 0x00, 0x18 }, // #ffa000
    { 0x00, 0x00, 0x00, 0x6e }, // #000000
}

RGBA D_803A0594_7B1C44[4] = {
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0x5e, 0x72, 0xff, 0x00 }, // #5e72ff
    { 0x77, 0xc4, 0xff, 0x00 }, // #77c4ff
};

#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E100_6AF7B0.s")
// void func_8029E100_6AF7B0(void) {
//     s16 temp_s0;
//     s16 temp_s5;
//     s32 temp_a2;
//     s32 temp_t0;
//     s32 temp_t3;
//     s32 temp_t7;
//     s32 temp_v0;
//     s32 temp_v1_2;
//     u16 temp_t4;
//     u8 temp_s4;
//     void *temp_a1;
//     void *temp_a1_2;
//     void *temp_s1;
//     void *temp_s1_2;
//     void *temp_s1_3;
//     void *temp_s1_4;
//     void *temp_s1_5;
//     void *temp_s1_6;
//     RGBA32 *rgba;
//     void *phi_s1;
//     s16 phi_s5;
//     s16 phi_s6;
//     s32 phi_s0;
//     void *phi_s1_2;
//     void *phi_s1_3;
//
//     // temp_a1 = D_801D9E90;
//     // D_801D9E90 = temp_a1 + 8;
//     // temp_a1->0 -> 06000000;
//     // temp_a1->4 -> 010049E8;
//     gSPDisplayList(D_801D9E90++, D_010049E8);
//
//     phi_s1 = D_803D3434->unk3B318;
//     phi_s5 = 0;
//     phi_s6 = 0;
//     if ((s32) D_803E97C0 > 0) {
//         do {
//             // temp_a1_2 = D_801D9E90;
//             // D_801D9E90 = temp_a1_2 + 8;
//             // temp_a1_2->unk4 = phi_s1;
//             // temp_a1_2->0 -> 06000000;
//             gSPDisplayList(D_801D9E90++, D_803D3434->unk3B318);
//
//             temp_s4 = D_803D3434->unk3B30A[phi_s5];
//             temp_s1 = phi_s1 + 8;
//
//             phi_s1->unk0 = (s32) ((((temp_s4 << 0xA) | ((temp_s4 * 0x10) - 1)) & 0xFFFF) | 0x04000000);
//             phi_s1->unk4 = (D_803D3434->unk39C88[phi_s6 * 0x10]; // + (phi_s6 * 0x10) );
//
//             // temp_s1->0 -> BE000000;
//             // temp_s1->4 -> E;
//             gSPCullDisplayList(phi_s1++, 0, 7);
//             temp_s1_2 = temp_s1 + 8;
//             temp_s1_3 = temp_s1_2 + 8;
//             temp_t7 = SSSV_RAND(4) * 4;
//             // temp_s1_2->4 -> 5000;
//             // temp_s1_2->0 -> FB000000;
//             rgba = &D_803A0594_7B1C44[(temp_t7 & 0xFFFF)]; // rgba
//             gDPSetEnvColor(phi_s1++, 0x00, 0x00, 0x50, 0x00);
//             gDPSetPrimColor(phi_s1++, 0, 0, rgba->r, rgba->g, rgba->b, rgba->a);
//
//             // temp_s1_3->0 -> FA000000;
//             // temp_s1_3->unk4 = (s32) (temp_v1->unk3 | (temp_v1->unk0 << 0x18) | (temp_v1->unk1 << 0x10) | (temp_v1->unk2 << 8));
//             temp_s1_4 = temp_s1_3 + 8;
//             temp_t0 = temp_s4 - 9;
//             phi_s0 = 0;
//             phi_s1_2 = temp_s1_4;
//             phi_s1_3 = temp_s1_4;
//             if (temp_t0 > 0) {
//                 do {
//                     temp_v1_2 = -(s32) ((((s32) D_803A05A4_7B1C54.unk0 >> 2) + (phi_s0 >> 2)) << 7);
//                     temp_v0 = phi_s0 * 2;
//                     phi_s1_2->unk0 = (s32) (((temp_v1_2 & 0xFFF) << 0xC) | 0xF2000000);
//                     temp_t3 = (temp_v0 + 0x16) & 0xFF;
//                     temp_a2 = ((temp_v0 + 0x10) & 0xFF) << 0x10;
//                     phi_s1_2->unk4 = (s32) ((((temp_v1_2 + 0x7F) & 0xFFF) << 0xC) | 0x3F);
//                     temp_s0 = phi_s0 + 4;
//                     temp_s1_5 = phi_s1_2 + 8;
//                     temp_s1_5->unk0 = (s32) (temp_a2 | (temp_t3 << 8) | ((temp_v0 + 0x12) & 0xFF) | 0xB1000000);
//                     temp_s1_5->unk4 = (s32) (temp_a2 | (((temp_v0 + 0x14) & 0xFF) << 8) | temp_t3);
//                     temp_s1_6 = temp_s1_5 + 8;
//                     phi_s0 = (s32) temp_s0;
//                     phi_s1_2 = temp_s1_6;
//                     phi_s1_3 = temp_s1_6;
//                 } while ((s32) temp_s0 < temp_t0);
//             }
//             // phi_s1_3->0 -> B8000000;
//             // phi_s1_3->unk4 = 0;
//             gSPEndDisplayList(phi_s1++);
//
//             phi_s5 = phi_s5 + 1;
//             // phi_s1 = phi_s1_3 + 8;
//             // phi_s5 = phi_s5;
//             phi_s6 = (s16) (phi_s6 + temp_s4);
//         } while (phi_s5 < D_803E97C0);
//     }
//     temp_t4 = D_803A05A4_7B1C54.unk0 + 4;
//     D_803A05A4_7B1C54.unk0 = temp_t4;
//     D_803A05A4_7B1C54.unk5A4 = (s16) (temp_t4 & 0xF);
// }

void func_8029E3CC_6AFA7C(void) {
    if (D_803D3434->usedModelViewMtxs < 250) {
        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D343C->xPos.w,
            D_803D343C->zPos.w,
            D_803D343C->yPos.w + (D_803D343C->unk42 << 0xF),
            D_803D343C->zRotation,
            D_803D343C->yRotation,
            D_803D343C->unk40 << 5,
            D_803D343C->unk40 << 5,
            D_803D343C->unk40 << 5);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D3438[D_803D343C->unk64]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}

void func_8029E528_6AFBD8(void) {
    s16 i;

    gSPDisplayList(D_801D9E8C++, &D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650_7D1D00);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);

    for (i = 0; i <= D_803D4BB0.unk1; i++) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2);

        func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D4BB0.unk124[i].unk0,
            D_803D4BB0.unk124[i].unk4,
            D_803D4BB0.unk124[i].unk8,
            D_803D4BB0.unk3F4[i].unk0,
            D_803D4BB0.unk3F4[i].unk2,
            D_803D4BB0.unkAA[i] << 5,
            D_803D4BB0.unkAA[i] << 5,
            D_803D4BB0.unkAA[i] << 5);

        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        // Take Two Interactive Logo ?
        if (D_05006170 == D_803D4BB0.unk4E4[i]) {
            gDPPipeSync(D_801D9E8C++);
            gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, G_RM_AA_ZB_OPA_SURF2);
        }

        gSPDisplayList(D_801D9E8C++, D_803D4BB0.unk4E4[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
    D_803D4BB0.unk1 = -1;
}

void func_8029E7D0_6AFE80(void) {
    s16 i;

    gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP(D_801D9E8C++,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);

    for (i = 0; i <= D_803D45D0.unk0; i++) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        gDPSetPrimColor(D_801D9E8C++, 0, 0,
            D_803D45D0.unk52C[i].r,
            D_803D45D0.unk52C[i].g,
            D_803D45D0.unk52C[i].b,
            0xFF);

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D45D0.unk7C[i].unk0,
            D_803D45D0.unk7C[i].unk4,
            D_803D45D0.unk7C[i].unk8,
            D_803D45D0.unk34C[i].unk0,
            D_803D45D0.unk34C[i].unk2,
            D_803D45D0.unk2[i] << 5,
            D_803D45D0.unk2[i] << 5,
            D_803D45D0.unk2[i] << 5);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D45D0.unk43C[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

        // battery farm tv?
        if (D_0100C120 == D_803D45D0.unk43C[i]) {
            gDPSetCombineLERP(D_801D9E8C++,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0);
            gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
        }
    }

    D_803D45D0.unk0 = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029EAAC_6B015C.s")
// not quite this..
// void func_8029EAAC_6B015C(void) {
//     u8 var_t3;
//     s8 var_t2;
//     s32 var_s6;
//
//     gSPDisplayList(D_801D9E8C++, &D_01004AF8);
//     gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
//
//     // var_t4 = 0xFF;
//     // var_t2 = 0;
//     var_s6 = 0xFF;
//
//     for (var_t2 = 0; var_t2 != -1; var_t2 = D_803D3FF8.unk6E[var_t2]) {
//         var_t3 = D_803D3FF8.unk32[var_t2] & 0x3F;
//         if (var_t3 != var_s6) {
//             if (var_s6 != 0xFF) {
//                 D_803D3FF8.unk2[var_t3] = -1;
//                 var_t3 = D_803D3FF8.unk32[var_t2] & 0x3F;
//             }
//
//             // var_t4 = var_t3 & 0xFF;
//             gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ((s32)&D_0102F010) + (var_t3 << 0xB));
//             gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//             gDPLoadSync(D_801D9E8C++);
//             gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
//             gDPPipeSync(D_801D9E8C++);
//             gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//             gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 124, 124);
//             var_s6 = var_t3;
//         }
//
//         if (D_803D3434->usedModelViewMtxs >= 250) {
//             break;
//         }
//
//         func_80125FE0(
//             &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], // + (temp_v1 << 6) + 0x33590,
//             D_803D3FF8.unk124[var_t2].unk0,
//             D_803D3FF8.unk124[var_t2].unk4,
//             D_803D3FF8.unk124[var_t2].unk8,
//             D_803D3FF8.unk3F4[var_t2].unk0,
//             D_803D3FF8.unk3F4[var_t2].unk2,
//             D_803D3FF8.unkAA[var_t2] << 5,
//             D_803D3FF8.unkAA[var_t2] << 5,
//             D_803D3FF8.unkAA[var_t2] << 5);
//
//         guLookAtReflect(
//             &D_803D3434->unk38CD0[D_803D3434->unk39310],
//             &D_803D3434->unk38A50[D_803D3434->unk39310],
//             D_803F2C44,
//             D_803F2C48,
//             D_803F2C4C,
//             D_803D3FF8.unk124[var_t2].unk0 / 65536.0f,
//             D_803D3FF8.unk124[var_t2].unk4 / 65536.0f,
//             D_803D3FF8.unk124[var_t2].unk8 / 65536.0f,
//             D_80204200,
//             D_80204204,
//             D_80204208);
//
//         gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
//         gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
//         gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//         gSPDisplayList(D_801D9E8C++, D_803D3FF8.unk4E4[var_t2]);
//         gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
//         D_803D3434->unk39310++;
//     }
//
//     D_803D3FF8.unk0 = -1;
//     D_803D3FF8.unk1 = -1;
// }

void func_8029EF20_6B05D0(struct025 *arg0, Gfx **dl) {
    u8 current_texture;
    u8 loaded_texture;
    s8 i;

    i = 0;
    loaded_texture = 0xFF;

    for (;i != -1; i = arg0->unk6E[i]) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        current_texture = arg0->unk32[i] & 0x3F;
        if (current_texture != loaded_texture) {
            loaded_texture = current_texture;
            gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ((s32)&D_800BA760 + (loaded_texture * 0xAB8)));
            gDPTileSync((*dl)++);
            gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPTileSync((*dl)++);
            gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1372, 0);
            gDPTileSync((*dl)++);
        }

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            arg0->unk124[i].unk0,
            arg0->unk124[i].unk4,
            arg0->unk124[i].unk8,
            arg0->unk3F4[i].unk0,
            arg0->unk3F4[i].unk2,
            arg0->unkAA[i] << 5,
            arg0->unkAA[i] << 5,
            arg0->unkAA[i] << 5);

        gSPMatrix((*dl)++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList((*dl)++, arg0->unk4E4[i]);
        gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);

        // tv screen?
        if (D_01017AA0 == arg0->unk4E4[i]) {
            gDPSetCombineMode(D_801D9E8C++, G_CC_TRILERP, G_CC_MODULATEI2);
            gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
        }
    }
}

void func_8029F218_6B08C8(void) {
    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650_7D1D00);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
    gSPDisplayList(D_801D9E8C++, D_01004510);

    if (D_803D3448.unk1 != -1) {
        func_8029EF20_6B05D0(&D_803D3448, &D_801D9E8C);
    }
    if (D_803D3A20.unk1 != -1) {
        gDPPipeSync(D_801D9E8C++);
        gSPTexture(D_801D9E8C++, 32768, 32768, 1, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(D_801D9E8C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E8C++, 0x00, 0x00, 0x00, 0x00);
        gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0 , 0x113078);
        gDPSetCombineMode(D_801D9E8C++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
        func_8029EF20_6B05D0(&D_803D3A20, &D_801D9E8C);
    }
}

void func_8029F3CC_6B0A7C(void) {
    s16 i;

    D_803D3448.unk0 = -1;
    D_803D3448.unk1 = -1;
    D_803D3A20.unk0 = -1;
    D_803D3A20.unk1 = -1;
    D_803D3FF8.unk0 = -1;
    D_803D3FF8.unk1 = -1;
    D_803D45D0.unk0 = -1;
    D_803D4BB0.unk1 = -1;

    for (i = 0; i < 48; i++) {
        D_803D3448.unk2[i] = -1;
        D_803D3A20.unk2[i] = -1;
        D_803D3FF8.unk2[i] = -1;
    }
    func_8029D89C_6AEF4C();
    D_803D5508 = 0;
}

void func_8029F464_6B0B14(struct025 *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8) {
    s8 tmp;
    // arg1 is a 0..63
    if (arg0->unk1 < 59) {
        tmp = arg0->unk2[arg1];
        if (tmp == -1) {
            arg0->unk1++;
            arg0->unk32[arg0->unk1]       = arg1;
            arg0->unk4E4[arg0->unk1]      = arg8;
            arg0->unk3F4[arg0->unk1].unk0 = arg6;
            arg0->unk3F4[arg0->unk1].unk2 = arg7;
            arg0->unkAA[arg0->unk1]       = arg2;
            arg0->unk124[arg0->unk1].unk0 = arg3;
            arg0->unk124[arg0->unk1].unk4 = arg4;
            arg0->unk124[arg0->unk1].unk8 = arg5;

            arg0->unk6E[arg0->unk1] = -1;
            arg0->unk2[arg1] = arg0->unk1;
            if (arg0->unk0 != -1) {
                arg0->unk6E[arg0->unk0] = arg0->unk1;
            }
            arg0->unk0 = arg0->unk1;
        } else {
            arg0->unk1++;
            arg0->unk32[arg0->unk1]       = arg1;
            arg0->unk4E4[arg0->unk1]      = arg8;
            arg0->unk3F4[arg0->unk1].unk0 = arg6;
            arg0->unk3F4[arg0->unk1].unk2 = arg7;
            arg0->unkAA[arg0->unk1]       = arg2;
            arg0->unk124[arg0->unk1].unk0 = arg3;
            arg0->unk124[arg0->unk1].unk4 = arg4;
            arg0->unk124[arg0->unk1].unk8 = arg5;

            arg0->unk6E[arg0->unk1] = arg0->unk6E[tmp];
            arg0->unk6E[tmp] = arg0->unk1;

            if (arg0->unk6E[arg0->unk1] == -1) {
                arg0->unk0 = arg0->unk1;
            }
        }
    }
}

void func_8029F65C_6B0D0C(Animal *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8) {
    arg5 += arg0->unk42 << 0xF;

    if ((arg1 & 0xC0) == 0xC0) { // both flags set?
        func_8029F464_6B0B14(&D_803D3FF8, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else if ((arg1 & 0x40)) {
        func_8029F464_6B0B14(&D_803D3A20, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else if ((arg1 & 0x80)) {
        func_8029DB20_6AF1D0(arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else {
        func_8029F464_6B0B14(&D_803D3448, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029F7D4_6B0E84.s")
