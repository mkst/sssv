#include <ultra64.h>

Vtx D_04006E00_E43C0[4] = {
#include "data/inc/D_04006E00_E43C0.inc.c"
};

Vtx D_04006E40_E4400[4] = {
#include "data/inc/D_04006E40_E4400.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04006E80_E4440[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04006E00_E43C0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04006EA0_E4460[] = {
    gsSPVertex(D_04006E40_E4400, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
