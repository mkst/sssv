#include <ultra64.h>

Vtx D_0400E8A0_10E5F0[8] = {
#include "data/inc/D_0400E8A0_10E5F0.inc.c"
};
Vtx D_0400E920_10E670[24] = {
#include "data/inc/D_0400E920_10E670.inc.c"
};

const Gfx D_0400EAA0_10E7F0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400E8A0_10E5F0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400E920_10E670, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
