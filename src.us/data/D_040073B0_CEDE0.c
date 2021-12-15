#include <ultra64.h>

Vtx D_04007350_CED80[3] = {
#include "data/inc/D_04007350_CED80.inc.c"
};

Vtx D_04007380_CEDB0[3] = {
#include "data/inc/D_04007380_CEDB0.inc.c"
};

extern Gfx D_010037B8_3D088[];

Gfx D_040073B0_CEDE0[] = {
    gsSPDisplayList(D_010037B8_3D088),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007350_CED80, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

Gfx D_040073D8_CEE08[] = {
    gsSPDisplayList(D_010037B8_3D088),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007380_CEDB0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
