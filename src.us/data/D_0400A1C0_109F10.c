#include <ultra64.h>

Vtx D_04009FA0_109CF0[8] = {
#include "data/inc/D_04009FA0_109CF0.inc.c"
};
Vtx D_0400A020_109D70[26] = {
#include "data/inc/D_0400A020_109D70.inc.c"
};

extern u8 D_040097A0_1094F0[];

Gfx D_0400A1C0_109F10[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_04009FA0_109CF0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_040097A0_1094F0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_0400A020_109D70, 26, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 1, 9, 0, 6, 2, 1, 0),
    gsSP2Triangles(8, 10, 2, 0, 8, 7, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(5, 10, 17, 0, 5, 2, 10, 0),
    gsSP2Triangles(18, 14, 19, 0, 20, 19, 1, 0),
    gsSP2Triangles(4, 21, 18, 0, 4, 3, 21, 0),
    gsSP2Triangles(16, 14, 13, 0, 9, 22, 7, 0),
    gsSP2Triangles(9, 19, 15, 0, 9, 1, 19, 0),
    gsSP2Triangles(12, 14, 18, 0, 11, 13, 10, 0),
    gsSP2Triangles(11, 22, 16, 0, 11, 7, 22, 0),
    gsSP2Triangles(15, 19, 14, 0, 17, 23, 24, 0),
    gsSP2Triangles(17, 13, 12, 0, 17, 10, 13, 0),
    gsSP2Triangles(11, 16, 13, 0, 8, 11, 10, 0),
    gsSP2Triangles(6, 8, 2, 0, 6, 9, 7, 0),
    gsSP2Triangles(9, 15, 22, 0, 15, 16, 22, 0),
    gsSP2Triangles(17, 12, 23, 0, 5, 17, 24, 0),
    gsSP2Triangles(12, 18, 21, 0, 20, 18, 19, 0),
    gsSP2Triangles(0, 20, 1, 0, 0, 5, 25, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPPipeSync(),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPEndDisplayList(),
};
