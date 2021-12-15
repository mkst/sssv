#include <ultra64.h>

Vtx D_04001670_E8C20[10] = {
#include "data/inc/D_04001670_E8C20.inc.c"
};
Vtx D_04001710_E8CC0[5] = {
#include "data/inc/D_04001710_E8CC0.inc.c"
};

Gfx D_04001760_E8D10[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04001670_E8C20, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 2, 1, 0),
    gsSP2Triangles(1, 6, 5, 0, 7, 5, 6, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 4, 9, 0),
    gsSP2Triangles(9, 7, 8, 0, 3, 9, 4, 0),
    gsSPVertex(D_04001710_E8CC0, 5, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP1Triangle(4, 1, 0, 0),
    gsDPSetPrimColor(0, 0, 0xFC, 0xDC, 0x5C, 0xFF),
    gsSPEndDisplayList(),
};
