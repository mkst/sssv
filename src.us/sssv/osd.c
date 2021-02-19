#include <ultra64.h>

#include "common.h"

extern f64 D_803BE950; // = 0.6;

extern u8 D_01004600[];
extern u8 D_01004650[];
extern u8 D_0103BB20[];
extern u8 D_0103C720[];
extern u8 D_0103D520[];
extern u8 D_0103D320[];
extern u8 D_01029DD0[];

// osd_draw_health_and_power_bars
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/osd/func_80348230_7598E0.s")
// void func_80348230_7598E0(s32 arg0) {
//     s16 spF2;
//     s16 temp_a0;
//     s16 temp_t0;
//     s16 temp_t0_2;
//     s32 temp_t4;
//     s32 temp_t6;
//     Animal *temp_ra;
//     Animal *phi_ra;
//     s32 phi_t0;
//     s16 phi_t0_2;
//     Gfx **phi_v1;
//     s32 *phi_t1;
//     s32 phi_t0_3;
//
//     D_803F2D04.unk0 = D_803F2D04.unk0 + 1;
//     D_803F2D04.unk2D04 = (D_803F2D04.unk0 + 1) & 0xF;
//     D_803F2CEC = 0x60;
//     D_803F2CF0 = arg0 * 4;
//     if ((D_803F2CF0 >> 2) < gScreenHeight) {
//
//         gSPDisplayList(D_801D9E7C++, D_01004650);
//         gDPSetCycleType(D_801D9E7C++, G_CYC_1CYCLE);
//
//         gDPSetRenderMode(D_801D9E7C++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
//         gDPSetDepthSource(D_801D9E7C++, G_ZS_PRIM);
//         gDPSetPrimDepth(D_801D9E7C++, 0, 0);
//         gDPSetTexturePersp(D_801D9E7C++, G_TP_NONE);
//         gDPSetTextureLOD(D_801D9E7C++, G_TL_TILE);
//         gDPPipeSync(D_801D9E7C++);
//
//         gDPLoadTextureBlock(D_801D9E7C++, D_0103BB20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         gDPPipeSync(D_801D9E7C++);
//
//         gSPTextureRectangle(D_801D9E7C++, D_803F2CEC, D_803F2CF0 - 64, D_803F2CEC + 192, D_803F2CF0 + 64, G_TX_RENDERTILE, 0, 0, 1024, 1024);
//         gDPPipeSync(D_801D9E7C++);
//
//         gDPLoadTextureBlock(D_801D9E7C++, D_0103C720, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         gDPPipeSync(D_801D9E7C++);
//
//         gSPTextureRectangle(D_801D9E7C++, D_803F2CEC + 192, D_803F2CF0 - 64, D_803F2CEC + 384, D_803F2CF0 + 64, G_TX_RENDERTILE, 0, 0, 1024, 1024);
//         gDPPipeSync(D_801D9E7C++);
//
//         temp_ra = &D_801DDD8C[gCurrentAnimalIndex].unk0;
//
//         gDPPipeSync(D_801D9E7C++);
//
//         gDPSetRenderMode(D_801D9E7C++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
//         gDPSetTextureFilter(D_801D9E7C++, G_TF_POINT);
//
//         gDPLoadTextureBlock(D_801D9E7C++, D_0103D520, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         gSPTextureRectangle(D_801D9E7C++, D_803F2CEC + 0x2C, D_803F2CF0 + 4, D_803F2CEC + (((temp_ra->skillAEnergy / 16) * 12) / 16) + 0x2C, D_803F2CF0 + 0x30, G_TX_RENDERTILE, 0, 0, 1024, 1024);
//         // temp_v0_43->unk0 = (s32) ((((D_803F2CEC + (s16) ((s32) (s16) ((s16) ((s32) temp_ra->unk2E0 / 0x10) * 0xC) / 0x10) + 0x2C) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 + 0x30) & 0xFFF));
//         // temp_v0_43->unk4 = (s32) ((((D_803F2CEC + 0x2C) & 0xFFF) << 0xC) | ((D_803F2CF0 + 4) & 0xFFF));
//
//         gDPLoadTextureBlock(D_801D9E7C++, D_0103D320, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
//         gSPTextureRectangle(D_801D9E7C++, D_803F2CEC + 0x14, D_803F2CF0 - 0x30, D_803F2CEC + (((temp_ra->skillBEnergy / 16) * 12) / 16) + 0x14, D_803F2CF0 - 4, G_TX_RENDERTILE, 0, 0, 1024, 1024);
//         // temp_v0_53->unk0 = (s32) ((((D_803F2CEC + ((s32) (s16) ((s16) ((s32) temp_ra->unk2E4 / 0x10) * 0xC) / 0x10) + 0x14) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 4) & 0xFFF));
//         // temp_v0_53->unk4 = (s32) ((((D_803F2CEC + 0x14) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x30) & 0xFFF));
//
//         gDPSetTextureFilter(D_801D9E7C++, G_TF_BILERP);
//         gSPDisplayList(D_801D9E7C++, D_01004600);
//
//         // TODO: replace this with a macro
//         gDPSetTextureImage(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01029DD0);
//         gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD);
//         gDPLoadSync(D_801D9E7C++);
//         gDPLoadBlock(D_801D9E7C++, G_TX_LOADTILE, 0, 0, 31, 2048);
//         gDPPipeSync(D_801D9E7C++);
//         gDPSetTile(D_801D9E7C++, G_IM_FMT_I, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 3, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 3, G_TX_NOLOD);
//         gDPSetTileSize(D_801D9E7C++, G_TX_RENDERTILE, 0, 0, 4*(15), 4*(7));
//
//         temp_a0 = temp_ra->health;
//         phi_t0 = (s32) temp_t0;
//         if ((s32) temp_a0 < (s32) temp_t0) {
//             if ((temp_a0 + 1) < (s32) temp_t0) {
//                 D_803F2CE8 = (s16) (temp_t0 - 2);
//             } else {
//                 D_803F2CE8 = (s16) (temp_t0 - 1);
//             }
//         }
//         if (phi_t0 < (s32) temp_ra->health) {
//             phi_t0_2 = (s16) phi_t0;
//             phi_ra = temp_ra;
//             if (D_803F2CE6 != 0) {
//                 func_8032CD20_73E3D0(0xC, 0x72, (s16) ((phi_t0 * 0x10) + 0x3000), 0, (f32) (((f64) phi_t0 / 200.0) + D_803BE950));
//                 phi_t0_2 = D_803F2CE8;
//                 phi_ra = &D_801DDD8C[gCurrentAnimalIndex].unk0;
//             }
//             D_803F2CE8 = (s16) (phi_t0_2 + 1);
//             phi_t1 = &D_803F2CE8;
//         } else {
//             D_803F2CE6 = (u8)1;
//             phi_v1 = &D_801D9E7C; // could this be uninitialised?
//             phi_t1 = &D_803F2CE8;
//             phi_ra = temp_ra;
//         }
//         temp_t4 = (phi_ra->health << 17) >> 16;
//         if ((s32) temp_a0 >= 17) {
//             gDPSetPrimColor((*phi_v1)++, 0, 0, 0x08, 0x5F, 0x00, 0xD2);
//             gDPSetEnvColor((*phi_v1)++, 0x23, 0xDC, 0x00, 0xD2);
//         } else if (D_803F2D04.unk0 < 8) {
//             gDPSetPrimColor((*phi_v1)++, 0, 0, 0x82, 0x00, 0x00, 0xD2);
//             gDPSetEnvColor((*phi_v1)++, 0xEB, 0x00, 0x00, 0xD2);
//         } else {
//             gDPSetPrimColor((*phi_v1)++, 0, 0, 0x08, 0xA0, 0x00, 0xD2);
//             gDPSetEnvColor((*phi_v1)++, 0x23, 0xFA, 0x00, 0xD2);
//         }
//         temp_t0_2 = *phi_t1;
//         temp_a0 = &D_801DDD8C[gCurrentAnimalIndex].unk0->health;
//         if (temp_a0 < temp_t0_2) {
//             if (temp_t4 > 0) {
//                 gSPTextureRectangle((*phi_v1)++, D_803F2CEC + 0x54, D_803F2CF0 - 0x1C, temp_t4 + D_803F2CEC + 0x54, D_803F2CF0 - 8, G_TX_RENDERTILE, 0, 0, 0, 1723);
//                 // temp_v0_70->unk0 = (s32) ((((temp_t4 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 8) & 0xFFF));
//                 // temp_v0_70->unk4 = (s32) ((((D_803F2CEC + 0x54) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x1C) & 0xFFF));
//                 // temp_v0_71->unk0 = B400000000000000;
//                 // temp_v0_72->unk0 = B3000000000006BB;
//                 gDPPipeSync((*phi_v1)++);
//             }
//             gDPSetPrimColor((*phi_v1)++, 0, 0, 0x82, 0x00, 0x00, 0x78);
//             gDPSetEnvColor((*phi_v1)++, 0xEB, 0x00, 0x00, 0x78);
//             gSPTextureRectangle((*phi_v1)++, temp_t4 + D_803F2CEC + 0x54, D_803F2CF0 - 0x1C, temp_t4 + D_803F2CEC + (((temp_t0_2 - temp_a0) << 0x11) >> 0x10) + 0x54, D_803F2CF0 - 8, G_TX_RENDERTILE, 0, 0, 0, 1723);
//             // temp_v0_76->unk0 = (s32) ((((temp_t4 + D_803F2CEC + ((s32) ((temp_t0_2 - temp_a0_2) << 0x11) >> 0x10) + 0x54) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 8) & 0xFFF));
//             // temp_v0_76->unk4 = (s32) ((((temp_t4 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x1C) & 0xFFF));
//             // temp_v0_77->unk0 = B400000000000000;
//             // temp_v0_78->unk0 = B3000000000006BB;
//             gDPPipeSync((*phi_v1)++);
//
//             temp_a0 = &D_801DDD8C[gCurrentAnimalIndex].unk0->health;
//         }
//
//         if (temp_t0_2 < temp_a0) {
//             temp_t6 = (s32) (temp_t0_2 << 0x11) >> 0x10;
//             if (temp_t4 > 0) {
//                 gSPTextureRectangle((*phi_v1)++, D_803F2CEC + 0x54, D_803F2CF0 - 0x1C, temp_t6 + D_803F2CEC + 0x54, D_803F2CF0 - 8, G_TX_RENDERTILE, 0, 0, 0, 1723);
//                 // temp_v0_80->unk0 = (s32) ((((temp_t6 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 8) & 0xFFF));
//                 // temp_v0_80->unk4 = (s32) ((((D_803F2CEC + 0x54) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x1C) & 0xFFF));
//                 // temp_v0_81->unk0 = B400000000000000;
//                 // temp_v0_82->unk0 = B3000000000006BB;
//                 gDPPipeSync((*phi_v1)++);
//             }
//             gDPSetPrimColor((*phi_v1)++, 0, 0, 0x08, 0x5F, 0x00, 0x78);
//             gDPSetEnvColor((*phi_v1)++, 0x23, 0xDC, 0x00, 0x78);
//             gSPTextureRectangle((*phi_v1)++, temp_t6 + D_803F2CEC + 0x54, D_803F2CF0 - 0x1C, temp_t4 + D_803F2CEC + 0x54, D_803F2CF0 - 8, G_TX_RENDERTILE, 0, 0, 0, 1723);
//             // temp_v0_86->unk0 = (s32) ((((temp_t4 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 8) & 0xFFF));
//             // temp_v0_86->unk4 = (s32) ((((temp_t6 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x1C) & 0xFFF));
//             // temp_v0_87->unk0 = B400000000000000;
//             // temp_v0_88->unk0 = B3000000000006BB;
//             gDPPipeSync((*phi_v1)++);
//             temp_t0_2 = D_803F2CE8;
//             temp_a0 = &D_801DDD8C[gCurrentAnimalIndex].unk0->health;
//         }
//         if ((temp_t0_2 == temp_a0) && (temp_t4 > 0)) {
//             gSPTextureRectangle((*phi_v1)++, D_803F2CEC + 0x54, D_803F2CF0 - 0x1C, temp_t4 + D_803F2CEC + 0x54, D_803F2CF0 - 8, G_TX_RENDERTILE, 0, 0, 2, 1723);
//             // temp_v0_90->unk0 = (s32) ((((temp_t4 + D_803F2CEC + 0x54) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 - 8) & 0xFFF));
//             // temp_v0_90->unk4 = (s32) ((((D_803F2CEC + 0x54) & 0xFFF) << 0xC) | ((D_803F2CF0 - 0x1C) & 0xFFF));
//             // temp_v0_91->unk0 = B400000000000000;
//             // temp_v0_92->unk0 = B3000000000206BB;
//             gDPPipeSync((*phi_v1)++);
//         }
//         func_803493C8_75AA78();
//     }
// }

