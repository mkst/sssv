#include <ultra64.h>

#include "common.h"


extern s32 D_803A04E0;
extern s32 D_803FDEC0;
extern s32 D_80299730;
extern s32 D_80294E50;
extern s32 D_803B05A0;

extern s32 D_806A6500;
extern s32 D_807D1AD0;
extern s32 D_806384F0;

#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/func_8012C070.s")
// void func_8012C070(u8 arg0) {
//     s32 tmp0, tmp1, tmp2, tmp3;
//
//     // stop sounds
//     func_80133738();
//
//     switch (arg0) {
//         case 0:
//             tmp0 = 0x3A04E0 - 0x294E50;
//             tmp1 = 0x3C0420 - 0x3A04E0;
//             tmp2 = 0x7D1AD0 - 0x6A6500;
//             tmp3 = 0x3FDEC0 - 0x3C0420;
//             osInvalICache(&D_80294E50, tmp0);
//             osInvalDCache(&D_803A04E0, tmp1);
//             dma_read(0x6A6500, &D_80294E50, tmp2);
//             bzero(&D_803C0420, tmp3);
//             break;
//         case 1:
//             tmp0 = 0x299730 - 0x294E50;
//             tmp1 = 0x302E60 - 0x299730;
//             tmp2 = 0x6A6500 - 0x6384F0;
//             tmp3 = 0x3B05A0 - 0x302E60;
//             osInvalICache(&D_80294E50, tmp0);
//             osInvalDCache(&D_80299730, tmp1);
//             dma_read(0x6384F0, &D_80294E50, tmp2);
//             bzero(&D_80302E60, tmp3);
//             break;
//         default:
//             break;
//     }
// }
