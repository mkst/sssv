#include <ultra64.h>
#include "common.h"


// none of these functions look much fun

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034BD20_75D3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034C8F8_75DFA8.s")
// miles away
// void func_8034C8F8_75DFA8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *img, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 argA, s16 argB, u8 argC) {
//     s32 pad[6];
//
//     struct061 vtx[4];
//
//     s16 temp_v0_12;
//     s16 temp_v1_2;
//     s32 temp_a0;
//     s32 temp_lo;
//     s32 temp_v1;
//     s32 var_t8;
//     s32 var_v0;
//
//     // argC is either 0 or 1 (I think?)
//     switch (argC) {
//     case 0:
//         temp_v1 = arg0 - (s16) D_803F28E0[D_803F2A98].unk74;
//         temp_a0 = arg1 - (s16) D_803F28E0[D_803F2A98].unk78;
//
//         if (argB >= 0) {
//             var_v0 = ((temp_v1 * temp_v1) + (temp_a0 * temp_a0)) >> argB;
//         } else if (argB < 0) {
//             var_v0 = ((temp_v1 * temp_v1) + (temp_a0 * temp_a0)) << -argB;
//         }
//
//         // whats going on here?
//         if (var_v0 < 0x51000) {
//             if (var_v0 > 0x31000) {
//                 temp_lo = arg7 * (0x51000 - var_v0);
//                 var_t8 = temp_lo >> 0x11;
//                 if (temp_lo < 0) {
//                     s32 D_1FFFF;
//                     var_t8 = (s32) (D_1FFFF + temp_lo) >> 0x11;
//                 }
//                 arg7 = (s16) var_t8;
//             }
//         } else {
//             break;
//         }
//         // fallthrough
//     default:
//         gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, img);
//         gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
//         gDPLoadSync(D_801D9E90++);
//         gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 1023, 512);
//         gDPPipeSync(D_801D9E90++);
//         gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD);
//         gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(63), 4*(63));
//         gDPSetRenderMode(D_801D9E90++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
//         gDPSetCombineLERP(D_801D9E90++,
//             0, 0, 0, SHADE,
//             TEXEL0, 0, SHADE, 0,
//             0, 0, 0, SHADE,
//             TEXEL0, 0, SHADE, 0);
//         gDPPipeSync(D_801D9E90++);
//
//         temp_v0_12 = (D_80152C78[arg3 & 0xFF] >> 7) + 1;
//         temp_v1_2 = (D_80152C78[(arg3 + 64) & 0xFF] >> 7) + 1;
//
//         vtx[0].unk0 = (arg0 + ((arg5 * temp_v0_12) >> 8)) + ((arg6 * temp_v1_2) >> 8);
//         vtx[0].unk2 = (arg1 + ((arg5 * temp_v1_2) >> 8)) + (-(arg6 * temp_v0_12) >> 8);
//         vtx[0].unk4 = 0xFC0;
//         vtx[0].unk6 = 0xFC0;
//
//         vtx[1].unk0 = (arg0 - ((arg5 * temp_v0_12) >> 8)) + ((arg6 * temp_v1_2) >> 8);
//         vtx[1].unk2 = (arg1 - ((arg5 * temp_v1_2) >> 8)) + (-(arg6 * temp_v0_12) >> 8);
//         vtx[1].unk4 = 0;
//         vtx[1].unk6 = 0xFC0;
//
//         vtx[2].unk0 = (arg0 - ((arg5 * temp_v0_12) >> 8)) - ((arg6 * temp_v1_2) >> 8);
//         vtx[2].unk2 = (arg1 - ((arg5 * temp_v1_2) >> 8)) - (-(arg6 * temp_v0_12) >> 8);
//         vtx[2].unk4 = 0;
//         vtx[2].unk6 = 0;
//
//         vtx[3].unk0 = (arg0 + ((arg5 * temp_v0_12) >> 8)) - ((arg6 * temp_v1_2) >> 8);
//         vtx[3].unk2 = (arg1 + ((arg5 * temp_v1_2) >> 8)) - (-(arg6 * temp_v0_12) >> 8);
//         vtx[3].unk4 = 0xFC0;
//         vtx[3].unk6 = 0;
//
//         func_8034CCBC_75E36C(vtx, 4, arg2, arg7, arg8, arg9, argA);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034CCBC_75E36C.s")
// void func_8034CCBC_75E36C(struct061 arg0[], s16 numVtxs, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
//     struct061 spC8;
//     struct061 sp78;
//     s16 sp6A;
//     s16 sp68;
//
//     struct061 *tmp;
//     struct061 *var_s0;
//     struct061 *var_s2;
//
//     s16 x;
//     s16 maxX;
//     s16 minX;
//     s16 i;
//
//     minX = maxX = arg0[0].unk0;
//
//     for (i = 1; i < numVtxs; i++) {
//         if (arg0[i].unk0 <= minX) {
//             minX = arg0[i].unk0;
//         }
//         if (arg0[i].unk0 >= maxX) {
//             maxX = arg0[i].unk0;
//         }
//     }
//
//     var_s2 = arg0;
//
//     var_s0 = &spC8;
//     sp6A = numVtxs;
//
//     for (x = minX; (x & -64) != (maxX & -64); x = (x & -64) + 64) {
//         s16 tmp2 = (x & -64) + 64;
//         func_8034F3EC_760A9C(var_s2, &sp78, var_s0, sp6A, &sp68, &sp6A, tmp2);
//         func_8034CE88_75E538(&sp78, sp68, arg2, arg3, x >> 6, arg4, arg5, arg6);
//         tmp = var_s2;
//         var_s2 = var_s0;
//         var_s0 = tmp;
//     }
//     func_8034CE88_75E538(var_s2, sp6A, arg2, arg3, x >> 6, arg4, arg5, arg6);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034CE88_75E538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034D830_75EEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034F3EC_760A9C.s")
// void func_8034F3EC_760A9C(struct061 arg0[], struct061 arg1[], struct061 arg2[], s16 numVtxs, s16 *arg4, s16 *arg5, s16 arg6) {
//     s16 temp_t1;
//     s16 temp_t1_2;
//     s16 temp_t3;
//     s16 temp_t3_2;
//     s16 temp_t3_3;
//     s16 temp_t3_4;
//     s16 temp_t3_5;
//     s16 temp_t3_6;
//     s16 temp_t3_7;
//     s16 temp_t3_8;
//     s16 temp_t3_9;
//     s16 var_t0;
//     s16 var_t0_2;
//     s16 var_t0_3;
//     s16 var_t0_4;
//     s16 var_t4;
//     s16 var_t4_2;
//     s16 var_t4_3;
//     s16 i;
//     struct061 *temp_t2;
//
//     i = 1;
//     var_t0 = arg0->unk0;
//
//     if (arg0->unk0 < arg6) {
//         arg1->unk0 = arg0->unk0;
//         arg1->unk2 = arg0->unk2;
//         arg1->unk4 = arg0->unk4;
//         arg1->unk6 = arg0->unk6;
//         *arg4 = 1;
//         *arg5 = 0;
//     } else {
//         arg2->unk0 = arg0->unk0;
//         arg2->unk2 = arg0->unk2;
//         arg2->unk4 = arg0->unk4;
//         arg2->unk6 = arg0->unk6;
//         *arg4 = 0;
//         *arg5 = 1;
//     }
//
//     while (i < numVtxs) {
//         temp_t2 = &arg0[i];
//         if (temp_t2->unk0 < arg6) {
//             if (var_t0 < arg6) {
//                 (arg1 + *arg4)->unk0 = temp_t2->unk0;
//                 (arg1 + *arg4)->unk2 = temp_t2->unk2;
//                 (arg1 + *arg4)->unk4 = temp_t2->unk4;
//                 (arg1 + *arg4)->unk6 = temp_t2->unk6;
//                 *arg4 += 1;
//             } else {
//                 var_t4 = ABS(temp_t2->unk0 - arg6);
//                 var_t0_2 = ABS(var_t0 - arg6);
//                 temp_t3_3 = var_t4 + var_t0_2;
//
//                 arg1[*arg4].unk0 = arg6;
//                 arg1[*arg4].unk2 = ((((temp_t2 - 1)->unk2 * var_t4) + (var_t0_2 * temp_t2->unk2)) / temp_t3_3);
//                 arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4) + (var_t0_2 * temp_t2->unk4)) / temp_t3_3);
//                 arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4) + (var_t0_2 * temp_t2->unk6)) / temp_t3_3);
//
//                 arg2[*arg5].unk0 = arg1[*arg4].unk0;
//                 arg2[*arg5].unk2 = arg1[*arg4].unk2;
//                 arg2[*arg5].unk4 = arg1[*arg4].unk4;
//                 arg2[*arg5].unk6 = arg1[*arg4].unk6;
//                 *arg4 += 1;
//                 *arg5 += 1;
//
//                 arg1[*arg4].unk0 = temp_t2->unk0;
//                 arg1[*arg4].unk2 = temp_t2->unk2;
//                 arg1[*arg4].unk4 = temp_t2->unk4;
//                 arg1[*arg4].unk6 = temp_t2->unk6;
//                 *arg4 += 1;
//             }
//         } else {
//             if (var_t0 >= arg6) {
//                 arg2[*arg5].unk0 = temp_t2->unk0;
//                 arg2[*arg5].unk2 = temp_t2->unk2;
//                 arg2[*arg5].unk4 = temp_t2->unk4;
//                 arg2[*arg5].unk6 = temp_t2->unk6;
//                 *arg5 += 1;
//             } else {
//                 var_t4_2 = ABS(temp_t2->unk0 - arg6);
//                 var_t0_3 = ABS(var_t0 - arg6);
//                 temp_t3_6 = var_t4_2 + var_t0_3;
//
//                 arg1[*arg4].unk0 = arg6;
//                 arg1[*arg4].unk2 = ((((temp_t2 - 1)->unk2 * var_t4_2) + (var_t0_3 * temp_t2->unk2)) / temp_t3_6);
//                 arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4_2) + (var_t0_3 * temp_t2->unk4)) / temp_t3_6);
//                 arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4_2) + (var_t0_3 * temp_t2->unk6)) / temp_t3_6);
//
//                 arg2[*arg5].unk0 = arg1[*arg4].unk0;
//                 arg2[*arg5].unk2 = arg1[*arg4].unk2;
//                 arg2[*arg5].unk4 = arg1[*arg4].unk4;
//                 arg2[*arg5].unk6 = arg1[*arg4].unk6;
//                 *arg4 += 1;
//                 *arg5 += 1;
//
//                 arg2[*arg5].unk0 = temp_t2->unk0;
//                 arg2[*arg5].unk2 = temp_t2->unk2;
//                 arg2[*arg5].unk4 = temp_t2->unk4;
//                 arg2[*arg5].unk6 = temp_t2->unk6;
//                 *arg5 += 1;
//             }
//         }
//         var_t0 = temp_t2->unk0;
//         i++;
//     }
//
//     if (((arg0->unk0 < arg6) && (var_t0 >= arg6)) ||
//         ((arg0->unk0 >= arg6) && (var_t0 < arg6))) {
//         temp_t2 = &arg0[i];
//
//         var_t4_3 = ABS(arg0->unk0 - arg6);
//         var_t0_4 = ABS(var_t0 - arg6);
//         temp_t3_9 = var_t4_3 + var_t0_4;
//
//         arg1[*arg4].unk0 = arg6;
//         arg1[*arg4].unk2 = ((((temp_t2 - 1)->unk2 * var_t4_3) + (var_t0_4 * arg0->unk2)) / temp_t3_9);
//         arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4_3) + (var_t0_4 * arg0->unk4)) / temp_t3_9);
//         arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4_3) + (var_t0_4 * arg0->unk6)) / temp_t3_9);
//
//         arg2[*arg5].unk0 = (arg1 + *arg4)->unk0;
//         arg2[*arg5].unk2 = (arg1 + *arg4)->unk2;
//         arg2[*arg5].unk4 = (arg1 + *arg4)->unk4;
//         arg2[*arg5].unk6 = (arg1 + *arg4)->unk6;
//
//         *arg4 += 1;
//         *arg5 += 1;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_8034FCFC_7613AC.s")
// void func_8034FCFC_7613AC(struct061 *arg0, struct061 *arg1, struct061 *arg2, s16 numVtxs, s16 *arg4, s16 *arg5, s16 arg6) {
//     s16 temp_t1;
//     s16 temp_t1_2;
//     s16 temp_t3;
//     s16 temp_t3_2;
//     s16 temp_t3_3;
//     s16 temp_t3_4;
//     s16 temp_t3_5;
//     s16 temp_t3_6;
//     s16 temp_t3_7;
//     s16 temp_t3_8;
//     s16 temp_t3_9;
//     s16 var_t0;
//     s16 var_t0_2;
//     s16 var_t0_3;
//     s16 var_t0_4;
//     s16 var_t4;
//     s16 var_t4_2;
//     s16 var_t4_3;
//     s16 i;
//     struct061 *temp_t2;
//
//     i = 1;
//     var_t0 = arg0->unk2;
//
//     if (arg0->unk2 < arg6) {
//         arg1->unk0 = arg0->unk0;
//         arg1->unk2 = arg0->unk2;
//         arg1->unk4 = arg0->unk4;
//         arg1->unk6 = arg0->unk6;
//         *arg4 = 1;
//         *arg5 = 0;
//     } else {
//         arg2->unk0 = arg0->unk0;
//         arg2->unk2 = arg0->unk2;
//         arg2->unk4 = arg0->unk4;
//         arg2->unk6 = arg0->unk6;
//         *arg4 = 0;
//         *arg5 = 1;
//     }
//
//     while (i < numVtxs) {
//         temp_t2 = (arg0 + i);
//         if (temp_t2->unk2 < arg6) {
//             if (var_t0 < arg6) {
//                 (arg1 + *arg4)->unk0 = temp_t2->unk0;
//                 (arg1 + *arg4)->unk2 = temp_t2->unk2;
//                 (arg1 + *arg4)->unk4 = temp_t2->unk4;
//                 (arg1 + *arg4)->unk6 = temp_t2->unk6;
//                 *arg4 += 1;
//             } else {
//                 var_t4 = ABS(temp_t2->unk2 - arg6);
//                 var_t0_2 = ABS(var_t0 - arg6);
//                 temp_t3_3 = var_t4 + var_t0_2;
//
//                 arg1[*arg4].unk2 = arg6;
//                 arg1[*arg4].unk0 = ((((temp_t2 - 1)->unk0 * var_t4) + (var_t0_2 * temp_t2->unk0)) / temp_t3_3);
//                 arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4) + (var_t0_2 * temp_t2->unk4)) / temp_t3_3);
//                 arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4) + (var_t0_2 * temp_t2->unk6)) / temp_t3_3);
//
//                 arg2[*arg5].unk0 = arg1[*arg4].unk0;
//                 arg2[*arg5].unk2 = arg1[*arg4].unk2;
//                 arg2[*arg5].unk4 = arg1[*arg4].unk4;
//                 arg2[*arg5].unk6 = arg1[*arg4].unk6;
//                 *arg4 += 1;
//                 *arg5 += 1;
//
//                 arg1[*arg4].unk0 = temp_t2->unk0;
//                 arg1[*arg4].unk2 = temp_t2->unk2;
//                 arg1[*arg4].unk4 = temp_t2->unk4;
//                 arg1[*arg4].unk6 = temp_t2->unk6;
//                 *arg4 += 1;
//             }
//         } else {
//             if (var_t0 >= arg6) {
//                 arg2[*arg5].unk0 = temp_t2->unk0;
//                 arg2[*arg5].unk2 = temp_t2->unk2;
//                 arg2[*arg5].unk4 = temp_t2->unk4;
//                 arg2[*arg5].unk6 = temp_t2->unk6;
//                 *arg5 += 1;
//             } else {
//                 var_t4_2 = ABS(temp_t2->unk2 - arg6);
//                 var_t0_3 = ABS(var_t0 - arg6);
//                 temp_t3_6 = var_t4_2 + var_t0_3;
//
//                 arg1[*arg4].unk2 = arg6;
//                 arg1[*arg4].unk0 = ((((temp_t2 - 1)->unk0 * var_t4_2) + (var_t0_3 * temp_t2->unk0)) / temp_t3_6);
//                 arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4_2) + (var_t0_3 * temp_t2->unk4)) / temp_t3_6);
//                 arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4_2) + (var_t0_3 * temp_t2->unk6)) / temp_t3_6);
//
//                 arg2[*arg5].unk0 = arg1[*arg4].unk0;
//                 arg2[*arg5].unk2 = arg1[*arg4].unk2;
//                 arg2[*arg5].unk4 = arg1[*arg4].unk4;
//                 arg2[*arg5].unk6 = arg1[*arg4].unk6;
//                 *arg4 += 1;
//                 *arg5 += 1;
//
//                 arg2[*arg5].unk0 = temp_t2->unk0;
//                 arg2[*arg5].unk2 = temp_t2->unk2;
//                 arg2[*arg5].unk4 = temp_t2->unk4;
//                 arg2[*arg5].unk6 = temp_t2->unk6;
//                 *arg5 += 1;
//             }
//         }
//         var_t0 = temp_t2->unk2;
//         i++;
//     }
//
//     if (((arg0->unk2 < arg6) && (var_t0 >= arg6)) ||
//         ((arg0->unk2 >= arg6) && (var_t0 < arg6))) {
//         temp_t2 = (arg0 + i);
//
//         var_t4_3 = ABS(arg0->unk2 - arg6);
//         var_t0_4 = ABS(var_t0 - arg6);
//         temp_t3_9 = var_t4_3 + var_t0_4;
//
//         arg1[*arg4].unk2 = arg6;
//         arg1[*arg4].unk0 = ((((temp_t2 - 1)->unk0 * var_t4_3) + (var_t0_4 * arg0->unk0)) / temp_t3_9);
//         arg1[*arg4].unk4 = ((((temp_t2 - 1)->unk4 * var_t4_3) + (var_t0_4 * arg0->unk4)) / temp_t3_9);
//         arg1[*arg4].unk6 = ((((temp_t2 - 1)->unk6 * var_t4_3) + (var_t0_4 * arg0->unk6)) / temp_t3_9);
//
//         arg2[*arg5].unk0 = (arg1 + *arg4)->unk0;
//         arg2[*arg5].unk2 = (arg1 + *arg4)->unk2;
//         arg2[*arg5].unk4 = (arg1 + *arg4)->unk4;
//         arg2[*arg5].unk6 = (arg1 + *arg4)->unk6;
//
//         *arg4 += 1;
//         *arg5 += 1;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_75D3D0/func_80350600_761CB0.s")

