#include <ultra64.h>

Vtx D_0400ECD0_10EA20[8] = {
#include "data/inc/D_0400ECD0_10EA20.inc.c"
};
Vtx D_0400ED50_10EAA0[30] = {
#include "data/inc/D_0400ED50_10EAA0.inc.c"
};
Vtx D_0400EF30_10EC80[31] = {
#include "data/inc/D_0400EF30_10EC80.inc.c"
};
Vtx D_0400F120_10EE70[32] = {
#include "data/inc/D_0400F120_10EE70.inc.c"
};
Vtx D_0400F320_10F070[6] = {
#include "data/inc/D_0400F320_10F070.inc.c"
};
Vtx D_0400F380_10F0D0[32] = {
#include "data/inc/D_0400F380_10F0D0.inc.c"
};
Vtx D_0400F580_10F2D0[32] = {
#include "data/inc/D_0400F580_10F2D0.inc.c"
};
Vtx D_0400F780_10F4D0[28] = {
#include "data/inc/D_0400F780_10F4D0.inc.c"
};
Vtx D_0400F940_10F690[32] = {
#include "data/inc/D_0400F940_10F690.inc.c"
};
Vtx D_0400FB40_10F890[18] = {
#include "data/inc/D_0400FB40_10F890.inc.c"
};

Gfx D_0400FC60_10F9B0[] = {
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_0400ECD0_10EA20, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 8),
    gsSPVertex(D_0400ED50_10EAA0, 30, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(10, 11, 12, 13, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(18, 19, 20, 21, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(26, 27, 28, 29, 0),
    gsSPVertex(D_0400EF30_10EC80, 31, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 2, 25, 26, 0),
    gsSP1Quadrangle(27, 28, 29, 30, 0),
    gsSPVertex(D_0400F120_10EE70, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(21, 24, 25, 22, 0),
    gsSP1Quadrangle(24, 26, 27, 25, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400F320_10F070, 6, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSPVertex(D_0400F380_10F0D0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400F580_10F2D0, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400F780_10F4D0, 28, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(7, 10, 11, 8, 0),
    gsSP1Quadrangle(10, 12, 13, 11, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(15, 18, 19, 16, 0),
    gsSP1Quadrangle(18, 20, 21, 19, 0),
    gsSP1Quadrangle(22, 23, 24, 25, 0),
    gsSP1Quadrangle(23, 26, 27, 24, 0),
    gsSP1Quadrangle(26, 14, 17, 27, 0),
    gsSPVertex(D_0400F940_10F690, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 0, 3, 5, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(7, 10, 11, 8, 0),
    gsSP1Quadrangle(10, 12, 13, 11, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSP1Quadrangle(15, 18, 19, 16, 0),
    gsSP1Quadrangle(18, 6, 9, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(21, 24, 25, 22, 0),
    gsSP1Quadrangle(24, 26, 27, 25, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0400FB40_10F890, 18, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(1, 4, 5, 2, 0),
    gsSP1Quadrangle(6, 7, 8, 9, 0),
    gsSP1Quadrangle(7, 10, 11, 8, 0),
    gsSP1Quadrangle(10, 12, 13, 11, 0),
    gsSP1Quadrangle(14, 15, 16, 17, 0),
    gsSPEndDisplayList(),
};
