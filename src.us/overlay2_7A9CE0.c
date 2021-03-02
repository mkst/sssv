#include <ultra64.h>
#include "common.h"

extern u8 *D_800BA760;
extern u8 *D_800BDC80;
extern u8 *D_800BB700;
extern u8 *D_800DE390;
extern u8 *D_800BBBB0;
extern u8 *D_800BC060;
extern u8 *D_800BC510;
extern u8 *D_800BC9C0;
extern u8 *D_800BCE70;
extern u8 *D_800BD320;
extern u8 *D_800BD7D0;

extern s32 D_04006EC0;
extern s32 D_04007FA0;
extern s32 D_04000000;
extern s32 D_04013060;
extern s32 D_040133C0;
extern s32 D_040131B0;
extern s32 D_04013580;
extern s32 D_04007700;
extern s32 D_040077A0;
extern s32 D_040078C0;
extern s32 D_040079F0;
extern s32 D_04007B40;
extern s32 D_04007C60;
extern s32 D_04007D90;
extern s32 D_04007EC0;

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_80398630_7A9CE0.s")
// void func_80398630_7A9CE0(void) {
//     func_803800F0_7917A0(6);
//     rnc_decompress(D_801D9E6C + (D_04006EC0 & 0xFFFFFF), &D_800BA760); // rnc_42DCA0
//     rnc_decompress(D_801D9E6C + (D_04007FA0 & 0xFFFFFF), &D_800BDC80);
//     rnc_decompress(D_801D9E6C + (D_04000000 & 0xFFFFFF), &D_800DE390);
//     rnc_decompress(D_801D9E6C + (D_04013060 & 0xFFFFFF), &D_800C3A40);
//     rnc_decompress(D_801D9E6C + (D_040133C0 & 0xFFFFFF), &D_800C5240);
//     rnc_decompress(D_801D9E6C + (D_040131B0 & 0xFFFFFF), &D_800C4240);
//     rnc_decompress(D_801D9E6C + (D_04013580 & 0xFFFFFF), &D_800C4A40);
//     rnc_decompress(D_801D9E6C + (D_04007700 & 0xFFFFFF), &D_800BB700);
//     rnc_decompress(D_801D9E6C + (D_040077A0 & 0xFFFFFF), &D_800BBBB0);
//     rnc_decompress(D_801D9E6C + (D_040078C0 & 0xFFFFFF), &D_800BC060);
//     rnc_decompress(D_801D9E6C + (D_040079F0 & 0xFFFFFF), &D_800BC510);
//     rnc_decompress(D_801D9E6C + (D_04007B40 & 0xFFFFFF), &D_800BC9C0);
//     rnc_decompress(D_801D9E6C + (D_04007C60 & 0xFFFFFF), &D_800BCE70);
//     rnc_decompress(D_801D9E6C + (D_04007D90 & 0xFFFFFF), &D_800BD320);
//     rnc_decompress(D_801D9E6C + (D_04007EC0 & 0xFFFFFF), &D_800BD7D0);
// }


// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039884C_7A9EFC.s")
void func_8039884C_7A9EFC(void) {
    u8 sp18[0x58]; // 88?

    func_8039D6A4_7AED54();
    // debug here?
    if (0);
    D_803F7DA8.unk32 = 99;
    D_803F7D78.unk18 = 0;
    D_803F7D78.unk1C = 0;
    D_803F7D78.unk20 = 0;
    D_803F7D78.unk0 = 0.0f;
    D_803F7D78.unk4 = 0.0f;
    D_803F7D78.unk8 = 0.0f;
    D_803F7D78.unkC = 0.0f;
    D_803F7D78.unk10 = 0.0f;
    D_803F7D78.unk14 = 0.0f;
    D_803F7D70 = D_803C03F4;
    func_801308B4(&sp18, &D_803F2E34);
    D_803F7DA8.unk8 = 1.0f;
    D_803B7468 = D_803F7DA8.unk2D * 0xC;;
    D_803F7D68 = D_803F7DA8.unk2D * 0xC;;
    D_803F7DA8.unk0 = 40.0f;
    D_803F7DA8.unk4 = 30.0f;
    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DA0 = 6;
    D_803F7DA1 = 6;
    D_803F7DA2 = 0;
    D_803F7DA3 = 0;
    D_803F2E1E = func_80296320_6A79D0();
}

// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039895C_7AA00C.s")
void func_8039895C_7AA00C(void) {
    s16 i;

    D_803F7D9C = 0;
    D_803F7D9E = 0;
    D_803F7DD7 = 0;
    func_8039D580_7AEC30();

    for (i = 0; i < 4; i++) {
        func_80130CD4(i);
        strncpy(&D_8023F260, &D_8023F2E0[i], 64);
    }
    func_80130CD4(D_803F7DD6);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_80398A00_7AA0B0.s")
void func_80398A00_7AA0B0(void) {
    D_803F7DD8 = (u8)0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_80398A0C_7AA0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039A2DC_7AB98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039BBB8_7AD268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039BE98_7AD548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039C5F8_7ADCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039C834_7ADEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039CAB8_7AE168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039CCBC_7AE36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039CDE8_7AE498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039CE38_7AE4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039D034_7AE6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039D30C_7AE9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039D580_7AEC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039D6A4_7AED54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DAAC_7AF15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DB60_7AF210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DBC8_7AF278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7A9CE0/func_8039DCC0_7AF370.s")
