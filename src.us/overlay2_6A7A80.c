#include <ultra64.h>
#include "common.h"

// weird offsets
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802963D0_6A7A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80296544_6A7BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80296C8C_6A833C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_8029726C_6A891C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80297628_6A8CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802983D0_6A9A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802985AC_6A9C5C.s")

void func_8029877C_6A9E2C(void) {
    // maximum 64
    D_803C0430.unk204 += 1;
    D_803C0430.unk204 &= 0x3F;

    // maximum 255
    D_803C0430.unk200 += 64;
    if (D_803C0430.unk200 >= 256) {
        D_803C0430.unk200 &= 0xFF;
        D_803C0430.unk202 += 1;
        D_803C0430.unk202 &= 0xF;
    }

    D_803C0430.unk208 = 0;

    D_803C0430.unk206 += D_803C0430.unk20A;

    if (D_803C0430.unk206 == 240) {
        D_803C0430.unk20A = -8;
    }
    if (D_803C0430.unk206 == 0) {
        D_803C0430.unk20A = 8;
    }
    // maximum 31
    D_803C0430.unk20C += 1;
    D_803C0430.unk20C &= 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298818_6A9EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298B70_6AA220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298D44_6AA3F4.s")

s32 func_80298E08_6AA4B8(s16 arg0, s16 arg1) {
    // equivalent to dividing by 64
    arg0 >>= 6;
    arg1 >>= 6;

    if ((arg0 < D_803F2D50.unk10) ||
        (arg1 < D_803F2D50.unk12) ||
        ((D_803F2D50.unk10 + (u16)D_803F2D50.unk14) < arg0) ||
        ((D_803F2D50.unk12 + (u16)D_803F2D50.unk16) < arg1)) {
        return 0;
    }

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80298E98_6AA548.s")
// no ideas
#if 0
s16 func_80298E98_6AA548(s16 arg0, s16 arg1) {
    s16 sp1C;
    s32 temp_lo;
    u8 temp_a2;

    temp_a2 = D_803C0740[arg0 >> 6][arg1 >> 6].unk6;
    sp1C = temp_a2 * 4;
    if (func_80298E08_6AA4B8(arg0, arg1) != 0) {
        temp_lo = arg0 * arg1;
        return (s16) (sp1C + *(&D_803C0430 + ((temp_lo & 7) << 6) +
                              ((D_803C0430.unk204 + ((temp_lo + (arg0 * arg0)) * 8)) & 0x3F)));
    }
    return sp1C;
}
#endif

s16 func_80298F78_6AA628(s16 arg0, s16 arg1) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s16 temp_t4;
    s16 temp_t6;

    func_80299640_6AACF0(arg0 >> 6, arg1 >> 6, &sp36, &sp34, &sp32, &sp30);
    temp_t4 = arg0 & 0x3F;
    temp_t6 = arg1 & 0x3F;
    if ((temp_t4 + temp_t6) < 64) {
        return sp36 + ((((sp32 - sp36) * temp_t4) + ((sp34 - sp36) * temp_t6)) >> 6);
    } else {
        return sp30 + ((((sp34 - sp30) * (64 - temp_t4)) + ((sp32 - sp30) * (64 - temp_t6))) >> 6);
    }
}

// more of the same weirdness
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_802990A4_6AA754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299140_6AA7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6A7A80/func_80299640_6AACF0.s")
