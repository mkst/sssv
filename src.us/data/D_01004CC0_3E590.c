#include <ultra64.h>

Vtx D_01004C30_3E500[9] = {
#include "data/inc/D_01004C30_3E500.inc.c"
};

Gfx D_01004CC0_3E590[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_01004C30_3E500, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(1, 0, 6, 0, 4, 1, 7, 0),
    gsSP2Triangles(6, 7, 1, 0, 0, 4, 8, 0),
    gsSP2Triangles(7, 8, 4, 0, 8, 6, 0, 0),
    gsSP1Triangle(8, 6, 7, 0),
    gsSPEndDisplayList(),
};
