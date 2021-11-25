#include <ultra64.h>

Vtx D_040020C0_DF680[4] = {
#include "data/inc/D_040020C0_DF680.inc.c"
};
Vtx D_04002100_DF6C0[8] = {
#include "data/inc/D_04002100_DF6C0.inc.c"
};
Vtx D_04002180_DF740[4] = {
#include "data/inc/D_04002180_DF740.inc.c"
};

extern Gfx D_01003618_3CEE8[];

const Gfx D_040021C0_DF780[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xAB, 0xB8, 0xC1, 0xFF),
    gsSPVertex(D_040020C0_DF680, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPSetPrimColor(0, 0, 0xD9, 0xE9, 0xF4, 0xFF),
    gsSPVertex(D_04002100_DF6C0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSPVertex(D_04002180_DF740, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};
