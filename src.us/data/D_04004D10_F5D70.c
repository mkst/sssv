#include <ultra64.h>

Vtx D_04004CD0_F5D30[4] = {
#include "data/inc/D_04004CD0_F5D30.inc.c"
};

extern Gfx D_01003840_3D110[];

Gfx D_04004D10_F5D70[] = {
    gsSPVertex(D_04004CD0_F5D30, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
