#include <ultra64.h>
#include "common.h"


void func_802B9130_6CA7E0(struct061 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    s16 sp36;
    s16 sp34;
    s16 sp28;
    s16 temp_v1;
    s16 phi_a1;
    s16 tmp;

    if ((D_803D5530->state == 3) ||
        (D_803D5530->state == 6) ||
        (D_803D5530->state == 4) ||
        (D_803D5530->state == 182) ||
        (D_803D5530->state == 185) ||
        (D_803D5530->state == 183)) {

        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
    } else {
        D_803D552C->unk2F6 = (u16) D_803D552C->unk2F2;
        D_803D552C->unk2F8 = (u16) D_803D552C->unk2F4;
    }

    D_80203FE0[3].unk0 = -arg2;
    D_80203FE0[3].unk4 = 0;
    D_80203FE0[4].unk4 = 0;
    D_80203FE0[5].unk2 = -arg1;
    D_80203FE0[5].unk0 = -arg2;
    D_80203FE0[5].unk4 = 0;
    D_80203FE0[6].unk2 = -arg1;
    D_80203FE0[6].unk4 = 0;
    D_80203FE0[3].unk2 = arg1;
    D_80203FE0[4].unk0 = arg2;
    D_80203FE0[4].unk2 = arg1;
    D_80203FE0[6].unk0 = arg2;

    func_802BCF38_6CE5E8((u16) arg1, (u16) arg2, arg0);
    tmp = arg0->unk0;
    sp36 = (arg0->unk2 + tmp) >> 1;
    sp34 = (arg0->unk6 + arg0->unk4) >> 1;

    temp_v1 = tmp - sp36;
    if (temp_v1 >= arg2) {
        phi_a1 = 90;
    } else if (-arg2 >= temp_v1) {
        phi_a1 = -90;
    } else {
        phi_a1 = func_8012835C((temp_v1 * 256) / arg2);
    }

    if (phi_a1 < -30) {
        phi_a1 = (phi_a1 / 2) - 15;
    }
    if (phi_a1 > 30) {
        phi_a1 = (phi_a1 / 2) + 15;
    }

    func_802C7A7C_6D912C(&D_80203FE0[3], phi_a1);
    func_802C7A7C_6D912C(&D_80203FE0[4], phi_a1);

    temp_v1 = arg0->unk4 - sp34;

    if (temp_v1 >= arg2) {
        phi_a1 = 90;
    } else if (-arg2 >= temp_v1) {
        phi_a1 = -90;
    } else {
        phi_a1 = func_8012835C((temp_v1 * 256) / arg2);
    }

    if (phi_a1 < -30) {
        phi_a1 = (phi_a1 / 2) - 15;
    }

    if (phi_a1 > 30) {
        phi_a1 = (phi_a1 / 2) + 15;
    }

    func_802C7A7C_6D912C(&D_80203FE0[5], phi_a1);
    func_802C7A7C_6D912C(&D_80203FE0[6], phi_a1);

    sp28 = (sp36 + sp34) >> 1;
    temp_v1 = sp36 - sp28;

    if (arg1) {}; // regalloc

    if (temp_v1 >= arg1) {
        phi_a1 = -90;
    } else if (-arg1 >= temp_v1) {
        phi_a1 = 90;
    } else {
        phi_a1 = (func_8012835C(((temp_v1 * 256) / arg1)) * -1);
    }

    if (phi_a1 < -40) {
        phi_a1 = (phi_a1 / 2) - 20;
    }

    if (phi_a1 > 40) {
        phi_a1 = (phi_a1 / 2) + 20;
    }

    func_802C79E0_6D9090(&D_80203FE0[3], phi_a1);
    func_802C79E0_6D9090(&D_80203FE0[4], phi_a1);
    func_802C79E0_6D9090(&D_80203FE0[5], phi_a1);
    func_802C79E0_6D9090(&D_80203FE0[6], phi_a1);

    D_80203FE0[3].unk4 += (sp28 + arg3) - arg4;
    D_80203FE0[4].unk4 += (sp28 + arg3) - arg4;
    D_80203FE0[5].unk4 += (sp28 + arg3) - arg4;
    D_80203FE0[6].unk4 += (sp28 + arg3) - arg4;
    D_80203FE0[0].unk0 = 0;
    D_80203FE0[0].unk2 = 0;
    D_80203FE0[0].unk4 = (sp28 + arg3) - arg4;
}

