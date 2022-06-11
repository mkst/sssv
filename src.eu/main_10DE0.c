#include <ultra64.h>
#include "common.h"

extern Gfx **D_8015B070;

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_801356E0.s")
// void func_801356E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Gfx **dl, u8 *arg5, f32 arg6, f32 arg7, u8 arg8) {
//     u32 ulx, uly;
//     u32 lrx, lry;
//
//     f32 dsdx, dtdy;
//     s32 s, t;
//
//     gDPPipeSync((*dl)++);
//
//     switch (arg8) {
//     case 16:
//         gDPSetTextureImage((*dl)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, arg5);
//         gDPLoadSync((*dl)++);
//
//         gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
//             G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
//             G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//
//         break;
//     case 8:
//         gDPLoadSync((*dl)++);
//         gDPSetTextureImage((*dl)++, G_IM_FMT_I, G_IM_SIZ_8b, 1, arg5);
//
//         gDPLoadTextureBlock((*dl)++, arg5, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
//             G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
//             G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         break;
//     default:
//         func_8013968C(D_8015B070);
//         break;
//     }
//
//     ulx = MAX(arg0 * 4, 0);
//     uly = MAX(arg1 * 4, 0);
//     lrx = MAX((arg0 + arg2) * 4, 0);
//     lry = MAX((arg1 + arg3) * 4, 0);
//     dsdx = 16384.0f / (arg6 / 2.0f);
//     dtdy = 16384.0f / (arg7 / 2.0f);
//
//     // help...
//     s = MAX(MAX(arg0 * 4, 0) * ((s16) dsdx) >> 7, 0);
//     t = MAX(MAX(arg1 * 4, 0) * ((s16) dtdy) >> 7, 0);
//
//     gSPTextureRectangle(
//         /* pkt  */ (*dl)++,
//         /* ulx  */ ulx,          // 1
//         /* uly  */ uly,          // 1
//         /* lrx  */ lrx,          // 0
//         /* lry  */ lry,          // 0
//         /* tile */ G_TX_RENDERTILE, // 0
//         /* s    */ s,            // 2
//         /* t    */ t,            // 2
//         /* dsdx */ dsdx,         // 3
//         /* dtdy */ dtdy          // 3
//     );
//
//     gDPPipeSync((*dl)++);
//     gDPSetCycleType((*dl)++, G_CYC_1CYCLE);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_80135CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_801360E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_80136438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_801366DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_10DE0/func_80136958.s")
