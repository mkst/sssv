#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

s16  D_803C0420;
u8   gInitialisationState;
s16  D_803C0424;
s16  D_803C0426;
s16  D_803C0428;
s16  D_803C042A;
struct053 D_803C0430;

// ========================================================
// .text
// ========================================================

void func_80294E50_6A6500(void) {
    s16 width;

    D_80204278->usedModelViewMtxs = 0;
    D_80204278->unk39310 = 0;
    D_80204278->usedSprites = 0;
    D_8028645A = 0;
    // reset a bunch of things
    func_8029F3CC_6B0A7C();

    gRenderMode2 = 0x0000000000112038;
    if (gInitialisationState != 0) {
        gInitialisationState++;
        if (gInitialisationState == 2) {
            draw_rectangle(&D_801D9E7C,                0,                 0,            8, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C, gScreenWidth - 8,                 0, gScreenWidth, 240, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0,                 0, gScreenWidth,   8, 0, 0, 0, 0xFF);
            draw_rectangle(&D_801D9E7C,                0, gScreenHeight - 8, gScreenWidth, 240, 0, 0, 0, 0xFF);
        }
        if (gInitialisationState == 3) {
            init_rumble_pak();
            func_8012A400();
            // copy framebuffer?
            func_803925D0_7A3C80(D_8020428C->framebuffer, (u16*)D_800C5A40);
            D_803F6680.unk0 = 1;
            D_803F6714 = 0;
            gInitialisationState = 0;
            D_803F6680.unk26 = 0;
            D_803F6680.unk2D = 0;
            D_803F6704 = D_8020540C;
            set_tv_mode_normal();
        }
    }
    if (D_80152E98 == 1) {
        func_8038FD74_7A1424();
        D_80152E98 = 0;
    }
    if ((D_803F2AA2 == 3) || (D_803F2AA2 == 4)){
        func_8038E9F8_7A00A8();
        return;
    }

    if (((gControllerInput->button & START_BUTTON) && (D_802912DE == 1) && (D_803F6680.unk0 == 0)) || (D_803F6680.unk26 == 3)) {
        if ((gInputMode == INPUT_MODE_USER) && (D_803C0426 == 0) && (D_8020540C != 1) && (gInitialisationState == 0)) {
            if ((D_803F2D30.unk4 == 0) && (D_803F2D50.unkC6 == 0) && (D_803F2D30.level != END_CREDITS) && ((D_803E4D28 & 16) == 0)) {
                if ((D_803C0420 == 0) || (D_803C0420 >= 11)) {
                    play_sound_effect(SFX_UNKNOWN_127, 0, 0x5000, 1.0f, 64);
                    D_801D9ED4 = 10;
                    trigger_pause_menu();
                }
            }
        }
    }

    if (D_803E4D28 & 0x40) {
        init_rumble_pak();
        func_8012A400(); // receive some messages?
        // swap frame buffer
        memcpy_sssv(
            D_80162658[D_80152EB8].framebuffer,
            D_80162658[D_80152EB8 ^ 1].framebuffer,
            sizeof(gFramebuffer[0]));
        trigger_mission_brief_screen();
        // unset flag
        D_803E4D28 &= ~0x40;
    }

    if ((D_803E4D28 & 0x80) && (D_803C0426 == 0) && (D_80204288 == 10)) {
        D_803C0426 = 1;
        D_803C042A = 0;
    }

    if ((gControllerInput->button & START_BUTTON) &&
        (1 == D_802912DE) && (D_803C0426 == 0) && (D_80204288 == 10) && ((gEepromGlobal.unk8 & 1) == 0)) {
        D_803C0426 = 1;
        D_803C042A = 1;
    }

    if (D_803F6680.unk0 != 0) {
        if (D_803F6680.unk2D == 0) { // is menu loaded?
            // load menu displaylists & decompress a bunch of textures
            func_80398630_7A9CE0();
            D_803F6680.unk2D = 1;
        }
        // main menu code
        func_8038FF68_7A1618();
    } else {
        func_8038F414_7A0AC4();
        D_80204290 = 2;
        width = 320;
        if (gCheats.unk4 == 0) {
            D_803F2D50.unkDA = D_802053E0.screenWidth;
        } else {
            D_803F2D50.unkDA = width;
        }
        gScreenWidth = D_803F2D50.unkDA;
        gScreenHeight = 240;

        get_controller_input();
        if (gControllerInput != NULL) {
            read_controller_input(gControllerInput);
        }

        func_802FDA44_70F0F4();
        func_802FE5E8_70FC98();
        func_802F30A4_704754();

        gSPDisplayList(D_801D9E88++, D_01003498_3CD68);
        gSPDisplayList(D_801D9E88++, D_01004360_3DC30);
        gSPDisplayList(D_801D9E90++, D_01003B70_3D440);
        gSPDisplayList(D_801D9EB8++, D_01003998_3D268);

        gDPSetColorDither(D_801D9E90++, G_CD_NOISE);
        gDPSetAlphaDither(D_801D9E90++, G_AD_DISABLE);

        func_803041FC_7158AC();
        load_segments(&D_801D9E7C, D_80204278);
        switch_to_current_segment(&D_801D9E7C, D_80204278);

        gSPViewport(D_801D9E7C++, &D_80152EA8);

        func_80129430(&D_801D9E7C);

        gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->framebuffer));
        gSPDisplayList(D_801D9E7C++, D_01004270_3DB40);

        gSPClipRatio(D_801D9E7C++, FRUSTRATIO_3);

        func_8032F950_741000();
        func_802999E0_6AB090(D_80204278);
        func_80299AA8_6AB158(D_80204278, &D_801D9E7C);
        set_fog_position_and_color(&D_801D9E7C);
        func_802C87E0_6D9E90();
        if (func_8038CCC0_79E370() != 0) {
            D_803E4D28 |= 0x20; // add flag
        } else {
            D_803E4D28 &= ~0x20; // remove flag
        }
        if (D_803F671C != 0) {
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
            draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 2);
            D_803F671C += 1;
            if (D_803F671C > 2) {
                D_803F671C = 0;
            }
        }
        func_802B3EC0_6C5570(&D_801D9E7C, ((D_803F28D0[0] & 0xC0) >> 6), D_803F2C3C, D_803F2C40, D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.xPos.h, D_801D9ED8.animals[gCurrentAnimalIndex].animal->position.zPos.h);
        if ((gInitialisationState == 0) && (gInputMode == INPUT_MODE_USER) && (D_803F2D30.level != DMA_INTRO)) {
            func_80349DCC_75B47C(1);
        }

        gSPDisplayList(D_801D9E7C++, &D_80204278->unk267A0);
        func_8029877C_6A9E2C();
        D_803F2D50.unk18 = 1; //D_803F2D68 = 1;
        if (0) {};
        D_803C0430.unk20F += 1;
        D_803C0430.unk20F &= 7;
        if (D_803C0430.unk20F == 0) {
            // process collision map
            func_8029726C_6A891C(&D_803C0740);
            func_80296C8C_6A833C(&D_803C0740);
        }
        func_802B4D20_6C63D0();
        func_802FA6D8_70BD88();
        func_80397840_7A8EF0();
        func_802DA7F0_6EBEA0();
        func_802D6738_6E7DE8();
        func_802CB394_6DCA44(D_80204278);

        D_80152EA8.vp.vscale[0] = gScreenWidth  << 1;
        D_80152EA8.vp.vscale[1] = gScreenHeight << 1;
        D_80152EA8.vp.vtrans[0] = gScreenWidth  << 1;
        D_80152EA8.vp.vtrans[1] = gScreenHeight << 1;

        func_802DE950_6F0000();
        func_802C8878_6D9F28();
        func_802E072C_6F1DDC(0);

        gSPDisplayList(D_801D9E7C++, &D_80204278->unk9600);

        gRenderMode2 = 0x0000000000110038;
        func_8029F7D4_6B0E84(D_80204278, &D_801E9EB8);
        func_8029A720_6ABDD0();
        set_fog_position_and_color(&D_801D9E7C);

        gSPDisplayList(D_801D9E7C++, &D_80204278->unkBB80);

        if ((gControllerInput != NULL) && (D_801D9ED4 == 0) && (gControllerInput->button & L_TRIG)) {
            D_801D9ED4 = 10;
        }
        set_fog_position_and_color(&D_801D9E7C);
        if ((D_803F2AA2 != 2) || (D_803F6468 >= 7)) {
            func_80299B68_6AB218(D_80204278);
        }
        func_80297628_6A8CD8(&D_803C0740, D_80204278);

        gSPDisplayList(D_801D9E7C++, D_01003A58_3D328);
        gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
        gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

        if (D_803F2D10.unk0 < 2) {
            func_802D5AD8_6E7188(0, 1);
        }
        func_80299E84_6AB534(D_80204278);

        gSPDisplayList(D_801D9E7C++, &D_80204278->unkDAC0);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unk7D00);
        gSPDisplayList(D_801D9E7C++, &D_01004360_3DC30);

        gDPSetColorDither(D_801D9E7C++, G_CD_NOISE);
        gDPSetAlphaDither(D_801D9E7C++, G_AD_DISABLE);
        gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
        gSPTexture(D_801D9E7C++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);

        if (D_803F2D10.unk0 < 2) {
            func_802D5AD8_6E7188(1, 8);
        }
        gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
        gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);

        func_8029BB94_6AD244();
        func_803572F0_7689A0(); // check health?
        func_80357480_768B30(); // check if level failed
        func_80357438_768AE8(); // load game(?) after delay?
        display_trails();
        func_802FF25C_71090C();

        if (D_803F63C2 != 0) {
            // this function is empty
            func_8037D32C_78E9DC(&D_803B5764, D_803F63C2 + 1, 25, gScreenWidth - 25, gScreenHeight - 100);
        }
        if (gInitialisationState == 0) {
            if (gInputMode == INPUT_MODE_USER) {
                if (D_803F2D30.level != DMA_INTRO) {
                    func_80349DCC_75B47C(0);
                }
            } else if (gControllerConnected != 0) {
                load_default_display_list(&D_801D9E7C);
                set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
                select_font(0, FONT_COMIC_SANS, 1, 0);
                func_8012EB4C(&D_801D9E7C, D_80204368, gScreenWidth / 2, 200, 16.0f, 16.0f, 16);
            }
        }

        gDPPipeSync(D_801D9E7C++);
        gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
        gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x00, 0x00, 0x00);
        gDPSetRenderMode(D_801D9E7C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPFillRectangle(D_801D9E7C++, 23, 186, 117, 221);

        // re-orient camera?
        func_80299140_6AA7F0();

        gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

        if (D_803C0420 != 0) {
            if (D_803C0420 == 1) {
                func_803497DC_75AE8C();
                func_80349720_75ADD0();
            }
            D_803C0420++;
            D_803C0420 = D_803C0420 & 0x7F;
        }
        if (D_803F6680.unk27 != 0) {
            load_data_section(D_803F2D50.segment);
            load_level_texture_data(D_803F2D50.segment, D_803F2D50.unk52);
            load_water_texture();
            D_803F6680.unk27 = 0;
            D_803F6680.unk2D = 0;
            if (D_803F6704 != 0) { // if widescreen?
                set_tv_mode_widescreen();
            }
        }
        if (D_8028645A == 0) {
            D_8015517C = 0.0f;
        }
        if ((gCurrentMusicTrack == MUSIC_TRACK_LEVEL_FAILED) || (gCurrentMusicTrack == MUSIC_TRACK_LEVEL_PASSED) || (gCurrentMusicTrack == MUSIC_TRACK_BOSS_LEVEL_PASSED)) {
            D_8015517C = 1.0f;
            D_801546D8 = (u16)0x800;
        }
        if (D_803C0426 != 0) {
            if (D_803C0426 == 2) {
                stop_all_sounds();
            }
            if (D_803C0426 == 1) {
                if (D_803C042A == 0) {
                    reset_screen_transition();
                    trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
                }
                if (D_803C042A == 1) {
                    D_803C0426 = 13;
                }
                gCurrentMusicTrack = NO_MUSIC;
                D_803C0426 += 1;
            } else if (++D_803C0426 > 16) {
                D_80204284 = 3;
                D_80152E90 = 1; // select menu overlay
            }
        }
        if (gInputMode == INPUT_MODE_DISABLED) {
            if (D_803C0424 == 0) {
                func_8013385C(8.0f, 20.0f, 0);
                func_801337DC(0, 8.0f, 20.0f, 0);
                trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
                D_803C0424 = 1;
            } else {
                if (++D_803C0424 > 13) {
                    D_80204284 = 3;
                    D_80152E90 = 1; // select menu overlay
                    gCurrentMusicTrack = NO_MUSIC;
                }
            }
        }
        func_801375E8(0);
    }

    check_cheats(gControllerInput);
    perform_screen_transition();
    if ((D_803C0426 != 0) && (D_803C042A == 1)) {
        draw_rectangle(&D_801D9E7C, 0, 0, 320, 240, 0, 0, 0, 0xFF);
    }
    if ((D_803F2D30.level == END_CREDITS) && (D_803F6680.unk0 == 0)) {
        if (D_803C0428 != 0) {
            if (++D_803C0428 > 19) {
                gCurrentMusicTrack = NO_MUSIC;
                D_80204284 = 3;
                D_80152E90 = 1; // select menu overlay
            }
        } else if (display_credits() == 1) {
            D_803C0428 = 1;
            func_8013385C(6.0f, 20.0f, 0);
            func_801337DC(0, 6.0f, 20.0f, 0);
            trigger_screen_transition(TRANSITION_FADE_OUT_BLK);
        }
    }
    D_801552B4 = 0;
    D_801552B0 = 0;
}

