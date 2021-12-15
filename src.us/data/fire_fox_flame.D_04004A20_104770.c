#include <ultra64.h>


Vtx D_04004710_104460[15] = {
#include "data/inc/D_04004710_104460.inc.c"
};
Vtx D_04004800_104550[9] = {
#include "data/inc/D_04004800_104550.inc.c"
};
Vtx D_04004890_1045E0[15] = {
#include "data/inc/D_04004890_1045E0.inc.c"
};
Vtx D_04004980_1046D0[10] = {  // technically 9?
#include "data/inc/D_04004980_1046D0.inc.c"
};

extern Gfx D_01003740_3D010[];

Gfx D_04004A20_104770[] = {
    gsSPDisplayList(D_01003740_3D010),
    gsSPVertex(D_04004710_104460, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04004800_104550, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPVertex(D_04004890_1045E0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04004980_1046D0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPEndDisplayList(),
};
