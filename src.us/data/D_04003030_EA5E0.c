#include <ultra64.h>

Vtx D_04002F70_EA520[12] = {
#include "data/inc/D_04002F70_EA520.inc.c"
};

Gfx D_04003030_EA5E0[] = {
    gsSPVertex(D_04002F70_EA520, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(4, 1, 3, 0, 1, 4, 0, 0),
    gsSP2Triangles(4, 5, 0, 0, 2, 0, 5, 0),
    gsSP2Triangles(5, 6, 2, 0, 3, 2, 7, 0),
    gsSP2Triangles(7, 2, 6, 0, 8, 7, 6, 0),
    gsSP2Triangles(6, 5, 8, 0, 3, 7, 9, 0),
    gsSP2Triangles(10, 9, 7, 0, 7, 8, 10, 0),
    gsSP1Quadrangle(5, 4, 10, 8, 0),
    gsSP2Triangles(11, 3, 9, 0, 9, 10, 11, 0),
    gsSP2Triangles(3, 11, 4, 0, 10, 4, 11, 0),
    gsSPEndDisplayList(),
};
