#include <ultra64.h>

Vtx D_01033130_6CA00[4] = {
#include "data/inc/D_01033130_6CA00.inc.c"
};

Gfx D_01033170_6CA40[] = {
    gsSPVertex(D_01033130_6CA00, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(1, 3, 2, 0),
    gsSPEndDisplayList(),
};
