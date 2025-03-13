#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

s32  func_8030AAE0_71C190(Animal*);

// ========================================================
// .data
// ========================================================

s32 gGravity = FTOFIX32(2.0);
s32 D_803A05B4_7B1C64 = FTOFIX32(4.0);

// ========================================================
// .bss
// ========================================================

Animal2 *D_803D5520;
struct035 *D_803D5524;
Animal *D_803D5528;
Animal *D_803D552C; // is this *really* Animal? is it World?

Animal *D_803D5530; // pointer to first animal?
s16  gCurrentAnimalIndex; // current animal (id within level)
s16  D_803D5536; // tmp animal idx?
u8   D_803D5538; // "player is current animal"?
s16  D_803D553A;
s16  D_803D553C;
s16  gNumAnimalsInLevel; // number of animals in level? gNumAnimals

s16  D_803D5540; // timer
s16  D_803D5542; // timer
u16  D_803D5544; // timer (for attacks? everything?) gCurrentTick
s16  D_803D5546;
s16  D_803D5548;
s8   D_803D554A;
s8   D_803D554B; // target speed?
s8   D_803D554C; // boost duration?

s32  D_803D5550; // unused
s32  D_803D5554; // unused
s16  D_803D5558;
u16  D_803D555A; // timer
u8   D_803D555C;
u8   D_803D555D;

Animal *D_803D5560;
s16  D_803D5564;
s16  D_803D5566;
s16  D_803D5568;
s16  D_803D556A;
s16  D_803D556C;
s16  D_803D556E;

s16  D_803D5570;
u16  D_803D5572;
// s16  D_803D5574; // static in func_802AC9FC_6BE0AC

// ========================================================
// .text
// ========================================================

void func_802A4390_6B5A40(void) {
    D_803D5530->state = 2;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A43E4_6B5A94(u16 rotation, s8 arg1) {
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;

    D_803D5530->state = 3;
    D_803D5530->yRotation = rotation;

    if ((D_803D5524->unk9C == GORILLA) || (D_803D5524->unk9C == BEAR)) {
        if (D_803D552C->unk320 != NULL) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8790_6C9E40();
}

void func_802A44C4_6B5B74(u16 rotation, s8 arg1) {
    D_803D5530->state = 6;
    D_803D5530->yRotation = rotation;

    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;

    if ((D_803D5524->unk9C == GORILLA) || ( (D_803D5524->unk9C == BEAR))) {
        if (D_803D552C->unk320 != NULL) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8790_6C9E40();
}

void func_802A459C_6B5C4C(u16 rotation, s8 arg1) {
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;

    D_803D5530->state = 4;
    D_803D5530->yRotation = rotation;

    if ((D_803D5524->unk9C == GORILLA) || (D_803D5524->unk9C == BEAR)) {
        if (D_803D552C->unk320 != NULL) {
            arg1 = (arg1 * 5) / 6;
        }
    }
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
    func_802B8810_6C9EC0();
}

void func_802A467C_6B5D2C(s8 arg0) {
    s16 xVel;
    s16 zVel;
    s16 phi_v0;
    s16 sp60;
    s16 sp5E;
    s16 xVel2;
    s16 zVel2;

    s32 phi_t5;
    s32 yVel;

    s32 yVelOrig;
    s16 xPos;
    s16 zPos;
    s16 groundState;
    s16 phi_t0;

    Animal *animal;

    if (D_803D5538 != 0) {
        xPos = D_803D5564;
        zPos = D_803D5568;
        groundState = D_803D556C;
        animal = D_803D5560;
    } else {
        xPos = D_803D5530->position.xPos.h;
        zPos = D_803D5530->position.zPos.h;
        groundState = D_803D5530->unk160;
        animal = D_803D5530->unk6C;
    }
    D_803D552C->unk367 = 6;
    D_803D552C->unk36D = 1;

    if (animal != NULL) {
        zVel = 0;
        xVel = 0;
    } else {
        func_80311A2C_7230DC(xPos, zPos, &xVel, &zVel, groundState);
    }
    if ((animal == NULL) && ((xVel != 0) || (zVel != 0))) {
        if (groundState == 2) {
            phi_v0 = D_803E1D30[D_803C0740[xPos >> 6][zPos >> 6].unk3].unk0;
        } else {
            phi_v0 = D_803E1D30[D_803C0740[xPos >> 6][zPos >> 6].unk2].unk0;
        }

        if (phi_v0 == 0) {
            return;
        }
    }

    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;

    xVel2 = xVel;
    zVel2 = zVel;

    if (arg0 == 0) {
        phi_t5 = D_803D5524->unkA6;
    } else {
        phi_t5 = D_803D5524->unkA8;
    }

    if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
        phi_t0 = 0;
    } else {
        phi_t0 = 1;
    }

    if ((phi_t0 == 0) && (D_803D5538 != 0)) {
        func_80311A2C_7230DC(D_803D5566, D_803D556A, &sp60, &sp5E, D_803D556E);

        if ((ABS(sp60) < 24) && (ABS(sp5E) < 24)) {
            phi_t0 = 1;
            xVel2 = sp60;
            zVel2 = sp5E;
        }
    }

    if (xVel2 < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA6 << 15);
    }
    if (xVel2 > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA6 << 15);
    }
    if (zVel2 < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA6 << 15);
    }
    if (zVel2 > 23) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA6 << 15);
    }

    // store original?
    yVelOrig = D_803D5530->yVelocity.w;

    if (phi_t0 != 0) {
        yVel = phi_t5 << 16;
        if ((D_803D5530->unk162 != 1) && (D_803D5530->unk162 != 6)) {
            yVel += gGravity;
        }
        D_803D5530->yVelocity.w += yVel;
    } else {
        yVel = phi_t5 << 12;
        D_803D5530->yVelocity.w += yVel;
    }

    if (animal == NULL) {
        D_803D5530->yVelocity.w = MIN(yVel, D_803D5530->yVelocity.w);
        D_803D5530->yVelocity.w = MAX(yVelOrig, D_803D5530->yVelocity.w);
    } else {
        D_803D5530->yVelocity.w = MIN(animal->yVelocity.w + yVel, D_803D5530->yVelocity.w);
        D_803D5530->yVelocity.w = MAX(yVelOrig, D_803D5530->yVelocity.w);
    }
    if (D_803D5530->state < 7) {
        D_803D5530->unk162 = 3U;
        D_803D5530->state = 5U;
    } else {
        if ((D_803D5530->state >= 0x19) &&
            (D_803D5530->state >= 0x2B) &&
            (D_803D5530->state >= 0x40) &&
            (D_803D5530->state >= 0x52) &&
            (D_803D5530->state >= 0x6B) &&
            (D_803D5530->state >= 0x7C) &&
            (D_803D5530->state >= 0x91) &&
            (D_803D5530->state >= 0xA3) &&
            (D_803D5530->state < 0xBA)) {
            D_803D5530->unk162 = 7U;
            D_803D5530->state = 0xB8U;
        }
    }

    play_sound_effect_at_location(
        D_803A65D0_7B7C80[D_803D5524->unk9C],
        D_803A6680_7B7D30[D_803D5524->unk9C],
        0,
        D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

    func_802B8890_6C9F40();

    if ((animal != NULL) && (animal->unk162 == 5) && (animal->unk4C.unk1D)) {
        if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } // regalloc
        animal->yVelocity.w -= MIN(FTOFIX32(4.0), (D_803D5530->unk44 << 0x13) / animal->unk44);
    }
}

void func_802A4CB8_6B6368(void) {
    D_803D5530->state = 21;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A4D0C_6B63BC(u16 rotation, s8 arg1) {
    D_803D5530->state = 22;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A4D80_6B6430(u16 rotation, s8 arg1) {
    D_803D5530->state = 24;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A4DF4_6B64A4(u16 rotation, s8 arg1) {
    D_803D5530->state = 23;
    D_803D552C->unk31A = D_803D5524->unkA4 * 65536;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8978_6CA028();
}

void func_802A4E74_6B6524(void) {
    D_803D5530->state = 181;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A4EC8_6B6578(u16 rotation, s8 arg1) {
    D_803D5530->state = 182;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A4F68_6B6618(u16 rotation, s8 arg1) {
    D_803D5530->state = 185;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    D_803D552C->unk368 = arg1;
    func_802B8790_6C9E40();
}

void func_802A5008_6B66B8(u16 rotation, s8 arg1) {
    D_803D5530->state = 183;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8810_6C9EC0();
}

void func_802A50A8_6B6758(void) {
    s16 xVel, zVel;

    D_803D5530->state = 184;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;

    if (D_803D5530->unk162 != 1) {
        zVel = 0;
        xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA6 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA6 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA6 << 0xF);
    }
    if (zVel > 23) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA6 << 0xF);
    }

    if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
        D_803D5530->yVelocity.w += (D_803D5524->unkA6 << 12);
    } else {
        D_803D5530->yVelocity.w += (D_803D5524->unkA6 << 16);
        if (D_803D5530->unk162 != 1) {
            D_803D5530->yVelocity.w += gGravity;
        }
    }
    func_802B8890_6C9F40();
}

void func_802A5300_6B69B0(void) {
    s16 xVel, zVel;

    D_803D5530->state = 184;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 32;

    if (D_803D5530->unk162 != 1) {
        zVel = 0;
        xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }
    if (xVel < -23) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -D_803D5524->unkA8 << 0xF);
    }
    if (xVel > 23) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, D_803D5524->unkA8 << 0xF);
    }
    if (zVel < -23) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -D_803D5524->unkA8 << 0xF);
    }
    if (zVel > 23) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, D_803D5524->unkA8 << 0xF);
    }

    if ((ABS(xVel) > 23) || (ABS(zVel) > 23)) {
        D_803D5530->yVelocity.w += (D_803D5524->unkA8 << 12);
    } else {
        D_803D5530->yVelocity.w += (D_803D5524->unkA8 << 16);
        if (D_803D5530->unk162 != 1) {
            D_803D5530->yVelocity.w += gGravity;
        }
    }
    func_802B8890_6C9F40();
}

void func_802A5558_6B6C08(void) {
    D_803D5530->state = 201;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    func_802B8720_6C9DD0();
}

void func_802A55AC_6B6C5C(u16 rotation, s8 arg1) {
    D_803D5530->state = 202;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A5620_6B6CD0(u16 rotation, s8 arg1) {
    D_803D5530->state = 0xCC;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8918_6C9FC8();
}

void func_802A5694_6B6D44(u16 rotation, s8 arg1) {
    D_803D5530->state = 0xCB;
    D_803D552C->unk31A = D_803D5524->unkA4;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    func_802B8978_6CA028();
}

void func_802A5708_6B6DB8(s16 arg0, s16 arg1, s8 arg2) {
    D_803D5530->yRotation = arg0 & 0xFF;
    D_803D5530->unk28 = arg1;
    D_803D5530->state = 81;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg2;
    func_802B8A48_6CA0F8();
}

void func_802A5778_6B6E28(s16 arg0, u8 arg1) {
    s32 var_a1; // sp44
    s16 xVel;   // sp42
    s16 zVel;   // sp40

    D_803D552C->unk36D = 1;

    if ((D_803D5530->unk6C != NULL) || arg1) {
        zVel = 0; xVel = 0;
    } else {
        func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &xVel, &zVel, D_803D5530->unk160);
    }

    if ((arg1 == 0) && (D_803D5530->unk6C == 0) && ((xVel != 0) || (zVel != 0))) {
        u8 var_v1;
        if (D_803D5530->unk160 == 2) {
            var_v1 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk3].unk0;
        } else {
            var_v1 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk2].unk0;
        }
        if (var_v1 == 0) {
            return;
        }
    }

    D_803D5530->state = 42;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 0x16;
    if (arg1) {
        var_a1 = (arg0 + 6) * (D_803D5524->unkA6 << 0xD);
    } else if (arg0 == 0) {
        var_a1 = (D_803D5524->unkA6 & 0xFFFF) << 0x10;
    } else {
        D_803D5530->xVelocity.w += (D_803D5524->unkA4 >> 6) * SIN(D_803D5530->yRotation) * 2;
        D_803D5530->zVelocity.w += (D_803D5524->unkA4 >> 6) * COS(D_803D5530->yRotation) * 2;
        var_a1 = (arg0 + 1) * (D_803D5524->unkA6 << 0xE);
    }

    if (xVel <= -24) {
        D_803D5530->xVelocity.w = MIN(D_803D5530->xVelocity.w, -var_a1 >> 3);
    }
    if (xVel >= 24) {
        D_803D5530->xVelocity.w = MAX(D_803D5530->xVelocity.w, var_a1 >> 3);
    }
    if (zVel <= -24) {
        D_803D5530->zVelocity.w = MIN(D_803D5530->zVelocity.w, -var_a1 >> 3);
    }
    if (zVel >= 24) {
        D_803D5530->zVelocity.w = MAX(D_803D5530->zVelocity.w, var_a1 >> 3);
    }

    if ((ABS(xVel) >= 24) || (ABS(zVel) >= 24)) {
        D_803D5530->yVelocity.w += var_a1 >> 4;
    } else {
        D_803D5530->yVelocity.w += var_a1;
    }

    D_803D552C->unk30C = MAX(6, D_803D552C->unk30C);

    play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);

    if ((D_803D5530->unk6C != NULL) && (D_803D5530->unk6C->unk162 == 5) && (D_803D5530->unk6C->unk4C.unk1D != 0)) {
        D_803D5530->unk6C->yVelocity.w -= MIN(FTOFIX32(4.0), (D_803D5530->unk44 << 0x13) / D_803D5530->unk6C->unk44);
    }
    D_803D552C->unk368 = arg0 * 4;
}

void func_802A5C80_6B7330(void) {
    D_803D5530->state = 41;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk30C = MAX(6, D_803D552C->unk30C);
    func_802B8720_6C9DD0();
}

void func_802A5CF4_6B73A4(void) {
    D_803D552C->unk30E = 50;
    D_803D5530->state = 123;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;
    D_803D552C->unk368 = 0;
    D_803D5530->yVelocity.w = 2 * gGravity;
    D_803D5530->unk162 = 2;
}

void func_802A5D64_6B7414(void) {
    D_803D5530->state = 121;
    D_803D552C->unk31A = 0;
    D_803D5530->yVelocity.w = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 1;
    func_802B8720_6C9DD0();
}

void func_802A5DD0_6B7480(void) {
    D_803D5530->state = 62;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2FC = 22;
    D_803D552C->unk368 = 0;
    D_803D5530->yVelocity.w = 0;
}

void func_802A5E1C_6B74CC(u16 rotation) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 162;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 16;
}

void func_802A5E64_6B7514(void) {
    D_803D5530->state = 161;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D552C->unk308 = 10;
}

void func_802A5EA4_6B7554(void) {
    D_803D5530->state = 141;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = (u8)0;
    func_802B8720_6C9DD0();
}

