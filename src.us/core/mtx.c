#include <ultra64.h>
#include "common.h"

#include "mtx.h"


void func_80125980(Mtx *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;

    spC0 = (s64)D_80152350.unk2D0[arg4] << 8;
    spB8 = (s64)D_80152350.unk384[arg4] << 8;
    spB0 = (s64)D_80152350.unk2D0[arg5] << 8;
    spA8 = (s64)D_80152350.unk384[arg5] << 8;
    spA0 = (s64)D_80152350.unk2D0[arg6] << 8;
    sp98 = (s64)D_80152350.unk384[arg6] << 8;

    func_8012635C((arg7 * ( ((spB8 * sp98) / 0x10000) - ((spC0 * ((spB0 * spA0) / 0x10000)) / 0x10000))) / 0x10000, (arg8 * -((spC0 * spA8) / 0x10000)) / 0x10000, &arg0->m[0][0]);
    func_8012635C((arg9 * (-((spB8 * spA0) / 0x10000) - ((spC0 * ((spB0 * sp98) / 0x10000)) / 0x10000))) / 0x10000, 0,                                             &arg0->m[0][1]);

    func_8012635C((arg7 * ( ((spC0 * sp98) / 0x10000) + ((spB8 * ((spB0 * spA0) / 0x10000)) / 0x10000))) / 0x10000, (arg8 * ((spB8 * spA8) / 0x10000)) / 0x10000,  &arg0->m[0][2]);
    func_8012635C((arg9 * (-((spC0 * spA0) / 0x10000) + ((spB8 * ((spB0 * sp98) / 0x10000)) / 0x10000))) / 0x10000, 0,                                             &arg0->m[0][3]);

    func_8012635C((arg7 * (  (spA8 * spA0) / 0x10000)                                                  ) / 0x10000, (arg8 * -spB0) / 0x10000,                      &arg0->m[1][0]);
    func_8012635C((arg9 * (  (spA8 * sp98) / 0x10000)                                                  ) / 0x10000, 0,                                             &arg0->m[1][1]);

    func_8012635C(arg1, arg2,    &arg0->m[1][2]);
    func_8012635C(arg3, 0x10000, &arg0->m[1][3]);
}

void func_80125FE0(Mtx *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;

    sp80 = (s64)D_80152350.unk2D0[arg4] << 8;
    sp78 = (s64)D_80152350.unk384[arg4] << 8;
    sp70 = (s64)D_80152350.unk2D0[arg5] << 8;
    sp68 = (s64)D_80152350.unk384[arg5] << 8;

    func_8012635C((arg6 * sp68) / 0x10000,                       (-arg6 * sp70) / 0x10000,                      &arg0->m[0][0]);
    func_8012635C(0,                                             0,                                             &arg0->m[0][1]);

    func_8012635C( (arg7 * ((sp70 * sp78) / 0x10000)) / 0x10000, (arg7 * ((sp68 * sp78) / 0x10000)) / 0x10000,  &arg0->m[0][2]);
    func_8012635C( (arg7 * sp80) / 0x10000,                      0,                                             &arg0->m[0][3]);

    func_8012635C((-arg8 * ((sp70 * sp80) / 0x10000)) / 0x10000, (-arg8 * ((sp68 * sp80) / 0x10000)) / 0x10000, &arg0->m[1][0]);
    func_8012635C( (arg8 * sp78) / 0x10000,                      0,                                             &arg0->m[1][1]);

    func_8012635C(arg1,  arg2, &arg0->m[1][2]);
    func_8012635C(arg3, 0x10000, &arg0->m[1][3]);
}

void func_8012635C(s32 arg0, s32 arg1, Mtx *arg2) {
    arg2->m[0][0] = (arg0 & 0xFFFF0000) | ((arg1 >> 16) & 0xFFFF);
    arg2->m[2][0] = (arg0 << 16) | (arg1 & 0xFFFF);
}

