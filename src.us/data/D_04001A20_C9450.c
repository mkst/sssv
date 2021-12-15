#include <ultra64.h>

Vtx D_040019A0_C93D0[4] = {
#include "data/inc/D_040019A0_C93D0.inc.c"
};

Vtx D_040019E0_C9410[4] = {
#include "data/inc/D_040019E0_C9410.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];


Gfx D_04001A20_C9450[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_040019A0_C93D0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_04001A40_C9470[] = {
    gsSPVertex(D_040019E0_C9410, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
