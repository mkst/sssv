#include <ultra64.h>

Vtx D_04002900_F3960[31] = {
#include "data/inc/D_04002900_F3960.inc.c"
};
Vtx D_04002AF0_F3B50[30] = {
#include "data/inc/D_04002AF0_F3B50.inc.c"
};
Vtx D_04002CD0_F3D30[10] = {
#include "data/inc/D_04002CD0_F3D30.inc.c"
};

extern Gfx D_010034C0_3CD90[];
extern Gfx D_01003548_3CE18[];

Gfx D_04002D70_F3DD0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPVertex(D_04002900_F3960, 31, 0),
    gsSP1Quadrangle(0, 2, 1, 3, 0),
    gsSP1Quadrangle(3, 1, 4, 5, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 0, 3, 0),
    gsSP2Triangles(7, 3, 8, 0, 8, 3, 5, 0),
    gsSP2Triangles(8, 5, 9, 0, 9, 5, 6, 0),
    gsSP1Quadrangle(10, 7, 8, 11, 0),
    gsSP1Quadrangle(11, 8, 9, 12, 0),
    gsSP2Triangles(12, 9, 6, 0, 13, 10, 11, 0),
    gsSP2Triangles(13, 11, 14, 0, 14, 11, 12, 0),
    gsSP2Triangles(14, 12, 15, 0, 15, 12, 6, 0),
    gsSP1Quadrangle(16, 13, 14, 17, 0),
    gsSP1Quadrangle(17, 14, 15, 18, 0),
    gsSP2Triangles(18, 15, 6, 0, 19, 16, 17, 0),
    gsSP2Triangles(19, 17, 20, 0, 20, 17, 18, 0),
    gsSP2Triangles(20, 18, 21, 0, 21, 18, 6, 0),
    gsSP1Quadrangle(22, 19, 20, 23, 0),
    gsSP1Quadrangle(23, 20, 21, 24, 0),
    gsSP2Triangles(24, 21, 6, 0, 25, 22, 23, 0),
    gsSP2Triangles(25, 23, 26, 0, 26, 23, 24, 0),
    gsSP2Triangles(26, 24, 27, 0, 27, 24, 6, 0),
    gsSP1Quadrangle(28, 25, 26, 29, 0),
    gsSP2Triangles(29, 26, 27, 0, 2, 28, 29, 0),
    gsSP2Triangles(2, 29, 1, 0, 29, 27, 30, 0),
    gsSP2Triangles(30, 27, 6, 0, 1, 29, 30, 0),
    gsSP2Triangles(1, 30, 4, 0, 4, 30, 6, 0),
    gsSPDisplayList(D_01003548_3CE18),
    gsDPSetPrimColor(0, 0, 0xFF, 0x64, 0x00, 0xFF),
    gsSPVertex(D_04002AF0_F3B50, 30, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 0, 3, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 1, 2, 0),
    gsSP2Triangles(1, 5, 6, 0, 7, 6, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 3, 4, 9, 0),
    gsSP2Triangles(10, 9, 4, 0, 11, 8, 7, 0),
    gsSP2Triangles(8, 11, 12, 0, 13, 12, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 9, 10, 17, 0),
    gsSP2Triangles(18, 17, 10, 0, 16, 19, 18, 0),
    gsSP2Triangles(17, 18, 19, 0, 19, 16, 15, 0),
    gsSP2Triangles(8, 20, 6, 0, 20, 8, 21, 0),
    gsSP2Triangles(12, 21, 8, 0, 21, 12, 22, 0),
    gsSP2Triangles(14, 22, 12, 0, 6, 23, 1, 0),
    gsSP2Triangles(23, 6, 20, 0, 10, 24, 18, 0),
    gsSP2Triangles(18, 25, 16, 0, 25, 18, 24, 0),
    gsSP2Triangles(16, 26, 14, 0, 26, 16, 25, 0),
    gsSP2Triangles(22, 14, 26, 0, 1, 27, 0, 0),
    gsSP2Triangles(27, 1, 23, 0, 0, 28, 4, 0),
    gsSP2Triangles(28, 0, 27, 0, 4, 29, 10, 0),
    gsSP2Triangles(29, 4, 28, 0, 24, 10, 29, 0),
    gsDPSetPrimColor(0, 0, 0x80, 0x80, 0x80, 0xFF),
    gsSPVertex(D_04002CD0_F3D30, 10, 0),
    gsSP2Triangles(0, 2, 1, 0, 2, 3, 1, 0),
    gsSP2Triangles(2, 0, 4, 0, 0, 5, 4, 0),
    gsSP2Triangles(3, 2, 6, 0, 7, 3, 6, 0),
    gsSP1Quadrangle(5, 0, 8, 9, 0),
    gsSPEndDisplayList(),
};
