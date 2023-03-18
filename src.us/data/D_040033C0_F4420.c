#include <ultra64.h>

Vtx D_04003300_F4360[12] = {
#include "data/inc/D_04003300_F4360.inc.c"
};

Gfx D_040033C0_F4420[] = {
    gsDPSetPrimColor(0, 0, 0x82, 0x64, 0x64, 0xFF),
    gsSPVertex(D_04003300_F4360, 12, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(3, 0, 4, 0, 4, 0, 5, 0),
    gsSP2Triangles(2, 5, 0, 0, 5, 6, 4, 0),
    gsSP2Triangles(2, 1, 7, 0, 7, 4, 6, 0),
    gsSP2Triangles(7, 8, 2, 0, 6, 8, 7, 0),
    gsSP2Triangles(9, 7, 1, 0, 4, 7, 9, 0),
    gsSP2Triangles(1, 3, 9, 0, 8, 6, 10, 0),
    gsSP2Triangles(6, 5, 10, 0, 5, 2, 10, 0),
    gsSP2Triangles(2, 8, 10, 0, 9, 11, 4, 0),
    gsSP1Triangle(4, 11, 3, 0),
    gsSPEndDisplayList(),
};
