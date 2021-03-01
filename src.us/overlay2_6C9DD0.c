#include <ultra64.h>
#include "common.h"


void func_802B8720_6C9DD0(void) {
    D_803D5528->unk380 = 0;
    D_803D5528->unk394 = 0;
    D_803D5528->unk3A8 = 0;
    D_803D5528->unk3BC = 0;
    D_803D5528->unk3C0 = 0;
    D_803D5528->unk382 = 0;
    D_803D5528->unk396 = 0;
    D_803D5528->unk3AA = 0;
    D_803D5528->unk3BE = 0;
    func_802C7BB4_6D9264(4);
}

void func_802B8790_6C9E40(void) {
    D_803D5528->unk380 = 0;
    D_803D5528->unk394 = 0;
    D_803D5528->unk3A8 = 0;
    D_803D5528->unk3BC = 0;
    D_803D5528->unk3C0 = 0;
    D_803D5528->unk382 = 0;
    D_803D5528->unk396 = 0;
    D_803D5528->unk3AA = 0;
    D_803D5528->unk3BE = 0;
    D_803D552C->unk2FA = func_802B8B74_6CA224();
    func_802C7BB4_6D9264(5);
}

void func_802B8810_6C9EC0(void) {
    D_803D5528->unk380 = 0;
    D_803D5528->unk394 = 0;
    D_803D5528->unk3A8 = 0;
    D_803D5528->unk3BC = 0;
    D_803D5528->unk3C0 = 0;
    D_803D5528->unk382 = 0;
    D_803D5528->unk396 = 0;
    D_803D5528->unk3AA = 0;
    D_803D5528->unk3BE = 0;
    D_803D552C->unk2FA = func_802B8B74_6CA224();
    func_802C7BB4_6D9264(6);
}

void func_802B8890_6C9F40(void) {
    D_803D5528->unk380 = 3;
    D_803D5528->unk394 = 3;
    D_803D5528->unk3A8 = 4;
    D_803D5528->unk3BC = 4;
    D_803D5528->unk3C0 = 2;
    D_803D5528->unk3C4 = 2;
    D_803D5528->unk382 = -1;
    D_803D5528->unk396 = -1;
    D_803D5528->unk3AA = -1;
    D_803D5528->unk3BE = -1;
    func_802C7BB4_6D9264(6);
}

void func_802B8918_6C9FC8(void) {
    D_803D5528->unk380 = 7;
    D_803D5528->unk394 = 7;
    D_803D5528->unk3A8 = 7;
    D_803D5528->unk3BC = 7;
    D_803D5528->unk3C0 = 7;
    D_803D5528->unk3C4 = 7;
    D_803D5528->unk382 = 0;
    D_803D5528->unk396 = 0;
    D_803D5528->unk3AA = 0;
    D_803D5528->unk3BE = 0;
}

void func_802B8978_6CA028(void) {
    D_803D5528->unk380 = 8;
    D_803D5528->unk394 = 8;
    D_803D5528->unk3A8 = 8;
    D_803D5528->unk3BC = 8;
    D_803D5528->unk3C0 = 8;
    D_803D5528->unk3C4 = 8;
    D_803D5528->unk382 = 0;
    D_803D5528->unk396 = 0;
    D_803D5528->unk3AA = 0;
    D_803D5528->unk3BE = 0;
}

void func_802B89D8_6CA088(void) {
    D_803D5528->unk3C0 = 9;
    D_803D5528->unk3C4 = 9;
    D_803D5528->unk382 = -1;
    D_803D5528->unk396 = -1;
    D_803D5528->unk3AA = -1;
    D_803D5528->unk3BE = -1;
    D_803D5528->unk3C2 = -1;
    D_803D5528->unk3C6 = -1;
    func_802C7BB4_6D9264(6, 9);
}

void func_802B8A48_6CA0F8(void) {
    D_803D5528->unk380 = 10;
    D_803D5528->unk394 = 10;
    D_803D5528->unk3A8 = 10;
    D_803D5528->unk3BC = 10;
    D_803D5528->unk3C0 = 10;
    D_803D5528->unk3C4 = 10;
    D_803D5528->unk382 = -1;
    D_803D5528->unk396 = -1;
    D_803D5528->unk3AA = -1;
    D_803D5528->unk3BE = -1;
    D_803D5528->unk3C2 = -1;
    D_803D5528->unk3C6 = -1;
    func_802C7BB4_6D9264(6, -1);
}

