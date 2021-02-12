#include <ultra64.h>
#include "common.h"


void func_80294E50(void); // overlay

extern s32 D_803A04E0;
extern s32 D_803FDEC0;
extern s32 D_80299730;
extern s32 D_80294E50;
extern s32 D_80302E60;
extern s32 D_803B05A0;

extern s32 D_806A6500;
extern s32 D_807D1AD0;
extern s32 D_806384F0;

#pragma GLOBAL_ASM("asm/nonmatchings/main_7770/func_8012C070.s")
// void func_8012C070(u8 arg0) {
//     func_80133738();
//
//     switch (arg0) {
//         case 0:
//             osInvalICache(&D_80294E50, (s32)&D_803A04E0 - (s32)&D_80294E50);
//             osInvalDCache(&D_803A04E0, (s32)&D_803C0420 - (s32)&D_803A04E0);
//             dma_read(0x6A6500, &D_80294E50, (s32)&D_807D1AD0 - (s32)&D_806A6500);
//             bzero(&D_803C0420, (s32)&D_803FDEC0 - (s32)&D_803C0420);
//             break;
//         case 1:
//             osInvalICache(&D_80294E50, (s32)&D_80299730 - (s32)&D_80294E50);
//             osInvalDCache(&D_80299730, (s32)&D_80302E60 - (s32)&D_80299730);
//             dma_read(0x6384F0, &D_80294E50, (s32)&D_806A6500 - (s32)&D_806384F0);
//             bzero(&D_80302E60, (s32)&D_803B05A0 - (s32)&D_80302E60);
//             break;
//         default:
//             break;
//     }
// }