// osd_draw_score
void func_803491F0_75A8A0(void) {
    sprintf(&D_803F2D3E, &D_803BE940, D_803F2D30.score);
    select_font(0, 3, 1, 0);
    func_801304EC(&D_801D9E7C, &D_803F2D3E, gScreenWidth - 34, ((D_803F2CF0 >> 2) - 10));
}

void func_80349278_75A928(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/osd/func_80349280_75A930.s")
// NON-MATCHING: JUSTREG
// void func_80349280_75A930(Animal *arg0, s16 arg1) {
//     s32 temp_a2;
//     s32 temp_v1;
//
//     if (((arg0->unk16C->unk80 << 18) < 0) && ((arg0->unk366== 3) || (arg0->unk366 == 4) || (arg0->unk366 == 1))) {
//         if (arg1 != 0) {
//             temp_a2 = arg1 >> 2;
//             temp_v1 = temp_a2 + 4;
//             temp_a2 = arg0->unk36B + temp_a2;
//             if (temp_v1 < temp_a2) {
//                 arg0->unk36B = temp_a2;
//             } else {
//                 arg0->unk36B = temp_v1;
//             }
//         }
//         if (arg0 != D_801DDD8C[gCurrentAnimalIndex].unk0) {
//             if (arg0 == D_803F2CF8.animal) {
//                 if ((arg0->health - arg1) < 0) {
//                     D_803F2CF8.unk6 = 0;
//                 } else {
//                     D_803F2CF8.unk6 = arg0->health - arg1;
//                 }
//                 D_803F2CF8.unkA = 64;
//             } else if ((D_803F2CF8.animal == NULL) || ((arg1 != 0) && ((D_803F2CF8.unk8 == D_803F2CF8.unk6) || (D_803F2CF8.animal->unk16C->unk7C < arg0->unk16C->unk7C)))) {
//                 D_803F2CF8.animal = arg0;
//                 D_803F2CF8.health = arg0->health;
//                 if (arg0->health - arg1 < 0) {
//                     D_803F2CF8.unk6 = 0;
//                 } else {
//                     D_803F2CF8.unk6 = arg0->health - arg1;
//                 }
//                 D_803F2CF8.unk8 = D_803F2CF8.health;
//                 D_803F2CF8.unkA = 64;
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/osd/func_803493C8_75AA78.s")
// NON-MATCHING: few things wrong here..
// void func_803493C8_75AA78(void) {
//     s32 spC;
//     s32 temp_t7;
//     s32 temp_t9;
//
//     if (D_803F2CF8.animal != NULL) {
//
//         gDPPipeSync(D_801D9E7C++);
//
//         if (D_803F2CF8.unkA >= 33) {
//             spC = 32;
//         } else {
//             spC = D_803F2CF8.unkA;
//         }
//
//         temp_t9 = (spC * 6) & 0xFF; // blue alpha
//
//         // temp_v0_2->unk4 = (s32) (temp_t9 | 0x00508200); // dark blue
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x00, 0x50, 0x82, temp_t9);
//         // temp_v0_3->unk4 = (s32) (temp_t9 | 0x0050EB00); // light blue
//         gDPSetEnvColor(D_801D9E7C++, 0x00, 0x50, 0xEB, temp_t9);
//
//         // E4000000000C4000B400000000000000B300000000000400
//         gSPTextureRectangle(D_801D9E7C++, 4*(49), D_803F2CF0 + 0xC, D_803F2CF8.unk8 + 0xC4, D_803F2CF0 + 0x18, G_TX_RENDERTILE, 0, 0, 0, 1024);
//         gDPPipeSync(D_801D9E7C++);
//
//         temp_t7 = (spC * 5) & 0xFF; // pink alpha
//         // temp_v0_8->unk4 = (s32) (temp_t7 | 0xC8006400); // dark pink
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xC8, 0x00, 0x64, temp_t7);
//         // temp_v0_9->unk4 = (s32) (temp_t7 | 0xFF008000); // light pink
//         gDPSetEnvColor(D_801D9E7C++, 0xFF, 0x00, 0x80, temp_t7);
//
//         // E400000000000000B400000000000000B300000000000400
//         gSPTextureRectangle(D_801D9E7C++, D_803F2CF8.unk8 + 0xC4, D_803F2CF0 + 0xC, D_803F2CF8.unk8 + (D_803F2CF8.health - D_803F2CF8.unk8) + 0xC4, D_803F2CF0 + 0x18, G_TX_RENDERTILE, 0, 0, 0, 1024);
//
//         if (D_803F2CF8.unk6 < D_803F2CF8.unk8) {
//             D_803F2CF8.unk8 -= 1;
//         } else if ( D_803F2CF8.unkA > 0) {
//             D_803F2CF8.unkA -= 1;
//         } else {
//             D_803F2CF8.animal = 0;
//         }
//         gDPPipeSync(D_801D9E7C++);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/osd/func_8034967C_75AD2C.s")
// MATCHING: won't ok until .rodata complete
// void func_8034967C_75AD2C(void) {
//     D_803F2CDF = 0;
//     D_803F2CDA = 0;
//
//     switch (D_803F2CDC - 1) {
//         case 3:
//             D_803F2CDD = 5;
//             break;
//         case 4:
//             D_803F2CDD = 5;
//             break;
//         case 0:
//             D_803F2CDD = 2;
//             break;
//         case 1:
//             D_803F2CDD = 2;
//             break;
//         case 6:
//             D_803F2CDD = 8;
//             break;
//         case 7:
//             D_803F2CDD = 8;
//             break;
//     }
//     D_803F2CDC = 0;
// }

