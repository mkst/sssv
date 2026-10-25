#include <ultra64.h>
#include "common.h"

#include "mtx.h"


void build_rotate_scale_translate_matrix(Mtx *mtx, s32 xPos, s32 zPos, s32 yPos, s16 xRot, s16 yRot, s16 zRot, s32 xScale, s32 zScale, s32 yScale) {
    s64 spC0;
    s64 spB8;
    s64 spB0;
    s64 spA8;
    s64 spA0;
    s64 sp98;

    spC0 = (s64)SINB(xRot) << 8;
    spB8 = (s64)COSB(xRot) << 8;
    spB0 = (s64)SINB(yRot) << 8;
    spA8 = (s64)COSB(yRot) << 8;
    spA0 = (s64)SINB(zRot) << 8;
    sp98 = (s64)COSB(zRot) << 8;

    set_mtx_fixed_point_pair((xScale * ( ((spB8 * sp98) / 0x10000) - ((spC0 * ((spB0 * spA0) / 0x10000)) / 0x10000))) / 0x10000, (zScale * -((spC0 * spA8) / 0x10000)) / 0x10000, &mtx->m[0][0]);
    set_mtx_fixed_point_pair((yScale * (-((spB8 * spA0) / 0x10000) - ((spC0 * ((spB0 * sp98) / 0x10000)) / 0x10000))) / 0x10000, 0,                                             &mtx->m[0][1]);

    set_mtx_fixed_point_pair((xScale * ( ((spC0 * sp98) / 0x10000) + ((spB8 * ((spB0 * spA0) / 0x10000)) / 0x10000))) / 0x10000, (zScale * ((spB8 * spA8) / 0x10000)) / 0x10000,  &mtx->m[0][2]);
    set_mtx_fixed_point_pair((yScale * (-((spC0 * spA0) / 0x10000) + ((spB8 * ((spB0 * sp98) / 0x10000)) / 0x10000))) / 0x10000, 0,                                             &mtx->m[0][3]);

    set_mtx_fixed_point_pair((xScale * (  (spA8 * spA0) / 0x10000)                                                  ) / 0x10000, (zScale * -spB0) / 0x10000,                      &mtx->m[1][0]);
    set_mtx_fixed_point_pair((yScale * (  (spA8 * sp98) / 0x10000)                                                  ) / 0x10000, 0,                                             &mtx->m[1][1]);

    set_mtx_fixed_point_pair(xPos, zPos,    &mtx->m[1][2]);
    set_mtx_fixed_point_pair(yPos, 0x10000, &mtx->m[1][3]);
}

void func_80125FE0(Mtx *mtx, s32 xPos, s32 zPos, s32 yPos, s16 xRot, s16 yRot, s32 xScale, s32 zScale, s32 yScale) {
    s64 sp80;
    s64 sp78;
    s64 sp70;
    s64 sp68;

    sp80 = (s64)SINB(xRot) << 8;
    sp78 = (s64)COSB(xRot) << 8;
    sp70 = (s64)SINB(yRot) << 8;
    sp68 = (s64)COSB(yRot) << 8;

    set_mtx_fixed_point_pair((xScale * sp68) / 0x10000,                       (-xScale * sp70) / 0x10000,                      &mtx->m[0][0]);
    set_mtx_fixed_point_pair(0,                                               0,                                               &mtx->m[0][1]);

    set_mtx_fixed_point_pair( (zScale * ((sp70 * sp78) / 0x10000)) / 0x10000, (zScale * ((sp68 * sp78) / 0x10000)) / 0x10000,  &mtx->m[0][2]);
    set_mtx_fixed_point_pair( (zScale * sp80) / 0x10000,                      0,                                               &mtx->m[0][3]);

    set_mtx_fixed_point_pair((-yScale * ((sp70 * sp80) / 0x10000)) / 0x10000, (-yScale * ((sp68 * sp80) / 0x10000)) / 0x10000, &mtx->m[1][0]);
    set_mtx_fixed_point_pair( (yScale * sp78) / 0x10000,                      0,                                               &mtx->m[1][1]);

    set_mtx_fixed_point_pair(xPos,  zPos, &mtx->m[1][2]);
    set_mtx_fixed_point_pair(yPos, 0x10000, &mtx->m[1][3]);
}

void set_mtx_fixed_point_pair(s32 upper, s32 lower, s32 *mtxWord) {
    mtxWord[0] = (upper & 0xFFFF0000) | ((lower >> 16) & 0xFFFF);
    mtxWord[8] = (upper << 16) | (lower & 0xFFFF);
}

