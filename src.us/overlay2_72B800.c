#include <ultra64.h>
#include "common.h"

// ========================================================
// .rodata
// ========================================================

// eyes lookup
const s16 D_803BD530_7CEBE0[13] = {
    1,  0,  2,  3,  4,  5,  6,  7, 11,  9, 10,  9,  9, // 0,
    };
const s16 D_803BD54A_7CEBFA[12] = {
    1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11,
    };

const s16 tbd[13] = {
    0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11, // 0,
};

const s16 D_803BD564_7CEC14[] = {
    1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11, 0,
    1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11, 0,
    1,  2,  0,  0,  4,  6,  3,  5,  7,  6,  6,  8, 0,
    1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11, 0,
    1,  0,  2,  4,  3,  5,  6,  7, 11,  9, 10,  9, 9, 0,
    1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11,
};

const s16 D_803BD602_7CECB2[] = {
    0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11, 0,
    1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11,  0,
    1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11,  0,
    1,  2,  0,  0,  4,  6,  3,  5,  7,  6,  6,  8,  0,
    1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11,  0,
};

// ========================================================
// .text
// ========================================================

void func_8031A150_72B800(s16 arg0, s16 *leftEye, s16 *rightEye) {
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_v0;
    s32 temp_v0_2;

    *leftEye = 0;
    *rightEye = 0;
    if ((arg0 & 0x3F) >= 0x3A) {
        *leftEye = 5;
        *rightEye = 5;
    }
    if (((arg0 & 0x4FF) >= 0x46A) ||
        ((arg0 & 0xFFF) >= 0xE0C)) {
        *leftEye = 7;
        *rightEye = 7;
    }
    temp_v0 = arg0 & 0x2FF; // 767
    temp_v1 = temp_v0 - 737;
    if (temp_v0 > 737) {
        if (temp_v1 < 7) {
            *leftEye = 1;
            *rightEye = 0;
        } else if (temp_v1 < 14) {
            *leftEye = 0;
            *rightEye = 1;
        } else if (temp_v1 < 21) {
            *leftEye = 2;
            *rightEye = 0;
        } else {
            *leftEye = 0;
            *rightEye = 2;
        }
    }
    temp_v0_2 = arg0 & 0x3FF;
    temp_v1_2 = temp_v0_2 - 960;
    if (temp_v0_2 > 960) {
        if ((temp_v1_2 > 10) && (temp_v1_2 < 25)) {
            *leftEye = 3;
            *rightEye = 3;
        } else if ((temp_v1_2 > 40) && (temp_v1_2 < 55)) {
            *leftEye = 4;
            *rightEye = 4;
        } else {
            *leftEye = 0;
            *rightEye = 0;
        }
    }
}

void func_8031A278_72B928(s16 *arg0, s16 *arg1, s16 *arg2) {
    switch (D_803D5530->state) {
    case 4:
    case 5:
    case 23:
    case 0x2A:
    case 0x69:
    case 0x6A:
    case 0x7A:
    case 0x8F:
    case 0xA2:
    case 0xB7:
    case 0xB8:
    case 0xCB:
    case 0xDD:
        if (*arg1 != 5) {
            *arg1 = 8;
        }
        if (*arg2 != 5) {
            *arg2 = 8;
        }
        *arg0 &= 0x3F;
    }

    switch (D_803D552C->unk366) {
    case 2:
    case 5:
        *arg1 = 5;
        *arg2 = 5;
        break;
    case 4:
        *arg1 = 9;
        *arg2 = 9;
        break;
    }
}
