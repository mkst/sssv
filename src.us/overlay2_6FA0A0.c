#include <ultra64.h>
#include "common.h"


// is animal off screen?
s32 func_802E89F0_6FA0A0(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return 0;
        } else {
            return 4;
        }
    }
    if (D_803F28DC & 3) {
        if (D_803F28DC & 1) {
            if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28DC & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
                return 0;
            } else {
                return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
            }
        }
        if ((func_802E9B90_6FB240(((D_803F28DC & 0xFFC) << 0x12) -xPos, zPos, yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return 0;
        } else {
            return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        }
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
}

s32 func_802E8BBC_6FA26C(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return 0;
        } else {
            return 4;
        }
    }
    if (D_803F28DC & 1) {
        if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28DC & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return 0;
        }
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
}

#if 0
extern Gfx D_01003A28[];
extern Gfx D_01003A40_3D310[];
extern u8  D_01003BD0[];
// 16780
s32 func_802E8CF4_6FA3A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s16 red, s16 green, s16 blue, s8 arg8, u8 arg9) {
    f32 sp144;
    f32 sp140;
    f32 sp12C;
    f32 sp128;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    s64 spE0;
    s64 spD8;
    s64 spD0;

    s32 xh;   // sp38
    f32 yh;  // sp34

    f32 sp2C;

    f32 xl;   // sp28
    f32 yl;   // sp24

    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    // f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f2;
    f64 temp_f0_3;
    s16 temp_a1_3;
    s16 temp_v1_2;
    s16 temp_f10_2;
    s16 dsdx_dtdy;
    u8  var_a0;
    s64 temp_v1;

    if (func_8029A334_6AB9E4(arg0 >> 0x10, arg1 >> 0x10, arg2 >> 0x10) == 0) {
        return 4;
    }

    spE0 = (arg0 >> 0x10) - (s16) D_803F2C44;
    spD8 = (arg1 >> 0x10) - (s16) D_803F2C48;
    spD0 = (arg2 >> 0x10) - (s16) D_803F2C4C;

    temp_v1 = (((SQ(spD0) + SQ(spD8) + SQ(spE0)) >> arg8) * D_803F2E30) / 75.0f;

    if (temp_v1 > 0x4C9000) {
        return 4;
    }
    if ((temp_v1 <= 0x1000) && (arg9 == 0)) {
        D_803F2EDD = 0;
        return 0;
    }

    spFC = arg0 / 65536.0;
    spF8 = arg1 / 65536.0;
    spF4 = arg2 / 65536.0;

    temp_f16 = (D_80204278->unk38A10[2][0] * spFC) + (D_80204278->unk38A10[2][1] * spF8) + (D_80204278->unk38A10[2][2] * spF4) + D_80204278->unk38A10[2][3];
    if (temp_f16 <= -3.0) {

        sp144 = (D_80204278->unk38A10[0][0] * spFC) + (D_80204278->unk38A10[0][1] * spF8) + (D_80204278->unk38A10[0][2] * spF4) + D_80204278->unk38A10[0][3];
        sp140 = (D_80204278->unk38A10[1][0] * spFC) + (D_80204278->unk38A10[1][1] * spF8) + (D_80204278->unk38A10[1][2] * spF4) + D_80204278->unk38A10[1][3];

        sp12C = (gScreenWidth  * 2) + ((D_80204278->unk38A10[3][0] * sp144) / temp_f16);
        sp128 = (gScreenHeight * 2) + ((D_80204278->unk38A10[3][1] * sp140) / temp_f16);

        sp2C = (((s32) ((arg3 * 33) / D_803F2D50.unkE0) << 7) / -temp_f16) / 8.0;

        yl = sp128 - sp2C;
        if ((gScreenHeight * 4) < yl) {
            return 3;
        }

        xl = sp12C - sp2C;
        if (xl < (gScreenWidth * 4)) {

            xh = sp128 + sp2C;
            if (xh > 0.0f) {

                yh = sp12C + sp2C;
                if (yh > 0.0f) {

                    if ((temp_v1 < 0xE1000) && (arg9 == 0)) {
                        if (temp_v1 < 0x31000) {
                            D_803F2EDD = 0;
                            return 0;
                        }
                        D_803F2EDD = 1;
                        return 0;
                    }

                    if (arg4 != 0x64) {

                        gDPSetTextureImage(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_01003BD0[(arg4 << 7)]);
                        gDPSetTile(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                        gDPLoadSync(D_801D9EB8++);
                        gDPLoadBlock(D_801D9EB8++, G_TX_LOADTILE, 0, 0, 63, 2048);
                        gDPPipeSync(D_801D9EB8++);
                        gDPSetTile(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                        gDPSetTileSize(D_801D9EB8++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15));
                        gDPSetEnvColor(D_801D9EB8++, red, green, blue, 0xFF);
                        gSPDisplayList(D_801D9EB8++, D_01003A28);

                        temp_f2_3 = ((D_80204278->unk38A10[3][2] * temp_f16) + D_80204278->unk38A10[3][3]) / -temp_f16;
                        gDPSetPrimDepth(D_801D9EB8++, ((temp_f2_3 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42, 0);

                        if (D_803E1CF8.min >= (D_803E1CF8.max - 1)) {
                            var_a0 = 0;
                        } else {
                            temp_f0_3 = temp_f2_3 * 7990.0;
                            temp_v1_2 = D_803E1CF8.min << 3;
                            temp_a1_3 = D_803E1CF8.max << 3;

                            var_f2 = MIN(temp_f0_3, 8000.0);

                            temp_f10_2 = var_f2;
                            if (temp_v1_2 >= temp_f10_2) {
                                var_a0 = 0;
                            } else if (temp_f10_2 >= temp_a1_3) {
                                var_a0 = 0xFF;
                            } else {
                                var_a0 = (((var_f2 - temp_v1_2) * 255.0) / (temp_a1_3 - temp_v1_2));
                            }
                        }

                        gDPSetPrimColor(D_801D9EB8++, 0, var_a0, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0xFF);

                        if (xl < yh) {

                            dsdx_dtdy = (65536.0f / (yh - xl));

                            gSPScisTextureRectangle(
                            /* pkt  */ D_801D9EB8++,
                            /* xl   */ (s16) xl,
                            /* yl   */ (s16) yl,
                            /* xh   */ (s16) xh,
                            /* yh   */ (s16) yh,
                            /* tile */ G_TX_RENDERTILE,
                            /* t    */  (dsdx_dtdy * ((u32) xl & 3)) >> 9,
                            /* s    */ -(dsdx_dtdy * ((u32) yl & 3)) >> 7,
                            /* dsdx */ dsdx_dtdy,
                            /* dtdy */ dsdx_dtdy);

                            gSPDisplayList(D_801D9EB8++, D_01003A40_3D310);
                        }
                    }
                    return 1;
                }
            }
        }

        temp_f2_4 = (D_80204278->unk38A10[2][0] * spFC) + (D_80204278->unk38A10[2][1] * spF8) + (D_80204278->unk38A10[2][2] * (f32) ((f64) func_8031124C_7228FC(arg0 >> 0x10, arg1 >> 0x10) / 65536.0)) + D_80204278->unk38A10[2][3];
        if (temp_f2_4 <= -3.0) {
            temp_f14   = (gScreenWidth  * 2) + ((D_80204278->unk38A10[3][0] * sp144) / temp_f2_4);
            temp_f14_2 = (gScreenHeight * 2) + ((D_80204278->unk38A10[3][1] * sp140) / temp_f2_4);

            if (((sp12C + sp2C) < 0.0f) && ((temp_f14 + sp2C) < 0.0f)) {
                return 3;
            }
            if (((gScreenWidth * 4) < xl) && ((gScreenWidth * 4) < (temp_f14 - sp2C))) {
                return 3;
            }
            if (((gScreenWidth * 4) < yl) && ((gScreenWidth * 4) < (temp_f14_2 - sp2C))) {
                return 3;
            }
            return 2;
        }
        return 2;
    }

    if (temp_f16 <= (arg8 << 6)) {
        return 2;
    }

    if (((D_80204278->unk38A10[2][0] * spFC) + (D_80204278->unk38A10[2][1] * spF8) + (D_80204278->unk38A10[2][2] * (f32) (func_8031124C_7228FC(arg0 >> 0x10, arg1 >> 0x10) / 65536.0)) + D_80204278->unk38A10[2][3]) <= -3.0) {
        return 2;
    }
    return 3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802E8CF4_6FA3A4.s")
#endif

#if 0
s32 func_802E9B90_6FB240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    f32 tmp1;
    f32 tmp2;

    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f6;

    f32 sp6C;
    f32 sp68;
    f32 sp64;

    s64 sp58;
    s64 sp50;
    s64 sp48;
    //
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    s64 temp_v1;

    sp20 = arg0 >> 0x10;
    sp1C = arg1 >> 0x10;
    sp18 = arg2 >> 0x10;

    if (func_8029A334_6AB9E4(sp20, sp1C, sp18) == 0) {
        return 4;
    }

    sp50 = sp1C - (s16) D_803F2C48;
    sp58 = sp20 - (s16) D_803F2C44;
    sp48 = sp18 - (s16) D_803F2C4C;

    temp_v1 = (((SQ(sp48) + SQ(sp58) + SQ(sp50)) >> arg4) * D_803F2E30) / 75.0f;

    if ((temp_v1 > 0x4C9000)) {
        return 4;
    }
    if ((temp_v1 <= 0x1000)) {
        D_803F2EDD = 0;
        return 0;
    }

    sp6C = (arg0 / 65536.0);
    sp68 = (arg1 / 65536.0);
    sp64 = (arg2 / 65536.0);

    temp_f16 = (D_80204278->unk38A10[2][0] * sp6C) +
               (D_80204278->unk38A10[2][1] * sp68) +
               (D_80204278->unk38A10[2][2] * sp64) +
               (D_80204278->unk38A10[2][3]       );

    if (temp_f16 <= -3.0) {
        tmp1 = (D_80204278->unk38A10[0][0] * sp6C) +
               (D_80204278->unk38A10[0][1] * sp68) +
               (D_80204278->unk38A10[0][2] * sp64) +
               (D_80204278->unk38A10[0][3]       );

        tmp2 = (D_80204278->unk38A10[1][0] * sp6C) +
               (D_80204278->unk38A10[1][1] * sp68) +
               (D_80204278->unk38A10[1][2] * sp64) +
               (D_80204278->unk38A10[1][3]       );

        tmp1 = tmp1 * D_80204278->unk38A10[3][0];
        temp_f14 = (gScreenWidth * 2) + (tmp1 / temp_f16);

        tmp2 = tmp2 * D_80204278->unk38A10[3][1];
        temp_f6 = (gScreenHeight * 2) + (tmp2 / temp_f16);

        temp_f0 = (((s32) ((arg3 * 33) / D_803F2E30) << 7) / -temp_f16) / 8.0;

        if ((gScreenHeight * 4) < (temp_f6 - temp_f0)) {
            return 3;
        }

        if (((gScreenWidth * 4) > (temp_f14 - temp_f0)) && ((temp_f6 + temp_f0) > 0.0f) && ((temp_f14 + temp_f0) > 0.0f)) {
            if (temp_v1 < 0xE1000) {
                if ((temp_v1 < 0x31000)) {
                    D_803F2EDD = 0;
                    return 0;
                }
                D_803F2EDD = 1;
                return 0;
            }
            return 1;
        }
        return 3;
    }
    return 3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802E9B90_6FB240.s")
#endif

#if 0
s32 func_802EA004_6FB6B4(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {

    s64 temp_v1;
    s64 sp88;
    s32 pad;
    s32 sp78;

    s32 tmp;
    s32 temp_f10;

    f32 temp_f12;
    f32 temp_f0;

    s64 sp68;
    s64 sp60;
    s64 sp58;

    f32 temp_f2;
    f32 temp_f14;


    sp68 = (arg0 >> 0x10) - (s16) D_803F2C44;
    sp60 = (arg1 >> 0x10) - (s16) D_803F2C48;
    sp58 = (arg2 >> 0x10) - (s16) D_803F2C4C;

    if ((s64)((((SQ(sp58) + SQ(sp60) + SQ(sp68)) >> arg3) * D_803F2E30) / 75.0f) > 0xE1000) {
        return 1;
    }

    temp_f2 = arg0 / 65536.0;
    temp_f12 = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;

    temp_f10 = D_80204278->unk38A10[2][3] + ((D_80204278->unk38A10[2][0] * temp_f2) + (D_80204278->unk38A10[2][1] * temp_f12) + (D_80204278->unk38A10[2][2] * temp_f14));
    if (temp_f10 <= -3.0) {

        tmp =  ((D_80204278->unk38A10[0][0] * temp_f2) + (D_80204278->unk38A10[0][1] * temp_f12) + (D_80204278->unk38A10[0][2] * temp_f14) + D_80204278->unk38A10[0][3]);
        sp78 = ((D_80204278->unk38A10[1][0] * temp_f2) + (D_80204278->unk38A10[1][1] * temp_f12) + (D_80204278->unk38A10[1][2] * temp_f14) + D_80204278->unk38A10[1][3]);

        sp88 = (gScreenWidth * 2) + ((D_80204278->unk38A10[3][0] * tmp) / temp_f10);
        temp_v1 = (gScreenHeight * 2) + ((D_80204278->unk38A10[3][1] * sp78) / temp_f10);

        // help!
        if ((sp88 >= 0) && ((gScreenWidth * 4) < sp88)) {
            return 2;
        }
        if ((temp_v1 >= 0) && ((gScreenHeight * 4) < temp_v1)) {
            return 3;
        }
        return 0;
    }

    return 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6FA0A0/func_802EA004_6FB6B4.s")
#endif
