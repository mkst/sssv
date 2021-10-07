#include <ultra64.h>
#include "common.h"

extern u8 _7D1AD0_DATA_START[];
extern u8 _7D1AD0_DATA_END[];
extern u8 _7D2F50_DATA_START[];
extern u8 _7D2F50_DATA_END[];
extern u8 _7D3360_DATA_START[];
extern u8 _7D3360_DATA_END[];
extern u8 _7D3AB0_DATA_START[];
extern u8 _7D3AB0_DATA_END[];
extern u8 _7D4270_DATA_START[];
extern u8 _7D4270_DATA_END[];
extern u8 _7D4830_DATA_START[];
extern u8 _7D4830_DATA_END[];
extern u8 _7D49C0_DATA_START[];
extern u8 _7D49C0_DATA_END[];
extern u8 _7D5240_DATA_START[];
extern u8 _7D5240_DATA_END[];
extern u8 _7D5620_DATA_START[];
extern u8 _7D5620_DATA_END[];
extern u8 _7D5990_DATA_START[];
extern u8 _7D5990_DATA_END[];
extern u8 _7D5D90_DATA_START[];
extern u8 _7D5D90_DATA_END[];
extern u8 _7D61F0_DATA_START[];
extern u8 _7D61F0_DATA_END[];
extern u8 _7D64D0_DATA_START[];
extern u8 _7D64D0_DATA_END[];
extern u8 _7D6770_DATA_START[];
extern u8 _7D6770_DATA_END[];
extern u8 _7D6E30_DATA_START[];
extern u8 _7D6E30_DATA_END[];
extern u8 _7D7570_DATA_START[];
extern u8 _7D7570_DATA_END[];
extern u8 _7D7AA0_DATA_START[];
extern u8 _7D7AA0_DATA_END[];
extern u8 _7D8350_DATA_START[];
extern u8 _7D8350_DATA_END[];
extern u8 _7D88E0_DATA_START[];
extern u8 _7D88E0_DATA_END[];
extern u8 _7D8EA0_DATA_START[];
extern u8 _7D8EA0_DATA_END[];
extern u8 _7D92E0_DATA_START[];
extern u8 _7D92E0_DATA_END[];
extern u8 _7D9860_DATA_START[];
extern u8 _7D9860_DATA_END[];
extern u8 _7D9F20_DATA_START[];
extern u8 _7D9F20_DATA_END[];
extern u8 _7DA020_DATA_START[];
extern u8 _7DA020_DATA_END[];
extern u8 _7DA120_DATA_START[];
extern u8 _7DA120_DATA_END[];
extern u8 _7DA4A0_DATA_START[];
extern u8 _7DA4A0_DATA_END[];
extern u8 _7DA990_DATA_START[];
extern u8 _7DA990_DATA_END[];
extern u8 _7DADF0_DATA_START[];
extern u8 _7DADF0_DATA_END[];
extern u8 _7DB380_DATA_START[];
extern u8 _7DB380_DATA_END[];
extern u8 _7DBBC0_DATA_START[];
extern u8 _7DBBC0_DATA_END[];
extern u8 _7DC250_DATA_START[];
extern u8 _7DC250_DATA_END[];
extern u8 _7DC580_DATA_START[];
extern u8 _7DC580_DATA_END[];
extern u8 _7DC990_DATA_START[];
extern u8 _7DC990_DATA_END[];

