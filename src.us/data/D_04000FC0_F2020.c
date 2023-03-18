#include <ultra64.h>

Vtx D_04000F80_F1FE0[4] = {
#include "data/inc/D_04000F80_F1FE0.inc.c"
};

extern Gfx D_01003840_3D110[];

Gfx D_04000FC0_F2020[] = {
    gsSPVertex(D_04000F80_F1FE0, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
