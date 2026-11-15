#include <ultra64.h>
#include "common.h"

// ========================================================
// .data
// ========================================================

u8  gLevelAmbientRed = 80;
u8  gLevelAmbientGreen = 80;
u8  gLevelAmbientBlue = 80;

u8  gLevelDirectionalLightRed = 200;
u8  gLevelDirectionalLightGreen = 200;
u8  gLevelDirectionalLightBlue = 200;

u8  D_803A52B8_7B6968 = 1;

// ========================================================
// .bss
// ========================================================

static s16  D_803E1B20[5];
static s16  D_803E1B30[5];
static s16  D_803E1B40[5];
static s16  D_803E1B50[5];
static s16  D_803E1B60[5];
static s16  D_803E1B70[5];
static s16  D_803E1B80[5];
static s16  D_803E1B8A;
static s16  D_803E1B8C;
static s16  D_803E1B8E;

static s16  D_803E1B90;
static s16  D_803E1B92;
static s16  D_803E1B94;
static u8   D_803E1B96;
static u8   D_803E1B97;
static u8   D_803E1B98;
static u8   D_803E1B99;
static u8   D_803E1B9A;
static u8   D_803E1B9B;

static s32  D_803E1B9C; // unused
static s16  D_803E1BA0; // unused

static u16  sLevelLightTransitionDurationTicks;
static u16  sLevelLightTransitionElapsedTicks;
static u8   D_803E1BA6;
static s16  D_803E1BA8;
static s16  D_803E1BAA;
static s16  D_803E1BAC;
static s16  D_803E1BAE;
static s16  D_803E1BB0;
static s16  D_803E1BB2;
static s16  D_803E1BB4;
static s16  D_803E1BB6;
static s16  D_803E1BB8;

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

    a = gAnimalState.animals[gCurrentAnimalIndex].animal;

    delta = ABS(a->position.xPos.h - x) +
            ABS(a->position.zPos.h - y) +
            ABS(a->position.yPos.h - z);

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

            D_803E1B60[next] = ((x - a->position.xPos.h) * 120) / delta; // direction x
            D_803E1B70[next] = ((y - a->position.zPos.h) * 120) / delta; // direction y
            D_803E1B80[next] = ((z - a->position.yPos.h) * 120) / delta; // direction z
        }
    }
}

// reset_lights?
void reset_level_lighting(void) {
    gLevelAmbientRed = D_803E1B8A = 80;
    gLevelAmbientGreen = D_803E1B8C = 80;
    gLevelAmbientBlue = D_803E1B8E = 80;
    gLevelDirectionalLightRed = D_803E1B90 = 200;
    gLevelDirectionalLightGreen = D_803E1B92 = 200;
    gLevelDirectionalLightBlue = D_803E1B94 = 200;
    D_803E1B99 = 0;
    D_803E1B9A = 0;
    D_803E1B9B = 0;
    D_803E1B96 = 0;
    D_803E1B97 = 0;
    D_803E1B98 = 0;
    sLevelLightTransitionDurationTicks = sLevelLightTransitionElapsedTicks = 0;
    D_803A52B8_7B6968 = 1;
    D_803E1BA6 = 0;
}

void start_level_light_transition(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6) {
    D_803E1B99 = gLevelAmbientRed;
    D_803E1B9A = gLevelAmbientGreen;
    D_803E1B9B = gLevelAmbientBlue;
    D_803E1B96 = gLevelDirectionalLightRed;
    D_803E1B97 = gLevelDirectionalLightGreen;
    D_803E1B98 = gLevelDirectionalLightBlue;
    D_803E1B8A = (s16)arg0 - D_803E1B99; // these casts are required
    D_803E1B8C = (s16)arg1 - D_803E1B9A; // these casts are required
    D_803E1B8E = (s16)arg2 - D_803E1B9B; // these casts are required
    D_803E1B90 = (s16)arg3 - D_803E1B96;
    D_803E1B92 = (s16)arg4 - D_803E1B97;
    D_803E1B94 = (s16)arg5 - D_803E1B98;
    sLevelLightTransitionDurationTicks = arg6;
    sLevelLightTransitionElapsedTicks = 0;
    D_803A52B8_7B6968 = 0;
}

