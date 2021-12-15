#include <ultra64.h>

Vtx D_04004BE0_E21A0[25] = {
#include "data/inc/D_04004BE0_E21A0.inc.c"
};
Vtx D_04004D70_E2330[4] = {
#include "data/inc/D_04004D70_E2330.inc.c"
};
Vtx D_04004DB0_E2370[11] = {
#include "data/inc/D_04004DB0_E2370.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04004E60_E2420[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04004BE0_E21A0, 25, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(3, 1, 4, 0, 1, 2, 5, 0),
    gsSP2Triangles(6, 1, 5, 0, 7, 1, 6, 0),
    gsSP2Triangles(4, 1, 7, 0, 8, 7, 6, 0),
    gsSP2Triangles(4, 7, 8, 0, 8, 6, 9, 0),
    gsSP2Triangles(10, 9, 6, 0, 6, 5, 10, 0),
    gsSP2Triangles(11, 10, 5, 0, 12, 8, 9, 0),
    gsSP2Triangles(12, 4, 8, 0, 13, 12, 9, 0),
    gsSP2Triangles(14, 12, 13, 0, 3, 4, 14, 0),
    gsSP2Triangles(12, 14, 4, 0, 15, 14, 13, 0),
    gsSP2Triangles(16, 14, 15, 0, 5, 2, 16, 0),
    gsSP2Triangles(0, 3, 16, 0, 2, 0, 16, 0),
    gsSP2Triangles(14, 16, 3, 0, 17, 16, 15, 0),
    gsSP2Triangles(5, 16, 17, 0, 11, 5, 17, 0),
    gsSP2Triangles(9, 10, 18, 0, 18, 10, 19, 0),
    gsSP2Triangles(15, 13, 20, 0, 20, 13, 21, 0),
    gsSP2Triangles(13, 9, 21, 0, 21, 9, 18, 0),
    gsSP2Triangles(21, 22, 20, 0, 18, 19, 22, 0),
    gsSP2Triangles(21, 18, 22, 0, 23, 20, 22, 0),
    gsSP2Triangles(17, 15, 23, 0, 23, 15, 20, 0),
    gsSP2Triangles(10, 24, 19, 0, 24, 22, 19, 0),
    gsSP2Triangles(11, 24, 10, 0, 11, 17, 24, 0),
    gsSP2Triangles(24, 23, 22, 0, 24, 17, 23, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04004D70_E2330, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsDPSetPrimColor(0, 0, 0xD2, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04004DB0_E2370, 11, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 0, 0),
    gsSP2Triangles(5, 7, 6, 0, 7, 8, 6, 0),
    gsSP2Triangles(9, 5, 6, 0, 10, 9, 6, 0),
    gsSPEndDisplayList(),
};