s32 func_80126388(u16 joint0, u16 joint1, s32 scaleX, s32 scaleZ, s32 scaleY, s16 centerScale, s16 roll, u8 mirror, u8 orientationMode, Mtx *mtx) {
    s32 sp6C, sp68, sp64;
    s32 sp60, sp5C, sp58;
    s32 sp54, sp50, sp4C;
    s32 sp48, sp44, sp40;
    s32 sp3C, sp38, sp34;
    s32 sp30, sp2C, sp28;

    FracIntHelper sp20;

    s32 temp_t7_3;
    s32 temp_t8_4;
    s32 new_var;

    sp30 = (((D_80203FE0[joint0].unk0 + D_80203FE0[joint1].unk0) >> 1) << 0x10) / 8;
    sp2C = (((D_80203FE0[joint0].unk2 + D_80203FE0[joint1].unk2) >> 1) << 0x10) / 8;
    sp28 = (((D_80203FE0[joint0].unk4 + D_80203FE0[joint1].unk4) >> 1) << 0x10) / 8;

    sp30 = ((centerScale * sp30) >> 4) + sp30;
    sp2C = ((centerScale * sp2C) >> 4) + sp2C;
    sp28 = ((centerScale * sp28) >> 3) + sp28;

    sp6C = D_80203FE0[joint1].unk0 - D_80203FE0[joint0].unk0;
    sp68 = D_80203FE0[joint1].unk2 - D_80203FE0[joint0].unk2;
    sp64 = D_80203FE0[joint1].unk4 - D_80203FE0[joint0].unk4;

    if ((sp6C == 0) && (sp68 == 0)) {

        if (orientationMode == 1) {
            sp60 = 0 << 0xA;
            sp5C = 1 << 0xA;
            sp58 = 0 << 0xA;

            sp54 = 1 << 0xA;
            sp50 = 0 << 0xA;
            sp4C = 0 << 0xA;
        } else {
            sp60 = 1 << 0xA;
            sp5C = 0 << 0xA;
            sp58 = 0 << 0xA;

            sp54 = 0;
            sp50 = -(1 << 0xA);
            sp4C = 0 << 0xA;
        }
    } else {
        sp60 = sp68;
        sp5C = -sp6C;
        sp58 = 0;

        if (orientationMode == 1) {
            if (sp5C < 0) {
                sp60 = -sp68;
                sp5C = -sp5C;
            }
        } else if (sp68 < 0) {
            sp60 = -sp68;
            sp5C = -sp5C;
        }

        sp54 = (sp5C * sp64) / -256;
        sp50 = (sp64 * sp60) / 256;
        sp4C = ((sp6C * sp5C) - (sp68 * sp60)) / 256;

        if ((sp54 == 0) && (sp50 == 0) && (sp4C == 0)) {
            if (sp54 == 0) {
                if ((sp5C * sp64) < 0) {
                    sp54 = 1;
                } else if ((sp5C * sp64) > 0) {
                    sp54 = -1;
                }
            }
            if (sp50 == 0) {
                if ((sp64 * sp60) < 0) {
                    sp50 = -1;
                } else if ((sp64 * sp60) > 0) {
                    sp50 = 1;
                }
            }
            if (sp4C == 0) {
                if (((sp6C * sp5C) - (sp68 * sp60)) < 0) {
                    sp4C = -1;
                } else if (((sp6C * sp5C) - (sp68 * sp60)) > 0) {
                    sp4C = 1;
                }
            }
        }
    }

    sp3C = (s16) sqrtf(SQ((f32) sp6C) + SQ((f32) sp68) + SQ((f32) sp64));
    sp38 = (s16) sqrtf(SQ((f32) sp60) + SQ((f32) sp5C) + SQ((f32) sp58));
    sp34 = (s16) sqrtf(SQ((f32) sp54) + SQ((f32) sp50) + SQ((f32) sp4C));

    if (sp3C == 0) {
        return 0;
    }
    if (sp38 == 0) {
        return 0;
    }
    if (sp34 == 0) {
        return 0;
    }

    sp6C = (sp6C * scaleX) / sp3C;
    sp68 = (sp68 * scaleZ) / sp3C;
    sp64 = (sp64 * scaleY) / sp3C;

    sp60 = (sp60 * scaleX) / sp38;
    sp5C = (sp5C * scaleZ) / sp38;
    sp58 = (sp58 * scaleY) / sp38;

    sp54 = (((scaleX >> 3) * sp54) / sp34) << 3;
    sp50 = (((scaleZ >> 3) * sp50) / sp34) << 3;
    sp4C = (((scaleY >> 3) * sp4C) / sp34) << 3;

    switch (mirror) {
    case 0:
        break;
    case 1:
        sp60 = -sp60;
        sp5C = -sp5C;
        sp58 = -sp58;
        break;
    case 2:
        sp54 = -sp54;
        sp50 = -sp50;
        sp4C = -sp4C;
        break;
    case 3:
        sp60 = -sp60;
        sp5C = -sp5C;
        sp58 = -sp58;

        sp54 = -sp54;
        sp50 = -sp50;
        sp4C = -sp4C;
        break;
    }

    if (roll != 0) {
        sp48 = sp60;
        sp44 = sp5C;
        sp40 = sp58;

        temp_t7_3 = SIN(roll) >> 7;
        new_var = temp_t8_4 = COS(roll) >> 7;

        sp60 = ((temp_t7_3 * sp54) + (sp60 * new_var)) >> 8;
        sp5C = ((temp_t7_3 * sp50) + (sp5C * new_var)) >> 8;
        sp58 = ((temp_t7_3 * sp4C) + (sp58 * new_var)) >> 8;

        sp54 = ((sp54 * new_var) - (temp_t7_3 * sp48)) >> 8;
        sp50 = ((sp50 * new_var) - (temp_t7_3 * sp44)) >> 8;
        sp4C = ((sp4C * new_var) - (temp_t7_3 * sp40)) >> 8;
    }

    sp20.w.unk4 = sp6C;
    sp20.w.unk0 = sp68;
    mtx->m[0][0] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    mtx->m[2][0] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp64;
    mtx->m[0][1] = (sp20.h.unk4 << 0x10);
    mtx->m[2][1] = (sp20.h.unk6 << 0x10);

    sp20.w.unk4 = sp60;
    sp20.w.unk0 = sp5C;
    mtx->m[0][2] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    mtx->m[2][2] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp58;
    mtx->m[0][3] = (sp20.h.unk4 << 0x10);
    mtx->m[2][3] = (sp20.h.unk6 << 0x10);

    sp20.w.unk4 = sp54;
    sp20.w.unk0 = sp50;
    mtx->m[1][0] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    mtx->m[3][0] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp4C;
    mtx->m[1][1] = (sp20.h.unk4 << 0x10);
    mtx->m[3][1] = (sp20.h.unk6 << 0x10);

    sp20.w.unk4 = sp30;
    sp20.w.unk0 = sp2C;
    mtx->m[1][2] = (sp20.h.unk4 << 0x10) | sp20.h.unk0;
    mtx->m[3][2] = (sp20.h.unk6 << 0x10) | sp20.h.unk2;

    sp20.w.unk4 = sp28;
    mtx->m[1][3] = (sp20.h.unk4 << 0x10) | 1;
    mtx->m[3][3] = (sp20.h.unk6 << 0x10);

    return 1;
}

