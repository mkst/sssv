#include <ultra64.h>
#include "common.h"


// is this a loop? bunch of macros? what?
#if 0
void func_8032D680_73ED30(void) {

    // s16 i;
    Mtx *tmp;

    // f32 **dst;
    // s32 **src1;
    // s32 **src2;

    tmp = &D_80204278->unk37490;

    // src1 = &D_80204278->unk37490.m[0][0];
    // src2 = &D_80204278->unk37490.m[2][0];
    // dst  = &D_80204278->unk38A10;
    //
    // for (i = 0; i < 6; i++) {
    //     f32 tmp1, tmp2;
    //     tmp1 = ((src1[0][i*2] & 0xFFFF0000) | ((src2[0][i*2] & 0xFFFF0000) >> 16)) / 65536.0;
    //     tmp2 = ((src1[0][i*2] << 16) | (src2[0][i*2] & 0xFFFF)) / 65536.0;
    //     dst[0][i] = tmp1;
    //     dst[1][i] = tmp2;
    // }

    D_80204278->unk38A10[0][0] = (f32) ((tmp->m[0][0] & 0xFFFF0000      ) | ((tmp->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[1][0] = (f32) ((tmp->m[0][0]              << 16) |  (tmp->m[2][0] & 0xFFFF)           ) / 65536.0;

    D_80204278->unk38A10[0][1] = (f32) ((tmp->m[0][2] & 0xFFFF0000      ) | ((tmp->m[2][2] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[1][1] = (f32) ((tmp->m[0][2]              << 16) |  (tmp->m[2][2] & 0xFFFF)           ) / 65536.0;

    D_80204278->unk38A10[0][2] = (f32) ((tmp->m[1][0] & 0xFFFF0000      ) | ((tmp->m[3][0] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[1][2] = (f32) ((tmp->m[1][0]              << 16) |  (tmp->m[3][0] & 0xFFFF)           ) / 65536.0;

    D_80204278->unk38A10[0][3] = (f32) ((tmp->m[1][2] & 0xFFFF0000      ) | ((tmp->m[3][2] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[1][3] = (f32) ((tmp->m[1][2]              << 16) |  (tmp->m[3][2] & 0xFFFF)           ) / 65536.0;

    D_80204278->unk38A10[2][0] = (f32) ((tmp->m[0][1] & 0xFFFF0000      ) | ((tmp->m[2][1] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[2][1] = (f32) ((tmp->m[0][3] & 0xFFFF0000      ) | ((tmp->m[2][3] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[2][2] = (f32) ((tmp->m[1][1] & 0xFFFF0000      ) | ((tmp->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[2][3] = (f32) ((tmp->m[1][3] & 0xFFFF0000      ) | ((tmp->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;

    tmp = &D_80204278->unk37410;
    D_80204278->unk38A10[3][0] = (f32) ((tmp->m[0][0] & 0xFFFF0000      ) | ((tmp->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[3][1] = (f32) ((tmp->m[0][2]              << 16) |  (tmp->m[2][2] & 0xFFFF)           ) / 65536.0;
    D_80204278->unk38A10[3][2] = (f32) ((tmp->m[1][1] & 0xFFFF0000      ) | ((tmp->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
    D_80204278->unk38A10[3][3] = (f32) ((tmp->m[1][3] & 0xFFFF0000      ) | ((tmp->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;

    D_80204278->unk38A10[3][0] *= -(gScreenWidth * 2);
    D_80204278->unk38A10[3][1] *= gScreenHeight * 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032D680_73ED30.s")
#endif

#if 0
// 9716
void func_8032DACC_73F17C(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    f32 sp80;
    f32 sp7C;

    f32 xl;
    f32 yl; // sp10
    f32 xh;
    f32 yh; // sp8

    f32 yOffset; // sp4
    f32 xOffset;

    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f18;
    f32 temp_f2;
    f32 var_f12;

    f32 temp_f8;
    f32 temp_f6;

    s16 dsdx;
    s16 dtdy;
    u16 depth;

    temp_f18 = arg1 / 65536.0;
    temp_f12 = arg2 / 65536.0;
    temp_f14 = arg3 / 65536.0;

    temp_f0 = D_80204278->unk38A10[2][3] +
            ((D_80204278->unk38A10[2][2] * temp_f14) +
            ((D_80204278->unk38A10[2][1] * temp_f12) +
             (D_80204278->unk38A10[2][0] * temp_f18)));

    if (temp_f0 <= -3.0) {
        temp_f2 = ((D_80204278->unk38A10[3][2] * temp_f0) + D_80204278->unk38A10[3][3]) / -temp_f0;

        if (temp_f2 > 0.0) {

            temp_f8 = D_80204278->unk38A10[0][3] +
                    ((D_80204278->unk38A10[0][2] * temp_f14) +
                    ((D_80204278->unk38A10[0][1] * temp_f12) +
                     (D_80204278->unk38A10[0][0] * temp_f18)));

            temp_f6 = D_80204278->unk38A10[1][3] +
                    ((D_80204278->unk38A10[1][2] * temp_f14) +
                    ((D_80204278->unk38A10[1][1] * temp_f12) +
                     (D_80204278->unk38A10[1][0] * temp_f18)));

            sp80 = ((D_80204278->unk38A10[3][0] * temp_f8) / temp_f0) +  (gScreenWidth * (0, 2));
            sp7C = ((D_80204278->unk38A10[3][1] * temp_f6) / temp_f0) + (gScreenHeight * (0, 2));

            arg6 = (arg6 * 33) / D_803F2D50.fovY;

            var_f12 = (arg6 * 32) / -temp_f0;
            if (var_f12 > 16383) {
                var_f12 = 16383;
            }

            if (var_f12 > 0.0f) {
                depth = (temp_f2 * 1023.0f * 32.0f) + 32736.0f;
                gDPSetPrimDepth((*dl)++, (depth - D_803F2D50.unk42), 0);

                xOffset = (arg4 * var_f12) / 128.0;
                yOffset = (arg5 * var_f12) / 128.0;

                xl = sp80 - xOffset;
                yl = sp7C - yOffset;

                xh = sp80 + xOffset;
                yh = sp7C + yOffset;

                if ((xl < xh) && (yl < yh)) {

                    dsdx = ((arg4 << 0xC) / (yh - yl));
                    dtdy = ((arg5 << 0xC) / (xh - xl));

                    if ((xl < (gScreenWidth * 4)) && (yl < 960.0f) && (xh > 0.0f) && (yh > 0.0f)) {
                        gSPScisTextureRectangle(
                        /* pkt  */ (*dl)++,
                        /* xl   */ (s16) xl,
                        /* yl   */ (s16) yl,
                        /* xh   */ (s16) xh,
                        /* yh   */ (s16) yh,
                        /* tile */ G_TX_RENDERTILE,
                        /* s    */ 0,
                        /* t    */ -(dsdx * ((s16) yl & 3)) >> 7,
                        /* dsdx */ dsdx, // tbd
                        /* dtdy */ dtdy);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032DACC_73F17C.s")
#endif

#if 0
// plenty more to figure out
// 10738
void func_8032E150_73F800(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    f32 spA8; // made up
    f32 spA4; // made up

    f32 spA0;

    f32 sp9C;
    f32 sp98;
    f32 sp94;

    f32 sp64;
    f32 sp60;
    f32 sp5C;
    // s32 sp34;
    f32 xl; // sp20
    f32 xh; // sp4
    s16 dsdx; // sp0
    s16 dtdy;
    f32 yh;
    f32 yl;
    f32 temp_f0;
    f32 xOffset;
    f32 yOffset;
    s16 temp_a2;
    s16 temp_a3;
    f32 temp_f10;
    u8 var_a1;
    s32 var_v1;
    u16 depth;

    var_v1 = 0;

    sp64 = arg1 / 65536.0;
    sp60 = arg2 / 65536.0;
    sp5C = arg3 / 65536.0;

    temp_f0 = D_80204278->unk38A10[2][3] +
            ((D_80204278->unk38A10[2][2] * sp5C) +
            ((D_80204278->unk38A10[2][1] * sp60) +
             (D_80204278->unk38A10[2][0] * sp64)));

    if (temp_f0 <= -3.0) {

        sp98 = (D_80204278->unk38A10[3][3] + (D_80204278->unk38A10[3][2] * temp_f0)) / -temp_f0;
        if (sp98 > 0.0) {

            spA8 = D_80204278->unk38A10[0][3] +
                 ((D_80204278->unk38A10[0][2] * sp5C) +
                 ((D_80204278->unk38A10[0][1] * sp60) +
                  (D_80204278->unk38A10[0][0] * sp64)));

            spA4 = D_80204278->unk38A10[1][3] +
                 ((D_80204278->unk38A10[1][2] * sp5C) +
                 ((D_80204278->unk38A10[1][1] * sp60) +
                  (D_80204278->unk38A10[1][0] * sp64)));

            spA0 = ((D_80204278->unk38A10[3][0] * spA8) / temp_f0) + (gScreenWidth  * (0, 2));
            sp9C = ((D_80204278->unk38A10[3][1] * spA4) / temp_f0) + (gScreenHeight * (0, 2));

            arg6 = (arg6 * 33) / D_803F2D50.fovY;

            sp94 = (arg6 * 32) / -temp_f0;

            if (sp94 > 16383.0f) {
                sp94 = 16383.0f;
            }

            if (sp94 > 0.0f) {
                if (D_803E1CF8.min >= (D_803E1CF8.max - 1)) {
                    var_a1 = 0;
                } else {
                    temp_a2 = D_803E1CF8.min * 8;
                    temp_a3 = D_803E1CF8.max * 8;

                    temp_f10 = MIN(sp98 * 7990.0, 8000.0);

                    if (temp_a2 >= (s16)temp_f10) {
                        var_a1 = 0;
                    } else if ((s16)temp_f10 >= temp_a3) {
                        var_a1 = 0xFF;
                    } else {
                        var_a1 = ((temp_f10 - temp_a2) * 255.0) / (temp_a3 - temp_a2);
                    }
                }

                gDPSetPrimColor((*dl)++, 0, var_a1, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0xFF);

                depth = ((sp98 * 1023.0f * 32.0f) + 32736.0f);
                gDPSetPrimDepth((*dl)++, (depth - D_803F2D50.unk42), 0);

                if (arg5 > 32) {
                    arg5 -= 32;
                    var_v1 = 1;
                }

                xOffset = ((arg4 * sp94) / 128.0);
                yOffset = (arg5 * sp94) / 128.0;

                xl = spA0 - xOffset;

                if (var_v1 != 0) {
                    yl = sp9C - (yOffset * 3.0f);
                } else {
                    yl = sp9C - yOffset;
                }

                xh = spA0 + xOffset;
                yh = sp9C + yOffset;

                if ((xl < xh) && (yl < yh)) {

                    dsdx = (arg5 << 0xC) / (xh - xl);
                    dtdy = (arg4 << 0xC) / (yh - yl);

                    if ((xl < (gScreenWidth * 4)) && (yl < 960.0f) && (xh > 0.0f) && (yh > 0.0f)) {
                        gSPScisTextureRectangle(
                        /* pkt  */ (*dl)++,
                        /* xl   */ (s16) xl,
                        /* yl   */ (s16) yl,
                        /* xh   */ (s16) xh,
                        /* yh   */ (s16) yh,
                        /* tile */ G_TX_RENDERTILE,
                        /* s    */ ((dsdx * ((s16) xl & 3)) >> 9),
                        /* t    */ 0,
                        /* dsdx */ dsdx,
                        /* dtdy */ dtdy);

                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032E150_73F800.s")
#endif

void func_8032E9E4_740094(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7) {
    f32 temp_f8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp84;

    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f14;
    f32 temp_f2;

    s32 temp_v0;
    s32 var_a0;
    s32 var_v1;
    s16 dtdy;
    s16 dsdx;
    u16 depth;
    s16 temp_t7;
    u8  limit;

    temp_f2  = arg1 / 65536.0;
    temp_f10 = arg2 / 65536.0;
    temp_f14 = arg3 / 65536.0;

    temp_f0 = D_80204278->unk38A10[2][3] +
            ((D_80204278->unk38A10[2][2] * temp_f14) +
            ((D_80204278->unk38A10[2][1] * temp_f10) +
             (D_80204278->unk38A10[2][0] * temp_f2)));

    if (temp_f0 <= -3.0) {

        sp94 = (D_80204278->unk38A10[3][3] + (D_80204278->unk38A10[3][2] * temp_f0)) / -temp_f0;
        if (sp94 > 0.0) {

            temp_f8 = D_80204278->unk38A10[0][3] +
                    ((D_80204278->unk38A10[0][2] * temp_f14) +
                    ((D_80204278->unk38A10[0][1] * temp_f10) +
                     (D_80204278->unk38A10[0][0] * temp_f2)));
            sp98 = D_80204278->unk38A10[1][3] +
                 ((D_80204278->unk38A10[1][2] * temp_f14) +
                 ((D_80204278->unk38A10[1][1] * temp_f10) +
                  (D_80204278->unk38A10[1][0] * temp_f2)));

            sp90 = ((D_80204278->unk38A10[3][0] * temp_f8) / temp_f0) + (gScreenWidth  * (0, 2));
            sp84 = ((D_80204278->unk38A10[3][1] * sp98) / temp_f0) + (gScreenHeight * (0, 2));

            arg6 = (arg6 * 33) / D_803F2D50.fovY;
            arg7 = (arg7 * 33) / D_803F2D50.fovY;

            var_v1 = (arg6 * 32) / -temp_f0;
            var_a0 = (arg7 * 32) / -temp_f0;

            if (var_v1 > 16383) {
                var_v1 = 16383;
            }
            if (var_a0 > 16383) {
                var_a0 = 16383;
            }

            if ((var_v1 > 0) && (var_a0 > 0)) {
                f32 xl;
                f32 yl;
                f32 xh;
                f32 yh;
                f32 xOffset;
                f32 yOffset;

                temp_v0 = (1000 - ((1000 - D_803E1CF8.min) / 6));
                if (temp_v0 >= D_803E1CF8.max) {
                    limit = 0;
                } else {
                    temp_t7 = ((s32) sp94 * 1000) >> 16;
                    if (temp_v0 >= temp_t7) {
                        limit = 0;
                    } else {
                        limit = (((temp_t7 - temp_v0) << 8) / (D_803E1CF8.max - temp_v0));
                    }
                }

                depth = ((sp94 * 1023.0f * 32.0f) + 32736.0f);
                gDPSetPrimColor((*dl)++, 0, limit, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0xFF);
                gDPSetPrimDepth((*dl)++, (depth - D_803F2D50.unk42), 0);

                xOffset = (arg4 * var_v1) / 128.0;
                yOffset = (arg5 * var_a0) / 128.0;

                xl = sp90 - xOffset;
                yl = sp84 - yOffset;

                xh = sp90 + xOffset;
                yh = sp84 + yOffset;

                if ((xl < xh) && (yl < yh)) {

                    dsdx = (arg5 << 0xC) / (xh - xl);
                    dtdy = (arg4 << 0xC) / (yh - yl);

                    if ((xl < (gScreenWidth * 4)) && (yl < 960.0f) && (xh > 0.0f) && (yh > 0.0f)) {
                        gSPScisTextureRectangle(
                        /* pkt  */ (*dl)++,
                        /* xl   */ (s16) xl,
                        /* yl   */ (s16) yl,
                        /* xh   */ (s16) xh,
                        /* yh   */ (s16) yh,
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

void func_8032F170_740820(Gfx **dl, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, u8 arg8, s16 arg9) {
    f32 temp_f8;
    f32 sp8C;   // sp84?
    f32 temp_f18;
    f32 temp_f2;

    f32 sp7C;
    f32 sp78;
    f32 pad;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f16;

    f32 yOffset;
    f32 xOffset;
    f32 xl;
    f32 yl;
    f32 xh;
    f32 yh;

    s16 dsdx;
    s16 dtdy;

    s32 var_a3;
    s32 var_t1;

    temp_f0  = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;
    temp_f16 = arg3 / 65536.0;

    temp_f2 = D_80204278->unk38A10[2][3] +
            ((D_80204278->unk38A10[2][2] * temp_f16) +
            ((D_80204278->unk38A10[2][1] * temp_f14) +
             (D_80204278->unk38A10[2][0] * temp_f0 )));

    if (temp_f2 <= -3.0) {

        temp_f18 = (D_80204278->unk38A10[3][3] + (D_80204278->unk38A10[3][2] * temp_f2)) / -temp_f2;
        if (temp_f18 > 0.0) {

            temp_f8 = D_80204278->unk38A10[0][3] +
                    ((D_80204278->unk38A10[0][2] * temp_f16) +
                    ((D_80204278->unk38A10[0][1] * temp_f14) +
                     (D_80204278->unk38A10[0][0] * temp_f0)));

            sp8C = D_80204278->unk38A10[1][3] +
                 ((D_80204278->unk38A10[1][2] * temp_f16) +
                 ((D_80204278->unk38A10[1][1] * temp_f14) +
                  (D_80204278->unk38A10[1][0] * temp_f0)));

            sp78 = ((D_80204278->unk38A10[3][0] * temp_f8) / temp_f2) + (gScreenWidth  * (0, 2));
            sp7C = ((D_80204278->unk38A10[3][1] * sp8C) / temp_f2) + (gScreenHeight * (0, 2));

            arg6 = (arg6 * 33) / D_803F2D50.fovY;
            arg7 = (arg7 * 33) / D_803F2D50.fovY;

            var_a3 = (arg6 * 32) / -temp_f2;
            var_t1 = (arg7 * 32) / -temp_f2;

            if (var_a3 > 16383) {
                var_a3 = 16383;
            }
            if (var_t1 > 16383) {
                var_t1 = 16383;
            }

            if ((var_a3 > 0) && (var_t1 > 0)) {
                gDPSetPrimDepth((*dl)++, (u16)(((temp_f18 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42), 0);

                xOffset = (arg4 * var_a3) / 128.0;
                yOffset = (arg5 * var_t1) / 128.0;

                if (arg9 > 0) {
                    if ((arg9 * 2) < xOffset) {
                        xOffset = (arg9 * 2);
                    }
                    if ((arg9 * 2) < yOffset) {
                        yOffset = (arg9 * 2);
                    }
                }
                if (arg8 != 0) {
                    while ((gScreenWidth * 4) < sp78) {
                        sp78 -= (gScreenWidth * 4);
                    }
                    while (sp78 < 0.0f) {
                        sp78 += (gScreenWidth * 4);
                    }
                }

                xl = sp78 - xOffset;
                yl = sp7C - yOffset;

                xh = sp78 + xOffset;
                yh = sp7C + yOffset;

                if ((xl < xh) && (yl < yh)) {

                    dsdx = (arg5 << 0xC) / (xh - xl);
                    dtdy = (arg4 << 0xC) / (yh - yl);

                    if ((xl < (gScreenWidth * 4)) && (yl < 960.0f) && (xh > 0.0f) && (yh > 0.0f)) {
                        gSPScisTextureRectangle(
                        /* pkt  */ (*dl)++,
                        /* xl   */ (s16) xl,
                        /* yl   */ (s16) yl,
                        /* xh   */ (s16) xh,
                        /* yh   */ (s16) yh,
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

void func_8032F8C8_740F78(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8029CEF0_6AE5A0(arg0 << 16, arg1 << 16, arg2 << 16, 512, arg3 + 3, &D_803D2E08, arg3 + 3, 0, 0, 0);
}
