#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (from D_803F2EE0 to D_803F2EF0)
// ========================================================

s16 D_803F2EE0[2];

// ========================================================
// .text
// ========================================================

void func_8035E120_76F7D0(void) {
    D_803D552C->energy[0].unk0 = MIN(1024, D_803D552C->energy[0].unk0 + D_803D5524->unkDA[0][1]);

    if ((D_803D552C->energy[0].unk2 != 0x7FFF) && (D_803D552C->energy[0].unk2 != 0x7FFE)) {
        D_803D552C->energy[0].unk2 = MAX(0, D_803D552C->energy[0].unk2 - 1);
    }

    D_803D552C->energy[1].unk0 = MIN(1024, D_803D552C->energy[1].unk0 + D_803D5524->unkDA[1][1]);

    if ((D_803D552C->energy[1].unk2 != 0x7FFF) && (D_803D552C->energy[1].unk2 != 0x7FFE)) {
        D_803D552C->energy[1].unk2 = MAX(0, D_803D552C->energy[1].unk2 - 1);
    }
}

#if 0
// ESA: func_800818D8
// final if statements need work
// replenish energy?
void func_8035E200_76F8B0(void) {
    s16 skillAEnergy, skillBEnergy;

    skillAEnergy = D_803D552C->energy[0].unk0;
    D_803D552C->energy[0].unk0 = MIN(0x400, D_803D552C->energy[0].unk0 + D_803D5524->unkDA[0][1]);
    if ((D_803D552C->energy[0].unk2 != 0x7FFF) && (D_803D552C->energy[0].unk2 != 0x7FFE)) {
        D_803D552C->energy[0].unk2 = MAX(0, D_803D552C->energy[0].unk2 - 1);
    }

    skillBEnergy = D_803D552C->energy[1].unk0;
    D_803D552C->energy[1].unk0 = MIN(0x400, D_803D552C->energy[1].unk0 + D_803D5524->unkDA[1][1]);
    if ((D_803D552C->energy[1].unk2 != 0x7FFF) && D_803D552C->energy[1].unk2 != 0x7FFE) {
        D_803D552C->energy[1].unk2 = MAX(0, D_803D552C->energy[1].unk2 - 1);
    }

    if ((skillAEnergy < D_803D552C->energy[0].unk0)) {
        if (D_803D552C->energy[0].unk0 == 0x400) {
            if ((D_803D552C->energy && D_803D552C->energy) && D_803D552C->energy) {};
        }
    }

    if (((!D_803D552C->energy) && (!D_803D552C->energy)) && (!D_803D552C->energy)) {
    }

    if ((skillBEnergy < D_803D552C->energy[1].unk0)) {
        if ((D_803D552C->energy && D_803D552C->energy) && D_803D552C->energy) {};
    }

    D_803F2EE0[0] = D_803F2EE0[1] = 0;

    if (D_803D552C->energy) {};
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_76F7D0/func_8035E200_76F8B0.s")
#endif

// ESA: func_800819B0
s32 func_8035E344_76F9F4(Animal2 *arg0, s16 arg1) {
    if (arg0->unk0->unkDA[arg1][0] < arg0->animal->energy[arg1].unk0) {
        arg0->animal->energy[arg1].unk0 -= arg0->unk0->unkDA[arg1][0];
        arg0->animal->energy[arg1].unk2  = arg0->unk0->unkDA[arg1][2];
        if ((Animal*)arg0 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            D_803F2EE0[arg1] = 1;
        }
        return 1;
    }
    return 0;
}

void recharge_skill(s16 arg0) {
    D_803D552C->energy[arg0].unk0 += D_803D5524->unkDA[arg0][0];
}
