#include <ultra64.h>

Vtx D_0103B740_75010[20] = {
#include "data/inc/D_0103B740_75010.inc.c"
};

const Gfx D_0103B880_75150[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0103B740_75010, 20, 0),
    gsDPPipeSync(),
    gsSP2Triangles(1, 0, 2, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 0, 4, 0),
    gsSP2Triangles(6, 0, 5, 0, 2, 0, 6, 0),
    gsSP2Triangles(8, 7, 2, 0, 7, 9, 1, 0),
    gsSP2Triangles(9, 10, 3, 0, 10, 11, 4, 0),
    gsSP2Triangles(11, 12, 5, 0, 12, 8, 6, 0),
    gsSP2Triangles(14, 13, 8, 0, 13, 15, 7, 0),
    gsSP2Triangles(15, 16, 9, 0, 16, 17, 10, 0),
    gsSP2Triangles(17, 18, 11, 0, 18, 14, 12, 0),
    gsSP2Triangles(13, 14, 19, 0, 15, 13, 19, 0),
    gsSP2Triangles(16, 15, 19, 0, 17, 16, 19, 0),
    gsSP2Triangles(18, 17, 19, 0, 14, 18, 19, 0),
    gsSP2Triangles(1, 2, 7, 0, 3, 1, 9, 0),
    gsSP2Triangles(4, 3, 10, 0, 5, 4, 11, 0),
    gsSP2Triangles(6, 5, 12, 0, 2, 6, 8, 0),
    gsSP2Triangles(7, 8, 13, 0, 9, 7, 15, 0),
    gsSP2Triangles(10, 9, 16, 0, 11, 10, 17, 0),
    gsSP2Triangles(12, 11, 18, 0, 8, 12, 14, 0),
    gsSPEndDisplayList(),
};
