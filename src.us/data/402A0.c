#include <ultra64.h>

Vtx D_010066D0_3FFA0[] = {
#include "data/inc/D_010066D0_3FFA0.inc.c"
};

Vtx D_01006750_40020[] = {
#include "data/inc/D_01006750_40020.inc.c"
};

Gfx D_010069D0_402A0[] = {
    gsSPVertex(D_010066D0_3FFA0, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_010006A08_402D8[] = {
    gsSPVertex(D_01006750_40020, 8, 0),
    gsSP1Quadrangle(0, 1, 5, 4, 0),
    gsSP1Quadrangle(0, 4, 7, 3, 0),
    gsSP1Quadrangle(2, 3, 7, 6, 0),
    gsSP2Triangles(1, 2, 6, 0, 6, 5, 1, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
