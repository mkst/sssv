#include <ultra64.h>

Vtx D_04001790_F27F0[16] = {
#include "data/inc/D_04001790_F27F0.inc.c"
};
Vtx D_04001890_F28F0[10] = {
#include "data/inc/D_04001890_F28F0.inc.c"
};

Gfx D_04001930_F2990[] = {
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04001790_F27F0, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSP2Triangles(10, 8, 9, 0, 9, 11, 10, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSPVertex(D_04001890_F28F0, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 5, 4, 0),
    gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSPEndDisplayList(),
};
