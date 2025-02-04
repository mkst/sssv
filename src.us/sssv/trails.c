#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

#define TRAIL_TYPE_UNUSED  0
#define TRAIL_TYPE_REGULAR 1
#define TRAIL_TYPE_WALRUS  3
#define TRAIL_TYPE_SIMPLE  4

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (from D_803F7E10 to D_803FDEC0)
// ========================================================

static Trail gTrails[30];
static s16   trailsUsed;

static s32   bit_more_padding[4];

// ========================================================
// .text
// ========================================================

void reset_trails(void) {
    trailsUsed = 0;
    bzero_sssv((u8*)gTrails, sizeof(gTrails)); // 24720
}

void func_8039DD90_7AF440(Trail *arg0) {
    arg0->unk0.unk4 = 2;
}

// ESA: func_800884F4
Trail *add_regular_trail(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 red, u8 gren, u8 blue, u8 envRed, u8 envGreen, u8 envBlue, u8 argD, u8 argE, u8 argF, u8 arg10, u8 arg11, s32 arg12) {
    s16 i;

    if (arg12 != 0) {
        for (i = 0; i < 30; i++) {
            if ((gTrails[i].unk4 == arg12) && (gTrails[i].unk0.trailType != 0) && (gTrails[i].unk0.unk4 != 2)) {
                gTrails[i].unk1.unk4 = 1;
                return &gTrails[i];
            }
        }
    }

    for (i = 0; i < 30; i++) {
        if (gTrails[i].unk0.trailType == 0) {
            gTrails[i].trail.regular.unk240 = arg0;

            gTrails[i].unk0.trailType = 1;
            gTrails[i].unk0.unk4 = 1;

            gTrails[i].unk1.unk0 = arg11;
            gTrails[i].unk1.unk4 = 1;

            gTrails[i].trail.regular.unk0.state = arg1;

            gTrails[i].trail.regular.unk238 = arg4;
            gTrails[i].trail.regular.unk23A = arg5;
            gTrails[i].trail.regular.unk23C = arg6;

            gTrails[i].unk4 = arg12;

            gTrails[i].trail.regular.unk3 = 0;
            gTrails[i].trail.regular.unk4 = 0;
            gTrails[i].trail.regular.unk5 = arg2;

            gTrails[i].trail.regular.unk6 = red;
            gTrails[i].trail.regular.unk7 = gren;
            gTrails[i].trail.regular.unk8 = blue;

            gTrails[i].trail.regular.unk9 = envRed;
            gTrails[i].trail.regular.unkA = envGreen;
            gTrails[i].trail.regular.unkB = envBlue;

            gTrails[i].trail.regular.unkC = argD;
            gTrails[i].trail.regular.unkD = argE;
            gTrails[i].trail.regular.unkE = argF;

            gTrails[i].trail.regular.unkF = 0x80 / (arg3 * arg10);
            gTrails[i].trail.regular.unk10 = arg10;
            trailsUsed++;
            return &gTrails[i];
        }
    }

#ifdef AVOID_UB
    return NULL;
#endif
}

Trail *add_walrus_wake(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 red, u8 green, u8 blue, u8 envRed, u8 envGreen, u8 envBlue, u8 argD, u8 argE, s32 argF) {
    s16 i;

    if (argF != 0) {
        for (i = 0; i < 30; i++) {
            if ((argF == gTrails[i].unk4) && (gTrails[i].unk0.trailType != 0) && (gTrails[i].unk0.unk4 != 2)) {
                gTrails[i].unk1.unk4 = 1;
                return &gTrails[i];
            }
        }
        if ((arg0->xVelocity.h | arg0->zVelocity.h) == 0) {
            return NULL;
        }
    }

    for (i = 0; i < 30; i++) {
        if (gTrails[i].unk0.trailType == 0) {
            gTrails[i].unk0.trailType = 3;
            gTrails[i].unk0.unk4 = 1;
            gTrails[i].unk1.unk0 = argE;
            gTrails[i].unk4 = argF;

            gTrails[i].unk1.unk4 = 1;

            gTrails[i].trail.walrus.unk328 = arg0;
            gTrails[i].trail.walrus.unk0.state = arg1;

            gTrails[i].trail.walrus.unk320 = arg4;
            gTrails[i].trail.walrus.unk322 = arg5;
            gTrails[i].trail.walrus.unk324 = arg6;

            gTrails[i].trail.walrus.color[0] = red;
            gTrails[i].trail.walrus.color[1] = green;
            gTrails[i].trail.walrus.color[2] = blue;


            gTrails[i].trail.walrus.unk3 = 0;
            gTrails[i].trail.walrus.unk4 = 0;
            gTrails[i].trail.walrus.unk5 = arg2;

            gTrails[i].trail.walrus.env[0] = envRed;
            gTrails[i].trail.walrus.env[1] = envGreen;
            gTrails[i].trail.walrus.env[2] = envBlue;

            gTrails[i].trail.walrus.unkC = 0x80 / ((arg3 - 2) * argD);
            gTrails[i].trail.walrus.unkD = argD;

            trailsUsed++;
            return &gTrails[i];
        }
    }
#ifdef AVOID_UB
    return NULL;
#endif
}

