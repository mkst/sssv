#include <ultra64.h>

Vtx D_04003720_103470[4] = {
#include "data/inc/D_04003720_103470.inc.c"
};
Vtx D_04003760_1034B0[4] = {
#include "data/inc/D_04003760_1034B0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

Gfx D_040037A0_1034F0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04003720_103470, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_040037C0_103510[] = {
    gsSPVertex(D_04003760_1034B0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
