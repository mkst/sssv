#include <ultra64.h>
#include "common.h"

#include "dan.h"

// ========================================================
// .text
// ========================================================

void func_803973A0_7A8A50(s16 arg0) {
    s32 len = D_803B6890_7C7F40[arg0].romEnd - D_803B6890_7C7F40[arg0].romStart;

    osInvalDCache(D_803B6890_7C7F40[arg0].ramStart, D_803B6890_7C7F40[arg0].ramEnd - D_803B6890_7C7F40[arg0].ramStart);
    dma_read(D_803B6890_7C7F40[arg0].romStart, D_803B6890_7C7F40[arg0].ramDest, len);
}

void func_80397414_7A8AC4(u8 push, f32 x_amt, f32 y_amt, f32 z_amt, f32 x_angle, f32 y_angle, f32 z_angle) {
    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_amt, y_amt, z_amt);
    if (push) {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    } else {
        gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], y_angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], z_angle, 0.0f, 0.0f, 1.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], x_angle, 1.0f, 0.0f, 0.0f);
    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
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
    D_803F713C[arg1] = 0x3FF; // 10x1, enable all?
    D_803F714C[arg1] = 0;
    D_803F7144[arg1] = 0;
    D_803F7134[arg1] = arg0;
}

void func_80397840_7A8EF0(void) {
    s16 temp_a1;
    s16 i;
    s16 j;
    struct110b *temp_t0;
    f32 a, b, c, d, e, f;

    for (i = 0; i < 3; i++) {

        if (D_803F713C[i] != 0) {

            while ((D_803B7000_7C86B0[D_803F7134[i]].sfx != NULL) &&
                   (D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].unk0 == D_803F714C[i])) {
                func_8032C508_73DBB8(
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].id,
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].volume,
                    0,
                    D_803B7000_7C86B0[D_803F7134[i]].sfx[D_803F7144[i]].pitch);
                D_803F7144[i]++;
            };

            for (j = 0; j < 10; j++) {
                if (D_803F713C[i] & (1 << j)) {

                    if (D_803F6720[i][j].unk4C <= D_803F6720[i][j].unk48) {
                        s32 idx = D_803F70F8[i][j];
                        struct110c *foo = D_803B7000_7C86B0[D_803F7134[i]].unk0;

                        if (foo[j + 1].unk0 <= idx) {
                            D_803F713C[i] &= ~ (1 << j);  // clear flag
                            continue;
                        }

                        temp_t0 = &foo[j].unk4[idx];
                        a =  ((temp_t0->unk4 * 180.0f) / 32768.0f);
                        b = -((temp_t0->unk0 * 180.0f) / 32768.0f);
                        c = -((temp_t0->unk2 * 180.0f) / 32768.0f);
                        d = temp_t0->unk6;
                        e = -(f32)temp_t0->unk8;
                        f = -(f32)temp_t0->unkA;
                        func_80397C58_7A9308(
                            a,
                            b,
                            c,
                            d,
                            e,
                            f,
                            temp_t0->unkC,
                            j,
                            i);
                        D_803F70F8[i][j]++;
                    }
                }
            }
            func_80397D1C_7A93CC(i);
            D_803F714C[i]++;
        }
    }
}

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
                temp_f0 = cosf((SSSV_PI / 180) * tmp);
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

