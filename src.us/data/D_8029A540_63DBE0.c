#include <ultra64.h>

Vtx D_8029A3C0_63DA60[24] = {
#include "data/inc/D_8029A3C0_63DA60.inc.c"
};

Gfx D_8029A540_63DBE0[] = {
    gsDPPipeSync(),
    gsSPVertex(D_8029A3C0_63DA60, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSPEndDisplayList(),
};
