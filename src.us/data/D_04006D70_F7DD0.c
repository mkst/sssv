#include <ultra64.h>

Vtx D_04006CD0_F7D30[10] = {
#include "data/inc/D_04006CD0_F7D30.inc.c"
};

Gfx D_04006D70_F7DD0[] = {
    gsSPVertex(D_04006CD0_F7D30, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(1, 4, 3, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 1, 6, 0),
    gsSP2Triangles(6, 1, 0, 0, 7, 6, 0, 0),
    gsSP1Quadrangle(5, 6, 7, 8, 0),
    gsSP2Triangles(9, 5, 8, 0, 3, 5, 9, 0),
    gsSP2Triangles(3, 9, 2, 0, 2, 9, 8, 0),
    gsSPEndDisplayList(),
};
