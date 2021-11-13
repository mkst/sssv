#include <ultra64.h>
#include "common.h"
#include "pp.h"


extern u8 rnc_637160_ROM_START[], rnc_637160_ROM_END[];

#if 0
// textures?
u8* D_803A5770_7B6E20[][2] = {
    { 0x42DCA0, 0x435320, },
    { 0x435320, 0x43cb60, },
    { 0x43CB60, 0x4457f0, },
    { 0x4457F0, 0x44e790, },
    { 0x44E790, 0x44e7b0, },
    { 0x44E7B0, 0x4571a0, },
};

u8* D_803A57A0_7B6E50[][2] = {
    { 0x4571A0, 0x459590, }
    { 0x459590, 0x45d550, },
    { 0x45d550, 0x45edc0, },
    { 0x45edc0, 0x461900, },
    { 0x461900, 0x461950, },
    { 0x461950, 0x461A20, },
    { 0x461A20, 0x465f90, },
    { 0x465f90, 0x46ba30, },
    { 0x46ba30, 0x470670, },
    { 0x470670, 0x474ee0, },
    { 0x474ee0, 0x47a0f0, },
    { 0x47a0f0, 0x47f1e0, },
    { 0x47f1e0, 0x484450, },
    { 0x484450, 0x488a70, },
    { 0x488a70, 0x48dd20, },
    { 0x48dd20, 0x4927e0, },
    // ice
    { 0x4927e0, 0x497b90, },
    { 0x497b90, 0x49c950, },
    { 0x49c950, 0x4a1690, },
    { 0x4a1690, 0x4a5170, },
    { 0x4a5170, 0x4a97e0, },
    { 0x4a97e0, 0x4ae610, },
    { 0x4ae610, 0x4b3440, },
    { 0x4b3440, 0x4b3460, },
    { 0x4b3460, 0x4b79a0, },
    { 0x4b79a0, 0x4b79c0, },
    { 0x4b79c0, 0x4b79e0, },
    // desert
    { 0x4b79e0, 0x4bc330, },
    { 0x4bc330, 0x4c12c0, },
    { 0x4c12c0, 0x4c4cd0, },
    { 0x4c4cd0, 0x4c91b0, },
    { 0x4c91b0, 0x4cd3a0, },
    { 0x4cd3a0, 0x4d1770, },
    { 0x4d1770, 0x4d68d0, },
    { 0x4d68d0, 0x4d6960, },
    { 0x4d6960, 0x4d6980, }, // empty
    { 0x4d6980, 0x4d69a0, }, // empty
    { 0x4d69a0, 0x4db210, },
    { 0x4db210, 0x4db230, }, // empty
    { 0x4db230, 0x4e0b80, },
    { 0x4e0b80, 0x4e57f0, },
    { 0x4e57f0, 0x4eabe0, },
    { 0x4eabe0, 0x4efc40, },
    { 0x4efc40, 0x4f5470, },
    { 0x4f5470, 0x4f5490, }, // empty
    { 0x4f5490, 0x4f54b0, }, // empty
    { 0x4f54b0, 0x4f54d0, }, // empty
};

u8* D_803A5918_7B6FC8[] = {
    { 0x803A57D0, 0x803A5828, 0x803A5878, 0x803A58C8, },
};

u8* D_803A5928_7B6FD8[44][2] = {
    { 0x4F54D0, 0x4f6a70, },
    { 0x4f95b0, 0x4faf70, },
    { 0x4f8010, 0x4f95b0, },
    { 0x4f6a70, 0x4f8010, },
    { 0x4faf70, 0x4fc110, },
    { 0x4fc110, 0x4fd1e0, },
    { 0x4fd1e0, 0x4fdf70, },
    { 0x4fdf70, 0x4ff2b0, },
    { 0x4ff2b0, 0x500020, },
    { 0x500020, 0x500050, },
    { 0x500050, 0x501040, },
    { 0x501040, 0x502360, },
    { 0x502360, 0x503930, },
    { 0x503930, 0x504e70, },
    { 0x504e70, 0x505f00, },
    { 0x505f00, 0x505f30, },
    { 0x505f30, 0x506550, },
    { 0x506550, 0x506dd0, },
    { 0x506dd0, 0x507f00, },
    { 0x507f00, 0x507f30, },
    { 0x507f30, 0x507f60, },
    { 0x507f60, 0x507f90, },
    { 0x507f90, 0x507fc0, },
    { 0x507fc0, 0x509220, },
    { 0x509220, 0x509250, },
    { 0x509250, 0x50a4a0, },
    { 0x50a4a0, 0x50a4d0, },
    { 0x50a4d0, 0x50bdb0, },
    { 0x50bdb0, 0x50d230, },
    { 0x50d230, 0x50ecd0, },
    { 0x50ecd0, 0x5106e0, },
    { 0x5106e0, 0x512240, },
    { 0x512240, 0x512270, },
    { 0x512270, 0x5122a0, },
    { 0x5122a0, 0x5122d0, },
    { 0x5122d0, 0x5137c0, },
    { 0x5137c0, 0x514cb0, },
    { 0x514cb0, 0x515730, },
    { 0x515730, 0x516c20, },
    { 0x516c20, 0x518110, },
    { 0x518110, 0x519600, },
    { 0x519600, 0x51aaf0, },
    { 0x51aaf0, 0x51ab20, },
    { 0x51ab20, 0x51ab50, },
    { 0x51ab50, 0x51ab80, },
};

