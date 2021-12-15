#include <ultra64.h>

Vtx D_040041D0_E1790[4] = {
#include "data/inc/D_040041D0_E1790.inc.c"
};
Vtx D_04004210_E17D0[4] = {
#include "data/inc/D_04004210_E17D0.inc.c"
};
Vtx D_04004250_E1810[10] = {
#include "data/inc/D_04004250_E1810.inc.c"
};
Vtx D_040042F0_E18B0[21] = {
#include "data/inc/D_040042F0_E18B0.inc.c"
};
Vtx D_04004440_E1A00[18] = {
#include "data/inc/D_04004440_E1A00.inc.c"
};

extern Gfx D_01003618_3CEE8[];
extern Gfx D_01003548_3CE18[];
extern Gfx D_010034C0_3CD90[];

Gfx D_04004560_E1B20[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x9B, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04004250_E1810, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 2, 1, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 5, 7, 0),
    gsSP2Triangles(9, 8, 7, 0, 6, 9, 7, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_040041D0_E1790, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04004210_E17D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_040042F0_E18B0, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(0, 2, 4, 0, 5, 0, 4, 0),
    gsSP2Triangles(3, 0, 5, 0, 6, 3, 5, 0),
    gsSP2Triangles(6, 7, 3, 0, 7, 8, 3, 0),
    gsSP2Triangles(3, 8, 1, 0, 9, 8, 7, 0),
    gsSP2Triangles(9, 1, 8, 0, 10, 9, 7, 0),
    gsSP2Triangles(6, 11, 7, 0, 6, 5, 11, 0),
    gsSP2Triangles(12, 7, 11, 0, 7, 12, 10, 0),
    gsSP2Triangles(11, 5, 13, 0, 5, 4, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(16, 9, 10, 0, 16, 2, 1, 0),
    gsSP2Triangles(16, 1, 9, 0, 2, 16, 17, 0),
    gsSP2Triangles(17, 16, 10, 0, 4, 2, 17, 0),
    gsSP2Triangles(15, 13, 18, 0, 19, 11, 14, 0),
    gsSP2Triangles(12, 11, 19, 0, 13, 4, 20, 0),
    gsSP2Triangles(20, 18, 13, 0, 4, 17, 20, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x64, 0xFF),
    gsSPVertex(D_04004440_E1A00, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSPEndDisplayList(),
};
