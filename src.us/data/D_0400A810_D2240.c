#include <ultra64.h>

Vtx D_0400A700_D2130[8] = {
#include "data/inc/D_0400A700_D2130.inc.c"
};
Vtx D_0400A780_D21B0[9] = {
#include "data/inc/D_0400A780_D21B0.inc.c"
};

const Gfx D_0400A810_D2240[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400A700_D2130, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0400A780_D21B0, 9, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 2, 1, 0),
    gsSP1Quadrangle(6, 7, 5, 4, 0),
    gsSP1Triangle(6, 8, 7, 0),
    gsSPEndDisplayList(),
};
