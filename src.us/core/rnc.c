#include <ultra64.h>
#include "common.h"

/*
RNC Header:

3 bytes   signature "RNC"
1 byte    version
4 bytes   unpacked data length
4 bytes   packed data length
2 bytes   CRC-16 of packed data
2 bytes   CRC-16 of unpacked data
2 bytes   overlap size (used for inplace unpacking)

via https://wiki.multimedia.cx/index.php/RNC_ProPack

*/

// check_rnc_header
u16 rnc_decompress(u8 *src, u8* dst) {
    u16 res;

    if ((src[0] != 'R') || (src[1] != 'N') || (src[2] != 'C')) {
        return 0xFFFF; // -1
    }

    switch (src[3]) {
        case 0:
            res = 0; // no compression
            break;
        case 1:      // method 1 (all files appear to be this type)
            res = func_8012B194(src, dst);
            break;
        case 2:      // method 2
            res = func_8012B3B8(src, dst);
            break;
        default:
            res = 0xFFFE; // -2
    }

    return res;
}

// method 1 decompression
#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B194.s")
// method 2 decompression
#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B3B8.s")

// getting unpacked data length?
#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B648.s")
// Need to understand what the bitshifting is doing
// void func_8012B648(s32 arg0, s32 arg1) {
//     u32 sp2C;
//     u32 sp28;
//     u32 sp24;
//     u32 tmp4;
//
//     D_8022E3E0 = arg0 + 18;
//     D_8022E0DC = arg1;
//
//     arg0 += 4; // skip over header?
//     sp24 = func_8012BB6C(arg0);
//     sp28 = func_8012BB6C(arg0);
//     sp2C = func_8012BB6C(arg0);
//     tmp4 = func_8012BB6C(arg0);
//
//     D_8022E0D4 = (((tmp4 >> 16) & 0xFF00) >> 8) +
//                  (((sp2C >> 16) & 0x00FF) << 8) +
//                  (((sp28 << 8) + ((sp24 & 0xFF00) >> 8)) << 16) + arg1;
//
//     D_8022E3E4 = 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012B958.s")

u16 func_8012BA38(void) {
    u16 res = func_8012B804(1) + 4;
    if (func_8012B804(1) == 0) {
        return res;
    } else {
        return func_8012B804(1) + ((res - 1) << 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BA98.s")

// reverse_word
// i.e. "abcd" => "dcba"
u32 func_8012BB6C(u8 *arg0) {
    return arg0[0] | (arg0[1] << 8) | (arg0[2] << 16) | (arg0[3] << 24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BB98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BCEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/func_8012BF5C.s")

s32 func_8012C010(u32 arg0, u8 arg1) {
    s32 ret = 0;

    while (arg1--) {
        ret <<= 1;
        if (arg0 & 1) {
            ret |= 1;
        }
        arg0 >>= 1;
    }
    return ret;
}
