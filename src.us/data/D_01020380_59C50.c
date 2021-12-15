#include <ultra64.h>

Vtx D_01020290_59B60[15] = {
#include "data/inc/D_01020290_59B60.inc.c"
};

Gfx D_01020380_59C50[] = {
    gsSPVertex(D_01020290_59B60, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 11, 5, 8, 0),
    gsSP2Triangles(12, 8, 10, 0, 13, 10, 5, 0),
    gsSP2Triangles(4, 11, 12, 0, 1, 12, 13, 0),
    gsSP2Triangles(2, 13, 11, 0, 14, 4, 1, 0),
    gsSP2Triangles(2, 3, 0, 0, 4, 14, 3, 0),
    gsSP2Triangles(7, 8, 5, 0, 9, 10, 8, 0),
    gsSP2Triangles(6, 5, 10, 0, 8, 12, 11, 0),
    gsSP2Triangles(10, 13, 12, 0, 5, 11, 13, 0),
    gsSP2Triangles(12, 1, 4, 0, 13, 2, 1, 0),
    gsSP2Triangles(11, 4, 2, 0, 1, 0, 14, 0),
    gsSPEndDisplayList(),
};
