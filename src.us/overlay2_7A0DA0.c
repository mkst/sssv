#include <ultra64.h>
#include "common.h"


extern u8 D_05005000[];
extern Gfx D_01004270[];

void func_80392668_7A3D18(void);
void func_803929FC_7A40AC(s16);
void func_80397840_7A8EF0(void);
void func_80398A0C_7AA0BC(void);
void func_8039A2DC_7AB98C(void);

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
    if ((D_803F6716 != D_8023F2A0.sfxVol) ||
        (D_803F6718 != D_8023F2A0.musicVol) ||
        (D_803F671A != D_8023F2A0.language)) {
        write_eeprom(4);
        set_music_volume(D_8023F2A0.musicVol);
    }
    D_803F66A4 = 1;
    func_802F07D0_701E80();
    func_802F07E8_701E98(3);
    D_8028645C = 0;
}

void func_8038F794_7A0E44(void) {
    generate_stars();
    func_801337DC(0, 60.0f, 20.0f, 6.0f);

    D_803F6680.unk14 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
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
    D_803C0422 = 1;
    D_801D9ED4 = 6;
    D_803F6716 = D_8023F2A0.sfxVol;
    D_803F6718 = D_8023F2A0.musicVol;
    D_803F671A = D_8023F2A0.language;
}

void func_8038F8C8_7A0F78(void) {
    generate_stars();
    func_801337DC(0, 15.0f, 20.0f, 6.0f);

    D_803F6680.unk2D = 0;
    D_803F6680.unk31 = 0;
    D_803F6680.unk33 = 0;
    D_803F6680.unk35 = 0;
    D_803F6680.unk29 = 0;
    D_803F6680.unk18 = 40;
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
    func_8012A400();
}

void func_8038F968_7A1018(void) {
    D_803F2CE0 = &D_803F34C0[(s16)D_803F3330[D_803A8340]];
    D_803F2CE4 = func_8012E78C(D_803F2CE0, 10.0f, 10.0f, 0xC) - 0xC;
    D_803F6680.unk0 = 0;
    D_803F6680.unk27 = 1;
    set_music_volume(D_8023F2A0.musicVol);
    D_803F671C = 1;
}

void func_8038FA00_7A10B0(void) {
    generate_stars();

    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
    D_803F6680.unk8 = 6;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 20;
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    D_803F6680.unk24 = 0;
    D_803C0422 = 1;
}

void func_8038FAB4_7A1164(void) {
    generate_stars();

    D_803F6680.unk24 = 0;
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6730;
    D_803F6680.unk8 = 0xC;
    D_803F6680.unk6 = 2;
    D_803F6680.unk29 = 1;
    D_803F6680.unk18 = 30;
    D_803F6680.unk16 = 30;
    D_803F6680.unk2 = 0;
    D_803F6680.unk2A = 1;
    D_803F6680.unk2C = 1;
    D_803F6680.unk1A = 0;
    D_801D9ED4 = 6;
    D_803C0422 = 1;
}

void func_8038FB68_7A1218(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803F6680.unk2C = 0;
    D_803F6680.unk2A = 0;
    D_803C0422 = 0;
}

// load_level
void func_8038FB94_7A1244(s16 arg0) {
    D_803F671C = 0;
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    gLevelIndex = arg0;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    func_802F07E8_701E98(2);
    D_80152E98 = 0;
    D_803E1BC0 = 1;
}

// load_intro
void func_8038FC04_7A12B4(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    gLevelIndex = DMA_INTRO;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    D_80152E98 = 0;
}

void func_8038FC58_7A1308(void) {
    D_803F6680.unk2D = 1;
    D_803F6680.unk27 = 1;
    D_803F6680.unk0 = 0;
    D_803C0422 = 0;
    func_802961D4_6A7884();
    func_8029614C_6A77FC();
    if (D_803F7DD5 != 0) {
        func_802F07E8_701E98(2);
    }
    D_80152E98 = 0;
    D_8028645C = 0;
    D_80204290 = 2;
    func_801337DC(0, 60.0f, 0, 20.0f);
    func_8013385C(60.0f, 0, 20.0f);
}

