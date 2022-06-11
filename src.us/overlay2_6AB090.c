#include <ultra64.h>

#include "common.h"

// .data
s16 D_803A0500_7B1BB0 = 0;

void func_802999E0_6AB090(DisplayList *arg0) {
    guPerspective(&arg0->unk37410, &D_803C0658, D_803F2D50.unkE0, 1.0f, D_803F2D50.unkC, D_803F2D50.unkE, 1.0f);
    guScale(&arg0->unk37450, 0.5f, 0.5f, 0.5f);
    guScale(&arg0->unk374D0, 1.0f, 1.0f, 1.0f);
    func_8033F380_750A30();
}

void func_80299AA8_6AB158(DisplayList *arg0, Gfx **arg1) {
    gSPMatrix((*arg1)++, &arg0->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37450, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk37490, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
    gSPMatrix((*arg1)++, &arg0->unk374D0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPPerspNormalize((*arg1)++, D_803C0658);
}

void func_80299B68_6AB218(s32 arg0) {
    gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 16, &D_800DCC20[D_803C063C >> 1]);
    gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0180, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E7C++);
    gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(15.5), 4*(31));
    gDPPipeSync(D_801D9E7C++);
    gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E7C++, 6, 0, 0, 4*(31), 4*(31));

    gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 8, D_01021BB0);
    gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x01C0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
    gDPLoadSync(D_801D9E7C++);
    gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(7.5), 4*(15));
    gDPPipeSync(D_801D9E7C++);
    gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E7C++, 5, 0, 0, 4*(15), 4*(15));

    gSPDisplayList(D_801D9E7C++, D_010043A0_3DC70);

    func_8029A3B0_6ABA60(D_803F28E0[D_803F2A98].unk74, D_803F28E0[D_803F2A98].unk78, D_803F28E0[D_803F2A98].unk7C);

    for (D_803A0500_7B1BB0 = 0; D_803C0660[D_803A0500_7B1BB0].min != 99; D_803A0500_7B1BB0++) {
        gSPDisplayList(D_801D9E7C++, D_80205410[D_803C0660[D_803A0500_7B1BB0].min][D_803C0660[D_803A0500_7B1BB0].max]);
    }

    gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
}

void func_80299E84_6AB534(s32 arg0) {
    s32 pad2[2];
    s32 i;
    s32 j;
    Fog2 old;
    s32 pad;

    if ((D_803F2D18 > 10) && (D_803F2D10.unk0 == 2)) {
        // debug?
    } else {
        for (i = 0; i < D_803A0500_7B1BB0 - 1; i++) {
            for (j = 0; j < D_803A0500_7B1BB0 - 1; j++) {
                if (D_803C0660[j].position < D_803C0660[j+1].position) {
                    old = D_803C0660[j];
                    D_803C0660[j] = D_803C0660[j+1];
                    D_803C0660[j+1] = old;
                }
            }
        }

        D_803C0660[D_803A0500_7B1BB0].min = 99;

        gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 16, &D_800DCC20[D_803C063C >> 1]);

        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x015E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPLoadSync(D_801D9E7C++);
        gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(15.5), 4*(31));
        gDPPipeSync(D_801D9E7C++);
        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E7C++, 1, 0, 0, 4*(31), 4*(31));

        gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 8, D_01021BB0);

        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_8b, 1, 0x01D7, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
        gDPLoadSync(D_801D9E7C++);

        gDPLoadTile(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 4*(7.5), 4*(15));
        gDPPipeSync(D_801D9E7C++);
        gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01D7, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E7C++, 5, 0, 0, 4*(15), 4*(15));
        gDPSetEnvColor(D_801D9E7C++, 0x00, 0x00, 0x80, 0x00);
        gDPSetPrimColor(D_801D9E7C++, 0, 128, 128, 160, 190, 200);

        gSPDisplayList(D_801D9E7C++, D_01004458);

        gDPSetColorDither(D_801D9E7C++, G_CD_DISABLE);
        gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
        gDPSetAlphaCompare(D_801D9E7C++, G_AC_NONE);

        for (D_803A0500_7B1BB0 = 0; D_803C0660[D_803A0500_7B1BB0].min != 99; D_803A0500_7B1BB0++) {
            if (D_803F2CA8[D_803C0660[D_803A0500_7B1BB0].min][D_803C0660[D_803A0500_7B1BB0].max] == 1) {
                gSPDisplayList(D_801D9E7C++, D_802255F0[D_803C0660[D_803A0500_7B1BB0].min][D_803C0660[D_803A0500_7B1BB0].max]);
            }
        }
    }

    gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
    gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
    gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);

}

void func_8029A32C_6AB9DC(s32 arg0) {
}

s32 func_8029A334_6AB9E4(s32 arg0, s32 arg1, s32 arg2) {
    arg0 >>= 6;
    arg1 >>= 6;
    arg0 = (arg0 - 4) >> 4;
    arg1 = (arg1 - 8) >> 4;
    if ((arg0 < 0) || (arg0 >= 4) || (arg1 < 0) || (arg1 >= 6)) {
        return 1;
    }
    if (D_803F28D0[arg1] & (1 << arg0)) {
        return 1;
    }
    return 0;
}

