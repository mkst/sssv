#include <ultra64.h>

Vtx D_04000FE0_F2040[16] = {
#include "data/inc/D_04000FE0_F2040.inc.c"
};
Vtx D_040010E0_F2140[14] = {
#include "data/inc/D_040010E0_F2140.inc.c"
};
Vtx D_040011C0_F2220[9] = {
#include "data/inc/D_040011C0_F2220.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04001250_F22B0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000FE0_F2040, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 3, 2, 0, 2, 5, 4, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 7, 6, 0, 6, 8, 5, 0),
    gsSP2Triangles(8, 6, 9, 0, 9, 6, 7, 0),
    gsSP2Triangles(7, 10, 9, 0, 9, 11, 8, 0),
    gsSP2Triangles(11, 9, 12, 0, 12, 9, 10, 0),
    gsSP2Triangles(10, 13, 12, 0, 12, 14, 11, 0),
    gsSP2Triangles(14, 12, 15, 0, 15, 12, 13, 0),
    gsSPVertex(D_040010E0_F2140, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 5, 2, 3, 0),
    gsSP2Triangles(2, 5, 6, 0, 3, 7, 5, 0),
    gsSP2Triangles(7, 3, 8, 0, 8, 3, 4, 0),
    gsSP2Triangles(4, 9, 8, 0, 8, 10, 7, 0),
    gsSP2Triangles(10, 8, 11, 0, 11, 8, 9, 0),
    gsSP2Triangles(9, 12, 11, 0, 11, 13, 10, 0),
    gsSPVertex(D_040011C0_F2220, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 5, 4, 2, 0),
    gsSP1Quadrangle(2, 1, 6, 7, 0),
    gsSP1Quadrangle(2, 7, 8, 5, 0),
    gsSPEndDisplayList(),
};