void func_8038FCF8_7A13A8(void) {
    D_80204290 = 2;
    func_801337DC(0, 5.0f, 20.0f, 0);
    gLevelIndex = SMASHING_START;
    D_803F7DA8.currentLevel = 0;
    D_803F63C0 = load_level_text_data(D_8023F2A0.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
    func_8038FC58_7A1308();
}

// initialise game (?)
void func_8038FD74_7A1424(void) {
    reset_cheats();
    D_803F671C = 0;
    set_sfx_volume(D_8023F2A0.sfxVol);
    set_music_volume(D_8023F2A0.musicVol);
    D_803E1BC0 = 0;
    D_803C0424 = 0;
    D_803C0426 = 0;

    reset_credits_counters();
    load_level_text_data(D_8023F2A0.language, 32, D_80231AA0, D_80231D5C);
    generate_stars();

    D_803F6704 = 0;
    D_803F7DD4 = 0;
    D_803F6680.unk2E = 0;

    load_ingame_objects();
    load_water_texture();
    D_803F6680.unk2D = 0;
    D_803B683C = D_803B6790;
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
    D_803F7DD6 = 0;
    D_803C0422 = 0;
    D_803F2D30.score = 0;
    D_801D9ED4 = 6;
    D_8028645C = 25;
    D_801546D8 = 1600;
    D_801546E0 = 2048;
    D_8015517C = 1.0f;

    func_802F07D0_701E80(); // reset something
    func_802F07E8_701E98(2);

    if (D_80204288 == 0xA) {
        // load intro
        func_8038FC04_7A12B4();
    } else if (D_80204288 != 0) {
        // load level
        func_8038FB94_7A1244(D_803B6870[D_80204288]);
    }
}

void func_8038FF48_7A15F8(void) {
    D_803F6680.unk26 = 1;
    D_803F6680.unk2 = 0;
    D_803F6714 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_8038FF68_7A1618.s")
// almost regalloc but has rodata due to jump table
#if 0
void func_8038FF68_7A1618(void) {
    s16 pad;
    s16 sp3C;

    D_803F6680.unk2F = 0;
    if (D_803F6680.unk24 != 0) {
        D_803F6680.unk24 += 1;
        if (D_803F6680.unk24 >= 0xE) {
            D_80204284 = 3;
            D_80152E90 = 1;
        }
    }
    if (D_803F6680.unk2 < 900) {
        D_803F6680.unk2 = D_803F6680.unk2 + 1;
    }
    gScreenWidth = 320;
    gScreenHeight = 240;
    sp3C = 0;
    func_80392668_7A3D18();
    D_803C0640_7D1CF0 = 0xFFFFFFFFC8000000;
    D_803C0648_7D1CF8 = 0x0000000000112038;

    func_80391A38_7A30E8();
    if (D_803F6680.unk2A != 0) {
        sp3C = 1;
        func_80395480_7A6B30();
        func_80395B58_7A7208();

        gDPPipeSync(D_801D9E7C++);
        gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
        gDPPipeSync(D_801D9E7C++);

        func_80397840_7A8EF0();

        D_803B6870_7C7F20 += 1;
        if (D_803F6680.unk2B != 0) {
            gSPDisplayList(D_801D9E8C++, D_01004270);
            gDPPipeSync(D_801D9E8C++);

            gDPSetCycleType(D_801D9E8C++, G_CYC_2CYCLE);
            gDPSetRenderMode(D_801D9E8C++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

            // dan danger's face texture
            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_05005000);
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
            func_80397F5C_7A960C(0x4060000, 0x4920000, 0x3FD0000, 0, 0, 0xEA60, 0, 0);
        }
        if (D_803F6680.unk2B == 0) {
            gSPDisplayList(D_801D9E8C++, D_01004270);
            gDPPipeSync(D_801D9E8C++);

            gDPSetCycleType(D_801D9E8C++, G_CYC_2CYCLE);
            gSPSetGeometryMode(D_801D9E8C++, G_LIGHTING);
        }

        gDPPipeSync(D_801D9E8C++);
        gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
        gDPSetRenderMode(D_801D9E8C++, G_RM_PASS, G_RM_ZB_OPA_SURF2);

        func_803951BC_7A686C(&D_801D9E8C, 960, 1077, 1047);
        func_803951BC_7A686C(&D_801D9E8C, 1000, 1077, 1047);
        func_803951BC_7A686C(&D_801D9E8C, 1040, 1077, 1047);
        if (D_803F6680.unk2C != 0) {
            gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);

            func_80395314_7A69C4(&D_801D9E8C, 960, 1077, 1046);
            func_80395314_7A69C4(&D_801D9E8C, 1000, 1077, 1046);
            func_80395314_7A69C4(&D_801D9E8C, 1040, 1077, 1046);
        }
        func_803960F4_7A77A4(&D_801D9E8C);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unkBB80);
    }

    switch (D_803F6680.unk29) {
    case 0:
        switch (D_803F6680.unk18) {
        case -4:
            func_802F07D0_701E80();
            func_802F07E8_701E98(2);
            gLevelIndex = 1;
            func_8039661C_7A7CCC(12, 4, 0);

            D_803F6680.unk18 += 1;
            // diff around here
            D_803F6680.unk2C = 1U;
            D_803F6680.unk2A = 1U;
            func_80397734_7A8DE4(10, 0);
            D_803F6680.unk1A = 0;
            break;
        case -3:
            D_803F6680.unk1A += 1;
            if (D_803F713C[0] == 0) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 = 3;
                func_8039264C_7A3CFC();
            }
            break;
        case -2:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A == 6) {
                func_8039661C_7A7CCC(0, 8, 0);
                D_803F6680.unk18 += 2;
            }
            break;
        case 0:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2A = D_803F6680.unk2C = 1U;
            }
            break;
        case 1:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 = 2;
                D_803F6680.unk1A = 0;
            }
            break;
        case 2:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A == 8) {
                D_803F6680.unk18 = 3;
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2B = 0U;
            }
            break;
        case 3:
            if (D_803F6680.unk1A == 0) {
                D_803B683C_7C7EEC = D_803B6700_7C7DB0;
                D_803F6680.unk1A = 1;
                func_8039884C_7A9EFC();
                func_8039895C_7AA00C();
            }
            D_80204290 = 1;
            func_8039A2DC_7AB98C();
            break;
        case 4:
            if ((D_8023F260.unk34 & 1) == 0) { // D_8023F294
                func_8038FCF8_7A13A8();
            }
            D_80204290 = 1;
            func_80398A0C_7AA0BC();
            func_8039264C_7A3CFC();
            D_803B683C_7C7EEC = D_803B6700_7C7DB0;
            break;
        case 5:
            D_80204290 = 2;
            func_8039264C_7A3CFC();
            D_803B683C_7C7EEC = D_803B6700_7C7DB0;
            D_803F6680.unk2B = 0U;
            D_803F6680.unk2A = 1U;
            D_803F6680.unk2C = 1U;
            D_803F6680.unk18 += 1;
            D_803F6680.unk1A = 0;
            load_data_section(6);
            break;
        case 6:
            D_803F6680.unk2A = 1U;
            D_803F6680.unk1A += 1;
            D_803F6680.unk2C = 1U;
            if (D_803F6680.unk1A >= 0xB) {
                if ((D_803F7DD5 == 0x1E) || (D_803F7DD5 == 0x1F)) {
                    D_803F6680.unk18 += 1;
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
                func_801337DC(0, 10.f, 20.0f, 0);
                func_8013385C(10.0f, 19.0f, 1.0f);
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6730_7C7DE0;
                D_803F6680.unk18 = 14;
                D_803F6680.unk1A = 0;
                func_801337DC(0, 10.0f, 20.0f, 0);
                func_8013385C(10.0f, 19.0f, 1.0f);
            }
            break;
        case 8:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6718_7C7DC8;
            }
            break;
        case 9:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A > 0) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk1E = 1;
                D_803F6680.unk2A = 0U;
                D_803F6680.unk1A = 0;
            }
            break;
        case 10:
            if (D_803F6680.unk1A == 0) {
                D_803F63C0 = load_level_text_data(D_8023F2A0.language, D_803F7DD5, D_803F3330, D_803F34C0);
                D_803F6704 = 0;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk1A = 1;
            }
            D_80204290 = 1;
            func_803929FC_7A40AC(0);

            if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
                (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 0x40);
                D_801D9ED4 = 0xA;
                func_80395074_7A6724(0);
                D_803F6680.unk18 = 0xC;
                D_803F6680.unk1A = 0;
                D_803F6680.unk2C = D_803F6680.unk2A = 1U;
            }
            if (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1)) {
                play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 0x40);
                func_80395074_7A6724(0);
                D_801D9ED4 = 0xA;
                func_8039661C_7A7CCC(0, 8, 1);
                D_803F6680.unk18 = 0xB;
                D_803F6680.unk2A = 1U;
                D_803F6680.unk2B = 0U;
                D_803F6680.unk2C = 1U;
                D_803F6680.unk1A = 0;
            }
            break;
        case 11:
            if ((func_80396714_7A7DC4()) && (D_803F6680.unk1A == 0)) {
                D_803F6680.unk1A = 1;
            }
            if (D_803F6680.unk1A != 0) {
                D_803F6680.unk1A += 1;
                if (D_803F6680.unk1A >= 3) {
                    D_803B683C_7C7EEC = D_803B6700_7C7DB0;
                    D_803F6680.unk2C = 0U;
                    D_803F6680.unk2A = 0U;
                    D_803F6680.unk18 = 4;
                    D_803F6680.unk1A = 0;
                    func_8039884C_7A9EFC();
                }
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6730_7C7DE0;
            }
            break;
        case 12:
            D_80204290 = 2;
            func_8039661C_7A7CCC(2, 8, 1);
            D_803B683C_7C7EEC = D_803B6718_7C7DC8;
            D_803F6680.unk1A = 0;
            D_803F6680.unk18 = 13;
            D_803F6680.unk2A = 1U;
            // change around here
            func_801337DC(0, 10.0f, 20.0f, 0);
            func_8013385C(10.0f, 19.0f, 1.0f);
            break;
        case 13:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
                func_802F07D0_701E80();
                func_802F07E8_701E98(3);
            }
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk18 = 0xE;
                D_803B683C_7C7EEC = D_803B6730_7C7DE0;
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6730_7C7DE0;
                func_802F07D0_701E80();
                func_802F07E8_701E98(3);
            }
            break;
        case 14:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 2) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk1A = 0;
            }
            break;
        case 15:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A == 11) {
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk2B = 0U;
            }
            if (D_803F6680.unk1A > 11) {
                func_8038FC58_7A1308();
            }
            break;
        case 30:
            D_803F6680.unk2A = 1U;
            D_803F6680.unk2C = 1U;
            func_8039661C_7A7CCC(0, 6, 1);
            D_803F6680.unk18 += 1;
            break;
        case 31:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 2;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0;
            }
            break;
        case 33:
            D_803F6680.unk18 = 4;
            D_803F6680.unk2A = 0U;
            D_803F6680.unk2C = 0U;
            D_803F6680.unk1A = 0;
            func_8039895C_7AA00C();
            func_8039884C_7A9EFC();
            break;
        case 40:
            D_80204290 = 1;
            func_803929FC_7A40AC(0);
            if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
                ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 0x40);
                D_80204290 = 2;
                D_803F6680.unk0 = 0;
                D_803F6680.unk27 = 1;
                set_music_volume(D_8023F2A0.musicVol);
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
            D_803F6680.unk2B = 0U;
            if (D_803F6680.unk1C > 0) {
                D_803F6680.unk1C -= 20;
            }
            load_pause_menu(0, D_803F6680.unk1C);
            draw_rectangle(&D_801D9E7C,                0,                    0,            8, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C, gScreenWidth - 8,                    0, gScreenWidth, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0,                    0, gScreenWidth,   8, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0,    gScreenHeight - 8,   D_80203FD0, 240, 0, 0, 0, 0xFF);
            break;
        case 1:
            D_80204290 = 2;
            D_803F6680.unk1A = 0;
            D_803F6680.unk18 += 1;
            D_803F6680.unk2C = 1U;
            D_803F6680.unk2A = 1U;
            break;
        case 2:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 8) {
                D_803F6680.unk18 += 2;
                func_8039661C_7A7CCC(1, 8, 1);
                D_803F6680.unk1A = 0;
            }
            break;
        case 4:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6718_7C7DC8;
            }
            break;
        case 5:
            D_803F6680.unk18 += 1;
            D_803F6680.unk2C = 0U;
            D_803F6680.unk2A = 0U;
            D_803F6680.unk1E = 1;
            D_803F6680.unk1A = 0;
            break;
        case 6:
            D_80204290 = 1;
            func_803929FC_7A40AC(0);
            if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
                (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1)) ||
                (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1))) {
                play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 0x40);
                D_801D9ED4 = 10;
                func_80395074_7A6724(0);
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
                D_803F6680.unk2C = 1U;
                D_803F6680.unk2A = 1U;
                D_803F6680.unk14 = 0;
                D_80204290 = 2;
            }
            break;
        case 7:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 9) {
                func_8039661C_7A7CCC(2, 8, 1);
                D_803F6680.unk18 += 1;
            }
            break;
        case 8:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 += 2;
            }
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6730_7C7DE0;
            }
            break;
        case 10:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 9) {
                D_803F6680.unk18 = 0;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk2A = 0U;
            }
            break;
        case 20:
            func_8039BBB8_7AD268();
            determine_available_levels();
            D_803F6680.unk2B = 1U;
            D_803F2D30.score = 0;
            func_802F07D0_701E80();
            D_803B683C_7C7EEC = D_803B6730_7C7DE0;
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 1U;
            D_803F6680.unk18 += 1;
            D_803F6680.unk2C = 1U;
            func_80397734_7A8DE4(((guRandom() % 4) + 0xD), 0);
            func_8039661C_7A7CCC(0xB, 8, 0);
            func_8013385C(4.0f, 0, 20.0f);
            break;
        case 21:
            if (func_80396748_7A7DF8()) {
                D_803F6680.unk18 = 25;
                D_803F6680.unk1A = 0;
                func_8039264C_7A3CFC();
                D_803B683C_7C7EEC = D_803B6700_7C7DB0;
                func_80397734_7A8DE4(0, 0);
            }
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 0x1F) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            break;
        case 22:
            if (func_80396748_7A7DF8()) {
                func_8039264C_7A3CFC();
                func_8039661C_7A7CCC(0, 8, 0);
            }
            D_803F6680.unk1A += 1;
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 += 1;
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
                D_803F6680.unk18 += 1;
            }
            D_803F6680.unk1A += 1;
            break;
        case 24:
            if (func_80396714_7A7DC4()) {
                func_80397734_7A8DE4(0, 0);
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            break;
        case 25:
            D_803F6680.unk1A += 1;
            if ((s32) D_803F6680.unk1A >= 3) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk2B = 0U;
                D_803F6680.unk1A = 0;
            }
            break;
        case 26:
            D_803F6680.unk18 = 4;
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 0U;
            D_803F6680.unk2B = 0U;
            D_803F6680.unk2C = 0U;
            D_803F6680.unk29 = 0U;
            func_8039884C_7A9EFC();
            func_8039895C_7AA00C();
            break;
        case 30:
            D_803F6680.unk2B = 1U;
            if (D_803F6680.unk1A == 0) {
                func_8039661C_7A7CCC(0xB, 8, 0);
            }
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A == 1) {
                func_8039BBB8_7AD268();
                determine_available_levels();
            }
            if (D_803F6680.unk1A == 5) {
                if ((gLevelIndex == GIVE_A_DOG_A_BONUS) ||
                    (gLevelIndex == WALRACE_64) ||
                    (gLevelIndex == EVOS_ESCAPE) ||
                    (gLevelIndex == PUNCHUP_PYRAMID)) {
                    if ((D_803E4D28 & 2)) {
                        func_80397734_7A8DE4(((guRandom() % 4) + 17), 0);
                    } else {
                        func_80397734_7A8DE4(((guRandom() % 4) + 13), 0);
                    }
                } else {
                    func_80397734_7A8DE4(((guRandom() % 4) + 17), 0);
                }
                D_803F6680.unk18 += 1;
            }
            break;
        case 31:
            if ((D_803F713C[0] == 0) || (func_80396748_7A7DF8())) {
                func_8039264C_7A3CFC();
                if (D_803F7DD5 == 34) {
                    gLevelIndex = D_803F7DD5 + 1;
                    D_803F6680.unk18 = 40;
                    D_803F6680.unk1A = 0;
                    func_8039661C_7A7CCC(2, 16, 0);
                } else {
                    if (func_80396748_7A7DF8()) {
                        func_8039264C_7A3CFC();
                        // struct copy
                        D_803B683C_7C7EEC = D_803B6700_7C7DB0;
                    } else {
                        func_8039661C_7A7CCC(0, 8, 0);
                    }
                    D_803F6680.unk18 += 1;
                }
            }
            break;
        case 32:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk1A = 0;
                D_803F6680.unk18 += 1;
            }
            break;
        case 33:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A == 2) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk2B = 0U;
            }
            break;
        case 34:
            D_803F6680.unk18 = 4;
            D_803F6680.unk1A = 0;
            D_803F6680.unk2A = 0U;
            D_803F6680.unk2C = 0U;
            D_803F6680.unk29 = 0U;
            func_8039884C_7A9EFC();
            func_8039895C_7AA00C();
            break;
        case 40:
            if (func_80396714_7A7DC4()) {
                D_803F6680.unk18 += 1;
                D_803F6680.unk1A = 0;
                func_802F07D0_701E80();
                func_802F07E8_701E98(3);
            }
            break;
        case 41:
            D_803F6680.unk1A += 1;
            if (D_803F6680.unk1A >= 0xD) {
                D_803F6680.unk2A = 0U;
                D_803F6680.unk2B = 0U;
                D_803F6680.unk2C = 0U;
                D_803F6680.unk18 += 1;
            }
            break;
        case 42:
            D_803F6680.unk1A += 1;
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
        func_8039546C_7A6B1C(&D_801D9E90, 960, 0x435, 0x416);
        func_8039546C_7A6B1C(&D_801D9E90, 1000, 0x435, 0x416);
        func_8039546C_7A6B1C(&D_801D9E90, 0x410, 0x435, 0x416);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unkDAC0);
    }
}
#endif

