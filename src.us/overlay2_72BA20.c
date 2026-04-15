#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

typedef struct {
    Entity *unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;

    /* 0xE */  s16 startX;
    /* 0x10 */ s16 startZ;
    /* 0x12 */ s16 startY;

    /* 0x14 */ s16 endX;
    /* 0x16 */ s16 endZ;
    /* 0x18 */ s16 endY;

    /* 0x1C */ s32 dirX;
    /* 0x20 */ s32 dirZ;
    /* 0x24 */ s32 dirY;

    /* 0x28 */ s32 deltaX;
    /* 0x2C */ s32 deltaZ;
    /* 0x30 */ s32 deltaY;

    /* 0x34 */ s32 absDeltaX;
    /* 0x38 */ s32 absDeltaZ;
    /* 0x3C */ s32 absDeltaY;
    /* 0x40 */ s32 distance;
} LightningBeamState;

// ========================================================
// .data
// ========================================================

u16  D_803A5760_7B6E10 = 0;
// s16  D_803A5764_7B6E14 = 0; // defined in func_8031AE7C_72C52C

// ========================================================
// .bss
// ========================================================

s16  D_803E97C0;  // vertex array indexer
static LightningBeamState D_803E97C8;

// ========================================================
// .text
// ========================================================

// ESA: func_8004DEA0
void func_8031A370_72BA20(void) {
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_t8;
    s16 i;

    Entity *var_v0 = D_803E97C8.unk0;

    for (i = 1; i <= D_803E97C8.unkA; i++) {
        if ((i != D_803E97C8.unk4) || (D_803E97C8.unk8 == 0)) {
            var_v0->newPosition.xPos.h = var_v0->position.xPos.h = D_803E97C8.startX + ((D_803E97C8.dirX * ((i << 6) - 0x10)) >> 8);
            var_v0->newPosition.zPos.h = var_v0->position.zPos.h = D_803E97C8.startZ + ((D_803E97C8.dirZ * ((i << 6) - 0x10)) >> 8);
            var_v0->newPosition.yPos.h = var_v0->position.yPos.h = (D_803E97C8.startY + ((D_803E97C8.dirY * ((i << 6) - 0x10)) >> 8)) - 0x20;

            var_v0->unkC4[0].unkC = 0x1F;
            var_v0->unkC4[0].pos.xPos.w = 0;
            var_v0->unkC4[0].pos.zPos.w = 0;
            var_v0->unkC4[0].pos.yPos.w = 0x200000;
        } else {
            var_v0->newPosition.xPos.h = var_v0->position.xPos.h = D_803E97C8.endX - ((D_803E97C8.dirX * (D_803E97C8.unk8 + 0x10)) >> 8);
            var_v0->newPosition.zPos.h = var_v0->position.zPos.h = D_803E97C8.endZ - ((D_803E97C8.dirZ * (D_803E97C8.unk8 + 0x10)) >> 8);
            var_v0->newPosition.yPos.h = var_v0->position.yPos.h = (D_803E97C8.endY - D_803E97C8.unk8) - ((D_803E97C8.dirY * (D_803E97C8.unk8 + 0x10)) >> 8);

            var_v0->unkC4[0].unkC = D_803E97C8.unk8;
            var_v0->unkC4[0].pos.xPos.w = 0;
            var_v0->unkC4[0].pos.zPos.w = 0;
            var_v0->unkC4[0].pos.yPos.w = (D_803E97C8.unk8 << 0x10);
        }
        var_v0 = var_v0->unk248[2];
    }
    D_803E97C8.unk0 = var_v0;
}

