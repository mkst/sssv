#include <ultra64.h>

Vtx D_0100B040_44910[32] = {
#include "data/inc/D_0100B040_44910.inc.c"
};
Vtx D_0100B240_44B10[4] = {
#include "data/inc/D_0100B240_44B10.inc.c"
};
Vtx D_0100B280_44B50[4] = {
#include "data/inc/D_0100B280_44B50.inc.c"
};

Gfx D_0100B2C0_44B90[] = {
    gsSPVertex(D_0100B040_44910, 32, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSP1Quadrangle(4, 5, 6, 7, 0),
    gsSP1Quadrangle(8, 9, 10, 11, 0),
    gsSP1Quadrangle(12, 13, 14, 15, 0),
    gsSP1Quadrangle(16, 17, 18, 19, 0),
    gsSP1Quadrangle(20, 21, 22, 23, 0),
    gsSP1Quadrangle(24, 25, 26, 27, 0),
    gsSP1Quadrangle(28, 29, 30, 31, 0),
    gsSPVertex(D_0100B240_44B10, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPVertex(D_0100B280_44B50, 4, 0),
    gsSP1Quadrangle(0, 1, 2, 3, 0),
    gsSPEndDisplayList(),
};
