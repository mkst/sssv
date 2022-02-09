#include <ultra64.h>
#include "common.h"

#include "pp.h"


void func_80398630_7A9CE0(void) {
    load_data_section(6);
    // unpack menu graphics
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04006EC0)), D_800BA760); // central piece of SSSV
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007FA0)), D_800BDC80); // "SSSV" Header graphic
    // unpack powercell
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04000000)), D_800DE390); // powercell
    // unpack evo bodyparts
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04013060)), D_800C3A40); // evo head trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040133C0)), D_800C5240); // evo arms trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040131B0)), D_800C4240); // evo legs trophy
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04013580)), D_800C4A40); // evo torso trophy
    // unpack 'silver' level ring pieces
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007700)), D_800BB700); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040077A0)), D_800BBBB0); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040078C0)), D_800BC060); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_040079F0)), D_800BC510); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007B40)), D_800BC9C0); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007C60)), D_800BCE70); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007D90)), D_800BD320); // silver ring piece
    UnpackRNC((RNC_fileptr)(D_801D9E6C + SEGMENT_OFFSET(D_04007EC0)), D_800BD7D0); // silver ring piece
}

void func_8039884C_7A9EFC(void) {
    s16 sp18[44];

    determine_available_levels();
    D_803F7DA8.lastLevel = 99;
    D_803F7D78.unk0 = 0;
    D_803F7D78.unk4 = 0;
    D_803F7D78.unk8 = 0;
    D_803F7D78.unkC = 0;
    D_803F7D78.unk10 = 0;
    D_803F7D78.unk14 = 0;
    D_803F7D78.unk18 = 0;
    D_803F7D78.unk1C = 0;
    D_803F7D78.unk20 = 0;
    D_803F7D70 = D_803C03F4_7D1AA4; // 0.1f
    prepare_text(sp18, (u8*)D_803F2D50.titleText); // zero out title?
    D_803F7DA8.unk8 = 1.0f;
    D_803B7468 = D_803F7DA8.currentLevel * 12;
    D_803F7D68 = D_803F7DA8.currentLevel * 12;
    D_803F7DA8.unk0 = 40.0f;
    D_803F7DA8.unk4 = 30.0f;
    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DA0 = 6;
    D_803F7DA1 = 6;
    D_803F7DA2 = 0;
    D_803F7DA3 = 0;
    D_803F2E1E = get_evo_suit_color();
}

void func_8039895C_7AA00C(void) {
    s16 i;

    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DD7 = 0;
    generate_stars();

    for (i = 0; i < 4; i++) {
        read_eeprom(i);
        memcpy_sssv((u8*)&D_8023F260, (u8*) &D_8023F2E0[i], 64);
    }
    read_eeprom(D_803F7DD6);
}

void func_80398A00_7AA0B0(void) {
    D_803F7DD8 = 0;
}

