#include <ultra64.h>

Vtx D_05001000_86790[8] = {
#include "data/inc/D_05001000_86790.inc.c"
};
Vtx D_05001080_86810[17] = {
#include "data/inc/D_05001080_86810.inc.c"
};
Vtx D_05001190_86920[30] = {
#include "data/inc/D_05001190_86920.inc.c"
};
Vtx D_05001370_86B00[24] = {
#include "data/inc/D_05001370_86B00.inc.c"
};

extern u8 img_levels_HAVE_A_NICE_DAY_roof_tile_rgba16_rgba16__png[];
extern u8 img_levels_HAVE_A_NICE_DAY_floorboard_rgba16_rgba16__png[];

const Gfx D_050014F0_86C80[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05001000_86790, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_levels_HAVE_A_NICE_DAY_roof_tile_rgba16_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_05001080_86810, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 9, 0),
    gsSP2Triangles(10, 9, 12, 0, 13, 14, 9, 0),
    gsSP2Triangles(15, 13, 9, 0, 9, 14, 16, 0),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, img_levels_HAVE_A_NICE_DAY_floorboard_rgba16_rgba16__png),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(1, 0, 0, 4*(31), 4*(31)),
    gsSPTexture(32768, 32768, 0, 1, G_ON),
    gsSPVertex(D_05001190_86920, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 17, 21, 15, 0),
    gsSP2Triangles(20, 22, 18, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 11, 29, 9, 0),
    gsSPVertex(D_05001370_86B00, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 5, 7, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 5, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
