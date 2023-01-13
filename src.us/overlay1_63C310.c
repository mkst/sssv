#include <ultra64.h>

#include "common.h"

extern u8 D_80302E88[];
// miles and miles away...

typedef struct {
    u8 img[0x800];
} NewscasterTile;

#if 0
void func_80298C70_63C310(u8 arg0) {
    u8 *sp54;
    u8 j;
    u8 i;
    s32 sp4C;
    u8 sp4B;

    s32 pad[2];

    i = 0; // y
    j = 0; // x
    sp4C = 0; // image offset

    gSPDisplayList(D_801D9E7C++, &D_801582C0);

    func_801356C0(
        1,
        1,
        1,
        1,
        &D_801D9E7C,
        D_80302E88 + 0x62000 + 0, // newscaster
        1.0f,
        1.0f,
        8);

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 10; j++) {
            // draw black rectangle
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0, 0, 0, 255);
            gDPFillRectangle(D_801D9E7C++,
            /* ulx */ (((j << 5) - arg0 / 2) + 15),
            /* uly */ (((i << 5) - arg0 / 2) + 15),
            /* lrx */ (((j << 5) - arg0 / 2) + arg0 + 17),
            /* lry */ (((i << 5) - arg0 / 2) + arg0 + 17)
            );

            sp4B = (arg0 << 3) - 1;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, sp4B, sp4B, sp4B, 0xFF);

            // sp54 = D_80302E88 + 0x62000 + sp4C;
            func_801356C0(
                ((j << 5) - arg0 / 2) + 16,
                ((i << 5) - arg0 / 2) + 16,
                arg0,
                arg0,
                &D_801D9E7C,
                D_80302E88 + 0x62000 + sp4C,
                arg0,
                arg0,
                16);

            sp4C += sizeof(NewscasterTile);
        }
    }

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, 255, 255);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63C310/func_80298C70_63C310.s")
#endif

// this matches but can't be what the devs wrote!
// copy in 320x240xrgba16 image
void func_80298F1C_63C5BC(s32 *arg0, s32 *arg1) {
    u8 spF;
    u8 spE;
    u8 spD;
    u8 spC;

    s32 *src; // sp8
    s32 *dst; // sp4

    src = arg0;
    dst = arg1;

    spE = 8;
    while (spE--) {
        spF = 10;
        while (spF--) {
            spC = 32;
            while (spC--) {
                spD = 16;
                while (spD--) {
                    *dst++ = *src++;
                }
                src += 0x240 / 4; // 144
            }
            src += -0x4FC0 / 4; // 5104
        }
        src += 0x4D80 / 4; // 4960
    }
}
