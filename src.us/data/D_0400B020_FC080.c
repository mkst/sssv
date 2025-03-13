#include <ultra64.h>

Vtx D_0400AFA0_FC000[4] = {
#include "data/inc/D_0400AFA0_FC000.inc.c"
};
Vtx D_0400AFE0_FC040[4] = {
#include "data/inc/D_0400AFE0_FC040.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

Gfx D_0400B020_FC080[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_0400AFA0_FC000, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_0400B040_FC0A0[] = {
    gsSPVertex(D_0400AFE0_FC040, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
