#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F6410 to D_803F6450)
// ========================================================

static u8   D_803F6410[20];
Cheats  gCheats;

// ========================================================
// .text
// ========================================================

void reset_cheats(void) {
    D_803B62B0_7C7960 = 0;
    gCheatInputNeutralLatch = 0;
    D_803B62B8_7C7968 = 0;
    gCheatInputDebounceTimer = 0;
    gCheats.unk0 = 0;      // unused?
    gCheats.unk2 = 0;      // unused
    gCheats.unk4 = 0;      // always 0? checked in func_80294E50_6A6500
    gCheats.debugMode = 0;
    gCheats.unk8 = 0;      // unused
    gCheats.europe = 0;
    gCheats.ice = 0;
    gCheats.jungle = 0;
    gCheats.desert = 0;
    gCheats.bcp = 0;
    gCheats.hidden = 0;
    gCheats.unk16 = 0;     // unused
    gCheats.unk18 = 0;     // unused
    sprintf((char*)D_803F6410, "%9d", 111111111);
}

void check_cheats(OSContPad *contPad) {
    u16 lastButton;
    u16 butDown;
    u32 butDown2;
    s16 sp28[60]; // long enough...

    if (gCheats.debugMode != 0) {
        load_default_display_list(&gMainDL);
        set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
        select_font(0, FONT_DEFAULT, 0, 0);
        if ((gCheats.debugMode != 0) && (gOverlayMenuState.unk0 == 0)) {
            // print debug location
            sprintf(gDebugTextBuffer, "(%3d  %3d  %4d)",
                gAnimalState.animals[gCurrentAnimalIndex].animal->position.xPos.h >> 6,
                gAnimalState.animals[gCurrentAnimalIndex].animal->position.zPos.h >> 6,
                gAnimalState.animals[gCurrentAnimalIndex].animal->position.yPos.h);
            prepare_text((u8*)gDebugTextBuffer, sp28);
            display_text(&gMainDL, sp28, gScreenWidth - 20, 20, 16.0f, 16.0f);
            prepare_text((u8*)"Ver - 1.37", sp28);
            display_text(&gMainDL, sp28, gScreenWidth - 20, 36, 16.0f, 16.0f);
        }
    }
    // reset
    lastButton = 0;
    // button debounce
    if (gCheatInputDebounceTimer != 0) {
        gCheatInputDebounceTimer--;
    }
    // TODO: can this be simplified and still match?
    butDown = contPad->button;
    butDown2 = butDown;
    if ((gCheatInputNeutralLatch == 0) && (butDown2 == 0)) {
        gCheatInputNeutralLatch = 1;
        return;
    } else if (butDown2 != 0) {
        gCheatInputNeutralLatch = 0;
    }

    if ((gCheatInputDebounceTimer == 0) && (butDown2 != 0) && (gCheatLastButtonCode != butDown)) {
        u16 down = butDown;
        if (gFrameStepDivisor == 1) {
            gCheatInputDebounceTimer = 12;
        } else {
            gCheatInputDebounceTimer = 6;
        }
        if (down & CONT_A) {
            lastButton = 'A';
        }
        if (down & CONT_B) {
            lastButton = 'B';
        }
        if (down & CONT_UP) {
            lastButton = 'U';
        }
        if (down & CONT_DOWN) {
            lastButton = 'D';
        }
        if (down & CONT_LEFT) {
            lastButton = 'L';
        }
        if (down & CONT_RIGHT) {
            lastButton = 'R';
        }
        if (down & U_CBUTTONS) {
            lastButton = 'N';
        }
        if (down & D_CBUTTONS) {
            lastButton = 'S';
        }
        if (down & L_CBUTTONS) {
            lastButton = 'W';
        }
        if (down & R_CBUTTONS) {
            lastButton = 'E';
        }
        if (down & Z_TRIG) {
            lastButton = 'Z';
        }
        if (down & L_TRIG) {
            lastButton = 'I';
        }
        if (down & R_TRIG) {
            lastButton = 'T';
        }
        gCheatLastButtonCode = lastButton;
    }

    // if key pressed
    if (lastButton != 0) {
        // increment position
        if (++D_803B62B0_7C7960 >= 20) { // store last 20 values
            // wrap back to start
            D_803B62B0_7C7960 = 0;
        }
        D_803F6410[D_803B62B0_7C7960] = lastButton;
    }
    if (check_cheat_code(D_803F6410, "WIZDIZWE")) {
        gAnimalState.animals[gCurrentAnimalIndex].animal->Info.health = 127;
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        D_803B62B0_7C7960 = 0; // reset cursor position
    }
    if (check_cheat_code(D_803F6410, "UDIZDUZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.europe = 1 - gCheats.europe;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDZIDEZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.ice = 1 - gCheats.ice;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDWZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.jungle = 1 - gCheats.jungle;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDLZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.desert = 1 - gCheats.desert;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDRZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.bcp = 1 - gCheats.bcp;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "DUZIDLZD")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        gCheats.hidden = 1 - gCheats.hidden;
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "UIZDLZDU")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        cheat_activate_scale_pulse_effect(); // "funny effect 1"
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "IDZIDUIL")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        cheat_activate_energy_camera_effect(); // "funny effect 2"
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "ZDUIRILR")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        cheat_activate_big_head_effect(); // "funny effect 3"
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "LRZILZRL")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        cheat_toggle_mystery_bear();  // "funny effect 4"
        D_803B62B0_7C7960 = 0;
    }
    if (check_cheat_code(D_803F6410, "DANISIL\0")) {
        play_sound_effect(SFX_CHEAT_ENABLED, 0, 0x5000, 1.0f, 64);
        cheat_clear_camera_effects();  // "disable walrace cam?"
        D_803B62B0_7C7960 = 0;
    }
}

s32 check_cheat_code(const u8 *buttonPresses, const char *cheatCode) {
    s16 i;
    s16 len;
    s16 res;
    s16 idx;

    len = strlen_sssv((u8*)cheatCode);

    res = 1;
    for (i = 0; i < len; i++) {
        idx = D_803B62B0_7C7960 - i;
        if (idx < 0) {
            idx += 10; // wrap around
        }
        if (buttonPresses[idx] != (u8)cheatCode[len - i - 1]) {
            i = 100; // bust out of loop
            res = 0;
        }
    }

    if (res == 0) { // user has not entered a cheat code sequence
        return 0;
    }
    sprintf((char*)D_803F6410, "%9d", 111111111);
    return 1;
}