// unused
void func_802F301C_7046CC(u8 ambientRed, u8 ambientGreen, u8 ambientBlue, u8 envRed, u8 envGreen, u8 envBlue, u16 arg6, u16 arg7) {
    D_803E1BAE = ambientRed;
    D_803E1BB0 = ambientGreen;
    D_803E1BB2 = ambientBlue;
    D_803E1BB4 = envRed;
    D_803E1BB6 = envGreen;
    D_803E1BB8 = envBlue;
    D_803E1BA6 = 1;
    D_803E1BA8 = 0;
    D_803E1BAA = arg6;
    D_803E1BAC = arg7;
}

void update_level_lighting(void) {
    f32 var_f14;
    f32 var_f16;
    f32 var_f0;
    f32 var_f2;
    f32 var_f18;
    f32 var_f20;
    f32 var_f22;
    f32 temp;

    if (D_803A52B8_7B6968 == 0) {
        if (sLevelLightTransitionElapsedTicks == sLevelLightTransitionDurationTicks) {
            gLevelAmbientRed = D_803E1B99 + D_803E1B8A;
            gLevelAmbientGreen = D_803E1B9A + D_803E1B8C;
            gLevelAmbientBlue = D_803E1B9B + D_803E1B8E;
            gLevelDirectionalLightRed = D_803E1B96 + D_803E1B90;
            gLevelDirectionalLightGreen = D_803E1B97 + D_803E1B92;
            gLevelDirectionalLightBlue = D_803E1B98 + D_803E1B94;

            D_803E1BBA = D_803F2D50.waterPrimRed;
            D_803E1BBB = D_803F2D50.waterPrimGreen;
            D_803E1BBC = D_803F2D50.waterPrimBlue;

            D_803E1BBD = D_803F2D50.waterEnvRed;
            D_803E1BBE = D_803F2D50.waterEnvGreen;
            D_803E1BBF = D_803F2D50.waterEnvBlue;

            D_803A52B8_7B6968 = 1;
        } else {
            var_f0 = (f32) sLevelLightTransitionElapsedTicks / sLevelLightTransitionDurationTicks;
            gLevelAmbientRed = D_803E1B99 + (D_803E1B8A * var_f0);
            gLevelAmbientGreen = D_803E1B9A + (D_803E1B8C * var_f0);
            gLevelAmbientBlue = D_803E1B9B + (D_803E1B8E * var_f0);
            gLevelDirectionalLightRed = D_803E1B96 + (D_803E1B90 * var_f0);
            gLevelDirectionalLightGreen = D_803E1B97 + (D_803E1B92 * var_f0);
            gLevelDirectionalLightBlue = D_803E1B98 + (D_803E1B94 * var_f0);
            // water primary
            D_803E1BBA = (D_803F2D50.waterPrimRed + gLevelAmbientRed) / 2;
            D_803E1BBB = (D_803F2D50.waterPrimGreen + gLevelAmbientGreen) / 2;
            D_803E1BBC = (D_803F2D50.waterPrimBlue + gLevelAmbientBlue) / 2;
            // water env?
            D_803E1BBD = (D_803F2D50.waterEnvRed + gLevelAmbientRed) / 2;
            D_803E1BBE = (D_803F2D50.waterEnvGreen + gLevelAmbientGreen) / 2;
            D_803E1BBF = (D_803F2D50.waterEnvBlue + gLevelAmbientBlue) / 2;
            sLevelLightTransitionElapsedTicks++;
        }
    } else {
        gLevelAmbientRed = D_803E1B99 + D_803E1B8A;
        gLevelAmbientGreen = D_803E1B9A + D_803E1B8C;
        gLevelAmbientBlue = D_803E1B9B + D_803E1B8E;
        gLevelDirectionalLightRed = D_803E1B96 + D_803E1B90;
        gLevelDirectionalLightGreen = D_803E1B97 + D_803E1B92;
        gLevelDirectionalLightBlue = D_803E1B98 + D_803E1B94;
    }

    if (D_803E1BA6 != 0) {
        if (D_803E1BAA >= D_803E1BA8) {
            if (D_803E1BAA == 0) {
                var_f0 = 1.0f;
            } else {
                var_f0 = (f32) D_803E1BA8 / D_803E1BAA;
            }
            gLevelAmbientRed += ((f32) D_803E1BAE - gLevelAmbientRed) * var_f0;
            gLevelAmbientGreen += ((f32) D_803E1BB0 - gLevelAmbientGreen) * var_f0;
            gLevelAmbientBlue += ((f32) D_803E1BB2 - gLevelAmbientBlue) * var_f0;
            gLevelDirectionalLightRed += ((f32) D_803E1BB4 - gLevelDirectionalLightRed) * var_f0;
            gLevelDirectionalLightGreen += ((f32) D_803E1BB6 - gLevelDirectionalLightGreen) * var_f0;
            gLevelDirectionalLightBlue += ((f32) D_803E1BB8 - gLevelDirectionalLightBlue) * var_f0;
        } else if ((D_803E1BAA + D_803E1BAC) >= D_803E1BA8) {
            if (D_803E1BAA == 0) {
                var_f0 = 1.0f;
            } else {
                var_f0 = ((f32) D_803E1BA8 - D_803E1BAA) / D_803E1BAC;
            }
            gLevelAmbientRed = D_803E1BAE + (((f32) gLevelAmbientRed - D_803E1BAE) * var_f0);
            gLevelAmbientGreen = D_803E1BB0 + (((f32) gLevelAmbientGreen - D_803E1BB0) * var_f0);
            gLevelAmbientBlue = D_803E1BB2 + (((f32) gLevelAmbientBlue - D_803E1BB2) * var_f0);
            gLevelDirectionalLightRed = D_803E1BB4 + (((f32) gLevelDirectionalLightRed - D_803E1BB4) * var_f0);
            gLevelDirectionalLightGreen = D_803E1BB6 + (((f32) gLevelDirectionalLightGreen - D_803E1BB6) * var_f0);
            gLevelDirectionalLightBlue = D_803E1BB8 + (((f32) gLevelDirectionalLightBlue - D_803E1BB8) * var_f0);
        } else {
            D_803E1BA6 = 0;
        }
        D_803E1BA8++;
    }
    if (D_803F2A9A != 0x100) {
        var_f0 = (f32) D_803F2A9A / 256;

        gDisplayListContext->lights.a.l.col[0] = gDisplayListContext->lights.a.l.colc[0] = gLevelAmbientRed * var_f0;
        gDisplayListContext->lights.a.l.col[1] = gDisplayListContext->lights.a.l.colc[1] = gLevelAmbientGreen * var_f0;
        gDisplayListContext->lights.a.l.col[2] = gDisplayListContext->lights.a.l.colc[2] = gLevelAmbientBlue * var_f0;

        gDisplayListContext->lights.l[0].l.col[0] = gDisplayListContext->lights.l[0].l.colc[0] = gLevelDirectionalLightRed * var_f0;
        gDisplayListContext->lights.l[0].l.col[1] = gDisplayListContext->lights.l[0].l.colc[1] = gLevelDirectionalLightGreen * var_f0;
        gDisplayListContext->lights.l[0].l.col[2] = gDisplayListContext->lights.l[0].l.colc[2] = gLevelDirectionalLightBlue * var_f0;

        D_803E1BBD *= var_f0;
        D_803E1BBE *= var_f0;
        D_803E1BBF *= var_f0;
        D_803E1BBA *= var_f0;
        D_803E1BBB *= var_f0;
        D_803E1BBC *= var_f0;
    } else {
        gDisplayListContext->lights.a.l.col[0] = gDisplayListContext->lights.a.l.colc[0] = gLevelAmbientRed;
        gDisplayListContext->lights.a.l.col[1] = gDisplayListContext->lights.a.l.colc[1] = gLevelAmbientGreen;
        gDisplayListContext->lights.a.l.col[2] = gDisplayListContext->lights.a.l.colc[2] = gLevelAmbientBlue;

        gDisplayListContext->lights.l[0].l.col[0] = gDisplayListContext->lights.l[0].l.colc[0] = gLevelDirectionalLightRed;
        gDisplayListContext->lights.l[0].l.col[1] = gDisplayListContext->lights.l[0].l.colc[1] = gLevelDirectionalLightGreen;
        gDisplayListContext->lights.l[0].l.col[2] = gDisplayListContext->lights.l[0].l.colc[2] = gLevelDirectionalLightBlue;

        D_803E1BBA = ((D_803F2D50.waterPrimRed + D_803F2D50.waterPrimRed + D_803F2D50.waterPrimRed) + gLevelAmbientRed) / 4;
        D_803E1BBB = ((D_803F2D50.waterPrimGreen + D_803F2D50.waterPrimGreen + D_803F2D50.waterPrimGreen) + gLevelAmbientGreen) / 4;
        D_803E1BBC = ((D_803F2D50.waterPrimBlue + D_803F2D50.waterPrimBlue + D_803F2D50.waterPrimBlue) + gLevelAmbientBlue) / 4;
        D_803E1BBD = ((D_803F2D50.waterEnvRed + D_803F2D50.waterEnvRed + D_803F2D50.waterEnvRed) + gLevelAmbientRed) / 4;
        D_803E1BBE = ((D_803F2D50.waterEnvGreen + D_803F2D50.waterEnvGreen + D_803F2D50.waterEnvGreen) + gLevelAmbientGreen) / 4;
        D_803E1BBF = ((D_803F2D50.waterEnvBlue + D_803F2D50.waterEnvBlue + D_803F2D50.waterEnvBlue) + gLevelAmbientBlue) / 4;
    }

    if (D_803F2D50.useDynamicLightDir != 0) {
        var_f20 = (-D_80204218 * cosf(0.7853947f)) + (-D_8020421C * sinf(0.7853947f));
        var_f22 = (-D_8020421C * cosf(0.7853947f)) - (-D_80204218 * sinf(0.7853947f));

        var_f2 = -D_80204220;
        var_f18 = MAX(ABSF(var_f20), ABSF(var_f22));

        var_f0 = sqrtf(SQ(var_f20) + SQ(var_f22));
        var_f16 = var_f0 / (ABSF(var_f2) + 1.0);

        if (var_f18 == 0.0f) {
            var_f18 = 1.0f;
        }

        var_f20 *= 127.0f / var_f18;
        var_f22 *= 127.0f / var_f18;

        if (var_f16 < 0.25) {
            var_f20 += 4 * (127.0 - var_f20) * (0.25 - var_f16);
            var_f22 += 4 * (0.0 - var_f22) * (0.25 - var_f16);
        }
        var_f2 = 50.0f;
    } else {
        var_f20 = D_803F2D50.lightDirX;
        var_f22 = D_803F2D50.lightDirY;
        var_f2 = D_803F2D50.lightDirZ;
    }

    gDisplayListContext->lights.l[0].l.dir[0] = (s32)var_f20;
    gDisplayListContext->lights.l[0].l.dir[1] = (s32)var_f22;
    gDisplayListContext->lights.l[0].l.dir[2] = (s32)var_f2;

    add_single_light(&gMainDL);
}

