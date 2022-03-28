#include <ultra64.h>

Vtx D_04007A60_F8AC0[16] = {
#include "data/inc/D_04007A60_F8AC0.inc.c"
};

Gfx D_04007B60_F8BC0[] = {
    gsSPVertex(D_04007A60_F8AC0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(3, 0, 4, 0, 4, 0, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSP2Triangles(10, 8, 9, 0, 11, 8, 10, 0),
    gsSP2Triangles(10, 12, 11, 0, 1, 12, 2, 0),
    gsSP2Triangles(10, 13, 12, 0, 12, 13, 2, 0),
    gsSP2Triangles(14, 2, 13, 0, 0, 2, 14, 0),
    gsSP2Triangles(0, 14, 5, 0, 5, 14, 7, 0),
    gsSP2Triangles(14, 9, 7, 0, 10, 9, 14, 0),
    gsSP2Triangles(10, 14, 13, 0, 15, 11, 12, 0),
    gsSP1Quadrangle(8, 11, 15, 6, 0),
    gsSP2Triangles(6, 15, 4, 0, 4, 15, 3, 0),
    gsSP2Triangles(3, 15, 1, 0, 15, 12, 1, 0),
    gsSPEndDisplayList(),
};
