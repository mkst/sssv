#include <ultra64.h>

Vtx D_01017C90_51560[13] = {
#include "data/inc/D_01017C90_51560.inc.c"
};

const Gfx D_01017D60_51630[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01017C90_51560, 13, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 0, 4, 0),
    gsSP1Quadrangle(5, 6, 2, 7, 0),
    gsSP2Triangles(8, 5, 7, 0, 6, 5, 8, 0),
    gsSP1Quadrangle(9, 10, 2, 11, 0),
    gsSP2Triangles(12, 9, 11, 0, 10, 9, 12, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
