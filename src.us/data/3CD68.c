#include <ultra64.h>

extern Gfx D_01003460[];

const Gfx D_8004E898[] = {
    gsSPDisplayList(D_01003460),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPEndDisplayList(),
};
