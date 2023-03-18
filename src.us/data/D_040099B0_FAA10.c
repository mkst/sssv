#include <ultra64.h>

Vtx D_04009950_FA9B0[6] = {
#include "data/inc/D_04009950_FA9B0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_040099B0_FAA10[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04009950_FA9B0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(3, 0, 4, 0, 5, 0, 1, 0),
    gsSP2Triangles(0, 5, 4, 0, 5, 1, 2, 0),
    gsSP1Triangle(5, 2, 3, 0),
    gsSPEndDisplayList(),
};
