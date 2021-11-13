#include <ultra64.h>
#include "common.h"

// minigame?

void func_802CB360_6DCA10(void) {
    D_803D6120.unk0 = 0;
    memset_bytes((u8*)&D_803D6120, 0, sizeof(D_803D6120));
    D_803DA0F4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802CB394_6DCA44.s")

void func_802D5AD8_6E7188(s16 arg0, s16 arg1) {
    s16 i;

    for (i = arg0; i < arg1; i++) {
        if (D_803D6120.unk3FC8[i] == 1) {
            gSPDisplayList(D_801D9E7C++, &D_80204278->unk109A0[i]);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D5B88_6E7238.s")

// arg3 = smoke type 38 --> Zzzzz...
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/create_particle_effect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D6738_6E7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7434_6E8AE4.s")

#ifdef NON_MATCHING
void func_802D760C_6E8CBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s16 temp_s0;
    s16 temp_s2;
    s16 phi_v1;
    s16 i;
    s32 phi_v1_4;
    u16 random;

    if (arg3 < 2) {
        arg3 = 2;
    }

    phi_v1 = ABS(arg4);
    if (phi_v1 > 6) {
        phi_v1 = 6;
    }
    if (phi_v1 < 2) {
        phi_v1 = 2;
    }

    if (arg3 < 17) {
        tmp1 = 0;
    } else if ((arg3 > 16) && (arg3 < 27)) {
        tmp1 = 1;
    } else if (arg3 > 26) {
        tmp1 = 2;
    }

    tmp0 = (tmp1 + 1) << 4;
    if (tmp0 > 25) {
        tmp0 = 25;
    }

    tmp2 = arg3 / 4;
    if (tmp2 < 4) {
        tmp2 = 4;
    }
    if (tmp2 > 24) {
        tmp2 = 24;
    }

    for (i = 0; i < tmp0; i++) {
        temp_s0 = arg0 + ((D_80152350.unk2D0[(s16)((func_8012826C() & 7) + (360 / tmp0 * i))] * arg3) >> 9);
        temp_s2 = arg1 + ((D_80152350.unk384[(s16)((func_8012826C() & 7) + (360 / tmp0 * i))] * arg3) >> 9);
        phi_v1_4 = MAX(arg2, func_80298E98_6AA548(temp_s0, temp_s2));
        phi_v1_4 = (s16)(phi_v1_4 + 20);
        random = func_8012826C();
        guRandom();
        create_particle_effect(
            temp_s0,
            temp_s2,
            phi_v1_4,
            24,
            D_80152350.unk2D0[(s16)(360 / tmp0 * i)] * tmp2 << 4,
            D_80152350.unk384[(s16)(360 / tmp0 * i)] * tmp2 << 4,
            ((random & 0x7FFF) << 2) + (phi_v1 << 16),
            2,
            GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
            GPACK_RGBA5551((D_803E1BBA + 511) / 3, (D_803E1BBB + 511) / 3, (D_803E1BBC + 511) / 3, 1),
            0);
    }
    if (tmp1 == 0) {
        tmp3 = 0x5000;
    }
    if (tmp1 == 1) {
        tmp3 = 0x7FFF;
    }
    if (tmp1 == 2) {
        tmp3 = 0x5000;
    }
    // this seems weird
    if (tmp1 < 2) {
        play_sound_effect_at_location(SFX_UNKNOWN_165, 0x7FFF, 0x80, arg0, arg1, arg2, 1.0f);
    } else {
        play_sound_effect_at_location(SFX_UNKNOWN_76, tmp3, 0x80, arg0, arg1, arg2, 1.0f);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D760C_6E8CBC.s")
#endif

void func_802D7AD4_6E9184(s16 x, s16 z, s16 y, s16 arg3) {
    s16 i;
    s16 tmp = (arg3 * 3) + 1;

    for (i = 0; i < tmp; i++) {
            func_802D5B88_6E7238(
                (func_8012826C() & 7) + x,
                (func_8012826C() & 7) + z,
                y,
                28,
                (func_8012826C() & 7) + 1,
                0,
                0,
                0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6DCA10/func_802D7BE0_6E9290.s")

void func_802D9C64_6EB314(s16 x, s16 z, s16 y, s16 arg3, u16 color) {
    s16 tmp0;
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;
    s32 pad[3];
    s16 i;

    if (arg3 < 2) {
        arg3 = 2;
    }

    if (arg3 < 17) {
        tmp1 = 0;
    } else if ((arg3 > 16) && (arg3 < 33)) {
        tmp1 = 1;
    } else if (arg3 > 31) {
        tmp1 = 2;
    }

    tmp0 = (((func_8012826C() & 1) + tmp1) * 3) + 6;
    if (tmp0 > 12) {
        tmp0 = 12;
    }

    tmp2 = arg3 / 4;
    if (tmp2 < 4) {
        tmp2 = 4;
    }
    if (tmp2 > 24) {
        tmp2 = 24;
    }
    guRandom();
    guRandom();
    guRandom();
    for (i = 0; i < tmp0; i++) {
        create_particle_effect(
            x,
            z,
            y,
            35,
            D_80152350.unk2D0[(s16)((guRandom() % 90) + (360 / tmp0) * i)] * tmp2 * 84,
            D_80152350.unk384[(s16)((guRandom() % 90) + (360 / tmp0) * i)] * tmp2 * 84,
            ((func_8012826C() & 0x7FFF) * 2) + FTOFIX32(6.0),
            (func_8012826C() & 1) + 3,
            color,
            color,
            0);
    }
    func_8012826C();
    if (tmp1 == 0) {
        tmp3 = 0x2000;
    }
    if (tmp1 == 1) {
        tmp3 = 0x2500;
    }
    if (tmp1 == 2) {
        tmp3 = 0x3000;
    }
    play_sound_effect_at_location(SFX_UNKNOWN_77, tmp3, 0x80, x, z, y, 1.0f);
}

void func_802D9FC4_6EB674(s16 x, s16 z, s16 y, s16 arg3) {
    s16 phi_s0;
    u16 temp_v1;
    s16 i;

    phi_s0 = guRandom() % 4;

    switch (arg3) {
    case 1:
        play_sound_effect_at_location(SFX_PICKUP_ENERGY_BALL, 0x6000, 0, x, z, y, 1.0f);
        for (i = 0; i < 8; i++) {
            phi_s0 = (s16)(phi_s0 + 1) % 4;
            create_particle_effect(
                x,
                z,
                y,
                60,
                guRandom() % 0x80,
                0,
                0,
                16,
                D_803A20B0_7B3760[phi_s0],
                D_803A20B0_7B3760[phi_s0],
                i << 2);
        }
        break;
    case 2:
        play_sound_effect_at_location(D_803A1BB0_7B3260[D_803F2D3C].id, 0x6000, 0, x, z, y, D_803A1BB0_7B3260[D_803F2D3C].unk0);
        for (i = 0; i < 8; i++) {
            phi_s0 = (s16)(phi_s0 + 1) % 4;
            create_particle_effect(
                x,
                z,
                y,
                61,
                guRandom() % 0x80,
                0,
                0,
                16,
                D_803A20B0_7B3760[phi_s0 + 4],
                D_803A20B0_7B3760[phi_s0 + 4],
                i << 2);
        }
        break;
    case 3:
        play_sound_effect_at_location(SFX_UNKNOWN_112, 0x6000, 0, x, z, y, 1.0f);
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                ((guRandom() % 20) + x) - 12,
                ((guRandom() % 20) + z) - 12,
                ((guRandom() % 20) + y) - 12,
                89,
                guRandom() % 0x80,
                0,
                0,
                1,
                GPACK_RGBA5551((guRandom() % 64) + 192, (guRandom() % 64) + 192, 0, 1),
                GPACK_RGBA5551((guRandom() % 64) + 192, (guRandom() % 64) + 192, 0, 1),
                32);
        }
        break;
    case 4:
        play_sound_effect_at_location(SFX_UNKNOWN_163, 0x5000, 0, x, z, y, 1.0f);
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                ((guRandom() % 20) + x) - 12,
                ((guRandom() % 20) + z) - 12,
                ((guRandom() % 20) + y) - 12,
                89,
                guRandom() % 0x80,
                0,
                0,
                16,
                GPACK_RGBA5551((guRandom() % 64) + 192, (guRandom() % 64) + 192, 0, 1),
                GPACK_RGBA5551((guRandom() % 64) + 192, (guRandom() % 64) + 192, 0, 1),
                32);
        }
        break;
    case 5:
    case 6:
        if (arg3 == 5) {
            play_sound_effect_at_location(SFX_UNKNOWN_78, 0x6000, 0, x, z, y, 1.0f);
        }
        for (i = 0; i < 16; i++) {
            create_particle_effect(
                ((guRandom() % 60) + x) - 36,
                ((guRandom() % 60) + z) - 36,
                ((guRandom() % 60) + y) - 36,
                65,
                guRandom() % 0x80,
                0,
                0,
                16,
                GPACK_RGBA5551(248, 0, 248, 1),
                GPACK_RGBA5551(248, 0, 248, 1),
                0);
        }
        break;
    default:
        break;
    }
}
