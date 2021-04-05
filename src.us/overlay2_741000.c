#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032F950_741000.s")
// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FD0C_7413BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8032FF94_741644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80332444_743AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80334470_745B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033641C_747ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803378BC_748F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80337ECC_74957C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80338E1C_74A4CC.s")

void func_803391D0_74A880(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = 0.0f;
    D_803F2AD0->unk90 = -1.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 128.0f;
}

void func_80339238_74A8E8(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = 1.0f;
    D_803F2AD0->unk90 = 0.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 64.0f;
}

void func_803392A0_74A950(u8 arg0) {
    func_80338E1C_74A4CC(arg0);
    D_803F2AD0->unk8C = -1.0f;
    D_803F2AD0->unk90 = 0.0f;
    D_803F2AD0->unk20 = D_803F2AD0->unk24 = 192.0f;
}

void func_80339308_74A9B8(u8 arg0) {
    f32 tmp;

    D_803F2AD0 = &D_803F28E0[arg0];
    tmp = D_803F2AD0->unk20;
    func_80338E1C_74A4CC(arg0);
    if ((tmp > 32.0) && (tmp <= 96.0)) {
        D_803F2AD0->unk20 = 64.0f;
        D_803F2AD0->unk8C = 1.0f;
        D_803F2AD0->unk90 = 0.0f;
    } else if ((tmp > 96.0) && (tmp <= 160.0)) {
        D_803F2AD0->unk20 = 128.0f;
        D_803F2AD0->unk8C = 0.0f;
        D_803F2AD0->unk90 = -1.0f;
    } else if ((tmp > 160.0) && (tmp <= 224.0)) {
        D_803F2AD0->unk20 = 192.0f;
        D_803F2AD0->unk8C = -1.0f;
        D_803F2AD0->unk90 = 0.0f;
    } else {
        D_803F2AD0->unk20 = 0.0f;
        D_803F2AD0->unk8C = 0.0f;
        D_803F2AD0->unk90 = 1.0f;
    }
    D_803F2AD0->unk24 = D_803F2AD0->unk20;
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803394E4_74AB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80339B84_74B234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AAC8_74C178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033AC68_74C318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B118_74C7C8.s")

void func_8033B440_74CAF0(u8 arg0) {
    f32 temp_f0;
    f32 temp_f14;
    f32 phi_f2;

    D_803F2AD0 = &D_803F28E0[arg0];
    D_803F2AD0->unk8 = D_803F2AB4;
    D_803F2AD0->unkC = D_803F2AB8;
    D_803F2AD0->unk10 = D_803F2ABC;
    D_803F2AD0->unk74 = D_803F2AA8;
    D_803F2AD0->unk78 = D_803F2AAC;
    D_803F2AD0->unk7C = D_803F2AB0;
    D_803F2AD0->unk8C = D_803A6CD0;
    D_803F2AD0->unk90 = D_803A6CD4;
    D_803F2AD0->unk94 = D_803A6CD8;
    temp_f14 = D_803F2AD0->unk8 - D_803F2AD0->unk74;
    temp_f0 = D_803F2AD0->unkC - D_803F2AD0->unk78;
    if ((temp_f0 == 0.0) && (temp_f14 == 0.0)) {
        phi_f2 = 0.0f;
    } else {
        phi_f2 = func_801286B8(-temp_f0, temp_f14);
    }
    D_803F2AD0->unk24 = phi_f2;
    D_803F2AD0->unk20 = phi_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B594_74CC44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033B9B8_74D068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C054_74D704.s")

void func_8033C320_74D9D0(s32 arg0) {
    D_803F2AC5 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C334_74D9E4.s")

void func_8033C814_74DEC4(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C = sp3C + arg6;
    sp38 = sp38 + arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, sp34, 127, 1, arg8);
}

void func_8033C8EC_74DF9C(s16 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    func_8033E6B8_74FD68(arg3, arg4, arg5 + 10.0, &sp3C, &sp38, &sp34);
    sp3C = sp3C + arg6;
    sp38 = sp38 + arg7;
    func_8033C9CC_74E07C(arg0, arg1, arg2, 127, sp3C, sp38, (s16)sp34 + 34, 127, 1, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033C9CC_74E07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033D604_74ECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033DF88_74F638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033E430_74FAE0.s")

void func_8033E6B8_74FD68(f32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 tmp0;
    f32 tmp1;
    f32 tmp2;

    tmp1 = arg1 * D_803BE5F8 * 0.00390625;
    tmp0 = sinf(tmp1);
    tmp2 = arg0 * D_803BE600 * 0.00390625;
    *arg3 = D_803F2AD0->unk8 - cosf(tmp2) * (arg2 * tmp0);
    tmp0 = cosf(tmp1);
    *arg4 = D_803F2AD0->unkC - cosf(tmp2) * (arg2 * tmp0);
    *arg5 = D_803F2AD0->unk10 + sinf(tmp2) * arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033E7C8_74FE78.s")

void func_8033EF94_750644(u16 *arg0, u16 arg1) {
    u8 res = 0;

    if (((*arg0 & 8) != 0) && ((arg1 & 8) == 0)) {
        if (D_803F2C6E < MIN(D_803F28E0[D_803F2A98].unk66, 0)) {
            D_803F2C6E = MIN(MIN(MAX(D_803F2C6E + 1, D_803F28E0[D_803F2A98].unk64 + 1), D_803F28E0[D_803F2A98].unk66), 0);
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            res = 1;
        } else {
            res = 2;
        }
    }
    if (((*arg0 & 4) != 0) && ((arg1 & 4) == 0)) {
        if (D_803F2C6E > MAX(D_803F28E0[D_803F2A98].unk65, -2)) {
            D_803F2C6E = MAX(MAX(MIN(D_803F2C6E - 1, D_803F28E0[D_803F2A98].unk64 - 1), D_803F28E0[D_803F2A98].unk65), -2);
            D_803F28E0[D_803F2A98].unk64 = D_803F2C6E;
            res = 1;
        } else {
            res = 2;
        }
    }

    if (res == 2) {
        func_8032C508_73DBB8(16, 0x4000, 0, 1.0f);
    } else if (res == 1) {
        func_8032C508_73DBB8(15, 0x2A00, 0, 1.0f);
    }
}

void func_8033F23C_7508EC(s16 arg0) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E -= arg0;
    }
}

void func_8033F294_750944(s16 arg0) {
    if (D_803F28E0[D_803F2A98].unkD6 == 1) {
        D_803F2C6E += arg0;
    }
}

void func_8033F2EC_75099C(void) {
    D_803F2C70 = D_803F2C6E;
}

void func_8033F300_7509B0(void) {
    D_803F2C70 = MIN(D_803F2C70, D_803F28E0[D_803F2A98].unk66);
    D_803F2C70 = MAX(D_803F2C70, D_803F28E0[D_803F2A98].unk65);
    D_803F2C6E = D_803F2C70;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8033F380_750A30.s")

void func_80340E08_7524B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s8 arg5, s8 arg6, u8 arg7, s16 arg8) {
    memset_bytes((u8*)&D_803F2BF8, 0, 32);
    D_803F2BF8.unk12 = arg0;
    D_803F2BF8.unk14 = arg1;
    D_803F2BF8.unk15 = arg2;
    D_803F2BF8.unk16 = arg3;
    D_803F2BF8.unk17 = arg4;
    D_803F2BF8.unkA = arg8;
    D_803F2BF8.unk1A = arg6;
    D_803F2BF8.unk19 = arg5;
    D_803F2BF8.unk1B = arg7;
    D_803F2BF8.unk18 = 1;
    func_80340EA4_752554(&D_803F2BF8, -1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80340EA4_752554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_803415BC_752C6C.s")

void func_803421E0_753890(s16 arg0) {
    if (D_803F2ACA < arg0) {
        D_803F2ACA = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8034220C_7538BC.s")

void func_80342318_7539C8(s32 arg0, s32 arg1, s32 arg2) {
    func_803423C4_753A74(0, arg0 / 65536.0, arg1 / 65536.0, arg2 / 65536.0);
    func_803423C4_753A74(1, arg0 / 65536.0, arg1 / 65536.0, arg2 / 65536.0);
}

void func_803423C4_753A74(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_803F28E0[arg0].unk8 = D_803F28E0[arg0].unk8 + arg1;
    D_803F28E0[arg0].unkC = D_803F28E0[arg0].unkC + arg2;
    D_803F28E0[arg0].unk10 = D_803F28E0[arg0].unk10 + arg3;
    D_803F28E0[arg0].unk74 = D_803F28E0[arg0].unk74 + arg1;
    D_803F28E0[arg0].unk78 = D_803F28E0[arg0].unk78 + arg2;
    D_803F28E0[arg0].unk7C = D_803F28E0[arg0].unk7C + arg3;
    D_803F28E0[arg0].unk5A = D_803F28E0[arg0].unk5A + arg1 * 0.015625;
    D_803F28E0[arg0].unk5C = D_803F28E0[arg0].unk5C + arg2 * 0.015625;
    D_803F28E0[arg0].unk5E = D_803F28E0[arg0].unk5E + arg3 * 0.015625;
    D_803F28E0[arg0].unk98 = D_803F28E0[arg0].unk98 + arg1;
    D_803F28E0[arg0].unk9C = D_803F28E0[arg0].unk9C + arg2;
    D_803F28E0[arg0].unkA0 = D_803F28E0[arg0].unkA0 + arg3;
    D_803F28E0[arg0].unkD0 = D_803F28E0[arg0].unkD0 + arg1;
    D_803F28E0[arg0].unkD2 = D_803F28E0[arg0].unkD2 + arg2;
    D_803F28E0[arg0].unkD4 = D_803F28E0[arg0].unkD4 + arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80342550_753C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343438_754AE8.s")

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343720_754DD0.s")

void func_80343A50_755100(void) {
    if (D_803F2C1E > 0) {
        D_803F2C1E -= 1;
    } else if (((D_803F2C20 + 1) % 8) != D_803F2C22) {
        D_803F2C20 = (D_803F2C20 + 1) % 8;
        D_803F2C1E = D_803F2AF8[D_803F2C20].unkA + D_803F2AF8[D_803F2C20].unk8;
    } else {
        D_803F2AC6 = 1;
    }
}

// uses jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343AE0_755190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80343C44_7552F4.s")
// JUSTREG: perhaps not quite this?
// void func_80343C44_7552F4(s16 arg0, s16 *arg1, s16 *arg2) {
//     s16 *tmp = D_803A7B3C[arg0];
//     *arg1 = tmp[0];
//     *arg2 = tmp[1];
// }

void func_80343C74_755324(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4) {
    memset_bytes((u8*)&D_803F2AD8, 0, sizeof(D_803F2AD8));
    D_803F2AD8.unk18 = 1;
    D_803F2AD8.unkA = 40;
    D_803F2AD8.unk12 = arg0;
    D_803F2AD8.unk17 = arg1;
    D_803F2AD8.unk19 = arg2;
    D_803F2AD8.unk1A = arg3;
    D_803F2AD8.unk1B = arg4;
    if (((D_803F2C20 + 1) % 8) == D_803F2C22) {
        if ((D_803F2AF8[D_803F2C20].unk18 != 1) && (D_803F2AF8[D_803F2C20].unk18 != 0)) {
            D_803F2AF8[D_803F2C20].unkA = 40;
        }
    }
}

void func_80343D44_7553F4(u8 *arg0, s8 arg1) {
    func_80343AE0_755190(5, (s16) ((*arg0 << 5) - 136), 40, arg0, 0, 0, 0, 0, 0, 0, 44, arg1, -2, 0, 1);
}

void func_80343DC0_755470(void) {
    D_803F2C20 = 0;
    D_803F2C22 = 1;
    memset_bytes((u8*)&D_803F2AF8, 0, 32);
    D_803F2C1E = 0;
    D_803F2C18[0] = 0;
    D_803F2C18[1] = 0;
    D_803F2C18[2] = 0;

    D_803F28E0[D_803F2A98].unk0 = 27;
    D_803F28E0[D_803F2A98].unk2 = 0;
    D_803F28E0[D_803F2A98].unkD6 = 4;
    D_803F28E0[D_803F2A98].unk74 = D_803F2C44 - D_803F28E0[D_803F2A98].unkA4;
    D_803F28E0[D_803F2A98].unk78 = D_803F2C48 - D_803F28E0[D_803F2A98].unkA8;
    D_803F28E0[D_803F2A98].unk7C = D_803F2C4C;
    D_803F28E0[D_803F2A98].unk8 = D_803F2C50 - D_803F28E0[D_803F2A98].unkA4;
    D_803F28E0[D_803F2A98].unkC = D_803F2C54 - D_803F28E0[D_803F2A98].unkA8;
    D_803F28E0[D_803F2A98].unk10 = D_803F2C58;
    D_803F28E0[D_803F2A98].unk8C = D_80204200;
    D_803F28E0[D_803F2A98].unk90 = D_80204204;
    D_803F28E0[D_803F2A98].unk94 = D_80204208;

    D_803F2AF8[D_803F2C20].unk12 = D_803F28E0[D_803F2A98].unk2;
    D_803F2AF8[D_803F2C20].unk17 = D_803F28E0[D_803F2A98].unkC9;
    D_803F2AF8[D_803F2C20].unk18 = D_803F28E0[D_803F2A98].unkD6;
    D_803F2AF8[D_803F2C20].unk0 = D_803F28E0[D_803F2A98].unkCC;
    D_803F2AF8[D_803F2C20].unkC = D_803F28E0[D_803F2A98].unkD0;
    D_803F2AF8[D_803F2C20].unkE = D_803F28E0[D_803F2A98].unkD2;
    D_803F2AF8[D_803F2C20].unk10 = D_803F28E0[D_803F2A98].unkD4;
    D_803F2AF8[D_803F2C20].unk14 = D_803F28E0[D_803F2A98].unk5A;
    D_803F2AF8[D_803F2C20].unk15 = D_803F28E0[D_803F2A98].unk5C;
    D_803F2AF8[D_803F2C20].unk16 = D_803F28E0[D_803F2A98].unk5E;
    D_803F2AF8[D_803F2C20].unk19 = D_803F28E0[D_803F2A98].unk65;
    D_803F2AF8[D_803F2C20].unk1A = D_803F28E0[D_803F2A98].unk66;
    D_803F2AF8[D_803F2C20].unk1B = D_803F28E0[D_803F2A98].unk67;
}

void func_80343F58_755608(s16 arg0) {
    D_803F2C6E = arg0;
}

void func_80343F68_755618(void) {
    D_803F2AA7 = 1;
}

void func_80343F78_755628(void) {
    if (D_803F2AA7 != 0) {
        D_803F2AA7 = 0;
        if ((D_803F2C18[0] != 0) && (D_803F28E0[D_803F2A98].unk0 == 30)) {
            D_803F2C18[1] = D_803F2C18[2] - D_803F2C18[1];
            D_803F2A98 = (D_803F2A98 + 1) & 1;
            D_803F2AC8 = (D_803F2AC8 + 1) & 1;
            D_803A6CEC = -1;
        }
    }
}

// no idea
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_8034401C_7556CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_741000/func_80344158_755808.s")
// needs rest of file to match for the rodata
// s32 func_80344158_755808(s16 arg0) {
//     switch (arg0 - 3) {
//     case 0:
//     case 2:
//     case 3:
//     case 4:
//     case 14:
//     case 25:
//         return 1;
//     default:
//         return 0;
//     }
// }

void func_8034419C_75584C(s32 arg0) {
    func_80343AE0_755190(4, 0, 30, arg0, 0, 0, 0, 0, 0, 0, 228, 1, 0, 0, 0);
}

void func_803441FC_7558AC(void) {
    if (D_803F2C18[0] != 0) {
        if ((D_803F2C18[0] == 1) || (D_803F2C18[0] == 2)) {
            D_803F2C18[0] = 0;
            D_803F2C18[1] = 0;
        }
    }
}
