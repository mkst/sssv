#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F63E0 to D_803F63F0)
// ========================================================

s16  D_803F63E0; // used by elephant and hyena

// ========================================================
// .text
// ========================================================

// trigger_laughter
void func_80380620_791CD0(Animal *animal, s16 duration, s16 arg2, s16 arg3, u8 arg4) {
    animal->laughterDuration = duration;
    animal->unk352 = arg2;
    animal->unk356 = arg3;
    animal->laughterFactor = arg4; // laughter factor: hyena = 10
}

// reset_laughter_timer
void func_80380644_791CF4(Animal *arg0) {
    arg0->laughterDuration = 0;
}

// check_laughter_threshold
void func_8038064C_791CFC(void) {
    s32 tmp;

    if (D_803F2D10.unk0 == 0) {
        D_803D552C->laughterThreshold = MAX(0, D_803D552C->laughterThreshold - 1);
        if (D_803D552C->laughterThreshold <= 0) {
            D_803D552C->isLaughing = 0;
        }
    }
    if (D_803D552C->isLaughing != 0) {
        func_80380620_791CD0(D_803D552C, 150, 15, MIN(50, D_803D552C->laughterThreshold >> 1), 10);
        if (D_803F2D10.unk0) {} // regalloc
    }

    D_803F63E0 = 0;
    if ((D_803D552C->laughterDuration != 0) || (D_803D552C->unk34E != 0)) {
        if (D_803D552C->unk34E != 0) {
            D_803D552C->unk34E--;
            tmp = (((256 - (COS((D_803D552C->unk34E << 8) / D_803D552C->unk354) >> 7)) * D_803D552C->unk350) >> 9) + 256;
            D_803F2EB0 = (D_803F2EB0 * tmp) >> 8;
            D_803F2EB4 = (D_803F2EB4 * tmp) >> 8;
            D_803F2EB8 = (D_803F2EB8 * tmp) >> 8;

            D_803F63E0 = ((SIN((D_803D552C->unk34E << 8) / D_803D552C->unk354) >> 7) * D_803D552C->unk350) >> 8;
        } else {
            D_803D552C->unk354 = (((((64 - SSSV_RAND(128)) * D_803D552C->laughterFactor) >> 6) + 64) * D_803D552C->unk352) >> 6;
            D_803D552C->unk34E = D_803D552C->unk354;
            D_803D552C->unk350 = (((((64 - SSSV_RAND(128)) * D_803D552C->laughterFactor) >> 6) + 64) * D_803D552C->unk356) >> 6;
        }
        if (D_803D552C->laughterDuration > 0) {
            D_803D552C->laughterDuration--;
        }
    }
}
