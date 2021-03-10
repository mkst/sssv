#include <ultra64.h>

#include "common.h"

// strlen is already defined in libc, this is an extra...
u16 strlen2(u8 *s) {
    u16 i;

    if (s == NULL) {
        return 0;
    }
    for (i = 0; s[i] != 0; i++) {};

    return i;
}

void strcat(u8 *dst, u8 *src) {
    u16 i, j;

    i = strlen2(dst);
    j = 0;

    while (src[j] != 0) {
        dst[i] = src[j];
        i++, j++;
    }
    dst[i] = 0; // NUL terminate
}

void strcpy(u8* dst, u8 *src) {
    u16 i = 0;
    while (src[i] != 0) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0; // NUL terminate
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80128F38.s")

void fancy_bzero(u8 *addr, s32 len) {
    s32 unaligned_bytes, remainder;

    u64 *l;
    u8  *b;

    // if there is a non-8 aligned number of bytes, zero these now:
    unaligned_bytes = (s32)addr & 7;
    if (unaligned_bytes != 0) {
        unaligned_bytes = 8 - unaligned_bytes;
        if (len < unaligned_bytes) {
            unaligned_bytes = len;
        }
        // adjust remaining
        len = len - unaligned_bytes;

        b = addr;
        while (unaligned_bytes-- > 0) {
            *b++ = 0;
        }
        addr = b;
    }

    remainder = len & 7;
    // iterate length/8 times
    len = len >> 3;
    l = (u64 *)addr;
    while (len-- > 0) {
        *l++ = 0;
    }

    b = (u8 *)l;
    while (remainder-- > 0) {
        *b++ = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80129060.s")
