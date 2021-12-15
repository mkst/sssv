#include <ultra64.h>

Vtx D_0400DD60_124930[30] = {
#include "data/inc/D_0400DD60_124930.inc.c"
};
Vtx D_0400DF40_124B10[32] = {
#include "data/inc/D_0400DF40_124B10.inc.c"
};
Vtx D_0400E140_124D10[23] = {
#include "data/inc/D_0400E140_124D10.inc.c"
};

extern u8 D_0400D560_124130[];

Gfx D_0400E2B0_124E80[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPTileSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, D_0400D560_124130),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 256),
    gsSPVertex(D_0400DD60_124930, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 3, 4, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 7, 4, 0, 5, 6, 4, 0),
    gsSP2Triangles(6, 8, 9, 0, 7, 6, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 11, 10, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 17, 14, 0, 15, 16, 14, 0),
    gsSP2Triangles(16, 18, 19, 0, 17, 16, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 20, 0),
    gsSP2Triangles(24, 25, 20, 0, 23, 20, 25, 0),
    gsSP2Triangles(26, 25, 24, 0, 27, 25, 26, 0),
    gsSP2Triangles(28, 27, 26, 0, 29, 27, 28, 0),
    gsSPVertex(D_0400DF40_124B10, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 9, 8, 0),
    gsSP2Triangles(12, 11, 8, 0, 13, 11, 12, 0),
    gsSP2Triangles(14, 13, 12, 0, 15, 13, 14, 0),
    gsSP2Triangles(13, 15, 16, 0, 17, 16, 15, 0),
    gsSP2Triangles(11, 13, 18, 0, 16, 18, 13, 0),
    gsSP2Triangles(9, 11, 19, 0, 18, 19, 11, 0),
    gsSP2Triangles(4, 6, 20, 0, 21, 4, 20, 0),
    gsSP2Triangles(3, 2, 22, 0, 23, 3, 22, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 26, 25, 0),
    gsSP2Triangles(28, 24, 29, 0, 26, 29, 24, 0),
    gsSP1Triangle(30, 28, 31, 0),
    gsSPVertex(D_0400E140_124D10, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 5, 4, 0, 6, 7, 5, 0),
    gsSP2Triangles(1, 6, 5, 0, 8, 6, 1, 0),
    gsSP2Triangles(0, 8, 1, 0, 9, 8, 0, 0),
    gsSP2Triangles(10, 9, 0, 0, 11, 9, 10, 0),
    gsSP2Triangles(12, 11, 10, 0, 8, 13, 14, 0),
    gsSP1Quadrangle(6, 8, 14, 15, 0),
    gsSP2Triangles(7, 6, 15, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 16, 18, 0, 20, 16, 19, 0),
    gsSP2Triangles(21, 20, 19, 0, 7, 20, 21, 0),
    gsSP2Triangles(5, 7, 21, 0, 7, 15, 22, 0),
    gsSP1Triangle(20, 7, 22, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
