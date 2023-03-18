#include <ultra64.h>

Vtx D_04005240_F62A0[27] = {
#include "data/inc/D_04005240_F62A0.inc.c"
};

extern Gfx D_01003548_3CE18[];

Gfx D_040053F0_F6450[] = {
    gsDPSetPrimColor(0, 0, 0x94, 0x94, 0x94, 0xFF),
    gsSPDisplayList(D_01003548_3CE18),
    gsSPVertex(D_04005240_F62A0, 27, 0),
    gsSP1Quadrangle(0, 0, 1, 2, 0),
    gsSP2Triangles(0, 0, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 7, 7, 0, 5, 7, 7, 0),
    gsSP2Triangles(0, 2, 8, 0, 8, 2, 4, 0),
    gsSP2Triangles(0, 0, 8, 0, 8, 4, 9, 0),
    gsSP1Quadrangle(9, 4, 6, 10, 0),
    gsSP1Quadrangle(10, 6, 7, 7, 0),
    gsSP2Triangles(0, 8, 11, 0, 11, 8, 9, 0),
    gsSP2Triangles(0, 0, 11, 0, 11, 9, 12, 0),
    gsSP1Quadrangle(12, 9, 10, 13, 0),
    gsSP1Quadrangle(13, 10, 7, 7, 0),
    gsSP2Triangles(0, 11, 14, 0, 14, 11, 12, 0),
    gsSP2Triangles(0, 0, 14, 0, 14, 12, 15, 0),
    gsSP1Quadrangle(15, 12, 13, 16, 0),
    gsSP1Quadrangle(16, 13, 7, 7, 0),
    gsSP2Triangles(0, 14, 17, 0, 17, 14, 15, 0),
    gsSP2Triangles(0, 0, 17, 0, 17, 15, 18, 0),
    gsSP1Quadrangle(18, 15, 16, 19, 0),
    gsSP1Quadrangle(19, 16, 7, 7, 0),
    gsSP2Triangles(0, 17, 20, 0, 20, 17, 18, 0),
    gsSP2Triangles(0, 0, 20, 0, 20, 18, 21, 0),
    gsSP1Quadrangle(21, 18, 19, 22, 0),
    gsSP1Quadrangle(22, 19, 7, 7, 0),
    gsSP2Triangles(0, 20, 23, 0, 23, 20, 21, 0),
    gsSP1Quadrangle(0, 0, 23, 1, 0),
    gsSP2Triangles(23, 21, 24, 0, 24, 21, 22, 0),
    gsSP1Quadrangle(1, 23, 24, 3, 0),
    gsSP2Triangles(24, 22, 25, 0, 25, 22, 7, 0),
    gsSP2Triangles(25, 7, 7, 0, 3, 24, 25, 0),
    gsSP2Triangles(3, 25, 5, 0, 5, 25, 7, 0),
    gsSPEndDisplayList(),
};
