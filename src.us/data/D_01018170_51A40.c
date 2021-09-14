#include <ultra64.h>

Vtx D_01017F00_517D0[19] = {
#include "data/inc/D_01017F00_517D0.inc.c"
};
Vtx D_01018030_51900[20] = {
#include "data/inc/D_01018030_51900.inc.c"
};

const Gfx D_01018170_51A40[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x1D, 0x1C, 0x19, 0xFF),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_01017F00_517D0, 19, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 2, 1, 0, 5, 4, 1, 0),
    gsSP2Triangles(6, 4, 5, 0, 7, 4, 8, 0),
    gsSP1Quadrangle(9, 10, 11, 12, 0),
    gsSP2Triangles(13, 10, 9, 0, 9, 14, 13, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 15, 17, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x61, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_01018030_51900, 20, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 1, 0, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Quadrangle(8, 9, 7, 6, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(11, 14, 15, 12, 0),
    gsSP1Quadrangle(14, 16, 17, 15, 0),
    gsSP1Quadrangle(16, 18, 19, 17, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
