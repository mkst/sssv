#include <ultra64.h>

Vtx D_010186A0_51F70[6] = {
#include "data/inc/D_010186A0_51F70.inc.c"
};
Vtx D_01018700_51FD0[6] = {
#include "data/inc/D_01018700_51FD0.inc.c"
};

Gfx D_01018760_52030[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xFF, 0x38, 0x38, 0xFF),
    gsSPVertex(D_010186A0_51F70, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Quadrangle(0, 2, 3, 5, 0),
    gsSP1Quadrangle(2, 1, 4, 3, 0),
    gsSP1Quadrangle(1, 0, 5, 4, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xB6, 0xB6, 0xB6, 0xFF),
    gsSPVertex(D_01018700_51FD0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(2, 4, 0, 0, 1, 5, 3, 0),
    gsSP2Triangles(5, 0, 4, 0, 4, 3, 5, 0),
    gsSPEndDisplayList(),
};
