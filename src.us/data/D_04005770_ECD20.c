#include <ultra64.h>

Vtx D_04005190_EC740[32] = {
#include "data/inc/D_04005190_EC740.inc.c"
};
Vtx D_04005390_EC940[20] = {
#include "data/inc/D_04005390_EC940.inc.c"
};
Vtx D_040054D0_ECA80[32] = {
#include "data/inc/D_040054D0_ECA80.inc.c"
};
Vtx D_040056D0_ECC80[10] = {
#include "data/inc/D_040056D0_ECC80.inc.c"
};

extern Gfx D_01003618_3CEE8[];

Gfx D_04005770_ECD20[] = {
    gsSPDisplayList(D_01003618_3CEE8),
    gsDPSetPrimColor(0, 0, 0xC8, 0xC8, 0xC8, 0xFF),
    gsSPVertex(D_04005190_EC740, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 5, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 7, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 2, 11, 0, 12, 10, 11, 0),
    gsSP2Triangles(10, 12, 13, 0, 14, 13, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 15, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 17, 16, 0),
    gsSP2Triangles(9, 19, 18, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 22, 21, 0, 22, 23, 21, 0),
    gsSP2Triangles(23, 24, 21, 0, 24, 25, 21, 0),
    gsSP2Triangles(26, 20, 21, 0, 25, 27, 21, 0),
    gsSP2Triangles(27, 28, 21, 0, 28, 29, 21, 0),
    gsSP2Triangles(29, 30, 21, 0, 30, 26, 21, 0),
    gsSP1Triangle(20, 31, 22, 0),
    gsSPVertex(D_04005390_EC940, 20, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 1, 2, 0),
    gsSP2Triangles(1, 3, 4, 0, 5, 4, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 8, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 12, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 16, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 0, 0),
    gsSP1Triangle(19, 18, 17, 0),
    gsDPSetPrimColor(0, 0, 0x14, 0x14, 0x14, 0xFF),
    gsSPVertex(D_040054D0_ECA80, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 6, 5, 0, 6, 4, 7, 0),
    gsSP2Triangles(8, 10, 9, 0, 10, 8, 11, 0),
    gsSP2Triangles(12, 14, 13, 0, 14, 12, 15, 0),
    gsSP2Triangles(16, 15, 12, 0, 17, 13, 14, 0),
    gsSP2Triangles(13, 17, 18, 0, 19, 18, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 20, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 15, 16, 23, 0),
    gsSP2Triangles(24, 23, 16, 0, 25, 22, 21, 0),
    gsSP2Triangles(22, 25, 26, 0, 27, 26, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 28, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 30, 31, 24, 0),
    gsSPVertex(D_040056D0_ECC80, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 3, 0, 1, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 3, 1, 0),
    gsSP2Triangles(6, 8, 7, 0, 8, 6, 9, 0),
    gsSPEndDisplayList(),
};
