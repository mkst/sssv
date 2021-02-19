#include <ultra64.h>
#include "common.h"


void func_8038BA30_79D0E0(void)
{
    D_803B62B0 = 0;
    D_803B62B4 = 0;
    D_803B62B8 = 0;
    D_803B62BC = 0;
    D_803F6428[0] = 0;
    D_803F6428[1] = 0;
    D_803F6428[2] = 0;
    D_803F6428[3] = 0;
    D_803F6428[4] = 0;
    D_803F6428[5] = 0;
    D_803F6428[6] = 0;
    D_803F6428[7] = 0;
    D_803F6428[8]  = 0;
    D_803F6428[9]  = 0;
    D_803F6428[10]  = 0;
    D_803F6428[11]  = 0;
    D_803F6428[12]  = 0;
    // "%9d"
    sprintf(&D_803F6410, &D_803BFAA0, 111111111);
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/cheats/func_8038BAC0_79D170.s")
// void func_8038BAC0_79D170(u16 *buttonMaskPtr) {
//     s32 sp28;
//     u16 butDown;
//     Animal *player;
//     u8 lastButton;
//
//     if (D_803F642E != 0) {
//         func_8012C1F0(&D_801D9E7C);
//         set_menu_text_color(0xFF, 0xFF, 0, 0xFF); // yellow
//         select_font(0, 0, 0, 0);
//         if ((D_803F642E != 0) && (D_803F6680 == 0)) {
//             // print debug location
//             player = D_801DDD8C[gCurrentAnimalIndex].unk0;
//             // "(%3d  %3d  %4d)"
//             sprintf(&D_802042B0, D_803BFAA4, player->xPos >> 6, player->zPos >> 6, player->yPos);
//             func_801308B4(&D_802042B0, &sp28);
//             func_8012DEF8(&D_801D9E7C, &sp28, gScreenWidth - 20, 20, 16.0f, 16.0f);
//             func_801308B4(&D_803BFAB4, &sp28);
//             func_8012DEF8(&D_801D9E7C, &sp28, gScreenWidth - 20, 36, 16.0f, 16.0f);
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
//     if ((D_803B62BC == 0) && (butDown) && (butDown != D_803B62C0)) {
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
//     if (D_803B62C0 != 0)
//     {
//         // increment position
//         D_803B62B0 += 1;
//         if (D_803B62B0 >= 20) // store last 20 values
//         {
//             // wrap back to start
//             D_803B62B0 = 0;
//         }
//         D_803F6410[D_803B62B0] = D_803B62C0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFAC0) != 0) {
//         D_801DDD8C[gCurrentAnimalIndex].unk0->health = (u16)127;
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803B62B0 = 0; // reset cursor position
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFACC) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6432 = 1 - D_803F6432;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFAD8) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6434 = 1 - D_803F6434;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFAE4) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6436 = 1 - D_803F6436;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFAF0) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F6438 = 1 - D_803F6438;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFAFC) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F643A = 1 - D_803F643A;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB08) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         D_803F643C = 1 - D_803F643C;
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB14) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AC98_73C348();
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB20) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AE34_73C4E4();
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB2C) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032AEA0_73C550();
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB38) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032B084_73C734();
//         D_803B62B0 = 0;
//     }
//     if (func_8038C13C_79D7EC(&D_803F6410, D_803BFB44) != 0) {
//         func_8013307C(0x56, 0, 0x5000, 1.0f, 64);
//         func_8032B1C8_73C878();
//         D_803B62B0 = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/cheats/func_8038C13C_79D7EC.s")
