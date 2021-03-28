#include <ultra64.h>

#include "common.h"


u32 func_80128200(void) {
    u32 temp_v1;
    u32 temp_v2;

    temp_v1 = (D_80151430 * 4) + 2;
    temp_v2 = temp_v1 + 1;
    temp_v1 = (temp_v1 * temp_v2) >> 2;
    D_80151430 = temp_v1;
    return D_80151430;
}

// set time?
void func_8012822C(s32 time) {
    if (time == 0) {
        time = __ull_rshift(osGetTime(), 2);
    }
    D_80151430 = time;
}

u16 func_8012826C(void) {
    u16 temp_a0 = D_80151434;

    D_80151434 <<= 1;
    if (temp_a0 & CONT_A) {
        D_80151434 ^= 1;
    }
    if (temp_a0 & Z_TRIG) {
        D_80151434 ^= 1;
    }
    if (temp_a0 & R_TRIG) {
        D_80151434 ^= 1;
    }
    return D_80151434;
}

// is this some pseudo-random number generator?
void func_801282C4(void) {
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
    func_8012826C();
}

s16 func_8012835C(s16 idx) {
    if (idx >= 0) {
        return D_80152040[idx];
    } else {
        return -D_80152040[-idx];
    }
}

s16 func_801283AC(s16 arg0) {
    if (arg0 >= 0) {
        return 90 - D_80152040[arg0];
    } else {
        return 90 + D_80152040[-arg0];
    }
}

s8 func_8012840C(u8 idx) {
    return D_80152248[idx];
}

s8 func_80128424(u8 idx) {
    return 64 - D_80152248[idx];
}

// is this mapping controller input?
s16 func_8012844C(s16 arg0) {

    if (arg0 >= 2048) {
        return 89;
    }
    if (arg0 < -2047) {
        return -89;
    }

    if (arg0 < 0) {
        return -D_80151438[-arg0];
    } else {
        return D_80151438[arg0];
    }
}

s16 func_801284B8(s16 arg0, s16 arg1) {
    s32 phi_v1;
    s32 phi_v0;
    s16 res;

    if (arg0 < 0) {
        phi_v1 = -arg0;
    } else {
        phi_v1 = arg0;
    }
    if (arg1 < 0) {
        phi_v0 = -arg1;
    } else {
        phi_v0 = arg1;
    }

    if (phi_v1 < phi_v0) {
        if (arg1 > 0) {
            res = func_8012844C((arg0 * 64) / arg1);
            if (res < 0) {
                res += 360;
            }
        } else if (arg1 < 0) {
            res = (func_8012844C(((arg0 * 64) / arg1)) + 180);
        } else if (arg0 >= 0) {
            res = 90;
        } else {
            res = 270;
        }
    } else if (arg0 > 0) {
        res = 90 - func_8012844C((arg1 * 64) / arg0);
    } else if (arg0 < 0) {
        res = 270 - func_8012844C((arg1 * 64) / arg0);
    } else {
        if (arg1 >= 0) {
            res = 0;
        } else {
            res = 180;
        }
    }
    return res;
}

f32 func_801286B8(f32 arg0, f32 arg1) {
    f32 temp_f16;
    f32 temp_f2;
    s16 temp_v0;
    f32 *temp_v1;
    f32 phi_f0;
    f32 phi_f2;

    if (arg0 < 0.0f) {
        phi_f0 = -arg0;
    } else {
        phi_f0 = arg0;
    }
    if (arg1 < 0.0f) {
        phi_f2 = -arg1;
    } else {
        phi_f2 = arg1;
    }

    if (phi_f0 < phi_f2) {
        if (arg1 > 0.0f) {
            if (arg0 > 0.0f) {
                temp_f2 = (arg0 / arg1) * 256.0;
                temp_v0 = temp_f2;
                temp_v1 = &D_80151C38[temp_v0];
                temp_f16 = temp_f2 - temp_v0;
                return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) ;
            } else {
                temp_f2 = (-arg0 / arg1) * 256.0;
                temp_v0 = temp_f2;
                temp_v1 = &D_80151C38[temp_v0];
                temp_f16 = temp_f2 - temp_v0;
                return D_8015AC60 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
            }
        }
        if (arg0 > 0.0f) {
            temp_f2 = (arg0 / -arg1) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &D_80151C38[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return D_8015AC68 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
        } else {
            temp_f2 = (arg0 / arg1) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &D_80151C38[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) + D_8015AC70;
        }
    }
    if (arg1 > 0.0f) {
        if (arg0 > 0.0f) {
            temp_f2 = (arg1 / arg0) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &D_80151C38[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return D_8015AC78 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
        } else {
            temp_f2 = (arg1 / -arg0) * 256.0;
            temp_v0 = temp_f2;
            temp_v1 = &D_80151C38[temp_v0];
            temp_f16 = temp_f2 - temp_v0;
            return ((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]) + D_8015AC80;
        }
    } else if (arg0 > 0.0f) {
        temp_f2 = (-arg1 / arg0) * 256.0;
        temp_v0 = temp_f2;
        temp_v1 = &D_80151C38[temp_v0];
        temp_f16 = temp_f2 - temp_v0;
        return (((1.0 - temp_f16) * temp_v1[0]) + temp_f16 * temp_v1[1]) + D_8015AC88;
    } else {
        temp_f2 = (arg1 / arg0) * 256.0;
        temp_v0 = temp_f2;
        temp_v1 = &D_80151C38[temp_v0];
        temp_f16 = temp_f2 - temp_v0;
        return D_8015AC90 - (((1.0 - temp_f16) * temp_v1[0]) + (temp_f16 * temp_v1[1]));
    }
}

s16 func_80128C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v1;
    s32 phi_v1;
    s16 res;

    phi_v1 = arg3 - arg1;
    if (phi_v1 == 0) {
        phi_v1 = 1;
    }
    temp_v0 = arg2 - arg0;
    if (temp_v0 > 0) {
        if (phi_v1 > 0) {
            res = 180 - func_8012844C((temp_v0 * 64) / phi_v1);
        } else {
            res = -func_8012844C((temp_v0 * 64) / phi_v1);
        }
    } else if (phi_v1 > 0) {
        res = 180 - func_8012844C((temp_v0 * 64) / phi_v1);
    } else {
        res = 360 - func_8012844C((temp_v0 * 64) / phi_v1);
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