void func_802A5EF8_6B75A8(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 142;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A5F9C_6B764C(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 144;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = -arg1;
    D_803D552C->unk31A = arg1 * D_803D5524->unkA4 / 16;
    func_802B8790_6C9E40();
}

void func_802A6044_6B76F4(u16 rotation, s8 arg1) {
    D_803D5530->yRotation = rotation;
    D_803D5530->state = 143;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = arg1;
    D_803D552C->unk31A = D_803D5524->unkA4 >> 1;
    func_802B8810_6C9EC0();
}

void func_802A60C4_6B7774(void) {
    D_803D5530->state = 101;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
}

void func_802A6100_6B77B0(void) {
    D_803D5530->state = 103;
    D_803D552C->unk31A = 0;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
}

void func_802A613C_6B77EC(u16 rotation) {
    D_803D5530->state = 104;
    if (rotation != 256) {
        D_803D5530->yRotation = rotation;
    }
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A6198_6B7848(u16 rotation) {
    D_803D5530->state = 105;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 16;
    D_803D5530->unk162 = 2;
}

void func_802A61EC_6B789C(u16 rotation) {
    D_803D5530->state = 106;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A623C_6B78EC(s16 arg0, s16 arg1) {
    D_803D5530->state = 221;
    D_803D552C->unk308 = arg0;
    D_803D552C->unk30A = arg1 * 16;
    D_803D552C->unk368 = 0;
    D_803D5530->unk162 = 2;
}

void func_802A628C_6B793C(void) {
    s32 xVel;
    s32 zVel;
    s16 tmp;

    func_802E4A78_6F6128(D_803D552C->unk308);
    tmp = gCameras[gCameraId].unk20;
    xVel = ((COS(tmp) >> 7) * D_801D9ED8.unkFFDC) * 16;
    zVel = ((SIN(tmp) >> 7) * -D_801D9ED8.unkFFDC) * 16;
    D_803D5530->xVelocity.w += xVel;
    D_803D5530->zVelocity.w += zVel;
    D_803D552C->unk368 = 0;
    D_803D5546 = 50;
    func_802B2EA8_6C4558();
    D_803D5530->unk162 = 3;
}

void func_802A6390_6B7A40(void) {
    if (D_803D552C->unk360 == 0) {
        D_803D552C->unk360 = 3;
        D_803D552C->unk361 = 0;
    }
}

void func_802A63C0_6B7A70(void) {
    if (D_803D552C->unk360 == 0) {
        D_803D552C->unk360 = 3;
        D_803D552C->unk361 = 1;
    } else {
        D_803D552C->unk361 = 1;
    }
}

void func_802A6400_6B7AB0(void) {
    switch (D_803D5530->state) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        D_803D5530->state = 5;
        break;
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
        D_803D5530->state = 103;
        break;
    case 0xB5:
    case 0xB6:
    case 0xB7:
    case 0xB8:
    case 0xB9:
        D_803D5530->state = 184;
        break;
    }
}

s32 func_802A64B0_6B7B60(void) {
    s32 pad;
    s16 sp5A;
    s16 sp58;
    u8  var_v1_16;
    s8  var_a1;
    s8  pad2;
    s8  sp54;

    sp54 = 0;
    if (D_803D5530->unk161 != 1) {
        D_803D5530->unk54.unk0 |= (0x2|0x8);
    }
    if (D_803D5538 != 0) {
        D_801D9ED8.unkFFCE = 1;
    }
    D_803D552C->unk367 = D_803D5524->unkE7;
    func_802B8B1C_6CA1CC();
    if ((D_803D5544 - D_803D5530->unk48) > 6) {
        if ((D_803D552C->unk369 == 2) && (((D_803D5524->unk9C == GORILLA)) || (D_803D5524->unk9C == POLAR_BEAR))) {
            D_803D552C->unk369 = 0U;
            func_8037D340_78E9F0(0x19, 0xC0);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x7FFF, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            func_8034220C_7538BC(0x1E, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h);
            if (D_803D5538 != 0) {
                do_rumble(0, 0xC, 0x3C, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
            }
        }
    }

    if ((D_803D5524->canJump & 2) && (D_803D5538 != 0)) {
        func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &sp5A, &sp58, D_803D5530->unk160);
        if ((sp5A > -24) && (sp5A < 24) && (sp58 > -24) && (sp58 < 24)) {
            if (D_801D9ED8.curAButton != 0) {
                D_803D5530->yVelocity.w = ABS(D_803D5530->yVelocity.w) + (D_803D5524->unkA6 << 0xE);
                if (D_803D5530->yVelocity.h > 0x23) {
                    D_803D5530->yVelocity.w = 0x230000;
                }
                play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                if (D_803D5530->yVelocity.h > 20) {
                    func_803421E0_753890(0xF);
                }
                D_803D552C->unk36D = 1;
                return 0;
            }

            if (D_803D5530->yVelocity.h < -D_803D5524->unkA6) {
                D_803D5530->yVelocity.w = ABS(D_803D5530->yVelocity.w) / 2;
                return 0;
            }
        } else if ((sp5A > -72) && (sp5A < 72) && (sp58 > -72) && (sp58 < 72)) {
            if (D_803D5530->yVelocity.h < -2) {
                if (sp5A < -24) {
                    D_803D5530->xVelocity.w -= MIN(0x80000, ABS(D_803D5530->yVelocity.w / 4));
                }
                if (sp5A > 24) {
                    D_803D5530->xVelocity.w += MIN(0x80000, ABS(D_803D5530->yVelocity.w / 4));
                }
                if (sp58 < -24) {
                    D_803D5530->zVelocity.w -= MIN(0x80000, ABS(D_803D5530->yVelocity.w / 4));
                }
                if (sp58 > 24) {
                    D_803D5530->zVelocity.w += MIN(0x80000, ABS(D_803D5530->yVelocity.w / 4));
                }

                D_803D5546 = MAX(D_803D5546, 6);
            }
            if (D_801D9ED8.curAButton != 0) {
                D_803D5530->yVelocity.w = ABS((D_803D5530->yVelocity.w * 3) / 4) + (D_803D5524->unkA6 << 0xE);
                if (D_803D5530->yVelocity.h > 0x23) {
                    D_803D5530->yVelocity.w = 0x230000;
                }
                play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                if (D_803D5530->yVelocity.h > 20) {
                    func_803421E0_753890(0xF);
                }
                D_803D552C->unk36D = 1;
                return 0;
            }
            if (D_803D5530->yVelocity.h < - D_803D5524->unkA6) {
                D_803D5530->yVelocity.w = ABS(D_803D5530->yVelocity.w * 3) / 4;
                return 0;
            } else {
                // nothing
            }
        } else {
            // nothing
        }
    }

    if (D_803D5530->unk161 == 1) {
        if (D_803D5530->unk68->unk16C->unk2 == 5) {
            var_a1 = D_803D5530->unk68->unk16C->unkE6;
            if ((D_803D5530->unk68->unk16C->unk9C == TORTOISE_TANK_DEFENDING) || (D_803D5530->unk68->unk16C->unk9C == RACING_TORTOISE_DEFENDING) || (D_803D5530->unk68->unk16C->unk9C == DESERT_FOX_ATTACKING)) {
                var_a1 = D_803D5524->unkE6;
            }
            if ((var_a1 < D_803D5524->unkE6) && ((D_803D5530->unk68->unk366 != MOVEMENT_MODE_DEACTIVATED)) && (D_803D5530->unk68->unk366 != MOVEMENT_MODE_2)) {
                D_803D5530->yVelocity.w = 0xE0000;
                if (D_803D5530->unk68->unk4C.unk1A == 0) {
                    D_803D5530->unk68->health = (s16) (D_803D5530->unk68->health - 0x14);
                }
                D_803D5530->unk68->unk65 = 0x14;
                D_803D5530->unk162 = 3U;
                play_sound_effect_at_location(0x4B, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                func_80349280_75A930(D_803D5530->unk68, 0x14);
                func_802B8890_6C9F40();
            } else if (var_a1 == D_803D5524->unkE6) {
                D_803D5530->yVelocity.w = (ABS(D_803D5530->yVelocity.w) >> 3);
                if (D_803D5530->yVelocity.w < 0x40000) {
                    D_803D5530->yVelocity.w = 0;
                }
            } else {
                D_803D5530->yVelocity.w = (ABS(D_803D5530->yVelocity.w) >> 3);
                if (D_803D5530->yVelocity.w < 0x40000) {
                    D_803D5530->yVelocity.w = 0;
                }
            }
        } else if ((D_803D5530->unk68->unk162 == 5) && (D_803D5530->unk68->unk4C.unk1D)) {
            D_803D5530->unk68->yVelocity.w = D_803D5530->yVelocity.w = ((((D_803D5530->yVelocity.w >> 8) * D_803D5530->unk44) + (((s32) D_803D5530->unk68->yVelocity.w >> 8) * D_803D5530->unk68->unk44)) / (s32) (D_803D5530->unk44 + D_803D5530->unk68->unk44)) << 8;;
        }
    }

    if (D_803D5530->yVelocity.h < -D_803D5524->fallDistance) {
        spawn_dizzy_stars_big();
        if (D_803D5530->unk44 > 50) {
            func_803421E0_753890(40);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            if (D_803D5538 != 0) {
                do_rumble(0, 0x19, 0x37, 5, 0);
            }
        } else if (D_803D5530->unk44 > 20) {
            func_803421E0_753890(30);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            if (D_803D5538 != 0) {
                do_rumble(0, 0x12, 0x32, 5, 0);
            }
        } else {
            func_803421E0_753890(20);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
        if (D_803D5530->unk4C.unk1A == 0) {
            D_803D5530->health = 0;
        }
    } else if (D_803D5530->yVelocity.h < -((D_803D5524->fallDistance * 2) >> 2)) {
        spawn_dizzy_stars_big();
        if (D_803D5530->unk44 > 50) {
            func_803421E0_753890(30);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            if (D_803D5538 != 0) {
                do_rumble(0, 0x19, 0x37, 5, 0);
            }
        } else if (D_803D5530->unk44 > 20) {
            func_803421E0_753890(17);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            if (D_803D5538 != 0) {
                do_rumble(0, 0x12, 0x32, 5, 0);
            }
        } else {
            func_803421E0_753890(10);
            play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            if (D_803D5538 != 0) {
                do_rumble(0, 0xC, 0x2D, 5, 0);
            }
        }
        if (D_803D5530->unk4C.unk1A == 0) {
            D_803D5530->health = MAX(0, D_803D5530->health - (D_803D5524->unk8A >> 1));
        }
    } else {
        D_803D553A = 1;
        play_footstep_sfx(D_803D5524->mass, D_803D5524->unk9C, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk160);
        if (D_803D5538 != 0) {
            do_rumble(0, 5, 0x2D, 5, 0);
        }
    }

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
    case 2:
    case 3:
        if (D_803D5530->state == 0x6A) {
            func_802A60C4_6B7774();
            D_803D5530->unk162 = 1;
            if (D_803D5524->unk9C == PARROT_ATTACKING) {
                load_animal(PARROT);
                if (D_803D5530->yVelocity.h < -20) {
                    do_rumble(0, 0xF, 0x46, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
                } else if (D_803D5530->yVelocity.h < -10) {
                    do_rumble(0, 0xA, 0x28, 5, distance_from_player(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h));
                }
            }
        }

        if (D_803D5530->state < 7) {
            func_802A4390_6B5A40();
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x19) {
            func_802A4CB8_6B6368();
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x2B) {
            func_802A5C80_6B7330();
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x40) {
            D_803D5530->state = 161;
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x52) {
            sp54 = 1;
            func_802B38FC_6C4FAC(D_803D5530, 3, -1, 0);
            D_803D5530->yVelocity.h = MAX(8, (s32)(8u - (D_803D5530->yVelocity.h >> 1)));
        } else if (D_803D5530->state < 0x6B) {
            func_802A60C4_6B7774();
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x7C) {
            func_802A5D64_6B7414();
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0x91) {
            D_803D5530->unk162 = 6;
        } else if (D_803D5530->state < 0xA3) {
            D_803D5530->unk162 = 1;
        } else if (D_803D5530->state < 0xBA) {
            D_803D5530->unk162 = 6;
        } else if (D_803D5530->state < 0xCD) {
            D_803D5530->unk162 = 6;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        if (D_803D5530->state == 0xB8) {
            func_802A4E74_6B6524();
            D_803D5530->unk162 = 6;
        } else {
            D_803D5530->unk162 = 6;
        }
        break;
    }
    if (D_803D5530->unk161 == 1) {
        return 0;
    }
    if (D_803D5530->unk160 == 2) {
        var_v1_16 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk3].unk3;
    } else {
        var_v1_16 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk2].unk3;
    }

    if (var_v1_16 < 17) {
        var_v1_16 = 0;
    } else {
        var_v1_16 -= 16;
    }
    if ((D_803D5524->unk9C == POLAR_BEAR_DEFENDING) && (D_803D5538 != 0)) {
        var_v1_16 += 15;
    }

    if (((s8)func_80311D48_7233F8(D_803D5530) != 0) || (sp54 != 0)) {
        return 0;
    }
    if (var_v1_16 == 0) {
        return 1;
    }

    D_803D5530->yVelocity.w = (ABS(D_803D5530->yVelocity.w) * var_v1_16) >> 4;
    return 0;
}

s32 func_802A7648_6B8CF8(Animal *arg0) {
    s16 pad[1];
    s16 temp_lo;
    u8 phi_v1;

    if (arg0->unk161 != 1) {
        arg0->unk54.unk0 |= (0x8|0x2);
    }
    if ((arg0->unk16C->objectType != 2) || (D_803F2D50.unk52 != 6) || (D_803F2D50.segment != 0)) {
        temp_lo = -arg0->yVelocity.h * arg0->unk44;
        if (arg0->unk44 > 120) {
            if (temp_lo > 2000) {
                play_sound_effect_at_location(SFX_UNKNOWN_75, 0x5000, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.0f);
            } else if (temp_lo > 500) {
                play_sound_effect_at_location(SFX_UNKNOWN_75, 0x2800, 0, arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 1.5f);
            }
        }
    }

    switch (arg0->unk162 & 0xF) {
    default:
    case 1:
    case 2:
    case 3:
    case 4:
        arg0->unk162 = 1;
        break;
    case 5:
    case 6:
    case 7:
        arg0->unk162 = 6;
        break;
    }
    if (arg0->unk161 == 1) {
        return 0;
    }
    if (arg0->unk160 == 2) {
        phi_v1 = D_803E1D30[D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk3].unk3;
    } else {
        phi_v1 = D_803E1D30[D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk2].unk3;
    }
    if (phi_v1 < 17) {
        phi_v1 = 0;
    } else {
        phi_v1 -= 16;
    }

    if (func_80311D48_7233F8(arg0) != 0) {
        return 0;
    }
    if (phi_v1 == 0) {
        return 1;
    }

    arg0->yVelocity.w = ((ABS(arg0->yVelocity.w) * phi_v1) >> 4);
    return 0;
}

// ESA: func_8003BF7C
void func_802A78CC_6B8F7C(void) {
    f32 var_f12;

    s32 spC8;
    s32 spC4;

    s32 var_a0;

    s32 spBC;
    s32 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 spA4;

    s32 tmp2;
    s32 tmp3;
    s16 pad[6];

    s32 sp8C;
    u16 sp8A;
    s16 sp88;
    s16 sp86;
    //
    s32 var_a2;
    s32 var_a3;
    u8 sp7B;
    Animal *sp74;
    s16 sp72;
    s16 sp70;

    static f32 D_803D5580;

    if (D_803D5530->unk4A == 0) {
        D_803D552C->unk2F4 = D_803D552C->unk2F2;
        D_803D552C->unk2F2++;
        if (D_803D552C->unk2F2 >= 0x4000) {
            D_803D552C->unk2F2 -= 0x2000;
        }
        sp74 = D_803D5530->unk6C;
        if (D_803D552C->unk367 > 0) {
            D_803D552C->unk367--;
        }

        if (D_803D5546 != 0) {
            D_803D5546--;
            if (((D_803D5530->unk162 & 0xF) == 1) || ((D_803D5530->unk162 & 0xF) == 6)) {
                D_803D5546 = 0;
            }
        }
        spB4 = D_803D552C->position.yPos.w;

        switch (D_803D5530->unk162 & 0xF) {
        case 1:
            D_803D552C->yVelocity.w -= D_803A05B4_7B1C64;
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 1:
                D_803D5530->unk162 = 3;
                func_802A6400_6B7AB0();
                D_803D552C->yVelocity.w = (D_803D552C->yVelocity.w + D_803A05B4_7B1C64) - (gGravity * 2);
                break;
            case 0:
            case 2:
                break;
            }

            if ((D_803D5530->unk6C == sp74) || (D_803D5530->unk6C == 0)) {
                sp70 = 0;
                sp72 = 0;
                if (D_803D5530->unk6C == 0) {
                    func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &sp72, &sp70, D_803D5530->unk160);
                }

                if (((ABS(sp72) < 36) && (ABS(sp70) < 36)) || ((D_803D5530->position.yPos.h - (func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10)) > 64)) {
                    D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                } else {
                    D_803D5530->yVelocity.w = MIN(0x40000, D_803D5530->position.yPos.w - spB4);
                }
            }
            if ((D_803D5530->unk162 == 3) && ((D_803D552C->unk360 != 0) || ((D_803D5524->canJump & 1) && ((D_803D5544 - D_803D555A) < 3) && (D_803D552C->unk367 == 0) && ((D_803D5560 == NULL) || (D_803D5560->unk16C->unk82.unk1))))) {
                if (D_803D552C->yVelocity.w < 0) {
                    if (D_803D552C->yVelocity.w < D_803A05B4_7B1C64) {
                        D_803D552C->yVelocity.w += D_803A05B4_7B1C64;
                    } else {
                        D_803D552C->yVelocity.w = 0;
                    }
                }
            }
            func_802B2834_6C3EE4();
            func_802A3CD0_6B5380();
            func_802AC5CC_6BDC7C(&spC8, &spC4);
            sp8A = D_803D5520->unk0->traction;
            if (D_803D5524->unk9C == SKI_HUSKY) {
                func_802A4278_6B5928(2, 0xC, sp8A);
                if (D_803D554C != 0) {
                    if ((SQ(D_803D5530->xVelocity.w / 65536.0) + SQ(D_803D5530->zVelocity.w / 65536.0)) < 784.0) {
                        D_803D5530->xVelocity.w += (SIN(D_803D552C->heading) >> 7) * 0xDE;
                        D_803D5530->zVelocity.w += (COS(D_803D552C->heading) >> 7) * 0xDE;
                    }
                }
            } else if (D_803D5524->unk9C == WALRUS) {
                func_802A4278_6B5928(2, 0xC, sp8A);
                if (D_803D554C != 0) {
                    if (D_803F2D50.unk52 != 2) {
                        D_803D5530->xVelocity.w += (SIN(D_803D552C->heading) >> 7) << 7;
                        D_803D5530->zVelocity.w += (COS(D_803D552C->heading) >> 7) << 7;
                    } else {
                        D_803D5530->xVelocity.w += (SIN(D_803D552C->heading) >> 7) << 8;
                        D_803D5530->zVelocity.w += (COS(D_803D552C->heading) >> 7) << 8;
                    }
                }
            } else if (D_803D554C != 0) {
                spC8 += (spC8 * D_803D554B) >> 4;
                spC4 += (spC4 * D_803D554B) >> 4;

                var_a2 = ABS(D_803D5530->xVelocity.w);
                var_a0 = ABS(D_803D5530->zVelocity.w);

                var_a2 = MAX(var_a2, var_a0) + (MIN(var_a2, var_a0) >> 1);
                if (var_a2 > (D_803D5524->unkA4 << 11)) {
                    sp8A = sp8A / 4;
                } else if (var_a2 > (D_803D5524->unkA4 << 10)) {
                    sp8A = sp8A / 2;
                } else if (var_a2 < (D_803D5524->unkA4 << 8)) {
                    sp8A += sp8A >> 1;
                }
            }
            if ((D_803F2D50.segment == 1) && (D_803D5530->unk6C == NULL) &&
                ((D_803D5524->unk9C == WALRUS) || ((D_803D5524->unk9C == SKI_HUSKY) && (D_803D552C->unk310 == 0)) ||
                 ((ABS(spC8) < 0x10000) && (ABS(spC4) < 0x10000) && ((ABS(D_803D5530->xVelocity.w) > 0x20000) || (ABS(D_803D5530->zVelocity.w) > 0x20000))))) {

                var_a0 = MAX(ABS(D_803D5530->xVelocity.w), ABS(D_803D5530->zVelocity.w));
                if (var_a0 >= 0x60000) {
                    var_a0 = 0x60000;
                }

                var_f12 = MIN(1.0, var_a0 / (256 * 1024.0));

                D_803D5580 = MIN(D_803D5580 + 0.2, var_f12);
                func_8032CD70_73E420(
                    0x6F,
                    0x3F,
                    ((20480.0f * D_803D5580) * 0.4),
                    0,
                    sqrtf(((var_a0 / 65536.0) + 1.0)) * 0.5,
                    D_803D5530->position.xPos.h,
                    D_803D5530->position.zPos.h,
                    D_803D5530->position.yPos.h);
            }
            func_802ABB10_6BD1C0(sp8A, &spC8, &spC4);
            func_802A3E70_6B5520(D_803D5530, &spC8, &spC4);
            D_803D552C->xVelocity.w = spC8;
            D_803D552C->zVelocity.w = spC4;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w) - D_803A05B4_7B1C64;
            break;
        case 2:
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = (D_803D5530->position.yPos.w - spB4);
                }
                if ((D_803D5544 - D_803D5530->unk48) >= 4) {
                    func_802DBA58_6ED108(6, D_803D552C);
                }
                break;
            case 1:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            case 2:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            }
            func_802B2834_6C3EE4();
            func_802AC5CC_6BDC7C(&spC8, &spC4);
            if (D_803D554C != 0) {
                spC8 += (spC8 * D_803D554B) >> 4;
                spC4 += (spC4 * D_803D554B) >> 4;
            }
            func_802AC484_6BDB34((u16)D_803D5520->unk0->unkB6 * 100, &spC8, &spC4);
            D_803D5530->xVelocity.w = spC8;
            D_803D5530->zVelocity.w = spC4;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 3:
            D_803D5580 = 0.0f;
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = MIN(MAX(0x40000, D_803D5530->yVelocity.w + 0x40000), D_803D5530->position.yPos.w - spB4);
                }
                if (D_803D552C->unk364 == 3) {
                    D_803D552C->unk364 = 4;
                    D_803D552C->attackTimer = D_803D5544;
                }
                if ((D_803D5544 - D_803D5530->unk48) >= 5) {
                    func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &sp88, &sp86, D_803D5530->unk160);
                    if ((D_803D5530->yVelocity.h < -6) || ((ABS(sp88) < 24) && (ABS(sp86) < 24))) {
                        func_802DBA58_6ED108(6, D_803D552C);
                    }
                }
                break;
            case 1:                                 /* switch 5 */
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            case 2:                                 /* switch 5 */
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            }
            func_802B2834_6C3EE4();
            if (D_803D5546 == 0) {
                func_802AC8A0_6BDF50(&spC8, &spC4);
                sp8A = D_803D5520->unk0->traction * 0x10;
                if (D_803D5524->unk9C == SKI_HUSKY) {
                    if (D_803D554C != 0) {
                        if ((SQ(D_803D5530->xVelocity.w / 65536.0) + SQ(D_803D5530->zVelocity.w / 65536.0)) < 784.0) {
                            D_803D5530->xVelocity.w += ((SIN(D_803D552C->heading) >> 7) * 0xDE);
                            D_803D5530->zVelocity.w += ((COS(D_803D552C->heading) >> 7) * 0xDE);
                        }
                    }
                } else if (D_803D554C != 0) {
                    spC8 += (spC8 * D_803D554B) >> 4;
                    spC4 += (spC4 * D_803D554B) >> 4;

                    var_a2 = ABS(D_803D5530->xVelocity.w);
                    var_a0 = ABS(D_803D5530->zVelocity.w);

                    var_a2 = MAX(var_a2, var_a0) + (MIN(var_a2, var_a0) >> 1);
                    if ((D_803D5524->unkA4 << 11) < var_a2) {
                        sp8A = sp8A / 4;
                    } else if ((D_803D5524->unkA4 << 10) < var_a2) {
                        sp8A = sp8A / 2;
                    }
                }
                func_802AC484_6BDB34(sp8A, &spC8, &spC4);
                D_803D5530->xVelocity.w = spC8;
                D_803D5530->zVelocity.w = spC4;
            }
            if ((D_803D552C->unk360 == 0) && ((((D_803D5524->canJump & 1) == 0)) || (D_803D5524->class == 8) || (((D_803D5544 - D_803D555A) & 0xFFFF) >= 3) || (D_803D552C->unk367 != 0) || ((D_803D5560 != NULL) && (D_803D5560->unk16C->unk82.unk1 == 0)))) {
                D_803D5530->yVelocity.w -= gGravity;
            }
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 4:
            spAC = D_803D5530->position.xPos.w;
            spA8 = D_803D5530->position.zPos.w;
            spA4 = D_803D5530->position.yPos.w;

            tmp3 = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            tmp2 = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            sp8C = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;

            if (((sp8C >> 0x10) - (s16)(func_8031124C_7228FC(tmp3 >> 0x10, tmp2 >> 0x10) >> 0x10)) < 0xA) {
                var_a3 = func_80310EE4_722594((D_803D5530->position.xPos.w + D_803D5530->xVelocity.w) >> 0x10, (D_803D5530->position.zPos.w + D_803D5530->zVelocity.w) >> 0x10, D_803D5530->unk160) - func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160);
                var_a2 = MAX(0, MIN(var_a3, 0x60000));
                if (D_803D5530->yVelocity.w < var_a2) {
                    D_803D5530->yVelocity.w = var_a2;
                }
            }
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if ((D_803D5530->unk6C == NULL) && (D_803D5530->unk70 == NULL)) {
                    D_803D5530->position.xPos.w = spAC;
                    D_803D5530->position.zPos.w = spA8;
                    D_803D5530->position.yPos.w = spA4;
                }
            default:
                break;
            case 1:
                break;
            case 2:
                break;
            }
            D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
            func_802B2964_6C4014();
            func_802A403C_6B56EC(D_803D5530, 5);
            func_802A4184_6B5834();
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 5:
            spBC = D_803D5530->position.xPos.w;
            spB8 = D_803D5530->position.zPos.w;
            sp7B = D_803D5530->unk160;
            func_8030AAE0_71C190(D_803D5530);

            if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - spBC, D_803D5530->position.zPos.w - spB8)) {
                D_803D5530->unk160 = sp7B;
                spB0 = D_803D5530->position.xPos.w;
                D_803D5530->position.xPos.w = spBC;
                if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - spBC, D_803D5530->position.zPos.w - spB8)) {
                    D_803D5530->position.xPos.w = spB0;
                    D_803D5530->position.zPos.w = spB8;
                    if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - spBC, D_803D5530->position.zPos.w - spB8)) {
                        D_803D5530->position.xPos.w = spBC;
                    }
                }
            }

            D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
            func_802B2964_6C4014();
            func_802A40EC_6B579C();
            func_802AC5CC_6BDC7C(&spC8, &spC4);

            sp8A = D_803D5520->unk0->unkB4;
            if (D_803D5524->unk9C == WALRUS) {
                func_802A4278_6B5928(2, 0xC, sp8A);
                if (D_803D554C != 0) {
                    D_803D5530->xVelocity.w += (((SIN(D_803D552C->heading) >> 7) * 3) << 6);
                    D_803D5530->zVelocity.w += (((COS(D_803D552C->heading) >> 7) * 3) << 6);
                }
            } else {
                if (D_803D554C != 0) {
                    spC8 += (spC8 * D_803D554B) >> 4;
                    spC4 += (spC4 * D_803D554B) >> 4;

                    var_a2 = ABS(D_803D5530->xVelocity.w);
                    var_a0 = ABS(D_803D5530->zVelocity.w);

                    if (MAX(var_a2, var_a0) + (MIN(var_a2, var_a0) >> 1) > (D_803D5524->unkAA << 0xA)) {
                        sp8A = sp8A / 2;
                    } else {
                        sp8A = sp8A * 2;
                    }
                }
            }
            func_802A3F68_6B5618(&spC8, &spC4);
            func_802AC158_6BD808(sp8A, &spC8, &spC4);
            D_803D5530->xVelocity.w = spC8;
            D_803D5530->zVelocity.w = spC4;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 6:
            D_803D5530->yVelocity.w -= gGravity;
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 1:
                func_802A6400_6B7AB0();
                D_803D5530->unk162 = 7;
                break;
            case 0:
            case 2:
                break;
            }

            if ((D_803D5530->unk6C == sp74) || (D_803D5530->unk6C == 0)) {
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
            }
            func_802B2964_6C4014();
            func_802A3CD0_6B5380();
            func_802A403C_6B56EC(D_803D5530, 3);
            func_802AC5CC_6BDC7C(&spC8, &spC4);
            func_802ABB10_6BD1C0(D_803D5520->unk0->traction, &spC8, &spC4);
            D_803D5530->xVelocity.w = spC8;
            D_803D5530->zVelocity.w = spC4;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w) - gGravity;
            break;
        case 7:
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                    if ((D_803D5544 - D_803D5530->unk48) >= 5) {
                        if (D_803D552C->unk364 == 3) {
                            D_803D552C->unk364 = 4;
                            D_803D552C->attackTimer = D_803D5544;
                        } else {
                            func_802DBA58_6ED108(6, D_803D552C);
                        }
                    }
                }
                break;
            case 1:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            case 2:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - spB4;
                break;
            }

            func_802B2964_6C4014();
            D_803D5530->yVelocity.w -= gGravity >> 2;
            func_802A403C_6B56EC(D_803D5530, 3);
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        }

        if (D_803D554C > 0) {
            D_803D554C--;
        }
        D_803D554B = 0;

        switch (D_803D5530->state) {
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x29:
        case 0x2A:
        case 0x3D:
        case 0x3E:
        case 0x65:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x8D:
        case 0x8E:
        case 0x8F:
        case 0x90:
        case 0xA1:
        case 0xA2:
        case 0xB5:
        case 0xB6:
        case 0xB7:
        case 0xB8:
        case 0xB9:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
        case 0xDD:
            D_803D552C->previousHeading = D_803D552C->heading;
            func_802DB940_6ECFF0(&D_803D552C->heading, D_803D552C->yRotation, D_803D5524->unkB0);
            break;
        case 0x51:
            D_803D552C->previousHeading = D_803D552C->heading;
            D_803D552C->heading = D_803D5530->yRotation;
            break;
        }
        D_803D5530->unk65 = 0;

        if ((D_803D5530->unk4B > 32) && (D_803D5530->unk4C.unk1A == 0)) {
            D_803D5530->health= MAX(0, D_803D5530->health - 1);
            func_80349280_75A930(D_803D5530, 1);
            if (D_803D5530->unk4B > 48) {
                D_803D5530->health = MAX(0, D_803D5530->health - 1);
                func_80349280_75A930(D_803D5530, 1);
            }
            if (D_803D5530->unk4B > 60) {
                D_803D5530->health = MAX(0, D_803D5530->health - 4);
                func_80349280_75A930(D_803D5530, 4);
            }
        }
        func_802B3230_6C48E0();

        if (D_803D5530->position.xPos.h < 128) {
            D_803D5530->position.xPos.h = 128;
            D_803D5530->xVelocity.w = 0;
        }
        if (D_803D5530->position.zPos.h < 128) {
            D_803D5530->position.zPos.h = 128;
            D_803D5530->zVelocity.w = 0;
        }
        if (D_803D5530->position.xPos.h > (35 * 128) - 1) {
            D_803D5530->position.xPos.h = (35 * 128) - 1;
            D_803D5530->xVelocity.w = 0;
        }
        if (D_803D5530->position.zPos.h > (63 * 128) - 1) {
            D_803D5530->position.zPos.h = (63 * 128) - 1;
            D_803D5530->zVelocity.w = 0;
        }

        if (((D_803D5530->state == 2) || (D_803D5530->state == 0x15) || (D_803D5530->state == 0x29) || (D_803D5530->state == 0x79)) && (D_803F6450 != 0)) {
            if ((D_803D5524->unk9C != DOG) && (D_803D5524->unk9C != HYENA) && (D_803D5524->unk9C != HYENA_BIKER)) {
                if (SSSV_RAND(32) == 0) {
                    func_802AA5C0_6BBC70();
                }
            } else if (SSSV_RAND(16) == 0) {
                func_802AA85C_6BBF0C();
            }
        }
    }
}

