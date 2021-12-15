#include <ultra64.h>

Vtx D_04008990_1086E0[4] = {
#include "data/inc/D_04008990_1086E0.inc.c"
};

// FIXME
Vtx D_040089D0_108720[1] = {
#include "data/inc/D_040089D0_108720.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040089E0_108730[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04008990_1086E0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSPEndDisplayList(),
};
