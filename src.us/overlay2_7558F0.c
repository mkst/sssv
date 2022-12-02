#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80344240_7558F0.s")

void func_803458B8_756F68(Gfx **arg0, Vtx *vtx, s16 num) {
    gSPVertex((*arg0)++, K0_TO_PHYS(vtx), num, 0);
}

// a long way to go here
#if 0
void func_803458FC_756FAC(Gfx **dl, s32 arg1, s16 numTris) {
    s16 sp17A;
    s16 sp178;
    u8 sp175;
    s16 *sp4C;
    s16 *temp_t2;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_v0_6;
    s32 temp_a0;
    s32 temp_t9;
    u16 temp_v1;
    u8 temp_s6;
    struct102 *temp_v0;
    struct073 *temp_v0_4;
    s16 phi_t3;
    s16 *phi_t2;
    s16 phi_t3_2;

    s16 i;

    sp178 = 0;
    sp17A = 0;
    // phi_a2 = numTris;

    for (i = 0; i < numTris; i++) {
        // phi_t3 = 0xC;
        // phi_t3_2 = 0xC;
        // temp_t9 = i * 0x24; // sp17A
        temp_t2 = arg1 + (i * 0x24); //temp_t9;
        temp_v0 = &D_803F2C80[*temp_t2]; // *phi_t4 + (*temp_t2 * 0x34);
        temp_v1 = temp_v0->unk0;
        temp_s6 = temp_v0->unk2;
        // temp_a0 = temp_v1 & 8;
        sp175 = temp_v0->unk3;
        phi_t2 = temp_t2;
        // phi_t4_2 = phi_t4;
        // phi_t3_2 = phi_t3;
        if ((temp_v1 & 8) ||
            (temp_v1 & 0x40) ||
            (temp_v1 & 0x2000) ||
            (temp_v1 & 0x100)) {
            // sp40 = temp_v1 & 0x40;
            if ((temp_v1 & 8) && (D_803F2C86 != 4)) {
                gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0180, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                gDPSetTextureLOD((*dl)++, G_TL_TILE);
                gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                gDPTileSync((*dl)++);

                D_803F2C86 = 4;
            }
            if ((temp_v1 & 0x100) != 0) {
                if (12 != D_803F2C86) {
                    gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE);
                    gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x01C0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);

                    D_803F2C86 = 12;
                }
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                D_803E3130[D_803F2CA6].unk1 = 6;
                D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                D_803E3130[D_803F2CA6].unk14 = (s32 *) *dl;
                gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);

                D_803F2CA6 += 1;
                D_803F2C92 = 1;
            }
        } else {
            if (temp_s6 > 40) {
                if (D_803F2C86 != 14) {
                    D_803F2C8E = 0;
                    gDPPipeSync((*dl)++);
                    gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                    gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                    gDPSetCombineMode((*dl)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                    gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);
                    gDPSetTextureLOD((*dl)++, G_TL_TILE);
                    gSPTexture((*dl)++, 32768, 32768, 0, 6, G_ON);

                    if (D_803F2C96 != temp_s6) {
                        D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                        D_803E3130[D_803F2CA6].unk1 = (s8) (temp_s6 - 33);
                        D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                        D_803E3130[D_803F2CA6].unk14 = (s32 *) *dl;
                        D_803F2CA6 += 1; //D_803F2CA6 + 1;
                        gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_0102C810));
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPLoadSync((*dl)++);
                        gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 511, 512);
                        gDPPipeSync((*dl)++);
                        gDPSetTile((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPSetTileSize((*dl)++, 6, 0, 0, 124, 124);

                        D_803F2C96 = temp_s6;
                        D_803F2C97 = 0xFF;
                    }
                    D_803F2C86 = 14;
                }
            } else if (((temp_v1 & 8) == 0) && (D_803F2C86 != 1)) {
                gDPPipeSync((*dl)++);
                gDPSetAlphaCompare((*dl)++, G_AC_NONE);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
                gDPSetTextureLOD((*dl)++, G_TL_LOD);
                gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                gDPSetPrimColor((*dl)++, 128, 128, 0x00, 0x00, 0x00, 0x00);
                gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);

                D_803F2C86 = 1;
            }
            if (sp175 != 0) {
                D_803F2C86 = 1;
                if (D_803F2C86 != 0) {
                    D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) (temp_v0_4->unk0 | 1);
                    D_803E3130[D_803F2CA6].unk1 = 1;
                    D_803E3130[D_803F2CA6].unk2 = (s16) sp175;
                    D_803E3130[D_803F2CA6].unk14 = (s32 *) *dl;
                    gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                    gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
                    gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
                    gDPTileSync((*dl)++);
                    gDPPipeSync((*dl)++);

                    D_803F2CA6 += 1; //(s16) (D_803F2CA6 + 1);
                    D_803F2C92 = 1;
                }
            }
        }
        if (temp_v1 & 0x40) {
            if (D_803F2C99 == 0) {
                gDPPipeSync((*dl)++);
                gSPTexture((*dl)++, 32768, 32768, 0, G_TX_RENDERTILE, G_ON);
                gDPSetAlphaCompare((*dl)++, G_AC_THRESHOLD);
                gDPSetBlendColor((*dl)++, 0x00, 0x00, 0x00, 0x00);
                gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEIDECALA);
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);
                D_803F2C99 = 1;
            }
        } else if (D_803F2C99 == 1) {
            gDPPipeSync((*dl)++);
            gSPTexture((*dl)++, 32768, 32768, 5, G_TX_RENDERTILE, G_ON);
            gDPSetAlphaCompare((*dl)++, G_AC_NONE);
            gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);

            D_803F2C99 = 0U;
        }
        if (temp_v1 & 0x4000) {
            if (D_803F2C8E != 1) {
                D_803F2C8E = 1;
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_ZB_OPA_DECAL2);
                // goto block_37;
            }
        } else if (D_803F2C8E != 0) {
            D_803F2C8E = 0;
            if (temp_v0->unk2 > 40) {
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_TEX_EDGE2);

            } else {
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
            }
        }
        if (temp_v1 & 0x800) {
            if (D_803F2C88 != 2) {
                D_803F2C88 = 2;
                gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, G_RM_AA_ZB_OPA_INTER2);

            }
        } else if (D_803F2C88 != 1) {
            gDPSetRenderMode((*dl)++, D_803C0640_7D1CF0, D_803C0648_7D1CF8);
        }
        if (D_803F2C96 != temp_v0->unk2) {
            if (temp_v0->unk2 < 32) {
                sp4C = temp_t2;
                func_80346878_757F28(dl, temp_s6); //, numTris);
                // phi_t4_2 = &D_803F2C80;
            }
            D_803F2C96 = temp_s6;
            D_803F2C97 = 0xFF;
            phi_t2 = arg1 + (i * 0x24) ; // temp_t9;
        }
        // phi_t4 = phi_t4_2;
        // phi_t3 = phi_t3_2;
        if ((temp_v1 & 4) && (D_803F2C9A == 0)) {
            gSPClearGeometryMode((*dl)++, G_CULL_BACK);

            D_803F2C9A = 1;
        }
        if (((temp_v1 & 4) == 0) && (D_803F2C9A == 1)) {
            gSPSetGeometryMode((*dl)++, G_CULL_BACK);
            D_803F2C9A = 0;
        }
        if (temp_v1 & 0x80) {
            if (D_803F2C8A != 0) {
                D_803F2C8A = 0;
            }
        } else if (D_803F2C8A != 1) {
            D_803F2C8A = 1;
        }
        if (temp_v1 & 0x400) {
            if (D_803F2C8C != 1) {
                gDPSetCombineLERP((*dl)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, PRIMITIVE, SHADE, 0, 0, 0, 0, SHADE);
                gDPSetPrimColor((*dl)++, 128, 128, 45, 45, 45, 0x00);
                D_803F2C8C = 1;
            }
        } else if (D_803F2C8C == 1) {
            gDPSetCombineMode((*dl)++, G_CC_TRILERP, G_CC_MODULATEI2);
            D_803F2C8C = 0;
        }
        if ((sp175 == 0) && (D_803F2C92 != 0)) {
            if ((temp_v1 & 0x40) == 0) {
                gDPSetTileSize((*dl)++, G_TX_RENDERTILE, 0, 0, 124, 124);

            }
            gDPSetTileSize((*dl)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*dl)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*dl)++, 3, 0, 0, 12, 12);
            gDPSetTileSize((*dl)++, 4, 0, 0, 4, 4);
            gDPSetTileSize((*dl)++, 5, 0, 0, 0, 0);

            D_803F2C92 = 0;
        }
        if ((temp_v1 & 1) == 0) {
            for (i = 0; i < 4; i++) {
#if 0
                temp_a2 = i * 2;
                temp_v0_6 = (arg1 + (i * 0x24) + temp_a2)->unkC;
                if ((temp_v0_6 != 0) && ((temp_v0_6 & 1) != 0)) {
                    temp_v0_7 = D_803F2C80 + (phi_t2->unk0 * 0x34) + (i * 12);
                    // temp_a0_67 = *arg0;
                    // *arg0 = temp_a0_67 + 8;
                    // temp_a0_67->unk0 = (((phi_t2 + temp_a2)->unk4 * 2) & 0xFFFF) | 0xB2140000;
                    // temp_a0_67->unk4 = (s32) ((((temp_v0_7->unk4 << 5) << 0x10) & 0xFFFF0000) | ((temp_v0_7->unk6 << 5) & 0xFFFF));
                    gSPModifyVertex((*dl)++,
                        ((phi_t2 + temp_a2)->unk4 * 2),
                        G_MWO_POINT_ST,
                        (temp_v0_7->unk4 << 5) |
                        (temp_v0_7->unk6 << 5)));
                }
#endif
            }
            gSP1Quadrangle((*dl)++,
                phi_t2[2], //->unk4 << 1,
                phi_t2[3], //->unk6 << 1,
                phi_t2[4], //->unk8 << 1,
                phi_t2[5], //->unkA << 1,
                0); // flag

            sp178 += 1;
        } else {
            for (i = 0; i < 3; i++) {
#if 0
                temp_a2_2 = i * 2;
                temp_v0_6 = (arg1 + (i * 0x24) + temp_a2_2)->unkC;
                // phi_a2 = temp_a2_2;
                if ((temp_v0_6 != 0) && ((temp_v0_6 & 1) != 0)) {
                    temp_v0_9 = D_803F2C80 + (phi_t2[0] * 0x34) + (i * 12);
                    // temp_a0_69 = *arg0;
                    // *arg0 = temp_a0_69 + 8;
                    temp_a0_69->unk0 = (((phi_t2 + temp_a2_2)->unk4 * 2) & 0xFFFF) | 0xB2140000;
                    temp_a0_69->unk4 = (s32) ((((temp_v0_9->unk4 << 5) << 0x10) & 0xFFFF0000) | ((temp_v0_9->unk6 << 5) & 0xFFFF));
                }
#endif
                gSPModifyVertex((*dl)++,
                    phi_t2[i][2],
                    G_MWO_POINT_ST,
                    D_803F2C80[phi_t2[0]][i]
                );

            }
            gSP1Triangle((*dl)++,
                phi_t2[2], //->unk4 << 1,
                phi_t2[3], //->unk6 << 1,
                phi_t2[4], //->unk8 << 1,
                0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_803458FC_756FAC.s")
#endif

void func_80346878_757F28(Gfx **arg0, u8 arg1) {
    if (arg1 < 32) {
        gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
        gDPTileSync((*arg0)++);
        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTextureImage((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
        gDPTileSync((*arg0)++);
        gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    }
    gDPTileSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1372, 0);
    gDPTileSync((*arg0)++);
}

// load EVO texture?
void func_803469D4_758084(Gfx **arg0, u16 arg1) {
    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010 + ((u8)arg1 << 7));
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 31, 256);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 0);
}

