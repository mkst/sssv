#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63ED30/func_80299E00_63ED30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63ED30/func_8029A144_63F074.s")
// void func_8029A144_63F074(s32 *arg0, s32 *arg1) {
//     u8 spF;
//     u8 spE;
//     u8 spD;
//     u8 spC;
//
//     s32 *src; // sp8
//     s32 *dst; // sp4
//
//     src = arg0;
//     dst = arg1;
//
//     spE = 8;
//     spE += -1;
//     if (spE != 0) {
//         do {
//             spF = 0xA;
//             spF += -1;
//             if (spF != 0) {
//                 do {
//                     spC = 0x20;
//                     spC += -1;
//                     if (spC != 0) {
//                         do {
//                             spD = 0x10;
//                             spD += -1;
//                             if (spD != 0) {
//                                 do {
//                                     *dst++ = *src++;
//                                     // dst += 4;
//                                     // src += 4;
//                                     spD += -1;
//                                 } while (spD != 0);
//                             }
//                             src += 0x240;
//                             spC += -1;
//                         } while (spC != 0);
//                     }
//                     src += -0x4FC0;
//                     spF += -1;
//                 } while (spF != 0);
//             }
//             src += 0x4D80;
//             spE += -1;
//         } while (spE != 0);
//     }
// }
