#include <ultra64.h>

Vtx D_04007F50_F8FB0[12] = {
#include "data/inc/D_04007F50_F8FB0.inc.c"
};
Vtx D_04008010_F9070[9] = {
#include "data/inc/D_04008010_F9070.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_040080A0_F9100[] = {
    gsSPVertex(D_04007F50_F8FB0, 12, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 4, 5, 7, 0),
    gsSP1Quadrangle(8, 6, 7, 9, 0),
    gsSP1Quadrangle(10, 8, 9, 11, 0),
    gsSPVertex(D_04008010_F9070, 9, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x80, 0x80, 0x80, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(4, 1, 3, 0, 4, 2, 1, 0),
    gsSP2Triangles(2, 4, 3, 0, 1, 5, 0, 0),
    gsSP2Triangles(6, 0, 5, 0, 6, 2, 0, 0),
    gsSP2Triangles(7, 6, 5, 0, 8, 7, 5, 0),
    gsSP2Triangles(8, 6, 7, 0, 6, 8, 5, 0),
    gsSPEndDisplayList(),
};