void func_802A935C_6BAA0C(void) {
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 pad;
    s32 pad2;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s16 pad3;
    u8  sp51;

    s32 temp_v0_8;
    s32 phi_v1;
    s32 phi_a2;
    u16 traction;

    Animal *sp3C;

    if (D_803D5530->unk4A == 0) {
        D_803D552C->unk2F4 = D_803D552C->unk2F2;
        D_803D552C->unk2F2++;
        if (D_803D552C->unk2F2 >= 0x4000) {
            D_803D552C->unk2F2 -= 0x2000;
        }
        sp3C = D_803D5530->unk6C;
        if (D_803D552C->unk367 > 0) {
            D_803D552C->unk367--;
        }
        sp58 = D_803D552C->position.yPos.w;

        switch (D_803D5530->unk162 & 0xF) {
        case 1:
            D_803D552C->yVelocity.w = (D_803D552C->yVelocity.w - D_803A05B4_7B1C64);
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 1:
                func_802A6400_6B7AB0();
                D_803D5530->unk162 = 3;
                D_803D552C->yVelocity.w = ((D_803D552C->yVelocity.w + D_803A05B4_7B1C64) - (gGravity * 2));
                break;
            case 0:
            case 2:
                break;
            }

            if ((D_803D5530->unk6C == sp3C) || (D_803D5530->unk6C == 0)) {
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
            }
            func_802B2834_6C3EE4();
            func_802A3CD0_6B5380();
            func_802AC5CC_6BDC7C(&sp7C, &sp78);
            traction = D_803D5520->unk0->traction;
            if (D_803D5524->unk9C == WALRUS) {
                traction = (traction  * 2);
                if (D_803D554C != 0) {
                    D_803D5530->xVelocity.w += (SIN(D_803D552C->heading) >> 7) << 8;
                    D_803D5530->zVelocity.w += (COS(D_803D552C->heading) >> 7) << 8;
                }
            } else {
                if (D_803D552C->unk36E != 0) {
                    sp7C += (sp7C * D_803D552C->unk36E) >> 4;
                    sp78 += (sp78 * D_803D552C->unk36E) >> 4;

                    phi_a2 = ABS(D_803D5530->xVelocity.w);
                    phi_v1 = ABS(D_803D5530->zVelocity.w);

                    temp_v0_8 = MAX(phi_a2, phi_v1) + (MIN(phi_a2, phi_v1) >> 1);
                    if ((D_803D5524->unkA4 << 0xB) < temp_v0_8) {
                        traction  = (traction  / 4);
                    } else if ((D_803D5524->unkA4 << 0xA) < temp_v0_8) {
                        traction  = (traction  / 2);
                    } else if (temp_v0_8 < (D_803D5524->unkA4 << 8)) {
                        traction  += traction  >> 1;
                    }
                }
            }
            func_802ABB10_6BD1C0(traction , &sp7C, &sp78);
            func_802A3E70_6B5520(D_803D5530, &sp7C, &sp78);
            D_803D552C->xVelocity.w = sp7C;
            D_803D552C->zVelocity.w = sp78;
            D_803D5530->newPosition.xPos.w = (s32) (D_803D5530->position.xPos.w + D_803D5530->xVelocity.w);
            D_803D5530->newPosition.zPos.w = (s32) (D_803D5530->position.zPos.w + D_803D5530->zVelocity.w);
            D_803D5530->newPosition.yPos.w = (s32) ((D_803D5530->position.yPos.w + D_803D5530->yVelocity.w) - D_803A05B4_7B1C64);
            break;
        case 2:
            switch (func_8030AAE0_71C190(D_803D5530)) {                    /* switch 4; irregular */
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = (s32) (D_803D5530->position.yPos.w - sp58);
                }
                if ((D_803D5544 - D_803D5530->unk48) >= 4) {
                    func_802DBA58_6ED108(6, D_803D552C);
                }
                break;
            case 1:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            case 2:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            }
            func_802B2834_6C3EE4();
            func_802AC5CC_6BDC7C(&sp7C, &sp78);
            func_802AC484_6BDB34(((u16)D_803D5520->unk0->unkB6 * 0x64), &sp7C, &sp78);
            D_803D5530->xVelocity.w = sp7C;
            D_803D5530->zVelocity.w = sp78;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 3:
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = (s32) (D_803D5530->position.yPos.w - sp58);
                }
                if ((D_803D5544 - D_803D5530->unk48) >= 4) {
                    if (D_803D552C->unk364 == 3) {
                        D_803D552C->unk364 = 4U;
                        D_803D552C->attackTimer = D_803D5544;
                    } else {
                        func_802DBA58_6ED108(6, D_803D552C);
                    }
                }
                break;
            case 1:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            case 2:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            }
            func_802AC5CC_6BDC7C(&sp7C, &sp78);
            func_802AC484_6BDB34((D_803D5520->unk0->traction * 0x10), &sp7C, &sp78);
            D_803D5530->xVelocity.w = sp7C;
            D_803D5530->zVelocity.w = sp78;
            func_802B2834_6C3EE4();
            D_803D5530->yVelocity.w = D_803D5530->yVelocity.w - gGravity;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
            break;
        case 4:
            sp74 = D_803D5530->position.xPos.w;
            sp70 = D_803D5530->position.zPos.w;
            sp6C = D_803D5530->position.yPos.w;
            switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 6; irregular */
            case 0:
                if ((D_803D5530->unk6C == NULL) && (D_803D5530->unk70 == NULL)) {
                    D_803D5530->position.xPos.w = sp74;
                    D_803D5530->position.zPos.w = sp70;
                    D_803D5530->position.yPos.w = sp6C;
                }
                break;
            case 1:
                break;
            case 2:
                break;
            }
            D_803D5530->yVelocity.w = (D_803D5530->position.yPos.w - sp58);
            func_802B2964_6C4014();
            func_802A4220_6B58D0(&D_803D5530->xVelocity.w, &D_803D5530->zVelocity.w, 210);
            func_802A403C_6B56EC(D_803D5530, 3);
            func_802A4184_6B5834();
            D_803D5530->newPosition.xPos.w = (D_803D5530->position.xPos.w + D_803D5530->xVelocity.w);
            D_803D5530->newPosition.zPos.w = (D_803D5530->position.zPos.w + D_803D5530->zVelocity.w);
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w);
            break;
        case 5:
            sp60 = D_803D5530->position.xPos.w;
            sp5C = D_803D5530->position.zPos.w;
            sp51 = D_803D5530->unk160;

            if (func_8030AAE0_71C190(D_803D5530)) {
                // fakematch
                if (D_803D5530 && D_803D5530) {};
            }

            if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - sp60, D_803D5530->position.zPos.w - sp5C) != 0) {
                D_803D5530->unk160 = sp51;
                sp54 = D_803D5530->position.xPos.w;
                D_803D5530->position.xPos.w = sp60;
                if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - sp60, D_803D5530->position.zPos.w - sp5C) != 0) {
                    D_803D5530->position.xPos.w = sp54;
                    D_803D5530->position.zPos.w = sp5C;
                    if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - sp60, D_803D5530->position.zPos.w - sp5C) != 0) {
                        D_803D5530->position.xPos.w = sp60;
                    }
                }
            }
            D_803D5530->yVelocity.w = (D_803D5530->position.yPos.w - sp58);
            func_802B2964_6C4014();
            func_802A40EC_6B579C();
            func_802AC5CC_6BDC7C(&sp7C, &sp78);
            func_802A3F68_6B5618(&sp7C, &sp78);
            traction = D_803D5520->unk0->unkB4; // not traction?
            if (D_803D5524->unk9C == WALRUS) {
                traction = ((traction  * 5) >> 1);
                if (D_803D554C != 0) {
                    D_803D5530->xVelocity.w += ((SIN(D_803D552C->heading) >> 7) << 8);
                    D_803D5530->zVelocity.w += ((COS(D_803D552C->heading) >> 7) << 8);
                }
            }
            func_802AC158_6BD808(traction, &sp7C, &sp78);
            D_803D5530->xVelocity.w = sp7C;
            D_803D5530->zVelocity.w = sp78;
            D_803D5530->newPosition.xPos.w = (D_803D5530->position.xPos.w + D_803D5530->xVelocity.w);
            D_803D5530->newPosition.zPos.w = (D_803D5530->position.zPos.w + D_803D5530->zVelocity.w);
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w);
            break;
        case 6:
            D_803D5530->yVelocity.w = (s32) (D_803D5530->yVelocity.w - gGravity);
            switch (func_8030AAE0_71C190(D_803D5530)) {                   /* switch 7; irregular */
            case 1:
                func_802A6400_6B7AB0();
                D_803D5530->unk162 = 7;
                break;
            case 0:
            case 2:
                break;
            }
            if ((D_803D5530->unk6C == sp3C) || (D_803D5530->unk6C == 0)) {
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
            }
            func_802B2964_6C4014();
            func_802A3CD0_6B5380();
            func_802A403C_6B56EC(D_803D5530, 3);
            func_802AC5CC_6BDC7C(&sp7C, &sp78);
            func_802ABB10_6BD1C0(D_803D5520->unk0->traction, &sp7C, &sp78);
            D_803D5530->xVelocity.w = sp7C;
            D_803D5530->zVelocity.w = sp78;
            D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
            D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w) - gGravity;
            break;
        case 7:
            switch (func_8030AAE0_71C190(D_803D5530)) {
            case 0:
                if (func_802A64B0_6B7B60() != 0) {
                    D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                }
                break;
            case 1:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            case 2:
                D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp58;
                break;
            }
            func_802B2964_6C4014();
            D_803D5530->yVelocity.w = (s32) (D_803D5530->yVelocity.w - ((s32) gGravity >> 2));
            func_802A403C_6B56EC(D_803D5530, 3);
            D_803D5530->newPosition.xPos.w = (D_803D5530->position.xPos.w + D_803D5530->xVelocity.w);
            D_803D5530->newPosition.zPos.w = (D_803D5530->position.zPos.w + D_803D5530->zVelocity.w);
            D_803D5530->newPosition.yPos.w = (D_803D5530->position.yPos.w + D_803D5530->yVelocity.w);
            break;
        }

        switch (D_803D5530->state) {
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x29:
        case 0x3D:
        case 0x3E:
        case 0x65:
        case 0x68:
        case 0x69:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x8D:
        case 0x8E:
        case 0x8F:
        case 0x90:
        case 0xA1:
        case 0xA2:
        case 0xB5:
        case 0xB6:
        case 0xB7:
        case 0xB9:
        case 0xC9:
        case 0xCA:
        case 0xCB:
        case 0xCC:
            D_803D552C->previousHeading = D_803D552C->heading;
            func_802DB940_6ECFF0(&D_803D552C->heading, D_803D552C->yRotation, D_803D5524->unkB0);
            break;
        case 0x51:
            D_803D552C->previousHeading = D_803D552C->heading;
            D_803D552C->heading = D_803D5530->yRotation;
            break;
        }
        func_802B3230_6C48E0();

        // hard level borders
        if (D_803D5530->position.xPos.h < 128) {
            D_803D5530->position.xPos.h = 128;
            D_803D5530->xVelocity.w = 0;
        }
        if (D_803D5530->position.zPos.h < 128) {
            D_803D5530->position.zPos.h = 128;
            D_803D5530->zVelocity.w = 0;
        }
        if (D_803D5530->position.xPos.h > (35 * 128) - 1) {
            D_803D5530->position.xPos.h = (35 * 128) - 1;
            D_803D5530->xVelocity.w = 0;
        }
        if (D_803D5530->position.zPos.h > (63 * 128) - 1) {
            D_803D5530->position.zPos.h = (63 * 128) - 1;
            D_803D5530->zVelocity.w = 0;
        }
    }
}

void func_802AA0A0_6BB750(void) {
    if ((D_803D552C->unk366 != MOVEMENT_MODE_CRITICAL) &&
        ((D_803D5530->state == 2) || (D_803D5530->state == 0x15) || (D_803D5530->state == 0x29) || (D_803D5530->state == 0x79)) &&
        (SSSV_RAND(32) == 0) && (D_803F6450 != 0)) {
        func_802AA5C0_6BBC70();
    }
    if ((D_803D5530->unk4B > 32) && (D_803D5530->unk4C.unk1A == 0)) {
        D_803D5530->health = MAX(0, D_803D5530->health - 1);
        func_80349280_75A930(D_803D5530, 1);

        if (D_803D5530->unk4B > 48) {
            D_803D5530->health = MAX(0, D_803D5530->health - 1);
            func_80349280_75A930(D_803D5530, 1);
        }

        if (D_803D5530->unk4B > 60) {
            D_803D5530->health = 0;
            func_80349280_75A930(D_803D5530, 40);
        }
    }
}

// follow waypoint?
void func_802AA1EC_6BB89C(void) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    u8 sp37;

    if (D_803D5530->state != 0x1F) {
        switch (D_803D5530->unk162 & 0xF) {
        case 4:
        case 5:
        case 6:
        case 7:
            sp3C = D_803D5530->position.xPos.w;
            sp38 = D_803D5530->position.zPos.w;
            sp37 = D_803D5530->unk160;
            func_802AA444_6BBAF4();
            if (func_802B2AF0_6C41A0(D_803D5530->position.xPos.w - sp3C, D_803D5530->position.zPos.w - sp38) != 0) {
                D_803D5530->unk160 = sp37;
                D_803D5530->position.xPos.w = sp3C;
                D_803D5530->position.zPos.w = sp38;
            }
            func_802B2964_6C4014();
            func_802A40EC_6B579C();
            sp40 = 0;
            sp44 = 0;
            func_802A3F68_6B5618(&sp44, &sp40);
            func_802AC158_6BD808(3, &sp44, &sp40);
            D_803D5530->xVelocity.w = sp44;
            D_803D5530->zVelocity.w = sp40;
            break;
        case 2:
        case 3:
            func_802AA444_6BBAF4();
            if ((D_803D5530->unk162 == 1) && (D_803D5530->yVelocity.h < -0xA)) {
                play_sound_effect_at_location(SFX_UNKNOWN_72, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 0.5f);
            }
            func_802B2834_6C3EE4();
            D_803D552C->yVelocity.w -= gGravity;
            break;
        default:
            func_802AA444_6BBAF4();
            func_802B2834_6C3EE4();
            func_802A3CD0_6B5380();
            sp40 = 0;
            sp44 = 0;
            func_802ABB10_6BD1C0(30, &sp44, &sp40);
            func_802A3E70_6B5520(D_803D5530, &sp44, &sp40);
            D_803D552C->xVelocity.w = sp44;
            D_803D552C->zVelocity.w = sp40;
            D_803D552C->yVelocity.w -= gGravity;
            break;
        }
    }
    D_803D552C->previousHeading =  D_803D552C->heading = D_803D552C->yRotation;
}

