#include <ultra64.h>

Vtx D_04000270_F12D0[14] = {
#include "data/inc/D_04000270_F12D0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04000350_F13B0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xDA, 0x1C, 0xFF),
    gsSPVertex(D_04000270_F12D0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(0, 4, 1, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 3, 1, 0, 5, 6, 3, 0),
    gsSP1Quadrangle(3, 6, 7, 2, 0),
    gsSP2Triangles(0, 8, 4, 0, 4, 8, 9, 0),
    gsSP1Quadrangle(9, 6, 5, 4, 0),
    gsSP2Triangles(0, 10, 8, 0, 8, 10, 11, 0),
    gsSP1Quadrangle(11, 6, 9, 8, 0),
    gsSP2Triangles(0, 12, 10, 0, 0, 2, 12, 0),
    gsSP2Triangles(12, 2, 7, 0, 10, 12, 13, 0),
    gsSP2Triangles(13, 6, 11, 0, 7, 6, 13, 0),
    gsSP2Triangles(13, 11, 10, 0, 7, 13, 12, 0),
    gsSPEndDisplayList(),
};
