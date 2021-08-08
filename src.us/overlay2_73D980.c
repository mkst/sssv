#include <ultra64.h>
#include "common.h"


void func_8032C2D0_73D980(s16 id, s16 arg1, f32 arg2) {
    s16 *tmp;

    if (id != 255) {
        tmp = &D_803A69F0[id];
        if ((*tmp == 8) || (get_used_sound_count() < *tmp)) {
            play_sound_effect(id, 0, arg1, arg2, 64);
        }
    }
}

void play_sound_effect_at_location(s16 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, f32 arg6) {
    s32 sqrt;
    s16 tmp;

    if ((D_803F2D10.unk0 == 0) && (id != SFX_NONE)) {
        if ((D_803A69F0[id] == 8) || (get_used_sound_count() < D_803A69F0[id])) {
            sqrt = sqrtf(((arg3 - (s16) D_803F2C44) * (arg3 - (s16) D_803F2C44)) +
                         ((arg4 - (s16) D_803F2C48) * (arg4 - (s16) D_803F2C48)) +
                         ((arg5 - (s16) D_803F2C4C) * (arg5 - (s16) D_803F2C4C)));
            if (sqrt < D_803A6730[id]) {
                tmp = 256 - ((sqrt * 256) / D_803A6730[id]);
                play_sound_effect(id, 0, (tmp * arg1) >> 8, arg6, 64);
            }
        }
    }
}

void func_8032C508_73DBB8(s16 id, s16 arg1, s16 arg2, f32 arg3) {
    if (D_803F2D10.unk0 == 0) {
        if ((D_803A69F0[id] == 8) || (get_used_sound_count() < D_803A69F0[id])) {
            if (id != SFX_NONE) {
                play_sound_effect(id, 0, arg1, arg3, 64);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73D980/func_8032C5A8_73DC58.s")

void func_8032CA90_73E140(u16 arg0, u16 animalId, s16 xPos, s16 zPos, s16 yPos) {
    s32 sqrt;

    s16 pad;
    s16 id;
    s16 phi_t0;
    s16 tmp;

    f32 phi_f2;

    if ((D_803F2D10.unk0 == 0) &&
        (D_803D5530->unk4A == 0) &&
        (get_used_sound_count() < 6) &&
        (func_802B3D68_6C5418() < 1001)) {
        D_803D552C->unk36F -= 1;
        if (D_803D552C->unk36F <= 0) {
            D_803D552C->unk36F = D_803D5524->unkEB;
            switch (arg0) {
                case 20:
                    phi_f2 = 1.122f;
                    phi_t0 = 11;
                    break;
                case 40:
                    phi_f2 = 1.059f;
                    phi_t0 = 12;
                    break;
                default:
                case 60:
                    phi_f2 = 1.0f;
                    phi_t0 = 15;
                    break;
                case 80:
                    phi_f2 = 0.841f;
                    phi_t0 = 18;
                    break;
                case 100:
                    phi_f2 = 0.749f;
                    phi_t0 = 21;
                    break;
            }

            sqrt = sqrtf(
                ((xPos - (s16) D_803F2C44) * (xPos - (s16) D_803F2C44)) +
                ((zPos - (s16) D_803F2C48) * (zPos - (s16) D_803F2C48)) +
                ((yPos - (s16) D_803F2C4C) * (yPos - (s16) D_803F2C4C)));

            id = (func_8012826C() % 8) + 273; // 0x111

            if (sqrt < D_803A6730[id]) {
                tmp = 256 - ((s32) (sqrt * 256) / D_803A6730[id]);
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                play_sound_effect(id, 0, ((phi_t0 * tmp) << 14) >> 12, phi_f2, 64);
            }
        }
    }
}

void func_8032CD20_73E3D0(s32 arg0, s16 id, s16 arg2, s16 arg3, f32 arg4) {
    if (id != SFX_NONE) {
        func_8013328C(arg0, id, 64, arg4, arg2, arg3);
    }
}

void func_8032CD70_73E420(s32 arg0, s16 id, s16 arg2, s16 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s16 tmp;
    s32 sqrt;

    if (id != SFX_NONE) {
        sqrt = sqrtf(((arg5 - (s16) D_803F2C44) * (arg5 - (s16) D_803F2C44)) +
                     ((arg6 - (s16) D_803F2C48) * (arg6 - (s16) D_803F2C48)) +
                     ((arg7 - (s16) D_803F2C4C) * (arg7 - (s16) D_803F2C4C)));
        if (sqrt < D_803A6730[id]) {
            tmp = 256 - ((sqrt * 256) / D_803A6730[id]);
            // fakematch? or just a typo?
            sqrt = (tmp * arg2) >> 8;
            sqrt = (tmp * arg2) >> 8;
            func_8013328C(arg0, id, 64, arg4, sqrt, arg3);
        }
    }
}
