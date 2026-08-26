#include <ultra64.h>

Vtx D_040027C0_CA1F0[5] = {
#include "data/inc/D_040027C0_CA1F0.inc.c"
};
extern Gfx D_01003780_3D050[];

Gfx flying_dog_fire_left[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_040027C0_CA1F0, 5, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Vtx D_04002838_CA268[5] = {
#include "data/inc/D_04002838_CA268.inc.c"
};

Gfx flying_dog_fire_right[] = {
    gsSPDisplayList(D_01003780_3D050),
    gsSPVertex(D_04002838_CA268, 5, 0),
    gsSP2Triangles(0, 2, 4, 0, 1, 3, 4, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
