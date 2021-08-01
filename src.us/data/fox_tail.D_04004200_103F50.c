#include <ultra64.h>


Vtx D_04004140_103E90[6] = {
#include "data/inc/D_04004140_103E90.inc.c"
};
Vtx D_040041A0_103EF0[6] = {
#include "data/inc/D_040041A0_103EF0.inc.c"
};


const Gfx D_04004200_103F50[] = {
    gsSPVertex(D_04004140_103E90, 6, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x20, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 0, 0),
    gsSP2Triangles(1, 0, 0, 0, 0, 3, 2, 0),
    gsSP2Triangles(3, 0, 0, 0, 0, 4, 3, 0),
    gsSP2Triangles(4, 0, 0, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 1, 5, 0, 5, 0, 0, 0),
    gsSPVertex(D_040041A0_103EF0, 6, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
    gsSP1Triangle(2, 0, 5, 0),
    gsSPEndDisplayList(),
};
