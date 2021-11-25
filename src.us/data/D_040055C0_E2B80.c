#include <ultra64.h>

Vtx D_04005540_E2B00[4] = {
#include "data/inc/D_04005540_E2B00.inc.c"
};

Vtx D_04005580_E2B40[4] = {
#include "data/inc/D_04005580_E2B40.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

const Gfx D_040055C0_E2B80[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04005540_E2B00, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

const Gfx D_040055E0_E2BA0[] = {
    gsSPVertex(D_04005580_E2B40, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
