#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C4A70_6D6120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C56D0_6D6D80.s")
#if 0
// bleurgh
void func_802C56D0_6D6D80(u8 arg0) {
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_a3;
    s16 temp_t1;
    s16 temp_t4;
    s16 temp_t4_2;
    s16 temp_t7_2;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t7;
    s32 temp_t8;

    temp_v1 = D_80203FE0[19].unk4;
    temp_a3 = D_80203FE0[1].unk4;
    temp_t8 = D_80152C78[arg0] >> 7;
    temp_t0 = D_80203FE0[19].unk4 - temp_a3;
    temp_v0 = D_80203FE0[19].unk2;
    temp_t1 = D_80203FE0[1].unk2;
    temp_t7 = D_80152C78[arg0 + 64] >> 7;
    temp_t2 = temp_v0 - temp_t1;
    temp_a1 = ((s32) ((temp_t8 * temp_t0) + (temp_t2 * temp_t7)) >> 8) + temp_t1;
    D_80203FE0[19].unk2 = temp_a1;
    temp_t4 = ((s32) ((temp_t0 * temp_t7) - (temp_t8 * temp_t2)) >> 8) + temp_a3;
    temp_v1_2 = D_80203FE0[32].unk4;
    temp_v0_2 = D_80203FE0[32].unk2;
    D_80203FE0[20].unk2 = (s16) ((D_80203FE0[20].unk2 + temp_a1) - temp_v0);
    temp_t0_2 = temp_v1_2 - temp_a3;
    temp_t2_2 = temp_v0_2 - temp_t1;
    D_80203FE0[20].unk4 = (s16) ((D_80203FE0[20].unk4 + temp_t4) - D_80203FE0[19].unk4);
    D_80203FE0[19].unk4 = temp_t4;
    temp_a1_2 = ((s32) ((temp_t8 * temp_t0_2) + (temp_t2_2 * temp_t7)) >> 8) + temp_t1;
    D_80203FE0[32].unk2 = temp_a1_2;
    temp_t4_2 = ((s32) ((temp_t0_2 * temp_t7) - (temp_t8 * temp_t2_2)) >> 8) + temp_a3;
    temp_t7_2 = (D_80203FE0[33].unk4 + temp_t4_2) - temp_v1_2;
    D_80203FE0[32].unk4 = temp_t4_2;
    D_80203FE0[33].unk2 = (s16) ((D_80203FE0[33].unk2 + temp_a1_2) - temp_v0_2);
    D_80203FE0[33].unk4 = temp_t7_2;
}
#endif

void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;

    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + (D_80152350.unk2D0[arg2] * arg0 / 256);
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (D_80152350.unk384[arg2] * arg0 / 256);

    D_80203FE0[20].unk0 = D_80203FE0[19].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C58E4_6D6F94.s")
