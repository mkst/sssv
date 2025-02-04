#include <ultra64.h>
#include "common.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
    s32 unk0;   // xPos
    s32 unk4;   // zPos
    s32 unk8;   // yPos (next?)
} Vertex2; // size 0xC

typedef struct {
    s16 unk0;   // zRotation
    s16 unk2;   // yRotation
} Rotation; // size 0x4

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} RGB; // size 0x4

typedef struct {
    /* 0x0 */   s8  unk0;
    /* 0x1 */   s8  unk1;
    /* 0x2 */   s8  unk2[48];
    /* 0x32 */  u8  unk32[60];
    /* 0x6E */  s8  unk6E[60];
    /* 0xAA */  u16 unkAA[60];
    /* 0x124 */ Vertex2 unk124[60];
    /* 0x3F4 */ Rotation unk3F4[60];
    /* 0x4E4 */ Gfx *displayList[60];
} struct025; // size 0x5d4 (+4 bytes alignment)

typedef struct {
    /* 0x0 */   s8       unk0;
    /* 0x2 */   u16      unk2[60];
    /* 0x7C */  Vertex2  unk7C[60];
    /* 0x34C */ Rotation unk34C[60];
    /* 0x43C */ Gfx     *displayList[60];
    /* 0x52C */ RGB      color[60];
} struct072; // 0x5e0?

void func_8029E528_6AFBD8(void);
void func_8029E7D0_6AFE80(void);
void func_8029EF20_6B05D0(struct025 *arg0, Gfx **dl);
void func_8029F218_6B08C8(void);
void func_8029F464_6B0B14(struct025 *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, Gfx *arg8);


// ========================================================
// externs
// ========================================================

extern Gfx D_010049E8_3E2B8[];
extern u8  D_010084A0_41D70[];
extern Gfx D_0100A6D0_43FA0[];
extern u8  D_0100A730_44000[];
extern Gfx D_0100AF90_44860[];  // gun turret base
extern Gfx D_0100B2C0_44B90[];  // gun turrent gun
extern Gfx D_0100F4F0_48DC0[];
extern Gfx D_010106E0_49FB0[];
extern Gfx D_01011140_4AA10[];
extern Gfx D_01011B78_4B448[];
extern Gfx D_01012B80_4C450[];  // teleporter

extern u8  D_01031010_6A8E0[];

extern Gfx D_040148B0_114600[];
extern Gfx D_04014990_DC3C0[];  // # piece of silicon valley?
extern Gfx D_04015960_DD390[];
extern Gfx D_040165E0_116330[]; // # gherkin looking thing

extern Gfx D_050007A0_A1870[];
extern Gfx D_05001720_8A980[];  // # white/blue capsule thing
extern Gfx D_05004070_8D2D0[];  // # asteroid

extern u8 *D_803A8370_7B9A20[16]; // tbd

#if 0
D_803A8370_7B9A20[16] = {
    D_01034190_6DA60,
    D_01033190_6CA60,
    D_01034990_6E260,
};
#endif

// ========================================================
// .data
// ========================================================

s16 D_803A0580_7B1C30[3][3] = {
    { 0xFFD9, 0x001B, 0x0000, },
    { 0x002A, 0xFFA0, 0x0018, },
    { 0x0000, 0x006E, 0x0000, },
};

u8 D_803A0594_7B1C44[16] = {
    0xff, 0xff, 0xff, 0x00, // #ffffff
    0xff, 0xff, 0xff, 0x00, // #ffffff
    0x5e, 0x72, 0xff, 0x00, // #5e72ff
    0x77, 0xc4, 0xff, 0x00, // #77c4ff
};

// ========================================================
// .bss (more bss is defined below)
// ========================================================

static s16  D_803D2E00; // 0..15

DynamicTextures D_803D2E08;

// ========================================================
// .text
// ========================================================

void func_8029CEF0_6AE5A0(s32 xPos, s32 zPos, s32 yPos, u16 size, u8 category, DynamicTextures *arg5, s8 arg6, u8 red, u8 green, u8 blue) {
    s8 tmp;

    arg5->unk1++;
    if (arg5->unk1 < (s32)(sizeof(arg5->textures) / sizeof(DynamicTexture))) {
        arg5->textures[arg5->unk1].xPos = xPos;
        arg5->textures[arg5->unk1].zPos = zPos;
        arg5->textures[arg5->unk1].yPos = yPos;
        arg5->textures[arg5->unk1].size = size;
        arg5->textures[arg5->unk1].category = category; // ?
        arg5->textures[arg5->unk1].unk10 = arg6; // effectType?
        arg5->textures[arg5->unk1].red = red;
        arg5->textures[arg5->unk1].green = green;
        arg5->textures[arg5->unk1].blue = blue;

        tmp = arg5->textureGroups[category];

        if (tmp == -1) {
            arg5->textures[arg5->unk1].next = -1;
            arg5->textureGroups[category] = arg5->unk1;
            if (arg5->unk0 != -1) {
                arg5->textures[arg5->unk0].next = arg5->unk1;
            }
            arg5->unk0 = arg5->unk1;
        } else {
            arg5->textures[arg5->unk1].next = arg5->textures[tmp].next;
            arg5->textures[tmp].next = arg5->unk1;

            arg5->textureGroups[category] = arg5->unk1;
            if (arg5->textures[arg5->unk1].next == -1) {
                arg5->unk0 = arg5->unk1;
            }
        }
    }
}

