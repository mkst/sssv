#include <ultra64.h>

Vtx D_04001AE0_DF0A0[8] = {
#include "data/inc/D_04001AE0_DF0A0.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_04001B60_DF120[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04001AE0_DF0A0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(7, 6, 5, 0, 5, 4, 7, 0),
    gsSP2Triangles(2, 1, 5, 0, 5, 6, 2, 0),
    gsSP2Triangles(0, 3, 7, 0, 7, 4, 0, 0),
    gsSP2Triangles(4, 5, 1, 0, 1, 0, 4, 0),
    gsSP2Triangles(2, 6, 7, 0, 7, 3, 2, 0),
    gsSPEndDisplayList(),
};
