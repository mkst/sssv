#include <ultra64.h>

Vtx D_0400C9E0_10C730[8] = {
#include "data/inc/D_0400C9E0_10C730.inc.c"
};
Vtx D_0400CA60_10C7B0[31] = {
#include "data/inc/D_0400CA60_10C7B0.inc.c"
};
Vtx D_0400CC50_10C9A0[26] = {
#include "data/inc/D_0400CC50_10C9A0.inc.c"
};

const Gfx D_0400CDF0_10CB40[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400C9E0_10C730, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400CA60_10C7B0, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(1, 6, 7, 2, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 4, 6, 0),
    gsSP1Quadrangle(13, 14, 0, 4, 0),
    gsSP1Quadrangle(14, 15, 1, 0, 0),
    gsSP1Quadrangle(15, 12, 6, 1, 0),
    gsSP1Quadrangle(16, 17, 13, 12, 0),
    gsSP1Quadrangle(17, 18, 14, 13, 0),
    gsSP1Quadrangle(18, 19, 15, 14, 0),
    gsSP1Quadrangle(19, 16, 12, 15, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 25, 29, 30, 0),
    gsSPVertex(D_0400CC50_10C9A0, 26, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(16, 20, 21, 22, 0),
    gsSP1Quadrangle(23, 24, 21, 25, 0),
    gsSPEndDisplayList(),
};
