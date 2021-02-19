#include <ultra64.h>

#include "common.h"


// this file might very well be a continuation of string.c
#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_80129090.s")


#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_80129128.s")
// nope.
// s32 func_80129128(void) {
//     u32 tmp = (D_80152E80 * 0x41C64E6D) + 12345;
//     return D_80152E80 = (tmp >> 16) & 0x7FFF;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/strncpy.s")
// matches with -O3
// u8 *strncpy(u8 *src, u8 *dst, u32 len) {
//     u8 *_src  = src;
//     u8 *_dst = dst;
//
//     while (len-- > 0) {
//         *_dst++ = *_src++;
//     }
//     return dst;
// }

// #pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_80129198.s")
s32 func_80129198(s16 *arg0) {
    // huh? is this swallowed up by func_801291A4
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_801291A4.s")
// not this...
// u8 *func_801291A4(u8 *x) {
//     u8 *_x = x;
//     s16 tmp;
//
//     while (*_x) {
//         tmp = *_x;
//         *_x++ = func_80129198(tmp);
//     }
//
//     return x;
// }
