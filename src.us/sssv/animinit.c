#include <ultra64.h>
#include "common.h"

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

        gCitySegmentBase = _gfxanimSegmentStart;
        dma_read(_city_biomeSegmentRomStart, gCitySegmentBase, len);
        D_801D9EC4 = gCitySegmentBase;
        break;
    case SEGMENT_EUROPE:
        len = _europe_biomeSegmentRomEnd - _europe_biomeSegmentRomStart;
        SSSV_ASSERT(len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 132)

        gEuropeSegmentBase = _gfxanimSegmentStart;
        dma_read(_europe_biomeSegmentRomStart, gEuropeSegmentBase, len);
        D_801D9EC4 = gEuropeSegmentBase;
        break;
    case SEGMENT_ICE:
        len = _ice_biomeSegmentRomEnd - _ice_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 150)
        gIceSegmentBase = _gfxanimSegmentStart;
        dma_read(_ice_biomeSegmentRomStart, gIceSegmentBase, len);
        D_801D9EC4 = gIceSegmentBase;
        break;
    case SEGMENT_DESERT:
        len = _desert_biomeSegmentRomEnd - _desert_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 168)
        gDesertSegmentBase = _gfxanimSegmentStart;
        dma_read(_desert_biomeSegmentRomStart, gDesertSegmentBase, len);
        D_801D9EC4 = gDesertSegmentBase;
        break;
    case SEGMENT_JUNGLE:
        len = _jungle_biomeSegmentRomEnd - _jungle_biomeSegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 186)
        gJungleSegmentBase = _gfxanimSegmentStart;
        dma_read(_jungle_biomeSegmentRomStart, gJungleSegmentBase, len);
        D_801D9EC4 = gJungleSegmentBase;
        break;
    case SEGMENT_SHIP:
        // dan
        len = _data_7F790SegmentRomEnd - _data_7F790SegmentRomStart;
        SSSV_ASSERT(len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), "../src/animinit.c", 206)
        gSegment5Base = _gfxspecificSegmentStart;
        dma_read(_data_7F790SegmentRomStart, gSegment5Base, len);
        // menu
        len = _data_116BD0SegmentRomEnd - _data_116BD0SegmentRomStart;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 218)
        gMenuSegmentBase = _gfxanimSegmentStart;
        dma_read(_data_116BD0SegmentRomStart, gMenuSegmentBase, len);
        D_801D9EC4 = gMenuSegmentBase;
        break;
    }
}

// file split

void switch_to_current_segment(Gfx **arg0, DisplayList *arg1) {
    switch (D_803F2D50.segment) {
    case SEGMENT_CITY:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gCitySegmentBase));
        break;
    case SEGMENT_EUROPE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gEuropeSegmentBase));
        break;
    case SEGMENT_ICE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gIceSegmentBase));
        break;
    case SEGMENT_DESERT:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gDesertSegmentBase));
        break;
    case SEGMENT_JUNGLE:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gJungleSegmentBase));
        break;
    case SEGMENT_SHIP:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(gMenuSegmentBase));
        break;
    default:
        osSyncPrintf("Undefined segment - hware.c\n", arg0);
        break;
    }
}
