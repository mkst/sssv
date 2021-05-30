#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C4A70_6D6120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C56D0_6D6D80.s")

void func_802C5824_6D6ED4(s16 arg0, s16 arg1, s16 arg2) {
    D_80203FE0[19].unk0 = D_80203FE0[1].unk0;

    D_80203FE0[19].unk2 = D_80203FE0[1].unk2 + (D_80152350.unk2D0[arg2] * arg0 / 256);
    D_80203FE0[19].unk4 = D_80203FE0[1].unk4 + (D_80152350.unk384[arg2] * arg0 / 256);

    D_80203FE0[20].unk0 = D_80203FE0[19].unk0;
    D_80203FE0[20].unk2 = D_80203FE0[19].unk2 + arg1;
    D_80203FE0[20].unk4 = D_80203FE0[19].unk4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C58E4_6D6F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5EF4_6D75A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C5F34_6D75E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6468_6D7B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C64E0_6D7B90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C652C_6D7BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6C00_6D82B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C6FF4_6D86A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C71BC_6D886C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C7310_6D89C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C75A4_6D8C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C7600_6D8CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C78B0_6D8F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C79E0_6D9090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D6120/func_802C7A7C_6D912C.s")

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
