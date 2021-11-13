#include <ultra64.h>

Vtx D_0400C830_123400[31] = {
#include "data/inc/D_0400C830_123400.inc.c"
};
Vtx D_0400CA20_1235F0[12] = {
#include "data/inc/D_0400CA20_1235F0.inc.c"
};

extern u8 D_0400C030_122C00[];

const Gfx D_0400CAE0_1236B0[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_MODULATEI),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400C030_122C00),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPVertex(D_0400C830_123400, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 6, 2, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 9, 0, 11, 12, 6, 0),
    gsSP2Triangles(8, 13, 9, 0, 13, 8, 14, 0),
    gsSP2Triangles(15, 14, 8, 0, 7, 16, 17, 0),
    gsSP2Triangles(5, 12, 18, 0, 3, 5, 18, 0),
    gsSP2Triangles(17, 16, 19, 0, 1, 11, 6, 0),
    gsSP2Triangles(12, 11, 18, 0, 20, 4, 3, 0),
    gsSP2Triangles(21, 19, 16, 0, 10, 16, 7, 0),
    gsSP2Triangles(17, 22, 8, 0, 8, 7, 17, 0),
    gsSP2Triangles(23, 24, 25, 0, 22, 26, 24, 0),
    gsSP2Triangles(27, 28, 29, 0, 24, 8, 22, 0),
    gsSP2Triangles(25, 24, 26, 0, 28, 23, 25, 0),
    gsSP2Triangles(15, 8, 24, 0, 29, 25, 30, 0),
    gsSP1Triangle(26, 30, 25, 0),
    gsSPVertex(D_0400CA20_1235F0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 6, 3, 0),
    gsSP2Triangles(7, 3, 2, 0, 8, 9, 10, 0),
    gsSP1Triangle(11, 7, 2, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
