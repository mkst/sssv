#include <ultra64.h>

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Vtx D_04000990_1006E0[8] = {
#include "data/inc/D_04000990_1006E0.inc.c"
};
Vtx D_04000A10_100760[13] = {
#include "data/inc/D_04000A10_100760.inc.c"
};
Vtx D_04000AE0_100830[12] = {
#include "data/inc/D_04000AE0_100830.inc.c"
};
Vtx D_04000BA0_1008F0[15] = {
#include "data/inc/D_04000BA0_1008F0.inc.c"
};
Vtx D_04000C90_1009E0[6] = {
#include "data/inc/D_04000C90_1009E0.inc.c"
};
Vtx D_04000CF0_100A40[14] = {
#include "data/inc/D_04000CF0_100A40.inc.c"
};


Gfx D_04000DD0_100B20[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000990_1006E0, 8, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(0, 3, 4, 5, 0),
    gsSP1Quadrangle(0, 5, 6, 7, 0),
    gsDPSetPrimColor(0, 0, 0xC8, 0x64, 0x32, 0xFF),
    gsSPVertex(D_04000A10_100760, 13, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 2, 3, 0, 4, 5, 2, 0),
    gsSP2Triangles(5, 1, 2, 0, 1, 5, 6, 0),
    gsSP2Triangles(4, 7, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 4, 9, 7, 0),
    gsSP2Triangles(9, 8, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(4, 11, 9, 0, 4, 3, 11, 0),
    gsSP2Triangles(11, 10, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(12, 3, 0, 0, 3, 12, 11, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_04000AE0_100830, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 1, 2, 0),
    gsSP2Triangles(1, 5, 6, 0, 7, 6, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 4, 0),
    gsSP2Triangles(11, 10, 9, 0, 3, 4, 11, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000BA0_1008F0, 15, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 2, 5, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 9, 8, 0, 4, 10, 9, 0),
    gsSP2Triangles(8, 11, 6, 0, 12, 14, 13, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x00, 0x00, 0xFF),
    gsSPVertex(D_04000C90_1009E0, 6, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 2, 3, 0, 2, 4, 5, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000CF0_100A40, 14, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
    gsSP2Triangles(5, 8, 4, 0, 4, 10, 9, 0),
    gsSP2Triangles(4, 11, 10, 0, 12, 11, 13, 0),
    gsSPEndDisplayList(),
};
