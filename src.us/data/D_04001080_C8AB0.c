#include <ultra64.h>

Vtx D_04001000_C8A30[8] = {
#include "data/inc/D_04001000_C8A30.inc.c"
};

Gfx D_04001080_C8AB0[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_04001000_C8A30, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 3, 0),
    gsSP2Triangles(4, 5, 0, 0, 2, 0, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 1, 2, 0),
    gsSP2Triangles(1, 6, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(6, 2, 7, 0, 2, 5, 7, 0),
    gsSPEndDisplayList(),
};
