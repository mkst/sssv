#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

s32 func_802983D0_6A9A80(void);

// ========================================================
// .bss
// ========================================================

// FIXME: if these are defined in overlay2_6A6500 then it results in codegen changes
s64  gRenderMode1;
s64  gRenderMode2;
s64  gGeometryMode;
u16  gWorldPerspNorm; // matrix normalise

// ========================================================
// .text
// ========================================================

#ifdef NON_MATCHING
// CURRENT (75)
void func_802963D0_6A7A80(FrameContext *arg0) {
    s16 i;
    s16 j;
    s16 k;

    s32 x;
    s32 y;

    s16 width;
    s16 height;

    s16 width2;

    int new_var;

    gWaterAnimState.unk20A = 8;

    x = D_803F2D50.unk10;
    y = D_803F2D50.unk12;
    width = D_803F2D50.unk14;
    height = D_803F2D50.unk16;

    if (width == 0 || height == 0) {
        return;
    }

    width2 = width + 1;

    for (i = 0; i < 2; i++) { // double-buffer

        if (width) {};
        if (width) {};
        if (width) {};

        for (j = 0; j < (width + 1); j++) { // x-direction

            for (k = 0; k < height; k++) { // y-direction
                Vtx *v = &arg0[i].dl.unk286E0[((k * width2) + j)];

                v->v.ob[0] = ((j + x) << 6);
                v->v.ob[1] = ((k + y) << 6);

                new_var = 0;

                v->v.tc[0] = (j << 6) << 3;
                v->v.tc[1] = (k << 6) << 3;

                v->v.cn[0] = 0;
                v->v.cn[1] = 0;
                v->v.cn[2] = 0x7F;
                v->v.cn[3] = 0x80;
            }
        }
        k = new_var;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802963D0_6A7A80.s")
#endif

void func_80296544_6A7BF4(void) {
    f64 temp_f20;
    f64 temp_f22;
    f64 temp_f24;

    u8 i;

    gWaterAnimState.unk202 = 0;
    gWaterAnimState.unk204 = 0;

    if (D_803F2D50.unk22 == 0) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 1;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 3;
        }
    }
    if ((D_803F2D50.unk22 == 1) || (D_803F2D50.unk22 == 2)) {
        temp_f20 = SSSV_PI / 180;
        temp_f22 = 360.0 / 64;
        temp_f24 = 11.612;
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[0][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[1][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[2][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[3][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 3;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[4][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 7;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[5][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 2;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[6][i] = cosf(temp_f20 * (f32)(i * temp_f22)) * 8;
        }
        for (i = 0; i < 64; i++) {
            gWaterAnimState.unk0[7][i] = cosf(temp_f20 * (f32)(i * temp_f24)) * 4;
        }
    }
}

#ifdef NON_MATCHING
// CURRENT (2259)
void func_80296C8C_6A833C(struct063 arg0[73][129]) {
    s16 xPos;
    s16 zPos;
    s16 curWater;
    s16 nextWater;
    s16 temp_a0;
    s16 temp_s4;
    s16 delta;

    u32 Start1;
    u32 Start2;
    u32 End1;
    u32 End2;

    s32 pad;
    s32 rand;
    s32 six;

    six = 6;

    Start1 = D_803F2D50.unk12;
    End1 = D_803F2D50.unk12 + D_803F2D50.unk16;

    Start2 = D_803F2D50.unk10;
    End2 = D_803F2D50.unk10 + D_803F2D50.unk14;

    gWaterAnimState.unk20D = (gWaterAnimState.unk20D + 1) & 3;

    for (xPos = End2; xPos > Start2; xPos--) {
        for (zPos = End1; zPos > Start1; zPos--) {
            arg0[xPos][zPos].unk7 = 0; // clear terrain flags?

            if (arg0[xPos][zPos].unk6 != 0) {
                curWater = arg0[xPos][zPos].unk6;
                nextWater = arg0[xPos+1][zPos].unk6; //.unk40E; (408 + 6)
                if (SSSV_RAND(128) == 20) {
                    func_802D7AD4_6E9184(
                        (SSSV_RAND(64) + (xPos << 6)),
                        (SSSV_RAND(64) + (s16)(zPos << 6)),
                        D_803C0740[xPos][zPos].unk0 << 3,
                        0);
                }
                if (nextWater < curWater) {
                    delta = arg0[xPos+1][zPos].unk0; //unk408; (408 + 0)
                    if ((delta << 1) < curWater) {
                        if ((nextWater == 0) && (gWaterAnimState.unk20F == 0)) {
                            nextWater = (delta << 1);
                        }
                        if ((delta < (arg0[xPos][zPos].unk0 - 0x10)) && (nextWater < (arg0[xPos][zPos].unk0 << 1))) {
                            delta = 0;
                        } else {
                            delta = (curWater - nextWater) / 2;
                            if (delta > 1) {
                                delta += SSSV_RAND(2);
                            }
                        }
                        if (delta < 0) {
                            delta = 0;
                        }
                        curWater = curWater - delta;
                        nextWater = nextWater + delta;
                        arg0[xPos][zPos].unk7 = (s16)(arg0[xPos][zPos].unk7 & 0xF) + ((delta & 7) << 4);

                        if ((arg0[xPos][zPos].unk0 << 1) >= curWater) {
                            curWater = 0;
                        }
                        if ((arg0[xPos+1][zPos].unk6 == 0) && (nextWater != 0)) { // unk40E (408 + 6)
                            arg0[xPos+1][zPos].unk4 |= 2; // unk40C (408 + 4)
                        } else {
                            arg0[xPos+1][zPos].unk4 &= ~2; // unk40C (408 + 4)
                        }
                        if ((arg0[xPos][zPos].unk6 != 0) && (curWater == 0)) {
                            arg0[xPos][zPos].unk4 |= 4;
                        } else {
                            arg0[xPos][zPos].unk4 &= ~4;
                        }
                        arg0[xPos][zPos].unk6 = curWater;
                        arg0[xPos+1][zPos].unk6 = nextWater; // unk40E
                    }
                }

                curWater = arg0[xPos][zPos].unk6;
                nextWater = arg0[xPos][zPos+1].unk6; // unkE
                if (nextWater < curWater) {
                    delta = arg0[xPos][zPos+1].unk0; // unk8
                    if (((delta + 1) << 1) < curWater) {
                        if ((nextWater == 0) && (gWaterAnimState.unk20F == 0)) {
                            nextWater = (delta << 1);
                        }
                        if ((delta < arg0[xPos][zPos].unk0) && (nextWater < (arg0[xPos][zPos].unk0 << 1))) {
                            delta = (curWater - (arg0[xPos][zPos].unk0 << 1));
                        } else {
                            delta = (curWater - nextWater) / 2;
                            if (delta > 1) {
                                delta += SSSV_RAND(2);
                            }
                        }
                        if (delta <= 0) {
                            delta = 0;
                        }
                        curWater = curWater - delta;
                        nextWater = nextWater + delta;
                        arg0[xPos][zPos].unk7 = (arg0[xPos][zPos].unk7 & 0xF0) + (delta & 7);
                        if (curWater <= (arg0[xPos][zPos].unk0 << 1)) {
                            curWater = 0;
                        }
                        arg0[xPos][zPos+1].unk6 = nextWater; // unkE
                        arg0[xPos][zPos].unk6 = curWater;
                    }
                }

                if (((guRandom() % 31) == 4)) {

                    rand = guRandom();
                    temp_s4 = (xPos << 6) + (rand % 63);
                    rand = guRandom();
                    temp_a0 = (zPos << 6) + (rand % 63);

                    if (((1 - (((D_803C0740[temp_s4 >> six][temp_a0 >> 6].unk7 >> 4) & 8) >> 2)) * (((D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7 & 0xF0) >> 4) & 7)) ||
                        ((1 - (((D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7     ) & 8) >> 2)) * (  D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7               & 7))) {

                        create_particle_effect(
                            temp_s4,
                            temp_a0,
                            0,
                            13,
                            (s16)((1 - (((D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7 >> 4) & 8) >> 2)) * (((D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7 & 0xF0) >> 4) & 7)) << 0x10,
                            (s16)((1 - (((D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7     ) & 8) >> 2)) * (  D_803C0740[temp_s4 >> 6][temp_a0 >> 6].unk7               & 7)) << 0x10,
                            0,
                            SSSV_RAND(4) + 4,
                            0,
                            0,
                            0);
                    }
                }
            }
            if ((arg0[xPos][zPos].unk0 * 2) >= arg0[xPos][zPos].unk6) {
                arg0[xPos][zPos].unk6 = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80296C8C_6A833C.s")
#endif

#ifdef NON_MATCHING
// update_water_level
// 460
void func_8029726C_6A891C(struct063 arg0[73][129]) {
    s16 xPos;
    s16 zPos;

    s16 delta;

    s16 curWater;
    s16 prevWater;

    s16 var_s5;
    s32 pad;
    s32 new_var;
    struct005 sp4C;

    sp4C.Start2 = D_803F2D50.unk10;
    sp4C.End2 = D_803F2D50.unk10 + D_803F2D50.unk14;

    sp4C.Start1 = D_803F2D50.unk12;
    sp4C.End1 = D_803F2D50.unk12 + D_803F2D50.unk16;

    if (gWaterAnimState.unk20F == (gWaterAnimState.unk20F == 0)) {
        // maybe
    };
    curWater = arg0[sp4C.Start2][zPos].unk0;
    if (curWater && curWater) {
        // ??
    };

    var_s5 = 0;

    for (xPos = sp4C.Start2; xPos < sp4C.End2; xPos++) {
        for (zPos = sp4C.Start1; zPos <= sp4C.End1; zPos++) {

            if (((((((arg0[xPos][zPos].unk6 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) == 0)
                continue;

            curWater = arg0[xPos][zPos].unk6;
            prevWater = arg0[xPos - 1][zPos].unk6;
            if (prevWater < curWater) {
                // adjust water level
                if ((arg0[xPos - 1][zPos].unk0 * 2) < curWater) {
                    if ((prevWater == 0) && (gWaterAnimState.unk20F == 0)) {
                        prevWater = (arg0[xPos - 1][zPos].unk0 * 2);
                    }

                    new_var = arg0[xPos - 1][zPos].unk0;
                    if (((arg0[xPos][zPos].unk0 - 16) > new_var) &&
                        (prevWater < (arg0[xPos][zPos].unk0 * 2))) {

                        delta = (curWater - (arg0[xPos][zPos].unk0 * 2)) / 2;
                        if (delta < 1) {
                            delta = 0;
                        }
                    } else {
                        delta = ((curWater - prevWater) + (xPos & 1)) / 2;
                        if (delta > 1) {
                            delta += SSSV_RAND(2);
                        }
                    }

                    curWater  -= delta;
                    prevWater += delta;

                    // 1xxx____
                    arg0[xPos][zPos].unk7 = (((s16)(arg0[xPos][zPos].unk7 & 0xFF) & 0xF) + ((delta & 7) << 4)) | 0x80;

                    if (curWater <= (arg0[xPos][zPos].unk0 * 2)) {
                        curWater = 0;
                    }
                    arg0[xPos][zPos].unk6 = curWater;
                    arg0[xPos - 1][zPos].unk6 = prevWater;
                }
            }

            curWater = arg0[xPos][zPos].unk6;
            prevWater = arg0[xPos][zPos - 1].unk6;
            if (prevWater < curWater) {
                // adjust water level
                if ((arg0[xPos][zPos - 1].unk0 * 2) < curWater) {
                    if ((prevWater == 0) && (gWaterAnimState.unk20F == 0)) {
                        prevWater = (arg0[xPos][zPos - 1].unk0 * 2);
                    }

                    new_var = arg0[xPos][zPos].unk0;
                    if (((arg0[xPos][zPos - 1].unk0 + 4) < new_var) &&
                        (prevWater <= (arg0[xPos][zPos].unk0 * 2))) {
                        delta = (s64)((curWater - (arg0[xPos][zPos].unk0 * 2)) / 2); // fake
                        delta = MAX(2, delta);
                        var_s5++;

                        curWater -= delta;
                        delta = 0;
                    } else {
                        delta = ((curWater + (zPos & 1)) - prevWater) / 2;
                        if (delta > 1) {
                            delta += SSSV_RAND(2);
                        }
                    }
                    delta = MAX(0, delta);

                    curWater  -= delta;
                    prevWater += delta;

                    // ____1xxx
                    // arg0[xPos][zPos].unk7 = (((s16)(arg0[xPos][zPos].unk7 & 0xFF) & 0xF0) + (delta & 7)) | 8;
                    arg0[xPos][zPos].unk7 = (((((((((((((s16) ((arg0[xPos][zPos]).unk7 & 0xFF)) & 0xF0) + (delta & 7)) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) | 8;

                    if (curWater <= (arg0[xPos][zPos].unk0 * 2)) {
                        curWater = 0;
                    }

                    arg0[xPos][zPos].unk6 = curWater;
                    arg0[xPos][zPos - 1].unk6 = prevWater;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_8029726C_6A891C.s")
#endif

#if 0
extern Gfx D_010045A0_3DE70[];

// CURRENT (34997)
void func_80297628_6A8CD8(struct063 arg0[73][129], DisplayList *arg1) {
    u8 pad[0x44];
    u16 z; // sp190
    u16 x; // var_t0

    s16 i2 = G_CULL_BACK;

    u16 sp17A;
    u16 sp178;
    u16 sp176;
    u16 sp174;

    s32 sp164;
    s32 sp160;

    u16 sp142;
    u16 sp140;

    // s16 sp142;
    // s16 sp140;
    s16 vertsPerRow; // sp13C
    s16 sp136;
    s16 maxHeight; // sp134
    s16 minHeight; // sp132
    s16 sp12C;
    s16 sp126;

    // s32 spB8;
    // s32 spB4;
    s32 spB0;
    s16 spA8;
    // u32 spA4;
    s32 spA0;
    s32 sp98;
    // s32 sp88;
    s32 sp70;
    // s32 sp6C;

    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f2;

    s16 height;
    s16 end;
    s16 var_t1;
    s16 var_t5;
    s16 i;
    s32 temp_a0;
    s32 temp_s4;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t7;
    s32 var_s2;
    s32 var_s5;
    // s32 var_s7;
    s32 var_t4;
    s32 var_v1;
    s16 start;
    u16 temp_v1_3;

    static s16 D_803A04F0_7B1BA0 = 0;
    static s16 D_803A04F2_7B1BA2 = 0; // unused?
    static s16 D_803A04F8_7B1BA8 = 1; // unused?

    if (D_803F2D50.unk14 == 0) {
        return;
    }

    sp126 = 0;
    maxHeight = 10000;
    minHeight = -10000;

    gSPDisplayList(gLayer1DL++, D_01004270_3DB40);
    gSPDisplayList(gLayer1DL++, D_010045A0_3DE70);

    func_802985AC_6A9C5C(&gLayer1DL);

    gSPTexture(gLayer1DL++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON); // 0x10000
    gDPSetTextureLOD(gLayer1DL++, G_TL_TILE);
    gDPSetRenderMode(gLayer1DL++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
    gDPSetCombineLERP(gLayer1DL++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, PRIMITIVE);

    if ((D_803F2D50.unk14 != 0)) {
        if (D_803F2D50.unk16 != 0) {
            if (gCameraVisibilityMask[0] & 0x20) {

                D_803A04F0_7B1BA0 += 2;
                if (D_803A04F0_7B1BA0 >= 128) {
                    D_803A04F0_7B1BA0 = 0;
                }

                sp142 = D_803F2D50.unk14;
                sp140 = D_803F2D50.unk16;

                vertsPerRow = sp142 + 1;

                sp164 = D_803F2D50.unk10;
                sp160 = D_803F2D50.unk12;

                // reset water heights
                for (var_v1 = 0; var_v1 < (31 * 31); var_v1++) {
                    arg1->unk286E0[var_v1].v.ob[2] = 0;
                }

                gWaterAnimState.unk20E++;

                for (z = 0; z <= sp140; z++) {
                    for (x = 0; x <= sp142; x++) {

                        spB0 = (s32) z;
                        spA0 = (s32) z;
                        height = (D_803C0740[x + sp164][z + sp160].unk6 * 4) & 0xFFFF;
                        if (maxHeight >= height) {
                            maxHeight = height;
                        }
                        if (height >= minHeight) {
                            minHeight = height;
                        }

                        // sp98 = temp_v1;
                        if (height != 0) {
                            s32 tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
                            u16 tmp7, tmp8;
                            f32 foo =  64.0f;

                            temp_t1 = x + sp164;
                            temp_a0 = z + sp160;

                            sp17A = D_803C0740[temp_t1 - 1][temp_a0 - 1].unk6 * 4;
                            sp178 = D_803C0740[temp_t1 - 1][temp_a0 + 1].unk6 * 4;
                            sp176 = D_803C0740[temp_t1 + 1][temp_a0 + 1].unk6 * 4;
                            sp174 = D_803C0740[temp_t1 + 1][temp_a0 - 1].unk6 * 4;

                            temp_t2 = sp164 + (x * sp160) + z;
                            temp_t7 = (temp_t2 + sp164 + (x * sp164) + x) * 8;

                            tmp6 = (temp_t1 + sp160 + z);
                            tmp5 = (tmp6 + sp164 + temp_t1 + x) * 8;

                            arg1->unk286E0[(z * vertsPerRow) + x].v.ob[2] = gWaterAnimState.unk0[(temp_t2 & 7)][((gWaterAnimState.unk204 + temp_t7) & 0x3F)] + height;

                            tmp1 = gWaterAnimState.unk0[(tmp6    + 0) & 7][((gWaterAnimState.unk204 + tmp5   ) + 8) & 0x3F];
                            tmp2 = gWaterAnimState.unk0[(temp_t2 + 0) & 7][((gWaterAnimState.unk204 + temp_t7) + 0) & 0x3F];
                            tmp3 = gWaterAnimState.unk0[(temp_t2 + 1) & 7][((gWaterAnimState.unk204 + temp_t7) + 8) & 0x3F];
                            tmp4 = gWaterAnimState.unk0[(temp_t2 + 0) & 7][((gWaterAnimState.unk204 + temp_t7) + 0) & 0x3F];

                            tmp7 = (D_803C0740[temp_t1][z + sp160 + 0].unk6 * 4);
                            tmp8 = (D_803C0740[temp_t1][z + sp160 + 1].unk6 * 4);

                            temp_f20 = ((tmp1 + height + tmp2) - (tmp7)) / 64.0f;
                            temp_f22 = ((tmp3 + height + tmp4) - (tmp8)) / 64.0f;
                            temp_f24 = foo / 64.0f;

                            temp_f2 = 128.0f / sqrtf(SQ(temp_f20) + SQ(temp_f22) + SQ(temp_f24));
                            arg1->unk286E0[(z * vertsPerRow) + x].n.n[0] = (s32) (temp_f20 * temp_f2);
                            arg1->unk286E0[(z * vertsPerRow) + x].n.n[1] = (s32) (temp_f22 * temp_f2);
                            arg1->unk286E0[(z * vertsPerRow) + x].n.n[2] = (s32) (temp_f24 * temp_f2);

                            if (sp17A == 0) {
                                arg1->unk286E0[(((z - 1) * vertsPerRow) + x) - 1].v.ob[2] = height - gWaterAnimState.unk0[(temp_t2 & 7)][((gWaterAnimState.unk204 + temp_t7) & 0x3F)];
                            }
                            if (sp178 == 0) {
                                arg1->unk286E0[(((z + 1) * vertsPerRow) + x) - 1].v.ob[2] = height - gWaterAnimState.unk0[(temp_t2 & 7)][((gWaterAnimState.unk204 + temp_t7) & 0x3F)];
                            }
                            if (sp176 == 0) {
                                arg1->unk286E0[(((z + 1) * vertsPerRow) + x) + 1].v.ob[2] = height - gWaterAnimState.unk0[(temp_t2 & 7)][((gWaterAnimState.unk204 + temp_t7) & 0x3F)];
                            }
                            if (sp174 == 0) {
                                arg1->unk286E0[(((z - 1) * vertsPerRow) + x) + 1].v.ob[2] = height - gWaterAnimState.unk0[(temp_t2 & 7)][((gWaterAnimState.unk204 + temp_t7) & 0x3F)];
                            }
                        }
                    }
                }

                sp12C = 0;
                sp98 = sp140 - 1;

                sp136 = 0; // we never reset this?

                for (var_s5 = 0; var_s5 < sp142; var_s5 = (var_s5 + var_t1) - 1) {
                    var_s2 = 1;
                    if (sp142 < (var_s5 + 0x10)) {
                        var_t1 = (sp142 - var_s5) + 1;
                    } else {
                        var_t1 = 0x10;
                    }

                    arg1->unk2C2F0[sp136].v.ob[0] = (D_803F2D50.unk10 << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = (D_803F2D50.unk12 << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = maxHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = (D_803F2D50.unk10 << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = ((D_803F2D50.unk12 + D_803F2D50.unk16) << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = maxHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = ((D_803F2D50.unk10 + D_803F2D50.unk14) << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = ((D_803F2D50.unk12 + D_803F2D50.unk16) << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = maxHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = ((D_803F2D50.unk10 + D_803F2D50.unk14) << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = (D_803F2D50.unk12 << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = maxHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = (D_803F2D50.unk10 << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = (D_803F2D50.unk12 << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = minHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = (D_803F2D50.unk10 << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = ((D_803F2D50.unk12 + D_803F2D50.unk16) << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = minHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = ((D_803F2D50.unk10 + D_803F2D50.unk14) << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = ((D_803F2D50.unk12 + D_803F2D50.unk16) << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = minHeight;
                    sp136++;

                    arg1->unk2C2F0[sp136].v.ob[0] = ((D_803F2D50.unk10 + D_803F2D50.unk14) << 6);
                    arg1->unk2C2F0[sp136].v.ob[1] = (D_803F2D50.unk12 << 6);
                    arg1->unk2C2F0[sp136].v.ob[2] = minHeight;
                    sp136++;

                    gSPVertex(
                    /* pkt */ gLayer1DL++,
                    /* v   */ K0_TO_PHYS(&arg1->unk2C2F0[0]),
                    /* n   */ 8,
                    /* v0  */ 0);

                    gSPCullDisplayList(gLayer1DL++, 0, 7);

                    gSPVertex(
                    /* pkt */ gLayer1DL++,
                    /* v   */ K0_TO_PHYS(&arg1->unk286E0[var_s5]),
                    /* n   */ var_t1,
                    /* v0  */ 0);

                    // var_s7 = 1; /// ???
                    temp_s4 = var_t1 - 1;
                    var_t5 = vertsPerRow;
                    spA0 = (s32) var_t1;

                    for (var_t4 = 0; var_t4 < sp98; var_t4++) {
                        start = -100; // start
                        end = var_t1; // end

                        gDPPipeSync(gLayer1DL++);

                        for  (i = 0; i < var_t1; i++) {
                            if ((arg1->unk286E0[var_t4*vertsPerRow + i].v.ob[2] != 0) ||
                                (arg1->unk286E0[var_t5 + i].v.ob[2] != 0)) {
                                if (start == -100) {
                                    start = i;
                                }
                                end = i;
                            }
                        }

                        if (start < 0) {
                            start = 0;
                        }

                        sp12C += 1;
                        sp126 += (end - start) + 1;

                        gSPVertex(
                        /* pkt */ gLayer1DL++,
                        /* v   */ K0_TO_PHYS(&arg1->unk286E0[var_t5 + var_s5 + start]),
                        /* n   */ (end - start) + 1,
                        /* v0  */ (spA0 * var_s2) + start);

                        for (i = 0; i < temp_s4; i++) {

                            if (((D_803C0740[(var_s5 + i) + sp164 + 0][var_t4 + sp160 + 0].unk0 * 8) < arg1->unk286E0[(var_s5 + i) + (var_t4 * vertsPerRow) + 0].v.ob[2]) ||
                                ((D_803C0740[(var_s5 + i) + sp164 + 1][var_t4 + sp160 + 0].unk0 * 8) < arg1->unk286E0[(var_s5 + i) + (var_t4 * vertsPerRow) + 1].v.ob[2]) ||
                                ((D_803C0740[(var_s5 + i) + sp164 + 1][var_t4 + sp160 + 1].unk0 * 8) < arg1->unk286E0[(var_s5 + i) + (var_t5              ) + 1].v.ob[2]) ||
                                ((D_803C0740[(var_s5 + i) + sp164 + 0][var_t4 + sp160 + 1].unk0 * 8) < arg1->unk286E0[(var_s5 + i) + (var_t5              ) + 0].v.ob[2])) {

                                if (var_s2 != 0) {
                                    gSP2Triangles(
                                    /* gdl   */ gLayer1DL++,
                                    /* v00   */ (i + var_t1),
                                    /* v01   */ (i         ) + 1,
                                    /* v02   */ (i + var_t1) + 1,
                                    /* flag0 */ 0,
                                    /* v10   */ (i + var_t1),
                                    /* v11   */ (i         ) + 0,
                                    /* v12   */ (i         ) + 1,
                                    /* flag1 */ 0);

                                } else {
                                    gSP2Triangles(
                                    /* gdl   */ gLayer1DL++,
                                    /* v00   */ (i         ),
                                    /* v01   */ (i + var_t1) + 1,
                                    /* v02   */ (i         ) + 1,
                                    /* flag0 */ 0,
                                    /* v10   */ (i         ),
                                    /* v11   */ (i + var_t1),
                                    /* v12   */ (i + var_t1) + 1,
                                    /* flag1 */ 0);
                                }
                            }
                        }

                        var_s2 = 1 - var_s2; // toggle

                        var_t5 += vertsPerRow;
                    }
                }

                gSPSetGeometryMode(gLayer1DL++, G_CULL_BACK);
                gSPTexture(gLayer1DL++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            }
        }
    }
    func_802983D0_6A9A80();
}
#else
static s16 D_803A04F0_7B1BA0 = 0;
static s16 D_803A04F2_7B1BA2 = 0; // unused?
static s16 D_803A04F8_7B1BA8 = 1; // unused?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80297628_6A8CD8.s")
#endif

s32 func_802983D0_6A9A80(void) {
    s32 new_var UNUSED;
    s32 water_level = GET_WATER_LEVEL(D_803C0740, ((u16)gCameras[gCameraId].unk74), ((u16)gCameras[gCameraId].unk78));
    // needed!
    new_var = water_level;
    return 0;
}

// draw_water
void func_802985AC_6A9C5C(Gfx **dl) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, &gWaterTextureBuffer[gWaterAnimState.unk202 << 9]);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 1024);
    gDPPipeSync((*dl)++);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(63));
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0040, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

    gDPSetEnvColor((*dl)++, D_803E1BBD, D_803E1BBE, D_803E1BBF, D_803F2D50.waterEnvAlpha);

    gDPSetPrimColor((*dl)++, 128, gWaterAnimState.unk200, D_803E1BBA, D_803E1BBB, D_803E1BBC, D_803F2D50.waterPrimAlpha);
}

void func_8029877C_6A9E2C(void) {
    // maximum 64
    gWaterAnimState.unk204 += 1;
    gWaterAnimState.unk204 &= 0x3F;

    // maximum 255
    gWaterAnimState.unk200 += 64;
    if (gWaterAnimState.unk200 >= 256) {
        gWaterAnimState.unk200 &= 0xFF;
        gWaterAnimState.unk202 += 1;
        gWaterAnimState.unk202 &= 0xF;
    }

    gWaterAnimState.unk208 = 0;

    gWaterAnimState.unk206 += gWaterAnimState.unk20A;

    if (gWaterAnimState.unk206 == 240) {
        gWaterAnimState.unk20A = -8;
    }
    if (gWaterAnimState.unk206 == 0) {
        gWaterAnimState.unk20A = 8;
    }
    // maximum 31
    gWaterAnimState.unk20C += 1;
    gWaterAnimState.unk20C &= 0x1F;
}

// ESA: func_8002082C
s16 func_80298818_6A9EC8(s16 arg0, s16 arg1) {
    s16 phi_v1;
    s16 phi_t3;
    s16 phi_t4;
    s16 phi_a2;

    s16 a0;
    s16 a1;

    phi_v1 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 0) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) * (arg1 >> 6)) + ((arg0 >> 6) * (arg0 >> 6))) * 8)) +  0) & 0x3F];
    phi_t3 = (D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) * (arg1 >> 6)) + 1) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) * (arg1 >> 6)) + ((arg0 >> 6) * (arg0 >> 6))) * 8)) +  8) & 0x3F];

    phi_t4 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 1) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) + (arg1 >> 6)) + ((arg0 >> 6) + (arg0 >> 6))) * 8)) + 16) & 0x3F];
    phi_a2 = (D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2) + gWaterAnimState.unk0[(((arg0 >> 6) + (arg1 >> 6)) + 0) & 7][(u16)((gWaterAnimState.unk204 + ((((arg0 >> 6) + (arg1 >> 6)) + ((arg0 >> 6) + (arg0 >> 6))) * 8)) +  8) & 0x3F];

    if (phi_v1 < 16) {
        phi_v1 = MAX(phi_a2, MAX(phi_t3, phi_t4));
    }
    if (phi_t3 < 16) {
        phi_t3 = MAX(phi_v1, MAX(phi_t4, phi_a2));
    }
    if (phi_t4 < 16) {
        phi_t4 = MAX(phi_v1, MAX(phi_t3, phi_a2));
    }
    if (phi_a2 < 16) {
        phi_a2 = MAX(phi_v1, MAX(phi_t3, phi_t4));
    }

    a0 = arg0 & 0x3F;
    a1 = arg1 & 0x3F;

    if (a0 < a1) {
        return (phi_v1 + ((((phi_t4 - phi_t3) * a0) + ((phi_t3 - phi_v1) * a1)) >> 6));
    } else {
        return (phi_v1 + ((((phi_a2 - phi_v1) * a0) + ((phi_t4 - phi_a2) * a1)) >> 6));
    }
}

s16 unused_80298B70_6AA220(s16 arg0, s16 arg1) {
    s16 temp_t3;
    s16 temp_v0;

    s16 temp_a2;
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_v1;

    temp_v1 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6 << 2;
    temp_a2 = D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6 << 2;
    temp_a3 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6 << 2;
    temp_t0 = D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6 << 2;

    if ((temp_v1 + temp_a2 + temp_a3 + temp_t0) == 0) {
        return 0;
    }

    temp_v0 = arg0 & 0x3F;
    temp_t3 = arg1 & 0x3F;
    if (temp_v0 < temp_t3) {
        return (gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_a3 - temp_a2) * temp_v0) + ((temp_a2 - temp_v1) * temp_t3)) >> 6);
    } else {
        return (gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) * 8)) & 0x3F] >> 1) + temp_v1 + ((((temp_t0 - temp_v1) * temp_v0) + ((temp_a3 - temp_t0) * temp_t3)) >> 6);
    }
}

void unused_80298D44_6AA3F4(Animal *arg0) {
    s16 x;
    s16 z;
    s32 tmp;
    s32 tmp2;

    x = (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7 & 0xF0) >> 4) & 7) * (1 - (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7 >> 4) & 8) >> 2));
    z = (u16)(((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7       )     ) & 7) * (1 - (((D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7     ) & 8) >> 2));

    if (x != 0) {
        tmp = (arg0->xVelocity.w - (x << 17));
        arg0->xVelocity.w -= tmp >> 1;
    }
    if (z != 0) {
        tmp2 = (arg0->zVelocity.w - (z << 17));
        tmp = tmp2; // regalloc fix
        arg0->zVelocity.w -= tmp >> 1;
    }
}

// ESA: func_80020B38
s32 func_80298E08_6AA4B8(s16 arg0, s16 arg1) {
    // equivalent to dividing by 64
    arg0 >>= 6;
    arg1 >>= 6;

    if ((arg0 < D_803F2D50.unk10) ||
        (arg1 < D_803F2D50.unk12) ||
        ((D_803F2D50.unk10 + D_803F2D50.unk14) < arg0) ||
        ((D_803F2D50.unk12 + D_803F2D50.unk16) < arg1)) {
        return 0;
    }

    return 1;
}

// ESA: func_80020BB4
s16 func_80298E98_6AA548(s16 arg0, s16 arg1) {
    s16 tmp;
    s16 res;

    res = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;

    if (func_80298E08_6AA4B8(arg0, arg1)) {
        tmp = gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63];
        return res + tmp;
    } else {
        return res;
    }
}

// ESA: func_80020C8C
s16 func_80298F78_6AA628(s16 arg0, s16 arg1) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 temp_t4;
    s16 temp_t6;

    func_80299640_6AACF0(arg0 >> 6, arg1 >> 6, &sp36, &sp34, &sp32, &sp30);
    temp_t4 = arg0 & 0x3F;
    temp_t6 = arg1 & 0x3F;
    if ((temp_t4 + temp_t6) < 64) {
        return sp36 + ((((sp32 - sp36) * temp_t4) + ((sp34 - sp36) * temp_t6)) >> 6);
    } else {
        return sp30 + ((((sp34 - sp30) * (64 - temp_t4)) + ((sp32 - sp30) * (64 - temp_t6))) >> 6);
    }
}

s16 unused_802990A4_6AA754(s16 arg0, s16 arg1) {
    s16 tmp0;
    s16 tmp1;

    tmp0 = D_803C0740[arg0 >> 6][arg1 >> 6].unk6 << 2;
    tmp1 = gWaterAnimState.unk0[(arg0 * arg1) & 7][(u16)(gWaterAnimState.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] >> 1;

    return tmp0 + tmp1;
}

void func_80299140_6AA7F0(void) {
    s32 pad[2] UNUSED;
    s32 xPos; //sp5C;
    s32 zPos; //sp58;
    s32 yPos; //sp54;
    s16 i, j;
    s32 maxPoint;
    s16 temp_a3;
    s16 maxX;
    s16 maxZ;
    s16 minX;
    s16 minZ;
    s16 water_level;
    s32 newMax;

    maxPoint = 100000;

    minX = ((s32)gCameras[gCameraId].unk74 >> 6) - 25;
    minZ = ((s32)gCameras[gCameraId].unk78 >> 6) - 25;
    maxX = ((s32)gCameras[gCameraId].unk74 >> 6) + 25;
    maxZ = ((s32)gCameras[gCameraId].unk78 >> 6) + 25;

#ifdef __sgi
    if (1) { }
#endif

    if (minX < 4) {
        minX = 4;
    }
    if (minZ < 8) {
        minZ = 8;
    }
    if (maxX > 68) {
        maxX = 68;
    }
    if (maxZ > 104) {
        maxZ = 104;
    }

    for (i = minX; i <= maxX; i += 3) {
        for (j = minZ; j <= maxZ; j += 3) {
            temp_a3 = D_803C0740[i][j].unk6 << 2;
            if (temp_a3 != 0) {
                newMax = ABS((i << 6) - ((s16) gCameras[gCameraId].unk74)) + ABS((j << 6) - (s16) gCameras[gCameraId].unk78) + ABS(temp_a3 - (s16) gCameras[gCameraId].unk7C);
                newMax = ABS(newMax);

                if (newMax < maxPoint) {
                    maxPoint = newMax;
                    xPos = (i << 6);
                    zPos = (j << 6);
                    yPos = temp_a3;
                }
            }
        }
    }

    if (maxPoint != 100000) {
        if ((D_803F2D50.unk4C == 0) || (D_803F2D50.unk4C == 2)) {
            water_level = ((GET_WATER_LEVEL(D_803C0740, (u16)gCameras[gCameraId].unk74, (u16)gCameras[gCameraId].unk78)) << 2);
            if (water_level > (gCameras[gCameraId].unk7C - 12.0f)) {
                func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_12, 0x4718, 0, 0.28f, xPos, zPos, yPos); // D_803BAD00_7CC3B0
            } else {
                func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_12, 0x2800, 0, 1.0f, xPos, zPos, yPos);
            }
        }
        if (D_803F2D50.unk4C == 1) {
            func_8032CD70_73E420((void*)&gWaterAnimState.unk204, SFX_UNKNOWN_64, 0x7FFF, 0, 0.25f, xPos, zPos, yPos);
        }
    }
}