void func_80397F5C_7A960C(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5, u8 idx, u8 arg7) {
    s16 i;
    s16 j;
    s16 var_s2;

    if (arg7 == 2) {
        func_8034C8F8_75DFA8(
            D_803F6720[arg7][0].unk0.unkC[0] + (arg0 >> 16),
            D_803F6720[arg7][0].unk0.unkC[1] + (arg1 >> 16),
            D_803F6720[arg7][0].unk0.unkC[2] + (arg2 >> 16),
            ((arg4 - D_803F6720[arg7][0].unk0.unk0[2]) * 256) / 360,
            D_803A8370_7B9A20[1], // 0x1034190
            (arg5 << 3) >> 0x10,
            (arg5 << 4) >> 0x10,
            0x9B,
            0,
            0,
            0,
            8,
            1);
    }

    arg5 = arg5 / 5;
    func_80125FE0(
        &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs],
        arg0,
        arg1,
        arg2,
        arg3,
        arg4,
        arg5,
        arg5,
        arg5);

    gSPMatrix(D_801D9E8C++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    func_80397414_7A8AC4(
        0,
        D_803F6720[arg7][0].unk0.unkC[0],
        D_803F6720[arg7][0].unk0.unkC[1],
        D_803F6720[arg7][0].unk0.unkC[2],
        D_803F6720[arg7][0].unk0.unk0[0],
        D_803F6720[arg7][0].unk0.unk0[1],
        D_803F6720[arg7][0].unk0.unk0[2]
    );
    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][6]);

    if (arg7 != 2) {
        var_s2 = 4;
        j = 0;

        for (i = 0; i < 2; i++) {
            // push
            func_80397414_7A8AC4(
                1,
                D_803F6720[arg7][var_s2].unk0.unkC[0],
                D_803F6720[arg7][var_s2].unk0.unkC[1],
                D_803F6720[arg7][var_s2].unk0.unkC[2],
                D_803F6720[arg7][var_s2].unk0.unk0[0],
                D_803F6720[arg7][var_s2].unk0.unk0[1],
                D_803F6720[arg7][var_s2].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][j]);
            var_s2++;
            j++;

            // no push
            func_80397414_7A8AC4(
                0,
                D_803F6720[arg7][var_s2].unk0.unkC[0],
                D_803F6720[arg7][var_s2].unk0.unkC[1],
                D_803F6720[arg7][var_s2].unk0.unkC[2],
                D_803F6720[arg7][var_s2].unk0.unk0[0],
                D_803F6720[arg7][var_s2].unk0.unk0[1],
                D_803F6720[arg7][var_s2].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][j]);
            var_s2++;
            j++;

            // no push
            func_80397414_7A8AC4(
                0,
                D_803F6720[arg7][var_s2].unk0.unkC[0],
                D_803F6720[arg7][var_s2].unk0.unkC[1],
                D_803F6720[arg7][var_s2].unk0.unkC[2],
                D_803F6720[arg7][var_s2].unk0.unk0[0],
                D_803F6720[arg7][var_s2].unk0.unk0[1],
                D_803F6720[arg7][var_s2].unk0.unk0[2]
            );
            gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][j]);
            var_s2++;
            j++;

            gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);

        }
    }

    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][1].unk0.unkC[0],
        D_803F6720[arg7][1].unk0.unkC[1],
        D_803F6720[arg7][1].unk0.unkC[2],
        D_803F6720[arg7][1].unk0.unk0[0],
        D_803F6720[arg7][1].unk0.unk0[1],
        D_803F6720[arg7][1].unk0.unk0[2]
    );
    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][7]);

    if (arg7 != 2) {
        func_80397414_7A8AC4(
            1,
            D_803F6720[arg7][2].unk0.unkC[0],
            D_803F6720[arg7][2].unk0.unkC[1],
            D_803F6720[arg7][2].unk0.unkC[2],
            D_803F6720[arg7][2].unk0.unk0[0],
            D_803F6720[arg7][2].unk0.unk0[1],
            D_803F6720[arg7][2].unk0.unk0[2]
        );
        gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][8]);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][1].unk0.unkC[0],
        D_803F6720[arg7][1].unk0.unkC[1],
        D_803F6720[arg7][1].unk0.unkC[2],
        D_803F6720[arg7][1].unk0.unk0[0],
        D_803F6720[arg7][1].unk0.unk0[1],
        D_803F6720[arg7][1].unk0.unk0[2]
    );

    if (arg7 == 1) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, 0xEA, 0xE6, 0xFF, 0xFF); // very light lilac
        gDPSetCombineLERP(D_801D9E8C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
    }

    func_80397414_7A8AC4(
        1,
        D_803F6720[arg7][3].unk0.unkC[0],
        D_803F6720[arg7][3].unk0.unkC[1],
        D_803F6720[arg7][3].unk0.unkC[2],
        D_803F6720[arg7][3].unk0.unk0[0],
        D_803F6720[arg7][3].unk0.unk0[1],
        D_803F6720[arg7][3].unk0.unk0[2]
    );

    gSPDisplayList(D_801D9E8C++, D_803B7108_7C87B8[idx][9]);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
}
