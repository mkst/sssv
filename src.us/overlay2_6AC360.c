#include <ultra64.h>
#include "common.h"


void func_8029ACB0_6AC360(void) {
}

s32 func_8029ACB8_6AC368(s32 arg0, s32 arg1) {
    return 1;
}

extern struct063 D_80100000_X[][0x81];

// loops, initialising vertexes / level data
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029ACC8_6AC378.s")
// void func_8029ACC8_6AC378(void) {
//     s32 i, j;
//
//     // writes to 803C17A0
//     // 00280000 03000000 00280000 03000000
//     // 00280000 03000000 00280000 03000000
//
//     // copy in the vertexes
//     // D_803C0740 to D_803D1DA8 == ?
//     for (i = 0; i < 4; i++) {
//         for (j = 1; j < 0x81; j++) {
//             D_803C0740[i+4][j+8] = D_80100000_X[i][j];
//         }
//     }
//     // D_803C0740 to D_803D2980 == 72 lots of 0x408
//     for (i = 0; i < 72; i++) {
//         for (j = 0; j < 0x80; j++) {
//             D_803C0740[i][j].unk6 *= 2;//D_803C0740[i][j].unk6 * 2;
//         }
//     }
//
//     // force some opacity?
//     // D_803D0740 to D_803D0B40 == 1 iteration?
//     for (j = 0; j < 0x80; j++) {
//         D_803C0740[i][j].unk0 = 0xFF;
//     }
//
//     // who knows
//     // D_803C0740 to D_803D2980 (+ 0x1020) is 18 loops
//     for (i = 0; i < 18; i += 4) {
//         for (j = 0; j < 0x81; j++) {
//             // 63 =
//             D_803C0740[i][j].unk7 = D_803C0740[i][j].unk7 | 0x44;
//             D_803C0740[i][j+1].unk7 = D_803C0740[i][j+1].unk7 | 0x88;
//             D_803C0740[i][j+2].unk7 = 0x80;
//             D_803C0740[i][j+3].unk7 = 0xF0;
//         }
//     }
// }

// file split?

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B000_6AC6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC360/func_8029B56C_6ACC1C.s")

s16 distance_from_player(s16 x, s16 z, s16 y) {
    Animal *a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    return ABS(x - a->xPos) + ABS(z - a->zPos) + ABS(y - a->yPos);
}
