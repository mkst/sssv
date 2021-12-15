#include <ultra64.h>

Vtx D_04002A70_EA020[12] = {
#include "data/inc/D_04002A70_EA020.inc.c"
};

Gfx D_04002B30_EA0E0[] = {
    gsSPVertex(D_04002A70_EA020, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 5, 2, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 6, 4, 3, 0),
    gsSP2Triangles(6, 7, 4, 0, 4, 7, 5, 0),
    gsSP2Triangles(8, 5, 7, 0, 0, 5, 8, 0),
    gsSP2Triangles(6, 9, 7, 0, 7, 9, 8, 0),
    gsSP2Triangles(0, 10, 1, 0, 6, 3, 10, 0),
    gsSP2Triangles(10, 3, 1, 0, 0, 11, 10, 0),
    gsSP2Triangles(6, 10, 11, 0, 0, 8, 11, 0),
    gsSP2Triangles(11, 8, 9, 0, 6, 11, 9, 0),
    gsSPEndDisplayList(),
};
