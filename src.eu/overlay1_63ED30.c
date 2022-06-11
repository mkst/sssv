#include <ultra64.h>
#include "common.h"

extern Gfx D_801582E0[];
extern u8  D_80304388[];

void func_801356E0(s32 x, s32 y, u8 x_size, u8 y_size, Gfx **dl, u8 *arg5, f32 arg6, f32 arg7, u8 arg8);

typedef struct {
    u8 img[0x800];
} NewscasterTile;

#if 0
void func_80299E00_63ED30(u8 arg0) {
    u8 *sp54;
    u8 sp53 = 0;    // x
    u8 sp52 = 0;    // y
    s32 sp4C = 0;   // image offset
    u8 sp4B;

    gSPDisplayList(D_801D9E9C++, &D_801582E0);

    func_801356E0(
        1,
        1,
        1,
        1,
        &D_801D9E9C,
        D_80304388 + 0x62000 + 0,
        1.0f,
        1.0f,
        8);

    for (sp52 = 0; sp52 < 8; sp52++) {
        for (sp53 = 0; sp53 < 10; sp53++) {
            // paint a black rectangle
            gDPSetPrimColor(D_801D9E9C++, 0, 0, 0, 0, 0, 255);
            gDPFillRectangle(D_801D9E9C++,
            /* ulx */ (((sp53 << 5) - arg0 / 2) + 15),
            /* uly */ (((sp52 << 5) - arg0 / 2) + 15),
            /* lrx */ (((sp53 << 5) - arg0 / 2) + arg0 + 17),
            /* lry */ (((sp52 << 5) - arg0 / 2) + arg0 + 17)
            );

            sp4B = -1 - -arg0*8;
            gDPSetPrimColor(D_801D9E9C++, 0, 0, sp4B, sp4B, sp4B, 0xFF);

            sp54 = D_80304388 + 0x62000 + sp4C;
            func_801356E0(
                (((sp53 << 5) - arg0 / 2) + 15) + 1,
                (((sp52 << 5) - arg0 / 2) + 15) + 1,
                arg0,
                arg0,
                &D_801D9E9C,
                sp54,
                arg0,
                arg0,
                16);

            sp4C += sizeof(NewscasterTile);
        }
    }

    gDPSetPrimColor(D_801D9E9C++, 0, 0, 255, 255, 255, 255);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63ED30/func_80299E00_63ED30.s")
#endif

void func_8029A144_63F074(s32 *arg0, s32 *arg1) {
    u8 spF;
    u8 spE;
    u8 spD;
    u8 spC;

    s32 *src = arg0; // sp8
    s32 *dst = arg1; // sp4

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
