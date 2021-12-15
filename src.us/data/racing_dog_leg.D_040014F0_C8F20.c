#include <ultra64.h>

Vtx D_040013D0_C8E00[6] = {
#include "data/inc/D_040013D0_C8E00.inc.c"
};
Vtx D_04001430_C8E60[12] = {
#include "data/inc/D_04001430_C8E60.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040014F0_C8F20[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_040013D0_C8E00, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 3, 4, 5, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04001430_C8E60, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(1, 4, 0, 0, 4, 1, 3, 0),
    gsSP2Triangles(5, 4, 3, 0, 3, 2, 5, 0),
    gsSP2Triangles(6, 5, 2, 0, 2, 0, 7, 0),
    gsSP2Triangles(2, 7, 6, 0, 7, 8, 6, 0),
    gsSP2Triangles(5, 6, 8, 0, 7, 0, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 4, 5, 10, 0),
    gsSP2Triangles(10, 5, 8, 0, 8, 7, 10, 0),
    gsSP2Triangles(0, 11, 9, 0, 4, 10, 11, 0),
    gsSP2Triangles(10, 9, 11, 0, 11, 0, 4, 0),
    gsSPEndDisplayList(),
};
