#include <ultra64.h>

Vtx D_04002030_DF5F0[6] = {
#include "data/inc/D_04002030_DF5F0.inc.c"
};

const Gfx D_04002090_DF650[] = {
    gsSPVertex(D_04002030_DF5F0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsSP2Triangles(4, 1, 2, 0, 2, 3, 4, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 0, 1, 0),
    gsSP2Triangles(1, 4, 5, 0, 0, 5, 3, 0),
    gsSPEndDisplayList(),
};
