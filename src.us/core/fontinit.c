#include <ultra64.h>

#include "common.h"

#include "pp.h"


void font_init(void) {
    s32 pad;
    u32 len = fonts_ROM_END - fonts_ROM_START;

    SSSV_ASSERT(len < (_fontbufferSegmentEnd - _fontbufferSegmentStart), "../src/fontinit.c", 74)
    D_801D9E70 = D_8022E3F0;
    dma_read(fonts_ROM_START, (void*)D_8022E3F0, len);
    UnpackRNC((RNC_fileptr)D_8022E3F0, _fontbufferSegmentStart);
}
