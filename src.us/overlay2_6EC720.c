#include <ultra64.h>
#include "common.h"


#ifdef NON_MATCHING
void func_802DB070_6EC720(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    s16 sp46;
    s16 sp44;
    s16 sp42;

    s16 sp40;
    s16 sp3E;
    s16 sp3C;

    s16 phi_a0;
    s16 phi_a1;

    u16 bar;
    u16 foo;

    s32 phi_v1;

    s16 temp_t9_2;

    f32 tmp;

    sp44 = (D_80152350.unk2D0[arg2] * arg4) / 256;
    sp42 = (D_80152350.unk384[arg2] * arg4) / 256;

    sp46 = (D_80152350.unk2D0[arg3] * sp44) / 256;
    sp44 = (D_80152350.unk384[arg3] * sp44) / 256;

    // diff = prev joint location?
    sp40 = D_802040F0[arg1].unk0 - D_802040F0[arg0].unk0;
    sp3E = D_802040F0[arg1].unk2 - D_802040F0[arg0].unk2;
    sp3C = D_802040F0[arg1].unk4 - D_802040F0[arg0].unk4;

    tmp = SQ((f32) sp46) + SQ((f32) sp44) + SQ((f32) sp42);
    foo = (s32) sqrtf(tmp);

    tmp = SQ((f32) sp40) + SQ((f32) sp3E) + SQ((f32) sp3C);
    bar = (s32) sqrtf(tmp);

    phi_v1 = foo * bar;
    if (phi_v1 == 0) {
        phi_v1 = 1;
    }
    temp_t9_2 = func_801283AC((((sp46 * sp40) + (sp44 * sp3E) + (sp42 * sp3C)) * 256) / phi_v1);

    if (temp_t9_2 == 180) {
        temp_t9_2 = 179;
    }
    temp_t9_2 = temp_t9_2 >> 2;

    // falls apart here
    if ((arg5 < 17) != 0) {
        phi_v1 = arg5 + (temp_t9_2 * 17);
        phi_a0 = D_803A2D90_7B4440[phi_v1].unk0;
        phi_a1 = D_803A2D90_7B4440[phi_v1].unk2;
    } else {
        arg5 = (32 - arg5) & 0xFFFF;
        phi_v1 = arg5 + (temp_t9_2 * 17);
        phi_a1 = D_803A2D90_7B4440[phi_v1].unk0; // NOTE: swapped!
        phi_a0 = D_803A2D90_7B4440[phi_v1].unk2; // NOTE: swapped!
    }

    D_80203FE0[arg1].unk0 = D_80203FE0[arg0].unk0 + (((phi_a0 * sp46) + (phi_a1 * sp40)) / 256);
    D_80203FE0[arg1].unk2 = D_80203FE0[arg0].unk2 + (((phi_a0 * sp44) + (phi_a1 * sp3E)) / 256);
    D_80203FE0[arg1].unk4 = D_80203FE0[arg0].unk4 + (((phi_a0 * sp42) + (phi_a1 * sp3C)) / 256);
    if ((D_80203FE0[arg1].unk0 == D_80203FE0[arg0].unk0) &&
        (D_80203FE0[arg1].unk2 == D_80203FE0[arg0].unk2) &&
        (D_80203FE0[arg1].unk4 == D_80203FE0[arg0].unk4)) {
        D_80203FE0[arg1].unk0++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6EC720/func_802DB070_6EC720.s")
#endif

void func_802DB494_6ECB44(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    s16 tmp1, tmp2, tmp3;

    tmp1 = (D_80152350.unk2D0[arg2] * arg4) / 256;
    tmp3 = (D_80152350.unk384[arg2] * arg4) / 256;
    tmp2 = (D_80152350.unk2D0[arg3] * tmp1) / 256;
    tmp1 = (D_80152350.unk384[arg3] * tmp1) / 256;

    D_80203FE0[arg1].unk0 = D_80203FE0[arg0].unk0 + tmp2;
    D_80203FE0[arg1].unk2 = D_80203FE0[arg0].unk2 + tmp1;
    D_80203FE0[arg1].unk4 = D_80203FE0[arg0].unk4 + tmp3;
}

void func_802DB5C0_6ECC70(s16 arg0, s16 arg1, s16 arg2, u16 arg3) {
    D_80203FE0[0].unk0 = ((D_80203FE0[0].unk0 * (32 - arg3)) + (arg3 * arg0)) >> 5;
    D_80203FE0[0].unk2 = ((D_80203FE0[0].unk2 * (32 - arg3)) + (arg3 * arg1)) >> 5;
    D_80203FE0[0].unk4 = ((D_80203FE0[0].unk4 * (32 - arg3)) + (arg3 * arg2)) >> 5;
}

void func_802DB670_6ECD20(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3) {
    if (D_803F2ECC < 31) {
        func_802DB5C0_6ECC70(arg3[0], arg3[1], arg3[2], D_803F2ECC);
        arg3 += 3; // increment 6 bytes
        while (*arg0 != *arg1) {
            func_802DB070_6EC720(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++, D_803F2ECC);
            arg3 += 2; // increment 4 bytes
        }
    } else {
        D_80203FE0[0].unk0 = arg3[0];
        D_80203FE0[0].unk2 = arg3[1];
        D_80203FE0[0].unk4 = arg3[2];
        arg3 += 3; // increment 6 bytes
        while (*arg0 != *arg1) {
            func_802DB494_6ECB44(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++);
            arg3 += 2; // increment 4 bytes
        }
    }
}

void func_802DB7C4_6ECE74(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3) {
    if (D_803F2ECC < 31) {
        while (*arg0 != *arg1) {
            func_802DB070_6EC720(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++, D_803F2ECC);
            arg3 += 2;
        }
    } else {
        while (*arg0 != *arg1) {
            func_802DB494_6ECB44(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++);
            arg3 += 2;
        }
    }
}

void backup_joint_positions(void) {
    u16 i;

    if (D_803F2ECC < 31) {
        for (i = 0; i < 34; i++) {
            D_802040F0[i].unk0 = D_80203FE0[i].unk0;
            D_802040F0[i].unk2 = D_80203FE0[i].unk2;
            D_802040F0[i].unk4 = D_80203FE0[i].unk4;
        }
    }
}
