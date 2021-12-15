#include <ultra64.h>

Vtx D_04000940_DDF00[14] = {
#include "data/inc/D_04000940_DDF00.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04000A20_DDFE0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000940_DDF00, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(4, 3, 1, 0, 1, 5, 4, 0),
    gsSP2Triangles(5, 1, 2, 0, 6, 3, 4, 0),
    gsSP2Triangles(4, 7, 6, 0, 7, 4, 5, 0),
    gsSP2Triangles(8, 3, 6, 0, 6, 9, 8, 0),
    gsSP2Triangles(9, 6, 7, 0, 0, 3, 10, 0),
    gsSP2Triangles(10, 3, 8, 0, 8, 11, 10, 0),
    gsSP2Triangles(11, 8, 9, 0, 10, 12, 0, 0),
    gsSP2Triangles(2, 0, 12, 0, 12, 10, 11, 0),
    gsSP2Triangles(9, 13, 11, 0, 11, 13, 12, 0),
    gsSP2Triangles(12, 13, 2, 0, 2, 13, 5, 0),
    gsSP2Triangles(5, 13, 7, 0, 7, 13, 9, 0),
    gsSPEndDisplayList(),
};