void func_80391A38_7A30E8(void) {
    func_8032CD20_73E3D0(1169, SFX_UNKNOWN_73, 0x4000, 0, D_803C032C_7D19DC);
    if (D_803F66AA == 1) {
        if ((guRandom() % 20) == 1) {
            D_803B6880_7C7F30 = (s32) (guRandom() % 6);
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
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, D_803C0348_7D19F8);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        case 5:
            func_8032CD20_73E3D0(1269, SFX_UNKNOWN_132, 0x1000, 0, D_803C034C_7D19FC);
            func_8032CD20_73E3D0(1369, SFX_UNKNOWN_133, 0x1000, 0, 1.0f);
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80391C90_7A3340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803925D0_7A3C80.s")

void func_8039264C_7A3CFC(void) {
    D_803F66B8.unk40 = 0;
    D_803F66B8.unk42 = 0;
    D_803F66B8.unk48 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80392668_7A3D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803929FC_7A40AC.s")

// render some text to screen?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80393024_7A46D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/load_pause_menu.s")

void func_80395074_7A6724(s32 debug) {
    if (0 && debug) {
        // something like this
    }
    D_801D9ED4 = 10;
}

void func_80395088_7A6738(Gfx **arg0, s16 ulx, s16 uly, s16 lrx, s16 lry, u8 color) {
    gDPPipeSync((*arg0)++);
    gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetCombineLERP((*arg0)++, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0, NOISE, 0, PRIMITIVE, 0, 0, 0, 0, 0);
    gDPSetPrimColor((*arg0)++, 0, 0, color, color, color, 0x80);
    gDPPipeSync((*arg0)++);
    gDPFillRectangle((*arg0)++, ulx, uly, lrx, lry);
}

void func_803951BC_7A686C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, 0x8000, 0x8000, 0x9000);
    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    gSPDisplayList((*arg0)++, D_04006D00);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
    gDPPipeSync((*arg0)++);
}

void func_80395314_7A69C4(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], arg1 << 16, arg2 << 16, arg3 << 16, 0, 0, 0x8000, 0x8000, 0x9000);
    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    gSPDisplayList((*arg0)++, D_0400A9E0);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
    gDPPipeSync((*arg0)++);
}

