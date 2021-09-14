#include <ultra64.h>

Vtx D_0101A620_53EF0[24] = {
#include "data/inc/D_0101A620_53EF0.inc.c"
};

const Gfx D_0101A7A0_54070[] = {
    gsSPVertex(D_0101A620_53EF0, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(21, 22, 19, 0, 18, 23, 16, 0),
    gsSPEndDisplayList(),
};
