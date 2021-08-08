#include <ultra64.h>


Vtx D_05001680_86E10[8] = {
#include "data/inc/D_05001680_86E10.inc.c"
};
Vtx D_05001700_86E90[30] = {
#include "data/inc/D_05001700_86E90.inc.c"
};
Vtx D_050018E0_87070[31] = {
#include "data/inc/D_050018E0_87070.inc.c"
};
Vtx D_05001AD0_87260[32] = {
#include "data/inc/D_05001AD0_87260.inc.c"
};
Vtx D_05001CD0_87460[31] = {
#include "data/inc/D_05001CD0_87460.inc.c"
};
Vtx D_05001EC0_87650[32] = {
#include "data/inc/D_05001EC0_87650.inc.c"
};
Vtx D_050020C0_87850[21] = {
#include "data/inc/D_050020C0_87850.inc.c"
};

const Gfx D_05002210_879A0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05001680_86E10, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05001700_86E90, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 11, 0, 20, 21, 2, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(25, 27, 28, 0, 25, 29, 26, 0),
    gsSPVertex(D_050018E0_87070, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
    gsSP2Triangles(4, 5, 6, 0, 5, 2, 7, 0),
    gsSP1Quadrangle(0, 8, 9, 10, 0),
    gsSP2Triangles(0, 11, 4, 0, 12, 7, 3, 0),
    gsSP2Triangles(13, 3, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 9, 0, 3, 20, 12, 0),
    gsSP2Triangles(21, 20, 3, 0, 12, 21, 6, 0),
    gsSP2Triangles(3, 7, 2, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 29, 30, 0),
    gsSPVertex(D_05001AD0_87260, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 12, 0, 21, 26, 27, 0),
    gsSP2Triangles(28, 16, 29, 0, 19, 18, 30, 0),
    gsSP1Triangle(18, 29, 31, 0),
    gsSPVertex(D_05001CD0_87460, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(0, 5, 6, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 7, 4, 12, 0),
    gsSP2Triangles(13, 14, 10, 0, 15, 16, 17, 0),
    gsSP2Triangles(17, 16, 13, 0, 9, 11, 17, 0),
    gsSP2Triangles(4, 6, 18, 0, 14, 15, 11, 0),
    gsSP2Triangles(9, 17, 10, 0, 5, 3, 7, 0),
    gsSP2Triangles(2, 1, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 5, 26, 27, 0),
    gsSP2Triangles(28, 2, 21, 0, 15, 29, 30, 0),
    gsSP1Triangle(28, 14, 13, 0),
    gsSPVertex(D_05001EC0_87650, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 5, 8, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 7, 10, 0),
    gsSP2Triangles(12, 11, 13, 0, 14, 12, 15, 0),
    gsSP2Triangles(8, 9, 7, 0, 16, 17, 4, 0),
    gsSP2Triangles(18, 19, 10, 0, 20, 21, 13, 0),
    gsSP2Triangles(22, 23, 16, 0, 24, 25, 4, 0),
    gsSP2Triangles(26, 18, 8, 0, 22, 16, 27, 0),
    gsSP2Triangles(15, 28, 14, 0, 10, 13, 11, 0),
    gsSP2Triangles(22, 27, 23, 0, 29, 30, 31, 0),
    gsSPVertex(D_050020C0_87850, 21, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(11, 12, 9, 0, 13, 14, 15, 0),
    gsSP2Triangles(15, 16, 13, 0, 17, 18, 19, 0),
    gsSP1Triangle(19, 18, 20, 0),
    gsSPEndDisplayList(),
};
