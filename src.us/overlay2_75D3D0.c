#include <ultra64.h>
#include "common.h"


#if 0
// CURRENT (9788)
// esa:func_8006BC30 but customised

// #define SHADE 0
// #define TEXEL0 0
void func_8034BD20_75D3D0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *img, s16 arg5, s16 arg6, s16 alpha, s16 red, s16 green, s16 blue, s16 argB, u8 argC) {
    s16 idx;
    s16 new_distance;
    s16 best_distance;

    s16 tmp1;
    s16 tmp2;

    s16 tmp3;
    s16 tmp4;
    s16 tmp5;
    s16 tmp6;

    Animal *animal;
    Animal *var_ra;

    s16 sp23A;
    s16 sp238;
    s16 sp236;
    s16 sp234;

    s16 temp_t0;    // sp232?
    s16 temp_t1;    // sp230?
    s16 sp22E;
    s16 sp22C;

    struct061 vtxs[5][10]; // sp98 (5 * 10 * 8 => 0x190 big)
    s32 sp94;              // pad
    s16 numVtxs[5];        // sp8C

    s32 temp_a0;
    s32 temp_v1;

    CollisionNode *var_a2;

    s32 sp74;

    if (argC == 0) {

        temp_v1 = arg0 - (s16) gCameras[gCameraId].unk74;
        temp_a0 = arg1 - (s16) gCameras[gCameraId].unk78;
        if (argB >= 0) {
            sp74 = (SQ(temp_v1) + SQ(temp_a0)) >> argB;
        } else if (argB < 0) {
            sp74 = (SQ(temp_v1) + SQ(temp_a0)) << -argB;
        }

        if (sp74 < 0x51000) {
            if (sp74 > 0x31000) {
                alpha = (alpha * (0x51000 - sp74)) / 0x20000;
            }
        } else {
            return;
        }
    }

    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, img);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 512);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(63), 4*(63));
    gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
    gDPSetRenderMode(D_801D9E90++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetCombineLERP(D_801D9E90++, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);
    gDPPipeSync(D_801D9E90++);

    tmp1 = (s16)(SIN(arg3) >> 7) + 1;
    tmp2 = (s16)(COS(arg3) >> 7) + 1;

    tmp3 =  (arg5 * tmp1) >> 8;
    tmp5 = -(arg6 * tmp1) >> 8;
    tmp4 =  (arg5 * tmp2) >> 8;
    tmp6 =  (arg6 * tmp2) >> 8;

    vtxs[0][0].unk0 = arg0 + tmp3 + tmp6;
    vtxs[0][0].unk2 = arg1 + tmp4 + tmp5;
    vtxs[0][0].unk4 = 0xFC0;
    vtxs[0][0].unk6 = 0xFC0;

    vtxs[0][1].unk0 = arg0 - tmp3 + tmp6;
    vtxs[0][1].unk2 = arg1 - tmp4 + tmp5;
    vtxs[0][1].unk4 = 0;
    vtxs[0][1].unk6 = 0xFC0;

    vtxs[0][2].unk0 = arg0 - tmp3 - tmp6;
    vtxs[0][2].unk2 = arg1 - tmp4 - tmp5;
    vtxs[0][2].unk4 = 0;
    vtxs[0][2].unk6 = 0;

    vtxs[0][3].unk0 = arg0 + tmp3 - tmp6;
    vtxs[0][3].unk2 = arg1 + tmp4 - tmp5;
    vtxs[0][3].unk4 = 0xFC0;
    vtxs[0][3].unk6 = 0;

    numVtxs[0] = 4;

    sp23A = MIN(MIN(vtxs[0][0].unk0, vtxs[0][1].unk0), MIN(vtxs[0][2].unk0, vtxs[0][3].unk0));
    sp238 = MAX(MAX(vtxs[0][0].unk0, vtxs[0][1].unk0), MAX(vtxs[0][2].unk0, vtxs[0][3].unk0));

    sp236 = MIN(MIN(vtxs[0][0].unk2, vtxs[0][1].unk2), MIN(vtxs[0][2].unk2, vtxs[0][3].unk2));
    sp234 = MAX(MAX(vtxs[0][0].unk2, vtxs[0][1].unk2), MAX(vtxs[0][2].unk2, vtxs[0][3].unk2));

    var_ra = NULL;
    best_distance = 640; // 10 << 6 ?

    for (var_a2 = D_803DA110[(s16) ((s16)(arg0 >> 0xA) + ((s16)(arg1 >> 0xA) * 5))].next; var_a2 != NULL; var_a2 = var_a2->next) {
        animal = var_a2->animal;
        if ((animal != D_803D5530) && ((animal->unk3E & 0x3F) != 0x28) &&
            ((animal->unk16C->unk15 == 4) ||
            ((animal->unk16C->objectType == 93)) || (animal->unk16C->objectType == 94)) &&
            !(animal->unk163 & 0x10) && ((arg2 << 0x10) >= (animal->position.yPos.w + (animal->unk42 << 0x10)))) {

            if ((((animal->position.xPos.h + animal->unk30) >= sp23A) && (sp238 >= (animal->position.xPos.h - animal->unk30)))) {
                if ((((animal->position.zPos.h + animal->unk32) >= sp236) && (sp234 >= (animal->position.zPos.h - animal->unk32)))) {
                    new_distance = ABS(animal->position.xPos.h - arg0) + ABS(animal->position.zPos.h - arg1);
                    if (new_distance < best_distance) {
                        best_distance = new_distance;
                        var_ra = animal;
                    }
                }
            }
        }
    }

    if (var_ra == NULL) {
        func_8034CCBC_75E36C(vtxs[0], 4, arg2, alpha, red, green, blue);
        return;
    }

    temp_t1 = var_ra->position.xPos.h - var_ra->unk30; // x_low
    temp_t0 = var_ra->position.xPos.h + var_ra->unk30; // x_high
    sp22C = var_ra->position.zPos.h - var_ra->unk32;   // z_low
    sp22E = var_ra->position.zPos.h + var_ra->unk32;   // z_high

    if ((sp23A >= temp_t1) && (temp_t0 >= sp238)) {
        if ((sp236 >= sp22C) && (sp22E >= sp234)) {
            func_80351EE8_763598(4, vtxs[0], var_ra->position.yPos.h + var_ra->unk42, alpha, red, green, blue);
            idx = -1;
        } else {
            idx = 0;
        }
    } else if ((sp23A < temp_t0) && (temp_t0 < sp238)) {
        func_8034F3EC_760A9C(vtxs[0], vtxs[1], vtxs[2], 4, &numVtxs[1], &numVtxs[2], temp_t0);
        if (numVtxs[2] >= 3) {
            func_8034CCBC_75E36C(vtxs[2], numVtxs[2], arg2, alpha, red, green, blue);
        }
        idx = 1;
    } else if ((sp23A < temp_t1) && (temp_t1 < sp238)) {
        func_8034F3EC_760A9C(vtxs[0], vtxs[1], vtxs[2], 4, &numVtxs[1], &numVtxs[2], temp_t1);
        if (numVtxs[1] >= 3) {
            func_8034CCBC_75E36C(vtxs[1], numVtxs[1], arg2, alpha, red, green, blue);
        }
        idx = 2;
    } else {
        func_8034CCBC_75E36C(vtxs[0], 4, arg2, alpha, red, green, blue);
        idx = -1;
    }

    if (idx >= 0) {
        if ((sp22E >= sp236) && (sp234 >= sp22E)) {
            func_8034FCFC_7613AC(vtxs[idx], vtxs[3], vtxs[4], numVtxs[idx], &numVtxs[3], &numVtxs[4], sp22E);
            if (numVtxs[4] >= 3) {
                func_8034CCBC_75E36C(vtxs[4], numVtxs[4], arg2, alpha, red, green, blue);
            }
            if (numVtxs[3] >= 3) {
                func_80351EE8_763598(numVtxs[3], vtxs[3], var_ra->position.yPos.h + var_ra->unk42, alpha, red, green, blue);
            }
        } else if ((sp22C >= sp236) && (sp234 >= sp22C)) {
            func_8034FCFC_7613AC(vtxs[idx], vtxs[3], vtxs[4], numVtxs[idx], &numVtxs[3], &numVtxs[4], sp22C);
            if (numVtxs[3] >= 3) {
                func_8034CCBC_75E36C(vtxs[3], numVtxs[3], arg2, alpha, red, green, blue);
            }
            if (numVtxs[4] >= 3) {
                func_80351EE8_763598(numVtxs[4], vtxs[4], var_ra->position.yPos.h + var_ra->unk42, alpha, red, green, blue);
            }
        } else {
            if (numVtxs[idx] >= 3) {
                func_80351EE8_763598(numVtxs[idx], vtxs[idx], var_ra->position.yPos.h + var_ra->unk42, alpha, red, green, blue);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034BD20_75D3D0.s")
#endif

#if 0
// esa:func_8006C510 (but custom)
void func_8034C8F8_75DFA8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *img, s16 arg5, s16 arg6, s16 alpha, s16 red, s16 green, s16 blue, s16 argB, u8 argC) {
    s32 pad[8];


    s16 temp_v0;
    s16 temp_v1_2;

    s16 temp_t2;
    s16 temp_t4;
    s16 temp_t3;
    s16 temp_t0;
    s16 temp_t9;
    s16 temp_t8;

    struct061 vtx[4];

    s32 temp_v1;
    s32 var_v0;
    s32 temp_a0;

    // argC is either 0 or 1 (I think?)
    if (argC == 0) {
        temp_v1 = arg0 - (s16) gCameras[gCameraId].unk74;
        temp_a0 = arg1 - (s16) gCameras[gCameraId].unk78;

        if (argB >= 0) {
            var_v0 = (SQ(temp_v1) + SQ(temp_a0)) >> argB;
        } else if (argB < 0) {
            var_v0 = (SQ(temp_v1) + SQ(temp_a0)) << -argB;
        }

        if (var_v0 >= 0x51000) { // max distance?
            return;
        } else if (var_v0 > 0x31000) {
            alpha = (alpha * (0x51000 - var_v0)) / 0x20000;
        }
    }

    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, img);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 512);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(63), 4*(63));
    gDPSetRenderMode(D_801D9E90++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetCombineLERP(D_801D9E90++,
        0,      0,     0, SHADE,
        TEXEL0, 0, SHADE,     0,
        0,      0,     0, SHADE,
        TEXEL0, 0, SHADE,     0);
    gDPPipeSync(D_801D9E90++);

    temp_v0 = (SIN(arg3) >> 7);
    temp_v0 += 1;

    temp_t4 =  (arg5 * temp_v0) >> 8;
    temp_t8 = -(arg6 * temp_v0) >> 8;

    temp_v1_2 = (COS(arg3) >> 7);
    temp_v1_2 += 1;

    temp_t0 = (arg5 * temp_v1_2) >> 8;
    temp_t3 = (arg5 * temp_v1_2) >> 8;
    temp_t9 = (arg6 * temp_v1_2) >> 8;

    vtx[0].unk0 = arg0 + ((arg5 * temp_v0) >> 8) + temp_t9;
    vtx[0].unk2 = arg1 + temp_t3 + temp_t8;
    vtx[0].unk4 = 0xFC0;
    vtx[0].unk6 = 0xFC0;

    vtx[1].unk0 = arg0 - temp_t4 + temp_t9;
    vtx[1].unk2 = arg1 - temp_t0 + temp_t8;
    vtx[1].unk4 = 0;
    vtx[1].unk6 = 0xFC0;

    vtx[2].unk0 = arg0 - temp_t4 - temp_t9;
    vtx[2].unk2 = arg1 - temp_t0 - temp_t8;
    vtx[2].unk4 = 0;
    vtx[2].unk6 = 0;

    vtx[3].unk0 = arg0 + ((arg5 * temp_v0) >> 8) - temp_t9;
    vtx[3].unk2 = arg1 + temp_t3 - temp_t8;
    vtx[3].unk4 = 0xFC0;
    vtx[3].unk6 = 0;

    func_8034CCBC_75E36C(vtx, 4, arg2, alpha, red, green, blue);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034C8F8_75DFA8.s")
#endif

// ESA: func_8006C6E8
void func_8034CCBC_75E36C(struct061 *src, s16 numVtxs, s16 arg2, s16 alpha, s16 red, s16 green, s16 blue) {
    struct061 spC8[10];
    struct061 sp78[10];
    s16 temp_v0_2;
    s16 var_s3;
    s16 maxx;
    s16 i;
    s16 pad;
    s16 minx;

    s16 _numVtxs; //sp6A;
    s16 sp68;

    struct061 *tmp;
    struct061 *var_s0;
    struct061 *_src;

    minx = maxx = src->unk0;

    for (i = 1; i < numVtxs; i++) {
        if (minx >= src[i].unk0) {
            minx = src[i].unk0;
        }
        if (src[i].unk0 >= maxx) {
            maxx = src[i].unk0;
        }
    }

    _src = src;
    var_s0 = &spC8;
    _numVtxs = numVtxs;
    var_s3 = minx;

    while ((var_s3 & ~0x3F) != (maxx & ~0x3F)) {
        temp_v0_2 = (var_s3 & ~0x3F) + 0x40;
        func_8034F3EC_760A9C(_src, &sp78, var_s0, _numVtxs, &sp68, &_numVtxs, temp_v0_2);
        func_8034CE88_75E538(&sp78, sp68, arg2, alpha, var_s3 >> 6, red, green, blue);
        tmp = _src;
        _src = var_s0;
        var_s0 = tmp;
        var_s3 = temp_v0_2;
    }
    func_8034CE88_75E538(_src, _numVtxs, arg2, alpha, var_s3 >> 6, red, green, blue);
}


// ESA: func_8006C8DC
void func_8034CE88_75E538(struct061 *arg0, s16 arg1, s16 arg2, s16 alpha, s16 arg4, s16 red, s16 green, s16 blue) {
    struct061 sp1F0[10];
    struct061 sp1A0[10];
    struct061 *sp19C;

    s16 var_s7;
    s32 pad;

    struct061 sp144[10];
    struct061 spF4[10];
    s16 spF2;
    s16 spF0;
    s16 spEE;
    s16 spEC;

    s16 i;
    s16 maxx;
    s16 minx;
    s16 var_v0;
    s32 var_s2;

    s16 spDE;
    s16 var_s1;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_a0;

    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    s16 spBA;

    s16 var_t1_2;

    struct061 *var_fp;
    struct061 *tmp;

    u8 spAF;
    u8 spAE; // pad
    u8 spAD;
    s16 spAA;
    s16 spA8;
    s16 spA6;
    s16 var_s3;
    u8 spA3;

    minx = maxx = arg0[0].unk2;

    for (i = 0; i < arg1; i++) {
        if (minx >= arg0[i].unk2) {
            minx = arg0[i].unk2;
        }
        if (arg0[i].unk2 >= maxx) {
            maxx = arg0[i].unk2;
        }
    }

    sp19C = arg0;
    var_fp = &sp1F0;
    spF2 = arg1;

    spAA = minx >> 6;
    spDE = maxx >> 6;
    var_s3 = spAA;

    spAF = 0;

    for (; var_s3 <= spDE; var_s3++) {

        if (D_803C0740[arg4+0][var_s3+0].unk3 == 0) {
            var_s7 = 1;
            var_s2 = D_803C0740[arg4+0][var_s3+0].unk0 << 3;
            var_s4 = D_803C0740[arg4+1][var_s3+0].unk0 << 3;
            var_s5 = D_803C0740[arg4+0][var_s3+1].unk0 << 3;
            var_s6 = D_803C0740[arg4+1][var_s3+1].unk0 << 3;

            spAD = D_803C0740[arg4+0][var_s3+0].unk4 & 1;
        } else {
            var_v0 = MIN(D_803C0740[arg4+0][var_s3+0].unk1, D_803C0740[arg4+1][var_s3+1].unk1) << 3;

            if ((arg2 - 0x10) < (var_v0)) {
                var_s2 = D_803C0740[arg4+0][var_s3+0].unk0 << 3;
                var_s4 = D_803C0740[arg4+1][var_s3+0].unk0 << 3;
                var_s5 = D_803C0740[arg4+0][var_s3+1].unk0 << 3;
                var_s6 = D_803C0740[arg4+1][var_s3+1].unk0 << 3;

                spAD = D_803C0740[arg4+0][var_s3+0].unk4 & 1;
                var_s7 = 1;
            } else {
                var_s2 = D_803C0740[arg4+0][var_s3+0].unk1 << 3;
                var_s4 = D_803C0740[arg4+1][var_s3+0].unk1 << 3;
                var_s5 = D_803C0740[arg4+0][var_s3+1].unk1 << 3;
                var_s6 = D_803C0740[arg4+1][var_s3+1].unk1 << 3;

                spAD = D_803C0740[arg4+0][var_s3+0].unk4 & 2;
                var_s7 = 2;
            }
        }

        if (var_s6 != ((var_s4 + var_s5) - var_s2)) {
            var_t1_2 = 1;
            spA3 = 0;
        } else {
            var_t1_2 = 0;
            spA3 = 1;
        }

        var_a0 = MIN(MIN(var_s2, var_s6), MIN(var_s4, var_s5));

        if (arg2 < (var_a0 - 0x20)) {
            var_s7 = 3;
            var_t1_2 = 1;
        } else {
            spA8 = MIN(0xFF, ((arg2 + 0x20) - var_a0) << 4);
        }

        if (ABS((s16)gCameras[gCameraId].unk7C - var_a0)) {
            // debug?
        }

        var_v0 = MAX(MAX((D_803C0740[arg4+0][var_s3+0].unk6 * 4), (D_803C0740[arg4+1][var_s3+0].unk6 * 4)), MAX((D_803C0740[arg4+0][var_s3+1].unk6 * 4), (D_803C0740[arg4+1][var_s3+1].unk6 * 4)));

        if ((var_v0 < arg2) && ((var_s2 < (D_803C0740[arg4+0][var_s3+0].unk6 * 4)) || (var_s4 < (D_803C0740[arg4+1][var_s3+0].unk6 * 4)) || (var_s5 < (D_803C0740[arg4+0][var_s3+1].unk6 * 4)) || (var_s6 < (D_803C0740[arg4+1][var_s3+1].unk6 * 4)))) {
            var_s1 = 1;
            spA6 = MIN(0xFF, (arg2 - var_v0) << 4);
            var_t1_2 = 1;
        } else {
            var_s1 = 0;
        }

        if (var_t1_2 != 0) {
            if (spAF != 0) {
                func_8034FCFC_7613AC(sp19C, &sp1A0, var_fp, spF2, &spF0, &spF2, var_s3 << 6);
                tmp = sp19C;sp19C = var_fp;var_fp = tmp;

                func_80351390_762A40(spF0, &sp1A0, (spA8 * alpha) >> 8, arg4, spBA, spAF, red, green, blue, spC8, spC4, spC0, spBC);
                spAF = 0;
            }

            func_8034FCFC_7613AC(sp19C, &sp1A0, var_fp, spF2, &spF0, &spF2, (var_s3 + 1) << 6);
            tmp = sp19C;sp19C = var_fp;var_fp = tmp;

            if (var_s7 != 3) {
                if (spA3 != 0) {
                    if (spF0 >= 3) {
                        func_80351390_762A40(spF0, &sp1A0, (spA8 * alpha) >> 8, arg4, var_s3, spAF, red, green, blue, var_s2, var_s5, var_s4, var_s6);
                        if (var_s1 != 0) {
                            func_80351A44_7630F4(spF0, &sp1A0, (spA6 * alpha) >> 8, arg4, var_s3, red, green, blue);
                        }
                    }
                } else {
                    if ((var_s1 != 0) && (spF0 >= 3)) {
                        func_80351A44_7630F4(spF0, &sp1A0, (spA6 * alpha) >> 8, arg4, var_s3, red, green, blue);
                    }
                    func_8034D830_75EEE0(&sp1A0, &spF4, &sp144, spF0, &spEC, &spEE, arg4, var_s3, var_s7, spAD);

                    if (spEC >= 3) {
                        func_80350600_761CB0(spEC, &spF4, (spA8 * alpha) >> 8, arg4, var_s3, var_s7, spAD, 0, red, green, blue, var_s2, var_s5, var_s4, var_s6);
                    }

                    if (spEE >= 3) {
                        func_80350600_761CB0(spEE, &sp144, (spA8 * alpha) >> 8, arg4, var_s3, var_s7, spAD, 1, red, green, blue, var_s2, var_s5, var_s4, var_s6);
                    }
                }
            }
        } else {

            if (spAF == 0) {
                spAF = var_s7;
                spC8 = var_s2;
                spC0 = var_s4;
                spC4 = var_s5;
                spBC = var_s6;
                spBA = var_s3;
            } else if ((var_s7 == spAF) && ((spC0 - spC8) == (var_s4 - var_s2)) && ((spC4 - spC8) == (var_s5 - var_s2))) {
                continue;
            } else {
                func_8034FCFC_7613AC(sp19C, &sp1A0, var_fp, spF2, &spF0, &spF2, var_s3 << 6);
                func_80351390_762A40(spF0, &sp1A0, (spA8 * alpha) >> 8, arg4, spBA, spAF, red, green, blue, spC8, spC4, spC0, spBC);
                spAF = var_s7;
                spC8 = var_s2;
                spC0 = var_s4;
                spC4 = var_s5;
                spBC = var_s6;
                spBA = var_s3;

                tmp = sp19C;sp19C = var_fp;var_fp = tmp;
            }
        }

    }

    if (spAF != 0) {
        func_80351390_762A40(spF2, sp19C, (spA8 * alpha) >> 8, arg4, spBA, spAF, red, green, blue, spC8, spC4, spC0, spBC);
    }
}

// ESA: func_8006D384
void func_8034D830_75EEE0(struct061 *src, struct061 *arg1, struct061 *arg2, s16 arg3, s16 *arg4, s16 *arg5, s16 arg6, s16 arg7, s32 arg8, s8 arg9) {
    s32 pad2;
    s16 temp_a0;
    s16 temp_v1;
    s16 var_a1;
    s16 var_v1;
    s32 pad;

    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s16 tmp4;
    s16 new_var;

    s16 i;
    s8 var_s3;

    s8 sp48[3];

    if (arg9 != 0) {
        for (i = 0; i < arg3; i++) {
            tmp1 = src[i].unk0 - (arg6 << 6);
            tmp2 = src[i].unk2 - (arg7 << 6);
            if (tmp1 > tmp2) {
                sp48[i] = 0;
            } else if (tmp1 < tmp2) {
                sp48[i] = 1;
            } else {
                sp48[i] = 2;
            }
        }

        var_s3 = sp48[0];

        *arg4 = 0;
        *arg5 = 0;

        i = 1;

        if (var_s3 == 0) {
            // copy src to a
            arg1->unk0 = src->unk0;
            arg1->unk2 = src->unk2;
            arg1->unk4 = src->unk4;
            arg1->unk6 = src->unk6;
            *arg4 += 1;
        } else if (var_s3 == 1) {
            // copy src to b
            arg2->unk0 = src->unk0;
            arg2->unk2 = src->unk2;
            arg2->unk4 = src->unk4;
            arg2->unk6 = src->unk6;
            *arg5 += 1;
        } else {
            // copy src to a
            arg1->unk0 = src->unk0;
            arg1->unk2 = src->unk2;
            arg1->unk4 = src->unk4;
            arg1->unk6 = src->unk6;
            // copy src to b
            arg2->unk0 = src->unk0;
            arg2->unk2 = src->unk2;
            arg2->unk4 = src->unk4;
            arg2->unk6 = src->unk6;

            *arg4 += 1;
            *arg5 += 1;

            if ((sp48[1] == 0) || ((sp48[1] == 2) && (sp48[2] == 0))) {
                var_s3 = 0;
            } else {
                var_s3 = 1;
            }
        }

        for (; i < arg3; i++) {
            switch (var_s3) {
            case 0:
                switch (sp48[i]) {
                case 0:
                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;
                    *arg4 += 1;
                    break;
                case 1:

                    tmp1 = (src[i].unk0 - (arg6 << 6));
                    tmp2 = (src[i].unk2 - (arg7 << 6));
                    tmp3 = (src[i-1].unk0 - (arg6 << 6));
                    tmp4 = (src[i-1].unk2 - (arg7 << 6));

                    var_v1 = ABS(tmp1 - tmp2);
                    var_a1 = ABS(tmp3 - tmp4);
                    temp_a0 = var_v1 + var_a1;

                    var_s3 = 1;

                    arg1[*arg4].unk0 = ((var_a1 * src[i].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
                    arg1[*arg4].unk2 = ((var_a1 * src[i].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
                    arg1[*arg4].unk4 = ((var_a1 * src[i].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
                    arg1[*arg4].unk6 = ((var_a1 * src[i].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

                    arg2[*arg5].unk0 = arg1[*arg4].unk0;
                    arg2[*arg5].unk2 = arg1[*arg4].unk2;
                    arg2[*arg5].unk4 = arg1[*arg4].unk4;
                    arg2[*arg5].unk6 = arg1[*arg4].unk6;

                    *arg4 += 1;
                    *arg5 += 1;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg5 += 1;
                    break;
                case 2:

                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg4 += 1;
                    *arg5 += 1;

                    var_s3 = 1;

                    break;
                }
                break;
            case 1:
                switch (sp48[i]) {
                case 1:
                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg5 += 1;
                    break;
                case 0:
                    tmp1 = (src[i].unk0 - (arg6 << 6));
                    tmp2 = (src[i].unk2 - (arg7 << 6));
                    tmp3 = (src[i-1].unk0 - (arg6 << 6));
                    tmp4 = (src[i-1].unk2 - (arg7 << 6));

                    var_v1 = ABS(tmp1 - tmp2);
                    var_a1 = ABS(tmp3 - tmp4);

                    temp_a0 = var_v1 + var_a1;

                    arg1[*arg4].unk0 = ((var_a1 * src[i].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
                    arg1[*arg4].unk2 = ((var_a1 * src[i].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
                    arg1[*arg4].unk4 = ((var_a1 * src[i].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
                    arg1[*arg4].unk6 = ((var_a1 * src[i].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

                    arg2[*arg5].unk0 = arg1[*arg4].unk0;
                    arg2[*arg5].unk2 = arg1[*arg4].unk2;
                    arg2[*arg5].unk4 = arg1[*arg4].unk4;
                    arg2[*arg5].unk6 = arg1[*arg4].unk6;
                    *arg4 += 1;
                    *arg5 += 1;

                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;
                    *arg4 += 1;

                    var_s3 = 0;
                    break;
                case 2:
                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;

                    *arg4 += 1;
                    *arg5 += 1;

                    var_s3 = 0;
                    break;
                }
                break;
            case 2:
                break;
            }
        }

        if (((var_s3 == 1) && (sp48[0] == 0)) ||
            ((var_s3 == 0) && (sp48[0] == 1))) {

            tmp1 = (src[0].unk0 - (arg6 << 6));
            tmp2 = (src[0].unk2 - (arg7 << 6));
            tmp3 = (src[i-1].unk0 - (arg6 << 6));
            tmp4 = (src[i-1].unk2 - (arg7 << 6));

            var_v1 = ABS(tmp1 - tmp2);
            var_a1 = ABS(tmp3 - tmp4);

            temp_a0 = var_v1 + var_a1;

            arg1[*arg4].unk0 = ((var_a1 * src[0].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
            arg1[*arg4].unk2 = ((var_a1 * src[0].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
            arg1[*arg4].unk4 = ((var_a1 * src[0].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
            arg1[*arg4].unk6 = ((var_a1 * src[0].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

            arg2[*arg5].unk0 = arg1[*arg4].unk0;
            arg2[*arg5].unk2 = arg1[*arg4].unk2;
            arg2[*arg5].unk4 = arg1[*arg4].unk4;
            arg2[*arg5].unk6 = arg1[*arg4].unk6;

            *arg4 += 1;
            *arg5 += 1;
        }
    } else {
        for (i = 0; i < arg3; i++) {
            temp_v1 = src[i].unk0 + src[i].unk2;
            temp_a0 = (arg6 << 6) + (arg7 << 6) + 0x40;
            if (temp_v1 < temp_a0) {
                sp48[i] = 0;
            } else if (temp_a0 < temp_v1) {
                sp48[i] = 1;
            } else {
                sp48[i] = 2;
            }
        }

        var_s3 = sp48[0];

        *arg4 = 0;
        *arg5 = 0;

        i = 1;

        if (var_s3 == 0) {
            // copy src to a
            arg1->unk0 = src->unk0;
            arg1->unk2 = src->unk2;
            arg1->unk4 = src->unk4;
            arg1->unk6 = src->unk6;
            *arg4 += 1;
        } else if (var_s3 == 1) {
            // copy src to b
            arg2->unk0 = src->unk0;
            arg2->unk2 = src->unk2;
            arg2->unk4 = src->unk4;
            arg2->unk6 = src->unk6;
            *arg5 += 1;
        } else {
            // copy src to a
            arg1->unk0 = src->unk0;
            arg1->unk2 = src->unk2;
            arg1->unk4 = src->unk4;
            arg1->unk6 = src->unk6;
            // copy src to b
            arg2->unk0 = src->unk0;
            arg2->unk2 = src->unk2;
            arg2->unk4 = src->unk4;
            arg2->unk6 = src->unk6;

            *arg4 += 1;
            *arg5 += 1;

            if ((sp48[1] == 0) || ((sp48[1] == 2) && (sp48[2] == 0))) {
                var_s3 = 0;
            } else {
                var_s3 = 1;
            }
        }

        for (; i < arg3; i++) {
            switch (var_s3) {
            case 0:
                switch (sp48[i]) {
                case 0:
                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;
                    *arg4 += 1;
                    break;
                case 1:
                    temp_a0 = (arg6 << 6) + (arg7 << 6) + 0x40;

                    var_v1 = ABS((src[i].unk0 + src[i].unk2) - temp_a0);
                    var_a1 = ABS((src[i-1].unk0 + src[i-1].unk2) - temp_a0);

                    temp_a0 = var_v1 + var_a1;

                    var_s3 = 1;

                    arg1[*arg4].unk0 = ((var_a1 * src[i].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
                    arg1[*arg4].unk2 = ((var_a1 * src[i].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
                    arg1[*arg4].unk4 = ((var_a1 * src[i].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
                    arg1[*arg4].unk6 = ((var_a1 * src[i].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

                    arg2[*arg5].unk0 = arg1[*arg4].unk0;
                    arg2[*arg5].unk2 = arg1[*arg4].unk2;
                    arg2[*arg5].unk4 = arg1[*arg4].unk4;
                    arg2[*arg5].unk6 = arg1[*arg4].unk6;

                    *arg4 += 1;
                    *arg5 += 1;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg5 += 1;
                    break;
                case 2:
                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg4 += 1;
                    *arg5 += 1;

                    var_s3 = 1;
                    break;
                }
                break;
            case 1:
                switch (sp48[i]) {
                case 1:
                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;
                    *arg5 += 1;
                    break;
                case 0:
                    temp_a0 = (arg6 << 6) + (arg7 << 6) + 0x40;

                    var_v1 = ABS((src[i].unk0 + src[i].unk2) - temp_a0);
                    var_a1 = ABS((src[i-1].unk0 + src[i-1].unk2) - temp_a0);

                    temp_a0 = var_v1 + var_a1;

                    arg1[*arg4].unk0 = ((var_a1 * src[i].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
                    arg1[*arg4].unk2 = ((var_a1 * src[i].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
                    arg1[*arg4].unk4 = ((var_a1 * src[i].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
                    arg1[*arg4].unk6 = ((var_a1 * src[i].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

                    arg2[*arg5].unk0 = arg1[*arg4].unk0;
                    arg2[*arg5].unk2 = arg1[*arg4].unk2;
                    arg2[*arg5].unk4 = arg1[*arg4].unk4;
                    arg2[*arg5].unk6 = arg1[*arg4].unk6;
                    *arg4 += 1;
                    *arg5 += 1;

                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;
                    *arg4 += 1;

                    var_s3 = 0;
                    break;
                case 2:
                    arg1[*arg4].unk0 = src[i].unk0;
                    arg1[*arg4].unk2 = src[i].unk2;
                    arg1[*arg4].unk4 = src[i].unk4;
                    arg1[*arg4].unk6 = src[i].unk6;

                    arg2[*arg5].unk0 = src[i].unk0;
                    arg2[*arg5].unk2 = src[i].unk2;
                    arg2[*arg5].unk4 = src[i].unk4;
                    arg2[*arg5].unk6 = src[i].unk6;

                    *arg4 += 1;
                    *arg5 += 1;

                    var_s3 = 0;
                }
                break;
            case 2:
                break;
            }
        }

        if (((var_s3 == 1) && (sp48[0] == 0)) ||
            ((var_s3 == 0) && (sp48[0] == 1))) {

            temp_a0 = (arg6 << 6) + (arg7 << 6) + 0x40;

            var_v1 = ABS((src[0].unk0 + src[0].unk2) - temp_a0);
            var_a1 = ABS((src[i-1].unk0 + src[i-1].unk2) - temp_a0);
            temp_a0 = var_v1 + var_a1;

            arg1[*arg4].unk0 = ((var_a1 * src[0].unk0) + (var_v1 * src[i-1].unk0)) / temp_a0;
            arg1[*arg4].unk2 = ((var_a1 * src[0].unk2) + (var_v1 * src[i-1].unk2)) / temp_a0;
            arg1[*arg4].unk4 = ((var_a1 * src[0].unk4) + (var_v1 * src[i-1].unk4)) / temp_a0;
            arg1[*arg4].unk6 = ((var_a1 * src[0].unk6) + (var_v1 * src[i-1].unk6)) / temp_a0;

            arg2[*arg5].unk0 = arg1[*arg4].unk0;
            arg2[*arg5].unk2 = arg1[*arg4].unk2;
            arg2[*arg5].unk4 = arg1[*arg4].unk4;
            arg2[*arg5].unk6 = arg1[*arg4].unk6;

            *arg4 += 1;
            *arg5 += 1;
        }
    }
}

// ESA: func_8006EBD0
void func_8034F3EC_760A9C(struct061 *src, struct061 *arg1, struct061 *arg2, s16 numVtxs, s16 *arg4, s16 *arg5, s16 arg6) {

    s16 var_s2;
    s16 var_s3;
    s16 temp_t3;
    s16 var_t4;

    s16 i;
    s16 new_var;

    i = 1;
    new_var = src->unk0;
    var_s2 = new_var;

    if (new_var < arg6) {
        arg1->unk0 = src->unk0;
        arg1->unk2 = src->unk2;
        arg1->unk4 = src->unk4;
        arg1->unk6 = src->unk6;

        *arg4 = i;
        *arg5 = 0;
    } else {
        arg2->unk0 = src->unk0;
        arg2->unk2 = src->unk2;
        arg2->unk4 = src->unk4;
        arg2->unk6 = src->unk6;

        *arg4 = 0;
        *arg5 = i;
    }

    while (i < numVtxs) {
        var_s3 = src[i].unk0;

        if (var_s3 < arg6) {
            if (var_s2 < arg6) {
                arg1[*arg4].unk0 = src[i].unk0;
                arg1[*arg4].unk2 = src[i].unk2;
                arg1[*arg4].unk4 = src[i].unk4;
                arg1[*arg4].unk6 = src[i].unk6;
                *arg4 += 1;
            } else {
                var_t4 = ABS(var_s3 - arg6);
                var_s2 = ABS(var_s2 - arg6);
                temp_t3 = var_t4 + var_s2;

                arg1[*arg4].unk0 = arg6;
                arg1[*arg4].unk2 = ((var_s2 * src[i].unk2) + (var_t4 * src[i-1].unk2)) / temp_t3;
                arg1[*arg4].unk4 = ((var_s2 * src[i].unk4) + (var_t4 * src[i-1].unk4)) / temp_t3;
                arg1[*arg4].unk6 = ((var_s2 * src[i].unk6) + (var_t4 * src[i-1].unk6)) / temp_t3;

                arg2[*arg5].unk0 = arg1[*arg4].unk0;
                arg2[*arg5].unk2 = arg1[*arg4].unk2;
                arg2[*arg5].unk4 = arg1[*arg4].unk4;
                arg2[*arg5].unk6 = arg1[*arg4].unk6;
                *arg4 += 1;
                *arg5 += 1;

                arg1[*arg4].unk0 = src[i].unk0;
                arg1[*arg4].unk2 = src[i].unk2;
                arg1[*arg4].unk4 = src[i].unk4;
                arg1[*arg4].unk6 = src[i].unk6;
                *arg4 += 1;
            }
        } else if (var_s2 >= arg6) {
            arg2[*arg5].unk0 = src[i].unk0;
            arg2[*arg5].unk2 = src[i].unk2;
            arg2[*arg5].unk4 = src[i].unk4;
            arg2[*arg5].unk6 = src[i].unk6;
            *arg5 += 1;
        } else {
            var_t4 = ABS(var_s3 - arg6);
            var_s2 = ABS(var_s2 - arg6);
            temp_t3 = var_t4 + var_s2;

            arg1[*arg4].unk0 = arg6;
            arg1[*arg4].unk2 = ((var_s2 * src[i].unk2) + (src[i-1].unk2 * var_t4)) / temp_t3;
            arg1[*arg4].unk4 = ((var_s2 * src[i].unk4) + (src[i-1].unk4 * var_t4)) / temp_t3;
            arg1[*arg4].unk6 = ((var_s2 * src[i].unk6) + (src[i-1].unk6 * var_t4)) / temp_t3;

            arg2[*arg5].unk0 = arg1[*arg4].unk0;
            arg2[*arg5].unk2 = arg1[*arg4].unk2;
            arg2[*arg5].unk4 = arg1[*arg4].unk4;
            arg2[*arg5].unk6 = arg1[*arg4].unk6;
            *arg4 += 1;
            *arg5 += 1;

            arg2[*arg5].unk0 = src[i].unk0;
            arg2[*arg5].unk2 = src[i].unk2;
            arg2[*arg5].unk4 = src[i].unk4;
            arg2[*arg5].unk6 = src[i].unk6;
            *arg5 += 1;
        }
        var_s2 = var_s3;
        i++;
    }

    var_s3 = src->unk0;

    if (((var_s3 < arg6) && (var_s2 >= arg6)) ||
        ((var_s3 >= arg6) && (var_s2 < arg6))) {

        var_t4 = ABS(var_s3 - arg6);
        var_s2 = ABS(var_s2 - arg6);
        temp_t3 = var_t4 + var_s2;

        arg1[*arg4].unk0 = arg6;
        arg1[*arg4].unk2 = ((var_s2 * src->unk2) + (var_t4 * src[i-1].unk2)) / temp_t3;
        arg1[*arg4].unk4 = ((var_s2 * src->unk4) + (var_t4 * src[i-1].unk4)) / temp_t3;
        arg1[*arg4].unk6 = ((var_s2 * src->unk6) + (var_t4 * src[i-1].unk6)) / temp_t3;

        arg2[*arg5].unk0 = arg1[*arg4].unk0;
        arg2[*arg5].unk2 = arg1[*arg4].unk2;
        arg2[*arg5].unk4 = arg1[*arg4].unk4;
        arg2[*arg5].unk6 = arg1[*arg4].unk6;

        *arg4 += 1;
        *arg5 += 1;
    }
}

void func_8034FCFC_7613AC(struct061 *src, struct061 *arg1, struct061 *arg2, s16 numVtxs, s16 *arg4, s16 *arg5, s16 arg6) {
    s16 var_s2;
    s16 var_s3;
    s16 temp_t3;
    s16 var_t4;

    s16 i;
    s16 new_var;

    i = 1;

    new_var = src->unk2;
    var_s2 = new_var;

    if (new_var < arg6) {
        arg1->unk0 = src->unk0;
        arg1->unk2 = src->unk2;
        arg1->unk4 = src->unk4;
        arg1->unk6 = src->unk6;

        *arg4 = i;
        *arg5 = 0;
    } else {
        arg2->unk0 = src->unk0;
        arg2->unk2 = src->unk2;
        arg2->unk4 = src->unk4;
        arg2->unk6 = src->unk6;

        *arg4 = 0;
        *arg5 = i;
    }

    while (i < numVtxs) {
        var_s3 = src[i].unk2;
        do { } while (0); // only needed for ESA

        if (var_s3 < arg6) {
            if (var_s2 < arg6) {
                arg1[*arg4].unk0 = src[i].unk0;
                arg1[*arg4].unk2 = src[i].unk2;
                arg1[*arg4].unk4 = src[i].unk4;
                arg1[*arg4].unk6 = src[i].unk6;
                *arg4 += 1;
            } else {
                var_t4 = ABS(var_s3 - arg6);
                var_s2 = ABS(var_s2 - arg6);
                temp_t3 = var_t4 + var_s2;

                arg1[*arg4].unk2 = arg6;
                arg1[*arg4].unk0 = ((var_s2 * src[i].unk0) + (var_t4 * src[i-1].unk0)) / temp_t3;
                arg1[*arg4].unk4 = ((var_s2 * src[i].unk4) + (var_t4 * src[i-1].unk4)) / temp_t3;
                arg1[*arg4].unk6 = ((var_s2 * src[i].unk6) + (var_t4 * src[i-1].unk6)) / temp_t3;

                arg2[*arg5].unk0 = arg1[*arg4].unk0;
                arg2[*arg5].unk2 = arg1[*arg4].unk2;
                arg2[*arg5].unk4 = arg1[*arg4].unk4;
                arg2[*arg5].unk6 = arg1[*arg4].unk6;
                *arg4 += 1;
                *arg5 += 1;

                arg1[*arg4].unk0 = src[i].unk0;
                arg1[*arg4].unk2 = src[i].unk2;
                arg1[*arg4].unk4 = src[i].unk4;
                arg1[*arg4].unk6 = src[i].unk6;
                *arg4 += 1;
            }
        } else if (var_s2 >= arg6) {
            arg2[*arg5].unk0 = src[i].unk0;
            arg2[*arg5].unk2 = src[i].unk2;
            arg2[*arg5].unk4 = src[i].unk4;
            arg2[*arg5].unk6 = src[i].unk6;
            *arg5 += 1;
        } else {
            var_t4 = ABS(var_s3 - arg6);
            var_s2 = ABS(var_s2 - arg6);
            temp_t3 = var_t4 + var_s2;

            arg1[*arg4].unk2 = arg6;
            arg1[*arg4].unk0 = ((var_s2 * src[i].unk0) + (var_t4 * src[i-1].unk0)) / temp_t3;
            arg1[*arg4].unk4 = ((var_s2 * src[i].unk4) + (var_t4 * src[i-1].unk4)) / temp_t3;
            arg1[*arg4].unk6 = ((var_s2 * src[i].unk6) + (var_t4 * src[i-1].unk6)) / temp_t3;

            arg2[*arg5].unk0 = arg1[*arg4].unk0;
            arg2[*arg5].unk2 = arg1[*arg4].unk2;
            arg2[*arg5].unk4 = arg1[*arg4].unk4;
            arg2[*arg5].unk6 = arg1[*arg4].unk6;
            *arg4 += 1;
            *arg5 += 1;

            arg2[*arg5].unk0 = src[i].unk0;
            arg2[*arg5].unk2 = src[i].unk2;
            arg2[*arg5].unk4 = src[i].unk4;
            arg2[*arg5].unk6 = src[i].unk6;
            *arg5 += 1;
        }
        var_s2 = var_s3;
        i++;
    }

    var_s3 = src->unk2;

    if (((var_s3 < arg6) && (var_s2 >= arg6)) ||
        ((var_s3 >= arg6) && (var_s2 < arg6))) {

        var_t4 = ABS(var_s3 - arg6);
        var_s2 = ABS(var_s2 - arg6);
        temp_t3 = var_t4 + var_s2;

        arg1[*arg4].unk2 = arg6;
        arg1[*arg4].unk0 = (((var_s2 * src->unk0) + (var_t4 * src[i-1].unk0)) / temp_t3);
        arg1[*arg4].unk4 = (((var_s2 * src->unk4) + (var_t4 * src[i-1].unk4)) / temp_t3);
        arg1[*arg4].unk6 = (((var_s2 * src->unk6) + (var_t4 * src[i-1].unk6)) / temp_t3);

        arg2[*arg5].unk0 = arg1[*arg4].unk0;
        arg2[*arg5].unk2 = arg1[*arg4].unk2;
        arg2[*arg5].unk4 = arg1[*arg4].unk4;
        arg2[*arg5].unk6 = arg1[*arg4].unk6;

        *arg4 += 1;
        *arg5 += 1;
    }
}

#if 0
// CURRENT (9214)
// cant figure out the logic
// ESA: func_8006FC24
void func_80350600_761CB0(s16 numVtxs, struct061 *vtxs, s16 alpha, s16 arg3, s16 arg4, s32 arg5, u8 arg6, u8 arg7, s16 red, s16 green, s16 blue,
        s32 argB, s32 argC,
        s32 argD, s32 argE) {

    s16 temp_a2;
    s16 i;
    s16 temp_v0;
    s32 var_t0;
    s16 temp_t9;

    temp_t9 = ((ABS((s16) gCameras[gCameraId].unk7C - (s16) ((argB + argE) >> 1)) + 0x100) * 2) >> 8;
    if (temp_t9 > 4) {
        temp_t9 = (temp_t9 >> 1) + 2;
    }

    if ((D_80204278->usedVtxs + numVtxs) > 1000) {
        return;
    }

    if (arg6 != 0) {
        if (((arg7 == 0) && ((ABS(MAX(MAX(argB, argE), argD) - MIN(MIN(argB, argE), argD)) <= 192))) ||
            ((arg7 != 0) && ((ABS(MAX(MAX(argB, argE), argC) - MIN(MIN(argB, argE), argC)) <= 192)))) {

            gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

            for (i = 0; i < numVtxs; i++) {
                temp_v0 = vtxs[i].unk0 - (arg3 << 6);
                temp_a2 = vtxs[i].unk2 - (arg4 << 6);

                if (temp_v0 < temp_a2) {
                    var_t0 = ((((argE - argC) * temp_v0) + ((argC - argB) * temp_a2)) >> 6) + argB;
                } else {
                    var_t0 = ((((argD - argB) * temp_v0) + ((argE - argD) * temp_a2)) >> 6) + argB;
                }

                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = vtxs[i].unk0;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = vtxs[i].unk2;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = temp_t9 + var_t0;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = vtxs[i].unk4;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = vtxs[i].unk6;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
                D_80204278->usedVtxs++;
            }
        } else {
            return;
        }
    } else {
        if (((arg7 == 0) && (ABS(MAX(MAX(argB, argD), argC) - MIN(MIN(argD, argB), argC)) <= 192)) ||
            ((arg7 != 0) && (ABS(MAX(MAX(argD, argE), argC) - MIN(MIN(argD, argE), argC)) <= 192))) {

            gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

            for (i = 0; i < numVtxs; i++) {
                temp_v0 = vtxs[i].unk0 - (arg3 << 6);
                temp_a2 = vtxs[i].unk2 - (arg4 << 6);

                if ((temp_v0 + temp_a2) < 0x40) {
                    var_t0 = ((argB << 6) + ((argD - argB) * (       temp_v0)) + ((argC - argB) * (       temp_a2))) >> 6;
                } else {
                    var_t0 = ((argE << 6) + ((argC - argE) * (0x40 - temp_v0)) + ((argD - argE) * (0x40 - temp_a2))) >> 6;
                }
                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = vtxs[i].unk0;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = vtxs[i].unk2;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = temp_t9 + var_t0;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = vtxs[i].unk4;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = vtxs[i].unk6;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
                D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
                D_80204278->usedVtxs++;
            }
        } else {
            return;
        }
    }

    for (i = 2; i < numVtxs; i++) {
        if (i < (numVtxs - 1)) {
            gSP1Quadrangle(
            /* pkt  */ D_801D9E90++,
            /* v0   */ 0,
            /* v1   */ i - 1,
            /* v2   */ i,
            /* v3   */ i + 1,
            /* flag */ 0);
            i++;
        } else {
            gSP1Triangle(
            /* pkt  */ D_801D9E90++,
            /* v0   */ 0,
            /* v1   */ i - 1,
            /* v2   */ i,
            /* flag */ 0);
        }
    }
    gDPPipeSync(D_801D9E90++);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_80350600_761CB0.s")
#endif

// ESA: func_80070190
void func_80351390_762A40(s16 numVtxs, struct061 *arg1, s16 alpha, s16 arg3, s16 arg4, u16 arg5, s16 red, s16 green, s16 blue, s32 arg9, s32 argA, s32 argB, s32 argC) {
    s16 spD6;
    s16 spD4;

    s32 tmp;
    s16 i;
    s16 var_t1;
    s16 pad[2];


    if (numVtxs >= 3) {
        if (ABS(MAX(MAX(arg9, argC), MAX(argA, argB)) - MIN(MIN(arg9, argC), MIN(argA, argB))) <= 192) {

            var_t1 = ((ABS((s16) gCameras[gCameraId].unk7C - (s16) ((arg9 + argC) >> 1)) * 2) + 0x200) >> 8;
            if (var_t1 > 4) {
                var_t1 = (var_t1 >> 1) + 2;
            }

            if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
                gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

                for (i = 0; i < numVtxs; i++) {
                    spD6 = arg1[i].unk0 - (arg3 << 6);
                    spD4 = arg1[i].unk2 - (arg4 << 6);
                    tmp = arg9 + ((((argB - arg9) * spD6) + ((argA - arg9) * spD4)) >> 6);
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = tmp + var_t1;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
                    D_80204278->usedVtxs++;
                }

                for (i = 2; i < numVtxs; i++) {
                    if (i < (numVtxs - 1)) {
                        gSP1Quadrangle(
                            D_801D9E90++,
                            0,
                            i - 1,
                            i,
                            i + 1,
                            0);
                        i++; // 2 vtx were processed
                    } else {
                        gSP1Triangle(
                            D_801D9E90++,
                            0,
                            i - 1,
                            i,
                            0);
                    }
                }
                gDPPipeSync(D_801D9E90++);
            }
        }
    }
}

// ESA: func_800704EC (tbd)
void func_80351A44_7630F4(s16 numVtxs, struct061 *arg1, s16 alpha, s16 arg3, s16 arg4, s16 red, s16 green, s16 blue) {
    s16 pad[2];

    s16 temp_v0;
    s16 var_a3;
    s16 temp_a0;
    s16 i;

    s16 sp82;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;

    if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
        func_80299640_6AACF0(arg3, arg4, &sp82, &sp80, &sp7E, &sp7C);
        gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

        for (i = 0; i < numVtxs; i++) {
            func_80299640_6AACF0(arg3, arg4, &sp82, &sp80, &sp7E, &sp7C);

            temp_v0 = arg1[i].unk0 - (arg3 << 6);
            temp_a0 = arg1[i].unk2 - (arg4 << 6);
            if ((temp_v0 + temp_a0) < 0x40) {
                var_a3 = sp82 + ((((sp7E - sp82) * (0  + temp_v0)) + ((sp80 - sp82) * (0  + temp_a0))) >> 6);
            } else {
                var_a3 = sp7C + ((((sp80 - sp7C) * (64 - temp_v0)) + ((sp7E - sp7C) * (64 - temp_a0))) >> 6);
            }

            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = var_a3;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
            D_80204278->usedVtxs++;
        }

        for (i = 2; i < numVtxs; i++) {
            if (i < (numVtxs - 1)) {
                gSP1Quadrangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    i + 1,
                    0);
                i++; // 2 vtx were processed
            } else {
                gSP1Triangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    0);
            }
        }
        gDPPipeSync(D_801D9E90++);
    }
}

// ESA: func_8007080C (tbd)
void func_80351EE8_763598(s16 numVtxs, struct061 *arg1, s16 arg2, s16 alpha, s16 red, s16 green, s16 blue) {
    s16 var_a3;
    s32 var_v1;

    s16 i;

    var_v1 = ABS((s16) (s32) gCameras[gCameraId].unk7C - arg2);
    var_a3 = ((var_v1 * 2) + 0x80) >> 7;
    if (var_a3 > 4) {
        var_a3 = (var_a3 / 2) + 4;
    }

    if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
        gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);
        for (i = 0; i < numVtxs; i++) {
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = var_a3 + arg2;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
            D_80204278->usedVtxs++;
        }

        for (i = 2; i < numVtxs; i++) {
            if (i < (numVtxs - 1)) {
                gSP1Quadrangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    i + 1,
                    0);
                i++; // 2 vtx were processed
            } else {
                gSP1Triangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    0);
            }
        }
        gDPPipeSync(D_801D9E90++);
    }
}
