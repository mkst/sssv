#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

s16  D_803D6110;

// ========================================================
// .text
// ========================================================

void func_802C8FC0_6DA670(OSContPad *cont) {

    if (D_803D6110 != 0) {
        D_803D6110--;
    }

    if (D_803F2D10.unk0 == 0) {
        // save current controller input
        D_801D9ED8.unkFFBA = D_801D9ED8.unkFFB4;
        D_801D9ED8.unkFFBC = D_801D9ED8.unkFFB6;
        D_801D9ED8.unkFFB8 = D_801D9ED8.unkFFB2;
        D_801D9ED8.unkFFD0 = D_801D9ED8.unkFFC2;
        D_801D9ED8.unkFFD2 = D_801D9ED8.unkFFC4;
        D_801D9ED8.unkFFD4 = D_801D9ED8.unkFFBE;
        D_801D9ED8.unkFFD6 = D_801D9ED8.unkFFC0;
    }
    if ((D_803F2D10.unk0 != 0) || (D_803D6110 != 0) || (D_803F2AA3 != 0) ||
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk364 == 17)) {
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
        D_801D9ED8.unkFFC6 = 0;
        D_801D9ED8.unkFFC8 = 0;
        D_801D9ED8.unkFFCA = 0;
        D_801D9ED8.unkFFCC = 0;
        return;
    }

    if (cont->button & A_BUTTON) {
        D_801D9ED8.unkFFB2 = 1U;
    } else {
        D_801D9ED8.unkFFB2 = 0U;
    }
    if (cont->button & B_BUTTON) {
        D_801D9ED8.unkFFB6 = 1U;
    } else {
        D_801D9ED8.unkFFB6 = 0U;
    }
    if (cont->button & CONT_UP) {
        D_801D9ED8.unkFFBE = 1U;
    } else {
        D_801D9ED8.unkFFBE = 0U;
    }
    if (cont->button & CONT_DOWN) {
        D_801D9ED8.unkFFC0 = 1U;
    } else {
        D_801D9ED8.unkFFC0 = 0U;
    }
    if (cont->button & CONT_LEFT) {
        D_801D9ED8.unkFFC2 = 1U;
    } else {
        D_801D9ED8.unkFFC2 = 0U;
    }
    if (cont->button & CONT_RIGHT) {
        D_801D9ED8.unkFFC4 = 1U;
    } else {
        D_801D9ED8.unkFFC4 = 0U;
    }

    if ((D_803F2AA2 == 0) && (D_803F2AA3 == 0)) {
        if (cont->button & L_TRIG) {
            D_801D9ED8.unkFFB4 = 1U;
        } else if (cont->button & R_TRIG) {
            D_801D9ED8.unkFFB4 = 2U;
        } else {
            D_801D9ED8.unkFFB4 = 0U;
        }
    }

    func_8033E7C8_74FE78(cont);

    D_801D9ED8.unkFFD8 = cont->stick_x;
    D_801D9ED8.unkFFD9 = cont->stick_y;

    if (cont->button & U_CBUTTONS) {
        D_801D9ED8.unkFFC6 = 1;
    } else {
        D_801D9ED8.unkFFC6 = 0;
    }
    if (cont->button & D_CBUTTONS) {
        D_801D9ED8.unkFFC8 = 1;
    } else {
        D_801D9ED8.unkFFC8 = 0;
    }
    if (cont->button & L_CBUTTONS) {
        D_801D9ED8.unkFFCA = 1;
    } else {
        D_801D9ED8.unkFFCA = 0;
    }
    if (cont->button & R_CBUTTONS) {
        D_801D9ED8.unkFFCC = 1;
    } else {
        D_801D9ED8.unkFFCC = 0;
    }

    if (D_803F2D30.unk4) {
        // reset inputs
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
        D_801D9ED8.unkFFC6 = 0;
        D_801D9ED8.unkFFC8 = 0;
        D_801D9ED8.unkFFCA = 0;
        D_801D9ED8.unkFFCC = 0;
    }
    if (D_803D554A) {
        // reset inputs
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
    }
}
