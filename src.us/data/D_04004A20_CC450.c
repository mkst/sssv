#include <ultra64.h>

Vtx D_04004710_CC140[15] = {
#include "data/inc/D_04004710_CC140.inc.c"
};
Vtx D_04004800_CC230[9] = {
#include "data/inc/D_04004800_CC230.inc.c"
};
Vtx D_04004890_CC2C0[15] = {
#include "data/inc/D_04004890_CC2C0.inc.c"
};
Vtx D_04004980_CC3B0[10] = { // alignment?
#include "data/inc/D_04004980_CC3B0.inc.c"
};

extern Gfx D_01003740_3D010[];

Gfx D_04004A20_CC450[] = {
    gsSPDisplayList(D_01003740_3D010),
    gsSPVertex(D_04004710_CC140, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04004800_CC230, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPVertex(D_04004890_CC2C0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP1Triangle(12, 13, 14, 0),
    gsSPVertex(D_04004980_CC3B0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP1Triangle(6, 7, 8, 0),
    gsSPEndDisplayList(),
};
