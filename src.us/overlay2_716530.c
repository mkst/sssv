#include <ultra64.h>

#include "common.h"

#pragma intrinsic sqrtf

// calculate_hypotenuse
s32 func_80304E80_716530(struct039 *arg0) {
    s32 tmp0, tmp1;

    tmp0 = arg0->unk0;
    tmp1 = arg0->unk4;
    // a^2 + b^2 = c^2
    return sqrtf(tmp0 * tmp0 + tmp1 * tmp1);
}

void func_80304EC4_716574(struct039 *arg0, struct039 *arg1) {
    s32 temp_v0 = func_80304E80_716530(arg0);
    if (temp_v0 == 0) {
        arg1->unk0 = 0;
        arg1->unk4 = 0;
    } else {
        arg1->unk0 = (s32) (arg0->unk0 * 256) / temp_v0;
        arg1->unk4 = (s32) (arg0->unk4 * 256) / temp_v0;
    }
}

void func_80304F70_716620(struct039 *arg0, struct039 *arg1, struct039 *arg2) {
    arg2->unk0 = arg0->unk0 - arg1->unk0;
    arg2->unk4 = arg0->unk4 - arg1->unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_716530/func_80304F94_716644.s")

s16 func_80305084_716734(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    f32 tmp;
    s16 res;

    tmp = sqrtf(arg0 * arg0 + arg1 * arg1);
    tmp *= sqrtf(arg2 * arg2 + arg3 * arg3);

    if (tmp == 0.0f) {
        res = (u16)0;
    } else {
        res = func_801283AC((((arg0 * arg2) + (arg1 * arg3)) * 256) / tmp);
    }
    return res;
}

s16 func_80305194_716844(s16 arg0, s16 arg1) {
    s32 diff;
    s16 ret;

    diff = arg0 - arg1;
    if (diff < 0) {
        ret = -diff;
    } else {
        ret = diff;
    }
    if (ret >= 181) {
        ret = 360 - ret;
    }
    return ret;
}

s16 func_803051F0_7168A0(s16 arg0, s16 arg1) {
    s32 diff;
    s16 ret;

    diff = arg0 - arg1;

    if (diff < 0) {
        ret = -diff;
    } else {
        ret = diff;
    }
    if (ret >= 129) {
        ret = 256 - ret;
    }
    return ret;
}
