#include <ultra64.h>

Vtx D_040079A0_F8A00[4] = {
#include "data/inc/D_040079A0_F8A00.inc.c"
};

Vtx D_040079E0_F8A40[4] = {
    #include "data/inc/D_040079E0_F8A40.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04007A20_F8A80[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_040079A0_F8A00, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04007A40_F8AA0[] = {
    gsSPVertex(D_040079E0_F8A40, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