// ESA: func_800889C4 (TBD)
Trail *add_simple_trail(Animal *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 red, u8 gren, u8 blue, u8 envRed, u8 envGreen, u8 envBlue, u8 argD) {
    s16 i;

    for (i = 0; i < 30; i++) {
        if (gTrails[i].unk0.trailType == 0) {
            gTrails[i].unk0.trailType = TRAIL_TYPE_SIMPLE;
            gTrails[i].unk0.unk4 = 1;

            gTrails[i].unk1.unk0 = argD;
            gTrails[i].trail.simple.unk0.state = arg1;

            gTrails[i].trail.simple.animal = arg0;

            gTrails[i].trail.simple.unk238 = arg4;
            gTrails[i].trail.simple.unk23A = arg5;
            gTrails[i].trail.simple.unk23C = arg6;

            gTrails[i].trail.simple.unk1 = 0;
            gTrails[i].trail.simple.unk2 = 0;
            gTrails[i].trail.simple.unk3 = arg2;

            gTrails[i].trail.simple.color[0] = red;
            gTrails[i].trail.simple.color[1] = gren;
            gTrails[i].trail.simple.color[2] = blue;

            gTrails[i].trail.simple.env[0] = envRed;
            gTrails[i].trail.simple.env[1] = envGreen;
            gTrails[i].trail.simple.env[2] = envBlue;

            gTrails[i].trail.simple.unkA = arg3; // only called with 32
            trailsUsed++;
            return &gTrails[i];
        }
    }
#ifdef AVOID_UB
    return NULL;
#endif
}

void func_8039E33C_7AF9EC(WalrusWake *arg0) {
    Animal *animal;
    s32 temp_lo;
    s32 xVel;
    s32 zVel;

    animal = arg0->unk328;
    arg0->unkE[arg0->numVtxs >> 1] = 0;
    arg0->unk3E[arg0->numVtxs >> 1] = 0;
    xVel = animal->xVelocity.w >> 8;
    zVel = animal->zVelocity.w >> 8;

    arg0->unkBE[arg0->numVtxs >> 1] = func_801284B8(xVel, zVel);

    // these numbers are squared, so why?
    xVel = -xVel;
    zVel = -zVel;

    if (arg0->unk0.state == 1) {
        arg0->unkBE[arg0->numVtxs >> 1] += COS(arg0->unk4) >> 0xC;
        arg0->unkBE[arg0->numVtxs >> 1] += 40;
        if (arg0->unkBE[arg0->numVtxs >> 1] >= 360) {
            arg0->unkBE[arg0->numVtxs >> 1] -= 360;
        }
    } else if (arg0->unk0.state == 2) {
        arg0->unkBE[arg0->numVtxs >> 1] -= COS(arg0->unk4) >> 0xC;
        arg0->unkBE[arg0->numVtxs >> 1] -= 40;
        if (arg0->unkBE[arg0->numVtxs >> 1] < 0) {
            arg0->unkBE[arg0->numVtxs >> 1] += 360;
        }
    }

    arg0->unk5E[arg0->numVtxs >> 1][0] = animal->position.xPos.h;
    if (1) {};
    arg0->unk5E[arg0->numVtxs >> 1][1] = animal->position.zPos.h;
    arg0->unk5E[arg0->numVtxs >> 1][2] = animal->position.yPos.h;

    arg0->unkDE[arg0->numVtxs >> 1][0] = -D_80152350.unk2D0[arg0->unkBE[arg0->numVtxs >> 1]];
    arg0->unkDE[arg0->numVtxs >> 1][1] = -D_80152350.unk384[arg0->unkBE[arg0->numVtxs >> 1]];

    temp_lo = sqrtf((SQ(xVel) + SQ(zVel) + 1));
    arg0->unk2E[arg0->numVtxs >> 1] = MIN(0x80, (temp_lo * 128) / 15360); // u8, same as (temp_lo / 120)

    if ((arg0->numVtxs >> 1) & 1) {
        arg0->vtxs[arg0->numVtxs+0].v.tc[0] = 0x7FF;
        arg0->vtxs[arg0->numVtxs+0].v.tc[1] = 0;

        arg0->vtxs[arg0->numVtxs+1].v.tc[0] = 0x7FF;
        arg0->vtxs[arg0->numVtxs+1].v.tc[1] = 0x7FF;
    } else {
        arg0->vtxs[arg0->numVtxs+0].v.tc[0] = 0;
        arg0->vtxs[arg0->numVtxs+0].v.tc[1] = 0;

        arg0->vtxs[arg0->numVtxs+1].v.tc[0] = 0;
        arg0->vtxs[arg0->numVtxs+1].v.tc[1] = 0x7FF;
    }
}

