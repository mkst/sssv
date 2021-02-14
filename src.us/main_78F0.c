#include <ultra64.h>
#include "common.h"


void func_8012C1F0(Gfx **arg0) {
    gSPDisplayList((*arg0)++, &D_80154628);
}

void set_text_color(u8 r, u8 g, u8 b, u8 a) {
    D_8023F1F0 = r; // textColorR
    D_8023F1F1 = g; // textColorG
    D_8023F1F2 = b; // textColorB
    D_8023F1F3 = a; // textColorA
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C678.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012C978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012D374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012DCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012DEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012E724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012E78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012EB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012F160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FAD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_8012FBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801304EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801308B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_78F0/func_801308E8.s")

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