#if 0
void func_802C58E4_6D6F94(s16 arg0, s16 arg1) {
    s16 sp0;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_a1;
    s16 temp_t0_2;
    s16 temp_t4_2;
    s16 temp_t5;
    s16 var_a0;
    s16 var_a3_2;
    s16 var_t0;
    s16 var_t2;
    s16 var_v0;
    s16 var_v1;
    u16 temp_t0;
    s32 temp_t4;
    s32 temp_t6;
    u16 temp_v0;
    u16 var_t1;

    struct113 *tmp;

    tmp = &D_803D5528->unk3C0;

    temp_t0 = ((s32) D_803D552C->unk2F6 % 256);// & 0xFFFF;
    if (D_803D5528->unk3C0.unk0 != NULL) {
        tmp->unk2++; // = (s16) (D_803D5528->unk3C0.unk2+ 1);
    }
    switch (tmp->unk0) {                               /* irregular */
    case 1:
        if (tmp->unk2 >= 0x64) {
            tmp->unk0 = 0U;
        }
        break;
    case 5:
        if (tmp->unk2 >= 0x96) {
            tmp->unk0 = 0U;
        }
        break;
    }

    var_a0 = ((s16) ((D_803D5530->yRotation - D_803D552C->unk302) & 0xFF) * 360) >> 8;

    if ((var_a0 > 80) && (var_a0 < 280)) {
        if (var_a0 < 180) {
            var_a0 = 80;
        } else {
            var_a0 = 280;
        }
    }
    if (var_a0 > 180) {
        var_a0 -= 360;
    }

    switch (D_803D5530->state) {                        /* switch 1; irregular */
    case 0x3:                                       /* switch 1 */
    case 0x16:                                      /* switch 1 */
    case 0x3E:                                      /* switch 1 */
    case 0x68:                                      /* switch 1 */
    case 0xB6:                                      /* switch 1 */
    case 0xCA:                                      /* switch 1 */
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 80) + 90;
        var_v0 = var_a0;
        break;
    case 0x4:                                       /* switch 1 */
    case 0x17:                                      /* switch 1 */
    case 0x51:                                      /* switch 1 */
    case 0x69:                                      /* switch 1 */
    case 0xB7:                                      /* switch 1 */
    case 0xCB:                                      /* switch 1 */
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 40) + 90;
        var_v0 = var_a0;
        break;
    case 0x8D:                                      /* switch 1 */
        var_v1 = 90;
        var_v0 = var_a0;
        break;
    case 0x8E:                                      /* switch 1 */
    case 0x8F:                                      /* switch 1 */
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 60) + 90;
        var_v0 = var_a0;
        break;
    default:                                        /* switch 1 */
        if (tmp->unk0 != 1) {
            var_v1 = 90;
            if (tmp->unk0 != 5) {
                tmp->unk0 = 0U;
                var_v0 = var_a0;
            } else {
                if (tmp->unk2 < 37) {
                    var_v0 = 21 - ((D_80152350.unk384[(s16) ((tmp->unk2 * 360) / 75)]) / 18);
                }
                if ((tmp->unk2 >= 37) && (tmp->unk2 < 112)) {
                    var_v0 = (s16) ((D_80152350.unk2D0[(s16) ((tmp->unk2 * 360) / 150)]) / 6);
                }
                if (tmp->unk2 >= 112) {
                    var_v0 = ((D_80152350.unk384[(s16) ((tmp->unk2 * 360) / 75)]) / 12) - 21;
                }
            }
        } else {
            var_v0 = 0;
            var_v1 = 0x68 - ((D_80152350.unk384[((s16) ((tmp->unk2 * 360) / 100))]) / 18);
        }
        break;
    }

    if (D_803D552C->unk366 == 4) {
        var_v1 = 100;
        var_v0 = 0;
    }

    // temp_a1 = D_80203FE0[1].unk4;
    temp_t4 = (D_80203FE0[1].unk4 - D_80203FE0[2].unk4) * 3;
    // temp_a0_2 = D_80203FE0[2].unk0;
    temp_t4_2 = (D_80203FE0[1].unk2 + arg0) - (temp_t4 >> 2);
    temp_t5 = (temp_t4 >> 3) + D_80203FE0[1].unk4;
    D_80203FE0[19].unk2 = temp_t4_2;
    D_80203FE0[19].unk4 = temp_t5;
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[32].unk2 = temp_t4_2;
    D_80203FE0[32].unk4 = temp_t5;

    var_a3_2 = D_80203FE0[19].unk0;
    temp_t0_2 = D_80203FE0[19].unk2;
    var_t2 = D_80203FE0[19].unk4;
    D_80203FE0[32].unk0 = D_80203FE0[2].unk0;

    if (var_v0 != 0) {
        var_t0 = temp_t0_2 + ((arg1 * D_80152350.unk384[var_v0]) / 256);
        var_a3_2 += (arg1 * D_80152350.unk2D0[var_v0]) / 256;
    } else {
        var_t0 = temp_t0_2 + ((arg1 * D_80152350.unk2D0[var_v1]) / 256);
        var_t2 += (arg1 * D_80152350.unk384[var_v1]) / 256;
    }
    D_80203FE0[20].unk0 = var_a3_2;
    D_80203FE0[20].unk2 = var_t0;
    D_80203FE0[20].unk4 = var_t2;
    D_80203FE0[33].unk0 = var_a3_2;
    D_80203FE0[33].unk2 = D_80203FE0[32].unk2 + arg1;
    D_80203FE0[33].unk4 = D_80203FE0[32].unk4;
}
#endif

#ifdef NON_MATCHING_TODO // JUSTREG?
void func_802C5EF4_6D75A4(s16 arg0, s16 arg1) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[19].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + arg0;

    D_80203FE0[20].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[1].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[1].unk4 + arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5EF4_6D75A4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5F34_6D75E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6468_6D7B18.s")
