#include <ultra64.h>


Vtx D_050070B0_BB980[8] = {
#include "data/inc/D_050070B0_BB980.inc.c"
};
Vtx D_05007130_BBA00[30] = {
#include "data/inc/D_05007130_BBA00.inc.c"
};
Vtx D_05007310_BBBE0[32] = {
#include "data/inc/D_05007310_BBBE0.inc.c"
};
Vtx D_05007510_BBDE0[32] = {
#include "data/inc/D_05007510_BBDE0.inc.c"
};
Vtx D_05007710_BBFE0[19] = {
#include "data/inc/D_05007710_BBFE0.inc.c"
};


Gfx D_05007840_BC110[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_050070B0_BB980, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05007130_BBA00, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 3, 6, 0),
    gsSP1Quadrangle(7, 8, 9, 10, 0),
    gsSP1Quadrangle(1, 5, 11, 12, 0),
    gsSP1Quadrangle(13, 14, 15, 9, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 16, 18, 0),
    gsSP2Triangles(20, 16, 19, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05007310_BBBE0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 7, 0, 7, 8, 5, 0),
    gsSP2Triangles(9, 3, 10, 0, 6, 11, 12, 0),
    gsSP2Triangles(12, 8, 7, 0, 8, 13, 10, 0),
    gsSP1Quadrangle(5, 8, 10, 3, 0),
    gsSP2Triangles(7, 5, 4, 0, 10, 13, 9, 0),
    gsSP2Triangles(12, 7, 6, 0, 4, 3, 6, 0),
    gsSP2Triangles(3, 9, 11, 0, 6, 3, 11, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 22, 0),
    gsSP1Quadrangle(24, 21, 23, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_05007510_BBDE0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 5, 4, 0),
    gsSP2Triangles(3, 2, 4, 0, 1, 4, 2, 0),
    gsSP2Triangles(10, 2, 3, 0, 5, 9, 6, 0),
    gsSP2Triangles(0, 11, 12, 0, 9, 7, 6, 0),
    gsSP2Triangles(13, 8, 14, 0, 5, 6, 15, 0),
    gsSP2Triangles(16, 12, 7, 0, 2, 11, 0, 0),
    gsSP2Triangles(15, 6, 8, 0, 8, 7, 14, 0),
    gsSP2Triangles(14, 7, 11, 0, 12, 11, 7, 0),
    gsSP2Triangles(15, 8, 5, 0, 14, 10, 3, 0),
    gsSP2Triangles(4, 7, 9, 0, 4, 16, 7, 0),
    gsSP2Triangles(14, 3, 13, 0, 8, 3, 5, 0),
    gsSP2Triangles(10, 14, 11, 0, 1, 12, 16, 0),
    gsSP2Triangles(1, 0, 12, 0, 2, 10, 11, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 18, 17, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 22, 21, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 27, 26, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05007710_BBFE0, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 1, 8, 9, 0),
    gsSP2Triangles(9, 3, 2, 0, 7, 3, 10, 0),
    gsSP2Triangles(8, 11, 12, 0, 12, 3, 9, 0),
    gsSP2Triangles(4, 3, 7, 0, 11, 5, 10, 0),
    gsSP2Triangles(10, 3, 12, 0, 5, 11, 13, 0),
    gsSP2Triangles(11, 8, 14, 0, 14, 15, 13, 0),
    gsSP2Triangles(6, 5, 16, 0, 8, 1, 17, 0),
    gsSP2Triangles(17, 15, 14, 0, 16, 15, 18, 0),
    gsSP2Triangles(13, 15, 16, 0, 4, 7, 6, 0),
    gsSP2Triangles(2, 4, 0, 0, 7, 10, 5, 0),
    gsSP2Triangles(9, 2, 1, 0, 12, 9, 8, 0),
    gsSP2Triangles(10, 12, 11, 0, 13, 16, 5, 0),
    gsSP2Triangles(14, 13, 11, 0, 16, 18, 6, 0),
    gsSP1Triangle(17, 14, 8, 0),
    gsSPEndDisplayList(),
};
