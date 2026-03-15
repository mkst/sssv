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

    if (gUiFlowState.unk0 == 0) {
        // save current controller input
        gAnimalState.prevLRTrigger = gAnimalState.curLRTrigger;
        gAnimalState.prevBButton = gAnimalState.curBButton;
        gAnimalState.prevAButton = gAnimalState.curAButton;
        gAnimalState.prevDPadLeft = gAnimalState.curDPadLeft;
        gAnimalState.prevDPadRight = gAnimalState.curDPadRight;
        gAnimalState.prevDPadUp = gAnimalState.curDPadUp;
        gAnimalState.prevDPadDown = gAnimalState.curDPadDown;
    }

    if ((gUiFlowState.unk0 != 0) || (gControllerDebounce != 0) || (D_803F2AA3 != 0) ||
        (gAnimalState.animals[gCurrentAnimalIndex].animal->unk364 == 17)) {
        gAnimalState.curAButton = 0;
        gAnimalState.curBButton = 0;
        gAnimalState.curLRTrigger = NO_TRIGGER;
        gAnimalState.curDPadUp = 0;
        gAnimalState.curDPadDown = 0;
        gAnimalState.curDPadLeft = 0;
        gAnimalState.curDPadRight = 0;
        gAnimalState.stickX = 0;
        gAnimalState.stickY = 0;
        gAnimalState.curCButtonUp = 0;
        gAnimalState.curCButtonDown = 0;
        gAnimalState.curCButtonLeft = 0;
        gAnimalState.curCButtonRight = 0;
        return;
    }

    if (cont->button & A_BUTTON) {
        gAnimalState.curAButton = 1;
    } else {
        gAnimalState.curAButton = 0;
    }
    if (cont->button & B_BUTTON) {
        gAnimalState.curBButton = 1;
    } else {
        gAnimalState.curBButton = 0;
    }
    if (cont->button & CONT_UP) {
        gAnimalState.curDPadUp = 1;
    } else {
        gAnimalState.curDPadUp = 0;
    }
    if (cont->button & CONT_DOWN) {
        gAnimalState.curDPadDown = 1;
    } else {
        gAnimalState.curDPadDown = 0;
    }
    if (cont->button & CONT_LEFT) {
        gAnimalState.curDPadLeft = 1;
    } else {
        gAnimalState.curDPadLeft = 0;
    }
    if (cont->button & CONT_RIGHT) {
        gAnimalState.curDPadRight = 1;
    } else {
        gAnimalState.curDPadRight = 0;
    }

    if ((gCameraUiState == 0) && (D_803F2AA3 == 0)) {
        if (cont->button & L_TRIG) {
            gAnimalState.curLRTrigger = L_TRIGGER;
        } else if (cont->button & R_TRIG) {
            gAnimalState.curLRTrigger = R_TRIGGER;
        } else {
            gAnimalState.curLRTrigger = NO_TRIGGER;
        }
    }

    // adjust camera based on user input
    func_8033E7C8_74FE78(cont);

    gAnimalState.stickX = cont->stick_x;
    gAnimalState.stickY = cont->stick_y;

    if (cont->button & U_CBUTTONS) {
        gAnimalState.curCButtonUp = 1;
    } else {
        gAnimalState.curCButtonUp = 0;
    }
    if (cont->button & D_CBUTTONS) {
        gAnimalState.curCButtonDown = 1;
    } else {
        gAnimalState.curCButtonDown = 0;
    }
    if (cont->button & L_CBUTTONS) {
        gAnimalState.curCButtonLeft = 1;
    } else {
        gAnimalState.curCButtonLeft = 0;
    }
    if (cont->button & R_CBUTTONS) {
        gAnimalState.curCButtonRight = 1;
    } else {
        gAnimalState.curCButtonRight = 0;
    }

    if (gGameState.unk4) {
        // reset all inputs
        gAnimalState.curAButton = 0;
        gAnimalState.curBButton = 0;
        gAnimalState.curLRTrigger = 0;
        gAnimalState.curDPadUp = 0;
        gAnimalState.curDPadDown = 0;
        gAnimalState.curDPadLeft = 0;
        gAnimalState.curDPadRight = 0;
        gAnimalState.stickX = 0;
        gAnimalState.stickY = 0;
        gAnimalState.curCButtonUp = 0;
        gAnimalState.curCButtonDown = 0;
        gAnimalState.curCButtonLeft = 0;
        gAnimalState.curCButtonRight = 0;
    }
    // only relevant to dog?
    if (D_803D554A) {
        // reset inputs
        gAnimalState.curAButton = 0;
        gAnimalState.curBButton = 0;
        gAnimalState.curLRTrigger = 0;
        gAnimalState.curDPadUp = 0;
        gAnimalState.curDPadDown = 0;
        gAnimalState.curDPadLeft = 0;
        gAnimalState.curDPadRight = 0;
        gAnimalState.stickX = 0;
        gAnimalState.stickY = 0;
    }
}
