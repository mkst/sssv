#include <ultra64.h>

Vtx D_040045F0_EBBA0[32] = {
#include "data/inc/D_040045F0_EBBA0.inc.c"
};
Vtx D_040047F0_EBDA0[25] = {
#include "data/inc/D_040047F0_EBDA0.inc.c"
};
Vtx D_04004980_EBF30[8] = {
#include "data/inc/D_04004980_EBF30.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04004A00_EBFB0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xAA, 0x55, 0x00, 0xFF),
    gsSPVertex(D_040045F0_EBBA0, 32, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(0, 4, 2, 0, 0, 5, 4, 0),
    gsSP1Quadrangle(0, 3, 6, 7, 0),
    gsSP1Quadrangle(0, 7, 8, 5, 0),
    gsSP2Triangles(7, 9, 8, 0, 9, 7, 10, 0),
    gsSP2Triangles(6, 10, 7, 0, 11, 8, 9, 0),
    gsSP2Triangles(8, 11, 5, 0, 10, 6, 12, 0),
    gsSP2Triangles(3, 12, 6, 0, 5, 13, 4, 0),
    gsSP2Triangles(13, 5, 11, 0, 4, 14, 2, 0),
    gsSP2Triangles(14, 4, 13, 0, 2, 15, 1, 0),
    gsSP2Triangles(15, 2, 14, 0, 12, 3, 16, 0),
    gsSP2Triangles(1, 16, 3, 0, 16, 1, 15, 0),
    gsSP2Triangles(17, 19, 18, 0, 20, 17, 18, 0),
    gsSP2Triangles(19, 20, 18, 0, 21, 23, 22, 0),
    gsSP2Triangles(24, 21, 22, 0, 23, 24, 22, 0),
    gsSP2Triangles(25, 27, 26, 0, 25, 28, 27, 0),
    gsSP2Triangles(27, 29, 26, 0, 30, 26, 29, 0),
    gsSP1Triangle(31, 30, 29, 0),
    gsSPVertex(D_040047F0_EBDA0, 25, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(2, 0, 4, 0, 5, 4, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 4, 7, 0, 4, 8, 2, 0),
    gsSP2Triangles(9, 2, 8, 0, 2, 9, 3, 0),
    gsSP2Triangles(10, 3, 9, 0, 11, 8, 7, 0),
    gsSP1Quadrangle(11, 10, 9, 8, 0),
    gsSP2Triangles(11, 12, 10, 0, 11, 13, 12, 0),
    gsSP2Triangles(11, 14, 13, 0, 11, 15, 14, 0),
    gsSP2Triangles(15, 16, 14, 0, 17, 14, 16, 0),
    gsSP2Triangles(14, 17, 13, 0, 17, 12, 13, 0),
    gsSP2Triangles(16, 18, 17, 0, 18, 19, 17, 0),
    gsSP2Triangles(17, 19, 12, 0, 18, 20, 19, 0),
    gsSP2Triangles(18, 16, 21, 0, 22, 12, 19, 0),
    gsSP2Triangles(12, 22, 10, 0, 3, 10, 22, 0),
    gsSP2Triangles(22, 23, 3, 0, 1, 3, 23, 0),
    gsSP2Triangles(19, 24, 22, 0, 24, 19, 20, 0),
    gsSP1Triangle(23, 22, 24, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04004980_EBF30, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 6, 5, 7, 0),
    gsSPEndDisplayList(),
};
