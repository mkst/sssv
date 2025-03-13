#include <ultra64.h>
#include "common.h"

// ========================================================
// .rodata
// ========================================================

const LeftEyes D_803BD530_7CEBE0 = {
    {
        {1,  0,  2,  3,  4,  5,  6,  7, 11,  9, 10,  9,  9},  // D_803BD530_7CEBE0[0] is D_803BD530_7CEBE0 - (unused)
        {0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11},  // D_803BD530_7CEBE0[1] is D_803BD54A_7CEBFA - camel, cool_cod, dog, pirana, seagul, sheep, vulture
        {0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11},  // D_803BD530_7CEBE0[2] is D_803BD564_7CEC14 - hellirabbit
        {0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11},  // D_803BD530_7CEBE0[3] is D_803BD57E_7CEC2E - evo
        {0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11},  // D_803BD530_7CEBE0[4] is D_803BD598_7CEC48 - (unused)
        {0,  1,  2,  0,  0,  4,  6,  3,  5,  7,  6,  6,  8},  // D_803BD530_7CEBE0[5] is D_803BD5B2_7CEC62 - mouse, polar bear, elephant, husky, scorpion, fox, kangaroo
        {0,  1,  2,  3,  4, 12,  9,  7,  8, 10, 12, 10, 11},  // D_803BD530_7CEBE0[6] is D_803BD5CC_7CEC7C - hyena, hippo, gorilla, bear, lion
        {0,  1,  0,  2,  4,  3,  5,  6,  7, 11,  9, 10,  9},  // D_803BD530_7CEBE0[7] is D_803BD5E6_7CEC96 - (unused)
    },
};
const RightEyes D_803BD600_7CECB0 = {
    9,
    {
        {0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11}, // D_803BD600_7CECB0[0] is D_803BD602_7CECB2
        {0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11}, // D_803BD600_7CECB0[1] is D_803BD61C_7CECCC
        {0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11}, // D_803BD600_7CECB0[2] is D_803BD636_7CECE6
        {0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11}, // D_803BD600_7CECB0[3] is D_803BD66A_7CED1A
        {0,  1,  2,  0,  0,  4,  6,  3,  5,  7,  6,  6,  8}, // D_803BD600_7CECB0[4] is D_803BD684_7CED34
        {0,  1,  2,  4,  3, 12,  9,  7,  8, 10, 12, 10, 11}, // D_803BD600_7CECB0[5] is D_803BD69E_7CED4E
    },
};

// ========================================================
// .text
// ========================================================

void func_8031A150_72B800(s16 timer, s16 *leftEye, s16 *rightEye) {
    s16 temp_v1;

    // defaults
    *leftEye = 0;       // open
    *rightEye = 0;      // open

    // blink every 64 frames?
    if ((timer & 0x3F) >= 0x3A) {
        *leftEye = 5;   // closed
        *rightEye = 5;  // closed
    }
    // different blink effect every 1280 frames
    if (((timer & 0x4FF) >= 0x46A) ||
        ((timer & 0xFFF) >= 0xE0C)) {
        *leftEye = 7;
        *rightEye = 7;
    }
    temp_v1 = (timer & 0x2FF) - 737;
    if ((timer & 0x2FF) > 737) {
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
    temp_v1 = (timer & 0x3FF) - 960;
    if ((timer & 0x3FF) > 960) {
        if ((temp_v1 > 10) && (temp_v1 < 25)) {
            *leftEye = 3;
            *rightEye = 3;
        } else if ((temp_v1 > 40) && (temp_v1 < 55)) {
            *leftEye = 4;
            *rightEye = 4;
        } else {
            *leftEye = 0;
            *rightEye = 0;
        }
    }
}

// pick eye index?
void func_8031A278_72B928(s16 *timer, s16 *leftEye, s16 *rightEye) {
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
        if (*leftEye != 5) {
            *leftEye = 8;
        }
        if (*rightEye != 5) {
            *rightEye = 8;
        }
        // reset blink if in one of these states
        *timer &= 0x3F;
    }

    switch (D_803D552C->unk366) {
    case MOVEMENT_MODE_2:
    case MOVEMENT_MODE_DEACTIVATED:
        *leftEye = 5;   // closed?
        *rightEye = 5;  // closed?
        break;
    case MOVEMENT_MODE_CRITICAL:
        *leftEye = 9;   // pain?
        *rightEye = 9;  // pain?
        break;
    }
}
