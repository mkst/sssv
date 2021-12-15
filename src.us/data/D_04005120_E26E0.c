#include <ultra64.h>

Vtx D_04004F90_E2550[4] = {
#include "data/inc/D_04004F90_E2550.inc.c"
};
Vtx D_04004FD0_E2590[4] = {
#include "data/inc/D_04004FD0_E2590.inc.c"
};
Vtx D_04005010_E25D0[4] = {
#include "data/inc/D_04005010_E25D0.inc.c"
};
Vtx D_04005050_E2610[4] = {
#include "data/inc/D_04005050_E2610.inc.c"
};
Vtx D_04005090_E2650[4] = {
#include "data/inc/D_04005090_E2650.inc.c"
};
Vtx D_040050D0_E2690[5] = {
#include "data/inc/D_040050D0_E2690.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04005120_E26E0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04004F90_E2550, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPVertex(D_04004FD0_E2590, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPVertex(D_04005010_E25D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04005050_E2610, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_04005090_E2650, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040050D0_E2690, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 2, 4, 0),
    gsSPEndDisplayList(),
};
