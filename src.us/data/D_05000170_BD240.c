#include <ultra64.h>

Vtx D_05000000_BD0D0[8] = {
#include "data/inc/D_05000000_BD0D0.inc.c"
};
Vtx D_05000080_BD150[10] = {
#include "data/inc/D_05000080_BD150.inc.c"
};
Vtx D_05000120_BD1F0[5] = {
#include "data/inc/D_05000120_BD1F0.inc.c"
};

const Gfx D_05000170_BD240[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_BD0D0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05000080_BD150, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 1, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 1, 0, 9, 0),
    gsSPVertex(D_05000120_BD1F0, 5, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Triangle(2, 4, 3, 0),
    gsSPEndDisplayList(),
};
