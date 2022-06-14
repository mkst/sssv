#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80323680_734D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803250A8_736758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80326260_737910.s")

#ifdef NON_MATCHING // JUSTREG
void func_803277B4_738E64(void) {
    if ((D_803D552C->unk320 == 0) && (D_803D552C->unk365 != ATTACK_GRAB)) {
        D_803D552C->unk32A = D_803D5544 & 0xffff; // helps regalloc but unlikely?
        D_803D552C->unk365 = ATTACK_GRAB;
    } else if ((D_803D552C->unk320 != 0) &&
               (D_803D552C->unk365 != ATTACK_BEAR_2) &&
               (D_803D552C->unk365 != ATTACK_BEAR_3) &&
               (D_803D552C->unk318 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        // object is a bolder or ?
        if ((D_803D552C->unk320->unk16C->objectType == 2) || (D_803D552C->unk320->unk16C->objectType == 61)) {
            D_803D552C->unk365 = ATTACK_BEAR_2;
        } else {
            D_803D552C->unk365 = ATTACK_BEAR_3;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803277B4_738E64.s")
#endif

void func_8032786C_738F1C(void) {
    if ((D_803D552C->unk320 == 0) &&
        (D_803D552C->unk365 == ATTACK_NONE) &&
        (D_803D5530->state != 0xDD)) {
        load_animal(CRAZY_BEAR);
        D_803D552C->unk30E = 20;
    }
}

void func_803278D4_738F84(void) {
    if (D_803D552C->unk30E <= 0) {
        load_animal(BEAR);
    }
}

void func_80327908_738FB8(void) {
    s16 sp2E;
    s8 sp2D;

    if ((D_803D5530->state != 0xDD) && (D_803D552C->unk320 == 0)) {
        if (func_802E414C_6F57FC(D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, &sp2E, &sp2D)) {
            func_802A623C_6B78EC(sp2E, sp2D);
            D_803D552C->unk365 = ATTACK_NONE;
        }
    } else if ((D_803D5530->state == 0xDD) && (D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) {
        func_802A628C_6B793C();
    }
}

void func_803279BC_73906C(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 0xF,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 0xF);
    } else {
        func_8037D994_78F044(16);
        create_particle_effect(
            D_803D5530->xPos.h,
            D_803D5530->zPos.h,
            D_803D5530->yPos.h + (D_803D5530->unk42 >> 2),
            SSSV_RAND(2) + 25,
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            (SSSV_RAND(FTOFIX32(0.5)) * 2) - FTOFIX32(0.6103515625),
            0,
            SSSV_RAND(16) + 0xF,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            SSSV_RAND(32) + 0xF);
    }
}

void func_80327B84_739234(s32 arg0, s32 arg1, s32 arg2) {
}

void func_80327B94_739244(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == BEAR) {
        load_animal(CRAZY_BEAR);
    }
}
