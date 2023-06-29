#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

u32 func_802E3C88_6F5338(struct051* arg0);

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

struct088 D_803DA300[1000];
struct051 D_803E00C0[120];
s16  D_803E1B00; // counter, max 1000
s16  D_803E1B02; // another counter, max 120
s16  D_803E1B04; // used vtx for dynamic tails?
s16  D_803E1B06;
s16  D_803E1B08;

// ========================================================
// .text
// ========================================================

// ESA: func_800849B8
void func_802DD040_6EE6F0(s32 arg0) {
    s16 i;
    for (i = 0; i < 120; i++) {
        D_803E00C0[i].tailType = 0;
    }
    D_803E1B00 = 0;
    D_803E1B02 = 1;
}

// ESA: func_800849EC
s16 func_802DD090_6EE740(s16 numSegments, s32 length, u8 arg2, s8 tailType, s8 arg4, s32 arg5, s32 arg6, s32 arg7, u8 arg8, u8 arg9, Animal *argA, Animal *argB, s16 argC, s16 argD, s16 argE, s16 argF, s16 arg10, s16 arg11) {
    u16 i;
    s32 res;

    if (((D_803E1B00 + numSegments) < 1000) && (D_803E1B02 < 120)) {
        D_803E00C0[D_803E1B02].numSegments = numSegments;
        D_803E00C0[D_803E1B02].unk16 = D_803E1B00;
        D_803E00C0[D_803E1B02].unk1C = ((numSegments + 1) * length) >> 0x10;
        D_803E00C0[D_803E1B02].tailType = tailType;
        D_803E00C0[D_803E1B02].unk2F = arg4;
        D_803E00C0[D_803E1B02].unk32 = arg8;
        D_803E00C0[D_803E1B02].unk33 = arg9;
        D_803E00C0[D_803E1B02].unk0 = argA;
        D_803E00C0[D_803E1B02].unk4 = argB;
        D_803E00C0[D_803E1B02].unk8 = argC;
        D_803E00C0[D_803E1B02].unkA = argD;
        D_803E00C0[D_803E1B02].unkC = argE;
        D_803E00C0[D_803E1B02].unk18 = length;
        D_803E00C0[D_803E1B02].unk20 = arg5;
        D_803E00C0[D_803E1B02].unk24 = arg6;
        D_803E00C0[D_803E1B02].unk28 = arg7;
        D_803E00C0[D_803E1B02].unkE = argF;
        D_803E00C0[D_803E1B02].unk10 = arg10;
        D_803E00C0[D_803E1B02].unk12 = arg11;
        D_803E00C0[D_803E1B02].unk2C = 0;
        D_803E00C0[D_803E1B02].unk34 = 1;

        for (i = 0; i < numSegments; i++) {
            D_803DA300[D_803E1B00 + i].unk0 = arg5;
            D_803DA300[D_803E1B00 + i].unk4 = arg6;
            D_803DA300[D_803E1B00 + i].unk8 = arg7;
            D_803DA300[D_803E1B00 + i].unkC = 0;
            D_803DA300[D_803E1B00 + i].unk10 = 0;
            D_803DA300[D_803E1B00 + i].unk14 = 0;

            if (arg2) {
                arg7 += length;
            } else {
                arg7 -= length;
            }
        }
        D_803E1B00 += numSegments;
        return D_803E1B02++;
    } else {
        return 0;
    }
}

