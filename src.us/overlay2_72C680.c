#include <ultra64.h>
#include "common.h"
#include "pp.h"

extern u8 rnc_637160_ROM_START[], rnc_637160_ROM_END[];

#if 0
// levels
u8* D_803A5BF8_7B72A8[36][2] = {
    { 0x546D00, 0x54F0D0 },
    { 0x54F0D0, 0x554E00 },
    { 0x554E00, 0x55A390 },
    { 0x55A390, 0x560320 },
    { 0x560320, 0x567F00 },
    { 0x567F00, 0x56CD00 },
    { 0x56CD00, 0x572CC0 },
    { 0x572CC0, 0x578D10 },
    { 0x578D10, 0x57F1D0 },
    { 0x57F1D0, 0x582C60 },
    { 0x582C60, 0x588CA0 },
    { 0x588CA0, 0x58D380 },
    { 0x58D380, 0x591880 },
    { 0x591880, 0x596960 },
    { 0x596960, 0x5A1110 },
    { 0x5A1110, 0x5A7E10 },
    { 0x5A7E10, 0x5AE270 },
    { 0x5AE270, 0x5B4510 },
    { 0x5B4510, 0x5BA760 },
    { 0x5BA760, 0x5C3390 },
    { 0x5C3390, 0x5C8C80 },
    { 0x5C8C80, 0x5D06A0 },
    { 0x5D06A0, 0x5D7E70 },
    { 0x5D7E70, 0x5DF8F0 },
    { 0x5DF8F0, 0x5E49C0 },
    { 0x5E49C0, 0x5EB140 },
    { 0x5EB140, 0x5F2840 },
    { 0x5F2840, 0x5F9410 },
    { 0x5F9410, 0x603210 },
    { 0x603210, 0x607440 },
    { 0x607440, 0x60E920 },
    { 0x60E920, 0x60FFD0 },
    { 0x60FFD0, 0x6104A0 },
    { 0x6104A0, 0x6109D0 },
    { 0x6109D0, 0x616BB0 },
    { 0x616BB0, 0x617C30 }
};
#endif

// get_uncompressed_size
s32 func_8031AFD0_72C680(u8 *arg0) {

    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return uncompressed length length
        return arg0[7] | (arg0[6] << 8) | (arg0[5] << 16) | (arg0[4] << 24);
    } else {
        return arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24);
    }
}

// get_compressed_size
s32 func_8031B058_72C708(u8 *arg0) {
    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return compressed length length + RNC header size (18 bytes)
        return (arg0[11] | (arg0[10] << 8) | (arg0[9] << 16) | (arg0[8] << 24)) + HEADERLEN;
    } else {
        return (arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24)) + 4;
    }

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B0E8_72C798.s")
// NON-MATCHING: not quite right...
// s32 func_8031B0E8_72C798(u8 *arg0, u8 *arg1, u8 *arg2) {
//     if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
//         UnpackRNC(arg0, arg1);
//     } else {
//         memcpy_sssv(arg0 + 4, arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24), arg2);
//     }
//     return 1;
// }

// load_texture_bank()
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B174_72C824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level.s")
// void load_level(u8 arg0) {
//     u8 idx = arg0 - 1;
//
//     func_8031C374_72DA24();
//     dma_read(D_803A5BF8_7B72A8[idx][0], &D_80100000, D_803A5BF8_7B72A8[idx][1] - D_803A5BF8_7B72A8[idx][0]);
//     func_8031B400_72CAB0();
//     func_8031C48C_72DB3C();
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B400_72CAB0.s")

void func_8031C304_72D9B4(void) {
    func_8012A400(); // receive messages, synchronization?
    func_8012AC8C();
}

void func_8031C32C_72D9DC(void) {
    // zero out framebuffer 1
    bzero_sssv(gFramebuffer[0], sizeof(gFramebuffer[0]));
    // zero out framebuffer 2
    bzero_sssv(gFramebuffer[1], sizeof(gFramebuffer[0]));
    // cancel blackout
    osViBlack(0);
}

