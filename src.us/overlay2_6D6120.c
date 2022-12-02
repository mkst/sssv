#include <ultra64.h>
#include "common.h"


#if 0
void func_802C4A70_6D6120(s16 arg0, s16 arg1, u8 arg2) {
    s16 temp_t7_2;
    s16 temp_t9;
    s16 temp_v0;
    s16 var_a0;
    s16 var_t1; // sp46?
    s16 var_a0_2;
    s16 var_a1_2;
    s16 var_t2;
    s16 var_t3;
    u16 var_t0;

    struct113 *temp_t0_2;
    u16 temp_t4;

    temp_t4 = (D_803D552C->unk2F6 % 256);

    temp_t0_2 = &D_803D5528->unk3C0;
    if (temp_t0_2->unk0 != 0) {
        temp_t0_2->unk2 += 1;
    }
    switch (temp_t0_2->unk0) {                               /* switch 1 */
    case 1:                                         /* switch 1 */
        if (temp_t0_2->unk2 >= 100) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 18:                                        /* switch 1 */
        if (temp_t0_2->unk2 >= 50) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 5:                                         /* switch 1 */
        if (temp_t0_2->unk2 >= 150) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 19:                                        /* switch 1 */
        if (temp_t0_2->unk2 >= 75) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 15:                                        /* switch 1 */
        if (temp_t0_2->unk2 >= 10) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 16:                                        /* switch 1 */
        if (temp_t0_2->unk2 >= 28) {
            temp_t0_2->unk0 = 0;
        }
        break;
    case 17:                                        /* switch 1 */
        if (temp_t0_2->unk2 >= 60) {
            temp_t0_2->unk0 = 0;
        }
        if (temp_t0_2->unk2 == 5) {
            play_sound_effect_at_location(SFX_UNKNOWN_34, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
        break;
    default:                                        /* switch 1 */
        temp_t0_2->unk0 = 0;
        break;
    }
    var_a0 = (D_803D5530->yRotation - D_803D552C->unk302) & 0xFF;
    var_a0 = (var_a0 * 360) >> 8;
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

    switch (D_803D5530->state) {                        /* switch 4; irregular */
    case 0x3:                                       /* switch 4 */
    case 0x16:                                      /* switch 4 */
    case 0x3E:                                      /* switch 4 */
    case 0x68:                                      /* switch 4 */
    case 0xB6:                                      /* switch 4 */
    case 0xCA:                                      /* switch 4 */
        var_t2 = (D_80152350.unk2D0[(s16) ((temp_t4 * 360) / 256)] / 25) + 20;
        var_t3 = 0x5A;
        var_t1 = var_a0;
        break;
    case 0x4:                                       /* switch 4 */
    case 0x17:                                      /* switch 4 */
    case 0x51:                                      /* switch 4 */
    case 0x69:                                      /* switch 4 */
    case 0xB7:                                      /* switch 4 */
    case 0xCB:                                      /* switch 4 */
        var_t2 = MAX(1, (D_80152350.unk2D0[(s16) ((temp_t4 * 360) / 256)] / 10) + 20);
        var_t3 = 0x5A;
        var_t1 = var_a0;
        break;
    case 0x8D:                                      /* switch 4 */
        var_t2 = 0xA;
        var_t3 = 0x5A;
        var_t1 = var_a0;
        break;
    case 0x8E:                                      /* switch 4 */
    case 0x8F:                                      /* switch 4 */
        var_t2 = MAX(1, (D_80152350.unk2D0[(s16) ((temp_t4 * 360) / 256)] / 20) + 10);
        var_t3 = 0x5A;
        var_t1 = var_a0;
        break;
    default:                                        /* switch 4 */
        switch (temp_t0_2->unk0) {                  /* switch 2 */
        case 1:                                     /* switch 2 */
            var_t2 = 0x34 - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 100)] / 8);
            var_t3 = 0x85 - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 100)] / 6);
            var_t1 = 0;
            break;
        case 18:                                    /* switch 2 */
            var_t2 = 0x34 - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 50)] / 8);
            var_t3 = 0x85 - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 50)] / 6);
            var_t1 = 0;
            break;
        case 15:                                    /* switch 2 */
            var_t2 = 0x14;
            var_t3 = 0x5A;
            var_t1 = (-temp_t0_2->unk2 * 12) + 0x78;
            break;
        case 5:                                     /* switch 2 */
            var_t2 = (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 150)] / 26) + 10;
            var_t3 = 0x5A;
            if (temp_t0_2->unk2 < 37) {
                var_t1 = 0x2A - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 75)] / 6);
            }
            if ((temp_t0_2->unk2 >= 37) && (temp_t0_2->unk2 < 112)) {
                var_t1 = (D_80152350.unk2D0[(s16) ((temp_t0_2->unk2 * 360) / 150)] / 3);
            }
            if (temp_t0_2->unk2 >= 112) {
                var_t1 = (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 75)] / 6) - 42;
            }
            break;
        case 19:                                    /* switch 2 */
            var_t2 = (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 75)] / 26) + 10;
            var_t3 = 0x5A;
            if (temp_t0_2->unk2 < 18) {
                var_t1 = 0x2A - (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 37)] / 6);
            }
            if ((temp_t0_2->unk2 >= 18) && (temp_t0_2->unk2 < 56)) {
                var_t1 = (D_80152350.unk2D0[(s16) ((temp_t0_2->unk2 * 360) / 75)] / 3);
            }
            if (temp_t0_2->unk2 >= 56) {
                var_t1 = (D_80152350.unk384[(s16) ((temp_t0_2->unk2 * 360) / 37)] / 6) - 42;
            }
            break;
        case 16:                                    /* switch 2 */
            var_t2 = 0x14;
            var_t3 = 0x5A;
            var_t1 = var_a0;
            break;
        case 17:                                    /* switch 2 */
            var_t2 = 0x14;
            var_t3 = 0x5A;
            var_t1 = (D_80152C78[(s16)(temp_t0_2->unk2 << 6) & 0xFF] >> 7) >> 2;
            break;
        default:                                    /* switch 2 */
            temp_t0_2->unk0 = 0;
            var_t2 = 0x14;
            var_t3 = 0x5A;
            var_t1 = var_a0;
            break;
        }
        break;
    }

    switch (D_803D552C->unk364) {
    case 0:
        break;
    case 8:
        var_t0 = (D_803D5544 - D_803D552C->unk334);
        if (var_t0 == 5) {
            play_sound_effect_at_location(SFX_UNKNOWN_34, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
        if (var_t0 > 10) {
            var_t1 = D_80152C78[(s16)((var_t0 - 0xA) << 5) & 0xFF] >> 9;
        }
        break;
    }

    if (D_803D552C->unk366 == 4) {
        var_t2 = 0x55;
        var_t3 = 0xAA;
        var_t1 = 0;
    }

    switch (arg2) {                                 /* switch 3 */
    case 0:
        break;
    case 1:                                         /* switch 3 */
        var_t1 = var_t1 >> 1;
        break;
    case 2:                                         /* switch 3 */
        var_t1 = 0;
        break;
    case 3:                                         /* switch 3 */
        var_t2 = ((var_t2 - 0x14) >> 1) + 0x14;
        var_t3 = ((var_t3 - 0x5A) >> 1) + 0x5A;
        break;
    case 4:                                         /* switch 3 */
        var_t2 = ((var_t2 - 0x14) >> 1) + 0x14;
        var_t3 = ((var_t3 - 0x5A) >> 1) + 0x5A;
        var_t1 = var_t1 >> 1;
        break;
    case 5:                                         /* switch 3 */
        var_t2 = ((var_t2 - 0x14) >> 1) + 0x14;
        var_t3 = ((var_t3 - 0x5A) >> 1) + 0x5A;
        var_t1 = 0;
        break;
    case 6:                                         /* switch 3 */
        var_t2 = 0;
        var_t3 = 0x5A;
        break;
    case 7:                                         /* switch 3 */
        var_t2 = 0;
        var_t3 = 0x5A;
        var_t1 = var_t1 >> 1;
        break;
    case 8:                                         /* switch 3 */
        var_t2 = 0;
        var_t3 = 0x5A;
        var_t1 = 0;
        break;
    }

    // this section is complete junk

    var_a1_2 = D_80203FE0[1].unk0;
    temp_v0 = D_80203FE0[1].unk2 + ((arg0 * D_80152350.unk2D0[var_t2]) / 256);
    var_a0_2 = D_80203FE0[1].unk4 + ((arg0 * D_80152350.unk384[var_t2]) / 256);

    D_80203FE0[19].unk0 = var_a1_2;
    D_80203FE0[19].unk2 = temp_v0;
    D_80203FE0[19].unk4 = var_a0_2;

    if (var_t1 != 0) {
        var_a1_2 += (arg1 * D_80152350.unk2D0[var_t1]) / 256;
        temp_v0 += (arg1 * D_80152350.unk384[var_t1]) / 256;
    } else {
        var_a0_2 += (arg1 * D_80152350.unk384[var_t3]) / 256;
        temp_v0 += (arg1 * D_80152350.unk2D0[var_t3]) / 256;
    }

    D_80203FE0[20].unk0 = var_a1_2;
    D_80203FE0[20].unk2 = temp_v0;
    D_80203FE0[20].unk4 = var_a0_2;

    temp_t9 = D_80203FE0[1].unk2 + ((arg0 * D_80152350.unk2D0[20]) / 256);
    temp_t7_2 = D_80203FE0[1].unk4 + ((arg0 * D_80152350.unk384[20]) / 256);

    D_80203FE0[32].unk0 = var_a1_2;
    D_80203FE0[32].unk2 = temp_t9;
    D_80203FE0[32].unk4 = temp_t7_2;

    D_80203FE0[33].unk0 = var_a1_2;
    D_80203FE0[33].unk2 = temp_t9 + arg1;
    D_80203FE0[33].unk4 = temp_t7_2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C4A70_6D6120.s")
#endif

#if 0
// bleurgh
void func_802C56D0_6D6D80(s16 arg0) {
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
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C56D0_6D6D80.s")
#endif

void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;

    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + (D_80152350.unk2D0[arg2] * arg0 / 256);
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (D_80152350.unk384[arg2] * arg0 / 256);

    D_80203FE0[20].unk0 = D_80203FE0[19].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
}

void func_802C58E4_6D6F94(s16 arg0, s16 arg1) {
    struct113 *tmp;
    s16 var_v1;
    s16 var_v0; // sp0?
    s16 var_a3;
    u16 temp_t0;
    s16 var_t0;
    s16 var_a0;
    s16 var_t2;

    temp_t0 = D_803D552C->unk2F6 % 256;

    tmp = &D_803D5528->unk3C0;
    if (tmp->unk0 != 0) {
        tmp->unk2++;
    }
    switch (tmp->unk0) {
    case 1:
        if (tmp->unk2 >= 100) {
            tmp->unk0 = 0;
        }
        break;
    case 5:
        if (tmp->unk2 >= 150) {
            tmp->unk0 = 0;
        }
        break;
    }

    var_a0 = (D_803D5530->yRotation - D_803D552C->unk302) & 0xFF;
    var_a0 = (var_a0 * 360) >> 8;

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

    switch (D_803D5530->state) {
    case 0x3:
    case 0x16:
    case 0x3E:
    case 0x68:
    case 0xB6:
    case 0xCA:
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 80) + 90;
        var_v0 = var_a0;
        break;
    case 0x4:
    case 0x17:
    case 0x51:
    case 0x69:
    case 0xB7:
    case 0xCB:
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 40) + 90;
        var_v0 = var_a0;
        break;
    case 0x8D:
        var_v1 = 90;
        var_v0 = var_a0;
        break;
    case 0x8E:
    case 0x8F:
        var_v1 = (D_80152350.unk2D0[(s16) ((temp_t0 * 360) / 256)] / 60) + 90;
        var_v0 = var_a0;
        break;
    default:
        switch (tmp->unk0) {
        case 1:
            var_v0 = 0;
            var_v1 = 104 - ((D_80152350.unk384[((s16) ((tmp->unk2 * 360) / 100))]) / 18);
            break;
        case 5:
            var_v1 = 90;
            if (tmp->unk2 < 37) {
                var_v0 = 21 - ((D_80152350.unk384[(s16) ((tmp->unk2 * 360) / 75)]) / 12);
            }
            if ((tmp->unk2 >= 37) && (tmp->unk2 < 112)) {
                var_v0 = ((D_80152350.unk2D0[(s16) ((tmp->unk2 * 360) / 150)]) / 6);
            }
            if (tmp->unk2 >= 112) {
                var_v0 = ((D_80152350.unk384[(s16) ((tmp->unk2 * 360) / 75)]) / 12) - 21;
            }
            break;
        default:
            tmp->unk0 = 0;
            var_v1 = 90;
            var_v0 = var_a0;
            break;
        }
        break;
    }

    if (D_803D552C->unk366 == 4) {
        var_v1 = 100;
        var_v0 = 0;
    }

    D_80203FE0[32].unk0 = D_80203FE0[19].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[32].unk2 = D_80203FE0[19].unk2 = (D_80203FE0[1].unk2 + arg0) - (((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) * 3) >> 2);
    D_80203FE0[32].unk4 = D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (((D_80203FE0[1].unk4 - D_80203FE0[2].unk4) * 3) >> 3);

    var_a3 = D_80203FE0[19].unk0;
    var_t0 = D_80203FE0[19].unk2;
    var_t2 = D_80203FE0[19].unk4;

    if (var_v0 != 0) {
        var_a3 += (arg1 * D_80152350.unk2D0[var_v0]) / 256;
        var_t0 += (arg1 * D_80152350.unk384[var_v0]) / 256;
    } else {
        var_t0 += (arg1 * D_80152350.unk2D0[var_v1]) / 256;
        var_t2 += (arg1 * D_80152350.unk384[var_v1]) / 256;
    }

    D_80203FE0[20].unk0 = var_a3;
    D_80203FE0[20].unk2 = var_t0;
    D_80203FE0[20].unk4 = var_t2;

    D_80203FE0[33].unk0 = var_a3;
    D_80203FE0[33].unk2 = D_80203FE0[32].unk2 + arg1;
    D_80203FE0[33].unk4 = D_80203FE0[32].unk4;
}

