#include <ultra64.h>

const Gfx D_8004EF10[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0, PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsSPEndDisplayList(),
};
