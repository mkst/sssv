#include <ultra64.h>

Vtx D_05001C80_B2810[31] = {
#include "data/inc/D_05001C80_B2810.inc.c"
};
Vtx D_05001E70_B2A00[31] = {
#include "data/inc/D_05001E70_B2A00.inc.c"
};
Vtx D_05002060_B2BF0[27] = {
#include "data/inc/D_05002060_B2BF0.inc.c"
};

Gfx D_05002210_B2DA0[] = {
    gsSPVertex(D_05001C80_B2810, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 11, 10, 1, 0),
    gsSP2Triangles(4, 2, 12, 0, 12, 2, 1, 0),
    gsSP2Triangles(1, 10, 12, 0, 12, 10, 8, 0),
    gsSP2Triangles(8, 6, 12, 0, 12, 6, 4, 0),
    gsSP2Triangles(13, 3, 5, 0, 0, 3, 13, 0),
    gsSP2Triangles(13, 11, 0, 0, 9, 11, 13, 0),
    gsSP2Triangles(13, 7, 9, 0, 5, 7, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 15, 0),
    gsSP2Triangles(19, 16, 18, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 21, 0, 25, 22, 24, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 28, 30, 0),
    gsSPVertex(D_05001E70_B2A00, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(6, 9, 8, 0, 8, 9, 10, 0),
    gsSP2Triangles(10, 9, 1, 0, 1, 9, 2, 0),
    gsSP2Triangles(2, 9, 4, 0, 4, 9, 6, 0),
    gsSP2Triangles(11, 12, 0, 0, 13, 12, 11, 0),
    gsSP2Triangles(11, 7, 13, 0, 5, 7, 11, 0),
    gsSP2Triangles(11, 3, 5, 0, 0, 3, 11, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 16, 18, 0),
    gsSP2Triangles(19, 18, 15, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 21, 0, 25, 26, 24, 0),
    gsSP2Triangles(27, 28, 26, 0, 29, 30, 28, 0),
    gsSPVertex(D_05002060_B2BF0, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 7, 0, 8, 7, 4, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 11, 13, 0),
    gsSP2Triangles(14, 13, 10, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 16, 0, 20, 21, 19, 0),
    gsSP2Triangles(22, 23, 21, 0, 24, 25, 23, 0),
    gsSP2Triangles(26, 17, 25, 0, 5, 13, 11, 0),
    gsSP2Triangles(4, 10, 13, 0, 7, 11, 10, 0),
    gsSPEndDisplayList(),
};
