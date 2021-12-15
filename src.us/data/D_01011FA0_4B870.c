#include <ultra64.h>

Vtx D_01011DA0_4B670[8] = {
#include "data/inc/D_01011DA0_4B670.inc.c"
};
Vtx D_01011E20_4B6F0[24] = {
#include "data/inc/D_01011E20_4B6F0.inc.c"
};

Gfx D_01011FA0_4B870[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_01011DA0_4B670, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_01011E20_4B6F0, 24, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSPEndDisplayList(),
};
