#include <ultra64.h>

#include "common.h"


// second function called after osInitialize()
void func_801355B0(void) {
    osCreateThread(&D_802868D0, 1, (void*)func_80135604, 0, &D_8028D230, 10);
    osStartThread(&D_802868D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_80135604.s")
// NON-MATCHING: matches but does not OK
// void func_80135604(void) {
//     osCreateThread(&D_80286570, 6, (void *)func_80129B10, 0, &D_80288E30, 10);
//     osCreateThread(&D_80286720, 7, (void *)func_8012A260, 0, &D_8028B030, 8);
//     osCreatePiManager(150, &D_8028D030, &D_8028F640, 800);
//     osStartThread(&D_80286570);
//     // set lowest priority for this thread
//     osSetThreadPri(NULL, OS_PRIORITY_IDLE);
//     // loop forever
//     while (TRUE) {};
// }

// bunch of displaylist stuff
#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_801356C0.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_80135CD8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_801360C8.s")
#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_80136418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_801366BC.s")
// void func_801366BC(Gfx *arg0, u8 r, u8 g, u8 b, u8 a) {
//
//     gDPPipeSync(arg0++);
//     gDPHalf1(arg0++, &D_8015C750);
//     gLoadUcode(arg0++, &D_8014E300, 0x0800);
//     gDPPipeSync(arg0++);
//
//     func_80129300(arg0++, D_80204278);
//
//     gDPSetColorImage(arg0++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274 + 0x3BBE8));
//     gSPViewport(arg0++, &D_80152EA8);
//
//     gMoveWd(arg0++, G_MW_CLIP, G_MWO_CLIP_RNX, 0x00000004);
//     gMoveWd(arg0++, G_MW_CLIP, G_MWO_CLIP_RNY, 0x00000004);
//     gMoveWd(arg0++, G_MW_CLIP, G_MWO_CLIP_RPX, 0x0000FFFC);
//     gMoveWd(arg0++, G_MW_CLIP, G_MWO_CLIP_RPY, 0x0000FFFC);
//
//     gSPDisplayList(arg0++, &D_801584A0);
//     gDPSetPrimColor(arg0++, 0, 0, r, g, b, a);
//     gDPSetTextureFilter(arg0++, G_TF_POINT | G_TL_LOD | G_TD_SHARPEN);
//
//     gDPSetScissor(arg0++, G_SC_NON_INTERLACE, 8, 8, gScreenWidth, gScreenHeight);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_80136938.s")
