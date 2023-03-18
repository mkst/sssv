#include <ultra64.h>

Vtx D_04006080_F70E0[11] = {
#include "data/inc/D_04006080_F70E0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04006130_F7190[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x94, 0x94, 0x94, 0xFF),
    gsSPVertex(D_04006080_F70E0, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 4, 5, 0),
    gsSP2Triangles(5, 2, 1, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 9, 7, 0),
    gsSP2Triangles(10, 6, 8, 0, 10, 9, 6, 0),
    gsSP2Triangles(7, 10, 8, 0, 7, 9, 10, 0),
    gsSPEndDisplayList(),
};
