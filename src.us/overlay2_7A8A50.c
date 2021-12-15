#include <ultra64.h>
#include "common.h"

void func_8034C8F8_75DFA8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB, u8 argC);

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

extern u8 D_803FDEC0[]; // overlay2 bss end
extern u8 D_803FF340[]; // ??

// FIXME: replace with ROM offsets
struct046 D_803B6890_7C7F40[33] = {
    { _7D1AD0_DATA_START, _7D1AD0_DATA_END, D_803FDEC0, D_803FF340, D_803FDEC0, },
    { _7D2F50_DATA_START, _7D2F50_DATA_END, D_803FDEC0, 0x803FE2D0, D_803FDEC0, },
    { _7D3360_DATA_START, _7D3360_DATA_END, D_803FDEC0, 0x803FE610, D_803FDEC0, },
    { _7D3AB0_DATA_START, _7D3AB0_DATA_END, D_803FDEC0, 0x803FE680, D_803FDEC0, },
    { _7D4270_DATA_START, _7D4270_DATA_END, D_803FDEC0, 0x803FE480, D_803FDEC0, },
    { _7D4830_DATA_START, _7D4830_DATA_END, D_803FDEC0, 0x803FE050, D_803FDEC0, },
    { _7D49C0_DATA_START, _7D49C0_DATA_END, D_803FDEC0, 0x803FE740, D_803FDEC0, },
    { _7D5240_DATA_START, _7D5240_DATA_END, D_803FDEC0, 0x803FE2A0, D_803FDEC0, },
    { _7D5620_DATA_START, _7D5620_DATA_END, D_803FDEC0, 0x803FE230, D_803FDEC0, },
    { _7D5990_DATA_START, _7D5990_DATA_END, D_803FDEC0, 0x803FE2C0, D_803FDEC0, },
    { _7D5D90_DATA_START, _7D5D90_DATA_END, D_803FDEC0, 0x803FE320, D_803FDEC0, },
    { _7D61F0_DATA_START, _7D61F0_DATA_END, D_803FDEC0, 0x803FE1A0, D_803FDEC0, },
    { _7D64D0_DATA_START, _7D64D0_DATA_END, D_803FDEC0, 0x803FE160, D_803FDEC0, },
    { _7D6770_DATA_START, _7D6770_DATA_END, D_803FDEC0, 0x803FE580, D_803FDEC0, },
    { _7D6E30_DATA_START, _7D6E30_DATA_END, D_803FDEC0, 0x803FE600, D_803FDEC0, },
    { _7D7570_DATA_START, _7D7570_DATA_END, D_803FDEC0, 0x803FE3F0, D_803FDEC0, },
    { _7D7AA0_DATA_START, _7D7AA0_DATA_END, D_803FDEC0, 0x803FE770, D_803FDEC0, },
    { _7D8350_DATA_START, _7D8350_DATA_END, D_803FDEC0, 0x803FE450, D_803FDEC0, },
    { _7D88E0_DATA_START, _7D88E0_DATA_END, D_803FDEC0, 0x803FE480, D_803FDEC0, },
    { _7D8EA0_DATA_START, _7D8EA0_DATA_END, D_803FDEC0, 0x803FE300, D_803FDEC0, },
    { _7D92E0_DATA_START, _7D92E0_DATA_END, D_803FDEC0, 0x803FE440, D_803FDEC0, },
    { _7D9860_DATA_START, _7D9860_DATA_END, D_803FDEC0, 0x803FE580, D_803FDEC0, },
    { _7D9F20_DATA_START, _7D9F20_DATA_END, D_803FDEC0, 0x803FDFC0, D_803FDEC0, },
    { _7DA020_DATA_START, _7DA020_DATA_END, D_803FF340, 0x803FF440, D_803FF340, },
    { _7DA120_DATA_START, _7DA120_DATA_END, D_803FF340, 0x803FF6C0, D_803FF340, },
    { _7DA4A0_DATA_START, _7DA4A0_DATA_END, D_803FF340, 0x803FF830, D_803FF340, },
    { _7DA990_DATA_START, _7DA990_DATA_END, D_803FF340, 0x803FF7A0, D_803FF340, },
    { _7DADF0_DATA_START, _7DADF0_DATA_END, D_803FF340, 0x803FF8D0, D_803FF340, },
    { _7DB380_DATA_START, _7DB380_DATA_END, D_803FF340, 0x803FFB80, D_803FF340, },
    { _7DBBC0_DATA_START, _7DBBC0_DATA_END, D_803FF340, 0x803FF9D0, D_803FF340, },
    { _7DC250_DATA_START, _7DC250_DATA_END, D_803FF340, 0x803FF670, D_803FF340, },
    { _7DC580_DATA_START, _7DC580_DATA_END, D_803FF340, 0x803FF750, D_803FF340, },
    { _7DC990_DATA_START, _7DC990_DATA_END, D_803FF340, 0x803FF4A0, D_803FF340, },
};

s16 D_803B6B24_7C81D4[3] = {0, 23, 10};

// where is this used?
s16 D_803B6B2C_7C81DC = -1;

