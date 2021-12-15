#include <ultra64.h>

Vtx D_040003B0_E7960[4] = {
#include "data/inc/D_040003B0_E7960.inc.c"
};
Vtx D_040003F0_E79A0[12] = {
#include "data/inc/D_040003F0_E79A0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040004B0_E7A60[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x1E, 0x1E, 0x1E, 0xFF),
    gsSPVertex(D_040003B0_E7960, 4, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040003F0_E79A0, 12, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 6, 5, 7, 0),
    gsSP1Quadrangle(8, 10, 9, 11, 0),
    gsSPEndDisplayList(),
};
