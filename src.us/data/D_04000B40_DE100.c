#include <ultra64.h>

Vtx D_04000B00_DE0C0[4] = {
#include "data/inc/D_04000B00_DE0C0.inc.c"
};

extern Gfx D_01003840_3D110[];

Gfx D_04000B40_DE100[] = {
    gsSPVertex(D_04000B00_DE0C0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
