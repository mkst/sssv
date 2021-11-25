#include <ultra64.h>

Vtx D_04002370_DF930[4] = {
#include "data/inc/D_04002370_DF930.inc.c"
};
Vtx D_040023B0_DF970[6] = {
#include "data/inc/D_040023B0_DF970.inc.c"
};

const Gfx D_04002410_DF9D0[] = {
    gsSPVertex(D_04002370_DF930, 4, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x64, 0x00, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP1Triangle(3, 0, 2, 0),
    gsDPSetPrimColor(0, 0, 0xE8, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_040023B0_DF970, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 1, 2, 0),
    gsSP2Triangles(1, 0, 3, 0, 4, 3, 0, 0),
    gsSP2Triangles(0, 2, 4, 0, 5, 4, 2, 0),
    gsSP2Triangles(3, 5, 1, 0, 2, 1, 5, 0),
    gsSPEndDisplayList(),
};
