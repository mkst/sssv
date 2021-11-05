#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80323680_734D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803250A8_736758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_80326260_737910.s")

#ifdef NON_MATCHING // JUSTREG
void func_803277B4_738E64(void) {
    if ((D_803D552C->unk320 == 0) && (D_803D552C->unk365 != 11)) {
        D_803D552C->unk32A = D_803D5544 & 0xffff; // helps regalloc but unlikely?
        D_803D552C->unk365 = 11;
    } else if ((D_803D552C->unk320 != 0) && (D_803D552C->unk365 != 14) &&
               (D_803D552C->unk365 != 15) && (D_803D552C->unk318 == 0)) {
        D_803D552C->unk32A = D_803D5544;
        if ((D_803D552C->unk320->unk16C->unk0 == 2) || (D_803D552C->unk320->unk16C->unk0 == 61)) {
            D_803D552C->unk365 = 14;
        } else {
            D_803D552C->unk365 = 15;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/bear/func_803277B4_738E64.s")
#endif

void func_8032786C_738F1C(void) {
    if ((D_803D552C->unk320 == 0) && (D_803D552C->unk365 == 0) && (D_803D5530->state != 0xDD)) {
        load_animal(CRAZY_BEAR);
        D_803D552C->unk30E = (u16)0x14;
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
        if (func_802E414C_6F57FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, &sp2E, &sp2D)) {
            func_802A623C_6B78EC(sp2E, sp2D);
            D_803D552C->unk365 = 0;
        }
    } else if ((D_803D5530->state == 0xDD) && (D_801D9ED8.unkFFB8 == 0) && (D_801D9ED8.unkFFB2 != 0)) {
        func_802A628C_6B793C();
    }
}

void func_803279BC_73906C(void) {
    u16 tmp[7]; // is this a struct?

    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        tmp[3] = func_8012826C();
        tmp[4] = func_8012826C();
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        create_particle_effect(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (tmp[3] & 1) + 25,
            ((tmp[4] & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            ((tmp[5] & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            0,
            (tmp[6] & 0xF) + 0xF,
            1,
            1,
            (func_8012826C() & 0x1F) + 0xF);
    } else {
        func_8037D994_78F044(16);
        tmp[3] = func_8012826C();
        tmp[4] = func_8012826C();
        tmp[5] = func_8012826C();
        tmp[6] = func_8012826C();
        create_particle_effect(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (tmp[3] & 1) + 25,
            ((tmp[4] & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            ((tmp[5] & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            0,
            (tmp[6] & 0xF) + 0xF,
            1,
            1,
            (func_8012826C() & 0x1F) + 0xF);
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
