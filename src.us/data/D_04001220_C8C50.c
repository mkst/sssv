#include <ultra64.h>

Vtx D_040011A0_C8BD0[8] = {
#include "data/inc/D_040011A0_C8BD0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04001220_C8C50[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_040011A0_C8BD0, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 5, 0, 0),
    gsSP2Triangles(5, 4, 6, 0, 6, 1, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 6, 2, 7, 0),
    gsSPEndDisplayList(),
};
