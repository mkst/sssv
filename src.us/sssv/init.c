#include <ultra64.h>

#include "common.h"


// ========================================================
// .data
// ========================================================

// used in func_8029F7D4_6B0E84
u8 *D_803A8370_7B9A20[3] = {
    img_D_01034190_6DA60_i4__png,
    img_D_01033190_6CA60_i4__png,
    img_D_01034990_6E260_i4__png,
};

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
    u32 len = _segment1SegmentRomEnd - _segment1SegmentRomStart;

    SSSV_ASSERT(len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), "../src/init.c", 93);
    D_801D9E74 = &_gfxdlistSegmentStart;
    dma_read(_segment1SegmentRomStart, D_801D9E74, len);
}

// TODO: use actual D_800DCC20 buffer size
extern u8 WaterTexture[0x2200];

void load_water_texture(void) {
    s32 pad[2];
    u32 len = __5449C0SegmentRomEnd - __5449C0SegmentRomStart;

    SSSV_ASSERT(len <= sizeof(WaterTexture), "../src/init.c", 115);
    dma_read(__5449C0SegmentRomStart, &D_800DCC20, len);
}