// ESA: func_80088B00
void func_8039E6D4_7AFD84(RegularTrail *arg0) {
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    s16 temp_v0;
    Animal *animal;
    struct077 sp48; // 0x6 big
    s16 pad;
    s16 sp44;
    s16 sp42;
    s16 sp40;
    float new_var;
    s32 sp38;
    s32 sp34;

    animal = arg0->unk240;
    sp40 = animal->zRotation;
    sp42 = animal->yRotation;
    sp38 = animal->xVelocity.w >> 8;
    sp34 = animal->zVelocity.w >> 8;

    if (sp38 | sp34) {
      new_var = sqrtf(SQ(sp38) + SQ(sp34));
        sp44 = func_801284B8(
            -animal->yVelocity.w >> 8, new_var);
        temp_v0 = func_801284B8(sp38, sp34);

        if (animal->unk16C->objectType >= OB_TYPE_ANIMAL_OFFSET) {
            // it's an animal
            sp42 = (sp42 * 360) / 256;
            sp40 = (sp40 * 360) / 256;
        }

        switch (arg0->unk0.state) {
        case 0:
            sp5E = (D_80152350.unk384[temp_v0] * arg0->unk5) >> 8;
            sp5C = (-D_80152350.unk2D0[temp_v0] * arg0->unk5) >> 8;
            sp5A = 0;
            break;
        case 1:
            func_802F5F44_7075F4(0, 0, arg0->unk5, 360 - sp44, temp_v0, &sp48);

            sp5E = sp48.unk0;
            sp5C = sp48.unk2;
            sp5A = sp48.unk4;
            break;
        case 2:
            sp58 = (COS(arg0->unk4) * arg0->unk5) >> 0xF;
            sp5A = (-SIN(arg0->unk4) * arg0->unk5) >> 0xF;
            sp5E = (D_80152350.unk384[temp_v0] * sp58) >> 8;
            sp5C = (D_80152350.unk2D0[temp_v0] * -sp58) >> 8;
            break;
        case 3:
            sp58 = ((COS(arg0->unk4) * arg0->unk5) >> 0xF);
            sp5A = (-SIN(arg0->unk4) * arg0->unk5) >> 0xF;
            sp5E = (D_80152350.unk384[(s16) ((s32)func_80128200() % 360)] * sp58) >> 8;
            sp5C = (D_80152350.unk2D0[(s16) ((s32)func_80128200() % 360)] * -sp58) >> 8;
            break;
        default:
            break;
        }
    } else {
        sp5A = sp5C = sp5E = 0;
    }

    func_802F5F44_7075F4(arg0->unk238, arg0->unk23A, arg0->unk23C + (animal->unk42 >> 1), sp40, sp42, &sp48);

    arg0->unk38[arg0->unk1].v.ob[0] = (animal->position.xPos.h - sp5E) + sp48.unk0;
    arg0->unk38[arg0->unk1].v.ob[1] = (animal->position.zPos.h - sp5C) + sp48.unk2;
    arg0->unk38[arg0->unk1].v.ob[2] = (animal->position.yPos.h - sp5A) + sp48.unk4;

    arg0->unk38[arg0->unk1+1].v.ob[0] = animal->position.xPos.h + sp5E + sp48.unk0;
    arg0->unk38[arg0->unk1+1].v.ob[1] = animal->position.zPos.h + sp5C + sp48.unk2;
    arg0->unk38[arg0->unk1+1].v.ob[2] = animal->position.yPos.h + sp5A + sp48.unk4;

    if ((arg0->unk1 >> 1) & 1) {
        // odd
        arg0->unk38[arg0->unk1].v.tc[0] = 0x7FF;
        arg0->unk38[arg0->unk1].v.tc[1] = 0;

        arg0->unk38[arg0->unk1+1].v.tc[0] = 0x7FF;
        arg0->unk38[arg0->unk1+1].v.tc[1] = 0x7FF;
    } else {
        // even
        arg0->unk38[arg0->unk1].v.tc[0] = 0;
        arg0->unk38[arg0->unk1].v.tc[1] = 0;

        arg0->unk38[arg0->unk1+1].v.tc[0] = 0;
        arg0->unk38[arg0->unk1+1].v.tc[1] = 0x7FF;
    }
}

