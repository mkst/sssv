#include <ultra64.h>

Vtx D_04004E40_F5EA0[15] = {
#include "data/inc/D_04004E40_F5EA0.inc.c"
};

Gfx D_04004F30_F5F90[] = {
    gsDPSetPrimColor(0, 0, 0x6E, 0x00, 0x7E, 0xFF),
    gsSPVertex(D_04004E40_F5EA0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(3, 2, 4, 0, 2, 1, 5, 0),
    gsSP2Triangles(1, 0, 6, 0, 6, 5, 1, 0),
    gsSP2Triangles(0, 3, 7, 0, 7, 6, 0, 0),
    gsSP2Triangles(3, 4, 8, 0, 8, 7, 3, 0),
    gsSP2Triangles(4, 2, 9, 0, 9, 8, 4, 0),
    gsSP2Triangles(5, 9, 2, 0, 6, 7, 10, 0),
    gsSP2Triangles(8, 9, 11, 0, 9, 5, 12, 0),
    gsSP2Triangles(7, 8, 13, 0, 5, 6, 14, 0),
    gsSPEndDisplayList(),
};