#ifdef NON_MATCHING
// JUSTREG
void func_802C5EF4_6D75A4(s16 arg0, s16 arg1) {
    u16 tmp;
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[19].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[19].unk4 = (D_80203FE0[1].unk4 + arg0) & 0xFFFF;

    D_80203FE0[20].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[20].unk2 = (D_80203FE0[1].unk2 + arg1) & 0xFFFF;
    D_80203FE0[20].unk4 = D_80203FE0[1].unk4 + arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5EF4_6D75A4.s")
#endif

// used by vulture, seagull + parrot
void func_802C5F34_6D75E4(s16 arg0, s16 arg1, u8 arg2) {
    s16 pad[2];

    s16 var_a2;
    s16 var_a0;
    s16 var_a1;
    s16 var_a3;
    s16 var_t1;
    s16 var_v0;
    s16 var_v1;
    u16 temp_t9_2;
    struct113 *temp_v1_2;


    temp_v1_2 = &D_803D5528->unk3C0;
    if (temp_v1_2->unk0 != 0) {
        temp_v1_2->unk2++;
    }
    var_t1 = (D_803D5530->yRotation - D_803D552C->unk302) & 0xFF;
    var_t1 = (var_t1 * 360) >> 8;

    if ((var_t1 > 80) && (var_t1 < 280)) {
        if (var_t1 < 180) {
            var_t1 = 80;
        } else {
            var_t1 = 280;
        }
    }
    if (var_t1 > 180) {
        var_t1 -= 360;
    }

    switch (temp_v1_2->unk0) {
    case 1:
        var_a1 = 0;
        var_a2 = 62 - (D_80152350.unk384[(s16) ((temp_v1_2->unk2 * 360) / 100)] / 8);
        var_a3 = 133 - (D_80152350.unk384[(s16) ((temp_v1_2->unk2 * 360) / 100)] / 6);
        if (temp_v1_2->unk2 >= 100) {
            temp_v1_2->unk0 = 0;
        }
        break;
    case 5:
        var_a3 = 90;
        var_a2 = (D_80152350.unk384[(s16) ((temp_v1_2->unk2 * 360) / 150)] / 26) + 20;
        if (temp_v1_2->unk2 < 37) {
            var_a1 = 42 - (D_80152350.unk384[(s16) ((temp_v1_2->unk2 * 360) / 75)] / 6);
        }
        if ((temp_v1_2->unk2 >= 37) && (temp_v1_2->unk2 < 112)) {
            var_a1 = (D_80152350.unk2D0[(s16) ((temp_v1_2->unk2 * 360) / 150)] / 3);
        }
        if (temp_v1_2->unk2 >= 112) {
            var_a1 = (D_80152350.unk384[(s16) ((temp_v1_2->unk2 * 360) / 75)] / 6) - 42;
        }
        if (temp_v1_2->unk2 >= 150) {
            temp_v1_2->unk0 = 0;
        }
        break;
    case 9:
        var_a3 = 90;
        if (temp_v1_2->unk2 < 7) {
            var_a2 = ((temp_v1_2->unk2 * 20) / 6) + 20;
        } else if (temp_v1_2->unk2 < 0x1F) {
            var_a2 = 40 - (((temp_v1_2->unk2 * 20) - 120) / 24);
        }
        var_a1 = var_t1;
        if (temp_v1_2->unk2 >= 0x1E) {
            temp_v1_2->unk0 = 0;
        }
        break;
    default:
        var_a2 = 20;
        var_a3 = 90;
        var_a1 = var_t1;
        temp_v1_2->unk0 = 0;
        break;
    }

    switch (D_803D552C->unk364) {
    case 0:
        break;
    case 8:
        temp_t9_2 = (D_803D552C->unk334 - D_803D5544);
        if (temp_t9_2 > 10) {
            var_a1 = D_80152C78[(s16)((temp_t9_2 - 10) << 5) & 0xFF] >> 9;
        }
        break;
    }

    if (arg2 == 1) {
        var_a2 = var_a2 / 4;
    }
    if (arg2 == 1) {
        var_v0 = D_80203FE0[0].unk0;
        var_v1 = D_80203FE0[0].unk2;
        var_a0 = D_80203FE0[0].unk4;
    } else {
        var_v0 = D_80203FE0[1].unk0;
        var_v1 = D_80203FE0[1].unk2;
        var_a0 = D_80203FE0[1].unk4;
    }

    var_v1 += (arg0 * D_80152350.unk2D0[var_a2]) / 256;
    var_a0 += (arg0 * D_80152350.unk384[var_a2]) / 256;

    D_80203FE0[19].unk0 = var_v0;
    D_80203FE0[19].unk2 = var_v1;
    D_80203FE0[19].unk4 = var_a0;

    if (var_a1 != 0) {
        var_v0 += (arg1 * D_80152350.unk2D0[var_a1]) / 256;
        var_v1 += (arg1 * D_80152350.unk384[var_a1]) / 256;
    } else {
        var_v1 += (arg1 * D_80152350.unk2D0[var_a3]) / 256;
        var_a0 += (arg1 * D_80152350.unk384[var_a3]) / 256;
    }
    D_80203FE0[20].unk0 = var_v0;
    D_80203FE0[20].unk2 = var_v1;
    D_80203FE0[20].unk4 = var_a0;
}

#if 0
// used by mouse
void func_802C6468_6D7B18(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk4 = D_80203FE0[20].unk4 = (D_80203FE0[1].unk4 + arg0);
    D_80203FE0[20].unk2 = (D_80203FE0[1].unk2 + arg1);
    D_80203FE0[22].unk0 = D_80203FE0[1].unk0 - (arg2 >> 1);

    D_80203FE0[22].unk2 = D_80203FE0[23].unk2 = (D_80203FE0[1].unk2 + arg1) - arg1;
    D_80203FE0[19].unk2 = D_80203FE0[1].unk2;
    D_80203FE0[19].unk0 = D_80203FE0[20].unk0 = D_80203FE0[1].unk0;
    D_80203FE0[23].unk0 = D_80203FE0[1].unk0 + (arg2 >> 1);
    D_80203FE0[22].unk4 = D_80203FE0[23].unk4 = (D_80203FE0[1].unk4 + arg0) + (arg2 >> 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6468_6D7B18.s")
#endif

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

void func_802C652C_6D7BDC(s16 arg0, s16 arg1) {
    s32 pad[2];
    s16 var_a0;
    s16 temp_v0_3;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_a3_2;
    s16 var_t0;
    s16 var_v0;
    s16 var_v1;
    u16 temp_t3;
    u16 temp_t7;
    struct113 *temp_a2_2;


    temp_t3 = (D_803D552C->unk2F6 % 256);

    temp_a2_2 = &D_803D5528->unk3C0;
    if (temp_a2_2->unk0 != 0) {
        temp_a2_2->unk2++;
    }

    var_a1 = (D_803D5530->yRotation - D_803D552C->unk302) & 0xFF;
    var_a1 = (var_a1 * 360) >> 8;
    if ((var_a1 >= 0x51) && (var_a1 < 0x118)) {
        if (var_a1 < 0xB4) {
            var_a1 = 0x50;
        } else {
            var_a1 = 0x118;
        }
    }
    if (var_a1 >= 0xB5) {
        var_a1 -= 0x168;
    }

    switch (temp_a2_2->unk0) {
    case 1:
        if (temp_a2_2->unk2 >= 100) {
            temp_a2_2->unk0 = 0;
        }
        break;
    case 5:
        if (temp_a2_2->unk2 >= 0x96) {
            temp_a2_2->unk0 = 0;
        }
        break;
    }

    switch (D_803D5530->state) {
    case 0x3:
    case 0x16:
    case 0x3E:
    case 0x68:
    case 0xB6:
    case 0xCA:
        var_a3_2 = (D_80152350.unk2D0[(s16) ((temp_t3 * 0x168) / 256)] / 50) + 0x14;
        var_t0 = 90;
        var_a0 = var_a1;
        break;
    case 0x4:
    case 0x17:
    case 0x51:
    case 0x69:
    case 0xB7:
    case 0xCB:
        var_a3_2 = (D_80152350.unk2D0[(s16) ((temp_t3 * 0x168) / 256)] / 20) + 0x14;
        var_t0 = 90;
        var_a0 = var_a1;
        break;
    case 0x8D:
        var_a3_2 = 0xA;
        var_t0 = 90;
        var_a0 = var_a1;
        break;
    case 0x8E:
    case 0x8F:
        var_a3_2 = (D_80152350.unk2D0[(s16) ((temp_t3 * 0x168) / 256)] / 40) + 0xA;
        var_t0 = 90;
        var_a0 = var_a1;
        break;
    default:
        switch (temp_a2_2->unk0) {
        case 1:
            var_a0 = 0;
            temp_v0_3 = D_80152350.unk384[(s16) ((s32) (temp_a2_2->unk2 * 0x168) / 100)];
            var_a3_2 = 0x1C - (temp_v0_3 / 32);
            var_t0 = 0x64 - (temp_v0_3 / 24);
            break;
        case 5:
            var_t0 = 0x5A;
            var_a3_2 = (D_80152350.unk384[(s16) ((temp_a2_2->unk2 * 0x168) / 150)] / 52) + 0xF;
            if (temp_a2_2->unk2 < 0x25) {
                var_a0 = 0x15 - (D_80152350.unk384[(s16) ((temp_a2_2->unk2 * 0x168) / 75)] / 12);
            }
            if ((temp_a2_2->unk2 >= 0x25) && (temp_a2_2->unk2 < 0x70)) {
                var_a0 = (D_80152350.unk2D0[(s16) ((temp_a2_2->unk2 * 0x168) / 150)] / 6);
            }
            if (temp_a2_2->unk2 >= 0x70) {
                var_a0 = (D_80152350.unk384[(s16) ((temp_a2_2->unk2 * 0x168) / 75)] / 12) - 0x15;
            }
            break;
        default:
            var_a3_2 = 0x14;
            temp_a2_2->unk0 = 0;
            var_a0 = var_a1;
            var_t0 = 0x5A;
            break;
        }
        break;
    }

    switch (D_803D552C->unk364) {
    case 0:
        break;
    case 8:
        temp_t7 = D_803D552C->unk334 - D_803D5544;
        if (temp_t7 > 10) {
            var_a0 = D_80152C78[(s16)((temp_t7 - 10) << 5) & 0xFF] >> 9;
        }
    }

    var_v0 = D_80203FE0[1].unk0;
    var_v1 = D_80203FE0[1].unk2;
    var_a1_2 = D_80203FE0[1].unk4;

    var_v1 += ((arg0 * D_80152350.unk2D0[var_a3_2]) / 256);
    var_a1_2 += ((arg0 * D_80152350.unk384[var_a3_2]) / 256);

    D_80203FE0[19].unk0 = var_v0;
    D_80203FE0[19].unk2 = var_v1;
    D_80203FE0[19].unk4 = var_a1_2;

    if (var_a0 != 0) {
        var_v0 += (arg1 * D_80152350.unk2D0[var_a0]) / 256;
        var_v1 += (arg1 * D_80152350.unk384[var_a0]) / 256;
    } else {
        var_v1 += (arg1 * D_80152350.unk2D0[var_t0]) / 256;
        var_a1_2 += (arg1 * D_80152350.unk384[var_t0]) / 256;
    }
    D_80203FE0[20].unk0 = var_v0;
    D_80203FE0[20].unk2 = var_v1;
    D_80203FE0[20].unk4 = var_a1_2;
}

void func_802C6C00_6D82B0(s16 arg0, s16 arg1) {
    s16 temp_t0_3;
    s16 temp_t1;
    s16 temp_t2;
    s16 var_v0_2;
    s16 temp_t7;
    s16 temp_t7_2;
    s16 temp_t7_3;
    u16 temp_t9;
    struct113 *temp_a2_2;
    u16 var_t0;

    temp_a2_2 = &D_803D5528->unk3C0;
    if (temp_a2_2->unk0 != 0) {
        temp_a2_2->unk2 += 1;
    }

    var_t0 = temp_a2_2->unk0;
    switch (temp_a2_2->unk0) {
    case 1:
        temp_a2_2->unk0 = 0;
        var_t0 = 0;
        break;
    case 5:
        if (temp_a2_2->unk2 >= 0x96) {
            temp_a2_2->unk0 = 0;
            var_t0 = 0;
        }
        break;
    }

    var_v0_2 = (((D_803D5530->yRotation - D_803D552C->unk302) & 0xFF));
    var_v0_2 = (var_v0_2 * 360) >> 8;
    if ((var_v0_2 >= 0x51) && (var_v0_2 < 0x118)) {
        if (var_v0_2 < 0xB4) {
            var_v0_2 = 0x50;
        } else {
            var_v0_2 = 0x118;
        }
    }

    switch (temp_a2_2->unk0) {
    case 5:
        if (temp_a2_2->unk2 < 0x25) {
          var_v0_2 = 0x15 - (D_80152350.unk384[(s16) ((s32) (temp_a2_2->unk2 * 0x168) / 75)] / 12);
        }
        if ((temp_a2_2->unk2 >= 0x25) && (temp_a2_2->unk2 < 0x70)) {
          var_v0_2 = (s16) (D_80152350.unk2D0[(s16) ((s32) (temp_a2_2->unk2 * 0x168) / 150)] / 6);
        }
        if (temp_a2_2->unk2 >= 0x70) {
          var_v0_2 = (D_80152350.unk384[(s16) ((s32) (temp_a2_2->unk2 * 0x168) / 75)] / 12) - 0x15;
        }
        break;
    default:
    case 1:
        temp_a2_2->unk0 = 0;
        break;
    }

    switch (D_803D552C->unk364) {
    case 0:
        break;
    case 8:
        temp_t9 = (D_803D552C->unk334 - D_803D5544);
        if (temp_t9 > 10) {
            var_v0_2 = D_80152C78[(s16)((temp_t9 - 0xA) << 5) & 0xFF] >> 9;
        }
        break;
    }

    temp_t0_3 = D_80203FE0[1].unk0;
    temp_t1 = D_80203FE0[1].unk2;
    temp_t2 = D_80203FE0[1].unk4;
    temp_t2 += arg0;

    D_80203FE0[19].unk4 = temp_t2;
    D_80203FE0[19].unk0 = temp_t0_3;
    D_80203FE0[19].unk2 = temp_t1;

    var_v0_2 += (D_803D552C->unk30E * 360) / 1024;

    while (var_v0_2 > 180) {
        var_v0_2 -= 360;
    }
    while (var_v0_2 < -180) {
        var_v0_2 += 360;
    }

    if (var_v0_2 < -175) {
        var_v0_2 = -175;
    }
    if (var_v0_2 > 175) {
        var_v0_2 = 175;
    }

    temp_t7 = (D_80152350.unk2D0[var_v0_2] * arg1) / 256;
    temp_t7_2 = (D_80152350.unk384[var_v0_2] * arg1) / 256;
    temp_t7_3 = ((D_80152C78[(s16)(D_803D552C->unk310 >> 3) & 0xFF] >> 7) * arg1) >> 8;

    D_80203FE0[20].unk0 = temp_t0_3 + temp_t7;
    D_80203FE0[20].unk2 = temp_t1 + temp_t7_2;
    D_80203FE0[20].unk4 = temp_t2 + temp_t7_3;

    D_80203FE0[26].unk0 = temp_t0_3 - temp_t7;
    D_80203FE0[26].unk2 = temp_t1 - temp_t7_2;
    D_80203FE0[26].unk4 = temp_t2 - temp_t7_3;
}

#if 0
void func_802C6FF4_6D86A4(s16 arg0, s16 arg1) {
    s16 var_a0;
    s16 var_a2;
    s16 temp_hi;

    temp_hi = (D_803D5542 + 0x14) % 360;

    if (D_803D5542 < 96) {
        var_a0 = ((D_80152C78[(D_803D5542 << 3) & 0xFF] >> 7) * arg1) >> 9;
    } else {
        var_a0 = 0;
    }
    if (temp_hi < 96) {
        var_a2 = ((D_80152C78[(temp_hi << 3) & 0xFF] >> 7) * arg1) >> 9;
    } else {
        var_a2 = 0;
    }
    if ((D_803D5542 > 0xC0) && (D_803D5542 < 0xD8)) {
        var_a0 = ((D_80152C78[(D_803D5542 << 2) & 0xFF] >> 7) * arg1) >> 9;
    }

    if (ABS(var_a0) <= 16) {
        var_a0 = 16;
    }
    if (ABS(var_a2) <= 16) {
        var_a2 = 16;
    }

    if ((D_803D552C->unk366 == 5) || (D_803D552C->unk366 == 2)) {
        var_a0 = var_a2 = 0;
    }

    D_80203FE0[27].unk0 = D_80203FE0[26].unk0 = D_80203FE0[19].unk0 - arg0;
    D_80203FE0[29].unk0 = D_80203FE0[28].unk0 = D_80203FE0[19].unk0 + arg0;

    D_80203FE0[27].unk2 = (D_80203FE0[19].unk2 + var_a0);
    D_80203FE0[27].unk4 = ((D_80203FE0[19].unk4 + arg1) - (var_a0 >> 1));
    if (!temp_hi){}; // helps a bit...
    D_80203FE0[29].unk2 = (D_80203FE0[19].unk2 + var_a2);
    D_80203FE0[29].unk4 = ((D_80203FE0[19].unk4 + arg1) - (var_a2 >> 1));

    D_80203FE0[28].unk2 = D_80203FE0[26].unk2 = D_80203FE0[19].unk2;
    D_80203FE0[28].unk4 = D_80203FE0[26].unk4 = D_80203FE0[19].unk4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6FF4_6D86A4.s")
#endif

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

void func_802C78B0_6D8F60(u16 joint1, u16 joint2, s32 scaleX, s32 scaleZ, s32 scaleY, s16 arg5, s16 arg6, u8 arg7, u8 arg8, Gfx *dl) {
    if (func_80126388(joint1, joint2, scaleX, scaleZ, scaleY, arg5, arg6, arg7, arg8, &D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs])) {
        gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&D_80204278->modelViewMtx[D_80204278->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
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
