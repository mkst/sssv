#include <ultra64.h>

Vtx D_01004D10_3E5E0[8] = {
#include "data/inc/D_01004D10_3E5E0.inc.c"
};

const Gfx D_01004D90_3E660[] = {
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_01004D10_3E5E0, 8, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 2, 0, 0),
    gsSP2Triangles(6, 7, 5, 0, 4, 5, 7, 0),
    gsSP2Triangles(1, 2, 5, 0, 6, 5, 2, 0),
    gsSP2Triangles(3, 0, 7, 0, 4, 7, 0, 0),
    gsSP2Triangles(5, 4, 1, 0, 0, 1, 4, 0),
    gsSP2Triangles(6, 2, 7, 0, 3, 7, 2, 0),
    gsSPEndDisplayList(),
};
