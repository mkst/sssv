#include <ultra64.h>

Vtx D_04005BC0_CD5F0[14] = {
#include "data/inc/D_04005BC0_CD5F0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04005CA0_CD6D0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04005BC0_CD5F0, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 1, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(6, 1, 5, 0, 6, 0, 1, 0),
    gsSP2Triangles(7, 0, 6, 0, 0, 7, 8, 0),
    gsSP2Triangles(9, 0, 8, 0, 0, 9, 2, 0),
    gsSP2Triangles(10, 2, 9, 0, 10, 3, 2, 0),
    gsSP2Triangles(3, 11, 4, 0, 11, 3, 10, 0),
    gsSP2Triangles(11, 5, 4, 0, 5, 11, 12, 0),
    gsSP2Triangles(12, 6, 5, 0, 6, 12, 7, 0),
    gsSP1Quadrangle(7, 12, 13, 8, 0),
    gsSP2Triangles(8, 13, 9, 0, 13, 10, 9, 0),
    gsSP1Quadrangle(11, 10, 13, 12, 0),
    gsSPEndDisplayList(),
};
