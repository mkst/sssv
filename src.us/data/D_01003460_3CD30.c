#include <ultra64.h>

Gfx D_01003460_3CD30[] = {
    gsDPPipeSync(),
    gsSPTexture(32768, 32768, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};

Gfx D_01003498_3CD68[] = {
    gsSPDisplayList(D_01003460_3CD30),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPEndDisplayList(),
};

Gfx D_010034B0_3CD80[] = {
    gsSPDisplayList(D_01003460_3CD30),
    gsSPEndDisplayList(),
};
