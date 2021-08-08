#include <ultra64.h>


Vtx D_05005A50_BA320[8] = {
#include "data/inc/D_05005A50_BA320.inc.c"
};
Vtx D_05005AD0_BA3A0[31] = {
#include "data/inc/D_05005AD0_BA3A0.inc.c"
};
Vtx D_05005CC0_BA590[32] = {
#include "data/inc/D_05005CC0_BA590.inc.c"
};
Vtx D_05005EC0_BA790[30] = {
#include "data/inc/D_05005EC0_BA790.inc.c"
};
Vtx D_050060A0_BA970[30] = {
#include "data/inc/D_050060A0_BA970.inc.c"
};
Vtx D_05006280_BAB50[31] = {
#include "data/inc/D_05006280_BAB50.inc.c"
};
Vtx D_05006470_BAD40[31] = {
#include "data/inc/D_05006470_BAD40.inc.c"
};
Vtx D_05006660_BAF30[31] = {
#include "data/inc/D_05006660_BAF30.inc.c"
};
Vtx D_05006850_BB120[30] = {
#include "data/inc/D_05006850_BB120.inc.c"
};
Vtx D_05006A30_BB300[27] = {
#include "data/inc/D_05006A30_BB300.inc.c"
};


const Gfx D_05006BE0_BB4B0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05005A50_BA320, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05005AD0_BA3A0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(2, 5, 4, 0, 2, 6, 5, 0),
    gsSP2Triangles(6, 2, 7, 0, 7, 8, 6, 0),
    gsSP2Triangles(9, 10, 11, 0, 9, 12, 13, 0),
    gsSP2Triangles(8, 14, 5, 0, 10, 13, 15, 0),
    gsSP2Triangles(5, 6, 8, 0, 14, 15, 4, 0),
    gsSP2Triangles(14, 8, 11, 0, 9, 11, 16, 0),
    gsSP2Triangles(11, 10, 14, 0, 9, 13, 10, 0),
    gsSP2Triangles(4, 5, 14, 0, 9, 16, 17, 0),
    gsSP2Triangles(15, 14, 10, 0, 9, 17, 12, 0),
    gsSP2Triangles(7, 2, 1, 0, 8, 7, 16, 0),
    gsSP2Triangles(3, 4, 15, 0, 16, 11, 8, 0),
    gsSP2Triangles(12, 17, 18, 0, 19, 15, 20, 0),
    gsSP2Triangles(15, 19, 21, 0, 22, 18, 23, 0),
    gsSP2Triangles(17, 24, 7, 0, 25, 26, 12, 0),
    gsSP2Triangles(27, 21, 26, 0, 7, 18, 17, 0),
    gsSP2Triangles(20, 12, 19, 0, 7, 23, 18, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05005CC0_BA590, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(3, 4, 5, 0, 6, 7, 4, 0),
    gsSP2Triangles(0, 8, 7, 0, 2, 9, 8, 0),
    gsSP2Triangles(1, 5, 9, 0, 5, 1, 3, 0),
    gsSP2Triangles(4, 3, 6, 0, 7, 6, 0, 0),
    gsSP2Triangles(8, 0, 2, 0, 9, 2, 1, 0),
    gsSP2Triangles(10, 5, 4, 0, 10, 9, 5, 0),
    gsSP2Triangles(10, 8, 9, 0, 10, 7, 8, 0),
    gsSP2Triangles(10, 4, 7, 0, 11, 12, 13, 0),
    gsSP2Triangles(14, 15, 11, 0, 15, 16, 12, 0),
    gsSP2Triangles(16, 14, 13, 0, 11, 13, 14, 0),
    gsSP2Triangles(12, 11, 15, 0, 13, 12, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 17, 0),
    gsSP2Triangles(21, 22, 18, 0, 22, 20, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 18, 17, 21, 0),
    gsSP2Triangles(19, 18, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 23, 0, 27, 28, 24, 0),
    gsSP2Triangles(28, 26, 25, 0, 23, 25, 26, 0),
    gsSP2Triangles(24, 23, 27, 0, 25, 24, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05005EC0_BA790, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
    gsSP2Triangles(4, 5, 0, 0, 6, 1, 5, 0),
    gsSP2Triangles(7, 2, 1, 0, 8, 3, 2, 0),
    gsSP2Triangles(9, 0, 3, 0, 8, 10, 11, 0),
    gsSP2Triangles(11, 9, 8, 0, 10, 12, 11, 0),
    gsSP2Triangles(9, 11, 13, 0, 13, 4, 9, 0),
    gsSP2Triangles(11, 12, 13, 0, 4, 13, 14, 0),
    gsSP2Triangles(14, 6, 4, 0, 13, 12, 14, 0),
    gsSP2Triangles(6, 14, 15, 0, 15, 7, 6, 0),
    gsSP2Triangles(14, 12, 15, 0, 7, 15, 10, 0),
    gsSP2Triangles(10, 8, 7, 0, 15, 12, 10, 0),
    gsSP2Triangles(0, 9, 4, 0, 5, 4, 6, 0),
    gsSP2Triangles(1, 6, 7, 0, 2, 7, 8, 0),
    gsSP2Triangles(3, 8, 9, 0, 16, 17, 18, 0),
    gsSP2Triangles(19, 20, 21, 0, 16, 21, 20, 0),
    gsSP2Triangles(19, 22, 23, 0, 16, 23, 22, 0),
    gsSP2Triangles(19, 18, 17, 0, 18, 23, 16, 0),
    gsSP2Triangles(21, 22, 19, 0, 20, 17, 16, 0),
    gsSP2Triangles(23, 18, 19, 0, 22, 21, 16, 0),
    gsSP2Triangles(17, 20, 19, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 26, 25, 0, 28, 24, 26, 0),
    gsSP2Triangles(29, 25, 24, 0, 25, 29, 27, 0),
    gsSP2Triangles(26, 27, 28, 0, 24, 28, 29, 0),
    gsSPVertex(D_050060A0_BA970, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(4, 3, 2, 0, 6, 7, 5, 0),
    gsSP2Triangles(7, 6, 2, 0, 1, 0, 5, 0),
    gsSP2Triangles(2, 6, 0, 0, 5, 7, 3, 0),
    gsSP2Triangles(2, 1, 4, 0, 5, 0, 6, 0),
    gsSP2Triangles(2, 3, 7, 0, 5, 4, 1, 0),
    gsSP2Triangles(8, 9, 10, 0, 9, 10, 11, 0),
    gsSP2Triangles(10, 8, 12, 0, 8, 9, 13, 0),
    gsSP2Triangles(11, 13, 9, 0, 12, 11, 10, 0),
    gsSP2Triangles(13, 12, 8, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 17, 20, 18, 0),
    gsSP2Triangles(15, 14, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(22, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05006280_BAB50, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 10, 13, 0, 6, 8, 14, 0),
    gsSP2Triangles(10, 12, 15, 0, 2, 16, 0, 0),
    gsSP2Triangles(5, 11, 3, 0, 10, 9, 13, 0),
    gsSP2Triangles(17, 15, 12, 0, 14, 5, 18, 0),
    gsSP2Triangles(8, 0, 16, 0, 8, 7, 0, 0),
    gsSP2Triangles(14, 16, 19, 0, 20, 3, 11, 0),
    gsSP2Triangles(21, 19, 22, 0, 16, 14, 8, 0),
    gsSP2Triangles(3, 23, 4, 0, 19, 21, 14, 0),
    gsSP2Triangles(19, 16, 2, 0, 24, 21, 22, 0),
    gsSP2Triangles(11, 15, 20, 0, 0, 7, 1, 0),
    gsSP2Triangles(25, 23, 20, 0, 20, 23, 3, 0),
    gsSP2Triangles(11, 5, 9, 0, 25, 20, 15, 0),
    gsSP2Triangles(5, 14, 21, 0, 26, 27, 28, 0),
    gsSP2Triangles(27, 29, 28, 0, 29, 30, 28, 0),
    gsSP1Triangle(30, 26, 28, 0),
    gsSPVertex(D_05006470_BAD40, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 4, 2, 0, 4, 0, 2, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 5, 0),
    gsSP2Triangles(9, 6, 5, 0, 10, 11, 6, 0),
    gsSP2Triangles(11, 12, 7, 0, 12, 13, 5, 0),
    gsSP2Triangles(13, 14, 8, 0, 14, 10, 9, 0),
    gsSP2Triangles(6, 9, 10, 0, 7, 6, 11, 0),
    gsSP2Triangles(5, 7, 12, 0, 8, 5, 13, 0),
    gsSP2Triangles(9, 8, 14, 0, 11, 10, 15, 0),
    gsSP2Triangles(10, 14, 15, 0, 14, 13, 15, 0),
    gsSP2Triangles(13, 12, 15, 0, 12, 11, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 16, 0),
    gsSP2Triangles(21, 19, 18, 0, 20, 21, 17, 0),
    gsSP2Triangles(16, 18, 19, 0, 18, 17, 21, 0),
    gsSP2Triangles(17, 16, 20, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 22, 0, 27, 25, 24, 0),
    gsSP2Triangles(26, 27, 23, 0, 22, 24, 25, 0),
    gsSP2Triangles(24, 23, 27, 0, 23, 22, 26, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05006660_BAF30, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 4, 0),
    gsSP2Triangles(3, 0, 5, 0, 2, 5, 0, 0),
    gsSP2Triangles(4, 2, 1, 0, 5, 4, 3, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 6, 8, 0),
    gsSP2Triangles(9, 8, 10, 0, 8, 7, 11, 0),
    gsSP2Triangles(7, 6, 12, 0, 6, 9, 13, 0),
    gsSP2Triangles(9, 10, 14, 0, 10, 8, 15, 0),
    gsSP2Triangles(16, 17, 14, 0, 14, 15, 16, 0),
    gsSP2Triangles(16, 18, 17, 0, 19, 16, 15, 0),
    gsSP2Triangles(15, 11, 19, 0, 19, 18, 16, 0),
    gsSP2Triangles(20, 19, 11, 0, 11, 12, 20, 0),
    gsSP2Triangles(20, 18, 19, 0, 21, 20, 12, 0),
    gsSP2Triangles(12, 13, 21, 0, 21, 18, 20, 0),
    gsSP2Triangles(17, 21, 13, 0, 13, 14, 17, 0),
    gsSP2Triangles(17, 18, 21, 0, 11, 15, 8, 0),
    gsSP2Triangles(12, 11, 7, 0, 13, 12, 6, 0),
    gsSP2Triangles(14, 13, 9, 0, 15, 14, 10, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05006850_BB120, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSPVertex(D_05006A30_BB300, 27, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP1Triangle(24, 25, 26, 0),
    gsSPEndDisplayList(),
};
