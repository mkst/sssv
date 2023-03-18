#include <ultra64.h>

Vtx D_04000BB0_F1C10[5] = {
#include "data/inc/D_04000BB0_F1C10.inc.c"
};
Vtx D_04000C00_F1C60[12] = {
#include "data/inc/D_04000C00_F1C60.inc.c"
};
Vtx D_04000CC0_F1D20[11] = {
#include "data/inc/D_04000CC0_F1D20.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04000D70_F1DD0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04000BB0_F1C10, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP1Triangle(4, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04000C00_F1C60, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSPVertex(D_04000CC0_F1D20, 11, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xDA, 0x1C, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 2, 5, 3, 0),
    gsSP1Quadrangle(6, 5, 2, 1, 0),
    gsSP2Triangles(1, 7, 6, 0, 1, 0, 7, 0),
    gsSP1Quadrangle(8, 5, 6, 7, 0),
    gsSP2Triangles(7, 9, 8, 0, 0, 4, 9, 0),
    gsSP2Triangles(7, 0, 9, 0, 5, 10, 3, 0),
    gsSP1Triangle(3, 10, 4, 0),
    gsSPEndDisplayList(),
};
