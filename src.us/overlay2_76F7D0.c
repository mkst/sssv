#include <ultra64.h>
#include "common.h"


void func_8035E120_76F7D0(void) {
    D_803D552C->skillAEnergy[0] = MIN(1024, D_803D552C->skillAEnergy[0] + D_803D5524->unkDA[1]);

    if ((D_803D552C->skillAEnergy[1] != 0x7FFF) && (D_803D552C->skillAEnergy[1] != 0x7FFE)) {
        D_803D552C->skillAEnergy[1] = MAX(0, D_803D552C->skillAEnergy[1] - 1);
    }

    D_803D552C->skillBEnergy[0] = MIN(1024, D_803D552C->skillBEnergy[0] + D_803D5524->unkE0[1]);

    if ((D_803D552C->skillBEnergy[1] != 0x7FFF) && (D_803D552C->skillBEnergy[1] != 0x7FFE)) {
        D_803D552C->skillBEnergy[1] = MAX(0, D_803D552C->skillBEnergy[1] - 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E200_76F8B0.s")
// void func_8035E200_76F8B0(void) {
//     s16 skillAEnergy;
//     s16 skillBEnergy;
//
//     // store original
//     skillAEnergy = D_803D552C->skillAEnergy[0];
//
//     D_803D552C->skillAEnergy[0] = MIN(1024, D_803D552C->skillAEnergy[0] + D_803D5524->unkDA[1]);
//     if ((D_803D552C->skillAEnergy[1] != 0x7FFF) && (D_803D552C->skillAEnergy[1] != 0x7FFE)) {
//         D_803D552C->skillAEnergy[1] = MAX(0, D_803D552C->skillAEnergy[1] - 1);
//     }
//
//     // store original
//     skillBEnergy = D_803D552C->skillBEnergy[0];
//
//     D_803D552C->skillBEnergy[0] = MIN(1024, D_803D552C->skillBEnergy[0] + D_803D5524->unkE0[1]);
//     if ((D_803D552C->skillBEnergy[1] != 0x7FFF) && (D_803D552C->skillBEnergy[1] != 0x7FFE)) {
//         D_803D552C->skillBEnergy[1] = MAX(0, D_803D552C->skillBEnergy[1] - 1);
//     }
//
//     // falls apart about here...
//     if ((skillAEnergy < D_803D552C->skillAEnergy[0]) && (D_803D552C->skillAEnergy[0] == 1024)) {
//
//     } else if (skillBEnergy < D_803D552C->skillBEnergy[0]) {
//         D_803F2EE0[0] = D_803F2EE0[1];
//         D_803F2EE0[1] = 0;
//     }
// }

// urghhh, what is this
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E344_76F9F4.s")

#ifdef NON_MATCHING // JUSTREG
void recharge_skill(s16 arg0) {
    D_803D552C->skillAEnergy[arg0*2] += D_803D5524->unkDA[arg0*3];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/recharge_skill.s")
#endif