void func_8029D0A8_6AE758(void) {
    u8 loaded_texture;
    u8 loaded_texture_2;
    s8 i;
    u8 r, g, b;

    DynamicTexture *tex;

    static s32 D_803D3428;
    static s32 D_803D342C;

    loaded_texture = 0xFF;
    loaded_texture_2 = 0xFF;

    D_803D2E00 += 1;
    D_803D2E00 &= 0xF;

    if ((guRandom() % 20) == 1) {
        if (D_803D342C == 5) {
            D_803D342C = 1;
        } else {
            D_803D342C = 5;
        }
    }

    // normally increment by 1, sometimes by 5?
    D_803D3428 += D_803D342C;
    D_803D3428 %= 9;

    gSPDisplayList(D_801D9E90++, D_01004308_3DBD8);
    gSPDisplayList(D_801D9EB8++, D_01004B98_3E468);

    for (i = 0; i != -1; i = D_803D2E08.textures[i].next) {
        tex = &D_803D2E08.textures[i];

        if (tex->category < 32) {
            if (tex->category != loaded_texture) {
                if (loaded_texture != 0xFF) {
                    D_803D2E08.textureGroups[loaded_texture] = -1;
                }
                loaded_texture = tex->category;
                if (loaded_texture == 0) {
                    func_8029D8D8_6AEF88(&D_801D9EB8, loaded_texture + (D_803D3428 / 3));
                } else {
                    func_8029D8D8_6AEF88(&D_801D9EB8, loaded_texture);
                }
            }
            if (tex->unk10 == 127) {
                func_8032E150_73F800(&D_801D9EB8, tex->xPos, tex->zPos, tex->yPos, 31, 63, tex->size * 3);
            } else {
                func_8032E150_73F800(&D_801D9EB8, tex->xPos, tex->zPos, tex->yPos, 31, 31, tex->size * 3);
            }
            gDPPipeSync(D_801D9EB8++);
        } else {
            r = tex->red;
            g = tex->green;
            b = tex->blue;

            if (tex->category < 48) {
                gDPSetPrimColor(D_801D9E90++, 0, 0, r, g, b, 0xFF);
                gDPSetEnvColor(D_801D9E90++, r, g, b, 0);
            }
            if (tex->category != loaded_texture_2) {
                if (loaded_texture_2 != 0xFF) {
                    // mark old as cleared
                    D_803D2E08.textureGroups[loaded_texture_2] = -1;
                }
                loaded_texture_2 = tex->category;
                if (loaded_texture_2 < 48) {
                    // i4/i8/i16?
                    gDPSetCombineLERP(D_801D9E90++,
                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);

                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_01029E10_636E0 + ((loaded_texture_2 << 0xA) - 0x8000)));

                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 511, 512);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);

                } else if (loaded_texture_2 == 48) {
                    // rgba32
                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, OS_PHYSICAL_TO_K0(D_01040CB0_7A580 + (((((loaded_texture_2 + (D_803D2E00 >> 1))) << 0xA) - 0xC000) << 1)));

                    gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 256);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 124, 124);

                    // FIXME: why cant we use OS_PHYSICAL_TO_K0
                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 32, (void *) ((D_0103ECB0_78580 + (((loaded_texture_2 + (D_803D2E00 >> 1)) << 0xA) - 0xC000)) + 0x80000000));

                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPLoadSync(D_801D9E90++);
                    gDPLoadTile(D_801D9E90++, G_TX_LOADTILE, 0, 0, 124, 124);
                    gDPPipeSync(D_801D9E90++);
                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                    gDPSetTileSize(D_801D9E90++, 1, 0, 0, 124, 124);
                    gDPSetCombineLERP(D_801D9E90++,
                        PRIMITIVE, 0, TEXEL0, 0,
                        PRIMITIVE, 0, TEXEL1, 0,
                        0, 0, 0, COMBINED,
                        0, 0, 0, COMBINED);
                }
            }
            if (loaded_texture_2 == 0x30) {
                if (tex->unk10 == 60) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 255, 255, 255, 255); // white
                }
                if (tex->unk10 == 59) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 255, 160, 255, 255); // light pink
                }
                if (tex->unk10 == 58) {
                    gDPSetPrimColor(D_801D9E90++, 0, 0, 255, 0,   255, 255); // bright pink
                }
            }

            gDPSetDepthSource(D_801D9E90++, G_ZS_PRIM);
            gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

            func_8032DACC_73F17C(
                &D_801D9E90,
                tex->xPos,
                tex->zPos,
                tex->yPos,
                0x1F,
                0x1F,
                tex->size * 3);
            gDPPipeSync(D_801D9E90++);
        }
    }

    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
}

// new file, or just bss ordering fun?

static s16  D_803D3430;
static s16  D_803D3432;
DisplayList* D_803D3434;
static Gfx **D_803D3438;
static Animal *D_803D343C;
static struct035 *D_803D3440;
static struct025  D_803D3448;
static struct025  D_803D3A20;
static struct025  D_803D3FF8;
static struct072  D_803D45D0;
static struct025  D_803D4BB0;
static struct057  D_803D5188[32];
static s16  D_803D5508;


void func_8029D89C_6AEF4C(void) {
    s16 i;
    // DynamicTexture
    D_803D2E08.unk0 = -1;
    D_803D2E08.unk1 = -1;
    for (i = 0; i < 64; i++) {
        D_803D2E08.textureGroups[i] = -1;
    }
}

void func_8029D8D8_6AEF88(Gfx **arg0, s16 arg1) {
    u8 *img1;
    u8 *img2;

    if (arg1 < 8) {
        img1 = (u8*)D_800BA760 + 0x1D4C0 + (arg1 << 11); // 2048 bytes per image
        img2 = (u8*)D_800BA760 + 0x214C0 + (arg1 << 9);  // 512 bytes per image
    } else {
        arg1 = arg1 - 8;
        img1 = (u8*)D_800BA760 + 0x1ACC0 + (arg1 << 11); // 2048 bytes per image
        img2 = (u8*)D_800BA760 + 0x1CCC0 + (arg1 << 9);  // 512 bytes per image
    }

    gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, OS_K0_TO_PHYSICAL(img1));
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 4*31, 4*31);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 4*31, 4*31);

    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 16, OS_K0_TO_PHYSICAL(img2));
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*arg0)++);
    gDPLoadTile((*arg0)++, G_TX_LOADTILE, 0, 0, 62, 4*31);
    gDPPipeSync((*arg0)++);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, 1, 0, 0, 4*31, 4*31);
}

void func_8029DB20_6AF1D0(u8 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, Gfx *arg7) {
    s32 temp_f10;
    s32 temp_f16;
    s32 temp_f8;
    s32 temp_t1;
    s16 idx;
    s16 i;

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

        for (i = D_803D5508; i > idx; i--) {
            D_803D5188[i] = D_803D5188[i - 1];
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

void func_8029DD84_6AF434(void) {
    u8 current_texture;
    u8 loaded_texture;
    s16 i;

    gSPDisplayList(D_801D9E90++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E90++, gGeometryMode);
    gSPDisplayList(D_801D9E90++, D_01004510_3DDE0);

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

        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

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

        gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        gSPClearGeometryMode(D_801D9E90++, G_CULL_BACK);
        gSPDisplayList(D_801D9E90++, D_803D5188[i].unk14);
        gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
    }

    D_803D5508 = 0;
    gSPSetGeometryMode(D_801D9E90++, G_CULL_BACK);
}

void func_8029E100_6AF7B0(void) {
    static u16 D_803A05A4_7B1C54 = 0; // .data

    Gfx *dl;

    s16 i;
    s16 j;
    s16 vtx_index;
    s32 color_index;
    s16 num_vtxs;

    gSPDisplayList(D_801D9E90++, D_010049E8_3E2B8);

    dl = D_803D3434->unk3B318;

    vtx_index = 0;
    for (i = 0; i < D_803E97C0; i++) {
        gSPDisplayList(D_801D9E90++, dl);

        num_vtxs = D_803D3434->unk3B30A[i];
        gSPVertex(dl++, &D_803D3434->unk39C88[vtx_index], num_vtxs, 0);
        gSPCullDisplayList(dl++, 0, 7);

        color_index = SSSV_RAND(4);
        gDPSetEnvColor(
            dl++,
            0x00,
            0x00,
            0x50,
            0x00);
        gDPSetPrimColor(
            dl++,
            0,
            0,
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 0],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 1],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 2],
            D_803A0594_7B1C44[((color_index << 2) & 0xFFFF) + 3]);

        for (j = 0; j < num_vtxs - 9; j += 4) {
            s32 uls, ult, lrs, lrt;
            u16 tmp = (D_803A05A4_7B1C54 >> 2) + (j >> 2);

            uls = -(tmp << 7);
            ult = 0;
            lrs = uls + 0x7F;
            lrt = ult + 0x3F;

            gDPSetTileSize(
            /* pkt */ dl++,
            /* t   */ G_TX_RENDERTILE,
            /* uls */ uls,
            /* ult */ ult,
            /* lrs */ lrs,
            /* lrt */ lrt);

            gSP2Triangles(
            /* pkt   */ dl++,
            /* v00   */ (j + 9) - 1,
            /* v01   */ (j + 9) + 2,
            /* v02   */ (j + 9) + 0,
            /* flag0 */ 0,
            /* v10   */ (j + 9) - 1,
            /* v11   */ (j + 9) + 1,
            /* v12   */ (j + 9) + 2,
            /* flag1 */ 0
            );
        }
        gSPEndDisplayList(dl++);
        vtx_index += num_vtxs;
    }
    D_803A05A4_7B1C54 += 4;
    D_803A05A4_7B1C54 &= 0xF;

}

