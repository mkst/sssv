#include <ultra64.h>

Vtx D_040046A0_E1C60[18] = {
#include "data/inc/D_040046A0_E1C60.inc.c"
};
Vtx D_040047C0_E1D80[3] = {
#include "data/inc/D_040047C0_E1D80.inc.c"
};
Vtx D_040047F0_E1DB0[3] = {
#include "data/inc/D_040047F0_E1DB0.inc.c"
};
Vtx D_04004820_E1DE0[3] = {
#include "data/inc/D_04004820_E1DE0.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04004850_E1E10[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040046A0_E1C60, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
    gsSP2Triangles(7, 8, 5, 0, 7, 9, 8, 0),
    gsSP2Triangles(9, 10, 8, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 11, 9, 0, 7, 12, 9, 0),
    gsSP2Triangles(4, 12, 7, 0, 12, 13, 11, 0),
    gsSP2Triangles(4, 13, 12, 0, 13, 4, 6, 0),
    gsSP2Triangles(14, 11, 5, 0, 14, 15, 11, 0),
    gsSP2Triangles(11, 16, 5, 0, 5, 16, 17, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x64, 0xFF),
    gsSPVertex(D_040047C0_E1D80, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_040047F0_E1DB0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPVertex(D_04004820_E1DE0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPEndDisplayList(),
};
