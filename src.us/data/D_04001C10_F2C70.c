#include <ultra64.h>

Vtx D_04001B50_F2BB0[12] = {
#include "data/inc/D_04001B50_F2BB0.inc.c"
};

Gfx D_04001C10_F2C70[] = {
    gsDPSetPrimColor(0, 0, 0x7D, 0x33, 0xFF, 0xFF),
    gsSPVertex(D_04001B50_F2BB0, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSPEndDisplayList(),
};