// ESA: func_80084BE4
// used by kangaroo, husky, lion, elephant, mouse, scorpion and rat
void func_802DD244_6EE8F4(s16 arg0, struct118 *arg1) {
    struct051 *temp_s1;
    struct088 *var_t1;
    s16 i;

    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s2;
    s32 var_s7;
    s32 var_a0;

    temp_s1 = &D_803E00C0[arg0];
    var_t1 = &D_803DA300[temp_s1->unk16];

    var_s3 = temp_s1->unk20;
    var_s4 = temp_s1->unk24;
    var_s5 = temp_s1->unk28;

    // iterate over each segment
    for (i = 0; i < temp_s1->numSegments; i++) {

        var_t1[i].unk0 = var_s3; // startx?
        var_t1[i].unk4 = var_s4; // startz?
        var_t1[i].unk8 = var_s5; // starty?
        var_t1[i].unkC = 0;
        var_t1[i].unk10 = 0;
        var_t1[i].unk14 = 0;

        // whilst it's not the final segment
        if (i < (temp_s1->numSegments - 1)) {
            var_s6 = (( arg1[i+1].unk0 * (D_80152C78[(temp_s1->unk2C + 0x40) & 0xFF] >> 7)) + (arg1[i+1].unk4 * (D_80152C78[temp_s1->unk2C & 0xFF] >> 7))) >> 8;
            var_s2 = ((-arg1[i+1].unk0 * (D_80152C78[temp_s1->unk2C & 0xFF] >> 7)) + (arg1[i+1].unk4 * (D_80152C78[(temp_s1->unk2C + 0x40) & 0xFF] >> 7))) >> 8;
            var_s7 = arg1[i+1].unk8;

            var_a0 = sqrtf(SQ((f32)var_s6) + SQ((f32)var_s2) + SQ((f32)var_s7));
            if (var_a0 < FTOFIX32(0.0625)) {
                var_s2 = FTOFIX32(1.0);
                var_a0 = FTOFIX32(1.0);
            }
        }

        var_s3 += (var_s6 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
        var_s4 += (var_s2 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
        var_s5 += (var_s7 * (temp_s1->unk18 >> 8)) / (var_a0 >> 8);
    }
}

#if 0
// miles away
// ESA: func_80084E58
void func_802DD548_6EEBF8(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3) {

    Animal *temp_v0;
    f32 temp_f0_2;
    s16 temp_a0;
    s16 i;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_t6;
    s32 temp_t8_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_t4;

    struct051 *temp_fp;
    struct088 *var_t5;

    if (D_803F2D10.unk0 == 0) {
        temp_fp = &D_803E00C0[arg0];
        var_t5 = &D_803DA300[temp_fp->unk16];

        if (temp_fp->unk4 != NULL) {
            temp_fp->unk20 = temp_fp->unk4->xPos.w + (temp_fp->unkE << 0x10);
            temp_fp->unk24 = temp_fp->unk4->zPos.w + (temp_fp->unk10 << 0x10);
            temp_fp->unk28 = temp_fp->unk4->yPos.w + (temp_fp->unk12 << 0x10);
        }
        var_t5->unk0 = temp_fp->unk20;
        var_t5->unk4 = temp_fp->unk24;
        var_t5->unk8 = temp_fp->unk28;

        if (arg3 == 1) {
            var_t4 = MAX(temp_fp->unk28, ((D_803C0740[temp_fp->unk20 >> 0x16][temp_fp->unk24 >> 0x16].unk6 * 4) - 0x20) << 0x10);
        }

        var_s5 = temp_fp->unk20;
        var_s6 = temp_fp->unk24;
        var_s7 = temp_fp->unk28;

        for (i = 1; i < temp_fp->numSegments; i++) {

            temp_s2 = var_s5 - (var_t5[i].unk0 + ((var_t5[i].unkC  * arg2) / 256) + (((arg1[i].unk0 * (D_80152C78[(temp_fp->unk2C + 0x40) & 0xFF] >> 7)) + (arg1[i].unk4 * (D_80152C78[temp_fp->unk2C & 0xFF] >> 7))) >> 8));
            temp_s3 = var_s6 - (var_t5[i].unk4 + ((var_t5[i].unk10 * arg2) / 256) + (((arg1[i].unk4 * (D_80152C78[(temp_fp->unk2C + 0x40) & 0xFF] >> 7)) - (arg1[i].unk0 * (D_80152C78[temp_fp->unk2C & 0xFF] >> 7))) >> 8));

            var_a2 = arg1[i].unk8 + var_t5[i].unk8 + ((var_t5[i].unk14 * arg2) / 256);
            if ((arg3 == 1) && (var_t4 < var_a2)) {
                var_a2 = var_t4;
            }
            temp_s4 = var_s7 - var_a2;

            temp_f0_2 = sqrtf(SQ((f32)temp_s2) + SQ((f32)temp_s3) + SQ((f32)temp_s4));
            if (temp_f0_2 != 0.0f) {
                var_a1 = temp_fp->unk18 / (s32) (temp_f0_2 / 1024.0);
            } else {
                var_a1 = 1;
            }
            var_s5 = var_s5 - ((temp_s2 * var_a1) >> 0xA);
            var_s6 = var_s6 - ((temp_s3 * var_a1) >> 0xA);
            var_s7 = var_s7 - ((temp_s4 * var_a1) >> 0xA);

            var_t5[i].unkC  = var_s5 - var_t5[i].unk0;
            var_t5[i].unk10 = var_s6 - var_t5[i].unk4;
            var_t5[i].unk14 = var_s7 - var_t5[i].unk8;

            var_t5[i].unk0 = var_s5;
            var_t5[i].unk4 = var_s6;
            var_t5[i].unk8 = var_s7;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/dynamic_tail/func_802DD548_6EEBF8.s")
#endif

#if 0
// ESA: func_80085274 (TBD)
// long way away
void func_802DD994_6EF044(s16 arg0, struct118 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 sp1E6;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    // padding?
    f32 sp194;
    f32 sp190;
    f32 sp18C;
    // padding ? // sp170;
    s32 sp130[16];
    s32 spF0[16];
    s32 spB0[16];

    f32 sp88;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;

    f32 temp_f2;
    f32 var_f12;
    f32 var_f14;
    f32 var_f16;
    f32 var_f2;
    f32 temp_f0_10;
    f64 var_f12_2;

    s16 i;
    s16 var_s1;

    s32 temp_s2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_t0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;

    struct051 *temp_v0;
    struct088 *var_t5;

    temp_v0 = &D_803E00C0[arg0];
    var_t5 = &D_803DA300[temp_v0->unk16];

    if (temp_v0->unk4 != NULL) {
        temp_v0->unk20 = temp_v0->unk4->xPos.w + (temp_v0->unkE << 0x10);
        temp_v0->unk24 = temp_v0->unk4->zPos.w + (temp_v0->unk10 << 0x10);
        temp_v0->unk28 = temp_v0->unk4->yPos.w + (temp_v0->unk12 << 0x10);
    }

    var_t5->unk0 = temp_v0->unk20;
    var_t5->unk4 = temp_v0->unk24;
    var_t5->unk8 = temp_v0->unk28;

    var_s2 = temp_v0->unk20;
    var_s3 = temp_v0->unk24;
    var_s4 = temp_v0->unk28;

    for (i = 1; i < arg4; i++) {
        s32 a = var_t5[i].unk0;
        s32 b = var_t5[i].unk4;
        s32 c = var_t5[i].unk8;

        sp130[i] = a; //  var_t5[i].unk0;
        spF0[i]  = b; // var_t5[i].unk4;
        spB0[i]  = c; // var_t5[i].unk8;

        temp_s5 = var_s2 - ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[i].unk4) + (arg1[i].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + a + ((var_t5[i].unkC * arg2) / 256));
        temp_s6 = var_s3 - ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[i].unk4) + (-arg1[i].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + b + ((var_t5[i].unk10 * arg2) / 256));
        temp_s7 = var_s4 - (arg1[i].unk8 + c + ((var_t5[i].unk14 * arg2) / 256));

        temp_f0 = sqrtf(SQ((f32)temp_s5) + SQ((f32)temp_s6) + SQ((f32)temp_s7));
        if (temp_f0 != 0.0f) {
            var_v1 = temp_v0->unk18 / (s32) (temp_f0 / 1024.0);
        } else {
            var_v1 = 1;
        }

        var_s2 -= (temp_s5 * var_v1) >> 0xA;
        var_s3 -= (temp_s6 * var_v1) >> 0xA;
        var_s4 -= (temp_s7 * var_v1) >> 0xA;

        var_t5[i].unkC = var_s2 - var_t5[i].unk0;
        var_t5[i].unk10 = var_s3 - var_t5[i].unk4;
        var_t5[i].unk14 = var_s4 - var_t5[i].unk8;

        var_t5[i].unk0 = var_s2;
        var_t5[i].unk4 = var_s3;
        var_t5[i].unk8 = var_s4;
    }

    if (temp_v0->unk32 & 2) {
        if (temp_v0->unk32 & 1) {
            var_t5[arg4].unk10 = (var_t5[arg4].unk10 * 0xF) >> 4;
        } else {
            var_t5[arg4].unkC = (var_t5[arg4].unkC * 0xF) >> 4;
        }
    }

    sp194 = ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[arg4].unk4) + ( arg1[arg4].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + var_t5[arg4].unk0 + ((var_t5[arg4].unkC * arg3) / 256));
    sp190 = ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[arg4].unk4) + (-arg1[arg4].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + var_t5[arg4].unk4 + ((var_t5[arg4].unk10 * arg3) / 256));
    sp18C = arg1[arg4].unk8 + var_t5[arg4].unk8 + ((var_t5[arg4].unk14 * arg3) / 256);

    sp1B8 = sp194 - temp_v0->unk20;
    sp1B4 = sp190 - temp_v0->unk24;
    sp1B0 = sp18C - temp_v0->unk28;

    temp_f0 = sqrtf(SQ(sp1B8) + SQ(sp1B4) + SQ(sp1B0));
    if ((arg4 * temp_v0->unk18) < temp_f0) {
        sp194 = temp_v0->unk20 + (sp1B8 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp190 = temp_v0->unk24 + (sp1B4 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp18C = temp_v0->unk28 + (sp1B0 * ((arg4 * temp_v0->unk18) / temp_f0));
        sp1E6 = 1;
    } else {
        sp1E6 = 0;
    }

    var_s2 = sp194;
    var_s3 = sp190;
    var_s4 = sp18C;

    var_t5[arg4].unkC = var_s2 - (f32) var_t5[arg4].unk0;
    var_t5[arg4].unk10 = var_s3 - (f32) var_t5[arg4].unk4;
    var_t5[arg4].unk14 = var_s4 - (f32) var_t5[arg4].unk8;

    var_t5[arg4].unk0 = var_s2;
    var_t5[arg4].unk4 = var_s3;
    var_t5[arg4].unk8 = var_s4;


    for (i = arg4 + 1; i < temp_v0->numSegments; i++) {
        s32 a = var_t5[i].unk0;
        s32 b = var_t5[i].unk4;
        s32 c = var_t5[i].unk8;

        temp_s5 = var_s2 - ((((D_80152C78[temp_v0->unk2C & 0xFF] * arg1[i].unk4) + ( arg1[i].unk0 * D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF])) >> 0xF) + a + ((var_t5[i].unkC * arg2) / 256));
        temp_s6 = var_s3 - ((((D_80152C78[(temp_v0->unk2C + 0x40) & 0xFF] * arg1[i].unk4) + (-arg1[i].unk0 * D_80152C78[temp_v0->unk2C & 0xFF])) >> 0xF) + b + ((var_t5[i].unk10 * arg2) / 256));
        temp_s7 = var_s4 - (arg1[i].unk8 + c + ((var_t5[i].unk14 * arg2) / 256));

        temp_f2 = sqrtf(SQ((f32)temp_s5) + SQ((f32)temp_s6) + SQ((f32)temp_s7));
        if (temp_f2 != 0.0) {
            var_v1 = temp_v0->unk18 / (s32) (temp_f2 / 1024.0);
        } else {
            var_v1 = 1;
        }

        var_s2 -= (temp_s5 * var_v1) >> 0xA;
        var_s3 -= (temp_s6 * var_v1) >> 0xA;
        var_s4 -= (temp_s7 * var_v1) >> 0xA;

        var_t5[i].unkC = var_s2 - var_t5[i].unk0;
        var_t5[i].unk10 = var_s3 - var_t5[i].unk4;
        var_t5[i].unk14 = var_s4 - var_t5[i].unk8;

        var_t5[i].unk0 = var_s2;
        var_t5[i].unk4 = var_s3;
        var_t5[i].unk8 = var_s4;
    }

    if (sp1E6 != 0) {
        var_s1 = 0;
    } else {
        for (var_s1 = arg4 - 1; var_s1 >= 0; var_s1--) {
            temp_f0 = var_t5[var_s1].unk0 - var_t5[arg4].unk0;
            temp_f2 = var_t5[var_s1].unk4 - var_t5[arg4].unk4;
            temp_f14 = var_t5[var_s1].unk8 - var_t5[arg4].unk8;
            if ((sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2) + (temp_f14 * temp_f14)) <= (f32) (temp_v0->unk18 * (arg4 - var_s1)))) {
                break;
            }
        }
    }

    temp_s2 = arg4 - var_s1;

    temp_f2 = var_t5[var_s1].unk0 - var_t5[arg4].unk0;
    temp_f14 = var_t5[var_s1].unk4 - var_t5[arg4].unk4;
    temp_f16 = var_t5[var_s1].unk8 - var_t5[arg4].unk8;

    var_f12 = sqrtf(SQ(temp_f2) + SQ(temp_f14) + SQ(temp_f16));
    if (var_f12 < 1.0) {
        var_f12 = 1.0;
    }

    if (var_f12 < temp_v0->unk18 * temp_s2) {
        var_f2 = temp_f2 / temp_s2;
        var_f14 = temp_f14 / temp_s2;
        var_f16 = temp_f16 / temp_s2;
    } else {
        var_f2 = (temp_v0->unk18 * temp_f2) / var_f12;
        var_f14 = (temp_v0->unk18 * temp_f14) / var_f12;
        var_f16 = (temp_v0->unk18 * temp_f16) / var_f12;
    }

    for (i = arg4 - 1; i > var_s1; i--) {
        var_t5[i].unk0 = var_t5[i+1].unk0 + var_f2;
        var_t5[i].unk4 = var_t5[i+1].unk4 + var_f14;
        var_t5[i].unk8 = var_t5[i+1].unk8 + var_f16;

        var_t5[i].unkC = var_t5[i].unk0 - sp130[i];
        var_t5[i].unk10 = var_t5[i].unk4 - spF0[i];
        var_t5[i].unk14 = var_t5[i].unk8 - spB0[i];
    }

    temp_f0_10 = (ABS(var_t5[arg4].unkC) + ABS(var_t5[arg4].unk10) + ABS(var_t5[arg4].unk14)) / 1310720.0;
    var_f12_2 = MIN(1.0, temp_f0_10 / 2.0);

    func_8032CD70_73E420(
        temp_v0,
        SFX_UNKNOWN_35,
        var_f12_2 * 28672.0,
        0,
        (temp_f0_10 / 1.5) + 0.7,
        var_t5[arg4].unk0 >> 0x10,
        var_t5[arg4].unk4 >> 0x10,
        var_t5[arg4].unk8 >> 0x10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/dynamic_tail/func_802DD994_6EF044.s")
#endif

// ESA: func_80086120
void func_802DE770_6EFE20(s16 arg0, s16 arg1, s32 xVelocity, s32 zVelocity, s32 yVelocity) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC += xVelocity;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 += zVelocity;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 += yVelocity;
}

void func_802DE7F4_6EFEA4(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 i;

    for (i = D_803E00C0[arg0].unk16; i < D_803E00C0[arg0].unk16 + D_803E00C0[arg0].numSegments; i++) {
        D_803DA300[i].unk0 += arg1;
        D_803DA300[i].unk4 += arg2;
        D_803DA300[i].unk8 += arg3;
    }
}

// ESA: func_800861AC
void func_802DE890_6EFF40(s16 arg0, s16 arg1, s32 xPos, s32 zPos, s32 yPos, s32 xVelocity, s32 zVelocity, s32 yVelocity) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk0 = xPos;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk4 = zPos;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk8 = yPos;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC = xVelocity;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 = zVelocity;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 = yVelocity;
}

