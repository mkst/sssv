#include <ultra64.h>

Vtx D_04006A10_F7A70[11] = {
#include "data/inc/D_04006A10_F7A70.inc.c"
};

Gfx D_04006AC0_F7B20[] = {
    gsSPVertex(D_04006A10_F7A70, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 3, 1, 0, 2, 4, 0, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(2, 3, 5, 0, 2, 6, 4, 0),
    gsSP2Triangles(2, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 4, 7, 0, 8, 9, 4, 0),
    gsSP2Triangles(9, 5, 4, 0, 6, 5, 10, 0),
    gsSP1Triangle(10, 7, 6, 0),
    gsSPEndDisplayList(),
};
