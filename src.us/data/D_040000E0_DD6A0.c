#include <ultra64.h>

Vtx D_04000000_DD5C0[14] = {
#include "data/inc/D_04000000_DD5C0.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_040000E0_DD6A0[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_04000000_DD5C0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(0, 4, 1, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 3, 1, 0, 6, 3, 5, 0),
    gsSP2Triangles(6, 5, 7, 0, 7, 5, 4, 0),
    gsSP2Triangles(6, 8, 3, 0, 3, 8, 2, 0),
    gsSP2Triangles(6, 7, 9, 0, 10, 2, 8, 0),
    gsSP2Triangles(0, 2, 10, 0, 6, 9, 11, 0),
    gsSP2Triangles(6, 11, 8, 0, 8, 11, 10, 0),
    gsSP2Triangles(11, 9, 12, 0, 0, 10, 12, 0),
    gsSP2Triangles(12, 10, 11, 0, 13, 12, 9, 0),
    gsSP2Triangles(4, 13, 7, 0, 0, 13, 4, 0),
    gsSP2Triangles(0, 12, 13, 0, 9, 7, 13, 0),
    gsSPEndDisplayList(),
};
