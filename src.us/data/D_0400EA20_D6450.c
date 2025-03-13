#include <ultra64.h>

Vtx D_0400E950_D6380[13] = {
#include "data/inc/D_0400E950_D6380.inc.c"
};

Gfx D_0400EA20_D6450[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400E950_D6380, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(1, 5, 6, 0, 3, 6, 7, 0),
    gsSP2Triangles(5, 8, 7, 0, 3, 2, 6, 0),
    gsSP2Triangles(2, 4, 0, 0, 6, 2, 1, 0),
    gsSP2Triangles(9, 10, 11, 0, 8, 11, 10, 0),
    gsSP2Triangles(3, 7, 10, 0, 12, 0, 4, 0),
    gsSP2Triangles(3, 9, 4, 0, 10, 7, 8, 0),
    gsSP2Triangles(7, 6, 5, 0, 4, 9, 12, 0),
    gsSP2Triangles(3, 10, 9, 0, 11, 12, 9, 0),
    gsSP2Triangles(8, 0, 12, 0, 0, 8, 5, 0),
    gsSP2Triangles(12, 11, 8, 0, 5, 1, 0, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
