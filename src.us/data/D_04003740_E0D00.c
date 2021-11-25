#include <ultra64.h>

Vtx D_040036C0_E0C80[4] = {
#include "data/inc/D_040036C0_E0C80.inc.c"
};

Vtx D_04003700_E0CC0[4] = {
    #include "data/inc/D_04003700_E0CC0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

const Gfx D_04003740_E0D00[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_040036C0_E0C80, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

const Gfx D_04003760_E0D20[] = {
    gsSPVertex(D_04003700_E0CC0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
