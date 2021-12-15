#include <ultra64.h>

Vtx D_04006800_F7860[7] = {
#include "data/inc/D_04006800_F7860.inc.c"
};
Vtx D_04006870_F78D0[8] = {
#include "data/inc/D_04006870_F78D0.inc.c"
};

Gfx D_040068F0_F7950[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04006800_F7860, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP1Triangle(5, 6, 3, 0),
    gsDPSetPrimColor(0, 0, 0xE7, 0x6F, 0x97, 0xFF),
    gsSPVertex(D_04006870_F78D0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(1, 3, 4, 0, 0, 5, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 1, 6, 2, 0),
    gsSP2Triangles(2, 6, 0, 0, 0, 6, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 6, 1, 7, 0),
    gsSP2Triangles(1, 4, 7, 0, 5, 7, 4, 0),
    gsSPEndDisplayList(),
};
