#include <ultra64.h>

Vtx D_04007DF0_E53B0[4] = {
#include "data/inc/D_04007DF0_E53B0.inc.c"
};

Vtx D_04007E30_E53F0[4] = {
#include "data/inc/D_04007E30_E53F0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04007E70_E5430[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04007DF0_E53B0, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 2, 0, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04007E90_E5450[] = {
    gsSPVertex(D_04007E30_E53F0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
