#include <ultra64.h>

Vtx D_04004D30_F5D90[11] = {
#include "data/inc/D_04004D30_F5D90.inc.c"
};

Gfx D_04004DE0_F5E40[] = {
    gsDPSetPrimColor(0, 0, 0x6E, 0x00, 0x7E, 0xFF),
    gsSPVertex(D_04004D30_F5D90, 11, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 0, 3, 0, 1, 5, 3, 0),
    gsSP2Triangles(5, 1, 6, 0, 2, 6, 1, 0),
    gsSP2Triangles(6, 2, 7, 0, 0, 7, 2, 0),
    gsSP2Triangles(7, 0, 8, 0, 4, 8, 0, 0),
    gsSP2Triangles(8, 4, 9, 0, 9, 3, 5, 0),
    gsSP2Triangles(3, 9, 4, 0, 6, 10, 5, 0),
    gsSP2Triangles(5, 10, 9, 0, 9, 10, 8, 0),
    gsSP2Triangles(8, 10, 7, 0, 7, 10, 6, 0),
    gsSPEndDisplayList(),
};
