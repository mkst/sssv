#include <ultra64.h>

Vtx D_040039F0_E0FB0[4] = {
#include "data/inc/D_040039F0_E0FB0.inc.c"
};
Vtx D_04003A30_E0FF0[3] = {
#include "data/inc/D_04003A30_E0FF0.inc.c"
};
Vtx D_04003A60_E1020[5] = {
#include "data/inc/D_04003A60_E1020.inc.c"
};
Vtx D_04003AB0_E1070[3] = {
#include "data/inc/D_04003AB0_E1070.inc.c"
};

Gfx D_04003AE0_E10A0[] = {
    gsSPVertex(D_040039F0_E0FB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04003A30_E0FF0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04003A60_E1020, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 2, 4, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04003AB0_E1070, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};
