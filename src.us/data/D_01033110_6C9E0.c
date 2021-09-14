#include <ultra64.h>

Vtx D_010330D0_6C9A0[4] = {
#include "data/inc/D_010330D0_6C9A0.inc.c"
};

const Gfx D_01033110_6C9E0[] = {
    gsSPVertex(D_010330D0_6C9A0, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(1, 3, 2, 0),
    gsSPEndDisplayList(),
};
