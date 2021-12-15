#include <ultra64.h>
#include "common.h"

#include "structs.h"
#include "variables.us.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031C7A0_72DE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031D624_72ECD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/mouse/func_8031E6A0_72FD50.s")

void func_8031F858_730F08(void) {
    rmonPrintf(D_803BD9A0_7CF050); // "Helimouse is gone\n"
}

void func_8031F87C_730F2C(void) {
    load_animal(MOUSE2);
}

void func_8031F89C_730F4C(void) {
    load_animal(MOUSE);
}

void func_8031F8BC_730F6C(void) {
    if (D_803D5530->state == 21) {
        func_8037D9D4_78F084();
        create_particle_effect(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (func_8012826C() & 1) + 25,
            ((func_8012826C() & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            ((func_8012826C() & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            0,
            (func_8012826C() & 0xF) + 10,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            (func_8012826C() & 0xF) + 0xF);
    } else {
        func_8037D994_78F044(16); // not animal id
        create_particle_effect(
            D_803D5530->xPos,
            D_803D5530->zPos,
            D_803D5530->yPos + (D_803D5530->unk42 >> 2),
            (func_8012826C() & 1) + 25,
            ((func_8012826C() & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            ((func_8012826C() & 0x7FFF) * 2) - FTOFIX32(0.6103515625),
            0,
            (func_8012826C() & 0xF) + 10,
            GPACK_RGBA5551(0, 0, 0, 1),
            GPACK_RGBA5551(0, 0, 0, 1),
            (func_8012826C() & 0xF) + 0xF);
    }
}

void func_8031FA84_731134(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    load_animal(HARD_MOUSE);
    D_803D552C->unk365 = ATTACK_MOUSE_TAIL;
    D_803D552C->unk32A = D_803D5544;
}

void func_8031FAD8_731188(void) {
    if (D_803D552C->unk365 != ATTACK_MOUSE_2) {
        if ((D_803D5544 - (u16)D_803D552C->unk32A) >= 8) {
            if (D_803D552C->unk365 != ATTACK_MOUSE_TAIL) {
                D_803D552C->unk32A = D_803D5544;
            }
            D_803D552C->unk365 = ATTACK_MOUSE_2;
        }
    }
}

void func_8031FB30_7311E0(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == MOUSE) {
        load_animal(MOUSE2);
    }
}

void func_8031FB78_731228(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == RACING_MOUSE) {
        load_animal(HARD_MOUSE);
        D_803D552C->unk365 = ATTACK_MOUSE_TAIL;
        D_803D552C->unk32A = D_803D5544;
    }
}

void racing_mouse_turbo(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 16;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
