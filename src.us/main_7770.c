#include <ultra64.h>

#include "common.h"


extern u8 D_803A04E0[];
extern u8 D_006384F0[];
extern u8 D_006A6500[];
extern u8 D_007D1AD0[];

extern u8 D_80294E50[];
extern u8 D_80299730[];
extern u8 D_803B05A0[];
extern u8 D_803FDEC0[];

#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/func_8012C070.s")
// an enigma...
// void func_8012C070(u8 arg0)
// {
//     u8 *new_var;
//
//     func_80133738();
//     switch (arg0)
//     {
//     case 0:
//         new_var = D_803C0420;
//         osInvalICache(D_80294E50, D_803A04E0 - D_80294E50);
//         osInvalDCache(D_803A04E0, ((s32) new_var) - ((s32) D_803A04E0));
//         dma_read(D_006A6500, D_80294E50, D_007D1AD0 - D_006A6500);
//         bzero(new_var, ((s32) D_803FDEC0) - ((s32) new_var));
//         break;
//     case 1:
//         new_var = D_80302E60;
//         osInvalICache(D_80294E50, D_80299730 - D_80294E50);
//         osInvalDCache(D_80299730, ((s32) new_var) - ((s32) D_80299730));
//         dma_read(D_006384F0, D_80294E50, D_006A6500 - D_006384F0);
//         bzero(new_var, ((s32) D_803B05A0) - ((s32) new_var));
//     }
// }
