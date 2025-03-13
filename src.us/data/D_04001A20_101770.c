#include <ultra64.h>

Vtx D_040019A0_1016F0[4] = {
#include "data/inc/D_040019A0_1016F0.inc.c"
};
Vtx D_040019E0_101730[4] = {
#include "data/inc/D_040019E0_101730.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

Gfx D_04001A20_101770[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_040019A0_1016F0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_04001A40_101790[] = {
    gsSPVertex(D_040019E0_101730, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