void func_80349720_75ADD0(void) {
    D_803F2CDF = 1;
    func_80349D34_75B3E4();
}

void func_80349748_75ADF8(void) {
    if (D_803F2CDC == 0) {
        D_803F2CDA = 0;
        D_803F2CDC = 8;
    }
    D_803F2CDE = 1;
}

void func_80349778_75AE28(void) {
    if (((D_803F2CDC == 7) || (D_803F2CDC == 8)) && (D_803F2CDD == 0)) {
        D_803F2CDC = 9;
        D_803F2CDA = 0;
    }
    else if (D_803F2CDC == 8) {
        D_803F2CDD = 9;
    }
    D_803F2CDE = 0;
}

void func_803497DC_75AE8C(void) {
    D_803F2CDC = 8;
    D_803F2CDD = 0;
    D_803F2CD0 = 0;
    D_803F2CD2 = 0;
    D_803F2CD4 = 0;
    D_803F2CD6 = -1;
    D_803F2CD8 = 30;
    D_803F2CDA = 0;
    D_803F2CDE = 1;
    D_803F2CDF = 1;
    D_803F2CE0 = 0;
    D_803F2CF2 = 1;
    func_80128FB4(&D_803F2CF8, 12);
}

u8 func_80349874_75AF24(void) {
    return (D_803F2CDF != 0) && (D_803F2CDC == 0 ||
                                 D_803F2CDC == 1 ||
                                 D_803F2CDC == 7 ||
                                 ((D_803F2CDC == 6) && (D_803F2CDA == 0)) ||
                                 ((D_803F2CDC == 3) && (D_803F2CDA == 0))
                                );
}

