#include <ultra64.h>

Vtx D_04000500_E7AB0[4] = {
#include "data/inc/D_04000500_E7AB0.inc.c"
};
Vtx D_04000540_E7AF0[12] = {
#include "data/inc/D_04000540_E7AF0.inc.c"
};

Gfx D_04000600_E7BB0[] = {
    gsDPSetPrimColor(0, 0, 0x1E, 0x1E, 0x1E, 0xFF),
    gsSPVertex(D_04000500_E7AB0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04000540_E7AF0, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSPEndDisplayList(),
};
