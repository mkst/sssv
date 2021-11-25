#include <ultra64.h>

Vtx D_04003530_E0AF0[4] = {
#include "data/inc/D_04003530_E0AF0.inc.c"
};
Vtx D_04003570_E0B30[4] = {
#include "data/inc/D_04003570_E0B30.inc.c"
};
Vtx D_040035B0_E0B70[4] = {
#include "data/inc/D_040035B0_E0B70.inc.c"
};
Vtx D_040035F0_E0BB0[4] = {
#include "data/inc/D_040035F0_E0BB0.inc.c"
};

extern Gfx D_010034C0_3CD90[];

const Gfx D_04003630_E0BF0[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_04003530_E0AF0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04003570_E0B30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_040035B0_E0B70, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_040035F0_E0BB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
