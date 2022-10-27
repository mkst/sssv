#include <ultra64.h>
#include "common.h"

u16  D_803A5760_7B6E10 = 0;
// s16  D_803A5764_7B6E14 = 0;

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

void func_8031A150_72B800(s16 arg0, u16 *leftEye, u16 *rightEye) {
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

#ifdef NON_MATCHING
void func_8031A370_72BA20(void) {
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_t8;
    s16 i;

    struct058 *var_v0 = D_803E97C8.unk0;
    for (i = 1; i <= D_803E97C8.unkA; i++) {
        if ((i != D_803E97C8.unk4) || (D_803E97C8.unk8 == 0)) {
            temp_t4 = D_803E97C8.unkE + ((D_803E97C8.unk1C * ((i << 6) - 0x10)) >> 8);
            var_v0->unk4 = temp_t4;
            var_v0->unk10 = temp_t4;

            temp_t8 = D_803E97C8.unk10 + ((D_803E97C8.unk20 * ((i << 6) - 0x10)) >> 8);
            var_v0->unk8 = temp_t8;
            var_v0->unk14 = temp_t8;

            temp_t5 = (D_803E97C8.unk12 + ((D_803E97C8.unk24 * ((i << 6) - 0x10)) >> 8)) - 0x20;
            var_v0->unkC = temp_t5;
            var_v0->unk18 = temp_t5;

            var_v0->unkD0 = 0x1F;
            var_v0->unkC4 = 0;
            var_v0->unkC8 = 0;
            var_v0->unkCC = 0x200000;
        } else {
            temp_t4 = D_803E97C8.unk14 - ((D_803E97C8.unk1C * (D_803E97C8.unk8 + 0x10)) >> 8);
            var_v0->unk4 = temp_t4;
            var_v0->unk10 = temp_t4;

            temp_t8 = D_803E97C8.unk16 - ((D_803E97C8.unk20 * (D_803E97C8.unk8 + 0x10)) >> 8);
            var_v0->unk8 = temp_t8;
            var_v0->unk14 = temp_t8;

            temp_t5 = (D_803E97C8.unk18 - D_803E97C8.unk8) - ((D_803E97C8.unk24 * (D_803E97C8.unk8 + 0x10)) >> 8);
            var_v0->unkC = temp_t5;
            var_v0->unk18 = temp_t5;

            var_v0->unkD0 = D_803E97C8.unk8;
            var_v0->unkC4 = 0;
            var_v0->unkC8 = 0;
            var_v0->unkCC = (D_803E97C8.unk8 << 0x10);
        }
        var_v0 = var_v0->next;
    }
    D_803E97C8.unk0 = var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B800/func_8031A370_72BA20.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B800/func_8031A4E0_72BB90.s")

// used by object 28
void func_8031AA0C_72C0BC(struct058 *arg0) {
    struct058 *temp_v0;
    struct058 *var_v1;
    s16 i;

    if (arg0->unk24C != NULL) {
        temp_v0 = arg0->unk24C;

        D_803E97C8.unk28 = temp_v0->unk4 - arg0->unk4;
        D_803E97C8.unk2C = temp_v0->unk8 - arg0->unk8;
        D_803E97C8.unk30 = temp_v0->unkC - arg0->unkC;

        D_803E97C8.unk34 = ABS(D_803E97C8.unk28);
        D_803E97C8.unk38 = ABS(D_803E97C8.unk2C);
        D_803E97C8.unk3C = ABS(D_803E97C8.unk30);

        D_803E97C8.unk40 = (s16)sqrtf(
            ((D_803E97C8.unk28) * (D_803E97C8.unk28)) +
            ((D_803E97C8.unk2C) * (D_803E97C8.unk2C)) +
            ((D_803E97C8.unk30) * (D_803E97C8.unk30)));
            D_803E97C8.unkC = (D_803E97C8.unk40 >> 6) + 1;

            D_803E97C8.unk1C = (D_803E97C8.unk28 << 8) / D_803E97C8.unk40;
            D_803E97C8.unk20 = (D_803E97C8.unk2C << 8) / D_803E97C8.unk40;
            D_803E97C8.unk24 = (D_803E97C8.unk30 << 8) / D_803E97C8.unk40;

            D_803E97C8.unk4 = (D_803E97C8.unk40 - 34) >> 6;
            D_803E97C8.unk8 = (((D_803E97C8.unk40 - 34) & 0x3F) >> 1) - 1;

            if (D_803E97C8.unk4 == 0) {
                D_803E97C8.unk4 = 1;
                if (D_803E97C8.unk8 <= 0) {
                    D_803E97C8.unk8 = 1;
                }
            } else if ((D_803E97C8.unk8 < 0) ) {
                D_803E97C8.unk8 = 0;
            } else {
                D_803E97C8.unk4 += 1;
            }
            if (arg0->unk0 == 1) {
                D_803E97C8.unk6 = D_803E97C8.unk4;
            } else {
                D_803E97C8.unk6 = 0;
            }
            if (D_803E97C8.unkC >= 7) {
                for (var_v1 = arg0->next; arg0->unk152 > 0; var_v1 = var_v1->next, arg0->unk152--) {
                    var_v1->unk26C = 1;
                }
            } else {
                if (arg0->unk152 != D_803E97C8.unk6) {
                    if (arg0->unk152 < D_803E97C8.unk6) {
                        var_v1 = arg0;
                        for (i = arg0->unk152; i > 0; i--) {
                            var_v1 = var_v1->next;
                        }
                        do {
                            var_v1->next = (struct058 *)func_802C9564_6DAC14(31, 0, 0, 0, 0, 0, 0, 0, 0, 0x800);
                            var_v1 = var_v1->next;
                            arg0->unk152++;
                        } while (arg0->unk152 < D_803E97C8.unk6);
                    } else {
                        var_v1 = arg0;
                        for (i = 0; i <= D_803E97C8.unk6; i++) {
                            var_v1 = var_v1->next;
                        }
                        do {
                            var_v1->unk26C = 1;
                            var_v1 = var_v1->next;
                            arg0->unk152--;
                        } while (D_803E97C8.unk6 < arg0->unk152);

                    }
                }
            }
            if (arg0->unk152 > 0) {
                D_803E97C8.unk0 = arg0->next;

                D_803E97C8.unkE = arg0->unk4;
                D_803E97C8.unk10 = arg0->unk8;
                D_803E97C8.unk12 = arg0->unkC + (arg0->unk42 >> 1);

                D_803E97C8.unk14 = temp_v0->unk4;
                D_803E97C8.unk16 = temp_v0->unk8;
                D_803E97C8.unk18 = temp_v0->unkC + (arg0->unk42 >> 1);

                D_803E97C8.unkA = arg0->unk152;
                func_8031A370_72BA20();
                func_8031A4E0_72BB90();
            }
            if (arg0->unk0 == 1) { // enabled?
                func_8032CED0_73E580(
                    arg0,
                    SFX_UNKNOWN_115,
                    0x4000,
                    0.5f,
                    0,
                    0,
                    (temp_v0->unk4 + arg0->unk4) >> 1,
                    (temp_v0->unk8 + arg0->unk8) >> 1,
                    (temp_v0->unkC + arg0->unkC) >> 1,
                    0,
                    0,
                    0);
        }
    }
}

void func_8031AE7C_72C52C(Animal *arg0) {
    s16 i;

    static s16 D_803A5764_7B6E14 = 0;

    if (D_803A5764_7B6E14 > 0) {
        D_803A5764_7B6E14--;
    }
    if (arg0->unk5C & 8) {
        arg0->unk5C = 0;
        if (D_803A5764_7B6E14 <= 0) {
            D_803A5764_7B6E14 = (guRandom() & 0xF) + 0x3C;
            play_sound_effect_at_location(SFX_UNKNOWN_77, 0x6000, 0, arg0->xPos.h, arg0->zPos.h, arg0->yPos.h, 1.0f);
        }

        for (i = 0; i < 3; i++) {
            s32 temp_s1 = (SSSV_RAND(8) - 4) << 16;
            s32 temp_s2 = (SSSV_RAND(8) - 4) << 16;
            s32 temp_s3 = (SSSV_RAND(8) - 2) << 16;
            create_particle_effect(
                arg0->xPos.h,
                arg0->zPos.h,
                arg0->yPos.h,
                35,
                temp_s1,
                temp_s2,
                temp_s3,
                6,
                0,
                0,
                0);
        }
    }
}
