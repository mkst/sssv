#include <ultra64.h>

Vtx D_0400D500_FE560[30] = {
#include "data/inc/D_0400D500_FE560.inc.c"
};

Gfx D_0400D6E0_FE740[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400D500_FE560, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 6, 0, 0, 7, 3, 8, 0),
    gsSP2Triangles(6, 8, 0, 0, 7, 8, 6, 0),
    gsSP2Triangles(2, 9, 0, 0, 8, 3, 0, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 14, 10, 0),
    gsSP2Triangles(15, 16, 10, 0, 17, 13, 18, 0),
    gsSP2Triangles(16, 18, 10, 0, 17, 18, 16, 0),
    gsSP2Triangles(12, 19, 10, 0, 18, 13, 10, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 20, 0),
    gsSP2Triangles(25, 26, 20, 0, 27, 23, 28, 0),
    gsSP2Triangles(26, 28, 20, 0, 27, 28, 26, 0),
    gsSP2Triangles(22, 29, 20, 0, 28, 23, 20, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
