#include <ultra64.h>
#include "common.h"


void reset_cheats(void)
{
    D_803B62B0 = 0;
    D_803B62B4 = 0;
    D_803B62B8 = 0;
    D_803B62BC = 0;
    D_803F6428.unk0 = 0;
    D_803F6428.unk2 = 0;
    D_803F6428.unk4 = 0;
    D_803F6428.unk6 = 0;
    D_803F6428.unk8 = 0;
    D_803F6428.europe = 0;
    D_803F6428.ice = 0;
    D_803F6428.jungle = 0;
    D_803F6428.desert = 0;
    D_803F6428.final = 0;
    D_803F6428.hidden = 0;
    D_803F6428.unk16 = 0;
    D_803F6428.unk18 = 0;
    sprintf(D_803F6410, "%9d", 111111111);
}

void check_cheats(OSContPad *contPad) {
    u16 lastButton;
    u16 butDown;
    u32 butDown2;
    s16 sp28[60]; // long enough...

    if (D_803F6428.unk6 != 0) {
        load_default_display_list(&D_801D9E7C);
        set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
        select_font(0, 0, 0, 0);
        if ((D_803F6428.unk6 != 0) && (D_803F6680.unk0 == 0)) {
            // print debug location
            sprintf(D_802042B0, "(%3d  %3d  %4d)",
                D_801DDD8C[gCurrentAnimalIndex].unk0->xPos >> 6,
                D_801DDD8C[gCurrentAnimalIndex].unk0->zPos >> 6,
                D_801DDD8C[gCurrentAnimalIndex].unk0->yPos);
            prepare_text(D_802042B0, sp28);
            func_8012DEF8(&D_801D9E7C, sp28, gScreenWidth - 20, 20, 16.0f, 16.0f);
            prepare_text("Ver - 1.37", sp28);
            func_8012DEF8(&D_801D9E7C, sp28, gScreenWidth - 20, 36, 16.0f, 16.0f);
        }
    }
    // reset
    lastButton = 0;
    // button debounce
    if (D_803B62BC != 0) {
        D_803B62BC--;
    }
    // TODO: can this be simplified and still match?
    butDown = contPad->button;
    butDown2 = butDown;
    if ((D_803B62B4 == 0) && (butDown2 == 0)) {
        D_803B62B4 = 1;
        return;
    } else if (butDown2 != 0) {
        D_803B62B4 = 0;
    }

    if ((D_803B62BC == 0) && (butDown2 != 0) && (D_803B62C0 != butDown)) {
        u16 down = butDown;
        if (D_80204290 == 1) {
            D_803B62BC = 12;
        } else {
            D_803B62BC = 6;
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
        D_803B62C0 = lastButton;
    }

    // if key pressed
    if (lastButton != 0) {
        // increment position
        if (++D_803B62B0 >= 20) { // store last 20 values
            // wrap back to start
            D_803B62B0 = 0;
        }
        D_803F6410[D_803B62B0] = lastButton;
    }
    if (check_cheat_code(D_803F6410, "WIZDIZWE")) {
        D_801DDD8C[gCurrentAnimalIndex].unk0->health = 127;
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803B62B0 = 0; // reset cursor position
    }
    if (check_cheat_code(D_803F6410, "UDIZDUZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.europe = 1 - D_803F6428.europe;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDZIDEZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.ice = 1 - D_803F6428.ice;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDWZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.jungle = 1 - D_803F6428.jungle;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDLZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.desert = 1 - D_803F6428.desert;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "UDIZDRZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.final = 1 - D_803F6428.final;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "DUZIDLZD")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        D_803F6428.hidden = 1 - D_803F6428.hidden;
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "UIZDLZDU")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        func_8032AC98_73C348(); // "funny effect 1"
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "IDZIDUIL")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        func_8032AE34_73C4E4(); // "funny effect 2"
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "ZDUIRILR")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        func_8032AEA0_73C550(); // "funny effect 3"
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "LRZILZRL")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        func_8032B084_73C734();  // "funny effect 4"
        D_803B62B0 = 0;
    }
    if (check_cheat_code(D_803F6410, "DANISIL\0")) {
        play_sound_effect(86, 0, 0x5000, 1.0f, 64);
        func_8032B1C8_73C878();  // "disable wallrace cam?"
        D_803B62B0 = 0;
    }
}

s32 check_cheat_code(const u8 *buttonPresses, const char *cheatCode) {
    s16 i;
    s16 len;
    s16 res;
    s16 idx;

    len = strlen2(cheatCode);

    res = 1;
    for (i = 0; i < len; i++) {
        idx = D_803B62B0 - i;
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
    sprintf(D_803F6410, "%9d", 111111111);
    return 1;
}
