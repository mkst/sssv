#include <ultra64.h>

Vtx D_0101F670_58F40[31] = {
#include "data/inc/D_0101F670_58F40.inc.c"
};
Vtx D_0101F860_59130[31] = {
#include "data/inc/D_0101F860_59130.inc.c"
};
Vtx D_0101FA50_59320[6] = {
#include "data/inc/D_0101FA50_59320.inc.c"
};

const Gfx D_0101FAB0_59380[] = {
    gsSPVertex(D_0101F670_58F40, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0101F860_59130, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(5, 6, 3, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 13, 29, 11, 0),
    gsSP1Triangle(19, 30, 17, 0),
    gsSPVertex(D_0101FA50_59320, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
