#include <ultra64.h>

Vtx D_04004270_CBCA0[6] = {
#include "data/inc/D_04004270_CBCA0.inc.c"
};
Vtx D_040042D0_CBD00[6] = {
#include "data/inc/D_040042D0_CBD00.inc.c"
};

const Gfx D_04004330_CBD60[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0x20, 0x00, 0xFF),
    gsSPVertex(D_04004270_CBCA0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 0, 1, 0, 0, 4, 5, 0),
    gsSP1Quadrangle(2, 3, 5, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040042D0_CBD00, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 1, 4, 0, 0),
    gsSP2Triangles(4, 2, 5, 0, 0, 5, 3, 0),
    gsSP1Triangle(5, 0, 4, 0),
    gsSPEndDisplayList(),
};
