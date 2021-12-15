#include <ultra64.h>

Vtx D_04006B20_106870[4] = {
#include "data/inc/D_04006B20_106870.inc.c"
};

extern Gfx D_01003840_3D110[];

Gfx D_04006B60_1068B0[] = {
    gsSPVertex(D_04006B20_106870, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003840_3D110),
    gsSPEndDisplayList(),
};
