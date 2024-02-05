#include <ultra64.h>

#include "common.h"


// ========================================================
// .bss (D_803F2D10 to D_803F2D20)
// ========================================================

struct003 D_803F2D10;   // where to put this?
s32  D_803F2D14;        // unused
s16  D_803F2D18;        // used in overlay2_6AB090.c

// ========================================================
// .text
// ========================================================

void load_ingame_objects(void) {
    s32 pad[2];
    u32 len = segment1_ROM_END - segment1_ROM_START;

    if (!(len < (D_80099600 - D_8004B400))) {
        rmonPrintf("\nASSERT: len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), %s, %u\n", "../src/init.c", 93);
        *(volatile int*)0 = 0;
    }
    D_801D9E74 = &D_8004B400;
    dma_read(segment1_ROM_START, D_801D9E74, len);
}

void load_water_texture(void) {
    s32 pad[2];
    u32 len = _5449C0_ROM_END - _5449C0_ROM_START;

    if (len >= 0x2201U) {
        rmonPrintf("\nASSERT: len <= sizeof(WaterTexture), %s, %u\n", "../src/init.c", 115);
        *(volatile int*)0 = 0;
    }
    dma_read(_5449C0_ROM_START, &D_800DCC20, len);
}
