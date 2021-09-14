#include <ultra64.h>

Vtx D_05000000_BD2B0[23] = {
#include "data/inc/D_05000000_BD2B0.inc.c"
};
Vtx D_05000170_BD420[11] = {
#include "data/inc/D_05000170_BD420.inc.c"
};
Vtx D_05000220_BD4D0[6] = {
#include "data/inc/D_05000220_BD4D0.inc.c"
};

const Gfx D_05000280_BD530[] = {
    gsSPVertex(D_05000000_BD2B0, 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 0, 0),
    gsSP2Triangles(10, 11, 12, 0, 2, 1, 13, 0),
    gsSP2Triangles(14, 2, 13, 0, 4, 13, 15, 0),
    gsSP2Triangles(11, 0, 16, 0, 15, 0, 11, 0),
    gsSP2Triangles(1, 0, 15, 0, 15, 13, 1, 0),
    gsSP2Triangles(10, 17, 15, 0, 15, 11, 10, 0),
    gsSP2Triangles(13, 3, 16, 0, 3, 5, 12, 0),
    gsSP2Triangles(16, 12, 11, 0, 3, 12, 16, 0),
    gsSP2Triangles(15, 17, 4, 0, 3, 13, 4, 0),
    gsSP2Triangles(14, 6, 18, 0, 19, 8, 7, 0),
    gsSP2Triangles(14, 18, 2, 0, 9, 16, 0, 0),
    gsSP2Triangles(8, 18, 6, 0, 19, 16, 9, 0),
    gsSP2Triangles(19, 9, 8, 0, 20, 21, 22, 0),
    gsSPVertex(D_05000170_BD420, 11, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 3, 0, 7, 4, 3, 0),
    gsSP2Triangles(6, 3, 5, 0, 8, 9, 10, 0),
    gsSPVertex(D_05000220_BD4D0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
