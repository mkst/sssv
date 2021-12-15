#include <ultra64.h>

Vtx D_0400DB90_10D8E0[8] = {
#include "data/inc/D_0400DB90_10D8E0.inc.c"
};
Vtx D_0400DC10_10D960[32] = {
#include "data/inc/D_0400DC10_10D960.inc.c"
};
Vtx D_0400DE10_10DB60[20] = {
#include "data/inc/D_0400DE10_10DB60.inc.c"
};

Gfx D_0400DF50_10DCA0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400DB90_10D8E0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400DC10_10D960, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(1, 4, 5, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 2, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(10, 12, 13, 0, 8, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(13, 20, 21, 22, 0),
    gsSP1Quadrangle(23, 10, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_0400DE10_10DB60, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