#if 0
s32 func_80126388(u16 joint0, u16 joint1, s32 scaleX, s32 scaleZ, s32 scaleY, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Mtx *arg9) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;

    s32 sp5C;
    s32 sp58; // ?
    s32 sp54;
    s32 sp50;

    s32 sp4C;

    s32 sp3C;
    s32 sp38;
    s16 sp34;

    s32 sp30;
    s32 sp2C;
    s32 sp28;

    FracIntHelper sp20;

    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_t5_2;
    s32 temp_t7_3;
    s32 temp_t8_4;

    s32 var_t3;

    sp30 = (((D_80203FE0[joint1].unk0 + D_80203FE0[joint0].unk0) >> 1) << 0x10) / 8;
    sp2C = (((D_80203FE0[joint1].unk2 + D_80203FE0[joint0].unk2) >> 1) << 0x10) / 8;
    sp28 = (((D_80203FE0[joint1].unk4 + D_80203FE0[joint0].unk4) >> 1) << 0x10) / 8;

    sp30 = ((arg5 * sp30) >> 4) + sp30;
    sp2C = ((arg5 * sp2C) >> 4) + sp2C;
    sp28 = ((arg5 * sp28) >> 3) + sp28;

    sp6C = D_80203FE0[joint1].unk0 - D_80203FE0[joint0].unk0;
    sp68 = D_80203FE0[joint1].unk2 - D_80203FE0[joint0].unk2;
    sp64 = D_80203FE0[joint1].unk4 - D_80203FE0[joint0].unk4;

    if ((sp6C == 0) && (sp68 == 0)) {

        if (arg8 == 1) {
            sp60 = 0;
            var_t3 = sp54 = 0x400;
            sp50 = 0;
            sp4C = 0;
        } else {
            sp60 = 0x400;
            var_t3 = sp54 = 0;
            sp50 = -0x400;
            sp4C = 0;
        }
        // need to reference var_t3
    } else {
        var_t3 = -sp6C;
        sp60 = sp68;
        if (arg8 == 1) {
            if (var_t3 < 0) {
                sp60 = -sp68;
                var_t3 = -var_t3;
            }
        } else if (sp68 < 0) {
            sp60 = -sp68;
            var_t3 = -var_t3;
        }

        sp54 = -((var_t3 * sp64) / 256);
        sp50 = (sp64 * sp60) / 256;
        sp4C = ((sp6C * var_t3) - (sp68 * sp60)) / 256;

        if ((sp54 == 0) && (sp50 == 0) && (sp4C == 0)) {
            if (sp54 == 0) {
                if ((var_t3 * sp64) < 0) {
                    sp54 = 1;
                } else if ((var_t3 * sp64) > 0) {
                    sp54 = -1;
                }
            }
            if (sp50 == 0) {
                if ((sp64 * sp60) < 0) {
                    sp50 = -1;
                } else if ((sp64 * sp60) > 0) {
                    sp50 = 1;
                }
            }
            if (sp4C == 0) {
                if (((sp6C * var_t3) - (sp68 * sp60)) < 0) {
                    sp4C = -1;
                } else if (((sp6C * var_t3) - (sp68 * sp60)) > 0) {
                    sp4C = 1;
                }
            }
        }
    }

    sp58 = 0;

    sp3C = (s16) (s32) sqrtf(((f32) sp6C * sp6C) + ((f32) sp68 * sp68) + ((f32) sp64 * sp64));
    sp38 = (s16) (s32) sqrtf(((f32) sp60 * sp60) + ((f32) sp5C * sp5C) + ((f32) sp58 * sp58));
    sp34 = (s16) (s32) sqrtf(((f32) sp54 * sp54) + ((f32) sp50 * sp50) + ((f32) sp4C * sp4C));

    if (sp3C == 0) {
        return 0;
    }
    if (sp38 == 0) {
        return 0;
    }
    if (sp34 == 0) {
        return 0;
    }

    sp6C = (sp6C * scaleX) / sp3C;
    sp68 = (sp68 * scaleZ) / sp3C;
    sp64 = (sp64 * scaleY) / sp3C;

    sp60 = (sp60 * scaleX) / sp38;
    sp5C = (sp5C * scaleZ) / sp38;
    sp58 = (sp58 * scaleY) / sp38;

    sp54 = (((scaleX >> 3) * sp54) / sp34) * 8;
    sp50 = (((scaleZ >> 3) * sp50) / sp34) * 8;
    sp4C = (((scaleY >> 3) * sp4C) / sp34) * 8;

    switch (arg7) {                                 /* irregular */
    case 0:
        break;
    case 1:
        sp60 = -sp60;
        sp5C = -sp5C;
        sp58 = -sp58;
        break;
    case 2:
        sp54 = -sp54;
        sp50 = -sp50;
        sp4C = -sp4C;
        break;
    case 3:
        sp60 = -sp60;
        sp5C = -sp5C;
        sp58 = -sp58;

        sp54 = -sp54;
        sp50 = -sp50;
        sp4C = -sp4C;
        break;
    }

    if (arg6 != 0) {
        temp_t7_3 = SIN(arg6) >> 7;
        temp_t8_4 = COS(arg6) >> 7;
        temp_a0_2 = sp60;
        temp_a1 = sp5C;
        temp_t5_2 = sp58;

        sp60 = ((temp_t7_3 * sp54) + (sp60 * temp_t8_4)) >> 8;
        sp5C = ((temp_t7_3 * sp50) + (sp5C * temp_t8_4)) >> 8;
        sp58 = ((temp_t7_3 * sp4C) + (sp58 * temp_t8_4)) >> 8;

        sp54 = ((sp54 * temp_t8_4) - (temp_t7_3 * temp_a0_2)) >> 8;
        sp50 = ((sp50 * temp_t8_4) - (temp_t7_3 * temp_a1)) >> 8;
        sp4C = ((sp4C * temp_t8_4) - (temp_t7_3 * temp_t5_2)) >> 8;
    }

    sp20.w.unk4 = sp6C;
    sp20.w.unk0 = sp68;
    arg9->m[0][0] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    arg9->m[2][0] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp64;
    arg9->m[0][1] = sp20.h.unk4 << 0x10;
    arg9->m[2][1] = sp20.h.unk6 << 0x10;

    sp20.w.unk4 = sp60;
    sp20.w.unk0 = sp5C;
    arg9->m[0][2] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    arg9->m[2][2] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp58;
    arg9->m[0][3] = sp20.h.unk4 << 0x10;
    arg9->m[2][3] = sp20.h.unk6 << 0x10;

    sp20.w.unk4 = sp54;
    sp20.w.unk0 = sp50;
    arg9->m[1][0] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    arg9->m[3][0] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp4C;
    arg9->m[1][1] = sp20.h.unk4 << 0x10;
    arg9->m[3][1] = sp20.h.unk6 << 0x10;

    sp20.w.unk4 = sp30;
    sp20.w.unk0 = sp2C;
    arg9->m[1][2] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    arg9->m[3][2] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp28;
    arg9->m[1][3] = (sp20.h.unk4 << 0x10) | 1;
    arg9->m[3][3] = sp20.h.unk6 << 0x10;

    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/mtx/func_80126388.s")