// load_xlui_texture
void func_80346AB0_758160(Gfx **arg0, u8 arg1) {
    rmonPrintf("load xlui texture - %d\n", arg1);
    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[(s32)arg1]);
    gDPTileSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync((*arg0)++);
}

// uses delay slot
#if 0
void func_80346BB4_758264(Gfx **arg0, struct115* arg1, s16 numTris) {
    s16 i;    // sp29A
    s16 tris; // sp298
    u8  padx[3];
    u8  sp294;
    u8  pad2[0x14];
    s16 sp28E;
    // s32 sp5C;
    // s16 *sp58;
    // s32 sp50;
    // s32 sp48;
    // s32 sp44;

    s32 temp_t0_3;
    // s32 temp_v1_9;
    s16 var_v0_5;
    s16 var_v0_4;
    s8 temp_t0_2;

    u16 vtxFlags;
    u8 temp_s1;

    tris = 0;

    for (i = 0; i < numTris; i++) {
        sp28E = 1;

        // helpppp...
        vtxFlags = D_803F2C80[arg1[i].unk0].unk0[0].unk0;
        temp_s1 = D_803F2C80[arg1[i].unk0].unk0[0].unk3;
        sp294   = D_803F2C80[arg1[i].unk0].unk0[0].unk2;

        if (((vtxFlags & 0x20)) || (vtxFlags & 0x10) || (vtxFlags & 0x200) || (vtxFlags & 0x8000) || (vtxFlags & 0x100) || (vtxFlags & 0x1000)) {
            if ((vtxFlags & 0x8000) && (D_803F2C84 != 7)) {
                gDPSetCombineMode((*arg0++), G_CC_MODULATEI, G_CC_PASS2);
                gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803C0648_7D1CF8);
                D_803F2C84 = 7;
            }
            if ((vtxFlags & 0x10)) {
                sp28E = 0;
                if (D_803F2C84 != 3) {
                    gDPPipeSync((*arg0)++);
                    gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, PRIMITIVE);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON); // qu016(0.5)

                    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B610);

                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x019E, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*arg0)++);
                    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*arg0)++);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x019E, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*arg0)++);
                    D_803F2C84 = 3;
                }

                D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) temp_v1_2->unk0 | 1;
                if (temp_s1 != 0) {
                    D_803E3130[D_803F2CA6].unk1 = 0;
                    D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // qu08

                } else {
                    D_803E3130[D_803F2CA6].unk1 = 7;
                    D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;
                    gDPSetPrimColor((*arg0)++, 128, 128, 0x00, 0x00, 0x00, 0xDC);

                }
                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x200)) {
                sp28E = 0;
                if (D_803F2C84 != 6) {
                    gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, SHADE_ALPHA, TEXEL0, TEXEL1, PRIMITIVE, SHADE, PRIMITIVE, PRIMITIVE, SHADE, COMBINED, SHADE, 0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON);
                    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, D_0102B810);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x01A0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync((*arg0)++);
                    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 124);
                    gDPPipeSync((*arg0)++);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x01A0, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x015E, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPPipeSync((*arg0)++);
                    D_803F2C84 = 6;
                }
                D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;

                if (temp_s1 != 0) {
                    D_803E3130[D_803F2CA6].unk1 = 3;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // qu08
                } else {
                    D_803E3130[D_803F2CA6].unk1 = 7;
                    D_803E3130[D_803F2CA6].unk14 = *arg0;
                    gDPSetPrimColor((*arg0)++, 128, 128, 0xFF, 0xFF, 0xFF, 0xDC); // qu08
                    gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
                    gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
                }
                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x100)) {
                sp28E = 0;
                if (D_803F2C84 != 0xB) {
                    gSPClearGeometryMode((*arg0)++, G_FOG);
                    gDPSetCombineLERP((*arg0)++, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 6, G_ON);
                    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 6, 0x01DE, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);

                    D_803F2C84 = 0xB;
                }
                D_803E3130[D_803F2CA6].unk2 = temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;
                D_803E3130[D_803F2CA6].unk1 = 5;
                D_803E3130[D_803F2CA6].unk14 = *arg0;
                gDPSetTileSize((*arg0)++, 6, 0, 0, 60, 60);

                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if ((vtxFlags & 0x1000)) {
                sp28E = 0;
                if (D_803F2C84 != 13) {
                    gSPClearGeometryMode((*arg0)++, G_FOG);
                    gDPSetCombineLERP((*arg0)++, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
                    gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);
                    gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                    gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 5, G_ON);

                    D_803F2C84 = 13;
                }
                D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) temp_v1_5->unk0 | 1;
                D_803E3130[D_803F2CA6].unk1 = 5;
                D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;
                gDPSetTileSize((*arg0)++, 5, 0, 0, 60, 60);

                D_803F2C94 = 1;
                D_803F2CA6 += 1;
            }
            if (((vtxFlags & 0x20)) && ((vtxFlags & 0x10) == 0) && ((vtxFlags & 0x200) == 0) && ((vtxFlags & 0x100) == 0)) {
                vtxFlags = D_803F2C80[arg1[i].unk0].unk0[0].unk2;
                if (sp294 >= 32) {
                    if (D_803F2C84 != 0xE) {
                        gDPPipeSync((*arg0)++);
                        if (sp294 > 40) {
                            gDPSetCombineMode((*arg0)++, G_CC_MODULATEIDECALA, G_CC_PASS2);
                            gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*arg0)++, 0x00, 0x00, 0x00, 0x01);

                            if (vtxFlags & 0x4000) {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, G_RM_ZB_XLU_DECAL2);
                            } else {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, D_803F2CC4);

                            }
                            gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                            gSPTexture((*arg0)++, 0x8000, 0x8000, 0, 6, G_ON);

                            temp_t0_2 = sp294 - 33;
                            D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                            D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) D_803E3130[D_803F2CA6].unk0 | 1;
                            D_803E3130[D_803F2CA6].unk1 = temp_t0_2;
                            D_803F2CA6++; // = temp_a1_2 + 1;
                            D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;
                            if (temp_t0_2 == 9) {
                                gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1,OS_PHYSICAL_TO_K0(D_0102D810));
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*arg0)++);
                                gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*arg0)++);
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);

                            } else {
                                gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_0102C810));
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync((*arg0)++);
                                gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 511, 512);
                                gDPPipeSync((*arg0)++);
                                gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);

                            }
                            gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        } else {
                            gDPSetCombineLERP((*arg0)++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, SHADE, 0, COMBINED);
                            if (vtxFlags & 0x4000) {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, G_RM_ZB_XLU_DECAL2);

                            } else {
                                gDPSetRenderMode((*arg0)++, D_803C0640_7D1CF0, D_803F2CC4);
                            }
                            gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                            gSPTexture((*arg0)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                            gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
                            gDPSetBlendColor((*arg0)++, 0x00, 0x00, 0x00, 0x01);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                            gDPSetTile((*arg0)++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5);
                            gDPSetTileSize((*arg0)++, 5, 0, 0, 0, 0);

                            D_803F2C84 = 0xE;
                        }
                        if (temp_s1 != 0) {
                            D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                            D_803E3130[D_803F2CA6].unk0 = (u8) D_803E3130[D_803F2CA6].unk0 | 1;
                            D_803E3130[D_803F2CA6].unk1 = 0xB;
                            D_803F2CA6++; // = temp_a1_3 + 1;
                            D_803F2C94 = 1;
                            D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;

                            gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                            gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
                            gDPSetTileSize((*arg0)++, 2, 0, 0, 4*(7), 4*(7));

                        }
                    }
                } else {
                    if (vtxFlags & 1) {
                        var_v0_4 = 3;
                    } else {
                        var_v0_4 = 4;
                    }

                    // delayslot around here ish
                    var_v0_5 = var_v0_4 + 1;
                    if (var_v0_4 > 0) {
                    loop_59:
                        if (var_v0_5 > 0) {
                            var_v0_5 = var_v0_5 + 1;
                            goto loop_59;
                        }
                    }

                    if ((D_803F2C84 != 9) && (sp294 != 0)) {
                        gDPPipeSync((*arg0)++);
                        gSPClearGeometryMode((*arg0)++, G_FOG);
                        gDPSetEnvColor((*arg0)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & 0x4000) {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);
                        } else {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);

                        }
                        if (vtxFlags & 0x40) {
                            gDPSetAlphaCompare((*arg0)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*arg0)++, G_AC_NONE);

                        }
                        gDPSetCombineMode((*arg0)++, G_CC_TRILERP, G_CC_MODULATEI2);
                        gSPTexture((*arg0)++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                        gDPSetTextureLOD((*arg0)++, G_TL_TILE);
                                                                      /* line, tmem, tile, palette ... */
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 0, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, 1, G_TX_NOMIRROR | G_TX_WRAP, 4, 1);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0140, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, 2, G_TX_NOMIRROR | G_TX_WRAP, 3, 2);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0150, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, 2, 3, G_TX_NOMIRROR | G_TX_WRAP, 2, 3);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0154, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, 1, 4, G_TX_NOMIRROR | G_TX_WRAP, 1, 4);
                        gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x0156, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 5);
                        gDPSetTileSize((*arg0)++, 5, 0, 0, 0, 0);

                        D_803F2C84 = 9;
                    }

                    if ((temp_s1 != 0) && !(vtxFlags & 0x100) && !(vtxFlags & 0x10) && !(vtxFlags & 0x200)) {
                        D_803E3130[D_803F2CA6].unk2 = (s16) temp_s1;
                        D_803E3130[D_803F2CA6].unk0 |= 1; //(u8) temp_v1_8->unk0 | 1;
                        D_803E3130[D_803F2CA6].unk1 = 4;
                        D_803E3130[D_803F2CA6].unk14 = (s32) *arg0;
                        gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
                        gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
                        gDPSetTileSize((*arg0)++, 2, 0, 0, 4*(7), 4*(7));
                        gDPTileSync((*arg0)++);
                        gDPPipeSync((*arg0)++);
                        D_803F2C94 = 1;
                        D_803F2CA6 += 1;
                    }
                    if ((sp294 == 0) && (D_803F2C84 != 0xA)) {
                        gDPPipeSync((*arg0)++);
                        gSPClearGeometryMode((*arg0)++, G_FOG);
                        gDPSetEnvColor((*arg0)++, 0x00, 0x00, 0x80, 0x80);

                        if (vtxFlags & 0x4000) {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, G_RM_ZB_XLU_DECAL2);

                        } else {
                            gDPSetRenderMode((*arg0)++, G_RM_PASS, D_803F2CC4);

                        }
                        if (vtxFlags & 0x40) {
                            gDPSetAlphaCompare((*arg0)++, G_AC_DITHER);
                        } else {
                            gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
                        }
                        gDPSetCombineMode((*arg0)++, G_CC_SHADE, G_CC_PASS2);

                        D_803F2C84 = 0xA;
                    }
                }
            }
        }

        if ((D_803F2C98 != (s32) sp294) && (sp28E == 1)) {
            if (sp294 <= 40) {
                func_80346878_757F28(arg0, sp294);
                D_803F2C98 = sp294;
            } else {
                D_803F2C98 = 100;
            }
        }
        if (vtxFlags & 4) {
            if (D_803F2C9B == 0) {
                gSPClearGeometryMode((*arg0)++, G_CULL_BACK);
                D_803F2C9B = 1;
            }
        } else if (D_803F2C9B == (u8) 1) {
            gSPSetGeometryMode((*arg0)++, G_CULL_BACK);
            D_803F2C9B = 0;
        }
        if ((temp_s1 == 0) && (D_803F2C94 != 0)) {
            gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 124, 124);
            gDPSetTileSize((*arg0)++, 1, 0, 0, 60, 60);
            gDPSetTileSize((*arg0)++, 2, 0, 0, 28, 28);
            gDPSetTileSize((*arg0)++, 5, 0, 0, 124, 124);
            gDPSetTileSize((*arg0)++, 6, 0, 0, 124, 124);
            D_803F2C94 = 0;
        }

        if ((vtxFlags & 1) == 0) {
            gSP1Quadrangle((*arg0)++,
            /* v0   */ tris + 0,
            /* v1   */ tris + 1,
            /* v2   */ tris + 2,
            /* v3   */ tris + 3,
            /* flag */ 0);
            tris += 1; // 4 triangles
        } else {
            gSP1Triangle((*arg0)++,
            /* v0   */ tris + 0,
            /* v1   */ tris + 1,
            /* v2   */ tris + 2,
            /* flag */ 0);
        }
        tris += 3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7558F0/func_80346BB4_758264.s")
#endif