void func_80349900_75AFB0(s32 arg0, u16 arg1) {
    D_803F2CE0 = arg0;
    D_803F2CD0 = arg1 * 30;
    D_803F2CD4 = 0;
    D_803F2CDA = 0;
    D_803F2CE4 = func_8012E78C(D_803F2CE0, 10.0f, 10.0f, 0xC) - 0xC;
    if (D_803F2CDC == 0) {
        D_803F2CDC = 5;
        D_803F2CDD = 0;
    } else if (D_803F2CDC == 1) {
        D_803F2CDC = 4;
        D_803F2CDD = 0;
    } else if (D_803F2CDC == 7) {
        D_803F2CDC = 9;
        D_803F2CDD = 5;
    } else if (((D_803F2CDC == 6) || (D_803F2CDC == 3)) && (D_803F2CDA == 0)) {
        D_803F2CDC = 4;
        D_803F2CDD = 0;
    }
}

// dupe of func_80349874_75AF24
u8 func_80349A14_75B0C4(void) {
    return (D_803F2CDF != 0) && (D_803F2CDC == 0 ||
                                 D_803F2CDC == 1 ||
                                 D_803F2CDC == 7 ||
                                 ((D_803F2CDC == 6) && (D_803F2CDA == 0)) ||
                                 ((D_803F2CDC == 3) && (D_803F2CDA == 0))
                                );
}

