#include <ultra64.h>

Vtx D_01012000_4B8D0[8] = {
#include "data/inc/D_01012000_4B8D0.inc.c"
};
Vtx D_01012080_4B950[31] = {
#include "data/inc/D_01012080_4B950.inc.c"
};
Vtx D_01012270_4BB40[3] = {
#include "data/inc/D_01012270_4BB40.inc.c"
};

Gfx D_010122A0_4BB70[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01012000_4B8D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01012080_4B950, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(2, 24, 0, 0, 5, 25, 3, 0),
    gsSP2Triangles(8, 26, 6, 0, 11, 27, 9, 0),
    gsSP2Triangles(14, 28, 12, 0, 17, 29, 15, 0),
    gsSP1Triangle(20, 30, 18, 0),
    gsSPVertex(D_01012270_4BB40, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
