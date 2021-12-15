#include <ultra64.h>

Vtx D_04003D60_EB310[6] = {
#include "data/inc/D_04003D60_EB310.inc.c"
};
Vtx D_04003DC0_EB370[4] = {
#include "data/inc/D_04003DC0_EB370.inc.c"
};

Gfx D_04003E00_EB3B0[] = {
    gsSPVertex(D_04003D60_EB310, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 1, 3, 0, 1, 4, 0, 0),
    gsSP2Triangles(0, 4, 5, 0, 2, 0, 5, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04003DC0_EB370, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPEndDisplayList(),
};
