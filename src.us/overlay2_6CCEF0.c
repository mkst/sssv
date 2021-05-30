#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB840_6CCEF0.s")
// nonsense
// void func_802BB840_6CCEF0(u16 arg0) {
//     s16 tmp0;
//     s16 tmp2;
//     s16 tmp4;
//
//     tmp0 = D_80203FE0[2].unk0;
//     tmp4 = D_80203FE0[2].unk4;
//     tmp2 = D_80203FE0[2].unk2 - arg0;
//
//     D_80203FE0[26].unk0 = tmp0;
//     D_80203FE0[26].unk2 = tmp2;
//     D_80203FE0[26].unk4 = tmp4;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB870_6CCF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BB938_6CCFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBA10_6CD0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBC90_6CD340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BBFA0_6CD650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC1F4_6CD8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC350_6CDA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC628_6CDCD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BC900_6CDFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BCC50_6CE300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BCDA0_6CE450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BCF38_6CE5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BD21C_6CE8CC.s")

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BD358_6CEA08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BD40C_6CEABC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BE1A0_6CF850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BEAB0_6D0160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BF3C0_6D0A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802BFF84_6D1634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C0364_6D1A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C13E4_6D2A94.s")

void func_802C1830_6D2EE0(u16 arg0, struct061 *arg1) {
    func_802C19CC_6D307C(&D_803D5528->unk370, arg1->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk384, arg1->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk398, arg1->unk4, 5, 13, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk3AC, arg1->unk6, 6, 16, 0, arg0);
}

void func_802C18FC_6D2FAC(u16 arg0, u16 arg1, struct061 *arg2) {
    func_802C19CC_6D307C(&D_803D5528->unk370, arg2->unk0, 3, 7, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk384, arg2->unk2, 4, 10, 0, arg0);
    func_802C19CC_6D307C(&D_803D5528->unk398, arg2->unk4, 5, 13, 0, arg1);
    func_802C19CC_6D307C(&D_803D5528->unk3AC, arg2->unk6, 6, 16, 0, arg1);
}

void func_802C19CC_6D307C(s32 *arg0, s16 arg1, u16 arg2, u16 arg3, s32 arg4, u16 arg5) {
    s16 tmp0 = D_80203FE0[arg2].unk0;
    s16 tmp2 = D_80203FE0[arg2].unk2;

    D_80203FE0[arg3].unk0 = tmp0;
    D_80203FE0[arg3].unk2 = tmp2;
    D_80203FE0[arg3].unk4 = arg1 + arg5;

    D_80203FE0[arg3+1].unk0 = tmp0;
    D_80203FE0[arg3+1].unk2 = tmp2;
    D_80203FE0[arg3+1].unk4 = arg1;

    D_80203FE0[arg3+2].unk0 = tmp0;
    D_80203FE0[arg3+2].unk2 = tmp2;
    D_80203FE0[arg3+2].unk4 = arg1;
}

void func_802C1A44_6D30F4(u16 arg0, u16 arg1, s32 arg2) {
    D_80203FE0[14].unk2 = 0;
    D_80203FE0[14].unk0 = D_80203FE0[14].unk2;
    D_80203FE0[14].unk4 = D_80203FE0[2].unk4 - arg0;

    D_80203FE0[15].unk0 = 0;
    D_80203FE0[15].unk2 = D_80203FE0[14].unk2 + arg1;
    D_80203FE0[15].unk4 = D_80203FE0[14].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C1A88_6D3138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C23F8_6D3AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C287C_6D3F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C2D98_6D4448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3188_6D4838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C353C_6D4BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3C64_6D5314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C3F58_6D5608.s")

void func_802C4448_6D5AF8(s16 arg0) {
    if ((D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        if ((D_803D5540 & 7) == 0) {
            func_8032CA90_73E140(D_803D5524->unk7C, D_803D5524->unk9C, D_803D5530->xPos, D_803D5530->zPos, D_803D5530->yPos);
        }
    }
    D_80203FE0[5].unk0 = D_80203FE0[0].unk0;
    D_80203FE0[5].unk2 = D_80203FE0[0].unk2;
    D_80203FE0[5].unk4 = D_80203FE0[0].unk4 - arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C44E8_6D5B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C4A70_6D6120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C56D0_6D6D80.s")

void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;

    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + (D_80152350.unk2D0[arg2] * arg0 / 256);
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (D_80152350.unk384[arg2] * arg0 / 256);

    D_80203FE0[20].unk0 = D_80203FE0[19].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C58E4_6D6F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C5EF4_6D75A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C5F34_6D75E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C6468_6D7B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C64E0_6D7B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C652C_6D7BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C6C00_6D82B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C6FF4_6D86A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C71BC_6D886C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C7310_6D89C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C75A4_6D8C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C7600_6D8CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C78B0_6D8F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C79E0_6D9090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CCEF0/func_802C7A7C_6D912C.s")

void func_802C7B18_6D91C8(struct061 *arg0, s16 arg1) {
    s16 temp_v0;
    s16 temp_v1;

    temp_v0 = arg0->unk0;
    temp_v1 = arg0->unk2;

    arg0->unk0 = ((temp_v0 * D_80152350.unk384[arg1]) + (temp_v1 * D_80152350.unk2D0[arg1])) / 256;
    arg0->unk2 = ((temp_v1 * D_80152350.unk384[arg1]) - (temp_v0 * D_80152350.unk2D0[arg1])) / 256;
}

void func_802C7BB4_6D9264(u16 arg0) {
    D_803D5528->unk37A = D_803D5528->unk374;
    D_803D5528->unk37C = D_803D5528->unk376;
    D_803D5528->unk37E = D_803D5528->unk378;
    D_803D5528->unk38E = D_803D5528->unk388;
    D_803D5528->unk390 = D_803D5528->unk38A;
    D_803D5528->unk392 = D_803D5528->unk38C;
    D_803D5528->unk3A2 = D_803D5528->unk39C;
    D_803D5528->unk3A4 = D_803D5528->unk39E;
    D_803D5528->unk3A6 = D_803D5528->unk3A0;
    D_803D5528->unk3B6 = D_803D5528->unk3B0;
    D_803D5528->unk3B8 = D_803D5528->unk3B2;
    D_803D5528->unk3BA = D_803D5528->unk3B4;
    D_803D552C->unk2FE = D_803D552C->unk2F2;
    D_803D552C->unk300 = arg0;
}
