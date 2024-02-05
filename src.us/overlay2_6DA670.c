#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

s16  gControllerDebounce;

// ========================================================
// .text
// ========================================================

void read_controller_input(OSContPad *cont) {

    if (gControllerDebounce != 0) {
        gControllerDebounce--;
    }

    if (D_803F2D10.unk0 == 0) {
        // save current controller input
        D_801D9ED8.prevLRTrigger = D_801D9ED8.curLRTrigger;
        D_801D9ED8.prevBButton = D_801D9ED8.curBButton;
        D_801D9ED8.prevAButton = D_801D9ED8.curAButton;
        D_801D9ED8.prevDPadLeft = D_801D9ED8.curDPadLeft;
        D_801D9ED8.prevDPadRight = D_801D9ED8.curDPadRight;
        D_801D9ED8.prevDPadUp = D_801D9ED8.curDPadUp;
        D_801D9ED8.prevDPadDown = D_801D9ED8.curDPadDown;
    }

    if ((D_803F2D10.unk0 != 0) || (gControllerDebounce != 0) || (D_803F2AA3 != 0) ||
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk364 == 17)) {
        D_801D9ED8.curAButton = 0;
        D_801D9ED8.curBButton = 0;
        D_801D9ED8.curLRTrigger = NO_TRIGGER;
        D_801D9ED8.curDPadUp = 0;
        D_801D9ED8.curDPadDown = 0;
        D_801D9ED8.curDPadLeft = 0;
        D_801D9ED8.curDPadRight = 0;
        D_801D9ED8.stickX = 0;
        D_801D9ED8.stickY = 0;
        D_801D9ED8.curCButtonUp = 0;
        D_801D9ED8.curCButtonDown = 0;
        D_801D9ED8.curCButtonLeft = 0;
        D_801D9ED8.curCButtonRight = 0;
        return;
    }

    if (cont->button & A_BUTTON) {
        D_801D9ED8.curAButton = 1;
    } else {
        D_801D9ED8.curAButton = 0;
    }
    if (cont->button & B_BUTTON) {
        D_801D9ED8.curBButton = 1;
    } else {
        D_801D9ED8.curBButton = 0;
    }
    if (cont->button & CONT_UP) {
        D_801D9ED8.curDPadUp = 1;
    } else {
        D_801D9ED8.curDPadUp = 0;
    }
    if (cont->button & CONT_DOWN) {
        D_801D9ED8.curDPadDown = 1;
    } else {
        D_801D9ED8.curDPadDown = 0;
    }
    if (cont->button & CONT_LEFT) {
        D_801D9ED8.curDPadLeft = 1;
    } else {
        D_801D9ED8.curDPadLeft = 0;
    }
    if (cont->button & CONT_RIGHT) {
        D_801D9ED8.curDPadRight = 1;
    } else {
        D_801D9ED8.curDPadRight = 0;
    }

    if ((D_803F2AA2 == 0) && (D_803F2AA3 == 0)) {
        if (cont->button & L_TRIG) {
            D_801D9ED8.curLRTrigger = L_TRIGGER;
        } else if (cont->button & R_TRIG) {
            D_801D9ED8.curLRTrigger = R_TRIGGER;
        } else {
            D_801D9ED8.curLRTrigger = NO_TRIGGER;
        }
    }

    // adjust camera based on user input
    func_8033E7C8_74FE78(cont);

    D_801D9ED8.stickX = cont->stick_x;
    D_801D9ED8.stickY = cont->stick_y;

    if (cont->button & U_CBUTTONS) {
        D_801D9ED8.curCButtonUp = 1;
    } else {
        D_801D9ED8.curCButtonUp = 0;
    }
    if (cont->button & D_CBUTTONS) {
        D_801D9ED8.curCButtonDown = 1;
    } else {
        D_801D9ED8.curCButtonDown = 0;
    }
    if (cont->button & L_CBUTTONS) {
        D_801D9ED8.curCButtonLeft = 1;
    } else {
        D_801D9ED8.curCButtonLeft = 0;
    }
    if (cont->button & R_CBUTTONS) {
        D_801D9ED8.curCButtonRight = 1;
    } else {
        D_801D9ED8.curCButtonRight = 0;
    }

    if (D_803F2D30.unk4) {
        // reset all inputs
        D_801D9ED8.curAButton = 0;
        D_801D9ED8.curBButton = 0;
        D_801D9ED8.curLRTrigger = 0;
        D_801D9ED8.curDPadUp = 0;
        D_801D9ED8.curDPadDown = 0;
        D_801D9ED8.curDPadLeft = 0;
        D_801D9ED8.curDPadRight = 0;
        D_801D9ED8.stickX = 0;
        D_801D9ED8.stickY = 0;
        D_801D9ED8.curCButtonUp = 0;
        D_801D9ED8.curCButtonDown = 0;
        D_801D9ED8.curCButtonLeft = 0;
        D_801D9ED8.curCButtonRight = 0;
    }
    // only relevant to dog?
    if (D_803D554A) {
        // reset inputs
        D_801D9ED8.curAButton = 0;
        D_801D9ED8.curBButton = 0;
        D_801D9ED8.curLRTrigger = 0;
        D_801D9ED8.curDPadUp = 0;
        D_801D9ED8.curDPadDown = 0;
        D_801D9ED8.curDPadLeft = 0;
        D_801D9ED8.curDPadRight = 0;
        D_801D9ED8.stickX = 0;
        D_801D9ED8.stickY = 0;
    }
}
