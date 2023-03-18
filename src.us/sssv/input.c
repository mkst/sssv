#include <ultra64.h>
#include "common.h"


s32 D_803A52C0_7B6970 = 0;

void get_controller_input(void) {
    static s16 D_803A52C4_7B6974 = 0;
    gControllerInput = &D_803E1BC4;

    switch (D_803E1BC0) {
    case 0:
        // user input
        D_803E1BC4.button =  D_802910E8[D_801D9ED0].button;
        D_803E1BC4.stick_x = D_802910E8[D_801D9ED0].stick_x;
        D_803E1BC4.stick_y = D_802910E8[D_801D9ED0].stick_y;
        break;
    case 2:
        // no input
        D_803E1BC4.button =  0;
        D_803E1BC4.stick_x = 0;
        D_803E1BC4.stick_y = 0;
        break;
    case 1:
        // demo input
        if (D_803A52C0_7B6970 == 0) {
            D_80151434 = 0xB57; // reset seed
            func_8012822C(1); // set game time to 1

            switch (D_803F2D50.segment) {
            case 0:
                D_803E1BD4 = D_803B1F20_7C35D0;
                break;
            case 1:
                if (D_803F2D50.unk52 == 1) {
                    D_803E1BD4 = D_803B2580_7C3C30;
                } else {
                    D_803E1BD4 = D_803B29D8_7C4088;
                }
                break;
            case 2:
                D_803E1BD4 = D_803B30D0_7C4780;
                break;
            case 5:
                D_803E1BD4 = D_803B384C_7C4EFC; // this one is empty
                break;
            case 3:
            case 4:
            default:
                D_803E1BD4 = D_803B3388_7C4A38;
                break;
            }
            D_803A52C4_7B6974 = 0;
        }
        D_803A52C4_7B6974--;
        if (D_803A52C4_7B6974 < 0) {
            if (1) {};
            // read next input
            if (D_803E1BD4->button != END_DEMO) {
                D_803E1BC4.button  = D_803E1BD4->button;
                D_803E1BC4.stick_x = D_803E1BD4->stick_x;
                D_803E1BC4.stick_y = D_803E1BD4->stick_y;
                D_803A52C4_7B6974 = D_803E1BD4->count;
                D_803E1BD4++; // next!
            } else {
                // end of demo input
                D_803E1BC4.button  = 0;
                D_803E1BC4.stick_x = D_803E1BC4.stick_y = 0;
                // no more input...
                D_803E1BC0 = 2;
            }
        }
        // start pressed
        if ((D_802910E8[D_801D9ED0].button & CONT_START)) {
            // no more input...
            D_803E1BC0 = 2;
        }
        break;
    default:
        break;
    }

    D_803A52C0_7B6970++;
}
