#include <ultra64.h>
#include "common.h"

#if 0

s32 func_8032B1E0_73C890(Animal *arg0, s16 arg1, s16 arg2, s32 *arg3, s32 *arg4) {
    s16 sp92;
    // s32 *sp88;
    s32 sp84;
    s32 sp80;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp38;
    s32 sp30;
    // struct035_ptr *sp2C;
    Animal *sp20;
    s16 temp_a0;
    // s16 temp_a1;
    // s16 temp_a3;
    s16 temp_t1;
    s16 temp_t4;
    s16 temp_t4_2;
    s16 idx;
    s16 temp_v0_2;
    s16 temp_v0_5;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 var_a0;
    s16 var_a0_3;
    s16 var_a0_5;
    s16 var_a0_6;
    s16 var_a2;
    s16 var_t1;
    s16 var_t1_2;
    s16 var_t5;
    s16 var_t6;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s16 var_v1_4;
    s16 var_v1_5;
    s16 var_v1_6;
    s16 var_v1_7;
    struct035_ptr *temp_ra;
    struct035_ptr *temp_t7;
    struct035_ptr *temp_t9;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a1_7;
    s32 temp_a1_8;
    s32 temp_a1_9;
    s32 temp_a2;
    s32 temp_a2_2;
    s16 temp_lo;
    s16 temp_lo_2;
    s32 temp_t0;
    s16 temp_t6;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0_2;
    s32 var_a0_4;
    s32 var_a2_2;
    s32 var_t0;
    s32 var_t3;

    temp_ra = arg0->unk16C->unk18;
    if (temp_ra == NULL) {
        *arg3 = arg0->yPos.w + (arg0->unk42 << 0x10);
        *arg4 = arg0->yPos.w;
        return 1;
    }

    temp_t6 = (arg0->unk40 << 6) >> 0xC;

    if ((arg1 >= (arg0->xPos.h - temp_t6)) && (arg1 < (arg0->xPos.h + temp_t6)) &&
        (arg2 >= (arg0->zPos.h - temp_t6)) && (arg2 < (arg0->zPos.h + temp_t6))) {

        temp_t1 = temp_t6 * 2;
        sp92 = temp_t1;

        switch (arg0->yRotation) {              /* irregular */
        default:
            var_a0 = (arg1 - arg0->xPos.h) + temp_t6;
            var_a2 = (arg2 - arg0->zPos.h) + temp_t6;
            break;
        case 90:
            var_a0 = (arg0->zPos.h + temp_t6) - arg2;
            var_a2 = (arg1 - arg0->xPos.h) + temp_t6;
            break;
        case 180:
            var_a0 = (arg0->xPos.h + temp_t6) - arg1;
            var_a2 = (arg0->zPos.h + temp_t6) - arg2;
            break;
        case 270:
            var_a0 = (arg2 - arg0->zPos.h) + temp_t6;
            var_a2 = (arg0->xPos.h + temp_t6) - arg1;
            break;
        }

        if (temp_t1 >= 0x40) {

            temp_lo = (var_a0 << 5) / temp_t1;
            temp_lo_2 = (var_a2 << 5) / temp_t1;

            temp_v0 = var_a0 - ((temp_lo * temp_t1) >> 5);
            temp_v1_2 = var_a2 - ((temp_lo_2 * temp_t1) >> 5);

            if (temp_v0 < temp_v1_2) {
                idx = temp_lo + (temp_lo_2 << 5);
                temp_t9 = &temp_ra[idx];
                temp_a1_2 = temp_ra[idx].unk8;
                temp_a2 = temp_lo_2 + 1;
                sp58 = temp_a1_2;

                if (temp_ra[idx].unk8 != 0) {
                    var_v1 = 31;
                    if ((temp_ra[idx].unk8 << 0) >= 0) {
                        do {
                            var_v1 -= 1;
                        } while (!(temp_ra[idx].unk8 & (1 << var_v1)));
                    }
                    sp68 = (s32) var_v1;
                    var_a0_2 = arg0->yPos.w;
                    sp38 = (s32) temp_t1;
                    sp78 = var_a0_2 + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
                } else {
                    var_a0_2 = arg0->yPos.w;
                    sp38 = (s32) temp_t1;
                    sp68 = 0;
                    sp78 = var_a0_2;
                }

                if (temp_a2 >= 0x20) {
                    var_t0 = var_a0_2;
                    var_t5 = 0;
                    sp54 = 0;
                } else {
                    idx = (s16) temp_lo + (temp_a2 << 5);
                    temp_a1_3 = temp_ra[idx].unk8;
                    var_t0 = var_a0_2;
                    var_t5 = 0;
                    sp54 = temp_a1_3;

                    if (temp_ra[idx].unk8 != 0) {
                        var_v1 = 0x1F;
                        if ((temp_ra[idx].unk8 << 0) >= 0) {
                            do {
                                var_v1 -= 1;
                            } while (!(temp_ra[idx].unk8 & (1 << var_v1)));
                        }
                        var_t5 = var_v1;
                        var_t0 = var_a0_2 + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
                    }
                }

                var_t3 = var_a0_2;
                if ((((s16) temp_lo + 1) >= 0x20) || (temp_a2 >= 0x20)) {
                    var_t1 = 0;
                    sp50 = 0;
                } else {
                    idx = (s16) temp_lo + (temp_a2 << 5) + 1;
                    temp_v0_3 = temp_ra[idx].unk8;
                    var_t3 = var_a0_2;
                    var_t1 = 0;
                    sp50 = temp_v0_3;
                    if (temp_ra[idx].unk8 != 0) {
                        var_v1 = 0x1F;
                        if ((temp_ra[idx].unk8 << 0) >= 0) {
                            do {
                                var_v1 -= 1;
                            } while (!(temp_ra[idx].unk8 & (1 << var_v1)));
                        }
                        var_t1 = var_v1;
                        var_t3 = var_a0_2 + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
                    }
                }
                // sp88 = temp_ra;
                sp74 = var_t0;
                sp70 = var_t3;
                sp30 = (s32) idx;
                if (func_8032BD5C_73D40C(sp58, sp54, sp50, (s32) sp68, (s16) (s32) var_t5, (s16) (s32) var_t1) == 0) {
                    if (sp68 != 0) {
                        *arg3 = sp78;
                        goto block_42;
                    }
                    // goto block_89;
                    return 0;
                }
                *arg3 = ((s32) (((var_t3 - var_t0) * temp_v0) + ((var_t0 - sp78) * temp_v1_2)) / (s32) (sp38 >> 5)) + sp78;
block_42:
                temp_a1_4 = temp_ra[idx].unk8;
                if (temp_a1_4 != 0) {
                    var_a0_3 = 0;
                    if (!(temp_a1_4 & 1)) {
                        do {
                            var_a0_3 += 1;
                        } while (!(temp_ra[idx].unk8 & (1 << var_a0_3)));
                    }
                    *arg4 = arg0->yPos.w + (arg0->unk42 << 0xF) + (((var_a0_3 - 0x10) * sp92) << 0xB);
                    return 1;
                }
                return 0;
            }
            idx = (s16) temp_lo + ((s16) temp_lo_2 << 5);
            temp_t7 = &temp_ra[idx];
            // sp2C = temp_t7;
            temp_a1_5 = temp_ra[idx].unk8;
            temp_a2_2 = (s16) temp_lo_2 + 1;
            sp58 = temp_a1_5;
            if (temp_a1_5 != 0) {
                var_v1 = 0x1F;
                if ((temp_a1_5 << 0) >= 0) {
                    do {
                        var_v1 -= 1;
                    } while ((temp_ra[idx].unk8 & (1 << var_v1)) == 0);
                }
                sp68 = (s32) var_v1;
                var_a0_4 = arg0->yPos.w;
                sp38 = (s32) temp_t1;
                sp78 = var_a0_4 + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
            } else {
                var_a0_4 = arg0->yPos.w;
                sp38 = (s32) temp_t1;
                sp68 = 0;
                sp78 = var_a0_4;
            }
            temp_a1_6 = (s16) temp_lo + 1;
            var_t3 = var_a0_4;
            if ((temp_a1_6 >= 0x20) || (temp_a2_2 >= 0x20)) {
                var_t1_2 = 0;
                sp50 = 0;
            } else {
                idx = (s16) temp_lo + (temp_a2_2 << 5) + 1;
                // temp_v0_4 = temp_ra[idx].unk8;
                var_t3 = var_a0_4;
                var_t1_2 = 0;
                sp50 = temp_ra[idx].unk8;
                if (temp_ra[idx].unk8 != 0) {
                    var_v1_5 = 0x1F;
                    if ((temp_ra[idx].unk8 << 0) >= 0) {
                        do {
                            var_v1_5 -= 1;
                        } while (!(temp_ra[idx].unk8 & (1 << var_v1_5)));
                    }
                    var_t1_2 = var_v1_5;
                    var_t3 = var_a0_4 + (arg0->unk42 << 0xF) + (((var_v1_5 - 0xF) * sp92) << 0xB);
                }
            }
            idx = idx + 1;
            if (temp_a1_6 >= 0x20) {
                var_t0 = var_a0_4;
                var_a2_2 = 0;
            } else {
                var_t0 = var_a0_4;
                var_a2_2 = temp_ra[idx].unk8;
                if (temp_ra[idx].unk8 != 0) {
                    var_v1 = 0x1F;
                    if ((temp_ra[idx].unk8 << 0) >= 0) {
                        do {
                            var_v1 -= 1;
                        } while ((temp_ra[idx].unk8 & (1 << var_v1)) == 0);
                    }
                    var_t0 = var_a0_4 + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
                }
            }
            // sp88 = temp_ra;
            sp6C = var_t0;
            sp70 = var_t3;
            sp30 = (s32) idx;
            if (func_8032BD5C_73D40C(temp_ra[idx].unk8, sp50, var_a2_2, (s32) sp68, (s16) 0, (s16) (s32) var_t1_2) == 0) {
                if (sp68 != 0) {
                    *arg3 = sp78;
                    goto block_74;
                } else {
                    return 0; //goto block_89;
                }
            }
            *arg3 = ((s32) (((var_t0 - sp78) * temp_v0) + ((var_t3 - var_t0) * temp_v1_2)) / (s32) (sp38 >> 5)) + sp78;
block_74:
            if (temp_ra[idx].unk8 != 0) {
                var_a0_6 = 0;
                if (!(temp_ra[idx].unk8 & 1)) {
                    do {
                        var_a0_6 += 1;
                    } while ((temp_ra[idx].unk8 & (1 << var_a0_6)) == 0);
                }
                *arg4 = arg0->yPos.w + (arg0->unk42 << 0xF) + (((var_a0_6 - 0x10) * sp92) << 0xB);
                return 1;
            }
            // goto block_89;
        } else {
            idx = (s16) ((s32) (var_a0 << 5) / temp_t1) + ((s16) ((s32) (var_a2 << 5) / temp_t1) << 5);
            if (temp_ra[idx].unk8 != 0) {
                var_v1 = 0x1F;
                if ((temp_ra[idx].unk8 << 0) >= 0) {
                    do {
                        var_v1 -= 1;
                    } while ((temp_ra[idx].unk8 & (1 << var_v1)) == 0);
                }

                var_a0_6 = 0;
                if ((temp_ra[idx].unk8 & 1) == 0) {
                    do {
                        var_a0_6 += 1;
                    } while ((temp_ra[idx].unk8 & (1 << var_a0_6)) == 0);
                }
                *arg3 = arg0->yPos.w + (arg0->unk42 << 0xF) + (((var_v1 - 0xF) * sp92) << 0xB);
                *arg4 = arg0->yPos.w + (arg0->unk42 << 0xF) + (((var_a0_6 - 0x10) * sp92) << 0xB);
                return 1;
            }
        }
    }
block_89:
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73C890/func_8032B1E0_73C890.s")
#endif

// check some flag?
u8 func_8032BCF8_73D3A8(s32 arg0, s16 arg1) {
    if (arg1 >= 0) {
        while ((2 << arg1) & arg0) {
            if (--arg1 < 0) {
                break;
            }
        }
    }
    return (arg1 + 1) == 0;
}

s32 func_8032BD5C_73D40C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5) {
    if (arg0 == 0) {
        if ((func_8032BCF8_73D3A8(arg1, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg1 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg2, arg5) == 0)) {
            return 0;
        }
    }
    if (arg2 == 0) {
        if ((func_8032BCF8_73D3A8(arg0, arg4) == 0) || (func_8032BCF8_73D3A8(arg1, arg4) == 0)) {
            return 0;
        }
    }
    return 1;
}

