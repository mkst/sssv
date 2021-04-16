#include <ultra64.h>
#include "common.h"


void func_80319A50_72B100(void) {
    fancy_bzero(&D_803E8F60, 1100); // 0x44C
    fancy_bzero(&D_803E8E60, 256);
    D_803E93B0[5] = D_803E93B0[2] = 245;
    D_803A5750_7B6E00 = 0;
}

// huh
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319AA0_72B150.s")
// void func_80319AA0_72B150(void *arg0, s8 arg1) {
//     (arg0 + arg0->unk0)->unk1 = arg1;
//     arg0->unk5 = arg1;
//     arg0->unk0 = (u8) (arg0->unk0 + 1);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319AC4_72B174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319B4C_72B1FC.s")

// needs jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319C38_72B2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319E1C_72B4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_80319F58_72B608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A150_72B800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A278_72B928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A370_72BA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031A4E0_72BB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031AA0C_72C0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B100/func_8031AE7C_72C52C.s")