// used by mouse
// void func_802C6468_6D7B18(s16 arg0, s16 arg1, s16 arg2) {
//     s16 tmp0 = D_80203FE0[1].unk0;
//     s16 tmp1 = D_80203FE0[1].unk2;
//     s16 tmp2 = D_80203FE0[1].unk4;
//
//     D_80203FE0[19].unk0 = tmp0;
//     D_80203FE0[19].unk2 = tmp1;
//     D_80203FE0[19].unk4 = tmp2 + arg0;
//
//     D_80203FE0[20].unk0 = tmp0;
//     D_80203FE0[20].unk2 = tmp1 + arg1;
//     D_80203FE0[20].unk4 = tmp2 + arg0;
//
//     D_80203FE0[22].unk0 = tmp0 - (arg2 >> 1);
//     D_80203FE0[22].unk2 = tmp1 + arg1 - arg1;
//     D_80203FE0[22].unk4 = tmp2 + arg0 + (arg2 >> 1);
//
//     D_80203FE0[23].unk0 = tmp0 + (arg2 >> 1);
//     D_80203FE0[23].unk2 = tmp1 + arg1 - arg1;
//     D_80203FE0[23].unk4 = tmp2 + arg0 + (arg2 >> 1);
// }

void func_802C64E0_6D7B90(s16 arg0) {
    s16 tmp0 = D_80203FE0[2].unk0;
    s16 tmp1 = D_80203FE0[2].unk2;
    s16 tmp2 = D_80203FE0[2].unk4;

    D_80203FE0[22].unk0 = tmp0 - (arg0 >> 1);
    D_80203FE0[22].unk2 = tmp1;
    D_80203FE0[22].unk4 = tmp2 + (arg0 >> 1);

    D_80203FE0[23].unk0 = tmp0 + (arg0 >> 1);
    D_80203FE0[23].unk2 = tmp1;
    D_80203FE0[23].unk4 = tmp2 + (arg0 >> 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C652C_6D7BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6C00_6D82B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6FF4_6D86A4.s")

void func_802C71BC_6D886C(s16 *arg0, s16 *arg1, s16 *arg2, s16 arg3) {
    *arg0 = D_803D5530->xPos.h + ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * (D_80203FE0[20].unk0 + 0   )) / 32) + ((D_80152C78[(D_803D552C->unk302 + 0) & 0xFF] * (D_80203FE0[20].unk2 + arg3)) / 32)) >> 0xF);
    *arg1 = D_803D5530->zPos.h + ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * (D_80203FE0[20].unk2 + arg3)) / 32) - ((D_80152C78[(D_803D552C->unk302 + 0) & 0xFF] * (D_80203FE0[20].unk0 + 0   )) / 32)) >> 0xF);
    *arg2 = D_803D5530->yPos.h + (D_80203FE0[19].unk4 / 32);
}

void func_802C7310_6D89C0(void) {
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_s4;
    s16 sp68;
    s16 sp66;
    s16 sp64;
    s16 i;


    temp_s2 = D_803D5530->xPos.h;
    temp_s3 = D_803D5530->zPos.h;
    temp_s4 = (D_80203FE0[0].unk4 / 32) + D_803D5530->yPos.h;

    func_802C56D0_6D6D80(-D_803D552C->unk318 * 3);
    func_802C71BC_6D886C(&sp68, &sp66, &sp64, 0);

    i = 0;
    if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, temp_s2, temp_s3, temp_s4, D_803D5530->unk160, 0, 0)) {
        while ((D_803D552C->unk318 < 0x1C) && (i < 4)) {
            func_802C56D0_6D6D80(-3);
            func_802C71BC_6D886C(&sp68, &sp66, &sp64, 0);

            if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, temp_s2, temp_s3, temp_s4, D_803D5530->unk160, 0, 0)) {
                D_803D552C->unk318++;
                i++;
            } else {
                func_802C56D0_6D6D80(3);
                break;
            }
        }
    } else {
        while ((D_803D552C->unk318 > 0) && (i < 4)) {
            func_802C56D0_6D6D80(3);
            func_802C71BC_6D886C(&sp68, &sp66, &sp64, 0);
            if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, temp_s2, temp_s3, temp_s4, D_803D5530->unk160, 0, 0)) {
                func_802C56D0_6D6D80(-3);
                break;
            } else {
                D_803D552C->unk318--;
                i++;
            }
        }
    }
}

void func_802C75A4_6D8C54(s16 arg0) {
    D_80203FE0[19].unk2 -= arg0 * 90;
    D_80203FE0[19].unk4 += arg0 * 90;
    D_80203FE0[20].unk2 -= arg0 * 90;
    D_80203FE0[20].unk4 += arg0 * 90;
}

