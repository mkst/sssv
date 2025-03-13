#include <ultra64.h>

Vtx D_040028B0_102600[6] = {
#include "data/inc/D_040028B0_102600.inc.c"
};

extern Gfx D_01003780_3D050[];

Gfx D_04002910_102660[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_040028B0_102600, 6, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 1, 3, 5, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
