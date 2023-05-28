#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

s16  D_803E1B20[5]; // may be a bunch of structs instead?
s16  D_803E1B30[5];
s16  D_803E1B40[5];
s16  D_803E1B50[5];
s16  D_803E1B60[5];
s16  D_803E1B70[5];
s16  D_803E1B80[5];
s16  D_803E1B8A;
s16  D_803E1B8C;
s16  D_803E1B8E;

s16  D_803E1B90;
s16  D_803E1B92;
s16  D_803E1B94;
u8   D_803E1B96;
u8   D_803E1B97;
u8   D_803E1B98;
u8   D_803E1B99;
u8   D_803E1B9A;
u8   D_803E1B9B;

s32  D_803E1B9C; // unused
s16  D_803E1BA0; // unused

u16  D_803E1BA2;
u16  D_803E1BA4;
u8   D_803E1BA6;
s16  D_803E1BA8;
s16  D_803E1BAA;
s16  D_803E1BAC;
s16  D_803E1BAE;
s16  D_803E1BB0;
s16  D_803E1BB2;
s16  D_803E1BB4;
s16  D_803E1BB6;
s16  D_803E1BB8;
u8   D_803E1BBA; // env r
u8   D_803E1BBB; // env g
u8   D_803E1BBC; // env b
u8   D_803E1BBD; // water r
u8   D_803E1BBE; // water g
u8   D_803E1BBF; // water b

// ========================================================
// .text
// ========================================================

void clear_used_lights(void) {
    s16 i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        D_803E1B20[i] = 0;
    }
}

void add_light_at_location(s16 x, s16 y, s16 z, s16 intensity, s16 r, s16 g, s16 b) {
    s16 delta;
    Animal *a;

    s16 i;
    s16 prev;
    s16 _intensity;
    s16 next = 0;

    a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;

    delta = ABS(a->xPos.h - x) +
            ABS(a->zPos.h - y) +
            ABS(a->yPos.h - z);

    if ((delta < 320) && (delta != 0)) {
        if (delta <= 192) {
            _intensity = intensity;
        } else {
            _intensity = (intensity * (320 - delta)) / 128;
        }

        prev = D_803E1B20[0];
        next = 0;

        for (i = 1; i < MAX_LIGHTS; i++) {
            if (D_803E1B20[i] < prev) {
                next = i;
                prev = D_803E1B20[i];
            }
        }

        if (prev < _intensity) {
            D_803E1B20[next] = _intensity;
            D_803E1B30[next] = (r * _intensity) >> 8;
            D_803E1B40[next] = (g * _intensity) >> 8;
            D_803E1B50[next] = (b * _intensity) >> 8;

            D_803E1B60[next] = ((x - a->xPos.h) * 120) / delta; // direction x
            D_803E1B70[next] = ((y - a->zPos.h) * 120) / delta; // direction y
            D_803E1B80[next] = ((z - a->yPos.h) * 120) / delta; // direction z
        }
    }
}

void func_802F2DF8_7044A8(void) {
    D_803A52A0_7B6950 = D_803E1B8A = 80;
    D_803A52A4_7B6954 = D_803E1B8C = 80;
    D_803A52A8_7B6958 = D_803E1B8E = 80;
    D_803A52AC_7B695C = D_803E1B90 = 200;
    D_803A52B0_7B6960 = D_803E1B92 = 200;
    D_803A52B4_7B6964 = D_803E1B94 = 200;
    D_803E1B99 = 0;
    D_803E1B9A = 0;
    D_803E1B9B = 0;
    D_803E1B96 = 0;
    D_803E1B97 = 0;
    D_803E1B98 = 0;
    D_803E1BA2 = D_803E1BA4 = 0;
    D_803A52B8_7B6968 = 1;
    D_803E1BA6 = 0;
}

