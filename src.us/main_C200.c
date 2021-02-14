#include <ultra64.h>
#include "common.h"


extern s32 D_8012A390;

#pragma GLOBAL_ASM("asm/nonmatchings/main_C200/func_80130B00.s")
// void func_80130B00(void) {
//
//     if (0x12EDC0 - 0x12A390 >= (u32) (&D_800EF0D0 - &D_800E1220)) {
//         // "\nASSERT: len < (_fontbufferSegmentEnd - _fontbufferSegmentStart), %s, %u\n"
//         // "../src/fontinit.c"
//         rmonPrintf(&D_8015AD10, &D_8015AD5C, 0x4A, 0x12EDC0 - 0x12A390);
//         *(volatile int*)0 = 0;
//     }
//     D_801D9E70 = &D_8022E3F0;
//     dma_read(&D_8012A390, &D_8022E3F0, 0x12EDC0 - 0x12A390); //, 0x12EDC0 - 0x12A390);
//     rnc_decompress(&D_8022E3F0, &D_800E1220);
// }

// waste some time
void func_80130BA0(void) {
    s16 phi_v0 = 0;
    do { phi_v0++; } while (phi_v0 < 60U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_C200/func_80130BC4.s")

void func_80130C04(void) {
    func_80129090(&D_8023F260, 0, 64);
}
