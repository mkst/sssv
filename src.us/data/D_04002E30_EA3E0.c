#include <ultra64.h>

Vtx D_04002B90_EA140[6] = {
#include "data/inc/D_04002B90_EA140.inc.c"
};
Vtx D_04002BF0_EA1A0[4] = {
#include "data/inc/D_04002BF0_EA1A0.inc.c"
};
Vtx D_04002C30_EA1E0[26] = {
#include "data/inc/D_04002C30_EA1E0.inc.c"
};
Vtx D_04002DD0_EA380[6] = {
    #include "data/inc/D_04002DD0_EA380.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

Gfx D_04002E30_EA3E0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04002B90_EA140, 6, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSPVertex(D_04002DD0_EA380, 6, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04002BF0_EA1A0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04002C30_EA1E0, 26, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(0, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(3, 2, 5, 0, 5, 6, 3, 0),
    gsSP2Triangles(0, 7, 4, 0, 0, 8, 7, 0),
    gsSP2Triangles(8, 9, 7, 0, 0, 10, 8, 0),
    gsSP2Triangles(0, 1, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(9, 8, 11, 0, 1, 12, 10, 0),
    gsSP2Triangles(11, 10, 12, 0, 12, 1, 3, 0),
    gsSP2Triangles(3, 13, 12, 0, 13, 3, 6, 0),
    gsSP2Triangles(12, 14, 11, 0, 14, 12, 13, 0),
    gsSP2Triangles(6, 15, 13, 0, 11, 16, 9, 0),
    gsSP2Triangles(16, 11, 14, 0, 14, 17, 16, 0),
    gsSP2Triangles(7, 18, 4, 0, 5, 4, 18, 0),
    gsSP2Triangles(18, 7, 9, 0, 18, 19, 5, 0),
    gsSP2Triangles(6, 5, 19, 0, 19, 20, 6, 0),
    gsSP1Quadrangle(15, 6, 20, 21, 0),
    gsSP2Triangles(20, 22, 21, 0, 20, 19, 22, 0),
    gsSP2Triangles(22, 23, 21, 0, 23, 17, 21, 0),
    gsSP2Triangles(23, 16, 17, 0, 16, 23, 24, 0),
    gsSP2Triangles(24, 22, 19, 0, 9, 24, 18, 0),
    gsSP2Triangles(22, 24, 23, 0, 19, 18, 24, 0),
    gsSP2Triangles(24, 9, 16, 0, 13, 25, 14, 0),
    gsSP2Triangles(17, 25, 21, 0, 25, 15, 21, 0),
    gsSP2Triangles(17, 14, 25, 0, 25, 13, 15, 0),
    gsSPEndDisplayList(),
};
