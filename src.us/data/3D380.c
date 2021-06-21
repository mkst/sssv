#include <ultra64.h>

const Gfx D_8004EEB0[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};
