#include <ultra64.h>

#include "common.h"

#include "controller.h"

// randu
u32 random_u32(void) {
    u32 temp_v1;
    u32 temp_v2;

    temp_v1 = (sRandomState32 << 2) + 2;
    temp_v2 = temp_v1 + 1;
    temp_v1 = (temp_v1 * temp_v2) >> 2;
    sRandomState32 = temp_v1;
    return sRandomState32;
}

// set_random_seed
void seed_random_u32(s32 time) {
    if (time == 0) {
        time = osGetTime() >> 2;
    }
    sRandomState32 = time;
}

u16 advance_random_seed(void) {
    u16 temp_a0 = gSeed;

    gSeed <<= 1;
    if (temp_a0 & CONT_A) {
        gSeed ^= 1;
    }
    if (temp_a0 & Z_TRIG) {
        gSeed ^= 1;
    }
    if (temp_a0 & R_TRIG) {
        gSeed ^= 1;
    }
    return gSeed;
}

// is this some pseudo-random number generator?
s32 advance_random_seed_16_steps(void) {
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    advance_random_seed();
    return advance_random_seed();
}

// ESA: func_8001CED4
s16 asin_deg_q8(s16 idx) {
    if (idx >= 0) {
        return gAsinDegreesQ8Table[idx];
    } else {
        return -gAsinDegreesQ8Table[-idx];
    }
}

// get_angle_in_degrees?
// ESA: func_8001CF24
s16 acos_deg_q8(s16 arg0) {
    if (arg0 >= 0) {
        return 90 - gAsinDegreesQ8Table[arg0];
    } else {
        return 90 + gAsinDegreesQ8Table[-arg0];
    }
}

// ESA: func_8001CF7C
s8 func_8012840C(u8 idx) {
    return D_80152248[idx];
}

s8 func_80128424(u8 idx) {
    return 64 - D_80152248[idx];
}

// is this mapping controller input?
// ESA: func_8001CF98
s16 atan_deg_q6(s16 arg0) {
    if (arg0 > 2047) {
        return 89;
    } else
    if (arg0 < -2047) {
        return -89;
    } else
    if (arg0 < 0) {
        return -sAtanDegreesQ6Table[-arg0];
    } else {
        return sAtanDegreesQ6Table[arg0];
    }
}

// ESA: func_8001CFEC
s16 atan2_deg_s16(s16 arg0, s16 arg1) {
    s16 res;

    if (ABS(arg0) < ABS(arg1)) {
        if (arg1 > 0) {
            res = atan_deg_q6((arg0 * 64) / arg1);
            if (res < 0) {
                res += 360;
            }
        } else if (arg1 < 0) {
            res = (atan_deg_q6(((arg0 * 64) / arg1)) + 180);
        } else if (arg0 >= 0) {
            res = 90;
        } else {
            res = 270;
        }
    } else if (arg0 > 0) {
        res = 90 - atan_deg_q6((arg1 * 64) / arg0);
    } else if (arg0 < 0) {
        res = 270 - atan_deg_q6((arg1 * 64) / arg0);
    } else {
        if (arg1 >= 0) {
            res = 0;
        } else {
            res = 180;
        }
    }
    return res;
}

// ESA: func_8001D140
f32 atan2_deg_f32(f32 arg0, f32 arg1) {
    f32 temp_f16;
    f32 temp_f2;
    s16 temp_v0;
    f32 *temp_v1;

    if (ABSF(arg0) < ABSF(arg1)) {
        if (arg1 > 0.0f) {
            if (arg0 > 0.0f) {
                temp_f2 = (arg0 / arg1) * 256.0;
                temp_v0 = temp_f2;
                temp_v1 = &sAtanDegreesQ8Table[temp_v0];
                temp_f16 = temp_f2 - temp_v0;
                return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) ;
            } else {
                temp_f2 = (-arg0 / arg1) * 256.0;
                temp_v0 = temp_f2;
                temp_v1 = &sAtanDegreesQ8Table[temp_v0];
                temp_f16 = temp_f2 - temp_v0;
                return 360.0 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
            }
        }
        if (arg0 > 0.0f) {
            temp_f2 = (arg0 / -arg1) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &sAtanDegreesQ8Table[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return 180.0 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
        } else {
            temp_f2 = (arg0 / arg1) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &sAtanDegreesQ8Table[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) + 180.0;
        }
    }
    if (arg1 > 0.0f) {
        if (arg0 > 0.0f) {
            temp_f2 = (arg1 / arg0) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &sAtanDegreesQ8Table[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return 90.0 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
        } else {
            temp_f2 = (arg1 / -arg0) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &sAtanDegreesQ8Table[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) + 270.0;
        }
    } else if (arg0 > 0.0f) {
        temp_f2 = (-arg1 / arg0) * 256.0;
        temp_v0 = temp_f2;
        temp_v1 = &sAtanDegreesQ8Table[temp_v0];
        temp_f16 = temp_f2 - temp_v0;
        return (((1.0 - temp_f16) * temp_v1[0]) + temp_f16 * temp_v1[1]) + 90.0;
    } else {
        temp_f2 = (arg1 / arg0) * 256.0;
        temp_v0 = temp_f2;
        temp_v1 = &sAtanDegreesQ8Table[temp_v0];
        temp_f16 = temp_f2 - temp_v0;
        return 270.0 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
    }
}

// ESA: func_8001D294 or func_80021044?
s16 func_80128C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 phi_v1;
    s16 res;

    phi_v1 = arg3 - arg1;
    temp_v0 = arg2 - arg0;
    if (phi_v1 == 0) {
        phi_v1 = 1;
    }
    if (temp_v0 > 0) {
        if (phi_v1 > 0) {
            res = 180 - atan_deg_q6((temp_v0 * 64) / phi_v1);
        } else {
            res = -atan_deg_q6((temp_v0 * 64) / phi_v1);
        }
    } else if (phi_v1 > 0) {
        res = 180 - atan_deg_q6((temp_v0 * 64) / phi_v1);
    } else {
        res = 360 - atan_deg_q6((temp_v0 * 64) / phi_v1);
    }

    if (res < 0) {
        res += 360;
    } else {
        if (res >= 360) {
            res -= 360;
        }
    }
    res = 360 - res;
    return res;
}
