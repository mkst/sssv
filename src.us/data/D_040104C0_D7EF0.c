#include <ultra64.h>

Vtx D_040100E0_D7B10[31] = {
#include "data/inc/D_040100E0_D7B10.inc.c"
};
Vtx D_040102D0_D7D00[31] = {
#include "data/inc/D_040102D0_D7D00.inc.c"
};

Gfx D_040104C0_D7EF0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_040100E0_D7B10, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 0, 2, 0, 4, 5, 6, 0),
    gsSP2Triangles(5, 7, 8, 0, 7, 4, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 11, 13, 14, 0),
    gsSP2Triangles(13, 10, 15, 0, 15, 16, 17, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 15, 17, 0),
    gsSP2Triangles(19, 20, 21, 0, 21, 22, 19, 0),
    gsSP2Triangles(20, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 27, 0, 28, 30, 29, 0),
    gsSPVertex(D_040102D0_D7D00, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 3, 8, 9, 0),
    gsSP2Triangles(10, 0, 9, 0, 9, 8, 10, 0),
    gsSP2Triangles(4, 2, 1, 0, 3, 11, 8, 0),
    gsSP2Triangles(2, 9, 0, 0, 5, 4, 6, 0),
    gsSP2Triangles(7, 12, 11, 0, 3, 5, 11, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 13, 17, 0),
    gsSP2Triangles(14, 16, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 19, 23, 0, 20, 22, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 26, 28, 29, 0),
    gsSP2Triangles(28, 25, 30, 0, 27, 30, 25, 0),
    gsSP2Triangles(29, 27, 26, 0, 30, 29, 28, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
