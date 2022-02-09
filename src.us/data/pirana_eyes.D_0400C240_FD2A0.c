#include <ultra64.h>

Vtx D_0400C1C0_FD220[4] = {
#include "data/inc/D_0400C1C0_FD220.inc.c"
};

Vtx D_0400C200_FD260[4] = {
#include "data/inc/D_0400C200_FD260.inc.c"
};

extern Gfx D_01003850_3D120[];

Gfx D_0400C240_FD2A0[] = {
    gsSPDisplayList(D_01003850_3D120),
    gsSPVertex(D_0400C1C0_FD220, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_0400C260_FD2C0[] = {
    gsSPVertex(D_0400C200_FD260, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
