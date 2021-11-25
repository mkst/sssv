#include <ultra64.h>

Vtx D_04000240_DD800[9] = {
#include "data/inc/D_04000240_DD800.inc.c"
};

extern Gfx D_01003618_3CEE8[];

const Gfx D_040002D0_DD890[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04000240_DD800, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 2, 3, 0),
    gsSP2Triangles(3, 4, 5, 0, 4, 6, 5, 0),
    gsSP2Triangles(2, 5, 6, 0, 7, 2, 6, 0),
    gsSP2Triangles(7, 1, 2, 0, 7, 6, 8, 0),
    gsSP2Triangles(0, 8, 4, 0, 7, 8, 1, 0),
    gsSP2Triangles(8, 0, 1, 0, 8, 6, 4, 0),
    gsSPEndDisplayList(),
};