void func_802AA424_6BBAD4(void) {
    func_802AA444_6BBAF4();
}

void func_802AA444_6BBAF4(void) {
    s32 sp1C;
    s32 temp_v0;

    sp1C = D_803D552C->position.yPos.w;
    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        if ((temp_v0 != 0) && (temp_v0 == 1)) {
            D_803D5530->unk162 = 3;
        }
        break;
    case 2:
    case 3:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        switch (temp_v0) {
        case 0:
            D_803D5530->unk162 = 1;
            break;
        case 1:
            D_803D5530->unk162 = 3;
            break;
        }
        break;
    case 4:
    case 5:
    case 7:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        switch (temp_v0) {
        case 0:
            D_803D5530->unk162 = 6;
            break;
        case 1:
            D_803D5530->unk162 = 5;
            break;
        }
        break;
    case 6:
        temp_v0 = func_8030AAE0_71C190(D_803D5530);
        if ((temp_v0 != 0) && (temp_v0 == 1)) {
            D_803D5530->unk162 = 7;
        }
        break;
    }
    D_803D5530->yVelocity.w = D_803D5530->position.yPos.w - sp1C;
}

void func_802AA5C0_6BBC70(void) {
    u8 rand = (func_8012826C() >> 8) & 0xF;
    switch (rand) {
    case 0:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 1;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 1:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 1;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 2:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 1;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 3:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 1;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 4:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 11;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 5:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 11;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 6:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 11;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 7:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 11;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 8:
    case 9:
        if ((D_803D5528->unk3C0.unk0 == 0) && (D_803D5524->unk9C != RACING_DOG) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0.unk0 = 1;
            D_803D5528->unk3C0.unk2 = 0;
        }
        break;
    case 10:
    case 11:
        if ((D_803D5528->unk3C0.unk0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0.unk0 = 5;
            D_803D5528->unk3C0.unk2 = 0;
        }
        break;
    }
}

void func_802AA85C_6BBF0C(void) {
    u8 rand = (func_8012826C() >> 8) & 0xF;

    switch (rand) {
    case 0:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 1;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 1:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 1;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 2:
        break;
    case 3:
        if ((D_803D5528->unk3C0.unk0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0.unk0 = 17;
            D_803D5528->unk3C0.unk2 = 0;
        }
        break;
    case 4:
        if ((D_803D5528->unk370.unk10 == 0) && (D_803D5528->unk384.unk10 == 0)) {
            D_803D5528->unk370.unk10 = 11;
            D_803D5528->unk370.unk12 = 0;
        }
        break;
    case 5:
        if ((D_803D5528->unk384.unk10 == 0) && (D_803D5528->unk370.unk10 == 0)) {
            D_803D5528->unk384.unk10 = 11;
            D_803D5528->unk384.unk12 = 0;
        }
        break;
    case 6:
        if ((D_803D5528->unk398.unk10 == 0) && (D_803D5528->unk3AC.unk10 == 0)) {
            D_803D5528->unk398.unk10 = 11;
            D_803D5528->unk398.unk12 = 0;
        }
        break;
    case 7:
        if ((D_803D5528->unk3AC.unk10 == 0) && (D_803D5528->unk398.unk10 == 0)) {
            D_803D5528->unk3AC.unk10 = 11;
            D_803D5528->unk3AC.unk12 = 0;
        }
        break;
    case 8:
    case 9:
    case 10:
    case 11:
        if ((D_803D5528->unk3C0.unk0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0.unk0 = 5;
            D_803D5528->unk3C0.unk2 = 0;
        }
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        if ((D_803D5528->unk3C0.unk0 == 0) && (D_803D552C->unk318 == 0)) {
            D_803D5528->unk3C0.unk0 = 19;
            D_803D5528->unk3C0.unk2 = 0;
        }
        break;
    }
}

void func_802AAAB0_6BC160(void) {
    u16 state;

    if ((D_803D552C->unk360 != 0) && (--D_803D552C->unk360 == 0)) {
        func_802A467C_6B5D2C(D_803D552C->unk361);
    }

    state = D_803D5530->state;
    if (state < 7) {
        func_802AC980_6BE030();
        func_802AD87C_6BEF2C();
    } else if (state < 25) {
        func_802AC980_6BE030();
        func_802AE278_6BF928();
    } else if (state < 0x2B) {
        func_802AC980_6BE030();
        func_802AE9C4_6C0074();
    } else if (state < 0x40) {
        func_802AD63C_6BECEC();
        func_802AEE18_6C04C8();
    } else if (state < 0x52) {
        func_802AD63C_6BECEC();
        func_802AE698_6BFD48();
    } else if (state < 0x6B) {
        func_802AC980_6BE030();
        func_802AF9FC_6C10AC();
    } else if (state < 0x7C) {
        func_802AC980_6BE030();
        func_802AEBB0_6C0260();
    } else if (state < 0x91) {
        func_802AC980_6BE030();
        func_802AF308_6C09B8();
    } else if (state < 0xA3) {
        func_802AC980_6BE030();
        func_802AF7E4_6C0E94();
    } else if (state < 0xBA) {
        func_802AC980_6BE030();
        func_802ADDD0_6BF480();
    } else if (state < 0xCD) {
        func_802AC980_6BE030();
        func_802AE488_6BFB38();
    } else if (state < 0xDE) {
        func_802AD63C_6BECEC();
        func_802B066C_6C1D1C();
    }

    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A == 0) {
        if ((D_801D9ED8.curAButton != 0) &&
            ((D_803D552C->energy[0].unk2 == 0) || (D_803D552C->energy[0].unk2 == 0x7FFE)) &&
            (func_8035E344_76F9F4(D_803D5520, 0))) {

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EE89C_6FFF4C();
                break;
            case BEAR:
                func_803277B4_738E64();
                break;
            case MYSTERY_BEAR:
                func_803279BC_73906C();
                break;
            case RACING_DOG:
                func_802EEA7C_70012C();
                break;
            case FIRE_FOX:
                func_802E84E0_6F9B90();
                break;
            case FOX:
            case RACING_FOX:
                func_802E864C_6F9CFC();
                break;
            case RACING_MOUSE:
                func_8031F8BC_730F6C();
                break;
            case RAT:
                func_8035F92C_770FDC();
                break;
            case CANNON_CAMEL:
                func_8036F404_780AB4();
                break;
            case SCORPION:
                func_80379048_78A6F8();
                break;
            case KING_PENGUIN:
                func_80365954_777004();
                break;
            case WALRUS:
                func_803766E8_787D98();
                break;
            case SKI_HUSKY:
                func_8036BBE8_77D298();
                break;
            case POLAR_TANK:
                func_80368B78_77A228();
                break;
            case CHAMELEON:
                chameleon_attack();
                break;
            case HYENA_BIKER:
                func_8035A170_76B820();
                break;
            case HIPPO:
                func_802F0374_701A24();
                break;
            case ELEPHANT:
                func_8037D06C_78E71C();
                break;
            case RACING_TORTOISE:
                func_80355F64_767614();
                break;
            case SHEEP:
                sheep_float();
                break;
            case TORTOISE_TANK:
                func_80355EDC_76758C();
                break;
            case SPRINGY_THINGY:
                func_80362A00_7740B0();
                break;
            case KING_RAT:
                func_8035FA84_771134();
                break;
            case EVO_SHELLSUIT:
                func_8038B330_79C9E0();
            }
        } else {
            if ((D_801D9ED8.curAButton == 0) && (D_803D552C->energy[0].unk2 == 0x7FFF)) {
                D_803D552C->energy[0].unk2 = 0;
            }
            if (D_803D552C->energy[0].unk2 == 0x7FFE) {
                D_803D552C->energy[0].unk2 = 0x7FFF;
            }

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EE9EC_70009C();
                break;
            case ELEPHANT:
                func_8037D0EC_78E79C();
                break;
            case KING_RAT:
                func_8035FAEC_77119C();
                break;
            case SHEEP:
                func_80362964_774014();
                break;
            }
        }

        if ((D_801D9ED8.curBButton != 0) &&
            ((D_803D552C->energy[1].unk2 == 0) || (D_803D552C->energy[1].unk2 == 0x7FFE)) &&
            func_8035E344_76F9F4(D_803D5520, 1)) {

            switch (D_803D5524->unk9C) {
            case FLYING_DOG:
                func_802EEA18_7000C8();
                break;
            case BEAR:
                bear_attack();
                break;
            case PARROT:
                func_803144F8_725BA8();
                break;
            case COOL_COD:
                func_80383804_794EB4();
                break;
            case PIRANA:
                func_80382C9C_79434C();
                break;
            case DOG:
                func_802EEA54_700104();
                break;
            case RACING_DOG:
                func_802EEC44_7002F4();
                break;
            case FIRE_FOX:
                func_802E8500_6F9BB0();
                break;
            case FOX:
            case RACING_FOX:
                func_802E86C8_6F9D78();
                break;
            case MOUSE:
                func_8031F87C_730F2C();
                break;
            case RACING_MOUSE:
                func_8031FA84_731134();
                break;
            case RAT:
                func_8035FA5C_77110C();
                break;
            case CAMEL:
                func_8036F3AC_780A5C();
                break;
            case CANNON_CAMEL:
                func_8036F4CC_780B7C();
                break;
            case SCORPION:
                func_80379070_78A720();
                break;
            case BOXING_KANGAROO:
                func_80372510_783BC0();
                break;
            case POGO_KANGAROO:
                func_803725A4_783C54();
                break;
            case VULTURE:
            case VULTURE2:
                func_8036D30C_77E9BC();
                break;
            case SEAGULL:
            case SEAGULL2:
                func_80381C60_793310();
                break;
            case DESERT_FOX:
                func_80374470_785B20();
                break;
            case ARMED_DESERT_FOX:
                func_803744C4_785B74();
                break;
            case PENGUIN:
                func_80365C28_7772D8();
                break;
            case KING_PENGUIN:
                func_80365C7C_77732C();
                break;
            case WALRUS:
                func_803769E0_788090();
                break;
            case HUSKY:
                func_8036BBB8_77D268();
                break;
            case SKI_HUSKY:
                func_8036BCF8_77D3A8();
                break;
            case POLAR_BEAR:
                func_80368AC4_77A174();
                break;
            case POLAR_TANK:
                func_80368BA0_77A250();
                break;
            case RABBIT:
                func_80302018_7136C8();
                break;
            case HELI_RABBIT:
                func_80302080_713730();
                break;
            case GORILLA:
                func_8037B590_78CC40();
                break;
            case CHAMELEON:
                chameleon_hide();
                break;
            case HYENA:
                func_8035A130_76B7E0();
                break;
            case HYENA_BIKER:
                func_8035A2A8_76B958();
                break;
            case LION:
                func_802F2A2C_7040DC();
                break;
            case HIPPO:
                func_802F03B8_701A68();
                break;
            case ELEPHANT:
                func_8037D138_78E7E8();
                break;
            case TORTOISE_TANK:
                func_80355EFC_7675AC();
                break;
            case RACING_TORTOISE:
                func_80355FFC_7676AC();
                break;
            case RAM:
            case SPRINGY_RAM:
                springy_ram_headbutt();
                break;
            case SHEEP:
            case SPRINGY_THINGY:
                func_803629B0_774060();
                break;
            case FROG:
                func_80302D5C_71440C();
                break;
            case KING_RAT:
                func_8035FB10_7711C0();
                break;
            case EVO_SHELLSUIT:
                func_8038B730_79CDE0();
                break;
            }
        } else {
            if ((D_801D9ED8.curBButton == 0) && (D_803D552C->energy[1].unk2 == 0x7FFF)) {
                D_803D552C->energy[1].unk2 = 0;
            }
            if (D_803D552C->energy[1].unk2 == 0x7FFE) {
                D_803D552C->energy[1].unk2 = 0x7FFF;
            }

            switch (D_803D5524->unk9C) {
            case FOX:
            case RACING_FOX:
                func_802E8760_6F9E10();
                break;
            case MOUSE2:
                func_8031F89C_730F4C();
                break;
            case PARROT_ATTACKING:
                func_80314590_725C40();
                break;
            case TORTOISE_TANK_DEFENDING:
                func_80356064_767714();
                break;
            case RACING_TORTOISE_DEFENDING:
                func_803560CC_76777C();
                break;
            case SNEAKY_CHAMELEON:
                chameleon_unhide();
                break;
            case CRAZY_BEAR:
                crazy_bear_attack();
                break;
            case HARD_MOUSE:
                func_8031FAD8_731188();
                break;
            case CRAZY_HUSKY:
                func_8036BE70_77D520();
                break;
            case POLAR_BEAR_DEFENDING:
                func_80368B04_77A1B4();
                break;
            case DESERT_FOX_ATTACKING:
                func_80374518_785BC8();
                break;
            case KING_RAT:
                func_8035FC08_7712B8();
                break;
            case KING_PENGUIN:
                func_80365D74_777424();
                break;
            case PIRANA:
                func_80382CB0_794360();
                break;
            case EVO_SHELLSUIT:
                func_8038B774_79CE24();
                break;
            // why does this matter
            default:
                break;
            }
        }

        switch (D_803D5524->unk9C) {
        case BEAR:
            func_80327908_738FB8();
            break;
        case TORTOISE_TANK:
            func_80355918_766FC8();
            break;
        case GORILLA:
            func_8037B660_78CD10();
            break;
        }
    }

    if ((D_801D9ED8.unkFFDA != 0) ||
        (D_801D9ED8.curAButton != 0) ||
        (D_801D9ED8.curBButton != 0)) {
        D_803D552C->unk35E = D_803D5544;
    }
}

void func_802AB8EC_6BCF9C(u8 rotation, s8 arg1, s16 yOffset) {
    if (D_803D552C->unk360 != 0) {
        if (--D_803D552C->unk360 == 0) {
            func_802A467C_6B5D2C(D_803D552C->unk361);
        }
    }
    if (D_803D552C->isLaughing != 0) {
        arg1 = 0;
        yOffset = 0;
    }
    if ((arg1 != 0) && (arg1 != -1)) {
        D_803D552C->unk35E = D_803D5544;
    }

    if (D_803D5530->state < 7) {
        func_802B0B00_6C21B0(rotation, arg1);
    } else if (D_803D5530->state < 0x19) {
        func_802B0F4C_6C25FC(rotation, arg1);
    } else if (D_803D5530->state < 0x2B) {
        func_802B1210_6C28C0(rotation, arg1);
    } else if (D_803D5530->state < 0x40) {
        func_802B1374_6C2A24(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x52) {
        func_802B1654_6C2D04(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x6B) {
        func_802B1E28_6C34D8(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x7C) {
        func_802B1918_6C2FC8(rotation, arg1, yOffset);
    } else if (D_803D5530->state < 0x91) {
        func_802B1B98_6C3248(rotation, arg1);
    } else if (D_803D5530->state < 0xA3) {
        func_802B1D00_6C33B0(rotation, arg1);
    } else if (D_803D5530->state < 0xBA) {
        func_802B0D4C_6C23FC(rotation, arg1);
    } else if (D_803D5530->state < 0xCD) {
        func_802B10B0_6C2760(rotation, arg1);
    }
}

// ESA: func_8003F83C
void func_802ABB10_6BD1C0(u16 traction, s32 *arg1, s32 *arg2) {
    s32 xVel;
    s32 zVel;

    s32 xVelDelta; // uninitialised?
    s32 zVelDelta; // uninitialised?

    s32 temp_t0;
    s32 var_a2;
    s32 temp_a3;
    s32 temp_v1;

    s16 temp_a1;

    xVel = D_803D5530->xVelocity.w;
    zVel = D_803D5530->zVelocity.w;

    if (D_803D5530->unk161 == 1) {
        if (D_803D5530->unk68 != NULL) {
            if ((D_803D5530->unk68->unk16C->unk2 == 5) && (D_803D5530->unk68->unk16C->unkE6 >= D_803D5530->unk16C->unkE6)) {
                D_803D552C->previousHeading = D_803D552C->heading;
                temp_a1 = D_803D5530->unk68->heading - D_803D5530->unk68->previousHeading;
                D_803D552C->heading = (D_803D552C->heading + temp_a1) & 0xFF;
                D_803D5530->yRotation = (D_803D5530->yRotation + temp_a1) & 0xFF;
                if (temp_a1 != 0) {
                    temp_t0 = D_803D5530->position.xPos.w - D_803D5530->unk68->position.xPos.w;
                    temp_a3 = D_803D5530->position.zPos.w - D_803D5530->unk68->position.zPos.w;
                    D_803D5530->position.xPos.w = D_803D5530->unk68->position.xPos.w + ((temp_t0 >> 8) * (COS(temp_a1) >> 7)) + ((temp_a3 >> 8) * (SIN(temp_a1) >> 7));
                    D_803D5530->position.zPos.w = D_803D5530->unk68->position.zPos.w + ((temp_a3 >> 8) * (COS(temp_a1) >> 7)) - ((temp_t0 >> 8) * (SIN(temp_a1) >> 7));
                }
            }

            if (D_803D5530->unk68->unk16C->objectType == OBJECT_BOULDER) {
                xVelDelta = (*arg1 + (D_803D5530->unk68->xVelocity.w * 2)) - xVel;
                zVelDelta = (*arg2 + (D_803D5530->unk68->zVelocity.w * 2)) - zVel;
            } else {
                xVelDelta = (*arg1 + D_803D5530->unk68->xVelocity.w) - xVel;
                zVelDelta = (*arg2 + D_803D5530->unk68->zVelocity.w) - zVel;
            }
        }
#if AVOID_UB
        else {
            // uninitialised!!
            xVelDelta = *arg1 - xVel;
            zVelDelta = *arg2 - zVel;
        }
#endif
    } else {
        xVelDelta = *arg1 - xVel;
        zVelDelta = *arg2 - zVel;
    }

    if (D_803D5530->unk161 == 1) {
        var_a2 = traction * 60;
    } else if (D_803D5530->unk160 == 2) {
        var_a2 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk3].unk0 * traction;
    } else {
        var_a2 = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk2].unk0 * traction;
    }

    // tracked animals have more grip?
    if ((D_803D5524->unk9C == POLAR_TANK) || (D_803D5524->unk9C == TORTOISE_TANK)) {
        if (var_a2 == 0) {
            var_a2 = 90;
        } else if (var_a2 < 451) {
            var_a2 = 450;
        }
    }

    temp_v1 = func_802AC928_6BDFD8(xVelDelta, zVelDelta) >> 8;
    if (temp_v1 == 0) {
        *arg1 = xVel + xVelDelta;
        *arg2 = zVel + zVelDelta;
        return;
    }
    if (temp_v1 < var_a2) {
        *arg1 = xVel + xVelDelta;
        *arg2 = zVel + zVelDelta;
        return;
    }

    if (temp_v1 < (var_a2 * 5)) {
        xVelDelta = ((xVelDelta >> 8) * var_a2) / temp_v1;
        zVelDelta = ((zVelDelta >> 8) * var_a2) / temp_v1;

        *arg1 = xVel + (xVelDelta << 8);
        *arg2 = zVel + (zVelDelta << 8);

        if (((xVel * xVelDelta) > 0) || ((zVel * zVelDelta) > 0)) {
            kick_up_dust_small(xVel - ((SIN(D_803D552C->heading) >> 7) << 0xA), zVel - ((COS(D_803D552C->heading) >> 7) << 0xA));
        } else {
            kick_up_dust_small(0, 0);
        }
    } else {
        xVelDelta = ((xVelDelta >> 8) * var_a2) / temp_v1;
        zVelDelta = ((zVelDelta >> 8) * var_a2) / temp_v1;

        *arg1 = xVel + (xVelDelta << 8);
        *arg2 = zVel + (zVelDelta << 8);

        if (((xVel * xVelDelta) > 0) || ((zVel * zVelDelta) > 0)) {
            kick_up_dust_big(xVel - ((SIN(D_803D552C->heading) >> 7) << 0xA), zVel - ((COS(D_803D552C->heading) >> 7) << 0xA));
        } else {
            kick_up_dust_big(0, 0);
        }
    }
}

void func_802AC158_6BD808(u16 arg0, s32 *arg1, s32 *arg2) {
    s32 sp44;
    s32 sp40;
    s32 xVel;
    s32 zVel;

    s32 temp_lo;
    s32 phi_t0;
    s32 temp_v1_3;


    sp44 = D_803D5530->xVelocity.w;
    sp40 = D_803D5530->zVelocity.w;

    if ((D_803D5530->unk161 == 1) && (D_803D5530->unk68 != NULL)) {
        xVel = (*arg1 + D_803D5530->unk68->xVelocity.w) - sp44;
        zVel = (*arg2 + D_803D5530->unk68->zVelocity.w) - sp40;
    } else {
        xVel = *arg1 - sp44;
        zVel = *arg2 - sp40;
    }

    phi_t0 = arg0 * 4;
    if ((D_803D5544 - D_803D5530->unk48) < 5) {
        if ((D_803D5530->position.yPos.h - (func_8031124C_7228FC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h) >> 16)) < 32) {
            temp_lo = D_803E1D30[D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk2].unk0 * arg0;
            if (temp_lo >= phi_t0) {
                phi_t0 = temp_lo;
            }
        }
    }

    temp_v1_3 = func_802AC928_6BDFD8(xVel, zVel) >> 8;
    if (temp_v1_3 == 0) {
        *arg1 = sp44 + xVel;
        *arg2 = sp40 + zVel;
    } else if (temp_v1_3 < phi_t0) {
        *arg1 = sp44 + xVel;
        *arg2 = sp40 + zVel;
    } else if (temp_v1_3 < (phi_t0 * 5)) {
        xVel = ((xVel >> 8) * phi_t0) / temp_v1_3;
        zVel = ((zVel >> 8) * phi_t0) / temp_v1_3;
        *arg1 = sp44 + (xVel << 8);
        *arg2 = sp40 + (zVel << 8);
    } else {
        xVel = ((xVel >> 8) * phi_t0) / temp_v1_3;
        zVel = ((zVel >> 8) * phi_t0) / temp_v1_3;
        *arg1 = sp44 + (xVel << 8);
        *arg2 = sp40 + (zVel << 8);
    }
}

