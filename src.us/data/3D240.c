#include <ultra64.h>

const Gfx D_01003970_3D240[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

const Gfx D_01003998_3D268[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetDepthSource(G_ZS_PRIM),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x14),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsDPSetCombineLERP(PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsSPEndDisplayList(),
};

const Gfx D_010039F8_3D2C8[] = {
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_NOOP2),
    gsSPClearGeometryMode(-1),
    gsSPSetGeometryMode(G_ZBUFFER),
    gsDPSetCombineLERP(PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0),
    gsSPEndDisplayList(),
};

const Gfx D_01003A28_3D2F8[] = {
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, 0, 0, 0, TEXEL0, PRIMITIVE, ENVIRONMENT, PRIM_LOD_FRAC, ENVIRONMENT, 0, 0, 0, TEXEL0),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};