#if 0
void display_zone_select_screen(void) {
    char ascii[52];
    s16  wide_text[26]; // 0x118 - 0xE4 => 52

    s16 currentLevel;

    f32 spE0;
    f32 spDC;

    s16 old_current_level;
    s16 vertical_offset;
    s16 tmp_level;

    s16 secs;
    s16 mins;

    u8 evo_r;
    u8 evo_b;
    u8 evo_g;

    D_803E4D2C = 0;
    if (D_8028645C != 25) {
        D_8028645C = 25;
        D_801546D8 = 1600; // volume related
        D_801546E0 = 2048;
        D_8015517C = 1.0f;
    }
    D_803B74C4_7C8B74 = 12.0f; // font scale
    if ((D_8023F2A0.language == LANG_ITALIAN) ||
        (D_8023F2A0.language == LANG_FRENCH) ||
        (D_8023F2A0.language == LANG_SPANISH) ||
        (D_8023F2A0.language == LANG_PORTUGESE)) {
        D_803B74C4_7C8B74 = D_803C03F8_7D1AA8; // 9.7f
    }

    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);
    render_stars(&D_801D9E7C);

    gDPPipeSync(D_801D9E7C++);

    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    D_803F7DA8.unk0 = 94.0f;
    D_803F7DA8.unk4 = 134.0f;
    D_803F7DA8.unk0 = func_8039CDE8_7AE498(D_803F7DA8.unk0, 94.0f);
    D_803F7DA8.unk4 = func_8039CDE8_7AE498(D_803F7DA8.unk4, 134.0f);
    D_803F7DA8.unk8 += (2.0 - D_803F7DA8.unk8) / 16;
    // 1.95 and 2.05
    if ((D_803C0400_7D1AB0 < D_803F7DA8.unk8) && (D_803F7DA8.unk8 < D_803C0408_7D1AB8)) {
        D_803F7DA8.unk8 = 2.0f;
    }

    spE0 = D_803F7DA8.unk0 - 21.5f * D_803F7DA8.unk8;
    spDC = D_803F7DA8.unk4 - 21.5f * D_803F7DA8.unk8;

    gDPPipeSync(D_801D9E7C++);

    load_default_display_list(&D_801D9E7C);
    select_font(0, FONT_COMIC_SANS, 0, 0);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_ZONE_SELECT), 0x18, 0x1F, 24.0f, 16.0f, -1);

    gSPDisplayList(D_801D9E7C++, &D_801584A0);

    gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

    // decompress ZONE SELECT image
    UnpackRNC(SEGMENT_OFFSET(D_04012B20_1296F0) + D_801D9E6C, D_800DD3F0); // ZONE_SELECT rgba16

    if (D_803F7DA8.lastLevel != D_803F7DA8.currentLevel) {
        // level thumbnails
        dma_read(D_803B7268_7C8918[D_803F7DA8.currentLevel].start, D_800B0B20, D_803B7268_7C8918[D_803F7DA8.currentLevel].end - D_803B7268_7C8918[D_803F7DA8.currentLevel].start);
        UnpackRNC(D_800B0B20, D_800B49A0);

        D_803F7DA8.lastLevel = D_803F7DA8.currentLevel;

        // trophy images
        dma_read(D_803B7368_7C8A18[D_803F7DA8.currentLevel].start, D_800B0B20, D_803B7368_7C8A18[D_803F7DA8.currentLevel].end - D_803B7368_7C8A18[D_803F7DA8.currentLevel].start);
        UnpackRNC(D_800B0B20, D_800B68E0);

        D_803F63C0 = load_level_text_data(D_8023F2A0.language, D_803F7DA8.currentLevel, D_803F3330, D_803F34C0);
        load_level_title();
    }
    gDPPipeSync(D_801D9E7C++);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0x80);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPPipeSync(D_801D9E7C++);

    func_803962EC_7A799C(&D_801D9E7C, 800, 592, 1200, 888, D_800B49A0, 64, 47);
    gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0x1A);

    // currentLevel = (s16)(D_803F7DA8.currentLevel + 1); // no diff?
    if (((s16)(D_803F7DA8.currentLevel + 1) == GIVE_A_DOG_A_BONUS) ||
        ((s16)(D_803F7DA8.currentLevel + 1) == WALRACE_64) ||
        ((s16)(D_803F7DA8.currentLevel + 1) == EVOS_ESCAPE) ||
        ((s16)(D_803F7DA8.currentLevel + 1) == PUNCHUP_PYRAMID) ||
        ((s16)(D_803F7DA8.currentLevel + 1) == BIG_CELEBRATION_PARADE)) {
        switch (D_803F2E1E) { // evo suit color
        case EVO_BRONZE_SHELLSUIT:
            evo_r = 200;
            evo_g = 200;
            evo_b = 0;
            break;
        case EVO_SILVER_SHELLSUIT:
            evo_r = 180;
            evo_g = 180;
            evo_b = 180;
            break;
        case EVO_GOLD_SHELLSUIT:
            evo_r = 255;
            evo_g = 255;
            evo_b = 20;
            break;
        }

        func_803967D4_7A7E84(276, 102, evo_r, evo_g, evo_b, D_8023F260.evoPartsCollected & EVO_HEAD, D_8023F260.evoPartsCollected & EVO_TORSO, D_8023F260.evoPartsCollected & EVO_ARMS, D_8023F260.evoPartsCollected & EVO_LEGS, 0);
    } else if (D_8023F260.level[D_803F7DA8.currentLevel].trophy) {
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        func_803962EC_7A799C(&D_801D9E7C, 1072, 448, 1200, 576, &D_800B68E0, 32, 31);
    }

    if (D_803F7DA2 != 0) {
        D_803F7DA2 -= 1;
    }
    if (D_803F7DA3 != 0) {
        D_803F7DA3 -= 1;
    }
    if ((D_802912E4 == 1) && (gControllerInput->stick_x <= 20)) {
        D_803F7DA3 = 0;
    }
    if ((D_802912E3 == 1) && (gControllerInput->stick_x >= -20)) {
        D_803F7DA2 = 0;
    }
    if (((gControllerInput->button & CONT_LEFT) || (gControllerInput->stick_x < -20)) && (D_803F7DA2 == 0)) {
        if (D_803F7DA0 < 8) {
            D_803F7DA0 = 8;
        } else {
            D_803F7DA0 -= 1;
        }
        D_803F7DA2 = D_803F7DA0;
        old_current_level = D_803F7DA8.currentLevel;
        D_803F7DA8.currentLevel = get_next_available_level(D_803F7DA8.currentLevel, -1);
        if (old_current_level != D_803F7DA8.currentLevel) {
            if (D_803F7DA8.currentLevel == PUNCHUP_PYRAMID) {
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
            } else if (get_biome_for_level(D_803F7DA8.currentLevel) != D_803F7DA8.biome) {
                play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
            } else {
                play_sound_effect(SFX_MENU_NAGIVATE_DOWN, 0, 0x5000, 1.0f, 64);
            }
        }
        if (old_current_level != D_803F7DA8.currentLevel) {
            func_80395074_7A6724(0);
        } else {
            func_80395074_7A6724(1);
        }
    }
    if (((gControllerInput->button & CONT_RIGHT) || (gControllerInput->stick_x > 20)) && (D_803F7DA3 == 0)) {
        if (D_803F7DA1 < 8) {
            D_803F7DA1 = 8;
        } else {
            D_803F7DA1 -= 1;
        }
        D_803F7DA3 = D_803F7DA1;
        old_current_level = D_803F7DA8.currentLevel;
        D_803F7DA8.currentLevel = get_next_available_level(D_803F7DA8.currentLevel, 1);
        if (old_current_level != D_803F7DA8.currentLevel) {
            if (D_803F7DA8.currentLevel == PUNCHUP_PYRAMID) {
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
            } else if (get_biome_for_level(D_803F7DA8.currentLevel) != D_803F7DA8.biome) {
                play_sound_effect(SFX_MENU_NAGIVATE_NEW_BIOME, 0, 0x5000, 1.0f, 64);
            } else {
                play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
            }
        }
        if (old_current_level != D_803F7DA8.currentLevel) {
            func_80395074_7A6724(0);
        } else {
            func_80395074_7A6724(1);
        }
    }
    if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
        ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
        play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
        func_80395074_7A6724(0);
        D_803F6680.unk18 += 1;
        gLevelIndex = D_803F7DA8.currentLevel + 1;
    }
    if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
        play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
        func_80395074_7A6724(0);
        D_803F6680.unk18 -= 1;
        func_8039895C_7AA00C();
    }

    D_803F7DA8.biome = get_biome_for_level(D_803F7DA8.currentLevel);
    if (D_803F7DA8.biome == UI_EUROPE_BIOME) {
        D_803F7DA8.unkC += (-6.0 - D_803F7DA8.unkC) / 2;     // pop out ring
        D_803F7DA8.unk10 += (-12.0 - D_803F7DA8.unk10) / 2;  // pop out ring
        D_803F7DA8.unkC = func_8039CDE8_7AE498(D_803F7DA8.unkC, -6.0f);
        D_803F7DA8.unk10 = func_8039CDE8_7AE498(D_803F7DA8.unk10, -12.0f);
    } else {
        D_803F7DA8.unkC += (0.0f - D_803F7DA8.unkC) / 2;
        D_803F7DA8.unk10 += (0.0f - D_803F7DA8.unk10) / 2;
        D_803F7DA8.unkC = func_8039CDE8_7AE498(D_803F7DA8.unkC, 0.0f);
        D_803F7DA8.unk10 = func_8039CDE8_7AE498(D_803F7DA8.unk10, 0.0f);
    }

    if (D_803F7DA8.biome == UI_ICE_BIOME) {
        D_803F7DA8.unk24 += (12.0 - D_803F7DA8.unk24) / 2;
        D_803F7DA8.unk28 += (-4.0 - D_803F7DA8.unk28) / 2;
        D_803F7DA8.unk24 = func_8039CDE8_7AE498(D_803F7DA8.unk24, 12.0f);
        D_803F7DA8.unk28 = func_8039CDE8_7AE498(D_803F7DA8.unk28, -4.0f);
    } else {
        D_803F7DA8.unk24 += (0.0f - D_803F7DA8.unk24) / 2;
        D_803F7DA8.unk28 += (0.0f - D_803F7DA8.unk28) / 2;
        D_803F7DA8.unk24 = func_8039CDE8_7AE498(D_803F7DA8.unk24, 0.0f);
        D_803F7DA8.unk28 = func_8039CDE8_7AE498(D_803F7DA8.unk28, 0.0f);
    }

    if (D_803F7DA8.biome == UI_JUNGLE_BIOME) {
        D_803F7DA8.unk1C += (3.0 - D_803F7DA8.unk1C) / 2;
        D_803F7DA8.unk20 += (12.0 - D_803F7DA8.unk20) / 2;
        D_803F7DA8.unk1C = func_8039CDE8_7AE498(D_803F7DA8.unk1C, 3.0f);
        D_803F7DA8.unk20 = func_8039CDE8_7AE498(D_803F7DA8.unk20, 12.0f);
    } else {
        D_803F7DA8.unk1C += (0.0f - D_803F7DA8.unk1C) / 2;
        D_803F7DA8.unk20 += (0.0f - D_803F7DA8.unk20) / 2;
        D_803F7DA8.unk1C = func_8039CDE8_7AE498(D_803F7DA8.unk1C, 0.0f);
        D_803F7DA8.unk20 = func_8039CDE8_7AE498(D_803F7DA8.unk20, 0.0f);
    }

    if (D_803F7DA8.biome == UI_DESERT_BIOME) {
        D_803F7DA8.unk14 += (-12.0 - D_803F7DA8.unk14) / 2;
        D_803F7DA8.unk18 += (6.0 - D_803F7DA8.unk18) / 2;
        D_803F7DA8.unk14 = func_8039CDE8_7AE498(D_803F7DA8.unk14, -12.0f);
        D_803F7DA8.unk18 = func_8039CDE8_7AE498(D_803F7DA8.unk18, 6.0f);
    } else {
        D_803F7DA8.unk14 += (0.0f - D_803F7DA8.unk14) / 2;
        D_803F7DA8.unk18 += (0.0f - D_803F7DA8.unk18) / 2;
        D_803F7DA8.unk14 = func_8039CDE8_7AE498(D_803F7DA8.unk14, 0.0f);
        D_803F7DA8.unk18 = func_8039CDE8_7AE498(D_803F7DA8.unk18, 0.0f);
    }

    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    // big celebration parade
    func_8039BE98_7AD548(180, 180, 180, 128, 30, 30, &D_8023F260,                              spE0,                                spDC, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // europe
    func_8039BE98_7AD548(180,  40, 120, 128, 0,   9, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unkC,  D_803F7DA8.unk4 + D_803F7DA8.unk10, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // ice
    func_8039BE98_7AD548(0,   180, 255, 128, 10, 16, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk24, D_803F7DA8.unk4 + D_803F7DA8.unk28, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // jungle
    func_8039BE98_7AD548(0,   160,   0, 128, 17, 22, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk1C, D_803F7DA8.unk4 + D_803F7DA8.unk20, D_803F7DA8.unk8, D_803F7DA8.currentLevel);
    // desert
    func_8039BE98_7AD548(200, 200,   0, 128, 23, 29, &D_8023F260, D_803F7DA8.unk0 + D_803F7DA8.unk14, D_803F7DA8.unk4 + D_803F7DA8.unk18, D_803F7DA8.unk8, D_803F7DA8.currentLevel);

    load_default_display_list(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
    select_font(0, FONT_COMIC_SANS, 0, 0);

    // currentLevel = D_803F7DA8.currentLevel; // 0-indexed
    tmp_level = D_803F7DA8.currentLevel;

    vertical_offset = 60;
    if (D_803F7DA8.currentLevel != SECRET_LEVEL-1) { // hidden or BIG_CELEBRATION_PARADE ?
        // write title text
        display_text(&D_801D9E7C, (u8*)D_803F2D50.titleText, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        tmp_level = D_803F7DD5;
    }
    vertical_offset += D_803B74B0_7C8B60 + 1.0f;
    currentLevel = tmp_level;

    if (D_803F7DA8.currentLevel != SECRET_LEVEL-1) {
        if (D_8023F260.level[D_803F7DA8.currentLevel].completed == 1) {
            display_text(&D_801D9E7C, get_message_address_by_id(MSG_SECURED), 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        } else {
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_AVAILABLE), 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        }
        vertical_offset += D_803B74B0_7C8B60 + 1.0f;
        tmp_level = D_803F7DD5;
    }

    // this can't be right?
    // currentLevel = (s16)(D_803F7DA8.currentLevel + 1);
    currentLevel += tmp_level + 1;
    if ((currentLevel == GIVE_A_DOG_A_BONUS) ||
        (currentLevel == WALRACE_64) ||
        (currentLevel == EVOS_ESCAPE) ||
        (currentLevel == PUNCHUP_PYRAMID) ||
        (currentLevel == BIG_CELEBRATION_PARADE) ||
        (currentLevel == SECRET_LEVEL)) {

        if (currentLevel == GIVE_A_DOG_A_BONUS) {
            s32 time = (D_8023F260.unk30 >> 13) & 0x1FF;
            if (time) {
                seconds_to_mins_secs(time, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, D_803C03A0_7D1A50, mins, secs); // "%d:0%d"
                } else {
                    sprintf(ascii, D_803C03A8_7D1A58, mins, secs); // "%d:%d"
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_1), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (currentLevel == WALRACE_64) {
            if (D_8023F260.unk30 & 0xFF) {
                seconds_to_mins_secs(D_8023F260.unk30 & 0xFF, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, D_803C03B0_7D1A60, mins, secs); // "%d:0%d"
                } else {
                    sprintf(ascii, D_803C03B8_7D1A68, mins, secs); // "%d:%d"
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                if ((D_8023F2A0.language == LANG_ITALIAN) || (D_8023F2A0.language == LANG_FRENCH)) {
                    display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_2), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                } else {
                    display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_2), 270, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                }
            }
        }
        if (currentLevel == EVOS_ESCAPE) {
            if ((D_8023F260.unk30 >> 24) * 100) {
                sprintf(ascii, D_803C03C0_7D1A70, (D_8023F260.unk30 >> 24) * 100); //  "%d"
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_HIGH_SCORE), 257, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (currentLevel == PUNCHUP_PYRAMID) {
            u16 rounds = (D_8023F260.unk30 >> 8) & 0x1F;
            if (rounds) {
                sprintf(ascii, D_803C03C4_7D1A74, rounds); //  "%d"
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_ROUNDS), 285, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (currentLevel == BIG_CELEBRATION_PARADE) {
            s32 time = (D_8023F260.unk34 >> 8) & 0x1FF;
            if (time) {
                seconds_to_mins_secs(time, &mins, &secs);
                if (secs < 10) {
                    sprintf(ascii, D_803C03C8_7D1A78, mins, secs); // "%d:0%d"
                } else {
                    sprintf(ascii, D_803C03D0_7D1A80, mins, secs); // "%d:%d"
                }
                prepare_text((u8*)ascii, wide_text);
                display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
                display_text(&D_801D9E7C, get_message_address_by_id(MSG_RECORD_1), 264, vertical_offset, D_803B74C4_7C8B74, D_803B74C0_7C8B70);
            }
        }
        if (currentLevel == SECRET_LEVEL) {
            s32 score = (D_8023F260.unk34 >> 21) & 0x7FF;
            sprintf(ascii, D_803C03D8_7D1A88, score * 100); // "%d"
            prepare_text((u8*)ascii, wide_text);
            display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
            display_text(&D_801D9E7C, get_message_address_by_id(MSG_HIGH_SCORE), 240, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);
        }
    } else {
        sprintf(ascii, D_803C03DC_7D1A8C, D_8023F260.level[currentLevel].powercells); //  "%2d"
        prepare_text((u8*)ascii, wide_text);
        display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);

        gSPDisplayList(D_801D9E7C++, &D_801584A0);

        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x80);

        // draw powercell
        func_803962EC_7A799C(&D_801D9E7C, 1040, (vertical_offset - 2) << 2, 1104, (vertical_offset + 14) << 2, D_800DE390, 32, 32);
    }
    func_8039D034_7AE6E4(&D_801D9E7C, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ui_main_menu/display_zone_select_screen.s")
#endif

void func_8039A2DC_7AB98C(void) {
    s8 ascii[26];
    s16 wide_text[26];
    s16 vertical_offset;

    s8 cont_up;
    s8 cont_down;
    s8 cont_left;
    s8 cont_right;
    s8 stick_input;

    s16 x_offset;
    s16 y_offset;
    s16 progress[3];

    if (D_803F7DA8.unk2F == 0) {
        D_803F7DA8.unk31 = 99; // initialise default?
    }
    func_8039CE38_7AE4E8(&D_801D9E7C);
    func_8039CAB8_7AE168(1);

    render_stars(&D_801D9E7C);
    gDPPipeSync(D_801D9E7C++);

    load_default_display_list(&D_801D9E7C);

    select_font(0U, FONT_COMIC_SANS, 0U, 0U);
    set_menu_text_color(0xFF, 0xFF, 0U, 0xFF);
    if (D_8023F2A0.language == LANG_FRENCH) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_BANK_SELECT), 24, 31, 22.0f, 16.0f, -1);
        D_803B74AC_7C8B5C = 11.0f; // glyph height
        D_803B74B0_7C8B60 = 16.0f; // glyph width
    } else {
        D_803B74AC_7C8B5C = 12.0f; // glyph height
        D_803B74B0_7C8B60 = 16.0f; // glyph width
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_BANK_SELECT), 24, 31, 24.0f, 16.0f, -1);
    }

    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    gSPDisplayList(D_801D9E7C++, D_801584A0);

    func_8039C5F8_7ADCA8(56, 88, 1.0f, (PlayerEeprom*)&D_8023F2E0[0], (D_803F7DA8.bank == 0) || (D_803F7DA8.unk31 == 0));
    func_8039C5F8_7ADCA8(0x84, 88, 1.0f, (PlayerEeprom*)&D_8023F2E0[1], (D_803F7DA8.bank == 1) || (D_803F7DA8.unk31 == 1));
    func_8039C5F8_7ADCA8(56, 164, 1.0f, (PlayerEeprom*)&D_8023F2E0[2], (D_803F7DA8.bank == 2) || (D_803F7DA8.unk31 == 2));
    func_8039C5F8_7ADCA8(0x84, 164, 1.0f, (PlayerEeprom*)&D_8023F2E0[3], (D_803F7DA8.bank == 3) || (D_803F7DA8.unk31 == 3));

    // get user progress
    if (D_803F7DA8.unk2F == 2) {
        get_player_progress((PlayerEeprom *) &D_8023F2E0[D_803F7DA8.unk31], (s16*)&progress);
    } else {
        get_player_progress((PlayerEeprom *) &D_8023F2E0[D_803F7DA8.bank], (s16*)&progress);
    }
    set_menu_text_color(0xFFU, 0xFFU, 0U, 0xFFU);

    if (D_802912E4 == 1) {
        D_803F7DA3 = 0;
    }
    if (D_802912E3 == 1) {
        D_803F7DA2 = 0;
    }

    cont_up = cont_down = cont_left = cont_right = stick_input = 0;

    if (gControllerInput->stick_x < -0x1E) {
        if (D_801D9ED4 == 0) {
            cont_left = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_x > 0x1E) {
        if (D_801D9ED4 == 0) {
            cont_right = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_y > 0x1E) {
        if (D_801D9ED4 == 0) {
            cont_up = 1;
        } else {
            stick_input = 1;
        }
    }
    if (gControllerInput->stick_y < -0x1E) {
        if (D_801D9ED4 == 0) {
            cont_down = 1;
        } else {
            stick_input = 1;
        }
    }
    if ((cont_up != 0) || (cont_down != 0) || (cont_left != 0) || (cont_right != 0)) {
        D_801D9ED4 = 17;
    }

    if (stick_input == 0) {
        if (((gControllerInput->button & CONT_LEFT) != 0) && (D_802912E3 == 1)) {
            cont_left = 1;
        } else if (((gControllerInput->button & CONT_RIGHT) != 0) && (D_802912E4 == 1)) {
            cont_right = 1;
        } else if (((gControllerInput->button & CONT_UP) != 0) && (D_802912E1 == 1)) {
            cont_up = 1;
        } else if (((gControllerInput->button & CONT_DOWN) != 0) && (D_802912E2 == 1)) {
            cont_down = 1;
        }
    }
    switch (D_803F7DA8.unk2F) { // BANK SELECT
    case 0: // NO MENU OPEN
        if ((cont_left) && ((D_803F7DA8.bank == 1) || (D_803F7DA8.bank == 3))) {
            D_803F7DA8.bank -= 1;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_right) && (((D_803F7DA8.bank == 0)) || (D_803F7DA8.bank == 2))) {
            D_803F7DA8.bank += 1;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_up) && (((D_803F7DA8.bank == 2)) || (D_803F7DA8.bank == 3))) {
            D_803F7DA8.bank -= 2;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((cont_down) && (((D_803F7DA8.bank == 0)) || (D_803F7DA8.bank == 1))) {
            D_803F7DA8.bank += 2;
            play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
        }
        if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1) && (D_803F6680.unk24 == 0)) {
            play_sound_effect(164, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            func_8038F708_7A0DB8();
        }
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk2F == 0) {
                D_803F7DA8.unk2F = 1;
                D_803F7DA8.unk30 = 0; // SELECT
            }
        }
        break;
    case 1: // "SELECT / COPY / DELETE" MENU OPEN
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk30 == 0) { // SELECT
                play_sound_effect(0x8F, 0, 0x5000, 1.0f, 64);
                memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F260, 64);

                D_803F7DA8.unk8 = 1.0f; // scale
                switch (D_803F7DA8.bank) {
                case 0:
                    D_803F7DA8.unk0 = 56.0f;
                    D_803F7DA8.unk4 = 88.0f;
                    break;
                case 1:
                    D_803F7DA8.unk0 = 132.0f;
                    D_803F7DA8.unk4 = 88.0f;
                    break;
                case 2:
                    D_803F7DA8.unk0 = 56.0f;
                    D_803F7DA8.unk4 = 164.0f;
                    break;
                case 3:
                    D_803F7DA8.unk0 = 132.0f;
                    D_803F7DA8.unk4 = 164.0f;
                    break;
                }

                D_803F6680.unk18 += 1;
                func_8039884C_7A9EFC();
                D_803F7DA8.currentLevel = 0;
            }
            if (D_803F7DA8.unk30 == 1) { // COPY
                play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);

                D_803F7DA8.unk2F = 2;
                if (D_803F7DA8.bank == 0) {
                    D_803F7DA8.unk31 = 1;
                }
                if (D_803F7DA8.bank == 1) {
                    D_803F7DA8.unk31 = 3;
                }
                if (D_803F7DA8.bank == 2) {
                    D_803F7DA8.unk31 = 0;
                }
                if (D_803F7DA8.bank == 3) {
                    D_803F7DA8.unk31 = 2;
                }
            }
            if (D_803F7DA8.unk30 == 2) { // DELETE
                play_sound_effect(0x93, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 3;
                D_803F7DA8.unk30 = 0;
            }
        } else {
            if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
                play_sound_effect(164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if (cont_up != 0) {
                if (D_803F7DA8.unk30 > 0) {
                    D_803F7DA8.unk30 -= 1;
                    play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
                }
            }
            if (cont_down != 0) {
                if (D_803F7DA8.unk30 < 2) {
                    D_803F7DA8.unk30 += 1;
                    play_sound_effect(0x91, 0, 0x5000, 1.0f, 64);
                }
            }
        }

        if (D_803F7DA8.bank == 0) {
            x_offset = 58;
            y_offset = 88;
        }
        if (D_803F7DA8.bank == 1) {
            x_offset = 134;
            y_offset = 88;
        }
        if (D_803F7DA8.bank == 2) {
            x_offset = 58;
            y_offset = 164;
        }
        if (D_803F7DA8.bank == 3) {
            x_offset = 134;
            y_offset = 164;
        }

        draw_rectangle(&D_801D9E7C, x_offset - 38, y_offset - 24, x_offset + 36, y_offset + 20, 0, 0, 0, 0xA8);
        load_default_display_list(&D_801D9E7C);
        select_font(0U, FONT_COMIC_SANS, 0U, 0U);

        if (D_803F7DA8.unk30 == 0) { // SELECT
            set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU); // white
        } else {
            set_menu_text_color(0x80U, 0x80U, 0x80U, 0xFFU); // grey
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_SELECT), x_offset, (y_offset - 0x12), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        if (D_803F7DA8.unk30 == 1) { // COPY
            set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);
        } else {
            set_menu_text_color(0x80U, 0x80U, 0x80U, 0xFFU);
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_COPY), x_offset, (y_offset - 6), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        if (D_803F7DA8.unk30 == 2) { // DELETE
            set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);
        } else {
            set_menu_text_color(0x80U, 0x80U, 0x80U, 0xFFU);
        }
        display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_DELETE), x_offset, (y_offset + 6), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

        break;
    case 2: // "COPY TO" MENU
        if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1)) ||
            ((gControllerInput->button & A_BUTTON) && (D_802912DF == 1))) {
            func_80395074_7A6724(0);
            memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F2E0[D_803F7DA8.unk31], 64);
            memcpy_sssv((u8 *) &D_8023F2E0[D_803F7DA8.bank], (u8 *) &D_8023F260, 0x40U);
            write_eeprom((s16) D_803F7DA8.unk31);
            D_803F7DA8.unk2F = 0;
            play_sound_effect(SFX_UNKNOWN_143, 0, 0x5000, 1.0f, 64);
        } else {
            if ((gControllerInput->button & B_BUTTON) && (D_802912E0 == 1)) {
                play_sound_effect(164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if ((cont_left != 0) && (((D_803F7DA8.unk31 == 1)) || (D_803F7DA8.unk31 == 3))) {
                D_803F7DA8.unk31 = (s8) (D_803F7DA8.unk31 - 1);
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 += 1;
                }
            }
            if ((cont_right != 0) && (((D_803F7DA8.unk31 == 0)) || (D_803F7DA8.unk31 == 2))) {
                D_803F7DA8.unk31 = (s8) (D_803F7DA8.unk31 + 1);
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);

                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 -= 1;
                }
            }
            if ((cont_up != 0) && (((D_803F7DA8.unk31 == 2)) || (D_803F7DA8.unk31 == 3))) {
                D_803F7DA8.unk31 -= 2;
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);

                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 += 2;
                }
            }
            if ((cont_down != 0) && (((D_803F7DA8.unk31 == 0)) || (D_803F7DA8.unk31 == 1))) {
                D_803F7DA8.unk31 += 2;
                play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                if (D_803F7DA8.bank == D_803F7DA8.unk31) {
                    D_803F7DA8.unk31 -= 2;
                }
            }
            if (D_803F7DA8.bank == 0) {
                x_offset = 58;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 1) {
                x_offset = 134;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 2) {
                x_offset = 58;
                y_offset = 164;
            }
            if (D_803F7DA8.bank == 3) {
                x_offset = 134;
                y_offset = 164;
            }
            draw_rectangle(&D_801D9E7C, (x_offset - 0x1E), (y_offset - 0x18), (x_offset + 0x1C), (s16) (y_offset + 0x14), (u8) 0, (u8) 0, (u8) 0, (u8) 0xA8);
            load_default_display_list(&D_801D9E7C);
            select_font(0U, FONT_COMIC_SANS, 0U, 0U);
            set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_COPY2), x_offset, (y_offset - 0xC), D_803B74B4_7C8B64, D_803B74B8_7C8B68);
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_TO), x_offset, y_offset, D_803B74B4_7C8B64, D_803B74B8_7C8B68);
        }
        break;
    case 3:
        if ((((gControllerInput->button & START_BUTTON)) && (D_802912DE == 1)) ||
            (((gControllerInput->button & A_BUTTON)) && (D_802912DF == 1))) {
            play_sound_effect(164, 0, 0x5000, 1.0f, 64);
            func_80395074_7A6724(0);
            if (D_803F7DA8.unk30 == 0) { // SELECT
                D_803F7DA8.unk2F = 0;
            } // else
            if (D_803F7DA8.unk30 == 1) { // COPY
                memset_bytes((u8 *) &D_8023F260, 0U, 0x40U);
                memset_bytes((u8 *) &D_8023F2E0[D_803F7DA8.bank], 0U, 0x40U);
                write_eeprom((s16) D_803F7DA8.bank);
                D_803F7DA8.unk2F = 0;
            }
        } else {
            if (((gControllerInput->button & B_BUTTON)) && (D_802912E0 == 1)) {
                play_sound_effect(SFX_UNKNOWN_164, 0, 0x5000, 1.0f, 64);
                D_803F7DA8.unk2F = 0;
            }
            if ((cont_up != 0) || (cont_down != 0)) {
                D_803F7DA8.unk30 = (1 - D_803F7DA8.unk30);
                if (D_803F7DA8.unk30 == 0) { // SELECT
                    play_sound_effect(SFX_MENU_NAGIVATE_UP, 0, 0x5000, 1.0f, 64);
                }
                if (D_803F7DA8.unk30 == 1) { // COPY
                    play_sound_effect(SFX_UNKNOWN_146, 0, 0x5000, 1.0f, 64);
                }
            }
            // temp_v0_9 = D_803F7DA8.bank;
            if (D_803F7DA8.bank == 0) {
                x_offset = 58;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 1) {
                x_offset = 134;
                y_offset = 88;
            }
            if (D_803F7DA8.bank == 2) {
                x_offset = 58;
                y_offset = 164;
            }
            if (D_803F7DA8.bank == 3) {
                x_offset = 134;
                y_offset = 164;
            }
            draw_rectangle(&D_801D9E7C, (s16) (x_offset - 0x1E), (s16) (y_offset - 0x18), (s16) (x_offset + 0x1C), (s16) (y_offset + 0x14), (u8) 0, (u8) 0, (u8) 0, (u8) 0xA8);
            load_default_display_list(&D_801D9E7C);
            gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);

            select_font(0U, FONT_COMIC_SANS, 0U, 0U);

            if (D_803F7DA8.unk30 == 0) { // SELECT
                set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);
            } else {
                set_menu_text_color(0x80U, 0x80U, 0x80U, 0xFFU);
            }
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_CANCEL), x_offset, (y_offset - 0xC), D_803B74B4_7C8B64, D_803B74B8_7C8B68);

            if (D_803F7DA8.unk30 == 1) { // COPY
                set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);
            } else {
                set_menu_text_color(0x80U, 0x80U, 0x80U, 0xFFU);
            }
            display_text_centered(&D_801D9E7C, get_message_address_by_id(MSG_DELETE2), x_offset, y_offset, D_803B74B4_7C8B64, D_803B74B8_7C8B68);
        }
        break;
    }

    load_default_display_list(&D_801D9E7C);
    select_font(0U, FONT_COMIC_SANS, 1U, 0U);
    set_menu_text_color(0xFFU, 0xFFU, 0xFFU, 0xFFU);

    if ((D_8023F2A0.language == LANG_FRENCH) || (D_8023F2A0.language == LANG_SPANISH)) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17U, 0xD0U, 15.2f, 16.0f, -1);
    } else if ((D_8023F2A0.language == LANG_PORTUGESE) || (D_8023F2A0.language == LANG_JAPANESE)) {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17U, 0xD0U, 10.0f, 16.0f, -1);
    } else {
        func_8012D374(&D_801D9E7C, get_message_address_by_id(MSG_SELECT_A_BANK), 0x17U, 0xD0U, 16.0f, 16.0f, -1);
    }

    vertical_offset = 56;

    // write "Secure Zones"
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_SECURE_ZONES), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    // write "Species"
    vertical_offset += D_803B74B0_7C8B60 + 6.0f;
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_SPECIES), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    // write "Encountered"
    vertical_offset += D_803B74B0_7C8B60;
    display_text(&D_801D9E7C, get_message_address_by_id(MSG_ENCOUNTERED), 264, vertical_offset, D_803B74AC_7C8B5C, D_803B74B0_7C8B60);

    vertical_offset = 56;
    // write ":" for "Secure Zones"
    sprintf(ascii, D_803C03E0_7D1A90, D_803C03E4_7D1A94); // &D_803C03E0_7D1A90,  &D_803C03E4_7D1A94 "%s", ":"
    prepare_text((u8 *) ascii, wide_text);
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write ":" for "Species Encountered"
    vertical_offset += D_803B74B0_7C8B60 + 6;
    vertical_offset += D_803B74B0_7C8B60;
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write ":" for Powercell icon
    vertical_offset += D_803B74B0_7C8B60 + 6;
    func_8012D374(&D_801D9E7C, wide_text, 268, vertical_offset, 12.0f, D_803B74B0_7C8B60, -1);

    // write levels
    vertical_offset = 56;
    sprintf(ascii, D_803C03E8_7D1A98, progress[0]); // levels // "%2d"
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, 12.0f, D_803B74B0_7C8B60);

    vertical_offset += D_803B74B0_7C8B60 + 6;
    vertical_offset += D_803B74B0_7C8B60;

    // write species
    sprintf(ascii, D_803C03EC_7D1A9C, progress[1]); // species // & "%2d"
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, 12.0f, D_803B74B0_7C8B60);

    // write powercells
    vertical_offset += D_803B74B0_7C8B60 + 6;
    sprintf(ascii, D_803C03F0_7D1AA0, progress[2]); // powercells // "%3d"
    prepare_text((u8 *) ascii, wide_text);
    display_text(&D_801D9E7C, wide_text, 300, vertical_offset, D_803B74BC_7C8B6C, D_803B74C0_7C8B70);

    gSPDisplayList(D_801D9E7C++, D_801584A0);
    gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xff, 0xff, 0xff, 0xff);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);
    gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x80);

    // draw powercell
    func_803962EC_7A799C(&D_801D9E7C, 968, (vertical_offset - 2) << 2, 1032, (vertical_offset + 14) << 2, D_800DE390, 32, 32);
    func_8039D034_7AE6E4(&D_801D9E7C, 0);
}

