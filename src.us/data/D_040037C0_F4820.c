#include <ultra64.h>

Vtx D_040036C0_F4720[4] = {
#include "data/inc/D_040036C0_F4720.inc.c"
};
Vtx D_04003700_F4760[4] = {
#include "data/inc/D_04003700_F4760.inc.c"
};
Vtx D_04003740_F47A0[4] = {
#include "data/inc/D_04003740_F47A0.inc.c"
};
Vtx D_04003780_F47E0[4] = {
#include "data/inc/D_04003780_F47E0.inc.c"
};

extern Gfx D_010034C0_3CD90[];

Gfx D_040037C0_F4820[] = {
    gsSPDisplayList(D_010034C0_3CD90),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_040036C0_F4720, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04003700_F4760, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, 1, G_ON),
    gsSPVertex(D_04003740_F47A0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_04003780_F47E0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
