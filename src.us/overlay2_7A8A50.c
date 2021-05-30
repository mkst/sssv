#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_803973A0_7A8A50.s")
// JUSTREG - need to remove the temp vars
// void func_803973A0_7A8A50(s16 arg0) {
//     s32 pad;
//     s32 tmp1;
//     s32 tmp2;
//
//     tmp2 = D_803B6890[arg0].unk4 - D_803B6890[arg0].unk0;
//     tmp1 = D_803B6890[arg0].unkC - D_803B6890[arg0].unk8;
//
//     osInvalDCache(D_803B6890[arg0].unk8, tmp1);
//     dma_read(D_803B6890[arg0].unk0, D_803B6890[arg0].unk10, tmp2);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397414_7A8AC4.s")

// init/reset something
void func_803976E0_7A8D90(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_803F713C[i] = 0;
        D_803F7144[i] = 0;
        D_803F714C[i] = 0;
    }
}

void func_80397734_7A8DE4(s16 arg0, u8 arg1) {
    s16 i;

    arg0 += D_803B6B24[arg1];
    func_803973A0_7A8A50(arg0);
    for (i = 0; i < 10; i++) {
        D_803F70F8[arg1][i] = 0;
        D_803F6720[arg1][i].unk48 = 0.0f;
        D_803F6720[arg1][i].unk4C = 0.0f;
    }
    D_803F713C[arg1] = 0x3FF;
    D_803F714C[arg1] = 0;
    D_803F7144[arg1] = 0;
    D_803F7134[arg1] = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397840_7A8EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397B84_7A9234.s")

void func_80397C58_7A9308(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8) {
    struct048 *temp_v0 = &D_803F6720[arg8][arg7];

    temp_v0->unk18 = temp_v0->unk0;
    temp_v0->unk1C = temp_v0->unk4;
    temp_v0->unk20 = temp_v0->unk8;
    temp_v0->unk24 = temp_v0->unkC;
    temp_v0->unk28 = temp_v0->unk10;
    temp_v0->unk2C = temp_v0->unk14;

    temp_v0->unk30 = arg0;
    temp_v0->unk34 = arg1;
    temp_v0->unk50 = (u16)1;
    temp_v0->unk38 = arg2;
    temp_v0->unk3C = arg3;
    temp_v0->unk40 = arg4;
    temp_v0->unk44 = arg5;
    temp_v0->unk48 = 0.0f;
    temp_v0->unk4C = arg6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397D1C_7A93CC.s")
// void func_80397D1C_7A93CC(u8 arg0) {
//     f32 temp_f0;
//     f32 temp_f10;
//     f32 temp_f16;
//     f32 temp_f22;
//     f32 temp_f24;
//     f32 temp_f26;
//     f32 temp_f28;
//     f32 temp_f30;
//     struct048 *temp_s0;
//     s16 i;
//
//     for (i = 0; i < 10; i++) {
//         temp_s0 = &D_803F6720[arg0][i];
//         if (temp_s0->unk50 == 0) {
//             continue;
//         }
//         temp_s0->unk48 += 1.0f;
//         if (temp_s0->unk4C <= temp_s0->unk48) {
//             temp_f22 = (temp_s0->unk30 - temp_s0->unk18) / 2.0f;
//             temp_f24 = (temp_s0->unk34 - temp_s0->unk1C) / 2.0f;
//             temp_f26 = (temp_s0->unk38 - temp_s0->unk20) / 2.0f;
//             temp_f28 = (temp_s0->unk3C - temp_s0->unk24) / 2.0f;
//             temp_f16 = (temp_s0->unk44 - temp_s0->unk2C) / 2.0f;
//             temp_f30 = (temp_s0->unk40 - temp_s0->unk28) / 2.0f;
//             temp_f0 = cosf(((temp_s0->unk48 / temp_s0->unk4C) * 180.0f) * D_803C0390);
//             temp_s0->unk0 = (temp_s0->unk18 + temp_f22) - (temp_f22 * temp_f0);
//             temp_s0->unk4 = (temp_s0->unk1C + temp_f24) - (temp_f24 * temp_f0);
//             temp_s0->unk8 = (temp_s0->unk20 + temp_f26) - (temp_f26 * temp_f0);
//             temp_s0->unkC = (temp_s0->unk24 + temp_f28) - (temp_f28 * temp_f0);
//             temp_s0->unk10 = (temp_s0->unk28 + temp_f30) - (temp_f30 * temp_f0);
//             temp_s0->unk14 = (temp_s0->unk2C + temp_f16) - (temp_f16 * temp_f0);
//         } else {
//             temp_s0->unk0 = temp_s0->unk30;
//             temp_s0->unk50 = 0;
//             temp_s0->unk4 = temp_s0->unk34;
//             temp_s0->unk8 = temp_s0->unk38;
//             temp_s0->unkC = temp_s0->unk3C;
//             temp_s0->unk10 = temp_s0->unk40;
//             temp_s0->unk14 = temp_s0->unk44;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397F5C_7A960C.s")
