#include <ultra64.h>

Vtx D_01004FE0_3E8B0[8] = {
#include "data/inc/D_01004FE0_3E8B0.inc.c"
};

const Gfx D_01005060_3E930[] = {
    gsSPVertex(D_01004FE0_3E8B0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(3, 1, 2, 0, 2, 0, 4, 0),
    gsSP2Triangles(2, 0, 4, 0, 1, 3, 5, 0),
    gsSP2Triangles(1, 3, 5, 0, 6, 5, 3, 0),
    gsSP2Triangles(6, 5, 3, 0, 5, 6, 7, 0),
    gsSP1Triangle(5, 6, 7, 0),
    gsSPEndDisplayList(),
};
