#include <ultra64.h>

Vtx D_0400CF20_FDF80[31] = {
#include "data/inc/D_0400CF20_FDF80.inc.c"
};
Vtx D_0400D110_FE170[5] = {
#include "data/inc/D_0400D110_FE170.inc.c"
};

Gfx D_0400D160_FE1C0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400CF20_FDF80, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 4, 5, 0, 7, 4, 8, 0),
    gsSP2Triangles(1, 4, 7, 0, 7, 9, 1, 0),
    gsSP2Triangles(10, 1, 9, 0, 2, 1, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 12, 11, 0),
    gsSP2Triangles(15, 12, 14, 0, 16, 15, 14, 0),
    gsSP2Triangles(17, 15, 16, 0, 18, 15, 19, 0),
    gsSP2Triangles(12, 15, 18, 0, 18, 20, 12, 0),
    gsSP2Triangles(21, 12, 20, 0, 13, 12, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 23, 22, 0),
    gsSP2Triangles(26, 23, 25, 0, 27, 26, 25, 0),
    gsSP2Triangles(28, 26, 27, 0, 29, 26, 30, 0),
    gsSP1Triangle(23, 26, 29, 0),
    gsSPVertex(D_0400D110_FE170, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP1Triangle(4, 2, 3, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
