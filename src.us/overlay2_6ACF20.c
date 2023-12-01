#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

void func_8029C8F0_6ADFA0(Gfx **dl);

// ========================================================
// externs
// ========================================================

extern u8  D_01006C60[];
extern Gfx D_010047D0[];
extern Gfx D_010049E8_3E2B8[];
extern Gfx D_01004510_3DDE0[]; // tbd
extern u8  D_010084A0[];
extern Gfx D_0100A6D0_43FA0[];
extern Gfx D_0100A730[];
extern Gfx D_0100AF90_44860[];  // gun turret base
extern Gfx D_0100B2C0_44B90[];  // gun turrent gun
extern Gfx D_0100F4F0_48DC0[];
extern Gfx D_010106E0_49FB0[];
extern Gfx D_01011140_4AA10[];
extern Gfx D_01011AB0_4B380[];
extern Gfx D_01011B78_4B448[];
extern Gfx D_01012B80_4C450[];  // teleporter

extern u8  D_01031010_6A8E0[];

extern Gfx D_040148B0_114600[];
extern Gfx D_04014990_DC3C0[];  // # piece of silicon valley?
extern Gfx D_04015960_DD390[];
extern Gfx D_040165E0_116330[]; // # gherkin looking thing

extern Gfx D_050007A0_A1870[];
extern Gfx D_05001720_8A980[];  // # white/blue capsule thing
extern Gfx D_05004070_8D2D0[];  // # asteroid

extern s32 D_803A8370_7B9A20[]; // tbd

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

struct054 D_803D2D90;

f32  D_803D2DF8;
s16  D_803D2DFC;
s16  D_803D2DFE;
s16  D_803D2E00;

struct059 D_803D2E08;

s32  D_803D3428;
s32  D_803D342C;
s16  D_803D3430;
s16  D_803D3432;
DisplayList* D_803D3434;
s32 *D_803D3438;
Animal *D_803D343C;
struct035 *D_803D3440;
// pad ?
struct025  D_803D3448; // 0x5d4 + 4 ?
struct025  D_803D3A20;
struct025  D_803D3FF8;
struct072  D_803D45D0;
struct025  D_803D4BB0;
struct057  D_803D5188[32];
s16  D_803D5508;

u8 overlay2_6ACF20_post_padding[0x20];

// ========================================================
// .text
// ========================================================

