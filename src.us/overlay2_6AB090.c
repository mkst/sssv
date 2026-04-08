#include <ultra64.h>

#include "common.h"

// ========================================================
// .data
// ========================================================

s16 D_803A0500_7B1BB0 = 0;

// ========================================================
// .bss
// ========================================================

GfxHelper gVisibleWorldCellQueue[28];

// ========================================================
// .text
// ========================================================

void setup_world_perspective_6AB090(DisplayList *arg0) {
    guPerspective(&arg0->unk37410, &gWorldPerspNorm, D_803F2D50.fovY, 1.0f, D_803F2D50.unkC, D_803F2D50.unkE, 1.0f);
    guScale(&arg0->unk37450, 0.5f, 0.5f, 0.5f);
    guScale(&arg0->unk374D0, 1.0f, 1.0f, 1.0f);
    update_world_camera_transform();
}

void setup_frame_render_state(DisplayList *arg0, Gfx **arg1) {
    gSPMatrix((*arg1)++, &arg0->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPPerspNormalize((*arg1)++, gWorldPerspNorm);
}

void draw_visible_world_cell_opaque_pass(DisplayList *arg0) {
    gDPSetTextureImage(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 16, &gWaterTextureBuffer[(gWaterAnimState.unk20C >> 1) << 9]);
    gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0180, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMainDL++);
    gDPLoadTile(gMainDL++, G_TX_LOADTILE, 0, 0, 4*(15.5), 4*(31));
    gDPPipeSync(gMainDL++);
    gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMainDL++, 6, 0, 0, 4*(31), 4*(31));

    gDPSetTextureImage(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 8, D_01021BB0_5B480);
    gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x01C0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
    gDPLoadSync(gMainDL++);
    gDPLoadTile(gMainDL++, G_TX_LOADTILE, 0, 0, 4*(7.5), 4*(15));
    gDPPipeSync(gMainDL++);
    gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
    gDPSetTileSize(gMainDL++, 5, 0, 0, 4*(15), 4*(15));

    gSPDisplayList(gMainDL++, D_010043A0_3DC70);

    build_visible_world_cell_queue(gCameras[gCameraId].unk74, gCameras[gCameraId].unk78, gCameras[gCameraId].unk7C);

    for (D_803A0500_7B1BB0 = 0; gVisibleWorldCellQueue[D_803A0500_7B1BB0].start != 99; D_803A0500_7B1BB0++) {
        gSPDisplayList(gMainDL++, gWorldCellOpaqueDisplayLists[gVisibleWorldCellQueue[D_803A0500_7B1BB0].start][gVisibleWorldCellQueue[D_803A0500_7B1BB0].end]);
    }

    gDPSetTextureLOD(gMainDL++, G_TL_TILE);
}

