#include <ultra64.h>

Vtx D_040017D0_E8D80[17] = {
#include "data/inc/D_040017D0_E8D80.inc.c"
};
Vtx D_040018E0_E8E90[17] = {
#include "data/inc/D_040018E0_E8E90.inc.c"
};

Gfx D_040019F0_E8FA0[] = {
    gsDPSetPrimColor(0, 0, 0xCD, 0xCD, 0xCD, 0xFF),
    gsSPVertex(D_040017D0_E8D80, 17, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(1, 3, 4, 0, 5, 3, 2, 0),
    gsSP2Triangles(5, 2, 6, 0, 2, 0, 6, 0),
    gsSP2Triangles(5, 7, 3, 0, 7, 4, 3, 0),
    gsSP2Triangles(4, 7, 8, 0, 5, 9, 7, 0),
    gsSP2Triangles(9, 8, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 10, 9, 0, 5, 11, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 5, 13, 11, 0),
    gsSP2Triangles(13, 12, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(5, 15, 13, 0, 5, 6, 15, 0),
    gsSP2Triangles(15, 14, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(16, 6, 0, 0, 6, 16, 15, 0),
    gsDPSetPrimColor(0, 0, 0xFC, 0xDC, 0x5C, 0xFF),
    gsSPVertex(D_040018E0_E8E90, 17, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 4, 3, 0, 4, 5, 3, 0),
    gsSP2Triangles(3, 6, 2, 0, 6, 3, 5, 0),
    gsSP2Triangles(7, 2, 6, 0, 2, 7, 1, 0),
    gsSP2Triangles(0, 8, 4, 0, 8, 9, 4, 0),
    gsSP2Triangles(5, 4, 9, 0, 0, 1, 10, 0),
    gsSP2Triangles(0, 10, 11, 0, 10, 12, 11, 0),
    gsSP2Triangles(12, 10, 13, 0, 13, 1, 7, 0),
    gsSP2Triangles(1, 13, 10, 0, 14, 11, 12, 0),
    gsSP2Triangles(11, 14, 15, 0, 0, 11, 15, 0),
    gsSP2Triangles(0, 15, 8, 0, 15, 16, 8, 0),
    gsSP2Triangles(16, 15, 14, 0, 9, 8, 16, 0),
    gsSPEndDisplayList(),
};