// ESA: func_800750E0
void func_8029B870_6ACF20(Animal *arg0, Animal *arg1) {
    s32 dist = ((arg0->position.xPos.h - arg1->position.xPos.h) * (arg0->position.xPos.h - arg1->position.xPos.h)) +
               ((arg0->position.zPos.h - arg1->position.zPos.h) * (arg0->position.zPos.h - arg1->position.zPos.h));
    if ((arg1->state == 1) &&
        (D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) &&
        (dist < 800) && (arg0->unk16C->unk82.unk2) &&
        (arg1->unk248[1] != NULL) && (arg0->unk320 == 0)) {
        Animal *tmp;
        arg1->unk158 = 1;
        arg0->position.xPos.h = arg1->position.xPos.h;
        arg0->position.zPos.h = arg1->position.zPos.h;
        D_803D2D90.unk4C = arg1->position.xPos.h;
        D_803D2D90.unk4E = arg1->position.zPos.h;
        D_803D2D90.unk50 = arg1->position.yPos.h;
        D_803D2D90.unk2 = 54;
        tmp = arg1->unk248[1];
        D_803D2D90.unk60 = tmp;
        D_803D2D90.unk5C = arg1;
        D_803D2D90.unk52 = tmp->position.xPos.h;
        D_803D2D90.unk54 = tmp->position.zPos.h;
        D_803D2D90.unk56 = tmp->position.yPos.h;
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

// ESA: func_80075248
void func_8029B9B8_6AD068(Animal *arg0, Animal *arg1) {
    D_803D2D90.unk5C = 0;
    D_803D2D90.unk60 = arg1;
    D_803D2D90.unk52 = arg1->position.xPos.h;
    D_803D2D90.unk54 = arg1->position.zPos.h;
    D_803D2D90.unk56 = arg1->position.yPos.h;
    D_803D2D90.unk58 = arg0;
    D_803D2D90.unk58->position.xPos.h = D_803D2D90.unk52;
    D_803D2D90.unk58->position.zPos.h = D_803D2D90.unk54;
    D_803D2D90.unk58->position.yPos.h = D_803D2D90.unk56 + 8;
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

// ESA: func_80075310
void func_8029BA70_6AD120(Animal *arg0, Animal *arg1) {
    if (arg1->state != 0) {
        s32 dist = ((arg0->position.xPos.h - arg1->position.xPos.h) * (arg0->position.xPos.h - arg1->position.xPos.h)) +
                   ((arg0->position.zPos.h - arg1->position.zPos.h) * (arg0->position.zPos.h - arg1->position.zPos.h));
        if ((D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) && (dist < 0x320)) {
            arg1->unk158 = 1;
            D_803D2D90.unk5C = arg1;
            D_803D2D90.unk60 = 0;
            D_803D2D90.unk4C = arg1->position.xPos.h;
            D_803D2D90.unk4E = arg1->position.zPos.h;
            D_803D2D90.unk50 = arg1->position.yPos.h;
            D_803D2D90.unk46 = D_803D2D90.unk4C;
            D_803D2D90.unk48 = D_803D2D90.unk4E;
            D_803D2D90.unk4A = D_803D2D90.unk50;
            D_803D2D90.unk52 = arg1->position.xPos.h;
            D_803D2D90.unk54 = arg1->position.zPos.h;
            D_803D2D90.unk56 = arg1->position.yPos.h;
            D_803D2D90.unk58 = arg0;
            arg0->position.xPos.h = arg1->position.xPos.h;
            arg0->position.zPos.h = arg1->position.zPos.h;
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
// ESA: func_80075438
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
            add_light_at_location(D_803D2D90.unk5C->position.xPos.h, D_803D2D90.unk5C->position.zPos.h, D_803D2D90.unk5C->position.yPos.h + 0x80, 0xFF, 0, 0, 0);
            add_light_at_location(D_803D2D90.unk60->position.xPos.h, D_803D2D90.unk60->position.zPos.h, D_803D2D90.unk60->position.yPos.h + 0x80, 0xFF, 0, 0, 0);
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
                    play_sound_effect_at_location(SFX_UNKNOWN_52, 0x4000, 0x80, D_803D2D90.unk46, D_803D2D90.unk48, D_803D2D90.unk4A, 1.0f);
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
                    play_sound_effect_at_location(SFX_UNKNOWN_52, 0x4000, 0x80, D_803D2D90.unk46, D_803D2D90.unk48, D_803D2D90.unk4A, 1.0f);
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
                D_803D2D90.unk58->position.xPos.h = D_803D2D90.unk52;
                D_803D2D90.unk58->position.zPos.h = D_803D2D90.unk54;
                D_803D2D90.unk58->position.yPos.h = D_803D2D90.unk56 + 8;
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

void func_8029CEF0_6AE5A0(s32 xPos, s32 zPos, s32 yPos, u16 size, u8 arg4, struct059 *arg5, s8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s8 tmp;

    arg5->unk1++;
    if (arg5->unk1 < 75) {
        arg5->unk44[arg5->unk1].unk0 = xPos; // x
        arg5->unk44[arg5->unk1].unk4 = zPos; // z
        arg5->unk44[arg5->unk1].unk8 = yPos; // y
        arg5->unk44[arg5->unk1].unkC = size; // size?
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

#if 0
// bleurgh
void func_8029D0A8_6AE758(void) {
    u8 sp56;
    s16 var_fp;
    s8 var_v0;
    u8 var_t3;

    sp56 = 0xFF;
    var_fp = 0xFF;
    D_803D2E00 += 1;
    D_803D2E00 &= 0xF;

    if ((guRandom() % 20) == 1) {
        if (D_803D342C == 5) {
            D_803D342C = 1;
        } else {
            D_803D342C = 5;
        }
    }

    D_803D3428 += D_803D342C;
    D_803D3428 %= 9;

    gSPDisplayList(D_801D9E90++, D_01004308);
    gSPDisplayList(D_801D9E88++, D_01004B98);

    var_v0 = 0;
    do {
        struct059a *tmp = &D_803D2E08.unk44[var_v0];
        // temp_s4 = (var_v0 * 0x14) + &D_803D2E08;
        // temp_s2 = temp_s4 + 0x44;
        if (tmp->unk12 < 0x20) { // (s32) temp_s4->unk52
            // temp_s2_2 = temp_s4 + 0x44;
            // D_803D2E08.unk44[var_v0]
            if (var_fp != tmp->unkE) {
                if (var_fp != 0xFF) {
                    D_803D2E08.unk2[var_fp] = -1;
                }
                var_fp = tmp->unkE & 0xFF;
                if (var_fp == 0) {
                    func_8029D8D8_6AEF88(&D_801D9EB8, (var_fp + (D_803D3428 / 3)));
                } else {
                    func_8029D8D8_6AEF88(&D_801D9EB8, var_fp);
                }
            }
            if (tmp->unk10 == 127) {
                func_8032E150_73F800(&D_801D9EB8, tmp->unk0, tmp->unk4, tmp->unk8, 0x1F, 0x3F, tmp->unkC * 3);
            } else {
                func_8032E150_73F800(&D_801D9EB8, tmp->unk0, tmp->unk4, tmp->unk8, 0x1F, 0x1F, tmp->unkC * 3);
            }
            gDPPipeSync(D_801D9E88++);
        } else {
            var_t3 = sp56;
            if (tmp->unkE < 0x30) {
                gDPSetPrimColor(D_801D9E90++, 0, 0,
                    tmp->unk11,
                    tmp->unk12,
                    tmp->unk13,
                    0xFF);
                gDPSetEnvColor(D_801D9E90++, 0x11, 0x22, 0x33, 0x44);
            }
            if (var_t3 != tmp->unkE) {
                if (var_t3 != 0xFF) {
                    D_803D2E08.unk2[sp56] = -1;
                }

                var_t3 = tmp->unkE & 0xFF;
                sp56 = var_t3;
                if (var_t3 < 0x30) {
                    // i4/i8/i16?

                    gDPSetCombineLERP(D_801D9E90++,
                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);

                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, ((var_t3 << 0xA) + 0x7FFF8000 + (s32)&D_01029E10));
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);

                } else if (var_t3 == 0x30) {
                    // rgba32

                    // 0x80000000 + -0xc000
                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (((((var_t3 + ((s16) D_803D2E00 >> 1)) << 0xA) + 0xFFFF4000) * 2) + 0x80000000 + (s32)&D_01040CB0));
                    gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 256);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);

                    // 0x80000000 - 0xC000
                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 32, (((var_t3 + ((s16) D_803D2E00 >> 1)) << 0xA) + 0x7FFF4000 + (s32)&D_0103ECB0));
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadTile(D_801D9E90++, G_TX_LOADTILE, 0, 0, 124, 124);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, 1, 0, 0, 124, 124);
                    gDPSetCombineLERP(D_801D9E90++,
                        PRIMITIVE, 0, TEXEL0, 0,
                        PRIMITIVE, 0, TEXEL1, 0,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                }
            }
            if (var_t3 == 0x30) {
                if (tmp->unk10 == 60) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF); // white
                }
                if (tmp->unk10 == 59) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 255, 160, 255, 0xFF);    // light pink
                }
                if (tmp->unk10 == 58) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0x00, 0xFF, 0xFF); // bright pink
                }
            }

            gDPSetDepthSource(D_801D9E90++, G_ZS_PRIM);
            gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

            func_8032DACC_73F17C(
                &D_801D9E90,
                tmp->unk0,
                tmp->unk4,
                tmp->unk8,
                0x1F,
                0x1F,
                tmp->unkC * 3);
            gDPPipeSync(D_801D9E90++);
        }
        var_v0 = tmp->unkF; //unk53; (0x44 + 0xF)
    } while (var_v0 != -1);

    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D0A8_6AE758.s")
