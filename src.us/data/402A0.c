#include <ultra64.h>

Vtx D_010066D0_3FFA0[] = {
#include "data/inc/D_010066D0_3FFA00.inc.c"
};

const Gfx D_010069D0_402A0[] = {
    gsSPVertex(D_010066D0_3FFA0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
