#include <ultra64.h>

Vtx D_040006C0_DDC80[24] = {
#include "data/inc/D_040006C0_DDC80.inc.c"
};

extern Gfx D_01003618_3CEE8[];

const Gfx D_04000840_DDE00[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_040006C0_DDC80, 24, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSP2Triangles(12, 14, 13, 0, 14, 12, 15, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 16, 19, 0),
    gsSP2Triangles(20, 22, 21, 0, 22, 20, 23, 0),
    gsSPEndDisplayList(),
};
