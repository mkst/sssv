#include <ultra64.h>

Vtx D_04003940_EAEF0[8] = {
#include "data/inc/D_04003940_EAEF0.inc.c"
};
Vtx D_040039C0_EAF70[8] = {
#include "data/inc/D_040039C0_EAF70.inc.c"
};
Vtx D_04003A40_EAFF0[31] = {
#include "data/inc/D_04003A40_EAFF0.inc.c"
};
Vtx D_04003C30_EB1E0[3] = {
#include "data/inc/D_04003C30_EB1E0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04003C60_EB210[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x00, 0xFF),
    gsSPVertex(D_04003940_EAEF0, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 1, 2, 0),
    gsSP2Triangles(1, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(7, 6, 5, 0, 3, 4, 7, 0),
    gsDPSetPrimColor(0, 0, 0xC8, 0xC8, 0x00, 0xFF),
    gsSPVertex(D_040039C0_EAF70, 8, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(2, 4, 1, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 6, 4, 0, 1, 6, 0, 0),
    gsSP2Triangles(6, 3, 0, 0, 6, 1, 4, 0),
    gsSP2Triangles(3, 6, 7, 0, 7, 2, 3, 0),
    gsSP2Triangles(6, 5, 7, 0, 2, 7, 5, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04003A40_EAFF0, 31, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 9, 8, 0, 1, 11, 10, 0),
    gsSP2Triangles(9, 10, 11, 0, 11, 1, 12, 0),
    gsSP2Triangles(13, 15, 14, 0, 14, 15, 16, 0),
    gsSP2Triangles(16, 15, 17, 0, 17, 15, 18, 0),
    gsSP2Triangles(18, 15, 19, 0, 19, 15, 13, 0),
    gsSP2Triangles(20, 22, 21, 0, 21, 24, 23, 0),
    gsSP2Triangles(23, 26, 25, 0, 25, 28, 27, 0),
    gsSP1Triangle(27, 30, 29, 0),
    gsSPVertex(D_04003C30_EB1E0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
