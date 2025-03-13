#include <ultra64.h>

Vtx D_04000500_100250[19] = {
#include "data/inc/D_04000500_100250.inc.c"
};
Vtx D_04000630_100380[7] = {
#include "data/inc/D_04000630_100380.inc.c"
};
Vtx D_040006A0_1003F0[14] = {
#include "data/inc/D_040006A0_1003F0.inc.c"
};
Vtx D_04000780_1004D0[15] = {
#include "data/inc/D_04000780_1004D0.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04000870_1005C0[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0x80, 0xFF),
    gsSPVertex(D_04000500_100250, 19, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 1, 0, 0, 5, 1, 4, 0),
    gsSP2Triangles(6, 1, 5, 0, 3, 1, 6, 0),
    gsSP2Triangles(0, 2, 7, 0, 7, 8, 0, 0),
    gsSP2Triangles(4, 0, 8, 0, 9, 7, 2, 0),
    gsSP2Triangles(2, 3, 9, 0, 8, 10, 4, 0),
    gsSP2Triangles(5, 4, 10, 0, 10, 11, 5, 0),
    gsSP2Triangles(6, 5, 11, 0, 11, 12, 6, 0),
    gsSP2Triangles(12, 9, 3, 0, 3, 6, 12, 0),
    gsSP2Triangles(7, 9, 13, 0, 13, 14, 7, 0),
    gsSP2Triangles(8, 7, 14, 0, 14, 15, 8, 0),
    gsSP2Triangles(10, 8, 15, 0, 15, 16, 10, 0),
    gsSP2Triangles(11, 10, 16, 0, 16, 17, 11, 0),
    gsSP2Triangles(12, 11, 17, 0, 17, 18, 12, 0),
    gsSP2Triangles(18, 13, 9, 0, 9, 12, 18, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04000630_100380, 7, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 5, 2, 0),
    gsSP2Triangles(6, 0, 2, 0, 5, 6, 2, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_040006A0_1003F0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP2Triangles(5, 4, 8, 0, 4, 9, 10, 0),
    gsSP2Triangles(4, 10, 11, 0, 12, 13, 11, 0),
    gsSPVertex(D_04000780_1004D0, 15, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 2, 0, 6, 7, 5, 0),
    gsSP2Triangles(6, 8, 9, 0, 4, 9, 10, 0),
    gsSP2Triangles(8, 6, 11, 0, 12, 13, 14, 0),
    gsSPEndDisplayList(),
};