void func_8029E3CC_6AFA7C(void) {
    if (D_803D3434->usedModelViewMtxs < 250) {
        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D343C->position.xPos.w,
            D_803D343C->position.zPos.w,
            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
            D_803D343C->zRotation,
            D_803D343C->yRotation,
            D_803D343C->unk40 << 5,
            D_803D343C->unk40 << 5,
            D_803D343C->unk40 << 5);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D3438[D_803D343C->unk64]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}

void func_8029E528_6AFBD8(void) {
    s16 i;

    gSPDisplayList(D_801D9E8C++, &D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
    gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);

    for (i = 0; i <= D_803D4BB0.unk1; i++) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2);

        func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D4BB0.unk124[i].unk0,
            D_803D4BB0.unk124[i].unk4,
            D_803D4BB0.unk124[i].unk8,
            D_803D4BB0.unk3F4[i].unk0,
            D_803D4BB0.unk3F4[i].unk2,
            D_803D4BB0.unkAA[i] << 5,
            D_803D4BB0.unkAA[i] << 5,
            D_803D4BB0.unkAA[i] << 5);

        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        // Take Two Interactive Logo ?
        if (D_05006170 == D_803D4BB0.displayList[i]) {
            gDPPipeSync(D_801D9E8C++);
            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);
        }

        gSPDisplayList(D_801D9E8C++, D_803D4BB0.displayList[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
    D_803D4BB0.unk1 = -1;
}

void func_8029E7D0_6AFE80(void) {
    s16 i;

    gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineLERP(D_801D9E8C++,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0,
        SHADE, 0, PRIMITIVE, 0);
    gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);

    for (i = 0; i <= D_803D45D0.unk0; i++) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        gDPSetPrimColor(D_801D9E8C++, 0, 0,
            D_803D45D0.color[i].r,
            D_803D45D0.color[i].g,
            D_803D45D0.color[i].b,
            0xFF);

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D45D0.unk7C[i].unk0,
            D_803D45D0.unk7C[i].unk4,
            D_803D45D0.unk7C[i].unk8,
            D_803D45D0.unk34C[i].unk0,
            D_803D45D0.unk34C[i].unk2,
            D_803D45D0.unk2[i] << 5,
            D_803D45D0.unk2[i] << 5,
            D_803D45D0.unk2[i] << 5);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D45D0.displayList[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

        // battery farm tv?
        if (D_0100C120_459F0 == D_803D45D0.displayList[i]) {
            gDPSetCombineLERP(D_801D9E8C++,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0,
                SHADE, 0, PRIMITIVE, 0);
            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
        }
    }

    D_803D45D0.unk0 = -1;
}

void func_8029EAAC_6B015C(void) {
    u8 loaded_texture;
    u8 current_texture;
    s8 i;

    gSPDisplayList(D_801D9E8C++, D_01004AF8_3E3C8);
    gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);

    current_texture = 0xFF;
    loaded_texture = 0xFF;
    i = 0;
    for (; i != -1; i = D_803D3FF8.unk6E[i])  {
        current_texture = loaded_texture;
        if (current_texture != (D_803D3FF8.unk32[i] & 0x3F)) {
            if (loaded_texture != 0xFF) {
                // mark current texture as unloaded?
                D_803D3FF8.unk2[loaded_texture] = -1;
            }

            loaded_texture = D_803D3FF8.unk32[i] & 0x3F;

            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010_688E0 + ((loaded_texture << 0x8) << 3));
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPLoadSync(D_801D9E8C++);
            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
            gDPPipeSync(D_801D9E8C++);
            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
            gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 124, 124);
        }

        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            D_803D3FF8.unk124[i].unk0,
            D_803D3FF8.unk124[i].unk4,
            D_803D3FF8.unk124[i].unk8,
            D_803D3FF8.unk3F4[i].unk0,
            D_803D3FF8.unk3F4[i].unk2,
            D_803D3FF8.unkAA[i] << 5,
            D_803D3FF8.unkAA[i] << 5,
            D_803D3FF8.unkAA[i] << 5);

        guLookAtReflect(
            &D_803D3434->unk38CD0[D_803D3434->unk39310],
            &D_803D3434->unk38A50[D_803D3434->unk39310],
            D_803F2C44, D_803F2C48, D_803F2C4C,
            D_803D3FF8.unk124[i].unk0 / 65536.0f,
            D_803D3FF8.unk124[i].unk4 / 65536.0f,
            D_803D3FF8.unk124[i].unk8 / 65536.0f,
            D_80204200,
            D_80204204,
            D_80204208);

        gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
        gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(D_801D9E8C++, D_803D3FF8.displayList[i]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
        D_803D3434->unk39310++;
    }

    D_803D3FF8.unk0 = -1;
    D_803D3FF8.unk1 = -1;
}