void reset_player_progress(void) {
    D_803F2D30.unkA = 3; // only place this value is used?
    D_803F2D30.unk4 = 0;

    D_803F2D10.unk0 = 0;
    D_803F2D10.unk1 = 0;
    D_803F2D10.unk2 = 0;
    D_803F2D10.unk3 = 0;

    D_803F2D50.unkC6 = 0;
    D_803F2D50.unkC4 = 1;

    D_8020427C = 0;

    D_803F2D30.powercells = 0;
}

// unused?
void reset_player_health(void) {
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = 0x7F;
    D_803F2CE8 = 0;
    D_8020427C = 1;
}

void func_802961D4_6A7884(void) {
    func_8012A400(); // synchronise?
    load_ingame_objects();
    load_water_texture();
    gInitialisationState = 0;
    D_803F6680.unk4 = 0;
    D_8028645A = 0;
    D_8015517C = 0.0f;
    gCurrentMusicTrack = NO_MUSIC;
    D_803F2D50.unkDA = 320;
    D_803F2D50.unkDC = 0;

    gRenderMode1 = 0xFFFFFFFFC8000000;
    gRenderMode2 = 0x0000000000112038;
    gGeometryMode = G_FOG;

    load_objects();
    func_802C9834_6DAEE4();
    func_80296544_6A7BF4(); // init_cosine_tables
    reset_particles();
    func_80304170_715820(); // empty function
    func_80304194_715844(); // zero out texture size data?
    load_level_data(D_803F2D30.level);
    D_80204280 = D_803F2D30.level;
    D_803F2D30.unk4 = 0;
    func_80296310_6A79C0();
    func_802B3FAC_6C565C();
    D_803F2D50.evoSuitColor = get_evo_suit_color();
    D_803F2D50.unkDC = 1;
    set_tv_mode_normal();
    gTasksCompleted = 0;
}

void func_80296310_6A79C0(void) {
    D_803C0420 = 1;
}

s32 get_evo_suit_color(void) {
    s16 powercells;
    s16 i;
    s32 color;

    powercells = 0;

    for (i = 1; i < 32; i++) {
        if ((i != GIVE_A_DOG_A_BONUS) &&
            (i != WALRACE_64) &&
            (i != EVOS_ESCAPE) &&
            (i != PUNCHUP_PYRAMID) &&
            (i != BIG_CELEBRATION_PARADE)) {
                powercells += D_8023F260.level[i-1].powercells;
            }
    }
    if (powercells < 200) {
        color = EVO_BRONZE_SHELLSUIT;
    } else if (powercells < 390) {
        color = EVO_SILVER_SHELLSUIT;
    } else {
        color = EVO_GOLD_SHELLSUIT;
    }

    return color;
}
