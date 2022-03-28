#include <ultra64.h>

Vtx D_04008F80_F9FE0[7] = {
#include "data/inc/D_04008F80_F9FE0.inc.c"
};

Gfx D_04008FF0_FA050[] = {
    gsSPVertex(D_04008F80_F9FE0, 7, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP1Quadrangle(5, 4, 2, 0, 0),
    gsSP2Triangles(6, 1, 2, 0, 4, 1, 6, 0),
    gsSP1Triangle(4, 6, 2, 0),
    gsSPEndDisplayList(),
};
