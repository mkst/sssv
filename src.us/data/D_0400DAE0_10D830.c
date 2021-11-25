#include <ultra64.h>

Vtx D_0400D8A0_10D5F0[8] = {
#include "data/inc/D_0400D8A0_10D5F0.inc.c"
};
Vtx D_0400D920_10D670[28] = {
#include "data/inc/D_0400D920_10D670.inc.c"
};

const Gfx D_0400DAE0_10D830[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400D8A0_10D5F0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400D920_10D670, 28, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(3, 2, 7, 5, 0),
    gsSP1Quadrangle(1, 0, 4, 6, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(11, 10, 7, 2, 0),
    gsSP1Quadrangle(10, 9, 6, 7, 0),
    gsSP1Quadrangle(9, 8, 1, 6, 0),
    gsSP1Quadrangle(8, 11, 2, 1, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
