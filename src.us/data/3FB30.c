#include <ultra64.h>

Vtx D_01005FF0_3F8C0[] = {
#include "data/inc/D_01005FF0_3F8C0.inc.c"
};
Vtx D_010061F0_3FAC0[] = {
#include "data/inc/D_010061F0_3FAC0.inc.c"
};

const Gfx D_01006260_3FB30[] = {
    gsSPVertex(D_01005FF0_3F8C0, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(3, 1, 4, 0, 2, 4, 1, 0),
    gsSP2Triangles(4, 2, 5, 0, 5, 6, 4, 0),
    gsSP1Quadrangle(3, 4, 6, 0, 0),
    gsSP2Triangles(2, 0, 7, 0, 6, 7, 0, 0),
    gsSP2Triangles(7, 6, 8, 0, 6, 5, 8, 0),
    gsSP2Triangles(9, 11, 10, 0, 11, 9, 12, 0),
    gsSP2Triangles(13, 15, 14, 0, 15, 13, 16, 0),
    gsSP2Triangles(17, 19, 18, 0, 19, 17, 20, 0),
    gsSP2Triangles(21, 23, 22, 0, 23, 21, 24, 0),
    gsSP2Triangles(25, 27, 26, 0, 28, 25, 26, 0),
    gsSP2Triangles(28, 26, 29, 0, 27, 29, 26, 0),
    gsSP2Triangles(29, 27, 30, 0, 30, 31, 29, 0),
    gsSP1Quadrangle(28, 29, 31, 25, 0),
    gsSPVertex(D_010061F0_3FAC0, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(0, 1, 4, 0, 3, 4, 1, 0),
    gsSP1Quadrangle(0, 4, 5, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 3, 2, 6, 0),
    gsSPEndDisplayList(),
};
