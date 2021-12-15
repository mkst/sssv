#include <ultra64.h>

Vtx D_04002220_DF7E0[4] = {
#include "data/inc/D_04002220_DF7E0.inc.c"
};
Vtx D_04002260_DF820[12] = {
#include "data/inc/D_04002260_DF820.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04002320_DF8E0[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xAB, 0xB8, 0xC1, 0xFF),
    gsSPVertex(D_04002220_DF7E0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xD9, 0xE9, 0xF4, 0xFF),
    gsSPVertex(D_04002260_DF820, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSPEndDisplayList(),
};
