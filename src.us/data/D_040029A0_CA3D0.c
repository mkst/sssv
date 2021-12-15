#include <ultra64.h>

Vtx D_04002940_CA370[6] = {
#include "data/inc/D_04002940_CA370.inc.c"
};
extern Gfx D_01003780_3D050[];

Gfx D_040029A0_CA3D0[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_04002940_CA370, 6, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsSP2Triangles(0, 2, 5, 0, 1, 3, 5, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
