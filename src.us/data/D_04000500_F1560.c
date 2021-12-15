#include <ultra64.h>

Vtx D_040003D0_F1430[10] = {
#include "data/inc/D_040003D0_F1430.inc.c"
};
Vtx D_04000470_F14D0[9] = {
#include "data/inc/D_04000470_F14D0.inc.c"
};

Gfx D_04000500_F1560[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xDA, 0x1C, 0xFF),
    gsSPVertex(D_040003D0_F1430, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(0, 3, 4, 0, 3, 2, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 6, 4, 3, 0),
    gsSP2Triangles(6, 7, 4, 0, 4, 7, 0, 0),
    gsSP1Quadrangle(8, 7, 6, 5, 0),
    gsSP2Triangles(5, 9, 8, 0, 9, 0, 7, 0),
    gsSP2Triangles(9, 5, 2, 0, 2, 1, 9, 0),
    gsSP2Triangles(0, 9, 1, 0, 7, 8, 9, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04000470_F14D0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPEndDisplayList(),
};
