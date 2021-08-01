#include <ultra64.h>

Vtx D_04001250_DE810[9] = {
#include "data/inc/D_04001250_DE810.inc.c"
};

const Gfx D_040012E0_DE8A0[] = {
    gsSPVertex(D_04001250_DE810, 9, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(1, 4, 0, 0, 4, 1, 5, 0),
    gsSP2Triangles(2, 5, 1, 0, 6, 4, 5, 0),
    gsSP2Triangles(5, 2, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 2, 3, 0, 2, 7, 6, 0),
    gsSP1Quadrangle(8, 7, 3, 0, 0),
    gsSP1Quadrangle(8, 0, 4, 7, 0),
    gsSPEndDisplayList(),
};