// ESA: func_80086234
void func_802DE914_6EFFC4(s16 idx, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    struct051 *tmp = &D_803E00C0[idx];
    tmp->unk20 = arg1;
    tmp->unk24 = arg2;
    tmp->unk28 = arg3;
    tmp->unk2C = arg4;
}

#ifdef NON_MATCHING
void func_802DE950_6F0000(void) {
    s32 pad[2];
    s16 temp_s0_27;
    s16 i;
    s16 j;

    s32 temp_a2;

    s32 tmpX;
    s32 tmpZ;
    s32 tmpY;

    struct051 *temp_s2;
    struct118 *var_a3;
    u32 vtx;
    u8 temp_v0_2;

    gDPPipeSync(D_801D9E88++);
    gSPDisplayList(D_801D9E88++, D_01004270_3DB40);
    gDPSetCycleType(D_801D9E88++, G_CYC_2CYCLE);
    gSPTexture(D_801D9E88++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetRenderMode(D_801D9E88++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gSPClearGeometryMode(D_801D9E88++, -1);
    gSPSetGeometryMode(D_801D9E88++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_CLIPPING);
    gDPSetCombineLERP(D_801D9E88++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, TEXEL0);
    gDPSetAlphaCompare(D_801D9E88++, G_AC_THRESHOLD);
    gDPSetBlendColor(D_801D9E88++, 0x00, 0x00, 0x00, 0x00);

    for (i = 0; i < D_803E1B02; i++) {
        temp_s2 = &D_803E00C0[i];
        switch (temp_s2->tailType) {
        case 0:
            break;
        case 6:
            if (func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 + (temp_s2->unk1C << 0xF), 0xDAC, 0x64, 0, 0, 0, 1, 0) == 0) {
                if (temp_s2->unk34 == 1) {
                    func_802DD244_6EE8F4(i, D_803A3C9C_7B534C);
                }

                temp_s2->unk34 = 0;
                switch (temp_s2->unk31) {
                default:
                    var_a3 = D_803A3EDC_7B558C;
                    break;
                case 0:
                    var_a3 = D_803A3C9C_7B534C;
                    break;
                case 1:
                    var_a3 = D_803A3D5C_7B540C;
                    break;
                case 2:
                    var_a3 = D_803A3E1C_7B54CC;
                    break;
                }

                temp_v0_2 = D_803C0740[((temp_s2->unk20 >> 0x10) >> 6)][((temp_s2->unk24 >> 0x10) >> 6)].unk7;
                temp_a2 = ((1 - (((temp_v0_2 >> 4) & 8) >> 2)) * (((temp_v0_2 & 0xF0) >> 4) & 7)) << 0xB;

                for (j = 0; j < 8; j++) {
                    D_803A3F9C_7B564C[j].unk0 = var_a3[j].unk0 + temp_a2;
                    D_803A3F9C_7B564C[j].unk4 = var_a3[j].unk4 + temp_a2;
                    D_803A3F9C_7B564C[j].unk8 = var_a3[j].unk8;
                }

                func_802DD548_6EEBF8(i, D_803A3F9C_7B564C, 0xF0, 1);
                if (SSSV_RAND(64) == 0) {
                    temp_s2->unk31 = (temp_s2->unk31 + 1) % 4;
                }

                if ((D_803E1B04 + (temp_s2->numSegments * 2)) < 385) {
                    vtx = func_802E3C88_6F5338(temp_s2);

                    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.25f, 0.25f, 0.25f);
                    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    gSPVertex(D_801D9E88++, vtx, temp_s2->numSegments * 2, 0);

                    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

                    func_802E4F20_6F65D0(D_01036190);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x78, 0x8C, 0xDC, 0xFF);

                    gDPSetEnvColor(D_801D9E88++, 0x00, 0x14, 0x31, 0x00);
                    gSPTexture(D_801D9E88++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                    gSPDisplayList(D_801D9E88++, D_010379D8);
                    gSPDisplayList(D_801D9E88++, D_01037A00);

                    D_803E1B04 += temp_s2->numSegments * 2;
                }
            } else {
                temp_s2->unk34 = 1;
            }
            break;

        case 7:                                 /* switch 1 */
            if (func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 + (temp_s2->unk1C << 0xF), 0x1B58, 0x64, 0, 0, 0, 1, 0) == 0) {
                if (temp_s2->unk34 == 1) {
                    func_802DD244_6EE8F4(i, D_803A3D5C_7B540C);
                }

                temp_s2->unk34 = 0;
                switch (temp_s2->unk31) {            /* switch 4; irregular */
                default:                        /* switch 4 */
                    var_a3 = D_803A3EDC_7B558C;
                    break;
                case 0:                         /* switch 4 */
                    var_a3 = D_803A3C9C_7B534C;
                    break;
                case 1:                         /* switch 4 */
                    var_a3 = D_803A3D5C_7B540C;
                    break;
                case 2:                         /* switch 4 */
                    var_a3 = D_803A3E1C_7B54CC;
                    break;
                }

                temp_v0_2 = D_803C0740[((temp_s2->unk20 >> 0x10) >> 6)][((temp_s2->unk24 >> 0x10) >> 6)].unk7;
                temp_a2 = ((1 - (((temp_v0_2 >> 4) & 8) >> 2)) * (((temp_v0_2 & 0xF0) >> 4) & 7)) << 0xB;

                for (j = 0; j < 16; j++) {
                    D_803A3F9C_7B564C[j].unk0 = var_a3[j].unk0 + temp_a2;
                    D_803A3F9C_7B564C[j].unk4 = var_a3[j].unk4 + temp_a2;
                    D_803A3F9C_7B564C[j].unk8 = var_a3[j].unk8;
                }

                func_802DD548_6EEBF8(i, D_803A3F9C_7B564C, 0xE6, 1);
                if (SSSV_RAND(64) == 0) {
                    temp_s2->unk31 = (temp_s2->unk31 + 1) % 4;
                }
                if ((D_803E1B04 + (temp_s2->numSegments * 2)) < 385) {
                    vtx = func_802E3C88_6F5338(temp_s2);
                    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.25f, 0.25f, 0.25f);

                    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    gSPVertex(D_801D9E88++, vtx, temp_s2->numSegments * 2, 0);

                    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

                    func_802E4F20_6F65D0(D_01036190);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0x78, 0x8C, 0xDC, 0xFF);
                    gDPSetEnvColor(D_801D9E88++, 0x00, 0x14, 0x31, 0x00);

                    gSPTexture(D_801D9E88++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                    gSPDisplayList(D_801D9E88++, D_01037950);
                    gSPDisplayList(D_801D9E88++, D_01037998);
                    D_803E1B04 += (temp_s2->numSegments * 2);
                }
            } else {
                temp_s2->unk34 = 1;
            }
            break;
        case 19:                                /* switch 1 */
        case 20:                                /* switch 1 */
        case 21:                                /* switch 1 */
        case 22:                                /* switch 1 */
        case 23:                                /* switch 1 */
        case 24:                                /* switch 1 */
        case 25:                                /* switch 1 */
        case 26:                                /* switch 1 */
        case 27:                                /* switch 1 */
        case 28:                                /* switch 1 */
        case 29:                                /* switch 1 */
        case 30:                                /* switch 1 */
        case 36:                                /* switch 1 */
        case 37:                                /* switch 1 */
            if (((temp_s2->unk4 == NULL) && ((func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << (temp_s2->numSegments + 0x1F)), temp_s2->numSegments * 0x9C4, 0x64, 0, 0, 0, 1, 0) == 0) || (temp_s2->unk2F == 2))) ||
                ((temp_s2->unk4 != NULL) && ((func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << (temp_s2->numSegments + 0x1F)), temp_s2->numSegments * 0x7D0, 0x64, 0, 0, 0, 1, 0) == 0) ||
                                             (func_802E8BBC_6FA26C(temp_s2->unk4->xPos.w, temp_s2->unk4->zPos.w, temp_s2->unk4->yPos.w + (temp_s2->unk4->unk42 << 0xF), (s32) (temp_s2->unk4->unk16C->unk8E * temp_s2->unk4->unk40) >> 7, 0x64, 0, 0, 0, temp_s2->unk4->unk16C->unk8E, 0) != 4)))) {

                if (temp_s2->unk34 == 1) {
                    func_802DD244_6EE8F4(i, D_803A41DC_7B588C);
                }
                temp_s2->unk34 = 0;
                temp_s0_27 = (D_803D5542 + (temp_s2->unk33 * 2)) % 90;
                if ((temp_s2->unk32 & 1) == 0) {
                    if (temp_s0_27 < 45) {
                        func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, (s16) 0x40);
                    } else {
                        func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, (s16) 0xC0);
                    }
                } else if (temp_s0_27 < 45) {
                    func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, (s16) 0);
                } else {
                    func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, (s16) 0x80);
                }
                if (temp_s2->unk2F == 2) {
                    func_802DD994_6EF044(i, D_803A41DC_7B588C, 0xD2, 0xFF, (s16) (s32) temp_s2->unk30);
                } else if ((temp_s0_27 < 22) || ((temp_s0_27 > 45) && (temp_s0_27 < 67))) {
                    func_802DD548_6EEBF8(i, D_803A411C_7B57CC, 0xD7, 0);
                } else {
                    func_802DD548_6EEBF8(i, D_803A41DC_7B588C, 0xD7, 0);
                }

                if (temp_s2->unk0 != NULL) {

                    tmpX = D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk0 + (temp_s2->unk8 << 0x10);
                    tmpZ = D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk4 + (temp_s2->unkA << 0x10);
                    tmpY = D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk8 + (temp_s2->unkC << 0x10);

                    if (tmpX < 0x400000) {
                        tmpX = 0x400000;
                    }
                    if (tmpZ < 0x400000) {
                        tmpZ = 0x400000;
                    }
                    if (tmpX > 0x11FFFFFF) {
                        tmpX = 0x11FFFFFF;
                    }
                    if (tmpZ > 0x1FFFFFFF) {
                        tmpZ = 0x1FFFFFFF;
                    }
                    temp_s2->unk0->xVelocity.w = tmpX - temp_s2->unk0->xPos.w;
                    temp_s2->unk0->zVelocity.w = tmpZ - temp_s2->unk0->zPos.w;
                    temp_s2->unk0->yVelocity.w = tmpY - temp_s2->unk0->yPos.w;

                    temp_s2->unk0->unk4C.unk19 = 1;
                    temp_s2->unk0->yPos.w = tmpY;
                }

                func_8034C8F8_75DFA8(D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk0 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk4 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 1].unk8 >> 0x10, 0, D_01033190, 0xC, 0xC, 0x80, 0, 0, 0, 1, 0);
                func_8034C8F8_75DFA8(D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 2].unk0 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 2].unk4 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 2].unk8 >> 0x10, 0, D_01033190, 0xC, 0xC, 0x5A, 0, 0, 0, 0, 0);
                func_8034C8F8_75DFA8(D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 3].unk0 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 3].unk4 >> 0x10, D_803DA300[(temp_s2->unk16 + temp_s2->numSegments) - 3].unk8 >> 0x10, 0, D_01033190, 0xC, 0xC, 0x32, 0, 0, 0, 0, 0);

                if ((D_803E1B04 + (temp_s2->numSegments * 2)) < 385) {
                    vtx = func_802E3C88_6F5338(temp_s2);
                    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.25f, 0.25f, 0.25f);
                    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gSPVertex(D_801D9E88++, vtx, temp_s2->numSegments * 2, 0);

                    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

                    switch (temp_s2->tailType) {          /* switch 2 */
                    case 19:                    /* switch 2 */
                    case 22:                    /* switch 2 */
                    case 25:                    /* switch 2 */
                    case 28:                    /* switch 2 */
                        func_802E4F20_6F65D0(D_01036190);
                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0x52, 0xDC, 0x63, 0xFF);
                        gDPSetEnvColor(D_801D9E88++, 0x00, 0x31, 0x00, 0x00);
                        break;
                    case 20:                    /* switch 2 */
                    case 23:                    /* switch 2 */
                    case 26:                    /* switch 2 */
                    case 29:                    /* switch 2 */
                        func_802E4F20_6F65D0(D_01035990);
                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x9C, 0x31, 0xFF);
                        gDPSetEnvColor(D_801D9E88++, 0x31, 0x08, 0x00, 0x00);
                        break;
                    case 21:                    /* switch 2 */
                    case 24:                    /* switch 2 */
                    case 27:                    /* switch 2 */
                    case 30:                    /* switch 2 */
                        func_802E4F20_6F65D0(D_01035190);
                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                        gDPSetEnvColor(D_801D9E88++, 0x00, 0x00, 0x00, 0x00);
                        break;
                    case 36:                    /* switch 2 */
                    case 37:                    /* switch 2 */
                        func_802E4F20_6F65D0(D_0102BA10);
                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0xD7, 0xD7, 0xFF, 0xFF);
                        gDPSetEnvColor(D_801D9E88++, 0x89, 0x65, 0xB4, 0x00);
                        break;
                    }
                    gSPTexture(D_801D9E88++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                    if (temp_s2->numSegments == 0x10) {
                        gSPDisplayList(D_801D9E88++, D_01037950);
                    } else {
                        gSPDisplayList(D_801D9E88++, D_010379D8);
                    }
                    if (temp_s2->numSegments == 0x10) {
                        gSPDisplayList(D_801D9E88++, D_01037998);
                    } else {
                        gSPDisplayList(D_801D9E88++, D_01037A00);
                    }
                    D_803E1B04 += (temp_s2->numSegments * 2);
                }
            } else {
                temp_s2->unk34 = 1;
            }
            break;

        case 8:                                 /* switch 1 */
            if (((temp_s2->unk4 == NULL) &&  (func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << (temp_s2->numSegments + 0x1F)), temp_s2->numSegments * 0x7D0, 0x64, 0, 0, 0, 1, 0) == 0)) ||
                ((temp_s2->unk4 != NULL) && ((func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << (temp_s2->numSegments + 0x1F)), temp_s2->numSegments * 0x7D0, 0x64, 0, 0, 0, 1, 0) == 0) ||
                                             (func_802E8BBC_6FA26C(temp_s2->unk4->xPos.w, temp_s2->unk4->zPos.w, temp_s2->unk4->yPos.w + (temp_s2->unk4->unk42 << 0xF), (temp_s2->unk4->unk16C->unk8E * temp_s2->unk4->unk40) >> 7,  0x64, 0, 0, 0, temp_s2->unk4->unk16C->unk8E, 0) != 4)))) {

                if (temp_s2->unk34 == 1) {
                    func_802DD244_6EE8F4(i, D_803A41DC_7B588C);
                }
                func_802DD548_6EEBF8(i, D_803A429C_7B594C, 0xAA, 0);

                if (temp_s2->unk0 != NULL) {
                    tmpX = D_803DA300[temp_s2->unk16+15].unk0 + (temp_s2->unk8 << 0x10);
                    tmpZ = D_803DA300[temp_s2->unk16+15].unk4 + (temp_s2->unkA << 0x10);
                    tmpY = D_803DA300[temp_s2->unk16+15].unk8 + (temp_s2->unkC << 0x10);

                    if (tmpX < 0x400000) {
                        tmpX = 0x400000;
                    }
                    if (tmpZ < 0x400000) {
                        tmpZ = 0x400000;
                    }
                    if (tmpX > 0x11FFFFFF) {
                        tmpX = 0x11FFFFFF;
                    }
                    if (tmpZ > 0x1FFFFFFF) {
                        tmpZ = 0x1FFFFFFF;
                    }
                    temp_s2->unk0->xVelocity.w = tmpX - temp_s2->unk0->xPos.w;
                    temp_s2->unk0->zVelocity.w = tmpZ - temp_s2->unk0->zPos.w;
                    temp_s2->unk0->yVelocity.w = tmpY - temp_s2->unk0->yPos.w;
                    temp_s2->unk0->unk4C.unk19 = 1;
                }
                if ((D_803E1B04 + (temp_s2->numSegments * 2)) < 0x181) {
                    vtx = func_802E3C88_6F5338(temp_s2);

                    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], 0.25f, 0.25f, 0.25f);
                    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                    gSPVertex(D_801D9E88++, vtx, temp_s2->numSegments * 2, 0);

                    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);

                    func_802E4F20_6F65D0(D_01035190);

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    gDPSetEnvColor(D_801D9E88++, 0x00, 0x00, 0x00, 0x00);

                    gSPTexture(D_801D9E88++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                    gSPDisplayList(D_801D9E88++, D_01037950);
                    gSPDisplayList(D_801D9E88++, D_01037998);
                    D_803E1B04 += temp_s2->numSegments * 2;
                }
            } else {
                temp_s2->unk34 = 1;
            }
            break;
        case 9:
            if (func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << 0xF), 0xBB8, 0x64, 0, 0, 0, 1, 0) != 4) {
                switch (temp_s2->unk31) {
                case 0:
                    func_802DD548_6EEBF8(i, D_803A435C_7B5A0C, 0xF5, 0);
                    break;
                case 1:
                    func_802DD548_6EEBF8(i, D_803A4398_7B5A48, 0xF5, 0);
                    break;
                case 2:
                    func_802DD548_6EEBF8(i, D_803A43D4_7B5A84, 0xF5, 0);
                    break;
                default:
                    func_802DD548_6EEBF8(i, D_803A4410_7B5AC0, 0xF5, 0);
                    break;
                }
                if (SSSV_RAND(8) == 0) {
                    temp_s2->unk31 = (temp_s2->unk31 + 1) % 4;
                }

                for (j = 0; j < 3; j++) {
                    func_8029CEF0_6AE5A0(D_803DA300[temp_s2->unk16+j].unk0, D_803DA300[temp_s2->unk16+j].unk4, D_803DA300[temp_s2->unk16+j].unk8, 0x200U, 3, &D_803D2E08, 0, 0xFF, 0xFF, 0xFF);
                }
                func_8029CEF0_6AE5A0(D_803DA300[temp_s2->unk16+j].unk0, D_803DA300[temp_s2->unk16+j].unk4, D_803DA300[temp_s2->unk16+j].unk8, 0x400U, 0x20, &D_803D2E08, 0, 0xFF, 0xFF, 0xFF);

                add_light_at_location(D_803DA300[temp_s2->unk16+3].unk0 >> 0x10, D_803DA300[temp_s2->unk16+3].unk4 >> 0x10, D_803DA300[temp_s2->unk16+3].unk8 >> 0x10, 0xFF, 0xFF, 0x96, 0);
                func_8012826C();
                func_8034C8F8_75DFA8(D_803DA300[temp_s2->unk16+3].unk0 >> 0x10, D_803DA300[temp_s2->unk16+3].unk4 >> 0x10, D_803DA300[temp_s2->unk16+3].unk8 >> 0x10, 0, D_01033190, 0x50, 0x50, 0x64, 0xFF, 0xFF, 0x80, 2, 0);
            } else {
                temp_s2->unk34 = 1;
            }
            break;
        case 10:                                /* switch 1 */
            if (func_802E8BBC_6FA26C(temp_s2->unk20, temp_s2->unk24, temp_s2->unk28 - (temp_s2->unk1C << 0xF), 0xBB8, 0x64, 0, 0, 0, 1, 0) != 4) {
                temp_s0_27 = (D_803D5542 + (temp_s2->unk33 * 2)) % 46;

                if ((temp_s2->unk32 & 1) == 0) {
                    if (temp_s0_27 < 23) {
                        func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, 0x40);
                    } else {
                        func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, 0xC0);
                    }
                } else if (temp_s0_27 < 23) {
                    func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, 0);
                } else {
                    func_802DE914_6EFFC4(i, temp_s2->unk20, temp_s2->unk24, temp_s2->unk28, 0x80);
                }
                if ((temp_s0_27 < 12) || ((temp_s0_27 > 23) && (temp_s0_27 < 35))) {
                    func_802DD548_6EEBF8(i, D_803A444C_7B5AFC, 0xEB, 0);
                } else {
                    func_802DD548_6EEBF8(i, D_803A4488_7B5B38, 0xEB, 0);
                }

                for (j = 0; j < 3; j++) {
                    func_8029CEF0_6AE5A0(D_803DA300[temp_s2->unk16+j].unk0, D_803DA300[temp_s2->unk16+j].unk4, D_803DA300[temp_s2->unk16+j].unk8, 0x200U, 3, &D_803D2E08, 0, 0xFF, 0xFF, 0xFF);
                }
                func_8029CEF0_6AE5A0(D_803DA300[temp_s2->unk16+j].unk0, D_803DA300[temp_s2->unk16+j].unk4, D_803DA300[temp_s2->unk16+j].unk8, 0x800U, 0x20, &D_803D2E08, 0, 0xFF, 0xFF, 0xFF);

                add_light_at_location(D_803DA300[temp_s2->unk16+3].unk0 >> 0x10, D_803DA300[temp_s2->unk16+3].unk4 >> 0x10, D_803DA300[temp_s2->unk16+3].unk8 >> 0x10, 0xFF, 0xFF, 0x96, 0);
                func_8012826C();

                func_8034C8F8_75DFA8(
                    ((D_803DA300[temp_s2->unk16+3].unk0 >> 0x10) * 5) - ((D_803DA300[temp_s2->unk16+2].unk0 >> 0x10) * 4),
                    ((D_803DA300[temp_s2->unk16+3].unk4 >> 0x10) * 5) - ((D_803DA300[temp_s2->unk16+2].unk4 >> 0x10) * 4),
                    D_803DA300[temp_s2->unk16+3].unk8 >> 0x10,
                    0,
                    D_01033190, 0x50, 0x50, 0x64, 0xFF, 0xFF, 0x80, 2, 0);
            } else {
                temp_s2->unk34 = 1;
            }
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/dynamic_tail/func_802DE950_6F0000.s")
#endif

