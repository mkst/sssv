#include <ultra64.h>
#include "common.h"

// ========================================================
// externs
// ========================================================

extern u8  _gfxanimSegmentStart[];      // D_80099600
extern u8  _gfxanimSegmentEnd[];        // D_800B0B20

extern u8  _gfxspecificSegmentStart[];  // D_800B0B20
extern u8  _gfxspecificSegmentEnd[];    // D_800BA760

// ========================================================
// .text
// ========================================================

void load_data_section(u8 segment) {
    u32 len;
    u8  pad[0x1C];

    osWritebackDCacheAll();
    bzero_sssv(_gfxanimSegmentStart, _gfxanimSegmentEnd - _gfxanimSegmentStart);

    switch (segment) {
    case SEGMENT_CITY:
        len = _city_biomeSegmentRomEnd - _city_biomeSegmentRomStart;
        SSSV_ASSERT(len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 114)

        D_801D9E5C = _gfxanimSegmentStart;
        dma_read(_city_biomeSegmentRomStart, D_801D9E5C, len);
        D_801D9EC4 = D_801D9E5C;
        break;
    case SEGMENT_EUROPE:
        len = _europe_biomeSegmentRomEnd - _europe_biomeSegmentRomStart;
        SSSV_ASSERT(len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 132)

        D_801D9E58 = _gfxanimSegmentStart;
        dma_read(_europe_biomeSegmentRomStart, D_801D9E58, len);
        D_801D9EC4 = D_801D9E58;
        break;
    case SEGMENT_ICE:
        len = _ice_biomeSegmentRomEnd - _ice_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 150)
        D_801D9E60 = _gfxanimSegmentStart;
        dma_read(_ice_biomeSegmentRomStart, D_801D9E60, len);
        D_801D9EC4 = D_801D9E60;
        break;
    case SEGMENT_DESERT:
        len = _desert_biomeSegmentRomEnd - _desert_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 168)
        D_801D9E64 = _gfxanimSegmentStart;
        dma_read(_desert_biomeSegmentRomStart, D_801D9E64, len);
        D_801D9EC4 = D_801D9E64;
        break;
    case SEGMENT_JUNGLE:
        len = _jungle_biomeSegmentRomEnd - _jungle_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 186)
        D_801D9E68 = _gfxanimSegmentStart;
        dma_read(_jungle_biomeSegmentRomStart, D_801D9E68, len);
        D_801D9EC4 = D_801D9E68;
        break;
    case SEGMENT_SHIP:
        // dan
        len = _data_7F790SegmentRomEnd - _data_7F790SegmentRomStart;
        SSSV_ASSERT(len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), "../src/animinit.c", 206)
        D_801D9E78 = _gfxspecificSegmentStart;
        dma_read(_data_7F790SegmentRomStart, D_801D9E78, len);
        // menu
        len = _data_116BD0SegmentRomEnd - _data_116BD0SegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 218)
        D_801D9E6C = _gfxanimSegmentStart;
        dma_read(_data_116BD0SegmentRomStart, D_801D9E6C, len);
        D_801D9EC4 = D_801D9E6C;
        break;
    }
}

// file split

void switch_to_current_segment(Gfx **arg0, DisplayList *arg1) {
    switch (D_803F2D50.segment) {
    case SEGMENT_CITY:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E5C));
        break;
    case SEGMENT_EUROPE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E58));
        break;
    case SEGMENT_ICE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E60));
        break;
    case SEGMENT_DESERT:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E64));
        break;
    case SEGMENT_JUNGLE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E68));
        break;
    case SEGMENT_SHIP:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E6C));
        break;
    default:
        osSyncPrintf("Undefined segment - hware.c\n", arg0);
        break;
    }
}
