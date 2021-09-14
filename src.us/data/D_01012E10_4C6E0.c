#include <ultra64.h>

Vtx D_01012C60_4C530[27] = {
#include "data/inc/D_01012C60_4C530.inc.c"
};

const Gfx D_01012E10_4C6E0[] = {
    gsSPVertex(D_01012C60_4C530, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 11, 0, 1, 10, 12, 0),
    gsSP2Triangles(9, 11, 7, 0, 11, 12, 10, 0),
    gsSP2Triangles(12, 2, 1, 0, 2, 4, 0, 0),
    gsSP2Triangles(4, 6, 3, 0, 6, 13, 5, 0),
    gsSP2Triangles(14, 15, 16, 0, 14, 17, 15, 0),
    gsSP1Quadrangle(18, 19, 20, 20, 0),
    gsSP1Quadrangle(21, 21, 18, 20, 0),
    gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
    gsSP1Quadrangle(24, 16, 25, 26, 0),
    gsSP1Quadrangle(16, 26, 14, 14, 0),
    gsSPEndDisplayList(),
};
