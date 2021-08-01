#include <ultra64.h>

#include "common.h"

#include "pp.h"

void font_init(void) {
    u32 fontbufferSegmentLen = D_800EF0D0 - D_800E1220;
    u32 len = D_0012EDC0 - D_0012A390;

    if (len >= fontbufferSegmentLen) {
        rmonPrintf("\nASSERT: len < (_fontbufferSegmentEnd - _fontbufferSegmentStart), %s, %u\n", "../src/fontinit.c", 74);
        // die
        *(volatile int*)0 = 0;
    }

    D_801D9E70 = D_8022E3F0;
    dma_read(D_0012A390, (void*)D_8022E3F0, len);
    UnpackRNC((RNC_fileptr)D_8022E3F0, D_800E1220);
}
