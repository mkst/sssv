#include <ultra64.h>

Vtx D_04001A00_F2A60[12] = {
#include "data/inc/D_04001A00_F2A60.inc.c"
};

Gfx D_04001AC0_F2B20[] = {
    gsDPSetPrimColor(0, 0, 0x7D, 0x33, 0xFF, 0xFF),
    gsSPVertex(D_04001A00_F2A60, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSPEndDisplayList(),
};
