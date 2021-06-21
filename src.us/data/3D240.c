#include <ultra64.h>

const Gfx D_8004ED70[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};
