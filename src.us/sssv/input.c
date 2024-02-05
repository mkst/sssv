#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

s32 D_803A52C0_7B6970 = 0;

// ========================================================
// .bss
// ========================================================

s16       gInputMode;
OSContPad D_803E1BC4;
OSContPad D_803E1BCC; // unused

DemoInput *demoInput;

// ========================================================
// .text
// ========================================================

void get_controller_input(void) {
    static s16 D_803A52C4_7B6974 = 0;
    gControllerInput = &D_803E1BC4;

    switch (gInputMode) {
    case INPUT_MODE_USER:
        D_803E1BC4.button =  D_802910E8[D_801D9ED0].button;
        D_803E1BC4.stick_x = D_802910E8[D_801D9ED0].stick_x;
        D_803E1BC4.stick_y = D_802910E8[D_801D9ED0].stick_y;
        break;
    case INPUT_MODE_DISABLED:
        D_803E1BC4.button =  0;
        D_803E1BC4.stick_x = 0;
        D_803E1BC4.stick_y = 0;
        break;
    case INPUT_MODE_DEMO:
        if (D_803A52C0_7B6970 == 0) {
            gSeed = 0xB57; // reset seed
            func_8012822C(1); // set game time to 1

            switch (D_803F2D50.segment) {
            case SEGMENT_EUROPE:
                demoInput = D_803B1F20_7C35D0;
                break;
            case SEGMENT_ICE:
                if (D_803F2D50.unk52 == 1) {
                    demoInput = D_803B2580_7C3C30;
                } else {
                    demoInput = D_803B29D8_7C4088;
                }
                break;
            case SEGMENT_DESERT:
                demoInput = D_803B30D0_7C4780;
                break;
            case SEGMENT_CITY:
                demoInput = D_803B384C_7C4EFC; // this one is empty
                break;
            case SEGMENT_JUNGLE:
            case SEGMENT_4:
            default:
                demoInput = D_803B3388_7C4A38;
                break;
            }
            D_803A52C4_7B6974 = 0;
        }
        D_803A52C4_7B6974--;
        if (D_803A52C4_7B6974 < 0) {
            if (1) {};
            // read next input
            if (demoInput->button != END_DEMO) {
                D_803E1BC4.button  = demoInput->button;
                D_803E1BC4.stick_x = demoInput->stick_x;
                D_803E1BC4.stick_y = demoInput->stick_y;
                D_803A52C4_7B6974 = demoInput->count;
                demoInput++; // next!
            } else {
                // end of demo input
                D_803E1BC4.button  = 0;
                D_803E1BC4.stick_x = D_803E1BC4.stick_y = 0;
                // no more input...
                gInputMode = INPUT_MODE_DISABLED;
            }
        }
        // start pressed by user
        if ((D_802910E8[D_801D9ED0].button & CONT_START)) {
            // no more input...
            gInputMode = INPUT_MODE_DISABLED;
        }
        break;
    default:
        break;
    }

    D_803A52C0_7B6970++;
}
