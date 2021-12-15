#include <ultra64.h>

Vtx D_040033D0_E0990[14] = {
#include "data/inc/D_040033D0_E0990.inc.c"
};

Gfx D_040034B0_E0A70[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040033D0_E0990, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 0, 2, 0),
    gsSP2Triangles(0, 6, 7, 0, 6, 5, 8, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 7, 9, 0, 1, 0, 10, 0),
    gsSP2Triangles(7, 10, 0, 0, 8, 11, 9, 0),
    gsSP2Triangles(5, 4, 11, 0, 11, 8, 5, 0),
    gsSP2Triangles(11, 12, 9, 0, 4, 3, 12, 0),
    gsSP2Triangles(12, 11, 4, 0, 12, 13, 9, 0),
    gsSP2Triangles(13, 10, 9, 0, 3, 1, 13, 0),
    gsSP2Triangles(13, 12, 3, 0, 10, 13, 1, 0),
    gsSPEndDisplayList(),
};
