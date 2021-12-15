#include <ultra64.h>

Vtx D_040052F0_CCD20[7] = {
#include "data/inc/D_040052F0_CCD20.inc.c"
};
Vtx D_04005360_CCD90[7] = {
#include "data/inc/D_04005360_CCD90.inc.c"
};
extern Gfx D_01003618_3CEE8[];

Gfx D_040053D0_CCE00[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x99, 0x99, 0xFF),
    gsSPVertex(D_040052F0_CCD20, 7, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x99, 0x99, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 0, 3, 2, 0),
    gsSP2Triangles(0, 4, 3, 0, 0, 5, 4, 0),
    gsSP2Triangles(0, 6, 5, 0, 0, 1, 6, 0),
    gsSPVertex(D_04005360_CCD90, 7, 0),
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsSP2Triangles(4, 2, 3, 0, 5, 2, 4, 0),
    gsSP2Triangles(6, 2, 5, 0, 1, 2, 6, 0),
    gsSPEndDisplayList(),
};
