#include <ultra64.h>

Vtx D_04008D00_F9D60[7] = {
#include "data/inc/D_04008D00_F9D60.inc.c"
};

Gfx D_04008D70_F9DD0[] = {
    gsSPVertex(D_04008D00_F9D60, 7, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP1Quadrangle(5, 4, 2, 0, 0),
    gsSP2Triangles(6, 1, 2, 0, 4, 1, 6, 0),
    gsSP1Triangle(4, 6, 2, 0),
    gsSPEndDisplayList(),
};