void func_8039BBB8_7AD268(void) {
    s16 level;

    if (D_803F2D50.unkC6 != 0) {
        if (D_803E4D28 & 1) { // souvenir collected
            level = D_803F7DA8.currentLevel + 1;
            if ((level != GIVE_A_DOG_A_BONUS) &&
                (level != WALRACE_64) &&
                (level != EVOS_ESCAPE) &&
                (level != PUNCHUP_PYRAMID) &&
                (level != BIG_CELEBRATION_PARADE)) {
                D_8023F260.level[D_803F2D30.unk8 - 1].trophy = 1;
            }
            // regalloc helper
            if (1) {}
        }
        level = D_803F7DA8.currentLevel + 1;
        if (D_803E4D28 & 2) { // level completed
            if (level == GIVE_A_DOG_A_BONUS) {
                D_8023F260.evoPartsCollected |= EVO_TORSO;
            }
            if (level == WALRACE_64) {
                D_8023F260.evoPartsCollected |= EVO_HEAD;
            }
            if (level == EVOS_ESCAPE) {
                D_8023F260.evoPartsCollected |= EVO_ARMS;
            }
            if (level == PUNCHUP_PYRAMID) {
                D_8023F260.evoPartsCollected |= EVO_LEGS;
            }
        }
        if ((level == GIVE_A_DOG_A_BONUS) ||
            (level == WALRACE_64) ||
            (level == EVOS_ESCAPE) ||
            (level == PUNCHUP_PYRAMID)) {
            if (D_803E4D28 & 2) {
                D_8023F260.level[D_803F2D30.unk8 - 1].completed = 1;
            }
        } else {
            D_8023F260.level[D_803F2D30.unk8 - 1].completed = 1;
            // 'powercells' element used to store 'time' in bonus levels
            if (D_8023F260.level[D_803F2D30.unk8 - 1].powercells < D_803F2D30.powercells) {
                D_8023F260.level[D_803F2D30.unk8 - 1].powercells = D_803F2D30.powercells;
            }
        }
        D_803F2D50.unkC6 = 0;
        memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[D_803F7DA8.bank], 64);
        write_eeprom(D_803F7DA8.bank);

        level = D_803F7DA8.currentLevel + 1;
        if ((level == GIVE_A_DOG_A_BONUS) ||
            (level == WALRACE_64) ||
            (level == EVOS_ESCAPE) ||
            (level == PUNCHUP_PYRAMID)) {
            if (D_803E4D28 & 2) {
                if (level == PUNCHUP_PYRAMID) {
                    // only increment level counter if we have collected all bodyparts
                    if (D_8023F260.evoPartsCollected == (EVO_TORSO | EVO_HEAD | EVO_ARMS | EVO_LEGS)) {
                        D_803F7DA8.currentLevel += 1;
                    }
                } else {
                    D_803F7DA8.currentLevel += 1;
                }
            }
        } else {
            D_803F7DA8.currentLevel += 1;
        }
        // there is no level 32, so trigger end credits
        if (D_803F7DA8.currentLevel == SECRET_LEVEL-1) {
            D_803F7DA8.currentLevel = END_CREDITS-1;
        }
    } else {
        if (D_8023F260.score < D_803F2D30.score) {
            D_8023F260.score = D_803F2D30.score;
        }
        memcpy_sssv((u8*)&D_8023F260, (u8*)&D_8023F2E0[D_803F7DA8.bank], 64);
        write_eeprom(D_803F7DA8.bank);
    }
}

