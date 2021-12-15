#include <ultra64.h>

Vtx D_0400D5B0_10D300[8] = {
#include "data/inc/D_0400D5B0_10D300.inc.c"
};
Vtx D_0400D630_10D380[25] = {
#include "data/inc/D_0400D630_10D380.inc.c"
};

Gfx D_0400D7C0_10D510[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400D5B0_10D300, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x1F, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400D630_10D380, 25, 0),
    gsSP1Quadrangle(0, 1, 2, 0, 0),
    gsSP1Quadrangle(0, 0, 0, 0, 0),
    gsSP1Quadrangle(3, 0, 0, 4, 0),
    gsSP1Quadrangle(5, 6, 7, 8, 0),
    gsSP1Quadrangle(0, 2, 4, 0, 0),
    gsSP1Quadrangle(1, 0, 0, 3, 0),
    gsSP1Quadrangle(9, 10, 4, 2, 0),
    gsSP1Quadrangle(10, 11, 3, 4, 0),
    gsSP1Quadrangle(11, 12, 1, 3, 0),
    gsSP1Quadrangle(12, 9, 2, 1, 0),
    gsSP1Quadrangle(8, 7, 10, 9, 0),
    gsSP1Quadrangle(7, 6, 11, 10, 0),
    gsSP1Quadrangle(6, 5, 12, 11, 0),
    gsSP1Quadrangle(5, 8, 9, 12, 0),
    gsSP1Quadrangle(13, 14, 15, 16, 0),
    gsSP1Quadrangle(17, 18, 19, 20, 0),
    gsSP1Quadrangle(21, 22, 23, 24, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