void func_802F2EEC_70459C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6) {
    D_803E1B99 = D_803A52A0_7B6950;
    D_803E1B9A = D_803A52A4_7B6954;
    D_803E1B9B = D_803A52A8_7B6958;
    D_803E1B96 = D_803A52AC_7B695C;
    D_803E1B97 = D_803A52B0_7B6960;
    D_803E1B98 = D_803A52B4_7B6964;
    D_803E1B8A = (s16)arg0 - D_803E1B99; // these casts are required
    D_803E1B8C = (s16)arg1 - D_803E1B9A; // these casts are required
    D_803E1B8E = (s16)arg2 - D_803E1B9B; // these casts are required
    D_803E1B90 = (s16)arg3 - D_803E1B96;
    D_803E1B92 = (s16)arg4 - D_803E1B97;
    D_803E1B94 = (s16)arg5 - D_803E1B98;
    D_803E1BA2 = arg6;
    D_803E1BA4 = 0;
    D_803A52B8_7B6968 = 0;
}

void func_802F301C_7046CC(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7) {
    D_803E1BAE = arg0;
    D_803E1BB0 = arg1;
    D_803E1BB2 = arg2;
    D_803E1BB4 = arg3;
    D_803E1BB6 = arg4;
    D_803E1BB8 = arg5;
    D_803E1BA6 = 1;
    D_803E1BA8 = 0;
    D_803E1BAA = arg6;
    D_803E1BAC = arg7;
}

