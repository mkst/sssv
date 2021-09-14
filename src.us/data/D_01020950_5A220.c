#include <ultra64.h>

Vtx D_010208C0_5A190[9] = {
#include "data/inc/D_010208C0_5A190.inc.c"
};

const Gfx D_01020950_5A220[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_010208C0_5A190, 9, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(1, 0, 4, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 6, 8, 0),
    gsSP2Triangles(6, 0, 3, 0, 5, 2, 8, 0),
    gsSP2Triangles(6, 5, 8, 0, 4, 0, 6, 0),
    gsSP2Triangles(7, 4, 6, 0, 2, 1, 4, 0),
    gsSP2Triangles(4, 8, 2, 0, 7, 8, 4, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