// NON-MATCHING: final function needs some love
#if 0
void func_8039BE98_7AD548(u8 red, u8 green, u8 blue, u8 alpha, s16 start, s16 end, PlayerEeprom *eeprom, s16 xRot, s16 yRot, f32 scale, u8 currentLevel) {

    f32 temp_f22;
    s32 phi_t4;
    s32 phi_t5;
    s16 i;
    s8 *temp_t0;

    D_803F7D60 = (D_803F7D60 + 1) % 100; // pulse

    if (start == 30) {
        if (currentLevel == 30) {
            if (eeprom->level[30].completed == 1) {
                if (D_803F7D60 < 50) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240); // orange (selected)
                }
            } else {
                if (D_803F7D60 < 50) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240); // orange (selected)
                }
            }
        } else if ((D_803F7DFE == 0) && (currentLevel != 0xff)) {
            gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
        } else if (currentLevel == 0xFF) {
            if (eeprom->level[30].completed == 1) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red - 0xF, 0x28, 0x28, 0xFF);
            } else {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 0xFF);
            }
        } else {
            if (eeprom->level[30].completed == 1) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
            } else {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 70);
            }
        }
        func_8039C834_7ADEE4(&D_801D9E7C, D_800BA760, 43, 43, scale, scale, 0, 0, xRot, yRot);
    } else {
        // temp_f22 = scale / 2.0f;

        for (i = start; i < end; i++) {

            temp_t0 = &D_803B71D0[i];
            if (temp_t0[0] < 0) {
                phi_t4 = 1;
            } else {
                phi_t4 = 0;
            }
            if (temp_t0[1] < -1) {
                phi_t5 = 1;
            } else {
                phi_t5 = 0;
            }
            if (i == currentLevel) {
                if (eeprom->level[i].completed == 1) {
                    if (D_803F7D60 < 50) {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                    } else {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240);
                    }
                } else {
                    if (D_803F7D60 < 50) {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                    } else {
                        gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 128, 0, 240);
                    }
                }
            } else if ((D_803F7DE0[i] == 0) && (currentLevel != 0xFF)) {
                gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 20);
            } else if (currentLevel == 0xFF) {
                if (eeprom->level[i].completed == 1) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red + 15, 0, 0, 255);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 255);
                }
            } else {
                if (eeprom->level[i].completed == 1) {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 240);
                } else {
                    gDPSetPrimColor(D_801D9E7C++, 0, 0, red, green, blue, 70);
                }
            }
            func_8039C834_7ADEE4(&D_801D9E7C,
                /* img  */ D_800BB700 + ((temp_t0[4] * 0x4B0)) , // + 0xFA0 + &D_800BA760
                /* width */ temp_t0[2] << 1,
                /* height */ temp_t0[3] << 1,
                /* xscale */ scale / 2.0f,
                /* yscale */ scale / 2.0f,
                /* flipx*/ phi_t4,
                /* flipy*/ phi_t5,
                /* xpos */ (s16) (s32) (xRot + ((f32) temp_t0[0] * scale)),
                /* ypos */ (s16) (s32) (yRot + ((f32) temp_t0[1] * scale))
            );
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ui_main_menu/func_8039BE98_7AD548.s")
#endif