void func_802AC484_6BDB34(u16 arg0, s32 *arg1, s32 *arg2) {
    s32 xVel;
    s32 zVel;
    s32 xVelDiff;
    s32 zVelDiff;
    s32 temp_v1;
    s32 sp28;
    s32 pad2[2];

    xVel = D_803D5530->xVelocity.w;
    zVel = D_803D5530->zVelocity.w;
    sp28 = arg0;
    xVelDiff = *arg1 - xVel;
    zVelDiff = *arg2 - zVel;
    temp_v1 = func_802AC928_6BDFD8(xVelDiff, zVelDiff) >> 8;
    if ((temp_v1 != 0) && (temp_v1 >= arg0)) {
        xVelDiff = ((xVelDiff / 256) * sp28) / temp_v1;
        zVelDiff = ((zVelDiff / 256) * sp28) / temp_v1;
        *arg1 = (xVelDiff << 8) + xVel;
        *arg2 = (zVelDiff << 8) + zVel;
    }
}

void func_802AC5CC_6BDC7C(s32 *arg0, s32 *arg1) {
    if (D_803D5530->yRotation == 256) {
        *arg0 = 0;
        *arg1 = 0;
        return;
    }

    switch (D_803D5530->state) {
    case 0x2:
    case 0x15:
    case 0x29:
    case 0x3D:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x6A:
    case 0x79:
    case 0x7B:
    case 0x8D:
    case 0xA1:
    case 0xB5:
    case 0xB8:
    case 0xC9:
    case 0xDD:
        *arg0 = 0;
        *arg1 = 0;
        break;
    case 0x3:
    case 0x5:
    case 0x16:
    case 0x3E:
    case 0x7A:
    case 0xA2:
    case 0xB6:
    case 0xCA:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x6:
    case 0x18:
    case 0xCC:
        *arg0 = 0;
        *arg1 = -(D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x4:
    case 0x17:
    case 0x2A:
    case 0xB7:
    case 0xCB:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkA4 * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x68:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAC * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x69:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAC * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x51:
        *arg0 = 0;
        *arg1 = D_803D5524->unkAC << 0xA;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x8E:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x90:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    case 0x8F:
        *arg0 = 0;
        *arg1 = (D_803D5524->unkAA * D_803D552C->unk368) << 6;
        func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
        break;
    default:
        *arg0 = 0;
        *arg1 = 0;
        break;
    }
}

// ESA: func_80040260
void func_802AC8A0_6BDF50(s32 *arg0, s32 *arg1) {
    *arg0 = 0;

    if (D_801D9ED8.unkFFDA > 2) {
        *arg1 = (D_803D5524->unkA4 * 1024);
    } else if (D_801D9ED8.unkFFDA > 0) {
        *arg1 = (D_803D5524->unkA4 * 5) << 7;
    } else {
        *arg1 = 0;
    }

    func_802B90A0_6CA750(D_803D5530->yRotation, arg0, arg1);
}

s32 func_802AC928_6BDFD8(s32 arg0, s32 arg1) {
    arg0 = ABS(arg0);
    arg1 = ABS(arg1);

    if (arg1 >= arg0) {
        return arg1 + (arg0 / 2);
    } else {
        return arg0 + (arg1 / 2);
    }
}

void func_802AC980_6BE030(void) {
    switch (gCameras[gCameraId].cameraMode) {
    case 3:
    case 5:
    case 6:
    case 7:
    case 17:
    case 28:
        func_802AD0FC_6BE7AC();
        break;
    default:
        func_802AC9FC_6BE0AC();
        break;
    }
}

void func_802AC9FC_6BE0AC(void) {
    static s16 D_803D5574; // .bss
    s16 temp_v0;
    s16 var_v1_2;
    s16 var_a1;
    s16 var_a2;

    var_a1 = D_801D9ED8.stickX;
    var_a2 = D_801D9ED8.stickY;

    if (ABS(var_a1) <= 10) {
        var_a1 = 0;
    } else if (var_a1 > 0) {
        var_a1 -= 10;
    } else {
        var_a1 += 10;
    }

    if (ABS(var_a2) <= 10) {
        var_a2 = 0;
    } else if (var_a2 > 0) {
        var_a2 -= 10;
    } else {
        var_a2 += 10;
    }

    temp_v0 = sqrtf(SQ((f32)var_a1) + SQ((f32)var_a2));

    D_801D9ED8.unkFFDA = 0;
    if (temp_v0 >= 18) {
        D_801D9ED8.unkFFDA = 1;
    }
    if (temp_v0 >= 26) {
        D_801D9ED8.unkFFDA = 2;
    }
    if (temp_v0 >= 38) {
        D_801D9ED8.unkFFDA = 3;
    }
    if (temp_v0 >= 56) {
        D_801D9ED8.unkFFDA = 4;
    }

    if (temp_v0 == 0) {
        D_801D9ED8.unkFFA8 = 0x100;
    } else {
        if (ABS(var_a1) <= ABS(var_a2)) {
            if (var_a2 >= 0) {
                var_v1_2 = func_8012840C(((var_a1 << 7) / temp_v0) + 0x80);
            } else {
                var_v1_2 = 0x80 - func_8012840C(((var_a1 << 7) / temp_v0) + 0x80);
            }
        } else if (var_a1 >= 0) {
            var_v1_2 = 0x40 - func_8012840C(((var_a2 << 7) / temp_v0) + 0x80);
        } else {
            var_v1_2 = 0xC0 + func_8012840C(((var_a2 << 7) / temp_v0) + 0x80);
        }
        D_801D9ED8.unkFFA8 = (s16) (var_v1_2 & 0xFF);
    }
    D_803D5570 = ((s16) ((s32) (((D_803F2C3C + 90.0f) * 256.0f) / 360.0f))) & 0xFF;

    if (D_801D9ED8.unkFFA8 != 0x100) {
        if ((D_803D5574 == 0) || (gCameras[gCameraId].cameraMode == 0x1A)) {
            // nothing
        }
        if (gCameras[gCameraId].cameraMode != 0x1A) {
            D_801D9ED8.unkFFA8 = (D_801D9ED8.unkFFA8 + D_803D5570) & 0xFF;
        }
        if (gCameras[gCameraId].cameraMode == 0x1A) {
            D_801D9ED8.unkFFA8 = (s16) (s32) (D_801D9ED8.unkFFA8 + gCameras[gCameraId].unk20) & 0xFF;
        }
    }

    if (gCameras[gCameraId].cameraMode != 0x1A) {
        // whitespace seems to affect codegen
        if (D_801D9ED8.unkFFA8 != 0x100) {
            if (D_801D9ED8.unkFFA8 <= 0x40) { D_801D9ED8.unkFFA8 = (0x20 - ((COS(D_801D9ED8.unkFFA8 << 1) >> 7) >> 3));
            } else if (D_801D9ED8.unkFFA8 <= 0x80) { D_801D9ED8.unkFFA8 = (0x60 - ((COS((D_801D9ED8.unkFFA8 - 0x40) << 1) >> 7) >> 3));
            } else if (D_801D9ED8.unkFFA8 <= 0xC0) { D_801D9ED8.unkFFA8 = (0xA0 - ((COS((D_801D9ED8.unkFFA8 - 0x80) << 1) >> 7) >> 3));
            } else { D_801D9ED8.unkFFA8 = (0xE0 - ((COS((D_801D9ED8.unkFFA8 - 0xC0) << 1) >> 7) >> 3)) & 0xFF;
            }
        }
    }

    D_803D5574 = temp_v0;
    if (D_803F2C28 > 0) {
        D_803F2C28--;
        D_803D5574 = 0;
        D_801D9ED8.unkFFDA = 0;
        D_801D9ED8.unkFFA8 = 0x100;
    }

    if (D_801D9ED8.unkFFA8 != 0x100) {
        if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 != 0) {
            D_801D9ED8.unkFFA8 = (D_801D9ED8.unkFFA8 + (((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 >> 2) * (SIN(D_803D5540 << 2) >> 7)) >> 0xA)) & 0xFF;
        }
    }
    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->isLaughing != 0) {
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_801D9ED8.unkFFA8 = (D_801D9ED8.unkFFA8 + ((SIN(D_803D5540 << 3) >> 7) / 6)) & 0xFF;
        }
    }
    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A != 0) {
        D_801D9ED8.unkFFA8 = 0x100;
        D_801D9ED8.unkFFDA = 0;
    }
}

void func_802AD0FC_6BE7AC(void) {
    static s16 D_803D5576; // .bss

    s16 temp_a3;

    s16 var_a1;
    s16 var_v1;

    var_a1 = D_801D9ED8.stickX;
    var_v1 = D_801D9ED8.stickY;

    if (ABS(var_a1) <= 10) {
        var_a1 = 0;
        D_803D5576 = MAX(D_803D5576 - 2, 0);
    } else {
        D_803D5576 = MIN(D_803D5576 + 1, 14);
        if (var_a1 > 0) {
            var_a1 = var_a1 - 10;
        } else {
            var_a1 = var_a1 + 10;
        }
    }

    if (ABS(var_v1) <= 10) {
        var_v1 = 0;
    } else if (var_v1 > 0) {
        var_v1 = var_v1 - 10;
    } else {
        var_v1 = var_v1 + 10;
    }

    if (D_803D5524->unk9C == WALRUS) {
        D_803D5548 += (var_a1 * D_803D5576) / 21;
    } else {
        D_803D5548 += (var_a1 * D_803D5576) / 14;
    }

    // modulo
    temp_a3 = D_803D5548 >> 4;
    D_803D5548 = D_803D5548 - (temp_a3 << 4);

    if (D_801D9ED8.unkFFA8 == 0x100) {
        D_801D9ED8.unkFFA8 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation;
    }
    D_801D9ED8.unkFFA8 += temp_a3;

    if (D_801D9ED8.unkFFA8 < 0) {
        D_801D9ED8.unkFFA8 += 256;
    }
    if (D_801D9ED8.unkFFA8 >= 0x100) {
        D_801D9ED8.unkFFA8 -= 256;
    }

    D_801D9ED8.unkFFDA = 0;
    if (var_v1 >= 18) {
        D_801D9ED8.unkFFDA = 1;
    }
    if (var_v1 >= 26) {
        D_801D9ED8.unkFFDA = 2;
    }
    if (var_v1 >= 38) {
        D_801D9ED8.unkFFDA = 3;
    }
    if (var_v1 >= 56) {
        D_801D9ED8.unkFFDA = 4;
    }
    if (var_v1 <= -18) {
        D_801D9ED8.unkFFDA = -1;
    }
    if (var_v1 <= -26) {
        D_801D9ED8.unkFFDA = -2;
    }
    if (var_v1 <= -38) {
        D_801D9ED8.unkFFDA = -3;
    }
    if (var_v1 <= -56) {
        D_801D9ED8.unkFFDA = -4;
    }

    if (D_803F2C28 > 0) {
        D_803F2C28--;
        D_801D9ED8.unkFFDA = 0;
        D_801D9ED8.unkFFA8 = 0x100;
    }

    if ((D_801D9ED8.unkFFA8 != 0x100) && (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 != 0)) {
        D_803D5548 = D_803D5548 + ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk348 * (SIN(D_803D5540 << 2) >> 7)) >> 0xD);
    }
    if ((D_801D9ED8.animals[gCurrentAnimalIndex].animal->isLaughing != 0) && (D_801D9ED8.unkFFA8 != 0x100)) {
        D_801D9ED8.unkFFA8 = (D_801D9ED8.unkFFA8 + (D_803D5540 * 2)) & 0xFF;
    }
    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A != 0) {
        D_801D9ED8.unkFFA8 = 0x100;
        D_801D9ED8.unkFFDA = 0;
    }
}

void func_802AD49C_6BEB4C(void) {
    static s16 D_803D5578; // .bss

    s16 temp_t9;

    s16 phi_v0;
    s16 phi_v1;


    phi_v0 = D_801D9ED8.stickX;
    phi_v1 = D_801D9ED8.stickY;

    if (D_803F2D30.unk4 != 0) {
        phi_v0 = phi_v1 = 0;
    }

    if (ABS(phi_v0) <= 10) {
        phi_v0 = 0;
        D_803D5578 = MAX(D_803D5578 - 2, 0);
    } else {
        D_803D5578 = MIN(D_803D5578 + 1, 14);
        if (phi_v0 > 0) {
            phi_v0 -= 10;
        } else {
            phi_v0 += 10;
        }
    }

    if (ABS(phi_v1) <= 10) {
        // nothing
    }

    D_803D5548 += (phi_v0 * D_803D5578) / 28;

    temp_t9 = D_803D5548 >> 4;
    D_803D5548 = D_803D5548 - (temp_t9 << 4);
    D_801D9ED8.unkFFA8 += temp_t9;

    if (D_801D9ED8.unkFFA8 < 0) {
        D_801D9ED8.unkFFA8 += 256;
    }
    if (D_801D9ED8.unkFFA8 >= 256) {
        D_801D9ED8.unkFFA8 -= 256;
    }

    if ((gControllerInput != NULL) && (gControllerInput->button & A_BUTTON)) {
        D_801D9ED8.unkFFDA = 4;
    } else {
        D_801D9ED8.unkFFDA = 0;
    }
}

void func_802AD63C_6BECEC(void) {
    static s16 D_803D557A; // .bss

    D_801D9ED8.unkFFDC = 0;
    if (D_801D9ED8.stickX < -17) {
        D_801D9ED8.unkFFDC = (D_801D9ED8.stickX << 6) / 55;
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFDC * D_803D557A) / 14;
        if (D_801D9ED8.unkFFDC < -64) {
            D_801D9ED8.unkFFDC = -64;
        }
        D_803D557A = MIN(D_803D557A + 1, 14);
    } else if (D_801D9ED8.stickX > 17) {
        D_801D9ED8.unkFFDC = (D_801D9ED8.stickX << 6) / 55;
        D_801D9ED8.unkFFDC = (D_801D9ED8.unkFFDC * D_803D557A) / 14;
        if (D_801D9ED8.unkFFDC > 64) {
            D_801D9ED8.unkFFDC = 64;
        }
        D_803D557A = MIN(D_803D557A + 1, 14);
    } else {
        D_803D557A = MAX(D_803D557A - 2, 0);
    }

    D_801D9ED8.unkFFDE = 0;
    if (D_801D9ED8.stickY < -17) {
        D_801D9ED8.unkFFDE = (-17 - D_801D9ED8.stickY) >> 1;
    } else if (D_801D9ED8.stickY > 17) {
        D_801D9ED8.unkFFDE = (17 - D_801D9ED8.stickY) >> 1;
    }
    if (D_801D9ED8.animals[gCurrentAnimalIndex].animal->state == 0xDD) {
        D_803D5570 = gCameras[gCameraId].unk20;
    }
    D_801D9ED8.unkFFA8 = ((D_801D9ED8.unkFFA8 + D_803D5570) & 0xFF);
}

void func_802AD87C_6BEF2C(void) {
    u16 sp1E;

    sp1E = D_803D5530->yRotation;
    if ((D_803D5524->unk9C == EVO_SHELLSUIT) && (D_803D552C->unk30C > 20)) {
        D_801D9ED8.unkFFDA = 0;
        D_801D9ED8.unkFFA8 = 0x100;
    }
    if (D_801D9ED8.prevAButton == 0) {
        D_803D5572 = D_803D5544;
    }
    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        switch (D_803D5530->state) {
        case 1:
        case 2:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;

            if (D_801D9ED8.unkFFDA > 0) {
                func_802A43E4_6B5A94(D_801D9ED8.unkFFA8, 10);
            }
            if (D_801D9ED8.unkFFDA < 0) {
                func_802A44C4_6B5B74(D_801D9ED8.unkFFA8, 10);
            } else {
                if (D_801D9ED8.unkFFA8 != 0x100) {
                    D_803D5530->yRotation = D_801D9ED8.unkFFA8;
                }
            }
            break;
        case 3:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;

            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4390_6B5A40();
            } else if (D_801D9ED8.unkFFDA > 3) {
                func_802A459C_6B5C4C(D_801D9ED8.unkFFA8, 16);
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 4:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 2;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4390_6B5A40();
            } else
            if (D_801D9ED8.unkFFDA < 3) {
                func_802A43E4_6B5A94(sp1E, 10);
            }
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 6:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A4390_6B5A40();
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 3:
        if ((D_801D9ED8.unkFFA8 != sp1E) && (D_801D9ED8.unkFFA8 != 0x100)) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
    if ((D_801D9ED8.curAButton != 0) && ((D_803D5544 - D_803D5572) < 8) && (D_803D5524->canJump & 1) && (D_803D552C->unk367 <= 0) && (D_803D555C != 0) && ((D_803D5544 - D_803D555A) < 4)) {
        D_803D555C = 0;
        switch (D_803D555D) {
        default:
        case 0:
            func_802A6390_6B7A40();
            break;
        case 1:
            func_802A6390_6B7A40();
            break;
        case 2:
            func_802A63C0_6B7A70();
            break;
        }
    }
}

void func_802ADDD0_6BF480(void) {
    u16 rotation = D_803D5530->yRotation;

    switch (D_803D5530->unk162 & 0xF) {
    case 6:
        switch (D_803D5530->state) {
        case 0x1:
        case 0xB5:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA > 0) {
                func_802A4EC8_6B6578(D_801D9ED8.unkFFA8, 10);
            } else if (D_801D9ED8.unkFFDA < 0) {
                func_802A4F68_6B6618(D_801D9ED8.unkFFA8, 10);
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xB6:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 1;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4E74_6B6524();
            } else {
                if (D_801D9ED8.unkFFA8 != 256) {
                    D_803D5530->yRotation = D_801D9ED8.unkFFA8;
                } else
                if (D_801D9ED8.unkFFDA >= 3) {
                    func_802A5008_6B66B8(D_801D9ED8.unkFFA8, 16);
                }
            }
            break;
        case 0xB7:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 2;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4E74_6B6524();
            } else if (D_801D9ED8.unkFFDA < 3) {
                func_802A4EC8_6B6578(rotation, 10);
            }
            if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xB9:
            D_803D555A = D_803D5544;
            D_803D555C = 1;
            D_803D555D = 0;
            D_803D5560 = D_803D5530->unk6C;
            D_803D5566 = D_803D5564;
            D_803D556A = D_803D5568;
            D_803D556E = D_803D556C;
            D_803D5564 = D_803D5530->position.xPos.h;
            D_803D5568 = D_803D5530->position.zPos.h;
            D_803D556C = D_803D5530->unk160;
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A4E74_6B6524();
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        }
        break;
    case 7:
        if (D_801D9ED8.unkFFA8 != 256) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
    if ((D_801D9ED8.curAButton != 0) && (D_803D5524->canJump & 1) &&
        (D_803D552C->unk367 <= 0) && (D_803D555C != 0) &&
        ((D_803D5544 - D_803D555A) < 4)) {
        D_803D555C = 0;
        switch (D_803D555D) {
        default:
        case 0:
            func_802A6390_6B7A40();
            break;
        case 1:
            func_802A6390_6B7A40();
            break;
        case 2:
            func_802A6390_6B7A40();
            break;
        }
    }
}