void func_8031C374_72DA24(void) {
    func_8031C304_72D9B4();
    D_803E1B10[0] = 1;
    D_803E1B10[1] = 100;
    D_803E1B10[3] = 8;
    D_803E1B10[2] = 5;
    D_803F2E0C = 0;
}

void func_8031C3C0_72DA70(u8 *arg0, s16 arg1) {
    s16 i;

    memcpy_sssv(arg0, (u8*)&D_803E9840[D_803F28C2], sizeof(struct067));

    for (i = 0; i < 247; i++) {
        if (arg1 == D_803A8528_7B9BD8[i].unk1C) {
            D_803A8528_7B9BD8[i].unk18 = &D_803E9840[D_803F28C2];
        }
    }
    D_803F28C2 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031C48C_72DB3C.s")
// void func_8031C48C_72DB3C(void) {
//
//     Animal *temp_a0;
//     struct071 *temp_v0;
//     struct069 *temp_v0_5;
//     struct068 *temp_v0_6;
//     s16 i;
//
//
//     if (D_803F2D50.unkBC != 0) {
//         func_8029B9B8_6AD068(D_801D9ED8.animal[gCurrentAnimalIndex].unk0, D_803F2D50.unkBC);
//     }
//
//     load_data_section(D_803F2D50.unk20);
//     func_802FD8CC_70EF7C();
//     func_8033C334_74D9E4();
//     func_802F2DF8_7044A8();
//     func_802FE4C4_70FB74();
//     func_8039DD60_7AF410(); // reset used objects, zero out memory
//     func_802C85EC_6D9C9C();
//
//     for (i = 0; i < 170; i++) {
//         temp_v0 = &D_801E9EB8[i];
//         if (temp_v0->unk1AC != 0) {
//             func_803191B0_72A860(&temp_v0->unk4.h);
//         }
//     }
//
//     for (i = 0; i < D_803D553E; i++) {
//         temp_a0 = D_801D9ED8.animal[i].unk0;
//         if (temp_a0->unk1A8 != 0) {
//             func_803191B0_72A860(temp_a0);
//         }
//     }
//
//     for (i = 0; i < 247; i++) {
//         D_803A8528_7B9BD8[i].unk18 = 0;
//     }
//
//     D_803F28C2 = 0;
//     osWritebackDCacheAll();
//     dma_read(rnc_637160_ROM_START, &D_80100000, rnc_637160_ROM_START - rnc_637160_ROM_START);
//     UnpackRNC(&D_80100000, &gFramebuffer);
//
//     // starts falling apart around here...
//     for (i = 0; i < 170; i++) {
//         temp_v0 = D_801E9EB8[i].unk170;
//         if ((temp_v0 != NULL) && (&D_801E9EB8[i+1].unk0 == 0)) {
//             if ((temp_v0->unk1C != 0) && (temp_v0->unk18 == 0)) {
//                 func_8031C3C0_72DA70((s32)&gFramebuffer + (((s16) temp_v0->unk1C - 1) * 0x100C), (s16) temp_v0->unk1C);
//             }
//         }
//     }
//
//     for (i = 0; i < D_803E8E54; i++) {
//         temp_v0_5 = &D_803E4D40 + (i * 10);
//         if ((temp_v0_5->unk0 == 16) || (temp_v0_5->unk0 == 17)) {
//             temp_v0_6 = &D_803A8528_7B9BD8[temp_v0_5->unk2];
//             if ((temp_v0_6->unk1C != 0) && (temp_v0_6->unk18 == 0)) {
//                 func_8031C3C0_72DA70((s32)&gFramebuffer + (((s16) temp_v0_6->unk1C - 1) * 0x100C), (s16) temp_v0_6->unk1C);
//             }
//         }
//     }
//
//     func_8031C32C_72D9DC();
//     func_802963D0_6A7A80(&D_80162658);
// }
