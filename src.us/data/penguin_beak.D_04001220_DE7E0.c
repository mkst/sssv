#include <ultra64.h>


Vtx D_040011E0_DE7A0[4] = {
#include "data/inc/D_040011E0_DE7A0.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_04001220_DE7E0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040011E0_DE7A0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP1Triangle(2, 3, 1, 0),
    gsSPEndDisplayList(),
};
