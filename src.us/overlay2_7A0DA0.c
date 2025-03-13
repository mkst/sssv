#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

Vp D_803B66F0_7C7DA0 = {
    /* scale */
    {{
        640,
        480,
        511,
        0,
    },
    /* translate */
    {
        640,
        480,
        511,
        0,
    }},
};

static struct004 D_803B6700_7C7DB0[13] = {
    {
        1039.0f,
        1107.0f,
        1044.0f,
        1039.0f,
        -7838.0f,
        1032.0f,
    },
    {
        999.0f,
        1107.0f,
        1044.0f,
        999.0f,
        -7838.0f,
        1032.0f,
    },
    {
        959.0f,
        1107.0f,
        1044.0f,
        959.0f,
        -7838.0f,
        1032.0f,
    },
    {
        1055.0f,
        1141.0f,
        1041.0f,
        947.0f,
        -5142.0f,
        1041.0f,
    },
    {
        1005.0f,
        1140.0f,
        1041.0f,
        1707.0f,
        -5762.0f,
        1041.0f,
    },
    {
        977.0f,
        1186.0f,
        1041.0f,
        1077.0f,
        -6782.0f,
        1041.0f,
    },
    {
        962.0f,
        1310.0f,
        1153.0f,
        4494.0f,
        -8516.0f,
        -5653.0f,
    },
    {
        994.0f,
        1311.0f,
        1156.0f,
        1000.0f,
        -7822.0f,
        -4883.0f,
    },
    {
        1015.0f,
        1116.0f,
        1043.0f,
        1014.0f,
        -5762.0f,
        1043.0f,
    },
    {
        999.0f,
        1116.0f,
        1043.0f,
        1000.0f,
        -7822.0f,
        1067.0f,
    },
    {
        959.0f,
        1130.0f,
        1044.1f,
        1000.0f,
        -7822.0f,
        1067.0f,
    },
    {
        967.0f,
        1270.0f,
        1115.0f,
        7448.0f,
        -10950.0f,
        -5653.0f,
    },
    {
        967.0f,
        1270.0f,
        1120.0f,
        7448.0f,
        -10950.0f,
        -5653.0f,
    },
};

// unused?
static s32 D_803B6838_7C7EE8 = 0;

static struct004 D_803B683C_7C7EEC = {
    977.25f,
    1102.5f,
    1041.18f,
    977.25f,
    -7652.0f,
    1041.18f,
};

// unused?
static s32 D_803B6854_7C7F04[5] = {
    0x03CF0000, // FTOFIX32(975.0)
    0x03B00000, // FTOFIX32(944.0)
    0x04270000, // FTOFIX32(1063.0)
    0x044C0000, // FTOFIX32(1100.0)
    0x042F0000, // FTOFIX32(1071.0)
};

static f32 charWidth = 8.04f;
static f32 charHeight = 16.0f;

static s16 D_803B6870_7C7F20[] = {
    0x0000, // 'timer' placeholder
    NO_LEVEL_0, // aka play intro again
    HAVE_A_NICE_DAY,
    PINBALL_BLIZZARD,
    SOMETHING_FISHY,
    JUNGLE_JUMPS,
    STING_IN_THE_TAIL,
};

static s32 D_803B6880_7C7F30 = 0;

// ========================================================
// .bss
// ========================================================

struct027 D_803F6680;
static struct032 D_803F66B8;
s16  D_803F6704;
static s16  D_803F6706;
static s16  D_803F6708;
static s16  D_803F670A;
static s16  D_803F670C;
static s16  D_803F670E; // static in func_80395B58_7A7208
static s32  D_803F6710; // unused
u16  D_803F6714; // effectively unused, always 0
s16  D_803F6716; // current sfx volume
s16  D_803F6718; // current music volume
s16  D_803F671A; // current language
s16  D_803F671C;


// ========================================================
// .text
// ========================================================


#if 0
// for permuter
#define TEXEL0 1
#define TEXEL1 0
#define PRIMITIVE 0
#define SHADE 0
#define COMBINED 0
#endif

void func_8038F6F0_7A0DA0(void) {
    D_803F6680.unk8 = 5;
    D_803F6680.unkE = 0;
}

void func_8038F708_7A0DB8(void) {
    if ((D_803F6716 != gEepromGlobal.sfxVol) ||
        (D_803F6718 != gEepromGlobal.musicVol) ||
        (D_803F671A != gEepromGlobal.language)) {
        write_eeprom(4);
        set_music_volume(gEepromGlobal.musicVol);
    }
    D_803F6680.unk24 = 1;
    reset_screen_transition();
    trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
    gCurrentMusicTrack = NO_MUSIC;
}

void trigger_pause_menu(void) {
    generate_stars();
    func_801337DC(0, 60.0f, 20.0f, 6.0f);

    D_803F6680.unk14 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
    D_803F6680.unk31 = 0;
    D_803F6680.unk33 = 0;
    D_803F6680.unk35 = 0;
    D_803F6680.unk29 = 1;
    D_803F6680.unk16 = 0x1E;
    D_803F6680.unk2 = 0;
    D_803F6680.unk18 = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk1A = 0;
    D_803F6680.unk1E = 0xFF;
    D_803F6680.unk20 = 1;
    D_803F6680.unk22 = 0;
    D_803F6680.unk24 = 0;
    D_803F6706 = 0;
    D_803F6708 = 0;
    D_803F670A = 0x500;
    D_803F670C = 960;
    gInitialisationState = 1;
    D_801D9ED4 = 6;
    D_803F6716 = gEepromGlobal.sfxVol;
    D_803F6718 = gEepromGlobal.musicVol;
    D_803F671A = gEepromGlobal.language;
}

void trigger_mission_brief_screen(void) {
    generate_stars();
    func_801337DC(0, 15.0f, 20.0f, 6.0f);

    D_803F6680.unk2D = 0;
    D_803F6680.unk31 = 0;
    D_803F6680.unk33 = 0;
    D_803F6680.unk35 = 0;
    D_803F6680.unk29 = 0;
    D_803F6680.unk18 = 40; // mission brief
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk1A = 0;
    D_803F6680.unk1E = 0xFF;
    D_803F6680.unk20 = 1;
    D_803F6680.unk22 = 0;
    D_803F6680.unk24 = 0;
    D_803F6680.unk0 = 1;
    gScreenWidth = 320;
    func_8012A400(); // thread6 sync?
}

void func_8038F968_7A1018(void) {
    D_803F2CE0 = &D_803F34C0[(s16)D_803F3330[D_803A8340_7B99F0]];
    D_803F2CE4 = func_8012E78C(D_803F2CE0, 10.0f, 10.0f, 12) - 12;
    D_803F6680.unk0 = 0;
    D_803F6680.unk27 = 1;
    set_music_volume(gEepromGlobal.musicVol);
    D_803F671C = 1;
}

void trigger_level_failed(void) {
    generate_stars();

    D_803F6680.unk2D = 0;
    D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
    D_803F6680.unk8 = 6;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 20; // level select menu?
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    D_803F6680.unk24 = 0;
    gInitialisationState = 1;
}

void func_8038FAB4_7A1164(void) {
    generate_stars();

    D_803F6680.unk24 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
    D_803F6680.unk8 = 12;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 30;
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    gInitialisationState = 1;
}

void func_8038FB68_7A1218(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2A = 0;
    gInitialisationState = 0;
}

void load_demo_level(s16 level) {
    D_803F671C = 0;
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    gInitialisationState = 0;
    D_803F2D30.level = level;
    init_level();
    reset_player_progress();
    trigger_screen_transition(TRANSITION_FADE_IN);
    D_80152E98 = 0;
    gInputMode = INPUT_MODE_DEMO;
}

void load_intro(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    gInitialisationState = 0;
    D_803F2D30.level = DMA_INTRO;
    init_level();
    reset_player_progress();
    D_80152E98 = 0;
}

void func_8038FC58_7A1308(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    gInitialisationState = 0;
    init_level();
    reset_player_progress();
    if (D_803F7DA8.currentLevel != 0) {
        trigger_screen_transition(TRANSITION_FADE_IN);
    }
    D_80152E98 = 0;
    gCurrentMusicTrack = NO_MUSIC;
    D_80204290 = 2;
    func_801337DC(0, 60.0f, 0, 20.0f);
    func_8013385C(60.0f, 0, 20.0f);
}

