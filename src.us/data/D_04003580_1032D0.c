#include <ultra64.h>

Vtx D_04003480_1031D0[8] = {
#include "data/inc/D_04003480_1031D0.inc.c"
};
Vtx D_04003500_103250[8] = {
#include "data/inc/D_04003500_103250.inc.c"
};

Gfx D_04003580_1032D0[] = {
    gsDPSetPrimColor(0, 0, 0x1E, 0x1E, 0x1E, 0xFF),
    gsSPVertex(D_04003480_1031D0, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSPVertex(D_04003500_103250, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
    gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
    gsSPEndDisplayList(),
};
