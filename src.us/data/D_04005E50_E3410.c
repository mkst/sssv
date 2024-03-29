#include <ultra64.h>

Vtx D_040058D0_E2E90[32] = {
#include "data/inc/D_040058D0_E2E90.inc.c"
};
Vtx D_04005AD0_E3090[32] = {
#include "data/inc/D_04005AD0_E3090.inc.c"
};
Vtx D_04005CD0_E3290[24] = {
#include "data/inc/D_04005CD0_E3290.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_04005E50_E3410[] = {
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_040058D0_E2E90, 32, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 5, 0, 4, 0),
    gsSP2Triangles(6, 0, 5, 0, 7, 0, 6, 0),
    gsSP2Triangles(2, 0, 7, 0, 8, 2, 7, 0),
    gsSP2Triangles(9, 1, 2, 0, 2, 8, 9, 0),
    gsSP2Triangles(10, 3, 1, 0, 1, 9, 10, 0),
    gsSP2Triangles(11, 4, 3, 0, 3, 10, 11, 0),
    gsSP2Triangles(12, 5, 4, 0, 4, 11, 12, 0),
    gsSP2Triangles(13, 6, 5, 0, 5, 12, 13, 0),
    gsSP2Triangles(14, 7, 6, 0, 6, 13, 14, 0),
    gsSP2Triangles(7, 14, 8, 0, 15, 9, 8, 0),
    gsSP2Triangles(16, 10, 9, 0, 9, 15, 16, 0),
    gsSP2Triangles(17, 16, 15, 0, 18, 11, 10, 0),
    gsSP2Triangles(10, 16, 18, 0, 19, 18, 16, 0),
    gsSP2Triangles(16, 17, 19, 0, 20, 12, 11, 0),
    gsSP2Triangles(11, 18, 20, 0, 21, 20, 18, 0),
    gsSP2Triangles(18, 19, 21, 0, 22, 13, 12, 0),
    gsSP2Triangles(12, 20, 22, 0, 23, 22, 20, 0),
    gsSP2Triangles(20, 21, 23, 0, 24, 14, 13, 0),
    gsSP2Triangles(13, 22, 24, 0, 25, 24, 22, 0),
    gsSP2Triangles(22, 23, 25, 0, 26, 8, 14, 0),
    gsSP2Triangles(14, 24, 26, 0, 8, 26, 15, 0),
    gsSP2Triangles(27, 26, 24, 0, 24, 25, 27, 0),
    gsSP2Triangles(28, 15, 26, 0, 26, 27, 28, 0),
    gsSP2Triangles(15, 28, 17, 0, 29, 19, 17, 0),
    gsSP2Triangles(30, 21, 19, 0, 19, 29, 30, 0),
    gsSP2Triangles(31, 23, 21, 0, 21, 30, 31, 0),
    gsSPVertex(D_04005AD0_E3090, 32, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 4, 5, 2, 0),
    gsSP2Triangles(6, 4, 0, 0, 0, 3, 6, 0),
    gsSP2Triangles(7, 6, 3, 0, 5, 4, 8, 0),
    gsSP2Triangles(8, 9, 5, 0, 10, 8, 4, 0),
    gsSP2Triangles(4, 6, 10, 0, 11, 10, 6, 0),
    gsSP2Triangles(6, 7, 11, 0, 12, 8, 10, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 11, 7, 0),
    gsSP2Triangles(14, 12, 11, 0, 11, 13, 14, 0),
    gsSP2Triangles(15, 14, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(16, 17, 14, 0, 12, 14, 17, 0),
    gsSP2Triangles(17, 16, 18, 0, 17, 19, 12, 0),
    gsSP2Triangles(8, 12, 19, 0, 19, 20, 8, 0),
    gsSP2Triangles(18, 21, 17, 0, 19, 17, 21, 0),
    gsSP2Triangles(21, 22, 19, 0, 20, 19, 22, 0),
    gsSP2Triangles(22, 23, 20, 0, 15, 24, 16, 0),
    gsSP2Triangles(16, 24, 18, 0, 25, 24, 15, 0),
    gsSP2Triangles(13, 25, 15, 0, 25, 13, 26, 0),
    gsSP2Triangles(26, 13, 27, 0, 7, 27, 13, 0),
    gsSP2Triangles(27, 7, 28, 0, 3, 28, 7, 0),
    gsSP2Triangles(28, 3, 29, 0, 30, 29, 23, 0),
    gsSP2Triangles(29, 30, 28, 0, 23, 22, 30, 0),
    gsSP2Triangles(29, 3, 31, 0, 31, 23, 29, 0),
    gsSPVertex(D_04005CD0_E3290, 24, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(2, 0, 4, 0, 5, 4, 0, 0),
    gsSP2Triangles(0, 3, 5, 0, 4, 5, 6, 0),
    gsSP2Triangles(6, 7, 4, 0, 8, 10, 9, 0),
    gsSP2Triangles(10, 8, 11, 0, 12, 11, 8, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 13, 12, 0),
    gsSP2Triangles(12, 15, 14, 0, 15, 12, 16, 0),
    gsSP2Triangles(8, 16, 12, 0, 16, 8, 17, 0),
    gsSP2Triangles(9, 17, 8, 0, 17, 9, 18, 0),
    gsSP2Triangles(17, 19, 16, 0, 18, 19, 17, 0),
    gsSP2Triangles(20, 16, 19, 0, 16, 20, 15, 0),
    gsSP2Triangles(20, 21, 15, 0, 15, 21, 14, 0),
    gsSP2Triangles(14, 21, 22, 0, 13, 14, 22, 0),
    gsSP2Triangles(23, 21, 20, 0, 19, 23, 20, 0),
    gsSPEndDisplayList(),
};