void load_smashing_start(void) {
    D_80204290 = 2;
    func_801337DC(0, 5.0f, 20.0f, 0);
    D_803F2D30.level = SMASHING_START;
    D_803F7DA8.currentLevel = 0;
    gLoadedMessageCount = load_level_text_data(gEepromGlobal.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
    func_8038FC58_7A1308();
}

// initialise game (?)
void func_8038FD74_7A1424(void) {
    reset_cheats();
    D_803F671C = 0;
    set_sfx_volume(gEepromGlobal.sfxVol);
    set_music_volume(gEepromGlobal.musicVol);
    gInputMode = INPUT_MODE_USER;
    D_803C0424 = 0;
    D_803C0426 = 0;

    reset_credits_counters();
    // load lang33.dat
    load_level_text_data(gEepromGlobal.language, 32, D_80231AA0, D_80231D50.data);
    generate_stars();

    D_803F6704 = 0;
    D_803F7DA8.biome = 0;
    D_803F6680.unk2E = 0;

    load_ingame_objects();
    load_water_texture();
    D_803F6680.unk2D = 0;
    D_803B683C_7C7EEC = D_803B6700_7C7DB0[6];
    D_803F6680.unk8 = 6;
    D_803F6680.unk24 = 0;
    D_803F6680.unk6 = 6;
    D_803F6680.unk29 = 0;
    D_803F6680.unk16 = 30;
    D_803F6680.unk0 = 1;
    D_803F6680.unk2 = 0;
    D_803F6680.unk18 = 2;
    D_803F6680.unk1A = 0;
    D_803F6680.unk2A = 0;
    D_803F6680.unk2B = 0;
    D_803F6680.unk2C = 0;
    D_803F7DA8.bank = 0;
    gInitialisationState = 0;
    D_803F2D30.score = 0;
    D_801D9ED4 = 6;
    gCurrentMusicTrack = MUSIC_TRACK_MAIN_THEME;
    D_801546D8 = 1600;
    D_801546E0 = 2048;
    D_8015517C = 1.0f;

    reset_screen_transition();
    trigger_screen_transition(TRANSITION_FADE_IN);

    if (D_80204288 == 10) {
        load_intro();
    } else if (D_80204288 != 0) {
        load_demo_level(D_803B6870_7C7F20[D_80204288]);
    }
}

void func_8038FF48_7A15F8(void) {
    D_803F6680.unk26 = 1;
    D_803F6680.unk2 = 0;
    D_803F6714 = 0;
}

#ifdef NON_MATCHING
void func_8038FF68_7A1618(void) {
    s16 pad;
    s16 sp3C;

    D_803F6680.unk2F = 0;
    if (D_803F6680.unk24 != 0) {
        D_803F6680.unk24++;
        if (D_803F6680.unk24 >= 0xE) {
            D_80204284 = 3;
            D_80152E90 = 1;
        }
    }
    if (D_803F6680.unk2 < 900) {
        D_803F6680.unk2++;
    }
    gScreenWidth = 320;
    gScreenHeight = 240;
    sp3C = 0;
    func_80392668_7A3D18();
    gRenderMode1 = 0xFFFFFFFFC8000000;
    gRenderMode2 = 0x0000000000112038;

    func_80391A38_7A30E8();
    if (D_803F6680.unk2A != 0) {
        sp3C = 1;
        func_80395480_7A6B30();
        func_80395B58_7A7208();

        gDPPipeSync(D_801D9E7C++);
        gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
        gDPPipeSync(D_801D9E7C++);

        func_80397840_7A8EF0();

        D_803B6870_7C7F20[0]++;
        if (D_803F6680.unk2B != 0) {
            gSPDisplayList(D_801D9E8C++, D_01004270_3DB40);
            gDPPipeSync(D_801D9E8C++);

            gDPSetCycleType(D_801D9E8C++, G_CYC_2CYCLE);
            gDPSetRenderMode(D_801D9E8C++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

            // dan danger's face texture
            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img_actors_dan_dan1_rgba16__png);
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPLoadSync(D_801D9E8C++);
            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 2047, 256);
            gDPPipeSync(D_801D9E8C++);

            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(63));
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gSPSetGeometryMode(D_801D9E8C++, G_LIGHTING);
            gDPSetCombineLERP(D_801D9E8C++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, TEXEL0);

            D_803F6680.unk30 += 8;
            gDPSetPrimColor(D_801D9E8C++, 0, 0, 0x00, 0x00, 0x00, 0x00);
            func_80397F5C_7A960C(FTOFIX32(1030.0), FTOFIX32(1170.0), FTOFIX32(1021.0), 0, 0, 0xEA60, 0, 0);
        }
        if (D_803F6680.unk2B == 0) {
            gSPDisplayList(D_801D9E8C++, D_01004270_3DB40);
            gDPPipeSync(D_801D9E8C++);

            gDPSetCycleType(D_801D9E8C++, G_CYC_2CYCLE);
            gSPSetGeometryMode(D_801D9E8C++, G_LIGHTING);
        }

        gDPPipeSync(D_801D9E8C++);
        gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
        gDPSetRenderMode(D_801D9E8C++, G_RM_PASS, G_RM_ZB_OPA_SURF2);

        // load each of the 3 tv bodies
        render_tv_body(&D_801D9E8C, 960, 1077, 1047);
        render_tv_body(&D_801D9E8C, 1000, 1077, 1047);
        render_tv_body(&D_801D9E8C, 1040, 1077, 1047);
        if (D_803F6680.unk2C != 0) {
            gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
            // load tv screen/glass
            render_tv_glass(&D_801D9E8C, 960, 1077, 1046);
            render_tv_glass(&D_801D9E8C, 1000, 1077, 1046);
            render_tv_glass(&D_801D9E8C, 1040, 1077, 1046);
        }
        // load spaceship interior
        render_spaceship_interior(&D_801D9E8C);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unkBB80);
    }

    switch (D_803F6680.unk29) {
    case 0:
        switch (D_803F6680.unk18) {
        case -4:
            reset_screen_transition();
            trigger_screen_transition(TRANSITION_FADE_IN);
            D_803F2D30.level = 1;
            func_8039661C_7A7CCC(12, 4, 0);

            D_803F6680.unk18++;
            // diff starts around here
            D_803F6680.unk2C = 1;
            D_803F6680.unk2A = 1;
            func_80397734_7A8DE4(10, 0);
            D_803F6680.unk1A = 0;
            break;
        case -3:
            D_803F6680.unk1A++;
            if (D_803F713C[0] == 0) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk2A = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 = 3;
                func_8039264C_7A3CFC();
            }
            break;
        case -2:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A == 6) {
                func_8039661C_7A7CCC(0, 8, 0);
                D_803F6680.unk18 += 2;
            }
            break;
        case 0:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18++;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2A = D_803F6680.unk2C = 1;
            }
            break;
        case 1:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 = 2;
                D_803F6680.unk1A = 0;
            }
            break;
        case 2:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A == 8) {
                D_803F6680.unk18 = 3;
                D_803F6680.unk2A = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2B = 0;
            }
            break;
        case 3:
            if (D_803F6680.unk1A == 0) {
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
                D_803F6680.unk1A = 1;
                func_8039884C_7A9EFC();
                func_8039895C_7AA00C();
            }
            D_80204290 = 1;
            func_8039A2DC_7AB98C();
            break;
        case 4:
            // this is set to 1 when the user has already seen the intro cutscene
            if ((D_8023F260.unk34 & 1) == 0) {
                load_smashing_start();
            }
            D_80204290 = 1;
            display_zone_select_screen();
            func_8039264C_7A3CFC();
            D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
            break;
        case 5:
            D_80204290 = 2;
            func_8039264C_7A3CFC();
            D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
            D_803F6680.unk2B = 0;
            D_803F6680.unk2A = 1;
            D_803F6680.unk2C = 1;
            D_803F6680.unk18++;
            D_803F6680.unk1A = 0;
            load_data_section(6);
            break;
        case 6:
            D_803F6680.unk2A = 1;
            D_803F6680.unk1A++;
            D_803F6680.unk2C = 1;
            if (D_803F6680.unk1A >= 0xB) {
                if ((D_803F7DA8.currentLevel == 30) || (D_803F7DA8.currentLevel == 31)) {
                    D_803F6680.unk18++;
                    func_8039661C_7A7CCC(2, 4, 1);
                } else {
                    D_803F6680.unk18 += 2;
                    func_8039661C_7A7CCC(1, 8, 1);
                }
            }
            break;
        case 7:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 = 14;
                D_803F6680.unk1A = 0;
                func_801337DC(0, 10.0f, 20.0f, 0.0f);
                func_8013385C(10.0f, 19.0f, 1.0f);
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
                D_803F6680.unk18 = 14;
                D_803F6680.unk1A = 0;
                func_801337DC(0, 10.0f, 20.0f, 0.0f);
                func_8013385C(10.0f, 19.0f, 1.0f);
            }
            break;
        case 8:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[1];
            }
            break;
        case 9:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A > 0) {
                D_803F6680.unk18++;
                D_803F6680.unk1E = 1;
                D_803F6680.unk2A = 0;
                D_803F6680.unk1A = 0;
            }
            break;
        case 10:
            if (D_803F6680.unk1A == 0) {
                gLoadedMessageCount = load_level_text_data(gEepromGlobal.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
                D_803F6704 = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk1A = 1;
            }
            D_80204290 = 1;
            load_mission_brief_screen(0);

            if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
                (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 0xA;
                func_80395074_7A6724(0);
                D_803F6680.unk18 = 12;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2C = D_803F6680.unk2A = 1;
            }
            if (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1)) {
                play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                func_80395074_7A6724(0);
                D_801D9ED4 = 0xA;
                func_8039661C_7A7CCC(0, 8, 1);
                D_803F6680.unk18 = 11;
                D_803F6680.unk2A = 1;
                D_803F6680.unk2B = 0;
                D_803F6680.unk2C = 1;
                D_803F6680.unk1A = 0;
            }
            break;
        case 11:
            if ((func_80396714_7A7DC4()) && (D_803F6680.unk1A == 0)) {
                D_803F6680.unk1A = 1;
            }
            if (D_803F6680.unk1A != 0) {
                D_803F6680.unk1A++;
                if (D_803F6680.unk1A >= 3) {
                    D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
                    D_803F6680.unk2C = 0;
                    D_803F6680.unk2A = 0;
                    D_803F6680.unk18 = 4;
                    D_803F6680.unk1A = 0;
                    func_8039884C_7A9EFC();
                }
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
            }
            break;
        case 12:
            D_80204290 = 2;
            func_8039661C_7A7CCC(2, 8, 1);
            D_803B683C_7C7EEC = D_803B6700_7C7DB0[1];
            D_803F6680.unk1A = 0;
            D_803F6680.unk18 = 13;
            D_803F6680.unk2A = 1;
            // change around here
            func_801337DC(0, 10.0f, 20.0f, 0.0f);
            func_8013385C(10.0f, 19.0f, 1.0f);
            break;
        case 13:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
                reset_screen_transition();
                trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
            }
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk18 = 0xE;
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
                reset_screen_transition();
                trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
            }
            break;
        case 14:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 2) {
                D_803F6680.unk18++;
                D_803F6680.unk1A = 0;
            }
            break;
        case 15:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A == 11) {
                D_803F6680.unk2A = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk2B = 0;
            }
            if (D_803F6680.unk1A > 11) {
                func_8038FC58_7A1308();
            }
            break;
        case 30:
            D_803F6680.unk2A = 1;
            D_803F6680.unk2C = 1;
            func_8039661C_7A7CCC(0, 6, 1);
            D_803F6680.unk18++;
            break;
        case 31:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 2;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
            }
            break;
        case 33:
            D_803F6680.unk18 = 4;
            D_803F6680.unk2A = 0;
            D_803F6680.unk2C = 0;
            D_803F6680.unk1A = 0;
            func_8039895C_7AA00C();
            func_8039884C_7A9EFC();
            break;
        case 40:
            D_80204290 = 1;
            load_mission_brief_screen(0);
            if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
                ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                D_80204290 = 2;
                D_803F6680.unk0 = 0;
                D_803F6680.unk27 = 1;
                set_music_volume(gEepromGlobal.musicVol);
            }
            break;
        }
        break;

    case 1:
        switch (D_803F6680.unk18) {
        case 0:
            if (D_803F6680.unk1A == 0) {
                D_803F6680.unk1A = 1;
            }
            D_80204290 = 1;
            D_803F6680.unk2B = 0;
            if (D_803F6680.unk1C > 0) {
                D_803F6680.unk1C -= 20;
            }
            load_pause_menu(0, D_803F6680.unk1C);
            draw_rectangle(&D_801D9E7C,                0,                    0,            8, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C, gScreenWidth - 8,                    0, gScreenWidth, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0,                    0, gScreenWidth,   8, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0,    gScreenHeight - 8, gScreenWidth, 240, 0, 0, 0, 0xFF);
            break;
        case 1:
            D_80204290 = 2;
            D_803F6680.unk1A = 0;
            D_803F6680.unk18++;
            D_803F6680.unk2C = 1;
            D_803F6680.unk2A = 1;
            break;
        case 2:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 8) {
                D_803F6680.unk18 += 2;
                func_8039661C_7A7CCC(1, 8, 1);
                D_803F6680.unk1A = 0;
            }
            break;
        case 4:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[1];
            }
            break;
        case 5:
            D_803F6680.unk18++;
            D_803F6680.unk2C = 0;
            D_803F6680.unk2A = 0;
            D_803F6680.unk1E = 1;
            D_803F6680.unk1A = 0;
            break;
        case 6:
            D_80204290 = 1;
            load_mission_brief_screen(0);
            if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
                (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1)) ||
                (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                D_801D9ED4 = 10;
                func_80395074_7A6724(0);
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
                D_803F6680.unk2C = 1;
                D_803F6680.unk2A = 1;
                D_803F6680.unk14 = 0;
                D_80204290 = 2;
            }
            break;
        case 7:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 9) {
                func_8039661C_7A7CCC(2, 8, 1);
                D_803F6680.unk18++;
            }
            break;
        case 8:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 += 2;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
            }
            break;
        case 10:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 9) {
                D_803F6680.unk18 = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk2A = 0;
            }
            break;
        case 20:
            func_8039BBB8_7AD268();
            determine_available_levels();
            D_803F6680.unk2B = 1;
            D_803F2D30.score = 0;
            reset_screen_transition();
            D_803B683C_7C7EEC = D_803B6700_7C7DB0[2];
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 1;
            D_803F6680.unk18++;
            D_803F6680.unk2C = 1;
            func_80397734_7A8DE4((RAND(4) + 13), 0);
            func_8039661C_7A7CCC(11, 8, 0);
            func_8013385C(4.0f, 0, 20.0f);
            break;
        case 21:
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk18 = 25;
                D_803F6680.unk1A = 0;
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
                func_80397734_7A8DE4(0, 0);
            }
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 0x1F) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            break;
        case 22:
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                func_8039661C_7A7CCC(0, 8, 0);
            }
            D_803F6680.unk1A++;
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18++;
            }
            break;
        case 23:
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk18 = 0x18;
                func_8039264C_7A3CFC();
                func_8039661C_7A7CCC(0, 8, 0);
            }
            if (D_803F713C[0] == 0) {
                func_8039661C_7A7CCC(0, 8, 0);
                D_803F6680.unk18++;
            }
            D_803F6680.unk1A++;
            break;
        case 24:
            if (func_80396714_7A7DC4()) {
                func_80397734_7A8DE4(0, 0);
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            break;
        case 25:
            D_803F6680.unk1A++;
            if ((s32) D_803F6680.unk1A >= 3) {
                D_803F6680.unk18++;
                D_803F6680.unk2A = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk2B = 0;
                D_803F6680.unk1A = 0;
            }
            break;
        case 26:
            D_803F6680.unk18 = 4;
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 0;
            D_803F6680.unk2B = 0;
            D_803F6680.unk2C = 0;
            D_803F6680.unk29 = 0;
            func_8039884C_7A9EFC();
            func_8039895C_7AA00C();
            break;
        case 30:
            D_803F6680.unk2B = 1;
            if (D_803F6680.unk1A == 0) {
                func_8039661C_7A7CCC(11, 8, 0);
            }
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A == 1) {
                func_8039BBB8_7AD268();
                determine_available_levels();
            }
            if (D_803F6680.unk1A == 5) {
                if ((D_803F2D30.level == GIVE_A_DOG_A_BONUS) ||
                    (D_803F2D30.level == WALRACE_64) ||
                    (D_803F2D30.level == EVOS_ESCAPE) ||
                    (D_803F2D30.level == PUNCHUP_PYRAMID)) {
                    if ((D_803E4D28 & 2)) {
                        func_80397734_7A8DE4((RAND(4) + 17), 0);
                    } else {
                        func_80397734_7A8DE4((RAND(4) + 13), 0);
                    }
                } else {
                    func_80397734_7A8DE4((RAND(4) + 17), 0);
                }
                D_803F6680.unk18++;
            }
            break;
        case 31:
            if ((D_803F713C[0] == 0) || (func_80396748_7A7DF8())) {
                func_8039264C_7A3CFC();
                if (D_803F7DA8.currentLevel == 34) {
                    D_803F2D30.level = D_803F7DA8.currentLevel + 1;
                    D_803F6680.unk18 = 40;
                    D_803F6680.unk1A = 0;
                    func_8039661C_7A7CCC(2, 16, 0);
                } else {
                    if (func_80396748_7A7DF8()) {
                        func_8039264C_7A3CFC();
                        // struct copy
                        D_803B683C_7C7EEC = D_803B6700_7C7DB0[0];
                    } else {
                        func_8039661C_7A7CCC(0, 8, 0);
                    }
                    D_803F6680.unk18++;
                }
            }
            break;
        case 32:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18++;
            }
            break;
        case 33:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A == 2) {
                D_803F6680.unk18++;
                D_803F6680.unk2A = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk2B = 0;
            }
            break;
        case 34:
            D_803F6680.unk18 = 4;
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 0;
            D_803F6680.unk2C = 0;
            D_803F6680.unk29 = 0;
            func_8039884C_7A9EFC();
            func_8039895C_7AA00C();
            break;
        case 40:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18++;
                D_803F6680.unk1A = 0;
                reset_screen_transition();
                trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
            }
            break;
        case 41:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 0xD) {
                D_803F6680.unk2A = 0;
                D_803F6680.unk2B = 0;
                D_803F6680.unk2C = 0;
                D_803F6680.unk18++;
            }
            break;
        case 42:
            D_803F6680.unk1A++;
            if (D_803F6680.unk1A >= 2) {
                reset_credits_counters();
                D_803C0428 = 0;
                func_8038FC58_7A1308();
            }
            break;
        }
    }

    if ((sp3C == 1) && (D_803F6680.unk2C != 0)) {
        func_80395B58_7A7208();
        // empty functions
        func_8039546C_7A6B1C(&D_801D9E90,  960, 0x435, 0x416);
        func_8039546C_7A6B1C(&D_801D9E90, 1000, 0x435, 0x416);
        func_8039546C_7A6B1C(&D_801D9E90, 1040, 0x435, 0x416);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unkDAC0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_8038FF68_7A1618.s")
#endif

// play_tv_static_buzz_sfx
void func_80391A38_7A30E8(void) {
    func_8032CD20_73E3D0(1169, SFX_UNKNOWN_73, 0x4000, 0, 0.76f);
    if (D_803F6680.unk2A == 1) {
        if (RAND(20) == 1) {
            D_803B6880_7C7F30 = RAND(6);
        }
        switch (D_803B6880_7C7F30) {
        case 0:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.0f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 1:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.0f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 2:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.0f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 3:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.0f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 4:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.12f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 5:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, 1.33f);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        }
    }
}

