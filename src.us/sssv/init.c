#include <ultra64.h>

#include "common.h"


extern u8 D_803BE9F0[];
extern u8 D_803BEA38[];

extern u8 D_0007F790[];
extern u8 D_000398D0[];

extern u8 D_803BEA48[];
extern u8 D_803BEA78[];

extern u8 D_00546BC0[];
extern u8 D_005449C0[];

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80352280_763930.s")
// NON-MATCHING: 80% there..
// void func_80352280_763930(void) {
//     u32 len = D_0007F790 - D_000398D0;
//
//     if (len >= D_80099600 - D_8004B400) {
//         // "\nASSERT: len < (_gfxdlistSegmentEnd - _gfxdlistSegmentStart), %s, %u\n"
//         // "../src/init.c"
//         rmonPrintf(D_803BE9F0, D_803BEA38, 0x5D, len);
//         // die
//         *(volatile int*)0 = 0;
//     }
//     D_801D9E74 = D_8004B400;
//     dma_read(&D_000398D0, D_8004B400, len);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80352310_7639C0.s")
// NON-MATCHING: wrong stack size...
// void func_80352310_7639C0(void) {
//     u32 len = D_00546BC0 - D_005449C0;
//
//     if (len >= 0x2201U) {
//         // "\nASSERT: len <= sizeof(WaterTexture), %s, %u\n"
//         // "../src/init.c"
//         rmonPrintf(D_803BEA48, D_803BEA78, 0x73, len);
//         *(volatile int*)0 = 0;
//     }
//     dma_read(&D_005449C0, &D_800DCC20, len);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80352380_763A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80354188_765838.s")

// file boundary?

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80355130_7667E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80355918_766FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/init/func_80355E14_7674C4.s")

void func_80355EDC_76758C(void) {
    func_8035E3E8_76FA98(0);
}

void func_80355EFC_7675AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032C360_73DA10(123, 0x7FFF, 0, D_803D5530->xPos,  D_803D5530->zPos, D_803D5530->yPos, D_803BEB0C);
    func_8032AAF0_73C1A0(29);
}

void func_80355F64_767614(void) {
    func_8037D994_78F044(20);
    if ((D_803D5540 & 1) == 0) {
        func_802D5F4C_6E75FC(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos + (D_803D5530->unk42 >> 2), 21, 0, 0, (func_8012826C() + 0x30000) & 0x7FFF, 30, 1, 1, 0);
    }
}

void func_80355FFC_7676AC(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032C360_73DA10(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB10);
    func_8032AAF0_73C1A0(65);
}

void func_80356064_767714(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032C360_73DA10(101, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB14);
    func_8032AAF0_73C1A0(27);
}

void func_803560CC_76777C(void) {
    func_802DBA58_6ED108(15, D_803D552C);
    func_8032C360_73DA10(101, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB18);
    func_8032AAF0_73C1A0(28);
}

void func_80356134_7677E4(s32 arg0) {
    s32 temp_v0;
    s16 rot;

    temp_v0 = func_802F8160_709810(D_803D5530, arg0, 0x20, 0x14, 0x1E, 0x59, -4, 3, (f32)D_803A05B0 / 65536.0);
    if (temp_v0 == -1) {
        rot = 32;
    } else {
        rot = (temp_v0 * 256) / 360;
    }
    func_80322064_733714(17, 32, 0, 20, 30, D_803D5530->yRotation, rot, 2, 0x2D);
    func_801373CC(0, 10, 40, 5, func_8029B7D0_6ACE80(D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos));
    func_8034220C_7538BC(0xE, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);

    if ((D_803D552C->unk308 + 30) >= 47) {
        D_803D552C->unk308 = 46;
    } else {
        D_803D552C->unk308 += 30;
    }

    func_8032C360_73DA10(75, 0x5000, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, 1.0f);
}

void func_803562C8_767978(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == 27) {
        func_8032C360_73DA10(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB1C);
        func_8032AAF0_73C1A0(29);
    }
}

void func_80356348_7679F8(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == 28) {
        func_8032C360_73DA10(123, 0x7FFF, 0, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos, D_803BEB20);
        func_8032AAF0_73C1A0(65);
    }
}

void func_803563C8_767A78(s16 arg0) {
    if (arg0 != 0) {
        D_803D552C->unk36E = 20;
        D_803D552C->unk2EC = arg0;
    } else {
        D_803D552C->unk36E = 0;
    }
}
