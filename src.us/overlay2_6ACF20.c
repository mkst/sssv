#include <ultra64.h>
#include "common.h"


void func_8029B870_6ACF20(Animal *arg0, Animal *arg1) {
    s32 dist = ((arg0->xPos.h - arg1->xPos.h) * (arg0->xPos.h - arg1->xPos.h)) +
               ((arg0->zPos.h - arg1->zPos.h) * (arg0->zPos.h - arg1->zPos.h));
    if ((arg1->state == 1) &&
        (D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) &&
        (dist < 800) && (arg0->unk16C->unk80.bit) &&
        (arg1->unk248[1] != NULL) && (arg0->unk320 == 0)) {
        Animal *tmp;
        arg1->unk158 = 1;
        arg0->xPos.h = arg1->xPos.h;
        arg0->zPos.h = arg1->zPos.h;
        D_803D2D90.unk4C = arg1->xPos.h;
        D_803D2D90.unk4E = arg1->zPos.h;
        D_803D2D90.unk50 = arg1->yPos.h;
        D_803D2D90.unk2 = 0x36;
        tmp = arg1->unk248[1];
        D_803D2D90.unk60 = tmp;
        D_803D2D90.unk5C = arg1;
        D_803D2D90.unk52 = tmp->xPos.h;
        D_803D2D90.unk54 = tmp->zPos.h;
        D_803D2D90.unk56 = tmp->yPos.h;
        D_803D2D90.unk58 = arg0;
        D_803D2D90.unk0 = 1;
        D_803D2D90.unk46 = D_803D2D90.unk4C;
        D_803D2D90.unk48 = D_803D2D90.unk4E;
        D_803D2D90.unk4A = D_803D2D90.unk50;
        func_802B33D0_6C4A80(arg0);
        arg0->unk364 = 16;
        arg0->unk334 = D_803D5544;
    }
}

void func_8029B9B8_6AD068(Animal *arg0, Animal *arg1) {
    D_803D2D90.unk5C = 0;
    D_803D2D90.unk60 = arg1;
    D_803D2D90.unk52 = arg1->xPos.h;
    D_803D2D90.unk54 = arg1->zPos.h;
    D_803D2D90.unk56 = arg1->yPos.h;
    D_803D2D90.unk58 = arg0;
    D_803D2D90.unk58->xPos.h = D_803D2D90.unk52;
    D_803D2D90.unk58->zPos.h = D_803D2D90.unk54;
    D_803D2D90.unk58->yPos.h = D_803D2D90.unk56 + 8;
    D_803D2D90.unk58->xVelocity.w = 0;
    D_803D2D90.unk58->zVelocity.w = 0;
    D_803D2D90.unk58->yVelocity.w = 0;
    D_803D2D90.unk58->unk68 = D_803D2D90.unk60;
    D_803D2D90.unk58->unk70 = 0;
    D_803D2D90.unk58->unk160 = D_803D2D90.unk60->unk160;
    D_803D2D90.unk0 = 3;
    D_803D2D90.unk2 = 55;
    arg0->unk364 = 16;
    arg0->unk334 = D_803D5544 - 150;
}