void func_8039546C_7A6B1C(Gfx **arg0, s16 arg1, s16 arg2, s16 arg3) {
}

void func_80395480_7A6B30(void) {
    D_803B66F0.unk0 = gScreenWidth  * 2;
    D_803B66F0.unk2 = gScreenHeight * 2;
    D_803B66F0.unk8 = gScreenWidth  * 2;
    D_803B66F0.unkA = gScreenHeight * 2;

    gDPPipeSync(D_801D9E7C++);
    func_80129594(&D_801D9E7C, D_80204278);
    gDPPipeSync(D_801D9E7C++);

    load_segments(&D_801D9E7C, D_80204278);

    gSPSegment(D_801D9E7C++, 0x04, osVirtualToPhysical(D_801D9E6C));
    gSPViewport(D_801D9E7C++, &D_803B66F0);
    func_80129430(&D_801D9E7C);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 1.0f, 2.0f, 2000.0f, 1.0f);
    guRotateRPY(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);

    guLookAt(&D_80204278->unk37490, D_803B683C.unk0, (D_803F6700 / 700.0f) + D_803B683C.unk4, D_803B683C.unk8, D_803B683C.unkC, D_803B683C.unk10, D_803B683C.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPFogPosition(D_801D9E7C++, 995, 999);
    gDPSetFogColor(D_801D9E7C++, 0xFF, 0xFF, 0xFF, 0x00);

    gSPDisplayList(D_801D9E7C++, D_01004270);
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
    gSPViewport(D_801D9E7C++, &D_803B66F0);

    guPerspective(&D_80204278->unk37410, &D_803C0658, 45.0f, 0.92f, 2.0f, D_803C0388, 1.0f);
    guRotateRPY(&D_80204278->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&D_80204278->unk374D0, 1.0f, 1.0f, 1.0f);
    guLookAt(&D_80204278->unk37490, D_803B683C.unk0, D_803B683C.unk4, D_803B683C.unk8, D_803B683C.unkC, D_803B683C.unk10, D_803B683C.unk14, 0.0f, 0.0f, 1.0f);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPDisplayList(D_801D9E7C++, D_01004270);
    gSPClearGeometryMode(D_801D9E7C++, G_FOG);
    gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_80395B58_7A7208.s")
// Needs significantly more understanding of C
// void func_80395B58_7A7208(void) {
//     s16 temp_t0;
//     s32 temp_lo;
//     f32 temp_a1;
//     u32 temp_a2;
//
//     temp_a1 = (u32) (40.0f * 1.0f);
//     D_80204278->unk3B638.l.col[0] = temp_a1;
//     D_80204278->unk3B638.l.colc[0] = temp_a1;
//     D_80204278->unk3B638.l.dir[0] = temp_a1;
//     temp_a2 = (u32) (200.0f * 1.0f);
//     D_80204278->unk3B640.l.col[0] = temp_a2;
//     D_80204278->unk3B640.l.colc[0] = temp_a2;
//     D_80204278->unk3B640.l.dir[0] = temp_a2;
//
//     D_80204278->unk3B648 = -0x6D;
//     D_80204278->unk3B649 = 0x5C;
//     D_80204278->unk3B64A = 0x70;
//     // huh
//     temp_t0 = (s16) ((s32) (s16) (D_803F670E + 2) % 360);
//     temp_lo = (s32) &D_80152350.unk2D0[(temp_t0 + 0xFF) / 6]; // maybe not unk2D0
//     D_80204278->unk3B650 = temp_lo;
//     D_80204278->unk3B651 = 8;
//     D_80204278->unk3B652 = 0;
//     D_80204278->unk3B654 = temp_lo;
//     D_80204278->unk3B655 = 0;
//     D_80204278->unk3B656 = 0;
//     D_80204278->unk3B658 = 0x57;
//     D_80204278->unk3B659 = 0x64;
//     D_80204278->unk3B65A = 0;
//
//     gSPNumLights(D_801D9E7C++, 1);
//     gSPLight(D_801D9E7C++, &D_80204278->unk3B640, 1);
//     gSPLight(D_801D9E7C++, &D_80204278->unk3B638, 2);
// }

void func_80395E98_7A7548(Gfx **arg0) {
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_2CYCLE);
    gDPPipeSync((*arg0)++);
    gSPDisplayList((*arg0)++, D_01004AF8);

    gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, G_RM_AA_ZB_OPA_SURF2);

    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_01030810);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1023, 256);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);

    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0x3E80000, 0x3E80000, 0x3E80000, 0, 0, 0xC0000, 0xC0000, 0xC0000);
    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);
}

