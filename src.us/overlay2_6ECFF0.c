#include <ultra64.h>
#include "common.h"


// ESA: func_80062F98
void func_802DB940_6ECFF0(s16 *heading, s16 arg1, u16 arg2) {
    if (*heading != arg1) {
        s16 tmp = arg1 - *heading;
        if (tmp < 0) {
            tmp += 256;
        }
        if (tmp < 128) {
            *heading += arg2;
            if ((tmp - arg2) < 0) {
                *heading = arg1;
            }
            if (*heading >= 256) {
                *heading -= 256;
            }
        } else {
            *heading -= arg2;
            if ((tmp + arg2) > 256) {
                *heading = arg1;
            }
            if (*heading < 0) {
                *heading += 256;
            }
        }
    }
}

// ESA: func_8006303C
void func_802DB9E8_6ED098(s16 *arg0, s16 arg1, u16 delta) {
    if (*arg0 != arg1) {
        if (*arg0 < arg1) {
            *arg0 += delta;
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        } else {
            *arg0 -= delta;
            if (*arg0 < arg1) {
                *arg0 = arg1;
            }
        }
    }
}

// ESA: func_8006309C
void func_802DBA58_6ED108(u8 arg0, Animal *animal) {
    if (arg0 == ATTACK_STATE_LUNGE_FWD) {
        if (((animal->heading > 32) && (animal->heading < 92)) ||
            ((animal->heading > 160) && (animal->heading < 224))) {
            arg0 = ATTACK_STATE_LUNGE_FWD;
        } else {
            arg0 = ATTACK_STATE_LUNGE_BACK;
        }
    } else if (arg0 == ATTACK_STATE_LUNGE_BACK) {
        if (((animal->heading > 32) && (animal->heading < 92)) ||
            ((animal->heading > 160) && (animal->heading < 224))) {
            arg0 = ATTACK_STATE_LUNGE_BACK;
        } else {
            arg0 = ATTACK_STATE_LUNGE_FWD;
        }
    }
    if (animal->attackState != arg0) {
        if (animal->attackState == ATTACK_STATE_NONE) {
            func_802DBB64_6ED214(&animal->attackState, &animal->attackTimer, arg0);
        } else if (arg0 > animal->attackState) {
            func_802DBB64_6ED214(&animal->attackState, &animal->attackTimer, arg0);
        }
    } else if (arg0 == ATTACK_STATE_STUMBLE) {
        func_802DBB64_6ED214(&animal->attackState, &animal->attackTimer, arg0);
    }
}

// ESA: func_80063164
void func_802DBB64_6ED214(u8 *attackState, u16 *attackTimer, u16 arg2) {
    *attackState = arg2;
    *attackTimer = gGameplayTick;
}
