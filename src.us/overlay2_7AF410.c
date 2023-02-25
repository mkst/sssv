#include <ultra64.h>

#include "common.h"


#define TRAIL_TYPE_UNUSED  0
#define TRAIL_TYPE_REGULAR 1
#define TRAIL_TYPE_WALRUS  3
#define TRAIL_TYPE_SIMPLE  4


void reset_trails(void) {
    D_803FDEA0 = 0; // trails used = 0
    bzero_sssv((u8*)gTrails, sizeof(gTrails)); // 24720
}

void func_8039DD90_7AF440(Trail *arg0) {
    arg0->unk0.unk4 = 2;
}

Trail *add_regular_trail(struct071 *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 red, u8 gren, u8 blue, u8 envRed, u8 envGreen, u8 envBlue, u8 argD, u8 argE, u8 argF, u8 arg10, u8 arg11, s32 arg12) {
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
            D_803FDEA0++;
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

            gTrails[i].trail.walrus.red = red;
            gTrails[i].trail.walrus.green = green;
            gTrails[i].trail.walrus.blue = blue;


            gTrails[i].trail.walrus.unk3 = 0;
            gTrails[i].trail.walrus.unk4 = 0;
            gTrails[i].trail.walrus.unk5 = arg2;

            gTrails[i].trail.walrus.envRed = envRed;
            gTrails[i].trail.walrus.envGreen = envGreen;
            gTrails[i].trail.walrus.envBlue = envBlue;

            gTrails[i].trail.walrus.unkC = 0x80 / ((arg3 - 2) * argD);
            gTrails[i].trail.walrus.unkD = argD;

            D_803FDEA0++;
            return &gTrails[i];
        }
    }
#ifdef AVOID_UB
    return 0;
#endif
}

Trail *add_simple_trail(s32 arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, u8 red, u8 gren, u8 blue, u8 envRed, u8 envGreen, u8 envBlue, u8 argD) {
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

            gTrails[i].trail.simple.red = red;
            gTrails[i].trail.simple.green = gren;
            gTrails[i].trail.simple.blue = blue;

            gTrails[i].trail.simple.envRed = envRed;
            gTrails[i].trail.simple.envGreen = envGreen;
            gTrails[i].trail.simple.envBlue = envBlue;

            gTrails[i].trail.simple.unkA = arg3; // only called with 32
            D_803FDEA0++;
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
        arg0->unkBE[arg0->numVtxs >> 1] += D_80152C78[(arg0->unk4 + 0x40) & 0xFF] >> 0xC;
        arg0->unkBE[arg0->numVtxs >> 1] += 40;
        if (arg0->unkBE[arg0->numVtxs >> 1] >= 360) {
            arg0->unkBE[arg0->numVtxs >> 1] -= 360;
        }
    } else if (arg0->unk0.state == 2) {
        arg0->unkBE[arg0->numVtxs >> 1] -= D_80152C78[(arg0->unk4 + 0x40) & 0xFF] >> 0xC;
        arg0->unkBE[arg0->numVtxs >> 1] -= 40;
        if (arg0->unkBE[arg0->numVtxs >> 1] < 0) {
            arg0->unkBE[arg0->numVtxs >> 1] += 360;
        }
    }

    arg0->unk5E[arg0->numVtxs >> 1][0] = animal->xPos.h;
    if (1) {};
    arg0->unk5E[arg0->numVtxs >> 1][1] = animal->zPos.h;
    arg0->unk5E[arg0->numVtxs >> 1][2] = animal->yPos.h;

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

