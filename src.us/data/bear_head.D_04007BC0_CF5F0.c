#include <ultra64.h>


Vtx D_040078A0_CF2D0[13] = {
#include "data/inc/D_040078A0_CF2D0.inc.c"
};
Vtx D_04007970_CF3A0[13] = {
#include "data/inc/D_04007970_CF3A0.inc.c"
};
Vtx D_04007A40_CF470[12] = {
#include "data/inc/D_04007A40_CF470.inc.c"
};
Vtx D_04007B00_CF530[6] = {
#include "data/inc/D_04007B00_CF530.inc.c"
};
Vtx D_04007B60_CF590[6] = {
#include "data/inc/D_04007B60_CF590.inc.c"
};


extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04007BC0_CF5F0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_040078A0_CF2D0, 13, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 0, 1, 0),
    gsSP2Triangles(5, 4, 0, 0, 5, 6, 4, 0),
    gsSP2Triangles(6, 7, 4, 0, 3, 4, 7, 0),
    gsSP2Triangles(5, 8, 6, 0, 8, 9, 6, 0),
    gsSP2Triangles(7, 6, 9, 0, 9, 8, 10, 0),
    gsSP2Triangles(11, 10, 8, 0, 5, 1, 11, 0),
    gsSP2Triangles(5, 11, 8, 0, 1, 12, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_04007970_CF3A0, 13, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 5, 2, 0),
    gsSP2Triangles(0, 6, 5, 0, 0, 4, 6, 0),
    gsSP2Triangles(3, 7, 4, 0, 7, 3, 8, 0),
    gsSP2Triangles(1, 8, 3, 0, 8, 1, 9, 0),
    gsSP2Triangles(2, 9, 1, 0, 9, 2, 10, 0),
    gsSP2Triangles(5, 10, 2, 0, 10, 5, 11, 0),
    gsSP2Triangles(6, 11, 5, 0, 11, 6, 12, 0),
    gsSP2Triangles(12, 4, 7, 0, 4, 12, 6, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04007A40_CF470, 12, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 6, 5, 7, 0),
    gsSP1Quadrangle(8, 10, 9, 11, 0),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04007B00_CF530, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSPVertex(D_04007B60_CF590, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSPEndDisplayList(),
};
