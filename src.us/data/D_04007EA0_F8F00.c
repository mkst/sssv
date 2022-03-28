#include <ultra64.h>

Vtx D_04007D60_F8DC0[20] = {
#include "data/inc/D_04007D60_F8DC0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04007EA0_F8F00[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x80, 0x80, 0x80, 0xFF),
    gsSPVertex(D_04007D60_F8DC0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(2, 1, 4, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 6, 4, 0, 0, 6, 3, 0),
    gsSP2Triangles(5, 7, 6, 0, 6, 7, 3, 0),
    gsSP2Triangles(8, 7, 5, 0, 5, 9, 8, 0),
    gsSP2Triangles(5, 1, 9, 0, 9, 1, 10, 0),
    gsSP2Triangles(10, 1, 3, 0, 11, 10, 3, 0),
    gsSP2Triangles(11, 3, 7, 0, 7, 8, 11, 0),
    gsSP2Triangles(12, 10, 11, 0, 13, 10, 12, 0),
    gsSP2Triangles(9, 10, 13, 0, 13, 14, 9, 0),
    gsSP2Triangles(12, 11, 15, 0, 11, 8, 15, 0),
    gsSP2Triangles(9, 15, 8, 0, 14, 15, 9, 0),
    gsSP2Triangles(0, 2, 16, 0, 2, 17, 16, 0),
    gsSP2Triangles(17, 2, 4, 0, 0, 16, 18, 0),
    gsSP2Triangles(6, 0, 18, 0, 18, 17, 4, 0),
    gsSP2Triangles(6, 18, 4, 0, 19, 16, 17, 0),
    gsSP2Triangles(18, 16, 19, 0, 19, 17, 18, 0),
    gsSPEndDisplayList(),
};