void func_8039C5F8_7ADCA8(s16 arg0, s16 arg1, f32 arg2, PlayerEeprom *eeprom, s16 active) {
    s32 tmp0, tmp1;
    u8 evo_r, evo_g, evo_b, col;

    if (active == 1) {
        evo_r = 200;
        evo_g = 200;
        evo_b = 255;
        col = 255;
    } else {
        evo_r = 60;
        evo_g = 60;
        evo_b = 100;
        col = 128;
    }
    gDPSetPrimColor(D_801D9E7C++, 0, 0, col, col, col, 255);

    tmp0 = arg0 - (21.5f * arg2);
    tmp1 = arg1 - (21.5f * arg2);
    // BIG_CELEBRATION_PARADE
    func_8039BE98_7AD548(evo_r, evo_g, evo_b, 128, 30, 30, eeprom, tmp0, tmp1, arg2, -1);
    // EUROPE
    func_8039BE98_7AD548(evo_r, evo_g, evo_b, 128,  0,  9, eeprom, arg0, arg1, arg2, -1);
    // ICE
    func_8039BE98_7AD548(evo_r, evo_g, evo_b, 128, 10, 16, eeprom, arg0, arg1, arg2, -1);
    // JUNGLE
    func_8039BE98_7AD548(evo_r, evo_g, evo_b, 128, 17, 22, eeprom, arg0, arg1, arg2, -1);
    // DESERT
    func_8039BE98_7AD548(evo_r, evo_g, evo_b, 128, 23, 29, eeprom, arg0, arg1, arg2, -1);
}