void draw_visible_world_cell_translucent_pass(DisplayList *arg0) {
    s32 pad2[2];
    s32 i;
    s32 j;
    GfxHelper old;
    s32 pad;

    if ((D_803F2D18 > 10) && (gUiFlowState.unk0 == 2)) {
        // debug?
    } else {
        for (i = 0; i < D_803A0500_7B1BB0 - 1; i++) {
            for (j = 0; j < D_803A0500_7B1BB0 - 1; j++) {
                if (gVisibleWorldCellQueue[j].position < gVisibleWorldCellQueue[j+1].position) {
                    old = gVisibleWorldCellQueue[j];
                    gVisibleWorldCellQueue[j] = gVisibleWorldCellQueue[j+1];
                    gVisibleWorldCellQueue[j+1] = old;
                }
            }
        }

        gVisibleWorldCellQueue[D_803A0500_7B1BB0].start = 99;

        gDPSetTextureImage(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 16, &gWaterTextureBuffer[(gWaterAnimState.unk20C >> 1) << 9]);

        gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x015E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPLoadSync(gMainDL++);
        gDPLoadTile(gMainDL++, G_TX_LOADTILE, 0, 0, 4*(15.5), 4*(31));
        gDPPipeSync(gMainDL++);
        gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPSetTileSize(gMainDL++, 1, 0, 0, 4*(31), 4*(31));

        gDPSetTextureImage(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 8, D_01021BB0_5B480);

        gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x01D7, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
        gDPLoadSync(gMainDL++);

        gDPLoadTile(gMainDL++, G_TX_LOADTILE, 0, 0, 4*(7.5), 4*(15));
        gDPPipeSync(gMainDL++);
        gDPSetTile(gMainDL++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01D7, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
        gDPSetTileSize(gMainDL++, 5, 0, 0, 4*(15), 4*(15));
        gDPSetEnvColor(gMainDL++, 0x00, 0x00, 0x80, 0x00);
        gDPSetPrimColor(gMainDL++, 0, 128, 128, 160, 190, 200);

        gSPDisplayList(gMainDL++, D_01004458_3DD28);

        gDPSetColorDither(gMainDL++, G_CD_DISABLE);
        gDPSetAlphaDither(gMainDL++, G_AD_PATTERN);
        gDPSetAlphaCompare(gMainDL++, G_AC_NONE);

        for (D_803A0500_7B1BB0 = 0; gVisibleWorldCellQueue[D_803A0500_7B1BB0].start != 99; D_803A0500_7B1BB0++) {
            if (gWorldCellTranslucentEnabled[gVisibleWorldCellQueue[D_803A0500_7B1BB0].start][gVisibleWorldCellQueue[D_803A0500_7B1BB0].end] == 1) {
                gSPDisplayList(gMainDL++, gWorldCellTranslucentDisplayLists[gVisibleWorldCellQueue[D_803A0500_7B1BB0].start][gVisibleWorldCellQueue[D_803A0500_7B1BB0].end]);
            }
        }
    }

    gDPSetColorDither(gMainDL++, G_CD_BAYER);
    gDPSetAlphaDither(gMainDL++, G_AD_PATTERN);
    gDPSetTextureLOD(gMainDL++, G_TL_TILE);

}

void func_8029A32C_6AB9DC(s32 arg0) {
}

s16 is_world_cell_loaded_6AB9E4(s32 arg0, s32 arg1, s32 arg2) {
    arg0 >>= 6;
    arg1 >>= 6;
    arg0 = (arg0 - 4) >> 4;
    arg1 = (arg1 - 8) >> 4;
    if ((arg0 < 0) || (arg0 >= 4) || (arg1 < 0) || (arg1 >= 6)) {
        return 1;
    }
    if (gCameraVisibilityMask[arg1] & (1 << arg0)) {
        return 1;
    }
    return 0;
}

void build_visible_world_cell_queue(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad;
    s32 i;
    s32 j;
    s32 temp_a1;
    s32 temp_t0;
    GfxHelper old;

    D_803A0500_7B1BB0 = 0;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            if (gCameraVisibilityMask[i] & (1 << j)) {
                temp_a1 = arg0 - (((j * 16) + 12) << 6);
                temp_t0 = arg1 - (((i * 16) + 16) << 6);
                gVisibleWorldCellQueue[D_803A0500_7B1BB0].start = j;
                gVisibleWorldCellQueue[D_803A0500_7B1BB0].end = i;
                gVisibleWorldCellQueue[D_803A0500_7B1BB0].position = (((temp_a1 * temp_a1) + (temp_t0 * temp_t0)) / 64);
                D_803A0500_7B1BB0 += 1;
            }
        }
    }

    for (i = 0; i < D_803A0500_7B1BB0 - 1; i++) {
        for (j = 0; j < D_803A0500_7B1BB0 - 1; j++) {
            if (gVisibleWorldCellQueue[j+1].position < gVisibleWorldCellQueue[j].position) {
                old = gVisibleWorldCellQueue[j];
                gVisibleWorldCellQueue[j] = gVisibleWorldCellQueue[j+1];
                gVisibleWorldCellQueue[j+1] = old;
            }
        }
    }
    gVisibleWorldCellQueue[D_803A0500_7B1BB0].start = 99;
}

// get mid color of image?
u16 func_8029A52C_6ABBDC(u8 arg0) {
    s16 *img;
    u16 tmp = arg0 & 0x3F;

    // list of 32x32 mipmap images (0xAB8 each)
    img = (s16*)(D_800BA760 + ((tmp + 1) * 0xAB8));
    tmp = img[-4];

    return tmp;
}

u16 func_8029A568_6ABC18(s16 arg0) {
    u16 r;
    u16 g;
    u16 b;

    // rgba 5/5/5/1 to 25% intensity
    // rrrrrgggggbbbbba => __rrr__ggg__bbb_
    // 0000000000111110 => 0000000000001110
    // 0000011111000000 => 0000000111000000
    // 1111100000000000 => 0011100000000000

    b =  ((arg0 & 0x003E) >> 2)         & 0x003E;
    g = (((arg0 & 0x07C0) >> 7) << 5)   & 0x07C0;
    r = (((arg0 & 0xF800) >> 12) << 10) & 0xF800;

    return (b | g | r);
}

