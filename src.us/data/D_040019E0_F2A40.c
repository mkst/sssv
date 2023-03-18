#include <ultra64.h>

Vtx D_040019A0_F2A00[4] = {
#include "data/inc/D_040019A0_F2A00.inc.c"
};

Gfx D_040019E0_F2A40[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040019A0_F2A00, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPEndDisplayList(),
};
