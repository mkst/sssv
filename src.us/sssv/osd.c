#include <ultra64.h>
#include "common.h"


// ========================================================
// externs
// ========================================================

extern Gfx D_01004650_3DF20[];
extern u8 D_01029DD0_636A0[];
extern u8 img_hud_energy_bar_left_rgba16__png[]; // img/hud/energy_bar_left.rgba16
extern u8 img_hud_energy_bar_right_rgba16__png[]; // img/hud/energy_bar_right.rgba16
extern u8 img_hud_power_green_rgba16__png[]; // img/hud/power_green.rgba16
extern u8 img_hud_power_blue_rgba16__png[]; // img/hud/power_blue.rgba16

// ========================================================
// .data
// ========================================================

extern f64 D_803BE950_7D0000; // = 0.6;

// ========================================================
// .bss (D_803F2CD0 to D_803F2D20)
// ========================================================

s16  D_803F2CD0; // other timer
s16  D_803F2CD2; // (race?) timer
s16  D_803F2CD4;
s16  D_803F2CD6;
s16  D_803F2CD8;
static s16  D_803F2CDA;
s8   D_803F2CDC;
static s8   D_803F2CDD;
static u8   D_803F2CDE;
static u8   D_803F2CDF;
s16 *D_803F2CE0;
s16  D_803F2CE4;
u8   D_803F2CE6;
s16  D_803F2CE8; // health slider 'animation'
static s32  D_803F2CEC; // xpos for texture
static s16  D_803F2CF0;
static u8   D_803F2CF2;    // effectively unused, always 1
static struct033 D_803F2CF8; // pointer to an animal+health

// ========================================================
// .text
// ========================================================

