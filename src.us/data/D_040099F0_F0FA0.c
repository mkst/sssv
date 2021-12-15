#include <ultra64.h>

Vtx D_04009850_F0E00[26] = {
#include "data/inc/D_04009850_F0E00.inc.c"
};

Gfx D_040099F0_F0FA0[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04009850_F0E00, 26, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(6, 1, 9, 0, 6, 2, 1, 0),
    gsSP2Triangles(8, 10, 2, 0, 8, 7, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(5, 10, 17, 0, 5, 2, 10, 0),
    gsSP2Triangles(18, 14, 19, 0, 20, 19, 1, 0),
    gsSP2Triangles(4, 21, 18, 0, 4, 3, 21, 0),
    gsSP2Triangles(16, 14, 13, 0, 9, 22, 7, 0),
    gsSP2Triangles(9, 19, 15, 0, 9, 1, 19, 0),
    gsSP2Triangles(12, 14, 18, 0, 11, 13, 10, 0),
    gsSP2Triangles(11, 22, 16, 0, 11, 7, 22, 0),
    gsSP2Triangles(15, 19, 14, 0, 17, 23, 24, 0),
    gsSP2Triangles(17, 13, 12, 0, 17, 10, 13, 0),
    gsSP2Triangles(11, 16, 13, 0, 8, 11, 10, 0),
    gsSP2Triangles(6, 8, 2, 0, 6, 9, 7, 0),
    gsSP2Triangles(9, 15, 22, 0, 15, 16, 22, 0),
    gsSP2Triangles(17, 12, 23, 0, 5, 17, 24, 0),
    gsSP2Triangles(12, 18, 21, 0, 20, 18, 19, 0),
    gsSP2Triangles(0, 20, 1, 0, 0, 5, 25, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