void func_802C7600_6D8CB0(s16 arg0, s16 arg1) {
    s16 i;
    s16 xPos;
    s16 zPos;
    s16 sp68;
    s16 sp66;
    s16 sp64;
    s16 yPos;

    xPos = D_803D5530->xPos.h;
    zPos = D_803D5530->zPos.h;
    yPos = (D_80203FE0[0].unk4 / 32) + D_803D5530->yPos.h;

    func_802C75A4_6D8C54(D_803D552C->unk318);
    func_802C71BC_6D886C(&sp68, &sp66, &sp64, arg0);

    i = 0;
    if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, xPos, zPos, yPos, D_803D5530->unk160, 0, 0)) {
        while ((D_803D552C->unk318 < arg1) && (i < 4)) {
            func_802C75A4_6D8C54(1);
            func_802C71BC_6D886C(&sp68, &sp66, &sp64, arg0);

            if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, xPos, zPos, yPos, D_803D5530->unk160, 0, 0)) {
                D_803D552C->unk318++;
                i++;
            } else {
                func_802C56D0_6D6D80(3);
                return;
            }
        }
    } else {
        while ((D_803D552C->unk318 > 0) && (i < 4)) {
            func_802C75A4_6D8C54(-1);
            func_802C71BC_6D886C(&sp68, &sp66, &sp64, arg0);

            if (func_8033C9CC_74E07C(sp68, sp66, sp64, 0x7F, xPos, zPos, yPos, D_803D5530->unk160, 0, 0)) {
                func_802C56D0_6D6D80(-3);
                return;
            } else {
                D_803D552C->unk318--;
                i++;
            }
        }
    }
}

void func_802C78B0_6D8F60(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Gfx *dl) {
    if (func_80126388(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        D_80204278->usedModelViewMtxs += 1;
        gSPDisplayList(D_801D9E88++, dl);
        gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
    }
}

void func_802C79E0_6D9090(struct061 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk2;
    s16 temp_v1 = arg0->unk4;

    arg0->unk2 = ((temp_v0 * D_80152350.unk384[arg1]) + (D_80152350.unk2D0[arg1] * temp_v1)) / 256;
    arg0->unk4 = ((temp_v1 * D_80152350.unk384[arg1]) - (D_80152350.unk2D0[arg1] * temp_v0)) / 256;
}

void func_802C7A7C_6D912C(struct061 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk0;
    s16 temp_v1 = arg0->unk4;

    arg0->unk0 = ((temp_v0 * D_80152350.unk384[arg1]) + (D_80152350.unk2D0[arg1] * temp_v1)) / 256;
    arg0->unk4 = ((temp_v1 * D_80152350.unk384[arg1]) - (D_80152350.unk2D0[arg1] * temp_v0)) / 256;
}

void func_802C7B18_6D91C8(struct061 *arg0, s16 arg1) {
    s16 temp_v0 = arg0->unk0;
    s16 temp_v1 = arg0->unk2;

    arg0->unk0 = ((temp_v0 * D_80152350.unk384[arg1]) + (temp_v1 * D_80152350.unk2D0[arg1])) / 256;
    arg0->unk2 = ((temp_v1 * D_80152350.unk384[arg1]) - (temp_v0 * D_80152350.unk2D0[arg1])) / 256;
}

void func_802C7BB4_6D9264(u16 arg0) {
    D_803D5528->unk370.unkA = D_803D5528->unk370.unk4;
    D_803D5528->unk370.unkC = D_803D5528->unk370.unk6;
    D_803D5528->unk370.unkE = D_803D5528->unk370.unk8;

    D_803D5528->unk384.unkA = D_803D5528->unk384.unk4;
    D_803D5528->unk384.unkC = D_803D5528->unk384.unk6;
    D_803D5528->unk384.unkE = D_803D5528->unk384.unk8;

    D_803D5528->unk398.unkA = D_803D5528->unk398.unk4;
    D_803D5528->unk398.unkC = D_803D5528->unk398.unk6;
    D_803D5528->unk398.unkE = D_803D5528->unk398.unk8;

    D_803D5528->unk3AC.unkA = D_803D5528->unk3AC.unk4;
    D_803D5528->unk3AC.unkC = D_803D5528->unk3AC.unk6;
    D_803D5528->unk3AC.unkE = D_803D5528->unk3AC.unk8;

    D_803D552C->unk2FE = D_803D552C->unk2F2;
    D_803D552C->unk300 = arg0;
}
