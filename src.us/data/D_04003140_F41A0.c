#include <ultra64.h>

Vtx D_04003080_F40E0[12] = {
#include "data/inc/D_04003080_F40E0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04003140_F41A0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x64, 0x64, 0x64, 0xFF),
    gsSPVertex(D_04003080_F40E0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(1, 0, 4, 0, 3, 1, 5, 0),
    gsSP2Triangles(4, 5, 1, 0, 0, 6, 4, 0),
    gsSP2Triangles(6, 2, 5, 0, 2, 6, 0, 0),
    gsSP2Triangles(5, 4, 6, 0, 5, 2, 7, 0),
    gsSP2Triangles(3, 7, 2, 0, 7, 3, 8, 0),
    gsSP2Triangles(8, 3, 9, 0, 5, 9, 3, 0),
    gsSP2Triangles(7, 9, 5, 0, 9, 7, 10, 0),
    gsSP2Triangles(8, 10, 7, 0, 9, 11, 8, 0),
    gsSP1Triangle(10, 11, 9, 0),
    gsSPEndDisplayList(),
};
