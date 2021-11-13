#include <ultra64.h>

Vtx D_04007590_CEFC0[19] = {
#include "data/inc/D_04007590_CEFC0.inc.c"
};
Vtx D_040076C0_CF0F0[7] = {
#include "data/inc/D_040076C0_CF0F0.inc.c"
};
Vtx D_04007730_CF160[9] = {
#include "data/inc/D_04007730_CF160.inc.c"
};

extern Gfx D_01003618_3CEE8[];

const Gfx D_040077C0_CF1F0[] = {
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_04007590_CEFC0, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(4, 2, 3, 0, 4, 5, 2, 0),
    gsSP2Triangles(2, 5, 0, 0, 1, 6, 3, 0),
    gsSP2Triangles(7, 0, 5, 0, 4, 8, 5, 0),
    gsSP2Triangles(5, 8, 7, 0, 9, 7, 8, 0),
    gsSP2Triangles(4, 10, 8, 0, 8, 10, 9, 0),
    gsSP1Quadrangle(4, 3, 11, 10, 0),
    gsSP2Triangles(11, 3, 6, 0, 6, 12, 11, 0),
    gsSP2Triangles(12, 9, 10, 0, 10, 11, 12, 0),
    gsSP2Triangles(1, 0, 13, 0, 13, 14, 1, 0),
    gsSP2Triangles(6, 1, 14, 0, 14, 15, 6, 0),
    gsSP2Triangles(12, 6, 15, 0, 15, 16, 12, 0),
    gsSP2Triangles(9, 12, 16, 0, 16, 17, 9, 0),
    gsSP2Triangles(7, 9, 17, 0, 17, 18, 7, 0),
    gsSP2Triangles(18, 13, 0, 0, 0, 7, 18, 0),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_040076C0_CF0F0, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 6, 5, 0, 0, 2, 6, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04007730_CF160, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPEndDisplayList(),
};
