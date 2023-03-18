#include <ultra64.h>

Vtx D_04000000_FFD50[26] = {
#include "data/inc/D_04000000_FFD50.inc.c"
};

extern Gfx D_010034C0_3CD90[];

Gfx D_040001A0_FFEF0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04000000_FFD50, 26, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(4, 2, 0, 0, 0, 5, 4, 0),
    gsSP2Triangles(5, 0, 3, 0, 3, 6, 5, 0),
    gsSP2Triangles(7, 2, 4, 0, 4, 8, 7, 0),
    gsSP2Triangles(8, 4, 5, 0, 5, 9, 8, 0),
    gsSP1Quadrangle(9, 5, 6, 10, 0),
    gsSP2Triangles(6, 11, 10, 0, 6, 3, 11, 0),
    gsSP2Triangles(12, 11, 3, 0, 3, 1, 12, 0),
    gsSP2Triangles(11, 13, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 2, 7, 0, 7, 15, 14, 0),
    gsSP2Triangles(15, 7, 8, 0, 8, 16, 15, 0),
    gsSP2Triangles(16, 9, 10, 0, 16, 8, 9, 0),
    gsSP2Triangles(17, 2, 14, 0, 14, 18, 17, 0),
    gsSP2Triangles(18, 14, 15, 0, 15, 19, 18, 0),
    gsSP2Triangles(19, 16, 10, 0, 19, 15, 16, 0),
    gsSP2Triangles(20, 2, 17, 0, 17, 21, 20, 0),
    gsSP2Triangles(21, 17, 18, 0, 18, 22, 21, 0),
    gsSP2Triangles(22, 19, 10, 0, 22, 18, 19, 0),
    gsSP2Triangles(23, 2, 20, 0, 1, 2, 23, 0),
    gsSP2Triangles(23, 12, 1, 0, 20, 24, 23, 0),
    gsSP2Triangles(24, 13, 12, 0, 24, 20, 21, 0),
    gsSP2Triangles(12, 23, 24, 0, 21, 25, 24, 0),
    gsSP2Triangles(25, 22, 10, 0, 13, 25, 10, 0),
    gsSP2Triangles(25, 21, 22, 0, 13, 24, 25, 0),
    gsSPEndDisplayList(),
};
