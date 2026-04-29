#include <ultra64.h>
#include "common.h"

#ifdef CRASH_SCREEN
void crash_screen_init(void);
// void crash_screen_set_framebuffer(u16 *framebuffer, u16 width, u16 height);
#endif

void func_80125950(s32 arg0 UNUSED) {
    osInitialize();
    clear_framebuffer();
    init2();
#ifdef CRASH_SCREEN
    crash_screen_init();
    // crash_screen_set_framebuffer(gFramebuffer, 320, 240);
#endif
}
