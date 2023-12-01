#include <ultra64.h>
#include "common.h"




// ========================================================
// .bss
// ========================================================

s16  D_803D5510;
s16  D_803D5512;

// s32  D_803D5514; // unused
// s32  D_803D5518; // unused
// s32  D_803D551C; // unused

// ========================================================
// .text
// ========================================================

// ESA: func_800646E4
void func_802A3CD0_6B5380(void) {
    s16 xVel, zVel;

    if (D_803D5530->unk160 == 2) {
        func_80311AA8_723158(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &D_803D5510, &D_803D5512);
    } else {
        func_80311BF8_7232A8(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, &D_803D5510, &D_803D5512);
    }

    if (D_803D5530->unk161 == 0) {
        xVel = D_803D5510;
        zVel = D_803D5512;

        if (xVel > 24) {
            xVel += xVel - 24;
        }
        if (xVel < -24) {
            xVel += xVel + 24;
        }

        if (zVel > 24) {
            zVel += zVel - 24;
        }
        if (zVel < -24) {
            zVel += zVel + 24;
        }

        D_803D5530->xVelocity.w += MAX(MIN(xVel, 128), -128) << 12;
        D_803D5530->zVelocity.w += MAX(MIN(zVel, 128), -128) << 12;
    }
}

// ESA: func_80064858
void func_802A3E70_6B5520(Animal *arg0, s32 *arg1, s32 *arg2) {
    if (arg0->unk161 == 0) {
        if (D_803D5510 < -23) {
            *arg1 = MIN(*arg1, FTOFIX32(-1.0));
        }
        if (D_803D5510 > 23) {
            *arg1 = MAX(*arg1, FTOFIX32(1.0));
        }
        if (D_803D5512 < -23) {
            *arg2 = MIN(*arg2, FTOFIX32(-1.0));
        }
        if (D_803D5512 > 23) {
            *arg2 = MAX(*arg2, FTOFIX32(1.0));
        }
    }
}

// ESA: func_80064930
void func_802A3F68_6B5618(s32 *arg0, s32 *arg1) {
    *arg0 += ((((D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk7 & 0xF0) >> 4) & 7   ) * (1 - (((D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk7 >> 4) & 8) >> 2))) << 17;
    *arg1 += ((((D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk7 & 7)        ) & 0xFF) * (1 - (((D_803C0740[D_803D5530->position.xPos.h >> 6][D_803D5530->position.zPos.h >> 6].unk7     ) & 8) >> 2))) << 17;
}

// ESA: func_80064A14
void func_802A403C_6B56EC(Animal *arg0, s16 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a2;

    temp_v0 = arg0->xVelocity.w;
    temp_a2 = D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk7;
    temp_v1 = arg0->zVelocity.w;

    temp_v0 = temp_v0 - (((1 - (((temp_a2 >> 4) & 8) >> 2)) * (((temp_a2 & 0xF0) >> 4) & 7)) << 17);
    temp_v1 = temp_v1 - (((1 - ((temp_a2 & 8) >> 2)) * ((u8)temp_a2 & 7)) << 17);

    arg0->xVelocity.w -= (temp_v0 >> arg1);
    arg0->zVelocity.w -= (temp_v1 >> arg1);
}

// ESA: func_80064AC0
void func_802A40EC_6B579C(void) {
    s16 tmp;
    if (D_803D5524->waterClass & (WATER_DAMAGE | WATER_DAMAGE_X2)) {
        tmp = D_803D5524->unkBA;
    } else {
        tmp = D_803D5524->unkB8;
    }
    D_803D5530->yVelocity.w = (D_803D5530->yVelocity.w * 7) >> 3;
    D_803D5530->yVelocity.w -= ((D_803D5530->position.yPos.h + tmp) - func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h)) << 10;
}

// ESA: func_80064B5C
void func_802A4184_6B5834(void) {
    s16 tmp = (D_803D5530->position.yPos.h + D_803D5524->unkBA) - func_80298F78_6AA628(D_803D5530->position.xPos.h, D_803D5530->position.zPos.h);
    if (tmp >= 0) {
        D_803D5530->yVelocity.w -= D_803A05B0;
    } else if (tmp >= -15) {
        D_803D5530->yVelocity.w -= ((tmp + 16) * D_803A05B0) >> 4;
    }
}

// ESA: func_80064C08
void func_802A4220_6B58D0(s32* xVel, s32* zVel, u16 arg2) {
    // not assigned to anything?
    MAX(ABS(*xVel), ABS(*zVel));

    *xVel = (*xVel * arg2) >> 8;
    *zVel = (*zVel * arg2) >> 8;
}

// ESA: func_80064CD0
void func_802A4278_6B5928(u16 arg0, u16 arg1, s16 arg2) {
    s32 pad1;
    s32 pad2;
    s32 temp_t6_2;
    s32 temp_t7_2;
    s32 xVel;
    s32 temp_t7_3;
    s32 zVel;

    xVel = D_803D5530->xVelocity.w;
    zVel = D_803D5530->zVelocity.w;

    temp_t7_2 = SIN(D_803D552C->unk302) >> 5;
    temp_t6_2 = COS(D_803D552C->unk302) >> 5;
    temp_t7_3 = (((xVel >> 0xA) * temp_t7_2) + ((zVel >> 0xA) * temp_t6_2)) >> 0xA;

    temp_t7_2 = (temp_t7_2 * temp_t7_3);
    temp_t6_2 = (temp_t6_2 * temp_t7_3);

    xVel = xVel - (((((xVel - temp_t7_2) >> arg0) + (xVel >> arg1)) * arg2) >> 4);
    zVel = zVel - (((((zVel - temp_t6_2) >> arg0) + (zVel >> arg1)) * arg2) >> 4);

    D_803D5530->xVelocity.w = xVel;
    D_803D5530->zVelocity.w = zVel;
}