u8* D_803A5A90_7B7140[][2] = {
    { 0x803A5948, 0x803A59A0, 0x803A5A40, 0x803A59F0, },
};

// level objects
u8 *D_803A5AA0_7B7150[40][2] = {
    { 0x85790, 0x87b80, },  // HAVE_A_NICE_DAY
    { 0x87b80, 0x89260, },
    { 0x89260, 0x92bf0, },
    { 0x92bf0, 0x96790, },
    { 0x96790, 0x97020, },
    { 0x97020, 0x9e0d0, },
    { 0x9e0d0, 0x9ed10, },
    { 0x9ed10, 0xa0e40, },
    { 0xa0e40, 0xa10c0, },
    { 0xa10c0, 0xa10d0, },
    { 0xa10d0, 0xaa940, },
    { 0xaa940, 0xb0490, },
    { 0xb0490, 0xb0b90, },
    { 0xb0b90, 0xb2ed0, },
    { 0xb2ed0, 0xb3d70, },
    { 0xb3d70, 0xb3d80, },
    { 0xb3d80, 0xb3d90, },
    { 0xb3d90, 0xb3da0, },
    { 0xb3da0, 0xb3db0, },
    { 0xb3db0, 0xb3dc0, },
    { 0xb3dc0, 0xb3dd0, },
    { 0xb3dd0, 0xb40c0, },
    { 0xb40c0, 0xb40d0, },
    { 0xb40d0, 0xb43a0, },
    { 0xb43a0, 0xb48c0, },
    { 0xb48c0, 0xb48d0, },
    { 0xb48d0, 0xbd090, },
    { 0xbd090, 0xbd0a0, },
    { 0xbd0a0, 0xbd0b0, },
    { 0xbd0b0, 0xbd0c0, },
    { 0xbd0c0, 0xbd0d0, },
    { 0xbd0d0, 0xbd2b0, },
    { 0xbd2b0, 0xbfc40, },
    { 0xbfc40, 0xc4500, },
    { 0xc4500, 0xc4510, },
    { 0xc4510, 0xc47a0, },
    { 0xc47a0, 0xc47b0, },
    { 0xc47b0, 0xc7a00, },
    { 0xc7a00, 0xc7a10, },
    { 0xc7a10, 0xc7a20, },
    { 0xc7a20, 0xc7a30, },
};

u8* D_803A5BE8_7B7298[][2] = {
    { 0x803A5AA0, 0x803A5AF8, 0x803A5B98, 0x803A5B48, },
};

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

s32 get_uncompressed_size(u8 *arg0) {
    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return uncompressed length length
        return arg0[7] | (arg0[6] << 8) | (arg0[5] << 16) | (arg0[4] << 24);
    } else {
        return arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24);
    }
}

s32 get_compressed_size(u8 *arg0) {
    if ((arg0[0] == 'R') && (arg0[1] == 'N') && (arg0[2] == 'C')) {
        // return compressed length length + RNC header size (18 bytes)
        return (arg0[11] | (arg0[10] << 8) | (arg0[9] << 16) | (arg0[8] << 24)) + HEADERLEN;
    } else {
        return (arg0[3] | (arg0[2] << 8) | (arg0[1] << 16) | (arg0[0] << 24)) + 4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B0E8_72C798.s")
// NON-MATCHING: not quite right...
// s32 func_8031B0E8_72C798(u8 *src, u8 *scratch, s32 len) {
//     if ((src[0] == 'R') && (src[1] == 'N') && (src[2] == 'C')) {
//         UnpackRNC(src, scratch);
//     } else {
//         memcpy_sssv(src + 4, src[3] | (src[2] << 8) | (src[1] << 16) | (src[0] << 24), len);
//     }
//     return 1;
// }

// load_texture_bank()
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B174_72C824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/load_level.s")
// void load_level(u8 level) {
//     func_8031C374_72DA24();
//     // 0-indexed so subtract 1
//     level = level - 1;
//     //
//     dma_read(
//         D_803A5BF8_7B72A8[level][0],
//         &D_80100000,
//         D_803A5BF8_7B72A8[level][1] - D_803A5BF8_7B72A8[level][0]);
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

void func_8031C374_72DA24() {
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
