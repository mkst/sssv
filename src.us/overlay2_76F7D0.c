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

#ifdef __sgi
void unused_8035E120_76F7D0(void) {
    D_803D552C->energy[0].unk0 = MIN(1024, D_803D552C->energy[0].unk0 + D_803D5524->unkDA[0][1]);

    if ((D_803D552C->energy[0].unk2 != 0x7FFF) && (D_803D552C->energy[0].unk2 != 0x7FFE)) {
        D_803D552C->energy[0].unk2 = MAX(0, D_803D552C->energy[0].unk2 - 1);
    }

    D_803D552C->energy[1].unk0 = MIN(1024, D_803D552C->energy[1].unk0 + D_803D5524->unkDA[1][1]);

    if ((D_803D552C->energy[1].unk2 != 0x7FFF) && (D_803D552C->energy[1].unk2 != 0x7FFE)) {
        D_803D552C->energy[1].unk2 = MAX(0, D_803D552C->energy[1].unk2 - 1);
    }
}
#endif

// ESA: func_800818D8
// Recharges skill energy, ticks cooldowns and clears the skill-use flags.
void func_8035E200_76F8B0(void) {
    s16 oldEnergyB;
    s16 oldEnergyA;
    s16 newEnergyB;
    s16 costB;
    s16 usedSkillB;
    s32 rechargeA;

    oldEnergyA = D_803D552C->energy[SKILL_A].unk0;
    D_803D552C->energy[SKILL_A].unk0 = MIN(0x400, D_803D552C->energy[SKILL_A].unk0 + D_803D5524->unkDA[SKILL_A][1]);
    if ((D_803D552C->energy[SKILL_A].unk2 != 0x7FFF) && (D_803D552C->energy[SKILL_A].unk2 != 0x7FFE)) {
        D_803D552C->energy[SKILL_A].unk2 = MAX(0, D_803D552C->energy[SKILL_A].unk2 - 1);
    }

    oldEnergyB = D_803D552C->energy[SKILL_B].unk0;
    D_803D552C->energy[SKILL_B].unk0 = MIN(0x400, D_803D552C->energy[SKILL_B].unk0 + D_803D5524->unkDA[SKILL_B][1]);
    if ((D_803D552C->energy[SKILL_B].unk2 != 0x7FFF) && (D_803D552C->energy[SKILL_B].unk2 != 0x7FFE)) {
        D_803D552C->energy[SKILL_B].unk2 = MAX(0, D_803D552C->energy[SKILL_B].unk2 - 1);
    }

    // fakematch: preserves the skill A full-charge branch layout.
    rechargeA = (oldEnergyA < D_803D552C->energy[SKILL_A].unk0 &&
                 D_803D552C->energy[SKILL_A].unk0 == 0x400)
                    ? 0x400 - oldEnergyA
                    : D_803D5524->unkDA[SKILL_A][1];
    if (rechargeA > 0 && D_803D552C->energy[SKILL_A].unk0 == 0x400 &&
        oldEnergyA < 0x400) {}

    newEnergyB = D_803D552C->energy[SKILL_B].unk0;
    usedSkillB = D_803F2EE0[SKILL_B];
    if (newEnergyB > oldEnergyB) {
        // fakematch: preserves register allocation across the skill B check.
        if (usedSkillB && D_803D5524->unkDA[SKILL_B][1] > 0 &&
            newEnergyB > D_803D5524->unkDA[SKILL_B][0]) {}

        // fakematch: inferred affordability check retains the species load.
        costB = D_803D5524->unkDA[SKILL_B][0];
        if (oldEnergyB <= costB && newEnergyB > costB) {}
    }

    D_803F2EE0[SKILL_A] = D_803F2EE0[SKILL_B] = 0;
}

// ESA: func_800819B0
s32 func_8035E344_76F9F4(Animal2 *arg0, s16 arg1) {
    if (arg0->unk0->unkDA[arg1][0] < arg0->animal->energy[arg1].unk0) {
        arg0->animal->energy[arg1].unk0 -= arg0->unk0->unkDA[arg1][0];
        arg0->animal->energy[arg1].unk2  = arg0->unk0->unkDA[arg1][2];
        if ((Animal*)arg0 == gAnimalState.animals[gCurrentAnimalIndex].animal) {
            D_803F2EE0[arg1] = 1;
        }
        return 1;
    }
    return 0;
}

void recharge_skill(s16 arg0) {
    D_803D552C->energy[arg0].unk0 += D_803D5524->unkDA[arg0][0];
}
