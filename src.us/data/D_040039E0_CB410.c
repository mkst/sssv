#include <ultra64.h>

Vtx D_040037E0_CB210[32] = {
#include "data/inc/D_040037E0_CB210.inc.c"
};
extern Gfx D_01003618_3CEE8[];

const Gfx D_040039E0_CB410[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040037E0_CB210, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 9, 8, 0, 8, 11, 10, 0),
    gsSP2Triangles(12, 10, 11, 0, 11, 13, 12, 0),
    gsSP2Triangles(14, 12, 13, 0, 13, 15, 14, 0),
    gsSP2Triangles(16, 14, 15, 0, 15, 17, 16, 0),
    gsSP2Triangles(18, 16, 17, 0, 17, 19, 18, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 21, 18, 0),
    gsSP2Triangles(22, 21, 20, 0, 20, 23, 22, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 25, 22, 0),
    gsSP2Triangles(26, 25, 24, 0, 24, 27, 26, 0),
    gsSP2Triangles(28, 26, 27, 0, 27, 29, 28, 0),
    gsSP2Triangles(30, 28, 29, 0, 29, 31, 30, 0),
    gsSPEndDisplayList(),
};