#ifdef NON_MATCHING
// just the stack
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
    s32 sp38;
    s32 sp34;

    animal = arg0->unk240;
    sp40 = animal->zRotation;
    sp42 = animal->yRotation;
    sp38 = animal->xVelocity.w >> 8;
    sp34 = animal->zVelocity.w >> 8;

    if (sp38 | sp34) {
        sp44 = func_801284B8(
            -animal->yVelocity.w >> 8,
            sqrtf(SQ(sp38) + SQ(sp34)));
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
            sp58 = (D_80152C78[(arg0->unk4 + 0x40) & 0xFF] * arg0->unk5) >> 0xF;

            sp5A = (-D_80152C78[arg0->unk4 & 0xFF] * arg0->unk5) >> 0xF;
            sp5E = (D_80152350.unk384[temp_v0] * sp58) >> 8;
            sp5C = (D_80152350.unk2D0[temp_v0] * -sp58) >> 8;
            break;
        case 3:
            sp58 = ((D_80152C78[(arg0->unk4 + 0x40) & 0xFF] * arg0->unk5) >> 0xF);

            sp5A = (-D_80152C78[arg0->unk4 & 0xFF] * arg0->unk5) >> 0xF;
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

    arg0->unk38[arg0->unk1].v.ob[0] = (animal->xPos.h - sp5E) + sp48.unk0;
    arg0->unk38[arg0->unk1].v.ob[1] = (animal->zPos.h - sp5C) + sp48.unk2;
    arg0->unk38[arg0->unk1].v.ob[2] = (animal->yPos.h - sp5A) + sp48.unk4;

    arg0->unk38[arg0->unk1+1].v.ob[0] = animal->xPos.h + sp5E + sp48.unk0;
    arg0->unk38[arg0->unk1+1].v.ob[1] = animal->zPos.h + sp5C + sp48.unk2;
    arg0->unk38[arg0->unk1+1].v.ob[2] = animal->yPos.h + sp5A + sp48.unk4;

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
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/func_8039E6D4_7AFD84.s")
#endif

#if 0
// so much more to do here...
extern Gfx D_01004A70_3E340[];
extern u8  D_01044CB0_7E580[];
extern u8  D_010454B0_7ED80[];

void display_trails(void) {
    s16 i; // sp19E
    struct077 sp17C;                                /* compiler-managed */
    f32 sp178;
    f32 sp174;
    f32 sp170;

    f32 sp16C;
    f32 sp168;
    f32 sp164;

    f32 temp_f0;
    f32 temp_f2;

    s16 temp_a3;
    s16 temp_s5_3;
    s16 temp_s6;
    s16 temp_t0_2;

    s16 temp_v1_5;
    s16 var_a3;
    s16 var_s1;
    s16 temp_a1;

    s16 temp_t0;
    s16 temp_t8_3;
    s16 var_v1;
    Trail *temp_fp;

    s16 var_s4;
    u8 var_t1;
    u8 var_t5;

    WalrusWake *walrusWake;
    RegularTrail *trail;
    SimpleTrail *simpleTrail;
    Animal *animal;

    gSPDisplayList(D_801D9E90++, D_01004A70_3E340);
    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01044CB0_7E580); // trail

    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 1024);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(127));

    gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_010454B0_7ED80);

    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(D_801D9E90++);
    gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 1024);
    gDPPipeSync(D_801D9E90++);
    gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0100, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(127));

    if (D_803FDEA0 > 0) {
        for (i = 0; i < 30; i++) {
            temp_fp = &gTrails[i];
            switch (temp_fp->unk0.trailType) {
              case 0:
                  break;

              case 1:
                  // temp_v1_6 = (u8) temp_fp->unk0;
                  trail = &temp_fp->trail.regular;
                  animal = trail->unk240;
                  if ((temp_fp->unk0.unk4 != 2) && (((temp_fp->unk1.unk0 == 2) && (temp_fp->unk0.unk4 != 0)) || (animal->unk26C != 0))) {
                      // temp_fp->unk0 = (s8) ((temp_v1_6 & 0xFFF0) | 2);
                      temp_fp->unk0.unk4 = 2;
                      temp_fp->unk4 = 0;
                  }
                  // temp_fp->unk1 &= 0xFFF0;
                  temp_fp->unk1.unk4 = 0;

                  if (trail->unk3 == 0) {
                      // temp_v1_7 = (u8) temp_fp->unk0;
                      // temp_v0_12 = temp_v1_7 & 0xF;
                      if (temp_fp->unk0.unk4 != 2) {
                          if (temp_fp->unk0.unk4 == 1) {
                              // temp_fp->unk0 = (s8) (temp_v1_7 & 0xFFF0);
                              temp_fp->unk0.unk4 = 0;
                              trail->unk2 = 0;
                              trail->unk1 = 0;
                              trail->unk12[0] = 0;
                              func_8039E6D4_7AFD84(trail);
                          }
                          // temp_v0_13 = trail->unk2;
                          // temp_t8_7 = (trail->unk1 + 2) & 0x1F;
                          // var_v1_2 = temp_t8_7 & 0xFF;
                          trail->unk1 = (trail->unk1 + 2)  & 0x1F; // = temp_t8_7;
                          if (trail->unk2 == trail->unk1) {
                              trail->unk2 = (trail->unk2 + 2) & 0x1F;
                              // var_v1_2 = temp_t8_7 & 0xFF;
                          }
                          // (trail + ((var_v1_2 >> 1) * 2))->unk12 = 0;
                          trail->unk12[trail->unk1 >> 1] = 0;
                      }
                  }

                  if (temp_fp->unk0.unk4 != 2) {
                      func_8039E6D4_7AFD84(trail);
                  }

                  for (var_s4 = trail->unk2; var_s4 != trail->unk1; var_s4 = (var_s4 + 2) & 0x1F) {
                      trail->unk12[var_s4 >> 1] += trail->unkF;
                      if (trail->unk12[var_s4 >> 1] >= 0x80) {
                          trail->unk2 = (trail->unk2 + 2) & 0x1F;
                          if (trail->unk1 == trail->unk2) {
                              D_803FDEA0--;
                              temp_fp->unk0.trailType = 0;
                              break;
                          }
                      } else {
                          trail->unk38[(var_s4 >> 1)+0].v.cn[3] = 0x80 - trail->unk12[var_s4 >> 1];
                          trail->unk38[(var_s4 >> 1)+1].v.cn[3] = 0x80 - trail->unk12[var_s4 >> 1];
                      }
                  }

                  gSPVertex(D_801D9E90++, &trail->unk38, 32, 0);
                  gDPSetCombineMode(D_801D9E90++, G_CC_BLENDPE, G_CC_BLENDPE);
                  gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                  gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                  for (var_s1 = trail->unk2; var_s1 != trail->unk1; var_s1 = (var_s1 + 2) & 0x1F) {
                      temp_f2 = trail->unk12[var_s1 >> 1] / 128.0f;

                      sp164 = trail->unkC * temp_f2;
                      sp168 = trail->unkD * temp_f2;
                      sp16C = trail->unkE * temp_f2;

                      temp_f0 = 1.0f - temp_f2;
                      sp170 = sp164 + (trail->unk6 * temp_f0);
                      sp174 = sp168 + (trail->unk7 * temp_f0);
                      sp178 = sp16C + (trail->unk8 * temp_f0);

                      gDPSetPrimColor(D_801D9E90++, 0, 0, sp170, sp174, sp178, 0xFF);

                      sp170 = sp164 + (trail->unk9 * temp_f0);
                      sp174 = sp168 + (trail->unkA * temp_f0);
                      sp178 = sp16C + (trail->unkB * temp_f0);

                      gDPSetEnvColor(D_801D9E90++, sp170, sp174, sp178, 0xFF);

                      // temp_s0_42->words.w0 = ((temp_v0_15 & 0xFF) << 0x10) | (((((var_s1 + 3) & 0x1F) * 2) & 0xFF) << 8) | ((temp_v0_15 + 2) & 0xFF) | 0xB1000000;
                      // temp_s0_42->words.w1 = ((temp_v0_15 & 0xFF) << 0x10) | (((((var_s1 + 2) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1 + 3) & 0x1F) * 2) & 0xFF);
                      gSP1Quadrangle(
                          D_801D9E90++,
                          (var_s1 + 0),
                          (var_s1 + 2) & 0x1F,
                          (var_s1 + 3) & 0x1F,
                          (var_s1 + 1),
                          0);
                  }

                  trail->unk3 += 1;
                  trail->unk3 = (trail->unk3 % trail->unk10);
                  trail->unk4 += 0x20;
                break;
            case 4:
                simpleTrail = &temp_fp->trail.simple;
                animal = temp_fp->trail.regular.unk240;
                if (animal->unk26C != 0) {
                    // temp_v1 = (u8) temp_fp->unk0;
                    // if ((temp_v1 & 0xF) != 2) {
                    if (temp_fp->unk0.unk4 != 2) {
                        // temp_fp->unk0 = (s8) ((temp_v1 & 0xFFF0) | 2);
                        temp_fp->unk0.unk4 = 2;
                    }
                }
                // if (((u8) temp_fp->unk0 & 0xF) != 2) {
                if (temp_fp->unk0.unk4 != 2) {
                    simpleTrail->unk2C = animal->xPos.h;
                    simpleTrail->unk2E = animal->zPos.h;
                    simpleTrail->unk30 = animal->yPos.h + (animal->unk42 >> 1);
                    goto block_55;
                }

                // temp_t8_2 = simpleTrail->unk2 + 6;
                simpleTrail->unk2 = simpleTrail->unk2 + 6;
                if ((simpleTrail->unk2) >= 192) {
                    // temp_fp->unk0 = (s8) ((u8) temp_fp->unk0 & 0xFF0F);
                    temp_fp->unk0.trailType = 0;
                } else {
  block_55:
                    for (var_a3 = 0; var_a3 < simpleTrail->unkA; var_a3 += 2) {
                    // if ((s32) simpleTrail->unkA > 0) {
                        // do {
                        temp_t0 = var_a3 >> 1;
                        if (var_a3 & 2) {
                            var_v1 = (D_80152C78[(simpleTrail->unk1 + 0x40) & 0xFF] << 5) >> 0xF;
                        } else {
                            var_v1 = -(D_80152C78[(simpleTrail->unk1 + 0x40) & 0xFF] << 5) >> 0xF;
                        }
                        // temp_a0 = temp_s5->unk40;
                        temp_t8_3 = ((var_v1 + 0x100) * animal->unk40) >> 0xB;
                        temp_a1 = ((simpleTrail->unk3 * 8 * animal->unk40) >> 0xB) + temp_t8_3;
                        // temp_v0 = trail + (var_a3 * 0x10);
                        // temp_a2 = &D_80152350.unk0[(s16) ((s32) (temp_t0 * 0x168) / (s32) ((s32) simpleTrail->unkA >> 1))];
                        simpleTrail->unk38[var_a3+0].v.ob[1] = 0;
                        simpleTrail->unk38[var_a3+0].v.ob[0] = (s16) ((s32) (D_80152350.unk384[(s16) (((var_a3 >> 1) * 360) / (simpleTrail->unkA >> 1))] * temp_t8_3) >> 8);
                        simpleTrail->unk38[var_a3+0].v.ob[2] = (s16) ((s32) (D_80152350.unk2D0[(s16) (((var_a3 >> 1) * 360) / (simpleTrail->unkA >> 1))] * temp_t8_3) >> 8);

                        simpleTrail->unk38[var_a3+1].v.ob[1] = 0;
                        simpleTrail->unk38[var_a3+1].v.ob[0] = (s16) ((s32) (D_80152350.unk384[(s16) (((var_a3 >> 1) * 360) / (simpleTrail->unkA >> 1))] * temp_a1) >> 8);
                        simpleTrail->unk38[var_a3+1].v.ob[2] = (s16) ((s32) (D_80152350.unk2D0[(s16) (((var_a3 >> 1) * 360) / (simpleTrail->unkA >> 1))] * temp_a1) >> 8);

                        simpleTrail->unk38[var_a3+0].v.cn[3] = 0xC0 - simpleTrail->unk2;
                        simpleTrail->unk38[var_a3+1].v.cn[3] = 0xC0 - simpleTrail->unk2;

                        if (temp_t0 & 1) {
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
                        gDPSetPrimColor(D_801D9E90++, 0, 0, simpleTrail->red, simpleTrail->green, simpleTrail->blue, 0xFF);

                        gDPSetEnvColor(D_801D9E90++, simpleTrail->envRed, simpleTrail->envGreen, simpleTrail->envBlue, 0xFF);

                        guTranslate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], (f32) simpleTrail->unk2C, (f32) simpleTrail->unk2E, (f32) simpleTrail->unk30);
                        gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                        temp_f2 = ((simpleTrail->unk2 / 64.0f) * 0.125f) + 0.125;
                        guScale(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], temp_f2, temp_f2, temp_f2);
                        gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                        guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], animal->yRotation, 0.0f, 0.0f, 1.0f);
                        gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                        guRotate(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs], animal->zRotation, 1.0f, 0.0f, 0.0f);
                        gSPMatrix(D_801D9E90++, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

                        gSPVertex(D_801D9E90++, &simpleTrail->unk38, 32, 0);

                        gSPPopMatrix(D_801D9E90++, G_MTX_MODELVIEW);

                        gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                        // temp_a2_2 = simpleTrail->unkA;
                        temp_a3 = simpleTrail->unkA - 1;
                        for (var_s1 = 0; var_s1 < simpleTrail->unkA; var_s1 += 2) {
                            // temp_s0_27->words.w0 = (((var_s1 * 2) & 0xFF) << 0x10) | (((((var_s1 + 3) & temp_a3) * 2) & 0xFF) << 8) | (((var_s1 * 2) + 2) & 0xFF) | 0xB1000000;
                            // temp_s0_27->words.w1 = (((var_s1 * 2) & 0xFF) << 0x10) | (((((var_s1 + 2) & temp_a3) * 2) & 0xFF) << 8) | ((((var_s1 + 3) & temp_a3) * 2) & 0xFF);
                            gSP1Quadrangle(
                                D_801D9E90++,
                                (var_s1 + 0), // & (simpleTrail->unkA - 1),
                                (var_s1 + 2) & temp_a3,
                                (var_s1 + 3) & temp_a3,
                                (var_s1 + 1), // & (simpleTrail->unkA - 1),
                                0);
                        }
                    }
                    simpleTrail->unk1 += 2; // numTris / numVtx
                }
                break;
            case 3:
                walrusWake = &temp_fp->trail.walrus;
                // temp_v1_2 = (u8) temp_fp->unk0;
                // sp148 = walrusWake;
                // temp_v0_3 = temp_v1_2 & 0xF;
                animal = walrusWake->unk328;
                var_t1 = 0;

                if (temp_fp->unk0.unk4 != 2) {
                    if ((animal->xVelocity.h | animal->zVelocity.h) != 0) {
                        var_t5 = 1;
                    } else {
                        var_t5 = 0;
                    }
                } else {
                    var_t5 = 0;
                }

                if ((temp_fp->unk0.unk4 != 2) && ((((temp_fp->unk1.unk0) == 2) && (temp_fp->unk0.unk4 == 0)) || (animal->unk26C != 0))) {
                    // temp_fp->unk0 = (s8) ((temp_v1_2 & 0xFFF0) | 2);
                    temp_fp->unk0.unk4 = 2;
                    temp_fp->unk4 = 0;
                }
                // temp_fp->unk1 &= 0xFFF0;
                temp_fp->unk1.unk4 = 0;
                if ((walrusWake->unk3 == 0) && (temp_fp->unk0.unk4 != 2)) {
                    // temp_v1_3 = (u8) temp_fp->unk0;
                    // temp_v0_4 = temp_v1_3 & 0xF;
                    if (temp_fp->unk0.unk4 == 1) {
                        // temp_fp->unk0 = (s8) (temp_v1_3 & 0xFFF0);
                        temp_fp->unk0.unk4 = 0;

                        walrusWake->unk2 = 0U;
                        walrusWake->unk4 = 0U;
                        walrusWake->numVtxs = 0U;
                        func_8039E33C_7AF9EC(walrusWake);
                        var_t1 = 0;
                    }
                    if (var_t5 != 0) {
                        walrusWake->numVtxs = (walrusWake->numVtxs + 2) & 0x1F;
                        if (walrusWake->unk2 == walrusWake->numVtxs) {
                            walrusWake->unk2 = (u8) ((walrusWake->unk2 + 2) & 0x1F);
                        }
                        walrusWake->unk4 += 40; //= (u8) (walrusWake->unk4 + 0x28);
                        func_8039E33C_7AF9EC(walrusWake);
                        var_t1 = 0;
                    }
                }


                var_s4 = walrusWake->unk2;
                do {
  // loop_88:
                    // temp_s2 = (s32) var_s4 >> 1;
                    if (var_t5 == 0) {
                        // temp_s0_28 = walrusWake + (((s32) var_s4 >> 1) * 2);
                        // temp_v0_6 = temp_s0_28->unkE;
                        // temp_v0_6 = walrusWake->unkE[var_s4 >> 1];
                        if (walrusWake->unkE[var_s4 >> 1] < 0x40) {
                            // temp_s0_28->unkE = (s16) (0x80 - temp_v0_6);
                            walrusWake->unkE[var_s4 >> 1] = 0x80 - walrusWake->unkE[var_s4 >> 1];
                        }
                    }

                    // temp_s0_29 = walrusWake + (temp_s2 * 2);
                    // temp_s0_29->unkE = (s16) (temp_s0_29->unkE + trail->unkC);
                    walrusWake->unkE[var_s4 >> 1] += walrusWake->unkC;
                    // temp_v0_7 = walrusWake->unkE[temp_s2];
                    // temp_s0_29->unk3E = (s16) (temp_s0_29->unk3E + `trail->unkC);
                    walrusWake->unk3E[var_s4 >> 1] += walrusWake->unkC; // CHECK
                    if (walrusWake->unkE[var_s4 >> 1] >= 0x80) {
                        // temp_s0_29->unkE = 0x80;
                        walrusWake->unkE[var_s4 >> 1] = 0x80;
                        // temp_v0_8 = walrusWake->unk2;
                        if ((var_s4 == walrusWake->unk2)) {
                            // temp_t9_2 = (temp_v0_8 + 2) & 0x1F;
                            walrusWake->unk2 = (walrusWake->unk2 + 2) & 0x1F; //temp_t9_2;
                            if ((walrusWake->numVtxs == walrusWake->unk2) && (temp_fp->unk1.unk0 != 0)) {
                                  // temp_fp->unk0 = (s8) ((u8) temp_fp->unk0 & 0xFF0F);
                                  D_803FDEA0--;
                                  temp_fp->unk0.trailType = 0;
                            } else {
                              // goto block_98;
                            }
                        } else {
                            // goto block_98;
                        }
                    } else {
                        // temp_s1 = walrusWake + (var_s4 * 0x10);
                        temp_s6 = (((D_80152C78[((walrusWake->unkE[var_s4 >> 1] & 0xFF))]) >> 8) * (walrusWake->unk2E[var_s4 >> 1])) >> 7;
                        // walrusWake->unk38[var_s4 + 15].unk7;
                        // temp_s1->unk12F = (s8) temp_t6_2;
                        walrusWake->vtxs[var_s4 + 0].v.cn[3] = temp_s6;

                        // temp_s1->unk13F = (s8) temp_t6_2;
                        walrusWake->vtxs[var_s4 + 1].v.cn[3] = temp_s6;
                        // temp_v1_4 = walrusWake->unk5;
                        // temp_t0_2 = temp_s0_29->unkBE;
                        temp_t0_2 = walrusWake->unkBE[var_s4 >> 1]; //unkE;
                        // temp_a3_2 = ((s32) (temp_s0_29->unk3E * temp_v1_4) >> 5) + temp_v1_4;
                        temp_a3 = ((s32) (walrusWake->unk3E[var_s4 >> 1] * walrusWake->unk5) >> 5) + walrusWake->unk5;
                        // temp_a0_3 = &D_80152350.unk0[temp_t0_2];
                        // sp135 = var_t5;
                        // sp14F = var_t1;
                        temp_s5_3 = (D_80152350.unk384[temp_t0_2] * temp_a3) >> 8;
                        temp_s6 = (-D_80152350.unk2D0[temp_t0_2] * temp_a3) >> 8;
                        func_802F5F44_7075F4(walrusWake->unk320, walrusWake->unk322, walrusWake->unk324, 0, temp_t0_2, &sp17C);
                        // temp_v0_9 = walrusWake + (temp_s2 * 4);
                        temp_v1_5 = D_80152C78[walrusWake->unk3E[var_s4 >> 1] & 0xFF];

                        sp17C.unk0 = sp17C.unk0 + ((walrusWake->unkDE[var_s4 >> 1][0] * temp_v1_5) >> 0x11);
                        sp17C.unk2 = sp17C.unk2 + ((walrusWake->unkDE[var_s4 >> 1][1] * temp_v1_5) >> 0x11);
                        sp17C.unk0 = sp17C.unk0 + ((walrusWake->unkDE[var_s4 >> 1][0] * walrusWake->unk3E[var_s4 >> 1]) >> 8);
                        sp17C.unk2 = sp17C.unk2 + ((walrusWake->unkDE[var_s4 >> 1][1] * walrusWake->unk3E[var_s4 >> 1]) >> 8);

                        walrusWake->vtxs[var_s4+0].v.ob[0] = (walrusWake->unk5E[var_s4 >> 1][0] + temp_s5_3 + sp17C.unk0);
                        walrusWake->vtxs[var_s4+0].v.ob[1] = (walrusWake->unk5E[var_s4 >> 1][1] + temp_s6 + sp17C.unk2);
                        walrusWake->vtxs[var_s4+0].v.ob[2] = (walrusWake->unk5E[var_s4 >> 1][2] + sp17C.unk4);

                        walrusWake->vtxs[var_s4+1].v.ob[0] = ((walrusWake->unk5E[var_s4 >> 1][0] - temp_s5_3) + sp17C.unk0);
                        walrusWake->vtxs[var_s4+1].v.ob[1] = ((walrusWake->unk5E[var_s4 >> 1][1] - temp_s6) + sp17C.unk2);
                        walrusWake->vtxs[var_s4+1].v.ob[2] = (walrusWake->unk5E[var_s4 >> 1][2] + sp17C.unk4);

                    }
                    if (var_s4 == walrusWake->numVtxs) {
                        var_t1 = 1; // break
                    }
                    var_s4 = (var_s4 + 2) & 0x1F;
                } while (var_t1 == 0);

                gSPVertex(D_801D9E90++, &walrusWake->vtxs, 32, 0); // &trail->unk38[0xE].unk8;
                gDPSetCombineMode(D_801D9E90++, G_CC_BLENDPE, G_CC_BLENDPE);
                gDPSetAlphaCompare(D_801D9E90++, G_AC_NONE);
                gDPSetPrimColor(D_801D9E90++, 0, 0, walrusWake->red, walrusWake->green, walrusWake->blue, 0xFF);
                gDPSetEnvColor(D_801D9E90++, walrusWake->envRed, walrusWake->envGreen, walrusWake->envBlue, 0xFF);
                gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0020, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

                for (var_s1 = walrusWake->unk2; var_s1 != walrusWake->numVtxs; var_s1 = (var_s1 + 2) & 0x1F) {
                    // temp_s0_36->words.w0 = ((((var_s1_2 + 0) * 2) & 0xFF) << 0x10) | (((((var_s1_2 + 3) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1_2 + 1)) & 0xFF) | 0xB1000000;
                    // temp_s0_36->words.w1 = ((((var_s1_2 + 0) * 2) & 0xFF) << 0x10) | (((((var_s1_2 + 2) & 0x1F) * 2) & 0xFF) << 8) | ((((var_s1_2 + 3) & 0x1F) * 2) & 0xFF);
                    gSP1Quadrangle(D_801D9E90++,
                        (var_s1 + 0),
                        (var_s1 + 2) & 0x1F,
                        (var_s1 + 3) & 0x1F,
                        (var_s1 + 1),
                        0);
                }

                walrusWake->unk3++;
                walrusWake->unk3 = walrusWake->unk3 % walrusWake->unkD;
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7AF410/display_trails.s")
#endif