#endif

// unused?
void func_80126CC4(s16 arg0, Mtx *arg1) {
    FracIntHelper sp8;
    FracIntHelper sp0;

    s16 temp_a2;
    s16 temp_v0;

    temp_v0 = D_80152350.unk2D0[arg0];
    temp_a2 = D_80152350.unk384[arg0];

    sp8.h.unk4 = arg1->m[0][0] >> 0x10;
    sp8.h.unk6 = arg1->m[2][0] >> 0x10;
    sp8.h.unk0 = arg1->m[0][0];
    sp8.h.unk2 = arg1->m[2][0];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    arg1->m[0][0] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    arg1->m[2][0] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = arg1->m[0][2] >> 0x10;
    sp8.h.unk6 = arg1->m[2][2] >> 0x10;
    sp8.h.unk0 = arg1->m[0][2];
    sp8.h.unk2 = arg1->m[2][2];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    arg1->m[0][2] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    arg1->m[2][2] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = arg1->m[1][0] >> 0x10;
    sp8.h.unk6 = arg1->m[3][0] >> 0x10;
    sp8.h.unk0 = arg1->m[1][0];
    sp8.h.unk2 = arg1->m[3][0];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    arg1->m[1][0] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    arg1->m[3][0] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = arg1->m[1][2] >> 0x10;
    sp8.h.unk6 = arg1->m[3][2] >> 0x10;
    sp8.h.unk0 = arg1->m[1][2];
    sp8.h.unk2 = arg1->m[3][2];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    arg1->m[1][2] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    arg1->m[3][2] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
}

