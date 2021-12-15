#include <ultra64.h>

Vtx D_04007CF0_CF720[12] = {
#include "data/inc/D_04007CF0_CF720.inc.c"
};
Vtx D_04007DB0_CF7E0[8] = {
#include "data/inc/D_04007DB0_CF7E0.inc.c"
};
Vtx D_04007E30_CF860[9] = {
#include "data/inc/D_04007E30_CF860.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04007EC0_CF8F0[] = {
    gsDPSetPrimColor(0, 0, 0xB0, 0x3F, 0x00, 0xFF),
    gsSPVertex(D_04007CF0_CF720, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(2, 0, 4, 0, 5, 2, 4, 0),
    gsSP2Triangles(0, 3, 6, 0, 6, 7, 5, 0),
    gsSP2Triangles(2, 5, 7, 0, 7, 6, 3, 0),
    gsSP2Triangles(8, 2, 7, 0, 9, 7, 3, 0),
    gsSP2Triangles(1, 9, 3, 0, 7, 9, 8, 0),
    gsSP2Triangles(9, 1, 10, 0, 1, 11, 10, 0),
    gsSP2Triangles(11, 1, 2, 0, 2, 8, 11, 0),
    gsDPSetPrimColor(0, 0, 0xAD, 0x6B, 0x52, 0xFF),
    gsSPVertex(D_04007DB0_CF7E0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 3, 4, 0),
    gsSP2Triangles(3, 5, 2, 0, 6, 2, 5, 0),
    gsSP2Triangles(2, 6, 1, 0, 4, 6, 5, 0),
    gsSP2Triangles(6, 4, 7, 0, 4, 0, 7, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04007E30_CF860, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 5, 4, 0),
    gsSP1Triangle(6, 8, 7, 0),
    gsSPEndDisplayList(),
};
