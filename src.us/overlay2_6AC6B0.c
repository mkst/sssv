#include <ultra64.h>
#include "common.h"



// ========================================================
// definitions
// ========================================================

s32 func_8030400C_7156BC(Animal*, s16, s16, s32*, s32*);
s32 func_8032B1E0_73C890(Animal*, s16, s16, s32*, s32*);

// ========================================================
// .data
// ========================================================

u16 D_803A0510_7B1BC0[] = {
    0x0206, 0xBA26, 0x0206, 0x0000, 0x0000,
    0xAE26, 0x0200, 0x0200, 0x0200, 0x0000,
    0x0200, 0x0000, 0x0200, 0x0206, 0x0202,
    0x0000,
};

// ========================================================
// .bss
// ========================================================

// ========================================================
// .text
// ========================================================

#if 0
// absolute shambles.
// ESA: func_800397B0
u8 func_8029B000_6AC6B0(s16 arg0, s16 arg1, s32 yPos, Animal *arg3, Animal *arg4, Animal **arg5, s32 *arg6,
                                                                    Animal *arg7, Animal **arg8, s32 *arg9) {
    s32 sp9C;
    s32 sp98;
    s32 pad[6];

    s32 temp_v1_2;
    s32 temp_v0_5;
    s32 temp_t5;
    s16 temp_v0;
    Animal *animal;
    s32 minDist;
    s32 do_check;
    s32 maxDist;

    struct065 *var_s2;
    struct035 *temp_a1;
    struct035 *tmp;

    *arg6 = -1;
    *arg9 = -1;

    *arg5 = NULL;
    *arg8 = NULL;

    maxDist = 0;
    minDist = 0x40000000;

    temp_v0 = (s16)(arg0 >> 0xA) + ((s16) (arg1 >> 0xA) * 5);
    var_s2 = D_803DA110[temp_v0].next;

    if ((temp_v0 < 0) || (temp_v0 >= 40)) {
        return 0;
    }

    for (; var_s2 != NULL; var_s2 = var_s2->next) {
        animal = var_s2->animal;

        if (animal == arg3) {
            if ((arg3->unk16C->objectType != (256+63)) || (arg3->unk365 != 9)) {

                temp_a1 = arg3->unk16C;
                tmp = animal->unk16C;
                temp_t5 = tmp->unk2;

                if (((D_803A0510_7B1BC0[5]             & (1 << (0xF - tmp->unk2))) != 0) ||
                    ((D_803A0510_7B1BC0[temp_a1->unk2] & (1 << (0xF - temp_t5))) == 0)) {

                    var_s2 = var_s2->next; // not correct... urgh

                } else if ((temp_a1->unk2 == 5) && (animal == arg3->unk320)) {

                    var_s2 = var_s2->next; // not correct... urgh

                } else if (((animal->unk15C != 0) && (arg3 == animal->owner)) ||
                           ((arg3->unk15C != 0) && (animal == arg3->owner))) {

                     var_s2 = var_s2->next; // not correct... urgh

                } else {
                    do_check = 0;
                    if ((tmp->unk2 == 5) && (temp_a1->unk2 == 5)) {
                        if ((tmp->unkE6 < temp_a1->unkE6) || (func_8030AA08_71C0B8(animal, arg3) != 0) || (animal->unk366 == 5) || (arg3->unk366 == 5)) {
                            if (animal->unk16C->unkE6 >= arg3->unk16C->unkE6) {
                                if (((arg0 >= (animal->position.xPos.h - animal->unk34)) && (arg0 < (animal->position.xPos.h + animal->unk34))) &&
                                    ((arg1 >= (animal->position.zPos.h - animal->unk34)) && (arg1 < (animal->position.zPos.h + animal->unk34)))) {
                                    do_check = func_8030400C_7156BC(animal, arg0, arg1, &sp9C, &sp98);
                                }
                            } else if ((((arg3->unk162 != 1) || (arg3->unk68 != NULL)) && (arg3->yVelocity.w < FTOFIX32(-6.0))) || ((animal->unk366 == 5)) || (animal->unk366 == 2)) {

                                temp_v0_5 = arg0 - animal->position.xPos.h;
                                temp_v1_2 = arg1 - animal->position.zPos.h;
                                temp_t5 = animal->unk30 * 2;

                                if ((SQ(temp_v0_5) + SQ(temp_v1_2)) <= SQ(temp_t5)) {
                                    do_check = 1;
                                    sp9C = animal->position.yPos.w + (animal->unk42 << 0x10);
                                    sp98 = animal->position.yPos.w;
                                }
                            }
                        }
                    } else {
                        if (((arg0 >= (animal->position.xPos.h - animal->unk30)) && (arg0 < (animal->position.xPos.h + animal->unk30))) &&
                           ((arg1 >= (animal->position.zPos.h - animal->unk32)) && (arg1 < (animal->position.zPos.h + animal->unk32)))) {
                            do_check = func_8032B1E0_73C890(animal, arg0, arg1, &sp9C, &sp98);
                        }
                    }

                    if (do_check != 0) {

                        animal->unk4C.unk19 = 1;
                        if (animal == arg4) {
                            if (sp9C >= maxDist) {
                                maxDist = *arg6 = sp9C;
                                *arg5 = arg4;
                            }
                        } else if (animal == arg7) {
                            if (minDist >= sp98) {
                                *arg9 = minDist = sp98;
                                *arg8 = arg7;
                            }
                        } else if (arg3 == animal->unk68) {
                            if (sp98 < minDist) {
                                *arg9 = minDist = sp98;
                                *arg8 = animal;
                            }
                        } else if (arg3 == animal->unk70) {
                            if (maxDist < sp9C) {
                                maxDist = *arg6 = sp9C;
                                *arg5 = animal;
                            }
                        } else if (yPos < ((sp98 + sp9C) >> 1)) {
                            if (sp98 < minDist) {
                                *arg9 = minDist = sp98;
                                *arg8 = animal;
                            }
                        } else if (maxDist < sp9C) {
                            maxDist = *arg6 = sp9C;
                            *arg5 = animal;
                        }
                    }
                }
            }
        }
    }

    return (*arg5 != NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6AC6B0/func_8029B000_6AC6B0.s")
#endif

s32 func_8029B56C_6ACC1C(s16 arg0, s16 arg1, s16 *arg2, struct063 arg3[73][129]) {
    s16 temp_t3;
    s16 temp_t5;

    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_v1;

    s32 changed;

    s16 a0 = arg0 >> 6;
    s16 a1 = arg1 >> 6;

    if ((a0 < 0) || (a0 >= 72) || (a1 < 0) || (a1 >= 128)) {
        return 0;
    }

    if (arg3[a0][a1].unk3 != 0) {
        temp_v1 = arg3[(a0) + 0][(a1) + 0].unk1 << 3;
        temp_a3 = arg3[(a0) + 0][(a1) + 1].unk1 << 3;
        temp_t0 = arg3[(a0) + 1][(a1) + 1].unk1 << 3;
        temp_t1 = arg3[(a0) + 1][(a1) + 0].unk1 << 3;

        temp_t3 = arg0 & 0x3F;
        temp_t5 = arg1 & 0x3F;

        if ((D_803C0740[(a0)][(a1)].unk4 & 1)) {
            if (temp_t3 < temp_t5) {
                *arg2 = temp_v1 + ((((temp_t0 - temp_a3) * temp_t3) + ((temp_a3 - temp_v1) * temp_t5)) >> 6);
            } else {
                *arg2 = temp_v1 + ((((temp_t1 - temp_v1) * temp_t3) + ((temp_t0 - temp_t1) * temp_t5)) >> 6);
            }
        } else {
            if ((temp_t3 + temp_t5) < 64) {
                *arg2 = (((temp_v1 << 6) + ((temp_t1 - temp_v1) * temp_t3) + ((temp_a3 - temp_v1) * temp_t5)) >> 6);
            } else {
                *arg2 = (((temp_t0 << 6) + ((temp_a3 - temp_t0) * (0x40 - temp_t3)) + ((temp_t1 - temp_a3) * (0x40 - temp_t5))) >> 6);
            }
        }
        changed = 1;
        *arg2 -= D_803E1D30[D_803C0740[a0][a1].unk3].unk2 << 3;
    } else {
        changed = 0;
    }

    return changed;
}
