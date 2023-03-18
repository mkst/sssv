#include <ultra64.h>

Vtx D_04006300_F7360[4] = {
#include "data/inc/D_04006300_F7360.inc.c"
};

Vtx D_04006340_F73A0[4] = {
  #include "data/inc/D_04006340_F73A0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04006380_F73E0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04006300_F7360, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_040063A0_F7400[] = {
    gsSPVertex(D_04006340_F73A0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
