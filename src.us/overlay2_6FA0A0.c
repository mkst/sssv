#include <ultra64.h>
#include "common.h"

extern Gfx D_01003A28_3D2F8[];
extern Gfx D_01003A40_3D310[];
extern u8  img_D_01003BD0_3D4A0_ci4__png[]; // fov masks


// is animal off screen?
s16 func_802E89F0_6FA0A0(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 fovImageIdx, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return VISIBILITY_VISIBLE;
        } else {
            return VISIBILITY_INVISIBLE;
        }
    }
    if (D_803F28D0[6] & 3) {
        if (D_803F28D0[6] & 1) {
            if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28D0[6] & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
                return VISIBILITY_VISIBLE;
            } else {
                return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
            }
        }
        if ((func_802E9B90_6FB240(((D_803F28D0[6] & 0xFFC) << 0x12) -xPos, zPos, yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return VISIBILITY_VISIBLE;
        } else {
            return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
        }
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
    }
}


// only used by dynamic objects / tails
s16 func_802E8BBC_6FA26C(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 fovImageIdx, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (func_8029A334_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return VISIBILITY_VISIBLE;
        } else {
            return VISIBILITY_INVISIBLE;
        }
    }
    if (D_803F28D0[6] & 1) {
        if ((func_802E9B90_6FB240(xPos, zPos, ((D_803F28D0[6] & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return VISIBILITY_VISIBLE;
        }
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
    } else {
        return func_802E8CF4_6FA3A4(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
    }
}

s16 func_802E8CF4_6FA3A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 fovImageIdx, s16 red, s16 green, s16 blue, s8 arg8, u8 arg9) {
    f32 sp144;
    f32 sp140;

    s64 fov;

    f32 temp_f14;
    f32 temp_f16;

    f32 sp12C;
    f32 sp128;

    f32 xh;  // sp38
    f32 yh;  // sp34

    f32 xl;   // sp28
    f32 yl;   // sp24

    f32 temp_f162;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f2;

    s16 temp_a1_3;
    s16 temp_v1_2;

    s16 dsdx_dtdy;

    u8  lod;

    f32 spFC;
    f32 spF8;
    f32 spF4;
    s32 unused3[3];
    s64 spE0;
    s64 spD8;
    s64 spD0;
    s32 unused;
    s32 unused4;
    f32 unused5;
    f32 sp2C;

    if (func_8029A334_6AB9E4(arg0 >> 0x10, arg1 >> 0x10, arg2 >> 0x10) == 0) {
        return VISIBILITY_INVISIBLE;
    }

    spE0 = (arg0 >> 0x10) - (s16) D_803F2C44; // x distance to camera
    spD8 = (arg1 >> 0x10) - (s16) D_803F2C48; // z distance to camera
    spD0 = (arg2 >> 0x10) - (s16) D_803F2C4C; // y distance to camera

    fov = (SQ(spE0) + SQ(spD8) + SQ(spD0)) >> arg8;
    fov = (fov * D_803F2D50.fovY) / 75.0f;

    if (fov > 0x4C9000) {
        return VISIBILITY_INVISIBLE;
    }
    if ((fov <= 0x1000) && (arg9 == 0)) {
        D_803F2EDD = 0;
        return VISIBILITY_VISIBLE;
    }

    spFC = arg0 / 65536.0;
    spF8 = arg1 / 65536.0;
    spF4 = arg2 / 65536.0;

    temp_f16 = D_80204278->unk38A10[2][3] +
             ((D_80204278->unk38A10[2][2] * spF4) +
             ((D_80204278->unk38A10[2][1] * spF8) +
              (D_80204278->unk38A10[2][0] * spFC)));

    if (temp_f16 <= -3.0) {

        sp144 = D_80204278->unk38A10[0][3] +
              ((D_80204278->unk38A10[0][2] * spF4) +
              ((D_80204278->unk38A10[0][1] * spF8) +
               (D_80204278->unk38A10[0][0] * spFC)));
        sp140 = D_80204278->unk38A10[1][3] +
              ((D_80204278->unk38A10[1][2] * spF4) +
              ((D_80204278->unk38A10[1][1] * spF8) +
               (D_80204278->unk38A10[1][0] * spFC)));

         sp12C = ((D_80204278->unk38A10[3][0] * sp144) / temp_f16) + ((0, gScreenWidth * 2));
        sp128 = ((D_80204278->unk38A10[3][1] * sp140) / temp_f16) + (0, gScreenHeight * 2);

        arg3 = arg3 * 33 / D_803F2D50.fovY;
        sp2C = (arg3 * 128 / -temp_f16) / 8.0;

        xl = sp12C - sp2C;
        yl = sp128 - sp2C;
        yh = sp12C + sp2C;
        xh = sp128 + sp2C;

        if (yl > gScreenHeight * 4) {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }

        if (xl < gScreenWidth * 4 && xh > 0.0f && yh > 0.0f) {
            if (fov < 0xE1000 && arg9 == 0) {
                if (fov < 0x31000) {
                    D_803F2EDD = 0;
                } else {
                    D_803F2EDD = 1;
                }
                return VISIBILITY_VISIBLE;
            }

            if (fovImageIdx != 100) {
                gDPSetTextureImage(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &img_D_01003BD0_3D4A0_ci4__png[(fovImageIdx << 7)]);
                gDPSetTile(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(D_801D9EB8++);
                gDPLoadBlock(D_801D9EB8++, G_TX_LOADTILE, 0, 0, 63, 2048);
                gDPPipeSync(D_801D9EB8++);
                gDPSetTile(D_801D9EB8++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(D_801D9EB8++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15));
                gDPSetEnvColor(D_801D9EB8++, red, green, blue, 0xFF);
                gSPDisplayList(D_801D9EB8++, D_01003A28_3D2F8);

                temp_f2_3 = (D_80204278->unk38A10[3][3] + (D_80204278->unk38A10[3][2] * temp_f16)) / -temp_f16;
                gDPSetPrimDepth(D_801D9EB8++, (u16)((temp_f2_3 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42, 0);

                if (D_803E1CF8.min >= (D_803E1CF8.max - 1)) {
                    lod = 0;
                } else {
                    temp_v1_2 = D_803E1CF8.min << 3;
                    temp_a1_3 = D_803E1CF8.max << 3;

                    var_f2 = MIN(8000.0, temp_f2_3 * 7990.0);

                    if (temp_v1_2 >= (s16)var_f2) {
                        lod = 0;
                    } else if ((s16)var_f2 >= temp_a1_3) {
                        lod = 0xFF;
                    } else {
                        lod = ((var_f2 - temp_v1_2) * 255.0) / (temp_a1_3 - temp_v1_2);
                    }
                }

                gDPSetPrimColor(D_801D9EB8++, 0, lod, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0xFF);

                if (xl < yh) {

                    dsdx_dtdy = (65536.0f / (yh - xl));

                    gSPScisTextureRectangle(
                    /* pkt  */ D_801D9EB8++,
                    /* xl   */ (s16) xl,
                    /* yl   */ (s16) yl,
                    /* xh   */ (s16) yh,
                    /* yh   */ (s16) xh,
                    /* tile */ G_TX_RENDERTILE,
                    /* t    */  (dsdx_dtdy * ((u16) xl & 3)) >> 9,
                    /* s    */ -(dsdx_dtdy * ((u16) yl & 3)) >> 7,
                    /* dsdx */ dsdx_dtdy,
                    /* dtdy */ dsdx_dtdy);

                    gSPDisplayList(D_801D9EB8++, D_01003A40_3D310);
                }
            }
            return VISIBILITY_TOO_FAR;
        }

        spF4 = func_8031124C_7228FC(arg0 >> 0x10, arg1 >> 0x10) / 65536.0;
        temp_f2_4 = D_80204278->unk38A10[2][3] +
                ((D_80204278->unk38A10[2][2] * spF4) +
                ((D_80204278->unk38A10[2][1] * spF8) +
                (D_80204278->unk38A10[2][0] * spFC)));

        if (temp_f2_4 <= -3.0) {
            // temp_f14 = D_80204278->unk38A10[3][0] * sp144 / temp_f2_4 + gScreenWidth  * 2;
            temp_f14 = ((D_80204278->unk38A10[3][0] * sp144) / temp_f2_4) + (0, gScreenWidth * 2);
            temp_f162 = ((D_80204278->unk38A10[3][1] * sp140) / temp_f2_4) + (0, gScreenHeight *  2);
        } else {
            return VISIBILITY_OUT_OF_BOUNDS_X;
        }

        if ((sp12C + sp2C) < 0 && (temp_f14 + sp2C < 0)) {
            // fake
            spF4 = (1 * spF4);
            // end fake
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }
        if ((gScreenWidth * 4 < xl) &&( gScreenWidth * 4 < temp_f14 - sp2C)) {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }
        if ((gScreenWidth * 4 < yl) && (gScreenWidth * 4 < temp_f162 - sp2C)) {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }
        return VISIBILITY_OUT_OF_BOUNDS_X;
    }

    if (temp_f16 <= (arg8 << 6)) {
        return VISIBILITY_OUT_OF_BOUNDS_X;
    }

    spF4 = func_8031124C_7228FC(arg0 >> 0x10, arg1 >> 0x10) / 65536.0;

    temp_f2_4 = D_80204278->unk38A10[2][3] +
            ((D_80204278->unk38A10[2][2] * spF4) +
            ((D_80204278->unk38A10[2][1] * spF8) +
            (D_80204278->unk38A10[2][0] * spFC)));

    if (temp_f2_4 <= -3.0) {
        return VISIBILITY_OUT_OF_BOUNDS_X;
    }
    return VISIBILITY_OUT_OF_BOUNDS_Y;
}

s16 func_802E9B90_6FB240(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    s32 pad[0x4];

    f32 height;
    s32 pad2[2];
    f32 width;

    f32 temp_f0;
    f32 temp_f16;
    f32 tmp1;
    f32 tmp2;

    f32 sp6C;
    f32 sp68;
    f32 sp64;

    s64 sp58;
    s64 sp50;
    s64 sp48;
    s64 fov;

    if (func_8029A334_6AB9E4(arg0 >> 0x10, arg1 >> 0x10, arg2 >> 0x10) == 0) {
        return VISIBILITY_INVISIBLE;
    }

    sp58 = (arg0 >> 0x10) - (s16) D_803F2C44;
    sp50 = (arg1 >> 0x10) - (s16) D_803F2C48;
    sp48 = (arg2 >> 0x10) - (s16) D_803F2C4C;

    fov = (((SQ(sp58) + SQ(sp50) + SQ(sp48)) >> arg4));
    fov = (fov * D_803F2D50.fovY) / 75.0f;

    if ((fov > 0x4C9000)) { // FTOFIX32(76.5625)
        return VISIBILITY_INVISIBLE;
    }
    if ((fov <= 0x1000)) { // FTOFIX32(0.0625)
        D_803F2EDD = 0;
        return VISIBILITY_VISIBLE;
    }

    sp6C = (arg0 / 65536.0);
    sp68 = (arg1 / 65536.0);
    sp64 = (arg2 / 65536.0);

    temp_f16 = D_80204278->unk38A10[2][3] +
             ((D_80204278->unk38A10[2][2] * sp64) +
             ((D_80204278->unk38A10[2][1] * sp68) +
              (D_80204278->unk38A10[2][0] * sp6C)));

    if (temp_f16 <= -3.0) {

        tmp1 = D_80204278->unk38A10[0][3] +
             ((D_80204278->unk38A10[0][2] * sp64) +
             ((D_80204278->unk38A10[0][1] * sp68) +
              (D_80204278->unk38A10[0][0] * sp6C)));

        tmp2 = D_80204278->unk38A10[1][3] +
             ((D_80204278->unk38A10[1][2] * sp64) +
             ((D_80204278->unk38A10[1][1] * sp68) +
              (D_80204278->unk38A10[1][0] * sp6C)));

        // replace (0, 2) with temp var assignment? width/height?
        width = ((D_80204278->unk38A10[3][0] * tmp1) / temp_f16) + ((0, gScreenWidth * 2));
        height =  ((D_80204278->unk38A10[3][1] * tmp2) / temp_f16) + ((0, gScreenHeight * 2));

        arg3 = ((arg3 * 33) / D_803F2D50.fovY);
        temp_f0 = (arg3 * 128 / (-temp_f16)) / 8.0;

        if ((gScreenHeight * 4) < (height - temp_f0)) {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }

        if (((gScreenWidth * 4) > (width - temp_f0)) &&
            ((height + temp_f0) > 0.0f) &&
            ((width + temp_f0) > 0.0f)) {

            if (fov < 0xE1000) {
                if ((fov < 0x31000)) {
                    D_803F2EDD = 0;
                } else {
                    D_803F2EDD = 1;
                }
                return VISIBILITY_VISIBLE;
            } else {
                return VISIBILITY_TOO_FAR;
            }
        } else {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }
    }

    return VISIBILITY_OUT_OF_BOUNDS_Y;
}

s16 func_802EA004_6FB6B4(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s64 sp88;
    s64 sp80;
    s32 sp7C; // X coordinate in camera space.
    s32 sp78; // Y coordinate in camera space.
    s32 sp74; // (Z-depth) is used to normalize X and Y
    s32 sp70; // unused
    s64 sp68;
    s64 sp60;
    s64 sp58;

    f32 fov;
    f32 temp_f2;
    s32 pad;
    f32 temp_f12;
    f32 temp_f14;

    sp68 = (arg0 >> 0x10) - (s16) D_803F2C44;
    sp60 = (arg1 >> 0x10) - (s16) D_803F2C48;
    sp58 = (arg2 >> 0x10) - (s16) D_803F2C4C;

    sp60 = ((SQ(sp68) + SQ(sp60) + SQ(sp58)) >> arg3);
    fov = (sp60 * D_803F2D50.fovY) / 75.0f;
    if ((s64)fov > 0xE1000) {
        return VISIBILITY_TOO_FAR;
    }

    temp_f2 = arg0 / 65536.0;
    temp_f12 = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;

    sp74 = D_80204278->unk38A10[2][3] +
         ((D_80204278->unk38A10[2][2] * temp_f14) +
         ((D_80204278->unk38A10[2][1] * temp_f12) +
          (D_80204278->unk38A10[2][0] * temp_f2)));

    if (sp74 <= -3.0) {

        sp7C = D_80204278->unk38A10[0][3] +
             ((D_80204278->unk38A10[0][2] * temp_f14) +
             ((D_80204278->unk38A10[0][1] * temp_f12) +
              (D_80204278->unk38A10[0][0] * temp_f2)));

        sp78 = D_80204278->unk38A10[1][3] +
             ((D_80204278->unk38A10[1][2] * temp_f14) +
             ((D_80204278->unk38A10[1][1] * temp_f12) +
              (D_80204278->unk38A10[1][0] * temp_f2)));

        sp88 = ((D_80204278->unk38A10[3][0] * sp7C) / sp74) + (gScreenWidth *  ((0, 2)));
        sp80 = ((D_80204278->unk38A10[3][1] * sp78) / sp74) + (gScreenHeight * ((0, 2)));

        if ((sp88 < 0) || ((gScreenWidth * 4) < sp88)) {
            return VISIBILITY_OUT_OF_BOUNDS_X; // out of horizontal bounds
        }
        if ((sp80 < 0) || ((gScreenHeight * 4) < sp80)) {
            return VISIBILITY_OUT_OF_BOUNDS_Y; // out of vertical bounds
        }
        return VISIBILITY_VISIBLE;
    }

    return VISIBILITY_OUT_OF_BOUNDS_X;
}
