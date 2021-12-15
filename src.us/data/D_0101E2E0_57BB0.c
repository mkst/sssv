#include <ultra64.h>

Vtx D_0101E070_57940[8] = {
#include "data/inc/D_0101E070_57940.inc.c"
};
Vtx D_0101E0F0_579C0[31] = {
#include "data/inc/D_0101E0F0_579C0.inc.c"
};

Gfx D_0101E2E0_57BB0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101E070_57940, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101E0F0_579C0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(3, 4, 0, 0, 0, 5, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 3, 1, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 9, 4, 1, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 1, 0),
    gsSP2Triangles(15, 1, 0, 0, 13, 16, 14, 0),
    gsSP1Quadrangle(9, 1, 14, 4, 0),
    gsSP2Triangles(17, 10, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(17, 0, 4, 0, 22, 0, 17, 0),
    gsSP2Triangles(11, 14, 16, 0, 11, 10, 14, 0),
    gsSP1Quadrangle(4, 14, 10, 17, 0),
    gsSP2Triangles(8, 7, 23, 0, 24, 25, 26, 0),
    gsSP1Quadrangle(24, 10, 12, 27, 0),
    gsSP2Triangles(17, 18, 28, 0, 17, 29, 22, 0),
    gsSP2Triangles(22, 8, 23, 0, 6, 8, 22, 0),
    gsSP2Triangles(24, 27, 25, 0, 10, 24, 26, 0),
    gsSP2Triangles(10, 26, 18, 0, 17, 19, 21, 0),
    gsSP2Triangles(17, 21, 29, 0, 19, 28, 20, 0),
    gsSP2Triangles(22, 23, 30, 0, 19, 17, 28, 0),
    gsSP1Triangle(29, 6, 22, 0),
    gsSPEndDisplayList(),
};