// only called with 0 or 1
void func_802E072C_6F1DDC(s8 arg0) {
    s32 pad[2];
    struct051 *temp_s4;
    s16 i; // sp5A

    for (i = 0; i < D_803E1B02; i++) {
        temp_s4 = &D_803E00C0[i];
        if ((*(u8*)&arg0 == 0) || (((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk3C8.unk2 != 0)) && (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk3C8.unk2 == i))) {
            switch (temp_s4->tailType) {
            case 0:
                break;
            case 3:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3B4C_7B51FC, 0x96, 0);

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x8000, 0xC000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x8000, 0xA000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x8000, 0x8000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x8000, 0x6000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x8000, 0x4000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }

                break;
            case 4:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, &D_803A3BAC_7B525C, 0x96, 0);

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x8000, 0xC000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x8000, 0xA000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x8000, 0x8000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x8000, 0x6000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x8000, 0x4000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;
            case 32:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3B4C_7B51FC, 0x96, 0);

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x10000, 0x18000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x10000, 0x14000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x10000, 0x10000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x10000, 0xC000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x10000, 0x8000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;

            case 33:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3BAC_7B525C, 0x96, 0);
                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x10000, 0x18000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x10000, 0x14000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x10000, 0x10000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x10000, 0xC000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x10000, 0x8000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;

            case 34:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3C3C_7B52EC, 0x96, 0);
                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x99, 0x99, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x8000, 0xC000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x8000, 0xA000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x8000, 0x8000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x8000, 0x6000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x8000, 0x4000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006C00_CE630);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;
            case 11:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3990_7B5040, 0x96, 0);
                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xBE, 0xFF, 0xFF, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xD4, 0xFF, 0xFF, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;
            case 12:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3990_7B5040, 0x96, 0);

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, (((D_80152C78[(s16)(D_803D5540 * 0x10) & 0xFF] >> 7) >> 2) + 0x80), 0xFF, 0xFF, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }

                    gDPSetPrimColor(D_801D9E88++, 0, 0, (((D_80152C78[(s16)((D_803D5540 * 0x10) + 0x55) & 0xFF] >> 7) >> 2) + 0x80), 0xFF, 0xFF, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }

                    gDPSetPrimColor(D_801D9E88++, 0, 0, (((D_80152C78[(s16)((D_803D5540 * 0x10) + 0xAA) & 0xFF] >> 7) >> 2) + 0x80), 0xFF, 0xFF, 0xFF);
                    if (D_803D5540 & 8) {
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_04003930_E0EF0);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                    } else {
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x1199A, 0x1199A, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_040039C0_E0F80);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                    }
                }
                break;

            case 13:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3B1C_7B51CC, 0x96, 0);

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x8A, 0x47, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x33D7, 0x33D7, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003580_EAB30);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x33D7, 0x33D7, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04003640_EABF0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x33D7, 0x33D7, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_040036D0_EAC80);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;
            case 14:
            case 15:
                if (temp_s4->unk34 == 0) {
                    if (temp_s4->tailType == 0xE) {
                        func_802DD548_6EEBF8(i, D_803A3A74_7B5124, 0x82, 0);
                    } else {
                        func_802DD548_6EEBF8(i, D_803A3AC8_7B5178, 0x64, 0);
                    }

                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0x00, 0x00, 0xFF);

                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006050_ED600);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006050_ED600);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006050_ED600);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006050_ED600);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04006050_ED600);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+5].unk0, D_803DA300[temp_s4->unk16+5].unk4, D_803DA300[temp_s4->unk16+5].unk8, D_803DA300[temp_s4->unk16+6].unk0, D_803DA300[temp_s4->unk16+6].unk4, D_803DA300[temp_s4->unk16+6].unk8, 0x2852, 0x2852, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04005F70_ED520);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;

            case 16:
            case 17:
            case 18:
            case 31:
                if (temp_s4->unk34 == 0) {
                    switch (temp_s4->tailType) {        /* switch 1; irregular */
                    case 16:                    /* switch 1 */
                        func_802DD548_6EEBF8(i, D_803A39C0_7B5070, 0xA, 0);
                        break;
                    case 17:                    /* switch 1 */
                        func_802DD548_6EEBF8(i, D_803A39FC_7B50AC, 0xA, 0);
                        break;
                    case 18:                    /* switch 1 */
                        func_802DD548_6EEBF8(i, D_803A3A38_7B50E8, 0x14, 0);
                        break;
                    }
                    if (temp_s4->tailType != 0x1F) {
                        gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);

                        gDPSetPrimColor(D_801D9E88++, 0, 0, 0x94, 0x94, 0x94, 0xFF);
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x9CCC, 0x9CCC, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_04006200_F7260);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x7000, 0x7000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_04006200_F7260);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x5999, 0x5999, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_04006200_F7260);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                        if (func_80126FD4(D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, D_803DA300[temp_s4->unk16+4].unk0, D_803DA300[temp_s4->unk16+4].unk4, D_803DA300[temp_s4->unk16+4].unk8, 0x5999, 0x5999, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                            gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                            gSPDisplayList(D_801D9E88++, D_040062C0_F7320);
                            gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                        }
                    }
                }
                break;
            case 35:
                if (temp_s4->unk34 == 0) {
                    func_802DD548_6EEBF8(i, D_803A3C0C_7B52BC, 0x96, 0);
                    gSPDisplayList(D_801D9E88++, D_01003548_3CE18);
                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xFF, 0xDA, 0x1C, 0xFF);
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+0].unk0, D_803DA300[temp_s4->unk16+0].unk4, D_803DA300[temp_s4->unk16+0].unk8, D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, 0x10000, 0x10000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04000E70_F1ED0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+1].unk0, D_803DA300[temp_s4->unk16+1].unk4, D_803DA300[temp_s4->unk16+1].unk8, D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, 0x10000, 0x10000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04000E70_F1ED0);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }

                    gDPSetPrimColor(D_801D9E88++, 0, 0, 0xAA, 0x64, 0x1C, 0xFF);
                    if (func_80126FD4(D_803DA300[temp_s4->unk16+2].unk0, D_803DA300[temp_s4->unk16+2].unk4, D_803DA300[temp_s4->unk16+2].unk8, D_803DA300[temp_s4->unk16+3].unk0, D_803DA300[temp_s4->unk16+3].unk4, D_803DA300[temp_s4->unk16+3].unk8, 0x10000, 0x10000, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
                        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                        gSPDisplayList(D_801D9E88++, D_04000EF0_F1F50);
                        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
                    }
                }
                break;
            }
        }
    }
}

