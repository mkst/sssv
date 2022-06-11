#include <ultra64.h>
#include "common.h"

// tbd
u8 func_80322A58_734108(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, Animal **animal, Animal *arg6, u8 arg7);


// try_pickup_animal?
Animal *func_803213B0_732A60(void) {
    Animal *a = D_803D5530->unk6C;

    if ((a == NULL) &&
        (func_80322A58_734108(D_803D5530->xPos.h, D_803D5530->zPos.h, (s16) (D_803D5530->yPos.h - 0x10), 0x10, 0, &a, D_803D5530, 0)) &&
        (!(a->unk16C->unk80.bit) || (a->unk366 != 5) || ((a->unk160 == 1) && (D_803D5530->unk160 == 2)))) {
        a = NULL;
    }

    if (a != NULL) {
        if ((a->unk16C->unk80.bit2 == 0) && (a->unk4C.unk27)) {
            if ((D_803D5524->unkC0 >= (s32) a->unk44) &&
                (((a->unk16C->unk80.bit == 0) && ((a->state == 0) || (a->state == 1))) || ((a->unk16C->unk80.bit != 0) && (a->unk366 == 5))) &&
                (a->unk4A == 0) && ((a->unk16C->unk80.bit == 0) || (a->unk44 < 100))) {
                D_803D552C->unk324 = a->state;
                D_803D552C->unk320 = a;
                a->state = 0x1FU;
                a->unk4C.unk25 = 1;
                play_sound_effect_at_location(SFX_UNKNOWN_40, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.5f);
                if ((a->unk16C->unk80.bit) == 0) {
                    if (a->unk163 & 8) {
                        a->unk163 |= 32;
                    }
                    a->unk163 |= 8;
                }
                return a;
            }
        }
    }
    return NULL;
}

