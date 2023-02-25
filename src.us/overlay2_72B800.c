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


#if 0
// no real idea whats going on here...
void func_8031A4E0_72BB90(void) {
    s16 x0;
    s16 y0; // sp4C
    s16 z0; // sp4A
    s16 x1; // sp48
    s16 y1; // sp46
    s16 z1; // sp44
    s16 x2;
    s16 y2;
    s16 z2;

    s16 i;

    s16 startX0;
    s16 startX1;
    s16 startY0;
    s16 startY1;
    s16 startZ0;
    s16 startZ1;

    s32 temp_s2;
    s32 temp_s4;
    s32 temp_s5;

    u8 temp_s7;
    Vtx *vtxs;

    vtxs = &D_80204278->unk39C88[D_80204278->unk3B308];
    D_80204278->unk3B30A[D_803E97C0] = 8;


    D_80204278->unk3B308 += 8;

    if (D_803E97C8.unkE < D_803E97C8.unk16) {
        startX0 = D_803E97C8.unkE;
        startX1 = D_803E97C8.unk14;
    } else {
        startX1 = D_803E97C8.unkE;
        startX0 = D_803E97C8.unk14;
    }

    if (D_803E97C8.unk10 < D_803E97C8.unk16) {
        startY0 = D_803E97C8.unk10;
        startY1 = D_803E97C8.unk16;
    } else {
        startY1 = D_803E97C8.unk10;
        startY0 = D_803E97C8.unk16;
    }

    if (D_803E97C8.unk12 < D_803E97C8.unk18) {
        startZ1 = D_803E97C8.unk12;
        startZ0 = D_803E97C8.unk18;
    } else {
        startZ0 = D_803E97C8.unk12;
        startZ1 = D_803E97C8.unk18;
    }

    vtxs[0].v.ob[0] = startX0;
    vtxs[0].v.ob[1] = startY0;
    vtxs[0].v.ob[2] = startZ0;

    vtxs[1].v.ob[0] = startX1;
    vtxs[1].v.ob[1] = startY0;
    vtxs[1].v.ob[2] = startZ0;

    vtxs[2].v.ob[0] = startX1;
    vtxs[2].v.ob[1] = startY1;
    vtxs[2].v.ob[2] = startZ0;

    vtxs[3].v.ob[0] = startX0;
    vtxs[3].v.ob[1] = startY1;
    vtxs[3].v.ob[2] = startZ0;

    vtxs[4].v.ob[0] = startX0;
    vtxs[4].v.ob[1] = startY0;
    vtxs[4].v.ob[2] = startZ1;

    vtxs[5].v.ob[0] = startX1;
    vtxs[5].v.ob[1] = startY0;
    vtxs[5].v.ob[2] = startZ1;

    vtxs[6].v.ob[0] = startX1;
    vtxs[6].v.ob[1] = startY1;
    vtxs[6].v.ob[2] = startZ1;

    vtxs[7].v.ob[0] = startX0;
    vtxs[7].v.ob[1] = startY1;
    vtxs[7].v.ob[2] = startZ1;

    vtxs += 8;

    x0 = D_803E97C8.unkE;
    y0 = D_803E97C8.unk10;
    z0 = D_803E97C8.unk12 + 4;

    x1 = D_803E97C8.unkE;
    y1 = D_803E97C8.unk10;
    z1 = D_803E97C8.unk12 - 4;


    for (i = 1; i <= D_803E97C8.unkC; i++) {

        if (i == D_803E97C8.unkC) {
            // final iteration
            x2 = D_803E97C8.unk14;
            y2 = D_803E97C8.unk16;
            z2 = D_803E97C8.unk18;
        } else {
            temp_s4 = D_803E97C8.unkE  + ((((D_803E97C8.unk28 << 8) / D_803E97C8.unkC) * i) >> 8);
            temp_s5 = D_803E97C8.unk10 + ((((D_803E97C8.unk2C << 8) / D_803E97C8.unkC) * i) >> 8);
            temp_s2 = D_803E97C8.unk12 + ((((D_803E97C8.unk30 << 8) / D_803E97C8.unkC) * i) >> 8);
            temp_s7 = (D_803A5760_7B6E10 + (i * 0x10));
            y2 = (temp_s5 + SSSV_RAND(32)) - 16;
            x2 = (temp_s4 + SSSV_RAND(32)) - 16;
            z2 = (temp_s2 + SSSV_RAND(32)) - 8 + ((D_80152C78[(temp_s7 + 0x40) & 0xFF] * 8) >> 0xF);
        }

        // .. because.. of course whitespace affects regalloc
#pragma _permuter sameline start
        vtxs[0].v.ob[0] = x0; \
        vtxs[0].v.ob[1] = y0; \
        vtxs[0].v.ob[2] = z0 + 4; \
        vtxs[0].v.tc[0] = 0; \
        vtxs[0].v.tc[1] = 0; \
        vtxs[0].v.cn[0] = 0xFF; \
        vtxs[0].v.cn[1] = 0xFF; \
        vtxs[0].v.cn[2] = 0xFF;
#pragma _permuter sameline end

#pragma _permuter sameline start
        vtxs[1].v.ob[0] = x1; \
        vtxs[1].v.ob[1] = y1; \
        vtxs[1].v.ob[2] = z1 - 4; \
        vtxs[1].v.tc[0] = 0; \
        vtxs[1].v.tc[1] = 0x3FF; \
        vtxs[1].v.cn[0] = 0xFF; \
        vtxs[1].v.cn[1] = 0xFF; \
        vtxs[1].v.cn[2] = 0xFF;
#pragma _permuter sameline end

#pragma _permuter sameline start
        vtxs[2].v.ob[0] = x2; \
        vtxs[2].v.ob[1] = y2; \
        vtxs[2].v.ob[2] = z2 + 4 + 4; \
        vtxs[2].v.tc[0] = 0x7FF; \
        vtxs[2].v.tc[1] = 0; \
        vtxs[2].v.cn[0] = 0xFF; \
        vtxs[2].v.cn[1] = 0xFF; \
        vtxs[2].v.cn[2] = 0xFF;
#pragma _permuter sameline end


#pragma _permuter sameline start
        vtxs[3].v.ob[0] = x2; \
        vtxs[3].v.ob[1] = y2; \
        vtxs[3].v.ob[2] = z2 - 4 - 4; \
        vtxs[3].v.tc[0] = 0x7FF; \
        vtxs[3].v.tc[1] = 0x3FF; \
        vtxs[3].v.cn[0] = 0xFF; \
        vtxs[3].v.cn[1] = 0xFF; \
        vtxs[3].v.cn[2] = 0xFF;
#pragma _permuter sameline end

        D_80204278->unk3B30A[D_803E97C0] += 4;
        D_80204278->unk3B308 += 4;

        x0 = x2;
        y0 = y2;
        z0 = z2 + 4;

        x1 = x2;
        y1 = y2;
        z1 = z2 - 4;

        vtxs += 4;
    }

    D_803E97C0++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72B800/func_8031A4E0_72BB90.s")
#endif

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
