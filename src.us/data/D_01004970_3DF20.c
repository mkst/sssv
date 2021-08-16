#include <ultra64.h>

const Gfx D_01004970_3DF20[] = {
    gsDPPipeSync(),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x80),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_PASS, AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_NOOP2),
    gsSPEndDisplayList(),
};
