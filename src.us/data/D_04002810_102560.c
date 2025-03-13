#include <ultra64.h>

Vtx D_040027C0_102510[5] = {
#include "data/inc/D_040027C0_102510.inc.c"
};

extern Gfx D_01003780_3D050[];

Gfx D_04002810_102560[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_040027C0_102510, 5, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Vtx D_04002838_102588[5] = {
#include "data/inc/D_04002838_102588.inc.c"
};

Gfx D_04002888_1025D8[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_04002838_102588, 5, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
