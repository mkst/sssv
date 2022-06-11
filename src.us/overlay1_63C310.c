#include <ultra64.h>

#include "common.h"


// miles and miles away...
#if 0
void func_80298C70_63C310(u8 arg0) {
    u8 *sp54;
    u8 sp53;
    u8 sp52;
    s32 sp4C;
    u8 sp4B;

    s32 pad[2];

    sp53 = 0; // x
    sp52 = 0; // y
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

    for (sp52 = 0; sp52 < 8; sp52++) {
        for (sp53 = 0; sp53 < 10; sp53++) {
            // draw black rectangle
            gDPSetPrimColor(D_801D9E7C++, 0, 0, 0, 0, 0, 255);
            gDPFillRectangle(D_801D9E7C++,
                (((sp53 << 5) - arg0 / 2) + 15),
                (((sp52 << 5) - arg0 / 2) + 15),
                (((sp53 << 5) - arg0 / 2) + arg0 + 17),
                (((sp52 << 5) - arg0 / 2) + arg0 + 17)
            );

            sp4B = -1 - -arg0*8;
            gDPSetPrimColor(D_801D9E7C++, 0, 0, sp4B, sp4B, sp4B, 0xFF);

            sp54 = D_80302E88 + 0x62000 + sp4C;
            func_801356C0(
                ((sp53 << 5) - arg0 / 2) + 16,
                ((sp52 << 5) - arg0 / 2) + 16,
                arg0,
                arg0,
                &D_801D9E7C,
                sp54,
                arg0,
                arg0,
                16);

            sp4C += 0x800;
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