void add_multiple_lights(void) {
    s16 used;
    s16 i;

    used = 0;

    // copy all used lights into a contiguous lights array
    for (i = 0; i < MAX_LIGHTS; i++) {
        if (D_803E1B20[i] > 0) {
            used++;
            gDisplayListContext->lights.l[used].l.col[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.col[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.col[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            gDisplayListContext->lights.l[used].l.colc[0] = (D_803E1B30[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.colc[1] = (D_803E1B40[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.colc[2] = (D_803E1B50[i] * D_803F2A9A) >> 8;

            gDisplayListContext->lights.l[used].l.dir[0] = D_803E1B60[i];
            gDisplayListContext->lights.l[used].l.dir[1] = D_803E1B70[i];
            gDisplayListContext->lights.l[used].l.dir[2] = D_803E1B80[i];
        }
    }

    switch (used) {
    case 0:
        break;
    case 1:
        gSPSetLights2(gOpaqueDL++, gDisplayListContext->lights);
        return;
    case 2:
        gSPSetLights3(gOpaqueDL++, gDisplayListContext->lights);
        break;
    case 3:
        gSPSetLights4(gOpaqueDL++, gDisplayListContext->lights);
        break;
    case 4:
        gSPSetLights5(gOpaqueDL++, gDisplayListContext->lights);
        break;
    case 5:
        gSPSetLights6(gOpaqueDL++, gDisplayListContext->lights);
        break;
    case 6:
        gSPSetLights7(gOpaqueDL++, gDisplayListContext->lights);
        break;
    }
}

void add_single_light(Gfx** dl) {
    gSPSetLights1((*dl)++, gDisplayListContext->lights);
}
