#include <ultra64.h>

Vtx D_0101C770_56040[31] = {
#include "data/inc/D_0101C770_56040.inc.c"
};
Vtx D_0101C960_56230[30] = {
#include "data/inc/D_0101C960_56230.inc.c"
};
Vtx D_0101CB40_56410[22] = {
#include "data/inc/D_0101CB40_56410.inc.c"
};

Gfx D_0101CCA0_56570[] = {
    gsSPVertex(D_0101C770_56040, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(1, 4, 2, 0, 5, 6, 7, 0),
    gsSP2Triangles(8, 6, 5, 0, 6, 9, 7, 0),
    gsSP2Triangles(10, 11, 12, 0, 13, 11, 10, 0),
    gsSP2Triangles(11, 14, 12, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 16, 15, 0, 16, 19, 17, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 21, 20, 0),
    gsSP2Triangles(21, 24, 22, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_0101C960_56230, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 5, 4, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 9, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 5, 18, 3, 0),
    gsSP2Triangles(8, 19, 6, 0, 9, 20, 5, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 23, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 22, 21, 0),
    gsSPVertex(D_0101CB40_56410, 22, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 1, 0),
    gsSP2Triangles(4, 3, 5, 0, 5, 0, 4, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 12, 18, 19, 0),
    gsSP2Triangles(2, 4, 0, 0, 2, 20, 3, 0),
    gsSP2Triangles(7, 21, 5, 0, 1, 0, 8, 0),
    gsSPEndDisplayList(),
};