void func_8029BA70_6AD120(Animal *arg0, Animal *arg1) {
    if (arg1->state != 0) {
        s32 dist = ((arg0->xPos.h - arg1->xPos.h) * (arg0->xPos.h - arg1->xPos.h)) +
                   ((arg0->zPos.h - arg1->zPos.h) * (arg0->zPos.h - arg1->zPos.h));
        if ((D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) && (dist < 0x320)) {
            arg1->unk158 = 1;
            D_803D2D90.unk5C = arg1;
            D_803D2D90.unk60 = 0;
            D_803D2D90.unk4C = arg1->xPos.h;
            D_803D2D90.unk4E = arg1->zPos.h;
            D_803D2D90.unk50 = arg1->yPos.h;
            D_803D2D90.unk46 = D_803D2D90.unk4C;
            D_803D2D90.unk48 = D_803D2D90.unk4E;
            D_803D2D90.unk4A = D_803D2D90.unk50;
            D_803D2D90.unk52 = arg1->xPos.h;
            D_803D2D90.unk54 = arg1->zPos.h;
            D_803D2D90.unk56 = arg1->yPos.h;
            D_803D2D90.unk58 = arg0;
            arg0->xPos.h = arg1->xPos.h;
            arg0->zPos.h = arg1->zPos.h;
            D_803D2D90.unk0 = 1;
            D_803D2D90.unk2 = 56;
            func_802B33D0_6C4A80(arg0);
            arg0->unk364 = 17;
            arg0->unk334 = D_803D5544;
            func_8035739C_768A4C();
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029BB94_6AD244.s")

// bunch of display lists
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029C8F0_6ADFA0.s")

void func_8029CEF0_6AE5A0(s32 arg0, s32 arg1, s32 arg2, u16 arg3, u8 arg4, struct059 *arg5, s8 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s8 tmp;

    arg5->unk1++;
    if (arg5->unk1 < 75) {
        arg5->unk44[arg5->unk1].unk0 = arg0; // x
        arg5->unk44[arg5->unk1].unk4 = arg1; // z
        arg5->unk44[arg5->unk1].unk8 = arg2; // y
        arg5->unk44[arg5->unk1].unkC = arg3; // ?
        arg5->unk44[arg5->unk1].unkE = arg4; // ?
        arg5->unk44[arg5->unk1].unk10 = arg6; // ?
        arg5->unk44[arg5->unk1].unk11 = arg7; // red
        arg5->unk44[arg5->unk1].unk12 = arg8; // green
        arg5->unk44[arg5->unk1].unk13 = arg9; // blue

        tmp = arg5->unk2[arg4];

        if (tmp == -1) {
            arg5->unk44[arg5->unk1].unkF = -1;
            arg5->unk2[arg4] = arg5->unk1;
            if (arg5->unk0 != -1) {
                arg5->unk44[arg5->unk0].unkF = arg5->unk1;
            }
            arg5->unk0 = arg5->unk1;
        } else {
            arg5->unk44[arg5->unk1].unkF = arg5->unk44[tmp].unkF;
            arg5->unk44[tmp].unkF = arg5->unk1;

            arg5->unk2[arg4] = arg5->unk1;
            if (arg5->unk44[arg5->unk1].unkF == -1) {
                arg5->unk0 = arg5->unk1;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D0A8_6AE758.s")

void func_8029D89C_6AEF4C(void) {
    s16 i;
    // struct059
    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
    for (i = 0; i < 64; i++) {
        D_803D2E08.unk2[i] = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D8D8_6AEF88.s")
// void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1) {
//     u8 *phi_a2;
//     u8 *phi_v1;
//     s32 phi_at;
//     // this is currently nonsense
//     if (arg1 < 8) {
//         // offset is 120000
//         phi_a2 = &D_800BA760->unk1D4C0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9);
//         phi_at = 0x214C0;
//     } else {
//         // 2048 size?
//         arg1 = arg1 - 8;
//         // offset is 109760
//         phi_a2 = &D_800BA760->unk1ACC0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9); // 512 size?
//         phi_at = 0x1CCC0;
//     }
//
//     gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, (s32)phi_a2 + 0x80000000);
//     gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync((*arg0)++);
//     gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 4*31, 4*31);
//     gDPPipeSync((*arg0)++);
//     gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);
//
//     gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, (s32)phi_v1 + phi_at + 0x80000000);
//     gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync((*arg0)++);
//     gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 4*31);
//     gDPPipeSync((*arg0)++);
//     gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize((*arg0)++, 1, 0, 0, 4*31, 4*31);
// }

void func_8029DB20_6AF1D0(u8 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s32 arg7) {
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_f8;
    s32 temp_t1;
    s16 idx;
    s16 phi_v1;

    temp_f16 = D_803F2C44 - (arg2 >> 16);
    temp_f10 = D_803F2C48 - (arg3 >> 16);
    temp_f8 = D_803F2C4C - (arg4 >> 16);

    temp_t1 = sqrtf((temp_f16 * temp_f16) + (temp_f10 * temp_f10) + (temp_f8 * temp_f8));
    if (D_803D5508 == 0) {
        D_803D5188[0].unk14 = arg7;
        D_803D5188[0].unk18 = arg0;
        D_803D5188[0].unk4 = arg2;
        D_803D5188[0].unk8 = arg3;
        D_803D5188[0].unkC = arg4;
        D_803D5188[0].unk10 = arg5;
        D_803D5188[0].unk12 = arg6;
        D_803D5188[0].unk2 = arg1;
        D_803D5188[0].unk0 = temp_t1;
        D_803D5508++;
        return;
    }

    if (D_803D5508 < 32) {

        for (idx = 0; ((idx < D_803D5508) && (temp_t1 < D_803D5188[idx].unk0)); idx++) {};

        for (phi_v1 = D_803D5508; phi_v1 > idx; phi_v1--) {
            D_803D5188[phi_v1] = D_803D5188[phi_v1 - 1];
        }

        D_803D5188[idx].unk18 = arg0;
        D_803D5188[idx].unk14 = arg7;
        D_803D5188[idx].unk4 = arg2;
        D_803D5188[idx].unk8 = arg3;
        D_803D5188[idx].unkC = arg4;
        D_803D5188[idx].unk0 = temp_t1;
        D_803D5188[idx].unk10 = arg5;
        D_803D5188[idx].unk12 = arg6;
        D_803D5188[idx].unk2 = arg1;
        D_803D5508++;
    }
}

#ifdef NON_MATCHING
void func_8029DD84_6AF434(void) {
    u8 current_texture;
    u8 loaded_texture;
    s16 i;

    gSPDisplayList(D_801D9E90++, &D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E90++, D_803C0650_7D1D00);
    gSPDisplayList(D_801D9E90++, &D_01004510);

    gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
    gDPSetCombineLERP(D_801D9E90++, SHADE, 0, COMBINED, 0, 0, 0, 0, PRIMITIVE, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0, 0, PRIMITIVE);
    gDPSetPrimColor(D_801D9E90++, 0, 0, 0, 0, 0, 128);

    loaded_texture = 255;
    for (i = 0; i < D_803D5508; i++) {
        current_texture = D_803D5188[i].unk18 & 0x3F;
        // if we need to load a new texture, do so?
        if (current_texture != loaded_texture) {
            loaded_texture = current_texture;
            // are these "europe" textures, or just intro or first level? or biome specific?
            gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_800BA760[current_texture ^ 0]); // regalloc fix
            gDPTileSync(D_801D9E90++);
            gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPTileSync(D_801D9E90++);
            gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1372, 0);
            gDPTileSync(D_801D9E90++);
        }

        if (D_803D3434->usedModelViewMtxs < 250) {
            func_80125FE0(
                &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
                D_803D5188[i].unk4,
                D_803D5188[i].unk8,
                D_803D5188[i].unkC,
                D_803D5188[i].unk10,
                D_803D5188[i].unk12,
                D_803D5188[i].unk2 << 5,
                D_803D5188[i].unk2 << 5,
                D_803D5188[i].unk2 << 5);

            gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            D_803D3434->usedModelViewMtxs++;

            gSPClearGeometryMode(D_801D9E90++, G_CULL_BACK);
            gSPDisplayList(D_801D9E90++, D_803D5188[i].unk14);
            gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
        } else {
            break;
        }
    }
    D_803D5508 = 0;
    gSPSetGeometryMode(D_801D9E90++, G_CULL_BACK);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029DD84_6AF434.s")
#endif

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA32;

#if 0
{
    // 007b1bf0
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0xff }, // #ffffff
    { 0xff, 0x00, 0x00, 0x00 }, // #ff0000
    { 0xff, 0x00, 0x00, 0xff }, // #ff0000
    // 007b1c00
    { 0x00, 0xff, 0x00, 0x00 }, // #00ff00
    { 0x00, 0xff, 0x00, 0xff }, // #00ff00
    { 0x00, 0x00, 0xff, 0x00 }, // #0000ff
    { 0x00, 0x00, 0xff, 0xff }, // #0000ff
    // 007b1c10
    { 0x50, 0x50, 0x50, 0x00 }, // #505050
    { 0x50, 0x50, 0x50, 0xff }, // #505050
    { 0xff, 0xff, 0x00, 0x00 }, // #ffff00
    { 0xff, 0xff, 0x00, 0xff }, // #ffff00
    // 007b1c20
    { 0x00, 0x00, 0x00, 0x00 }, // #000000
    { 0x00, 0x00, 0x00, 0xff }, // #000000
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0xff }, // #ffffff
    // 007b1c30
    { 0xff, 0xd9, 0x00, 0x1b }, // #ffd900
    { 0x00, 0x00, 0x00, 0x2a }, // #000000
    { 0xff, 0xa0, 0x00, 0x18 }, // #ffa000
    { 0x00, 0x00, 0x00, 0x6e }, // #000000
}

RGBA D_803A0594_7B1C44[4] = {
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0xff, 0xff, 0xff, 0x00 }, // #ffffff
    { 0x5e, 0x72, 0xff, 0x00 }, // #5e72ff
    { 0x77, 0xc4, 0xff, 0x00 }, // #77c4ff
};

#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E100_6AF7B0.s")
// void func_8029E100_6AF7B0(void) {
//     s16 temp_s0;
//     s16 temp_s5;
//     s32 temp_a2;
//     s32 temp_t0;
//     s32 temp_t3;
//     s32 temp_t7;
//     s32 temp_v0;
//     s32 temp_v1_2;
//     u16 temp_t4;
//     u8 temp_s4;
//     void *temp_a1;
//     void *temp_a1_2;
//     void *temp_s1;
//     void *temp_s1_2;
//     void *temp_s1_3;
//     void *temp_s1_4;
//     void *temp_s1_5;
//     void *temp_s1_6;
//     RGBA32 *rgba;
//     void *phi_s1;
//     s16 phi_s5;
//     s16 phi_s6;
//     s32 phi_s0;
//     void *phi_s1_2;
//     void *phi_s1_3;
//
//     // temp_a1 = D_801D9E90;
//     // D_801D9E90 = temp_a1 + 8;
//     // temp_a1->unk0 = 0x06000000;
//     // temp_a1->unk4 = 0x010049E8;
//     gSPDisplayList(D_801D9E90++, D_010049E8);
//
//     phi_s1 = D_803D3434->unk3B318;
//     phi_s5 = 0;
//     phi_s6 = 0;
//     if ((s32) D_803E97C0 > 0) {
//         do {
//             // temp_a1_2 = D_801D9E90;
//             // D_801D9E90 = temp_a1_2 + 8;
//             // temp_a1_2->unk4 = phi_s1;
//             // temp_a1_2->unk0 = 0x06000000;
//             gSPDisplayList(D_801D9E90++, D_803D3434->unk3B318);
//
//             temp_s4 = D_803D3434->unk3B30A[phi_s5];
//             temp_s1 = phi_s1 + 8;
//
//             phi_s1->unk0 = (s32) ((((temp_s4 << 0xA) | ((temp_s4 * 0x10) - 1)) & 0xFFFF) | 0x04000000);
//             phi_s1->unk4 = (D_803D3434->unk39C88[phi_s6 * 0x10]; // + (phi_s6 * 0x10) );
//
//             // temp_s1->unk0 = 0xBE000000;
//             // temp_s1->unk4 = 0xE;
//             gSPCullDisplayList(phi_s1++, 0, 7);
//             temp_s1_2 = temp_s1 + 8;
//             temp_s1_3 = temp_s1_2 + 8;
//             temp_t7 = SSSV_RAND(4) * 4;
//             // temp_s1_2->unk4 = 0x5000;
//             // temp_s1_2->unk0 = 0xFB000000;
//             rgba = &D_803A0594_7B1C44[(temp_t7 & 0xFFFF)]; // rgba
//             gDPSetEnvColor(phi_s1++, 0x00, 0x00, 0x50, 0x00);
//             gDPSetPrimColor(phi_s1++, 0, 0, rgba->r, rgba->g, rgba->b, rgba->a);
//
//             // temp_s1_3->unk0 = 0xFA000000;
//             // temp_s1_3->unk4 = (s32) (temp_v1->unk3 | (temp_v1->unk0 << 0x18) | (temp_v1->unk1 << 0x10) | (temp_v1->unk2 << 8));
//             temp_s1_4 = temp_s1_3 + 8;
//             temp_t0 = temp_s4 - 9;
//             phi_s0 = 0;
//             phi_s1_2 = temp_s1_4;
//             phi_s1_3 = temp_s1_4;
//             if (temp_t0 > 0) {
//                 do {
//                     temp_v1_2 = -(s32) ((((s32) D_803A05A4_7B1C54.unk0 >> 2) + (phi_s0 >> 2)) << 7);
//                     temp_v0 = phi_s0 * 2;
//                     phi_s1_2->unk0 = (s32) (((temp_v1_2 & 0xFFF) << 0xC) | 0xF2000000);
//                     temp_t3 = (temp_v0 + 0x16) & 0xFF;
//                     temp_a2 = ((temp_v0 + 0x10) & 0xFF) << 0x10;
//                     phi_s1_2->unk4 = (s32) ((((temp_v1_2 + 0x7F) & 0xFFF) << 0xC) | 0x3F);
//                     temp_s0 = phi_s0 + 4;
//                     temp_s1_5 = phi_s1_2 + 8;
//                     temp_s1_5->unk0 = (s32) (temp_a2 | (temp_t3 << 8) | ((temp_v0 + 0x12) & 0xFF) | 0xB1000000);
//                     temp_s1_5->unk4 = (s32) (temp_a2 | (((temp_v0 + 0x14) & 0xFF) << 8) | temp_t3);
//                     temp_s1_6 = temp_s1_5 + 8;
//                     phi_s0 = (s32) temp_s0;
//                     phi_s1_2 = temp_s1_6;
//                     phi_s1_3 = temp_s1_6;
//                 } while ((s32) temp_s0 < temp_t0);
//             }
//             // phi_s1_3->unk0 = 0xB8000000;
//             // phi_s1_3->unk4 = 0;
//             gSPEndDisplayList(phi_s1++);
//
//             phi_s5 = phi_s5 + 1;
//             // phi_s1 = phi_s1_3 + 8;
//             // phi_s5 = phi_s5;
//             phi_s6 = (s16) (phi_s6 + temp_s4);
//         } while (phi_s5 < D_803E97C0);
//     }
//     temp_t4 = D_803A05A4_7B1C54.unk0 + 4;
//     D_803A05A4_7B1C54.unk0 = temp_t4;
//     D_803A05A4_7B1C54.unk5A4 = (s16) (temp_t4 & 0xF);
// }

void func_8029E3CC_6AFA7C(void) {
    if (D_803D3434->usedModelViewMtxs < 250) {
        func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D343C->unk4, D_803D343C->unk8, D_803D343C->unkC + (D_803D343C->unk42 << 0xF),
            D_803D343C->unk2E, D_803D343C->unk2C,
            D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_803D3434->usedModelViewMtxs += 1;
        gSPDisplayList(D_801D9E8C++, D_803D3438[D_803D343C->unk64]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E528_6AFBD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E7D0_6AFE80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029EAAC_6B015C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029EF20_6B05D0.s")

void func_8029F218_6B08C8(void) {
    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, D_803C0650_7D1D00);
    gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
    gSPDisplayList(D_801D9E8C++, D_01004510);

    if (D_803D3448.unk1 != -1) {
        func_8029EF20_6B05D0(&D_803D3448, &D_801D9E8C);
    }
    if (D_803D3A20.unk1 != -1) {
        gDPPipeSync(D_801D9E8C++);
        gSPTexture(D_801D9E8C++, 32768, 32768, 1, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(D_801D9E8C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E8C++, 0x00, 0x00, 0x00, 0x00);
        gDPSetRenderMode(D_801D9E8C++, D_803C0640_7D1CF0 , 0x113078);
        gDPSetCombineMode(D_801D9E8C++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
        func_8029EF20_6B05D0(&D_803D3A20, &D_801D9E8C);
    }
}

void func_8029F3CC_6B0A7C(void) {
    s16 i;

    D_803D3448.unk0 = -1;
    D_803D3448.unk1 = -1;
    D_803D3A20.unk0 = -1;
    D_803D3A20.unk1 = -1;
    D_803D3FF8.unk0 = -1;
    D_803D3FF8.unk1 = -1;
    D_803D45D0 = -1;
    D_803D4BB1 = -1;

    for (i = 0; i < 48; i++) {
        D_803D3448.unk2[i] = -1;
        D_803D3A20.unk2[i] = -1;
        D_803D3FF8.unk2[i] = -1;
    }
    func_8029D89C_6AEF4C();
    D_803D5508 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029F464_6B0B14.s")
// what are these offsets?
// void func_8029F464_6B0B14(struct059 *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8) {
//     s8 tmp;
//     // arg1 is a 0..63
//     if (arg0->unk1 < 59) {
//         tmp = arg0->unk2[arg1];
//         if (tmp == -1) {
//             arg0->unk1++;
//             arg0->unk44[arg0->unk1].unk0  = arg1; // + arg0->unk1)->unk32 = arg1; //temp_t6;
//             arg0->unk44[arg0->unk1].unk4  = arg8; // + (arg0->unk1 * 4))->unk4E4 = arg8;
//             arg0->unk44[arg0->unk1].unk8  = arg6; // + (arg0->unk1 * 4))->unk3F4 = arg6;
//             arg0->unk44[arg0->unk1].unkC  = arg7; // + (arg0->unk1 * 4))->unk3F6 = arg7;
//             arg0->unk44[arg0->unk1].unkE  = arg2; // + (arg0->unk1 * 2))->unkAA = (s16) arg2;
//             arg0->unk44[arg0->unk1].unk10 = arg3; // + (arg0->unk1 * 12))->unk124 = arg3;
//             arg0->unk44[arg0->unk1].unk11 = arg4; // + (arg0->unk1 * 12))->unk128 = arg4;
//             arg0->unk44[arg0->unk1].unk12 = arg5; // + (arg0->unk1 * 12))->unk12C = arg5;
//
//             arg0->unk44[arg0->unk1].unk13 = -1; // + arg0->unk1)->unk6E = -1;
//
//             arg0->unk2[arg1] = arg0->unk1;
//             if (arg0->unk0 != -1) {
//                 arg0->unk44[arg0->unk0].unkF = arg0->unk1; // (arg0 + arg0->unk0)->unk6E
//             }
//             arg0->unk0 = arg0->unk1;
//         } else {
//             arg0->unk1++;
//             arg0->unk44[arg0->unk1].unk0 = arg1; //(arg0 + arg0->unk1)->unk32 = arg1; //temp_t6;
//             arg0->unk44[arg0->unk1].unk4 = arg8; //(arg0 + (arg0->unk1 * 4))->unk4E4 = arg8;
//             arg0->unk44[arg0->unk1].unk8 = arg6; //(arg0 + (arg0->unk1 * 4))->unk3F4 = arg6;
//             arg0->unk44[arg0->unk1].unkC = arg7; //(arg0 + (arg0->unk1 * 4))->unk3F6 = arg7;
//             arg0->unk44[arg0->unk1].unkE = arg2; //(arg0 + (arg0->unk1 * 2))->unkAA = (s16) arg2;
//             arg0->unk44[arg0->unk1].unk10 = arg3; //(arg0 + (arg0->unk1 * 0xC))->unk124 = arg3;
//             arg0->unk44[arg0->unk1].unk11 = arg4; //(arg0 + (arg0->unk1 * 0xC))->unk128 = arg4;
//             arg0->unk44[arg0->unk1].unk12 = arg5; //(arg0 + (arg0->unk1 * 0xC))->unk12C = arg5;
//
//             arg0->unk44[arg0->unk1].unkF = arg0->unk44[tmp].unkF;
//             arg0->unk44[tmp].unkF = arg0->unk1;
//
//             if (arg0->unk44[arg0->unk1].unkF == -1) {
//                 arg0->unk0 = arg0->unk1;
//             }
//         }
//     }
// }

void func_8029F65C_6B0D0C(Animal *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s32 arg8) {
    arg5 += arg0->unk42 << 0xF;

    if ((arg1 & 0xC0) == 0xC0) { // both flags set?
        func_8029F464_6B0B14(&D_803D3FF8, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else if ((arg1 & 0x40)) {
        func_8029F464_6B0B14(&D_803D3A20, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else if ((arg1 & 0x80)) {
        func_8029DB20_6AF1D0(arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    } else {
        func_8029F464_6B0B14(&D_803D3448, arg1 & 0x3F, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029F7D4_6B0E84.s")
