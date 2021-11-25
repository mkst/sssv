#include <ultra64.h>

Vtx D_04004240_F52A0[17] = {
#include "data/inc/D_04004240_F52A0.inc.c"
};
Vtx D_04004350_F53B0[10] = {
#include "data/inc/D_04004350_F53B0.inc.c"
};
Vtx D_040043F0_F5450[6] = {
#include "data/inc/D_040043F0_F5450.inc.c"
};
Vtx D_04004450_F54B0[6] = {
#include "data/inc/D_04004450_F54B0.inc.c"
};

const Gfx D_040044B0_F5510[] = {
    gsSPVertex(D_04004240_F52A0, 17, 0),
    gsDPSetPrimColor(0, 0, 0x6E, 0x00, 0x7E, 0xFF),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
    gsSP2Triangles(5, 2, 6, 0, 6, 2, 1, 0),
    gsSP2Triangles(6, 7, 5, 0, 4, 5, 7, 0),
    gsSP2Triangles(7, 8, 4, 0, 3, 4, 8, 0),
    gsSP2Triangles(8, 9, 3, 0, 0, 3, 9, 0),
    gsSP2Triangles(8, 7, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 12, 11, 10, 0),
    gsSP2Triangles(11, 13, 9, 0, 12, 13, 11, 0),
    gsSP2Triangles(12, 14, 13, 0, 12, 10, 15, 0),
    gsSP2Triangles(7, 6, 15, 0, 15, 10, 7, 0),
    gsSP1Quadrangle(12, 15, 16, 14, 0),
    gsDPSetPrimColor(0, 0, 0xE6, 0x87, 0xB0, 0xFF),
    gsSPVertex(D_04004350_F53B0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 3, 5, 0, 3, 6, 7, 0),
    gsSP2Triangles(7, 0, 3, 0, 8, 2, 1, 0),
    gsSP2Triangles(8, 4, 2, 0, 1, 9, 8, 0),
    gsSPVertex(D_040043F0_F5450, 6, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSP2Triangles(1, 2, 4, 0, 3, 4, 2, 0),
    gsSP2Triangles(4, 5, 1, 0, 1, 5, 0, 0),
    gsSPVertex(D_04004450_F54B0, 6, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP2Triangles(2, 1, 4, 0, 4, 3, 2, 0),
    gsSP1Quadrangle(5, 4, 1, 0, 0),
    gsSPEndDisplayList(),
};
