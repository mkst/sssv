#include <ultra64.h>


Vtx D_04003F10_103C60[18] = {
#include "data/inc/D_04003F10_103C60.inc.c"
};
Vtx D_04004030_103D80[6] = {
#include "data/inc/D_04004030_103D80.inc.c"
};


const Gfx D_04004090_103DE0[] = {
    gsSPVertex(D_04003F10_103C60, 18, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x20, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 5, 0, 6, 2, 3, 0),
    gsSP2Triangles(6, 5, 7, 0, 5, 8, 7, 0),
    gsSP2Triangles(8, 5, 4, 0, 6, 7, 9, 0),
    gsSP2Triangles(7, 10, 9, 0, 10, 7, 8, 0),
    gsSP1Quadrangle(11, 10, 8, 4, 0),
    gsSP1Quadrangle(11, 4, 0, 1, 0),
    gsSP2Triangles(11, 1, 12, 0, 6, 13, 2, 0),
    gsSP2Triangles(6, 14, 13, 0, 6, 9, 15, 0),
    gsSP2Triangles(6, 15, 14, 0, 9, 16, 15, 0),
    gsSP2Triangles(16, 9, 10, 0, 11, 16, 10, 0),
    gsSP2Triangles(11, 17, 16, 0, 17, 15, 16, 0),
    gsSP2Triangles(15, 17, 14, 0, 11, 12, 17, 0),
    gsSPVertex(D_04004030_103D80, 6, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 4, 0, 5, 0),
    gsSPEndDisplayList(),
};
