#include <ultra64.h>

Vtx D_04002470_DFA30[4] = {
#include "data/inc/D_04002470_DFA30.inc.c"
};

Vtx D_040024B0_DFA70[4] = {
#include "data/inc/D_040024B0_DFA70.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_040024F0_DFAB0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04002470_DFA30, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04002510_DFAD0[] = {
    gsSPVertex(D_040024B0_DFA70, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
