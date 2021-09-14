#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80364780_775E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/penguin/func_80365954_777004.s")
// void func_80365954_777004(void) {
//
//     Animal *a;
//     u16 tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
//
//     if ((D_803D552C->unk162 != 1) && (D_803D552C->unk4A == 0)) {
//         func_8032CD70_73E420(
//             D_803D552C,
//             103,
//             0x7000,
//             0,
//             0.25f,
//             D_803D552C->xPos,
//             D_803D552C->zPos,
//             D_803D552C->yPos
//             );
//
//         a = D_803D5530;
//         if (a->yVelocity.w > FTOFIX32(4.0)) {
//             a->yVelocity.w += FTOFIX32(1.0);
//         } else {
//             a->yVelocity.w += FTOFIX32(2.0);
//         }
//
//         tmp0 = func_8012826C();
//         tmp1 = func_8012826C();
//         tmp2 = func_8012826C();
//         tmp3 = func_8012826C();
//         tmp4 = func_8012826C();
//         tmp5 = func_8012826C();
//         tmp6 = func_8012826C();
//
//         func_802D5F4C_6E75FC(
//             ((tmp0 & 0xF) + a->xPos) - 8,
//             ((tmp1 & 0xF) + a->zPos) - 8,
//             a->yPos,
//             ((tmp2 & 1) + 25),
//             ((tmp3 & 0x7FFF) * 2) - 40000,
//             ((tmp4 & 0x7FFF) * 2) - 40000,
//             (a->yVelocity.w >> 1) - 200000,
//             tmp5 & 0xC,
//             1,
//             0x39CF,
//             (tmp6 & 0xF) + 20);
//
//         tmp0 = func_8012826C();
//         tmp1 = func_8012826C();
//         tmp2 = func_8012826C();
//         tmp3 = func_8012826C();
//         tmp4 = func_8012826C();
//         tmp5 = func_8012826C();
//         a = D_803D5530;
//         func_802D5F4C_6E75FC(
//             ((tmp0 & 0xF) + a->xPos) - 8,
//             ((tmp1 & 0xF) + a->zPos) - 8,
//             a->yPos,
//             0x3F,
//             (a->xVelocity.w >> 2) * -1,
//             (a->zVelocity.w >> 2) * -1,
//             (a->yVelocity.w >> 1) - 300000,
//             (tmp2 & 0x1F) + 30,
//             ((((tmp3 & 0x3F) + 0xC0) << 3) & 0x7C0) | ((((tmp4 & 0x3F) + 0xC0) << 8) & 0xF800) | 1,
//                                                       ((((tmp5 & 0x3F) + 0xC0) << 8) & 0xF800) | 1,
//             0);
//
//     } else {
//         recharge_skill(0);
//         if (D_803D552C) {};
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
