#include <ultra64.h>
#include "common.h"

// 2400 lines
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_78A890/func_803791E0_78A890.s")

void func_8037B590_78CC40(void) {
    if ((D_803D552C->unk320 == 0) && (D_803D552C->unk365 != 11) && (D_803D5530->unk162 == 1)) {
        // fakematch
        if (D_803D5530) {};

        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 11;
    } else if (D_803D552C->unk320 != 0) {
        if ((D_803D552C->unk365 != 14) && (D_803D552C->unk365 != 15) && (D_803D552C->unk318 == 0)) {
            D_803D552C->unk32A = D_803D5544;
            if ((D_803D552C->unk320->unk16C->unk0 == 2) || (D_803D552C->unk320->unk16C->unk0 == 61)) {
                D_803D552C->unk365 = 14;
            } else {
                D_803D552C->unk365 = 15;
            }
        }
    }
}

void func_8037B660_78CD10(void) {
    s16 sp2E;
    s8  sp2D;

    if ((D_803D5530->state != 0xDD) && (D_803D552C->unk320 == 0)) {
        if (func_802E414C_6F57FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, &sp2E, &sp2D) != 0) {
             func_802A623C_6B78EC(sp2E, sp2D);
        }
    } else if (D_803D5530->state == 0xDD) {
        if ((D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) {
            func_802A628C_6B793C();
        }
    }
}

void func_8037B70C_78CDBC(void) {
    if (D_803D5530->unk162 == 1) {
        func_802A63C0_6B7A70();
        D_803D552C->unk369 = 1;
    }
}

void func_8037B754_78CE04(Animal *arg0, Animal *arg1) {
    if (arg0->unk365 != 11) {
        arg0->unk330 = arg1;
        arg0->unk32A = D_803D5544;
        arg0->unk365 = 11;
    }
}

void func_8037B784_78CE34(Animal *arg0) {
    if (arg0->unk320 != NULL) {
        if ((arg0->unk365 != 14) && (arg0->unk365 != 15) &&
            (D_803D552C->unk318 == 0)) {
            arg0->unk32A = D_803D5544;
            if ((arg0->unk320->unk16C->unk0 == 2) ||
                (arg0->unk320->unk16C->unk0 == 61)) {
                arg0->unk365 = 14;
            } else {
                arg0->unk365 = 15;
            }
        }
    }
}
