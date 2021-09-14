#include <ultra64.h>

Vtx D_04003720_CB150[4] = {
#include "data/inc/D_04003720_CB150.inc.c"
};
Vtx D_04003760_CB190[4] = {
    #include "data/inc/D_04003760_CB190.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

const Gfx D_040037A0_CB1D0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04003720_CB150, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};

const Gfx D_040037C0_CB1F0[] = {
    gsSPVertex(D_04003760_CB190, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
