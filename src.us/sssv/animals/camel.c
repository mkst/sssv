#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/camel/func_8036D700_77EDB0.s")

void func_8036F3AC_780A5C(void) {
    if (D_803D552C->unk365 != 22) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 22;
    } else {
        recharge_skill(1);
    }
}

void func_8036F404_780AB4(void) {
    func_80322064_733714(17, 60, 0, 60, 22, D_803D552C->unk308, 4, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_8036F4CC_780B7C(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 23;
    func_802B342C_6C4ADC();
}

// water cannon?
void func_8036F50C_780BBC(Animal *arg0) {
    if (D_803D552C->unk365 != 22) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 80, 18, 80, -80, 3, (f32)D_803A05B0 / 65536.0);
        if (tmp == -1) {
            tmp = 32;
        } else {
            tmp = (s16) ((tmp * 256) / 360);
        }
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 22;
        D_803D552C->unk338 = tmp;
    }
}

void camel_cannon_fire_cannon(Animal *arg0) {
    s32 tmp = func_802F8160_709810(D_803D5530, arg0, 60, 60, 22, 32, -12, 0, (f32)D_803A05B0 / 65536.0);
    if (tmp == -1) {
        tmp = 2;
    } else {
        tmp = (s16) ((tmp * 256) / 360);
    }
    func_80322064_733714(17, 60, 0, 60, 22, D_803D552C->unk308, tmp, 1, 20);
    D_803D552C->unk30A = MIN(38, D_803D552C->unk30A + 25);
    func_803421E0_753890(17);
    play_sound_effect_at_location(75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_8036F740_780DF0(u16 arg0) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 23;
    D_803D552C->unk338 = arg0;
    func_802B33D0_6C4A80(D_803D5530);
}