#endif

void func_8029D89C_6AEF4C(void) {
    s16 i;
    // struct059
    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
    for (i = 0; i < 64; i++) {
        D_803D2E08.unk2[i] = -1;
    }
}

void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1) {
    u8 *img1;
    u8 *img2;

    if (arg1 < 8) {
        img1 = (u8*)D_800BA760 + 0x1D4C0 + (arg1 << 11); // 2048 bytes per image
        img2 = (u8*)D_800BA760 + 0x214C0 + (arg1 << 9);  // 512 bytes per image
    } else {
        arg1 = arg1 - 8;
        img1 = (u8*)D_800BA760 + 0x1ACC0 + (arg1 << 11); // 2048 bytes per image
        img2 = (u8*)D_800BA760 + 0x1CCC0 + (arg1 << 9);  // 512 bytes per image
    }

    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, OS_K0_TO_PHYSICAL(img1));
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 4*31, 4*31);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);

    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, OS_K0_TO_PHYSICAL(img2));
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 4*31);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, 1, 0, 0, 4*31, 4*31);
}

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
    gSPSetGeometryMode(D_801D9E90++, D_803C0650);
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

extern u8 D_803A0594_7B1C44[16];

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

u8 D_803A0594_7B1C44[16] = {
    0xff, 0xff, 0xff, 0x00, // #ffffff
    0xff, 0xff, 0xff, 0x00, // #ffffff
    0x5e, 0x72, 0xff, 0x00, // #5e72ff
    0x77, 0xc4, 0xff, 0x00, // #77c4ff
};

#endif

#if 0
// CURRENT (1305)
void func_8029E100_6AF7B0(void) {
    static u16 D_803A05A4_7B1C54 = 0; // .data

    Gfx *dl;

    s16 i;
    s16 j;
    s16 vtx_index;
    s32 color_index;
    s16 num_vtxs;

    gSPDisplayList(D_801D9E90++, D_010049E8_3E2B8);


    dl = D_803D3434->unk3B318;

    vtx_index = 0;
    for (i = 0; i < D_803E97C0; i++) {
        gSPDisplayList(D_801D9E90++, dl);

        num_vtxs = D_803D3434->unk3B30A[i];
        gSPVertex(dl++, &D_803D3434->unk39C88[vtx_index], num_vtxs, 0);
        gSPCullDisplayList(dl++, 0, 7);

        color_index = SSSV_RAND(4);
        gDPSetEnvColor(
            dl++,
            0x00,
            0x00,
            0x50,
            0x00);
        gDPSetPrimColor(
            dl++,
            0,
            0,
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 0],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 1],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 2],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 3]);

        for (j = 0; j < num_vtxs - 9; j += 4) {
            s32 uls, ult, lrs, lrt;
            // temp_v1_2 = -(((D_803A05A4_7B1C54 >> 2) + (j >> 2)) << 7);
            // dl_2->unk0 = (Gfx *) (((temp_v1_2 & 0xFFF) << 0xC) | 0xF2000000);
            // dl_2->unk4 = (s32) ((((temp_v1_2 + 0x7F) & 0xFFF) << 0xC) | 0x3F);

            uls = -(((D_803A05A4_7B1C54 >> 2) + ((j) >> 2)) << 7);
            ult = 0;
            lrs = uls + 0x7F;
            lrt = ult + 0x3F;

            gDPSetTileSize(
            /* pkt */ dl++,
            /* t   */ G_TX_RENDERTILE,
            /* uls */ uls,
            /* ult */ ult,
            /* lrs */ lrs,
            /* lrt */ lrt);

            // temp_v0 = j * 2;
            // temp_s1_4->unk0 = (((((temp_v0 + 16) & 0xFF) << 0x10) | (((temp_v0 + 22) & 0xFF) << 8) | ((temp_v0 + 18) & 0xFF) | 0xB1000000);
            // temp_s1_4->unk4 =  ((((temp_v0 + 16) & 0xFF) << 0x10) | (((temp_v0 + 20) & 0xFF) << 8) | ((temp_v0 + 22) & 0xFF));

            gSP1Quadrangle(
            /* pkt  */ dl++,
            /* v0   */ (j + 9) + 2, // addiu   a3,v0,0x16
            /* v1   */ (j + 9) - 1, // addiu   a2,v0,0x10
            /* v2   */ (j + 9) + 0, // addiu   t8,v0,0x12
            /* v3   */ (j + 9) + 1, // addiu   t2,v0,0x14
            /* flag */ 0);
        }
        gSPEndDisplayList(dl++);
        vtx_index += num_vtxs;
    }
    D_803A05A4_7B1C54 += 4;
    D_803A05A4_7B1C54 &= 0xF;

}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E100_6AF7B0.s")
#endif

void func_8029E3CC_6AFA7C(void) {
    if (D_803D3434->usedModelViewMtxs < 250) {
        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D343C->position.xPos.w,
            D_803D343C->position.zPos.w,
            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
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
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);

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
            gDPSetRenderMode(D_801D9E8C++, D_803C0640, G_RM_AA_ZB_OPA_SURF2);
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
    gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);

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
            gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);
        }
    }

    D_803D45D0.unk0 = -1;
}

