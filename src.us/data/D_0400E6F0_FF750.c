#include <ultra64.h>

Vtx D_0400E3F0_FF450[31] = {
#include "data/inc/D_0400E3F0_FF450.inc.c"
};
Vtx D_0400E5E0_FF640[17] = {
#include "data/inc/D_0400E5E0_FF640.inc.c"
};

Gfx D_0400E6F0_FF750[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400E3F0_FF450, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 26, 27, 24, 0),
    gsSP2Triangles(28, 24, 27, 0, 29, 25, 30, 0),
    gsSPVertex(D_0400E5E0_FF640, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 4, 7, 0, 9, 5, 10, 0),
    gsSP2Triangles(10, 11, 9, 0, 12, 9, 11, 0),
    gsSP2Triangles(13, 5, 14, 0, 14, 15, 13, 0),
    gsSP1Triangle(16, 13, 15, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
