#include <ultra64.h>

Vtx D_04000330_DD8F0[5] = {
#include "data/inc/D_04000330_DD8F0.inc.c"
};
Vtx D_04000380_DD940[8] = {
#include "data/inc/D_04000380_DD940.inc.c"
};
Vtx D_04000400_DD9C0[26] = {
#include "data/inc/D_04000400_DD9C0.inc.c"
};

const Gfx D_040005A0_DDB60[] = {
    gsSPVertex(D_04000330_DD8F0, 5, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(0, 1, 4, 0, 4, 1, 3, 0),
    gsSP2Triangles(0, 4, 2, 0, 2, 4, 3, 0),
    gsSPVertex(D_04000380_DD940, 8, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSPVertex(D_04000400_DD9C0, 26, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 2, 3, 0),
    gsSP2Triangles(3, 4, 6, 0, 7, 6, 4, 0),
    gsSP2Triangles(8, 3, 6, 0, 3, 8, 5, 0),
    gsSP2Triangles(9, 5, 8, 0, 5, 9, 10, 0),
    gsSP2Triangles(2, 5, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(11, 9, 12, 0, 12, 9, 13, 0),
    gsSP2Triangles(13, 9, 8, 0, 6, 13, 8, 0),
    gsSP2Triangles(10, 14, 2, 0, 14, 1, 2, 0),
    gsSP2Triangles(14, 10, 11, 0, 1, 14, 15, 0),
    gsSP2Triangles(16, 15, 14, 0, 11, 16, 14, 0),
    gsSP2Triangles(16, 11, 12, 0, 12, 17, 16, 0),
    gsSP2Triangles(13, 6, 17, 0, 6, 7, 17, 0),
    gsSP2Triangles(17, 12, 13, 0, 18, 17, 7, 0),
    gsSP2Triangles(15, 16, 18, 0, 17, 18, 16, 0),
    gsSP2Triangles(19, 1, 15, 0, 1, 19, 20, 0),
    gsSP2Triangles(20, 0, 1, 0, 21, 20, 19, 0),
    gsSP2Triangles(15, 22, 19, 0, 21, 19, 22, 0),
    gsSP2Triangles(22, 15, 18, 0, 18, 23, 22, 0),
    gsSP2Triangles(21, 22, 23, 0, 23, 18, 7, 0),
    gsSP2Triangles(21, 24, 20, 0, 0, 20, 24, 0),
    gsSP2Triangles(24, 4, 0, 0, 21, 23, 25, 0),
    gsSP2Triangles(7, 25, 23, 0, 4, 24, 25, 0),
    gsSP2Triangles(21, 25, 24, 0, 25, 7, 4, 0),
    gsSPEndDisplayList(),
};
