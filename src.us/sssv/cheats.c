#include <ultra64.h>
#include "common.h"


void func_8038BA30_79D0E0(void)
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
    D_803F6428.desert  = 0;
    D_803F6428.final  = 0;
    D_803F6428.hidden  = 0;
    D_803F6428.unk16  = 0;
    D_803F6428.unk18  = 0;
    // "%9d"
    sprintf(&D_803F6410, &D_803BFAA0, 111111111);
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/cheats/func_8038BAC0_79D170.s")
// closer but not there yet...
// void func_8038BAC0_79D170(u16 *buttonMaskPtr) {
//     u16 lastButton;
//     u16 butDown;
//     Animal *player;
//     u16 sp28[60]; // TBD how long this needs to be
//
//     if (D_803F6428.unk6 != 0) {
//         func_8012C1F0(&D_801D9E7C);
//         set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
//         select_font(0, 0, 0, 0);
//         if ((D_803F6428.unk6 != 0) && (D_803F6680.unk0 == 0)) {
//             // print debug location
//             player = D_801DDD8C[gCurrentAnimalIndex].unk0;
//             // "(%3d  %3d  %4d)"
//             sprintf(&D_802042B0, D_803BFAA4, player->xPos >> 6, player->zPos >> 6, player->yPos);
//             func_801308B4(&D_802042B0, sp28);
//             func_8012DEF8(&D_801D9E7C, sp28, gScreenWidth - 20, 20, 16.0f, 16.0f);
//             func_801308B4(&D_803BFAB4, sp28);
//             func_8012DEF8(&D_801D9E7C, sp28, gScreenWidth - 20, 36, 16.0f, 16.0f);
//         }
//     }
//
//     // button debounce
//     if (D_803B62BC != 0) {
//         D_803B62BC--;
//     }
//     butDown = *buttonMaskPtr;
//     if ((D_803B62B4 == 0) && (butDown == 0)) {
//         D_803B62B4 = 1;
//         return;
//     }
//     if (butDown != 0) {
//         D_803B62B4 = 0;
//     }
//
//     lastButton = 0;
//     if ((D_803B62BC == 0) && (butDown != 0) && (butDown != D_803B62C0)) {
//         if (D_80204290 == 1) {
//             D_803B62BC = 12;
//         } else {
//             D_803B62BC = 6;
//         }
//         if (butDown & CONT_A) {
//             lastButton = 'A';
//         }
//         if (butDown & CONT_B) {
//             lastButton = 'B';
//         }
//         if (butDown & CONT_UP) {
//             lastButton = 'U';
//         }
//         if (butDown & CONT_DOWN) {
//             lastButton = 'D';
//         }
//         if (butDown & CONT_LEFT) {
//             lastButton = 'L';
//         }
//         if (butDown & CONT_RIGHT) {
//             lastButton = 'R';
//         }
//         if (butDown & U_CBUTTONS) {
//             lastButton = 'N';
//         }
//         if (butDown & D_CBUTTONS) {
//             lastButton = 'S';
//         }
//         if (butDown & L_CBUTTONS) {
//             lastButton = 'W';
//         }
//         if (butDown & R_CBUTTONS) {
//             lastButton = 'E';
//         }
//         if (butDown & Z_TRIG) {
//             lastButton = 'Z';
//         }
//         if (butDown & L_TRIG) {
//             lastButton = 'I';
//         }
//         if (butDown & R_TRIG) {
//             lastButton = 'T';
//         }
//         D_803B62C0 = lastButton;
//     }
//
//     // if key pressed
//     if (lastButton != 0) {
//         // increment position
//         D_803B62B0 += 1;
//         if (D_803B62B0 >= 20) { // store last 20 values
//             // wrap back to start
//             D_803B62B0 = 0;
//         }
//         D_803F6410[D_803B62B0] = lastButton;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFAC0)) {
//         D_801DDD8C[gCurrentAnimalIndex].unk0->health = 127;
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803B62B0 = 0; // reset cursor position
//     }
//     if (check_cheat_code(D_803F6410, D_803BFACC)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.europe = 1 - D_803F6428.europe;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFAD8)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.ice = 1 - D_803F6428.ice;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFAE4)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.jungle = 1 - D_803F6428.jungle;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFAF0)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.desert = 1 - D_803F6428.desert;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFAFC)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.final = 1 - D_803F6428.final;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB08)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6428.hidden = 1 - D_803F6428.hidden;
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB14)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AC98_73C348(); // "funny effect 1"
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB20)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AE34_73C4E4(); // "funny effect 2"
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB2C)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AEA0_73C550(); // "funny effect 3"
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB38)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032B084_73C734();  // "funny effect 4"
//         D_803B62B0 = 0;
//     }
//     if (check_cheat_code(D_803F6410, D_803BFB44)) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032B1C8_73C878();  // "disable wallrace cam?"
//         D_803B62B0 = 0;
//     }
// }

s32 check_cheat_code(u8 *buttonPresses, u8 *cheatCode) {
    s16 i;
    s16 len;
    s16 res;
    s16 idx;

    len = func_80128DD0(cheatCode);

    res = 1;
    for (i = 0; i < len; i++) {
        idx = D_803B62B0 - i;
        if (idx < 0) {
            idx += 10; // wrap around
        }
        if (buttonPresses[idx] != cheatCode[len - i - 1]) {
            i = 100; // bust out of loop
            res = 0;
        }
    }

    if (res == 0) { // user has not entered a cheat code sequence
        return 0;
    }
    sprintf(&D_803F6410, D_803BFB50, 111111111);
    return 1;
}
