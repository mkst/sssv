#include <ultra64.h>

Vtx D_04004070_E1630[4] = {
#include "data/inc/D_04004070_E1630.inc.c"
};
Vtx D_040040B0_E1670[4] = {
#include "data/inc/D_040040B0_E1670.inc.c"
};
Vtx D_040040F0_E16B0[4] = {
#include "data/inc/D_040040F0_E16B0.inc.c"
};
Vtx D_04004130_E16F0[5] = {
#include "data/inc/D_04004130_E16F0.inc.c"
};

Gfx D_04004180_E1740[] = {
    gsSPVertex(D_04004070_E1630, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPVertex(D_040040B0_E1670, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPVertex(D_040040F0_E16B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSPVertex(D_04004130_E16F0, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 2, 4, 0),
    gsSPEndDisplayList(),
};
