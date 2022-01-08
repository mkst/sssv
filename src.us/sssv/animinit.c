#include <ultra64.h>
#include "common.h"


extern u8  data_7F790_ROM_START[];      // dan
extern u8  data_7F790_ROM_END[];

extern u8  europe_biome_ROM_START[];
extern u8  europe_biome_ROM_END[];

extern u8  ice_biome_ROM_START[];
extern u8  ice_biome_ROM_END[];

extern u8  desert_biome_ROM_START[];
extern u8  desert_biome_ROM_END[];

extern u8  jungle_biome_ROM_START[];
extern u8  jungle_biome_ROM_END[];

extern u8  city_biome_ROM_START[];
extern u8  city_biome_ROM_END[];

extern u8  data_116BD0_ROM_START[];     // menu
extern u8  data_116BD0_ROM_END[];

extern u8  _gfxanimSegmentStart[];      // D_80099600
extern u8  _gfxanimSegmentEnd[];        // D_800B0B20

extern u8  _gfxspecificSegmentStart[];  // D_800B0B20
extern u8  _gfxspecificSegmentEnd[];    // D_800BA760


void load_data_section(u8 arg0) {
    u32 len;
    u8  pad[0x1C];

    osWritebackDCacheAll();
    bzero_sssv(_gfxanimSegmentStart, _gfxanimSegmentEnd - _gfxanimSegmentStart);

    switch (arg0) {
    case 5:
        // city animals
        len = city_biome_ROM_END - city_biome_ROM_START;
        SSSV_ASSERT(len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 114)

        D_801D9E5C = _gfxanimSegmentStart;
        dma_read(city_biome_ROM_START, D_801D9E5C, len);
        D_801D9EC4 = D_801D9E5C;
        break;
    case 0:
        // europe animals
        len = europe_biome_ROM_END - europe_biome_ROM_START;
        SSSV_ASSERT(len < (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 132)

        D_801D9E58 = _gfxanimSegmentStart;
        dma_read(europe_biome_ROM_START, D_801D9E58, len);
        D_801D9EC4 = D_801D9E58;
        break;
    case 1:
        // ice animals
        len = ice_biome_ROM_END - ice_biome_ROM_START;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 150)
        D_801D9E60 = _gfxanimSegmentStart;
        dma_read(ice_biome_ROM_START, D_801D9E60, len);
        D_801D9EC4 = D_801D9E60;
        break;
    case 2:
        // desert animals
        len = desert_biome_ROM_END - desert_biome_ROM_START;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 168)
        D_801D9E64 = _gfxanimSegmentStart;
        dma_read(desert_biome_ROM_START, D_801D9E64, len);
        D_801D9EC4 = D_801D9E64;
        break;
    case 3:
        // jungle animals
        len = jungle_biome_ROM_END - jungle_biome_ROM_START;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 186)
        D_801D9E68 = _gfxanimSegmentStart;
        dma_read(jungle_biome_ROM_START, D_801D9E68, len);
        D_801D9EC4 = D_801D9E68;
        break;
    case 6: // ship
        // dan
        len = data_7F790_ROM_END - data_7F790_ROM_START;
        SSSV_ASSERT(len <= (_gfxspecificSegmentEnd - _gfxspecificSegmentStart), "../src/animinit.c", 206)
        D_801D9E78 = _gfxspecificSegmentStart;
        dma_read(data_7F790_ROM_START, D_801D9E78, len);
        // menu
        len = data_116BD0_ROM_END - data_116BD0_ROM_START;
        SSSV_ASSERT(len <= (_gfxanimSegmentEnd - _gfxanimSegmentStart), "../src/animinit.c", 218)
        D_801D9E6C = _gfxanimSegmentStart;
        dma_read(data_116BD0_ROM_START, D_801D9E6C, len);
        D_801D9EC4 = D_801D9E6C;
        break;
    }
}

void func_80380490_791B40(Gfx **arg0, DisplayList *arg1) {
    switch (D_803F2D70) {
    case 5:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E5C));
        break;
    case 0:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E58));
        break;
    case 1:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E60));
        break;
    case 2:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E64));
        break;
    case 3:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E68));
        break;
    case 6:
        gSPSegment((*arg0)++, 0x04, osVirtualToPhysical(D_801D9E6C));
        break;
    default:
        rmonPrintf("Undefined segment - hware.c\n", arg0);
        break;
    }
}
