#include <ultra64.h>

Vtx D_040037B0_EAD60[15] = {
#include "data/inc/D_040037B0_EAD60.inc.c"
};

Gfx D_040038A0_EAE50[] = {
    gsSPVertex(D_040037B0_EAD60, 15, 0),
    gsSP2Triangles(0, 1, 1, 0, 2, 1, 1, 0),
    gsSP2Triangles(1, 2, 0, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 1, 1, 0, 1, 4, 2, 0),
    gsSP2Triangles(2, 4, 5, 0, 5, 3, 2, 0),
    gsSP2Triangles(6, 3, 5, 0, 3, 6, 6, 0),
    gsSP2Triangles(5, 6, 6, 0, 6, 7, 3, 0),
    gsSP2Triangles(3, 7, 0, 0, 7, 6, 6, 0),
    gsSP2Triangles(6, 5, 8, 0, 8, 5, 4, 0),
    gsSP2Triangles(8, 6, 6, 0, 4, 9, 8, 0),
    gsSP2Triangles(1, 9, 4, 0, 9, 1, 1, 0),
    gsSP2Triangles(10, 1, 1, 0, 10, 0, 7, 0),
    gsSP2Triangles(1, 0, 10, 0, 6, 11, 7, 0),
    gsSP2Triangles(7, 11, 10, 0, 11, 6, 6, 0),
    gsSP1Quadrangle(6, 8, 12, 11, 0),
    gsSP2Triangles(12, 8, 9, 0, 12, 6, 6, 0),
    gsSP2Triangles(9, 13, 12, 0, 13, 1, 1, 0),
    gsSP2Triangles(13, 10, 11, 0, 1, 13, 9, 0),
    gsSP2Triangles(1, 10, 13, 0, 11, 12, 13, 0),
    gsSPEndDisplayList(),
};
