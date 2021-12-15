#include <ultra64.h>

Vtx D_04000AA0_DE060[4] = {
#include "data/inc/D_04000AA0_DE060.inc.c"
};

extern Gfx D_010037F0_3D0C0[];

Gfx D_04000AE0_DE0A0[] = {
    gsSPDisplayList(D_010037F0_3D0C0),
    gsSPVertex(D_04000AA0_DE060, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSPEndDisplayList(),
};