void unused_80126CC4(s16 angle, Mtx *mtx) {
    FracIntHelper sp8;
    FracIntHelper sp0;

    s16 temp_a2;
    s16 temp_v0;

    temp_v0 = SINB(angle);
    temp_a2 = COSB(angle);

    sp8.h.unk4 = mtx->m[0][0] >> 0x10;
    sp8.h.unk6 = mtx->m[2][0] >> 0x10;
    sp8.h.unk0 = mtx->m[0][0];
    sp8.h.unk2 = mtx->m[2][0];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    mtx->m[0][0] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    mtx->m[2][0] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = mtx->m[0][2] >> 0x10;
    sp8.h.unk6 = mtx->m[2][2] >> 0x10;
    sp8.h.unk0 = mtx->m[0][2];
    sp8.h.unk2 = mtx->m[2][2];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    mtx->m[0][2] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    mtx->m[2][2] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = mtx->m[1][0] >> 0x10;
    sp8.h.unk6 = mtx->m[3][0] >> 0x10;
    sp8.h.unk0 = mtx->m[1][0];
    sp8.h.unk2 = mtx->m[3][0];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    mtx->m[1][0] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    mtx->m[3][0] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
    sp8.h.unk4 = mtx->m[1][2] >> 0x10;
    sp8.h.unk6 = mtx->m[3][2] >> 0x10;
    sp8.h.unk0 = mtx->m[1][2];
    sp8.h.unk2 = mtx->m[3][2];

    sp0.w.unk4 = ((temp_a2 * sp8.w.unk4) + (temp_v0 * sp8.w.unk0)) / 256;
    sp0.w.unk0 = ((temp_a2 * sp8.w.unk0) - (temp_v0 * sp8.w.unk4)) / 256;
    mtx->m[1][2] = (s32) ((sp0.h.unk4 << 0x10) | sp0.h.unk0);
    mtx->m[3][2] = (s32) ((sp0.h.unk6 << 0x10) | sp0.h.unk2);
}

