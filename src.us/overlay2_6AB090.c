#include <ultra64.h>

#include "common.h"


void func_802999E0_6AB090(DisplayList *arg0) {
    guPerspective(&arg0->unk37410, &D_803C0658, D_803F2D50.unkE0, 1.0f, D_803F2D50.unkC, D_803F2D50.unkE, 1.0f);
    guRotateRPY(&arg0->unk37450, 0.5f, 0.5f, 0.5f);
    guRotateRPY(&arg0->unk374D0, 1.0f, 1.0f, 1.0f);
    func_8033F380_750A30();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_80299AA8_6AB158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_80299B68_6AB218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_80299E84_6AB534.s")

void func_8029A32C_6AB9DC(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A334_6AB9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A3B0_6ABA60.s")

u16 func_8029A52C_6ABBDC(u8 arg0) {
    struct038 *s;
    u16 tmp = arg0 & 0x3F;

    s = &D_800BB210[tmp];
    tmp = s->unk0;
    return tmp;
}

u16 func_8029A568_6ABC18(s16 arg0) {
    s16 temp_v0;
    u16 temp_v1;
    u16 temp_v2;
    u16 temp_v3;
    u16 res;

    temp_v0 = arg0;
    temp_v1 =  ((temp_v0 & 0x3E) >> 2) & 0x3E;
    temp_v2 = (((temp_v0 & 0x7C0) >> 7) << 5) & 0x7C0;
    temp_v3 = (((temp_v0 & 0xF800) >> 12) << 10) & 0xF800;

    res = temp_v1 | temp_v2 | temp_v3;
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A5B4_6ABC64.s")
// void func_8029A5B4_6ABC64(Gfx **arg0, u8 r, u8 g, u8 b) {
//     gSPFogPosition((*arg0)++, 1033, 992); // not quite right
//     gDPSetFogColor((*arg0)++, r, g, b, 0x00);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A624_6ABCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029A720_6ABDD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AB090/func_8029ABCC_6AC27C.s")
