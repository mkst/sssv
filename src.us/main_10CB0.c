#include <ultra64.h>

#include "common.h"


// second function called after osInitialize()
void init2(void) {
    osCreateThread(&gThread1, 1, (void*)func_80135604, 0, &D_8028D230, 10);
    osStartThread(&gThread1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/main_10CB0/func_80135604.s")
// NON-MATCHING: matches but does not OK
// void func_80135604(void) {
//     osCreateThread(&gThread6, 6, (void *)func_80129B10, 0, &D_80288E30, 10);
//     osCreateThread(&gThread7, 7, (void *)func_8012A260, 0, &D_8028B030, 8);
//     osCreatePiManager(150, &D_8028D030, &D_8028F640, 800);
//     osStartThread(&gThread6);
//     // set lowest priority for this thread
//     osSetThreadPri(NULL, OS_PRIORITY_IDLE);
//     // loop forever
//     while (TRUE) {};
// }
