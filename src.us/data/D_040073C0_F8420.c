#include <ultra64.h>

Vtx D_040072C0_F8320[8] = {
#include "data/inc/D_040072C0_F8320.inc.c"
};
Vtx D_04007340_F83A0[8] = {
#include "data/inc/D_04007340_F83A0.inc.c"
};

Gfx D_040073C0_F8420[] = {
    gsSPVertex(D_040072C0_F8320, 8, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(1, 4, 3, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 7, 6, 5, 0),
    gsSPVertex(D_04007340_F83A0, 8, 0),
    gsDPSetPrimColor(0, 0, 0xE7, 0x6F, 0x97, 0xFF),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(3, 2, 4, 0, 2, 1, 5, 0),
    gsSP2Triangles(4, 2, 5, 0, 5, 1, 0, 0),
    gsSP2Triangles(5, 6, 4, 0, 6, 5, 7, 0),
    gsSP1Triangle(7, 5, 0, 0),
    gsSPEndDisplayList(),
};
