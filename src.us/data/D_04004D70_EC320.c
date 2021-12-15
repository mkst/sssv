#include <ultra64.h>

Vtx D_04004CD0_EC280[5] = {
#include "data/inc/D_04004CD0_EC280.inc.c"
};
Vtx D_04004D20_EC2D0[5] = {
#include "data/inc/D_04004D20_EC2D0.inc.c"
};

Gfx D_04004D70_EC320[] = {
    gsDPSetPrimColor(0, 0, 0xD5, 0xAA, 0x80, 0xFF),
    gsSPVertex(D_04004CD0_EC280, 5, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 1, 4, 0),
    gsDPSetPrimColor(0, 0, 0xAA, 0x55, 0x00, 0xFF),
    gsSPVertex(D_04004D20_EC2D0, 5, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 2, 0),
    gsSPEndDisplayList(),
};