void func_802AE278_6BF928(void) {
    D_803D555A = D_803D5544;

    switch (D_803D5530->unk162 & 0xF) {
    case 1:
        switch (D_803D5530->state) {
        case 21:
            if (D_801D9ED8.unkFFDA > 0) {
                func_802A4D0C_6B63BC(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFDA < 0) {
                func_802A4D80_6B6430(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 22:
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFDA >= 3) {
                func_802A4DF4_6B64A4(D_801D9ED8.unkFFA8, 0x10);
            }
            break;
        case 23:
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFDA < 3) {
                func_802A4D0C_6B63BC(D_801D9ED8.unkFFA8, 0xA);
            }
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 24:
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A4CB8_6B6368();
            } else if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 3:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

void func_802AE488_6BFB38(void) {
    D_803D555A = D_803D5544;

    switch (D_803D5530->unk162 & 0xF) {
    case 6:
        switch (D_803D5530->state) {
        case 0xC9:
            if (D_801D9ED8.unkFFDA > 0) {
                func_802A55AC_6B6C5C(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFDA < 0) {
                func_802A5620_6B6CD0(D_801D9ED8.unkFFA8, 0xA);
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xCA:
            if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFDA >= 3) {
                func_802A5694_6B6D44(D_801D9ED8.unkFFA8, 0x10);
            }
            break;
        case 0xCB:
            if (D_801D9ED8.unkFFDA <= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFDA < 3) {
                func_802A55AC_6B6C5C(D_801D9ED8.unkFFA8, 0xA);
            }
            if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
            break;
        case 0xCC:
            if (D_801D9ED8.unkFFDA >= 0) {
                func_802A5558_6B6C08();
            } else if (D_801D9ED8.unkFFA8 != 256) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 7:
        if (D_801D9ED8.unkFFA8 != 256) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

void func_802AE698_6BFD48(void) {
    s16 temp_a1;
    s16 temp_v0;
    s16 temp_v1;
    s16 distance_from_ground;
    s32 var_a3;

    static s16 D_803D557C; // .bss

    if (D_803D5530->state == 0x51) {
        D_803D557C = D_803D557C + ((D_801D9ED8.unkFFDC * 4) / 3);
        temp_v1 = D_803D557C / 32;

        D_803D557C = D_803D557C - (temp_v1 << 5);

        D_803D5530->yRotation += temp_v1;
        D_803D5530->yRotation &= 0xFF;

        D_803D552C->unk306 = D_801D9ED8.unkFFDC / 16;

        temp_a1 = D_801D9ED8.unkFFDE - D_803D5530->unk28;
        if (temp_a1 > 0) {
            D_803D5530->unk28 += MIN(temp_a1, 10);
        } else {
            D_803D5530->unk28 += MAX(temp_a1, -10);
        }

        var_a3 = D_803D5530->unk28 << 0xF;

        distance_from_ground = get_distance_from_ground();

        if ((distance_from_ground > 0xA80) && (var_a3 >= -0x10000)) {
            var_a3 = -0x10000;
        }

        if (distance_from_ground > 0xA00) {
            if (var_a3 >= ((0xA00 - distance_from_ground) << 9)) {
                var_a3 = ((0xA00 - distance_from_ground) << 9);
            }
        } else {
            if ((distance_from_ground > 0x980) && (var_a3 >= (var_a3 >> 1))) {
                var_a3 = (var_a3 >> 1);
            }
        }

        if (D_803D5530->yVelocity.h >= 0x15) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -0x14) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h >= 0x11) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -0x10) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h >= 0xD) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -0xC) {
            D_803D5530->yVelocity.h += 1;
        }

        if ((var_a3 - D_803D5530->yVelocity.w) > 0) {
            D_803D5530->yVelocity.w += MIN(0xC000, (var_a3 - D_803D5530->yVelocity.w));
        } else {
            D_803D5530->yVelocity.w += MAX(-0xC000, (var_a3 - D_803D5530->yVelocity.w));
        }

        if (D_803D552C->unk365 == ATTACK_FOX_4) {
            if ((distance_from_ground < 2528) || (D_803D5530->yVelocity.h < -8)) {
                D_803D552C->unk365 = ATTACK_NONE;
            }
            D_803D5530->yVelocity.h -= 2;
        } else if ((distance_from_ground > 2550) && (D_803D5530->yVelocity.w > 0)) {
            D_803D552C->unk32A = D_803D5544;
            D_803D552C->unk365 = ATTACK_FOX_4;
        }
    }
}

void func_802AE9C4_6C0074(void) {
    D_803D552C->unk30E = 0;
    if ((D_803D5530->unk162 & 0xF) == 1) {
        if (D_803D552C->unk30C > 0) {
            D_803D552C->unk30C--;
        }
    }

    switch (D_803D5530->state) {
    case 1:
    case 41:
        D_803D555A = D_803D5544;
        D_803D5560 = D_803D5530->unk6C;

        if ((D_801D9ED8.unkFFA8 != 256) && (D_801D9ED8.curAButton != 0) && (D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            func_802A5778_6B6E28(MAX(0, D_801D9ED8.unkFFDA), 0);
            D_803D552C->unk30A += 32;
            D_803D5530->unk162 = 3;
        } else if ((D_801D9ED8.unkFFA8 == 256) && (D_801D9ED8.curAButton != 0) && (D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            func_802A5778_6B6E28(0, 0);
            D_803D5530->unk162 = 3;
        } else if (D_801D9ED8.unkFFA8 != 256) {
            D_803D552C->unk30E = MAX(0, D_801D9ED8.unkFFDA);
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        } else {
            D_803D552C->unk30E = 0;
        }
        break;
    case 42:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
}

void func_802AEBB0_6C0260(void) {
    s32 airHeight;

    if (D_803D552C->unk30E >= 5) {
        D_803D552C->unk30E--;
    }
    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }

    switch (D_803D5530->state) {
    case 0x1:
    case 0x79:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        if (D_801D9ED8.curAButton != 0) {
            func_802A5CF4_6B73A4();
        }
        break;
    case 0x7A:
    case 0x7B:
        if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            D_803D5530->state = 0x7A;
            D_803D552C->unk368 = (D_801D9ED8.unkFFDA * 0x10) >> 2;
        } else {
            D_803D5530->state = 0x7BU;
            D_803D552C->unk368 = 0;
        }
        if (D_801D9ED8.curAButton != 0) {
            airHeight = get_distance_from_ground();
            if (airHeight < 256) {
                D_803D5530->yVelocity.w += gGravity >> 3;
            } else if (airHeight < 384) {
                if (D_803D5530->yVelocity.w > FTOFIX32(-1.5)) {
                    D_803D5530->yVelocity.w -= gGravity >> 5;
                }
            } else {
                // cap height
                D_803D5530->yVelocity.w -= gGravity >> 3;
            }
            D_803D552C->unk30E = MIN(100, D_803D552C->unk30E + 4);
        } else {
            D_803D5530->yVelocity.w -= gGravity >> 3;
        }
        break;
    }
    D_803D552C->unk30C = (D_803D552C->unk30C + (D_803D552C->unk30E >> 2)) % 255;
}

void func_802AEE18_6C04C8(void) {
    switch (D_803D5530->state) {
    case 0x3E:
        D_803D5530->yRotation += (D_801D9ED8.unkFFDC >> 3);
        D_803D5530->yRotation &= 0xFF;

        D_803D5530->unk28 = D_801D9ED8.unkFFDE;

        D_803D5530->yVelocity.w =  ((D_803D5530->yVelocity.w * 7) >> 3) + ((D_803D5530->unk28 * 5) << 8);
        D_803D5530->yVelocity.w += (SIN(D_803D5540 << 2) >> 7) << 6;

        if ((D_801D9ED8.unkFFDC != 0) || (D_803D552C->unk30C != 0)) {
            D_803D552C->unk30E = MIN(16, D_803D552C->unk30E + 1);
        } else {
            D_803D552C->unk30E = MAX(0, D_803D552C->unk30E - 2);
        }

        if (D_801D9ED8.unkFFDC != 0) {
            if (D_803D552C->unk30C == 0) {
                if (D_801D9ED8.unkFFDC < 0) {
                    if ((D_803D552C->unk310 <= 0x300) && (D_803D552C->unk310 >= 0x2EA)) {
                        D_803D552C->unk310 = 0x300;
                    } else {
                        D_803D552C->unk310 = (D_803D552C->unk310 + 20) & 0x3FF;
                    }
                } else {
                    if ((D_803D552C->unk310 <= 0x100) && (D_803D552C->unk310 >= 0xEB)) {
                        D_803D552C->unk310 = 0x100;
                    } else {
                        D_803D552C->unk310 = (D_803D552C->unk310 + 20) & 0x3FF;
                    }
                }
            }
        }

        if (D_801D9ED8.curAButton != 0) {
            if (D_801D9ED8.prevAButton == 0) {
                D_803D552C->unk30C += 64;
            } else {
                D_803D552C->unk30C = MAX(64, D_803D552C->unk30C);
            }
        }
        if (D_803D552C->unk30C < 50) {
            D_803D552C->unk30C = MAX(0, D_803D552C->unk30C - 6);
        } else {
            D_803D552C->unk30C = (D_803D552C->unk30C * 7) >> 3;
        }

        D_803D5530->xVelocity.w += (D_803D552C->unk30C * SIN(D_803D552C->heading)) / 110;
        D_803D5530->zVelocity.w += (D_803D552C->unk30C * COS(D_803D552C->heading)) / 110;
        if ((D_803D552C->unk365 == ATTACK_NONE) && (D_801D9ED8.curBButton != 0) && (D_801D9ED8.prevBButton == 0)) {
            if ((D_803D5530->position.yPos.h - func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h)) >= -0x3F) {
                D_803D552C->unk369 = 0;
                D_803D5530->position.yPos.h += 23;
                D_803D5530->yVelocity.h += 23;
                D_803D5530->xVelocity.w += SIN(D_803D552C->heading) * 6;
                D_803D5530->zVelocity.w += COS(D_803D552C->heading) * 6;
                D_803D552C->unk308 = 0;
                D_803D5530->state = 0x3FU;
                D_803D5530->unk162 = 3;
                play_sound_effect_at_location(SFX_UNKNOWN_42, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            } else if (D_803D5524->unk9C != PIRANA) {
                func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
            }
        }
        break;
    case 0x1:
    case 0x3D:
    case 0x3F:
        break;
    }
}

void func_802AF308_6C09B8(void) {
    u16 rotation = D_803D5530->yRotation;

    switch (D_803D5530->state) {
    default:
        break;
    case 0x1:
    case 0x8D:
        if (D_801D9ED8.unkFFDA > 0) {
            if ((D_803D5524->unk9C != VULTURE) && (D_803D5524->unk9C != SEAGULL2)) {
                func_802A5EF8_6B75A8(D_801D9ED8.unkFFA8, 0xA);
            }
        } else if (D_801D9ED8.unkFFDA < 0) {
            if ((D_803D5524->unk9C != VULTURE) && (D_803D5524->unk9C != SEAGULL2)) {
                func_802A5F9C_6B764C(D_801D9ED8.unkFFA8, 0xA);
            }
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 0x8E:
        if (D_801D9ED8.unkFFDA <= 0) {
            func_802A5EA4_6B7554();
        } else if (D_801D9ED8.unkFFDA >= 3) {
            func_802A6044_6B76F4(D_801D9ED8.unkFFA8, 0x10);
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    case 0x8F:
        if (D_801D9ED8.unkFFA8 == rotation) {
            if (D_801D9ED8.unkFFDA < 3) {
                func_802A5EF8_6B75A8(rotation, 0xA);
            }
        } else if (D_801D9ED8.unkFFA8 == 0x100) {
            func_802A5EA4_6B7554();
        } else {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    case 0x90:
        if (D_801D9ED8.unkFFDA >= 0) {
            func_802A5EA4_6B7554();
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        }
        break;
    }
    if ((D_803D5524->unk9C == FROG) && (D_801D9ED8.curAButton != 0)) {
        if ((D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {

            if ((D_803D5530->position.yPos.h - (MAX(MAX(D_803C0740[(D_803D5530->position.xPos.h >> 6) + 0][(D_803D5530->position.zPos.h >> 6) + 0].unk6, D_803C0740[(D_803D5530->position.xPos.h >> 6) + 1][(D_803D5530->position.zPos.h >> 6) + 0].unk6), MAX(D_803C0740[(D_803D5530->position.xPos.h >> 6) + 0][(D_803D5530->position.zPos.h >> 6) + 1].unk6, D_803C0740[(D_803D5530->position.xPos.h >> 6) + 1][(D_803D5530->position.zPos.h >> 6) + 1].unk6)) * 4)) > -40) {
                func_802A5778_6B6E28(MAX(0, D_801D9ED8.unkFFDA), 1);
                D_803D552C->unk30A += 32;
                D_803D5530->unk162 = 3;
                D_803D5530->position.yPos.h = MIN(D_803D5530->position.yPos.h, ((MAX(MAX(D_803C0740[(D_803D5530->position.xPos.h >> 6) + 0][(D_803D5530->position.zPos.h >> 6) + 0].unk6, D_803C0740[(D_803D5530->position.xPos.h >> 6) + 1][(D_803D5530->position.zPos.h >> 6) + 0].unk6), MAX(D_803C0740[(D_803D5530->position.xPos.h >> 6) + 0][(D_803D5530->position.zPos.h >> 6) + 1].unk6, D_803C0740[(D_803D5530->position.xPos.h >> 6) + 1][(D_803D5530->position.zPos.h >> 6) + 1].unk6)) * 4) - D_803D5524->unkB8 + 12));
            }
        }
    }

    if (D_803D552C->unk30C > 0) {
        D_803D552C->unk30C--;
    }
}

void func_802AF7E4_6C0E94(void) {
    if ((D_803D5540 & 1) == 0) {
        if ((D_803D5530->unk4A == 0) && (D_803D5530->unk4C.unk1A == 0)) {
            D_803D5530->health--;
            D_803D5530->health = D_803D5530->health;
            D_803D552C->lastHpLost++;
        }
    }
    switch (D_803D5530->state) {
    case 0x1:
    case 0xA1:
        if (D_803D552C->unk308 > 0) {
            D_803D552C->unk308--;
        } else {
            // huh?
            if ((D_801D9ED8.unkFFA8 != 0x100) && (D_801D9ED8.unkFFA8 != 0x100)) {
                func_802A5E1C_6B74CC(D_801D9ED8.unkFFA8);
            }
        }
        break;
    case 0xA2:
        if (D_801D9ED8.unkFFA8 == 0x100) {
            func_802A5E64_6B7514();
        } else if (D_801D9ED8.unkFFA8 != 0x100) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        break;
    }
    D_803D552C->unk30E = (func_8012826C() & 0x1F) - 0xF;
    if ((D_801D9ED8.curAButton != 0) && (D_801D9ED8.prevAButton == 0)) {
        if ((ABS(D_803D5530->xVelocity.h) + ABS(D_803D5530->zVelocity.h)) < 12) {
            D_803D5530->xVelocity.w += SIN(D_803D552C->heading) * 3;
            D_803D5530->zVelocity.w += COS(D_803D552C->heading) * 3;
        }
    }
}

void func_802AF9FC_6C10AC(void) {
    s32 pad1;
    s32 pad2;
    u16 sp4E;
    s16 sp4C;
    s16 pad;
    s16 tmp;
    s16 yVel;
    s16 xVel;
    s16 zVel;

    D_803D552C->unk30E++;

    if (D_801D9ED8.prevAButton == 0) {
        D_803D5572 = D_803D5544;
    }

    sp4E = D_803D5530->yRotation;   // angle?
    sp4C = D_803D5524->unkC2;       // lift?

    if ((D_803D5540 % 3) != 2) {
        D_803D5558 += -1;
    }

    D_803D5558 = MAX(D_803D5530->position.yPos.h - 64, D_803D5558);

    switch (D_803D5524->unk9C) {
    case SEAGULL:
    case VULTURE2:
        yVel = 384;
        break;
    case VULTURE:
    case SEAGULL2:
        yVel = 288;
        break;
    case PARROT:
        yVel = 640;
        break;
    default:
        yVel = 0;
        break;
    }

    func_80311A2C_7230DC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &xVel, &zVel, D_803D5530->unk160);

    if ((D_803D5530->unk68 != 0) || ((ABS(xVel) < 0x22) && (ABS(zVel) < 0x22))) {
        if (D_803D5530->unk162 == 1) {
            D_803D552C->unk30E = 0;
            D_803D5558 = MAX(D_803D5558, D_803D5530->position.yPos.h + yVel);
        } else {
            D_803D5558 = MAX(D_803D5558, func_802B25B4_6C3C64(1) + yVel);
        }
    }

    switch (D_803D5530->state) {
    case 101:
        if ((D_801D9ED8.curAButton != 0) && (((D_803D5544 - D_803D5572) < 8) || (D_803D5530->unk162 != 1))) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        } else {
            if (D_801D9ED8.unkFFA8 != 0x100) {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }

            if ((D_801D9ED8.unkFFA8 != 0x100) && (D_803D5530->unk162 == 1) && (D_801D9ED8.unkFFDA > 0)) {
                if ((D_803D5530->xVelocity.w == 0) && (D_803D5530->zVelocity.w == 0)) {
                    D_803D5530->xVelocity.w += SIN(D_801D9ED8.unkFFA8) << 3;
                    D_803D5530->zVelocity.w += COS(D_801D9ED8.unkFFA8) << 3;
                    D_803D5530->yVelocity.w = FTOFIX32(10.0);
                    play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    D_803D5530->unk162 = 3;
                    D_803D552C->unk367 = 27;
                }
            }
        }

        if ((D_803D5530->unk162 == 3) && (D_803D552C->unk367 == 0) && (D_803D5530->yVelocity.h < -0xA)) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
            D_803D553A = 4;
            D_803D552C->unk30C = sp4C;
            D_803D5530->unk162 = 2;
            func_802B8AD8_6CA188();
            if ((D_803D5524->unk9C == VULTURE2) || (D_803D5524->unk9C == SEAGULL)) {
                D_803D5528->unk3C0.unk4 = 13;
            } else if ((D_803D5524->unk9C == VULTURE) || (D_803D5524->unk9C == SEAGULL2)) {
                D_803D5528->unk3C0.unk4 = 14;
            }
        }
        break;
    case 102:
        if (D_803D552C->unk365 == ATTACK_NONE) {
            func_802A60C4_6B7774();
        }
        break;
    case 103:
        if (D_801D9ED8.unkFFA8 != 256) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        }
        if (D_801D9ED8.unkFFDA > 0) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        }
        break;
    case 104:
        if (D_801D9ED8.unkFFDA == 0) {
            func_802A6100_6B77B0();
        } else if (D_801D9ED8.unkFFA8 != sp4E) {
            D_803D5530->yRotation = D_801D9ED8.unkFFA8;
        } else if (D_801D9ED8.unkFFDA >= 3) {
            func_802A6198_6B7848(D_801D9ED8.unkFFA8);
        }
        break;
    case 105:
        if (D_801D9ED8.unkFFA8 != sp4E) {
            if (D_801D9ED8.unkFFA8 == 0x100) {
                func_802A6100_6B77B0();
            } else {
                D_803D5530->yRotation = D_801D9ED8.unkFFA8;
            }
        } else if (D_801D9ED8.unkFFDA < 3) {
            func_802A613C_6B77EC(D_801D9ED8.unkFFA8);
        }
        break;
    case 106:
        if ((gGravity * -16) < D_803D5530->yVelocity.w) {
            D_803D5530->yVelocity.w -= gGravity + (gGravity >> 1);
        }
        break;
    default:
        break; // required
    }

    if (((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) && (D_803D5530->state != 0x6A)) {
        D_803D5530->yVelocity.w = ((D_803D5530->yVelocity.w * 7) >> 3);
    }

    D_803D5530->yVelocity.w -= (gGravity >> 2);

    if ((D_803D5524->unk9C == VULTURE2) ||
        (D_803D5524->unk9C == VULTURE) ||
        (D_803D5524->unk9C == SEAGULL) ||
        (D_803D5524->unk9C == SEAGULL2)) {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += gGravity >> 2;
        }
    } else {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-5.0)) {
            D_803D5530->yVelocity.w += gGravity >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-7.0)) {
            D_803D5530->yVelocity.w += gGravity >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-8.0)) {
            D_803D5530->yVelocity.w += gGravity >> 3;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += gGravity >> 2;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += gGravity >> 1;
        }
    }
    if (D_803D552C->unk30C > 0) {
        if ((((sp4C * 0xA) >> 4) < D_803D552C->unk30C) && (sp4C >= D_803D552C->unk30C)) {
            D_803D5530->xVelocity.w += SIN(D_803D552C->heading) * 3;
            D_803D5530->zVelocity.w += COS(D_803D552C->heading) * 3;

            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == VULTURE) ||
                (D_803D5524->unk9C == SEAGULL) ||
                (D_803D5524->unk9C == SEAGULL2)) {
                if ((D_803D5530->yVelocity.w < FTOFIX32(-2.0)) && (D_803D5530->position.yPos.h < (D_803D5558 - 192))) {
                    D_803D5530->yVelocity.w += FTOFIX32(2.0);
                } else if ((D_803D5530->yVelocity.w < FTOFIX32(4.0)) && (D_803D5530->position.yPos.h < (D_803D5558 - 192))) {
                    D_803D5530->yVelocity.w += FTOFIX32(1.5625);
                } else if (D_803D5530->yVelocity.w < FTOFIX32(2.0)) {
                    // distance to ground?
                    if (D_803D5558 < D_803D5530->position.yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.75);
                    } else if ((D_803D5558 - 64) < D_803D5530->position.yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(1.0625);
                    } else if ((D_803D5558 - 128) < D_803D5530->position.yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(1.375);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(1.5625);
                    }
                }
            } else {
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (D_803D5558 < D_803D5530->position.yPos.h) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.5);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(1.75);
                    }
                }
            }
        }
        D_803D552C->unk30C--;
        if ((D_803D552C->unk30C == (sp4C >> 1)) && ((D_803D5524->unk9C == VULTURE) || (D_803D5524->unk9C == SEAGULL2))) {
            D_803D553A = 4;
        }
    } else {
        tmp = 0;
        if (D_803D5524->unk9C == PARROT) {
            if ((D_801D9ED8.curAButton != 0) && (D_803D5530->state != 0x6A) && ((D_803D5544 - D_803D5572) < 8)) {
                tmp = 1;
            }
        } else if (D_801D9ED8.curAButton != 0) {
            tmp = 1;
        }
        if (tmp) {
            D_803D553A = 4;
            D_803D5530->yVelocity.w += (4 << (20 / sp4C));
            D_803D552C->unk30C = sp4C;
            D_803D5530->unk162 = 2;
            func_802B8AD8_6CA188();
            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == SEAGULL)) {
                D_803D5528->unk3C0.unk4 = 13;
            } else if ((D_803D5524->unk9C == VULTURE) ||
                       (D_803D5524->unk9C == SEAGULL2)) {
                D_803D5528->unk3C0.unk4 = 14;
            }
        }
    }
}

