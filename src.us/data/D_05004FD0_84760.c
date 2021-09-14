#include <ultra64.h>

Vtx D_05004F50_846E0[8] = {
#include "data/inc/D_05004F50_846E0.inc.c"
};

const Gfx D_05004FD0_84760[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05004F50_846E0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 5, 4, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
