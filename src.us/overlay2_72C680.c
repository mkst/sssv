#include <ultra64.h>
#include "common.h"

#if 0
// levels
u32 D_803A5BF8_7B72A8[36][2] = {
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
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031AFD0_72C680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B058_72C708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B0E8_72C798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B174_72C824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B390_72CA40.s")
// load_level
// void func_8031B390_72CA40(u8 arg0) {
//     u8 idx = arg0 - 1;
//
//     func_8031C374_72DA24();
//     dma_read(D_803A5BF8_7B72A8[idx][0], &D_80100000, D_803A5BF8_7B72A8[idx][1] - D_803A5BF8_7B72A8[idx][0]);
//     func_8031B400_72CAB0();
//     func_8031C48C_72DB3C();
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031B400_72CAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031C304_72D9B4.s")

void func_8031C32C_72D9DC(void) {
    // zero out framebuffer 1
    fancy_bzero(gFramebuffer[0], sizeof(gFramebuffer[0]));
    // zero out framebuffer 2
    fancy_bzero(gFramebuffer[1], sizeof(gFramebuffer[0]));
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

    strncpy(arg0, (u8*)&D_803E9840[D_803F28C2], sizeof(struct067));

    for (i = 0; i < 247; i++) {
        if (arg1 == D_803A8528_7B9BD8[i].unk1C) {
            D_803A8528_7B9BD8[i].unk18 = &D_803E9840[D_803F28C2];
        }
    }
    D_803F28C2 += 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72C680/func_8031C48C_72DB3C.s")
