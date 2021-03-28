#include <ultra64.h>

#include "common.h"

#if 0
char* asm[] = {
    "mov si,animaltype",
    "add si,128",
    "mov blocksi,si",
    "mov ax,0",
    "mov ax,xpos",
    "mov bx,ax",
    "shl al,4",
    "shr al,4",
    "mov ah,0",
    "cmp animalinview,0",
    "je  scared",
    "mov ax,0",
    "scared:",
    "mov energy,ax",
    "mov ax,bx",
    "shr ax,4",
    "mov animalpositionx,0",
    "mov animalpositiony,0",
    "mov si,animalpositionz",
    "mov world,ax",
    "mov ax,ypos",
    "and ah,ah",
    "mov bx,ax",
    "shl al,4",
    "shr al,4",
    "cmp animalinview,0",
    "je  fearless",
    "mov ax,0",
    "fearless:",
    "mov intelligence,ax",
    "mov ax,bx",
    "shr ax,4",
    "mul strength",
    "add world,ax",
    "push bp",
    "push ds",
    "leslies code sucks:",
    "cmp movedcounter,1",
    "jne again",
    "mov movedcounter,800",
    "again:",
    "mov si,animalpositionz",
    "mov ds,worldfeatureseg",
    "mov bx,world",
    "mov al,(ds:si+bx)",
    "mov curblock,al",
    "push bp",
    "push ds",
    "mov byte (ds:si+bx),0",
    "jmp havetomove",
    "nothuhumantemp:",
    "mov si,worldfeatureanimofs",
    "mov ds,worldfeatureanimseg",
    "mov bx,world",
    "mov cx,0",
    "mov cl,(ds:si+bx)",
    "cmp cl,254",
    "jne continue",
    "mov byte (ds:si+bx),0",
    "jmp havetomove",
    "continue:",
    "animalnotoverlay:",
    "cmp al,enemy1right",
    "jb  gnotbaddie",
    "cmp al,enemy2right",
    "jae gbaddie2",
    "mov al,enemy1right",
    "jmp gnotbaddie",
    "gbaddie2:",
    "mov al,enemy2right",
    "gnotbaddie:",
}
#endif

