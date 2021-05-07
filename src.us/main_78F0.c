#include <ultra64.h>
#include "common.h"


#if 0

// language file offsets
// at ROM 0x2fc00
const s32 D_80154500[37][2] = {
    /* start, end */
    {0x617C30, 0x61A4A0}, // lang1
    {0x61A4A0, 0x61B820},
    {0x61B820, 0x61C2F0},
    {0x61C2F0, 0x61CE40},
    {0x61CE40, 0x61D990},
    {0x61D990, 0x61E310},
    {0x61E310, 0x61EE10},
    {0x61EE10, 0x61FA70},
    {0x61FA70, 0x620DE0},
    {0x620DE0, 0x622280},
    {0x622280, 0x622FB0},
    {0x622FB0, 0x623720},
    {0x623720, 0x624080},
    {0x624080, 0x624B90},
    {0x624B90, 0x625930},
    {0x625930, 0x6265F0},
    {0x6265F0, 0x627DA0},
    {0x627DA0, 0x6286E0},
    {0x6286E0, 0x628F80},
    {0x628F80, 0x629A00},
    {0x629A00, 0x62A4B0},
    {0x62A4B0, 0x62ADA0},
    {0x62ADA0, 0x62C170},
    {0x62C170, 0x62C920},
    {0x62C920, 0x62D2A0},
    {0x62D2A0, 0x62DB10},
    {0x62DB10, 0x62E550},
    {0x62E550, 0x62EE70},
    {0x62EE70, 0x62F620},
    {0x62F620, 0x630510},
    {0x630510, 0x6336B0},
    {0x6336B0, 0x633720},
    {0x633720, 0x6364B0},
    {0x6364B0, 0x6370C0},
    {0x6370C0, 0x637110},
    {0x637110, 0x637160}, // lang36
    {0, 0} /* might just be alignment? */
};

#endif