// draw sprite
void func_8039C834_7ADEE4(Gfx **dl, s32 src, u16 width, u16 height, f32 scale_x, f32 scale_y, u8 flip_x, u8 flip_y, u16 p_screen_x, u16 p_screen_y) {
    guSprite2DInit(
    /* sprite ptr */    &D_80204278->sprites[D_80204278->usedSprites],
    /* source ptr */    src,
    /* tlut ptr */      0,
    /* stride */        width,
    /* width */         width,
    /* height */        height - 1,
    /* img type */      0,
    /* bitsize */       2,
    /* s */             0,
    /* t */             0);

    gSPSprite2DBase((*dl)++, OS_K0_TO_PHYSICAL(&D_80204278->sprites[D_80204278->usedSprites]));
    gSPSprite2DScaleFlip((*dl)++, 1024.0f / scale_x, 1024.0f / scale_y, flip_x, flip_y);

    gSPSprite2DDraw((*dl)++, p_screen_x * 4, p_screen_y * 4);

    D_80204278->usedSprites += 1;
}

void func_8039CAB8_7AE168(s16 arg0) {
    if (arg0 == 1) {
        draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 40);
    }

    gSPDisplayList(D_801D9E7C++, &D_801584A0);
    gDPPipeSync(D_801D9E7C++);
    gDPSetAlphaCompare(D_801D9E7C++, G_AC_THRESHOLD);

    gDPSetBlendColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
    gDPSetRenderMode(D_801D9E7C++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(D_801D9E7C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
    gDPPipeSync(D_801D9E7C++);

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, 255, 80);

    gDPSetColorDither(D_801D9E7C++, G_CD_NOISE);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_DISABLE);

    func_8039C834_7ADEE4(&D_801D9E7C, D_800BDC80, 320, 36, 1.0f, 1.0f, 0, 0, 0, 12);

    gDPPipeSync(D_801D9E7C++);
}