void func_8029EAAC_6B015C(void) {
    u8 loaded_texture;
    u8 current_texture;
    s8 i;

    gSPDisplayList(D_801D9E8C++, &D_01004AF8);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);

    current_texture = 0xFF;
    loaded_texture = 0xFF;
    i = 0;
    for (; i != -1; i = D_803D3FF8.unk6E[i])  {
        current_texture = loaded_texture;
        if (current_texture != (D_803D3FF8.unk32[i] & 0x3F)) {
            if (loaded_texture != 0xFF) {
                // mark current texture as unloaded?
                D_803D3FF8.unk2[loaded_texture] = -1;
            }

            loaded_texture = D_803D3FF8.unk32[i] & 0x3F;

            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_0102F010[loaded_texture << 0x8]);
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPLoadSync(D_801D9E8C++);
            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
            gDPPipeSync(D_801D9E8C++);
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 124, 124);
        }

        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D3FF8.unk124[i].unk0,
            D_803D3FF8.unk124[i].unk4,
            D_803D3FF8.unk124[i].unk8,
            D_803D3FF8.unk3F4[i].unk0,
            D_803D3FF8.unk3F4[i].unk2,
            D_803D3FF8.unkAA[i] << 5,
            D_803D3FF8.unkAA[i] << 5,
            D_803D3FF8.unkAA[i] << 5);

        guLookAtReflect(
            &D_803D3434->unk38CD0[D_803D3434->unk39310],
            &D_803D3434->unk38A50[D_803D3434->unk39310],
            D_803F2C44, D_803F2C48, D_803F2C4C,
            D_803D3FF8.unk124[i].unk0 / 65536.0f,
            D_803D3FF8.unk124[i].unk4 / 65536.0f,
            D_803D3FF8.unk124[i].unk8 / 65536.0f,
            D_80204200,
            D_80204204,
            D_80204208);

        gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
        gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D3FF8.unk4E4[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
        D_803D3434->unk39310++;
    }

    D_803D3FF8.unk0 = -1;
    D_803D3FF8.unk1 = -1;
}

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
            gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);
        }
    }
}

