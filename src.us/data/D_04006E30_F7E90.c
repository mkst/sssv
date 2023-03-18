#include <ultra64.h>

Vtx D_04006DC0_F7E20[7] = {
#include "data/inc/D_04006DC0_F7E20.inc.c"
};

Gfx D_04006E30_F7E90[] = {
    gsSPVertex(D_04006DC0_F7E20, 7, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(4, 2, 1, 0, 0, 3, 5, 0),
    gsSP1Quadrangle(5, 3, 4, 1, 0),
    gsSP2Triangles(6, 2, 4, 0, 3, 2, 6, 0),
    gsSP1Triangle(3, 6, 4, 0),
    gsSPEndDisplayList(),
};
