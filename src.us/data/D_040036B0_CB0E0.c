#include <ultra64.h>

Vtx D_040035D0_CB000[14] = {
#include "data/inc/D_040035D0_CB000.inc.c"
};

const Gfx D_040036B0_CB0E0[] = {
    gsSPVertex(D_040035D0_CB000, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 6, 5, 0, 0, 2, 6, 0),
    gsSP2Triangles(2, 1, 7, 0, 7, 8, 2, 0),
    gsSP2Triangles(6, 2, 8, 0, 9, 7, 1, 0),
    gsSP2Triangles(1, 3, 9, 0, 10, 9, 3, 0),
    gsSP2Triangles(3, 4, 10, 0, 11, 10, 4, 0),
    gsSP2Triangles(4, 5, 11, 0, 12, 11, 5, 0),
    gsSP2Triangles(8, 12, 6, 0, 5, 6, 12, 0),
    gsSP1Quadrangle(13, 8, 7, 9, 0),
    gsSP1Quadrangle(13, 9, 10, 11, 0),
    gsSP1Quadrangle(13, 11, 12, 8, 0),
    gsSPEndDisplayList(),
};
