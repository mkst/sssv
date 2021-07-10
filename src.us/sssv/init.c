#include <ultra64.h>

#include "common.h"


void func_80352280_763930(void) {
    s32 pad[2];
    u32 len = D_0007F790 - D_000398D0;

    if (len >= D_80099600 - D_8004B400) {
        // "\nASSERT: len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), %s, %u\n"
        // "../src/init.c"
        rmonPrintf(D_803BE9F0, D_803BEA38, 93, len);
        // die
        *(volatile int*)0 = 0;
    }
    D_801D9E74 = &D_8004B400;
    dma_read(D_000398D0, D_801D9E74, len);
}

void func_80352310_7639C0(void) {
    s32 pad[2];
    u32 len = D_00546BC0 - D_005449C0;

    if (len >= 0x2201U) {
        // "\nASSERT: len <= sizeof(WaterTexture), %s, %u\n"
        // "../src/init.c"
        rmonPrintf(D_803BEA48, D_803BEA78, 115, len);
        *(volatile int*)0 = 0;
    }
    dma_read(D_005449C0, &D_800DCC20, len);
}

// 2000 lines
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80352380_763A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80354188_765838.s")
