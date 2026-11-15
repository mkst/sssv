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

u8  gLevelLightTransitionComplete = 1;

// ========================================================
// .bss
// ========================================================

static s16  sLocalLightIntensities[5];
static s16  sLocalLightRed[5];
static s16  sLocalLightGreen[5];
static s16  sLocalLightBlue[5];
static s16  sLocalLightDirectionX[5];
static s16  sLocalLightDirectionY[5];
static s16  sLocalLightDirectionZ[5];
static s16  sLightTransitionAmbientDeltaRed;
static s16  sLightTransitionAmbientDeltaGreen;
static s16  sLightTransitionAmbientDeltaBlue;

static s16  sLightTransitionDirectionalDeltaRed;
static s16  sLightTransitionDirectionalDeltaGreen;
static s16  sLightTransitionDirectionalDeltaBlue;
static u8   sLightTransitionStartDirectionalRed;
static u8   sLightTransitionStartDirectionalGreen;
static u8   sLightTransitionStartDirectionalBlue;
static u8   sLightTransitionStartAmbientRed;
static u8   sLightTransitionStartAmbientGreen;
static u8   sLightTransitionStartAmbientBlue;

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

u8   gWaterPrimRed; // water prim r
u8   gWaterPrimGreen; // water prim g
u8   gWaterPrimBlue; // water prim b
u8   gWaterEnvRed; // water env r
u8   gWaterEnvGreen; // water env g
u8   gWaterEnvBlue; // water env b

// ========================================================
// .text
// ========================================================

void clear_used_lights(void) {
    s16 i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        sLocalLightIntensities[i] = 0;
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

        prev = sLocalLightIntensities[0];
        next = 0;

        for (i = 1; i < MAX_LIGHTS; i++) {
            if (sLocalLightIntensities[i] < prev) {
                next = i;
                prev = sLocalLightIntensities[i];
            }
        }

        if (prev < _intensity) {
            sLocalLightIntensities[next] = _intensity;
            sLocalLightRed[next] = (r * _intensity) >> 8;
            sLocalLightGreen[next] = (g * _intensity) >> 8;
            sLocalLightBlue[next] = (b * _intensity) >> 8;

            sLocalLightDirectionX[next] = ((x - a->position.xPos.h) * 120) / delta; // direction x
            sLocalLightDirectionY[next] = ((y - a->position.zPos.h) * 120) / delta; // direction y
            sLocalLightDirectionZ[next] = ((z - a->position.yPos.h) * 120) / delta; // direction z
        }
    }
}

// reset_lights?
void reset_level_lighting(void) {
    gLevelAmbientRed = sLightTransitionAmbientDeltaRed = 80;
    gLevelAmbientGreen = sLightTransitionAmbientDeltaGreen = 80;
    gLevelAmbientBlue = sLightTransitionAmbientDeltaBlue = 80;
    gLevelDirectionalLightRed = sLightTransitionDirectionalDeltaRed = 200;
    gLevelDirectionalLightGreen = sLightTransitionDirectionalDeltaGreen = 200;
    gLevelDirectionalLightBlue = sLightTransitionDirectionalDeltaBlue = 200;
    sLightTransitionStartAmbientRed = 0;
    sLightTransitionStartAmbientGreen = 0;
    sLightTransitionStartAmbientBlue = 0;
    sLightTransitionStartDirectionalRed = 0;
    sLightTransitionStartDirectionalGreen = 0;
    sLightTransitionStartDirectionalBlue = 0;
    sLevelLightTransitionDurationTicks = sLevelLightTransitionElapsedTicks = 0;
    gLevelLightTransitionComplete = 1;
    D_803E1BA6 = 0;
}

