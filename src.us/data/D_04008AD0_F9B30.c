#include <ultra64.h>

Vtx D_04008990_F99F0[4] = {
#include "data/inc/D_04008990_F99F0.inc.c"
};
Vtx D_040089D0_F9A30[4] = {
#include "data/inc/D_040089D0_F9A30.inc.c"
};
Vtx D_04008A10_F9A70[8] = {
#include "data/inc/D_04008A10_F9A70.inc.c"
};
Vtx D_04008A90_F9AF0[4] = {
#include "data/inc/D_04008A90_F9AF0.inc.c"
};

Gfx D_04008AD0_F9B30[] = {
    gsDPSetPrimColor(0, 0, 0xD6, 0xFF, 0xD6, 0xFF),
    gsSPVertex(D_04008990_F99F0, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 2, 0, 0),
    gsSPVertex(D_040089D0_F9A30, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 0, 1, 0),
    gsSPVertex(D_04008A90_F9AF0, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 2, 0, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x7B, 0x00, 0xFF),
    gsSPVertex(D_04008A10_F9A70, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 0, 2, 4, 0),
    gsSP2Triangles(1, 5, 3, 0, 1, 0, 5, 0),
    gsSP2Triangles(0, 4, 5, 0, 6, 7, 3, 0),
    gsSPEndDisplayList(),
};
