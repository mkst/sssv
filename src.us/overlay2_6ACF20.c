#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

void func_8029C8F0_6ADFA0(Gfx **dl);

// ========================================================
// externs
// ========================================================

extern u8  img_D_01006C60_40530_i4__png[];

// ========================================================
// .data
// ========================================================

// unused data
extern u8 D_803A0530_7B1BE0[10][8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,
    0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF,
    0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x50, 0x50, 0x50, 0x00, 0x50, 0x50, 0x50, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
};

// ========================================================
// .bss
// ========================================================

struct054 D_803D2D90; // also used by camera

static f32  D_803D2DF8;
static s16  D_803D2DFC;
static s16  D_803D2DFE;

// ========================================================
// .text
// ========================================================

// ESA: func_800750E0
void maybe_trigger_exit_teleporter(Animal *arg0, Animal *teleporter) {
    s32 dist = ((arg0->position.xPos.h - teleporter->position.xPos.h) * (arg0->position.xPos.h - teleporter->position.xPos.h)) +
               ((arg0->position.zPos.h - teleporter->position.zPos.h) * (arg0->position.zPos.h - teleporter->position.zPos.h));

    if ((teleporter->state == 1) &&
        (D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) &&
        (dist < 800) && (arg0->unk16C->unk82.unk2) &&
        (teleporter->unk248[1] != NULL) && (arg0->unk320 == NULL)) {
        Animal *tmp;
        teleporter->unk158 = 1;
        arg0->position.xPos.h = teleporter->position.xPos.h;
        arg0->position.zPos.h = teleporter->position.zPos.h;
        D_803D2D90.unk4C = teleporter->position.xPos.h;
        D_803D2D90.unk4E = teleporter->position.zPos.h;
        D_803D2D90.unk50 = teleporter->position.yPos.h;
        D_803D2D90.unk2 = OBJECT_TELEPORTER_BASE;
        tmp = teleporter->unk248[1];
        D_803D2D90.unk60 = tmp;
        D_803D2D90.unk5C = teleporter;
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
        arg0->attackTimer = D_803D5544;
    }
}

// ESA: func_80075248
// trigger_entrance_teleporter
void func_8029B9B8_6AD068(Animal *player, Animal *teleporter) {
    D_803D2D90.unk5C = 0;
    D_803D2D90.unk60 = teleporter;
    D_803D2D90.unk52 = teleporter->position.xPos.h;
    D_803D2D90.unk54 = teleporter->position.zPos.h;
    D_803D2D90.unk56 = teleporter->position.yPos.h;
    D_803D2D90.unk58 = player;
    D_803D2D90.unk58->position.xPos.h = D_803D2D90.unk52;
    D_803D2D90.unk58->position.zPos.h = D_803D2D90.unk54;
    D_803D2D90.unk58->position.yPos.h = D_803D2D90.unk56 + 8;
    D_803D2D90.unk58->xVelocity.w = 0;
    D_803D2D90.unk58->zVelocity.w = 0;
    D_803D2D90.unk58->yVelocity.w = 0;
    D_803D2D90.unk58->unk68 = D_803D2D90.unk60;
    D_803D2D90.unk58->unk70 = NULL;
    D_803D2D90.unk58->unk160 = D_803D2D90.unk60->unk160;
    D_803D2D90.unk0 = 3;
    D_803D2D90.unk2 = OBJECT_ENTRANCE_TELEPORTER;
    player->unk364 = 16;
    player->attackTimer = D_803D5544 - 150;
}

