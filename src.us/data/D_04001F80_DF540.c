#include <ultra64.h>

Vtx D_04001E30_DF3F0[12] = {
#include "data/inc/D_04001E30_DF3F0.inc.c"
};
Vtx D_04001EF0_DF4B0[9] = {
#include "data/inc/D_04001EF0_DF4B0.inc.c"
};

Gfx D_04001F80_DF540[] = {
    gsDPSetPrimColor(0, 0, 0xD9, 0xE9, 0xF4, 0xFF),
    gsSPVertex(D_04001E30_DF3F0, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 6, 0, 1, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 5, 0, 0),
    gsSP2Triangles(1, 8, 6, 0, 8, 1, 3, 0),
    gsSP2Triangles(3, 9, 8, 0, 9, 3, 4, 0),
    gsSP2Triangles(4, 10, 9, 0, 5, 7, 10, 0),
    gsSP2Triangles(10, 4, 5, 0, 11, 7, 6, 0),
    gsSP1Quadrangle(11, 6, 8, 9, 0),
    gsSP1Quadrangle(11, 9, 10, 7, 0),
    gsDPSetPrimColor(0, 0, 0xE8, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04001EF0_DF4B0, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsSP2Triangles(4, 1, 2, 0, 2, 3, 4, 0),
    gsSP2Triangles(5, 0, 1, 0, 1, 4, 5, 0),
    gsSP2Triangles(0, 5, 3, 0, 3, 6, 4, 0),
    gsSP2Triangles(6, 3, 7, 0, 5, 7, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 4, 6, 0),
    gsSP2Triangles(7, 5, 8, 0, 4, 8, 5, 0),
    gsSPEndDisplayList(),
};
