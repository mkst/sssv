#include <ultra64.h>

Vtx D_050045B0_AEEF0[8] = {
#include "data/inc/D_050045B0_AEEF0.inc.c"
};
Vtx D_05004630_AEF70[28] = {
#include "data/inc/D_05004630_AEF70.inc.c"
};

Gfx D_050047F0_AF130[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_050045B0_AEEF0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05004630_AEF70, 28, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
    gsSP2Triangles(19, 20, 18, 0, 20, 21, 18, 0),
    gsSP2Triangles(22, 23, 24, 0, 23, 25, 24, 0),
    gsSP2Triangles(25, 26, 24, 0, 26, 27, 24, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
