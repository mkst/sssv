#include <ultra64.h>

Vtx D_04005480_E2A40[4] = {
#include "data/inc/D_04005480_E2A40.inc.c"
};

Vtx D_040054C0_E2A80[4] = {
    #include "data/inc/D_040054C0_E2A80.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

const Gfx D_04005500_E2AC0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04005480_E2A40, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

const Gfx D_04005520_E2AE0[] = {
    gsSPVertex(D_040054C0_E2A80, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