void func_80351390_762A40(s16 numVtxs, struct061 arg1[], s16 alpha, s16 arg3, s16 arg4, s32 arg5, s16 red, s16 green, s16 blue, s32 arg9, s32 argA, s32 argB, s32 argC) {
    s16 spD6;
    s16 spD4;

    s32 tmp;
    s16 i;
    s16 var_t1;
    s16 pad[2];


    if (numVtxs > 2) {
        if (ABS(MAX(MAX(arg9, argC), MAX(argA, argB)) - MIN(MIN(arg9, argC), MIN(argA, argB))) <= 192) {

            var_t1 = ((ABS((s16) D_803F28E0[D_803F2A98].unk7C - (s16) ((arg9 + argC) >> 1)) * 2) + 0x200) >> 8;
            if (var_t1 > 4) {
                var_t1 = (var_t1 >> 1) + 2;
            }

            if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
                gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

                for (i = 0; i < numVtxs; i++) {
                    spD6 = arg1[i].unk0 - (arg3 << 6);
                    spD4 = arg1[i].unk2 - (arg4 << 6);
                    tmp = arg9 + ((((argB - arg9) * spD6) + ((argA - arg9) * spD4)) >> 6);
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = tmp + var_t1;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
                    D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
                    D_80204278->usedVtxs++;
                }

                for (i = 2; i < numVtxs; i++) {
                    if (i < (numVtxs - 1)) {
                        gSP1Quadrangle(
                            D_801D9E90++,
                            0,
                            i - 1,
                            i,
                            i + 1,
                            0);
                        i++; // 2 vtx were processed
                    } else {
                        gSP1Triangle(
                            D_801D9E90++,
                            0,
                            i - 1,
                            i,
                            0);
                    }
                }
                gDPPipeSync(D_801D9E90++);
            }
        }
    }
}

