#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/hilites/func_8034A320_75B9D0.s")
// NON-MATCHING: something along these lines..
// void func_8034A320_75B9D0(void) {
//     Mtx m;
//
//     if (D_80204278->usedHilites < 100) {
//         guLookAtHilite(&m, &D_80204278->lookAts[D_80204278->usedHilites], &D_80204278->hilites[D_80204278->usedHilites],
//             D_803F2C44, D_803F2C48, D_803F2C4C,
//             /* these are lw not lh instructions, does D_803D5530 contain a union or is it a different struct entirely? */
//             ((f32)D_803D5530->xPos / 65536.0), ((f32)D_803D5530->zPos / 65536.0), ((f32)D_803D5530->yPos / 65536.0),
//             D_80204200, D_80204204, D_80204208,
//             -60.0f, 0.0f, 60.0f,
//             -60.0f, 0.0f, 60.0f,
//             32, 32);
//
//         gSPLookAtX(D_801D9E88++, (s32)&D_80204278->lookAts[D_80204278->usedHilites] & 0x1FFFFFFF);
//         gSPLookAtY(D_801D9E88++, (s32)&D_80204278->lookAts[D_80204278->usedHilites] & 0x1FFFFFFF);
//         gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE,
//             (s32)&D_80204278->hilites[D_80204278->usedHilites + 1], (s32)&D_80204278->hilites[D_80204278->usedHilites],
//             (s32)&D_80204278->hilites[D_80204278->usedHilites + 1] + 0x7C, (s32)&D_80204278->hilites[D_80204278->usedHilites] + 0x7C); //  + 0x7C
//
//         D_80204278->usedHilites += 1;
//     } else { // "Sorry, no more space for extra usedHilites\n"
//         rmonPrintf(D_803BE9A0);
//     }
// }