s32 func_80126FD4(s32 arg0, s32 arg1, s32 arg2,
                  s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7,
                  Mtx *arg8) {

    s32 sp74, sp70, sp6C;
    s32 sp68, sp64, sp60;
    s32 sp5C, sp58, sp54;
    s32 unused[3];
    s32 sp44, sp40, sp3C;
    s32 sp38, sp34, sp30;
    FracIntHelper sp28;

    sp38 = (arg0 + arg3) >> 1;
    sp34 = (arg1 + arg4) >> 1;
    sp30 = (arg2 + arg5) >> 1;

    arg0 = arg0 >> 8;
    arg1 = arg1 >> 8;
    arg2 = arg2 >> 8;
    arg3 = arg3 >> 8;
    arg4 = arg4 >> 8;
    arg5 = arg5 >> 8;

    sp74 = arg3 - arg0;
    sp70 = arg4 - arg1;
    sp6C = arg5 - arg2;

    if ((sp74 == 0) && (sp70 == 0)) {
        sp68 = 0x400;
        sp64 = 0;
        sp60 = 0;

        sp5C = 0;
        sp58 = -0x400;
        sp54 = 0;
    } else {
        sp68 = sp70;
        sp64 = -sp74;
        sp60 = 0;

        if (sp68 < 0) {
            sp68 = -sp68;
            sp64 = -(-sp74);
        }

        sp5C = (sp64 * sp6C) / -512;
        sp58 = (sp6C * sp68) / 512;
        sp54 = ((sp74 * sp64) - (sp70 * sp68)) / 512;


        if (sp5C == 0) {
            if ((sp64 * sp6C) < 0) {
                sp5C = 1;
            } else if ((sp64 * sp6C) > 0) {
                sp5C = -1;
            }
        }
        if (sp58 == 0) {
            if ((sp6C * sp68) < 0) {
                sp58 = -1;
            } else if ((sp6C * sp68) > 0) {
                sp58 = 1;
            }
        }
        if (sp54 == 0) {
            if (((sp74 * sp64) - (sp70 * sp68)) < 0) {
                sp54 = -1;
            } else if (((sp74 * sp64) - (sp70 * sp68)) > 0) {
                sp54 = 1;
            }
        }
    }

    sp44 = sqrtf(SQ((f32) sp74) + SQ((f32) sp70) + SQ((f32) sp6C));
    sp40 = sqrtf(SQ((f32) sp68) + SQ((f32) sp64) + SQ((f32) sp60));
    sp3C = sqrtf(SQ((f32) sp5C) + SQ((f32) sp58) + SQ((f32) sp54));

    if (sp44 == 0) {
        return 0;
    }
    if (sp40 == 0) {
        return 0;
    }
    if (sp3C == 0) {
        return 0;
    }

    sp74 = (sp74 * arg6) / sp44;
    sp70 = (sp70 * arg6) / sp44;
    sp6C = (sp6C * arg6) / sp44;

    sp68 = (sp68 * arg7) / sp40;
    sp64 = (sp64 * arg7) / sp40;
    sp60 = (sp60 * arg7) / sp40;

    sp5C = (sp5C * arg7) / sp3C;
    sp58 = (sp58 * arg7) / sp3C;
    sp54 = (sp54 * arg7) / sp3C;

    sp28.w.unk4 = sp74;
    sp28.w.unk0 = sp70;
    arg8->m[0][0] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    arg8->m[2][0] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp6C;
    arg8->m[0][1] = sp28.h.unk4 << 0x10;
    arg8->m[2][1] = sp28.h.unk6 << 0x10;

    sp28.w.unk4 = sp68;
    sp28.w.unk0 = sp64;
    arg8->m[0][2] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    arg8->m[2][2] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp60;
    arg8->m[0][3] = sp28.h.unk4 << 0x10;
    arg8->m[2][3] = sp28.h.unk6 << 0x10;

    sp28.w.unk4 = sp5C;
    sp28.w.unk0 = sp58;
    arg8->m[1][0] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    arg8->m[3][0] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp54;
    arg8->m[1][1] = (sp28.h.unk4 << 0x10);
    arg8->m[3][1] = (sp28.h.unk6 << 0x10);

    sp28.w.unk4 = sp38;
    sp28.w.unk0 = sp34;
    arg8->m[1][2] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    arg8->m[3][2] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp30;
    arg8->m[1][3] = (sp28.h.unk4 << 0x10) | 1;
    arg8->m[3][3] = (sp28.h.unk6 << 0x10);

    return 1;
}

