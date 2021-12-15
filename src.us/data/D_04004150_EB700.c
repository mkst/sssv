#include <ultra64.h>

Vtx D_04004030_EB5E0[18] = {
#include "data/inc/D_04004030_EB5E0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04004150_EB700[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x80, 0x80, 0x80, 0xFF),
    gsSPVertex(D_04004030_EB5E0, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 2, 0, 4, 0),
    gsSP2Triangles(5, 4, 0, 0, 1, 5, 0, 0),
    gsSP2Triangles(5, 1, 6, 0, 1, 3, 6, 0),
    gsSP2Triangles(7, 5, 6, 0, 7, 8, 5, 0),
    gsSP2Triangles(7, 9, 8, 0, 7, 6, 9, 0),
    gsSP2Triangles(6, 10, 9, 0, 11, 5, 8, 0),
    gsSP1Quadrangle(12, 10, 11, 8, 0),
    gsSP1Quadrangle(12, 8, 9, 10, 0),
    gsSP2Triangles(10, 6, 13, 0, 13, 6, 3, 0),
    gsSP2Triangles(13, 3, 14, 0, 15, 13, 14, 0),
    gsSP2Triangles(16, 14, 3, 0, 3, 4, 16, 0),
    gsSP2Triangles(4, 5, 16, 0, 14, 16, 15, 0),
    gsSP2Triangles(17, 16, 5, 0, 17, 10, 13, 0),
    gsSP2Triangles(11, 17, 5, 0, 15, 16, 17, 0),
    gsSP2Triangles(13, 15, 17, 0, 10, 17, 11, 0),
    gsSPEndDisplayList(),
};
