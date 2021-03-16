#include <ultra64.h>
#include "common.h"


void func_80300130_7117E0(s16 *arg0, s16 *arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    if (*arg0 < 0) {
        *arg1 += -*arg0 >> arg4;
    } else {
        *arg1 -= *arg0 >> arg5;
    }
    if (arg7 < *arg1) {
        *arg1 -= 1;
    } else if (*arg1 < -arg7) {
        *arg1 += 1;
    }
    *arg0 += *arg1;
    if (*arg0 < arg3) {
        *arg0 = arg3;
        *arg1 = arg6;
    } else if (arg2 < *arg0) {
        *arg0 = arg2;
        *arg1 = arg6;
    }
}
