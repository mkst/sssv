#include <ultra64.h>

Vtx D_05001790_80F20[31] = {
#include "data/inc/D_05001790_80F20.inc.c"
};
Vtx D_05001980_81110[11] = {
#include "data/inc/D_05001980_81110.inc.c"
};

Gfx D_05001A30_811C0[] = {
    gsSPVertex(D_05001790_80F20, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(0, 5, 6, 0, 6, 7, 0, 0),
    gsSP2Triangles(6, 4, 3, 0, 3, 7, 6, 0),
    gsSP2Triangles(2, 5, 0, 0, 2, 1, 3, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 13, 0),
    gsSP2Triangles(16, 15, 17, 0, 14, 11, 10, 0),
    gsSP2Triangles(17, 18, 16, 0, 9, 18, 17, 0),
    gsSP2Triangles(9, 8, 18, 0, 10, 19, 14, 0),
    gsSP2Triangles(13, 12, 15, 0, 14, 19, 12, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 25, 0, 28, 22, 26, 0),
    gsSP2Triangles(29, 30, 24, 0, 24, 23, 29, 0),
    gsSP1Triangle(25, 27, 23, 0),
    gsSPVertex(D_05001980_81110, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 2, 4, 0, 9, 5, 10, 0),
    gsSP2Triangles(10, 5, 4, 0, 4, 2, 10, 0),
    gsSP1Quadrangle(10, 2, 1, 3, 0),
    gsSP1Triangle(10, 3, 9, 0),
    gsSPEndDisplayList(),
};
