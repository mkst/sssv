#include <ultra64.h>

Vtx D_05000000_B0B90[32] = {
#include "data/inc/D_05000000_B0B90.inc.c"
};
Vtx D_05000200_B0D90[31] = {
#include "data/inc/D_05000200_B0D90.inc.c"
};
Vtx D_050003F0_B0F80[32] = {
#include "data/inc/D_050003F0_B0F80.inc.c"
};
Vtx D_050005F0_B1180[32] = {
#include "data/inc/D_050005F0_B1180.inc.c"
};
Vtx D_050007F0_B1380[31] = {
#include "data/inc/D_050007F0_B1380.inc.c"
};
Vtx D_050009E0_B1570[30] = {
#include "data/inc/D_050009E0_B1570.inc.c"
};
Vtx D_05000BC0_B1750[32] = {
#include "data/inc/D_05000BC0_B1750.inc.c"
};
Vtx D_05000DC0_B1950[31] = {
#include "data/inc/D_05000DC0_B1950.inc.c"
};
Vtx D_05000FB0_B1B40[32] = {
#include "data/inc/D_05000FB0_B1B40.inc.c"
};
Vtx D_050011B0_B1D40[30] = {
#include "data/inc/D_050011B0_B1D40.inc.c"
};
Vtx D_05001390_B1F20[20] = {
#include "data/inc/D_05001390_B1F20.inc.c"
};
Vtx D_050014D0_B2060[30] = {
#include "data/inc/D_050014D0_B2060.inc.c"
};
Vtx D_050016B0_B2240[3] = {
#include "data/inc/D_050016B0_B2240.inc.c"
};

Gfx D_050016E0_B2270[] = {
    gsSPVertex(D_05000000_B0B90, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 11, 13, 0, 14, 13, 15, 0),
    gsSP2Triangles(2, 16, 0, 0, 5, 17, 3, 0),
    gsSP2Triangles(8, 18, 6, 0, 11, 12, 9, 0),
    gsSP2Triangles(13, 14, 12, 0, 15, 19, 14, 0),
    gsSP2Triangles(20, 21, 22, 0, 23, 20, 24, 0),
    gsSP2Triangles(25, 23, 26, 0, 27, 25, 28, 0),
    gsSP2Triangles(29, 27, 30, 0, 21, 29, 31, 0),
    gsSPVertex(D_05000200_B0D90, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 8, 7, 0),
    gsSP2Triangles(12, 8, 11, 0, 9, 6, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 14, 0),
    gsSP2Triangles(18, 15, 17, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 20, 0, 24, 21, 20, 0),
    gsSP2Triangles(25, 21, 24, 0, 22, 19, 25, 0),
    gsSP2Triangles(26, 27, 28, 0, 27, 29, 30, 0),
    gsSPVertex(D_050003F0_B0F80, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 5, 7, 8, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 11, 13, 0),
    gsSP2Triangles(14, 13, 10, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 17, 19, 0, 18, 20, 21, 0),
    gsSP2Triangles(21, 22, 16, 0, 16, 22, 19, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 25, 27, 0),
    gsSP2Triangles(28, 27, 24, 0, 29, 30, 31, 0),
    gsSPVertex(D_050005F0_B1180, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 2, 0),
    gsSP2Triangles(7, 8, 9, 0, 9, 8, 10, 0),
    gsSP2Triangles(10, 8, 11, 0, 11, 8, 12, 0),
    gsSP2Triangles(12, 8, 13, 0, 13, 8, 7, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 16, 0),
    gsSP2Triangles(19, 16, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 23, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_050007F0_B1380, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 6, 0),
    gsSP2Triangles(10, 7, 6, 0, 11, 7, 10, 0),
    gsSP2Triangles(8, 5, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 13, 0, 17, 14, 16, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 19, 0),
    gsSP2Triangles(23, 20, 19, 0, 24, 20, 23, 0),
    gsSP2Triangles(21, 18, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 26, 0, 30, 27, 29, 0),
    gsSPVertex(D_050009E0_B1570, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 1, 0),
    gsSP2Triangles(5, 2, 4, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 7, 0, 11, 8, 7, 0),
    gsSP2Triangles(12, 8, 11, 0, 9, 6, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 20, 13, 21, 0),
    gsSP2Triangles(14, 13, 22, 0, 17, 23, 24, 0),
    gsSP2Triangles(13, 20, 25, 0, 20, 19, 26, 0),
    gsSP2Triangles(17, 27, 28, 0, 16, 29, 27, 0),
    gsSPVertex(D_05000BC0_B1750, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(4, 2, 1, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 6, 13, 16, 0),
    gsSP2Triangles(5, 14, 13, 0, 17, 18, 19, 0),
    gsSP2Triangles(15, 20, 13, 0, 20, 21, 16, 0),
    gsSP2Triangles(20, 22, 19, 0, 15, 23, 22, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 26, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05000DC0_B1950, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
    gsSP2Triangles(0, 4, 5, 0, 6, 7, 8, 0),
    gsSP2Triangles(9, 10, 8, 0, 11, 8, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 15, 3, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 16, 20, 15, 0),
    gsSP2Triangles(21, 22, 2, 0, 23, 21, 1, 0),
    gsSP2Triangles(24, 23, 25, 0, 2, 1, 21, 0),
    gsSP2Triangles(1, 25, 23, 0, 25, 26, 24, 0),
    gsSP2Triangles(25, 3, 15, 0, 15, 26, 25, 0),
    gsSP2Triangles(14, 27, 13, 0, 28, 29, 30, 0),
    gsSPVertex(D_05000FB0_B1B40, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
    gsSP2Triangles(5, 3, 6, 0, 7, 0, 3, 0),
    gsSP2Triangles(3, 5, 7, 0, 8, 1, 0, 0),
    gsSP2Triangles(6, 3, 9, 0, 9, 4, 10, 0),
    gsSP2Triangles(11, 6, 12, 0, 2, 4, 0, 0),
    gsSP2Triangles(4, 9, 3, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 13, 17, 0, 18, 11, 19, 0),
    gsSP2Triangles(4, 2, 10, 0, 20, 18, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 27, 29, 0, 28, 30, 31, 0),
    gsSPVertex(D_050011B0_B1D40, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 6, 8, 0),
    gsSP2Triangles(9, 8, 5, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 12, 14, 0, 13, 15, 16, 0),
    gsSP2Triangles(16, 17, 11, 0, 11, 17, 14, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 20, 22, 0),
    gsSP2Triangles(23, 22, 19, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 26, 28, 0, 29, 28, 25, 0),
    gsSPVertex(D_05001390_B1F20, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(3, 5, 6, 0, 6, 7, 1, 0),
    gsSP2Triangles(1, 7, 4, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 9, 8, 0, 10, 9, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 15, 12, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 19, 16, 0),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_050014D0_B2060, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(2, 18, 0, 0, 5, 19, 3, 0),
    gsSP2Triangles(8, 20, 6, 0, 11, 21, 9, 0),
    gsSP2Triangles(14, 22, 12, 0, 17, 23, 15, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_050016B0_B2240, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
