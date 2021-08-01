#include <ultra64.h>
#include "common.h"


void func_8029B870_6ACF20(Animal *arg0, Animal *arg1) {
    s32 dist = ((arg0->xPos - arg1->xPos) * (arg0->xPos - arg1->xPos)) +
               ((arg0->zPos - arg1->zPos) * (arg0->zPos - arg1->zPos));
    if ((arg1->state == 1) &&
        (D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) &&
        (dist < 800) && (arg0->unk16C->unk80.bit) &&
        (arg1->unk248[1] != NULL) && (arg0->unk320 == 0)) {
        Animal *tmp;
        arg1->unk158 = 1;
        arg0->xPos = arg1->xPos;
        arg0->zPos = arg1->zPos;
        D_803D2D90.unk4C = arg1->xPos;
        D_803D2D90.unk4E = arg1->zPos;
        D_803D2D90.unk50 = arg1->yPos;
        D_803D2D90.unk2 = 0x36;
        tmp = arg1->unk248[1];
        D_803D2D90.unk60 = tmp;
        D_803D2D90.unk5C = arg1;
        D_803D2D90.unk52 = tmp->xPos;
        D_803D2D90.unk54 = tmp->zPos;
        D_803D2D90.unk56 = tmp->yPos;
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
    D_803D2D90.unk52 = arg1->xPos;
    D_803D2D90.unk54 = arg1->zPos;
    D_803D2D90.unk56 = arg1->yPos;
    D_803D2D90.unk58 = arg0;
    D_803D2D90.unk58->xPos = D_803D2D90.unk52;
    D_803D2D90.unk58->zPos = D_803D2D90.unk54;
    D_803D2D90.unk58->yPos = D_803D2D90.unk56 + 8;
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
        s32 dist = ((arg0->xPos - arg1->xPos) * (arg0->xPos - arg1->xPos)) +
                   ((arg0->zPos - arg1->zPos) * (arg0->zPos - arg1->zPos));
        if ((D_803D2D90.unk0 == 0) && (D_803D2D90.unk64 == 0) && (dist < 0x320)) {
            arg1->unk158 = 1;
            D_803D2D90.unk5C = arg1;
            D_803D2D90.unk60 = 0;
            D_803D2D90.unk4C = arg1->xPos;
            D_803D2D90.unk4E = arg1->zPos;
            D_803D2D90.unk50 = arg1->yPos;
            D_803D2D90.unk46 = D_803D2D90.unk4C;
            D_803D2D90.unk48 = D_803D2D90.unk4E;
            D_803D2D90.unk4A = D_803D2D90.unk50;
            D_803D2D90.unk52 = arg1->xPos;
            D_803D2D90.unk54 = arg1->zPos;
            D_803D2D90.unk56 = arg1->yPos;
            D_803D2D90.unk58 = arg0;
            arg0->xPos = arg1->xPos;
            arg0->zPos = arg1->zPos;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029CEF0_6AE5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D0A8_6AE758.s")

void func_8029D89C_6AEF4C(void) {
    s16 i;

    D_803D2E08[0] = -1;
    D_803D2E08[1] = -1;
    for (i = 0; i < 64; i++) {
        D_803D2E08[i+2] = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029D8D8_6AEF88.s")
// void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1) {
//     u8 *phi_a2;
//     u8 *phi_v1;
//     s32 phi_at;
//     // this is currently nonsense
//     if (arg1 < 8) {
//         phi_a2 = &D_800BA760->unk1D4C0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9);
//         phi_at = 0x214C0;
//     } else {
//         arg1 = arg1 - 8;
//         phi_a2 = &D_800BA760->unk1ACC0[arg1]; //  << 0xB
//         phi_v1 = &D_800BA760 + (arg1 << 9);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029DB20_6AF1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029DD84_6AF434.s")
// NON-MATCHING: 80%-ish of the way there
// void func_8029DD84_6AF434(void) {
//     s32 current_texture;
//     s32 temp_t8_2;
//     struct057 *temp_s1;
//     s32 loaded_texture;
//     s16 i;
//
//     gSPDisplayList(D_801D9E90++, &D_010049A0_3E270);
//     gSPSetGeometryMode(D_801D9E90++, D_803C0650_7D1D00);
//     gSPDisplayList(D_801D9E90++, &D_01004510);
//
//     gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
//     gDPSetCombineLERP(D_801D9E90++, SHADE, 0, COMBINED, 0, 0, 0, 0, PRIMITIVE, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0, 0, PRIMITIVE);
//     gDPSetPrimColor(D_801D9E90++, 0, 0, 0, 0, 0, 128);
//
//     loaded_texture = 255;
//     for (i = 0; i < D_803D5508; i++) {
//         temp_s1 = (((i * 8) - i) * 4) + &D_803D5188;
//         current_texture = temp_s1->unk18 & 0x3F;
//         // if we need to load a new texture, do so?
//         if (loaded_texture != current_texture ) {
//             // are these "europe" textures, or just intro or first level? or biome specific?
//             gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_800BA760[current_texture]);
//             gDPTileSync(D_801D9E90++);
//             gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//             gDPTileSync(D_801D9E90++);
//             gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1372, 0);
//             gDPTileSync(D_801D9E90++);
//             loaded_texture = current_texture;
//         }
//         if (D_803D3434->usedModelViewMtxs < 250) {
//             temp_t8_2 = temp_s1->unk2 << 5;
//             func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
//                 temp_s1->unk4, temp_s1->unk8, temp_s1->unkC,
//                 temp_s1->unk10, temp_s1->unk12, temp_t8_2, temp_t8_2, temp_t8_2);
//
//             gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//             D_803D3434->usedModelViewMtxs += 1;
//
//             gSPClearGeometryMode(D_801D9E90++, G_CULL_BACK);
//             gSPDisplayList(D_801D9E90++, temp_s1->unk14);
//             gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
//         }
//     }
//     D_803D5508 = 0;
//     gSPSetGeometryMode(D_801D9E90++, G_CULL_BACK);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029E100_6AF7B0.s")

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

    for (i = 0; i < 0x30; i++) {
        D_803D3448.unk2[i] = -1;
        D_803D3A20.unk2[i] = -1;
        D_803D3FF8.unk2[i] = -1;
    }
    func_8029D89C_6AEF4C();
    D_803D5508 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6ACF20/func_8029F464_6B0B14.s")


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