#if 0
// unused
// CURRENT (16736)
void func_80391C90_7A3340(Gfx **dl, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 pad[8];

    s16 idx;
    f32 var_f0;
    s16 var_t3;
    u16 phi_s1;
    s16 var_t2;

    gSPDisplayList((*dl)++, D_01004270_3DB40);
    gDPPipeSync((*dl)++);

    gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
    gDPPipeSync((*dl)++);

    gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineMode((*dl)++, G_CC_DECALRGB, G_CC_DECALRGB);
    gSPClearGeometryMode((*dl)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);

    gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

    for (idx = 0; idx < 12; idx++) {
        var_f0 = arg2 - (((arg4 - arg2) / 11) * idx);

        // final iteration
        if (idx == 11) {
            var_f0 = ((var_f0 - var_t2) / 2) + var_t2;
        }

        var_t2 = var_f0;

        var_t3 = idx * 1984; // ?
        if (var_t3 < 0) {
            var_t3 = 0;
        }

        D_80204278->unk31070[2*idx].v.ob[0] = arg1 - 1.0f;
        D_80204278->unk31070[2*idx].v.ob[1] = arg5;
        D_80204278->unk31070[2*idx].v.ob[2] = var_t2;

        D_80204278->unk31070[2*idx].v.cn[0] = 0xFF;
        D_80204278->unk31070[2*idx].v.cn[1] = 0xFF;
        D_80204278->unk31070[2*idx].v.cn[2] = 0xFF;
        D_80204278->unk31070[2*idx].v.cn[3] = 0xFF;

        D_80204278->unk31070[2*idx].v.tc[0] = 0;
        D_80204278->unk31070[2*idx].v.tc[1] = var_t3;

        D_80204278->unk31070[2*idx+1].v.ob[0] = arg3 + 1.0f;
        D_80204278->unk31070[2*idx+1].v.ob[1] = arg5;
        D_80204278->unk31070[2*idx+1].v.ob[2] = var_t2;

        D_80204278->unk31070[2*idx+1].v.cn[0] = 0xFF;
        D_80204278->unk31070[2*idx+1].v.cn[1] = 0xFF;
        D_80204278->unk31070[2*idx+1].v.cn[2] = 0xFF;
        D_80204278->unk31070[2*idx+1].v.cn[3] = 0xFF;

        D_80204278->unk31070[2*idx+1].v.tc[0] = 0x2800;
        D_80204278->unk31070[2*idx+1].v.tc[1] = var_t3;
    }

    gSPVertex((*dl)++, K0_TO_PHYS(&D_80204278->unk31070[idx]), 31, 0);

    for (idx = 0; idx < 22; idx += 2) {
        gDPPipeSync((*dl)++);

        gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ((u8*)D_800BA760 + 0xB2E0 + (idx * 0x6E0)));

        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync((*dl)++);
        gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1919, 52);
        gDPPipeSync((*dl)++);
        gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 636, 44);
        gDPPipeSync((*dl)++);

        phi_s1 = 0x170;
        if (idx == 20) {
            phi_s1 = 0x130;
        }

        gDPPipeSync((*dl)++);

        // High-order 16 bits are the s coordinate value. Low-order 16 bits are the t coordinate value (s10.5)
        // S | T in s10.5 format
        gSPModifyVertex((*dl)++, (idx + 0) & 0xFFFF, G_MWO_POINT_ST, 0x00B00000 | 0x00000010);
        gSPModifyVertex((*dl)++, (idx + 1) & 0xFFFF, G_MWO_POINT_ST, 0x11700000 | 0x00000010);
        gSPModifyVertex((*dl)++, (idx + 2) & 0xFFFF, G_MWO_POINT_ST, 0x00B00000 | phi_s1);
        gSPModifyVertex((*dl)++, (idx + 3) & 0xFFFF, G_MWO_POINT_ST, 0x11700000 | 0x00000010);

        gDPPipeSync((*dl)++);

        gSP2Triangles(
            /* gdl   */ (*dl)++,
            /* v00   */ idx + 0,
            /* v01   */ idx + 2,
            /* v02   */ idx + 3,
            /* flag0 */ 0,
            /* v10   */ idx + 0,
            /* v11   */ idx + 3,
            /* v12   */ idx + 1,
            /* flag1 */ 0);
        gDPPipeSync((*dl)++);
    }

    D_80204278->unk31250[0].v.ob[0] = arg1 + 2.0f;
    D_80204278->unk31250[0].v.ob[1] = arg5;
    D_80204278->unk31250[0].v.ob[2] = (arg4 - (arg4 - arg2)) + 2;
    D_80204278->unk31250[1].v.ob[0] = arg3 - 2.0f;
    D_80204278->unk31250[1].v.ob[1] = arg5;
    D_80204278->unk31250[1].v.ob[2] = (arg4 - (arg4 - arg2)) + 2;

    D_80204278->unk31250[2].v.ob[0] = arg3 - 2.0f;
    D_80204278->unk31250[2].v.ob[1] = arg5;
    D_80204278->unk31250[2].v.ob[2] = (arg2 - (arg4 - arg2)) - 2;
    D_80204278->unk31250[3].v.ob[0] = arg1 + 2.0f;
    D_80204278->unk31250[3].v.ob[1] = arg5;
    D_80204278->unk31250[3].v.ob[2] = (arg2 - (arg4 - arg2)) - 2;

    D_80204278->unk31250[4].v.ob[0] = arg1 - 1.0f;
    D_80204278->unk31250[4].v.ob[1] = arg5;
    D_80204278->unk31250[4].v.ob[2] = (arg4 - (arg4 - arg2)) - 1;
    D_80204278->unk31250[5].v.ob[0] = arg3 + 1.0f;
    D_80204278->unk31250[5].v.ob[1] = arg5;
    D_80204278->unk31250[5].v.ob[2] = (arg4 - (arg4 - arg2)) - 1;

    D_80204278->unk31250[6].v.ob[0] = arg3 + 1.0f;
    D_80204278->unk31250[6].v.ob[1] = arg5;
    D_80204278->unk31250[6].v.ob[2] = (arg2 - (arg4 - arg2)) + 1;
    D_80204278->unk31250[7].v.ob[0] = arg1 - 1.0f;
    D_80204278->unk31250[7].v.ob[1] = arg5;
    D_80204278->unk31250[7].v.ob[2] = (arg2 - (arg4 - arg2)) + 1;

    gSPVertex((*dl)++, K0_TO_PHYS(D_80204278->unk31250), 8, 0);

    gDPSetCombineMode((*dl)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*dl)++, 0, 0, 0x00, 0x00, 0x00, 0x00);

    gSP2Triangles((*dl)++, 0, 4, 1, 0, 1, 4, 5, 0);
    gSP2Triangles((*dl)++, 0, 3, 7, 0, 7, 4, 0, 0);
    gSP2Triangles((*dl)++, 1, 5, 2, 0, 5, 6, 2, 0);
    gSP2Triangles((*dl)++, 7, 3, 2, 0, 2, 6, 7, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80391C90_7A3340.s")
#endif

void func_803925D0_7A3C80(u16 *src, u16 *dst) {
    u16 *_src;
    u16 *_dst;
    s16 col, row;
    s16 len;
    u16 val; // needed for regalloc

    _src = src;
    _dst = dst;
    len = 320 - D_802053E0.screenWidth;

    for (row = 0; row < 240; row++) {
        for (col = 0; col < D_802053E0.screenWidth; col += 2) {
            *_dst++ = val = *_src++;
            _src++;
        }
        _src += len;
    }
}

void func_8039264C_7A3CFC(void) {
    D_803F66B8.unk40 = 0;
    D_803F66B8.unk42 = 0;
    D_803F66B8.unk48 = 0.0f;
}

void func_80392668_7A3D18(void) {
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    s32 var_a1;

    if ((D_803F66B8.unk42 != 0) || (D_803F66B8.unk40 != 0)) {
        if (D_803F6680.unk2B == 0) {
            D_80204290 = 1;
        } else {
            D_80204290 = 2;
        }
    }

    if (D_803F66B8.unk40 != 0) {
        if (D_803F66B8.unk30 >= 0x100) {
            D_803F66B8.unk40 = 0;
            D_803F6680.unkC = 0;
        } else {
            D_803F66B8.unk30 += D_803F66B8.unk38;
        }

        temp_f2  = (D_803F66B8.unk18 - D_803F66B8.unk0) / 2;
        temp_f12 = (D_803F66B8.unk1C - D_803F66B8.unk4) / 2;
        temp_f14 = (D_803F66B8.unk20 - D_803F66B8.unk8) / 2;

        if (D_803F66B8.unk34 >= 256) {
            var_a1 = FTOFIX32(-0.5);
        } else if (D_803F66B8.unk34 == 0) {
            var_a1 = FTOFIX32(0.5);
        } else {
            var_a1 = COS(D_803F66B8.unk34 >> 1);
        }

        if (D_803F66B8.unk30 & 1) {
            var_a1 = (COS((D_803F66B8.unk30 >> 1) + 1) + var_a1) / 2;
        }
        if (D_803F66B8.unk44 != 0) {
            // FIXME: how to use SIN macro
            D_803F66B8.unk48 = (D_80152C78[D_803F66B8.unk34 >> 1] * 2) / 3;
        } else {
            D_803F66B8.unk48 = 0.0f;
        }

        D_803B683C_7C7EEC.unk0 = (D_803F66B8.unk0 + temp_f2)  - (((temp_f2  * 2) * var_a1) / 65536);
        D_803B683C_7C7EEC.unk4 = (D_803F66B8.unk4 + temp_f12) - (((temp_f12 * 2) * var_a1) / 65536);
        D_803B683C_7C7EEC.unk8 = (D_803F66B8.unk8 + temp_f14) - (((temp_f14 * 2) * var_a1) / 65536);
    }

    if (D_803F66B8.unk42 != 0) {
        if (D_803F66B8.unk34 >= 0x100) {
            D_803F66B8.unk42 = 0;
            D_803F6680.unkC = 0;
        } else {
            D_803F66B8.unk34 += D_803F66B8.unk3C;
        }

        temp_f2  = (D_803F66B8.unk24 - D_803F66B8.unkC) / 2;
        temp_f12 = (D_803F66B8.unk28 - D_803F66B8.unk10) / 2;
        temp_f14 = (D_803F66B8.unk2C - D_803F66B8.unk14) / 2;


        if (D_803F66B8.unk34 >= 256) {
            var_a1 = FTOFIX32(-0.5);
        } else if (D_803F66B8.unk34 == 0) {
            var_a1 = FTOFIX32(0.5);
        } else {
            var_a1 = COS(D_803F66B8.unk34 >> 1);
        }
        // single line for regalloc
        if (D_803F66B8.unk34 & 1) {var_a1 = (COS((D_803F66B8.unk34 >> 1) + 1) + var_a1) / 2;}

        D_803B683C_7C7EEC.unkC  = (D_803F66B8.unkC  + temp_f2)  - (((temp_f2  * 2) * var_a1) / 65536);
        D_803B683C_7C7EEC.unk10 = (D_803F66B8.unk10 + temp_f12) - (((temp_f12 * 2) * var_a1) / 65536);
        D_803B683C_7C7EEC.unk14 = (D_803F66B8.unk14 + temp_f14) - (((temp_f14 * 2) * var_a1) / 65536);
    }
}

void load_mission_brief_screen(s16 _vertical_offset) {
    s16 vertical_offset;
    s16 horizontal_offset;
    s16 tasks;
    s16 i;
    s16 *mission_brief_text;

    s16 is_first_line; // spA2

    u8  sp8C[20];
    s16 sp64[20];

    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);
    render_stars(&D_801D9E7C);
    gDPPipeSync(D_801D9E7C++);

    load_default_display_list(&D_801D9E7C);
    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // YELLOW
    func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_MISSION_BRIEF), 24, 30, 24.0f, 16.0f, -1);

    charWidth = 12.0f;
    charHeight = 13.0f;

    vertical_offset = _vertical_offset + 52;
    horizontal_offset = 23;

    if (gEepromGlobal.language == LANG_JAPANESE) {
        charWidth = 14.0f;
        charHeight = 15.0f;
    }

    tasks = 0;
    is_first_line = 0;

    // print title e.g. "Have a Nice Day!"
    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
    vertical_offset = display_text_wrapped(D_801D9E98, D_803F2D50.titleText, horizontal_offset, vertical_offset, 16.0f, 16.0f, 296, 14);
    vertical_offset += 24;

    select_font(0, FONT_COMIC_SANS, 0, 0);

    for (i = 0; i < gLoadedMessageCount; i++) {
        // load mission task text
        mission_brief_text = &D_803F34C0[(s16)D_803F3330[i]];

        if (mission_brief_text[0] == 307) {
            if (mission_brief_text[1] == 307) { // <MISSION_OBJECTIVE>
                horizontal_offset = 43;
                if (is_first_line == 0) {
                    is_first_line = 1;
                    vertical_offset += charHeight;
                }
                if ((1 << tasks) & gTasksCompleted) {
                    // '☑️' completed checkbox (green text)
                    set_menu_text_color(0, 200, 0, 0xFF);
                    sprintf((char*)sp8C, "%c", 93);
                    prepare_text(sp8C, sp64);
                    vertical_offset = display_text_wrapped(D_801D9E98, &sp64, 0x17, vertical_offset, charWidth, charHeight, 0x128, charHeight);
                    // dark YELLOW for task text
                    set_menu_text_color(120, 120, 0, 0xFF);
                } else {
                    // '☐' checkbox (yellow text)
                    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
                    sprintf((char*)sp8C, "%c", 94);
                    prepare_text(sp8C, sp64);
                    vertical_offset = display_text_wrapped(D_801D9E98, &sp64, 0x17, vertical_offset, charWidth, charHeight, 0x128, charHeight);
                }
                tasks++;
            }
            if (mission_brief_text[1] == 371) { // "c" change color to white?
                set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
                horizontal_offset = 0x17;
            }

            // write out task e.g. "Get FOUR sheep into the pen"
            mission_brief_text += 2;
            vertical_offset = display_text_wrapped(D_801D9E98, mission_brief_text, horizontal_offset, vertical_offset, charWidth, charHeight, 0x128, charHeight);
            vertical_offset += charHeight + 2.0f;
        }
    }

    gSPEndDisplayList(D_801D9E98[0]++);

    gSPDisplayList(D_801D9E7C++, D_80204278->unk109A0);

    func_8039D034_7AE6E4(&D_801D9E7C, 0);
}

