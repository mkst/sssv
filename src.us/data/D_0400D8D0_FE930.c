#include <ultra64.h>

Vtx D_0400D760_FE7C0[23] = {
#include "data/inc/D_0400D760_FE7C0.inc.c"
};

Gfx D_0400D8D0_FE930[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400D760_FE7C0, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsSP1Quadrangle(8, 2, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(13, 17, 11, 0, 16, 18, 14, 0),
    gsSP2Triangles(19, 20, 21, 0, 21, 22, 19, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
