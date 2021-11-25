#include <ultra64.h>

Vtx D_04004900_E1EC0[30] = {
#include "data/inc/D_04004900_E1EC0.inc.c"
};

extern Gfx D_010034C0_3CD90[];

const Gfx D_04004AE0_E20A0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04004900_E1EC0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(6, 5, 4, 0, 7, 5, 6, 0),
    gsSP2Triangles(8, 5, 7, 0, 9, 8, 7, 0),
    gsSP2Triangles(10, 4, 2, 0, 11, 6, 4, 0),
    gsSP2Triangles(12, 2, 1, 0, 13, 9, 7, 0),
    gsSP2Triangles(14, 7, 6, 0, 15, 5, 8, 0),
    gsSP1Quadrangle(16, 15, 8, 9, 0),
    gsSP2Triangles(16, 17, 15, 0, 17, 7, 14, 0),
    gsSP2Triangles(17, 18, 15, 0, 18, 6, 11, 0),
    gsSP2Triangles(18, 19, 15, 0, 19, 4, 10, 0),
    gsSP2Triangles(15, 19, 20, 0, 20, 3, 5, 0),
    gsSP2Triangles(15, 20, 5, 0, 19, 21, 20, 0),
    gsSP2Triangles(21, 2, 12, 0, 20, 21, 22, 0),
    gsSP2Triangles(22, 0, 3, 0, 20, 22, 3, 0),
    gsSP2Triangles(21, 23, 22, 0, 23, 1, 0, 0),
    gsSP2Triangles(22, 23, 0, 0, 24, 17, 16, 0),
    gsSP2Triangles(24, 9, 13, 0, 24, 16, 9, 0),
    gsSP2Triangles(25, 21, 19, 0, 25, 10, 2, 0),
    gsSP2Triangles(21, 25, 2, 0, 25, 19, 10, 0),
    gsSP2Triangles(26, 19, 18, 0, 26, 11, 4, 0),
    gsSP2Triangles(19, 26, 4, 0, 26, 18, 11, 0),
    gsSP2Triangles(27, 23, 21, 0, 27, 12, 1, 0),
    gsSP2Triangles(23, 27, 1, 0, 27, 21, 12, 0),
    gsSP2Triangles(28, 17, 24, 0, 28, 13, 7, 0),
    gsSP2Triangles(17, 28, 7, 0, 28, 24, 13, 0),
    gsSP2Triangles(29, 18, 17, 0, 29, 14, 6, 0),
    gsSP2Triangles(18, 29, 6, 0, 29, 17, 14, 0),
    gsSPEndDisplayList(),
};
