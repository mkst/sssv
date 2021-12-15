#include <ultra64.h>

Vtx D_05000000_87B80[8] = {
#include "data/inc/D_05000000_87B80.inc.c"
};
Vtx D_05000080_87C00[3] = {
#include "data/inc/D_05000080_87C00.inc.c"
};

Gfx D_050000B0_87C30[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05000000_87B80, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_05000080_87C00, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
