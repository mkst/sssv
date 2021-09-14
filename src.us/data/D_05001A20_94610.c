#include <ultra64.h>

Vtx D_050017F0_943E0[32] = {
#include "data/inc/D_050017F0_943E0.inc.c"
};
Vtx D_050019F0_945E0[3] = {
#include "data/inc/D_050019F0_945E0.inc.c"
};

const Gfx D_05001A20_94610[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050017F0_943E0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(13, 16, 17, 14, 0),
    gsSP1Quadrangle(16, 12, 15, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(21, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_050019F0_945E0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
