#include <ultra64.h>

Vtx D_04003700_EACB0[8] = {
#include "data/inc/D_04003700_EACB0.inc.c"
};

Gfx D_04003780_EAD30[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04003700_EACB0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSPEndDisplayList(),
};
