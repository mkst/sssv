#include <ultra64.h>

Gfx D_01004A70_3E340[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetCombineMode(G_CC_BLENDPE, G_CC_BLENDPEDECALA),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsDPLoadTextureBlock_4b(0x01044CB0, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};

Gfx D_01004AF8_3E3C8[] = {
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_CULL_BACK | G_TEXTURE_GEN),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

Gfx D_01004B28_3E3F8[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_PASS2),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x01021CB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx D_01004B98_3E468[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x01),
    gsSPEndDisplayList(),
};

Gfx D_01004C08_3E4D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_NONE),
};