void osd_draw_health_and_power_bars(s16 arg0) {
    s16 new_var;
    s16 foo;
    s16 health;
    s16 tmp2;
    s16 tmp1;
    s16 temp_t7;

    static s32  D_803F2D04;

    D_803F2D04++;
    D_803F2D04 = D_803F2D04 & 0xF;

    D_803F2CEC = 0x60;
    D_803F2CF0 = arg0 << 2;

    if ((D_803F2CF0 >> 2) < gScreenHeight) {
        // maybe an if statement about energy? seems to be required to get correct regalloc
        tmp1 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0 / 16;
        tmp2 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0 / 16;

        gSPDisplayList(D_801D9E7C++, D_01004650_3DF20);

        gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);

        gDPSetRenderMode(D_801D9E7C++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
        gDPSetDepthSource(D_801D9E7C++, G_ZS_PRIM);
        gDPSetPrimDepth(D_801D9E7C++, 0, 0);
        gDPSetTexturePersp(D_801D9E7C++, G_TP_NONE);
        gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
        gDPPipeSync(D_801D9E7C++);

        gDPLoadTextureBlock(D_801D9E7C++, img_hud_energy_bar_left_rgba16__png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gDPPipeSync(D_801D9E7C++);

        gSPTextureRectangle(
            D_801D9E7C++,
            D_803F2CEC,
            D_803F2CF0 - 64,
            D_803F2CEC + 192,
            D_803F2CF0 + 64,
            G_TX_RENDERTILE,
            0,
            0,
            1024,
            1024);
        gDPPipeSync(D_801D9E7C++);

        gDPLoadTextureBlock(D_801D9E7C++, img_hud_energy_bar_right_rgba16__png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(D_801D9E7C++);

        new_var = 0x7000; // fuuuu

        gSPTextureRectangle(
            D_801D9E7C++,
            D_803F2CEC + 192,
            D_803F2CF0 - 64,
            D_803F2CEC + 384,
            D_803F2CF0 + 64,
            G_TX_RENDERTILE,
            0,
            0,
            1024,
            1024);
        gDPPipeSync(D_801D9E7C++);

        tmp1 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0 / 16;
        tmp2 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0 / 16;

        tmp1 = (tmp1 * 12);
        tmp2 = (tmp2 * 12);

        tmp1 = tmp1 / 16;
        tmp2 = tmp2 / 16;

        gDPPipeSync(D_801D9E7C++);

#if 0
        gDPSetRenderMode(D_801D9E7C++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
#else
        gDPSetRenderMode(D_801D9E7C++,
            ((((new_var | 0x8) | (0 << 30)) | (3 << 26)) | (0 << 22)) | (2 << 18),
            ((((new_var | 0x8) | (0 << 28)) | (3 << 24)) | (0 << 20)) | (2 << 16));
#endif

        gDPSetTextureFilter(D_801D9E7C++, G_TF_POINT);

        gDPLoadTextureBlock(D_801D9E7C++, img_hud_power_blue_rgba16__png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(
            D_801D9E7C++,
            D_803F2CEC + 0x2C,
            D_803F2CF0 + 4,
            D_803F2CEC + 44 + tmp1,
            D_803F2CF0 + 0x30,
            G_TX_RENDERTILE,
            0,
            0,
            1024,
            1024);

        gDPLoadTextureBlock(D_801D9E7C++, img_hud_power_green_rgba16__png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(
            D_801D9E7C++,
            D_803F2CEC + 0x14,
            D_803F2CF0 - 0x30,
            D_803F2CEC + 20 + tmp2,
            D_803F2CF0 - 4,
            G_TX_RENDERTILE,
            0,
            0,
            1024,
            1024);

        gDPSetTextureFilter(D_801D9E7C++, G_TF_BILERP);
        gSPDisplayList(D_801D9E7C++, D_01004600_3DED0);

        // TODO: replace this with a macro
        gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01029DD0_636A0);
        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD);
        gDPLoadSync(D_801D9E7C++);
        gDPLoadBlock(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 31, 2048);
        gDPPipeSync(D_801D9E7C++);
        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E7C++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(7));

        health = D_801D9ED8.animals[gCurrentAnimalIndex].animal->health;
        if (D_803F2CE8 > D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) {
            if (D_803F2CE8 > (D_801D9ED8.animals[gCurrentAnimalIndex].animal->health + 1)) {
                D_803F2CE8 -= 2;
            } else {
                D_803F2CE8--;
            }
        }

        if (D_803F2CE8 < D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) {
            if (D_803F2CE6 != 0) {
                func_8032CD20_73E3D0(0xC, SFX_UNKNOWN_114, (D_803F2CE8 << 4) + 0x3000, 0, (f32) ((D_803F2CE8 / 200.0) + 0.6));
            }
            D_803F2CE8++;
        } else {
            D_803F2CE6 = 1;
        }

        temp_t7 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->health;
        temp_t7 = temp_t7 << 1;

        if (health >= 17) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x08, 0x5F, 0x00, 0xD2);
            gDPSetEnvColor(D_801D9E7C++, 0x23, 0xDC, 0x00, 0xD2);
        } else if (D_803F2D04 < 8) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x82, 0x00, 0x00, 0xD2);
            gDPSetEnvColor(D_801D9E7C++, 0xEB, 0x00, 0x00, 0xD2);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x08, 0xA0, 0x00, 0xD2);
            gDPSetEnvColor(D_801D9E7C++, 0x23, 0xFA, 0x00, 0xD2);
        }

        if (D_803F2CE8 > D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) {
            foo = ((D_803F2CE8 - D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) << 1);
            if (temp_t7 > 0) {
                gSPTextureRectangle(
                    D_801D9E7C++,
                    (D_803F2CEC + 0x54),
                    D_803F2CF0 - 0x1C,
                    temp_t7 + (D_803F2CEC + 0x54),
                    D_803F2CF0 - 8,
                    G_TX_RENDERTILE,
                    0,
                    0,
                    0,
                    1723);
                gDPPipeSync(D_801D9E7C++);
            }
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x82, 0x00, 0x00, 0x78);
            gDPSetEnvColor(D_801D9E7C++, 0xEB, 0x00, 0x00, 0x78);
            gSPTextureRectangle(
                D_801D9E7C++,
                temp_t7 + (D_803F2CEC + 0x54),
                D_803F2CF0 - 0x1C,
                temp_t7 + (D_803F2CEC + 0x54) + foo,
                D_803F2CF0 - 8,
                G_TX_RENDERTILE,
                0,
                0,
                0,
                1723);
            gDPPipeSync(D_801D9E7C++);
        }

        if (D_803F2CE8 < D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) {
            foo = (D_803F2CE8 << 1);
            if (temp_t7 > 0) {
                gSPTextureRectangle(
                    D_801D9E7C++,
                    (D_803F2CEC + 0x54),
                    (D_803F2CF0 - 0x1C),
                    foo + (D_803F2CEC + 0x54),
                    D_803F2CF0 - 8,
                    G_TX_RENDERTILE,
                    0,
                    0,
                    0,
                    1723);

                gDPPipeSync(D_801D9E7C++);
            }
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x08, 0x5F, 0x00, 0x78);
            gDPSetEnvColor(D_801D9E7C++, 0x23, 0xDC, 0x00, 0x78);
            gSPTextureRectangle(D_801D9E7C++,
                foo + (D_803F2CEC + 0x54),
                D_803F2CF0 - 0x1C,
                temp_t7 + (D_803F2CEC + 0x54),
                D_803F2CF0 - 8,
                G_TX_RENDERTILE,
                0,
                0,
                0,
                1723);
            gDPPipeSync(D_801D9E7C++);
        }

        if (D_803F2CE8 == D_801D9ED8.animals[gCurrentAnimalIndex].animal->health) {
            if (temp_t7 > 0) {
                gSPTextureRectangle(
                    D_801D9E7C++,
                    (D_803F2CEC + 0x54),
                    D_803F2CF0 - 0x1C,
                    temp_t7 + (D_803F2CEC + 0x54),
                    D_803F2CF0 - 8,
                    G_TX_RENDERTILE,
                    0,
                    0,
                    2,
                    1723);
                gDPPipeSync(D_801D9E7C++);
            }
        }
        func_803493C8_75AA78();
    }
}

