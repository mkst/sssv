#include <ultra64.h>

#include "common.h"


extern s32 D_803A04E0;
extern s32 D_80299730;
extern s32 D_80294E50;

extern u8 D_00294E50[];
extern u8 D_00299730[];
extern u8 D_00302E60[];
extern u8 D_003A04E0[];
extern u8 D_003B05A0[];
extern u8 D_003C0420[];
extern u8 D_003FDEC0[];
extern u8 D_006384F0[];
extern u8 D_006A6500[];
extern u8 D_007D1AD0[];

void func_80294E50(void);
#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/func_8012C070.s")
// an enigma...
// void func_8012C070(u8 arg0) {
//     s32 tmp0, tmp1, tmp2, tmp3;
//
//     // stop sounds
//     func_80133738();
//
//     switch (arg0) {
//         case 0:
//             tmp0 = D_003A04E0 - D_00294E50;
//             tmp1 = D_003C0420 - D_003A04E0;
//             tmp2 = D_007D1AD0 - D_006A6500;
//             tmp3 = D_003FDEC0 - D_003C0420;
//             osInvalICache(D_80294E50, tmp0);
//             osInvalDCache(D_803A04E0, tmp1);
//             dma_read(D_006A6500, func_80294E50, tmp2);
//             bzero(D_803C0420, tmp3);
//             break;
//         case 1:
//             tmp0 = D_00299730 - D_00294E50;
//             tmp1 = D_00302E60 - D_00299730;
//             tmp2 = D_006A6500 - D_006384F0;
//             tmp3 = D_003B05A0 - D_00302E60;
//             osInvalICache(D_80294E50, tmp0);
//             osInvalDCache(D_80299730, tmp1);
//             dma_read(D_006384F0, func_80294E50, tmp2);
//             bzero(D_80302E60, tmp3);
//             break;
//         default:
//             break;
//     }
// }
