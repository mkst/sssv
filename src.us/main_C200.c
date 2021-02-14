#include <ultra64.h>
#include "common.h"

extern s32 D_8012A390;
extern s32 D_8012EDC0;

#pragma GLOBAL_ASM("asm/nonmatchings/main_C200/func_80130B00.s")
// void func_80130B00(void) {
//     u32 len = (&D_800EF0D0 - &D_800E1220);
//
//     if (len >= (&D_8012EDC0 - &D_8012A390)) {
//         // "\nASSERT: len < (_fontbufferSegmentEnd - _fontbufferSegmentStart), %s, %u\n"
//         // "../src/fontinit.c"
//         rmonPrintf(D_8015AD10, D_8015AD5C, 74, &D_8012EDC0 - &D_8012A390);
//         // die
//         *(volatile int*)0 = 0;
//     }
//
//     D_801D9E70 = D_8022E3F0;
//     dma_read(&D_8012A390, &D_8022E3F0, (&D_8012EDC0 - &D_8012A390));
//     rnc_decompress(&D_8022E3F0, &D_800E1220);
// }

// unused
void func_80130BA0(void) {
    s16 phi_v0 = 0;
    do { phi_v0++; } while (phi_v0 < 60U);
}

// unused
#pragma GLOBAL_ASM("asm/nonmatchings/main_C200/func_80130BC4.s")

void func_80130C04(void) {
    func_80129090(&D_8023F260, 0, 64);
}
