#include <ultra64.h>

Vtx D_0400E0E0_FF140[31] = {
#include "data/inc/D_0400E0E0_FF140.inc.c"
};
Vtx D_0400E2D0_FF330[9] = {
#include "data/inc/D_0400E2D0_FF330.inc.c"
};

Gfx D_0400E360_FF3C0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400E0E0_FF140, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 0, 2, 0, 4, 1, 0, 0),
    gsSP2Triangles(4, 3, 1, 0, 4, 0, 3, 0),
    gsSP2Triangles(5, 6, 7, 0, 6, 8, 7, 0),
    gsSP2Triangles(8, 5, 7, 0, 9, 6, 5, 0),
    gsSP2Triangles(9, 8, 6, 0, 9, 5, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 17, 16, 0),
    gsSP2Triangles(20, 14, 13, 0, 21, 12, 11, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0400E2D0_FF330, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
