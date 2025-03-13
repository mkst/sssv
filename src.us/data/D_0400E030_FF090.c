#include <ultra64.h>

Vtx D_0400DDC0_FEE20[8] = {
#include "data/inc/D_0400DDC0_FEE20.inc.c"
};
Vtx D_0400DE40_FEEA0[31] = {
#include "data/inc/D_0400DE40_FEEA0.inc.c"
};

Gfx D_0400E030_FF090[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400DDC0_FEE20, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400DE40_FEEA0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 3, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 0, 10, 0, 4, 11, 12, 0),
    gsSP2Triangles(3, 12, 8, 0, 2, 8, 7, 0),
    gsSP2Triangles(13, 14, 15, 0, 6, 11, 7, 0),
    gsSP2Triangles(6, 12, 11, 0, 6, 8, 12, 0),
    gsSP2Triangles(16, 17, 14, 0, 13, 18, 19, 0),
    gsSP2Triangles(16, 15, 20, 0, 10, 7, 11, 0),
    gsSP2Triangles(21, 22, 10, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 25, 27, 0, 23, 25, 26, 0),
    gsSP2Triangles(24, 27, 25, 0, 2, 10, 0, 0),
    gsSP2Triangles(28, 5, 3, 0, 5, 29, 4, 0),
    gsSP2Triangles(10, 22, 30, 0, 12, 3, 4, 0),
    gsSP2Triangles(8, 2, 3, 0, 7, 10, 2, 0),
    gsSP2Triangles(30, 9, 10, 0, 1, 28, 3, 0),
    gsSPEndDisplayList(),
};