void func_8029A3B0_6ABA60(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad;
    s32 i;
    s32 j;
    s32 temp_a1;
    s32 temp_t0;
    Fog2 old;

    D_803A0500_7B1BB0 = 0;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            if (D_803F28D0[i] & (1 << j)) {
                temp_a1 = arg0 - (((j * 16) + 12) << 6);
                temp_t0 = arg1 - (((i * 16) + 16) << 6);
                D_803C0660[D_803A0500_7B1BB0].min = j;
                D_803C0660[D_803A0500_7B1BB0].max = i;
                D_803C0660[D_803A0500_7B1BB0].position = (((temp_a1 * temp_a1) + (temp_t0 * temp_t0)) / 64);
                D_803A0500_7B1BB0 += 1;
            }
        }
    }

    for (i = 0; i < D_803A0500_7B1BB0 - 1; i++) {
        for (j = 0; j < D_803A0500_7B1BB0 - 1; j++) {
            if (D_803C0660[j+1].position < D_803C0660[j].position) {
                old = D_803C0660[j];
                D_803C0660[j] = D_803C0660[j+1];
                D_803C0660[j+1] = old;
            }
        }
    }
    D_803C0660[D_803A0500_7B1BB0].min = 99;
}

u16 func_8029A52C_6ABBDC(u8 arg0) {
    struct038 *s;
    u16 tmp = arg0 & 0x3F;

    s = &D_800BB210[tmp];
    tmp = s->unk0;
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

    return b | g | r;
}

void set_fog_factor_and_color(Gfx **dl, u8 r, u8 g, u8 b) {
    gSPFogFactor((*dl)++, 0xBC00F400, 0xF4000D00);
    gDPSetFogColor((*dl)++, r, g, b, 0);
}

void set_fog_position_and_color(Gfx **dl) {
    gSPFogPosition((*dl)++, D_803E1CF8.min, D_803E1CF8.max);
    gDPSetFogColor((*dl)++, D_803E1CF8.r, D_803E1CF8.g, D_803E1CF8.b, 0x00);
}

void func_8029A720_6ABDD0(void) {
    if (D_803F28DC & 1) {
        func_80127D30(&D_80204278->unk37510, (D_803F28DC & 0xFFC) << 1);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37510, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unkBB80);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unk9600);
        gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37450, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37490, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    } else if (D_803F28DC & 2) {
        func_80127ED4(&D_80204278->unk37510, (D_803F28DC & 0xFFC) << 1);

        D_80204278->unk3B6B0.l.col[0]  = D_80204278->unk3B638.l.col[0] >> 1;
        D_80204278->unk3B6B0.l.col[1]  = D_80204278->unk3B638.l.col[1] >> 1;
        D_80204278->unk3B6B0.l.col[2]  = D_80204278->unk3B638.l.col[2] >> 1;
        D_80204278->unk3B6B0.l.colc[0] = D_80204278->unk3B638.l.colc[0] >> 1;
        D_80204278->unk3B6B0.l.colc[1] = D_80204278->unk3B638.l.colc[1] >> 1;
        D_80204278->unk3B6B0.l.colc[2] = D_80204278->unk3B638.l.colc[2] >> 1;

        D_80204278->unk3B6B8.l.col[0]  = D_80204278->unk3B640[0].l.col[0] >> 2;
        D_80204278->unk3B6B8.l.col[1]  = D_80204278->unk3B640[0].l.col[1] >> 2;
        D_80204278->unk3B6B8.l.col[2]  = D_80204278->unk3B640[0].l.col[2] >> 2;
        D_80204278->unk3B6B8.l.colc[0] = D_80204278->unk3B640[0].l.col[0] >> 2;
        D_80204278->unk3B6B8.l.colc[1] = D_80204278->unk3B640[0].l.col[1] >> 2;
        D_80204278->unk3B6B8.l.colc[2] = D_80204278->unk3B640[0].l.col[2] >> 2;

        D_80204278->unk3B6B8.l.dir[0] = D_80204278->unk3B640[0].l.dir[0];
        D_80204278->unk3B6B8.l.dir[1] = D_80204278->unk3B640[0].l.dir[1];
        D_80204278->unk3B6B8.l.dir[2] = D_80204278->unk3B640[0].l.dir[2];

        gSPNumLights(D_801D9E7C++, 1);
        gSPLight(D_801D9E7C++, &D_80204278->unk3B6B8, 1);
        gSPLight(D_801D9E7C++, &D_80204278->unk3B6B0, 2);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37510, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPDisplayList(D_801D9E7C++, &D_80204278->unk9600);

        gSPNumLights(D_801D9E7C++, 1);
        gSPLight(D_801D9E7C++, &D_80204278->unk3B640, 1);
        gSPLight(D_801D9E7C++, &D_80204278->unk3B638, 2);

        gSPPopMatrix(D_801D9E7C++, G_MTX_MODELVIEW);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37410, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37450, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37490, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    }
}

void func_8029ABCC_6AC27C(void) {
    func_80125980(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0x1000000, 0x2000000, 0x5780000, 0, 0, 0, 0x20000, 0x20000, 0x20000);
    gSPMatrix(D_801D9E7C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;
}