void func_80349AA0_75B150(u16 arg0) {
    D_803F2CDA = 0;
    D_803F2CD2 = arg0;
    D_803F2CDD = 0;
    if (arg0 == 0) {
        D_803F2CD4 = D_803F2CD8;
        if (D_803F2CDC == 1) {
            D_803F2CDC = 3;
        }
    } else if (D_803F2CDC == 0) {
        D_803F2CDC = 2;
        D_803F2CD4 = 0;
    } else if (D_803F2CDC == 7) {
        D_803F2CDC = 9;
        D_803F2CDD = 2;
        D_803F2CD4 = 0;
    } else if (((D_803F2CDC == 6) || (D_803F2CDC == 3)) && (D_803F2CDA == 0)) {
        D_803F2CDC = 1;
        D_803F2CD4 = 0;
    }
}

// osd_draw_timer
void func_80349B84_75B234(u16 arg0) {
    s32 time;
    u8 str[40]; // how long is a piece of string

    time = D_803F2CD2;
    if (time > 0) {
        if (time < 60) {
            sprintf(&D_803A8344, &D_803BE944, time); // "%d"
        } else {
            sprintf(&D_803A8344, &D_803BE948, time / 60, time % 60); // "%d:%02d"
        }
    }
    func_801308B4(&D_803A8344, &str);
    func_8012C1F0(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    select_font(0, 0, 1, 0);
    // write string centered
    func_8012C978(&D_801D9E7C, &str, gScreenWidth >> 1, arg0, 16.0f, 16.0f);
}

void func_80349CA4_75B354(u16 arg0) {
    func_8012C1F0(&D_801D9E7C);
    set_menu_text_color(0xFF, 0xFF, 0, 0xFF);
    select_font(0, 0, 1, 0);
    func_8012EB4C(&D_801D9E7C, D_803F2CE0, (gScreenWidth >> 1), arg0, 16.0f, 16.0f, 0x10);
}

void func_80349D34_75B3E4(void) {

    if (D_803F2CDF == 0) {
        D_803F2CDC = 0;
    } else if ((D_803F2CDC == 6) && (D_803F2CD2 > 0)) {
        D_803F2CDC = 2;
    } else if (D_803F2CDD != 0) {
        D_803F2CDC = D_803F2CDD;
        D_803F2CDD = 0;
    } else if (D_803F2CDE != 0) {
        D_803F2CDC = 8;
    } else {
        D_803F2CDC = 0;
    }
    D_803F2CDA = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/osd/func_80349DCC_75B47C.s")
// NON-MATCHING: starts ok-ish, falls apart towards the end
// void func_80349DCC_75B47C(s16 arg0) {
//     s16 temp_t6;
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s16 temp_v0_3;
//     s16 temp_v0_4;
//     s16 temp_v0_5;
//     s16 temp_v0_6;
//     s16 temp_v0_7;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     s16 phi_a0;
//     s16 phi_a0_2;
//     s16 phi_a0_3;
//     s32 phi_a1;
//     s16 phi_a0_4;
//     s16 phi_a0_5;
//     s16 phi_a1_2;
//     s16 phi_a1_3;
//     s16 phi_a0_6;
//     s16 phi_a1_4;
//
//     if ((arg0 == 0) && (D_803F2D10.unk0 == 0)) {
//         if ((s32) D_803F2CD2 > 0) {
//             D_803F2CD4 += 1;
//             if ((s32) D_803F2CD4 >= (s32) D_803F2CD8) {
//                 D_803F2CD4 = (u16)0;
//                 D_803F2CD2 +=  D_803F2CD6;
//             }
//         }
//     }
//     switch (D_803F2CDC) {
//         case 1:
//             if (arg0 == 0) {
//                 if (D_803F2CD2 <= 0) {
//                     D_803F2CDC = 3U;
//                     D_803F2CDA = 0;
//                 }
//                 func_80349B84_75B234(gScreenHeight - 36);
//             }
//             break;
//         case 2:
//             if (arg0 == 0) {
//                 if (D_803F2CDA >= 9) {
//                     D_803F2CDC = (u8)1U;
//                     phi_a0 = gScreenHeight - 0x24;
//                 } else {
//                     phi_a0 = gScreenHeight - (D_803F2CDA * 4);
//                 }
//                 func_80349B84_75B234(phi_a0);
//                 D_803F2CDA += 1;
//             }
//             break;
//         case 3:
//             if (arg0 == 0) {
//                 if (D_803F2CDA >= 9) {
//                     func_80349D34_75B3E4();
//                     D_803F2CD4 += 1;
//                     phi_a0 = gScreenHeight;
//                 } else {
//                     phi_a0 = ((gScreenHeight + (D_803F2CDA * 4)) - 36);
//                 }
//                 func_80349B84_75B234(phi_a0);
//                 D_803F2CDA += 1;
//               }
//               break;
//         case 4:
//             if (arg0 == 0) {
//                 D_803F2CD0 = (s16) (D_803F2CD0 - 1);
//                 if ((s32) D_803F2CD0 <= 0) {
//                     D_803F2CDC = (u8)6U;
//                     D_803F2CDA = (u16)0;
//                 }
//                 func_80349CA4_75B354(gScreenHeight - 0x24);
//             }
//             break;
//         case 5:
//             if (arg0 == 0) {
//                 if ((s32) D_803F2CDA >= 9) {
//                     D_803F2CDC = (u8)4U;
//                     phi_a0_3 = gScreenHeight - 0x24;
//                 } else {
//                     temp_v1 = gScreenHeight;
//                     phi_a0_3 = (temp_v1 + ((9 - D_803F2CDA) * ((s32) (((temp_v1 + D_803F2CE4) - temp_v1) + 0x24) / 9))) - 0x24;
//                 }
//                 func_80349CA4_75B354(phi_a0_3); //, phi_a1, &D_803F2CDC);
//                 D_803F2CDA += 1;
//             }
//             break;
//         case 6:
//             if (arg0 == 0) {
//                 if (D_803F2CD2 > 0) {
//                     D_803F2CDC = (u8)1U;
//                     phi_a0_4 = (s16) (gScreenHeight - 0x24);
//                 } else {
//                     if ((s32) D_803F2CDA >= 9) {
//                         func_80349D34_75B3E4(); //&D_803F2CD2); //, temp_t6, &D_803F2CDC);
//                         phi_a0_4 = (s16) (gScreenHeight + D_803F2CE4);
//                     } else {
//                         temp_v1_2 = gScreenHeight;
//                         phi_a0_4 = (s16) ((temp_v1_2 + (D_803F2CDA * ((s32) (((temp_v1_2 + D_803F2CE4) - temp_v1_2) + 0x24) / 9))) - 0x24);
//                     }
//                 }
//                 func_80349CA4_75B354(phi_a0_4);
//                 D_803F2CDA += 1;
//             }
//             break;
//         case 7:
//             if (arg0 == 0) {
//                 func_803491F0_75A8A0();
//             }
//             break;
//         case 8:
//             if (arg0 == 0) {
//                 func_803491F0_75A8A0();
//             }
//             break;
//         case 9:
//             if (arg0 == 0) {
//                 if ((s32) D_803F2CDA >= 9) {
//                     func_80349D34_75B3E4();
//                 }
//                 func_803491F0_75A8A0();
//             }
//             if (arg0 != 0) {
//                 if (D_803F2CDA >= 9) {
//                     phi_a0_6 = D_80203FD2;
//                 } else {
//                     phi_a0_6 = (D_80203FD2 + (D_803F2CDA * 4)) - 0x24;
//                 }
//                 func_80348230_7598E0(phi_a0_6);
//             }
//             if (arg0 == 0) {
//                 D_803F2CDA += 1;
//             }
//             break;
//         case 0:
//             if (D_803F2CDA >= 9) {
//                 D_803F2CDC = (u8)7U;
//                 phi_a0_5 = gScreenHeight - 0x24;
//             } else {
//                 phi_a0_5 = gScreenHeight - (D_803F2CDA * 4);
//             }
//             func_80348230_7598E0(phi_a0_5);
//             D_803F2CDA += 1;
//             func_80348230_7598E0(gScreenHeight - 0x24); // doubtful?
//             break;
//     }
// }