#ifdef NON_MATCHING
// offsets are fakematches...
void func_8032BE28_73D4D8(Animal *arg0) {
    s16 temp_v0;
    s32 *temp_a1;
    s16 x;
    s16 y1;
    s16 y2;
    s16 phi_s0;
    s16 i;

    temp_a1 = arg0->unk16C->unk18;
    if (temp_a1 != NULL) {
        gSPDisplayList(D_801D9E8C++, D_01003548_3CE18);
        if (temp_a1 != NULL) {
            x = (D_803D5540 >> 3) % 32;
            for (i = 0; i < 32; i++) {
                temp_v0 = x + (i << 5);
                if (temp_a1[temp_v0+2] != 0) {
                    y1 = 0;
                    while ((temp_a1[temp_v0+2] & (1 << y1)) == 0) {
                        y1++;
                    }
                    y2 = 31;
                    while ((temp_a1[temp_v0+2] & (1 << y2)) == 0) {
                        y2--;
                    }
                    if (y1 == y2) {
                        // arg0, x, y, z, r, g, b
                        func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 200);  // turquoise
                    } else {
                        func_8032C0EC_73D79C(arg0, x, i, y1, 0, 200, 0);    // green
                        func_8032C0EC_73D79C(arg0, x, i, y2, 0, 0,   200);  // blue
                        phi_s0 = y1;
                        while (phi_s0 < y2) {
                            if ((temp_a1[temp_v0+2] & (1 << phi_s0)) == 0) {
                                // red
                                func_8032C0EC_73D79C(arg0, x, i, phi_s0, 255, 0, 0);
                            }
                            phi_s0++;
                        }
                    }
                }
            }
        }
    }
    // regalloc helper
    if (temp_a1 && temp_a1) {};
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73C890/func_8032BE28_73D4D8.s")
#endif

void func_8032C0EC_73D79C(Animal *arg0, s16 x, s16 y, s16 z, s16 r, s16 g, s16 b) {

    if (D_803D3434->usedModelViewMtxs < 240) {
        gDPSetPrimColor(D_801D9E8C++, 0, 0, r, g, b, 0xFF);
        guTranslate(&D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], (2.0 * (f32) x) - 30.0, (2.0 * (f32) y) - 30.0, (2.0 * (f32)z) - 32.0);
        gSPMatrix(D_801D9E8C++, &D_803D3434->modelViewMtx[D_803D3434->usedModelViewMtxs], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        D_803D3434->usedModelViewMtxs += 1;

        gSPDisplayList(D_801D9E8C++, D_0103B6F0);
        gSPPopMatrix(D_801D9E8C++, G_MTX_MODELVIEW);
    }
}
