#include <ultra64.h>
#include "common.h"


void func_802B3EC0_6C5570(Gfx **arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    D_803A05C0_7B1C70 = 1 - D_803A05C0_7B1C70;
    if (arg1 != 1) {
        if (0) {
            // debug stub?
        };
        if (arg1 == 0) {
            draw_rectangle(arg0, 0, 0, 320, 240, 0, 0, 0, 255);
            func_802B4148_6C57F8(arg0);
        }
        if (arg1 == 2) {
            draw_rectangle(arg0, 8, 8, gScreenWidth - 8, gScreenHeight - 8, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 255);
        }
    }
}

void func_802B3FAC_6C565C(void) {
    s16 i;
    for (i = 0 ; i < 360; i++) {
        D_803D5590[i] = (guRandom() % 0xFFFA) - 0x7FF8;
        D_803D5860[i] = (guRandom() % 0xFFFA) + 0x7FF8;
        D_803D5B30[i] = (guRandom() % 0x1B58) - 0xBB8;
        D_803D5E00[i] = (guRandom() % 0x64)   + 0x96;
    }
}

void func_802B4148_6C57F8(Gfx **arg0) {
    s16 i;
    s16 temp_s6;

    gDPSetPrimDepth((*arg0)++, 0, 0);
    gDPPipeSync((*arg0)++);
    gSPClearGeometryMode((*arg0)++, G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gDPSetCombineLERP((*arg0)++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
    gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
    gSPTexture((*arg0)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
    gDPSetBlendColor((*arg0)++, 0x00, 0x00, 0x00, 0x00);
    gDPSetDepthSource((*arg0)++, G_ZS_PRIM);
    gDPSetTexturePersp((*arg0)++, G_TP_NONE);
    gDPSetPrimColor((*arg0)++, 0, 0, 0xB4, 0xB4, 0xDC, 0xFF);

    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_K0_TO_PHYSICAL(D_0102A210));
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 511, 512);

    temp_s6 = D_803A05C8_7B1C78;

    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

    temp_s6 = temp_s6 - D_803E4D30;

    for (i = 0; i < 360; i++) {
        func_802B4794_6C5E44(arg0, D_803D5590[i] << 16, (D_803D5860[i] + temp_s6) << 16, D_803D5B30[i] << 0x11, 0x1F, 0x1F, D_803D5E00[i] << 8);
        if ((D_803E4D28 & 4) != 0) {
            func_802B4794_6C5E44(arg0, D_803D5590[i] << 16, (D_803D5860[i] + temp_s6) << 16, (D_803D5B30[i] - 0x2EE0) << 0x11, 0x1F, 0x1F, D_803D5E00[i] << 8);
            func_802B4794_6C5E44(arg0, D_803D5590[i] << 16, (D_803D5860[i] + temp_s6) << 16, (D_803D5B30[i] + 0x2EE0) << 0x11, 0x1F, 0x1F, D_803D5E00[i] << 8);
            func_802B4794_6C5E44(arg0, (D_803D5590[i] + 0x2710) << 16, (D_803D5860[i] + temp_s6) << 16, (D_803D5B30[i] + 6000) << 0x11, 0x1F, 0x1F, D_803D5E00[i] << 8);
        }
    }

    D_803A05C8_7B1C78 = temp_s6;
    if ((D_803F6680.unk0 == 0) && ((guRandom() % 100000) < 5)) {
        s32 temp_s0;
        s16 temp_s1;
        s16 temp_s2;

        temp_s1 = guRandom() % 360;
        temp_s0 = (guRandom() % 6000) + 2000;
        temp_s2 = guRandom() % 360;

        create_particle_effect(
            ((D_80152350.unk2D0[temp_s2] * temp_s0) / 0x80) + 0x900,
            ((D_80152350.unk384[temp_s2] * temp_s0) / 0x80) + 0xE00,
            (guRandom() % 2000) + 1000,
            86,
            D_80152350.unk2D0[temp_s1] * 4000,
            D_80152350.unk384[temp_s1] * 4000,
            D_80152350.unk2D0[(s16)(guRandom() % 360)] * 5000,
            100,
            GPACK_RGBA5551(200, 200, 248, 0),
            GPACK_RGBA5551(0, 0, 248, 0),
            0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C5570/func_802B4794_6C5E44.s")
