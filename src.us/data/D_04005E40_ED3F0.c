#include <ultra64.h>

Vtx D_04005DC0_ED370[4] = {
#include "data/inc/D_04005DC0_ED370.inc.c"
};

Vtx D_04005E00_ED3B0[4] = {
#include "data/inc/D_04005E00_ED3B0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04005E40_ED3F0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04005DC0_ED370, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04005E60_ED410[] = {
    gsSPVertex(D_04005E00_ED3B0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
