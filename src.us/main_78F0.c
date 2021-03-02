#include <ultra64.h>
#include "common.h"


void func_8012C1F0(Gfx **arg0) {
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
    D_8023F1E0.unk0 = &D_80154370;
    D_8023F1E0.fontAddress = &D_800E1220; // _fontbufferSegmentStart
    D_8023F1E0.unk8 = 16;
    D_8023F1E0.unk9 = 16;
    D_8023F1E0.unkA = 4;
    D_8023F1E0.glyphBytes = 128;
}

void select_lcd_font(void) {
    D_8023F1E0.fontAddress = &D_80158550; // 7-segment display font
    D_8023F1E0.unk8 = 16;
    D_8023F1E0.unk9 = 16;
    D_8023F1E0.unkA = 16;
    D_8023F1E0.glyphBytes = 512;
}

s16 func_8012C314(f32 arg0) {
    f32 a = arg0 / D_8023F1E8;
    s16 res = D_8023F1F8 * a;
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C978.s")

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
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE,   0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTile((*arg0)++, G_IM_FMT_I, G_IM_SIZ_4b,  1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*arg0)++, G_TX_RENDERTILE, 0, 0, 60, 60);
}

void func_8012FAD4(Gfx **dl, s32 arg1) {
    gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, arg1 & 0x1FFFFFFF);
    gDPLoadSync((*dl)++);
    gDPLoadBlock((*dl)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*dl)++);
}

void load_glyph(Gfx **arg0, s16 arg1) {
    gDPSetTextureImage((*arg0)++, G_IM_FMT_I, G_IM_SIZ_16b, 1, ((arg1 * D_8023F1E0.glyphBytes) + D_8023F1E0.fontAddress) & 0x1FFFFFFF);
    gDPLoadSync((*arg0)++);
    gDPLoadBlock((*arg0)++, G_TX_LOADTILE, 0, 0, 63, 2048);
    gDPPipeSync((*arg0)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801304EC.s")

void func_801308B4(u8 *src, u16 *dst) {
    u8 tmp;
    while (*src != NULL) {
        tmp = *src;
        *dst++ = tmp + 272; // 0x110
        src++;
    }

    *dst = 30000;
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801308E8.s")
// miles and miles away
// s16 func_801308E8(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3) {
//     s16 temp_s1;
//     s16 temp_s3;
//     s16 temp_s4;
//     void *temp_s0;
//     struct024 *temp_v0_2;
//     s32 phi_s0;
//     s32 phi_s0_2;
//     s16 phi_s2;
//     s16 phi_s1;
//     void *phi_s0_4;
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
//     temp_v0_2 = &D_80154500[arg1];
//     dma_read(temp_v0_2->start, &D_8022E3F0, temp_v0_2->end - temp_v0_2->start);
//     rnc_decompress(&D_8022E3F0, &D_80235410);
//     strncpy(&D_80235410 + D_80235410[arg0], &D_8022E3F0, 12000);
//
//     temp_s4 = D_8022E3F0[0];
//     phi_s2 = (u16)0;
//     phi_s1 = (u16)0;
//     phi_s0_4 = &D_8022E3F0[1];
//     while (phi_s1++ < (s32) temp_s4) {
//         strncpy(D_8022E3F0[phi_s1], arg3[phi_s1], phi_s0_4);
//     }
// //     if ((s32) temp_s4 > 0) {
// // loop_12:
// //         temp_s3 = *phi_s0_4;
// //         temp_s0 = phi_s0_4 + 2;
// //         *(arg2 + (phi_s1 * 2)) = phi_s2;
// //         temp_s1 = phi_s1 + 1;
// //         phi_s2 = (s16) (phi_s2 + temp_s3);
// //         phi_s1 = temp_s1;
// //         phi_s0_4 = temp_s0 + (((s32) temp_s3 / 2) * 2);
// //         if ((s32) temp_s1 < (s32) temp_s4) {
// //             goto loop_12;
// //         }
// //     }
//     return temp_s4;
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
