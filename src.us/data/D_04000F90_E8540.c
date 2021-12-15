#include <ultra64.h>

Vtx D_04000DF0_E83A0[26] = {
#include "data/inc/D_04000DF0_E83A0.inc.c"
};

Gfx D_04000F90_E8540[] = {
    gsSPVertex(D_04000DF0_E83A0, 26, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 4, 2, 5, 0),
    gsSP2Triangles(6, 5, 2, 0, 0, 6, 2, 0),
    gsSP2Triangles(5, 7, 4, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 8, 5, 0, 5, 6, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 0, 10, 6, 0),
    gsSP1Quadrangle(11, 7, 8, 12, 0),
    gsSP2Triangles(8, 9, 12, 0, 13, 12, 9, 0),
    gsSP2Triangles(9, 10, 13, 0, 14, 13, 10, 0),
    gsSP2Triangles(0, 14, 10, 0, 11, 12, 15, 0),
    gsSP2Triangles(12, 13, 15, 0, 16, 15, 13, 0),
    gsSP2Triangles(13, 14, 16, 0, 17, 16, 14, 0),
    gsSP2Triangles(0, 17, 14, 0, 11, 15, 18, 0),
    gsSP2Triangles(15, 16, 18, 0, 19, 18, 16, 0),
    gsSP2Triangles(16, 17, 19, 0, 11, 18, 20, 0),
    gsSP2Triangles(18, 19, 20, 0, 0, 21, 17, 0),
    gsSP2Triangles(21, 19, 17, 0, 0, 3, 21, 0),
    gsSP2Triangles(22, 1, 4, 0, 1, 22, 3, 0),
    gsSP2Triangles(4, 23, 22, 0, 11, 23, 7, 0),
    gsSP2Triangles(23, 4, 7, 0, 3, 24, 21, 0),
    gsSP2Triangles(19, 21, 24, 0, 24, 20, 19, 0),
    gsSP2Triangles(24, 3, 22, 0, 22, 25, 24, 0),
    gsSP2Triangles(11, 25, 23, 0, 11, 20, 25, 0),
    gsSP2Triangles(25, 22, 23, 0, 20, 24, 25, 0),
    gsSPEndDisplayList(),
};
