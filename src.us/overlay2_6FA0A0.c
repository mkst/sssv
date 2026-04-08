#include <ultra64.h>
#include "common.h"

extern Gfx gFovMaskRenderSetupDl[];
extern Gfx D_01003A40_3D310[];
extern u8  img_D_01003BD0_3D4A0_ci4__png[]; // fov masks


// is animal off screen?
s16 classify_object_visibility_6FA0A0(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 fovImageIdx, s16 arg5, s16 arg6, s16 arg7, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (is_world_cell_loaded_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return VISIBILITY_VISIBLE;
        } else {
            return VISIBILITY_INVISIBLE;
        }
    }
    if (gCameraVisibilityMask[6] & 3) {
        if (gCameraVisibilityMask[6] & 1) {
            if ((classify_visibility_simple(xPos, zPos, ((gCameraVisibilityMask[6] & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
                return VISIBILITY_VISIBLE;
            } else {
                return classify_visibility_and_draw_fov_mask(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
            }
        }
        if ((classify_visibility_simple(((gCameraVisibilityMask[6] & 0xFFC) << 0x12) -xPos, zPos, yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return VISIBILITY_VISIBLE;
        } else {
            return classify_visibility_and_draw_fov_mask(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
        }
    } else {
        return classify_visibility_and_draw_fov_mask(xPos, zPos, yPos, arg3, fovImageIdx, arg5, arg6, arg7, arg8, arg9);
    }
}


// only used by dynamic objects / tails
s16 classify_dynamic_visibility_6FA26C(s32 xPos, s32 zPos, s32 yPos, s32 arg3, u8 fovImageIdx, s16 red, s16 green, s16 blue, s8 arg8, u8 arg9) {
    if (arg3 == 0) {
        if (is_world_cell_loaded_6AB9E4(xPos >> 16, zPos >> 16, yPos >> 16) != 0) {
            return VISIBILITY_VISIBLE;
        } else {
            return VISIBILITY_INVISIBLE;
        }
    }
    if (gCameraVisibilityMask[6] & 1) {
        if ((classify_visibility_simple(xPos, zPos, ((gCameraVisibilityMask[6] & 0xFFC) << 0x12) - yPos, arg3, arg8) == 0) && (arg9 == 0)) {
            return VISIBILITY_VISIBLE;
        }
        return classify_visibility_and_draw_fov_mask(xPos, zPos, yPos, arg3, fovImageIdx, red, green, blue, arg8, arg9);
    } else {
        return classify_visibility_and_draw_fov_mask(xPos, zPos, yPos, arg3, fovImageIdx, red, green, blue, arg8, arg9);
    }
}

s16 classify_visibility_and_draw_fov_mask(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 fovImageIdx, s16 red, s16 green, s16 blue, s8 arg8, u8 arg9) {
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

    if (is_world_cell_loaded_6AB9E4(arg0 >> 0x10, arg1 >> 0x10, arg2 >> 0x10) == 0) {
        return VISIBILITY_INVISIBLE;
    }

    spE0 = (arg0 >> 0x10) - (s16) gCameraEyeWorldX; // x distance to camera
    spD8 = (arg1 >> 0x10) - (s16) gCameraEyeWorldZ; // z distance to camera
    spD0 = (arg2 >> 0x10) - (s16) gCameraEyeWorldY; // y distance to camera

    fov = (SQ(spE0) + SQ(spD8) + SQ(spD0)) >> arg8;
    fov = (fov * D_803F2D50.fovY) / 75.0f;

    if (fov > 1225 * 4096) {
        return VISIBILITY_INVISIBLE;
    }
    if ((fov <= 4096) && (arg9 == 0)) {
        gLodDetailState = 0;
        return VISIBILITY_VISIBLE;
    }

    spFC = arg0 / 65536.0;
    spF8 = arg1 / 65536.0;
    spF4 = arg2 / 65536.0;

    temp_f16 =
        (gDisplayListContext->unk38A10.flat.unk20 * spFC) +
        (gDisplayListContext->unk38A10.flat.unk24 * spF8) +
        (gDisplayListContext->unk38A10.flat.unk28 * spF4) +
        (gDisplayListContext->unk38A10.flat.unk2C);

    if (temp_f16 <= -3.0) {
        sp144 =
            (gDisplayListContext->unk38A10.flat.unk0 * spFC) +
            (gDisplayListContext->unk38A10.flat.unk4 * spF8) +
            (gDisplayListContext->unk38A10.flat.unk8 * spF4) +
            (gDisplayListContext->unk38A10.flat.unkC);

        sp140 =
            (gDisplayListContext->unk38A10.flat.unk10 * spFC) +
            (gDisplayListContext->unk38A10.flat.unk14 * spF8) +
            (gDisplayListContext->unk38A10.flat.unk18 * spF4) +
            (gDisplayListContext->unk38A10.flat.unk1C);

        sp12C = ((gDisplayListContext->unk38A10.flat.unk30 * sp144) / temp_f16) + (0, gScreenWidth * 2);
        sp128 = ((gDisplayListContext->unk38A10.flat.unk34 * sp140) / temp_f16) + (0, gScreenHeight * 2);

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
                    gLodDetailState = 0;
                } else {
                    gLodDetailState = 1;
                }
                return VISIBILITY_VISIBLE;
            }

            if (fovImageIdx != 100) {
                gDPSetTextureImage(gAuxDL++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &img_D_01003BD0_3D4A0_ci4__png[(fovImageIdx << 7)]);
                gDPSetTile(gAuxDL++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gAuxDL++);
                gDPLoadBlock(gAuxDL++, G_TX_LOADTILE, 0, 0, 63, 2048);
                gDPPipeSync(gAuxDL++);
                gDPSetTile(gAuxDL++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(gAuxDL++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(15));
                gDPSetEnvColor(gAuxDL++, red, green, blue, 0xFF);
                gSPDisplayList(gAuxDL++, gFovMaskRenderSetupDl);

                temp_f2_3 = (
                    (gDisplayListContext->unk38A10.flat.unk38 * temp_f16) +
                    (gDisplayListContext->unk38A10.flat.unk3C)
                ) / -temp_f16;
                gDPSetPrimDepth(gAuxDL++, (u16)((temp_f2_3 * 1023.0f * 32.0f) + 32736.0f) - D_803F2D50.unk42, 0);

                if (gFogState.min >= (gFogState.max - 1)) {
                    lod = 0;
                } else {
                    temp_v1_2 = gFogState.min << 3;
                    temp_a1_3 = gFogState.max << 3;

                    var_f2 = MIN(8000.0, temp_f2_3 * 7990.0);

                    if (temp_v1_2 >= (s16)var_f2) {
                        lod = 0;
                    } else if ((s16)var_f2 >= temp_a1_3) {
                        lod = 0xFF;
                    } else {
                        lod = ((var_f2 - temp_v1_2) * 255.0) / (temp_a1_3 - temp_v1_2);
                    }
                }

                gDPSetPrimColor(gAuxDL++, 0, lod, gFogState.r, gFogState.g, gFogState.b, 0xFF);

                if (xl < yh) {
                    dsdx_dtdy = (65536.0f / (yh - xl));

                    gSPScisTextureRectangle(
                    /* pkt  */ gAuxDL++,
                    /* xl   */ (s16) xl,
                    /* yl   */ (s16) yl,
                    /* xh   */ (s16) yh,
                    /* yh   */ (s16) xh,
                    /* tile */ G_TX_RENDERTILE,
                    /* t    */  (dsdx_dtdy * ((u16) xl & 3)) >> 9,
                    /* s    */ -(dsdx_dtdy * ((u16) yl & 3)) >> 7,
                    /* dsdx */ dsdx_dtdy,
                    /* dtdy */ dsdx_dtdy);

                    gSPDisplayList(gAuxDL++, D_01003A40_3D310);
                }
            }
            return VISIBILITY_TOO_FAR;
        }

        spF4 = sample_ground_height_at_xz(arg0 >> 0x10, arg1 >> 0x10) / 65536.0;
        temp_f2_4 =
            (gDisplayListContext->unk38A10.flat.unk20 * spFC) +
            (gDisplayListContext->unk38A10.flat.unk24 * spF8) +
            (gDisplayListContext->unk38A10.flat.unk28 * spF4) +
            (gDisplayListContext->unk38A10.flat.unk2C);

        if (temp_f2_4 <= -3.0) {
            temp_f14 =  ((gDisplayListContext->unk38A10.flat.unk30 * sp144) / temp_f2_4) + (0, gScreenWidth * 2);
            temp_f162 = ((gDisplayListContext->unk38A10.flat.unk34 * sp140) / temp_f2_4) + (0, gScreenHeight * 2);
        } else {
            return VISIBILITY_OUT_OF_BOUNDS_X;
        }

        if ((sp12C + sp2C) < 0 && (temp_f14 + sp2C < 0)) {
            // fake
            spF4 = (1 * spF4);
            // end fake
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }
        if ((gScreenWidth * 4 < xl) && (gScreenWidth * 4 < temp_f14 - sp2C)) {
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

    spF4 = sample_ground_height_at_xz(arg0 >> 0x10, arg1 >> 0x10) / 65536.0;
    temp_f2_4 =
        (gDisplayListContext->unk38A10.flat.unk20 * spFC) +
        (gDisplayListContext->unk38A10.flat.unk24 * spF8) +
        (gDisplayListContext->unk38A10.flat.unk28 * spF4) +
        (gDisplayListContext->unk38A10.flat.unk2C);

    if (temp_f2_4 <= -3.0) {
        return VISIBILITY_OUT_OF_BOUNDS_X;
    }
    return VISIBILITY_OUT_OF_BOUNDS_Y;
}

s16 classify_visibility_simple(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
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

    if (is_world_cell_loaded_6AB9E4(arg0 >> 0x10, arg1 >> 0x10, arg2 >> 0x10) == 0) {
        return VISIBILITY_INVISIBLE;
    }

    sp58 = (arg0 >> 0x10) - (s16) gCameraEyeWorldX;
    sp50 = (arg1 >> 0x10) - (s16) gCameraEyeWorldZ;
    sp48 = (arg2 >> 0x10) - (s16) gCameraEyeWorldY;

    fov = (((SQ(sp58) + SQ(sp50) + SQ(sp48)) >> arg4));
    fov = (fov * D_803F2D50.fovY) / 75.0f;

    if ((fov > 1225 * 4096)) { // FTOFIX32(76.5625)
        return VISIBILITY_INVISIBLE;
    }
    if ((fov <= 4096)) { // FTOFIX32(0.0625)
        gLodDetailState = 0;
        return VISIBILITY_VISIBLE;
    }

    sp6C = (arg0 / 65536.0);
    sp68 = (arg1 / 65536.0);
    sp64 = (arg2 / 65536.0);

    temp_f16 =
        (gDisplayListContext->unk38A10.flat.unk20 * sp6C) +
        (gDisplayListContext->unk38A10.flat.unk24 * sp68) +
        (gDisplayListContext->unk38A10.flat.unk28 * sp64) +
        (gDisplayListContext->unk38A10.flat.unk2C);

    if (temp_f16 <= -3.0) {

        tmp1 =
            (gDisplayListContext->unk38A10.flat.unk0 * sp6C) +
            (gDisplayListContext->unk38A10.flat.unk4 * sp68) +
            (gDisplayListContext->unk38A10.flat.unk8 * sp64) +
            (gDisplayListContext->unk38A10.flat.unkC);

        tmp2 =
            (gDisplayListContext->unk38A10.flat.unk10 * sp6C) +
            (gDisplayListContext->unk38A10.flat.unk14 * sp68) +
            (gDisplayListContext->unk38A10.flat.unk18 * sp64) +
            (gDisplayListContext->unk38A10.flat.unk1C);

        // replace (0, 2) with temp var assignment? width/height?
        width =  ((gDisplayListContext->unk38A10.flat.unk30 * tmp1) / temp_f16) + ((0, gScreenWidth * 2));
        height = ((gDisplayListContext->unk38A10.flat.unk34 * tmp2) / temp_f16) + ((0, gScreenHeight * 2));

        arg3 = (arg3 * 33) / D_803F2D50.fovY;
        temp_f0 = (arg3 * 128 / (-temp_f16)) / 8.0;

        if ((gScreenHeight * 4) < (height - temp_f0)) {
            return VISIBILITY_OUT_OF_BOUNDS_Y;
        }

        if (((gScreenWidth * 4) > (width - temp_f0)) &&
            ((height + temp_f0) > 0.0f) &&
            ((width + temp_f0) > 0.0f)) {

            if (fov < 225 * 4096) {
                if ((fov < 49 * 4096)) {
                    gLodDetailState = 0;
                } else {
                    gLodDetailState = 1;
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

s16 classify_particle_visibility_6FB6B4(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
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

    sp68 = (arg0 >> 0x10) - (s16) gCameraEyeWorldX;
    sp60 = (arg1 >> 0x10) - (s16) gCameraEyeWorldZ;
    sp58 = (arg2 >> 0x10) - (s16) gCameraEyeWorldY;

    sp60 = ((SQ(sp68) + SQ(sp60) + SQ(sp58)) >> arg3);
    fov = (sp60 * D_803F2D50.fovY) / 75.0f;
    if ((s64)fov > 0xE1000) {
        return VISIBILITY_TOO_FAR;
    }

    temp_f2 = arg0 / 65536.0;
    temp_f12 = arg1 / 65536.0;
    temp_f14 = arg2 / 65536.0;

    sp74 =
        (gDisplayListContext->unk38A10.flat.unk20 * temp_f2) +
        (gDisplayListContext->unk38A10.flat.unk24 * temp_f12) +
        (gDisplayListContext->unk38A10.flat.unk28 * temp_f14) +
        (gDisplayListContext->unk38A10.flat.unk2C           );

    if (sp74 <= -3.0) {

        sp7C =
            (gDisplayListContext->unk38A10.flat.unk0 * temp_f2) +
            (gDisplayListContext->unk38A10.flat.unk4 * temp_f12) +
            (gDisplayListContext->unk38A10.flat.unk8 * temp_f14) +
            (gDisplayListContext->unk38A10.flat.unkC           );

        sp78 =
            (gDisplayListContext->unk38A10.flat.unk10 * temp_f2) +
            (gDisplayListContext->unk38A10.flat.unk14 * temp_f12) +
            (gDisplayListContext->unk38A10.flat.unk18 * temp_f14) +
            (gDisplayListContext->unk38A10.flat.unk1C           );

        sp88 = ((gDisplayListContext->unk38A10.flat.unk30 * sp7C) / sp74) + (gScreenWidth *  ((0, 2)));
        sp80 = ((gDisplayListContext->unk38A10.flat.unk34 * sp78) / sp74) + (gScreenHeight * ((0, 2)));

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
