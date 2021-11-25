#include <ultra64.h>

Vtx D_0400EB10_10E860[8] = {
#include "data/inc/D_0400EB10_10E860.inc.c"
};
Vtx D_0400EB90_10E8E0[12] = {
#include "data/inc/D_0400EB90_10E8E0.inc.c"
};

const Gfx D_0400EC50_10E9A0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400EB10_10E860, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400EB90_10E8E0, 12, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(6, 9, 10, 11, 0),
    gsSP1Quadrangle(0, 5, 6, 11, 0),
    gsSP1Quadrangle(5, 4, 7, 6, 0),
    gsSP1Quadrangle(4, 3, 8, 7, 0),
    gsSP1Quadrangle(3, 2, 9, 8, 0),
    gsSP1Quadrangle(2, 1, 10, 9, 0),
    gsSP1Quadrangle(1, 0, 11, 10, 0),
    gsSPEndDisplayList(),
};
