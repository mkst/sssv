#include <ultra64.h>
#include "common.h"


#ifdef NON_MATCHING
void func_80125900(void) {
    bzero(_mainSegmentBssStart, (u32)_mainSegmentBssSize);
    func_80125950((s32)_mainSegmentBssStart);
}

static void alignment1(void) {
}
static void alignment2(void) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/entrypoint/func_80125900.s")
#endif