Animal *func_803215DC_732C8C(s16 arg0, s16 arg1) {
    s32 pad[2];

    s16 temp_a2;
    s16 temp_v0;

    s16 temp_s1;
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_s4;

    s16 temp_t1;
    s16 temp_t2;
    Animal *a;

    struct065 *temp_v1;


    temp_a2 = D_803D5530->xPos.h;
    temp_a2 += ((((s16) D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
    temp_v0 = D_803D5530->zPos.h;
    temp_v0 += ((((s16) D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);

    temp_s1 = temp_a2 - arg1; // x min
    temp_s2 = temp_v0 - arg1; // z min
    temp_s3 = temp_a2 + arg1; // x max
    temp_s4 = temp_v0 + arg1; // z max

    temp_t1 = D_803D5530->yPos.h - 64;     // y min
    temp_t2 = D_803D5530->yPos.h + 64 + D_803D5524->unkBA; // y max

    for (temp_v1 = D_803DA110[(s16) ((s16)(temp_a2 >> 0xA) + ((s16)(temp_v0 >> 0xA) * 5))].next; temp_v1 != NULL; temp_v1 = temp_v1->next) {
        a = temp_v1->animal;
        if ((a->xPos.h >= temp_s1) && (temp_s3 >= a->xPos.h)) {
            if ((a->zPos.h >= temp_s2) && (temp_s4 >= a->zPos.h)) {
                if ((a->yPos.h >= temp_t1) && (temp_t2 >= a->yPos.h)) {
                    if ((D_803D5524->unk9C == ELEPHANT) && (a->unk16C->unk0 != 2)) {
                        return NULL;
                    }
                }
            }
        }
        if ((a != D_803D5530) && (a != D_803D5530->unk6C)) {
            if ((a->xPos.h >= temp_s1) && (temp_s3 >= a->xPos.h)) {
                if ((a->zPos.h >= temp_s2) && (temp_s4 >= a->zPos.h) && (a->unk16C->unk80.bit2 == 0) && (a->unk4C.unk27)) {
                    if ((a->yPos.h >= temp_t1) && (temp_t2 >= a->yPos.h)) {
                        if ((D_803D5524->unkC0 >= a->unk44) && (a->unk40 <= 3072) && ((a->state == 0) || (a->state == 1)) && (a->unk4A == 0)) {
                            D_803D552C->unk324 = a->state;
                            D_803D552C->unk320 = a;
                            a->state = 30;
                            a->unk4C.unk25 = 1;
                            return a;
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

Animal *func_803218D8_732F88(Animal *arg0) {
    if (arg0 != NULL) {
        D_803D552C->unk324 = arg0->state;
        D_803D552C->unk320 = arg0;
        arg0->state = 30;
        arg0->unk4C.unk25 = 1;
        return arg0;
    }
    return NULL;
}

void func_80321920_732FD0(Animal *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg0->xVelocity.h = D_803D5530->xVelocity.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8);
        arg0->zVelocity.h = D_803D5530->zVelocity.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8);
        arg0->yVelocity.h = (D_803D5530->yVelocity.h + arg2) - 1;
        arg0->unk4C.unk25 = 1;
        arg0->unk160 = D_803D5530->unk160;
        if (arg0->unk160 != 0) {
            if (((arg0->unk160 == 1) || (arg0->unk160 == 2)) && (D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3 == 0)) {
                arg0->unk160 = 0U;
            }
        } else {
            if (D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3 != 0) {
                if ((func_80310F58_722608(arg0->xPos.h, arg0->zPos.h) >> 0x10) < arg0->yPos.h) {
                    arg0->unk160 = 2U;
                } else {
                    arg0->unk160 = 1U;
                }
            }
        }

        arg0->state = D_803D552C->unk324;
        D_803D552C->unk320 = 0;

        if (arg0->yRotation < 45) {
            arg0->yRotation = 0;
        } else if (arg0->yRotation < 135) {
            arg0->yRotation = 90;
        } else if (arg0->yRotation < 225) {
            arg0->yRotation = 180;
        } else if (arg0->yRotation < 315) {
            arg0->yRotation = 270;
        } else {
            arg0->yRotation = 0;
        }
        if (arg0->unk16C->unk80.bit == 0) {
            if ((arg0->unk163 & 0x20) == 0) {
                // remove flags
                arg0->unk163 &= -(8 | 1);
            }
        }
    }
}

void func_80321B70_733220(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_t0;

    Animal *a = D_803D552C->unk320;
    if (a != 0) {
        a->xPos.h = (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8) + (D_803D5530->xPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8));
        a->zPos.h = D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8) - (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->yPos.h = D_803D5530->yPos.h + arg2;
        a->unk160 = D_803D5530->unk160;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;

        temp_t0 = D_803D552C->unk302 - D_803D552C->unk304;
        if (a->unk16C->unk80.bit != 0) {
            a->yRotation = ((a->yRotation + temp_t0) & 0xFF);
            a->unk302 = a->yRotation;
        } else {
            temp_t0 = (temp_t0 * 360) / 256;
            a->yRotation += temp_t0;
            while (a->yRotation < 0) {
                a->yRotation += 360;
            }
            while (a->yRotation >= 360) {
                a->yRotation -= 360;
            }
        }
    }
}

void func_80321D74_733424(s16 arg0, s16 arg1) {
    Animal *a = D_803D552C->unk320;
    if (a != NULL) {
        a->xPos.h = D_803D5530->xPos.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->zPos.h = D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);
        a->yPos.h = D_803D5530->yPos.h + arg1;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80321E60_733510.s")
// long way to go here
// void func_80321E60_733510(u8 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
//     s32 sp38;
//     s32 sp34;
//     s32 sp30;
//
//     s32 zpos;
//     s32 xpos;
//
//     s32 temp_t7;
//     s32 temp_t7_2;
//
//     struct071 *obj;
//
//     temp_t7 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7;
//     temp_t7_2 = D_80152C78[D_803D552C->unk302 & 0xFF] >> 7;
//
//     xpos = D_803D5530->xPos.h;
//     xpos += (((temp_t7 * arg2) + (arg1 * (temp_t7_2))) >> 8);
//     zpos = D_803D5530->zPos.h;
//     zpos += (((arg1 * temp_t7) - ((temp_t7_2) * arg2)) >> 8);
//
//     sp38 = (temp_t7_2) * (D_80152C78[(arg5 + 64) & 0xFF] >> 7) * arg4;
//     sp34 = (temp_t7) * (D_80152C78[(arg5 + 64) & 0xFF] >> 7) * arg4;
//     sp30 = ((D_80152C78[arg5 & 0xFF] >> 7) * arg4) << 8;
//
//     obj = func_802C9564_6DAC14(
//         id & 0xffff,
//         xpos,
//         zpos,
//         D_803D5530->yPos.h + arg3,
//         D_803D5530->xVelocity.w + sp38,
//         D_803D5530->zVelocity.w + sp34,
//         D_803D5530->yVelocity.w + sp30,
//         0,
//         0,
//         0);
//     if (obj != 0) {
//         D_803D5530->xVelocity.w -= sp38 >> arg6;
//         D_803D5530->zVelocity.w -= sp34 >> arg6;
//         obj->unk15C = 15;
//         obj->unk168 = D_803D5530;
//         if (arg7 != 0) {
//             obj->unk15E = arg7;
//         }
//     }
// }

// how to match these functions??
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322064_733714.s")
// void func_80322064_733714(u8 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8) {
//     s32 sp38;
//     s32 sp34;
//     s32 temp_lo;
//     s32 temp_t6;
//     s32 temp_t8;
//     struct071 *obj;
//
//     temp_t8 = D_80152C78[(arg5 + 64) & 0xFF] >> 7;
//     temp_t6 = D_80152C78[arg5 & 0xFF] >> 7;
//     sp38 = temp_t6 * (D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4;
//     sp34 = temp_t8 * (D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4;
//     obj = func_802C9564_6DAC14(
//         id,
//         D_803D5530->xPos.h + (((temp_t8 * arg2) + (arg1 * temp_t6)) >> 8),
//         D_803D5530->zPos.h + (((arg1 * temp_t8) - (temp_t6 * arg2)) >> 8),
//         D_803D5530->yPos.h + arg3,
//         D_803D5530->xVelocity.w + sp38,
//         D_803D5530->zVelocity.w + sp34,
//         D_803D5530->yVelocity.w + (((D_80152C78[arg6 & 0xFF] >> 7) * arg4) << 8),
//         0,
//         0,
//         0);
//     if (obj != NULL) {
//         D_803D5530->xVelocity.w -= (sp38 >> arg7);
//         D_803D5530->zVelocity.w -= (sp34 >> arg7);
//         obj->unk15C = 15;
//         obj->unk168 = (void *) D_803D5530;
//         if (arg8 != 0) {
//             obj->unk15E = arg8;
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_8032225C_73390C.s")
// another junk function
// void func_8032225C_73390C(u8 id, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8) {
//     s32 xpos;
//     s32 zpos;
//
//     struct071 *obj;
//
//     xpos = D_803D5530->xPos.h + ((((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg2) + (arg1 * (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7))) >> 8);
//     zpos = D_803D5530->zPos.h + (((arg1 * (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7)) - ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2)) >> 8);
//
//     obj = func_802C9564_6DAC14(
//         id & 0xffff,
//         xpos & 0xFFFFFFFFFFFFFFFFu,
//         zpos & 0xFFFFFFFFFFFFFFFFu,
//         D_803D5530->yPos.h + arg3,
//         D_803D5530->xVelocity.w + arg4,
//         D_803D5530->zVelocity.w + arg5,
//         D_803D5530->yVelocity.w + arg6,
//         0,
//         0,
//         0);
//
//     if (obj != NULL) {
//         D_803D5530->xVelocity.w -= arg4 >> arg7;
//         D_803D5530->zVelocity.w -= arg5 >> arg7;
//         obj->unk168 = D_803D5530;
//         if (arg8 != 0) {
//             obj->unk15E = arg8;
//         }
//     }
// }

void apply_recoil(s16 arg0) {
    s32 temp_t2 = D_80152C78[(u8)D_803D552C->unk302] >> 7;
    s32 temp_t7 = D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7;

    if (arg0 < 0) {
        D_803D5530->xVelocity.w += temp_t2 << (8 - arg0);
        D_803D5530->zVelocity.w += temp_t7 << (8 - arg0);
    } else {
        D_803D5530->xVelocity.w -= temp_t2 << (arg0 + 8);
        D_803D5530->zVelocity.w -= temp_t7 << (arg0 + 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803224C4_733B74.s")

u8 func_80322A58_734108(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 damage, Animal **arg5, Animal *arg6, u8 arg7) {
    s32 pad[2];
    struct065 *temp_t8;
    struct044 *phi_s2; // ?
    u8 pad2[3];
    u8 ret;
    s16 phi_s1;
    Animal *a;

    ret = 0;
    temp_t8 = D_803DA110[(s16)((s16)(arg0 >> 0xA) + ((s16)(arg1 >> 0xA) * 5))].next;
    while (temp_t8 != NULL) {
        a = temp_t8->animal;
        if ((a != D_803D5530) && (a != arg6) && (a->unk16C->unk0 != 64)) {
            // TODO: FIXME
            if (a->unkD0.m[0][0] != 0) {
                // TODO: FIXME
                phi_s2 = (struct044*)&a->unkC0[0][2];
                do {
                    if ((ABS((a->xPos.h + phi_s2->unk0) - arg0) < phi_s2->unkC + arg3) &&
                        (ABS((a->zPos.h + phi_s2->unk4) - arg1) < phi_s2->unkC + arg3) &&
                        (ABS((a->yPos.h + phi_s2->unk8) - arg2) < phi_s2->unkC + arg3)) {
                        ret = 1;
                        if (arg7 != 0) {
                            a->unk57 = arg7;
                        }
                        if (arg5 != NULL) {
                            *arg5 = a;
                        }
                        if (a->unk16C->unk80.bit) {
                            func_802FD674_70ED24(D_803D5530, a);
                            phi_s1 = 0;
                            if (D_803D5530->unk44 < a->unk44) {
                                phi_s1 = 1;
                            }
                            if ((D_803D5530->unk44 * 2) < a->unk44) {
                                phi_s1 += 1;
                            }
                            if ((D_803D5530->unk44 * 3) < a->unk44) {
                                phi_s1 += 1;
                            }
                            // apply fall damage between animals?
                            func_802B356C_6C4C1C(a, damage, D_803D5524->unkE6, 1);
                            if (D_803D5538 != 0) {
                                a->unk2EB += 1;
                            }
                            a->unk65 = MIN(100, a->unk65 + (0x14 >> phi_s1));
                            a->unk4C.unk25 = 1;
                        } else if ((a->unk4A == 0) && (a->unk4C.unk26 == 0)) {
                            a->health = MAX(0, a->health);
                        }
                    }
                    phi_s2++;
                } while (phi_s2->unkC != 0);
            }
        }
        temp_t8 = temp_t8->next;
    }
    return ret;
}

// delay slot
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_80322D68_734418.s")

Animal *func_80323040_7346F0(void) {
    s16 temp_fp;
    s16 x_dist;
    s16 z_dist;
    s16 candidate;
    s16 temp_s7;
    s16 temp_v0;
    s16 y_dist;

    Animal *temp_s3;
    struct065 *temp_s4;

    s16 phi_a0;
    s16 phi_a2;
    s16 phi_a1;
    s16 phi_v0;
    s16 phi_v1;
    s16 best;
    f32 phi_f2;
    Animal *res;

    s16 x;
    s16 y;

    x = (D_803D5530->xPos.h >> 0xA);
    y = (D_803D5530->zPos.h >> 0xA);

    res = NULL;
    best = 320;

    temp_s7 = (D_80152C78[D_803D552C->unk302 & 0xFF]) >> 9;
    temp_fp = (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF]) >> 9;

    for (temp_s4 = D_803DA110[(s16) (x + (y * 5))].next; temp_s4 != NULL; temp_s4 = temp_s4->next) {
        temp_s3 = temp_s4->animal;
        if ((temp_s3 != D_803D5530) && (((temp_s3->unk16C->unk80.bit) && (temp_s3->unk366 != 5) && ((temp_s3->unk16C->unk0 != 0x13D)) && (temp_s3->unk16C->unk0 != 0x13E) && (temp_s3->unk16C->unk0 != 0x13F)) || (temp_s3->unk16C->unk0 == 0x91))) {
            x_dist = D_803D5530->xPos.h - temp_s3->xPos.h;
            z_dist = D_803D5530->zPos.h - temp_s3->zPos.h;
            y_dist = D_803D5530->yPos.h - temp_s3->yPos.h;

            phi_a2 = ABS(x_dist);
            phi_a0 = ABS(z_dist);
            phi_a1 = ABS(y_dist);

            candidate = (MAX(MAX(phi_a2, phi_a0), phi_a1) >> 1) + (phi_a2 >> 1) + (phi_a0 >> 1) + (phi_a1 >> 1);
            if (candidate < best) {
                phi_f2 = MAX(1.0, sqrtf((x_dist * x_dist) + (z_dist * z_dist)));
                if ((s16) (-((x_dist * temp_s7) + (z_dist * temp_fp)) / phi_f2) > 0) {
                    best = candidate;
                    res = temp_s3;
                }
            }
        }

    }
    return res;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803233A0_734A50.s")
// miles away
// s32 func_803233A0_734A50(s16 x0, s16 y0, s16 z0, s16 x1, s16 y1, s16 z1) {
//
//     s16 temp_v1;
//
//     struct065 *temp_a1;
//     Animal *a;
//     s32 phi_a2;
//     s32 phi_a3;
//     s32 phi_t0;
//     s16 i;
//
//     s32 tmp1 = (x0 - x1);
//     s32 tmp2 = (y0 - y1);
//     s32 tmp3 = (z0 - z1);
//
//     f32 tmpf1 = tmp1;
//     f32 tmpf2 = tmp2;
//     f32 tmpf3 = tmp3;
//
//     temp_v1 = ((s16) sqrtf((tmpf1 * tmpf1) + (tmpf2 * tmpf2) + (tmpf3 * tmpf3)) / 10) + 1;
//
//     phi_a2 = (x1 << 0x10) + ((tmp1 << 0x10) / (temp_v1 + 1) >> 1);
//     phi_a3 = (y1 << 0x10) + ((tmp2 << 0x10) / (temp_v1 + 1) >> 1);
//     phi_t0 = (z1 << 0x10) + ((tmp3 << 0x10) / (temp_v1 + 1) >> 1);
//
//     // i = 0;
//     for (i = 0; i < temp_v1; i++) {
//         for (temp_a1 = D_803DA110[(s16) ((s16)(phi_a2 >> 0x1A) + ((s16) (phi_a3 >> 0x1A) * 5))].next; temp_a1 != NULL; temp_a1 = temp_a1->next) {
//             a = temp_a1->animal;
//             if (a->unk16C->unk0 == 0x5B) {
//                 if ((a->yPos.h < (phi_t0 >> 0x10)) && ((phi_t0 >> 0x10) < (a->yPos.h + a->unk42))) {
//                     if (a->unk30 >= ABS((phi_a2 >> 0x10) - a->xPos.h)) {
//                         if (a->unk32 >= ABS((phi_a3 >> 0x10) - a->zPos.h)) {
//                             return 1;
//                         }
//                     }
//                 }
//                 if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
//             }
//         }
//
//         phi_a2 += (tmp1 << 0x10) / (temp_v1 + 1);
//         phi_a3 += (tmp2 << 0x10) / (temp_v1 + 1);
//         phi_t0 += (tmp3 << 0x10) / (temp_v1 + 1);
//     }
//
//     return 0;
// }
