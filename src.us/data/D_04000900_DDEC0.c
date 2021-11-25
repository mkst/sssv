#include <ultra64.h>

Vtx D_04000890_DDE50[7] = {
#include "data/inc/D_04000890_DDE50.inc.c"
};

const Gfx D_04000900_DDEC0[] = {
    gsDPSetPrimColor(0, 0, 0xA3, 0x69, 0x00, 0xFF),
    gsSPVertex(D_04000890_DDE50, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(0, 4, 1, 0, 4, 3, 1, 0),
    gsSP2Triangles(0, 5, 4, 0, 5, 3, 4, 0),
    gsSP2Triangles(0, 6, 5, 0, 6, 3, 5, 0),
    gsSP2Triangles(0, 2, 6, 0, 2, 3, 6, 0),
    gsSPEndDisplayList(),
};
