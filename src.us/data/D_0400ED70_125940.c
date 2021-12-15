#include <ultra64.h>

Vtx D_0400EC30_125800[20] = {
#include "data/inc/D_0400EC30_125800.inc.c"
};

extern u8 D_0400E430_125000[];

Gfx D_0400ED70_125940[] = {
    gsDPPipeSync(),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400E430_125000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPVertex(D_0400EC30_125800, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 4, 5, 0, 2, 1, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 5, 4, 7, 0),
    gsSP2Triangles(6, 8, 9, 0, 7, 6, 9, 0),
    gsSP2Triangles(8, 10, 11, 0, 9, 8, 11, 0),
    gsSP2Triangles(10, 12, 13, 0, 11, 10, 13, 0),
    gsSP2Triangles(12, 14, 15, 0, 13, 12, 15, 0),
    gsSP2Triangles(14, 16, 17, 0, 15, 14, 17, 0),
    gsSP2Triangles(16, 18, 19, 0, 17, 16, 19, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
