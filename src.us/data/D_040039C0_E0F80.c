#include <ultra64.h>

Vtx D_04003960_E0F20[6] = {
#include "data/inc/D_04003960_E0F20.inc.c"
};

const Gfx D_040039C0_E0F80[] = {
    gsSPVertex(D_04003960_E0F20, 6, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 1, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 4, 3, 0, 5, 1, 4, 0),
    gsSPEndDisplayList(),
};