// draw_quad?
void func_80393024_7A46D4(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 idx, u8 color) {

    D_80204278->unk31070[idx].v.ob[0] = arg1;
    D_80204278->unk31070[idx].v.ob[1] = arg5;
    D_80204278->unk31070[idx].v.ob[2] = arg2;

    D_80204278->unk31070[idx+1].v.ob[0] = arg1;
    D_80204278->unk31070[idx+1].v.ob[1] = arg5;
    D_80204278->unk31070[idx+1].v.ob[2] = arg4;

    D_80204278->unk31070[idx+2].v.ob[0] = arg3;
    D_80204278->unk31070[idx+2].v.ob[1] = arg5;
    D_80204278->unk31070[idx+2].v.ob[2] = arg4;

    D_80204278->unk31070[idx+3].v.ob[0] = arg3;
    D_80204278->unk31070[idx+3].v.ob[1] = arg5;
    D_80204278->unk31070[idx+3].v.ob[2] = arg2;

    gSPVertex((*dl)++, K0_TO_PHYS(&D_80204278->unk31070[idx]), 4, 0);
    gDPPipeSync((*dl)++);

    gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPClearGeometryMode((*dl)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP((*dl)++, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0);
    gDPSetPrimColor((*dl)++, 0, 0, color, color, color, 0x80);
    gDPPipeSync((*dl)++);
    gSP1Quadrangle((*dl)++, 0, 1, 2, 3, 0);
}

#ifdef NON_MATCHING
// CURRENT (1702)
void load_pause_menu(s32 arg0, s16 arg1) {
    u8 sp174[60];
    s16 spFC[60];

    s16 col;
    s16 row;

    s16 cnt;
    s16 level;

    u8 alpha; // spF3
    u8 suit_red;
    u8 suit_blue;
    u8 suit_green;
    s16 user_selection;

    s32 new_var;
    s16 vertical_offset;
    s16 font_width; // spE6

    font_width = 16;
    if ((gEepromGlobal.language == LANG_ITALIAN) ||
        (gEepromGlobal.language == LANG_SPANISH)) {
        font_width = 10;
    }
    if ((gEepromGlobal.language == LANG_FRENCH) ||
        (gEepromGlobal.language == LANG_GERMAN) ||
        (gEepromGlobal.language == LANG_DUTCH) ||
        (gEepromGlobal.language == LANG_PORTUGESE)) {
        font_width = 12;
    }

    if (D_803F6680.unk20 != 0) {
        if (D_803F6680.unk20 < 0xFF) {
            D_803F6680.unk20++;
        }
        if (D_803F6706 != 760) {
            D_803F6706 += (f32) ((760 - D_803F6706) * 0.125);
            D_803F670A += (f32) ((1168 - D_803F670A) * 0.125);
            D_803F6708 += (f32) ((224 - D_803F6708) * 0.125);
            D_803F670C += (f32) ((512 - D_803F670C) * 0.125);
        }
        alpha = 0xFF;
    }

    if (D_803F6680.unk22 != 0) {
        alpha = 0xFF;

        // update eeprom if volume or language changed
        if ((D_803F6680.unk22 == 1) && ((D_803F6716 != gEepromGlobal.sfxVol) || (D_803F6718 != gEepromGlobal.musicVol) || (D_803F671A != gEepromGlobal.language))) {
            write_eeprom(4);
            set_music_volume(gEepromGlobal.musicVol);
        }
        if (D_803F6680.unk22 < 0xFF) {
            D_803F6680.unk22++;
        }
        if (D_803F6706 >= 9) {
            D_803F6706 += (f32) ((0 - D_803F6706) * 0.5);
            D_803F670A += (f32) ((1280 - D_803F670A) * 0.5);
            D_803F6708 += (f32) ((0 - D_803F6708) * 0.5);
            D_803F670C += (f32) ((960 - D_803F670C) * 0.5);
        } else {
            D_803F6706 = 0;
            D_803F670A = 1280;
            D_803F6708 = 0;
            D_803F670C = 960;
            func_8038F968_7A1018();
        }
    }

    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);
    render_stars(&D_801D9E7C);

    gSPDisplayList(D_801D9E7C++, &D_801584A0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPPipeSync(D_801D9E7C++);

    // is this required? maybe a macro?
    gDPPipeSync(D_801D9E7C++);
    load_default_display_list(&D_801D9E7C);

    // write "OPTIONS" in yellow at top of screen
    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_OPTIONS), 24, 31, 24.0f, 16.0f, -1);

    level = D_803F7DA8.currentLevel + 1;
    if (level != SECRET_LEVEL) {
        gDPPipeSync(D_801D9E7C++);

        gSPDisplayList(D_801D9E7C++, &D_801584A0);
        gDPPipeSync(D_801D9E7C++);

        gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        // cyan (0xFA000000 -0xE2)
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 30);
        gDPPipeSync(D_801D9E7C++);

        level = D_803F7DA8.currentLevel + 1;
        if ((level == GIVE_A_DOG_A_BONUS) ||
            (level == WALRACE_64) ||
            (level == EVOS_ESCAPE) ||
            (level == PUNCHUP_PYRAMID) ||
            (level == BIG_CELEBRATION_PARADE)) {

            // show evo rather than powercells for bonus levels
            switch (D_803F2D50.evoSuitColor) {
            case EVO_BRONZE_SHELLSUIT:
                suit_red = 200;
                suit_green = 200;
                suit_blue = 0;
                break;
            case EVO_SILVER_SHELLSUIT:
                suit_red = 180;
                suit_green = 180;
                suit_blue = 180;
                break;
            case EVO_GOLD_SHELLSUIT:
                suit_red = 255;
                suit_green = 255;
                suit_blue = 20;
                break;
            }
            func_803967D4_7A7E84(224, 110, suit_red, suit_green, suit_blue, D_8023F260.evoPartsCollected & EVO_HEAD, D_8023F260.evoPartsCollected & EVO_TORSO, D_8023F260.evoPartsCollected & EVO_ARMS, D_8023F260.evoPartsCollected & EVO_LEGS, 1);
        } else {

            // print rows of powercells (non-collected)
            cnt = 0;

            gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
            gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

            for (row = 0; row < 3; row++) {
                for (col = 0; col < 5; col++) {
                    func_803962EC_7A799C(&D_801D9E7C,
                        (col * 22 + 188) << 2, // x0
                        (row * 22 + 136) << 2, // y0
                        (col * 22 + 204) << 2, // x1
                        (row * 22 + 152) << 2, // y1
                        D_800DE390,
                        32,
                        32
                    );
                    gDPPipeSync(D_801D9E7C++);
                    cnt++; // pointless but massively affects codegen, is this a macro?
                }
            }

            // fill in collected powercells
            cnt = 0;

            gSPDisplayList(D_801D9E7C++, &D_801584A0);
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);
            gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x80);
            gDPPipeSync(D_801D9E7C++);

            for (row = 0; row < 3; row++) {
                for (col = 0; col < 5; col++) {
                    if (cnt < D_803F2D30.powercells) {
                        func_803962EC_7A799C(&D_801D9E7C,
                            (col * 22 + 188) << 2,  // x0
                            (row * 22 + 136) << 2,  // y0
                            (col * 22 + 204) << 2,  // x1
                            (row * 22 + 152) << 2,  // y1
                            D_800DE390,             // img
                            32,                     // width
                            32                      // height
                        );
                        gDPPipeSync(D_801D9E7C++);
                    }
                    cnt++;
                }
            }
        }
    }


    vertical_offset = arg1 + 58;

    if (gRegion == REGION_US) {
        // no "language" option so bump everything down a smidge?
        vertical_offset += 8;
    }
    // wraparound
    if (D_803F6680.unk14 < PAUSE_MENU_OPTION_CONTINUE) {
        D_803F6680.unk14 = PAUSE_MENU_OPTION_LEAVE_SV;
    }
    if (D_803F6680.unk14 > PAUSE_MENU_OPTION_LEAVE_SV) {
        D_803F6680.unk14 = PAUSE_MENU_OPTION_CONTINUE;
    }
    gDPPipeSync(D_801D9E7C++);

    gSPDisplayList(D_801D9E7C++, &D_801584A0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gDPSetDepthSource(D_801D9E7C++, G_ZS_PRIM);
    gDPSetRenderMode(D_801D9E7C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);
    gDPSetCombineLERP(D_801D9E7C++,
        PRIMITIVE, 0, TEXEL0,         0,
        0,         0,      0, PRIMITIVE,
        PRIMITIVE, 0, TEXEL0,         0,
        0,         0,      0, PRIMITIVE);
    gDPPipeSync(D_801D9E7C++);

    // display thumbnail of game?
    func_803962EC_7A799C(&D_801D9E7C,
        D_803F6706, // x0
        D_803F6708, // y0
        D_803F670A, // x1
        D_803F670C, // y1
        D_800C5A40, // current framebuffer?
        D_802053E0.screenWidth >> 1, // half screen width?
        240);                        // height?

    if ((D_803F6680.unk22 == 0) && (D_803F6680.unk24 == 0)) {
        if (D_803F7DA8.currentLevel != 31) {
            // draw the grey box for level title
            draw_rectangle(&D_801D9E7C, 20, 204, 300, 224, 80, 80, 80, 45);
        }
        gDPPipeSync(D_801D9E7C++);

        load_default_display_list(&D_801D9E7C);
        select_font(0, FONT_COMIC_SANS, 1, 0);
        set_menu_text_color(160, 160, 160, 0xFF);
        if (D_803F7DA8.currentLevel != 31) {
            // write level title
            display_text_centered(&D_801D9E7C, D_803F2D50.titleText, 160, 208, 16.0f, 16.0f);
        }
        gDPPipeSync(D_801D9E7C++);

        load_default_display_list(&D_801D9E7C);
        select_font(0, FONT_COMIC_SANS, 0, 0);
        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_CONTINUE) {
            set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
        }

        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_CONTINUE), 94, vertical_offset, font_width, 16.0f);
        vertical_offset += 18;

        if ((D_803F7DA8.currentLevel != 30) && (D_803F7DA8.currentLevel != 31)) {
            if (D_803F6680.unk14 == 1U) {
                set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
            } else {
                set_menu_text_color(0x80, 0x80, 0x80, alpha);
            }
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_MISSION_BRIEF2), 94, vertical_offset, font_width, 16.0f);
            vertical_offset += 18;
        }

        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_REPLAY_ZONE) {
            if (D_803F6680.unk35 == 0) { // if cancel/confirm not active
                set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_REPLAY_ZONE), 94, vertical_offset, font_width, 16.0f);
                vertical_offset += 18;
            } else {
                if (D_803F6680.unk36 == 0) { // cancel active
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_CANCEL2), 91, vertical_offset, font_width, 16.0f);

                if (D_803F6680.unk36 == 1U) { // confirm active
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_CONFIRM), 97, vertical_offset, font_width, 16.0f, -1);
                vertical_offset += 18;
            }
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_REPLAY_ZONE), 94, vertical_offset, font_width, 16.0f);
            vertical_offset += 18;
        }

        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_EXIT_ZONE) {
            if (D_803F6680.unk31 == 0) {
                set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_EXIT_ZONE), 94, vertical_offset, font_width, 16.0f);
                vertical_offset += 18;
            } else {
                if (D_803F6680.unk32 == 0) { // cancel active
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_CANCEL2), 91, vertical_offset, font_width, 16.0f);

                if (D_803F6680.unk32 == 1U) { // confirm active
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_CONFIRM), 97, vertical_offset, font_width, 16.0f, -1);
                vertical_offset += 18;
            }
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_EXIT_ZONE), 94, vertical_offset, font_width, 16.0f);
            vertical_offset += 18;
        }

        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_MUSIC) {
            set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
        }
        // "[ <<<<<<<<<<<<<<<<<<<<" // 91 + 272 => 363 => ♫
        sprintf((char*)sp174, "[ <<<<<<<<<<<<<<<<<<<<");
        // fill out "|"
        sp174[gEepromGlobal.musicVol + 2] = '>';
        prepare_text(sp174, spFC);
        display_text_centered(&D_801D9E7C, spFC, 94, vertical_offset, 16.0f, 16.0f);
        vertical_offset += 18;

        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_SFX) {
            set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
        }
        // "%c <<<<<<<<<<<<<<<<<<<<"
        sprintf((char*)sp174, "%c <<<<<<<<<<<<<<<<<<<<", 92); // 92 + 272 => 364 => 🔊
        // fill out "|"
        sp174[gEepromGlobal.sfxVol + 2] = '>';
        prepare_text(sp174, spFC);
        display_text_centered(&D_801D9E7C, spFC, 94, vertical_offset, 16.0f, 16.0f);
        vertical_offset += 18;

        // show "language" menu if not US ROM
        if (gRegion != REGION_US) {
            if (D_803F6680.unk14 == PAUSE_MENU_OPTION_LANGUAGE) {
                set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
            } else {
                set_menu_text_color(0x80, 0x80, 0x80, alpha);
            }
            // "%d"
            sprintf((char*)sp174, "%d", gEepromGlobal.language);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_LANGUAGE), 94, vertical_offset, font_width, 16.0f);
            vertical_offset += 18;
        }

        if (D_803F6680.unk14 == PAUSE_MENU_OPTION_LEAVE_SV) {
            if (D_803F6680.unk33 == 0) {
                set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_LEAVE_SV), 94, vertical_offset, font_width, 16.0f);
            } else {
                if (D_803F6680.unk34 == 0) {
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_CANCEL2), 91, vertical_offset, font_width, 16.0f);

                if (D_803F6680.unk34 == 1U) {
                    set_menu_text_color(0xFF, 0xFF, 0xFF, alpha);
                } else {
                    set_menu_text_color(0x80, 0x80, 0x80, alpha);
                }
                func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_CONFIRM), 97, vertical_offset, font_width, 16.0f, -1);
            }
        } else {
            set_menu_text_color(0x80, 0x80, 0x80, alpha);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_LEAVE_SV), 94, vertical_offset, font_width, 16.0f);
        }

        // helper
        new_var = gControllerInput->stick_y;
        if (((new_var > 50) || (gControllerInput->button & CONT_UP) || (gControllerInput->button & U_CBUTTONS)) &&
            (D_801D9ED4 == 0) &&
            (D_803F6680.unk31 == 0) &&
            (D_803F6680.unk35 == 0) &&
            (D_803F6680.unk33 == 0)) {
            play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
            D_801D9ED4 = 0xA;

            D_803F6680.unk14--;
            if (gRegion == REGION_US) {
                // skip over language option
                if (D_803F6680.unk14 == PAUSE_MENU_OPTION_LANGUAGE) {
                    D_803F6680.unk14--;
                }
            }
            // no mission brief for credits/secret level?
            if ((D_803F7DA8.currentLevel == 30) || (D_803F7DA8.currentLevel == 31)) {
                if (D_803F6680.unk14 == PAUSE_MENU_OPTION_MISSION_BRIEF) {
                    D_803F6680.unk14--;
                }
            }
            func_80395074_7A6724(0);
        }

        if (((gControllerInput->stick_y < -50) || (gControllerInput->button & CONT_DOWN) || (gControllerInput->button & D_CBUTTONS)) &&
            (D_801D9ED4 == 0) &&
            (D_803F6680.unk31 == 0) &&
            (D_803F6680.unk35 == 0) &&
            (D_803F6680.unk33 == 0)) {
            play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
            D_801D9ED4 = 0xA;

            D_803F6680.unk14++;
            if (gRegion == REGION_US) {
                // skip over language option
                if (D_803F6680.unk14 == PAUSE_MENU_OPTION_LANGUAGE) {
                    D_803F6680.unk14++;
                }
            }
            if ((D_803F7DA8.currentLevel == 30) || (D_803F7DA8.currentLevel == 31)) {
                if (D_803F6680.unk14 == PAUSE_MENU_OPTION_MISSION_BRIEF) {
                    D_803F6680.unk14++;
                }
            }
            func_80395074_7A6724(0);
        }
        // reset state
        if ((gControllerInput->button & CONT_B) &&
            (D_802912E0 == 1) &&
            !((D_803F6680.unk31 == 0) && (D_803F6680.unk35 == 0) && (D_803F6680.unk33 == 0))) {
            play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
            D_803F6680.unk31 = 0;
            D_803F6680.unk35 = 0;
            D_803F6680.unk33 = 0;
        }

        user_selection = 0;
        if (((gControllerInput->stick_x < -50) || (gControllerInput->button & CONT_LEFT)) && (D_801D9ED4 == 0)) {
            user_selection = -1;
        }
        if (((gControllerInput->stick_x > 50) || (gControllerInput->button & CONT_RIGHT)) && (D_801D9ED4 == 0)) {
            user_selection = 1;
        }
        if (user_selection != 0) {
            switch (D_803F6680.unk14) {
            case PAUSE_MENU_OPTION_MUSIC:
                gEepromGlobal.musicVol += user_selection;
                if (gEepromGlobal.musicVol < MIN_AUDIO_VOLUME) {
                    gEepromGlobal.musicVol = MIN_AUDIO_VOLUME;
                }
                if (gEepromGlobal.musicVol > MAX_AUDIO_VOLUME) {
                    gEepromGlobal.musicVol = MAX_AUDIO_VOLUME;
                }

                if (user_selection == -1) {
                    play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
                }
                if (user_selection == 1) {
                    play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                }
                break;
            case PAUSE_MENU_OPTION_SFX:
                gEepromGlobal.sfxVol += user_selection;
                if (gEepromGlobal.sfxVol < MIN_AUDIO_VOLUME) {
                    gEepromGlobal.sfxVol = MIN_AUDIO_VOLUME;
                }
                if (gEepromGlobal.sfxVol > MAX_AUDIO_VOLUME) {
                    gEepromGlobal.sfxVol = MAX_AUDIO_VOLUME;
                }
                if (user_selection == -1) {
                    play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
                }
                if (user_selection == 1) {
                    play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                }
                func_80395074_7A6724(0);
                set_sfx_volume(gEepromGlobal.sfxVol);
                break;

            case PAUSE_MENU_OPTION_REPLAY_ZONE:
                if (D_803F6680.unk35 != 0) {
                    if (user_selection == -1) {
                        if (D_803F6680.unk36 == 1) {
                            play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk36 = 0;
                    }
                    if (user_selection == 1) {
                        if (D_803F6680.unk36 == 0) {
                            play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk36 = 1;
                    }
                }
                // fallthrough
            case PAUSE_MENU_OPTION_EXIT_ZONE:
                if (D_803F6680.unk31 != 0) {
                    if (user_selection == -1) {
                        if (D_803F6680.unk32 == 1) {
                            play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk32 = 0;
                    }
                    if (user_selection == 1) {
                        if (D_803F6680.unk32 == 0) {
                            play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk32 = 1;
                    }
                }
                break;
            case PAUSE_MENU_OPTION_LEAVE_SV:
                if (D_803F6680.unk33 != 0) {
                    if (user_selection == -1) {
                        if (D_803F6680.unk34 == 1) {
                            play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk34 = 0;
                    }
                    if (user_selection == 1) {
                        if (D_803F6680.unk34 == 0) {
                            play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                        }
                        D_803F6680.unk34 = 1;
                    }
                }
                break;
            case PAUSE_MENU_OPTION_LANGUAGE:
                gEepromGlobal.language += user_selection;
                // wraparound
                if (gEepromGlobal.language > LANG_MAX) {
                    gEepromGlobal.language = LANG_MIN;
                }
                if (gEepromGlobal.language < LANG_MIN) {
                    gEepromGlobal.language = LANG_MAX;
                }

                if (user_selection == 1) {
                    // Spanish -> American -> Dutch
                    if (gEepromGlobal.language == LANG_AMERICAN) {
                        gEepromGlobal.language = LANG_DUTCH;
                    }
                    // Italian -> Japanese -> Portugese
                    if (gEepromGlobal.language == LANG_JAPANESE) {
                        gEepromGlobal.language = LANG_PORTUGESE;
                    }
                }

                // Dutch -> American -> Spanish
                if (gEepromGlobal.language == LANG_AMERICAN) {
                    gEepromGlobal.language = LANG_SPANISH;
                }
                // Portugese -> Japanese -> Italian
                if (gEepromGlobal.language == LANG_JAPANESE) {
                    gEepromGlobal.language = LANG_ITALIAN;
                }

                play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
                func_80395074_7A6724(0);
                // load menu text
                load_level_text_data(gEepromGlobal.language, 32, D_80231AA0, D_80231D50.data);
                // load level specific text
                gLoadedMessageCount = load_level_text_data(gEepromGlobal.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
                load_level_title();
                break;
            }
            func_80395074_7A6724(0);
        }

        // reset active/confirm options
        if (D_803F6680.unk14 != PAUSE_MENU_OPTION_REPLAY_ZONE) {
            D_803F6680.unk35 = 0;
            D_803F6680.unk36 = 0;
        }
        if (D_803F6680.unk14 != PAUSE_MENU_OPTION_EXIT_ZONE) {
            D_803F6680.unk31 = 0;
            D_803F6680.unk32 = 0;
        }
        if (D_803F6680.unk14 != PAUSE_MENU_OPTION_LEAVE_SV) {
            D_803F6680.unk33 = 0;
            D_803F6680.unk34 = 0;
        }

        if (((gControllerInput->button & CONT_START) && (D_802912DE == 1)) ||
            ((gControllerInput->button & CONT_A) && (D_802912DF == 1))) {
            func_80395074_7A6724(0);
            switch (D_803F6680.unk14) {
            case PAUSE_MENU_OPTION_CONTINUE:
            case PAUSE_MENU_OPTION_MUSIC:
            case PAUSE_MENU_OPTION_SFX:
            case PAUSE_MENU_OPTION_LANGUAGE:
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                D_803F6680.unk22 = 1;
                D_803F6680.unk20 = 0;
                D_803C0420 = 2;
                func_801337DC(0, 60.0f, 6.0f, 20.0f);
                break;

            case PAUSE_MENU_OPTION_MISSION_BRIEF:
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                D_803F6706 = 760;
                D_803F670A = 1168;
                D_803F6708 = 224;
                D_803F670C = 512;
                D_803F6680.unk18++;
                break;

            case PAUSE_MENU_OPTION_REPLAY_ZONE:
                if (D_803F6680.unk35 == 0) {
                    play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk35 = 1;
                    D_803F6680.unk36 = 0;
                } else if (D_803F6680.unk36 == 1) {
                    gTasksCompleted = 0;
                    play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                    func_8039264C_7A3CFC();
                    D_803B683C_7C7EEC = D_803B6700_7C7DB0[2]; // struct copy
                    D_803F6680.unk2A = 1;
                    D_803F6680.unk2C = 1;
                    func_8039661C_7A7CCC(1, 8, 1);
                    D_803F6680.unk18 = 8;
                    D_803F6680.unk1A = 0;
                    D_803F6680.unk2A = 1;
                    D_803F6680.unk2C = 1;
                    D_803F6680.unk29 = 0;
                    D_803F2D30.score = 0;
                    if ((D_803F6716 != gEepromGlobal.sfxVol) || (D_803F6718 != gEepromGlobal.musicVol) || (D_803F671A != gEepromGlobal.language)) {
                        write_eeprom(4);
                        set_music_volume(gEepromGlobal.musicVol);
                    }
                    if ((D_803F7DA8.currentLevel == 30) || (D_803F7DA8.currentLevel == 31)) {
                        D_803F6680.unk18 = 7;
                        D_803F6680.unk2A = 1;
                        func_8039661C_7A7CCC(2, 8, 1);
                    }
                } else {
                    play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk35 = 0;
                }
                break;

            case PAUSE_MENU_OPTION_EXIT_ZONE:
                if (D_803F6680.unk31 == 0) {
                    play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk31 = 1;
                    D_803F6680.unk32 = 0;
                } else if (D_803F6680.unk32 == 1) {
                    gTasksCompleted = 0;
                    play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk18 = 30;
                    D_803F6680.unk29 = 0;
                    D_803F2D30.score = 0;
                    if ((D_803F6716 != gEepromGlobal.sfxVol) || (D_803F6718 != gEepromGlobal.musicVol) || (D_803F671A != gEepromGlobal.language)) {
                        write_eeprom(4);
                        set_music_volume(gEepromGlobal.musicVol);
                    }
                } else {
                    play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk31 = 0;
                }
                break;

            case PAUSE_MENU_OPTION_LEAVE_SV:
                if (D_803F6680.unk33 == 0) {
                    play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk33 = 1;
                    D_803F6680.unk34 = 0;
                } else if (D_803F6680.unk34 == 1) {
                    play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
                    func_8038F708_7A0DB8();
                } else {
                    play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                    D_803F6680.unk33 = 0;
                }
                break;
            }
        }
        func_8039D034_7AE6E4(&D_801D9E7C, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/load_pause_menu.s")
#endif

void func_80395074_7A6724(s32 debug) {
    if (0 && debug) {
        // something like this
    }
    D_801D9ED4 = 10;
}

void func_80395088_7A6738(Gfx **dl, s16 ulx, s16 uly, s16 lrx, s16 lry, u8 color) {
    gDPPipeSync((*dl)++);
    gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode((*dl)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP((*dl)++, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0);
    gDPSetPrimColor((*dl)++, 0, 0, color, color, color, 0x80);
    gDPPipeSync((*dl)++);
    gDPFillRectangle((*dl)++, ulx, uly, lrx, lry);
}

void render_tv_body(Gfx **dl, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, FTOFIX32(0.5), FTOFIX32(0.5), FTOFIX32(0.5625));
    gSPMatrix((*dl)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList((*dl)++, D_04006D00_11D8D0); // tv body
    gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);
    gDPPipeSync((*dl)++);
}

void render_tv_glass(Gfx **dl, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, FTOFIX32(0.5), FTOFIX32(0.5), FTOFIX32(0.5625));
    gSPMatrix((*dl)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList((*dl)++, D_0400A9E0_1215B0);
    gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);
    gDPPipeSync((*dl)++);
}

void func_8039546C_7A6B1C(Gfx **dl, s16 arg1, s16 arg2, s16 arg3) {
}

void func_80395480_7A6B30(void) {
    D_803B66F0_7C7DA0.vp.vscale[0] = gScreenWidth  * 2;
    D_803B66F0_7C7DA0.vp.vscale[1] = gScreenHeight * 2;
    D_803B66F0_7C7DA0.vp.vtrans[0] = gScreenWidth  * 2;
    D_803B66F0_7C7DA0.vp.vtrans[1] = gScreenHeight * 2;

    gDPPipeSync(D_801D9E7C++);
    func_80129594(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    load_segments(&D_801D9E7C, D_80204278);

    gSPSegment(D_801D9E7C++, 0x04, osVirtualToPhysical(D_801D9E6C));
    gSPViewport(D_801D9E7C++, &D_803B66F0_7C7DA0);
    func_80129430(&D_801D9E7C);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 1.0f, 2.0f, 2000.0f, 1.0f);
    guScale(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guScale(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);

    guLookAt(&D_80204278->unk37490, D_803B683C_7C7EEC.unk0, (D_803F66B8.unk48 / 700.0f) + D_803B683C_7C7EEC.unk4, D_803B683C_7C7EEC.unk8, D_803B683C_7C7EEC.unkC, D_803B683C_7C7EEC.unk10, D_803B683C_7C7EEC.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPFogPosition(D_801D9E7C++, 995, 999);
    gDPSetFogColor(D_801D9E7C++, 0xFF, 0xFF, 0xFF, 0x00);

    gSPDisplayList(D_801D9E7C++, D_01004270_3DB40);
    gSPClearGeometryMode(D_801D9E7C++, G_FOG);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

void func_80395854_7A6F04(void) {
    gDPPipeSync(D_801D9E7C++);
    func_80129594(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    load_segments(&D_801D9E7C, D_80204278);

    gSPSegment(D_801D9E7C++, 0x04, osVirtualToPhysical(D_801D9E6C));
    gSPViewport(D_801D9E7C++, &D_803B66F0_7C7DA0);

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 0.92f, 2.0f, 6000.0f, 1.0f);
    guScale(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guScale(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);
    guLookAt(&D_80204278->unk37490, D_803B683C_7C7EEC.unk0, D_803B683C_7C7EEC.unk4, D_803B683C_7C7EEC.unk8, D_803B683C_7C7EEC.unkC, D_803B683C_7C7EEC.unk10, D_803B683C_7C7EEC.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPDisplayList(D_801D9E7C++, D_01004270_3DB40);
    gSPClearGeometryMode(D_801D9E7C++, G_FOG);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

#if 0
// need to fix BSS
void func_80395B58_7A7208(void) {
    static s16 D_803F670E;
    s16 temp_lo;
    f32 temp_a1;
    f32 factor;

    factor = 1.0;
    temp_a1 = (40.0f * factor);

    D_80204278->lights.a.l.colc[0] = temp_a1;
    D_80204278->lights.a.l.col[0] = temp_a1;

    D_80204278->lights.a.l.colc[1] = temp_a1;
    D_80204278->lights.a.l.col[1] = temp_a1;

    D_80204278->lights.a.l.colc[2] = temp_a1;
    D_80204278->lights.a.l.col[2] = temp_a1;

    temp_a1 = (200.0f * factor);
    D_80204278->lights.l[0].l.colc[0] = temp_a1;
    D_80204278->lights.l[0].l.col[0] = temp_a1;

    D_80204278->lights.l[0].l.colc[1] = temp_a1;
    D_80204278->lights.l[0].l.col[1] = temp_a1;

    D_80204278->lights.l[0].l.colc[2] = temp_a1;
    D_80204278->lights.l[0].l.col[2] = temp_a1;

    D_80204278->lights.l[0].l.dir[0] = -0x6D;
    D_80204278->lights.l[0].l.dir[1] = 0x5C;
    D_80204278->lights.l[0].l.dir[2] = 0x70;

    D_803F670E += 2;
    D_803F670E %= 360;
    temp_lo = (D_80152350.unk0[D_803F670E] + 0xFF) / 6;

    D_80204278->lights.l[1].l.col[0] = temp_lo;
    D_80204278->lights.l[1].l.col[1] = 8;
    D_80204278->lights.l[1].l.col[2] = 0;

    D_80204278->lights.l[1].l.colc[0] = temp_lo;
    D_80204278->lights.l[1].l.colc[1] = 0;
    D_80204278->lights.l[1].l.colc[2] = 0;

    D_80204278->lights.l[1].l.dir[0] = 0x57;
    D_80204278->lights.l[1].l.dir[1] = 0x64;
    D_80204278->lights.l[1].l.dir[2] = 0;

    gSPSetLights1(D_801D9E7C++, D_80204278->lights);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80395B58_7A7208.s")
#endif

void func_80395E98_7A7548(Gfx **dl) {
    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_2CYCLE);
    gDPPipeSync((*dl)++);
    gSPDisplayList((*dl)++, D_01004AF8_3E3C8);

    gDPSetRenderMode((*dl)++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);

    gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img_silver_rgba16__png);
    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);

    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], FTOFIX32(1000.0), FTOFIX32(1000.0), FTOFIX32(1000.0), 0, 0, FTOFIX32(12.0), FTOFIX32(12.0), FTOFIX32(12.0));
    gSPMatrix((*dl)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);
}

void render_spaceship_interior(Gfx **dl) {
    gDPPipeSync((*dl)++);
    gDPSetCycleType((*dl)++, G_CYC_2CYCLE);
    gDPPipeSync((*dl)++);
    gSPTexture((*dl)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP((*dl)++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    gDPSetRenderMode((*dl)++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPSetGeometryMode((*dl)++, G_CULL_BACK | G_LIGHTING);

    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], FTOFIX32(1000.0), FTOFIX32(1000.0), FTOFIX32(1000.0), 0, 0, FTOFIX32(3.0), FTOFIX32(3.0), FTOFIX32(3.0));

    gSPMatrix((*dl)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList((*dl)++, D_04005B60_11C730); // spaceship interior
    gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);

    gDPPipeSync((*dl)++);
}

void func_803962EC_7A799C(Gfx **dl, s16 p_screen_x, s16 p_screen_y, s16 arg3, s16 arg4, u8* img, u16 width, u16 height) {
    guSprite2DInit(&D_80204278->sprites[D_80204278->usedSprites], img, 0, width, width, height, 0, 2, 0, 0);
    gSPSprite2DBase((*dl)++, OS_K0_TO_PHYSICAL(&D_80204278->sprites[D_80204278->usedSprites]));
    gSPSprite2DScaleFlip(
        (*dl)++,
        (f32)(((f32)width  / (((f32)arg3 - (f32)p_screen_x) * 0.25)) * 1024),
        (f32)(((f32)height / (((f32)arg4 - (f32)p_screen_y) * 0.25)) * 1024),
        0,
        0);

    gSPSprite2DDraw((*dl)++, p_screen_x, p_screen_y);
    gDPPipeSync((*dl)++);

    D_80204278->usedSprites++;
}

void func_8039661C_7A7CCC(s16 arg0, s16 arg1, s16 arg2) {
    struct004 *temp_v0;

    if (arg2 != 0) {
        D_803F66B8.unk44 = 1;
    } else {
        D_803F66B8.unk44 = 0;
    }
    temp_v0 = &D_803B6700_7C7DB0[arg0];
    D_803F66B8.unk0 = D_803B683C_7C7EEC.unk0;
    D_803F66B8.unk4 = D_803B683C_7C7EEC.unk4;
    D_803F66B8.unk8 = D_803B683C_7C7EEC.unk8;
    D_803F66B8.unkC = D_803B683C_7C7EEC.unkC;
    D_803F66B8.unk10 = D_803B683C_7C7EEC.unk10;
    D_803F66B8.unk14 = D_803B683C_7C7EEC.unk14;
    D_803F66B8.unk30 = 0;
    D_803F66B8.unk34 = 0;
    D_803F66B8.unk38 = arg1;
    D_803F66B8.unk3C = arg1;
    D_803F66B8.unk40 = 1;
    D_803F66B8.unk42 = 1;
    D_803F66B8.unk18 = temp_v0->unk0;
    D_803F66B8.unk1C = temp_v0->unk4;
    D_803F66B8.unk20 = temp_v0->unk8;
    D_803F66B8.unk24 = temp_v0->unkC;
    D_803F66B8.unk28 = temp_v0->unk10;
    D_803F66B8.unk2C = temp_v0->unk14;

    D_803F6680.unk6 = D_803F6680.unk8;
}

s32 func_80396714_7A7DC4(void) {
    if ((D_803F66B8.unk40 == 0) && (D_803F66B8.unk42 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80396748_7A7DF8(void) {
    if (((gControllerInput->button & CONT_START) && (D_802912DE == 1)) ||
        ((gControllerInput->button & CONT_A) && (D_802912DF == 1))) {
          play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
          D_803F6680.unk2F = 1;
          return 1;
    } else {
        return 0;
    }
}

void func_803967D4_7A7E84(s16 arg0, s16 arg1, u8 red, u8 green, u8 blue, s16 head, s16 torso, s16 arms, s16 legs, s16 arg9) {
    f32 scale;
    s32 pad;

    gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

#define BOOST_RED 0
#define BOOST_GREEN 0
#define BOOST_BLUE 0

    if (arg9 == 1) {
        if (head) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[0], 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 1);

        if (torso) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[2], 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 32);

        if (legs) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        // 2x legs
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[1], 32, 32, 1.0f, 1.0f, 0, 0, arg0 + 12, arg1 + 58);
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[1], 32, 32, 1.0f, 1.0f, 1, 0, arg0 - 12, arg1 + 58);

        if (arms) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        // 2x arms
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[3], 32, 32, 1.0f, 1.0f, 0, 0, arg0 + 26, arg1 + 28);
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[3], 32, 32, 1.0f, 1.0f, 1, 0, arg0 - 26, arg1 + 28);
    } else {
        scale = 0.5f;
        if (head) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[0], 32, 32, scale, scale, 0, 0, arg0, arg1);

        if (torso) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[2], 32, 32, scale, scale, 0, 0, arg0, arg1 + (32 * scale));

        if (legs) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[1], 32, 32, scale, scale, 0, 0, arg0 + (12 * scale), arg1 + (58 * scale));
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[1], 32, 32, scale, scale, 1, 0, arg0 - (12 * scale), arg1 + (58 * scale));

        if (arms) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red + BOOST_RED, green + BOOST_GREEN, blue+ BOOST_BLUE, 0xFF);
        } else {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[3], 32, 32, scale, scale, 0, 0, arg0 + (26 * scale), arg1 + (28 * scale));
        func_8039C834_7ADEE4(&D_801D9E7C, D_800C3A40[3], 32, 32, scale, scale, 1, 0, arg0 - (26 * scale), arg1 + (28 * scale));
    }
}
