#include <ultra64.h>

Vtx D_04000100_E76B0[5] = {
#include "data/inc/D_04000100_E76B0.inc.c"
};
Vtx D_04000150_E7700[14] = {
#include "data/inc/D_04000150_E7700.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];

Gfx D_04000230_E77E0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04000100_E76B0, 5, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 2, 0),
    gsSP2Triangles(1, 3, 2, 0, 3, 4, 0, 0),
    gsSP1Triangle(1, 4, 3, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04000150_E7700, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(2, 0, 4, 0, 5, 2, 4, 0),
    gsSP2Triangles(5, 6, 2, 0, 6, 1, 2, 0),
    gsSP2Triangles(1, 6, 7, 0, 3, 1, 7, 0),
    gsSP2Triangles(5, 8, 6, 0, 8, 7, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 3, 7, 9, 0),
    gsSP2Triangles(5, 10, 8, 0, 10, 9, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 3, 9, 11, 0),
    gsSP2Triangles(5, 12, 10, 0, 5, 4, 12, 0),
    gsSP2Triangles(12, 11, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(13, 4, 0, 0, 3, 11, 13, 0),
    gsSP2Triangles(3, 13, 0, 0, 4, 13, 12, 0),
    gsSPEndDisplayList(),
};
