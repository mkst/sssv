#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80364780_775E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80365954_777004.s")
// void func_80365954_777004(void) {
//     u16 sp4C;
//     u16 sp4A;
//     u16 sp48;
//     u16 sp46;
//     u16 sp44;
//     u16 sp42;
//
//
//     if ((D_803D552C->unk162 != 1) && (D_803D552C->unk4A == 0)) {
//         func_8032CD70_73E420(D_803D552C, 0x67, 0x7000, 0, 0.25f, D_803D552C->xPos, D_803D552C->zPos, D_803D552C->yPos);
//         if (D_803D5530->yVelocity.w >= 0x40001) {
//             D_803D5530->yVelocity.w += 0x10000;
//         } else {
//             D_803D5530->yVelocity.w += 0x28000;
//         }
//         sp42 = func_8012826C();
//         sp44 = func_8012826C();
//         sp46 = func_8012826C();
//         sp48 = func_8012826C();
//         sp4A = func_8012826C();
//         sp4C = func_8012826C();
//         func_802D5F4C_6E75FC(
//             ((sp42 & 0xF) + D_803D5530->xPos) - 8,
//             ((sp44 & 0xF) + D_803D5530->zPos) - 8,
//             D_803D5530->yPos,
//             ((sp46 & 1) + 25),
//             ((sp48 & 0x7FFF) * 2) - 40000,
//             ((sp4A & 0x7FFF) * 2) - 40000,
//             (D_803D5530->yVelocity.w >> 1) - 200000,
//             sp4C & 0xC,
//             1,
//             0x39CF,
//             (func_8012826C() & 0xF) + 20);
//         sp44 = func_8012826C();
//         sp46 = func_8012826C();
//         sp48 = func_8012826C();
//         sp4A = func_8012826C();
//         sp4C = func_8012826C();
//         func_802D5F4C_6E75FC(
//             ((sp44 & 0xF) + D_803D5530->xPos) - 8,
//             ((sp46 & 0xF) + D_803D5530->zPos) - 8,
//             D_803D5530->yPos,
//             0x3F,
//             (D_803D5530->xVelocity.w >> 2) * -1,
//             (D_803D5530->zVelocity.w >> 2) * -1,
//             (D_803D5530->yVelocity.w >> 1) - 300000,
//             (sp48 & 0x1F) + 30,
//             ((((sp4C & 0x3F) + 0xC0) * 8) & 0x7C0) | ((((sp4A & 0x3F) + 0xC0) << 8) & 0xF800) | 1,
//             ((((func_8012826C() & 0x3F) + 0xC0) << 8) & 0xF800) | 1,
//             0);
//     } else {
//         recharge_skill(0);
//     }
// }

void func_80365C28_7772D8(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk365 = 32;
        D_803D552C->unk32A = D_803D5544;
    } else {
        recharge_skill(1);
    }
}

void func_80365C7C_77732C(void) {
    if (D_803D552C->unk308 == 0) {
        if (D_803D552C->unk2B4.unk8 != 0) {
            play_sound_effect_at_location(0xB8, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEF14);
            D_803D552C->unk308 = 80;
        } else {
            func_8032C508_73DBB8(16, 0x7000, 0, 1.3f);
            D_803D552C->unk308 = 80;
        }
    }
    if (D_803D552C->unk2CC = func_8037E9AC_79005C()) {
        D_803D552C->unk2B4.unk4 = 1;
    } else {
        D_803D552C->unk2B4.unk4 = 0;
    }
}

void func_80365D74_777424(void) {
    D_803D552C->unk2B4.unk4 = 0;
}

// penguin?
void penguin_throw_snowball(Animal *arg0) {
    if (D_803D552C->unk365 != 32) {
        s32 tmp = func_802F8160_709810(D_803D5530, arg0, 0xA, 0x14, 0x23, 0x59, 0, 3, (f32) D_803A05B0 / 65536.0);
        if (tmp == -1) {
            tmp = 0x20;
        } else {
            tmp = (s16) ((tmp * 256) / 360);
        }
        D_803D552C->unk365 = 32;
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk338 = tmp;
    }
}

// king penguin attack
void func_80365E70_777520(s16 arg0) {
    if (D_803D552C->unk308 == 0) {
        play_sound_effect_at_location(184, 0x7000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEF18);
        D_803D552C->unk308 = 50;
    }
    D_803D552C->unk2EC = arg0;
    D_803D552C->unk2B4.unk4 = 1;
}
