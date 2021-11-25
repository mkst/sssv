#include <ultra64.h>

Vtx D_0400E000_10DD50[8] = {
#include "data/inc/D_0400E000_10DD50.inc.c"
};
Vtx D_0400E080_10DDD0[32] = {
#include "data/inc/D_0400E080_10DDD0.inc.c"
};
Vtx D_0400E280_10DFD0[31] = {
#include "data/inc/D_0400E280_10DFD0.inc.c"
};
Vtx D_0400E470_10E1C0[30] = {
#include "data/inc/D_0400E470_10E1C0.inc.c"
};
Vtx D_0400E650_10E3A0[18] = {
#include "data/inc/D_0400E650_10E3A0.inc.c"
};

const Gfx D_0400E770_10E4C0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400E000_10DD50, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400E080_10DDD0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400E280_10DFD0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 19, 20, 0),
    gsSP1Quadrangle(21, 22, 23, 24, 0),
    gsSP2Triangles(16, 25, 21, 0, 26, 17, 27, 0),
    gsSP2Triangles(26, 27, 28, 0, 16, 29, 30, 0),
    gsSPVertex(D_0400E470_10E1C0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSPVertex(D_0400E650_10E3A0, 18, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(8, 12, 9, 0, 13, 14, 15, 0),
    gsSP2Triangles(14, 16, 15, 0, 13, 17, 14, 0),
    gsSPEndDisplayList(),
};
