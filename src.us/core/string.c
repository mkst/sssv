#include <ultra64.h>

#include "common.h"

// strlen is already defined in libc, this is an extra...
u16 strlen_sssv(u8 *s) {
    u16 i;

    if (s == NULL) {
        return 0;
    }
    for (i = 0; s[i] != 0; i++) {};

    return i;
}

void strcat(u8 *dst, u8 *src) {
    u16 i, j;

    i = strlen_sssv(dst);
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

void strncpy(u8 *dst, u8 *src, s16 num) {
    u16 i = 0;
    while ((src[i] != 0) && (i < num)) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
}

s32 strcmp(u8 *str1, u8 *str2) {
    // empty strings are equal
    if ((*str1 == 0) && (*str2 == 0)) {
        return 0;
    }
    // iterate until NUL or mismatch
    while ((*str1 != 0) && (*str2 != 0)) {
        if (*str1++ != *str2++) {
            return 1;
        }
    };
    // final check...
    if (*str1 == *str2) {
        return 0;
    }
    // mismatch
    return 1;
}

void bzero_sssv(u8 *addr, s32 len) {
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

s32 *memset_words(s32 *dst, s32 c, u32 len) {
    while (len-- > 0) {
        *dst++ = c;
    }
    return dst;
}

u8 *memset_bytes(u8 *dst, u8 c, u32 len) {
    u32 word;
    u8 *_dst = dst;

    if (len > 3) {
        word = (c << 8) | c;
        word = (word << 16) | word;
        _dst = memset_words(dst, word, len >> 2);
        len = len & 3;
    }
    while (len-- > 0) {
        *_dst++ = c;
    }

    return dst;
}

u16 rand(void) {
      u32 *tmp = &D_80152E80;
      if (0) {
          // debug?
      }

      D_80152E80 = (*tmp * 0x41c64e6d + 12345) ;
      return (*tmp >> 16) & 0x7fff;
}

u8 *memcpy_sssv(u8 *src, u8 *dst, u32 len) {
    u8 *_src = src;
    u8 *_dst = dst;

    while (len-- > 0) {
        *_dst++ = *_src++;
    }
    return dst;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/string/func_80129198.s")
// matches with -O2 -g3
// s16 func_80129198(s16 arg0) {
//     // huh? is this swallowed up by func_801291A4
// }

u8 *func_801291A4(u8 *x) {
    u8 *_x = x;

    while (*_x) {
        *_x++ = func_80129198(*_x);
    }

    return x;
}
