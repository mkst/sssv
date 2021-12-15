#include <ultra64.h>

Vtx D_04000D30_E82E0[4] = {
#include "data/inc/D_04000D30_E82E0.inc.c"
};

Vtx D_04000D70_E8320[4] = {
    #include "data/inc/D_04000D70_E8320.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04000DB0_E8360[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04000D30_E82E0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04000DD0_E8380[] = {
    gsSPVertex(D_04000D70_E8320, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