s32 func_80126FD4(s32 startX, s32 startZ, s32 startY,
                  s32 endX,   s32 endZ,   s32 endY,
                  s32 lengthScale, s32 widthScale,
                  Mtx *mtx) {

    s32 sp74, sp70, sp6C;
    s32 sp68, sp64, sp60;
    s32 sp5C, sp58, sp54;
    s32 pad[3] UNUSED;
    s32 sp44, sp40, sp3C;
    s32 sp38, sp34, sp30;
    FracIntHelper sp28;

    sp38 = (startX + endX) >> 1;
    sp34 = (startZ + endZ) >> 1;
    sp30 = (startY + endY) >> 1;

    startX = startX >> 8;
    startZ = startZ >> 8;
    startY = startY >> 8;
    endX = endX >> 8;
    endZ = endZ >> 8;
    endY = endY >> 8;

    sp74 = endX - startX;
    sp70 = endZ - startZ;
    sp6C = endY - startY;

    if ((sp74 == 0) && (sp70 == 0)) {
        sp68 = 0x400;
        sp64 = 0;
        sp60 = 0;

        sp5C = 0;
        sp58 = -0x400;
        sp54 = 0;
    } else {
        sp68 = sp70;
        sp64 = -sp74;
        sp60 = 0;

        if (sp68 < 0) {
            sp68 = -sp68;
            sp64 = -(-sp74);
        }

        sp5C = (sp64 * sp6C) / -512;
        sp58 = (sp6C * sp68) / 512;
        sp54 = ((sp74 * sp64) - (sp70 * sp68)) / 512;


        if (sp5C == 0) {
            if ((sp64 * sp6C) < 0) {
                sp5C = 1;
            } else if ((sp64 * sp6C) > 0) {
                sp5C = -1;
            }
        }
        if (sp58 == 0) {
            if ((sp6C * sp68) < 0) {
                sp58 = -1;
            } else if ((sp6C * sp68) > 0) {
                sp58 = 1;
            }
        }
        if (sp54 == 0) {
            if (((sp74 * sp64) - (sp70 * sp68)) < 0) {
                sp54 = -1;
            } else if (((sp74 * sp64) - (sp70 * sp68)) > 0) {
                sp54 = 1;
            }
        }
    }

    sp44 = sqrtf(SQ((f32) sp74) + SQ((f32) sp70) + SQ((f32) sp6C));
    sp40 = sqrtf(SQ((f32) sp68) + SQ((f32) sp64) + SQ((f32) sp60));
    sp3C = sqrtf(SQ((f32) sp5C) + SQ((f32) sp58) + SQ((f32) sp54));

    if (sp44 == 0) {
        return 0;
    }
    if (sp40 == 0) {
        return 0;
    }
    if (sp3C == 0) {
        return 0;
    }

    sp74 = (sp74 * lengthScale) / sp44;
    sp70 = (sp70 * lengthScale) / sp44;
    sp6C = (sp6C * lengthScale) / sp44;

    sp68 = (sp68 * widthScale) / sp40;
    sp64 = (sp64 * widthScale) / sp40;
    sp60 = (sp60 * widthScale) / sp40;

    sp5C = (sp5C * widthScale) / sp3C;
    sp58 = (sp58 * widthScale) / sp3C;
    sp54 = (sp54 * widthScale) / sp3C;

    sp28.w.unk4 = sp74;
    sp28.w.unk0 = sp70;
    mtx->m[0][0] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    mtx->m[2][0] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp6C;
    mtx->m[0][1] = sp28.h.unk4 << 0x10;
    mtx->m[2][1] = sp28.h.unk6 << 0x10;

    sp28.w.unk4 = sp68;
    sp28.w.unk0 = sp64;
    mtx->m[0][2] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    mtx->m[2][2] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp60;
    mtx->m[0][3] = sp28.h.unk4 << 0x10;
    mtx->m[2][3] = sp28.h.unk6 << 0x10;

    sp28.w.unk4 = sp5C;
    sp28.w.unk0 = sp58;
    mtx->m[1][0] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    mtx->m[3][0] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp54;
    mtx->m[1][1] = (sp28.h.unk4 << 0x10);
    mtx->m[3][1] = (sp28.h.unk6 << 0x10);

    sp28.w.unk4 = sp38;
    sp28.w.unk0 = sp34;
    mtx->m[1][2] = (sp28.h.unk4 << 0x10) | sp28.h.unk0;
    mtx->m[3][2] = (sp28.h.unk6 << 0x10) | sp28.h.unk2;

    sp28.w.unk4 = sp30;
    mtx->m[1][3] = (sp28.h.unk4 << 0x10) | 1;
    mtx->m[3][3] = (sp28.h.unk6 << 0x10);

    return 1;
}

