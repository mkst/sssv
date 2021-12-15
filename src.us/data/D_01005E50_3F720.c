#include <ultra64.h>

Vtx D_01005A40_3F310[14] = {
#include "data/inc/D_01005A40_3F310.inc.c"
};
Vtx D_01005B20_3F3F0[17] = {
#include "data/inc/D_01005B20_3F3F0.inc.c"
};
Vtx D_01005C30_3F500[14] = {
#include "data/inc/D_01005C30_3F500.inc.c"
};
Vtx D_01005D10_3F5E0[14] = {
#include "data/inc/D_01005D10_3F5E0.inc.c"
};
Vtx D_01005DF0_3F6C0[6] = {
#include "data/inc/D_01005DF0_3F6C0.inc.c"
};

Gfx D_01005E50_3F720[] = {
    gsSPVertex(D_01005A40_3F310, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 12, 13, 0),
    gsSPVertex(D_01005B20_3F3F0, 17, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 0, 3, 0, 3, 2, 5, 0),
    gsSP2Triangles(2, 6, 5, 0, 6, 2, 1, 0),
    gsSP2Triangles(1, 7, 6, 0, 6, 8, 5, 0),
    gsSP2Triangles(8, 6, 7, 0, 7, 9, 8, 0),
    gsSP2Triangles(9, 4, 10, 0, 8, 10, 5, 0),
    gsSP2Triangles(10, 3, 5, 0, 10, 8, 9, 0),
    gsSP2Triangles(3, 10, 4, 0, 1, 0, 11, 0),
    gsSP2Triangles(11, 12, 1, 0, 7, 1, 12, 0),
    gsSP2Triangles(12, 13, 7, 0, 9, 7, 13, 0),
    gsSP2Triangles(13, 14, 9, 0, 4, 9, 14, 0),
    gsSP2Triangles(14, 15, 4, 0, 15, 11, 0, 0),
    gsSP2Triangles(0, 4, 15, 0, 11, 15, 16, 0),
    gsSP2Triangles(15, 14, 16, 0, 14, 13, 16, 0),
    gsSP2Triangles(13, 12, 16, 0, 12, 11, 16, 0),
    gsSPVertex(D_01005C30_3F500, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 12, 13, 0),
    gsSPVertex(D_01005D10_3F5E0, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 12, 13, 0),
    gsSPVertex(D_01005DF0_3F6C0, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 0, 2, 0, 4, 3, 0, 0),
    gsSP2Triangles(5, 4, 2, 0, 5, 3, 4, 0),
    gsSP2Triangles(1, 5, 2, 0, 1, 3, 5, 0),
    gsSPEndDisplayList(),
};
