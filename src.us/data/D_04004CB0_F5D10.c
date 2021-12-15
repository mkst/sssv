#include <ultra64.h>

Vtx D_04004C70_F5CD0[4] = {
#include "data/inc/D_04004C70_F5CD0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04004CB0_F5D10[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04004C70_F5CD0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};