void func_80127640(Mtx *arg0, s32 xPos, s32 zPos, s32 yPos, s16 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, s32 arg9) {
    s64 sp58;
    s64 sp50;
    s64 sp48;
    s64 sp40;

    FracIntHelper sp38;

    sp58 = (s64)(SIN(arg4) >> 7) << 8;
    sp50 = (s64)(COS(arg4) >> 7) << 8;

    sp48 = (s64)(SIN((arg4 + arg8) & 0xFF) >> 7) << 8;
    sp40 = (s64)(COS((arg4 + arg8) & 0xFF) >> 7) << 8;

    sp38.w.unk4 = (sp50 * arg5) >> 16;
    sp38.w.unk0 = (sp58 * arg5) >> 16;

    arg0->m[0][0] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    arg0->m[2][0] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    arg0->m[0][1] = 0;
    arg0->m[2][1] = 0;

    sp38.w.unk4 = (-sp58 * arg6) >> 16;
    sp38.w.unk0 = (sp50 * arg6) >> 16;
    arg0->m[0][2] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    arg0->m[2][2] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;
    arg0->m[0][3] = 0;
    arg0->m[2][3] = 0;

    sp38.w.unk4 = (sp40 * arg9) >> 16;
    sp38.w.unk0 = (sp48 * arg9) >> 16;
    arg0->m[1][0] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    arg0->m[3][0] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    sp38.w.unk4 = arg7;
    arg0->m[1][1] = sp38.h.unk4 << 0x10;
    arg0->m[3][1] = sp38.h.unk6 << 0x10;

    sp38.w.unk4 = xPos;
    sp38.w.unk0 = zPos;
    arg0->m[1][2] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    arg0->m[3][2] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    sp38.w.unk4 = yPos;
    arg0->m[1][3] = (sp38.h.unk4 << 0x10) | 1;
    arg0->m[3][3] = sp38.h.unk6 << 0x10;
}

