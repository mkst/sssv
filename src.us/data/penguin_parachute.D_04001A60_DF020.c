#include <ultra64.h>

Vtx D_04001900_DEEC0[22] = {
#include "data/inc/D_04001900_DEEC0.inc.c"
};

extern Gfx D_01003548_3CE18[];

const Gfx D_04001A60_DF020[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04001900_DEEC0, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(2, 4, 3, 0, 5, 4, 2, 0),
    gsSP2Triangles(5, 2, 1, 0, 1, 6, 5, 0),
    gsSP1Quadrangle(7, 4, 5, 6, 0),
    gsSP2Triangles(6, 8, 7, 0, 9, 4, 7, 0),
    gsSP2Triangles(9, 7, 8, 0, 8, 10, 9, 0),
    gsSP2Triangles(11, 4, 9, 0, 3, 4, 11, 0),
    gsSP2Triangles(11, 9, 10, 0, 10, 12, 11, 0),
    gsSP2Triangles(12, 0, 3, 0, 3, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 18, 0),
    gsSP1Triangle(19, 20, 21, 0),
    gsSPEndDisplayList(),
};
