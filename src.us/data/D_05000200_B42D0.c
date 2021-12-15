#include <ultra64.h>

Vtx D_05000000_B40D0[8] = {
#include "data/inc/D_05000000_B40D0.inc.c"
};
Vtx D_05000080_B4150[24] = {
#include "data/inc/D_05000080_B4150.inc.c"
};

Gfx D_05000200_B42D0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_B40D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000080_B4150, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSP1Quadrangle(3, 2, 7, 5, 0),
    gsSP1Quadrangle(1, 0, 4, 6, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 8, 11, 13, 0),
    gsSP1Quadrangle(14, 12, 13, 15, 0),
    gsSP1Quadrangle(9, 14, 15, 10, 0),
    gsSP1Quadrangle(11, 10, 15, 13, 0),
    gsSP1Quadrangle(9, 8, 12, 14, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(17, 16, 20, 21, 0),
    gsSP1Quadrangle(21, 20, 22, 23, 0),
    gsSP1Quadrangle(17, 21, 23, 18, 0),
    gsSP1Quadrangle(19, 18, 23, 22, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
