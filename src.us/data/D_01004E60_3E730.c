#include <ultra64.h>

Vtx D_01004DE0_3E6B0[4] = {
#include "data/inc/D_01004DE0_3E6B0.inc.c"
};

Vtx D_01004E20_3E6F0[4] = {
#include "data/inc/D_01004E20_3E6F0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_01004E60_3E730[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_01004DE0_3E6B0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_01004E80_3E750[] = {
    gsSPVertex(D_01004E20_3E6F0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
