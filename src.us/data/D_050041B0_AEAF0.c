#include <ultra64.h>

Vtx D_05002280_ACBC0[8] = {
#include "data/inc/D_05002280_ACBC0.inc.c"
};
Vtx D_05002300_ACC40[32] = {
#include "data/inc/D_05002300_ACC40.inc.c"
};
Vtx D_05002500_ACE40[30] = {
#include "data/inc/D_05002500_ACE40.inc.c"
};
Vtx D_050026E0_AD020[31] = {
#include "data/inc/D_050026E0_AD020.inc.c"
};
Vtx D_050028D0_AD210[32] = {
#include "data/inc/D_050028D0_AD210.inc.c"
};
Vtx D_05002AD0_AD410[32] = {
#include "data/inc/D_05002AD0_AD410.inc.c"
};
Vtx D_05002CD0_AD610[30] = {
#include "data/inc/D_05002CD0_AD610.inc.c"
};
Vtx D_05002EB0_AD7F0[31] = {
#include "data/inc/D_05002EB0_AD7F0.inc.c"
};
Vtx D_050030A0_AD9E0[31] = {
#include "data/inc/D_050030A0_AD9E0.inc.c"
};
Vtx D_05003290_ADBD0[31] = {
#include "data/inc/D_05003290_ADBD0.inc.c"
};
Vtx D_05003480_ADDC0[30] = {
#include "data/inc/D_05003480_ADDC0.inc.c"
};
Vtx D_05003660_ADFA0[31] = {
#include "data/inc/D_05003660_ADFA0.inc.c"
};
Vtx D_05003850_AE190[30] = {
#include "data/inc/D_05003850_AE190.inc.c"
};
Vtx D_05003A30_AE370[30] = {
#include "data/inc/D_05003A30_AE370.inc.c"
};
Vtx D_05003C10_AE550[30] = {
#include "data/inc/D_05003C10_AE550.inc.c"
};
Vtx D_05003DF0_AE730[31] = {
#include "data/inc/D_05003DF0_AE730.inc.c"
};
Vtx D_05003FE0_AE920[29] = {
#include "data/inc/D_05003FE0_AE920.inc.c"
};

Gfx D_050041B0_AEAF0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_05002280_ACBC0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_05002300_ACC40, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
    gsSP2Triangles(3, 0, 2, 0, 4, 5, 6, 0),
    gsSP2Triangles(7, 8, 9, 0, 10, 11, 12, 0),
    gsSP2Triangles(13, 14, 15, 0, 8, 16, 9, 0),
    gsSP2Triangles(8, 7, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 26, 0),
    gsSP2Triangles(27, 28, 29, 0, 30, 18, 31, 0),
    gsSPVertex(D_05002500_ACE40, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 3, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(18, 17, 16, 0, 23, 10, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 24, 11, 0),
    gsSP1Triangle(29, 21, 9, 0),
    gsSPVertex(D_050026E0_AD020, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(1, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 0, 14, 6, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 14, 0),
    gsSP2Triangles(20, 21, 22, 0, 16, 23, 11, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 18, 0),
    gsSP1Triangle(29, 3, 30, 0),
    gsSPVertex(D_050028D0_AD210, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 3, 0, 8, 9, 7, 0),
    gsSP2Triangles(9, 10, 11, 0, 12, 13, 14, 0),
    gsSP2Triangles(15, 16, 17, 0, 18, 19, 20, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 23, 25, 0),
    gsSP2Triangles(26, 25, 27, 0, 28, 27, 29, 0),
    gsSP1Triangle(30, 29, 31, 0),
    gsSPVertex(D_05002AD0_AD410, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 3, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 4, 3, 20, 0),
    gsSP2Triangles(21, 22, 12, 0, 23, 9, 24, 0),
    gsSP2Triangles(9, 23, 25, 0, 26, 27, 28, 0),
    gsSP1Triangle(29, 30, 31, 0),
    gsSPVertex(D_05002CD0_AD610, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 9, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 17, 24, 0, 25, 4, 26, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_05002EB0_AD7F0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 2, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 0, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 10, 26, 0),
    gsSP2Triangles(27, 28, 9, 0, 29, 24, 30, 0),
    gsSPVertex(D_050030A0_AD9E0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(5, 12, 3, 0, 13, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(14, 13, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(26, 27, 9, 0, 28, 29, 30, 0),
    gsSPVertex(D_05003290_ADBD0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP1Triangle(28, 29, 30, 0),
    gsSPVertex(D_05003480_ADDC0, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(0, 6, 7, 0, 8, 6, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 8, 13, 7, 0),
    gsSP2Triangles(8, 14, 13, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 20, 0),
    gsSP2Triangles(23, 24, 25, 0, 20, 26, 21, 0),
    gsSP1Triangle(27, 28, 29, 0),
    gsSPVertex(D_05003660_ADFA0, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 5, 9, 3, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 13, 10, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(20, 21, 6, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 7, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(15, 30, 7, 0),
    gsSPVertex(D_05003850_AE190, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(0, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 5, 20, 3, 0),
    gsSP2Triangles(16, 21, 22, 0, 23, 24, 20, 0),
    gsSP2Triangles(25, 26, 19, 0, 27, 28, 19, 0),
    gsSP1Triangle(16, 29, 14, 0),
    gsSPVertex(D_05003A30_AE370, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 19, 17, 0, 20, 15, 17, 0),
    gsSP2Triangles(21, 22, 17, 0, 23, 24, 25, 0),
    gsSP2Triangles(5, 26, 27, 0, 19, 28, 29, 0),
    gsSP1Triangle(28, 19, 18, 0),
    gsSPVertex(D_05003C10_AE550, 30, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(0, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 0, 18, 0, 18, 0, 2, 0),
    gsSP2Triangles(19, 20, 21, 0, 22, 23, 24, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 25, 27, 0),
    gsSP1Triangle(28, 27, 29, 0),
    gsSPVertex(D_05003DF0_AE730, 31, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
    gsSP2Triangles(5, 6, 7, 0, 8, 9, 10, 0),
    gsSP2Triangles(11, 12, 13, 0, 14, 15, 16, 0),
    gsSP2Triangles(17, 18, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 0, 24, 0, 25, 16, 26, 0),
    gsSP2Triangles(21, 27, 28, 0, 29, 28, 30, 0),
    gsSP1Triangle(28, 27, 8, 0),
    gsSPVertex(D_05003FE0_AE920, 29, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(18, 3, 19, 0, 20, 21, 22, 0),
    gsSP2Triangles(23, 24, 25, 0, 26, 27, 28, 0),
    gsSPEndDisplayList(),
};