typedef struct {
  Vtx vtx1;
  Vtx vtx2;
} Vtx2;

#if 0
// ESA: func_80087738
// not quite there yet...
// CURRENT (1884)
u32 func_802E3C88_6F5338(struct051* arg0) {
    s32 x;
    s32 y;
    s32 z;

    s32 var_a0;

    s32 var_a3;
    s32 temp_fp;

    s32 var_s2;
    s32 var_s3;
    s32 var_s4;

    Vtx2 *vtx;
    s16 i;

    var_a3 = D_803F2C5C * 1024.0;
    temp_fp = D_803F2C60 * 1024.0;

    // start of next available Vtxs
    vtx = &D_80204278->unk31070[D_803E1B04];

    // iterate over each tail segment
    for (i = 0; i < arg0->numSegments; i++) {
        if (i == (arg0->numSegments - 1)) {
            // final pieceq
            var_s2 =  ((D_803DA300[arg0->unk16 + arg0->numSegments - 1].unk8 - D_803DA300[arg0->unk16 + arg0->numSegments - 2].unk8) >> 0x10) * temp_fp;
            var_s3 =  ((D_803DA300[arg0->unk16 + arg0->numSegments - 1].unk8 - D_803DA300[arg0->unk16 + arg0->numSegments - 2].unk8) >> 0x10) * -var_a3;
            var_s4 =  ((D_803DA300[arg0->unk16 + arg0->numSegments - 1].unk4 - D_803DA300[arg0->unk16 + arg0->numSegments - 2].unk4) >> 0x10) * var_a3;
            var_s4 -= (((D_803DA300[arg0->unk16+15].unk0 - D_803DA300[arg0->unk16 + arg0->numSegments - 2].unk0) * temp_fp) >> 0x10);
        } else {
            var_s2 =  ((D_803DA300[arg0->unk16 + i + 1].unk8 - D_803DA300[arg0->unk16 + i + 0].unk8) >> 0x10) * temp_fp;
            var_s3 =  ((D_803DA300[arg0->unk16 + i + 1].unk8 - D_803DA300[arg0->unk16 + i + 0].unk8) >> 0x10) * -var_a3;
            var_s4 =  (((D_803DA300[arg0->unk16 + i + 1].unk4 - D_803DA300[arg0->unk16 + i + 0].unk4) >> 0x10) * var_a3);
            var_s4 -= (((D_803DA300[arg0->unk16 + i + 1].unk0 - D_803DA300[arg0->unk16 + i + 0].unk0) * temp_fp) >> 0x10);
        }

        var_a0 = 2 * sqrtf(SQ((f32)var_s2) + SQ((f32)var_s3) + SQ((f32)var_s4));
        if (var_a0 == 0) {
            var_a0 = 2;
        }

        x = (var_s2 * (arg0->unk18 >> 0xE)) / var_a0;
        y = (var_s3 * (arg0->unk18 >> 0xE)) / var_a0;
        z = (var_s4 * (arg0->unk18 >> 0xE)) / var_a0;

        vtx[i].vtx1.n.ob[0] = (D_803DA300[arg0->unk16 + i].unk0 >> 0xE) + x;
        vtx[i].vtx1.n.ob[1] = (D_803DA300[arg0->unk16 + i].unk4 >> 0xE) + y;
        vtx[i].vtx1.n.ob[2] = (D_803DA300[arg0->unk16 + i].unk8 >> 0xE) + z;

        vtx[i].vtx1.n.tc[0] = 0;

        vtx[i].vtx1.n.n[0] = -1;
        vtx[i].vtx1.n.n[1] = -1;
        vtx[i].vtx1.n.n[2] = -1;
        vtx[i].vtx1.n.n[3] = 0xFF;

        vtx[i].vtx2.n.ob[0] = (D_803DA300[arg0->unk16 + i].unk0 >> 0xE) - x;
        vtx[i].vtx2.n.ob[1] = (D_803DA300[arg0->unk16 + i].unk4 >> 0xE) - y;
        vtx[i].vtx2.n.ob[2] = (D_803DA300[arg0->unk16 + i].unk8 >> 0xE) - z;

        vtx[i].vtx2.n.tc[0] = 0x7C0;

        vtx[i].vtx2.n.n[0] = -1;
        vtx[i].vtx2.n.n[1] = -1;
        vtx[i].vtx2.n.n[2] = -1;
        vtx[i].vtx2.n.n[3] = 0xFF;

        vtx[i].vtx1.n.tc[1] = ((i << 5) - 0x80) << 6;
        vtx[i].vtx2.n.tc[1] = ((i << 5) - 0x80) << 6;
    }
    return OS_K0_TO_PHYSICAL(vtx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/dynamic_tail/func_802E3C88_6F5338.s")
#endif

#if 0
// needs some love
// ESA: func_80087AD0
s32 func_802E414C_6F57FC(s16 arg0, s16 arg1, s16 arg2, s16 *arg3, s8 *arg4) {
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 var_f2;

    s16 temp_t9; // tmp var

    s16 temp_v0;

    s16 var_a0;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_s3;
    s16 var_s5;

    s16 i;
    s16 var_v1;

    s32 temp_f18;
    s32 temp_fp;
    s32 temp_lo_2;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_t7;

    struct051 *temp_s1;
    struct088 *temp_s4;

    if (D_803E1B06 > 0) {
        D_803E1B06--;
    } else {
        D_803E1B08 = -1;
    }

    for (i = 0; i < 120; i++) {

        if ((D_803E00C0[i].tailType != 0) && (D_803E00C0[i].unk2F == 1) && (i != D_803E1B08)) {

            temp_s1 = &D_803E00C0[i];

            var_a1 = ABS(arg0 - (temp_s1->unk20 >> 0x10));
            var_v1 = ABS(arg1 - (temp_s1->unk24 >> 0x10));
            var_a0 = ABS(arg2 - (temp_s1->unk28 >> 0x10));

            if ((var_a1 < temp_s1->unk1C) && (var_v1 < temp_s1->unk1C) && (var_a0 < temp_s1->unk1C)) {
                temp_s4 = &D_803DA300[temp_s1->unk16];
                var_a3 = (temp_s1->unk18 >> 0xA);

                for (var_a2 = 2; var_a2 < temp_s1->numSegments; var_a2++) {
                    var_a1 = ABS(arg0 - (temp_s4[var_a2].unk0 >> 0x10));
                    var_v1 = ABS(arg1 - (temp_s4[var_a2].unk4 >> 0x10));
                    var_a0 = ABS(arg2 - (temp_s4[var_a2].unk8 >> 0x10));

                    if (var_a1 < var_v1) {
                        // sameline for regalloc
                        temp_t9 = var_a1;var_a1 = var_v1;var_v1 = temp_t9;
                    }
                    if (var_v1 < var_a0) {
                        var_v1 = var_a0;
                    }
                    if (var_a1 < var_v1) {
                        // sameline for regalloc
                        temp_t9 = var_a1;var_a1 = var_v1;var_v1 = temp_t9;
                    }

                    temp_v0 = var_a1 + (var_v1 >> 1);
                    if (temp_v0 < var_a3) {
                        var_a3 = temp_v0;
                        var_s5 = var_a2;
                    }
                }

                if (var_a3 <= ((temp_s1->unk18 >> 0x11) + (temp_s1->unk18 >> 0x10))) {
                    *arg3 = i;
                    *arg4 = var_s5;

                    temp_s1->unk2F = 2;
                    temp_s1->unk30 = var_s5;
                    temp_s1->unk35 = 2;
                    func_802DE890_6EFF40(i, var_s5, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, D_803D5530->xVelocity.w, D_803D5530->zVelocity.w, D_803D5530->yVelocity.w);

                    temp_s6 = D_803DA300[temp_s1->unk16 + var_s5].unk0 - temp_s1->unk20;
                    temp_s7 = D_803DA300[temp_s1->unk16 + var_s5].unk4 - temp_s1->unk24;
                    temp_fp = D_803DA300[temp_s1->unk16 + var_s5].unk8 - temp_s1->unk28;

                    var_f2 = (f32)(s32)sqrtf(SQ((f32)temp_s6) + SQ((f32)temp_s7) + SQ((f32)temp_fp)) / 256.0;
                    if (((var_s5 * temp_s1->unk18) >> 8) < var_f2) {
                        temp_lo_2 = (var_s5 * temp_s1->unk18) / (s32) var_f2;
                        D_803DA300[temp_s1->unk16 + var_s5].unk0 = temp_s1->unk20 + (((temp_s6 >> 4) * temp_lo_2) >> 4);
                        D_803DA300[temp_s1->unk16 + var_s5].unk4 = temp_s1->unk24 + (((temp_s7 >> 4) * temp_lo_2) >> 4);
                        D_803DA300[temp_s1->unk16 + var_s5].unk8 = temp_s1->unk28 + (((temp_fp >> 4) * temp_lo_2) >> 4);
                    }

                    for (var_s3 = var_s5 - 1; var_s3 >= 0; var_s3--) {
                        temp_f0 = temp_s4[var_s3].unk0 - temp_s4[var_s5].unk0;
                        temp_f2 = temp_s4[var_s3].unk4 - temp_s4[var_s5].unk4;
                        temp_f14 = temp_s4[var_s3].unk8 - temp_s4[var_s5].unk8;

                        if ((temp_s1->unk18 * (var_s5 - var_s3)) <= sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14))) {
                            break;
                        }
                    }
                    temp_s6 = temp_s4[var_s3].unk0 - temp_s4[var_s5].unk0;
                    temp_s7 = temp_s4[var_s3].unk4 - temp_s4[var_s5].unk4;
                    temp_fp = temp_s4[var_s3].unk8 - temp_s4[var_s5].unk8;

                    var_f2 = sqrtf(SQ((f32)temp_s6) + SQ((f32)temp_s7) + SQ((f32)temp_fp));
                    if (var_f2 < 100000.0) {
                        var_f2 = 100000.0f;
                    }

                    temp_f18 = var_f2 / 16;
                    temp_t7 = temp_s1->unk18 >> 0xE;

                    for (var_v1 = var_s5 - 1; var_v1 > var_s3; var_v1--) {
                        temp_s4[var_v1].unk0 = temp_s4[var_v1+1].unk0 + ((temp_t7 * temp_s6) / temp_f18);
                        temp_s4[var_v1].unk4 = temp_s4[var_v1+1].unk4 + ((temp_t7 * temp_s7) / temp_f18);
                        temp_s4[var_v1].unk8 = temp_s4[var_v1+1].unk8 + ((temp_t7 * temp_fp) / temp_f18);

                        temp_s4[var_v1].unkC = 0;
                        temp_s4[var_v1].unk10 = 0;
                        temp_s4[var_v1].unk14 = 0;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/dynamic_tail/func_802E414C_6F57FC.s")
#endif

void func_802E497C_6F602C(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    struct088 *tmp;

    tmp = &D_803DA300[D_803E00C0[arg0].unk16];

    *arg1 = (tmp->unk0 - D_803D5530->xPos.w) >> 14;
    *arg2 = (tmp->unk4 - D_803D5530->zPos.w) >> 14;
    *arg3 = (tmp->unk8 - D_803D5530->yPos.w) >> 14;

    if ((ABS(*arg3) < 100) &&
        (ABS(*arg1) < 100) &&
        (ABS(*arg2) < 100)) {
        *arg3 = 100;
    }
}

// ESA: func_8008822C
void func_802E4A78_6F6128(s16 arg0) {
    D_803E00C0[arg0].unk2F = 1;
    D_803E1B06 = 15;
    D_803E1B08 = arg0;
}

// ESA: func_80088268
void func_802E4AB8_6F6168(void) {
    s16 i;
    for (i = 0; i < 120; i++) {
        if (D_803E00C0[i].unk2F == 2) {
            D_803E00C0[i].unk2F = 1;
        }
    }
}

// load_dynamic_tail
s32 func_802E4B0C_6F61BC(s16 animalId) {
    switch (animalId) {
    case MOUSE:
    case RACING_MOUSE:
    case MOUSE2:
    case HELI_MOUSE:
    case RAT:
        return func_802DD090_6EE740(6, FTOFIX32(3.125),    1,  3, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case KING_RAT:
        return func_802DD090_6EE740(6, FTOFIX32(6.25),     1, 32, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case HUSKY:
    case SKI_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875),    1, 11, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case CRAZY_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875),    1, 12, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case POGO_KANGAROO:
    case BOXING_KANGAROO:
        return func_802DD090_6EE740(4, FTOFIX32(15.0),     1, 13, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case SCORPION:
        return func_802DD090_6EE740(7, FTOFIX32(5.90625),  1, 14, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case ELEPHANT:
        return func_802DD090_6EE740(5, FTOFIX32(16.40625), 1, 16, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case LION:
        return func_802DD090_6EE740(4, FTOFIX32(15.625),   1, 35, 0, D_803D5530->xPos.w, D_803D5530->zPos.w, D_803D5530->yPos.w, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    default:
        return 0;
    }
}

// unload_dynamic_tail ?
void func_802E4EB4_6F6564(s16 arg0) {
    if (arg0 != 0) {
        D_803E00C0[arg0].tailType = 0;
    }
    if ((D_803E1B02 >= 2) && D_803E00C0[D_803E1B02 - 1].tailType == 0) {
        D_803E1B02--;
    }
}

void func_802E4F20_6F65D0(u8 *img) {
    gDPSetTextureImage(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, img);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(D_801D9E88++);
    gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}