// at ROM 0x2fd30
const Gfx D_80154628[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetColorDither(G_CD_NOISE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};

void load_default_display_list(Gfx **arg0) {
    gSPDisplayList((*arg0)++, &D_80154628);
}

// does not appear to be used for cutscenes
void set_menu_text_color(u8 r, u8 g, u8 b, u8 a) {
    D_8023F1F0 = r; // textColorR
    D_8023F1F1 = g; // textColorG
    D_8023F1F2 = b; // textColorB
    D_8023F1F3 = a; // textColorA
}

void select_font(u8 arg0, u8 fontType, u8 arg2, u8 arg3) {
    D_8023F1F4 = arg0;
    D_8023F1F5 = arg2;
    if (fontType == 3) {
        select_lcd_font();
    } else {
        select_comic_sans_font();
    }
}

void select_comic_sans_font(void) {
    D_8023F1E0.unk0 = D_80154370;
    D_8023F1E0.fontAddress = D_800E1220; // _fontbufferSegmentStart
    D_8023F1E0.unk8 = 16; // width?
    D_8023F1E0.unk9 = 16; // height?
    D_8023F1E0.unkA = 4;  // color bitdepth?
    D_8023F1E0.glyphBytes = 128;
}

void select_lcd_font(void) {
    D_8023F1E0.fontAddress = D_80158550; // 7-segment display font
    D_8023F1E0.unk8 = 16; // width?
    D_8023F1E0.unk9 = 16; // height?
    D_8023F1E0.unkA = 16; // color bitdepth?
    D_8023F1E0.glyphBytes = 512;
}

s16 func_8012C314(f32 arg0) {
    f32 a = arg0 / D_8023F1E8;
    s16 res = D_8023F1F8 * a;
    return res;
}

u8 convert_text_to_int(s16 *arg0) {
#define TILESET_ZERO (TILESET_ASCII_OFFSET + '0')
#define TILESET_NINE (TILESET_ASCII_OFFSET + '9')
    u8 ret = 0, i = 0;

    while ((arg0[i] >= TILESET_ZERO) && (arg0[i] <= TILESET_NINE)) {
        ret = (ret*10 + arg0[i]) - TILESET_ZERO;
        i++;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C678.s")
// urghhh
// s32 func_8012C678(s16 *arg0, u16 arg1, u16 arg2) {
//     u8 spD8[16];
//     s16 sp34;
//     s16 sp32;
//     s16 sp30;
//     s16 temp_a3;
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s16 temp_v0_3;
//     s32 temp_t4;
//     u32 temp_t0;
//     s16 *temp_a0;
//     s32 phi_v1;
//     s16 phi_a3;
//     s16 phi_v0;
//     s16 phi_a3_2;
//
//     temp_v0 = *arg0; //->unk0;
//     if (temp_v0 == 0x150) {
//         *arg0++;
//         // temp_v0_2 = *(arg0 + 1); //->unk2;
//         temp_a0 = arg0 + 2;
//         if (*arg0 == 0x157) {
//             // sp30 = temp_a0->unk2;
//             sp34 = 0x7530;
//             sp32 = *(temp_a0 + 4);
//             phi_a3 = (u16)0;
//             if ((s32) sp30 >= 0x140) {
//                 phi_a3 = (u16)0;
//                 if ((s32) sp30 < 0x14A) {
//                     phi_v1 = 0;
//                     // phi_v0 = (sp + (0 * 2))->unk30;
//                     phi_a3_2 = (u16)0;
// loop_5:
//                     temp_t4 = (phi_v1 + 1) & 0xFF;
//                     temp_v0_3 = *(&sp30 + (temp_t4 * 2));
//                     temp_a3 = (phi_v0 + (phi_a3_2 * 0xA)) - 0x140;
//                     phi_a3 = temp_a3;
//                     if ((s32) temp_v0_3 >= 0x140) {
//                         phi_v1 = temp_t4;
//                         phi_a3 = temp_a3;
//                         phi_v0 = temp_v0_3;
//                         phi_a3_2 = temp_a3;
//                         if ((s32) temp_v0_3 < 0x14A) {
//                             goto loop_5;
//                         }
//                     }
//                 }
//             }
//             // "%d"
//             sprintf(&spD8, &D_8015ACA4, D_8023F206[phi_a3]);
//             prepare_text(&spD8, &D_8023F248);
//             func_8012D374(&D_801D9E7C, &D_8023F248, arg1, arg2, D_8023F1F8, D_8023F1FC, -1);
//             return 1;
//
//         }
//         // change text color
//         if (*arg0 == 339) {  // 'C' in tileset
//             switch (*++arg0) {
//             case 354: // 16: // 'R' in tileset
//                 // red
//                 D_8023F1F0 = 0xC8;
//                 D_8023F1F1 = 0x28;
//                 D_8023F1F2 = 0x28;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 343: // 5:  // 'G' in tileset
//                 // green
//                 D_8023F1F0 = 0;
//                 D_8023F1F1 = 0xFF;
//                 D_8023F1F2 = 0;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 338: // 0     // 'B' in tileset
//                 // blue
//                 D_8023F1F0 = 0x78;
//                 D_8023F1F1 = 0x78;
//                 D_8023F1F2 = 0xFF;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 361: // 14:
//                 // yellow
//                 D_8023F1F0 = 0xFF;
//                 D_8023F1F1 = 0xFF;
//                 D_8023F1F2 = 0;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 359: // 21:
//                 // white
//                 D_8023F1F0 = 0xFF;
//                 D_8023F1F1 = 0xFF;
//                 D_8023F1F2 = 0xFF;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 360: // 22:
//                 // black
//                 D_8023F1F0 = 0;
//                 D_8023F1F1 = 0;
//                 D_8023F1F2 = 0;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 352: //23:
//                 // purple
//                 D_8023F1F0 = 0xFF;
//                 D_8023F1F1 = 0;
//                 D_8023F1F2 = 0xFF;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             case 339: // 1
//                 // cyan
//                 D_8023F1F0 = 0;
//                 D_8023F1F1 = 0xFF;
//                 D_8023F1F2 = 0xFF;
//                 D_8023F1F3 = 0xFF;
//                 return 2;
//             }
//         }
//     } else if (temp_v0 == 20000) { // newline
//         return 3;
//     }
//     return 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/display_text.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012D374.s")

void draw_glyph(Gfx **arg0, s16 *arg1, u16 x, u16 y, f32 width, f32 height) {
    D_8023F1F8 = width;
    D_8023F1FC = height;
    func_8012FA78(arg0);
    load_glyph(arg0, *arg1);

    gSPTextureRectangle((*arg0)++, x * 4, y * 4, (x + (s32) D_8023F1F8) * 4, (y + (s32) D_8023F1FC) * 4, G_TX_RENDERTILE, 0, 0, 16384.0f / D_8023F1F8, 16384.0f / D_8023F1FC);
    gDPPipeSync((*arg0)++);
}

// write text to screen
#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012DEF8.s")

s32 func_8012E724(u16 *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0 = *arg0;
    if (temp_v0 == 336) {
        temp_v0 = *++arg0;
        if (temp_v0 == 343) {
            return 1;
        } else if (temp_v0 == 339) {
            return 2;
        }
    } else if ((u16)temp_v0 == 20000) {
        return 3;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012E78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012EB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012F160.s")

void func_8012FA78(Gfx **arg0) {
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE,   0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b,  1, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 60, 60);
}

void func_8012FAD4(Gfx **dl, s32 arg1) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, arg1 & 0x1FFFFFFF);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

void load_glyph(Gfx **arg0, s16 tileId) {
    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (tileId * D_8023F1E0.glyphBytes + (s32)D_8023F1E0.fontAddress) & 0x1FFFFFFF);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*arg0)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/display_score.s")
// void display_score(Gfx **arg0, u8 *score, u16 x_offset, u16 y_offset) {
//     s16 temp_t3;
//     u8 temp_t7;
//     s16 digits;
//     s16 temp_s3;
//
//     D_8023F1F8 = 16.0f;
//     D_8023F1FC = 16.0f;
//
//     digits = 0;
//     while (*score != 0) {
//         temp_t7 = (*score - 32) & 0xffff; // probably not it
//         D_8023F1E0.unk0 += temp_t7;
//         D_8023F1E0.unk0 -= temp_t7;
//         digits += 16; // how many.. chars? bytes? horizontal pixels?
//         score++;
//     }
//
//     gDPPipeSync((*arg0)++);
//     gDPSetCycleType((*arg0)++, G_CYC_1CYCLE);
//     gDPSetCombineMode((*arg0)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//     gDPSetRenderMode((*arg0)++, Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM), Z_UPD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
//     gDPSetDepthSource((*arg0)++, G_ZS_PRIM);
//     gDPSetPrimDepth((*arg0)++, 0, 0);
//     gDPSetTexturePersp((*arg0)++, G_TP_NONE);
//     gDPSetTextureLUT((*arg0)++, G_TT_NONE);
//     gDPSetAlphaCompare((*arg0)++, G_AC_NONE);
//
//     while (*score != 0) {
//
//         temp_t7 = (*score - 32); // ASCII to ?
//         D_8023F1E0.unk0 += temp_t7;
//         if (temp_t7 != 0) {
//             s32 img = &D_80158550[(temp_t7 << 8)];
//             gDPSetTextureImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, img - 4096);
//             gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//             gDPLoadSync((*arg0)++);
//             gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 255, 512);
//             gDPPipeSync((*arg0)++);
//             gDPSetTile((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD);
//             gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 60, 60);
//
//             temp_t3 = x_offset - digits;
//             temp_s3 = y_offset;
//             // temp_v0_18->unk0 = (s32) (((((temp_t3 + 0x18) * 4) & 0xFFF) << 12) | 0xE4000000 | (((temp_s3 + 0x10) * 4) & 0xFFF));
//             // temp_v0_18->unk4 = (s32) (((((temp_t3 + 8) * 4) & 0xFFF) << 12) | ((temp_s3 * 4) & 0xFFF));
//             gSPTextureRectangle((*arg0)++, ((temp_t3 + 8)), (temp_s3), ((temp_t3 + 0x18)), ((temp_s3 + 0x10)), G_TX_RENDERTILE, 0, 0, 1024, 1024);
//         }
//         D_8023F1E0.unk0 -= temp_t7;
//         x_offset += 16;
//         score++;
//     }
//
//     gDPPipeSync((*arg0)++);
// }

void prepare_text(u8 *src, s16 *dst) {
    u8 tmp;
    while (*src != NULL) {
        tmp = *src;
        *dst++ = tmp + 272; // 0x110
        src++;
    }

    *dst = 30000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801308E8.s")
// NON-MATCHING: a few differences
// s16 func_801308E8(s16 arg0, s16 language, u16 *arg2, s16 *arg3) {
//     s16 copied;
//     s16 chunk_size;
//     s16 i;
//     s16 *src;
//     s32 start, end;
//     s16 temp_s4;
//
//     if (D_80204260 == 1) {
//         if (arg0 < 0) {
//             arg0 = 2;
//         }
//         if (arg0 >= 9) {
//             arg0 = 2;
//         }
//         if (arg0 == 20) {
//             arg0 = 2;
//         }
//     }
//     if (D_80204260 == 2) {
//         arg0 = 2;
//     }
//     if (D_80204260 == 0) {
//         arg0 = 6;
//     }
//
//
//     // D_8022E3F0 is a scratch area:
//     // read into D_8022E3F0
//     // decompress from D_8022E3F0 into D_80235410
//     // copy 12000 bytes from D_80235410 into D_8022E3F0
//
//     start = D_80154500[language*2][0];
//     end = D_80154500[language*2][1];
//     dma_read(start, D_8022E3F0, end - start);
//     UnpackRNC((RNC_fileptr)D_8022E3F0, (u8*)D_80235410);
//     strncpy((u8*)D_80235410 + D_80235410[arg0], D_8022E3F0, 12000);
//
//     src = &D_8022E3F2; // offset?
//     copied = 0;
//
//     temp_s4 = D_8022E3F0[0];  // total_chunks?
//     for (i = 0; i < temp_s4; i++) {
//         chunk_size = *src++;
//         *arg2 = copied;
//         strncpy(src, arg3 + copied, chunk_size);
//         copied += chunk_size ;
//         src += chunk_size / 2;
//     }
//
//     return copied;
// }

s16 *func_80130A90(s16 arg0) {
    return &D_8022E3F0[D_8022E3F0[arg0 + 7000] + 7350];
}

s16 func_80130AC0(s16 *arg0) {
    s16 cnt = 0;

    while (*arg0 != 30000) {
        cnt++;
        arg0++;
    };

    return cnt;
}
