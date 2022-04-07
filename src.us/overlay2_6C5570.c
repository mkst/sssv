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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C5570/func_802B4794_6C5E44.s")
#if 0
// shitshow
void func_802B4794_6C5E44(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    // f32 sp0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f16_2;
    f32 temp_f18;
    f32 temp_f2;
    f32 temp_f6;
    // s16 temp_v1;
    s16 temp_f10_2;
    s16 temp_f4;
    s16 temp_f4_2;
    s16 temp_f6_2;
    s16 temp_f6_3;
    s16 temp_f8;
    s16 temp_t6;
    s16 temp_t7;
    s16 temp_t8;
    s16 temp_t8_2;

    f32 phi_f2;
    f32 phi_f2_2;

    s16 phi_t3;
    s16 phi_t2;

    s16 phi_t3_2;
    s16 phi_t2_2;
    s16 phi_t3_3;
    s16 phi_t0;
    s16 phi_a3;
    s16 phi_t0_2;

    temp_f12 = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;
    temp_f16 = arg3 / 65536.0;
    // sp0 = temp_f16;
    temp_f0 = (D_80204278->unk38A10[2][0] * temp_f12) +
              (D_80204278->unk38A10[2][1] * temp_f14) +
              (D_80204278->unk38A10[2][2] * temp_f16) +
              (D_80204278->unk38A10[2][3]);
    if (temp_f0 <= -3.0) {
        temp_f18 = -temp_f0;
        if ((((D_80204278->unk38A10[3][2] * temp_f0) + D_80204278->unk38A10[3][3]) / temp_f18) > 0.0) {
            // temp_v1 = gScreenWidth;
            sp7C = (D_80204278->unk38A10[0][0] * temp_f12) +
                   (D_80204278->unk38A10[0][1] * temp_f14) +
                   (D_80204278->unk38A10[0][2] * temp_f16) +
                   (D_80204278->unk38A10[0][3]);
            // sp7C = sp7C;
            sp78 = (D_80204278->unk38A10[1][0] * temp_f12) +
                   (D_80204278->unk38A10[1][1] * temp_f14) +
                   (D_80204278->unk38A10[1][2] * temp_f16) +
                   (D_80204278->unk38A10[1][3]);
            // sp78 = sp78;
            sp70 = (gScreenWidth  * 2) + ((D_80204278->unk38A10[3][0] * sp7C) / temp_f0);
            sp6C = (gScreenHeight * 2) + ((D_80204278->unk38A10[3][1] * sp78) / temp_f0);
            temp_f2 = ((s32) ((arg6 * 33) / D_803F2D50.unkE0) << 5) / temp_f18;
            // sp0 = temp_f2;
            phi_f2 = temp_f2;
            // clamps
            if (temp_f2 > 15.0f) {
                phi_f2 = 15.0f;
            }
            if (phi_f2 < 4.0f) {
                phi_f2 = 4.0f;
            }
            // ?
            if (phi_f2 > 0.0f) {
                temp_f0 = ((arg4 * phi_f2) * 0.0078125);
                temp_f12_2 = sp70 - temp_f0;
                temp_f14_2 = sp70 + temp_f0;
                if (temp_f12_2 < temp_f14_2) {
                    temp_f16_2 = sp6C + 2.0f;
                    temp_f0_3 = sp6C - (f32) ((arg5 * phi_f2) * 0.0078125);
                    if (temp_f0_3 < temp_f16_2) {
                        temp_f4 = (s32) ((f32) (arg5 << 0xC) / (temp_f14_2 - temp_f12_2));
                        temp_f6_2 = (s32) ((f32) (arg4 << 0xC) / (temp_f16_2 - temp_f0_3));
                        if ((temp_f12_2 < (f32) (gScreenWidth * 4)) && (temp_f0_3 < 960.0f) && (temp_f14_2 > 0.0f) && (temp_f16_2 > 0.0f)) {
                            phi_t2 = 0;
                            phi_t3 = 0;
                            phi_t2_2 = 0;
                            phi_t3_2 = 0;
                            phi_t3_3 = 0;
                            phi_t0 = 0;
                            if (temp_f14_2 > 0) {
                                phi_t2 = temp_f14_2;
                            }
                            if (temp_f16_2 > 0) {
                                phi_t3 = temp_f16_2;
                            }
                            if (temp_f12_2 > 0) {
                                phi_t2_2 = temp_f12_2;
                            }
                            if (temp_f0_3 > 0) {
                                phi_t3_2 = temp_f0_3;
                            }

                            if (temp_f8 < 0) {
                                if (temp_f4 < 0) {
                                    temp_t8 = (s32) ((s16) temp_f8 * (s16) temp_f4) >> 7;
                                    if (temp_t8 > 0) {
                                        phi_t0 = temp_t8;
                                    }
                                } else {
                                    temp_t7 = (s32) ((s16) temp_f8 * (s16) temp_f4) >> 7;
                                    if (temp_t7 < 0) {
                                        phi_t0 = temp_t7;
                                    }
                                }
                            }
                            if ((s32) (s16) temp_f4_2 < 0) {
                                if ((s32) (s16) temp_f6_2 < 0) {
                                    temp_t6 = (s32) ((s16) temp_f4_2 * (s16) temp_f6_2) >> 7;
                                    if (temp_t6 > 0) {
                                        phi_t3_3 = temp_t6;
                                    }
                                } else {
                                    temp_t8_2 = (s32) ((s16) temp_f4_2 * (s16) temp_f6_2) >> 7;
                                    if (temp_t8_2 < 0) {
                                        phi_t3_3 = temp_t8_2;
                                    }
                                }
                            }

                            gSPTextureRectangle(
                                /* pkt  */ (*arg0)++,
                                /* xl   */ phi_t2_2,
                                /* yl   */ phi_t3_2,
                                /* xh   */ phi_t2,
                                /* yh   */ phi_t3,
                                /* tile */ G_TEXRECT,
                                /* s    */ (((s32) ((s16) temp_f4 * ((s16) temp_f8 & 3)) >> 9) - phi_t0),
                                /* t    */ (((s32) -(s32) ((s16) temp_f6_2 * ((s16) temp_f4_2 & 3)) >> 7) - phi_t3_3),
                                /* dsdx */ temp_f4,
                                /* dtdy */ temp_f6_2
                                );
#if 0
                            temp_f6_3 = (s32) temp_f14_2;
                            temp_t0 = *arg0;
                            temp_f10_2 = (s32) temp_f16_2;
                            temp_f4_2 = (s32) temp_f0_3;
                            *arg0 = temp_t0 + 8;
                            phi_t3 = 0;
                            phi_t2 = 0;
                            phi_t3_2 = 0;
                            phi_t2_2 = 0;
                            phi_t3_3 = (s32) 0;
                            if ((s32) (s16) temp_f6_3 > 0) {
                                phi_t2 = (s16) temp_f6_3;
                            }
                            if ((s32) (s16) temp_f10_2 > 0) {
                                phi_t3 = (s16) temp_f10_2;
                            }
                            temp_f8 = (s32) temp_f12_2;
                            temp_t0->unk0 = (s32) ((phi_t3 & 0xFFF) | 0xE4000000 | ((phi_t2 & 0xFFF) << 0xC));
                            if ((s32) (s16) temp_f8 > 0) {
                                phi_t2_2 = (s16) temp_f8;
                            }
                            if ((s32) (s16) temp_f4_2 > 0) {
                                phi_t3_2 = (s16) temp_f4_2;
                            }
                            temp_t0->unk4 = (s32) ((phi_t3_2 & 0xFFF) | ((phi_t2_2 & 0xFFF) << 0xC));
                            temp_a2 = *arg0;
                            *arg0 = temp_a2 + 8;
                            temp_a2->unk0 = 0xB4000000;
                            phi_t0 = 0;
                            phi_t0_2 = 0;
                            if ((s32) (s16) temp_f8 < 0) {
                                if ((s32) (s16) temp_f4 < 0) {
                                    temp_t8 = (s32) ((s16) temp_f8 * (s16) temp_f4) >> 7;
                                    if (temp_t8 > 0) {
                                        phi_t0 = temp_t8;
                                    }
                                } else {
                                    temp_t7 = (s32) ((s16) temp_f8 * (s16) temp_f4) >> 7;
                                    if (temp_t7 < 0) {
                                        phi_t0_2 = temp_t7;
                                    }
                                    phi_t0 = phi_t0_2;
                                }
                            }
                            if ((s32) (s16) temp_f4_2 < 0) {
                                if ((s32) (s16) temp_f6_2 < 0) {
                                    temp_t6 = (s32) ((s16) temp_f4_2 * (s16) temp_f6_2) >> 7;
                                    if (temp_t6 > 0) {
                                        phi_t3_3 = temp_t6;
                                    }
                                } else {
                                    temp_t8_2 = (s32) ((s16) temp_f4_2 * (s16) temp_f6_2) >> 7;
                                    phi_a3 = 0;
                                    if (temp_t8_2 < 0) {
                                        phi_a3 = temp_t8_2;
                                    }
                                    phi_t3_3 = phi_a3;
                                }
                            }
                            temp_a2->unk4 = (s32) (((((s32) -(s32) ((s16) temp_f6_2 * ((s16) temp_f4_2 & 3)) >> 7) - phi_t3_3) & 0xFFFF) | ((((s32) ((s16) temp_f4 * ((s16) temp_f8 & 3)) >> 9) - phi_t0) << 0x10));
                            temp_t1 = *arg0;

                            *arg0 = temp_t1 + 8;
                            temp_t1->unk4 = (s32) (((s16) temp_f4 << 0x10) | ((s16) temp_f6_2 & 0xFFFF));
                            temp_t1->unk0 = 0xB3000000;
#endif
                        }
                    }
                }
            }
        }
    }
}
#endif
