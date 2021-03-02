#include <ultra64.h>

#include "common.h"


// this file might very well be a continuation of string.c

// this function matches with -O2
u8 *func_80129090(u8 *arg0, u8 arg1, u32 len) {
    u32 temp_v1;
    u8 *tmp = arg0;

    if (len > 3) {
        temp_v1 = (arg1 << 8) | arg1;
        tmp = func_80129060(arg0, (temp_v1 << 16) | temp_v1, len >> 2);
        len = len & 3;
    }
    while (len-- > 0) {
        *tmp++ = arg1;
    }

    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_80129128.s")
// nope.
// s32 func_80129128(void) {
//     u32 tmp = (D_80152E80 * 0x41C64E6D) + 12345;
//     return D_80152E80 = (tmp >> 16) & 0x7FFF;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/strncpy.s")
// matches with -O3
// u8 *strncpy(u8 *src, u8 *dst, u32 len) {
//     u8 *_src = src;
//     u8 *_dst = dst;
//
//     while (len-- > 0) {
//         *_dst++ = *_src++;
//     }
//     return dst;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_4790/func_80129198.s")
// matches with -O2 -g3
// s32 func_80129198(s16 *arg0) {
//     // huh? is this swallowed up by func_801291A4
//     return;
// }

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