#if 0
// CURRENT (30291)
void func_802F30A4_704754(void) {
    f32 temp_f0;

    f32 temp_f20;
    f32 temp_f22;

    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f0;

    f32 var_f18_2;
    f32 var_f20;
    f32 var_f22;
    f32 var_f2;
    f32 temp_f16_2;

    if (D_803A52B8_7B6968 == 0) {
        if (D_803E1BA2 == D_803E1BA4) {
            D_803A52A0_7B6950 = D_803E1B99 + D_803E1B8A;
            D_803A52A4_7B6954 = D_803E1B9A + D_803E1B8C;
            D_803A52A8_7B6958 = D_803E1B9B + D_803E1B8E;
            D_803A52AC_7B695C = D_803E1B96 + D_803E1B90;
            D_803A52B0_7B6960 = D_803E1B97 + D_803E1B92;
            D_803A52B4_7B6964 = D_803E1B98 + D_803E1B94;

            D_803E1BBA = D_803F2D50.unk54;
            D_803E1BBB = D_803F2D50.unk55;
            D_803E1BBC = D_803F2D50.unk56;

            D_803E1BBD = D_803F2D50.unk58;
            D_803E1BBE = D_803F2D50.unk59;
            D_803E1BBF = D_803F2D50.unk5A;

            D_803A52B8_7B6968 = 1;
        } else {
            temp_f0 = (f32) D_803E1BA4 / D_803E1BA2;
            D_803A52A0_7B6950 = D_803E1B99 + (D_803E1B8A * temp_f0);
            D_803A52A4_7B6954 = D_803E1B9A + (D_803E1B8C * temp_f0);
            D_803A52A8_7B6958 = D_803E1B9B + (D_803E1B8E * temp_f0);
            D_803A52AC_7B695C = D_803E1B96 + (D_803E1B90 * temp_f0);
            D_803A52B0_7B6960 = D_803E1B97 + (D_803E1B92 * temp_f0);
            D_803A52B4_7B6964 = D_803E1B98 + (D_803E1B94 * temp_f0);
            // water primary
            D_803E1BBA = (D_803F2D50.unk54 + D_803A52A0_7B6950) / 2;
            D_803E1BBB = (D_803F2D50.unk55 + D_803A52A4_7B6954) / 2;
            D_803E1BBC = (D_803F2D50.unk56 + D_803A52A8_7B6958) / 2;
            // water env?
            D_803E1BBD = (D_803F2D50.unk58 + D_803A52A0_7B6950) / 2;
            D_803E1BBE = (D_803F2D50.unk59 + D_803A52A4_7B6954) / 2;
            D_803E1BBF = (D_803F2D50.unk5A + D_803A52A8_7B6958) / 2;
            D_803E1BA4 += 1;
        }
    } else {
        D_803A52A0_7B6950 = D_803E1B99 + D_803E1B8A;
        D_803A52A4_7B6954 = D_803E1B9A + D_803E1B8C;
        D_803A52A8_7B6958 = D_803E1B9B + D_803E1B8E;
        D_803A52AC_7B695C = D_803E1B96 + D_803E1B90;
        D_803A52B0_7B6960 = D_803E1B97 + D_803E1B92;
        D_803A52B4_7B6964 = D_803E1B98 + D_803E1B94;
    }

    if (D_803E1BA6 != 0) {
        if (D_803E1BAA >= D_803E1BA8) {
            if (D_803E1BAA == 0) {
                var_f0 = 1.0f;
            } else {
                var_f0 = (f32) D_803E1BA8 / D_803E1BAA;
            }
            D_803A52A0_7B6950 += ((f32) D_803E1BAE - D_803A52A0_7B6950) * var_f0;
            D_803A52A4_7B6954 += ((f32) D_803E1BB0 - D_803A52A4_7B6954) * var_f0;
            D_803A52A8_7B6958 += ((f32) D_803E1BB2 - D_803A52A8_7B6958) * var_f0;
            D_803A52AC_7B695C += ((f32) D_803E1BB4 - D_803A52AC_7B695C) * var_f0;
            D_803A52B0_7B6960 += ((f32) D_803E1BB6 - D_803A52B0_7B6960) * var_f0;
            D_803A52B4_7B6964 += ((f32) D_803E1BB8 - D_803A52B4_7B6964) * var_f0;
        } else if ((D_803E1BAA + D_803E1BAC) >= D_803E1BA8) {
            if (D_803E1BAA == 0) {
                var_f0 = 1.0f;
            } else {
                var_f0 = (D_803E1BA8 - (f32) D_803E1BAA) / D_803E1BAC;
            }
            D_803A52A0_7B6950 = D_803E1BAE + (((f32) D_803A52A0_7B6950 - D_803E1BAE) * var_f0);
            D_803A52A4_7B6954 = D_803E1BB0 + (((f32) D_803A52A4_7B6954 - D_803E1BB0) * var_f0);
            D_803A52A8_7B6958 = D_803E1BB2 + (((f32) D_803A52A8_7B6958 - D_803E1BB2) * var_f0);
            D_803A52AC_7B695C = D_803E1BB4 + (((f32) D_803A52AC_7B695C - D_803E1BB4) * var_f0);
            D_803A52B0_7B6960 = D_803E1BB6 + (((f32) D_803A52B0_7B6960 - D_803E1BB6) * var_f0);
            D_803A52B4_7B6964 = D_803E1BB8 + (((f32) D_803A52B4_7B6964 - D_803E1BB8) * var_f0);
        } else {
            D_803E1BA6 = 0;
        }
        D_803E1BA8++;
    }
    if (D_803F2A9A != 0x100) {
        temp_f0 = D_803F2A9A / 256.0f;

        D_80204278->lights.a.l.col[0] = D_80204278->lights.a.l.colc[0] = (D_803A52A0_7B6950 * temp_f0);
        D_80204278->lights.a.l.col[1] = D_80204278->lights.a.l.colc[1] = (D_803A52A4_7B6954 * temp_f0);
        D_80204278->lights.a.l.col[2] = D_80204278->lights.a.l.colc[2] = (D_803A52A8_7B6958 * temp_f0);

        D_80204278->lights.l[0].l.col[0] = D_80204278->lights.l[0].l.colc[0] = (D_803A52AC_7B695C * temp_f0);
        D_80204278->lights.l[0].l.col[1] = D_80204278->lights.l[0].l.colc[1] = (D_803A52B0_7B6960 * temp_f0);
        D_80204278->lights.l[0].l.col[2] = D_80204278->lights.l[0].l.colc[2] = (D_803A52B4_7B6964 * temp_f0);

        D_803E1BBD *= temp_f0;
        D_803E1BBE *= temp_f0;
        D_803E1BBF *= temp_f0;
        D_803E1BBA *= temp_f0;
        D_803E1BBB *= temp_f0;
        D_803E1BBC *= temp_f0;
    } else {
        D_80204278->lights.a.l.col[0] = D_80204278->lights.a.l.colc[0] = D_803A52A0_7B6950;
        D_80204278->lights.a.l.col[1] = D_80204278->lights.a.l.colc[1] = D_803A52A4_7B6954;
        D_80204278->lights.a.l.col[2] = D_80204278->lights.a.l.colc[2] = D_803A52A8_7B6958;

        D_80204278->lights.l[0].l.col[0] = D_80204278->lights.l[0].l.colc[0] = D_803A52AC_7B695C;
        D_80204278->lights.l[0].l.col[1] = D_80204278->lights.l[0].l.colc[1] = D_803A52B0_7B6960;
        D_80204278->lights.l[0].l.col[2] = D_80204278->lights.l[0].l.colc[2] = D_803A52B4_7B6964;

        D_803E1BBA = ((D_803F2D50.unk54 * 3) + D_803A52A0_7B6950) / 4;
        D_803E1BBB = ((D_803F2D50.unk55 * 3) + D_803A52A4_7B6954) / 4;
        D_803E1BBC = ((D_803F2D50.unk56 * 3) + D_803A52A8_7B6958) / 4;
        D_803E1BBD = ((D_803F2D50.unk58 * 3) + D_803A52A0_7B6950) / 4;
        D_803E1BBE = ((D_803F2D50.unk59 * 3) + D_803A52A4_7B6954) / 4;
        D_803E1BBF = ((D_803F2D50.unk5A * 3) + D_803A52A8_7B6958) / 4;
    }

    if (D_803F2D50.unk75 != 0) {
        temp_f20 = (sinf(0.7853947f) * -D_8020421C) + (-D_80204218 * cosf(0.7853947f));
        temp_f22 = (-D_8020421C * cosf(0.7853947f)) - (sinf(0.7853947f) * -D_80204218);
        temp_f2_3 = -D_80204220;

        var_f18_2 = MAX(ABS(temp_f20), ABS(temp_f22));

        temp_f0 = sqrtf((temp_f20 * temp_f20) + (temp_f22 * temp_f22));

        if (var_f18_2 == 0.0f) {
            var_f18_2 = 1.0f;
        }
        temp_f2_4 = 127.0f / var_f18_2;
        var_f20 = temp_f20 * temp_f2_4;
        var_f22 = temp_f22 * temp_f2_4;
        temp_f16_2 = temp_f0 / (ABS(temp_f2_3) + 1.0);

        if (temp_f16_2 < 0.25) {
            var_f20 += 4.0 * (127.0 - var_f20) * (0.25 - temp_f16_2);
            var_f22 += 4.0 * (0.0 - var_f22) * (0.25 - temp_f16_2);
        }
        var_f2 = 50.0f;
    } else {
        var_f20 = D_803F2D50.unk76;
        var_f22 = D_803F2D50.unk77;
        var_f2 = D_803F2D50.unk78;
    }

    D_80204278->lights.l[0].l.dir[0] = (s32)var_f20;
    D_80204278->lights.l[0].l.dir[1] = (s32)var_f22;
    D_80204278->lights.l[0].l.dir[2] = (s32)var_f2;

    add_single_light(&D_801D9E7C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/lights/func_802F30A4_704754.s")
#endif

void add_multiple_lights(void) {
    s16 used;
    s16 i;

    used = 0;

    // copy all used lights into a contiguous lights array
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (D_803E1B20[i] > 0) {
            used++;
            D_80204278->lights.l[used].l.col[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            D_80204278->lights.l[used].l.col[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            D_80204278->lights.l[used].l.col[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            D_80204278->lights.l[used].l.colc[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            D_80204278->lights.l[used].l.colc[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            D_80204278->lights.l[used].l.colc[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            D_80204278->lights.l[used].l.dir[0] = D_803E1B60[i];
            D_80204278->lights.l[used].l.dir[1] = D_803E1B70[i];
            D_80204278->lights.l[used].l.dir[2] = D_803E1B80[i];
        }
    }

    switch (used) {
    case 0:
        break;
    case 1:
        gSPSetLights2(D_801D9E88++, D_80204278->lights);
        return;
    case 2:
        gSPSetLights3(D_801D9E88++, D_80204278->lights);
        break;
    case 3:
        gSPSetLights4(D_801D9E88++, D_80204278->lights);
        break;
    case 4:
        gSPSetLights5(D_801D9E88++, D_80204278->lights);
        break;
    case 5:
        gSPSetLights6(D_801D9E88++, D_80204278->lights);
        break;
    case 6:
        gSPSetLights7(D_801D9E88++, D_80204278->lights);
        break;
    }
}

void add_single_light(Gfx** dl) {
    gSPSetLights1((*dl)++, D_80204278->lights);
}
