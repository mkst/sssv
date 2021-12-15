#include <ultra64.h>

Vtx D_04000000_E75B0[4] = {
#include "data/inc/D_04000000_E75B0.inc.c"
};
Vtx D_04000040_E75F0[6] = {
#include "data/inc/D_04000040_E75F0.inc.c"
};

Gfx D_040000A0_E7650[] = {
    gsSPVertex(D_04000000_E75B0, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP1Triangle(3, 2, 0, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04000040_E75F0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 2, 1, 0),
    gsSP2Triangles(1, 3, 0, 0, 4, 0, 3, 0),
    gsSP2Triangles(0, 4, 2, 0, 5, 2, 4, 0),
    gsSP2Triangles(3, 1, 5, 0, 2, 5, 1, 0),
    gsSPEndDisplayList(),
};
