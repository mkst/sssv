#include <ultra64.h>

Vtx D_040041F0_EB7A0[14] = {
#include "data/inc/D_040041F0_EB7A0.inc.c"
};
Vtx D_040042D0_EB880[6] = {
#include "data/inc/D_040042D0_EB880.inc.c"
};

Gfx D_04004330_EB8E0[] = {
    gsDPSetPrimColor(0, 0, 0xAA, 0x55, 0x00, 0xFF),
    gsSPVertex(D_040041F0_EB7A0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 4, 2, 0, 0, 2, 4, 0),
    gsSP2Triangles(5, 1, 0, 0, 1, 5, 6, 0),
    gsSP2Triangles(6, 3, 1, 0, 0, 7, 5, 0),
    gsSP2Triangles(8, 7, 0, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 5, 7, 10, 0),
    gsSP2Triangles(10, 6, 5, 0, 0, 4, 11, 0),
    gsSP2Triangles(4, 12, 11, 0, 4, 13, 12, 0),
    gsDPSetPrimColor(0, 0, 0xD5, 0xAA, 0x80, 0xFF),
    gsSPVertex(D_040042D0_EB880, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 4, 0, 4, 1, 5, 0),
    gsSPEndDisplayList(),
};
