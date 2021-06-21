#include <ultra64.h>

Gfx D_8004E860[] = {
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};
