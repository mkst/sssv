#include <ultra64.h>

Vtx D_04006EC0_E4480[32] = {
#include "data/inc/D_04006EC0_E4480.inc.c"
};
Vtx D_040070C0_E4680[3] = {
#include "data/inc/D_040070C0_E4680.inc.c"
};

extern Gfx D_01003618_3CEE8[];

const Gfx D_040070F0_E46B0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04006EC0_E4480, 32, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0xFF, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
    gsSP2Triangles(16, 15, 12, 0, 12, 17, 16, 0),
    gsSP1Triangle(12, 14, 17, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP1Triangle(18, 19, 20, 0),
    gsSP2Triangles(20, 21, 18, 0, 21, 20, 22, 0),
    gsSP2Triangles(19, 18, 23, 0, 23, 24, 19, 0),
    gsSP2Triangles(24, 23, 25, 0, 25, 26, 24, 0),
    gsSP2Triangles(26, 25, 27, 0, 27, 22, 26, 0),
    gsSP2Triangles(22, 27, 21, 0, 28, 29, 30, 0),
    gsSP1Triangle(28, 30, 31, 0),
    gsSPVertex(D_040070C0_E4680, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
