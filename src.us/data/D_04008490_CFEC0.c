#include <ultra64.h>

Vtx D_04008410_CFE40[4] = {
#include "data/inc/D_04008410_CFE40.inc.c"
};

Vtx D_04008450_CFE80[4] = {
#include "data/inc/D_04008450_CFE80.inc.c"
};

const Gfx D_04008490_CFEC0[] = {
    gsSPVertex(D_04008410_CFE40, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};

const Gfx D_040084A8_CFED8[] = {
    gsSPVertex(D_04008450_CFE80, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};
