#include <ultra64.h>

Vtx D_04008560_F95C0[8] = {
#include "data/inc/D_04008560_F95C0.inc.c"
};
Vtx D_040085E0_F9640[7] = {
#include "data/inc/D_040085E0_F9640.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04008650_F96B0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xE7, 0x6F, 0x97, 0xFF),
    gsSPVertex(D_04008560_F95C0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(1, 3, 4, 0, 0, 5, 3, 0),
    gsSP2Triangles(4, 3, 5, 0, 1, 6, 2, 0),
    gsSP2Triangles(2, 6, 0, 0, 0, 6, 5, 0),
    gsSP2Triangles(6, 7, 5, 0, 6, 1, 7, 0),
    gsSP2Triangles(1, 4, 7, 0, 5, 7, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040085E0_F9640, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP1Triangle(5, 6, 3, 0),
    gsSPEndDisplayList(),
};
