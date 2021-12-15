#include <ultra64.h>

Vtx D_04001360_C8D90[4] = {
#include "data/inc/D_04001360_C8D90.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040013A0_C8DD0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04001360_C8D90, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Triangle(0, 3, 1, 0),
    gsSPEndDisplayList(),
};
