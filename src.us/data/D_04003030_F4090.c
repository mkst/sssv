#include <ultra64.h>

Vtx D_04002F40_F3FA0[15] = {
#include "data/inc/D_04002F40_F3FA0.inc.c"
};

Gfx D_04003030_F4090[] = {
    gsSPVertex(D_04002F40_F3FA0, 15, 0),
    gsDPSetPrimColor(0, 0, 0x80, 0x80, 0x80, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(2, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 8, 5, 0, 9, 5, 8, 0),
    gsSP2Triangles(10, 7, 6, 0, 6, 11, 10, 0),
    gsSP2Triangles(12, 10, 11, 0, 11, 13, 12, 0),
    gsSP2Triangles(13, 9, 14, 0, 14, 12, 13, 0),
    gsSP1Triangle(8, 14, 9, 0),
    gsSPEndDisplayList(),
};
