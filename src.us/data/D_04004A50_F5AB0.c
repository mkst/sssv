#include <ultra64.h>

Vtx D_04004940_F59A0[8] = {
#include "data/inc/D_04004940_F59A0.inc.c"
};
Vtx D_040049C0_F5A20[9] = {
#include "data/inc/D_040049C0_F5A20.inc.c"
};

const Gfx D_04004A50_F5AB0[] = {
    gsDPSetPrimColor(0, 0, 0x6E, 0x00, 0x7E, 0xFF),
    gsSPVertex(D_04004940_F59A0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 3, 4, 0, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 2, 4, 0),
    gsSP2Triangles(3, 6, 5, 0, 2, 5, 6, 0),
    gsSP2Triangles(6, 3, 7, 0, 7, 2, 6, 0),
    gsSP2Triangles(2, 7, 1, 0, 3, 1, 7, 0),
    gsDPSetPrimColor(0, 0, 0xE6, 0x87, 0xB0, 0xFF),
    gsSPVertex(D_040049C0_F5A20, 9, 0),
    gsSP2Triangles(1, 2, 0, 0, 4, 5, 3, 0),
    gsSP1Triangle(7, 8, 6, 0),
    gsSPEndDisplayList(),
};
