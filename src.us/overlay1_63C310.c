#include <ultra64.h>

#include "common.h"

extern u8 D_80302E88[];

typedef struct {
    u8 img[0x800];
} NewscasterTile;

void func_80298C70_63C310(u8 size) {
    u8 *sp54;
    u8 j;
    u8 i;
    u8 sp4B;
    u32 new_var;
    s32 sp4C;

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

    new_var = size;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 10; j++) {
            // draw black rectangle
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0, 0, 0, 255);
            gDPFillRectangle(D_801D9E7C++,
            /* ulx */ (j << 5) + (15 - (size / 2)),
            /* uly */ (i << 5) + (15 - (size / 2)),
            /* lrx */ (j << 5) + (17 - (size / 2)) + size,
            /* lry */ (i << 5) + (17 - (size / 2)) + size
            );

            sp4B = (size << 3) - 1;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, sp4B, sp4B, sp4B, 0xFF);

            sp54 = D_80302E88 + 0x62000 + sp4C;
            func_801356C0(
                (j << 5) + (16 - (size / 2)),
                (i << 5) + (16 - (size / 2)),
                new_var,
                new_var,
                &D_801D9E7C,
                sp54,
                size,
                size,
                16);

            sp4C += sizeof(NewscasterTile);
        }
    }

    gDPSetPrimColor(D_801D9E7C++, 0, 0, 255, 255, 255, 255);
}

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
