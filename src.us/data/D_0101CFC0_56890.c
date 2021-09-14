#include <ultra64.h>

Vtx D_0101CD80_56650[8] = {
#include "data/inc/D_0101CD80_56650.inc.c"
};
Vtx D_0101CE00_566D0[24] = {
#include "data/inc/D_0101CE00_566D0.inc.c"
};
Vtx D_0101CF80_56850[4] = {
#include "data/inc/D_0101CF80_56850.inc.c"
};

const Gfx D_0101CFC0_56890[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101CD80_56650, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101CE00_566D0, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 11, 10, 5, 0),
    gsSP2Triangles(15, 16, 17, 0, 5, 18, 3, 0),
    gsSP2Triangles(19, 20, 21, 0, 11, 22, 9, 0),
    gsSP2Triangles(14, 23, 12, 0, 5, 4, 11, 0),
    gsSPVertex(D_0101CF80_56850, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};
