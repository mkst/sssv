#include <ultra64.h>
#include "common.h"


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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F2DF8_7044A8.s")
// urgh
// void func_802F2DF8_7044A8(void) {
//     D_803A52A0_7B6950 = D_803E1B8A = 80;
//     D_803A52A4_7B6954 = D_803E1B8C = 80;
//     D_803A52A8_7B6958 = D_803E1B8E = 80;
//     D_803A52AC_7B695C = D_803E1B90 = 200;
//     D_803A52B0_7B6960 = D_803E1B92 = 200;
//     D_803A52B4_7B6964 = D_803E1B94 = 200;
//     D_803E1B99 = 0;
//     D_803E1B9A = 0;
//     D_803E1B9B = 0;
//     D_803E1B96 = 0;
//     D_803E1B97 = 0;
//     D_803E1B98 = 0;
//     D_803E1BA4 = 0;
//     D_803E1BA2 = 0;
//     D_803E1BA6 = 0;
//     D_803A52B8_7B6968 = 1;
// }

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F30A4_704754.s")

void add_multiple_lights(void) {
    s16 used;
    s16 i;

    used = 0;

    // copy all used lights into a contiguous lights array
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (D_803E1B20[i] > 0) {
            used++;
            D_80204278->unk3B640[used].l.col[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            D_80204278->unk3B640[used].l.col[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            D_80204278->unk3B640[used].l.col[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            D_80204278->unk3B640[used].l.colc[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            D_80204278->unk3B640[used].l.colc[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            D_80204278->unk3B640[used].l.colc[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            D_80204278->unk3B640[used].l.dir[0] = D_803E1B60[i];
            D_80204278->unk3B640[used].l.dir[1] = D_803E1B70[i];
            D_80204278->unk3B640[used].l.dir[2] = D_803E1B80[i];
        }
    }

    switch (used) {
    case 0:
        break;
    case 1:
        gSPNumLights(D_801D9E88++, 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 3);
        return;
    case 2:
        gSPNumLights(D_801D9E88++, 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[2], 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 4);
        break;
    case 3:
        gSPNumLights(D_801D9E88++, 4);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[2], 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[3], 4);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 5);
        break;
    case 4:
        gSPNumLights(D_801D9E88++, 5);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[2], 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[3], 4);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[4], 5);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 6);
        break;
    case 5:
        gSPNumLights(D_801D9E88++, 6);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[2], 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[3], 4);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[4], 5);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[5], 6);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 7);
        break;
    case 6:
        gSPNumLights(D_801D9E88++, 7);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[0], 1);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[1], 2);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[2], 3);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[3], 4);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[4], 5);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[5], 6);
        gSPLight(D_801D9E88++, &D_80204278->unk3B640[6], 7);
        gSPLight(D_801D9E88++, &D_80204278->unk3B638, 8);
        break;
    }
}

void add_single_light(Gfx** dl) {
    gSPNumLights((*dl)++, 1);
    gSPLight((*dl)++, &D_80204278->unk3B640, 1);
    gSPLight((*dl)++, &D_80204278->unk3B638, 2);
}
