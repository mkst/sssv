#include <ultra64.h>

Vtx D_04005D20_CD750[32] = {
#include "data/inc/D_04005D20_CD750.inc.c"
};
Vtx D_04005F20_CD950[18] = {
#include "data/inc/D_04005F20_CD950.inc.c"
};
extern Gfx D_01003548_3CE18[];

const Gfx D_04006040_CDA70[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0x66, 0x82, 0xFF, 0xFF),
    gsSPVertex(D_04005D20_CD750, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(0, 4, 3, 0, 3, 5, 2, 0),
    gsSP2Triangles(4, 0, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(7, 6, 8, 0, 9, 7, 8, 0),
    gsSP2Triangles(7, 9, 10, 0, 10, 11, 7, 0),
    gsSP2Triangles(11, 4, 7, 0, 4, 11, 12, 0),
    gsSP2Triangles(12, 3, 4, 0, 3, 12, 13, 0),
    gsSP2Triangles(5, 3, 13, 0, 13, 14, 5, 0),
    gsSP2Triangles(11, 10, 15, 0, 15, 16, 11, 0),
    gsSP2Triangles(16, 12, 11, 0, 12, 16, 17, 0),
    gsSP2Triangles(17, 13, 12, 0, 13, 17, 18, 0),
    gsSP2Triangles(14, 13, 18, 0, 18, 19, 14, 0),
    gsSP2Triangles(16, 15, 20, 0, 20, 21, 16, 0),
    gsSP2Triangles(21, 17, 16, 0, 17, 21, 22, 0),
    gsSP2Triangles(22, 18, 17, 0, 18, 22, 23, 0),
    gsSP2Triangles(19, 18, 23, 0, 23, 24, 19, 0),
    gsSP2Triangles(21, 20, 25, 0, 25, 26, 21, 0),
    gsSP2Triangles(26, 22, 21, 0, 22, 26, 27, 0),
    gsSP2Triangles(27, 23, 22, 0, 23, 27, 28, 0),
    gsSP2Triangles(24, 23, 28, 0, 28, 29, 24, 0),
    gsSP2Triangles(26, 25, 30, 0, 30, 31, 26, 0),
    gsSP1Triangle(31, 27, 26, 0),
    gsSPVertex(D_04005F20_CD950, 18, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 2, 0, 5, 0),
    gsSP2Triangles(5, 6, 2, 0, 4, 1, 7, 0),
    gsSP2Triangles(1, 8, 7, 0, 8, 1, 2, 0),
    gsSP2Triangles(2, 9, 8, 0, 9, 2, 6, 0),
    gsSP2Triangles(10, 9, 6, 0, 7, 11, 4, 0),
    gsSP2Triangles(6, 12, 10, 0, 9, 10, 13, 0),
    gsSP2Triangles(13, 14, 9, 0, 14, 8, 9, 0),
    gsSP2Triangles(8, 14, 15, 0, 15, 7, 8, 0),
    gsSP2Triangles(7, 15, 16, 0, 11, 7, 16, 0),
    gsSP1Triangle(14, 13, 17, 0),
    gsSPEndDisplayList(),
};
