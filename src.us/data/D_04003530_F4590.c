#include <ultra64.h>

Vtx D_04003430_F4490[16] = {
#include "data/inc/D_04003430_F4490.inc.c"
};

Gfx D_04003530_F4590[] = {
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04003430_F4490, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSPEndDisplayList(),
};
