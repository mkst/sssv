#include <ultra64.h>

// only 6 values, alignment or?
Vtx D_0103B680_74F50[7] = {
#include "data/inc/D_0103B680_74F50.inc.c"
};

const Gfx D_0103B6F0_74FC0[] = {
    gsSPVertex(D_0103B680_74F50, 6, 0),
    gsSP1Triangle(0, 2, 4, 0),
    gsSP1Triangle(0, 4, 3, 0),
    gsSP1Triangle(0, 3, 5, 0),
    gsSP1Triangle(0, 5, 2, 0),
    gsSP1Triangle(1, 4, 2, 0),
    gsSP1Triangle(1, 3, 4, 0),
    gsSP1Triangle(1, 5, 3, 0),
    gsSP1Triangle(1, 2, 5, 0),
    gsSPEndDisplayList(),
};