void set_fog_factor_and_color(Gfx **dl, u8 r, u8 g, u8 b) {
    gSPFogFactor((*dl)++, 0xBC00F400, 0xF4000D00);
    gDPSetFogColor((*dl)++, r, g, b, 0);
}

void set_fog_position_and_color(Gfx **dl) {
    gSPFogPosition((*dl)++, gFogState.min, gFogState.max);
    gDPSetFogColor((*dl)++, gFogState.r, gFogState.g, gFogState.b, 0x00);
}

void render_ship_window_projection_replay(void) {
    if (gCameraVisibilityMask[6] & 1) {
        func_80127D30(&gDisplayListContext->unk37510, (gCameraVisibilityMask[6] & 0xFFC) << 1);

        gSPMatrix(gMainDL++, &gDisplayListContext->unk37510, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPDisplayList(gMainDL++, &gDisplayListContext->gXluDL);
        gSPDisplayList(gMainDL++, &gDisplayListContext->gOpaqueDL);
        gSPPopMatrix(gMainDL++, G_MTX_MODELVIEW);

        gSPMatrix(gMainDL++, &gDisplayListContext->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37450, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37490, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    } else if (gCameraVisibilityMask[6] & 2) {
        func_80127ED4(&gDisplayListContext->unk37510, (gCameraVisibilityMask[6] & 0xFFC) << 1);

        gDisplayListContext->unk3B6B0.l.col[0]  = gDisplayListContext->lights.a.l.col[0] >> 1;
        gDisplayListContext->unk3B6B0.l.col[1]  = gDisplayListContext->lights.a.l.col[1] >> 1;
        gDisplayListContext->unk3B6B0.l.col[2]  = gDisplayListContext->lights.a.l.col[2] >> 1;
        gDisplayListContext->unk3B6B0.l.colc[0] = gDisplayListContext->lights.a.l.colc[0] >> 1;
        gDisplayListContext->unk3B6B0.l.colc[1] = gDisplayListContext->lights.a.l.colc[1] >> 1;
        gDisplayListContext->unk3B6B0.l.colc[2] = gDisplayListContext->lights.a.l.colc[2] >> 1;

        gDisplayListContext->unk3B6B8.l.col[0]  = gDisplayListContext->lights.l[0].l.col[0] >> 2;
        gDisplayListContext->unk3B6B8.l.col[1]  = gDisplayListContext->lights.l[0].l.col[1] >> 2;
        gDisplayListContext->unk3B6B8.l.col[2]  = gDisplayListContext->lights.l[0].l.col[2] >> 2;
        gDisplayListContext->unk3B6B8.l.colc[0] = gDisplayListContext->lights.l[0].l.col[0] >> 2;
        gDisplayListContext->unk3B6B8.l.colc[1] = gDisplayListContext->lights.l[0].l.col[1] >> 2;
        gDisplayListContext->unk3B6B8.l.colc[2] = gDisplayListContext->lights.l[0].l.col[2] >> 2;

        gDisplayListContext->unk3B6B8.l.dir[0] = gDisplayListContext->lights.l[0].l.dir[0];
        gDisplayListContext->unk3B6B8.l.dir[1] = gDisplayListContext->lights.l[0].l.dir[1];
        gDisplayListContext->unk3B6B8.l.dir[2] = gDisplayListContext->lights.l[0].l.dir[2];

        gSPNumLights(gMainDL++, 1);
        gSPLight(gMainDL++, &gDisplayListContext->unk3B6B8, 1);
        gSPLight(gMainDL++, &gDisplayListContext->unk3B6B0, 2);

        gSPMatrix(gMainDL++, &gDisplayListContext->unk37510, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPDisplayList(gMainDL++, &gDisplayListContext->gOpaqueDL);

        gSPNumLights(gMainDL++, 1);
        gSPLight(gMainDL++, &gDisplayListContext->lights.l, 1);
        gSPLight(gMainDL++, &gDisplayListContext->lights.a, 2);

        gSPPopMatrix(gMainDL++, G_MTX_MODELVIEW);

        gSPMatrix(gMainDL++, &gDisplayListContext->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37450, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(gMainDL++, &gDisplayListContext->unk37490, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    }
}

void func_8029ABCC_6AC27C(void) {
    build_rotate_scale_translate_matrix(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], FTOFIX32(256.0), FTOFIX32(512.0), FTOFIX32(1400.0), 0, 0, 0, FTOFIX32(2.0), FTOFIX32(2.0), FTOFIX32(2.0));
    gSPMatrix(gMainDL++, &gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}
