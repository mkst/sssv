#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_780E50/func_8036F7A0_780E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_780E50/func_80370C84_782334.s")

void func_80372510_783BC0(void) {
    D_803D552C->unk32A = D_803D5544;
    if ((func_8012826C() & 1) == 0) {
        D_803D552C->unk365 = 4;
    } else {
        D_803D552C->unk365 = 5;
    }
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_803725A4_783C54(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 35;
        D_803D552C->unk32C = D_803D552C->unk302;
    } else {
        func_8035E3E8_76FA98(1);
    }
}

void func_80372604_783CB4(void) {
    D_803D552C->unk32A = D_803D5544;
    if ((func_8012826C() & 1) == 0) {
        D_803D552C->unk365 = 4;
    } else {
        D_803D552C->unk365 = 5;
    }
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_80372698_783D48(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 0x23;
        D_803D552C->unk32C = D_803D552C->unk302;
    }
}
