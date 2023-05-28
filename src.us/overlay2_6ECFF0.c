#include <ultra64.h>
#include "common.h"


// ESA: func_80062F98
void func_802DB940_6ECFF0(s16 *arg0, s16 arg1, u16 arg2) {
    if (*arg0 != arg1) {
        s16 tmp = arg1 - *arg0;
        if (tmp < 0) {
            tmp += 256;
        }
        if (tmp < 128) {
            *arg0 += arg2;
            if ((tmp - arg2) < 0) {
                *arg0 = arg1;
            }
            if (*arg0 >= 256) {
                *arg0 -= 256;
            }
        } else {
            *arg0 -= arg2;
            if ((tmp + arg2) > 256) {
                *arg0 = arg1;
            }
            if (*arg0 < 0) {
                *arg0 += 256;
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

    if (arg0 == 8) { // xVelocity related
        if (((animal->unk302 > 32) && (animal->unk302 < 92)) ||
            ((animal->unk302 > 160) && (animal->unk302 < 224))) {
            arg0 = 8;
        } else {
            arg0 = 9;
        }
    } else if (arg0 == 9) { // zVelocity related
        if (((animal->unk302 > 32) && (animal->unk302 < 92)) ||
            ((animal->unk302 > 160) && (animal->unk302 < 224))) {
            arg0 = 9;
        } else {
            arg0 = 8;
        }
    }
    if (animal->unk364 != arg0) {
        if (animal->unk364 == 0) {
            func_802DBB64_6ED214(&animal->unk364, &animal->unk334, arg0);
        } else if (arg0 > animal->unk364) {
            func_802DBB64_6ED214(&animal->unk364, &animal->unk334, arg0);
        }
    } else if (arg0 == 6) {
        func_802DBB64_6ED214(&animal->unk364, &animal->unk334, arg0);
    }
}

// ESA: func_80063164
void func_802DBB64_6ED214(u8 *arg0, u16 *arg1, u16 arg2) {
    *arg0 = arg2;
    *arg1 = D_803D5544;
}
