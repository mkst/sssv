#include <ultra64.h>

Vtx D_04004AA0_1047F0[4] = {
#include "data/inc/D_04004AA0_1047F0.inc.c"
};
Vtx D_04004AE0_104830[4] = {
#include "data/inc/D_04004AE0_104830.inc.c"
};
Vtx D_04004B20_104870[6] = {
#include "data/inc/D_04004B20_104870.inc.c"
};
Vtx D_04004B80_1048D0[9] = {
#include "data/inc/D_04004B80_1048D0.inc.c"
};
Vtx D_04004C10_104960[16] = {
#include "data/inc/D_04004C10_104960.inc.c"
};


extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];


Gfx D_04004D10_104A60[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xFF, 0x20, 0x00, 0xFF),
    gsSPVertex(D_04004AA0_1047F0, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSPVertex(D_04004AE0_104830, 4, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPVertex(D_04004B20_104870, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(2, 0, 4, 0, 0, 3, 5, 0),
    gsSPVertex(D_04004B80_1048D0, 9, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 2, 0, 0),
    gsSP2Triangles(4, 2, 3, 0, 1, 2, 5, 0),
    gsSP2Triangles(2, 6, 5, 0, 7, 2, 4, 0),
    gsSP2Triangles(8, 2, 7, 0, 6, 2, 8, 0),
    gsSPVertex(D_04004C10_104960, 16, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x20, 0x00, 0xFF),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(1, 3, 4, 0, 5, 4, 3, 0),
    gsSP1Quadrangle(6, 5, 3, 2, 0),
    gsSP2Triangles(6, 7, 5, 0, 7, 8, 5, 0),
    gsSP2Triangles(4, 5, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 9, 7, 0, 6, 10, 7, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 11, 10, 0),
    gsSP2Triangles(6, 12, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(6, 14, 12, 0, 6, 15, 14, 0),
    gsSP2Triangles(2, 0, 15, 0, 6, 2, 15, 0),
    gsSPEndDisplayList(),
};
