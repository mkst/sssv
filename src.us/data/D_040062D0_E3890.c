#include <ultra64.h>

Vtx D_040061E0_E37A0[6] = {
#include "data/inc/D_040061E0_E37A0.inc.c"
};
Vtx D_04006240_E3800[9] = {
#include "data/inc/D_04006240_E3800.inc.c"
};

const Gfx D_040062D0_E3890[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040061E0_E37A0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 4, 3, 0, 3, 1, 5, 0),
    gsSPVertex(D_04006240_E3800, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 1, 6, 0, 0),
    gsSP2Triangles(6, 1, 4, 0, 6, 5, 7, 0),
    gsSP2Triangles(7, 2, 3, 0, 2, 7, 5, 0),
    gsSP1Quadrangle(8, 7, 3, 0, 0),
    gsSP1Quadrangle(8, 0, 6, 7, 0),
    gsSPEndDisplayList(),
};
