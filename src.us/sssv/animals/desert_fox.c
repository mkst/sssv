#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_803726E0_783D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_80373788_784E38.s")

void func_80374470_785B20(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 36;
    } else {
        func_8035E3E8_76FA98(1);
    }
}

void func_803744C4_785B74(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 14;
    } else {
        func_8035E3E8_76FA98(1);
    }
}

//Desert fox dizziness function
void func_80374518_785BC8(void) {
    func_8032AAF0_73C1A0(DESERT_FOX);

    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = 37;

    if (D_803D5528->skillBEnergy[0] < 900) {
        D_803D552C->unk348 = 512;
        D_803D552C->unk34A = 50;
    } else {
        if (D_803D552C->unk348 < D_803D552C->unk30A) {
            D_803D552C->unk348 = D_803D552C->unk30A;
        } else {
            D_803D552C->unk348 = D_803D552C->unk348;
        }
        D_803D552C->unk30A = 0;
    }
}

void func_803745BC_785C6C(void) {
}

void func_803745C4_785C74(s16 arg0) {
    D_803D552C->unk2EC = arg0;
    if (D_803D5524->unk9C == DESERT_FOX) {
        func_8032AAF0_73C1A0(DESERT_FOX_ATTACKING);
    }
}

void func_8037460C_785CBC(void) {
    if (D_803D552C->unk365 == 0) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = 14;
    } else {
        func_8035E3E8_76FA98(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_80374660_785D10.s")
// is xPos/zPos s32?
// void func_80374660_785D10(s16 arg0, s16 arg1, s16 arg2) {
//     s32 temp_ret;
//     s32 temp_t3;
//     s32 temp_t2;
//     s16 temp_t0;
//     s16 temp_a3;
//
//     if (((D_803D5530->unk162 & 0xF) == 1) && (D_803D5530->unk161 != 1)) {
//         temp_a3 = D_80152C78[D_803D552C->unk302 & 0xFF];
//         temp_t0 = D_80152C78[(D_803D552C->unk302 + 64) & 0xFF];
//         temp_t2 = (temp_a3 * arg1 * 2) + D_803D552C->xPos + (arg0 * temp_t0 * 2);
//         temp_t3 = (D_803D552C->zPos + (arg1 * temp_t0 * 2)) - (temp_a3 * arg0 * 2);
//         temp_ret = func_80310EE4_722594((temp_t2 >> 16), (temp_t3 >> 16), D_803D5530->unk160);
//         D_803F2F08[D_803B4F30].unk0 = temp_t2;
//         D_803F2F08[D_803B4F30].unk4 = temp_t3;
//         D_803F2F08[D_803B4F30].unk8 = temp_ret + 0x40000;
//         D_803F2F08[D_803B4F30].unkC = arg2;
//         D_803F2F08[D_803B4F30].unkE =  D_803D5544;
//         D_803B4F30 = (D_803B4F30 + 1) & 0x3F;
//         if (D_803B4F34 < 64) {
//             D_803B4F34 += 1;
//         }
//     }
// }

void func_803747CC_785E7C(void) {
    D_803B4F34 = 0;
    D_803B4F30 = D_803B4F34;
    D_803F330E = -1;
}

// display lists
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/desert_fox/func_803747F4_785EA4.s")
// void func_803747F4_785EA4(void) {
//     s16 temp_s3;
//     s16 temp_t4;
//     s16 temp_v0_13;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     u16 temp_t5;
//     void *temp_t0;
//     void *temp_v0;
//     s16 phi_s2;
//     void *phi_v0;
//     void *phi_v0_2;
//     s16 phi_s3;
//
//     if ((s32) D_803F330E >= 0) {
//         temp_t4 = D_803F330E * 0x1E;
//         func_8034C8F8_75DFA8(D_803F3308, D_803F330A, (s16) (D_803F330C + 0xA), 0, 0x1037A20, temp_t4, temp_t4, (s32) ((0xC - D_803F330E) * 0x9B) / 0xC, 0xFF, 0xFF, 0xFF, 0, 0);
//         D_803F330E = (s16) (D_803F330E + 1);
//         if ((s32) D_803F330E >= 0xD) {
//             D_803F330E = (u16)-1;
//         }
//     }
//     if ((s32) D_803B4F34 > 0) {
//         gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, 0x01037750);
//         gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//         gDPLoadSync(D_801D9E90++);
//         gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 255, 1024);
//         gDPPipeSync(D_801D9E90++);
//         gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
//         gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, qu102(31), qu102(31));
//         gSPDisplayList(D_801D9E90++, 0x01003A58);
//
//         temp_v1_2 = D_803B4F34;
//         if ((s32) D_803B4F34 > 0) {
//             phi_s2 = (s16) ((D_803B4F30 - D_803B4F34) & 0x3F);
//             phi_s3 = D_803B4F34;
// loop_6:
//             temp_t0 = (phi_s2 * 16) + &D_803F2F08;
//             temp_t5 = (D_803D5544 - temp_t0->unkE) & 0xFFFF;
//             if (temp_t5 >= 401) {
//                 if (D_803F2D50.unk20 == 1) {
//                     gDPSetEnvColor(D_801D9E90++, 0, 0, 100, 500 - temp_t5);
//                 } else {
//                     gDPSetEnvColor(D_801D9E90++, 0, 0, 0, 500 - temp_t5);
//                 }
//                 if (temp_t5 >= 500) {
//                     D_803B4F34 -= 1;
//                 }
//             } else {
//                 if (D_803F2D50.unk20 == 1) {
//                     gDPSetEnvColor(D_801D9E90++, 0, 0, 65, 100);
//                 } else {
//                     gDPSetEnvColor(D_801D9E90++, 0, 0, 0, 100);
//                 }
//             }
//             temp_v0_13 = temp_t0->unkC;
//             func_8032E9E4_740094(&D_801D9E90, temp_t0->unk0, temp_t0->unk4, temp_t0->unk8, 0x20, 0x20, temp_v0_13, (s32) (temp_v0_13 * D_803A6CC0) >> 8);
//             temp_s3 = phi_s3 - 1;
//             phi_s2 = (s16) ((phi_s2 + 1) & 0x3F);
//             phi_s3 = temp_s3;
//             if ((s32) temp_s3 > 0) {
//                 goto loop_6;
//             }
//         }
//         gSPTexture(D_801D9E90++, qu016(0.5), qu016(0.5), 0, G_TX_RENDERTILE, G_ON);
//         gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
//         gDPSetTexturePersp(D_801D9E90++, G_TP_PERSP);
//     }
// }

void func_80374C38_7862E8(s16 arg0, s16 arg1, s16 arg2) {
    D_803F3308 = arg0;
    D_803F330A = arg1;
    D_803F330C = arg2;
    D_803F330E = 2;
}
