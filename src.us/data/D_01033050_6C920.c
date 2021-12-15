#include <ultra64.h>

Vtx D_01033010_6C8E0[4] = {
#include "data/inc/D_01033010_6C8E0.inc.c"
};

Gfx D_01033050_6C920[] = {
    gsSPVertex(D_01033010_6C8E0, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(1, 3, 2, 0),
    gsSPEndDisplayList(),
};