void start_level_light_transition(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6) {
    sLightTransitionStartAmbientRed = gLevelAmbientRed;
    sLightTransitionStartAmbientGreen = gLevelAmbientGreen;
    sLightTransitionStartAmbientBlue = gLevelAmbientBlue;
    sLightTransitionStartDirectionalRed = gLevelDirectionalLightRed;
    sLightTransitionStartDirectionalGreen = gLevelDirectionalLightGreen;
    sLightTransitionStartDirectionalBlue = gLevelDirectionalLightBlue;
    sLightTransitionAmbientDeltaRed = (s16)arg0 - sLightTransitionStartAmbientRed; // these casts are required
    sLightTransitionAmbientDeltaGreen = (s16)arg1 - sLightTransitionStartAmbientGreen; // these casts are required
    sLightTransitionAmbientDeltaBlue = (s16)arg2 - sLightTransitionStartAmbientBlue; // these casts are required
    sLightTransitionDirectionalDeltaRed = (s16)arg3 - sLightTransitionStartDirectionalRed;
    sLightTransitionDirectionalDeltaGreen = (s16)arg4 - sLightTransitionStartDirectionalGreen;
    sLightTransitionDirectionalDeltaBlue = (s16)arg5 - sLightTransitionStartDirectionalBlue;
    sLevelLightTransitionDurationTicks = arg6;
    sLevelLightTransitionElapsedTicks = 0;
    gLevelLightTransitionComplete = 0;
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

    if (gLevelLightTransitionComplete == 0) {
        if (sLevelLightTransitionElapsedTicks == sLevelLightTransitionDurationTicks) {
            gLevelAmbientRed = sLightTransitionStartAmbientRed + sLightTransitionAmbientDeltaRed;
            gLevelAmbientGreen = sLightTransitionStartAmbientGreen + sLightTransitionAmbientDeltaGreen;
            gLevelAmbientBlue = sLightTransitionStartAmbientBlue + sLightTransitionAmbientDeltaBlue;
            gLevelDirectionalLightRed = sLightTransitionStartDirectionalRed + sLightTransitionDirectionalDeltaRed;
            gLevelDirectionalLightGreen = sLightTransitionStartDirectionalGreen + sLightTransitionDirectionalDeltaGreen;
            gLevelDirectionalLightBlue = sLightTransitionStartDirectionalBlue + sLightTransitionDirectionalDeltaBlue;

            gWaterPrimRed = D_803F2D50.waterPrimRed;
            gWaterPrimGreen = D_803F2D50.waterPrimGreen;
            gWaterPrimBlue = D_803F2D50.waterPrimBlue;

            gWaterEnvRed = D_803F2D50.waterEnvRed;
            gWaterEnvGreen = D_803F2D50.waterEnvGreen;
            gWaterEnvBlue = D_803F2D50.waterEnvBlue;

            gLevelLightTransitionComplete = 1;
        } else {
            var_f0 = (f32) sLevelLightTransitionElapsedTicks / sLevelLightTransitionDurationTicks;
            gLevelAmbientRed = sLightTransitionStartAmbientRed + (sLightTransitionAmbientDeltaRed * var_f0);
            gLevelAmbientGreen = sLightTransitionStartAmbientGreen + (sLightTransitionAmbientDeltaGreen * var_f0);
            gLevelAmbientBlue = sLightTransitionStartAmbientBlue + (sLightTransitionAmbientDeltaBlue * var_f0);
            gLevelDirectionalLightRed = sLightTransitionStartDirectionalRed + (sLightTransitionDirectionalDeltaRed * var_f0);
            gLevelDirectionalLightGreen = sLightTransitionStartDirectionalGreen + (sLightTransitionDirectionalDeltaGreen * var_f0);
            gLevelDirectionalLightBlue = sLightTransitionStartDirectionalBlue + (sLightTransitionDirectionalDeltaBlue * var_f0);
            // water primary
            gWaterPrimRed = (D_803F2D50.waterPrimRed + gLevelAmbientRed) / 2;
            gWaterPrimGreen = (D_803F2D50.waterPrimGreen + gLevelAmbientGreen) / 2;
            gWaterPrimBlue = (D_803F2D50.waterPrimBlue + gLevelAmbientBlue) / 2;
            // water env?
            gWaterEnvRed = (D_803F2D50.waterEnvRed + gLevelAmbientRed) / 2;
            gWaterEnvGreen = (D_803F2D50.waterEnvGreen + gLevelAmbientGreen) / 2;
            gWaterEnvBlue = (D_803F2D50.waterEnvBlue + gLevelAmbientBlue) / 2;
            sLevelLightTransitionElapsedTicks++;
        }
    } else {
        gLevelAmbientRed = sLightTransitionStartAmbientRed + sLightTransitionAmbientDeltaRed;
        gLevelAmbientGreen = sLightTransitionStartAmbientGreen + sLightTransitionAmbientDeltaGreen;
        gLevelAmbientBlue = sLightTransitionStartAmbientBlue + sLightTransitionAmbientDeltaBlue;
        gLevelDirectionalLightRed = sLightTransitionStartDirectionalRed + sLightTransitionDirectionalDeltaRed;
        gLevelDirectionalLightGreen = sLightTransitionStartDirectionalGreen + sLightTransitionDirectionalDeltaGreen;
        gLevelDirectionalLightBlue = sLightTransitionStartDirectionalBlue + sLightTransitionDirectionalDeltaBlue;
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

        gWaterEnvRed *= var_f0;
        gWaterEnvGreen *= var_f0;
        gWaterEnvBlue *= var_f0;
        gWaterPrimRed *= var_f0;
        gWaterPrimGreen *= var_f0;
        gWaterPrimBlue *= var_f0;
    } else {
        gDisplayListContext->lights.a.l.col[0] = gDisplayListContext->lights.a.l.colc[0] = gLevelAmbientRed;
        gDisplayListContext->lights.a.l.col[1] = gDisplayListContext->lights.a.l.colc[1] = gLevelAmbientGreen;
        gDisplayListContext->lights.a.l.col[2] = gDisplayListContext->lights.a.l.colc[2] = gLevelAmbientBlue;

        gDisplayListContext->lights.l[0].l.col[0] = gDisplayListContext->lights.l[0].l.colc[0] = gLevelDirectionalLightRed;
        gDisplayListContext->lights.l[0].l.col[1] = gDisplayListContext->lights.l[0].l.colc[1] = gLevelDirectionalLightGreen;
        gDisplayListContext->lights.l[0].l.col[2] = gDisplayListContext->lights.l[0].l.colc[2] = gLevelDirectionalLightBlue;

        gWaterPrimRed = ((D_803F2D50.waterPrimRed + D_803F2D50.waterPrimRed + D_803F2D50.waterPrimRed) + gLevelAmbientRed) / 4;
        gWaterPrimGreen = ((D_803F2D50.waterPrimGreen + D_803F2D50.waterPrimGreen + D_803F2D50.waterPrimGreen) + gLevelAmbientGreen) / 4;
        gWaterPrimBlue = ((D_803F2D50.waterPrimBlue + D_803F2D50.waterPrimBlue + D_803F2D50.waterPrimBlue) + gLevelAmbientBlue) / 4;
        gWaterEnvRed = ((D_803F2D50.waterEnvRed + D_803F2D50.waterEnvRed + D_803F2D50.waterEnvRed) + gLevelAmbientRed) / 4;
        gWaterEnvGreen = ((D_803F2D50.waterEnvGreen + D_803F2D50.waterEnvGreen + D_803F2D50.waterEnvGreen) + gLevelAmbientGreen) / 4;
        gWaterEnvBlue = ((D_803F2D50.waterEnvBlue + D_803F2D50.waterEnvBlue + D_803F2D50.waterEnvBlue) + gLevelAmbientBlue) / 4;
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
        if (sLocalLightIntensities[i] > 0) {
            used++;
            gDisplayListContext->lights.l[used].l.col[0] = (sLocalLightRed[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.col[1] = (sLocalLightGreen[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.col[2] = (sLocalLightBlue[i] * D_803F2A9A) >> 8;

            gDisplayListContext->lights.l[used].l.colc[0] = (sLocalLightRed[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.colc[1] = (sLocalLightGreen[i] * D_803F2A9A) >> 8;
            gDisplayListContext->lights.l[used].l.colc[2] = (sLocalLightBlue[i] * D_803F2A9A) >> 8;

            gDisplayListContext->lights.l[used].l.dir[0] = sLocalLightDirectionX[i];
            gDisplayListContext->lights.l[used].l.dir[1] = sLocalLightDirectionY[i];
            gDisplayListContext->lights.l[used].l.dir[2] = sLocalLightDirectionZ[i];
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