// ESA: func_8007D9D4
void osd_draw_score(void) {
    sprintf(D_803F2D30.scoreText, "%8d", D_803F2D30.score);
    select_font(0, FONT_LCD, 1, 0);
    display_score(&D_801D9E7C, D_803F2D30.scoreText, gScreenWidth - 34, ((D_803F2CF0 >> 2) - 10));
}

void func_80349278_75A928(void) {
}

// ESA: func_8007DA18
void func_80349280_75A930(Animal *arg0, s16 damage) {
    if ((arg0->unk16C->unk82.unk2) &&
        ((arg0->unk366 == MOVEMENT_MODE_INJURED) || (arg0->unk366 == MOVEMENT_MODE_CRITICAL) || (arg0->unk366 == MOVEMENT_MODE_NORMAL))) {
        if (damage != 0) {
            arg0->lastHpLost = MAX(arg0->lastHpLost + (damage >> 2), (damage >> 2) + 4);
        }
        if (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            if (arg0 == D_803F2CF8.animal) {
                D_803F2CF8.unk6 = MAX(0, arg0->health - damage);
                D_803F2CF8.unkA = 64;
            } else if ((D_803F2CF8.animal == NULL) || ((damage != 0) && ((D_803F2CF8.unk8 == D_803F2CF8.unk6) || (D_803F2CF8.animal->unk16C->mass < arg0->unk16C->mass)))) {
                D_803F2CF8.animal = arg0;
                D_803F2CF8.health = arg0->health;
                D_803F2CF8.unk6 = MAX(0, arg0->health - damage);
                D_803F2CF8.unk8 = D_803F2CF8.health;
                D_803F2CF8.unkA = 64;
            }
        }
    }
}

