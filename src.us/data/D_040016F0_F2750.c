#include <ultra64.h>

Vtx D_040016A0_F2700[5] = {
#include "data/inc/D_040016A0_F2700.inc.c"
};

Gfx D_040016F0_F2750[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040016A0_F2700, 5, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 1, 0, 4, 0, 3, 0),
    gsSP1Quadrangle(4, 3, 1, 0, 0),
    gsSPEndDisplayList(),
};
