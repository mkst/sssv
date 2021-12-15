#include <ultra64.h>

Vtx D_040054B0_CCEE0[5] = {
#include "data/inc/D_040054B0_CCEE0.inc.c"
};
Vtx D_04005500_CCF30[8] = {
#include "data/inc/D_04005500_CCF30.inc.c"
};

Gfx D_04005580_CCFB0[] = {
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSPVertex(D_040054B0_CCEE0, 5, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(3, 4, 0, 0, 1, 0, 4, 0),
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSPVertex(D_04005500_CCF30, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(3, 1, 0, 0, 4, 0, 2, 0),
    gsSP2Triangles(4, 5, 0, 0, 6, 0, 5, 0),
    gsSP2Triangles(6, 3, 0, 0, 3, 6, 7, 0),
    gsSP2Triangles(3, 7, 2, 0, 2, 7, 4, 0),
    gsSPEndDisplayList(),
};
