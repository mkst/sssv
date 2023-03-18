#include <ultra64.h>

Vtx D_04000F20_F1F80[4] = {
#include "data/inc/D_04000F20_F1F80.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04000F60_F1FC0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04000F20_F1F80, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};