void func_8029F218_6B08C8(void) {
    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648);
    gSPDisplayList(D_801D9E8C++, D_01004510);

    if (D_803D3448.unk1 != -1) {
        func_8029EF20_6B05D0(&D_803D3448, &D_801D9E8C);
    }
    if (D_803D3A20.unk1 != -1) {
        gDPPipeSync(D_801D9E8C++);
        gSPTexture(D_801D9E8C++, 32768, 32768, 1, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(D_801D9E8C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E8C++, 0x00, 0x00, 0x00, 0x00);
        gDPSetRenderMode(D_801D9E8C++, D_803C0640 , 0x113078);
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

#if 0
s32 D_803A8370_7B9A20[] = {
    // 007b9a20: 0103 4190 0103 3190 0103 4990 0000 0000  ..A...1...I.....
    D_01034190,
    D_01033190,
    D_01034990,
    0, // or just alignment
}

#endif

typedef struct {
  s16 unk0;
  s16 unk2;
  s16 unk4;

  s16 unk6;
  s16 unk8;
  s16 unkA;

  s16 unkC;
  s16 unkE;
  s16 unk10;
} fixme;

// could be s16[3][3] ?
extern fixme D_803A0580_7B1C30;

typedef struct {
  s16 unk0;
  s16 unk2;
  s16 unk4;
  s16 unk6;
  s16 unk8;
} fixme3; // size 0xA;

#if 0
fixme3 *D_803B1CDC_7C338C[16] = {
    D_803B1BCC_7C327C,
    D_803B1BEC_7C329C,
    D_803B1BF0_7C32A0,
    D_803B1BFC_7C32AC,
    D_803B1C1C_7C32CC,
    D_803B1C28_7C32D8,
    D_803B1C34_7C32E4,
    D_803B1C40_7C32F0,
    D_803B1C4C_7C32FC,
    D_803B1C58_7C3308,
    D_803B1C78_7C3328,
    D_803B1CC0_7C3370,
    D_803B1CCC_7C337C,
    D_803B1CD0_7C3380,
    D_803B1CD4_7C3384,
    D_803B1CD8_7C3388,
};
#else
extern fixme3 * D_803B1CDC_7C338C[];
#endif


#if 0
// CURRENT (54678)
void func_8029F7D4_6B0E84(DisplayList *arg0, s32 arg1) {
    // ? *sp480;                                       /* compiler-managed */
    u8        pad[0x68];
    struct077 sp318;
    struct077 sp2AC;
    s32 sp2A8;
    // s32 sp2A4;
    // s32 sp298;
    f32 temp_f20;

    fixme3 *var_s0;
    s16 temp_a2;

    s16 temp_v0_5;
    s16 temp_v0_7;
    s16 temp_v1_5;
    s16 i;
    s16 x;
    s16 var_s4;
    s16 var_t4;
    s16 var_t5;
    s32 green;
    s32 temp_t6_2;

    s32 temp_t7_2;
    s32 temp_t8_3;
    s32 temp_t8_4;
    s32 temp_t8_6;

    s32 temp_v0_6;
    s32 var_s0_3;
    s32 red;
    s32 var_s4_6;
    s32 var_t1;
    s32 var_t3;
    s32 var_v0_3;
    u16 var_v1;

    struct065 *var_a1;

    u16 color;

    u16 temp_v0_9;
    u16 var_s4_2;

    u8 var_s0_2;

    struct077 sp210;

    // s8 sp1AC;


    D_803D3430 = D_803D3430 + 1;
    D_803D3430 = D_803D3430 % 5;

    D_803D3432 = D_803D3432 + 8;
    D_803D3432 = D_803D3432 & 0x7F;

    D_803D3434 = arg0;

    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);

    // var_v0 = D_803DA110;
    // something like this?
    for (x = 0; x < 40; x++) {
        for (var_a1 = D_803DA110[x].next; var_a1 != NULL; var_a1 = var_a1->next) {
            D_803D343C = var_a1->animal;
            D_803D3440 = D_803D343C->unk16C;
            D_803D3438 = &D_803D3440->unk4;

            if (((D_803D3440->unk82.unk2 == 0)) && (var_a1 == &D_803D343C->unk11C[0])) {
                temp_t6_2 = D_803D343C->unk3E & 0x3F;
                if (temp_t6_2 != 40) {
                    switch (D_803D3440->unk3) {
                    case 6:
                    case 15:
                        // get rgba16 color (first u16 of image?)
                        color = func_8029A52C_6ABBDC(temp_t6_2);
                        var_v1 = func_802E8BBC_6FA26C(
                            D_803D343C->position.xPos.w,
                            D_803D343C->position.zPos.w,
                            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                            (D_803D3440->unk8E * D_803D343C->unk40) >> 0xB,
                            D_803D3440->unk90,
                            (((color & 0xF800) >> 9) & 0xFF), // red
                            (((color & 0x7C0) >> 4) & 0xFF),  // green
                            (((color & 0x3E) << 1) & 0xFF),   // blue
                            D_803D3440->unk94,
                            0);
                            break;
                    default:
                        var_v1 = func_802E8BBC_6FA26C(
                            D_803D343C->position.xPos.w,
                            D_803D343C->position.zPos.w,
                            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                            (D_803D3440->unk8E * D_803D343C->unk40) >> 0xB,
                            D_803D3440->unk90,
                            D_803D3440->unk91, // red
                            D_803D3440->unk92, // green
                            D_803D3440->unk93, // blue
                            D_803D3440->unk94,
                            0);
                        break;
                    }

                    switch (var_v1) {
                    case 0:
                    case 2:
                        if (((D_803D343C->unk3E & 0xC0) != 0x80) && !(D_803D343C->unk163 & 8)) {
                            // temp_t8 = D_803D3440->unk96.a; // >> 12;
                            if (D_803D3440->unk96.a == 1) {
                                func_8034C8F8_75DFA8(
                                    D_803D343C->position.xPos.h,
                                    D_803D343C->position.zPos.h,
                                    (D_803D343C->position.yPos.h + (D_803D343C->unk42 >> 1)),
                                    ((D_803D343C->yRotation << 8) / 360),
                                    D_803A8370_7B9A20[D_803D3440->unk96.c], // & 0xF],
                                    ((D_803D3440->unk96.c * D_803D343C->unk40) >> 0xB),
                                    ((D_803D3440->unk98 * D_803D343C->unk40) >> 0xB),
                                    0x9B,
                                    0,
                                    0,
                                    0,
                                    D_803D3440->unk99,
                                    0);
                            } else if (D_803D3440->unk96.a == 2) {
                                func_8034BD20_75D3D0(
                                    D_803D343C->position.xPos.h,
                                    D_803D343C->position.zPos.h,
                                    (D_803D343C->position.yPos.h + (D_803D343C->unk42 >> 1)),
                                    ((D_803D343C->yRotation << 8) / 360),
                                    D_803A8370_7B9A20[D_803D3440->unk96.c], // & 0xF],
                                    ((D_803D3440->unk96.c * D_803D343C->unk40) >> 0xB),
                                    ((D_803D3440->unk98 * D_803D343C->unk40) >> 0xB),
                                    0x9B,
                                    0,
                                    0,
                                    0,
                                    D_803D3440->unk99,
                                    0);
                            }
                        }
                        break;
                    }
                    // switch?
                    switch (var_v1) {
                    case 0:
                        switch (D_803D3440->unk4) {
                        case 0:
                            break; // not this
                        case 1:
                            func_8029CEF0_6AE5A0(
                                D_803D343C->position.xPos.w,
                                D_803D343C->position.zPos.w,
                                D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                                D_803D343C->unk40,
                                D_803D3440->unk14 + D_803D343C->unk64,
                                &D_803D2E08,
                                D_803D3440->objectType,
                                0,
                                0,
                                0);
                            break;
                        case 2:
                            if (D_803D4BB0.unk1 < 60) {
                                D_803D4BB0.unk1++;
                                D_803D4BB0.unk32[D_803D4BB0.unk1] = (s8) (D_803D343C->unk3E & 0x3F);
                                D_803D4BB0.unk4E4[D_803D4BB0.unk1] = D_803D343C->unk16C->unk4;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                D_803D4BB0.unkAA[D_803D4BB0.unk1] = D_803D343C->unk40;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                            }
                            break;
                        case 3:
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.unk43C[D_803D45D0.unk0] = D_803D343C->unk16C->unk4;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.unk52C[D_803D45D0.unk0].r = 0;
                                D_803D45D0.unk52C[D_803D45D0.unk0].g = 0;
                                D_803D45D0.unk52C[D_803D45D0.unk0].b = 0;
                            }
                            break;
                        case 4:
                            if (D_803D3434->usedModelViewMtxs >= 0xFA) {
                                // debug something?
                                continue; // ?
                            } else {
                                gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF);
                                gDPSetTextureLUT(D_801D9E8C++, G_TT_NONE);
                                gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                // temp_s0_9->words.w0 = 0x06000000;
                                // temp_s0_9->words.w1 = (u32) D_803D3438->unk0;
                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]); // TBD
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

                                if (D_803D343C->state == 1) {
                                    var_v0_3 = 4;
                                } else {
                                    var_v0_3 = 5;
                                }
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w,
                                    D_803D343C->position.zPos.w,
                                    D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF) + (D_803D343C->unk40 * 0x6E0),
                                    (s32)(D_803D343C->unk40 * 0.6),
                                    var_v0_3,
                                    &D_803D2E08,
                                    D_803D343C->unk3E,
                                    0,
                                    0,
                                    0);
                            }
                            break;
                        case 5:
                            if ((D_803D3434->usedModelViewMtxs + 2) >= 0xFA) {
                                continue; // ?
                            } else {
                                gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

                                gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);

                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);

                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]);
                                guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0.0f, 8.0f, 10.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                guRotate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], (f32) ((s16) D_803D343C->unk28 >> 5), 0.0f, 1.0f, 0.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[1]);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                // temp_s0_20->words.w1 = -0x1C8U; // b'\xff\xff\xfe8'
                                // temp_s0_20->words.w0 = 0xFC1219FF;
                                gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2); // TBD
                                gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_ON);
                            }
                            break;
                        case 6:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            break;
                        case 7:
                            if ((D_803D3434->usedModelViewMtxs + 1) >= 0xFA) {
                                continue; // ?
                            } else {
                                if (D_803D343C->state == 1) {
                                    func_8032CD70_73E420(D_803D343C, 0x83, 0x2AAA, 0, 1.0f, (s16) (s32) D_803D343C->position.xPos.h, (s16) (s32) D_803D343C->position.zPos.h, (s16) (s32) D_803D343C->position.yPos.h);
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);

                                    var_s4 = (D_803D3430 / 2);
                                    temp_v0_5 = distance_from_player(D_803D343C->position.xPos.h, D_803D343C->position.zPos.h, D_803D343C->position.yPos.h + D_803D343C->unk42 + 2);
                                    if (temp_v0_5 >= 512) {
                                        var_t4 = 0xFF;
                                        var_t5 = 0x7F;
                                    } else {
                                        var_t4 = temp_v0_5 / 2;
                                        var_t5 = temp_v0_5 / 4;
                                    }
                                    gSPDisplayList(D_801D9E90++, D_010049A0_3E270);
                                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_0100A730);
                                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                    gDPLoadSync(D_801D9E90++);
                                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 511, 512);
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
                                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, D_803D3432, 4*(31), 4*(31));
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                                    gSPTexture(D_801D9E90++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON); // qu016(0.5)
                                    gDPSetTextureLOD(D_801D9E90++, G_TL_TILE);
                                    gDPSetCombineLERP(D_801D9E90++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, COMBINED, COMBINED, 0, SHADE, 0);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
                                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xB9, 0xB9, 0xFF, var_t4);
                                    gDPSetEnvColor(D_801D9E90++, 0x64, 0x64, 0xBE, var_t5);

                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_0100A6D0_43FA0);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPDisplayList(D_801D9E90++, D_01003B70_3D440);
                                } else {
                                    var_s4 = 0;
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0x00, 0x00, 0xFF, 0xFF);
                                }
                                gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                                gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_010084A0 + (var_s4 * 0xAB8));
                                gDPTileSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPTileSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                                gDPTileSync(D_801D9E8C++);
                                gSPTexture(D_801D9E8C++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF) + 0x20000, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_01012B80_4C450);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                gDPPipeSync(D_801D9E8C++);

                                D_803D3434->unk39310++;
                            }
                            break;
                        case 8:
                            if (D_803D343C->unk16C->unk4 != 0) {
                                func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            }
                            for (var_s0 = D_803B1CDC_7C338C[D_803D3440->unk14]; var_s0->unk0 != 9999; var_s0 += 1) {
                                func_802F603C_7076EC(var_s0->unk0 << 6, var_s0->unk2 << 6, var_s0->unk4 << 6, D_803D343C->zRotation, (s32) D_803D343C->yRotation, (s32) D_803D343C->unk40, &sp318);
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w + (sp318.unk0 << 0xA),
                                    D_803D343C->position.zPos.w + (sp318.unk2 << 0xA),
                                    D_803D343C->position.yPos.w + (sp318.unk4 << 0xA) + (D_803D343C->unk42 << 0xF),
                                    ((var_s0->unk6 * D_803D343C->unk40) >> 0xB) ,
                                    var_s0->unk8,
                                    &D_803D2E08,
                                    D_803D343C->unk3E,
                                    D_803D343C->unk200[0],
                                    D_803D343C->unk200[1],
                                    D_803D343C->unk200[2]);
                            }
                            break;
                        case 9:
                            func_8029F464_6B0B14(&D_803D3FF8, D_803D343C->unk3E & 0x3F, (s32) D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            break;
                        case 10:
                            temp_v0_7 = 0x100 - D_803D343C->unk150;
                            temp_f20 = (1.0f - ((COS(temp_v0_7 << 3) / (temp_v0_7 + 16.0f)) / 16383.0f)) * (D_803D343C->unk40 / 2048.0f);
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, 0, 0, D_0100AF90_44860);
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, (temp_f20 * 2048.0f), D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_0100B2C0_44B90);
                            break;
                        case 11:
                            if (D_803D3434->usedModelViewMtxs >= 248) {
                                continue; // ?
                            } else {
                                gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                                gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E]);
                                gDPTileSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPTileSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                                gDPTileSync(D_801D9E8C++);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]);
                                guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0.0f, 8.0f, 10.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                guRotate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], (f32) ((s16) D_803D343C->unk28 >> 5), 0.0f, 1.0f, 0.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[1]);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            }
                            break;
                        case 12:
                            if (D_803D343C->state == 1) {
                                var_s0_2 = 0xFF;
                            } else {
                                var_s0_2 = 0x40;
                            }
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            func_802F5F44_7075F4(0, 0, (s16) ((s32) (D_803D343C->unk40 * ((s16) COS(D_803D343C->unk14E) >> 9)) >> 0xB), D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, &sp2AC);
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.unk43C[D_803D45D0.unk0] = D_803D343C->unk16C->unk8;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w + (sp2AC.unk0 << 0xD);
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w + (sp2AC.unk2 << 0xD);
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (sp2AC.unk4 << 0xD) + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.unk52C[D_803D45D0.unk0].r = var_s0_2;
                                D_803D45D0.unk52C[D_803D45D0.unk0].g = 0;
                                D_803D45D0.unk52C[D_803D45D0.unk0].b = 0;
                            }
                            func_802F603C_7076EC(0xF, 4, 0, D_803D343C->zRotation, (s32) D_803D343C->yRotation, (s32) D_803D343C->unk40, &sp2AC);
                            func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + ((s16) sp2AC.unk0 << 0x10), D_803D343C->position.zPos.w + (sp2AC.unk2 << 0x10), D_803D343C->position.yPos.w + (sp2AC.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), ((s32) D_803D343C->unk40 >> 2), (u8) 0x20, &D_803D2E08, (s8) 0, (u8) (s32) var_s0_2, (u8) 0, (u8) 0);
                            break;
                        case 13:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            sp2A8 = (D_803D343C->position.yPos.h + (D_803D343C->unk42 * 0.6));
                            temp_t7_2 = ((COS(D_803D343C->unk152) >> 7) * (D_803D343C->unk42 >> 2)) >> 8;
                            temp_t8_3 = (D_803D343C->unk14E * (s32) ((D_803D343C->unk40 << 5) * 0.125)) >> 8;
                            temp_t8_4 = SIN(D_803D343C->unk152) >> 7;

                            var_t3 = (ABS(temp_t8_4) * temp_t8_3) >> 8;
                            var_t1 = var_t3;

                            if (temp_t7_2 < 0) {
                                var_t1 = temp_t8_3;
                            } else {
                                var_t3 = temp_t8_3;
                            }
                            if (D_803D343C->unk14E > 0) {
                                red = ABS(temp_t8_4);
                                if (red > 0xFF) {
                                    red = 0xFF;
                                }
                                green = red >> 1;
                                gDPPipeSync(D_801D9E90++);
                                gSPDisplayList(D_801D9E90++, D_01004970_3E240);
                                gDPSetPrimColor(D_801D9E90++, 0, 0, (0xFF - red), (0xFF - green), 0xFF, 0xA0);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, (sp2A8 + temp_t7_2) << 0x10, (s16) 0x14, (s16) ((s32) (D_803D343C->unk152 * 0x168) >> 8), var_t1, var_t1, var_t1);
                                gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E90++, D_0101B000_548D0);
                                gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                                gDPSetPrimColor(D_801D9E90++, 0, 0, red, green + 0x80, 0xFF, 0xA0);

                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, (sp2A8 - temp_t7_2) << 0x10, (s16) -0x14, (s16) ((s32) (D_803D343C->unk152 * 0x168) >> 8), var_t3, var_t3, var_t3);
                                gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E90++, D_0101B000_548D0);
                                gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                            }
                            if (D_803D343C->state == 1) {
                                var_v0_3 = 4;
                            } else {
                                var_v0_3 = 5;
                            }

                            func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk40 * 0x600), (s32) (D_803D343C->unk40 * 0.2), (u8) var_v0_3, &D_803D2E08, (s8) (s32) D_803D343C->unk3E, (u8) 0, (u8) 0, (u8) 0);
                            break;
                        case 15:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            var_s4_2 = D_803D343C->unk40;
                            if (D_801552B0 != 0) {
                                var_s4_2 += guRandom() % 600;
                                D_803F2D24 = 1;
                            } else {
                                D_803F2D24 = 0;
                            }
                            gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                            gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2); // TBD

                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, var_s4_2 << 5, var_s4_2 << 5, var_s4_2 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_010106E0_49FB0);
                            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            var_s4_2 = D_803D343C->unk40;
                            if (D_801552B4 != 0) {
                                var_s4_2 += guRandom() % 600;
                            }
                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, var_s4_2 << 5, var_s4_2 << 5, var_s4_2 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_01011140_4AA10);
                            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            break;
                        case 16:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
                            if (D_803E4D28 & 4) {
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, G_RM_AA_ZB_OPA_SURF2);
                            } else {
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                            }
                            gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E & 0x3F]);
                            gDPTileSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                            gDPTileSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                            gDPTileSync(D_801D9E8C++);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, 1, 0);
                            break;
                        case 17:
                            func_8029F464_6B0B14(&D_803D3FF8, D_803D343C->unk3E & 0x3F, (s32) D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            if (D_803D343C->unk200[0] & 2) {
                                func_802F603C_7076EC(D_803A0580_7B1C30.unk0, D_803A0580_7B1C30.unk2, D_803A0580_7B1C30.unk4, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (u32) (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, 0x64, 0x64);
                            }
                            if (D_803D343C->unk200[0] & 4) {
                                func_802F603C_7076EC(-D_803A0580_7B1C30.unk0, D_803A0580_7B1C30.unk2, D_803A0580_7B1C30.unk4, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (u32) (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, 0x64, 0x64);
                            }
                            if (D_803D343C->unk200[0] & 0x18) {
                                if (D_803D343C->unk200[0] & 8) {
                                    var_s0_3 = 0xFF;
                                } else {
                                    var_s0_3 = 0;
                                }
                                func_802F603C_7076EC(D_803A0580_7B1C30.unk6, D_803A0580_7B1C30.unk8, D_803A0580_7B1C30.unkA, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (u32) (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, var_s0_3, 0);
                                func_802F603C_7076EC(-D_803A0580_7B1C30.unk6, D_803A0580_7B1C30.unk8, D_803A0580_7B1C30.unkA, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (u32) (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, var_s0_3, 0);
                            }
                            if (D_803D343C->unk200[0] & 0x20) {
                                func_802F603C_7076EC(D_803A0580_7B1C30.unkC, D_803A0580_7B1C30.unkE, D_803A0580_7B1C30.unk10, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                if (D_803D4BB0.unk1 < 60) {
                                    D_803D4BB0.unk1++;
                                    D_803D4BB0.unk32[D_803D4BB0.unk1] = (s8) (D_803D343C->unk3E & 0x3F);
                                    D_803D4BB0.unk4E4[D_803D4BB0.unk1] = D_05004070_8D2D0;
                                    D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                    D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                    D_803D4BB0.unkAA[D_803D4BB0.unk1] = D_803D343C->unk40;
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w + (sp210.unk0 << 0x10);
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w + (sp210.unk2 << 0x10);
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF);
                                    D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                                }
                            }
                            break;
                        case 18:
                            if (D_803D343C->state == 1) {
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->unk40, D_803D343C->unk3E, &D_803D2E08, 0, D_803D343C->unk200[0], D_803D343C->unk200[1], D_803D343C->unk200[2]);
                            }
                            break;
                        case 22:
                            if (D_803D343C->state == 1) {
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->unk40, D_803D343C->unk3E, &D_803D2E08, 0x7F, D_803D343C->unk200[0], D_803D343C->unk200[1], D_803D343C->unk200[2]);
                            }
                            break;
                        case 19:
                            if (D_803D343C->state == 1) {
                                var_s4_6 = (D_803D343C->unk40 * 3) >> 2;
                            } else {
                                var_s4_6 = D_803D343C->unk40;
                            }
                            if (D_803D4BB0.unk1 < 60) {
                                D_803D4BB0.unk1++;
                                D_803D4BB0.unk32[D_803D4BB0.unk1] = (s8) (D_803D343C->unk3E & 0x3F);
                                D_803D4BB0.unk4E4[D_803D4BB0.unk1] = D_803D343C->unk16C->unk4;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                D_803D4BB0.unkAA[D_803D4BB0.unk1] = var_s4_6;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                            }
                            if ((D_803D3434->usedModelViewMtxs + 2) >= 0xFA) {
                                continue; // ?
                            } else {
                                gDPSetTextureLUT(D_801D9E8C++, G_TT_NONE);
                                gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                if (D_803D343C->state == 1) {
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
                                } else {
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0x40, 0x00, 0x00, 0xFF);
                                }
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, var_s4_6 << 5, var_s4_6 << 5, var_s4_6 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_01011B78_4B448);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

                                if (D_803D343C->state == 1) {
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
                                    gDPSetCycleType(D_801D9E90++, G_CYC_1CYCLE);
                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADING_SMOOTH);
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gDPSetCombineLERP(D_801D9E90++, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0x00, 0x00, 0xA0);

                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, temp_t8_6, temp_t8_6, temp_t8_6);
                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_01011AB0_4B380);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                                    gSPSetGeometryMode(D_801D9E90++, G_FOG);
                                }
                            }
                            break;
                        case 20:
                            if (D_803D343C->state == 1) {
                                // help
                            }
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.unk43C[D_803D45D0.unk0] = D_803D343C->unk16C->unk4;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.unk52C[D_803D45D0.unk0].r = 0;
                                D_803D45D0.unk52C[D_803D45D0.unk0].g = 0 ; //sp1AD;
                                D_803D45D0.unk52C[D_803D45D0.unk0].b = 0 ; //sp1AE;
                            }
                            if (D_803D343C->state == 1) {
                                if (D_803D3434->usedModelViewMtxs >= 0xFA) {
                                    continue; // ?
                                } else {
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
                                    gDPSetCycleType(D_801D9E90++, G_CYC_1CYCLE);
                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADING_SMOOTH);
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gDPSetCombineLERP(D_801D9E90++, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_0100F4F0_48DC0);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                                    gSPSetGeometryMode(D_801D9E90++, G_FOG);
                                }
                            }
                            break;
                        case 21:
                            gSPDisplayList(D_801D9E8C++, D_01004AF8);
                            if (D_803E4D28 & 4) {
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, G_RM_AA_ZB_OPA_SURF2);
                            } else {
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                            }
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010[(D_803D343C->unk3E & 0x3F) << 0xB]); //  << 0xB
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPLoadSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
                            gDPPipeSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)); // qu102
                            guLookAtReflect(&D_803D3434->unk38CD0[D_803D3434->unk39310], &D_803D3434->unk38A50[D_803D3434->unk39310], D_803F2C44, D_803F2C48, D_803F2C4C, (f32) D_803D343C->position.xPos.w / 65536.0f, (f32) D_803D343C->position.zPos.w / 65536.0f, (f32) D_803D343C->position.yPos.w / 65536.0f, D_80204200, D_80204204, D_80204208);
                            gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
                            gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, (u8) 3, (u8) 1);
                            break;
                        case 23:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
                            gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_040165E0_116330 : D_05001720_8A980);

                            if (D_803D343C->unk158 == 0) {
                                for (i = 0; i < 3; i++) {
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0, 0, 0, 0, i * 120, 0x10000, 0x10000, 0x10000);
                                    gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_040148B0_114600 : D_04014990_DC3C0);
                                    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                }
                            }
                            if (D_803D343C->unk158 == 0) {
                                gSPDisplayList(D_801D9E8C++, D_01004AF8);
                                gDPSetRenderMode(D_801D9E8C++, D_803C0640, D_803C0648); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_01031010_6A8E0);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
                                gDPPipeSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

                                guLookAtReflect(&D_803D3434->unk38CD0[D_803D3434->unk39310], &D_803D3434->unk38A50[D_803D3434->unk39310], D_803F2C44, D_803F2C48, D_803F2C4C, (f32) D_803D343C->position.xPos.w / 65536.0f, (f32) D_803D343C->position.zPos.w / 65536.0f, (f32) D_803D343C->position.yPos.w / 65536.0f, D_80204200, D_80204204, D_80204208);
                                gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
                                gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
                                D_803D3434->unk39310++;

                                for (i = 0; i < 3; i++) {
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0, 0, 0, 0, i * 120, 0x10000, 0x10000, 0x10000);
                                    gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_050007A0_A1870 : D_04015960_DD390);
                                    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                }
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            }
                            break;
                        case 24:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, D_803C0650);
                            gDPSetRenderMode(D_801D9E8C++, D_803C0640, G_RM_AA_ZB_OPA_SURF2);
                            gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E & 0x3F]);
                            gDPTileSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                            gDPTileSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                            gDPTileSync(D_801D9E8C++);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, (u8) 4, (u8) 2);                                break;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    if (D_803D5508 > 0) {
        func_8029DD84_6AF434();
    }
    if (D_803D4BB0.unk1 != -1) {
        func_8029E528_6AFBD8();
    }
    if (D_803D45D0.unk0 != -1) {
        func_8029E7D0_6AFE80();
    }
    if (D_803D3FF8.unk1 != -1) {
        func_8029EAAC_6B015C();
    }
    func_8029F218_6B08C8();
    if (D_803D2E08.unk1 != -1) {
        func_8029D0A8_6AE758();
    }
    if (D_803E97C0 > 0) {
        func_8029E100_6AF7B0();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029F7D4_6B0E84.s")
#endif
