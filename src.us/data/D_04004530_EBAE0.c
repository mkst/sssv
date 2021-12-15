#include <ultra64.h>

Vtx D_040043B0_EB960[24] = {
#include "data/inc/D_040043B0_EB960.inc.c"
};

Gfx D_04004530_EBAE0[] = {
    gsDPSetPrimColor(0, 0, 0xAA, 0x55, 0x00, 0xFF),
    gsSPVertex(D_040043B0_EB960, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 3, 4, 0, 5, 4, 3, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP2Triangles(4, 8, 2, 0, 6, 8, 4, 0),
    gsSP2Triangles(9, 2, 8, 0, 2, 9, 0, 0),
    gsSP1Quadrangle(10, 1, 0, 11, 0),
    gsSP2Triangles(11, 0, 9, 0, 9, 12, 11, 0),
    gsSP2Triangles(13, 11, 12, 0, 10, 11, 13, 0),
    gsSP2Triangles(12, 14, 13, 0, 15, 13, 14, 0),
    gsSP2Triangles(10, 13, 15, 0, 14, 16, 15, 0),
    gsSP2Triangles(17, 15, 16, 0, 10, 15, 17, 0),
    gsSP2Triangles(18, 7, 16, 0, 16, 14, 18, 0),
    gsSP2Triangles(6, 7, 18, 0, 19, 18, 14, 0),
    gsSP2Triangles(6, 18, 19, 0, 14, 12, 19, 0),
    gsSP2Triangles(20, 19, 12, 0, 6, 19, 20, 0),
    gsSP2Triangles(6, 20, 8, 0, 21, 16, 7, 0),
    gsSP2Triangles(16, 21, 17, 0, 7, 5, 21, 0),
    gsSP2Triangles(3, 21, 5, 0, 10, 17, 22, 0),
    gsSP2Triangles(10, 22, 1, 0, 22, 17, 21, 0),
    gsSP2Triangles(21, 3, 22, 0, 1, 22, 3, 0),
    gsSP2Triangles(8, 20, 23, 0, 12, 23, 20, 0),
    gsSPEndDisplayList(),
};
