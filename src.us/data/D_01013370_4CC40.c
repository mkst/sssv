#include <ultra64.h>

Vtx D_01012E80_4C750[31] = {
#include "data/inc/D_01012E80_4C750.inc.c"
};
Vtx D_01013070_4C940[16] = {
#include "data/inc/D_01013070_4C940.inc.c"
};
Vtx D_01013170_4CA40[32] = {
#include "data/inc/D_01013170_4CA40.inc.c"
};

const Gfx D_01013370_4CC40[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0x02, 0x0F, 0xFF, 0xFF),
    gsSPVertex(D_01012E80_4C750, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP1Quadrangle(2, 1, 4, 5, 0),
    gsSP2Triangles(6, 2, 5, 0, 7, 6, 5, 0),
    gsSP2Triangles(8, 6, 7, 0, 9, 6, 8, 0),
    gsSP2Triangles(10, 6, 9, 0, 11, 10, 9, 0),
    gsSP2Triangles(12, 0, 3, 0, 13, 12, 3, 0),
    gsSP2Triangles(10, 13, 3, 0, 14, 13, 10, 0),
    gsSP2Triangles(15, 14, 10, 0, 11, 15, 10, 0),
    gsSP2Triangles(3, 16, 10, 0, 17, 16, 3, 0),
    gsSP2Triangles(17, 3, 2, 0, 2, 18, 17, 0),
    gsSP2Triangles(19, 18, 2, 0, 2, 6, 19, 0),
    gsSP2Triangles(6, 10, 16, 0, 16, 19, 6, 0),
    gsSP2Triangles(12, 13, 20, 0, 20, 21, 12, 0),
    gsSP2Triangles(0, 12, 21, 0, 21, 22, 0, 0),
    gsSP2Triangles(1, 0, 22, 0, 22, 23, 1, 0),
    gsSP2Triangles(24, 25, 4, 0, 4, 1, 24, 0),
    gsSP2Triangles(1, 23, 24, 0, 7, 5, 25, 0),
    gsSP2Triangles(25, 26, 7, 0, 8, 7, 26, 0),
    gsSP2Triangles(26, 27, 8, 0, 9, 8, 27, 0),
    gsSP2Triangles(27, 28, 9, 0, 11, 9, 28, 0),
    gsSP2Triangles(29, 11, 28, 0, 15, 11, 29, 0),
    gsSP2Triangles(30, 15, 29, 0, 14, 15, 30, 0),
    gsSPVertex(D_01013070_4C940, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
    gsSP2Triangles(1, 4, 3, 0, 5, 6, 7, 0),
    gsSP2Triangles(7, 8, 5, 0, 6, 9, 10, 0),
    gsSP2Triangles(10, 7, 6, 0, 11, 12, 10, 0),
    gsSP2Triangles(10, 9, 11, 0, 5, 8, 12, 0),
    gsSP2Triangles(12, 11, 5, 0, 13, 14, 15, 0),
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0, 0xDF, 0xFF, 0xDF, 0xFF),
    gsSPVertex(D_01013170_4CA40, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPEndDisplayList(),
};
