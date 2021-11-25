#include <ultra64.h>

Vtx D_04007670_E4C30[17] = {
#include "data/inc/D_04007670_E4C30.inc.c"
};
Vtx D_04007780_E4D40[6] = {
#include "data/inc/D_04007780_E4D40.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_040077E0_E4DA0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04007670_E4C30, 17, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 6, 0, 1, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 5, 0, 0),
    gsSP2Triangles(1, 8, 6, 0, 8, 1, 3, 0),
    gsSP2Triangles(3, 9, 8, 0, 9, 3, 4, 0),
    gsSP2Triangles(4, 10, 9, 0, 5, 7, 10, 0),
    gsSP2Triangles(10, 4, 5, 0, 11, 7, 6, 0),
    gsSP2Triangles(7, 11, 12, 0, 12, 10, 7, 0),
    gsSP2Triangles(6, 13, 11, 0, 13, 6, 8, 0),
    gsSP2Triangles(8, 14, 13, 0, 14, 8, 9, 0),
    gsSP2Triangles(9, 15, 14, 0, 10, 12, 15, 0),
    gsSP2Triangles(15, 9, 10, 0, 16, 12, 11, 0),
    gsSP1Quadrangle(16, 11, 13, 14, 0),
    gsSP1Quadrangle(16, 14, 15, 12, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0xFF, 0xFF),
    gsSPVertex(D_04007780_E4D40, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(4, 1, 3, 0, 3, 5, 4, 0),
    gsSPEndDisplayList(),
};