void func_803973A0_7A8A50(s16 arg0) {
    s32 len = D_803B6890_7C7F40[arg0].romEnd - D_803B6890_7C7F40[arg0].romStart;

    osInvalDCache(D_803B6890_7C7F40[arg0].ramStart, D_803B6890_7C7F40[arg0].ramEnd - D_803B6890_7C7F40[arg0].ramStart);
    dma_read(D_803B6890_7C7F40[arg0].romStart, D_803B6890_7C7F40[arg0].ramStart2, len);
}

void func_80397414_7A8AC4(u8 push, f32 x_amt, f32 y_amt, f32 z_amt, f32 x_angle, f32 y_angle, f32 z_angle) {
    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_amt, y_amt, z_amt);
    if (push) {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_80204278->usedModelViewMtxs += 1;
    } else {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_80204278->usedModelViewMtxs += 1;
    }

    guAlign(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], y_angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    guAlign(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], z_angle, 0.0f, 0.0f, 1.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;

    guAlign(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_angle, 1.0f, 0.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_80204278->usedModelViewMtxs += 1;
}

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

void func_80397D1C_7A93CC(u8 arg0) {
    f32 pad[4];
    f32 temp_f0;
    f32 temp_f10;
    f32 temp_f16;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f30;
    f32 tmp;
    f32 factor;
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_803F6720[arg0][i].unk50 != 0) {
            factor = 2.0f;
            D_803F6720[arg0][i].unk48 += 1.0f;
            if (D_803F6720[arg0][i].unk4C <= D_803F6720[arg0][i].unk48) {
                D_803F6720[arg0][i].unk0.unk0[0] = D_803F6720[arg0][i].unk30.unk0[0];
                D_803F6720[arg0][i].unk0.unk0[1] = D_803F6720[arg0][i].unk30.unk0[1];
                D_803F6720[arg0][i].unk0.unk0[2] = D_803F6720[arg0][i].unk30.unk0[2];
                D_803F6720[arg0][i].unk0.unkC[0] = D_803F6720[arg0][i].unk30.unkC[0];
                D_803F6720[arg0][i].unk0.unkC[1] = D_803F6720[arg0][i].unk30.unkC[1];
                D_803F6720[arg0][i].unk0.unkC[2] = D_803F6720[arg0][i].unk30.unkC[2];
                D_803F6720[arg0][i].unk50 = 0;
            } else {
                temp_f22 = (D_803F6720[arg0][i].unk30.unk0[0] - D_803F6720[arg0][i].unk18.unk0[0]) / factor;
                temp_f24 = (D_803F6720[arg0][i].unk30.unk0[1] - D_803F6720[arg0][i].unk18.unk0[1]) / factor;
                temp_f26 = (D_803F6720[arg0][i].unk30.unk0[2] - D_803F6720[arg0][i].unk18.unk0[2]) / factor;
                temp_f28 = (D_803F6720[arg0][i].unk30.unkC[0] - D_803F6720[arg0][i].unk18.unkC[0]) / factor;
                temp_f30 = (D_803F6720[arg0][i].unk30.unkC[1] - D_803F6720[arg0][i].unk18.unkC[1]) / factor;
                temp_f16 = (D_803F6720[arg0][i].unk30.unkC[2] - D_803F6720[arg0][i].unk18.unkC[2]) / factor;
                tmp = ((D_803F6720[arg0][i].unk48 / D_803F6720[arg0][i].unk4C) * 180.0f);
                // this is not quite PI (3.14159265359)
                temp_f0 = cosf((3.141579 / 180) * tmp);
                D_803F6720[arg0][i].unk0.unk0[0] = (D_803F6720[arg0][i].unk18.unk0[0] + temp_f22) - (temp_f22 * temp_f0);
                D_803F6720[arg0][i].unk0.unk0[1] = (D_803F6720[arg0][i].unk18.unk0[1] + temp_f24) - (temp_f24 * temp_f0);
                D_803F6720[arg0][i].unk0.unk0[2] = (D_803F6720[arg0][i].unk18.unk0[2] + temp_f26) - (temp_f26 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[0] = (D_803F6720[arg0][i].unk18.unkC[0] + temp_f28) - (temp_f28 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[1] = (D_803F6720[arg0][i].unk18.unkC[1] + temp_f30) - (temp_f30 * temp_f0);
                D_803F6720[arg0][i].unk0.unkC[2] = (D_803F6720[arg0][i].unk18.unkC[2] + temp_f16) - (temp_f16 * temp_f0);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A8A50/func_80397F5C_7A960C.s")
// what am I missing here?
// void func_80397F5C_7A960C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, u8 arg6, u8 arg7) {
//     s16 phi_s2;
//     s16 i;
//
//     if (arg7 == 2) {
//         // if (1) {};
//         func_8034C8F8_75DFA8(
//             (arg0 >> 16) + D_803F6720[arg7][0].unk0.unkC[0],
//             (arg1 >> 16) + D_803F6720[arg7][0].unk0.unkC[1],
//             (arg2 >> 16) + D_803F6720[arg7][0].unk0.unkC[2],
//             ((arg4 - D_803F6720[arg7][0].unk0.unk0[2]) * 256.0f) / 360.0f,
//             D_803A8374_7B9A24, // 0x1034190
//             (arg5 << 3) >> 0x10,
//             (arg5 << 4) >> 0x10,
//             0x9B,
//             0,
//             0,
//             0,
//             8,
//             1);
//     }
//     func_80125FE0(
//         &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
//         arg0,
//         arg1,
//         arg2,
//         arg3,
//         arg4,
//         (arg5 / 5),
//         (arg5 / 5),
//         (arg5 / 5));
//
//     gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
//     D_80204278->usedModelViewMtxs += 1;
//
//     func_80397414_7A8AC4(
//         0,
//         D_803F6720[arg7][0].unk0.unkC[0],
//         D_803F6720[arg7][0].unk0.unkC[1],
//         D_803F6720[arg7][0].unk0.unkC[2],
//         D_803F6720[arg7][0].unk0.unk0[0],
//         D_803F6720[arg7][0].unk0.unk0[1],
//         D_803F6720[arg7][0].unk0.unk0[2]
//     );
//     gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][6]); // ->unk18
//
//     if (arg7 != 2) {
//         phi_s2 = 4;
//         i = 0;
//         // is this a for loop?
//         do {
//             // push
//             func_80397414_7A8AC4(
//                 1,
//                 D_803F6720[arg7][phi_s2].unk0.unkC[0],
//                 D_803F6720[arg7][phi_s2].unk0.unkC[1],
//                 D_803F6720[arg7][phi_s2].unk0.unkC[2],
//                 D_803F6720[arg7][phi_s2].unk0.unk0[0],
//                 D_803F6720[arg7][phi_s2].unk0.unk0[1],
//                 D_803F6720[arg7][phi_s2].unk0.unk0[2]
//             );
//             gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]); // phi_s3
//
//             // no push
//             func_80397414_7A8AC4(
//                 0,
//                 D_803F6720[arg7][i].unk0.unkC[0],
//                 D_803F6720[arg7][i].unk0.unkC[1],
//                 D_803F6720[arg7][i].unk0.unkC[2],
//                 D_803F6720[arg7][i].unk0.unk0[0],
//                 D_803F6720[arg7][i].unk0.unk0[1],
//                 D_803F6720[arg7][i].unk0.unk0[2]
//             );
//             gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]);
//
//             // no push
//             func_80397414_7A8AC4(
//                 0,
//                 D_803F6720[arg7][i].unk0.unkC[0],
//                 D_803F6720[arg7][i].unk0.unkC[1],
//                 D_803F6720[arg7][i].unk0.unkC[2],
//                 D_803F6720[arg7][i].unk0.unk0[0],
//                 D_803F6720[arg7][i].unk0.unk0[1],
//                 D_803F6720[arg7][i].unk0.unk0[2]
//             );
//             gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][i]);
//
//             gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
//             phi_s2++;
//         } while (i++ < 2); //?
//     }
//
//     func_80397414_7A8AC4(
//         1,
//         D_803F6720[arg7][1].unk0.unkC[0],
//         D_803F6720[arg7][1].unk0.unkC[1],
//         D_803F6720[arg7][1].unk0.unkC[2],
//         D_803F6720[arg7][1].unk0.unk0[0],
//         D_803F6720[arg7][1].unk0.unk0[1],
//         D_803F6720[arg7][1].unk0.unk0[2]
//     );
//     gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][7]);
//
//     if (arg7 != 2) {
//         func_80397414_7A8AC4(
//             1,
//             D_803F6720[arg7][2].unk0.unkC[0],
//             D_803F6720[arg7][2].unk0.unkC[1],
//             D_803F6720[arg7][2].unk0.unkC[2],
//             D_803F6720[arg7][2].unk0.unk0[0],
//             D_803F6720[arg7][2].unk0.unk0[1],
//             D_803F6720[arg7][2].unk0.unk0[2]
//         );
//         gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][8]);
//         gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
//     }
//     func_80397414_7A8AC4(
//         1,
//         D_803F6720[arg7][1].unk0.unkC[0],
//         D_803F6720[arg7][1].unk0.unkC[1],
//         D_803F6720[arg7][1].unk0.unkC[2],
//         D_803F6720[arg7][1].unk0.unk0[0],
//         D_803F6720[arg7][1].unk0.unk0[1],
//         D_803F6720[arg7][1].unk0.unk0[2]
//     );
//
//     if (arg7 == 1) {
//         gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF); // very light lilac
//         gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
//     }
//
//     func_80397414_7A8AC4(
//         1,
//         D_803F6720[arg7][3].unk0.unkC[0],
//         D_803F6720[arg7][3].unk0.unkC[1],
//         D_803F6720[arg7][3].unk0.unkC[2],
//         D_803F6720[arg7][3].unk0.unk0[0],
//         D_803F6720[arg7][3].unk0.unk0[1],
//         D_803F6720[arg7][3].unk0.unk0[2]
//     );
//     gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[arg6][9]); //->unk24);
//     gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
//     gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
//     gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
// }