void get_player_progress(PlayerEeprom *e, s16 *arg1) {
    s16 levels;
    s16 powercells;
    s16 species;
    s16 i;

    levels = species = powercells = 0;

    for (i = 0; i < 31; i++) {
        if (e->level[i].completed) {
            levels += 1;
        }
        if ((i != GIVE_A_DOG_A_BONUS-1) &&
            (i != WALRACE_64-1) &&
            (i != EVOS_ESCAPE-1) &&
            (i != PUNCHUP_PYRAMID-1) &&
            (i != BIG_CELEBRATION_PARADE-1)) {
            powercells += e->level[i].powercells;
        }
    }

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        if (e->speciesSeen[(s8)(i >> 3)] & (1 << (s8)(i % 7))) {
            species += 1;
        }
    }

    arg1[0] = levels;
    arg1[1] = species;
    arg1[2] = powercells;
}

// min/max with tolerance?
f32 func_8039CDE8_7AE498(f32 arg0, f32 arg1) {
    if (((arg1 - 0.25) < arg0) && (arg0 < (arg1 + 0.25))) {
        return arg1;
    } else {
        return arg0;
    }
}

void func_8039CE38_7AE4E8(Gfx **arg0) {
    D_803B66F0.unk0 = 640;
    D_803B66F0.unk2 = 480;
    D_803B66F0.unk8 = 640;
    D_803B66F0.unkA = 480;

    gDPPipeSync((*arg0)++);
    gSPLoadUcode((*arg0)++, &D_8014E300, &D_8015C750);
    gDPPipeSync((*arg0)++);

    load_segments(arg0, D_80204278);

    gSPViewport((*arg0)++, &D_803B66F0);
    gDPSetDepthImage((*arg0)++, osVirtualToPhysical(&D_80100000));
    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gSPDisplayList((*arg0)++, D_01004270);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void func_8039D034_7AE6E4(Gfx **arg0, s16 arg1) {
    if (D_803F66A4 == 0) {
        if (D_803F7D9E == 0) {
            if (RAND(1000) < 10) {
                D_803F7D9E = 1;
            }
        } else {
            D_803F7D9E += 1;
        }

        if ((RAND(2) + 1) < D_803F7D9E) {
            D_803F7D9E = 0;
        }
        if (D_803F7D9C == 0) {
            if (RAND(2000) < 10) {
                D_803F7D9C = 1;
                func_8032CD20_73E3D0(0x283B, 0x74, 0x4000, 0, 1.0f);
            }
        } else {
            D_803F7D9C += 1;
        }
        if ((RAND(5) + 9) < D_803F7D9C) {
            D_803F7D9C = 0;
        }

        if ((D_803F7D9C != 0) || (arg1 != 0)) {
            gDPPipeSync((*arg0)++);
            gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
            gDPSetBlendColor((*arg0)++, 0, 0, 0, 128);
            gDPSetRenderMode((*arg0)++, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_PASS, G_AC_DITHER | CVG_DST_FULL | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);
            gSPClearGeometryMode((*arg0)++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
            gDPSetTexturePersp((*arg0)++, G_TP_NONE);
            gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

            if (arg1 != 0) {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, arg1);

            } else {
                gDPSetPrimColor((*arg0)++, 0, 0, 120, 120, 120, 5);

            }
            gDPPipeSync((*arg0)++);
            gDPFillRectangle((*arg0)++, 0, 0, 320, 239);
            gDPPipeSync(D_801D9E7C++);
        }
    }
}

void render_stars(Gfx **arg0) {
    s16 _i;

    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
    gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (_i = 0; _i < 180; _i++) {
        s16 x, y, i;

        // FIXME: fakematch
        i = _i;
        if (0) {};

        gDPSetPrimColor((*arg0)++, 0, 0, D_800DF220[i].brightness, D_800DF220[i].brightness, D_800DF220[i].brightness, 0);

        D_800DF220[i].x -= D_800DF220[i].speed * D_80204290;
        if (D_800DF220[i].x < 40) {
            // wrap around if moving off left side of screen
            D_800DF220[i].x += 1280;
        }

        x = D_800DF220[i].x;
        y = D_800DF220[i].y * 4;
        gSPTextureRectangle((*arg0)++, x, y, x + 4, y + 4, G_TX_RENDERTILE, 0, 0, 0, 0);
    }

    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
    gDPPipeSync((*arg0)++);
}

void generate_stars(void) {
    s16 i;
    for (i = 0; i < 180; i++) {
        D_800DF220[i].x = RAND(320) * 4;
        D_800DF220[i].y = RAND(240) * 4;
        D_800DF220[i].speed = RAND(4) + 1;
        D_800DF220[i].brightness = (D_800DF220[i].speed * 15) + 70;
    }
}

void determine_available_levels(void) {
    s16 i;
    s16 trophies_collected;

    for (i = 0; i < 31; i++) {
        if (i == 30) {
            if (D_8023F260.evoPartsCollected == (EVO_TORSO | EVO_HEAD | EVO_ARMS | EVO_LEGS)) {
                D_803F7DE0[i] = 1;
            } else {
                D_803F7DE0[i] = 0;
            }
        } else {
            if (D_8023F260.level[i].completed) {
                D_803F7DE0[i] = 1;
            } else {
                D_803F7DE0[i] = 0;
            }
            // if previous level complete, current is available?
            if ((i != 0) && (D_8023F260.level[i-1].completed)) {
                D_803F7DE0[i] = 1;
            }
        }
    }

    // initialise level counts to zero
    D_803F7E00 = D_803F7E02 = D_803F7E04 = D_803F7E06 = 0;

    // first level is always available
    D_803F7DE0[0] = 1;

    // determine europe levels completed
    for (i = 0; i < 10; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E00++;
        }
    }

    // if 3+ europe levels are complete, enable ice biome
    if (D_803F7E00 >= 3) {
        for (i = 10; i < D_803F7E00 + 9; i++) {
            if (i == 10) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 10; i < 17; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E02++;
        }
    }

    // if 3+ ice levels are complete, enable jungle biome
    if (D_803F7E02 >= 3) {
        for (i = 17; i < D_803F7E02 + 16; i++) {
            if (i == 17) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 17; i < 23; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E04++;
        }
    }

    // if 3+ jungle levels are complete, enable desert biome
    if (D_803F7E04 > 2) {
        for (i = 23; i < D_803F7E04 + 22; i++) {
            if (i == 23) {
                D_803F7DE0[i] = 1;
            } else if (D_8023F260.level[i-1].completed) {
                D_803F7DE0[i] = 1;
            }
        }
    }
    for (i = 23; i < 30; i++) {
        if (D_8023F260.level[i].completed) {
            D_803F7E06++; // unused
        }
    }

    trophies_collected = 0;
    for (i = 0; i < 30; i++) {
        if (D_8023F260.level[i].trophy) {
            trophies_collected++;
        }
    }
    // if all trophies collected enable hidden level
    if (trophies_collected >= 26) {
        D_803F7DE0[31] = 1;
    } else {
        D_803F7DE0[31] = 0;
    }

    // check cheats / overrides
    if (D_803F6428.europe) {
        for (i = 0; i < 10; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (D_803F6428.ice) {
        for (i = 10; i < 17; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (D_803F6428.jungle) {
        for (i = 17; i < 23; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (D_803F6428.desert) {
        for (i = 23; i < 30; i++) {
            D_803F7DE0[i] = 1;
        }
    }
    if (D_803F6428.final) {
        D_803F7DE0[30] = 1;
    }
    if (D_803F6428.hidden) {
        D_803F7DE0[31] = 1;
    }
}

// e.g. get_next_available_level(JUNGLE_JUMPS, -1)
s16 get_next_available_level(s16 current_level, s16 offset) {
    s16 level;
    s16 new_level;

    new_level = 99;
    level = current_level + offset;

    while (level != current_level) {
        // can this cause OOB?
        if ((D_803F7DE0[level] != 0) && (new_level == 99)) {
            new_level = level; // found available level?
        }
        level += offset;

        // wraparound
        if (level < 0) {
            level = 31;
        }
        if (level >= 32) {
            level = 0;
        }
    };

    if (new_level != 99) {
        return new_level;
    }
    return current_level;
}

void seconds_to_mins_secs(const s16 seconds, s16 *mins, s16 *secs) {
    s16 _div = seconds / 60;
    *mins = _div;
    *secs = seconds - (s16) (_div * 60);
}

void load_level_title(void) {
    s16 found;
    s16 i;
    s16 *msg;

    found = 0;
    // iterate over each message
    for (i = 0; i < D_803F63C0; i++) {
        msg = &D_803F34C0[(s16)D_803F3330[i]];
        if ((msg[0] == TEXT_CONTROL_CHAR) &&
            (msg[1] == TEXT_NEWLINE)) {
            // we found e.g. <N>Smashing Start
            msg = &msg[2];
            memcpy_sssv((u8*)msg, (u8*)D_803F2D50.titleText, 84);
            found = 1;
        }
    }

    if (found == 0) {
        D_803F2D50.titleText[0] = 304; // ' '
        D_803F2D50.titleText[1] = EOM;
    }
}

// note that levels appear to be in-game order (1-indexed) rather than common.h
// SMASHING_START (level 1) would be considered 0 here
s16 get_biome_for_level(s16 arg0) {
    if ((arg0 >= SMASHING_START-1) && (arg0 < SNOW_JOKE-1)) {
        return UI_EUROPE_BIOME;
    }
    if ((arg0 >= SNOW_JOKE-1) && (arg0 < JUNGLE_JAPES-1)) {
        return UI_ICE_BIOME;
    }
    if ((arg0 >= JUNGLE_JAPES-1) && (arg0 < FUN_IN_THE_SUN-1)) {
        return UI_JUNGLE_BIOME;
    }
    if ((arg0 >= FUN_IN_THE_SUN-1) && (arg0 < BIG_CELEBRATION_PARADE-1)) {
        return UI_DESERT_BIOME;
    }
    // TODO: understand why this is not END_CREDITS-1
    if ((arg0 == BIG_CELEBRATION_PARADE-1) || (arg0 == SECRET_LEVEL-1)) {
        return UI_CITY_BIOME;
    }
}
