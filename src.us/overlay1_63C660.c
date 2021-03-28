#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay1_63C660/func_80298FC0_63C660.s")
// NON-MATCHING: still a fair way to go here...
// s32 func_80298FC0_63C660(s16 arg0) {
//     s32 pad[2];
//     s16 *src, *dst;
//     s16 temp_a0_3;
//     u8 *phi_s0;
//     s16 i;
//     s16 phi_s0_3;
//     u16 *phi_v1_2;
//     s32 phi_a0_3;
//     s8 tmp;
//
//     if (arg0 == 0) {
//         for (i = 0; i < 9; i++) {
//             func_801308E8(i, 32, &D_80231AA0, &D_80231D5C);
//             if ((i != 6) && (i != 0)) {
//                 src = func_80130A90(28);
//                 dst = D_803B0400[i]; // what is this var
//                 while (*src != 30000) {
//                     *dst++ = *src++;
//                 }
//                 *dst = 30000; // 0x7530
//             }
//         }
//
//         D_803B0590 = 1;
//         D_803B0592 = 0;
//         D_803B0594 = 0;
//         D_803B0596 = D_803B0590;
//         return 0;
//     }
//
//     if (D_803B0594 != 0) {
//         D_803B0594 -= 8;
//     }
//
//     if (D_803B0592 != 0xF8) {
//         D_803B0592 += 8;
//     }
//
//     switch (D_803B0590) {
//     case 0:
//         phi_s0 = D_80301520;
//         break;
//     case 1:
//         phi_s0 = D_802FD920;
//         break;
//     case 2:
//         phi_s0 = D_802FE520;
//         break;
//     case 3:
//         phi_s0 = D_802FF120;
//         break;
//     case 4:
//         phi_s0 = D_802FFD20;
//         break;
//     case 5:
//         phi_s0 = D_80300920;
//         break;
//     case 6:
//         phi_s0 = D_80302120;
//
//     }
//     func_801366BC(&D_801D9E7C, D_803B0592, D_803B0592, D_803B0592, D_803B0592);
//     gDPPipeSync(D_801D9E7C++);
//
//     // src_6->unk4 = -0x805;
//     // temp_v0_6->unk0 = 0xFC30FE61;
//     gDPSetCombineLERP(D_801D9E7C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
//     gDPSetRenderMode(D_801D9E7C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x80, 0x80, 0x80, D_803B0592);
//     gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
//     gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
//
//     func_80136938(&D_801D9E7C, phi_s0, 48, 31, 180, 140, 0, 0, 70, 50, 16);
//
//     switch (D_803B0596) {
//     case 0: // switch 2
//         phi_s0 = D_80301520;
//         break;
//     case 1: // switch 2
//         phi_s0 = D_802FD920;
//         break;
//     case 2: // switch 2
//         phi_s0 = D_802FE520;
//         break;
//     case 3: // switch 2
//         phi_s0 = D_802FF120;
//         break;
//     case 4: // switch 2
//         phi_s0 = D_802FFD20;
//         break;
//     case 5: // switch 2
//         phi_s0 = D_80300920;
//         break;
//     case 6: // switch 2
//         phi_s0 = D_80302120;
//     }
//
//     func_801366BC(&D_801D9E7C, D_803B0595, D_803B0595, D_803B0595, D_803B0595);
//     gDPPipeSync(D_801D9E7C++);
//
//     // temp_v0_12->unk4 = -0x805;
//     // temp_v0_12->unk0 = 0xFC30FE61;
//     gDPSetCombineLERP(D_801D9E7C++, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE);
//     gDPSetRenderMode(D_801D9E7C++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//     gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x80, 0x80, 0x80, D_803B0594);
//     gDPSetColorDither(D_801D9E7C++, G_CD_BAYER);
//     gDPSetAlphaDither(D_801D9E7C++, G_AD_PATTERN);
//
//     func_80136938(&D_801D9E7C, phi_s0, 0x30, 0x1F, 0xB4, 0x8C, 0, 0, 0x46, 0x32, 0x10);
//
//     // not in loop
//     func_80129300(&D_801D9E7C, D_80204278);
//     gDPPipeSync(D_801D9E7C++);
//
//     phi_s0_3 = 66;
//     load_default_display_list(&D_801D9E7C);
//     select_font(0, 2, 1, 0);
//
//     for (i = 0; i < 7; i++) {
//         if (i == D_803B0590) {
//             set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
//         } else {
//             set_menu_text_color(0x80, 0x80, 0x80, 0xFF);
//         }
//         func_8012C978(&D_801D9E7C, (((i * 4) + i) * 8) + &D_803B0400, 0xA0, phi_s0_3, 16.0f, 16.0f);
//         phi_s0_3 += 16;
//     }
//
//     temp_a0_3 = D_803B0590;
//     tmp = D_802910D0[1];
//     if ((tmp >= 51) ||
//         (*D_802910D0 & U_JPAD) ||
//         (phi_a0_3 = temp_a0_3, (*D_802910D0 & U_CBUTTONS))) {
//         phi_a0_3 = temp_a0_3;
//         if ((D_801D9ED4 == 0) && (D_803B0590 > 0)) {
//             play_sound_effect(0x90, 0, 0x5000, 1.0f, 64);
//             D_801D9ED4 = 10;
//             D_803B0590 -= 1;
//         }
//     }
//     if ((tmp < -50) ||
//         (*D_802910D0 & D_JPAD) ||
//         (*D_802910D0 & D_CBUTTONS)) {
//         if (D_801D9ED4 == 0) {
//             if (phi_a0_3 < 6) {
//                 play_sound_effect(0x91, 0, 0x5000, 1.0f, 0x40);
//                 D_801D9ED4 = 0xA;
//                 D_803B0590 += 1;
//             }
//         }
//     }
//     if (D_803B0590 != phi_a0_3) {
//         D_803B0596 = D_803B0590;
//         D_803B0592 = 0;
//         D_803B0594 = 0xF8;
//     }
//
//     if ((*D_802910D0 & A_BUTTON) || (*D_802910D0 & START_BUTTON)) {
//         switch (D_803B0590) {
//         case 0: // switch 3
//             return 1;
//         case 1: // switch 3
//             return 2;
//         case 2: // switch 3
//             return 3;
//         case 3: // switch 3
//             return 4;
//         case 4: // switch 3
//             return 5;
//         case 5: // switch 3
//             return 7;
//         case 6: // switch 3
//             return 8;
//         }
//     }
//     return 0xFF;
// }
