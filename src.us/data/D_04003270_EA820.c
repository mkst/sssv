#include <ultra64.h>

Vtx D_04003090_EA640[7] = {
#include "data/inc/D_04003090_EA640.inc.c"
};
Vtx D_04003100_EA6B0[23] = {
#include "data/inc/D_04003100_EA6B0.inc.c"
};

Gfx D_04003270_EA820[] = {
    gsDPSetPrimColor(0, 0, 0xFF, 0xC6, 0x9B, 0xFF),
    gsSPVertex(D_04003090_EA640, 7, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(3, 2, 4, 0, 5, 4, 2, 0),
    gsSP2Triangles(0, 5, 2, 0, 0, 1, 6, 0),
    gsSP1Triangle(6, 1, 3, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0x8A, 0x47, 0xFF),
    gsSPVertex(D_04003100_EA6B0, 23, 0),
    gsSP2Triangles(0, 2, 1, 0, 1, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 1, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 0, 4, 7, 0),
    gsSP2Triangles(7, 8, 0, 0, 2, 0, 8, 0),
    gsSP2Triangles(9, 7, 4, 0, 7, 9, 10, 0),
    gsSP2Triangles(10, 11, 7, 0, 8, 7, 11, 0),
    gsSP2Triangles(12, 10, 9, 0, 9, 13, 12, 0),
    gsSP2Triangles(13, 9, 14, 0, 4, 14, 9, 0),
    gsSP1Quadrangle(15, 13, 14, 16, 0),
    gsSP2Triangles(15, 16, 6, 0, 14, 4, 16, 0),
    gsSP2Triangles(16, 3, 6, 0, 3, 16, 4, 0),
    gsSP2Triangles(13, 17, 12, 0, 17, 18, 12, 0),
    gsSP2Triangles(10, 12, 18, 0, 18, 19, 10, 0),
    gsSP2Triangles(11, 10, 19, 0, 5, 20, 17, 0),
    gsSP2Triangles(20, 5, 1, 0, 18, 17, 20, 0),
    gsSP2Triangles(20, 21, 18, 0, 19, 18, 21, 0),
    gsSP2Triangles(21, 20, 22, 0, 1, 22, 20, 0),
    gsSP1Triangle(22, 1, 2, 0),
    gsSPEndDisplayList(),
};
