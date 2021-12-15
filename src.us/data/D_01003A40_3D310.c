#include <ultra64.h>

Gfx D_01003A40_3D310[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPEndDisplayList(),
};

Gfx D_01003A58_3D328[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0, PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, ENVIRONMENT, 0, TEXEL0, 0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)),
    gsSPEndDisplayList(),
};