// ESA: func_8007DB6C
void func_803493C8_75AA78(void) {
    s32 tmp = 0;
    s32 offset = 0;

    if (D_803F2CF8.animal != NULL) {
        s32 alpha;
        gDPPipeSync(D_801D9E7C++);
        alpha = MIN(32, D_803F2CF8.unkA);

        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0, 80, 130, alpha * 6); // dark blue
        gDPSetEnvColor(D_801D9E7C++, 0, 80, 235, alpha * 6);        // light blue
        offset = D_803F2CF8.unk8;
        gSPTextureRectangle(
            /* pkt  */ D_801D9E7C++,
            /* xl   */ 196,
            /* yl   */ D_803F2CF0 + 12,
            /* xh   */ offset + 196,
            /* yh   */ D_803F2CF0 + 24,
            /* tile */ G_TX_RENDERTILE,
            /* s    */ 0,
            /* t    */ 0,
            /* dsdx */ 0,
            /* dtdy */ 1024);
        gDPPipeSync(D_801D9E7C++);

        gDPSetPrimColor(D_801D9E7C++, 0, 0, 200, 0, 100, alpha * 5);
        gDPSetEnvColor(D_801D9E7C++, 255, 0, 128, alpha * 5);

        tmp = D_803F2CF8.unk8;
        offset = D_803F2CF8.health - tmp;
        gSPTextureRectangle(
            /* pkt  */ D_801D9E7C++,
            /* xl   */ tmp + 196,
            /* yl   */ D_803F2CF0 + 12,
            /* xh   */ tmp + 196 + offset,
            /* yh   */ D_803F2CF0 + 24,
            /* tile */ G_TX_RENDERTILE,
            /* s    */ 0,
            /* t    */ 0,
            /* dsdx */ 0,
            /* dtdy */ 1024);

        if (D_803F2CF8.unk6 < D_803F2CF8.unk8) {
            D_803F2CF8.unk8 -= 1;
        } else if (D_803F2CF8.unkA > 0) {
            D_803F2CF8.unkA -= 1;
        } else {
            D_803F2CF8.animal = 0;
        }
        gDPPipeSync(D_801D9E7C++);
    }
}

void func_8034967C_75AD2C(void) {
    D_803F2CDF = 0;
    D_803F2CDA = 0;

    switch (D_803F2CDC) {
        case 4:
            D_803F2CDD = 5;
            break;
        case 5:
            D_803F2CDD = 5;
            break;
        case 1:
            D_803F2CDD = 2;
            break;
        case 2:
            D_803F2CDD = 2;
            break;
        case 7:
            D_803F2CDD = 8;
            break;
        case 8:
            D_803F2CDD = 8;
            break;
        default:
            break;
    }
    D_803F2CDC = 0;
}

void func_80349720_75ADD0(void) {
    D_803F2CDF = 1;
    func_80349D34_75B3E4();
}

void show_osd(void) {
    if (D_803F2CDC == 0) {
        D_803F2CDA = 0;
        D_803F2CDC = 8;
    }
    D_803F2CDE = 1;
}

void hide_osd(void) {
    if (((D_803F2CDC == 7) || (D_803F2CDC == 8)) && (D_803F2CDD == 0)) {
        D_803F2CDC = 9;
        D_803F2CDA = 0;
    }
    else if (D_803F2CDC == 8) {
        D_803F2CDD = 9;
    }
    D_803F2CDE = 0;
}

// ESA: func_8007DD7C
void func_803497DC_75AE8C(void) {
    D_803F2CDC = 8;
    D_803F2CDD = 0;
    D_803F2CD0 = 0;
    D_803F2CD2 = 0;
    D_803F2CD4 = 0;
    D_803F2CD6 = -1;
    D_803F2CD8 = 30;
    D_803F2CDA = 0;
    D_803F2CDE = 1;
    D_803F2CDF = 1;
    D_803F2CE0 = NULL;
    D_803F2CF2 = 1;
    bzero_sssv(&D_803F2CF8, 12);
}

// ESA: func_8007DDE8
u8 func_80349874_75AF24(void) {
    return (D_803F2CDF != 0) && (D_803F2CDC == 0 ||
                                 D_803F2CDC == 1 ||
                                 D_803F2CDC == 7 ||
                                 ((D_803F2CDC == 6) && (D_803F2CDA == 0)) ||
                                 ((D_803F2CDC == 3) && (D_803F2CDA == 0))
                                );
}