void func_803960F4_7A77A4(Gfx **arg0) {
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_2CYCLE);
    gDPPipeSync((*arg0)++);
    gSPTexture((*arg0)++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP((*arg0)++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPSetGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING);

    func_80125FE0(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0x3E80000, 0x3E80000, 0x3E80000, 0, 0, 0x30000, 0x30000, 0x30000);

    gSPMatrix((*arg0)++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;
    gSPDisplayList((*arg0)++, D_04005B60);
    gSPPopMatrix((*arg0)++, G_MTX_MODELVIEW);

    gDPPipeSync((*arg0)++);
}

// calls sprite macros
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803962EC_7A799C.s")

void func_8039661C_7A7CCC(s16 arg0, s16 arg1, s16 arg2) {
    struct004 *temp_v0;

    if (arg2 != 0) {
        D_803F66B8.unk44 = 1;
    } else {
        D_803F66B8.unk44 = 0;
    }
    temp_v0 = &D_803B6700[arg0];
    D_803F66B8.unk0 = D_803B683C.unk0;
    D_803F66B8.unk4 = D_803B683C.unk4;
    D_803F66B8.unk8 = D_803B683C.unk8;
    D_803F66B8.unkC = D_803B683C.unkC;
    D_803F66B8.unk10 = D_803B683C.unk10;
    D_803F66B8.unk14 = D_803B683C.unk14;
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
    D_803F6680.unk6 = (*(s16*)&D_803F6680.unk8); // FIXME?
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
          D_803F66AF = (u8)1;
          return 1;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A0DA0/func_803967D4_7A7E84.s")
// void func_803967D4_7A7E84(u16 arg0, s16 arg1, u8 r, u8 g, u8 b, s16 head, s16 torso, s16 arms, s16 legs, s16 arg9) {
//     s32 sp4C;
//     s32 sp40;
//     f32 temp_f10_2;
//     f32 temp_f12;
//     f32 temp_f16;
//     f32 temp_f2;
//     f32 temp_f2_2;
//     f32 temp_f2_3;
//     s32 temp_f10;
//     s32 temp_f16_2;
//     s32 temp_s1;
//     s32 temp_s2;
//     s32 temp_t3;
//     s32 temp_t5;
//     s32 temp_t6;
//     s32 temp_t9;
//
//     s32 phi_t4;
//     s32 phi_t4_2;
//
//     gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
//     gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
//
//     if (arg9 == 1) {
//         if (head != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C3A40, 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 1);
//
//         if (arms != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4A40, 32, 32, 1.0f, 1.0f, 0, 0, arg0, arg1 + 32);
//
//         if (legs != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 1.0f, 1.0f, 0, 0, arg0 + 0xC, arg1 + 0x3A);
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 1.0f, 1.0f, 1, 0, arg0 - 0xC, arg1 + 0x3A);
//
//         if (legs != 0) {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//         } else {
//             gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//         }
//
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 1.0f, 1.0f, 0, 0, arg0 + 0x1A, arg1 + 0x1C);
//         func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 1.0f, 1.0f, 1, 0, arg0 - 0x1A, arg1 + 0x1C);
//         return;
//     }
//
//     if (head != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//     }
//
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C3A40, 0x20, 0x20, 0.5f, 0.5f, 0, 0, arg0, arg1);
//
//     if (arms != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//     }
//
//     temp_f2 = (f32) arg1;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4A40, 0x20, 0x20, 0.5f, 0.5f, 0, 0, arg0, (u32) (temp_f2 + (32.0f * 0.5f)));
//
//     if (legs != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//     }
//
//     temp_f2_2 = 12.0f * 0.5f;
//     temp_f12 = (f32) (s16) arg0;
//     temp_t9 = (u32) (temp_f2 + (58.0f * 0.5f)) & 0xFFFF;
//     sp40 = temp_t9;
//     sp4C = temp_f12;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, 0.5f, 0.5f, 0, 0, (u32) (temp_f12 + temp_f2_2), temp_t9);
//     temp_f16 = ( f32) sp4C - temp_f2_2; // bitwise
//     temp_f10 = (s32) temp_f16;
//
// //     if ((ERROR(cfc1) & 0x78) != 0) {
// //         if ((ERROR(cfc1) & 0x78) == 0) {
// //             phi_t4 = (s32) (temp_f16 - 2.1474836e9f) | 0x80000000;
// //         } else {
// // loop_26:
// //             phi_t4 = -1;
// //         }
// //     } else {
// //         phi_t4 = temp_f10;
// //         if (temp_f10 < 0) {
// //             goto loop_26;
// //         }
// //     }
//
//     // func_8039C834_7ADEE4(&D_801D9E7C, &D_800C4240, 0x20, 0x20, phi_t4, sp40);
//
//     if (legs != 0) {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0xFF);
//     } else {
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, r, g, b, 0x14);
//     }
//
//     temp_f2_3 = 26.0f * 0.5f;
//     temp_t5 = (u32) (temp_f2 + (28.0f * 0.5f)) & 0xFFFF;
//     func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, 0.5f, 0.5f, 0, 0, (u32) ((f32) sp4C + temp_f2_3), temp_t5);
//     temp_f10_2 = (f32) sp4C - temp_f2_3; // bitwise
//     temp_f16_2 = (s32) temp_f10_2;
// //     if ((ERROR(cfc1) & 0x78) != 0) {
// //         if ((ERROR(cfc1) & 0x78) == 0) {
// //             phi_t4_2 = (s32) (temp_f10_2 - 2.1474836e9f) | 0x80000000;
// //         } else {
// // loop_34:
// //             phi_t4_2 = -1;
// //         }
// //     } else {
// //         phi_t4_2 = temp_f16_2;
// //         if (temp_f16_2 < 0) {
// //             goto loop_34;
// //         }
// //     }
//
//     // func_8039C834_7ADEE4(&D_801D9E7C, &D_800C5240, 0x20, 0x20, phi_t4_2, temp_t5);
// }
