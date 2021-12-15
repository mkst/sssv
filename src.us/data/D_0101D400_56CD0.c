#include <ultra64.h>

Vtx D_0101D030_56900[8] = {
#include "data/inc/D_0101D030_56900.inc.c"
};
Vtx D_0101D0B0_56980[31] = {
#include "data/inc/D_0101D0B0_56980.inc.c"
};
Vtx D_0101D2A0_56B70[18] = {
#include "data/inc/D_0101D2A0_56B70.inc.c"
};
Vtx D_0101D3C0_56C90[4] = {
#include "data/inc/D_0101D3C0_56C90.inc.c"
};

Gfx D_0101D400_56CD0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0101D030_56900, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0101D0B0_56980, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 14, 16, 0),
    gsSP2Triangles(17, 16, 18, 0, 19, 18, 20, 0),
    gsSP2Triangles(21, 20, 13, 0, 2, 22, 0, 0),
    gsSP2Triangles(5, 23, 3, 0, 8, 24, 6, 0),
    gsSP2Triangles(11, 25, 9, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 15, 0, 18, 19, 17, 0),
    gsSP2Triangles(20, 21, 19, 0, 13, 12, 21, 0),
    gsSP2Triangles(26, 27, 28, 0, 29, 30, 26, 0),
    gsSPVertex(D_0101D2A0_56B70, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(0, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(10, 11, 7, 0, 7, 12, 13, 0),
    gsSP2Triangles(14, 15, 7, 0, 7, 16, 17, 0),
    gsSPVertex(D_0101D3C0_56C90, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSPEndDisplayList(),
};