// ESA: func_8007DEA4
void func_80349900_75AFB0(s16 *text, u16 arg1) {
    D_803F2CE0 = text;
    D_803F2CD0 = arg1 * 30;
    D_803F2CD4 = 0;
    D_803F2CDA = 0;
    D_803F2CE4 = func_8012E78C(D_803F2CE0, 10.0f, 10.0f, 12) - 12;
    if (D_803F2CDC == 0) {
        D_803F2CDC = 5;
        D_803F2CDD = 0;
    } else if (D_803F2CDC == 1) {
        D_803F2CDC = 4;
        D_803F2CDD = 0;
    } else if (D_803F2CDC == 7) {
        D_803F2CDC = 9;
        D_803F2CDD = 5;
    } else if (((D_803F2CDC == 6) || (D_803F2CDC == 3)) && (D_803F2CDA == 0)) {
        D_803F2CDC = 4;
        D_803F2CDD = 0;
    }
}

// dupe of func_80349874_75AF24
// ESA: func_8007DF54
u8 func_80349A14_75B0C4(void) {
    return (D_803F2CDF != 0) && (D_803F2CDC == 0 ||
                                 D_803F2CDC == 1 ||
                                 D_803F2CDC == 7 ||
                                 ((D_803F2CDC == 6) && (D_803F2CDA == 0)) ||
                                 ((D_803F2CDC == 3) && (D_803F2CDA == 0))
                                );
}

// ESA: func_8007DFC4
void func_80349AA0_75B150(u16 arg0) {
    D_803F2CDA = 0;
    D_803F2CD2 = arg0;
    D_803F2CDD = 0;
    if (arg0 == 0) {
        D_803F2CD4 = D_803F2CD8;
        if (D_803F2CDC == 1) {
            D_803F2CDC = 3;
        }
    } else if (D_803F2CDC == 0) {
        D_803F2CDC = 2;
        D_803F2CD4 = 0;
    } else if (D_803F2CDC == 7) {
        D_803F2CDC = 9;
        D_803F2CDD = 2;
        D_803F2CD4 = 0;
    } else if (((D_803F2CDC == 6) || (D_803F2CDC == 3)) && (D_803F2CDA == 0)) {
        D_803F2CDC = 1;
        D_803F2CD4 = 0;
    }
}

void osd_draw_timer(s16 arg0) {
    s32 time;
    s16 str[20]; // how long is a piece of string

    time = D_803F2CD2;
    if (time > 0) {
        if (time < 60) {
            sprintf(D_803A8344_7B99F4, "%d", time);
        } else {
            sprintf(D_803A8344_7B99F4, "%d:%02d", time / 60, time % 60);
        }
    }

    prepare_text(D_803A8344_7B99F4, str);
    load_default_display_list(&D_801D9E7C);
    set_menu_text_color(255, 255, 0, 255); // yellow
    select_font(0, FONT_DEFAULT, 1, 0);
    // write string centered
    display_text_centered(&D_801D9E7C, str, gScreenWidth >> 1, arg0, 16.0f, 16.0f);
}

// ESA: func_8007E168 (tbd)
void func_80349CA4_75B354(s16 arg0) {
    load_default_display_list(&D_801D9E7C);
    set_menu_text_color(255, 255, 0, 255); // yellow
    select_font(0, FONT_DEFAULT, 1, 0);
    func_8012EB4C(&D_801D9E7C, D_803F2CE0, gScreenWidth >> 1, arg0, 16.0f, 16.0f, 0x10);
}

// ESA: func_8007E1B4
void func_80349D34_75B3E4(void) {
    if (D_803F2CDF == 0) {
        D_803F2CDC = 0;
    } else if ((D_803F2CDC == 6) && (D_803F2CD2 > 0)) {
        D_803F2CDC = 2;
    } else if (D_803F2CDD != 0) {
        D_803F2CDC = D_803F2CDD;
        D_803F2CDD = 0;
    } else if (D_803F2CDE != 0) {
        D_803F2CDC = 8;
    } else {
        D_803F2CDC = 0;
    }
    D_803F2CDA = 0;
}

