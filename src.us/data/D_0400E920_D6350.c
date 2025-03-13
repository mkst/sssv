#include <ultra64.h>

Vtx D_0400E8A0_D62D0[8] = {
#include "data/inc/D_0400E8A0_D62D0.inc.c"
};

Gfx D_0400E920_D6350[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_0400E8A0_D62D0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
