#include <ultra64.h>

Vtx D_0100E930_48200[31] = {
#include "data/inc/D_0100E930_48200.inc.c"
};
Vtx D_0100EB20_483F0[20] = {
#include "data/inc/D_0100EB20_483F0.inc.c"
};

Gfx D_0100EC60_48530[] = {
    gsSPVertex(D_0100E930_48200, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 13, 14, 11, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 29, 30, 27, 0),
    gsSPVertex(D_0100EB20_483F0, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 11, 8, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
    gsSPEndDisplayList(),
};
