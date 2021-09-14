#include <ultra64.h>

Vtx D_0101E6C0_57F90[8] = {
#include "data/inc/D_0101E6C0_57F90.inc.c"
};
Vtx D_0101E740_58010[8] = {
#include "data/inc/D_0101E740_58010.inc.c"
};

const Gfx D_0101E7C0_58090[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0101E6C0_57F90, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 0, 5, 4, 0),
    gsSP2Triangles(1, 4, 7, 0, 7, 2, 1, 0),
    gsSP2Triangles(6, 3, 2, 0, 4, 1, 0, 0),
    gsSP2Triangles(6, 7, 4, 0, 2, 7, 6, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x5D, 0x32, 0x14, 0xFF),
    gsSPVertex(D_0101E740_58010, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 6, 3, 0, 2, 5, 0, 0),
    gsSP2Triangles(6, 7, 4, 0, 1, 0, 3, 0),
    gsSP2Triangles(5, 2, 7, 0, 3, 0, 5, 0),
    gsSP2Triangles(7, 2, 1, 0, 1, 4, 7, 0),
    gsSP2Triangles(4, 3, 6, 0, 7, 6, 5, 0),
    gsSPEndDisplayList(),
};
