#include <ultra64.h>

#include "common.h"


void load_ingame_objects(void) {
    s32 pad[2];
    u32 len = D_0007F790 - D_000398D0;

    if (!(len < (D_80099600 - D_8004B400))) {
        rmonPrintf("\nASSERT: len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), %s, %u\n", "../src/init.c", 93);
        *(volatile int*)0 = 0;
    }
    D_801D9E74 = &D_8004B400;
    dma_read(D_000398D0, D_801D9E74, len);
}

void load_water_texture(void) {
    s32 pad[2];
    u32 len = D_00546BC0 - D_005449C0;

    if (len >= 0x2201U) {
        rmonPrintf("\nASSERT: len <= sizeof(WaterTexture), %s, %u\n", "../src/init.c", 115);
        *(volatile int*)0 = 0;
    }
    dma_read(D_005449C0, &D_800DCC20, len);
}