// ESA: func_80043E8C
void func_802B066C_6C1D1C(void) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 var_a0;
    s32 a2;
    s32 a3;

    sp36 = D_803D552C->unk308;

    if (D_801D9ED8.unkFFDE < 0) {
        var_a0 = -(-D_801D9ED8.unkFFDE >> 3);
    } else {
        var_a0 =   D_801D9ED8.unkFFDE >> 3;
    }

    if (D_803E00C0[sp36].unk35 == 0) {
        D_803D552C->unk30A += var_a0;
    }

    if (D_803D552C->unk30A < 56) {
        D_803D552C->unk30A = 58;
    }

    if (D_803D552C->unk30A > ((D_803E00C0[sp36].numSegments - 1) << 4)) {
        D_803D552C->unk30A = ((D_803E00C0[sp36].numSegments - 1) << 4);
    }

    sp34 = D_803D552C->unk30A >> 4;
    sp32 = D_803D552C->unk30A & 0xF;
    D_803E00C0[sp36].unk30 = sp34;

    if (D_801D9ED8.unkFFDC > 0) {
        D_803D5530->yRotation = ((s16)gCameras[gCameraId].unk20 + 0x40) & 0xFF;
    }
    if (D_801D9ED8.unkFFDC < 0) {
        D_803D5530->yRotation = ((s16)gCameras[gCameraId].unk20 + 0xC0) & 0xFF;
    }

    a2 =  D_801D9ED8.unkFFDC * (COS(gCameras[gCameraId].unk20) >> 7);
    a3 = -D_801D9ED8.unkFFDC * (SIN(gCameras[gCameraId].unk20) >> 7);
    if (D_803E00C0[sp36].unk35 == 0) {
        func_802DE770_6EFE20(
            sp36, // index
            sp34, // offset
            a2,
            a3,
            -0x10000);
    } else {
        D_803E00C0[sp36].unk35--;
    }

    if (sp32 == 0) {
        D_803D5530->position.xPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk0;
        D_803D5530->position.zPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk4;
        D_803D5530->position.yPos.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk8;
    } else {
        D_803D5530->position.xPos.w = ((16 - sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 0].unk0 >> 4) +
                                       (     sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk0 >> 4));
        D_803D5530->position.zPos.w = ((16 - sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 0].unk4 >> 4) +
                                       (     sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk4 >> 4));
        D_803D5530->position.yPos.w = ((16 - sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 0].unk8 >> 4) +
                                       (     sp32) * (D_803DA300[D_803E00C0[sp36].unk16 + sp34 + 1].unk8 >> 4));
    }

    func_803136B0_724D60(D_803D5530);
    D_803D5530->xVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unkC;
    D_803D5530->zVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk10;
    D_803D5530->yVelocity.w = D_803DA300[D_803E00C0[sp36].unk16 + sp34].unk14;
}

void func_802B0B00_6C21B0(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 2: // STATE_STANDING ?
        if (arg1 > 0) {
            if (arg1 < 0xE) {
                func_802A43E4_6B5A94(arg0, (s8) arg1);
            } else if (arg1 >= 0xE) {
                func_802A459C_6B5C4C(arg0, (s8) arg1);
            }
        }
        break;
    case 3: // STATE_WALKING
        if (arg1 < 0) {
            func_802A4390_6B5A40();
        } else if (arg1 == 0) {
            func_802A4390_6B5A40();
        } else if (arg1 >= 0xE) {
            func_802A459C_6B5C4C(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 0x10;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 4: // STATE_RUNNING
        if (arg1 < 0) {
            D_803D552C->unk368 = 0;
            D_803D552C->unk31A = 0;
            D_803D552C->unk2FA = 1000;
            func_802A4390_6B5A40();
        } else if (arg1 == 0) {
            func_802A4390_6B5A40();
        } else if (arg1 < 0xE) {
            func_802A43E4_6B5A94(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 0x10;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 5:
        break;
    }
    if (arg1 < 0) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B0D4C_6C23FC(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 181:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A4EC8_6B6578(arg0, arg1);
            } else if (arg1 >= 14) {
                func_802A5008_6B66B8(arg0, arg1);
            }
        }
        break;
    case 182:
        if (arg1 <= 0) {
            func_802A4E74_6B6524();
        } else if (arg1 >= 14) {
            func_802A5008_6B66B8(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    case 183:
        if (arg1 <= 0) {
            func_802A4E74_6B6524();
        } else if (arg1 < 14) {
            func_802A4EC8_6B6578(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            if (arg1 != D_803D552C->unk368) {
                D_803D552C->unk368 = arg1;
                D_803D552C->unk31A = (arg1 * D_803D5524->unkA4) / 16;
                D_803D552C->unk2FA = func_802B8B74_6CA224();
            }
        }
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B0F4C_6C25FC(s16 arg0, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 21:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A4D0C_6B63BC(arg0, arg1);
            } else {
                func_802A4DF4_6B64A4(arg0, arg1);
            }
        }
        break;
    case 22:
        if (arg1 <= 0) {
            func_802A4CB8_6B6368();
        } else if (arg1 > 13) {
            func_802A4DF4_6B64A4(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 23:
        if (arg1 <= 0) {
            func_802A4CB8_6B6368();
        } else if (arg1 < 14) {
            func_802A4D0C_6B63BC(arg0, arg1);
        } else {
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = arg1;
        }
        break;
    }

    if (arg1 == -1) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B10B0_6C2760(s16 rotation, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 201:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A55AC_6B6C5C(rotation, arg1);
            } else {
                func_802A5694_6B6D44(rotation, arg1);
            }
        }
        break;
    case 202:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 > 13) {
            func_802A5694_6B6D44(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 203:
        if (arg1 <= 0) {
            func_802A5558_6B6C08();
        } else if (arg1 < 13) {
            func_802A5694_6B6D44(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1210_6C28C0(s16 rotation, s16 arg1) {
    if ((D_803D5530->unk162 & 0xF) == 1) {
        if (D_803D552C->unk30C > 0) {
            D_803D552C->unk30C -= 1;
        }
    } else {
        D_803D552C->unk30C = MAX(D_803D552C->unk30C, 25);
    }

    switch (D_803D5530->state) {
    case 1:
    case 0x29:
        D_803D5530->yRotation = rotation;
        D_803D552C->heading = rotation;

        if ((D_803D552C->unk30C == 0) && (D_803D552C->unk367 <= 0)) {
            if (arg1 > 0) {
                func_802A5778_6B6E28(MIN(arg1 >> 2, 3), 0);
                D_803D5530->unk162 = 3;
            }
        }
        break;
    case 0x2A:
        D_803D5530->yRotation = rotation;
        D_803D552C->heading = rotation;
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1374_6C2A24(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[3];
    s16 pad2;
    s16 var_a3;

    D_803D552C->unk30C = (D_803D552C->unk30C + 1) & 0xFF;

    if ((D_803D5530->state != 1) && (D_803D5530->state != 0x3D) && (D_803D5530->state == 0x3E)) {
        if (arg1 <= 0) {
            D_803D552C->unk30C = 0;
            D_803D552C->unk30E = MAX(D_803D552C->unk30E - 1, 0);
        } else if (arg1 < 0xE) {
            D_803D552C->unk30C = arg1 * 6;
            D_803D552C->unk30E = MIN(D_803D552C->unk30E + 1, 10);
        } else {
            D_803D552C->unk30C = arg1 * 6;
            D_803D552C->unk30E = MIN(D_803D552C->unk30E + 1, 16);
        }

        D_803D5530->yRotation = rotation;
        if (arg1 > 0) {
            D_803D5530->xVelocity.w += (((arg1 * 0x10) * (SIN(D_803D5530->yRotation) >> 7)));
            D_803D5530->zVelocity.w += (((arg1 * 0x10) * (COS(D_803D5530->yRotation) >> 7)));
        }

        if (yOffset < 0) {
            if (yOffset == -1) {
                var_a3 = 60;
            } else {
                var_a3 = -yOffset;
            }
            var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->position.yPos.h);
        } else {
            var_a3 = yOffset - D_803D5530->position.yPos.h;
        }

        if (var_a3 > 80) {
            var_a3 = 80;
        }
        if (var_a3 < -80) {
            var_a3 = -80;
        }
        D_803D5530->unk28 = var_a3;
        D_803D5530->yVelocity.w = ((D_803D5530->yVelocity.w * 7) >> 3) + (D_803D5530->unk28 << 9);
        D_803D5530->yVelocity.w += ((SIN((D_803D552C->unk31C + (D_803D5540 * 4))) >> 7) << 6);
    }
    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1654_6C2D04(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[2];
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;
    s32 temp_v0_2;

    if (D_803D5530->state == 0x51) {
        var_v0 = (rotation - D_803D5530->yRotation) & 0xFF;
        if (var_v0 > 128) {
            var_v0 -= 256;
        }
        if (var_v0 > 4) {
            var_v0 = 4;
        }
        if (var_v0 < -4) {
            var_v0 = -4;
        }
        D_803D5530->yRotation = (D_803D5530->yRotation + var_v0) & 0xFF;
        D_803D552C->unk306 = var_v0;
        if (yOffset < 0) {
            if (yOffset == -1) {
                var_a3 = 60;
            } else {
                var_a3 = -yOffset;
            }
            var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->position.yPos.h);
        } else {
            var_a3 = yOffset - D_803D5530->position.yPos.h;
        }
        var_a3 = var_a3 >> 2;
        if ((get_distance_from_ground() >= 2369) && (var_a3 > 0)) {
            var_a3 = 0;
        }
        if (var_a3 > 40) {
            var_a3 = 40;
        }
        if (var_a3 < -40) {
            var_a3 = -40;
        }

        temp_v0 = var_a3 - D_803D5530->unk28;
        if (temp_v0 > 0) {
            D_803D5530->unk28 += MIN(temp_v0, 12);
        } else {
            D_803D5530->unk28 += MAX(temp_v0, -12);
        }

        if (D_803D5530->yVelocity.h > 20) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -20) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h > 16) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -16) {
            D_803D5530->yVelocity.h += 1;
        }
        if (D_803D5530->yVelocity.h > 12) {
            D_803D5530->yVelocity.h -= 1;
        }
        if (D_803D5530->yVelocity.h < -12) {
            D_803D5530->yVelocity.h += 1;
        }

        temp_v0_2 = (D_803D5530->unk28 << 0xE) - D_803D5530->yVelocity.w;
        if (temp_v0_2 > 0) {
            D_803D5530->yVelocity.w += MIN(0x4000, temp_v0_2);
        } else {
            D_803D5530->yVelocity.w += MAX(-0x4000, temp_v0_2);
        }
    }
}

void func_802B1918_6C2FC8(s16 arg0, s16 arg1, s16 arg2) {
    s16 pad[2];
    s16 var_a3;

    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) || (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }
    if (D_803D552C->unk30E > 8) {
        D_803D552C->unk30E--;
    }
    if (arg2 < 0) {
        if (arg2 == -1) {
            var_a3 = 60;
        } else {
            var_a3 = -arg2;
        }
        var_a3 = var_a3 + ((func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10) - D_803D5530->position.yPos.h);
    } else {
        var_a3 = arg2 - D_803D5530->position.yPos.h;
    }

    switch (D_803D5530->state) {
    case 0x1:
    case 0x79:
        if ((arg1 > 0) || (var_a3 > 0)) {
            func_802A5CF4_6B73A4();
            D_803D5530->unk162 = 2;
        }
        break;
    case 0x7A:
    case 0x7B:
        if (arg1 == 0) {
            D_803D5530->state = 123;
            D_803D552C->unk368 = 0;
        } else if (arg1 == -1) {
            D_803D5530->state = 123;
            D_803D5530->yRotation = arg0;
            D_803D552C->unk368 = 0;
        } else {
            D_803D5530->yRotation = arg0;
            D_803D5530->state = 122;
            D_803D552C->unk368 = arg1;
        }
        if ((var_a3 > 0) || (D_803D5530->yVelocity.w < (gGravity * -2))) {
            D_803D5530->yVelocity.w += gGravity >> 3;
            D_803D552C->unk30E = 50;
        } else {
            D_803D5530->yVelocity.w -= (gGravity >> 3);
        }
        break;
    }
    D_803D552C->unk30C = (D_803D552C->unk30C + (D_803D552C->unk30E >> 1)) % 360;
    if (arg1 < 0) {
        D_803D5530->yRotation = arg0;
    }
}

void func_802B1B98_6C3248(s16 rotation, s16 arg1) {
    switch (D_803D5530->state) {
    case 1:
    case 141:
        if (arg1 > 0) {
            if (arg1 < 14) {
                func_802A5EF8_6B75A8(rotation, arg1);
            } else if (arg1 > 13) {
                func_802A6044_6B76F4(rotation, arg1);
            }
        }
        break;

    case 142:
        if (arg1 <= 0) {
            func_802A5EA4_6B7554();
        } else if (arg1 > 13) {
            func_802A6044_6B76F4(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    case 143:
        if (arg1 <= 0) {
            func_802A5EA4_6B7554();
        } else if (arg1 < 14) {
            func_802A5EF8_6B75A8(rotation, arg1);
        } else {
            D_803D5530->yRotation = rotation;
            D_803D552C->unk368 = arg1;
        }
        break;
    }

    if (arg1 < 0) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1D00_6C33B0(s16 rotation, s16 arg1) {
    if ((D_803D5540 & 3) == 0) {
        if ((D_803D5530->unk4A == 0) && (D_803D5530->unk4C.unk1A == 0)) {
            D_803D5530->health--;
            D_803D5530->health = D_803D5530->health; // pointless?
            D_803D552C->lastHpLost++;
        }
    }

    switch (D_803D5530->state) {
    case 1:
    case 161:
        if ((arg1 == 1) || (arg1 == 2)) {
            func_802A5E1C_6B74CC(rotation);
        }
        break;
    case 162:
        if ((arg1 == 0) || (arg1 == -1)) {
            func_802A5E64_6B7514();
        }
        D_803D5530->yRotation = rotation;
        break;
    }

    if (arg1 == -1) {
        D_803D5530->yRotation = rotation;
    }
}

void func_802B1E28_6C34D8(s16 rotation, s16 arg1, s16 yOffset) {
    s16 pad[3];
    s16 airHeight;
    s16 phi_v1_6;
    s16 temp_v0_3;
    s16 sp18;

    if ((D_803D5530->yVelocity.w > FTOFIX32(6.0)) ||
        (D_803D5530->yVelocity.w < FTOFIX32(-6.0))) {
        D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    }
    sp18 = D_803D5524->unkC2;

    switch (D_803D5530->state) {
    case 101:
        if (arg1 > 0) {
            func_802A613C_6B77EC(rotation);
            D_803D5530->yVelocity.h += 2;
            D_803D5530->unk162 = 2;
        }
        D_803D5530->yRotation = rotation;
        break;
    case 103:
        if (arg1 > 0) {
            func_802A613C_6B77EC(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 104:
        if ((arg1 == 0) || (arg1 == -1)) {
            func_802A60C4_6B7774();
        } else if (arg1 >= 10) {
            func_802A6198_6B7848(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 105:
        if (arg1 < 10) {
            func_802A613C_6B77EC(rotation);
        }
        D_803D5530->yRotation = rotation;
        break;
    case 106:
        if ((gGravity * -32) < D_803D5530->yVelocity.w) {
            D_803D5530->yVelocity.w -= gGravity + (gGravity >> 1);
        }
        break;
    default:
        break; // required
    }

    D_803D5530->yVelocity.w -= gGravity >> 3;

    if ((D_803D5524->unk9C == VULTURE2) ||
        (D_803D5524->unk9C == VULTURE) ||
        (D_803D5524->unk9C == SEAGULL) ||
        (D_803D5524->unk9C == SEAGULL2)) {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += gGravity >> 2;
        }
    } else {
        if (D_803D5530->yVelocity.w <= FTOFIX32(-5.0)) {
            D_803D5530->yVelocity.w += gGravity >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-7.0)) {
            D_803D5530->yVelocity.w += gGravity >> 4;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-8.0)) {
            D_803D5530->yVelocity.w += gGravity >> 3;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-9.0)) {
            D_803D5530->yVelocity.w += gGravity >> 2;
        }
        if (D_803D5530->yVelocity.w <= FTOFIX32(-10.0)) {
            D_803D5530->yVelocity.w += gGravity >> 1;
        }
    }
    if (D_803D552C->unk30C > 0) {
        if ((((sp18 * 0xA) >> 4) < D_803D552C->unk30C) && (sp18 >= D_803D552C->unk30C)) {
            D_803D5530->xVelocity.w += SIN(D_803D552C->heading) * 3;
            D_803D5530->zVelocity.w += COS(D_803D552C->heading) * 3;
            if ((D_803D5524->unk9C == VULTURE2) ||
                (D_803D5524->unk9C == VULTURE) ||
                (D_803D5524->unk9C == SEAGULL) ||
                (D_803D5524->unk9C == SEAGULL2)) {
                airHeight = get_distance_from_ground();
                if ((D_803D5524->unk9C == VULTURE) ||
                    (D_803D5524->unk9C == SEAGULL2)) {
                    airHeight += airHeight >> 1;
                }
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (airHeight > 448) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.5625);
                    } else if (airHeight > 320) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.6875);
                    } else if (airHeight > 192) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.75);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(0.875);
                    }
                }
            } else {
                airHeight = get_distance_from_ground();
                if (D_803D5530->yVelocity.w < FTOFIX32(10.0)) {
                    if (airHeight > 640) {
                        D_803D5530->yVelocity.w += FTOFIX32(0.25);
                    } else {
                        D_803D5530->yVelocity.w += FTOFIX32(0.875);
                    }
                }
            }
        }
        D_803D552C->unk30C += -1;
    } else {
        if (yOffset < 0) {
            phi_v1_6 = ((func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 0x10) - yOffset) - D_803D5530->position.yPos.h;
        } else {
            phi_v1_6 = yOffset - D_803D5530->position.yPos.h;
        }
        if (D_803D5530->state != 0x6A) {
            temp_v0_3 = 0;
            if (phi_v1_6 >= -256) {
                if (phi_v1_6 < -128) {
                    if (D_803D5530->yVelocity.h < -10) {
                        temp_v0_3 = 1;
                    }
                } else if (phi_v1_6 < 0) {
                    if (D_803D5530->yVelocity.h < -5) {
                        temp_v0_3 = 1;
                    }
                } else if (phi_v1_6 < 64) {
                    if (D_803D5530->yVelocity.h < 2) {
                        temp_v0_3 = 1;
                    }
                } else if (D_803D5530->yVelocity.h < 10) {
                    temp_v0_3 = 1;
                }
            }
            if (temp_v0_3 != 0) {
                D_803D553A = 4;
                D_803D5530->yVelocity.w += 2 << (20 / sp18);
                D_803D552C->unk30C = sp18;
                D_803D5530->unk162 = 2;
                func_802B8AD8_6CA188();
                if ((D_803D5524->unk9C == VULTURE2) ||
                    (D_803D5524->unk9C == VULTURE) ||
                    (D_803D5524->unk9C == SEAGULL) ||
                    (D_803D5524->unk9C == SEAGULL2)) {
                    D_803D5528->unk3C0.unk4 = 13;
                }
            }
        }
    }
    if (arg1 == -1) {
        D_803D5530->yRotation = rotation;
    }
}

// get_distance_from_ground
s16 get_distance_from_ground(void) {
    return D_803D5530->position.yPos.h - func_802B25B4_6C3C64(1);
}

// ESA: func_800459A0
s16 func_802B25B4_6C3C64(u8 getWaterHeight) {
    s16 temp_t0;
    s16 temp_t1;

    s16 temp_a2;
    s16 temp_v1;

    s32 phi_t2;
    s32 phi_t4;
    s32 phi_t3;
    s32 phi_t5;

    s16 phi_a1;

    temp_v1 = D_803D5530->position.xPos.h >> 6;
    temp_a2 = D_803D5530->position.zPos.h >> 6;
    if (D_803D5530->unk160 == 2) {
        phi_a1 = MIN(MIN(D_803C0740[temp_v1 + 0][temp_a2 + 0].unk1,
                         D_803C0740[temp_v1 + 1][temp_a2 + 0].unk1),
                     MIN(D_803C0740[temp_v1 + 0][temp_a2 + 1].unk1,
                         D_803C0740[temp_v1 + 1][temp_a2 + 1].unk1));
    } else {
        temp_t0 = D_803D5530->position.xPos.h & 0x3F;
        temp_t1 = D_803D5530->position.zPos.h & 0x3F;

        phi_t2 = D_803C0740[temp_v1 + 0][temp_a2 + 0].unk0;
        phi_t3 = D_803C0740[temp_v1 + 0][temp_a2 + 1].unk0;
        phi_t4 = D_803C0740[temp_v1 + 1][temp_a2 + 0].unk0;
        phi_t5 = D_803C0740[temp_v1 + 1][temp_a2 + 1].unk0;

        if (D_803C0740[temp_v1 + 0][temp_a2 + 0].unk4 & 1) {
            if (temp_t0 < temp_t1) {
                phi_t4 = (s16) phi_t2;
            } else {
                phi_t3 = (s16) phi_t2;
            }
        } else if ((temp_t0 + temp_t1) < 64) {
            phi_t5 = (s16) phi_t2;
        } else {
            phi_t2 = (s16) phi_t5;
        }

        phi_a1 = MIN(MIN(phi_t2, phi_t4),
                     MIN(phi_t3, phi_t5));
    }

    if (getWaterHeight) {
        return MAX(phi_a1 * 8, D_803C0740[temp_v1 + 0][temp_a2 + 0].unk6 * 4);
    } // else return lowest point in terrain?
    return (phi_a1 * 8);
}

void func_802B2834_6C3EE4(void) {
    s16 phi_a2;
    s16 temp_v0_3;
    s16 a;
    s16 b;

    a = D_803D5530->position.xPos.h >> 6;
    b = D_803D5530->position.zPos.h >> 6;

    if ((D_803C0740[a + 0][b + 0].unk6) ||
        (D_803C0740[a + 1][b + 0].unk6) ||
        (D_803C0740[a + 0][b + 1].unk6) ||
        (D_803C0740[a + 1][b + 1].unk6)) {

        if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
            phi_a2 = D_803D5524->unkBA;
        } else {
            phi_a2 = D_803D5524->unkB8;
        }
        temp_v0_3 = func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
        if (temp_v0_3 != 0) {
            if ((D_803D5530->position.yPos.h + phi_a2) < temp_v0_3) {
                if (D_803D5530->state != 0xDD) {
                    func_802B315C_6C480C();
                }
                func_802B8B1C_6CA1CC();
                func_802D760C_6E8CBC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, D_803D5530->unk30, D_803D5530->yVelocity.h);
            }
        }
    }
}