#if 0
// plenty to do
s32 func_80127994(s32 arg0, s32 arg1, s32 arg2, Mtx *arg3) {
    FracIntHelper sp24;
    s32 temp_f4;

    temp_f4 = sqrtf(SQ((f32)arg0) + SQ((f32)arg1) + SQ((f32)arg2));
    if (temp_f4 == 0) {
        arg0 = arg1 = 0 << 0xA;
        arg2 = 1 << 0xA;
    } else {
        arg0 = (arg0 << 0xA) / temp_f4;
        arg1 = (arg1 << 0xA) / temp_f4;
        arg2 = (arg2 << 0xA) / temp_f4;
    }

    temp_f4 = sqrtf(SQ((f32)arg2) + SQ((f32)-arg0));

    sp24.w.unk4 = (( arg2 << 0xA) / temp_f4) << 6;
    sp24.w.unk0 = ((    0 << 0xA) / temp_f4) << 6;
    arg3->m[0][0] = ((sp24.h.unk4 << 0x10) | sp24.h.unk0);
    arg3->m[2][0] = ((sp24.h.unk6 << 0x10) | sp24.h.unk2);

    sp24.w.unk4 = ((-arg0 << 0xA) / temp_f4) << 6;
    arg3->m[0][1] = sp24.h.unk4 << 0x10;
    arg3->m[2][1] = sp24.h.unk6 << 0x10;

    sp24.w.unk4 = -((((    0 << 0xA) / temp_f4) * arg2) - (((-arg0 << 0xA) / temp_f4) * arg1)) << 6;
    sp24.w.unk0 = -((((-arg0 << 0xA) / temp_f4) * arg0) - ((( arg2 << 0xA) / temp_f4) * arg2)) << 6;
    arg3->m[0][2] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    arg3->m[2][2] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    sp24.w.unk4 = -(((( arg2 << 0xA) / temp_f4) * arg1) - (((    0 << 0xA) / temp_f4) * arg0)) << 6;
    arg3->m[0][3] = sp24.h.unk4 << 0x10;
    arg3->m[2][3] = sp24.h.unk6 << 0x10;

    sp24.w.unk4 = arg0 << 6;
    sp24.w.unk0 = arg1 << 6;
    arg3->m[1][0] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    arg3->m[3][0] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    sp24.w.unk4 = arg2 << 6;
    arg3->m[1][1] = sp24.h.unk4 << 0x10;
    arg3->m[3][1] = sp24.h.unk6 << 0x10;

    arg3->m[1][2] = 0;
    arg3->m[3][2] = 0;

    sp24.w.unk4 = 0;
    sp24.w.unk0 = FTOFIX32(1.0);
    arg3->m[1][3] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    arg3->m[3][3] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core/mtx/func_80127994.s")
#endif

void func_80127D30(Mtx *arg0, s16 arg1) {
    FracIntHelper sp0;
    u32 *intPart =  (u32*)&arg0->m[0][0];
    u32 *fracPart = (u32*)&arg0->m[2][0];

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(1.0);
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(-1.0);
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = arg1 << 17;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;
}

void func_80127ED4(Mtx *arg0, s16 arg1) {
    FracIntHelper sp0;
    s32 *intPart = (s32*)&arg0->m[0][0];
    s32 *fracPart = (s32*)&arg0->m[2][0];

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(-1.0);
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(1.0);
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk4 = arg1 << 17;
    sp0.w.unk0 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;
}

void func_80128078(Mtx *arg0, s16 arg1, s16 arg2) {
    s64 sp40;
    s64 sp38;

    FracIntHelper sp30;

    sp40 = (s64)D_80152350.unk2D0[arg2] << 8;
    sp38 = (s64)D_80152350.unk384[arg2] << 8;

    sp30.w.unk4 = 0x10000;

    arg0->m[0][0] = sp30.h.unk4 << 0x10;
    arg0->m[2][0] = sp30.h.unk6 << 0x10;

    arg0->m[0][1] = 0;
    arg0->m[2][1] = 0;

    sp30.w.unk0 = sp38;
    arg0->m[0][2] = sp30.h.unk0;
    arg0->m[2][2] = sp30.h.unk2;

    sp30.w.unk4 = sp40;
    arg0->m[0][3] = sp30.h.unk4 << 0x10;
    arg0->m[2][3] = sp30.h.unk6 << 0x10;

    sp30.w.unk0 = -sp40;
    arg0->m[1][0] = sp30.h.unk0;
    arg0->m[3][0] = sp30.h.unk2;

    sp30.w.unk4 = sp38;
    arg0->m[1][1] = sp30.h.unk4 << 0x10;
    arg0->m[3][1] = sp30.h.unk6 << 0x10;

    sp30.w.unk0 = arg1 * sp40;
    arg0->m[1][2] = sp30.h.unk0;
    arg0->m[3][2] = sp30.h.unk2;

    sp30.w.unk4 = (arg1 << 0x10) - (arg1 * sp38);
    arg0->m[1][3] = (sp30.h.unk4 << 0x10) | 1;
    arg0->m[3][3] = sp30.h.unk6 << 0x10;
}
