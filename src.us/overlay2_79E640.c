#include <ultra64.h>

#include "common.h"


void func_8038CF90_79E640(void) {
    gSPDisplayList(D_801D9E7C++, D_01004270);
    gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

void func_8012D374(s32, s32, s32, s32, f32, f32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038D004_79E6B4.s")
// miles away
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
//     u8 i;
//     s16 phi_s0_2;
//
//     func_8012C1F0(arg0);
//     select_font(0, 2, 0, 0);
//
//     if ((arg1 * 4) < 80) {
//         green = (arg1 * 4);
//     } else {
//         green = 80;
//     }
//     set_menu_text_color(0, green, 0, 0xFF);
//
//     phi_s1 = 10;
//     for (i = 0; i < 4 ; i++) {
//         sprintf(&spE4, &D_803BFFD4, D_803B6328[(func_80129128() / 0x39C) & 0xFF]);
//         func_801308B4(&spE4, &sp64);
//         func_8012D374(arg0, &sp64, 6, phi_s1, 13.0f, 9.0f, -1);
//         phi_s1 += 10;
//     }
//
//     for (phi_s0_2 = 0; phi_s0_2 < 15; phi_s0_2++) {
//         temp_v0_2 = func_8012826C();
//         temp_t4 = D_803B6320[temp_v0_2 & 7];
//         temp_s1 = (temp_v0_2 >> 3) & 0xF;
//         temp_s2 = (temp_v0_2 >> 8) & 3;
//         temp_a0 = &spE4;
//         spE4 = temp_t4;
//         func_801308B4(temp_a0, &sp64);
//         draw_glyph(arg0, &sp64, ((temp_s1 * 0xD) + 0xAF) & 0xFFFF, ((temp_s2 * 8) + 0xA) & 0xFFFF, 13.0f, 9.0f);
//     }
//
//     gSPEndDisplayList((*arg0)++);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038D258_79E908.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038DBE0_79F290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038DF18_79F5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038E504_79FBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038E80C_79FEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038E9F8_7A00A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038F414_7A0AC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038F5F8_7A0CA8.s")

void func_8038F694_7A0D44(void) {
    D_803F2AA2 = 0;
    D_803F2AA3 = 25;
    func_801337DC(0, 135.0f, 20.0f, 0);
    func_8013385C(135.0f, 20.0f, 0);
}