void func_802B964C_6CACFC(void) {
    D_80203FE0[1].unk0 = (D_80203FE0[3].unk0 + D_80203FE0[4].unk0) >> 1;
    D_80203FE0[1].unk2 = (D_80203FE0[3].unk2 + D_80203FE0[4].unk2) >> 1;
    D_80203FE0[1].unk4 = (D_80203FE0[3].unk4 + D_80203FE0[4].unk4) >> 1;
    D_80203FE0[2].unk0 = (D_80203FE0[5].unk0 + D_80203FE0[6].unk0) >> 1;
    D_80203FE0[2].unk2 = (D_80203FE0[5].unk2 + D_80203FE0[6].unk2) >> 1;
    D_80203FE0[2].unk4 = (D_80203FE0[5].unk4 + D_80203FE0[6].unk4) >> 1;
}

void func_802B96D0_6CAD80(s16 *arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_802BD358_6CEA08(arg0);
    D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk0 = D_80203FE0[2].unk2;
    D_80203FE0[2].unk4 = arg2 + *arg0;

    D_80203FE0[1].unk2 = 0;
    D_80203FE0[0].unk2 = 0;
    D_80203FE0[1].unk0 = D_80203FE0[1].unk2;
    D_80203FE0[1].unk4 = (arg1 * 2) + D_80203FE0[2].unk4;
    D_80203FE0[0].unk0 = D_80203FE0[0].unk2;
    D_80203FE0[0].unk4 = (D_80203FE0[1].unk4 + D_80203FE0[2].unk4) >> 1;
}

void func_802B975C_6CAE0C(s16 *arg0, s16 arg1, s16 arg2) {
    if ((D_803D5530->state == 3) || (D_803D5530->state == 6) || (D_803D5530->state == 4) ||
        (D_803D5530->state == 0xB6) || (D_803D5530->state == 0xB9) || (D_803D5530->state == 0xB7) ||
        (D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 * 256) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 * 256) / (u32) D_803D552C->unk2FA;
    } else {
        D_803D552C->unk2F6 = D_803D552C->unk2F2;
        D_803D552C->unk2F8 = D_803D552C->unk2F4;
    }

    func_802BD358_6CEA08(arg0);
    D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk0 = D_80203FE0[2].unk2;
    D_80203FE0[2].unk4 = *arg0;

    D_80203FE0[1].unk0 = D_80203FE0[1].unk2 = 0;
    D_80203FE0[24].unk0 = D_80203FE0[24].unk2 = 0;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 0xB6) || (D_803D5530->state == 6) || (D_803D5530->state == 0xB9)) {
        D_80203FE0[1].unk0 += ((arg1 *        (D_80152C78[(s16)D_803D552C->unk2F6 & 0xFF] >> 7)) >> 8) >> arg2;
        D_80203FE0[2].unk4 += ((arg1 * (256 - (D_80152C78[((s16)(D_803D552C->unk2F6 << 1) + 64) & 0xFF] >> 7))) >> 8) >> arg2;
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        D_80203FE0[1].unk0 += ((arg1 *        (D_80152C78[(s16)D_803D552C->unk2F6 & 0xFF] >> 7)) >> 8) >> arg2;
        D_80203FE0[2].unk4 += ((arg1 * (256 - (D_80152C78[((s16)(D_803D552C->unk2F6 << 1) + 64) & 0xFF] >> 7))) >> 8) >> arg2;
    }

    D_80203FE0[1].unk4 = D_80203FE0[2].unk4 + (arg1 << 1);
    D_80203FE0[24].unk4 = D_80203FE0[2].unk4 + (arg1 << 1);
    D_80203FE0[0].unk0 = D_80203FE0[0].unk2 = 0;
    D_80203FE0[0].unk4 = (D_80203FE0[1].unk4 + D_80203FE0[2].unk4) >> 1;
}

