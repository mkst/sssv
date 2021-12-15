#include <ultra64.h>

Vtx D_04004650_CC080[4] = {
#include "data/inc/D_04004650_CC080.inc.c"
};
Vtx D_04004690_CC0C0[4] = {
#include "data/inc/D_04004690_CC0C0.inc.c"
};

extern Gfx D_010037F0_3D0C0[];
extern Gfx D_01003840_3D110[];

Gfx D_040046D0_CC100[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04004650_CC080, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};

Gfx D_040046F0_CC120[] = {
    gsSPVertex(D_04004690_CC0C0, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