// FIXME: replace with ROM offsets
struct046 D_803B6890_7C7F40[33] = {
    { _7D1AD0_DATA_START, _7D1AD0_DATA_END, 0x803FDEC0, 0x803FF340, 0x803FDEC0, },
    { _7D2F50_DATA_START, _7D2F50_DATA_END, 0x803FDEC0, 0x803FE2D0, 0x803FDEC0, },
    { _7D3360_DATA_START, _7D3360_DATA_END, 0x803FDEC0, 0x803FE610, 0x803FDEC0, },
    { _7D3AB0_DATA_START, _7D3AB0_DATA_END, 0x803FDEC0, 0x803FE680, 0x803FDEC0, },
    { _7D4270_DATA_START, _7D4270_DATA_END, 0x803FDEC0, 0x803FE480, 0x803FDEC0, },
    { _7D4830_DATA_START, _7D4830_DATA_END, 0x803FDEC0, 0x803FE050, 0x803FDEC0, },
    { _7D49C0_DATA_START, _7D49C0_DATA_END, 0x803FDEC0, 0x803FE740, 0x803FDEC0, },
    { _7D5240_DATA_START, _7D5240_DATA_END, 0x803FDEC0, 0x803FE2A0, 0x803FDEC0, },
    { _7D5620_DATA_START, _7D5620_DATA_END, 0x803FDEC0, 0x803FE230, 0x803FDEC0, },
    { _7D5990_DATA_START, _7D5990_DATA_END, 0x803FDEC0, 0x803FE2C0, 0x803FDEC0, },
    { _7D5D90_DATA_START, _7D5D90_DATA_END, 0x803FDEC0, 0x803FE320, 0x803FDEC0, },
    { _7D61F0_DATA_START, _7D61F0_DATA_END, 0x803FDEC0, 0x803FE1A0, 0x803FDEC0, },
    { _7D64D0_DATA_START, _7D64D0_DATA_END, 0x803FDEC0, 0x803FE160, 0x803FDEC0, },
    { _7D6770_DATA_START, _7D6770_DATA_END, 0x803FDEC0, 0x803FE580, 0x803FDEC0, },
    { _7D6E30_DATA_START, _7D6E30_DATA_END, 0x803FDEC0, 0x803FE600, 0x803FDEC0, },
    { _7D7570_DATA_START, _7D7570_DATA_END, 0x803FDEC0, 0x803FE3F0, 0x803FDEC0, },
    { _7D7AA0_DATA_START, _7D7AA0_DATA_END, 0x803FDEC0, 0x803FE770, 0x803FDEC0, },
    { _7D8350_DATA_START, _7D8350_DATA_END, 0x803FDEC0, 0x803FE450, 0x803FDEC0, },
    { _7D88E0_DATA_START, _7D88E0_DATA_END, 0x803FDEC0, 0x803FE480, 0x803FDEC0, },
    { _7D8EA0_DATA_START, _7D8EA0_DATA_END, 0x803FDEC0, 0x803FE300, 0x803FDEC0, },
    { _7D92E0_DATA_START, _7D92E0_DATA_END, 0x803FDEC0, 0x803FE440, 0x803FDEC0, },
    { _7D9860_DATA_START, _7D9860_DATA_END, 0x803FDEC0, 0x803FE580, 0x803FDEC0, },
    { _7D9F20_DATA_START, _7D9F20_DATA_END, 0x803FDEC0, 0x803FDFC0, 0x803FDEC0, },
    { _7DA020_DATA_START, _7DA020_DATA_END, 0x803FF340, 0x803FF440, 0x803FF340, },
    { _7DA120_DATA_START, _7DA120_DATA_END, 0x803FF340, 0x803FF6C0, 0x803FF340, },
    { _7DA4A0_DATA_START, _7DA4A0_DATA_END, 0x803FF340, 0x803FF830, 0x803FF340, },
    { _7DA990_DATA_START, _7DA990_DATA_END, 0x803FF340, 0x803FF7A0, 0x803FF340, },
    { _7DADF0_DATA_START, _7DADF0_DATA_END, 0x803FF340, 0x803FF8D0, 0x803FF340, },
    { _7DB380_DATA_START, _7DB380_DATA_END, 0x803FF340, 0x803FFB80, 0x803FF340, },
    { _7DBBC0_DATA_START, _7DBBC0_DATA_END, 0x803FF340, 0x803FF9D0, 0x803FF340, },
    { _7DC250_DATA_START, _7DC250_DATA_END, 0x803FF340, 0x803FF670, 0x803FF340, },
    { _7DC580_DATA_START, _7DC580_DATA_END, 0x803FF340, 0x803FF750, 0x803FF340, },
    { _7DC990_DATA_START, _7DC990_DATA_END, 0x803FF340, 0x803FF4A0, 0x803FF340, },
};

s16 D_803B6B24_7C81D4[3] = {0, 23, 10};

// where is this used?
s16 D_803B6B2C_7C81DC = -1;

void func_803973A0_7A8A50(s16 arg0) {
    s32 len = D_803B6890_7C7F40[arg0].romEnd - D_803B6890_7C7F40[arg0].romStart;

    osInvalDCache(D_803B6890_7C7F40[arg0].ramStart, D_803B6890_7C7F40[arg0].ramEnd - D_803B6890_7C7F40[arg0].ramStart);
    dma_read(D_803B6890_7C7F40[arg0].romStart, D_803B6890_7C7F40[arg0].ramStart2, len);
}

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

// arg1 is 0 to 2
void func_80397734_7A8DE4(s16 arg0, u8 arg1) {
    s16 i;

    arg0 += D_803B6B24_7C81D4[arg1];
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

void func_80397B84_7A9234(void) {
    s16 i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 3; k++) {
                D_803F6720[i][j].unk18.unk0[k] = 0.0f;
                D_803F6720[i][j].unk18.unkC[k] = 0.0f;

                D_803F6720[i][j].unk0.unk0[k] = 0.0f;
                D_803F6720[i][j].unk0.unkC[k] = 0.0f;

                D_803F6720[i][j].unk30.unk0[k] = 0.0f;
                D_803F6720[i][j].unk30.unkC[k] = 0.0f;
            }
            D_803F6720[i][j].unk48 = 0.0f;
            D_803F6720[i][j].unk4C = 0.0f;
            D_803F6720[i][j].unk50 = 0;
        }
    }
}

void func_80397C58_7A9308(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7, u8 arg8) {
    struct048 *temp_v0 = &D_803F6720[arg8][arg7];

    temp_v0->unk18.unk0[0] = temp_v0->unk0.unk0[0];
    temp_v0->unk18.unk0[1] = temp_v0->unk0.unk0[1];
    temp_v0->unk18.unk0[2] = temp_v0->unk0.unk0[2];

    temp_v0->unk18.unkC[0] = temp_v0->unk0.unkC[0];
    temp_v0->unk18.unkC[1] = temp_v0->unk0.unkC[1];
    temp_v0->unk18.unkC[2] = temp_v0->unk0.unkC[2];

    temp_v0->unk30.unk0[0] = arg0;
    temp_v0->unk30.unk0[1] = arg1;
    temp_v0->unk30.unk0[2] = arg2;
    temp_v0->unk30.unkC[0] = arg3;
    temp_v0->unk30.unkC[1] = arg4;
    temp_v0->unk30.unkC[2] = arg5;

    temp_v0->unk48 = 0.0f;
    temp_v0->unk4C = arg6;
    temp_v0->unk50 = (u16)1;
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

// display lists
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397F5C_7A960C.s")