// ESA: func_80075310
void maybe_do_teleport(Animal *arg0, Animal *teleporter) {
    if (teleporter->state != 0) {
        s32 dist = ((arg0->position.xPos.h - teleporter->position.xPos.h) * (arg0->position.xPos.h - teleporter->position.xPos.h)) +
                   ((arg0->position.zPos.h - teleporter->position.zPos.h) * (arg0->position.zPos.h - teleporter->position.zPos.h));

        if ((D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) && (dist < 800)) {
            teleporter->unk158 = 1;
            D_803D2D90.unk5C = teleporter;
            D_803D2D90.unk60 = 0;
            D_803D2D90.unk4C = teleporter->position.xPos.h;
            D_803D2D90.unk4E = teleporter->position.zPos.h;
            D_803D2D90.unk50 = teleporter->position.yPos.h;
            D_803D2D90.unk46 = D_803D2D90.unk4C;
            D_803D2D90.unk48 = D_803D2D90.unk4E;
            D_803D2D90.unk4A = D_803D2D90.unk50;
            D_803D2D90.unk52 = teleporter->position.xPos.h;
            D_803D2D90.unk54 = teleporter->position.zPos.h;
            D_803D2D90.unk56 = teleporter->position.yPos.h;
            D_803D2D90.unk58 = arg0;
            arg0->position.xPos.h = teleporter->position.xPos.h;
            arg0->position.zPos.h = teleporter->position.zPos.h;
            D_803D2D90.unk0 = 1;
            D_803D2D90.unk2 = OBJECT_EXIT_TELEPORTER;
            func_802B33D0_6C4A80(arg0);
            arg0->unk364 = 17; // prevents user input
            arg0->attackTimer = D_803D5544;
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
    long new_var;

    if (D_803D2D90.unk64 != 0) {
        D_803D2D90.unk64--;
    }
    if (D_803D2D90.unk0 != 0) {

        if (D_803D2D90.unk2 == OBJECT_TELEPORTER_BASE) {
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
                D_803D2D90.unk38 = 0.0f;
                D_803D2D90.unk3C = 0.0f;
                D_803D2D90.unk40 = 0;
                D_803D2D90.unk42 = 0;
                D_803D2D90.unk44 = 0;
                D_803D2DFC = 0x4000;
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
                D_803D2D90.unk38 = 0.0f;
                D_803D2D90.unk3C = 0.0f;
                D_803D2D90.unk40 = 0;
                D_803D2D90.unk44 = 0;
                D_803D2D90.unk42 = 0;
                D_803D2DFC = 0x4000;
                D_803D2DF8 = 0.25f;
                do_rumble(0, 40, 8, 32, distance_from_player(D_803D2D90.unk52, D_803D2D90.unk54, D_803D2D90.unk56));
            }

            if (D_803D2D90.unk0 == 2) {
                D_803D2D90.unk42++;
                if (D_803D2D90.unk42 < 115) {
                    if (D_803D2D90.unk42 < 40) {
                        if (D_803D2DF8 < 0.75) {
                            D_803D2DF8 += 0.04;
                        }
                        D_803D2D90.unk40--;
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
                D_803D2D90.unk44++;
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

            if (1) {};

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

                if (!(D_803D2D90.unk2 == OBJECT_EXIT_TELEPORTER)) {
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

                if (new_var = (D_803D2D90.unk2 == OBJECT_TELEPORTER_BASE)) {};

                if (D_803D2D90.unk2 == OBJECT_ENTRANCE_TELEPORTER) {
                    func_802B34B8_6C4B68(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
                    D_803D2D90.unk60->state = 0;
                } else {
                    func_802B34B8_6C4B68(D_803D2D90.unk58);
                }
            }
            D_803D2D90.unk4 += 2;
            if (D_803D2D90.unk40 < 0) {
                D_803D2D90.unk40 += 15;
            }

            for (sp8C = 0; sp8C < 12; sp8C++) {
                if (D_803D2D90.unk6[sp8C] < (sp8C * 3)) {
                    D_803D2D90.unk6[sp8C] = D_803D2D90.unk3C;
                    var_s7 = D_80152350.unk2D0[(s16) (D_803D2D90.unk3C + (sp8C * 10))] >> 3;
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
                        // vertex x/z position?
                        if (D_803D2D90.unk1E[sp8C] >= 2) {
                            D_803D2D90.unk1E[sp8C] -= 2;
                        }
                        // vertex green level?
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
        img_D_01006C60_40530_i4__png,
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

    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, SSSV_RAND(16) * 16 + img_D_01006C60_40530_i4__png + 0x200);

    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0040, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 255, 1024);
    gDPPipeSync((*dl)++);

    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, 1, 0, 0, 124, 124);

    gDPPipeSync((*dl)++);

    gSPDisplayList((*dl)++, D_010047D0_3E0A0);

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
