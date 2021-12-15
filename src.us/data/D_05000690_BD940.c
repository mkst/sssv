#include <ultra64.h>

Vtx D_05000330_BD5E0[8] = {
#include "data/inc/D_05000330_BD5E0.inc.c"
};
Vtx D_050003B0_BD660[31] = {
#include "data/inc/D_050003B0_BD660.inc.c"
};
Vtx D_050005A0_BD850[15] = {
#include "data/inc/D_050005A0_BD850.inc.c"
};

Gfx D_05000690_BD940[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000330_BD5E0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_050003B0_BD660, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 0, 10, 0),
    gsSP1Quadrangle(11, 12, 13, 14, 0),
    gsSP1Quadrangle(15, 8, 16, 17, 0),
    gsSP1Quadrangle(18, 11, 14, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 18, 0, 26, 27, 28, 0),
    gsSP2Triangles(26, 28, 29, 0, 19, 30, 24, 0),
    gsSPVertex(D_050005A0_BD850, 15, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP1Triangle(11, 13, 14, 0),
    gsSPEndDisplayList(),
};