void func_8038CF90_79E640(void) {
    gSPDisplayList(D_801D9E7C++, D_01004270);
    gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

void func_8012D374(s32, s32, s32, u16, f32, f32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038D004_79E6B4.s")
// a fair way away
// void func_8038D004_79E6B4(Gfx **arg0, u16 arg1) {
//     u8 spE4;
//     u16 sp64[4];
//     s16 temp_s1;
//     s16 temp_s2;
//     s32 temp_v0_2;
//     u8 *temp_a0;
//     u8 temp_t4;
//     s32 green;
//     u16 phi_s1;
//     u16 i;
//     s16 phi_s0_2;
//
//
//     load_default_display_list(arg0);
//     select_font(0, 2, 0, 0);
//
//     if ((arg1 * 4) < 80) {
//         green = (arg1 * 4);
//     } else {
//         green = 80;
//     }
//     set_menu_text_color(0, green, 0, 0xFF);
//
//     // phi_s1 = 0;
//     for (i = 0; i < 4; i++) {
//         // "%s\n"
//         sprintf(&spE4, &D_803BFFD4, D_803B6328[(func_80129128() / 924) & 0xFF]);
//         func_801308B4(&spE4, &sp64);
//         func_8012D374(arg0, &sp64, 6, i * 10, 13.0f, 9.0f, -1);
//         // phi_s1 += 10;
//     }
//
//     for (phi_s0_2 = 0; phi_s0_2 < 15; phi_s0_2++) {
//         temp_v0_2 = func_8012826C();
//         temp_t4 = D_803B6320[temp_v0_2 & 7];
//         temp_s1 = (temp_v0_2 >> 3) & 0xF; //
//         temp_s2 = (temp_v0_2 >> 8) & 3;   // bottom 3 bits?
//         temp_a0 = &spE4;
//         spE4 = temp_t4;
//         func_801308B4(temp_a0, &sp64);
//         draw_glyph(arg0, &sp64, ((temp_s1 * 0xD) + 0xAF) , (temp_s2 * 8) + 10 , 13.0f, 9.0f);
//     }
//
//     gSPEndDisplayList((*arg0)++);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038D258_79E908.s")

void func_8038D920_79EFD0(u8 arg0) {
    func_8032F950_741000();
    func_802C87E0_6D9E90();
    func_802C8878_6D9F28();
    func_802E072C_6F1DDC(1);
    if (D_803F2AA2 != 0) {
        func_802F2B54_704204(D_801DDD8C[gCurrentAnimalIndex].unk0->xPos + 64, D_801DDD8C[gCurrentAnimalIndex].unk0->zPos,      D_801DDD8C[gCurrentAnimalIndex].unk0->yPos + 64, arg0,    0, arg0, 0);
        func_802F2B54_704204(D_801DDD8C[gCurrentAnimalIndex].unk0->xPos,      D_801DDD8C[gCurrentAnimalIndex].unk0->zPos - 64, D_801DDD8C[gCurrentAnimalIndex].unk0->yPos - 64, arg0, arg0,    0, 0);
        if ((D_803F2AA2 == 1) && (D_803B6318 != 2)) {
            func_802F2EEC_70459C(70, 70, 70, 50, 30, 30, 30);
            D_803F2AA2 += 1;
        }
    }
}

void func_8038DA70_79F120(void) {
    func_80380490_791B40(&D_801D9E7C, D_80204278);
    func_802999E0_6AB090(D_80204278);
    func_80299AA8_6AB158(D_80204278, &D_801D9E7C);

    gSPViewport(D_801D9E7C++, &D_80152EA8);
    gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
    gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);

    gSPDisplayList(D_801D9E7C++, D_01004270);
    gSPDisplayList(D_801D9E7C++, &D_80204278->unk9600);
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038DBE0_79F290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038DF18_79F5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E504_79FBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E80C_79FEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038E9F8_7A00A8.s")
// NON-MATCHING: a fair bit to do
// void func_8038E9F8_7A00A8(void) {
//     s16 sp68;
//     s16 temp_a0;
//     s16 temp_v0_2;
//     s16 temp_v0_5;
//     u16 temp_v0_6;
//     s16 i;
//
//     func_80129300(&D_801D9E7C, D_80204278);
//     func_80380490_791B40(&D_801D9E7C, D_80204278);
//
//     gSPViewport(D_801D9E7C++, &D_80152EA8);
//     func_80129430(&D_801D9E7C);
//
//     gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
//     gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
//     gSPFogPosition(D_801D9E7C++, -3026, -3067); // use gSPFogFactor
//     gDPSetFogColor(D_801D9E7C++, 0x00, 0x00, 0x00, 0x00);
//
//     if (D_803B6314 == 0) {
//         func_8013385C(1.0f, 0.0f, 20.0f);
//         D_803F6470 = 0;
//         D_803F646C = 0.0f;
//         if (D_80291090[0].hasRumblePak != 0) { // Controller array
//             func_80137168();
//             func_8013724C(0);
//         }
//     }
//     if (D_803F6470 < 0x64) {
//         D_803F6470 += 1;
//     }
//     if ((D_803F6470 == 5) && (D_803F2AA2 == 3)) {
//         play_sound_effect(0x87, 0, 0x5000, 1.0f, 0x40);
//     }
//     if (D_803B6314 < 2) {
//         draw_rectangle(&D_801D9E7C, 0, 0, 0x140, 0xF0, 0, 0, 0, 0xFF);
//         D_803B6314 += 1;
//     }
//     func_8032CD20_73E3D0(0x45, 0x84, 6144.0f * D_803F646C, 0, 1.0f);
//     func_8032CD20_73E3D0(0xA9, 0x85, 4352.0f * D_803F646C, 0, D_803C0160);
//     func_8032CD20_73E3D0(0x171, 0x85, 4352.0f * D_803F646C, 0, 1.0f);
//     func_8032CD20_73E3D0(0x10D, 0x86, 21760.0f * D_803F646C, 0, 1.0f);
//     if (D_803F646C < 1.0) {
//         D_803F646C += D_803C0168;
//     }
//     gScreenHeight = 240;
//     D_803A6CC4 = (((f64) ((s32) D_80152C78[D_803F6472] >> 7) / 3200.0) + D_803C0170);
//     D_803A6CC8 = (((f64) ((s32) D_80152C78[D_803F6472] >> 7) / 15.0) + D_803C0178);
//     D_803F6472 += 1;
//
//     D_80152EA8.unk0 = D_80203FD0 * 2;
//     D_80152EA8.unk2 = gScreenHeight * 2;
//     D_80152EA8.unk8 = D_80203FD0 * 2;
//     D_80152EA8.unkA = gScreenHeight * 2;
//
//     func_8038CF90_79E640();
//     if (D_803B6318 == 0) {
//         draw_rectangle(&D_801D9E7C, 0, 0, 0x140, 0xF0, 0, 0, 0, 0x4B);
//     } else {
//         draw_rectangle(&D_801D9E7C, 0, 0, 0x140, 0xF0, 0, 0, 0, 0x64);
//     }
//
//     switch (D_803B6318) {
//     case 0:
//         if (D_80203FD0 < 320) {
//             gScreenWidth = D_80203FD0 + 2;
//         }
//         func_8038D920_79EFD0(0xFF);
//         func_8038DA70_79F120();
//         D_803B6310 += 1;
//         if (D_803B6310 >= 0x29) {
//             D_803B631C = 1;
//             D_803B6310 = 0;
//             D_803B6318 = 1;
//         }
//         break;
//     case 1:
//         gScreenWidth = 320;
//         load_default_display_list(&D_801D9E7C);
//         set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
//         select_font(0, 2, 1, 0);
//         func_8038D920_79EFD0(0xFF);
//         sp68 = func_8012826C() & 7;
//         for (i = 0; i < 6; i++) {
//             temp_v0_5 = (((i * 4) + i) * 8) + sp68;
//
//             gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8 + (temp_v0_5 * 0x280)));
//             gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, (gScreenHeight - temp_v0_5) - 9);
//             gSPDisplayList(D_801D9E7C++, D_801D9E90);
//         }
//
//         gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
//         gDPSetScissor(D_801D9E7C++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth - 8, gScreenHeight - 8);
//
//         func_8038D004_79E6B4(&D_801D9E90, D_803B6310);
//         func_8038DA70_79F120();
//         func_8038E504_79FBB4(D_803B6310);
//         load_default_display_list(&D_801D9E7C);
//         set_menu_text_color(0x80, 0xFF, 0, 0xFF);
//         select_font(0, 2, 1, 0);
//         func_8038DBE0_79F290(0xE, 0x10);
//         temp_v0_6 = D_803B6310;
//         D_803B6310 = (u16) (temp_v0_6 + 1);
//         if ((s32) temp_v0_6 >= 0xFDE9) {
//             D_803B6310 = 0xC8U;
//         }
//         if (((*D_802910D0 & 0x8000) != 0) || ((*D_802910D0 & 0x4000) != 0)) {
//             if (D_803B631C == 0) {
//                 func_801337DC(0, 25.0f, 0, 20.0f);
//                 D_803B6314 = 0;
//                 D_803B631C = 1;
//                 D_803B6310 = 0U;
//                 D_803F2D10.unk0 = 0;
//                 D_803F2C6D = 0;
//                 D_803F2C6C = D_803F2C6D;
//                 D_803B6318 = 0;
//                 D_803F6460 = 0x64;
//                 D_803D6110 = 0x12;
//                 draw_rectangle(&D_801D9E7C, 0, 0, 0x140, 0xF0, 0, 0, 0, 0xFF);
//                 if (D_803F2AA2 == 4) {
//                     D_803F2AA2 = 2;
//                     D_803F6468 = 0;
//                     D_803F2AA3 = 0x3C;
//                 } else {
//                     D_803F2AA2 = 0;
//                 }
//             }
//         }
//         break;
//     case 2:
//         func_8038D920_79EFD0(0xFF);
//         func_8038DA70_79F120();
//         if (D_803B6310 == 1) {
//             func_802F2EEC_70459C(0x50, 0x50, 0x50, 0xC8, 0xC8, 0xC8, 0xA);
//         }
//         D_803B6310 += 1;
//         if ((D_803B6310) == 0x28) {
//             D_803B6310 = 0;
//             D_803F2AA2 = 0;
//             D_803F2D10.unk0 = 0;
//             D_803F2C6D = 0;
//             D_803F2C6C = D_803F2C6D;
//             D_803B6318 = 0;
//         }
//         break;
//     }
//
//     if (D_803B631C != 0) {
//         D_803B631C += 1;
//         if ((D_803B631C ^ 7) == 0) {
//             D_803B631C = (u8)0;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/terminal_background/func_8038F414_7A0AC4.s")
// NON-MATCHING: almost JUSTREG
// void func_8038F414_7A0AC4(void) {
//     switch (D_803F2AA2 & 0xff) {
//         u8 tmp;
//     case 0:
//         if (D_803F6460 > 0) {
//             D_803F6460 -= 1;
//         }
//         if ((D_803F2AA3 > 0) && ((tmp = --D_803F2AA3) == 0)) {
//             D_803F2AA2 = 3;
//             D_803B6318 = 0;
//             func_8038D258_79E908();
//             D_803B6310 = 0;
//             D_803A6CC4 = D_803C0180;
//             D_803A6CC8 = 45.0f;
//             D_803F6472 = 0;
//             D_803F2D10.unk0 = 3;
//             D_803F6474 = D_803F2E2A;
//         }
//         break;
//     case 1:
//         if (D_803F2AA3 > 0) {
//             D_803F2AA3 -= 1;
//         }
//         if ((D_803F2AA3 <= 0) && (D_803F6468 >= 100)) {
//             func_802B342C_6C4ADC();
//             func_801337DC(0, 25.0f, 20.0f, 0.0f);
//             D_803F2AA2 = 4;
//             D_803B6318 = 1;
//             func_8038D258_79E908();
//             D_803B6310 = 0;
//             D_803A6CC4 = D_803C0184;
//             D_803A6CC8 = 45.0f;
//             D_803F6472 = 0;
//             D_803F2D10.unk0 = 3;
//             D_803F6474 = D_803F2E2A;
//             func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
//         }
//         break;
//     case 2:
//         if ((D_803F2AA3 > 0) && (--D_803F2AA3 == 0)) {
//             D_803F2AA2 = 0;
//             func_802B34DC_6C4B8C();
//         }
//     }
// }

void func_8038F5F8_7A0CA8(s32 arg0) {
    if ((D_801DDD8C[gCurrentAnimalIndex].unk0->unk16C->unk0 != 0x13F) && (D_801DDD8C[gCurrentAnimalIndex].unk0->unk16C->unk0 != 0x13D)) {
        if (D_803F6460 == 0) {
            D_803D6110 = 100;
            D_803F2AA2 = 1;
            D_803F6464 = arg0;
            D_803F6468 = 0;
            D_803F2AA3 = 100;
            D_803F6460 = 100;
            func_8032AC48_73C2F8(D_801DDD8C[gCurrentAnimalIndex].unk0->unk16C->unk9C);
        }
    }
}

void func_8038F694_7A0D44(void) {
    D_803F2AA2 = 0;
    D_803F2AA3 = 25;
    func_801337DC(0, 135.0f, 20.0f, 0);
    func_8013385C(135.0f, 20.0f, 0);
}
