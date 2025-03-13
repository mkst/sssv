#include <ultra64.h>

/* actually only 6 */
Vtx D_01037690_70F60[7] = {
#include "data/inc/D_01037690_70F60.inc.c"
};

Gfx D_01037700_70FD0[] = {
    gsSPVertex(D_01037690_70F60, 6, 0),
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