void func_80351A44_7630F4(s16 numVtxs, struct061 arg1[], s16 alpha, s16 arg3, s16 arg4, s16 red, s16 green, s16 blue) {
    s16 pad[2];

    s16 temp_v0;
    s16 var_a3;
    s16 temp_a0;
    s16 i;

    s16 sp82;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;

    if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
        func_80299640_6AACF0(arg3, arg4, &sp82, &sp80, &sp7E, &sp7C);
        gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);

        for (i = 0; i < numVtxs; i++) {
            func_80299640_6AACF0(arg3, arg4, &sp82, &sp80, &sp7E, &sp7C);

            temp_v0 = arg1[i].unk0 - (arg3 << 6);
            temp_a0 = arg1[i].unk2 - (arg4 << 6);
            if ((temp_v0 + temp_a0) < 0x40) {
                var_a3 = sp82 + ((((sp7E - sp82) * (0  + temp_v0)) + ((sp80 - sp82) * (0  + temp_a0))) >> 6);
            } else {
                var_a3 = sp7C + ((((sp80 - sp7C) * (64 - temp_v0)) + ((sp7E - sp7C) * (64 - temp_a0))) >> 6);
            }

            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = var_a3;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
            D_80204278->usedVtxs++;
        }

        for (i = 2; i < numVtxs; i++) {
            if (i < (numVtxs - 1)) {
                gSP1Quadrangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    i + 1,
                    0);
                i++; // 2 vtx were processed
            } else {
                gSP1Triangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    0);
            }
        }
        gDPPipeSync(D_801D9E90++);
    }
}

