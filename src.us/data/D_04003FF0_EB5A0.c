#include <ultra64.h>

Vtx D_04003F70_EB520[4] = {
#include "data/inc/D_04003F70_EB520.inc.c"
};

Vtx D_04003FB0_EB560[4] = {
#include "data/inc/D_04003FB0_EB560.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04003FF0_EB5A0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04003F70_EB520, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_01003840_3D110[];

Gfx D_04004010_EB5C0[] = {
    gsSPVertex(D_04003FB0_EB560, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
