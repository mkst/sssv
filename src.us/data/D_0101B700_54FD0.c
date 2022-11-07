#include <ultra64.h>

Vtx D_0101B0B0_54980[8] = {
#include "data/inc/D_0101B0B0_54980.inc.c"
};
Vtx D_0101B130_54A00[30] = {
#include "data/inc/D_0101B130_54A00.inc.c"
};
Vtx D_0101B310_54BE0[9] = {
#include "data/inc/D_0101B310_54BE0.inc.c"
};
Vtx D_0101B3A0_54C70[30] = {
#include "data/inc/D_0101B3A0_54C70.inc.c"
};
Vtx D_0101B580_54E50[14] = {
#include "data/inc/D_0101B580_54E50.inc.c"
};
Vtx D_0101B660_54F30[10] = {
#include "data/inc/D_0101B660_54F30.inc.c"
};

Gfx D_0101B700_54FD0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101B0B0_54980, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101B130_54A00, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 2, 0),
    gsSP2Triangles(4, 0, 2, 0, 2, 5, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(10, 7, 6, 0, 9, 7, 11, 0),
    gsSP2Triangles(11, 7, 10, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 13, 12, 0, 16, 15, 12, 0),
    gsSP2Triangles(17, 16, 12, 0, 12, 14, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 19, 18, 0),
    gsSP2Triangles(22, 19, 21, 0, 23, 19, 22, 0),
    gsSP2Triangles(20, 19, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 25, 24, 0, 28, 27, 24, 0),
    gsSP2Triangles(29, 28, 24, 0, 24, 26, 29, 0),
    gsSPVertex(D_0101B310_54BE0, 9, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
    gsSP2Triangles(4, 1, 3, 0, 5, 1, 4, 0),
    gsSP2Triangles(2, 1, 5, 0, 6, 7, 8, 0),
    gsSPVertex(D_0101B3A0_54C70, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(0, 5, 3, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 6, 0, 11, 2, 1, 0),
    gsSP2Triangles(1, 12, 11, 0, 6, 11, 12, 0),
    gsSP2Triangles(12, 7, 6, 0, 2, 5, 0, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 13, 0),
    gsSP2Triangles(13, 18, 16, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 15, 14, 0),
    gsSP2Triangles(14, 26, 25, 0, 19, 25, 26, 0),
    gsSP2Triangles(26, 20, 19, 0, 15, 18, 13, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_0101B580_54E50, 14, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(4, 10, 13, 0, 13, 5, 4, 0),
    gsSP1Triangle(11, 3, 2, 0),
    gsSPVertex(D_0101B660_54F30, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 4, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 1, 0, 2, 3, 0, 0),
    gsSP2Triangles(4, 5, 3, 0, 6, 7, 5, 0),
    gsSP2Triangles(8, 9, 7, 0, 1, 0, 9, 0),
    gsSPEndDisplayList(),
};
