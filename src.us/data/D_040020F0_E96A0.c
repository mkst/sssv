#include <ultra64.h>

Vtx D_04002050_E9600[10] = {
#include "data/inc/D_04002050_E9600.inc.c"
};

Gfx D_040020F0_E96A0[] = {
    gsSPVertex(D_04002050_E9600, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP1Quadrangle(3, 0, 4, 1, 0),
    gsSP2Triangles(1, 4, 5, 0, 5, 2, 1, 0),
    gsSP2Triangles(4, 0, 6, 0, 2, 6, 0, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 2, 7, 0),
    gsSP2Triangles(7, 8, 6, 0, 5, 6, 8, 0),
    gsSP2Triangles(9, 7, 2, 0, 8, 9, 5, 0),
    gsSP1Triangle(2, 5, 9, 0),
    gsSPEndDisplayList(),
};
