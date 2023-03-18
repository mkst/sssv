#include <ultra64.h>

Vtx D_04006B10_F7B70[11] = {
#include "data/inc/D_04006B10_F7B70.inc.c"
};
Vtx D_04006BC0_F7C20[9] = {
#include "data/inc/D_04006BC0_F7C20.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04006C50_F7CB0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04006B10_F7B70, 11, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 5, 4, 0, 0),
    gsSP2Triangles(5, 6, 4, 0, 4, 6, 7, 0),
    gsSP2Triangles(7, 6, 8, 0, 8, 1, 2, 0),
    gsSP2Triangles(6, 9, 8, 0, 8, 9, 1, 0),
    gsSP2Triangles(0, 1, 10, 0, 1, 9, 10, 0),
    gsSP2Triangles(9, 6, 10, 0, 6, 5, 10, 0),
    gsSP1Triangle(5, 0, 10, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04006BC0_F7C20, 9, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 5, 8, 0),
    gsSPEndDisplayList(),
};