void func_802B9A5C_6CB10C(s16 *arg0, s16 arg1) {
    if ((D_803D5530->state == 3) || (D_803D5530->state == 6) || (D_803D5530->state == 4) ||
        (D_803D5530->state == 0xB6) || (D_803D5530->state == 0xB9) || (D_803D5530->state == 0xB7) ||
        (D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 * 256) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 * 256) / (u32) D_803D552C->unk2FA;
    } else {
        D_803D552C->unk2F6 = D_803D552C->unk2F2;
        D_803D552C->unk2F8 = D_803D552C->unk2F4;
    }

    func_802BD358_6CEA08(arg0);
    D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk0 = D_80203FE0[2].unk2;
    D_80203FE0[2].unk4 = *arg0;

    D_80203FE0[0].unk2 = 0;
    D_80203FE0[1].unk2 = 0;

    D_80203FE0[24].unk0 = D_80203FE0[24].unk2 = 0;;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 0xB6) || (D_803D5530->state == 6) || (D_803D5530->state == 0xB9)) {
        D_80203FE0[2].unk4 += ((arg1 * (256 - (D_80152C78[((s16)(D_803D552C->unk2F6 << 1) + 64) & 0xFF] >> 7))) >> 10);
        D_80203FE0[2].unk0 += ((arg1 *        (D_80152C78[(s16)D_803D552C->unk2F6 & 0xFF] >> 7)) >> 10);
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        D_80203FE0[2].unk4 += ((arg1 *       ((D_80152C78[((s16)(D_803D552C->unk2F6 << 1) + 64) & 0xFF] >> 7))) >> 10);
        D_80203FE0[2].unk0 += ((arg1 *        (D_80152C78[(s16)D_803D552C->unk2F6 & 0xFF] >> 7)) >> 10);
    }

    D_80203FE0[0].unk4 = (D_80203FE0[2].unk4 + arg1);

    D_80203FE0[1].unk4 = D_80203FE0[2].unk4 + (arg1 << 1);
    D_80203FE0[1].unk0 = D_80203FE0[2].unk0;
    D_80203FE0[0].unk0 = D_80203FE0[2].unk0;
    D_80203FE0[24].unk4 = D_80203FE0[2].unk4 + (arg1 << 1);
}

void func_802B9D20_6CB3D0(s16 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    u16 pad;
    s16 phi_t5;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 6) || (D_803D5530->state == 0xB6) ||
        (D_803D5530->state == 0xB9) || (D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) ||
        (D_803D5530->state == 0x8F)) {
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
        phi_t5 = 4;
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
        phi_t5 = 6;
    } else {
        D_803D552C->unk2F6 = D_803D552C->unk2F2;
        D_803D552C->unk2F8 = D_803D552C->unk2F4;
        phi_t5 = 0;
    }

    func_802BD358_6CEA08(arg0);

    D_80203FE0[2].unk0 = D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk4 = *arg0 + ((arg2 * 3) >> 2);

    D_80203FE0[0].unk0 = D_80203FE0[0].unk2 = 0;
    D_80203FE0[1].unk0 = D_80203FE0[1].unk2 = 0;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 0xB6) ||
        (D_803D5530->state == 6) || (D_803D5530->state == 0xB9)) {
        D_80203FE0[2].unk4 += (phi_t5 * arg1 * (256 - (D_80152C78[((s16)(D_803D552C->unk2F6 * 2) + 64) & 0xFF] >> 7))) >> 13;
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        D_80203FE0[2].unk4 += (phi_t5 * arg1 * (256 - (D_80152C78[((s16)(D_803D552C->unk2F6 * 2) + 64) & 0xFF] >> 7))) >> 13;
    }
    D_80203FE0[0].unk4 = D_80203FE0[2].unk4 + arg1;
    D_80203FE0[1].unk4 = D_80203FE0[2].unk4 + (arg1 * 2);
    D_80203FE0[1].unk0 += ((((phi_t5 * arg1) * ((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4)) >> 8));

    D_80203FE0[3].unk0 = D_80203FE0[1].unk0 - arg3;
    D_80203FE0[3].unk2 = D_80203FE0[1].unk2 - ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg3)) >> 9);
    D_80203FE0[3].unk4 = D_80203FE0[1].unk4 + ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg3)) >> 9);

    D_80203FE0[4].unk0 = D_80203FE0[1].unk0 + arg3;
    D_80203FE0[4].unk2 = D_80203FE0[1].unk2 + ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg3)) >> 9);
    D_80203FE0[4].unk4 = D_80203FE0[1].unk4 - ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg3)) >> 9);

    D_80203FE0[5].unk0 = D_80203FE0[2].unk0 - arg4;
    D_80203FE0[5].unk2 = D_80203FE0[2].unk2;
    D_80203FE0[5].unk4 = D_80203FE0[2].unk4 + ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg2)) >> 8);

    D_80203FE0[6].unk0 = D_80203FE0[2].unk0 + arg4;
    D_80203FE0[6].unk2 = D_80203FE0[2].unk2;
    D_80203FE0[6].unk4 = D_80203FE0[2].unk4 - ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t5 * arg2)) >> 8);
}

