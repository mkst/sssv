#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/parrot/func_80313790_724E40.s")

void func_803144F8_725BA8(void) {
    if ((D_803D5530->unk162 != 1) && (func_803224C4_733B74(0, 0, 0, 0, 32, 0, 0, 11) == 0) && (func_802B2580_6C3C30() >= 49)) {
        func_8032AAF0_73C1A0(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}

void func_80314590_725C40(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032AAF0_73C1A0(PARROT);
    func_8032C360_73DA10(0x8D, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BD114_7CE7C4);
    func_802A6100_6B77B0();
}

void func_80314600_725CB0(void) {
    if (D_803D5530->unk162 != 1) {
        func_8032AAF0_73C1A0(PARROT_ATTACKING);
        func_802A61EC_6B789C(D_803D5530->yRotation);
        D_803D552C->unk2EE = 0;
    }
}
