#include <ultra64.h>

Vtx D_04007F80_CF9B0[20] = {
#include "data/inc/D_04007F80_CF9B0.inc.c"
};
Vtx D_040080C0_CFAF0[32] = {
#include "data/inc/D_040080C0_CFAF0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_040082C0_CFCF0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_04007F80_CF9B0, 20, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
    gsSP1Quadrangle(5, 0, 1, 6, 0),
    gsSP2Triangles(1, 7, 6, 0, 7, 1, 2, 0),
    gsSP2Triangles(5, 8, 4, 0, 8, 9, 4, 0),
    gsSP2Triangles(3, 4, 9, 0, 5, 10, 8, 0),
    gsSP2Triangles(10, 11, 8, 0, 9, 8, 11, 0),
    gsSP2Triangles(11, 10, 12, 0, 5, 6, 13, 0),
    gsSP2Triangles(6, 14, 13, 0, 14, 6, 7, 0),
    gsSP2Triangles(5, 15, 10, 0, 5, 16, 15, 0),
    gsSP2Triangles(5, 17, 16, 0, 5, 13, 18, 0),
    gsSP2Triangles(5, 19, 17, 0, 5, 18, 19, 0),
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_040080C0_CFAF0, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 5, 3, 0, 0),
    gsSP2Triangles(4, 3, 6, 0, 7, 4, 6, 0),
    gsSP2Triangles(8, 6, 3, 0, 3, 5, 8, 0),
    gsSP2Triangles(7, 9, 4, 0, 9, 2, 4, 0),
    gsSP2Triangles(2, 9, 10, 0, 10, 1, 2, 0),
    gsSP2Triangles(7, 11, 9, 0, 11, 10, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 1, 10, 13, 0),
    gsSP2Triangles(12, 13, 10, 0, 7, 14, 11, 0),
    gsSP2Triangles(14, 12, 11, 0, 12, 14, 15, 0),
    gsSP2Triangles(7, 16, 14, 0, 16, 15, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 7, 18, 16, 0),
    gsSP2Triangles(18, 17, 16, 0, 7, 19, 18, 0),
    gsSP2Triangles(7, 20, 19, 0, 7, 21, 20, 0),
    gsSP2Triangles(17, 18, 22, 0, 19, 22, 18, 0),
    gsSP2Triangles(22, 19, 23, 0, 20, 23, 19, 0),
    gsSP2Triangles(23, 20, 24, 0, 21, 24, 20, 0),
    gsSP2Triangles(24, 21, 25, 0, 7, 26, 21, 0),
    gsSP2Triangles(26, 25, 21, 0, 7, 27, 26, 0),
    gsSP2Triangles(7, 6, 27, 0, 6, 8, 27, 0),
    gsSP2Triangles(28, 27, 8, 0, 25, 26, 28, 0),
    gsSP2Triangles(27, 28, 26, 0, 13, 12, 29, 0),
    gsSP2Triangles(15, 29, 12, 0, 29, 15, 30, 0),
    gsSP2Triangles(17, 30, 15, 0, 30, 17, 31, 0),
    gsSPEndDisplayList(),
};