#if 0
// real junk
void func_802BA220_6CB8D0(struct061 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5 /*unused*/) {
    s16 phi_a2;
    s16 phi_t4;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 6) || (D_803D5530->state == 0xB6) ||
        (D_803D5530->state == 0xB9) || (D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) ||
        (D_803D5530->state == 0x8F)) {
        phi_t4 = 4;
        phi_a2 = 2;
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        phi_t4 = 6;
        phi_a2 = 8;
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
    } else {
        phi_t4 = 0;
        phi_a2 = 0;
        D_803D552C->unk2F6 = D_803D552C->unk2F2;
        D_803D552C->unk2F8 = D_803D552C->unk2F4;
    }

    // WTF
    func_802BD21C_6CE8CC(arg3, arg0);

    D_80203FE0[2].unk0 = D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk4 = arg0->unk0 + arg2;

    // sp1A = ((phi_a2 * arg3) >> 4) + 0xA;
    D_80203FE0[0].unk0 = 0;
    D_80203FE0[1].unk0 = 0;
    D_80203FE0[1].unk2 = ((phi_a2 * arg3) >> 4) + 0xA;
    D_80203FE0[2].unk4 += ((((phi_t4 * arg3) * ((D_80152C78[(s16)(D_803D552C->unk2F6 * 2) & 0xFF] >> 7) >> 4)) >> 9));
    D_80203FE0[0].unk2 = ((((phi_a2 * arg3) >> 4) + 0xA) >> 1); // tbd

    if ((D_803D5530->state == 3) || (D_803D5530->state == 0xB6) || (D_803D5530->state == 6)) {
    } else {
        if (phi_a2 = D_803D5530->state) {
            // fake
        }
    }

    D_80203FE0[0].unk4 = D_80203FE0[2].unk4 + arg1;
    D_80203FE0[1].unk4 = D_80203FE0[2].unk4 + (arg1 * 2);
    D_80203FE0[1].unk4 += ((phi_t4 * arg3) * ((D_80152C78[(s16)(D_803D552C->unk2F6 * 2) & 0xFF] >> 7) >> 4)) >> 9;

    D_80203FE0[3].unk0 = D_80203FE0[1].unk0 - arg3;
    D_80203FE0[3].unk2 = D_80203FE0[1].unk2 + ((((D_80152C78[(s16) D_803D552C->unk2F6 & 0xFF] >> 7) >> 4) * (phi_t4 * arg3)) >> 8);
    D_80203FE0[3].unk4 = D_80203FE0[1].unk4;

    D_80203FE0[4].unk0 = D_80203FE0[1].unk0 + arg3;
    D_80203FE0[4].unk2 = D_80203FE0[1].unk2 - ((((D_80152C78[(s16) D_803D552C->unk2F6 & 0xFF] >> 7) >> 4) * (phi_t4 * arg3)) >> 8);
    D_80203FE0[4].unk4 = D_80203FE0[1].unk4;

    D_80203FE0[5].unk0 = D_80203FE0[2].unk0 - arg4;
    D_80203FE0[5].unk2 = D_80203FE0[2].unk2;
    D_80203FE0[5].unk4 = D_80203FE0[2].unk4 + ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t4 * arg2)) >> 10);

    D_80203FE0[6].unk0 = D_80203FE0[2].unk0 + arg4;
    D_80203FE0[6].unk2 = D_80203FE0[2].unk2;
    D_80203FE0[6].unk4 = D_80203FE0[2].unk4 - ((((D_80152C78[((s16) D_803D552C->unk2F6 + 64) & 0xFF] >> 7) >> 4) * (phi_t4 * arg2)) >> 10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CA7E0/func_802BA220_6CB8D0.s")
#endif

void func_802BA614_6CBCC4(s16 *arg0, s16 arg1) {
    if ((D_803D5530->state == 3) || (D_803D5530->state == 6) || (D_803D5530->state == 4) ||
        (D_803D5530->state == 0xB6) || (D_803D5530->state == 0xB9) || (D_803D5530->state == 0xB7) ||
        (D_803D5530->state == 0x8E) || (D_803D5530->state == 0x90) || (D_803D5530->state == 0x8F)) {
        D_803D552C->unk2F6 = (D_803D552C->unk2F2 << 8) / (u32) D_803D552C->unk2FA;
        D_803D552C->unk2F8 = (D_803D552C->unk2F4 << 8) / (u32) D_803D552C->unk2FA;
    } else {
        D_803D552C->unk2F6 = D_803D552C->unk2F2;
        D_803D552C->unk2F8 = D_803D552C->unk2F4;
    }

    func_802BD358_6CEA08(arg0);

    D_80203FE0[2].unk2 = 0;
    D_80203FE0[2].unk0 = D_80203FE0[2].unk2;
    D_80203FE0[2].unk4 = *arg0;
    D_80203FE0[1].unk2 = 0;
    D_80203FE0[1].unk0 = D_80203FE0[1].unk2;

    if ((D_803D5530->state == 3) || (D_803D5530->state == 0xB6) || (D_803D5530->state == 6) || (D_803D5530->state == 0xB9)) {
        D_80203FE0[2].unk4 += (arg1 * (D_80152C78[(s16)((D_803D552C->unk2F6 & 0xFF) >> 1) & 0xFF] >> 7)) >> 8;
        if ((((D_803D552C->unk2F6 & 0xFF) < (D_803D552C->unk2F8 & 0xFF)) || ((D_803D552C->unk2F8 == 0) && (D_803D552C->unk2F6 == 0))) && (D_803D5530->unk4A == 0)) {
            play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], (D_803A6680_7B7D30[D_803D5524->unk9C] * 5) >> 3, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    } else if ((D_803D5530->state == 4) || (D_803D5530->state == 0xB7)) {
        D_80203FE0[2].unk4 += (arg1 * (D_80152C78[(s16)((D_803D552C->unk2F6 & 0xFF) >> 1) & 0xFF] >> 7)) >> 7;
        if ((((D_803D552C->unk2F6 & 0xFF) < (D_803D552C->unk2F8 & 0xFF)) || ((D_803D552C->unk2F8 == 0) && (D_803D552C->unk2F6 == 0))) && (D_803D5530->unk4A == 0)) {
            play_sound_effect_at_location(D_803A65D0_7B7C80[D_803D5524->unk9C], D_803A6680_7B7D30[D_803D5524->unk9C], 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
    }

    if (D_803D552C->unk364 == 7) {
        u8 x = D_803D5544 - D_803D552C->unk334;
        D_80203FE0[2].unk4 += (arg1 * (D_80152C78[(s16)((u8)((x) << 4) >> 1) & 0xFF] >> 7)) >> 8;
    }
    D_80203FE0[1].unk4 = (D_80203FE0[2].unk4 + (arg1 * 2));
    if (D_803D5530->state == 5) {
        D_80203FE0[1].unk2 += ((arg1 >> 1));
    }
    D_80203FE0[0].unk2 = 0;
    D_80203FE0[0].unk0 = D_80203FE0[0].unk2;
    D_80203FE0[0].unk4 = (D_80203FE0[1].unk4 + D_80203FE0[2].unk4) >> 1;
}

void func_802BAA38_6CC0E8(u16 arg0, u16 arg1) {
    D_80203FE0[3].unk4 = 0;
    D_80203FE0[3].unk0 = -arg1;
    D_80203FE0[4].unk4 = 0;
    D_80203FE0[5].unk2 = -arg0;
    D_80203FE0[5].unk0 = -arg1;
    D_80203FE0[5].unk4 = 0;
    D_80203FE0[6].unk2 = -arg0;
    D_80203FE0[6].unk4 = 0;
    D_80203FE0[4].unk0 = arg1;
    D_80203FE0[6].unk0 = arg1;
    D_80203FE0[3].unk2 = arg0;
    D_80203FE0[4].unk2 = arg0;
    func_802C79E0_6D9090(&D_80203FE0[3], -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80203FE0[4], -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80203FE0[5], -D_803D5530->unk28);
    func_802C79E0_6D9090(&D_80203FE0[6], -D_803D5530->unk28);
    D_80203FE0[3].unk4 = (D_80203FE0[3].unk4 + (D_803D5524->unkB8 << 5));
    D_80203FE0[4].unk4 = (D_80203FE0[4].unk4 + (D_803D5524->unkB8 << 5));
    D_80203FE0[5].unk4 = (D_80203FE0[5].unk4 + (D_803D5524->unkB8 << 5));
    D_80203FE0[6].unk4 = (D_80203FE0[6].unk4 + (D_803D5524->unkB8 << 5));
    D_80203FE0[1].unk0 = ((D_80203FE0[3].unk0 + D_80203FE0[4].unk0) >> 1);
    D_80203FE0[1].unk2 = ((D_80203FE0[3].unk2 + D_80203FE0[4].unk2) >> 1);
    D_80203FE0[1].unk4 = ((D_80203FE0[3].unk4 + D_80203FE0[4].unk4) >> 1);
    D_80203FE0[2].unk0 = ((D_80203FE0[5].unk0 + D_80203FE0[6].unk0) >> 1);
    D_80203FE0[2].unk2 = ((D_80203FE0[5].unk2 + D_80203FE0[6].unk2) >> 1);
    D_80203FE0[2].unk4 = ((D_80203FE0[5].unk4 + D_80203FE0[6].unk4) >> 1);
    D_80203FE0[0].unk2 = 0;
    D_80203FE0[0].unk0 = D_80203FE0[0].unk2;
    D_80203FE0[0].unk4 = ((D_80203FE0[1].unk4 + D_80203FE0[2].unk4) >> 1);
}

void func_802BAC24_6CC2D4(u16 arg0, u16 arg1) {
    s16 velocity;

    D_80203FE0[0].unk2 = 0;

    D_80203FE0[1].unk0 = 0;
    D_80203FE0[1].unk2 = arg0;
    D_80203FE0[1].unk4 = 0;

    D_80203FE0[2].unk0 = 0;
    D_80203FE0[2].unk2 = -arg0;
    D_80203FE0[2].unk4 = 0;

    D_80203FE0[0].unk0 = D_80203FE0[0].unk2;
    D_80203FE0[0].unk4 = 0;

    velocity = (-D_803D5530->yVelocity.w) >> 14;
    if (velocity > 0) {
        velocity -= MIN(4, velocity);
    }
    if (velocity < 0) {
        velocity += MIN(4, -velocity);
    }

    velocity = MAX(-40, velocity);
    velocity = MIN(40, velocity);

    func_802C79E0_6D9090(&D_80203FE0[1], velocity);
    func_802C79E0_6D9090(&D_80203FE0[2], velocity);

    D_80203FE0[0].unk4 += arg1;
    D_80203FE0[1].unk4 += arg1;
    D_80203FE0[2].unk4 += arg1;
}

// used by seagull and vulture
void func_802BAD60_6CC410(u16 arg0, u16 arg1) {
    s32 temp_t9;
    s16 phi_a0;
    Animal * a;

    D_80203FE0[1].unk0 = 0;
    D_80203FE0[1].unk2 = arg0;
    D_80203FE0[1].unk4 = arg1;
    D_80203FE0[2].unk0 = 0;
    D_80203FE0[2].unk2 = -arg0;
    D_80203FE0[2].unk4 = arg1;
    D_80203FE0[0].unk2 = 0;
    D_80203FE0[0].unk0 = D_80203FE0[0].unk2;
    D_80203FE0[0].unk4 = arg1;

    if ((u16)D_803D5528->unk3C0.unk4 == 13) {
        phi_a0 = MIN(D_803D5528->unk3C0.unk6, 8);
        phi_a0 = phi_a0 * 32;
        temp_t9 = ((D_80152C78[(u8) phi_a0] >> 7) * arg0) >> 9;
        D_80203FE0[1].unk4 += temp_t9;
        D_80203FE0[2].unk4 += temp_t9;
    }
}

void func_802BAE24_6CC4D4(s16 *arg0, s16 *arg1, s16 arg2) {
    s16 phi_s0;

    s16 tmp;
    s16 temp_s5;
    s16 temp_s6;
    s16 temp_s7;

    if (D_803D552C->unk320 == NULL) {
        D_803D552C->unk318 = 0;
        return;
    }

    temp_s5 = D_803D5530->xPos.h;
    temp_s6 = D_803D5530->zPos.h;
    temp_s7 = D_803D5530->yPos.h + (D_80203FE0[0].unk4 / 32);

    *arg0 -= D_803D552C->unk318;
    *arg1 += D_803D552C->unk318;

    func_80321D74_733424(*arg0, *arg1);

    if (1) {};

    phi_s0 = 0;

    tmp = D_803D552C->unk320->xPos.h + (D_80152C78[D_803D552C->unk302 & 0xFF] >> 10);
    if (func_8033C9CC_74E07C(
        tmp,
        D_803D552C->unk320->zPos.h + (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 10),
        D_803D552C->unk320->yPos.h,
        0x7F,
        temp_s5,
        temp_s6,
        temp_s7,
        D_803D5530->unk160,
        0,
        0)) {

        while ((D_803D552C->unk318 < arg2) && (phi_s0 < 4)) {
            *arg0 += -1;
            *arg1 += 1;

            func_80321D74_733424(*arg0, *arg1);
            tmp = D_803D552C->unk320->xPos.h + (D_80152C78[D_803D552C->unk302 & 0xFF] >> 10);
            if (func_8033C9CC_74E07C(
                tmp,
                D_803D552C->unk320->zPos.h + (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 10),
                D_803D552C->unk320->yPos.h,
                0x7F,
                temp_s5,
                temp_s6,
                temp_s7,
                D_803D5530->unk160,
                0,
                0)) {

                D_803D552C->unk318++;
                phi_s0++;
            } else {
                *arg0 += -1;
                *arg1 += 1;
                break;
            }
        }
    } else {
        while ((D_803D552C->unk318 > 0) && (phi_s0 < 4)) {
            *arg0 += 1;
            *arg1 += -1;

            func_80321D74_733424(*arg0, *arg1);
            tmp = D_803D552C->unk320->xPos.h + (D_80152C78[D_803D552C->unk302 & 0xFF] >> 10);
            if (func_8033C9CC_74E07C(
                tmp,
                D_803D552C->unk320->zPos.h + (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 10),
                D_803D552C->unk320->yPos.h,
                0x7F,
                temp_s5,
                temp_s6,
                temp_s7,
                D_803D5530->unk160,
                0,
                0)) {
                *arg0 += 1;
                *arg1 += -1;
                break;
            }
            D_803D552C->unk318--;
            phi_s0++;
        }
    }
}

// used by vulture, seagull, parrot
void func_802BB1F0_6CC8A0(u16 arg0, u16 arg1) {
    s16 temp_a3;
    s16 temp_t0;
    s16 temp_t8;
    s16 var_v0;
    s16 var_v1;
    struct113 *temp_a2_2;
    u16 var_v1_2;
    s32 tmp;

    temp_a2_2 = &D_803D5528->unk3C0.unk4; // er?
    if ((temp_a2_2->unk0 != 0) && (D_803F2D10.unk0 == 0)) {
        temp_a2_2->unk2++;
    }

    switch (temp_a2_2->unk0) {
    default:
        tmp = 90 + ((D_80152C78[(s16)(D_803D5540 << 2) & 0xFF] >> 7) >> 4);
        var_v1 = var_v0 = tmp;
        temp_a2_2->unk0 = 0;
        break;
    case 9:
    case 13:
    case 14:
        var_v1_2 = temp_a2_2->unk2;
        if (temp_a2_2->unk0 == 0xD) {
            var_v1_2 = var_v1_2 << 1;
        }

        if (temp_a2_2->unk0 == 0xE) {
            var_v1_2 = var_v1_2 << 3;
            if (var_v1_2 > 36) {
                var_v1_2 -= 36;
            }
            if (var_v1_2 > 36) {
                var_v1_2 -= 36;
            }
            if (var_v1_2 > 36) {
                var_v1_2 -= 36;
            }
        }

        if (var_v1_2 < 5) {
            var_v0 = 40 + ((var_v1_2 * 130) / 4);
            var_v1 = 60 + ((var_v1_2 * 100) / 4);
        } else if (var_v1_2 < 13) {
            var_v0 = 170 - (((var_v1_2 - 4) * 100) / 8);
            var_v1 = 160 - (((var_v1_2 - 4) * 40) / 8);
        } else if (var_v1_2 < 21) {
            var_v0 = 70 - (((var_v1_2 - 12) * 60) / 8);
            var_v1 = 120 - (((var_v1_2 - 12) * 90) / 8);
        } else if (var_v1_2 < 37) {
            var_v0 = 10 + (((var_v1_2 - 20) * 80) / 16);
            var_v1 = 30 + (((var_v1_2 - 20) * 60) / 16);
        } else {
            temp_a2_2->unk0 = 0;
            var_v0 = 90;
            var_v1 = 0x5A;
        }
        break;
    case 12:
        if (temp_a2_2->unk2 > 20) {
            temp_a2_2->unk2 = 20;
        }
        var_v0 = 40 - ((temp_a2_2->unk2 * 0x1E) / 20);
        var_v1 = ((temp_a2_2->unk2 * 0x6E) / 20) + 0x3C;
        arg0 -= (arg0 * temp_a2_2->unk2) / 40;
        break;
    }

    temp_a3 = D_80203FE0[0].unk0;
    temp_t0 = D_80203FE0[0].unk2;
    temp_t8 = D_80203FE0[0].unk4;

    temp_a3 += ((arg0 * D_80152350.unk2D0[var_v0]) / 256);
    temp_t8 += ((arg0 * D_80152350.unk384[var_v0]) / 256);

    D_80203FE0[22].unk0 = temp_a3;
    D_80203FE0[22].unk2 = temp_t0;
    D_80203FE0[22].unk4 = temp_t8;

    D_80203FE0[24].unk0 = -temp_a3;
    D_80203FE0[24].unk2 = temp_t0;
    D_80203FE0[24].unk4 = temp_t8;

    temp_a3 += (arg1 * D_80152350.unk2D0[var_v1]) / 256;
    temp_t8 += (arg1 * D_80152350.unk384[var_v1]) / 256;

    D_80203FE0[23].unk0 = temp_a3;
    D_80203FE0[23].unk2 = temp_t0;
    D_80203FE0[23].unk4 = temp_t8;

    D_80203FE0[25].unk0 = -temp_a3;
    D_80203FE0[25].unk2 = temp_t0;
    D_80203FE0[25].unk4 = temp_t8;
}

#ifdef NON_MATCHING
// CURRENT (10)
void func_802BB70C_6CCDBC(s16 arg0, s16 arg1) {
    // u16 tmp = (arg0 + arg1);
    D_80203FE0[22].unk0 = arg0;
    D_80203FE0[22].unk2 = 0;
    D_80203FE0[22].unk4 = 0;

    D_80203FE0[24].unk0 = -arg0;
    D_80203FE0[24].unk2 = 0;
    D_80203FE0[24].unk4 = 0;

    D_80203FE0[23].unk0 = (arg0 + arg1) & 0xFFFF;
    D_80203FE0[23].unk2 = 0;
    D_80203FE0[23].unk4 = 0;

    D_80203FE0[25].unk0 = -(arg0 + arg1);
    D_80203FE0[25].unk2 = 0;
    D_80203FE0[25].unk4 = 0;
    if (D_803F2D10.unk0 == 0) {
        func_802DB9E8_6ED098(&D_803D552C->unk30C, (s16)(D_803D552C->unk306 * 15), 4);
    }
    func_802C7A7C_6D912C(&D_80203FE0[22], D_803D552C->unk30C);
    func_802C7A7C_6D912C(&D_80203FE0[23], D_803D552C->unk30C);
    func_802C7A7C_6D912C(&D_80203FE0[24], D_803D552C->unk30C);
    func_802C7A7C_6D912C(&D_80203FE0[25], D_803D552C->unk30C);

    D_80203FE0[22].unk4 += D_80203FE0[0].unk4;
    D_80203FE0[23].unk4 += D_80203FE0[0].unk4;
    D_80203FE0[24].unk4 += D_80203FE0[0].unk4;
    D_80203FE0[25].unk4 += D_80203FE0[0].unk4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6CA7E0/func_802BB70C_6CCDBC.s")
#endif