void func_80127640(Mtx *mtx, s32 xPos, s32 zPos, s32 yPos, s16 yRot, s32 xScale, s32 zScale, s32 yScale, s16 roll, s32 rollScale) {
    s64 sp58;
    s64 sp50;
    s64 sp48;
    s64 sp40;

    FracIntHelper sp38;

    sp58 = (s64)(SIN(yRot) >> 7) << 8;
    sp50 = (s64)(COS(yRot) >> 7) << 8;

    sp48 = (s64)(SIN((yRot + roll) & 0xFF) >> 7) << 8;
    sp40 = (s64)(COS((yRot + roll) & 0xFF) >> 7) << 8;

    sp38.w.unk4 = (sp50 * xScale) >> 16;
    sp38.w.unk0 = (sp58 * xScale) >> 16;

    mtx->m[0][0] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    mtx->m[2][0] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    mtx->m[0][1] = 0;
    mtx->m[2][1] = 0;

    sp38.w.unk4 = (-sp58 * zScale) >> 16;
    sp38.w.unk0 = (sp50 * zScale) >> 16;
    mtx->m[0][2] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    mtx->m[2][2] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;
    mtx->m[0][3] = 0;
    mtx->m[2][3] = 0;

    sp38.w.unk4 = (sp40 * rollScale) >> 16;
    sp38.w.unk0 = (sp48 * rollScale) >> 16;
    mtx->m[1][0] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    mtx->m[3][0] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    sp38.w.unk4 = yScale;
    mtx->m[1][1] = sp38.h.unk4 << 0x10;
    mtx->m[3][1] = sp38.h.unk6 << 0x10;

    sp38.w.unk4 = xPos;
    sp38.w.unk0 = zPos;
    mtx->m[1][2] = (sp38.h.unk4 << 0x10) | sp38.h.unk0;
    mtx->m[3][2] = (sp38.h.unk6 << 0x10) | sp38.h.unk2;

    sp38.w.unk4 = yPos;
    mtx->m[1][3] = (sp38.h.unk4 << 0x10) | 1;
    mtx->m[3][3] = sp38.h.unk6 << 0x10;
}

