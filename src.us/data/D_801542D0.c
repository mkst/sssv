#include <ultra64.h>

extern u8 img_D_801532D0_rgba16__png[];

Gfx D_801542D0[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_CULL_BACK | G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsSPTexture(1984, 1984, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(img_D_801532D0_rgba16__png, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};
