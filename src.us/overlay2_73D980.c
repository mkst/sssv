#include <ultra64.h>
#include "common.h"


void func_8032C2D0_73D980(s16 id, s16 arg1, f32 arg2) {
    s32 pad;

    if (id != 255) {
        if ((D_803A69F0[id] == 8) || (get_used_sound_count() < D_803A69F0[id])) {
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
            if (sqrt < D_803A6730_7B7DE0[id]) {
                tmp = 256 - ((sqrt * 256) / D_803A6730_7B7DE0[id]);
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

// footstep sfx?
void func_8032C5A8_73DC58(u16 mass, u16 animalId, s16 x, s16 y, s16 z, u8 arg5) {
    s32 sp34;
    s16 pad;
    s8 var_v0;
    s16 sfx_id;
    s16 sp2C;
    s16 var_v1;
    s16 var_t0;
    f32 sp24;

    if ((D_803F2D10.unk0 == 0) && (D_803D5530->unk4A == 0) &&
        (func_802B3D68_6C5418() < 1001) && (get_used_sound_count() < 6) &&
        (animalId != POLAR_BEAR_DEFENDING)) {

        if ((D_803D5530->state >= 0x8D) && (D_803D5530->state < 0x91)) {
            func_8032CA90_73E140(mass, animalId, x, y, z);
            return;
        }

        switch (mass) {
        case 20:
            sp2C = 11;
            sp24 = 1.122f;
            break;
        case 40:
            sp2C = 12;
            sp24 = 1.059f;
            break;
        case 60:
        default:
            sp2C = 15;
            sp24 = 1.0f;
            break;
        case 80:
            sp2C = 17;
            sp24 = 0.841f;
            break;
        case 100:
            sp2C = 19;
            sp24 = 0.749f;
            break;
        }
        sp34 = sqrtf((((x - (s16) D_803F2C44) * (x - (s16) D_803F2C44)) +
                      ((y - (s16) D_803F2C48) * (y - (s16) D_803F2C48)) +
                      ((z - (s16) D_803F2C4C) * (z - (s16) D_803F2C4C))));

        if (sp34 < 1600) {
            if (arg5 == 2) {
                var_v0 = D_803E1D30[D_803C0740[(x >> 6)][(y >> 6)].unk3].unk7;
            } else {
                var_v0 = D_803E1D30[D_803C0740[(x >> 6)][(y >> 6)].unk2].unk7;
            }
            if ((var_v0 < 0) || (var_v0 >= 7)) {
                var_v0 = 0;
            }
            switch (var_v0) {
            case 0:
            default:
                sfx_id = (func_8012826C() % 12) + 220;
                var_v1 = 0x4000;
                break;
            case 1:
                sfx_id = (func_8012826C() % 12) + 232;
                var_v1 = 0x4000;
                break;
            case 2:
                sfx_id = (func_8012826C() % 6) + 244;
                var_v1 = 0x4000;
                break;
            case 3:
                sfx_id = (func_8012826C() % 7) + 250;
                var_v1 = 0x4000;
                break;
            case 4:
                sfx_id = (func_8012826C() % 6) + 257;
                var_v1 = 0x5800;
                break;
            case 5:
                sfx_id = (func_8012826C() % 10) + 263;
                var_v1 = 0x5000;
                break;
            case 6:
                sfx_id = (func_8012826C() % 8) + 273;
                var_v1 = 0x4000;
                break;
            }

            if (sp34 < D_803A6730_7B7DE0[sfx_id]) {
                var_t0 = 256 - ((sp34 << 8) / D_803A6730_7B7DE0[sfx_id]);
            } else {
                var_t0 = 0;
            }

            if (animalId == SKI_HUSKY) {
                var_v1 = (var_v1 * 3) >> 2;
                sp24 = sp24 * 0.6;
            }
            play_sound_effect(sfx_id, 0, (s16) ((s32) (sp2C * var_t0 * var_v1) >> 0xC), sp24, 64);
        }
    }
}

void func_8032CA90_73E140(u16 mass, u16 animalId, s16 xPos, s16 zPos, s16 yPos) {
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
            switch (mass) {
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

            id = (func_8012826C() % 8) + 273;

            if (sqrt < D_803A6730_7B7DE0[id]) {
                tmp = 256 - ((s32) (sqrt * 256) / D_803A6730_7B7DE0[id]);
            } else {
                tmp = 0;
            }
            if (tmp != 0) {
                play_sound_effect(id, 0, ((phi_t0 * tmp) << 14) >> 12, phi_f2, 64);
            }
        }
    }
}

void func_8032CD20_73E3D0(void *arg0, s16 id, s16 arg2, s16 arg3, f32 arg4) {
    if (id != SFX_NONE) {
        func_8013328C(arg0, id, 64, arg4, arg2, arg3);
    }
}

void func_8032CD70_73E420(void *arg0, s16 id, s16 arg2, s16 arg3, f32 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s16 tmp;
    s32 sqrt;

    if (id != SFX_NONE) {
        sqrt = sqrtf(((arg5 - (s16) D_803F2C44) * (arg5 - (s16) D_803F2C44)) +
                     ((arg6 - (s16) D_803F2C48) * (arg6 - (s16) D_803F2C48)) +
                     ((arg7 - (s16) D_803F2C4C) * (arg7 - (s16) D_803F2C4C)));
        if (sqrt < D_803A6730_7B7DE0[id]) {
            tmp = 256 - ((sqrt * 256) / D_803A6730_7B7DE0[id]);
            // fakematch? or just a typo?
            sqrt = (tmp * arg2) >> 8;
            sqrt = (tmp * arg2) >> 8;
            func_8013328C(arg0, id, 64, arg4, sqrt, arg3);
        }
    }
}

void func_8032CED0_73E580(void *arg0, s16 soundId, s16 arg2, f32 arg3, s16 arg4, s16 arg5, s16 xPos, s16 zPos, s16 yPos, s32 xVel, s32 zVel, s32 yVel) {
    f32 temp_f0;
    s16 var_t0;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f12;

    s32 temp_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_f10;

    u8 var_v0;
    s16 var_a2;

    f32 temp_f2;


    if (soundId != 0xFF) {
        temp_v0 = xPos - (s16) D_803F2C44;
        temp_v1 = zPos - (s16) D_803F2C48;
        temp_a0 = yPos - (s16) D_803F2C4C;
        temp_f10 = sqrtf(SQ(temp_v0) + SQ(temp_v1) + SQ(temp_a0));

        if (temp_f10 < D_803A6730_7B7DE0[soundId]) {
            var_t0 = 256 - ((temp_f10 << 8) / D_803A6730_7B7DE0[soundId]);
        } else {
            var_t0 = 0;
        }

        if (var_t0 != 0) {
            if ((u8)arg5 != 0) {
                if ((D_803F28E0[D_803F2A98].cameraMode != 2) && (D_803F28E0[D_803F2A98].cameraMode != 12)) {
                    var_v0 = 0;
                } else {
                    var_v0 = 1;
                }
            } else {
                var_v0 = 1;
            }

            temp_f14 = xPos - D_803F2C44;
            temp_f16 = zPos - D_803F2C48;
            temp_f18 = yPos - D_803F2C4C;

            temp_f0 = sqrtf(SQ(temp_f14) + SQ(temp_f16) + SQ(temp_f18));
            temp_f14 = temp_f14 / temp_f0;
            temp_f16 = temp_f16 / temp_f0;
            temp_f18 = temp_f18 / temp_f0;

            temp_f2 = (D_80204218 * temp_f14) + (D_8020421C * temp_f16) + (D_80204220 * temp_f18);
            temp_f12 = (D_8020422C * temp_f14) + (D_80204230 * temp_f16) + (D_80204234 * temp_f18);

            if (ABS(temp_f12) > ABS(temp_f2)) {
                if (temp_f12 > 0.0f) {
                    var_a2 = 127;
                } else {
                    var_a2 = 0;
                }
            } else if (temp_f2 == 0.0) {
                var_a2 = 64;
            } else {
                var_a2 = ((temp_f12 / ABS(temp_f2)) * 63.0) + 64.0;
            }
            if (var_v0 != 0) {
                temp_f12 = ((temp_f14 * ((f32) xVel / 65536.0)) + (temp_f16 * ((f32) zVel / 65536.0)) + (temp_f18 * ((f32) yVel / 65536.0)));
                if (temp_f12 > 75.0f) {
                    temp_f12 = 75.0f;
                }
                if (temp_f12 < -75.0f) {
                    temp_f12 = -75.0f;
                }
                temp_f0 = (1.0 - (temp_f12 / 150.0f));
            } else {
                temp_f0 = 1.0f;
            }

            func_8013328C(arg0, soundId, var_a2, arg3 * temp_f0, (var_t0 * arg2) >> 8, arg4);
        }
    }
}
