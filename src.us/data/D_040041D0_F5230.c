#include <ultra64.h>

Vtx D_04004090_F50F0[14] = {
#include "data/inc/D_04004090_F50F0.inc.c"
};
Vtx D_04004170_F51D0[6] = {
#include "data/inc/D_04004170_F51D0.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040041D0_F5230[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04004090_F50F0, 14, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x64, 0x00, 0xFF),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
    gsSP2Triangles(4, 8, 7, 0, 5, 6, 9, 0),
    gsSP2Triangles(9, 10, 5, 0, 11, 5, 10, 0),
    gsSP2Triangles(12, 11, 10, 0, 13, 11, 12, 0),
    gsSPVertex(D_04004170_F51D0, 6, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSPEndDisplayList(),
};