// ESA: func_8007E23C
void func_80349DCC_75B47C(s16 arg0) {
    s16 phi_a0;

    if ((arg0 == 0) && (D_803F2D10.unk0 == 0)) {
        if (D_803F2CD2 > 0) {
            D_803F2CD4 += 1;
            if (D_803F2CD4 >= D_803F2CD8) {
                D_803F2CD4 = 0;
                D_803F2CD2 += D_803F2CD6;
            }
        }
    }
    switch (D_803F2CDC) {
        case 0:
            break;
        case 1:
            if (arg0 == 0) {
                if (D_803F2CD2 <= 0) {
                    D_803F2CDC = 3U;
                    D_803F2CDA = 0;
                }
                osd_draw_timer(gScreenHeight - 36);
            }
            break;
        case 2:
            if (arg0 == 0) {
                if (D_803F2CDA >= 9) {
                    D_803F2CDC = (u8)1U;
                    phi_a0 = gScreenHeight - 36;
                } else {
                    phi_a0 = gScreenHeight - (D_803F2CDA * 4);
                }
                osd_draw_timer(phi_a0);
                D_803F2CDA += 1;
            }
            break;
        case 3:
            if (arg0 == 0) {
                if (D_803F2CDA >= 9) {
                    func_80349D34_75B3E4();
                    D_803F2CD4 += 1;
                    phi_a0 = gScreenHeight;
                } else {
                    phi_a0 = ((gScreenHeight + (D_803F2CDA * 4)) - 36);
                }
                osd_draw_timer(phi_a0);
                D_803F2CDA += 1;
              }
              break;
        case 4:
            if (arg0 == 0) {
                D_803F2CD0 -= 1;
                if (D_803F2CD0 <= 0) {
                    D_803F2CDC = 6U;
                    D_803F2CDA = 0;
                }
                func_80349CA4_75B354(gScreenHeight - 36);
            }
            break;
        case 5:
            if (arg0 == 0) {
                if (D_803F2CDA >= 9) {
                    D_803F2CDC = (u8)4U;
                    phi_a0 = gScreenHeight - 36;
                } else {
                    phi_a0 = (gScreenHeight + ((9 - D_803F2CDA) * ((((gScreenHeight + D_803F2CE4) - gScreenHeight) + 36) / 9))) - 36;
                }
                func_80349CA4_75B354(phi_a0);
                D_803F2CDA += 1;
            }
            break;
        case 6:
            if (arg0 == 0) {
                if (D_803F2CD2 > 0) {
                    D_803F2CDC = (u8)1U;
                    phi_a0 = gScreenHeight - 36;
                } else {
                    if ((s32) D_803F2CDA >= 9) {
                        func_80349D34_75B3E4();
                        phi_a0 = gScreenHeight + D_803F2CE4;
                    } else {
                        phi_a0 = (gScreenHeight + (D_803F2CDA * ((((gScreenHeight + D_803F2CE4) - gScreenHeight) + 36) / 9))) - 36;
                    }
                }
                func_80349CA4_75B354(phi_a0);
                D_803F2CDA += 1;
            }
            break;
        case 7:
            if (arg0 != 0) {
                phi_a0 = gScreenHeight - 36;
                osd_draw_health_and_power_bars(phi_a0);
            } else {
                osd_draw_score();
            }
            break;
        case 8:
            if (arg0 != 0) {
                if (D_803F2CDA >= 9) {
                    D_803F2CDC = 7U;
                    phi_a0 = gScreenHeight - 0x24;
                } else {
                    phi_a0 = gScreenHeight - (D_803F2CDA * 4);
                }
                osd_draw_health_and_power_bars(phi_a0);
                D_803F2CDA += 1;
            } else {
                osd_draw_score();
            }
            break;
        case 9:
            if (arg0 == 0) {
                if ((s32) D_803F2CDA >= 9) {
                    func_80349D34_75B3E4();
                }
                osd_draw_score();
            }
            if (arg0 != 0) {
                if (D_803F2CDA >= 9) {
                    phi_a0 = gScreenHeight;
                } else {
                    phi_a0 = (gScreenHeight + (D_803F2CDA * 4)) - 36;
                }
                osd_draw_health_and_power_bars(phi_a0);
            }
            if (arg0 == 0) {
                D_803F2CDA += 1;
            }
            break;
    }
}
