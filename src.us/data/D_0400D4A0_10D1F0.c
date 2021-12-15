#include <ultra64.h>

Vtx D_0400CEE0_10CC30[8] = {
#include "data/inc/D_0400CEE0_10CC30.inc.c"
};
Vtx D_0400CF60_10CCB0[32] = {
#include "data/inc/D_0400CF60_10CCB0.inc.c"
};
Vtx D_0400D160_10CEB0[32] = {
#include "data/inc/D_0400D160_10CEB0.inc.c"
};
Vtx D_0400D360_10D0B0[20] = {
#include "data/inc/D_0400D360_10D0B0.inc.c"
};

Gfx D_0400D4A0_10D1F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400CEE0_10CC30, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400CF60_10CCB0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(0, 3, 1, 0, 0, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 7, 10, 0),
    gsSP2Triangles(11, 12, 5, 0, 5, 12, 13, 0),
    gsSP2Triangles(5, 13, 6, 0, 6, 13, 14, 0),
    gsSP1Quadrangle(15, 16, 17, 18, 0),
    gsSP1Quadrangle(19, 20, 21, 22, 0),
    gsSP1Quadrangle(16, 15, 20, 19, 0),
    gsSP1Quadrangle(18, 17, 22, 21, 0),
    gsSP2Triangles(9, 23, 24, 0, 6, 14, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_0400D160_10CEB0, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 14, 0, 20, 21, 14, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400D360_10D0B0, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 1, 5, 6, 0),
    gsSP1Quadrangle(4, 7, 8, 9, 0),
    gsSP1Quadrangle(2, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
    gsSP1Triangle(18, 19, 16, 0),
    gsSPEndDisplayList(),
};
