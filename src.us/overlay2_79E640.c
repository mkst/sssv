#include <ultra64.h>

#include "common.h"


void func_8038CF90_79E640(void) {
    gSPDisplayList(D_801D9E7C++, D_01004270);
    gDPSetCombineMode(D_801D9E7C++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038D004_79E6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038D258_79E908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_79E640/func_8038D920_79EFD0.s")

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
