#include <ultra64.h>

Vtx D_040078A0_E4E60[15] = {
#include "data/inc/D_040078A0_E4E60.inc.c"
};
Vtx D_04007990_E4F50[15] = {
#include "data/inc/D_04007990_E4F50.inc.c"
};
Vtx D_04007A80_E5040[6] = {
#include "data/inc/D_04007A80_E5040.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003618_3CEE8[];

const Gfx D_04007AE0_E50A0[] = {
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0xFF, 0xFF),
    gsSPVertex(D_040078A0_E4E60, 15, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 7, 4, 5, 0),
    gsSP2Triangles(8, 6, 4, 0, 7, 8, 4, 0),
    gsSP2Triangles(8, 7, 6, 0, 9, 11, 10, 0),
    gsSP2Triangles(11, 12, 10, 0, 13, 10, 12, 0),
    gsSP1Triangle(12, 14, 13, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04007990_E4F50, 15, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 6, 1, 3, 0),
    gsSP2Triangles(6, 0, 1, 0, 0, 6, 7, 0),
    gsSP2Triangles(7, 5, 0, 0, 6, 3, 8, 0),
    gsSP2Triangles(3, 9, 8, 0, 9, 3, 4, 0),
    gsSP2Triangles(4, 10, 9, 0, 5, 7, 10, 0),
    gsSP2Triangles(10, 4, 5, 0, 11, 6, 8, 0),
    gsSP2Triangles(11, 9, 10, 0, 11, 8, 9, 0),
    gsSP2Triangles(6, 11, 12, 0, 12, 7, 6, 0),
    gsSP2Triangles(7, 12, 13, 0, 13, 10, 7, 0),
    gsSP2Triangles(11, 10, 14, 0, 10, 13, 14, 0),
    gsDPSetPrimColor(0, 0, 0xDE, 0xDE, 0xFF, 0xFF),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04007A80_E5040, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(2, 0, 3, 0, 4, 3, 0, 0),
    gsSP2Triangles(3, 4, 1, 0, 5, 1, 4, 0),
    gsSP1Triangle(5, 4, 0, 0),
    gsSPEndDisplayList(),
};
