#include <ultra64.h>

Gfx D_010048A0_3E170[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_010048F8_3E1C8[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_PASS2),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x01021CB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