void func_802B8AD8_6CA188(void) {
    D_803D5528->unk3C0 = 9;
    D_803D5528->unk3C4 = 9;
    D_803D5528->unk3CE = 9;
    D_803D5528->unk3C2 = -1;
    D_803D5528->unk3C6 = -1;
    D_803D5528->unk3D0 = -1;
}

//s16 unk3C4 required for other functions, u16 for this one?
void func_802B8B1C_6CA1CC(void) {
    D_803D5528->unk3C0 = 12;
    D_803D5528->unk3CE = 12;
    D_803D5528->unk3C2 = -1;
    D_803D5528->unk3D0 = -1;
    if ((u16)D_803D5528->unk3C4 != 12U) {
        D_803D5528->unk3C4 = 12;
        D_803D5528->unk3C6 = -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B8B74_6CA224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B8C50_6CA300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B901C_6CA6CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B90A0_6CA750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B9130_6CA7E0.s")

void func_802B964C_6CACFC(void) {
    D_80203FE0.unk8 = ((D_80203FE0.unk20 + D_80203FE0.unk18) >> 1);
    D_80203FE0.unkA = ((D_80203FE0.unk22 + D_80203FE0.unk1A) >> 1);
    D_80203FE0.unkC = ((D_80203FE0.unk24 + D_80203FE0.unk1C) >> 1);
    D_80203FE0.unk10 = ((D_80203FE0.unk30 + D_80203FE0.unk28) >> 1);
    D_80203FE0.unk12 = ((D_80203FE0.unk32 + D_80203FE0.unk2A) >> 1);
    D_80203FE0.unk14 = ((D_80203FE0.unk34 + D_80203FE0.unk2C) >> 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B96D0_6CAD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B975C_6CAE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B9A5C_6CB10C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802B9D20_6CB3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BA220_6CB8D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BA614_6CBCC4.s")

void func_802BAA38_6CC0E8(u16 arg0, u16 arg1) {
    D_80203FE0.unk1C = 0;
    D_80203FE0.unk18 = -arg1;
    D_80203FE0.unk24 = 0;
    D_80203FE0.unk2A = -arg0;
    D_80203FE0.unk28 = -arg1;
    D_80203FE0.unk2C = 0;
    D_80203FE0.unk32 = -arg0;
    D_80203FE0.unk34 = 0;
    D_80203FE0.unk20 = arg1;
    D_80203FE0.unk30 = arg1;
    D_80203FE0.unk1A = arg0;
    D_80203FE0.unk22 = arg0;
    func_802C79E0_6D9090(&D_80203FF8, -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80204000, -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80204008, -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80204010, -D_803D5530->unk28);
    D_80203FE0.unk1C = (D_80203FE0.unk1C + (D_803D5524->unkB8 << 5));
    D_80203FE0.unk24 = (D_80203FE0.unk24 + (D_803D5524->unkB8 << 5));
    D_80203FE0.unk2C = (D_80203FE0.unk2C + (D_803D5524->unkB8 << 5));
    D_80203FE0.unk34 = (D_80203FE0.unk34 + (D_803D5524->unkB8 << 5));
    D_80203FE0.unk8 = ((D_80203FE0.unk20 + D_80203FE0.unk18) >> 1);
    D_80203FE0.unkA = ((D_80203FE0.unk22 + D_80203FE0.unk1A) >> 1);
    D_80203FE0.unkC = ((D_80203FE0.unk24 + D_80203FE0.unk1C) >> 1);
    D_80203FE0.unk10 = ((D_80203FE0.unk30 + D_80203FE0.unk28) >> 1);
    D_80203FE0.unk12 = ((D_80203FE0.unk32 + D_80203FE0.unk2A) >> 1);
    D_80203FE0.unk14 = ((D_80203FE0.unk34 + D_80203FE0.unk2C) >> 1);
    D_80203FE0.unk2 = 0;
    D_80203FE0.unk0 = D_80203FE0.unk2;
    D_80203FE0.unk4 = ((D_80203FE0.unk14 + D_80203FE0.unkC) >> 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BAC24_6CC2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BAD60_6CC410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BAE24_6CC4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BB1F0_6CC8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6C9DD0/func_802BB70C_6CCDBC.s")
