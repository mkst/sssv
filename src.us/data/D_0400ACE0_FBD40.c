#include <ultra64.h>

Vtx D_0400AB20_FBB80[4] = {
#include "data/inc/D_0400AB20_FBB80.inc.c"
};
Vtx D_0400AB60_FBBC0[8] = {
#include "data/inc/D_0400AB60_FBBC0.inc.c"
};
Vtx D_0400ABE0_FBC40[4] = {
#include "data/inc/D_0400ABE0_FBC40.inc.c"
};
Vtx D_0400AC20_FBC80[12] = {
#include "data/inc/D_0400AC20_FBC80.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_0400ACE0_FBD40[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_0400ABE0_FBC40, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSPVertex(D_0400AB20_FBB80, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_0400AB60_FBBC0, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(4, 6, 5, 7, 0),
    gsSPVertex(D_0400AC20_FBC80, 12, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x6B, 0x7B, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(4, 3, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 2, 0, 0, 2, 6, 7, 0),
    gsSP2Triangles(7, 4, 2, 0, 4, 7, 8, 0),
    gsSP2Triangles(7, 9, 8, 0, 9, 10, 8, 0),
    gsSP2Triangles(0, 11, 6, 0, 11, 9, 7, 0),
    gsSP2Triangles(11, 7, 6, 0, 11, 0, 1, 0),
    gsSPEndDisplayList(),
};