void func_80351EE8_763598(s16 numVtxs, struct061 arg1[], s16 arg2, s16 alpha, s16 red, s16 green, s16 blue) {
    s16 var_a3;
    s32 var_v1;

    s16 i;

    var_v1 = ABS((s16) (s32) D_803F28E0[D_803F2A98].unk7C - arg2);
    var_a3 = ((var_v1 * 2) + 0x80) >> 7;
    if (var_a3 >= 5) {
        var_a3 = (var_a3 / 2) + 4;
    }

    if ((D_80204278->usedVtxs + numVtxs) <= 1000) {
        gSPVertex(D_801D9E90++, &D_80204278->unk2C570[D_80204278->usedVtxs], numVtxs, 0);
        for (i = 0; i < numVtxs; i++) {
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[0] = arg1[i].unk0;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[1] = arg1[i].unk2;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.ob[2] = var_a3 + arg2;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[0] = arg1[i].unk4;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.tc[1] = arg1[i].unk6;

            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[0] = red;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[1] = green;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[2] = blue;
            D_80204278->unk2C570[D_80204278->usedVtxs].v.cn[3] = alpha;
            D_80204278->usedVtxs++;
        }

        for (i = 2; i < numVtxs; i++) {
            if (i < (numVtxs - 1)) {
                gSP1Quadrangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    i + 1,
                    0);
                i++; // 2 vtx were processed
            } else {
                gSP1Triangle(
                    D_801D9E90++,
                    0,
                    i - 1,
                    i,
                    0);
            }
        }
        gDPPipeSync(D_801D9E90++);
    }
}
