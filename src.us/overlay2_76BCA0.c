#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76BCA0/func_8035A5F0_76BCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76BCA0/func_8035BDC0_76D470.s")

void func_8035C018_76D6C8(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 7;
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_8035C08C_76D73C(void) {
    if ((D_803D552C->unk365 != 24) && (D_803D552C->unk365 != 25)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 24;
    }
}

void func_8035C0CC_76D77C(void) {
    if ((D_803D552C->unk365 != 24) && (D_803D552C->unk365 != 25)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 25;
    }
}

void func_8035C10C_76D7BC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 7;
    func_8032C360_73DA10(57, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_8035C180_76D830(s16 arg0) {
    D_803D552C->unk2EC = arg0;
}
