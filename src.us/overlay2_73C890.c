#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73C890/func_8032B1E0_73C890.s")

// check some flag?
u8 func_8032BCF8_73D3A8(s32 arg0, s16 arg1) {
    if (arg1 >= 0) {
        while ((2 << arg1) & arg0) {
            if (--arg1 < 0) {
                break;
            }
        }
    }
    return (arg1 + 1) == 0;
}

s32 func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5) {
    if (arg0 == 0) {
        if ((func_8032BCF8_73D3A8(arg1, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg1 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg2 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg1, arg4) == 0)) {
            return 0;
        }
    }
    return 1;
}

#ifdef NON_MATCHING
// offsets are fakematches...
void func_8032BE28_73D4D8(Animal *arg0) {
    s16 temp_v0;
    s32 *temp_a1;
    s16 x;
    s16 y1;
    s16 y2;
    s16 phi_s0;
    s16 i;

    temp_a1 = arg0->unk16C->unk18;
    if (temp_a1 != NULL) {
        gSPDisplayList(D_801D9E8C++, D_01003548_3CE18);
        if (temp_a1 != NULL) {
            x = (D_803D5540 >> 3) % 32;
            for (i = 0; i < 32; i++) {
                temp_v0 = x + (i << 5);
                if (temp_a1[temp_v0+2] != 0) {
                    y1 = 0;
                    while ((temp_a1[temp_v0+2] & (1 << y1)) == 0) {
                        y1++;
                    }
                    y2 = 31;
                    while ((temp_a1[temp_v0+2] & (1 << y2)) == 0) {
                        y2--;
                    }
                    if (y1 == y2) {
                        // arg0, x, y, z, r, g, b
                        func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 200);  // turquoise
                    } else {
                        func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 0);    // green
                        func_8032C0EC_73D79C(arg0, x, i, y2, 0, 0,   200);  // blue
                        phi_s0 = y1;
                        while (phi_s0 < y2) {
                            if ((temp_a1[temp_v0+2] & (1 << phi_s0)) == 0) {
                                // red
                                func_8032C0EC_73D79C(arg0, x, i, phi_s0, 255, 0, 0);
                            }
                            phi_s0++;
                        }
                    }
                }
            }
        }
    }
    // regalloc helper
    if (temp_a1 && temp_a1) {};
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73C890/func_8032BE28_73D4D8.s")
#endif

void func_8032C0EC_73D79C(Animal *arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b) {

    if (D_803D3434->usedModelViewMtxs < 240) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, r, g, b, 0xFF);
        guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], (2.0 * (f32) x) - 30.0, (2.0 * (f32) y) - 30.0, (2.0 * (f32)z) - 32.0);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        D_803D3434->usedModelViewMtxs += 1;

        gSPDisplayList(D_801D9E8C++, D_0103B6F0);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}
