#include <ultra64.h>

Vtx D_04005440_CCE70[4] = {
#include "data/inc/D_04005440_CCE70.inc.c"
};

const Gfx D_04005480_CCEB0[] = {
    gsSPVertex(D_04005440_CCE70, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 1, 0),
    gsSP2Triangles(2, 1, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(3, 1, 1, 0, 2, 3, 1, 0),
    gsSPEndDisplayList(),
};
