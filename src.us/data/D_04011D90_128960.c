#include <ultra64.h>

extern u8 D_040113E0_127FB0[];

Vtx D_04011BE0_1287B0[27] = {
#include "data/inc/D_04011BE0_1287B0.inc.c"
};


Gfx D_04011D90_128960[] = {
    gsDPPipeSync(),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_040113E0_127FB0),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPVertex(D_04011BE0_1287B0, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP1Triangle(24, 25, 26, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
