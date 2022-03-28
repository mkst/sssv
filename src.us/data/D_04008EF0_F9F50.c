#include <ultra64.h>

Vtx D_04008DB0_F9E10[4] = {
#include "data/inc/D_04008DB0_F9E10.inc.c"
};
Vtx D_04008DF0_F9E50[4] = {
#include "data/inc/D_04008DF0_F9E50.inc.c"
};
Vtx D_04008E30_F9E90[8] = {
#include "data/inc/D_04008E30_F9E90.inc.c"
};
Vtx D_04008EB0_F9F10[4] = {
#include "data/inc/D_04008EB0_F9F10.inc.c"
};

Gfx D_04008EF0_F9F50[] = {
    gsDPSetPrimColor(0, 0, 0xD6, 0xFF, 0xD6, 0xFF),
    gsSPVertex(D_04008DB0_F9E10, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 2, 0, 0),
    gsSPVertex(D_04008DF0_F9E50, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 0, 1, 0),
    gsSPVertex(D_04008EB0_F9F10, 4, 0),
    gsSP2Triangles(1, 0, 2, 0, 3, 1, 2, 0),
    gsSP1Triangle(3, 2, 0, 0),
    gsDPSetPrimColor(0, 0, 0x00, 0x7B, 0x00, 0xFF),
    gsSPVertex(D_04008E30_F9E90, 8, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 0, 2, 4, 0),
    gsSP2Triangles(1, 5, 3, 0, 1, 0, 5, 0),
    gsSP2Triangles(0, 4, 5, 0, 6, 7, 3, 0),
    gsSPEndDisplayList(),
};
