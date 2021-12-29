#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_80365F10_7775C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/polar_bear/func_803677C4_778E74.s")

// animation?
void func_80368840_779EF0(s16 arg0) {
    s32 pad;

    f32 temp_s1f;
    f32 temp_s7f;
    f32 temp_s2f;


    s16 temp_s1;
    s16 temp_s2;
    Vtx *phi_a1;
    Vtx *sp44;
    s32 tmp;
    s16 temp_s3;
    s16 temp_s7;
    s16 temp_v0;

    s16 i;

    sp44 = D_801D9EC4 + ((s32)D_04002930_DFEF0 & 0xFFFFFF);
    tmp = D_801D9EC4 + ((s32)D_04002630_DFBF0 & 0xFFFFFF);
    phi_a1 = tmp;

    for (i = 0; i < 48; i++) {
        // FIXME: fakematch nonsense
        temp_s1 = (((0, sp44)) + i)->v.ob[0];
        temp_s2 = (sp44 + i)->v.ob[1];
        temp_s3 = (sp44 + i)->v.ob[2];

        temp_s1f = temp_s1;
        temp_s2f = temp_s2;
        temp_s7f = temp_s7 = temp_s3 + ((temp_s3 + 75) / 2);

        temp_v0 = (s32) sqrtf((temp_s1f * temp_s1f) + (temp_s2f * temp_s2f) + (temp_s7f * temp_s7f));

        (phi_a1 + i)->v.ob[0] = ((((s16)  ((temp_s1 * 50) / temp_v0)       * arg0) + (temp_s1 * (32 - arg0))) >> 5);
        (phi_a1 + i)->v.ob[1] = ((((s16)  ((temp_s2 * 50) / temp_v0)       * arg0) + (temp_s2 * (32 - arg0))) >> 5);
        (phi_a1 + i)->v.ob[2] = ((((s16) (((temp_s7 * 50) / temp_v0) - 15) * arg0) + (temp_s3 * (32 - arg0))) >> 5);
    }
}

// polar bear
void func_80368AC4_77A174(void) {
    if ((D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) &&
        (D_803D552C->unk365 != ATTACK_POLAR_BEAR_3)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_2;
    }
}

// polar bear defending
void func_80368B04_77A1B4(void) {
    if ((D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) &&
        (D_803D552C->unk365 != ATTACK_POLAR_BEAR_3)) {
        load_animal(POLAR_BEAR);
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_3;
        func_802A4390_6B5A40();
        func_802B2834_6C3EE4();
    }
}

void func_80368B78_77A228(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_POLAR_BEAR_1;
}

// polar tank
void func_80368BA0_77A250(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 0x599, 0xB4, D_803D5530, 0x32, 0x21);
        play_sound_effect_at_location(SFX_UNKNOWN_38, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    } else {
        recharge_skill(1);
    }
}

void polar_tank_drop_mine(void) {
    if ((D_803D5530->unk162 == 1) && (D_803D5530->unk6C == 0)) {
        spawn_temporary_object(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 0x599, 0xDC, D_803D5530, 0x32, 0x21);
        play_sound_effect_at_location(SFX_UNKNOWN_38, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
    }
}

void polar_tank_fire_cannon(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_POLAR_BEAR_1;
}

void polar_bear_jump_thump(void) {
    if (D_803D5530->unk162 == 1) {
        func_802A467C_6B5D2C(0);
        D_803D552C->unk369 = 1;
    }
}

void func_80368D60_77A410(s16 arg0) {
    if (arg0 == 0) {
        D_803D552C->unk2EC = 0;
    } else if (D_803D552C->unk365 != ATTACK_POLAR_BEAR_2) {
        D_803D552C->unk2EC = arg0;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_POLAR_BEAR_2;
    } else {
        D_803D552C->unk2EC = arg0;
    }
}