s32 func_80127994(s32 vec0_x, s32 vec0_y, s32 vec0_z, Mtx *mtx) {
    s32 magnitude;
    s32 vec1_x, vec1_y, vec1_z;
    s32 vec2_x, vec2_y, vec2_z;
    FracIntHelper sp24;

    magnitude = sqrtf(SQ((f32)vec0_x) + SQ((f32)vec0_y) + SQ((f32)vec0_z));
    if (magnitude == 0) {
        vec0_x = vec0_y = (0 << 0xA);
        vec0_z = (1 << 0xA);
    } else {
        vec0_x = (vec0_x << 0xA) / magnitude;
        vec0_y = (vec0_y << 0xA) / magnitude;
        vec0_z = (vec0_z << 0xA) / magnitude;
    }
    magnitude = sqrtf(SQ((f32)vec0_z) + SQ((f32)-vec0_x));

#ifdef __sgi
    if (1) { } if (1) { }
#endif

    // vec1 lies in the XZ plane and is perpendicular to vec0
    vec1_x = ( vec0_z << 0xA) / magnitude;
    vec1_y = (      0 << 0xA) / magnitude;
    vec1_z = (-vec0_x << 0xA) / magnitude;

    magnitude = vec1_z; // pointless but required.

    // vec2 is dot product of vec0 and vec1, so vec0, vec1 and vec2 form an orthogonal basis
    vec2_x = -((vec1_y * vec0_z) - (vec1_z * vec0_y)) >> 10;
    vec2_y = -((vec1_z * vec0_x) - (vec1_x * vec0_z)) >> 10;
    vec2_z = -((vec1_x * vec0_y) - (vec1_y * vec0_x)) >> 10;

    sp24.w.unk4 = vec1_x << 6;
    sp24.w.unk0 = vec1_y << 6;
    mtx->m[0][0] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    mtx->m[2][0] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    sp24.w.unk4 = vec1_z << 6;
    mtx->m[0][1] = sp24.h.unk4 << 0x10;
    mtx->m[2][1] = sp24.h.unk6 << 0x10;

    sp24.w.unk4 = vec2_x << 6;
    sp24.w.unk0 = vec2_y << 6;
    mtx->m[0][2] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    mtx->m[2][2] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    sp24.w.unk4 = vec2_z << 6;
    mtx->m[0][3] = sp24.h.unk4 << 0x10;
    mtx->m[2][3] = sp24.h.unk6 << 0x10;

    sp24.w.unk4 = vec0_x << 6;
    sp24.w.unk0 = vec0_y << 6;
    mtx->m[1][0] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    mtx->m[3][0] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    sp24.w.unk4 = vec0_z << 6;
    mtx->m[1][1] = sp24.h.unk4 << 0x10;
    mtx->m[3][1] = sp24.h.unk6 << 0x10;

    mtx->m[1][2] = 0;
    mtx->m[3][2] = 0;

    sp24.w.unk4 = 0;
    sp24.w.unk0 = FTOFIX32(1.0);
    mtx->m[1][3] = (sp24.h.unk4 << 0x10) | sp24.h.unk0;
    mtx->m[3][3] = (sp24.h.unk6 << 0x10) | sp24.h.unk2;

    return 1;
}

void build_ship_window_z_projection_matrix(Mtx *mtx, s16 zOffset) {
    FracIntHelper sp0;
    u32 *intPart =  (u32*)&mtx->m[0][0];
    u32 *fracPart = (u32*)&mtx->m[2][0];

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(1.0);
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(-1.0);
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = zOffset << 17;
    *intPart++ =  (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;
}

void build_ship_window_x_projection_matrix(Mtx *mtx, s16 xOffset) {
    FracIntHelper sp0;
    s32 *intPart = (s32*)&mtx->m[0][0];
    s32 *fracPart = (s32*)&mtx->m[2][0];

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(-1.0);
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = 0;
    sp0.w.unk4 = FTOFIX32(1.0);
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk4 = xOffset << 17;
    sp0.w.unk0 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;

    sp0.w.unk0 = FTOFIX32(1.0);
    sp0.w.unk4 = 0;
    *intPart++ = (sp0.h.unk4 << 0x10) | sp0.h.unk0;
    *fracPart++ = (sp0.h.unk6 << 0x10) | sp0.h.unk2;
}

void build_spring_bounce_matrix(Mtx *mtx, s16 radius, s16 angle) {
    s64 sp40;
    s64 sp38;

    FracIntHelper sp30;

    sp40 = (s64)SINB(angle) << 8;
    sp38 = (s64)COSB(angle) << 8;

    sp30.w.unk4 = 0x10000;

    mtx->m[0][0] = sp30.h.unk4 << 0x10;
    mtx->m[2][0] = sp30.h.unk6 << 0x10;

    mtx->m[0][1] = 0;
    mtx->m[2][1] = 0;

    sp30.w.unk0 = sp38;
    mtx->m[0][2] = sp30.h.unk0;
    mtx->m[2][2] = sp30.h.unk2;

    sp30.w.unk4 = sp40;
    mtx->m[0][3] = sp30.h.unk4 << 0x10;
    mtx->m[2][3] = sp30.h.unk6 << 0x10;

    sp30.w.unk0 = -sp40;
    mtx->m[1][0] = sp30.h.unk0;
    mtx->m[3][0] = sp30.h.unk2;

    sp30.w.unk4 = sp38;
    mtx->m[1][1] = sp30.h.unk4 << 0x10;
    mtx->m[3][1] = sp30.h.unk6 << 0x10;

    sp30.w.unk0 = radius * sp40;
    mtx->m[1][2] = sp30.h.unk0;
    mtx->m[3][2] = sp30.h.unk2;

    sp30.w.unk4 = (radius << 0x10) - (radius * sp38);
    mtx->m[1][3] = (sp30.h.unk4 << 0x10) | 1;
    mtx->m[3][3] = sp30.h.unk6 << 0x10;
}
