#include <ultra64.h>

Vtx D_04003480_CAEB0[8] = {
#include "data/inc/D_04003480_CAEB0.inc.c"
};
Vtx D_04003500_CAF30[8] = {
#include "data/inc/D_04003500_CAF30.inc.c"
};

Gfx D_04003580_CAFB0[] = {
    gsDPSetPrimColor(0, 0, 0x1E, 0x1E, 0x1E, 0xFF),
    gsSPVertex(D_04003480_CAEB0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSPVertex(D_04003500_CAF30, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSPEndDisplayList(),
};
