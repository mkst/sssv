#include <ultra64.h>

Vtx D_0400A7B0_FB810[9] = {
#include "data/inc/D_0400A7B0_FB810.inc.c"
};

Gfx D_0400A840_FB8A0[] = {
    gsSPVertex(D_0400A7B0_FB810, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 3, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 0, 1, 0),
    gsSP2Triangles(0, 6, 7, 0, 6, 5, 7, 0),
    gsSP2Triangles(8, 1, 2, 0, 4, 8, 2, 0),
    gsSP1Quadrangle(8, 4, 6, 1, 0),
    gsSPEndDisplayList(),
};
