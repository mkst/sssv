#include <ultra64.h>

Vtx D_040027A0_E9D50[4] = {
#include "data/inc/D_040027A0_E9D50.inc.c"
};

Vtx D_040027E0_E9D90[4] = {
#include "data/inc/D_040027E0_E9D90.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04002820_E9DD0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_040027A0_E9D50, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04002840_E9DF0[] = {
    gsSPVertex(D_040027E0_E9D90, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
