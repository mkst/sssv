#include <ultra64.h>

Vtx D_04004DC0_EC370[26] = {
#include "data/inc/D_04004DC0_EC370.inc.c"
};
Vtx D_04004F60_EC510[12] = {
#include "data/inc/D_04004F60_EC510.inc.c"
};
Vtx D_04005020_EC5D0[3] = {
#include "data/inc/D_04005020_EC5D0.inc.c"
};

extern Gfx D_01003548_3CE18[];
extern Gfx D_01003618_3CEE8[];

Gfx D_04005050_EC600[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_04004DC0_EC370, 26, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(4, 1, 2, 0, 1, 4, 3, 0),
    gsSP2Triangles(2, 0, 5, 0, 6, 5, 0, 0),
    gsSP2Triangles(0, 3, 6, 0, 7, 2, 5, 0),
    gsSP2Triangles(3, 7, 6, 0, 5, 6, 7, 0),
    gsSP2Triangles(2, 7, 4, 0, 7, 3, 4, 0),
    gsSP2Triangles(8, 10, 9, 0, 11, 9, 10, 0),
    gsSP2Triangles(12, 8, 9, 0, 9, 11, 12, 0),
    gsSP2Triangles(8, 13, 10, 0, 14, 13, 8, 0),
    gsSP2Triangles(11, 14, 12, 0, 8, 12, 14, 0),
    gsSP2Triangles(10, 13, 15, 0, 16, 15, 13, 0),
    gsSP2Triangles(16, 14, 11, 0, 13, 14, 16, 0),
    gsSP2Triangles(16, 11, 17, 0, 17, 10, 15, 0),
    gsSP2Triangles(15, 16, 17, 0, 10, 17, 11, 0),
    gsSP2Triangles(18, 20, 19, 0, 21, 19, 20, 0),
    gsSP2Triangles(22, 21, 20, 0, 20, 18, 22, 0),
    gsSP2Triangles(23, 22, 18, 0, 19, 23, 18, 0),
    gsSP2Triangles(23, 19, 24, 0, 19, 21, 24, 0),
    gsSP2Triangles(25, 24, 21, 0, 24, 25, 23, 0),
    gsSP2Triangles(21, 22, 25, 0, 22, 23, 25, 0),
    gsDPSetPrimColor(0, 0, 0xAA, 0x55, 0x00, 0xFF),
    gsSPVertex(D_04004F60_EC510, 12, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 2, 3, 0),
    gsSP2Triangles(3, 2, 4, 0, 4, 2, 5, 0),
    gsSP2Triangles(5, 2, 0, 0, 6, 0, 1, 0),
    gsSP2Triangles(0, 6, 7, 0, 7, 5, 0, 0),
    gsSP2Triangles(1, 8, 6, 0, 8, 1, 3, 0),
    gsSP2Triangles(3, 9, 8, 0, 9, 3, 4, 0),
    gsSP2Triangles(4, 10, 9, 0, 5, 7, 10, 0),
    gsSP2Triangles(10, 4, 5, 0, 11, 7, 6, 0),
    gsSP1Quadrangle(11, 6, 8, 9, 0),
    gsSP1Quadrangle(11, 9, 10, 7, 0),
    gsSPDisplayList(D_01003618_3CEE8),
    gsSPVertex(D_04005020_EC5D0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
