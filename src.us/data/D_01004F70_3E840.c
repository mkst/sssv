#include <ultra64.h>

Vtx D_01004EA0_3E770[13] = {
#include "data/inc/D_01004EA0_3E770.inc.c"
};

Gfx D_01004F70_3E840[] = {
    gsSPVertex(D_01004EA0_3E770, 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP1Quadrangle(4, 3, 2, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 1, 6, 5, 0),
    gsSP2Triangles(6, 1, 0, 0, 4, 5, 7, 0),
    gsSP2Triangles(7, 5, 6, 0, 6, 8, 7, 0),
    gsSP2Triangles(0, 8, 6, 0, 4, 7, 9, 0),
    gsSP2Triangles(9, 7, 8, 0, 8, 10, 9, 0),
    gsSP2Triangles(11, 9, 10, 0, 4, 11, 3, 0),
    gsSP2Triangles(4, 9, 11, 0, 12, 0, 3, 0),
    gsSP2Triangles(3, 11, 12, 0, 10, 12, 11, 0),
    gsSP2Triangles(8, 0, 12, 0, 12, 10, 8, 0),
    gsSPEndDisplayList(),
};