// ESA: func_80020D84
void func_80299640_6AACF0(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5) {
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_a2;
    s16 temp_t7;

    if (func_80298E08_6AA4B8(arg0 << 6, arg1 << 6) == 0) {
        temp_a0 = D_803C0740[arg0 + 0][arg1 + 0].unk6 << 2;
        temp_a1 = D_803C0740[arg0 + 0][arg1 + 1].unk6 << 2;
        temp_a2 = D_803C0740[arg0 + 1][arg1 + 0].unk6 << 2;
        temp_t7 = D_803C0740[arg0 + 1][arg1 + 1].unk6 << 2;

        *arg2 = temp_a0;
        if (*arg2 == 0) {
            *arg2 = temp_a1;
            if (*arg2 == 0) {
                *arg2 = temp_a2;
                if (*arg2 == 0) {
                    *arg2 = temp_t7;
                }
            }
        }
        *arg4 = temp_a2;
        if (*arg4 == 0) {
            *arg4 = temp_a0;
            if (*arg4 == 0) {
                *arg4 = temp_t7;
                if (*arg4 == 0) {
                    *arg4 = temp_a1;
                }
            }
        }
        *arg3 = temp_a1;
        if (*arg3 == 0) {
            *arg3 = temp_t7;
            if (*arg3 == 0) {
                *arg3 = temp_a0;
                if (*arg3 == 0) {
                    *arg3 = temp_a2;
                }
            }
        }
        *arg5 = temp_t7;
        if (*arg5 == 0) {
            *arg5 = temp_a1;
            if (*arg5 == 0) {
                *arg5 = temp_a2;
                if (*arg5 == 0) {
                    *arg5 = temp_a0;
                }
            }
        }

        *arg2 += gWaterAnimState.unk0[((arg0 + 0) * (arg1 + 0)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 0) * (arg1 + 0)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1;
        *arg4 += gWaterAnimState.unk0[((arg0 + 1) * (arg1 + 0)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 1) * (arg1 + 0)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1;
        *arg3 += gWaterAnimState.unk0[((arg0 + 0) * (arg1 + 1)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 0) * (arg1 + 1)) + ((arg0 + 0) * (arg0 + 0))) << 3)) & 63] << 1;
        *arg5 += gWaterAnimState.unk0[((arg0 + 1) * (arg1 + 1)) & 7][(u16)(gWaterAnimState.unk204 + ((((arg0 + 1) * (arg1 + 1)) + ((arg0 + 1) * (arg0 + 1))) << 3)) & 63] << 1;
    } else {
        s32 idx1;
        s32 idx2;
        u16 a;
        s16 b; // fuuuu
        u16 c;

        c = D_803F2D50.unk10;
        a = D_803F2D50.unk12;
        b = D_803F2D50.unk14 + 1;

        idx1 = ((((s16)(arg1 - a) + 0) * b) + (s16)(arg0 - c));
        idx2 = ((((s16)(arg1 - a) + 1) * b) + (s16)(arg0 - c));

        *arg2 = gDisplayListContext->unk286E0[idx1 + 0].v.ob[2];
        *arg3 = gDisplayListContext->unk286E0[idx2 + 0].v.ob[2];
        *arg5 = gDisplayListContext->unk286E0[idx2 + 1].v.ob[2];
        *arg4 = gDisplayListContext->unk286E0[idx1 + 1].v.ob[2];
    }
}
