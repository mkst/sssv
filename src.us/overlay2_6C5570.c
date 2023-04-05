#include <ultra64.h>
#include "common.h"


void func_802B4794_6C5E44(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6);

s16 D_803A05C0_7B1C70 = 0;
s32 D_803A05C4_7B1C74 = 8;
s16 D_803A05C8_7B1C78 = 10000;

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
        D_803D5590[i] = RAND(65530) - 32760;
        D_803D5860[i] = RAND(65530) + 32760;
        D_803D5B30[i] = RAND(7000)  - 3000;
        D_803D5E00[i] = RAND(100)   + 150;
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

    // randomly generate a meteor
    if ((D_803F6680.unk0 == 0) && (RAND(100000) < 5)) {
        s32 temp_s0;
        s16 temp_s1;
        s16 temp_s2;

        temp_s1 = RAND(360);
        temp_s0 = RAND(6000) + 2000;
        temp_s2 = RAND(360);

        create_particle_effect(
            ((D_80152350.unk2D0[temp_s2] * temp_s0) / 0x80) + 0x900,
            ((D_80152350.unk384[temp_s2] * temp_s0) / 0x80) + 0xE00,
            RAND(2000) + 1000,
            86,
            D_80152350.unk2D0[temp_s1] * 4000,
            D_80152350.unk384[temp_s1] * 4000,
            D_80152350.unk2D0[(s16)RAND(360)] * 5000,
            100,
            GPACK_RGBA5551(200, 200, 248, 0),
            GPACK_RGBA5551(0, 0, 248, 0),
            0);
    }
}

#ifdef NON_MATCHING
void func_802B4794_6C5E44(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 xl;
    f32 yl;
    f32 xh;
    f32 yh;
    f32 temp_f16;
    f32 phi_f2;
    s32 new_var;
    s16 new_var2;
    s16 dsdx;
    s16 dtdy;

    temp_f12 = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;
    temp_f16 = arg3 / 65536.0;

    temp_f0 = (D_80204278->unk38A10[2][0] * temp_f12) + (D_80204278->unk38A10[2][1] * temp_f14) + (D_80204278->unk38A10[2][2] * temp_f16) + (D_80204278->unk38A10[2][3]);
    if (temp_f0 <= -3.0) {
        xl = ((D_80204278->unk38A10[3][2] * temp_f0) + D_80204278->unk38A10[3][3]) / (-temp_f0);
        if (xl > 0.0) {

            sp7C = (D_80204278->unk38A10[0][3]) + ((D_80204278->unk38A10[0][0] * temp_f12) +(D_80204278->unk38A10[0][1] * temp_f14) + (D_80204278->unk38A10[0][2] * temp_f16));
            sp78 = (D_80204278->unk38A10[1][3]) + ((D_80204278->unk38A10[1][0] * temp_f12) +(D_80204278->unk38A10[1][1] * temp_f14) + (D_80204278->unk38A10[1][2] * temp_f16));

            sp70 = (gScreenWidth  * 2) + ((D_80204278->unk38A10[3][0] * sp7C) / temp_f0);
            sp6C = ((new_var2 = gScreenHeight) * 2) + ((D_80204278->unk38A10[3][1] * sp78) / temp_f0);

            new_var = (arg6 * 33) / D_803F2D50.unkE0;
            phi_f2 = ((new_var) << 5) / -temp_f0;

            if (phi_f2 > 15.0f) {
                phi_f2 = 15.0f;
            }
            if (phi_f2 < 4.0f) {
                phi_f2 = 4.0f;
            }

            if (phi_f2 > 0.0f) {
                temp_f0 = ((arg4 * phi_f2) / 128.0);
                xl = sp70 - temp_f0;
                xh = sp70 + temp_f0;
                yl = sp6C - (f32) ((arg5 * phi_f2) / 128.0);
                yh = sp6C + 2.0f;

                if ((xl < xh) && (yl < yh)) {

                    dsdx = (arg5 << 0xC) / (xh - xl);
                    dtdy = (arg4 << 0xC) / (yh - yl);

                    if ((xl < (gScreenWidth * 4)) && (yl < 960.0f) && (xh > 0.0f) && (yh > 0.0f)) {
                        gSPScisTextureRectangle(
                            /* pkt  */ (*arg0)++,
                            /* xl   */ (s16)xl,
                            /* yl   */ (s16)yl,
                            /* xh   */ (s16)xh,
                            /* yh   */ (s16)yh,
                            /* tile */ G_TX_RENDERTILE,
                            /* s    */  (dsdx * ((s16) xl & 3)) >> 9,
                            /* t    */ -(dtdy * ((s16) yl & 3)) >> 7,
                            /* dsdx */ dsdx,
                            /* dtdy */ dtdy);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C5570/func_802B4794_6C5E44.s")
#endif
