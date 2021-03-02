#include <ultra64.h>
#include "common.h"


// reset_credit_counters
void func_8038B840_79CEF0(void) {
    D_803F6400 = 0;
    D_803F6402 = 0;
}

// display_credits
s32 func_8038B854_79CF04(void) {
    s16 i;
    u8 sp90[116]; // ?
    u8 sp50[64];

    func_8012C1F0(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0xFF, 0xFF);
    select_font(0, 2, 0, 0);

    for (i = 0; i < 16; i++) {
        sprintf(&sp50, D_803BFA90, D_803B6000[i + D_803F6400]);
        func_801308B4(&sp50, &sp90);
        if ((sp50[0] == 'E') && (sp50[1] == 'N') && (sp50[2] == 'D')) {
            D_803F6400 = 0;
            i = 1000; // break
        } else {
            func_8012C978(&D_801D9E7C, &sp90, gScreenWidth / 2, (D_803F6402 + (i * 16)), 16.0f, 16.0f);
        }
    }

    D_803F6402 -= 1;
    if (D_803F6402 == -16) {
        D_803F6400 += 1;
        D_803F6402 = 0;
    }

    if (i >= 101) {
        return 1; // credits finished
    } else {
        return 0;
    }

}
