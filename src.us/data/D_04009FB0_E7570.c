#include <ultra64.h>

Vtx D_04009E20_E73E0[25] = {
#include "data/inc/D_04009E20_E73E0.inc.c"
};

Gfx D_04009FB0_E7570[] = {
    gsSPVertex(D_04009E20_E73E0, 25, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 17, 20, 0),
    gsSP2Triangles(21, 22, 16, 0, 16, 23, 24, 0),
    gsSPEndDisplayList(),
};
