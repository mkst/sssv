#include <ultra64.h>

Vtx D_04008B60_F9BC0[17] = {
#include "data/inc/D_04008B60_F9BC0.inc.c"
};

Gfx D_04008C70_F9CD0[] = {
    gsSPVertex(D_04008B60_F9BC0, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 7, 5, 6, 0),
    gsSP2Triangles(5, 7, 8, 0, 7, 6, 9, 0),
    gsSP2Triangles(9, 7, 5, 0, 9, 10, 7, 0),
    gsSP1Quadrangle(10, 0, 11, 7, 0),
    gsSP2Triangles(0, 12, 11, 0, 2, 12, 0, 0),
    gsSP2Triangles(11, 13, 7, 0, 8, 7, 13, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 9, 6, 0),
    gsSP2Triangles(14, 6, 4, 0, 4, 1, 14, 0),
    gsSP2Triangles(0, 10, 14, 0, 10, 9, 14, 0),
    gsSP2Triangles(14, 1, 0, 0, 5, 8, 15, 0),
    gsSP1Quadrangle(3, 5, 15, 2, 0),
    gsSP2Triangles(15, 16, 2, 0, 2, 16, 12, 0),
    gsSP2Triangles(12, 16, 13, 0, 16, 15, 8, 0),
    gsSP1Triangle(8, 13, 16, 0),
    gsSPEndDisplayList(),
};
