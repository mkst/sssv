#include <ultra64.h>

Vtx D_04000F30_100C80[8] = {
#include "data/inc/D_04000F30_100C80.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04000FB0_100D00[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_04000F30_100C80, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 1, 3, 4, 0),
    gsSP2Triangles(4, 0, 5, 0, 2, 5, 0, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 4, 6, 0, 5, 7, 6, 0),
    gsSP2Triangles(6, 7, 2, 0, 2, 7, 5, 0),
    gsSPEndDisplayList(),
};
