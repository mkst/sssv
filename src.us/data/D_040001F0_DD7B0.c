#include <ultra64.h>

Vtx D_04000160_DD720[5] = {
#include "data/inc/D_04000160_DD720.inc.c"
};
Vtx D_040001B0_DD770[4] = {
#include "data/inc/D_040001B0_DD770.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_040001F0_DD7B0[] = {
    gsSPVertex(D_04000160_DD720, 5, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsSP2Triangles(0, 4, 3, 0, 4, 0, 1, 0),
    gsSPVertex(D_040001B0_DD770, 4, 0),
    gsDPSetPrimColor(0, 0, 0xA3, 0x69, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPEndDisplayList(),
};