#if 0
// CURRENT (3592)
extern Gfx D_01004A70_3E340[];
extern u8  D_01044CB0_7E580[];
extern u8  D_010454B0_7ED80[];

// esa:func_80088FEC
void display_trails(void) {
    s16 i; // sp19E
    s32 pad[6];
    struct077 sp17C;                                /* compiler-managed */
    f32 sp170[3];
    f32 sp164[3];

    f32 temp_f0;
    f32 temp_f2;

    s16 temp_a3;
    s16 temp_s5;
    s16 temp_s6;
    s16 temp_t0;

    s16 temp_v1;
    s16 var_a3;
    s16 var_s1;

    WalrusWake *walrusWake; // sp148?

    s32 temp_a1;
    s32 temp_t8;

    s32 var_v1;
    s32 idx;

    s16 var_s4;
    u8  var_t1;
    u8  var_t5;

    RegularTrail *trail;
    SimpleTrail *simpleTrail;
    Animal *animal;

    gSPDisplayList(D_801D9E90++, D_01004A70_3E340);

    // what macros are these? can't get _gDPLoadTextureBlock to match...
    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01044CB0_7E580); // trail
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD
    );
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 1024);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD
    );
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, (32-1) << 2, (128-1) << 2);

    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_010454B0_7ED80);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0100, G_TX_LOADTILE, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 1024);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, G_TX_RENDERTILE, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD
    );
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, (32-1) << 2, (128-1) << 2);

    if (trailsUsed > 0) {
        for (i = 0; i < 30; i++) {
            switch (gTrails[i].unk0.trailType) {
            case 0:
                break; // continue does the same

            case 1:
                trail = &gTrails[i].trail.regular;
                animal = trail->unk240;
                if ((gTrails[i].unk0.unk4 != 2)) {
                    // TBD..
                    if (((gTrails[i].unk1.unk0 == 2) && (gTrails[i].unk1.unk4 == 0)) || (animal->unk26C != 0)) {
                        gTrails[i].unk0.unk4 = 2;
                        gTrails[i].unk4 = 0;
                    }
                }

                gTrails[i].unk1.unk4 = 0;

                if (trail->unk3 == 0) {
                    if (gTrails[i].unk0.unk4 != 2) {
                        if (gTrails[i].unk0.unk4 == 1) {
                            gTrails[i].unk0.unk4 = 0;
                            trail->unk2 = trail->unk1 = 0; // maybe?
                            trail->unk12[0] = 0;
                            func_8039E6D4_7AFD84(trail);
                        }
                        trail->unk1 = (trail->unk1 + 2) & 0x1F;
                        if (trail->unk1 == trail->unk2) {
                            trail->unk2 = (trail->unk2 + 2) & 0x1F;
                        }
                        trail->unk12[trail->unk1 >> 1] = 0;
                    }
                }

                if (gTrails[i].unk0.unk4 != 2) {
                    func_8039E6D4_7AFD84(trail);
                }

                for (var_s4 = trail->unk2; var_s4 != trail->unk1; var_s4 = (var_s4 + 2) & 0x1F) {
                    trail->unk12[var_s4 >> 1] += trail->unkF;
                    if (trail->unk12[var_s4 >> 1] >= 0x80) {
                        trail->unk2 = (trail->unk2 + 2) & 0x1F;
                        if (trail->unk2 == trail->unk1) {
                            trailsUsed--;
                            gTrails[i].unk0.trailType = 0;
                            break; // break out of the loop
                        }
                    } else {
                        trail->unk38[(var_s4 >> 1)+0].v.cn[3] = 0x80 - trail->unk12[var_s4 >> 1];
                        trail->unk38[(var_s4 >> 1)+1].v.cn[3] = 0x80 - trail->unk12[var_s4 >> 1];
                    }
                }

                gSPVertex(D_801D9E90++, trail->unk38, 32, 0);
                gDPSetCombineMode(D_801D9E90++, G_CC_BLENDPE, G_CC_BLENDPE);
                gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                for (var_s1 = trail->unk2; var_s1 != trail->unk1; var_s1 = (var_s1 + 2) & 0x1F) {
                    temp_f2 = (f32)trail->unk12[var_s1 >> 1] / 128;

                    sp164[0] = trail->unkC * temp_f2;
                    sp164[1] = trail->unkD * temp_f2;
                    sp164[2] = trail->unkE * temp_f2;

                    temp_f0 = 1.0f - temp_f2;

                    sp170[0] = sp164[0] + (trail->unk6 * temp_f0);
                    sp170[1] = sp164[1] + (trail->unk7 * temp_f0);
                    sp170[2] = sp164[2] + (trail->unk8 * temp_f0);

                    gDPSetPrimColor(D_801D9E90++, 0, 0, sp170[0], sp170[1], sp170[2], 0xFF);

                    sp170[0] = sp164[0] + (trail->unk9 * temp_f0);
                    sp170[1] = sp164[1] + (trail->unkA * temp_f0);
                    sp170[2] = sp164[2] + (trail->unkB * temp_f0);

                    gDPSetEnvColor(D_801D9E90++, sp170[0], sp170[1], sp170[2], 0xFF);

                    // temp_s0_42->words.w0 = ((temp_v0_15 & 0xFF) << 0x10) | (((((var_s1 + 3) & 0x1F) * 2) & 0xFF) << 8) | ((temp_v0_15 + 2) & 0xFF) | 0xB1000000;
                    // temp_s0_42->words.w1 = ((temp_v0_15 & 0xFF) << 0x10) | (((((var_s1 + 2) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1 + 3) & 0x1F) * 2) & 0xFF);
                    gSP2Triangles(
                        D_801D9E90++,
                        (var_s1 + 0),
                        (var_s1 + 3) & 0x1F,
                        (var_s1 + 1),
                        0,
                        (var_s1 + 0),
                        (var_s1 + 2) & 0x1F,
                        (var_s1 + 3) & 0x1F,
                        0
                    );
                }

                trail->unk3 += 1;
                trail->unk3 = (trail->unk3 % trail->unk10);
                trail->unk4 += 0x20;
                break;

            case 4:
                simpleTrail = &gTrails[i].trail.simple;
                animal = simpleTrail->animal;

                if (animal->unk26C != 0) {
                    if (gTrails[i].unk0.unk4 != 2U) {
                        gTrails[i].unk0.unk4 = 2U;
                    }
                }

                if (gTrails[i].unk0.unk4 != 2) {
                    simpleTrail->unk2C = animal->position.xPos.h;
                    simpleTrail->unk2E = animal->position.zPos.h;
                    simpleTrail->unk30 = animal->position.yPos.h + (animal->unk42 >> 1);
                } else {
                    simpleTrail->unk2 = simpleTrail->unk2 + 6;
                    if (simpleTrail->unk2 >= 192) {
                        gTrails[i].unk0.trailType = 0;
                        break;
                    }
                }

                for (var_a3 = 0; var_a3 < simpleTrail->unkA; var_a3 += 2) {
                    idx = (((var_a3 >> 1) * 360) / (simpleTrail->unkA >> 1));

                    if (var_a3 & 2) {
                        var_v1 =  (COS(simpleTrail->unk1) << 5) >> 0xF;
                    } else {
                        var_v1 = -(COS(simpleTrail->unk1) << 5) >> 0xF;
                    }

                    temp_t8 = ((var_v1 + 0x100) * animal->unk40) >> 0xB;
                    temp_a1 = (((simpleTrail->unk3 * 8) * animal->unk40) >> 0xB);
                    temp_a1 = temp_a1 + temp_t8;

                    if (0) {};

                    simpleTrail->unk38[var_a3+0].v.ob[0] = (D_80152350.unk384[(s16)idx] * temp_t8) >> 8;
                    simpleTrail->unk38[var_a3+0].v.ob[1] = 0;
                    simpleTrail->unk38[var_a3+0].v.ob[2] = (D_80152350.unk2D0[(s16)idx] * temp_t8) >> 8;

                    simpleTrail->unk38[var_a3+1].v.ob[0] = (D_80152350.unk384[(s16)idx] * temp_a1) >> 8;
                    simpleTrail->unk38[var_a3+1].v.ob[1] = 0;
                    simpleTrail->unk38[var_a3+1].v.ob[2] = (D_80152350.unk2D0[(s16)idx] * temp_a1) >> 8;

                    simpleTrail->unk38[var_a3+0].v.cn[3] = 0xC0 - simpleTrail->unk2;
                    simpleTrail->unk38[var_a3+1].v.cn[3] = 0xC0 - simpleTrail->unk2;

                    if ((var_a3 >> 1) & 1) {
                        simpleTrail->unk38[var_a3+0].v.tc[0] = 0x7FF;
                        simpleTrail->unk38[var_a3+0].v.tc[1] = 0;

                        simpleTrail->unk38[var_a3+1].v.tc[0] = 0x7FF;
                        simpleTrail->unk38[var_a3+1].v.tc[1] = 0x7FF;
                    } else {
                        simpleTrail->unk38[var_a3+0].v.tc[0] = 0;
                        simpleTrail->unk38[var_a3+0].v.tc[1] = 0;

                        simpleTrail->unk38[var_a3+1].v.tc[0] = 0;
                        simpleTrail->unk38[var_a3+1].v.tc[1] = 0x7FF;
                    }
                }

                if (func_8029A334_6AB9E4(simpleTrail->unk2C, simpleTrail->unk2E, simpleTrail->unk30) != 0) {
                    gDPSetCombineMode(D_801D9E90++, G_CC_BLENDPE, G_CC_BLENDPE);
                    gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                    gDPSetPrimColor(D_801D9E90++, 0, 0, simpleTrail->color[0], simpleTrail->color[1], simpleTrail->color[2], 0xFF);

                    gDPSetEnvColor(D_801D9E90++, simpleTrail->env[0], simpleTrail->env[1], simpleTrail->env[2], 0xFF);

                    guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (f32) simpleTrail->unk2C, (f32) simpleTrail->unk2E, (f32) simpleTrail->unk30);
                    gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    // 0x4280 -> 64.0
                    // 0x4100 -> 8.0
                    temp_f2 = ((simpleTrail->unk2 / (1 / 0.015625f)) / (1 / 0.125f));
                    guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], temp_f2 + 0.125, temp_f2 + 0.125, temp_f2 + 0.125);
                    gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], animal->yRotation, 0.0f, 0.0f, 1.0f);
                    gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], animal->zRotation, 1.0f, 0.0f, 0.0f);
                    gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                    gSPVertex(D_801D9E90++, &simpleTrail->unk38, 32, 0);

                    gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                    temp_a3 = simpleTrail->unkA - 1;
                    for (var_s1 = 0; var_s1 < simpleTrail->unkA; var_s1 += 2) {
                        // temp_s0_27->words.w0 = (((var_s1 * 2) & 0xFF) << 0x10) | (((((var_s1 + 3) & temp_a3) * 2) & 0xFF) << 8) | (((var_s1 * 2) + 2) & 0xFF) | 0xB1000000;
                        // temp_s0_27->words.w1 = (((var_s1 * 2) & 0xFF) << 0x10) | (((((var_s1 + 2) & temp_a3) * 2) & 0xFF) << 8) | ((((var_s1 + 3) & temp_a3) * 2) & 0xFF);
                        gSP2Triangles(
                            D_801D9E90++,
                            (var_s1 + 0),
                            (var_s1 + 3) & (temp_a3),
                            (var_s1 + 1),
                            0,
                            (var_s1 + 0),
                            (var_s1 + 2) & (temp_a3),
                            (var_s1 + 3) & (temp_a3),
                            0
                        );
                    }
                }
                simpleTrail->unk1 += 2; // numTris / numVtx
                break;

            case 3:
                walrusWake = &gTrails[i].trail.walrus;
                animal = walrusWake->unk328;

                if (gTrails[i].unk0.unk4 != 2) {
                    if ((animal->xVelocity.h | animal->zVelocity.h) != 0) {
                        var_t5 = 1;
                    } else {
                        var_t5 = 0;
                    }
                } else {
                    var_t5 = 0;
                }

                if ((gTrails[i].unk0.unk4 != 2) &&
                    (((gTrails[i].unk1.unk0 == 2) && (gTrails[i].unk1.unk4 == 0)) || (animal->unk26C != 0))) {
                    gTrails[i].unk0.unk4 = 2;
                    gTrails[i].unk4 = 0;
                }

                gTrails[i].unk1.unk4 = 0;
                if ((walrusWake->unk3 == 0) && (gTrails[i].unk0.unk4 != 2)) {
                    if (gTrails[i].unk0.unk4 == 1) {
                        gTrails[i].unk0.unk4 = 0;

                        walrusWake->unk2 = walrusWake->unk4 = 0;
                        walrusWake->numVtxs = 0;
                        func_8039E33C_7AF9EC(walrusWake);
                    }
                    if (var_t5) {
                        walrusWake->numVtxs = (walrusWake->numVtxs + 2) & 0x1F;
                        if (walrusWake->unk2 == walrusWake->numVtxs) {
                            walrusWake->unk2 = (walrusWake->unk2 + 2) & 0x1F;
                        }
                        walrusWake->unk4 += 40;
                        func_8039E33C_7AF9EC(walrusWake);
                    }
                }

                for (var_t1 = 0, var_s4 = walrusWake->unk2; var_t1 == 0; var_s4 = (var_s4 + 2) & 0x1F) {
                    if (!var_t5) {
                        if (walrusWake->unkE[var_s4 >> 1] < 0x40) {
                            walrusWake->unkE[var_s4 >> 1] = 0x80 - walrusWake->unkE[var_s4 >> 1];
                        }
                    }

                    walrusWake->unkE[var_s4 >> 1] += walrusWake->unkC;
                    walrusWake->unk3E[var_s4 >> 1] += walrusWake->unkC; // CHECK
                    if (walrusWake->unkE[var_s4 >> 1] >= 0x80) {
                        walrusWake->unkE[var_s4 >> 1] = 0x80;
                        if ((var_s4 == walrusWake->unk2)) {
                            // first iteration?
                            walrusWake->unk2 = (walrusWake->unk2 + 2) & 0x1F;
                            if ((walrusWake->numVtxs == walrusWake->unk2) && (gTrails[i].unk1.unk0 != 0)) {
                                  trailsUsed--;
                                  gTrails[i].unk0.trailType = 0;
                                  break; // break out of the loop entirely
                            }
                        }
                    } else {
                        temp_s6 = ((walrusWake->unk2E[var_s4 >> 1]) * (SIN(walrusWake->unkE[var_s4 >> 1]) >> 8)) >> 7;
                        walrusWake->vtxs[var_s4 + 0].v.cn[3] = temp_s6;
                        walrusWake->vtxs[var_s4 + 1].v.cn[3] = temp_s6;

                        temp_t0 = walrusWake->unkBE[var_s4 >> 1]; //unkE;
                        temp_a3 = ((walrusWake->unk3E[var_s4 >> 1] * walrusWake->unk5) >> 5) + walrusWake->unk5;

                        temp_s5 = ( D_80152350.unk384[temp_t0] * temp_a3) >> 8;
                        temp_s6 = (-D_80152350.unk2D0[temp_t0] * temp_a3) >> 8;
                        func_802F5F44_7075F4(walrusWake->unk320, walrusWake->unk322, walrusWake->unk324, 0, temp_t0, &sp17C);

                        if (0) {}; // probably not

                        temp_v1 = SIN(walrusWake->unk3E[var_s4 >> 1]);

                        sp17C.unk0 += ((temp_v1 * walrusWake->unkDE[var_s4 >> 1][0]) >> 0x11);
                        sp17C.unk2 += ((temp_v1 * walrusWake->unkDE[var_s4 >> 1][1]) >> 0x11);

                        sp17C.unk0 += (walrusWake->unk3E[var_s4 >> 1] * walrusWake->unkDE[var_s4 >> 1][0]) >> 8;
                        sp17C.unk2 += (walrusWake->unk3E[var_s4 >> 1] * walrusWake->unkDE[var_s4 >> 1][1]) >> 8;

                        walrusWake->vtxs[var_s4+0].v.ob[0] = sp17C.unk0 + (walrusWake->unk5E[var_s4 >> 1][0] + temp_s5);
                        walrusWake->vtxs[var_s4+0].v.ob[1] = sp17C.unk2 + (walrusWake->unk5E[var_s4 >> 1][1] + temp_s6);
                        walrusWake->vtxs[var_s4+0].v.ob[2] = sp17C.unk4 + (walrusWake->unk5E[var_s4 >> 1][2]          );


                        walrusWake->vtxs[var_s4+1].v.ob[0] = sp17C.unk0 + (walrusWake->unk5E[var_s4 >> 1][0] - temp_s5);
                        walrusWake->vtxs[var_s4+1].v.ob[1] = sp17C.unk2 + (walrusWake->unk5E[var_s4 >> 1][1] - temp_s6);
                        walrusWake->vtxs[var_s4+1].v.ob[2] = sp17C.unk4 + (walrusWake->unk5E[var_s4 >> 1][2]          );
                    }
                    if (var_s4 == walrusWake->numVtxs) {
                        var_t1 = 1; // break
                    }
                }

                gSPVertex(D_801D9E90++, &walrusWake->vtxs, 32, 0);
                gDPSetCombineMode(D_801D9E90++, G_CC_BLENDPE, G_CC_BLENDPE);
                gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                gDPSetPrimColor(D_801D9E90++, 0, 0, walrusWake->color[0], walrusWake->color[1], walrusWake->color[2], 0xFF);
                gDPSetEnvColor(D_801D9E90++, walrusWake->env[0], walrusWake->env[1], walrusWake->env[2], 0xFF);
                gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0020, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                for (var_s1 = walrusWake->unk2; var_s1 != walrusWake->numVtxs; var_s1 = (var_s1 + 2) & 0x1F) {
                    // temp_s0_36->words.w0 = ((((var_s1_2 + 0) * 2) & 0xFF) << 0x10) | (((((var_s1_2 + 3) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1_2 + 1)) & 0xFF) | 0xB1000000;
                    // temp_s0_36->words.w1 = ((((var_s1_2 + 0) * 2) & 0xFF) << 0x10) | (((((var_s1_2 + 2) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1_2 + 3) & 0x1F) * 2) & 0xFF);
                    gSP2Triangles(
                        D_801D9E90++,
                        (var_s1 + 0),
                        (var_s1 + 3) & 0x1F,
                        (var_s1 + 1),
                        0,
                        (var_s1 + 0),
                        (var_s1 + 2) & 0x1F,
                        (var_s1 + 3) & 0x1F,
                        0
                    );
                }

                walrusWake->unk3++;
                walrusWake->unk3 %= walrusWake->unkD;
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/trails/display_trails.s")
#endif
