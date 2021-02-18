#include <ultra64.h>

#include "common.h"

extern f64 D_803BE950; // = 0.6;

// displaylist beast
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_80348230_7598E0.s")

// draw_score
void func_803491F0_75A8A0(void) {
    sprintf(&D_803F2D3E, &D_803BE940, D_803F2D30.score);
    select_font(0, 3, 1, 0);
    func_801304EC(&D_801D9E7C, &D_803F2D3E, gScreenWidth - 34, ((D_803F2CF0 >> 2) - 10));
}

void func_80349278_75A928(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_80349280_75A930.s")
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
//                 if (arg0->health - arg1 < 0) {
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

// draw the health bars ?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_803493C8_75AA78.s")
// NON-MATCHING: need to figure out a bunch of stuff
// void func_803493C8_75AA78(void) {
//     s32 spC;
//     s16 temp_a0;
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
//         temp_t9 = (spC * 6) & 0xFF;
//
//         // temp_v0_2->unk4 = (s32) (temp_t9 | 0x508200);
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0x50, 0x82, 0x00, temp_t9);
//         // temp_v0_3->unk4 = (s32) (temp_t9 | 0x50EB00);
//         gDPSetEnvColor(D_801D9E7C++, 0x50, 0xEB, 0x00, temp_t9);
//
//
//         // gDPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)
//         gSPTextureRectangle(D_801D9E7C++, 4*49, D_803F2CF0 + 0xC, D_803F2CF0 + 0x18, D_803F2CF8.unk8 + 0xC4, G_TX_RENDERTILE, 0, 0, 0, 0x400);
//
//         // gTexRect(D_801D9E7C++, 49*4, (D_803F2CF0 + 0xC), D_803F2CF0 + 0x18, D_803F2CF8.unk8 + 0xC4, G_TX_RENDERTILE);
//         // gDPHalf1((*arg0)++, 0x00000000);
//         // gDPHalf2((*arg0)++, 0x00000400);
//
//         // temp_v0_4->unk0 = (s32) ((((D_803F2CF8.unk8 + 0xC4) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 + 0x18) & 0xFFF));
//         // temp_v0_4->unk4 = (s32) (((D_803F2CF0 + 0xC) & 0xFFF) | 0xC4000);
//
//         gDPPipeSync(D_801D9E7C++);
//
//         // temp_v0_8->unk4 = (s32) (temp_t7 | 0xC8006400);
//         gDPSetPrimColor(D_801D9E7C++, 0, 0, 0xC8, 0x00, 0x64, 0x00);
//         // temp_v0_9->unk4 = (s32) (temp_t7 | 0xFF008000);
//         gDPSetEnvColor(D_801D9E7C++, 0xFF, 0x00, 0x80, 0x00);
//
//
//         // another gSPTextureRectangle here
//
//         gSPTextureRectangle(D_801D9E7C++, 4*49, D_803F2CF0 + 0xC, (temp_a0 + (D_803F2CF8.health - temp_a0) + 0xC4), temp_a0 + 0xC4, G_TX_RENDERTILE, 0, 0, 0, 0x400);
//
//         // temp_a0 = D_803F2CF8.unk8;
//         // temp_v0_10 = D_801D9E7C;
//         // D_801D9E7C = (void *) (temp_v0_10 + 8);
//         // temp_v0_10->unk0 = (s32) ((((temp_a0 + (D_803F2CF8.health - temp_a0) + 0xC4) & 0xFFF) << 0xC) | 0xE4000000 | ((D_803F2CF0 + 0x18) & 0xFFF));
//         // temp_v0_10->unk4 = (s32) ((((temp_a0 + 0xC4) & 0xFFF) << 0xC) | ((D_803F2CF0 + 0xC) & 0xFFF));
//         // temp_v0_11 = D_801D9E7C;
//         // D_801D9E7C = (void *) (temp_v0_11 + 8);
//         // temp_v0_11->unk4 = 0;
//         // temp_v0_11->unk0 = 0xB4000000;
//         // temp_v0_12 = D_801D9E7C;
//         // D_801D9E7C = (void *) (temp_v0_12 + 8);
//         // temp_v0_12->unk4 = 0x400;
//         // temp_v0_12->unk0 = 0xB3000000;
//
//         if (D_803F2CF8.unk6 < D_803F2CF8.unk8) {
//             D_803F2CF8.unk8 = D_803F2CF8.unk8 - 1;
//         } else {
//             if ( D_803F2CF8.unkA > 0) {
//                 D_803F2CF8.unkA = D_803F2CF8.unkA - 1;
//             } else {
//                 D_803F2CF8.animal = 0;
//             }
//         }
//         gDPPipeSync(D_801D9E7C++);
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_8034967C_75AD2C.s")
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
    s32 res;

    if ((res = D_803F2CDF != 0)) {
        if (!(res = D_803F2CDC == 0)) {
            if (!(res = D_803F2CDC == 1)) {
                if (!(res = D_803F2CDC == 7)) {
                    if ((res = (D_803F2CDC ^ 6)) || (!(res = D_803F2CDA == 0))) {
                        if ((res = D_803F2CDC == 3)) {
                            res = D_803F2CDA == 0;
                        }
                    }
                }
            }
        }
    }
    return res;
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
    s32 res;

    if ((res = D_803F2CDF != 0)) {
        if (!(res = D_803F2CDC == 0)) {
            if (!(res = D_803F2CDC == 1)) {
                if (!(res = D_803F2CDC == 7)) {
                    if ((res = (D_803F2CDC ^ 6)) || (!(res = D_803F2CDA == 0))) {
                        if ((res = D_803F2CDC == 3)) {
                            res = D_803F2CDA == 0;
                        }
                    }
                }
            }
        }
    }
    return res;
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

// display_timer?
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_80349CA4_75B354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_80349D34_75B3E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7598E0/func_80349DCC_75B47C.s")