#if 0
// no real idea whats going on here...
// ESA: func_8004E044 (but custom for ps1)
void func_8031A4E0_72BB90(void) {
    s32 pad[0xA];
    s16 x0;
    s16 y0; // sp4C
    s16 z0; // sp4A
    s16 x1; // sp48
    s16 y1; // sp46
    s16 z1; // sp44
    s32 x2;
    s32 y2;
    s32 z2;

    s16 i;

    s16 startX0;
    s16 startX1;
    s16 startY0;
    s16 startY1;
    s16 startZ0;
    s16 startZ1;

    s16 tmp1, tmp2;
    u8 phase;
    Vtx *vtxs;

    vtxs = &gDisplayListContext->unk39C88[gDisplayListContext->unk3B308];
    gDisplayListContext->unk3B30A[D_803E97C0] = 8;

    gDisplayListContext->unk3B308 += 8;

    if (D_803E97C8.startX < D_803E97C8.endZ) {
        startX0 = D_803E97C8.startX;
        startX1 = D_803E97C8.endX;
    } else {
        startX1 = D_803E97C8.startX;
        startX0 = D_803E97C8.endX;
    }

    if (D_803E97C8.startZ < D_803E97C8.endZ) {
        startY0 = D_803E97C8.startZ;
        startY1 = D_803E97C8.endZ;
    } else {
        startY1 = D_803E97C8.startZ;
        startY0 = D_803E97C8.endZ;
    }

    if (D_803E97C8.startY < D_803E97C8.endY) {
        startZ1 = D_803E97C8.startY;
        startZ0 = D_803E97C8.endY;
    } else {
        startZ0 = D_803E97C8.startY;
        startZ1 = D_803E97C8.endY;
    }

    vtxs->v.ob[0] = startX0;
    vtxs->v.ob[1] = startY0;
    vtxs->v.ob[2] = startZ0;
    vtxs++;

    vtxs->v.ob[0] = startX1;
    vtxs->v.ob[1] = startY0;
    vtxs->v.ob[2] = startZ0;
    vtxs++;

    vtxs->v.ob[0] = startX1;
    vtxs->v.ob[1] = startY1;
    vtxs->v.ob[2] = startZ0;
    vtxs++;

    vtxs->v.ob[0] = startX0;
    vtxs->v.ob[1] = startY1;
    vtxs->v.ob[2] = startZ0;
    vtxs++;

    vtxs->v.ob[0] = startX0;
    vtxs->v.ob[1] = startY0;
    vtxs->v.ob[2] = startZ1;
    vtxs++;

    vtxs->v.ob[0] = startX1;
    vtxs->v.ob[1] = startY0;
    vtxs->v.ob[2] = startZ1;
    vtxs++;

    vtxs->v.ob[0] = startX1;
    vtxs->v.ob[1] = startY1;
    vtxs->v.ob[2] = startZ1;
    vtxs++;

    vtxs->v.ob[0] = startX0;
    vtxs->v.ob[1] = startY1;
    vtxs->v.ob[2] = startZ1;
    vtxs++;

    x0 = D_803E97C8.startX;
    y0 = D_803E97C8.startZ;
    z0 = D_803E97C8.startY + 4;

    x1 = D_803E97C8.startX;
    y1 = D_803E97C8.startZ;
    z1 = D_803E97C8.startY - 4;

    for (i = 1; i <= D_803E97C8.unkC; i++) {

        if (i == D_803E97C8.unkC) {
            // final iteration
            x2 = D_803E97C8.endX;
            y2 = D_803E97C8.endZ;
            z2 = D_803E97C8.endY;
        } else {
            x2 = D_803E97C8.startX + ((((D_803E97C8.deltaX << 8) / D_803E97C8.unkC) * i) >> 8);
            y2 = D_803E97C8.startZ + ((((D_803E97C8.deltaZ << 8) / D_803E97C8.unkC) * i) >> 8);
            z2 = D_803E97C8.startY + ((((D_803E97C8.deltaY << 8) / D_803E97C8.unkC) * i) >> 8);
            phase = (D_803A5760_7B6E10 + (i * 0x10));
            y2 += SSSV_RAND(32) - 16;
            x2 += SSSV_RAND(32) - 16;
            z2 += SSSV_RAND(32) - 8;
            if (!D_803E97C8.startX) {};
            if ((&D_803E97C8) && (&D_803E97C8)){};
            z2 += (COS(phase) * 8) >> 0xF;
        }

#if 1
        tmp1 = z2 + 4;
        tmp2 = z2 - 4;

        /* 0x00 */ vtxs[0].v.ob[0] = x0;
        /* 0x02 */ vtxs[0].v.ob[1] = y0;
        /* 0x04 */ vtxs[0].v.ob[2] = z0 + 4;
        /* 0x0C */ vtxs[0].v.cn[0] = vtxs[0].v.cn[1] = vtxs[0].v.cn[2] = 0xFF;
        /* 0x08 */ vtxs[0].v.tc[0] = 0;
        /* 0x0A */ vtxs[0].v.tc[1] = 0;

        /* 0x10 */ vtxs[1].v.ob[0] = x1;
        /* 0x12 */ vtxs[1].v.ob[1] = y1;
        /* 0x14 */ vtxs[1].v.ob[2] = z1 - 4;
        /* 0x1A */ vtxs[1].v.tc[1] = 0x3FF;

        /* 0x22 */ vtxs[2].v.ob[1] = y2;
        /* 0x20 */ vtxs[2].v.ob[0] = x2;
        /* 0x24 */ vtxs[2].v.ob[2] = (tmp1 + 4);
        /* 0x28 */ vtxs[2].v.tc[0] = 0x7FF;

        /* 0x30 */ vtxs[3].v.ob[0] = x2;
        /* 0x32 */ vtxs[3].v.ob[1] = y2;

        /* 0x1C */ vtxs[1].v.cn[0] = vtxs[1].v.cn[1] = vtxs[1].v.cn[2] = 0xFF;
        /* 0x18 */ vtxs[1].v.tc[0] = 0;

        /* 0x2C */ vtxs[2].v.cn[0] = vtxs[2].v.cn[1] = vtxs[2].v.cn[2] = 0xFF;
        /* 0x2A */ vtxs[2].v.tc[1] = 0;
        /* 0x34 */ vtxs[3].v.ob[2] = (tmp2 - 4) & 0xFFFF;

        /* 0x3C */ vtxs[3].v.cn[0] = vtxs[3].v.cn[1] = vtxs[3].v.cn[2] = 0xFF;

        /* 0x38 */ vtxs[3].v.tc[0] = 0x7FF;
        /* 0x3A */ vtxs[3].v.tc[1] = 0x3FF;

        vtxs += 4;

        gDisplayListContext->unk3B30A[D_803E97C0] += 4;
        gDisplayListContext->unk3B308 += 4;

        x0 = x2;
        y0 = y2;
        z0 = tmp1;

        x1 = x2;
        y1 = y2;
        z1 = tmp2;
#else
        tmp1 = z2 + 4;
        tmp2 = z2 - 4;

        if (1) {
            vtxs[0].v.ob[0] = x0;
            vtxs[0].v.ob[1] = y0;
            vtxs[0].v.ob[2] = z0 + 4;
            vtxs[0].v.cn[0] = vtxs[0].v.cn[1] = vtxs[0].v.cn[2] = 0xFF;
            vtxs[0].v.tc[0] = 0;
            vtxs[0].v.tc[1] = 0;

            vtxs[1].v.ob[0] = x1;
            vtxs[1].v.ob[1] = y1;
            vtxs[1].v.ob[2] = z1 - 4;
            vtxs[1].v.cn[0] = vtxs[1].v.cn[1] = vtxs[1].v.cn[2] = 0xFF;
            vtxs[1].v.tc[0] = 0;
            vtxs[1].v.tc[1] = 0x3FF;

            vtxs[2].v.ob[0] = x2;
            vtxs[2].v.ob[1] = y2;
            vtxs[2].v.ob[2] = tmp1 + 4;
            vtxs[2].v.cn[0] = vtxs[2].v.cn[1] = vtxs[2].v.cn[2] = 0xFF;
            vtxs[2].v.tc[0] = 0x7FF;
            vtxs[2].v.tc[1] = 0;

            vtxs[3].v.ob[0] = x2;
            vtxs[3].v.ob[1] = y2;
            vtxs[3].v.ob[2] = (tmp2 - 4) & 0xFFFF;
            vtxs[3].v.cn[0] = vtxs[3].v.cn[1] = vtxs[3].v.cn[2] = 0xFF;
            vtxs[3].v.tc[0] = 0x7FF;
            vtxs[3].v.tc[1] = 0x3FF;

            vtxs += 4;

            gDisplayListContext->unk3B30A[D_803E97C0] += 4;
            gDisplayListContext->unk3B308 += 4;

            x0 = x2;
            y0 = y2;
            z0 = tmp1;

            x1 = x2;
            y1 = y2;
            z1 = tmp2;
        }
#endif
    }

    D_803E97C0++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72BA20/func_8031A4E0_72BB90.s")
#endif

// used by object 28
void func_8031AA0C_72C0BC(Entity *e) {
    Entity *other;
    Entity *tmp;
    s16 i;

    if (e->unk248[1] != NULL) {
        other = e->unk248[1];

        D_803E97C8.deltaX = other->position.xPos.h - e->position.xPos.h;
        D_803E97C8.deltaZ = other->position.zPos.h - e->position.zPos.h;
        D_803E97C8.deltaY = other->position.yPos.h - e->position.yPos.h;

        D_803E97C8.absDeltaX = ABS(D_803E97C8.deltaX);
        D_803E97C8.absDeltaZ = ABS(D_803E97C8.deltaZ);
        D_803E97C8.absDeltaY = ABS(D_803E97C8.deltaY);

        D_803E97C8.distance = (s16)sqrtf(
            ((D_803E97C8.deltaX) * (D_803E97C8.deltaX)) +
            ((D_803E97C8.deltaZ) * (D_803E97C8.deltaZ)) +
            ((D_803E97C8.deltaY) * (D_803E97C8.deltaY)));
            D_803E97C8.unkC = (D_803E97C8.distance >> 6) + 1;

            D_803E97C8.dirX = (D_803E97C8.deltaX << 8) / D_803E97C8.distance;
            D_803E97C8.dirZ = (D_803E97C8.deltaZ << 8) / D_803E97C8.distance;
            D_803E97C8.dirY = (D_803E97C8.deltaY << 8) / D_803E97C8.distance;

            D_803E97C8.unk4 = (D_803E97C8.distance - 34) >> 6;
            D_803E97C8.unk8 = (((D_803E97C8.distance - 34) & 0x3F) >> 1) - 1;

            if (D_803E97C8.unk4 == 0) {
                D_803E97C8.unk4 = 1;
                if (D_803E97C8.unk8 <= 0) {
                    D_803E97C8.unk8 = 1;
                }
            } else if ((D_803E97C8.unk8 < 0) ) {
                D_803E97C8.unk8 = 0;
            } else {
                D_803E97C8.unk4 += 1;
            }
            if (e->state == 1) {
                D_803E97C8.unk6 = D_803E97C8.unk4;
            } else {
                D_803E97C8.unk6 = 0;
            }
            if (D_803E97C8.unkC >= 7) {
                for (tmp = e->unk248[2]; e->Info.unk152 > 0; tmp = tmp->unk248[2], e->Info.unk152--) {
                    tmp->unk26C = 1;
                }
            } else {
                if (e->Info.unk152 != D_803E97C8.unk6) {
                    if (e->Info.unk152 < D_803E97C8.unk6) {
                        tmp = e;
                        for (i = e->Info.unk152; i > 0; i--) {
                            tmp = tmp->unk248[2];
                        }
                        do {
                            tmp->unk248[2] = spawn_object(31, 0, 0, 0, 0, 0, 0, 0, 0, 0x800);
                            tmp = tmp->unk248[2];
                            e->Info.unk152++;
                        } while (e->Info.unk152 < D_803E97C8.unk6);
                    } else {
                        tmp = e;
                        for (i = 0; i <= D_803E97C8.unk6; i++) {
                            tmp = tmp->unk248[2];
                        }
                        do {
                            tmp->unk26C = 1;
                            tmp = tmp->unk248[2];
                            e->Info.unk152--;
                        } while (D_803E97C8.unk6 < e->Info.unk152);

                    }
                }
            }
            if (e->Info.unk152 > 0) {
                D_803E97C8.unk0 = e->unk248[2];

                D_803E97C8.startX = e->position.xPos.h;
                D_803E97C8.startZ = e->position.zPos.h;
                D_803E97C8.startY = e->position.yPos.h + (e->unk42 >> 1);

                D_803E97C8.endX = other->position.xPos.h;
                D_803E97C8.endZ = other->position.zPos.h;
                D_803E97C8.endY = other->position.yPos.h + (e->unk42 >> 1);

                D_803E97C8.unkA = e->Info.unk152;
                func_8031A370_72BA20();
                func_8031A4E0_72BB90();
            }
            if (e->state == 1) { // enabled?
                func_8032CED0_73E580(
                    e,
                    SFX_UNKNOWN_115,
                    0x4000,
                    0.5f,
                    0,
                    0,
                    (other->position.xPos.h + e->position.xPos.h) >> 1,
                    (other->position.zPos.h + e->position.zPos.h) >> 1,
                    (other->position.yPos.h + e->position.yPos.h) >> 1,
                    0,
                    0,
                    0);
        }
    }
}

// ESA: func_8004E7F0
void func_8031AE7C_72C52C(Animal *arg0) {
    s16 i;

    static s16 D_803A5764_7B6E14 = 0;

    if (D_803A5764_7B6E14 > 0) {
        D_803A5764_7B6E14--;
    }
    if (arg0->unk5C.unk0 & 8) {
        arg0->unk5C.unk0 = 0;
        if (D_803A5764_7B6E14 <= 0) {
            D_803A5764_7B6E14 = (guRandom() & 0xF) + 0x3C;
            play_sound_effect_at_location(SFX_UNKNOWN_77, 0x6000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
        }

        for (i = 0; i < 3; i++) {
            s32 temp_s1 = (SSSV_RAND(8) - 4) << 16;
            s32 temp_s2 = (SSSV_RAND(8) - 4) << 16;
            s32 temp_s3 = (SSSV_RAND(8) - 2) << 16;
            create_particle_effect(
                arg0->position.xPos.h,
                arg0->position.zPos.h,
                arg0->position.yPos.h,
                35,
                temp_s1,
                temp_s2,
                temp_s3,
                6,
                0,
                0,
                0);
        }
    }
}
