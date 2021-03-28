#include <ultra64.h>
#include "common.h"


// requires jump table
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/vulture/func_8036C0B0_77D760.s")

void func_8036D30C_77E9BC(void) {
    if (D_803D552C->unk320 == NULL) {
        D_803D552C->unk320 = func_803213B0_732A60();
        if (D_803D552C->unk320 != NULL) {
            D_803D552C->unk308 = D_803D552C->unk320->unk42;
            func_8032AAF0_73C1A0(VULTURE);
            D_803D552C->yPos -= D_803D552C->unk308;
            if (D_803D5530->unk160 == 2) {
                if ((func_80310F58_722608(D_803D552C->xPos, D_803D552C->zPos) >> 16) < D_803D552C->yPos) {
                    D_803D552C->yPos = D_803D552C->yPos;
                } else {
                    D_803D552C->yPos = func_80310F58_722608(D_803D552C->xPos, D_803D552C->zPos) >> 16;
                }
            } else {
                if ((func_8031124C_7228FC(D_803D552C->xPos, D_803D552C->zPos) >> 0x10) < D_803D552C->yPos) {
                    D_803D552C->yPos = D_803D552C->yPos;
                } else {
                    D_803D552C->yPos = func_8031124C_7228FC(D_803D552C->xPos, D_803D552C->zPos) >> 16;
                }
            }
        } else if (D_803D5530->unk162 == 2) {
            if (D_803D5528->skillBEnergy[0] >= 401) {
                D_803D5528->skillBEnergy[0] -= 400;
                if (func_803224C4_733B74(-0x3E, 0, 0, 0xF, 0x14, 0, 0, 0x13) != 0) {
                    func_8032C360_73DA10(0x44, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
                    D_803D5530->yVelocity.h += 2;
                } else {
                    func_8032C360_73DA10(0x4F, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
                }
                if (D_803D552C->unk365 == 0) {
                    D_803D552C->unk365 = 18;
                    D_803D552C->unk32A = D_803D5544;
                }
            }
        }
    } else {
        func_8032C360_73DA10(99, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEF90);
        func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        D_803D552C->yPos += D_803D552C->unk308;
        D_803D552C->unk18 += D_803D552C->unk308;
        func_8032AAF0_73C1A0(VULTURE2);
    }
}

void func_8036D5CC_77EC7C(void) {
    if ((D_803D5530->unk162 == 2) || ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk16C->unk0 >= 256))) {
        if (func_803224C4_733B74(-62, 0, 0, 46, 20, 0, 0, 19) != 0) {
            func_8032C360_73DA10(68, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
            D_803D5530->yVelocity.h += 2;
        } else {
            func_8032C360_73DA10(79, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
        }
        if (D_803D552C->unk365 == 0) {
            D_803D552C->unk365 = 18;
            D_803D552C->unk32A = D_803D5544;
        }
    }
}
