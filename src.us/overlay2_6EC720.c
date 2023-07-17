#include <ultra64.h>
#include "common.h"


// NON-MATCHING: almost JUSTREG
#ifdef NON_MATCHING
void func_802DB070_6EC720(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    s16 tmp1;
    s16 tmp2;
    s16 tmp3;

    s16 sp40;
    s16 sp3E;
    s16 sp3C;

    s32 phi_v1;

    s16 temp_t9_2;

    u16 foo;
    u16 bar;
    f32 tmp;

    s16 phi_a0;
    s16 phi_a1;

    tmp1 = (D_80152350.unk2D0[arg2] * arg4) / 256;

    tmp2 = (D_80152350.unk384[arg2] * arg4) / 256;
    tmp3 = (D_80152350.unk2D0[arg3] * tmp1) / 256;
    tmp1 = (D_80152350.unk384[arg3] * tmp1) / 256;

    sp40 = D_802040F0[arg1].unk0 - D_802040F0[arg0].unk0;
    sp3E = D_802040F0[arg1].unk2 - D_802040F0[arg0].unk2;
    sp3C = D_802040F0[arg1].unk4 - D_802040F0[arg0].unk4;

    tmp = ((f32) tmp3 * tmp3) + ((f32) tmp1 * tmp1) + ((f32) tmp2 * tmp2);
    foo = (s32) sqrtf(tmp);

    tmp = ((f32) sp40 * sp40) + ((f32) sp3E * sp3E) + ((f32) sp3C * sp3C);
    bar = (s32) sqrtf(tmp);

    phi_v1 = foo * bar;
    if (phi_v1 == 0) {
        phi_v1 = 1;
    }
    temp_t9_2 = func_801283AC((((tmp3 * sp40) + (tmp1 * sp3E) + (tmp2 * sp3C)) * 256) / phi_v1);

    if (temp_t9_2 == 180) {
        temp_t9_2 = 179;
    }
    temp_t9_2 = (temp_t9_2 >> 2);

    // falls apart here
    foo = arg5;
    if ((foo < 17) != 0) {
        phi_v1 = foo + (temp_t9_2 * 17);
        phi_a0 = D_803A2D90_7B4440[phi_v1].unk0;
        phi_a1 = D_803A2D90_7B4440[phi_v1].unk2;
    } else {
        phi_v1 = (temp_t9_2 * 17);
        phi_v1 = phi_v1 + ((32 - foo) & 0xffff);
        phi_a0 = D_803A2D90_7B4440[phi_v1].unk0;
        phi_a1 = D_803A2D90_7B4440[phi_v1].unk2;
    }

    D_80203FE0[arg1].unk0 = D_80203FE0[arg0].unk0 + (((phi_a0 * tmp3) + (phi_a1 * sp40)) / 256);
    D_80203FE0[arg1].unk2 = D_80203FE0[arg0].unk2 + (((phi_a0 * tmp1) + (phi_a1 * sp3E)) / 256);
    D_80203FE0[arg1].unk4 = D_80203FE0[arg0].unk4 + (((phi_a0 * tmp2) + (phi_a1 * sp3C)) / 256);
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

void func_802DB8DC_6ECF8C(void) {
    u16 i;

    if (D_803F2ECC < 31) {
        for (i = 0; i < 34; i++) {
            D_802040F0[i].unk0 = D_80203FE0[i].unk0;
            D_802040F0[i].unk2 = D_80203FE0[i].unk2;
            D_802040F0[i].unk4 = D_80203FE0[i].unk4;
        }
    }
}
