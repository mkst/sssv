#include <ultra64.h>

#include "common.h"

// strlen
u16 func_80128DD0(u8 *str) {
    u16 i;

    if (str == NULL) {
        return 0;
    }

    i = 0;
    while (str[i] != 0) {
        i++;
    };

    return i;
}

// strcat
void func_80128E18(u8 *dst, u8 *src) {
    u16 i, j;

    i = func_80128DD0(dst);
    j = 0;

    while (src[j] != 0) {
        dst[i] = src[j];
        i++, j++;
    }

    dst[i] = 0; // NUL terminate
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80129060.s")
