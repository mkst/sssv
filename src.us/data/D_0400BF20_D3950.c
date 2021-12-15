#include <ultra64.h>

Vtx D_0400BC80_D36B0[31] = {
#include "data/inc/D_0400BC80_D36B0.inc.c"
};
Vtx D_0400BE70_D38A0[11] = {
#include "data/inc/D_0400BE70_D38A0.inc.c"
};

Gfx D_0400BF20_D3950[] = {
    gsSPVertex(D_0400BC80_D36B0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(5, 6, 2, 0, 2, 7, 5, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 7, 4, 0),
    gsSP2Triangles(2, 6, 0, 0, 4, 1, 0, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 13, 15, 16, 0),
    gsSP2Triangles(17, 16, 15, 0, 8, 11, 12, 0),
    gsSP2Triangles(15, 18, 17, 0, 17, 18, 9, 0),
    gsSP2Triangles(18, 10, 9, 0, 12, 19, 8, 0),
    gsSP2Triangles(16, 14, 13, 0, 14, 19, 12, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 26, 27, 0, 27, 20, 28, 0),
    gsSP2Triangles(24, 29, 30, 0, 30, 25, 24, 0),
    gsSP1Triangle(25, 26, 23, 0),
    gsSPVertex(D_0400BE70_D38A0, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(6, 0, 8, 0, 9, 5, 10, 0),
    gsSP2Triangles(6, 5, 9, 0, 9, 0, 6, 0),
    gsSP2Triangles(1, 0, 9, 0, 3, 1, 9, 0),
    gsSP1Triangle(10, 3, 9, 0),
    gsSPEndDisplayList(),
};
