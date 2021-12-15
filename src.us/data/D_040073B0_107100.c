#include <ultra64.h>

Vtx D_04007350_1070A0[3] = {
#include "data/inc/D_04007350_1070A0.inc.c"
};

Vtx D_04007380_1070D0[3] = {
    #include "data/inc/D_04007380_1070D0.inc.c"
};

extern Gfx D_010037B8_3D088[];

Gfx D_040073B0_107100[] = {
    gsSPDisplayList(D_010037B8_3D088),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007350_1070A0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

extern Gfx D_010037B8_3D088[];

Gfx D_040073D8_107128[] = {
    gsSPDisplayList(D_010037B8_3D088),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPVertex(D_04007380_1070D0, 3, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};
