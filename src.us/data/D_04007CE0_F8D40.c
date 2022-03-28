#include <ultra64.h>

Vtx D_04007BE0_F8C40[16] = {
#include "data/inc/D_04007BE0_F8C40.inc.c"
};

Gfx D_04007CE0_F8D40[] = {
    gsSPVertex(D_04007BE0_F8C40, 16, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(3, 4, 0, 0, 4, 5, 0, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 11, 10, 8, 0),
    gsSP2Triangles(10, 11, 12, 0, 1, 2, 12, 0),
    gsSP2Triangles(10, 12, 13, 0, 12, 2, 13, 0),
    gsSP2Triangles(14, 13, 2, 0, 0, 14, 2, 0),
    gsSP2Triangles(0, 5, 14, 0, 5, 7, 14, 0),
    gsSP2Triangles(14, 7, 9, 0, 10, 14, 9, 0),
    gsSP2Triangles(10, 13, 14, 0, 15, 12, 11, 0),
    gsSP2Triangles(8, 15, 11, 0, 8, 6, 15, 0),
    gsSP2Triangles(6, 4, 15, 0, 4, 3, 15, 0),
    gsSP2Triangles(3, 1, 15, 0, 15, 1, 12, 0),
    gsSPEndDisplayList(),
};