void func_8029EF20_6B05D0(struct025 *arg0, Gfx **dl) {
    u8 current_texture;
    u8 loaded_texture;
    s8 i;

    i = 0;
    loaded_texture = 0xFF;

    for (;i != -1; i = arg0->unk6E[i]) {
        if (D_803D3434->usedModelViewMtxs >= 250) {
            break;
        }

        current_texture = arg0->unk32[i] & 0x3F;
        if (current_texture != loaded_texture) {
            loaded_texture = current_texture;
            gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, ((s32)&D_800BA760 + (loaded_texture * 0xAB8)));
            gDPTileSync((*dl)++);
            gDPSetTile((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPTileSync((*dl)++);
            gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 1372, 0);
            gDPTileSync((*dl)++);
        }

        func_80125FE0(
            &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
            arg0->unk124[i].unk0,
            arg0->unk124[i].unk4,
            arg0->unk124[i].unk8,
            arg0->unk3F4[i].unk0,
            arg0->unk3F4[i].unk2,
            arg0->unkAA[i] << 5,
            arg0->unkAA[i] << 5,
            arg0->unkAA[i] << 5);

        gSPMatrix((*dl)++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList((*dl)++, arg0->displayList[i]);
        gSPPopMatrix((*dl)++, G_MTX_MODELVIEW);

        // tv screen?
        if (D_01017AA0_51370 == arg0->displayList[i]) {
            gDPSetCombineMode(D_801D9E8C++, G_CC_TRILERP, G_CC_MODULATEI2);
            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
        }
    }
}

void func_8029F218_6B08C8(void) {
    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
    gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
    gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);

    if (D_803D3448.unk1 != -1) {
        func_8029EF20_6B05D0(&D_803D3448, &D_801D9E8C);
    }
    if (D_803D3A20.unk1 != -1) {
        gDPPipeSync(D_801D9E8C++);
        gSPTexture(D_801D9E8C++, 32768, 32768, 1, G_TX_RENDERTILE, G_ON);
        gDPSetAlphaCompare(D_801D9E8C++, G_AC_THRESHOLD);
        gDPSetBlendColor(D_801D9E8C++, 0x00, 0x00, 0x00, 0x00);
        gDPSetRenderMode(D_801D9E8C++, gRenderMode1 , 0x113078);
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
    D_803D45D0.unk0 = -1;
    D_803D4BB0.unk1 = -1;

    for (i = 0; i < 48; i++) {
        D_803D3448.unk2[i] = -1;
        D_803D3A20.unk2[i] = -1;
        D_803D3FF8.unk2[i] = -1;
    }
    func_8029D89C_6AEF4C();
    D_803D5508 = 0;
}

void func_8029F464_6B0B14(struct025 *arg0, u8 arg1, s32 arg2, s32 xPos, s32 zPos, s32 yPos, s16 arg6, s16 arg7, Gfx *dl) {
    s8 tmp;
    // arg1 is a 0..63
    if (arg0->unk1 < 59) {
        tmp = arg0->unk2[arg1];
        if (tmp == -1) {
            arg0->unk1++;
            arg0->unk32[arg0->unk1]       = arg1;
            arg0->displayList[arg0->unk1] = dl;
            arg0->unk3F4[arg0->unk1].unk0 = arg6;
            arg0->unk3F4[arg0->unk1].unk2 = arg7;
            arg0->unkAA[arg0->unk1]       = arg2;
            arg0->unk124[arg0->unk1].unk0 = xPos;
            arg0->unk124[arg0->unk1].unk4 = zPos;
            arg0->unk124[arg0->unk1].unk8 = yPos;

            arg0->unk6E[arg0->unk1] = -1;
            arg0->unk2[arg1] = arg0->unk1;
            if (arg0->unk0 != -1) {
                arg0->unk6E[arg0->unk0] = arg0->unk1;
            }
            arg0->unk0 = arg0->unk1;
        } else {
            arg0->unk1++;
            arg0->unk32[arg0->unk1]       = arg1;
            arg0->displayList[arg0->unk1] = dl;
            arg0->unk3F4[arg0->unk1].unk0 = arg6;
            arg0->unk3F4[arg0->unk1].unk2 = arg7;
            arg0->unkAA[arg0->unk1]       = arg2;
            arg0->unk124[arg0->unk1].unk0 = xPos;
            arg0->unk124[arg0->unk1].unk4 = zPos;
            arg0->unk124[arg0->unk1].unk8 = yPos;

            arg0->unk6E[arg0->unk1] = arg0->unk6E[tmp];
            arg0->unk6E[tmp] = arg0->unk1;

            if (arg0->unk6E[arg0->unk1] == -1) {
                arg0->unk0 = arg0->unk1;
            }
        }
    }
}

void func_8029F65C_6B0D0C(Animal *arg0, u16 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, Gfx *arg8) {
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

typedef struct {
  s16 unk0;
  s16 unk2;
  s16 unk4;
  s16 unk6;
  s16 unk8;
} fixme3; // size 0xA;

#if 0
fixme3 *D_803B1CDC_7C338C[16] = {
    D_803B1BCC_7C327C,
    D_803B1BEC_7C329C,
    D_803B1BF0_7C32A0,
    D_803B1BFC_7C32AC,
    D_803B1C1C_7C32CC,
    D_803B1C28_7C32D8,
    D_803B1C34_7C32E4,
    D_803B1C40_7C32F0,
    D_803B1C4C_7C32FC,
    D_803B1C58_7C3308,
    D_803B1C78_7C3328,
    D_803B1CC0_7C3370,
    D_803B1CCC_7C337C,
    D_803B1CD0_7C3380,
    D_803B1CD4_7C3384,
    D_803B1CD8_7C3388,
};
#else
extern fixme3 * D_803B1CDC_7C338C[];
#endif


#if 0
// CURRENT (14385)
void func_8029F7D4_6B0E84(DisplayList *arg0, Objects *arg1) {
    u8        pad2[0x8];
    struct065 *var_a1;      // sp480

    Animal    *new_var3;
    struct035 *new_var2;

    f32 temp_f20;
    f32 new_var;

    fixme3 *var_s0;

    s16 temp_v0;
    s32 i;
    s16 j;

    u16 var_v1;
    s32 var_t1;
    s32 var_s4_6;
    s32 red;
    s32 green;
    s32 var_s0_3;
    s32 temp_t8;
    s32 temp_t7;
    s16 var_s4;
    s16 var_t4;
    s16 var_t5;

    s16 tmp1;
    s16 tmp2;
    s32 tmp3;

    u16 color;
    s32 new_var4;

    s32 var_s4_2;

    s32 var_s0_2; // also works as u8 with slightly different stack

    u8        pad[0x64];

    struct077 sp318; // currently at 0x3b4
    struct077 sp2AC;
    s32 sp2A8;
    s32 var_t3; // sp298?

    struct077 sp210;

    u8 sp1AC[3]; // uninitialised?



    D_803D3430 = D_803D3430 + 1;
    D_803D3430 = D_803D3430 % 5;

    D_803D3432 = D_803D3432 + 8;
    D_803D3432 = D_803D3432 & 0x7F;

    D_803D3434 = arg0;

    gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
    gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
    gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);

    // something like this?
    for (i = 0; i < 40; i++) {

        for (var_a1 = D_803DA110[i].next; var_a1 != NULL; var_a1 = var_a1->next) {

            new_var3 = D_803D343C = var_a1->animal;
            D_803D3440 = new_var3->unk16C;
            D_803D3438 = &D_803D3440->unk4;

            if ((D_803D3440->unk82.unk2 == 0) && (var_a1 == D_803D343C->unk11C)) {
                if ((D_803D343C->unk3E & 0x3F) != 40) {

                    new_var2 = D_803D3440; // fakery
                    switch (new_var2->unk3) {
                    case 6:
                    case 15:
                        // get rgba16 color (first u16 of image?)
                        color = D_803D343C->unk3E & 0x3F;
                        color = func_8029A52C_6ABBDC(color);
                        var_v1 = func_802E8BBC_6FA26C(
                            D_803D343C->position.xPos.w,
                            D_803D343C->position.zPos.w,
                            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                            (D_803D3440->unk8E * D_803D343C->unk40) >> 0xB,
                            D_803D3440->unk90,
                            (((color & 0xF800) >> 9) & 0xFF), // red
                            (((color & 0x7C0) >> 4) & 0xFF),  // green
                            (((color & 0x3E) << 1) & 0xFF),   // blue
                            D_803D3440->unk94,
                            0);
                            break;
                    default:
                        var_v1 = func_802E8BBC_6FA26C(
                            D_803D343C->position.xPos.w,
                            D_803D343C->position.zPos.w,
                            D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                            (D_803D3440->unk8E * D_803D343C->unk40) >> 0xB,
                            D_803D3440->unk90,
                            D_803D3440->unk91, // red
                            D_803D3440->unk92, // green
                            D_803D3440->unk93, // blue
                            D_803D3440->unk94,
                            0);
                        break;
                    }

                    switch (var_v1) {
                    case 0:
                    case 2:
                        if (((D_803D343C->unk3E & 0xC0) != 0x80) && !(D_803D343C->unk163 & 8)) {
                            if (D_803D3440->unk96.a == 1) {
                                tmp1 = (D_803D3440->unk97 * D_803D343C->unk40) >> 0xB;
                                tmp2 = (D_803D3440->unk98 * D_803D343C->unk40) >> 0xB;
                                func_8034C8F8_75DFA8(
                                    D_803D343C->position.xPos.h,
                                    D_803D343C->position.zPos.h,
                                    D_803D343C->position.yPos.h + (D_803D343C->unk42 >> 1),
                                    (D_803D343C->yRotation << 8) / 360,
                                    D_803A8370_7B9A20[D_803D3440->unk96.b],
                                    tmp1,
                                    tmp2,
                                    0x9B,
                                    0,
                                    0,
                                    0,
                                    D_803D3440->unk99,
                                    0);
                            } else if (D_803D3440->unk96.a == 2) {
                                tmp1 = (D_803D3440->unk97 * D_803D343C->unk40) >> 0xB;
                                tmp2 = (D_803D3440->unk98 * D_803D343C->unk40) >> 0xB;
                                func_8034BD20_75D3D0(
                                    D_803D343C->position.xPos.h,
                                    D_803D343C->position.zPos.h,
                                    D_803D343C->position.yPos.h + (D_803D343C->unk42 >> 1),
                                    (D_803D343C->yRotation << 8) / 360,
                                    D_803A8370_7B9A20[D_803D3440->unk96.b],
                                    tmp1,
                                    tmp2,
                                    0x9B,
                                    0,
                                    0,
                                    0,
                                    D_803D3440->unk99,
                                    0);
                            }
                        }
                        break;
                    }

                    if (var_v1) {
                        // ??
                    } else {
                        switch (D_803D3440->unk3) {
                        case 0:
                            if (1) {
                                // maybe ?
                            }
                            break; // not this
                        case 1:
                            func_8029CEF0_6AE5A0(
                                D_803D343C->position.xPos.w,
                                D_803D343C->position.zPos.w,
                                D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                                D_803D343C->unk40,
                                D_803D3440->unk14 + D_803D343C->unk64,
                                &D_803D2E08,
                                D_803D3440->objectType,
                                0,
                                0,
                                0);
                            break;
                        case 2:
                            if (D_803D4BB0.unk1 < 60) {
                                D_803D4BB0.unk1++;
                                D_803D4BB0.unk32[D_803D4BB0.unk1] = D_803D343C->unk3E & 0x3F;
                                D_803D4BB0.displayList[D_803D4BB0.unk1] = D_803D343C->unk16C->unk4;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                D_803D4BB0.unkAA[D_803D4BB0.unk1] = D_803D343C->unk40;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                            }
                            break;
                        case 3:
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.displayList[D_803D45D0.unk0] = D_803D343C->unk16C->unk4;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.color[D_803D45D0.unk0].r = 0;
                                D_803D45D0.color[D_803D45D0.unk0].g = 0;
                                D_803D45D0.color[D_803D45D0.unk0].b = 0;
                            }
                            break;
                        case 4:
                            if (D_803D3434->usedModelViewMtxs >= 250) {
                                // debug something?
                                break;
                            } else {
                                gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF);
                                gDPSetTextureLUT(D_801D9E8C++, G_TT_NONE);
                                gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]); // TBD
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w,
                                    D_803D343C->position.zPos.w,
                                    D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF) + ((D_803D343C->unk40 * 55) << 5),
                                    (s32)(D_803D343C->unk40 * 0.6),
                                    D_803D343C->state == 1 ? 4 : 5,
                                    &D_803D2E08,
                                    D_803D343C->unk3E,
                                    0,
                                    0,
                                    0);
                            }
                            break;
                        case 5:
                            if ((D_803D3434->usedModelViewMtxs + 2) >= 250) {
                                break;
                            } else {
                                gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);

                                gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);

                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);

                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]);
                                guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0.0f, 8.0f, 10.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                guRotate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->unk28 >> 5, 0.0f, 1.0f, 0.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[1]);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2); // TBD
                                gSPTexture(D_801D9E8C++, 0, 0, 0, G_TX_RENDERTILE, G_ON);
                            }
                            break;
                        case 6:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            break;
                        case 7:
                            if ((D_803D3434->usedModelViewMtxs + 1) >= 250) {
                                break;
                            } else {
                                if (D_803D343C->state == 1) {
                                    func_8032CD70_73E420(D_803D343C, 0x83, 0x2AAA, 0, 1.0f, D_803D343C->position.xPos.h, D_803D343C->position.zPos.h, D_803D343C->position.yPos.h);
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);

                                    var_s4 = (D_803D3430 / 2);

                                    temp_v0 = distance_from_player(D_803D343C->position.xPos.h, D_803D343C->position.zPos.h, D_803D343C->position.yPos.h + D_803D343C->unk42 + 2);
                                    if (temp_v0 >= 512) {
                                        var_t4 = 0xFF;
                                        var_t5 = 0x7F;
                                    } else {
                                        var_t4 = temp_v0 / 2;
                                        var_t5 = temp_v0 / 4;
                                    }
                                    gSPDisplayList(D_801D9E90++, D_010049A0_3E270);
                                    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_0100A730_44000);
                                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                    gDPLoadSync(D_801D9E90++);
                                    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 511, 512);
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
                                    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, D_803D3432, 4*(31), 4*(31));
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                                    gSPTexture(D_801D9E90++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON); // qu016(0.5)
                                    gDPSetTextureLOD(D_801D9E90++, G_TL_TILE);
                                    gDPSetCombineLERP(D_801D9E90++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, COMBINED, COMBINED, 0, SHADE, 0);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_PASS, G_RM_ZB_XLU_SURF2);
                                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xB9, 0xB9, 0xFF, var_t4);
                                    gDPSetEnvColor(D_801D9E90++, 0x64, 0x64, 0xBE, var_t5);

                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_0100A6D0_43FA0);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPDisplayList(D_801D9E90++, D_01003B70_3D440);
                                } else {
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0x00, 0x00, 0xFF, 0xFF);
                                    var_s4 = 0;
                                }
                                gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                                gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
                                gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_010084A0_41D70 + ((var_s4 * 1372) << 1)); // 32x32 mipmap (0xAB8)
                                gDPTileSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPTileSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                                gDPTileSync(D_801D9E8C++);
                                gSPTexture(D_801D9E8C++, 0x8000, 0x8000, 5, G_TX_RENDERTILE, G_ON);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF) + 0x20000, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_01012B80_4C450);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                gDPPipeSync(D_801D9E8C++);

                                D_803D3434->unk39310++;
                            }
                            break;
                        case 8:
                            if (D_803D343C->unk16C->unk4 != 0) {
                                func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            }
                            for (var_s0 = D_803B1CDC_7C338C[D_803D3440->unk14]; var_s0->unk0 != 9999; var_s0++) {
                                func_802F603C_7076EC(
                                    var_s0->unk0 << 6,
                                    var_s0->unk2 << 6,
                                    var_s0->unk4 << 6,
                                    D_803D343C->zRotation,
                                    D_803D343C->yRotation,
                                    D_803D343C->unk40,
                                    &sp318);

                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w + (sp318.unk0 << 0xA),
                                    D_803D343C->position.zPos.w + (sp318.unk2 << 0xA),
                                    D_803D343C->position.yPos.w + (sp318.unk4 << 0xA) + (D_803D343C->unk42 << 0xF),
                                    (var_s0->unk6 * D_803D343C->unk40) >> 0xB,
                                    var_s0->unk8,
                                    &D_803D2E08,
                                    D_803D343C->unk3E,
                                    D_803D343C->unk200[0],
                                    D_803D343C->unk200[1],
                                    D_803D343C->unk200[2]);
                            }
                            break;
                        case 9:
                            func_8029F464_6B0B14(&D_803D3FF8, D_803D343C->unk3E & 0x3F, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            break;
                        case 10:
                            temp_v0 = 0x100 - D_803D343C->unk150;
                            new_var = ((COS(temp_v0 << 3)) / (temp_v0 + 16.0f)) / 16383.0f;
                            temp_f20 = (1.0f - new_var) * (D_803D343C->unk40 / (1.0f * 2048));
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, 0, 0, D_0100AF90_44860);
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, temp_f20 * 2048.0f, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_0100B2C0_44B90);
                            break;
                        case 11:
                            if (D_803D3434->usedModelViewMtxs >= 248) {
                                break;
                            } else {
                                gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                                gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);

                                gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);

                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E]);
                                gDPTileSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                                gDPTileSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                                gDPTileSync(D_801D9E8C++);

                                func_80125FE0(
                                    &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs],
                                    D_803D343C->position.xPos.w,
                                    D_803D343C->position.zPos.w,
                                    D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                                    D_803D343C->zRotation,
                                    D_803D343C->yRotation,
                                    D_803D343C->unk40 << 5,
                                    D_803D343C->unk40 << 5,
                                    D_803D343C->unk40 << 5);

                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[0]);
                                guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0.0f, 8.0f, 10.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                                guRotate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->unk28 >> 5, 0.0f, 1.0f, 0.0f);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_803D3438[1]);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            }
                            break;
                        case 12:
                            if (D_803D343C->state == 1) {
                                var_s0_2 = 0xFF;
                            } else {
                                var_s0_2 = 0x40;
                            }
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);

                            tmp3 = (COS(D_803D343C->unk14E) >> 9);
                            tmp3 = (tmp3 * D_803D343C->unk40) >> 0xB;

                            func_802F5F44_7075F4(
                                0,
                                0,
                                tmp3,
                                D_803D343C->zRotation,
                                D_803D343C->yRotation,
                                &sp2AC);
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.displayList[D_803D45D0.unk0] = D_803D343C->unk16C->unk8;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w + (sp2AC.unk0 << 0xD);
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w + (sp2AC.unk2 << 0xD);
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (sp2AC.unk4 << 0xD) + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.color[D_803D45D0.unk0].r = var_s0_2;
                                D_803D45D0.color[D_803D45D0.unk0].g = 0;
                                D_803D45D0.color[D_803D45D0.unk0].b = 0;
                            }
                            func_802F603C_7076EC(0xF, 4, 0, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp2AC);
                            func_8029CEF0_6AE5A0(
                                D_803D343C->position.xPos.w + (sp2AC.unk0 << 0x10),
                                D_803D343C->position.zPos.w + (sp2AC.unk2 << 0x10),
                                D_803D343C->position.yPos.w + (sp2AC.unk4 << 0x10) + (D_803D343C->unk42 << 0xF),
                                D_803D343C->unk40 >> 2,
                                0x20,
                                &D_803D2E08,
                                0,
                                var_s0_2,
                                0,
                                0);
                            break;
                        case 13:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            sp2A8 = (D_803D343C->position.yPos.h + (D_803D343C->unk42 * 0.6));
                            temp_t7 = ((COS(D_803D343C->unk152) >> 7) * (D_803D343C->unk42 >> 2)) >> 8;

                            temp_t8 = (D_803D343C->unk40 << 5) / 8.0;
                            temp_t8 = (D_803D343C->unk14E * temp_t8) >> 8;
                            // FIXME: v0/v1 swap
                            var_t3 = var_t1 = (ABS(SIN(D_803D343C->unk152) >> 7) * temp_t8) >> 8;

                            if (temp_t7 < 0) {
                                var_t1 = temp_t8;
                            } else {
                                var_t3 = temp_t8;
                            }
                            if (D_803D343C->unk14E > 0) {
                                red = ABS(SIN(D_803D343C->unk152) >> 7);
                                if (red > 0xFF) {
                                    red = 0xFF;
                                }
                                green = red >> 1;
                                gDPPipeSync(D_801D9E90++);
                                gSPDisplayList(D_801D9E90++, D_01004970_3E240);
                                gDPSetPrimColor(D_801D9E90++, 0, 0, (0xFF - red), (0xFF - green), 0xFF, 0xA0);
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, (sp2A8 + temp_t7) << 0x10, 0x14, ((D_803D343C->unk152 * 360) >> 8), var_t1, var_t1, var_t1);
                                gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E90++, D_0101B000_548D0);
                                gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                                gDPSetPrimColor(D_801D9E90++, 0, 0, red, green + 0x80, 0xFF, 0xA0);

                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, (sp2A8 - temp_t7) << 0x10, -0x14, ((D_803D343C->unk152 * 360) >> 8), var_t3, var_t3, var_t3);
                                gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E90++, D_0101B000_548D0);
                                gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                            }

                            func_8029CEF0_6AE5A0(
                                D_803D343C->position.xPos.w,
                                D_803D343C->position.zPos.w,
                                D_803D343C->position.yPos.w + ((D_803D343C->unk40 * 6) << 8),
                                (s32) (D_803D343C->unk40 * 0.2),
                                D_803D343C->state == 1 ? 4 : 5,
                                &D_803D2E08,
                                D_803D343C->unk3E,
                                0,
                                0,
                                0);
                            break;
                        case 15:
                            func_8029F65C_6B0D0C(D_803D343C, D_803D343C->unk3E, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w, D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            var_s4_2 = D_803D343C->unk40;
                            if (D_801552B0 != 0) {
                                var_s4_2 += guRandom() % 600;
                                D_803F2D24 = 1;
                            } else {
                                D_803F2D24 = 0;
                            }
                            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
                            gDPSetCombineMode(D_801D9E8C++, G_CC_MODULATEIA, G_CC_PASS2);

                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, var_s4_2 << 5, var_s4_2 << 5, var_s4_2 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_010106E0_49FB0);
                            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            var_s4_2 = D_803D343C->unk40;
                            if (D_801552B4 != 0) {
                                var_s4_2 += guRandom() % 600;
                            }
                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, var_s4_2 << 5, var_s4_2 << 5, var_s4_2 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_01011140_4AA10);
                            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            break;
                        case 16:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
                            if (D_803E4D28 & 4) {
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);
                            } else {
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
                            }
                            gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E & 0x3F]);
                            gDPTileSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                            gDPTileSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                            gDPTileSync(D_801D9E8C++);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, 1, 0);
                            break;
                        case 17:
                            func_8029F464_6B0B14(&D_803D3FF8, D_803D343C->unk3E & 0x3F, D_803D343C->unk40, D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk16C->unk4);
                            if (D_803D343C->unk200[0] & 2) {
                                func_802F603C_7076EC(D_803A0580_7B1C30[0][0], D_803A0580_7B1C30[0][1], D_803A0580_7B1C30[0][2], D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, 0x64, 0x64);
                            }
                            if (D_803D343C->unk200[0] & 4) {
                                func_802F603C_7076EC(-D_803A0580_7B1C30[0][0], D_803A0580_7B1C30[0][1], D_803A0580_7B1C30[0][2], D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(D_803D343C->position.xPos.w + (sp210.unk0 << 0x10), D_803D343C->position.zPos.w + (sp210.unk2 << 0x10), D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF), (D_803D343C->unk40 / 2.6), 0x20, &D_803D2E08, 0, 0xFF, 0x64, 0x64);
                            }
                            if (D_803D343C->unk200[0] & 0x18) {
                                if (D_803D343C->unk200[0] & 8) {
                                    var_s0_3 = 0xFF;
                                } else {
                                    var_s0_3 = 0;
                                }
                                func_802F603C_7076EC(D_803A0580_7B1C30[1][0], D_803A0580_7B1C30[1][1], D_803A0580_7B1C30[1][2], D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w + (sp210.unk0 << 0x10),
                                    D_803D343C->position.zPos.w + (sp210.unk2 << 0x10),
                                    D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF),
                                    (D_803D343C->unk40 / 2.6),
                                    0x20,
                                    &D_803D2E08,
                                    0,
                                    0xFF,
                                    var_s0_3,
                                    0);
                                func_802F603C_7076EC(-D_803A0580_7B1C30[1][0], D_803A0580_7B1C30[1][1], D_803A0580_7B1C30[1][2], D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40, &sp210);
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w + (sp210.unk0 << 0x10),
                                    D_803D343C->position.zPos.w + (sp210.unk2 << 0x10),
                                    D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF),
                                    (D_803D343C->unk40 / 2.6),
                                    0x20,
                                    &D_803D2E08,
                                    0,
                                    0xFF,
                                    var_s0_3,
                                    0);
                            }
                            if (D_803D343C->unk200[0] & 0x20) {
                                func_802F603C_7076EC(
                                    D_803A0580_7B1C30[2][0],
                                    D_803A0580_7B1C30[2][1],
                                    D_803A0580_7B1C30[2][2],
                                    D_803D343C->zRotation,
                                    D_803D343C->yRotation,
                                    D_803D343C->unk40,
                                    &sp210);

                                if (D_803D4BB0.unk1 < 60) {
                                    D_803D4BB0.unk1++;
                                    D_803D4BB0.unk32[D_803D4BB0.unk1] = D_803D343C->unk3E & 0x3F;
                                    D_803D4BB0.displayList[D_803D4BB0.unk1] = D_05004070_8D2D0;
                                    D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                    D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                    D_803D4BB0.unkAA[D_803D4BB0.unk1] = D_803D343C->unk40;
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w + (sp210.unk0 << 0x10);
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w + (sp210.unk2 << 0x10);
                                    D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (sp210.unk4 << 0x10) + (D_803D343C->unk42 << 0xF);
                                    D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                                }
                            }
                            break;
                        case 18:
                            if (D_803D343C->state == 1) {
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w,
                                    D_803D343C->position.zPos.w,
                                    D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                                    D_803D343C->unk40,
                                    D_803D343C->unk3E,
                                    &D_803D2E08,
                                    0,
                                    D_803D343C->unk200[0],
                                    D_803D343C->unk200[1],
                                    D_803D343C->unk200[2]);
                            }
                            break;
                        case 22:
                            if (D_803D343C->state == 1) {
                                func_8029CEF0_6AE5A0(
                                    D_803D343C->position.xPos.w,
                                    D_803D343C->position.zPos.w,
                                    D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF),
                                    D_803D343C->unk40,
                                    D_803D343C->unk3E,
                                    &D_803D2E08,
                                    0x7F,
                                    D_803D343C->unk200[0],
                                    D_803D343C->unk200[1],
                                    D_803D343C->unk200[2]);
                            }
                            break;
                        case 19:
                            if (D_803D343C->state == 1) {
                                var_s4_6 = (D_803D343C->unk40 * 3) >> 2;
                            } else {
                                var_s4_6 = D_803D343C->unk40;
                            }
                            if (D_803D4BB0.unk1 < 60) {
                                D_803D4BB0.unk1++;
                                D_803D4BB0.unk32[D_803D4BB0.unk1] = D_803D343C->unk3E & 0x3F;
                                D_803D4BB0.displayList[D_803D4BB0.unk1] = D_803D343C->unk16C->unk4;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk0 = D_803D343C->zRotation;
                                D_803D4BB0.unk3F4[D_803D4BB0.unk1].unk2 = D_803D343C->yRotation;
                                D_803D4BB0.unkAA[D_803D4BB0.unk1] = var_s4_6;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk0 = D_803D343C->position.xPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk4 = D_803D343C->position.zPos.w;
                                D_803D4BB0.unk124[D_803D4BB0.unk1].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D4BB0.unk6E[D_803D4BB0.unk1] = -1;
                            }
                            if ((D_803D3434->usedModelViewMtxs + 2) >= 250) {
                                break;
                            } else {
                                var_s4_6 = var_s4_6 << 5;

                                gDPSetTextureLUT(D_801D9E8C++, G_TT_NONE);
                                gDPSetCombineLERP(D_801D9E8C++,
                                    SHADE, 0, PRIMITIVE, 0,
                                    SHADE, 0, PRIMITIVE, 0,
                                    SHADE, 0, PRIMITIVE, 0,
                                    SHADE, 0, PRIMITIVE, 0);
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
                                if (D_803D343C->state == 1) {
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);
                                } else {
                                    gDPSetPrimColor(D_801D9E8C++, 0, 0, 0x40, 0x00, 0x00, 0xFF);
                                }
                                func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, var_s4_6, var_s4_6, var_s4_6);
                                gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                gSPDisplayList(D_801D9E8C++, D_01011B78_4B448);
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

                                if (D_803D343C->state == 1) {
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
                                    gDPSetCycleType(D_801D9E90++, G_CYC_1CYCLE);
                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADING_SMOOTH);
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gDPSetCombineLERP(D_801D9E90++, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                                    gDPSetPrimColor(D_801D9E90++, 0, 0, 0xFF, 0x00, 0x00, 0xA0);

                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, var_s4_6, var_s4_6, var_s4_6);
                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_01011AB0_4B380);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                                    gSPSetGeometryMode(D_801D9E90++, G_FOG);
                                }
                            }
                            break;
                        case 20:
                            if (D_803D343C->state == 1) {
                                sp1AC[0] = 0;
                            } else {
                                sp1AC[0] = 0;
                            }
                            if (D_803D45D0.unk0 < 60) {
                                D_803D45D0.unk0++;
                                D_803D45D0.displayList[D_803D45D0.unk0] = D_803D343C->unk16C->unk4;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk0 = D_803D343C->zRotation;
                                D_803D45D0.unk34C[D_803D45D0.unk0].unk2 = D_803D343C->yRotation;
                                D_803D45D0.unk2[D_803D45D0.unk0] = D_803D343C->unk40;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk0 = D_803D343C->position.xPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk4 = D_803D343C->position.zPos.w;
                                D_803D45D0.unk7C[D_803D45D0.unk0].unk8 = D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF);
                                D_803D45D0.color[D_803D45D0.unk0].r = sp1AC[0];
                                D_803D45D0.color[D_803D45D0.unk0].g = sp1AC[1];
                                D_803D45D0.color[D_803D45D0.unk0].b = sp1AC[2];
                            }
                            if (D_803D343C->state == 1) {
                                if (D_803D3434->usedModelViewMtxs >= 250) {
                                    break;
                                } else {
                                    gDPPipeSync(D_801D9E90++);
                                    gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
                                    gDPSetCycleType(D_801D9E90++, G_CYC_1CYCLE);
                                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                                    gSPSetGeometryMode(D_801D9E90++, G_SHADING_SMOOTH);
                                    gSPClearGeometryMode(D_801D9E90++, G_FOG);
                                    gDPSetCombineLERP(D_801D9E90++, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE);
                                    gDPSetRenderMode(D_801D9E90++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                                    gSPMatrix(D_801D9E90++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E90++, D_0100F4F0_48DC0);
                                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);
                                    gSPSetGeometryMode(D_801D9E90++, G_FOG);
                                }
                            }
                            break;
                        case 21:
                            gSPDisplayList(D_801D9E8C++, D_01004AF8_3E3C8);
                            if (D_803E4D28 & 4) {
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);
                            } else {
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2);
                            }
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_0102F010_688E0 + (((D_803D343C->unk3E & 0x3F) * 256) << 3));
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPLoadSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
                            gDPPipeSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                            gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31)); // qu102
                            guLookAtReflect(&D_803D3434->unk38CD0[D_803D3434->unk39310], &D_803D3434->unk38A50[D_803D3434->unk39310], D_803F2C44, D_803F2C48, D_803F2C4C, (f32) D_803D343C->position.xPos.w / 65536.0f, (f32) D_803D343C->position.zPos.w / 65536.0f, (f32) D_803D343C->position.yPos.w / 65536.0f, D_80204200, D_80204204, D_80204208);
                            gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
                            gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, (u8) 3, (u8) 1);
                            break;
                        case 23:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
                            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                            func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), (s16) (s32) D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5, D_803D343C->unk40 << 5);
                            gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_040165E0_116330 : D_05001720_8A980);

                            if (D_803D343C->unk158 == 0) {
                                for (j = 0; j < 3; j++) {
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0, 0, 0, 0, j * 120, 0x10000, 0x10000, 0x10000);
                                    gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_040148B0_114600 : D_04014990_DC3C0);
                                    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                }
                            }
                            if (D_803D343C->unk158 == 0) {
                                gSPDisplayList(D_801D9E8C++, D_01004AF8_3E3C8);
                                gDPSetRenderMode(D_801D9E8C++, gRenderMode1, gRenderMode2); // gDPSetRenderMode(D_801D9E8C++, D_803C0644, D_803C064C);
                                gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_01031010_6A8E0);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPLoadSync(D_801D9E8C++);
                                gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1023, 256);
                                gDPPipeSync(D_801D9E8C++);
                                gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
                                gDPSetTileSize(D_801D9E8C++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));

                                guLookAtReflect(&D_803D3434->unk38CD0[D_803D3434->unk39310], &D_803D3434->unk38A50[D_803D3434->unk39310], D_803F2C44, D_803F2C48, D_803F2C4C, (f32) D_803D343C->position.xPos.w / 65536.0f, (f32) D_803D343C->position.zPos.w / 65536.0f, (f32) D_803D343C->position.yPos.w / 65536.0f, D_80204200, D_80204204, D_80204208);
                                gSPLookAtX(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[0]);
                                gSPLookAtY(D_801D9E8C++, &D_803D3434->unk38A50[D_803D3434->unk39310].l[1]);
                                D_803D3434->unk39310++;

                                for (j = 0; j < 3; j++) {
                                    func_80125FE0(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], 0, 0, 0, 0, j * 120, 0x10000, 0x10000, 0x10000);
                                    gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                                    gSPDisplayList(D_801D9E8C++, D_803D343C->unk16C->objectType == 0xF5 ? D_050007A0_A1870 : D_04015960_DD390);
                                    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                                }
                                gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
                            }
                            break;
                        case 24:
                            gSPDisplayList(D_801D9E8C++, D_010049A0_3E270);
                            gSPSetGeometryMode(D_801D9E8C++, gGeometryMode);
                            gDPSetRenderMode(D_801D9E8C++, gRenderMode1, G_RM_AA_ZB_OPA_SURF2);
                            gSPDisplayList(D_801D9E8C++, D_01004510_3DDE0);
                            gDPSetTextureImage(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800BA760[D_803D343C->unk3E & 0x3F]);
                            gDPTileSync(D_801D9E8C++);
                            gDPSetTile(D_801D9E8C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                            gDPTileSync(D_801D9E8C++);
                            gDPLoadBlock(D_801D9E8C++, G_TX_LOADTILE, 0, 0, 1372, 0);
                            gDPTileSync(D_801D9E8C++);
                            func_80397F5C_7A960C(D_803D343C->position.xPos.w, D_803D343C->position.zPos.w, D_803D343C->position.yPos.w + (D_803D343C->unk42 << 0xF), D_803D343C->zRotation, (s16) (s32) D_803D343C->yRotation, D_803D343C->unk40 << 5, (u8) 4, (u8) 2);                                break;
                            break;
                        default:
                            break;
                        }
                    }
                    if (1) { } if (1) { } if (1) { } if (1) { }
                }
            }
        }
    }

    if (D_803D5508 > 0) {
        func_8029DD84_6AF434();
        // if (!D_803D4BB0.unk1) {};
    }
    if (D_803D4BB0.unk1 != -1) {
        func_8029E528_6AFBD8();
    }
    if (D_803D45D0.unk0 != -1) {
        func_8029E7D0_6AFE80();
    }
    if (D_803D3FF8.unk1 != -1) {
        func_8029EAAC_6B015C();
    }
    func_8029F218_6B08C8();
    if (D_803D2E08.unk1 != -1) {
        func_8029D0A8_6AE758();
    }
    if (D_803E97C0 > 0) {
        func_8029E100_6AF7B0();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AE5A0/func_8029F7D4_6B0E84.s")
#endif