void func_802B2964_6C4014(void) {
    s16 phi_a3;
    s16 temp_v0_2;

    temp_v0_2 = func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        phi_a3 = D_803D5524->unkBA;
    } else {
        phi_a3 = D_803D5524->unkB8;
    }
    if ((temp_v0_2 == 0) || (temp_v0_2 < ((func_80310EE4_722594(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->unk160) >> 16) + phi_a3))) {
        func_802B2EA8_6C4558();
        return;
    }
    if ((D_803D5538 != 0) &&
        (((D_803D5524->class == CLASS_BIRD) && (D_801D9ED8.prevAButton == 0) && (D_801D9ED8.curAButton != 0)) ||
         ((D_803D5524->class == CLASS_HELI) && (D_801D9ED8.curAButton != 0)))) {

        if (((D_803D5530->position.yPos.h + phi_a3) - temp_v0_2) > -7) {
            D_803D5530->position.yPos.h = MAX(D_803D5530->position.yPos.h, temp_v0_2 - phi_a3);
            D_803D5530->yVelocity.w = FTOFIX32(4.0);
            func_802B2EA8_6C4558();
        }
    }
    if ((temp_v0_2 + 16) < D_803D5530->position.yPos.h) {
        func_802B2FF4_6C46A4();
    }
}

s32 func_802B2AF0_6C41A0(s32 arg0, s32 arg1) {
    if ((arg0 <= 0) && (func_802B2C20_6C42D0(D_803D5530->position.xPos.h - D_803D5524->unkBE, D_803D5530->position.zPos.h))) {
        return 1;
    }
    if ((arg0 >= 0) && (func_802B2C20_6C42D0(D_803D5530->position.xPos.h + D_803D5524->unkBE, D_803D5530->position.zPos.h))) {
        return 1;
    }
    if ((arg1 <= 0) && (func_802B2C20_6C42D0(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h - D_803D5524->unkBE))) {
        return 1;
    }
    if ((arg1 >= 0) && (func_802B2C20_6C42D0(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h + D_803D5524->unkBE))) {
        return 1;
    }
    // implicit return? UB?
}

s32 func_802B2C20_6C42D0(s16 arg0, s16 arg1) {
    s32 phi_v0_2;
    s16 phi_v1;
    s16 temp_a3;
    s16 xVel;
    s16 zVel;
    s32 pad;

    phi_v0_2 = MAX(MAX(D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 0].unk6,
                       D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 0].unk6),
                   MAX(D_803C0740[(arg0 >> 6) + 0][(arg1 >> 6) + 1].unk6,
                       D_803C0740[(arg0 >> 6) + 1][(arg1 >> 6) + 1].unk6)) & 0xFFFFFFFF;

    temp_a3 = D_803C0430.unk0[(arg0 * arg1) & 7][(u16)(D_803C0430.unk204 + (((arg0 * arg1) + (arg0 * arg0)) << 3)) & 63] + (4 * phi_v0_2);

    if (D_803D5524->waterClass & (WATER_DAMAGE|WATER_DAMAGE_X2)) {
        phi_v1 = D_803D5524->unkBA;
    } else {
        // regalloc helper
        if ((phi_v1 && phi_v1) && phi_v1) {}
        phi_v1 = D_803D5524->unkB8;
    }

    phi_v0_2 = func_80310EE4_722594(arg0, arg1, D_803D5530->unk160);
    if (phi_v0_2 == 0x40000000) {
        if (temp_a3 < ((func_8031124C_7228FC(arg0, arg1) >> 0x10) + phi_v1)) {
            func_80311BF8_7232A8(arg0, arg1, &xVel, &zVel);
            if (ABS(xVel) > 23) {
                return 1;
            }
            if (ABS(zVel) > 23) {
                return 1;
            }
        }
        return 0;
    }

    if (temp_a3 < ((phi_v0_2 >> 0x10) + phi_v1)) {
        func_80311A2C_7230DC(arg0, arg1, &xVel, &zVel, D_803D5530->unk160);
        if (ABS(xVel) > 23) {
            return 1;
        }
        if (ABS(zVel) > 23) {
            return 1;
        }
    }
    return 0;
}

void func_802B2EA8_6C4558(void) {
    switch (D_803D5524->class) {
    case CLASS_WALK:
        func_802A4390_6B5A40();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_WHEELS:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_POGO:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_FLYING:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case CLASS_BIRD:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_HELI:
        func_802A5D64_6B7414();
        D_803D5530->unk162 = 1;
        break;
    case CLASS_SWIM:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E64_6B7514();
        D_803D5530->unk162 = 1;
        break;
    }
}

void func_802B2FF4_6C46A4(void) {
    switch (D_803D5524->class) {
    case CLASS_WALK:
        D_803D5530->state = 5;
        D_803D5530->unk162 = 3;
        break;
    case CLASS_WHEELS:
        func_802A4CB8_6B6368();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_POGO:
        func_802A5C80_6B7330();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_FLYING:
        func_802A5708_6B6DB8(D_803D5530->yRotation, 0, 1);
        D_803D5530->unk162 = 2;
        break;
    case CLASS_BIRD:
        func_802A60C4_6B7774();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_HELI:
        func_802A5CF4_6B73A4();
        D_803D5530->unk162 = 3;
        break;
    case CLASS_SWIM:
        D_803D5530->xVelocity.w = 0;
        D_803D5530->zVelocity.w = 0;
        func_802A5E1C_6B74CC(0);
        D_803D5530->unk162 = 3;
        break;
    }
}

void func_802B315C_6C480C(void) {
    switch (D_803D5524->waterClass & (WATER_DAMAGE - 1)) {
    case WATER_FLOAT:
        func_802A5EA4_6B7554();
        D_803D5530->unk162 = 5;
        break;
    case WATER_SWIM:
        func_802A5DD0_6B7480();
        D_803D5530->unk162 = 4;
        break;
    case WATER_SINK_WALK:
        func_802A4E74_6B6524();
        D_803D5530->unk162 = 6;
        break;
    case WATER_SINK_WHEELS:
        func_802A5558_6B6C08();
        D_803D5530->unk162 = 6;
        break;
    case WATER_TBD:
        D_803D5530->yVelocity.w += FTOFIX32(5.0);
        break;
    }
}

void func_802B3230_6C48E0(void) {
    s16 tmp;

    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        switch (D_803D5530->state) {
        case 61:
        case 62:
        case 141:
        case 142:
        case 143:
        case 144:
        case 181:
        case 182:
        case 183:
        case 184:
        case 185:
        case 201:
        case 202:
        case 203:
        case 204:
            if (D_803D5524->unkBA < (func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h) - (func_8031124C_7228FC(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h) >> 0x10))) {
                if ((D_803D5530->unk4C.unk1A == 0) && ((D_803D5540 & 3) == 0)) {
                    tmp = 0;
                    if (D_803D5524->waterClass & WATER_DAMAGE) {
                        tmp += 1;
                    }
                    if (D_803D5524->waterClass & WATER_DAMAGE_X2) {
                        tmp += 2;
                    }
                    func_802B38FC_6C4FAC(D_803D5530, tmp, -1, 0);
                }
                if (SSSV_RAND(16) == 0xC) {
                    create_sparks(
                        D_803D5530->position.xPos.h,
                        D_803D5530->position.zPos.h,
                        D_803D5530->position.yPos.h,
                        33,
                        GPACK_RGBA5551(224, 224, 128, 1));
                }
            }
        }
    }
}

void func_802B33D0_6C4A80(Animal *a) {
    a->unk4A += 1;
    if (a->unk16C->unk82.unk2) {
        a->previousHeading = a->heading;
    }
}

void func_802B3400_6C4AB0(Animal *a) {
    a->unk4A = 1;
    if (a->unk16C->unk82.unk2) {
        a->previousHeading = a->heading;
    }
}

void func_802B342C_6C4ADC(void) {
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A += 1;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->previousHeading = D_801D9ED8.animals[gCurrentAnimalIndex].animal->heading;
}

void func_802B3474_6C4B24(void) {
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->previousHeading = D_801D9ED8.animals[gCurrentAnimalIndex].animal->heading;
}

// reference counter?
void func_802B34B8_6C4B68(Animal *a) {
    a->unk4A = MAX(0, a->unk4A - 1);
}

void func_802B34DC_6C4B8C(void) {
    Animal *a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    a->unk4A = MAX(0, a->unk4A - 1);
}

// increment
void func_802B3518_6C4BC8(void) {
    D_803D554A += 1;
}
// reset
void func_802B3530_6C4BE0(void) {
    D_803D554A = 1;
}
// decrement
void func_802B3540_6C4BF0(void) {
    D_803D554A = MAX(0, D_803D554A - 1);
}

void func_802B356C_6C4C1C(Animal *arg0, s16 damage, s16 arg2, u8 arg3) {
    s16 hpDrop;
    s16 temp_v1_2;
    s16 pad;

    damage <<= 4;

    if ((arg0->unk4C.unk1A != 0) || (arg0->unk4A != 0) || (arg0->unk16C->armour == 0xFF)) {
        damage = 0;
    }

    if (arg0->unk16C->unk82.unk2 == 0) {
        arg0->health = MAX(0, arg0->health - (damage >> 4));
    }

    switch (arg0->unk16C->unkE6) {
    case 0:
        hpDrop = (damage * 36) >> 4;
        break;
    case 1:
        hpDrop = (damage * 24) >> 4;
        break;
    case 2:
        hpDrop = (damage * 16) >> 4;
        break;
    case 3:
        hpDrop = (damage * 8) >> 4;
        break;
    case 4:
        hpDrop = (damage * 5) >> 4;
        break;
    default:
        hpDrop = (damage * 16) >> 4;
        break;
    }

    if ((arg2 >= 0) && (arg0->unk16C->unk82.unk2) && (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        temp_v1_2 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v1_2) {
        case 2:
            hpDrop = ((hpDrop * 3) >> 2);
            break;
        case 3:
            hpDrop = (hpDrop >> 1);
            break;
        case 4:
            hpDrop = (hpDrop >> 2);
            break;
        case 5:
            hpDrop = (hpDrop >> 3);
            break;
        case 6:
        case 7:
            hpDrop = 0;
            break;
        }
    }

    if ((arg0->unk16C->unk82.unk2) && (arg3 != 0) && ((arg0->health - hpDrop) > 0)) {
        if (hpDrop > 480) {
            func_802DBA58_6ED108(14, arg0);
            create_sparks(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 33, GPACK_RGBA5551(224, 224, 0, 1));
        } else if (hpDrop > 192) {
            func_802DBA58_6ED108(14, arg0);
            create_sparks(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 17, GPACK_RGBA5551(224, 224, 0, 1));
        } else if (hpDrop >= 64) {
            func_802DBA58_6ED108(13, arg0);
            create_sparks(arg0->position.xPos.h, arg0->position.zPos.h, arg0->position.yPos.h, 8, GPACK_RGBA5551(224, 224, 0, 1));
        }
    }
    hpDrop = MIN(hpDrop, 560);

    if ((damage != 0) && (hpDrop <= 0)) {
        hpDrop = 1;
    }

    func_80349280_75A930(arg0, hpDrop >> 4);

    if (hpDrop > 0) {
        arg0->health = MAX(0, (arg0->health - MAX(1, hpDrop >> 4)));
    }
}

void func_802B38FC_6C4FAC(Animal *arg0, s16 damage, s16 arg2, u8 stars) {
    s16 hpDrop;
    s16 temp_v0;

    if ((arg0->unk4C.unk1A != 0) || (arg0->unk4A != 0)) {
        damage = 0;
    }
    // e.g. POLAR_BEAR_DEFENDING
    if (arg0->unk16C->armour == 0xFF) {
        damage = 0;
    }
    hpDrop = damage;
    if ((arg2 >= 0) && (arg0->unk16C->unk82.unk2) && (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        temp_v0 = arg0->unk16C->unkE6 - arg2;
        switch (temp_v0) {
        case 2:
            hpDrop = (damage * 12) >> 4;
            break;
        case 3:
            hpDrop = (damage * 9) >> 4;
            break;
        case 4:
            hpDrop = (damage * 6) >> 4;
            break;
        case 5:
        case 6:
        case 7:
            hpDrop = (damage * 4) >> 4;
            break;
        }
    }

    if ((arg0->unk16C->unk82.unk2) && (stars != 0) && ((arg0->health - hpDrop) > 0)) {
        if (hpDrop > 480) {
            func_802DBA58_6ED108(14, arg0);
            spawn_dizzy_stars_big(); // lots of stars
        } else if (hpDrop > 192) {
            func_802DBA58_6ED108(14, arg0);
            spawn_dizzy_stars_medium(); // medium amount of stars
        } else if (hpDrop >= 64) {
            func_802DBA58_6ED108(13, arg0);
            spawn_dizzy_starts_small(); // small amount of stars
        }
    }

    // clamp min/max hp drop
    if ((damage != 0) && (hpDrop <= 0)) {
        hpDrop = 1;
    }
    if (hpDrop >= 35) {
        hpDrop = 35;
    }
    func_80349280_75A930(arg0, hpDrop);
    arg0->health = MAX(0, arg0->health - hpDrop);
}

// ESA: func_80046EC8
void func_802B3B48_6C51F8(Animal *arg0, Animal *arg1, s16 *damage) {
    s16 orig = *damage;
    s16 tmp;

    switch (arg0->unk16C->unkE6) {
    case 0:
        *damage = *damage * 36 >> 4;
        break;
    case 1:
        *damage = *damage * 24 >> 4;
        break;
    case 2:
        *damage = *damage * 16 >> 4;
        break;
    case 3:
        *damage = *damage * 8 >> 4;
        break;
    case 4:
        *damage = *damage * 5 >> 4;
        break;
    }

    if (arg0 != D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        tmp = arg0->unk16C->unkE6 - arg1->unk16C->unkE6;
        switch (tmp) {
        case 2:
            *damage = *damage >> 1;
            break;
        case 3:
            *damage = *damage >> 2;
            break;
        case 4:
            *damage = *damage >> 3;
            break;
        case 5:
        case 6:
        case 7:
            *damage = 0;
        }
    }

    if (orig != 0) {
        *damage = MAX(*damage, 1);
    }
}

// ESA: func_80047058
s16 func_802B3C9C_6C534C(s16 arg0, Animal *arg1) {
    if (arg0 == 0) {
        return 0;
    }

    switch (arg1->unk16C->unkE6) {
    case 0:
        arg0 = (arg0 * 32) >> 4;
        break;
    case 1:
        arg0 = (arg0 * 24) >> 4;
        break;
    case 2:
        // arg0 = (arg0 * 16) >> 4;
        break;
    case 3:
        arg0 = (arg0 * 10) >> 4;
        break;
    case 4:
        arg0 = (arg0 * 6) >> 4;
        break;
    }
    return  MAX(1, arg0);
}

s16 func_802B3D68_6C5418(void) {
    s16 x;
    s16 y;
    s16 z;

    f32 tmpf;

    tmpf = ABS(D_803D5530->position.xPos.h - D_803F2C44);
    x = (s16)tmpf >> 1;

    tmpf = ABS(D_803D5530->position.zPos.h - D_803F2C48);
    z = (s16)tmpf >> 1;

    tmpf = ABS(D_803D5530->position.yPos.h - D_803F2C4C);
    y = (s16)tmpf >> 1;

    return MAX(MAX(x, z), y) + x + z + y;
}
