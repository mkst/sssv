#include <ultra64.h>
#include "common.h"

#ifdef NON_MATCHING
// standard regalloc bollocks
// only cool_cod + pirana
void func_80302E50_714500(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_lo;
    s16 temp_a3;
    s16 phi_t3;
    s16 phi_t2;
    s16 phi_t4;

    u16 tmp1;
    u16 tmp2;
    s32 new_var;

    temp_a3 = D_803D552C->unk310;
    tmp1 = D_80203FE0[2].unk0 - (((D_80152C78[phi_t4 & 0xFF] >> 7) * arg2) >> 8);
    D_803D552C->unk310 = (D_803D552C->unk310 + D_803D552C->unk30C) & 0x3FF;

    if (D_803D552C->unk30E != 0) {
        if ((D_803D5538 != 0) && (D_803D552C->unk310 < temp_a3)) {
            play_sound_effect_at_location(SFX_UNKNOWN_9, D_803D552C->unk30E << 0xA, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        } else if ((D_803D5538 != 0) && (D_803D552C->unk310 > 0x200) && (temp_a3 <= 0x200)) {
            play_sound_effect_at_location(SFX_UNKNOWN_10, D_803D552C->unk30E << 0xA, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
        }
        new_var = (D_803D552C->unk310 >> 2);
        temp_lo = (D_80152C78[new_var & 0xFF]) >> 7;
        phi_t2 = (temp_lo * D_803D552C->unk30E) >> 9;
        phi_t3 = (temp_lo * D_803D552C->unk30E) >> 10;
        phi_t4 = (-(temp_lo * D_803D552C->unk30E)) >> 7;
    } else {
        phi_t4 = phi_t2 = phi_t3 = 0;
    }

    new_var = D_80152C78[phi_t3 & 0xFF];
    D_80203FE0[1].unk0 = ((new_var >> 7) * arg1) >> 9;
    D_80203FE0[1].unk2 = ((D_80152C78[(phi_t3 + 0x40) & 0xFF] >> 7) * arg1) >> 9;
    D_80203FE0[1].unk4 = 0;

    D_80203FE0[2].unk0 = -D_80203FE0[1].unk0;
    D_80203FE0[2].unk2 = -D_80203FE0[1].unk2;
    D_80203FE0[2].unk4 = 0;

    D_80203FE0[0].unk0 = (u16)(D_80203FE0[1].unk0 + (((D_80152C78[phi_t2 & 0xFF] >> 7) * arg0) >> 8));
    // D_80203FE0[0].unk2 = (u16)(D_80203FE0[1].unk2 + (((D_80152C78[(phi_t2 + 0x40) & 0xFF] >> 7) * arg0) >> 8));
    tmp1 = D_80203FE0[1].unk2 + (((D_80152C78[(phi_t2 + 0x40) & 0xFF] >> 7) * arg0) >> 8);
    D_80203FE0[0].unk2 = tmp1;
    D_80203FE0[0].unk4 = 0;

    tmp1 = D_80203FE0[2].unk0 - (((D_80152C78[phi_t4 & 0xFF] >> 7) * arg2) >> 8);
    D_80203FE0[3].unk0 = tmp1;
    tmp2 = D_80203FE0[2].unk2 - (((D_80152C78[(phi_t4 + 0x40) & 0xFF] >> 7) * arg2) >> 8);
    D_80203FE0[3].unk2 = tmp2;
    D_80203FE0[3].unk4 = 0;

    func_802C79E0_6D9090(&D_80203FE0[0], -D_803D5530->unk28 >> 1);
    func_802C79E0_6D9090(&D_80203FE0[1], -D_803D5530->unk28 >> 1);
    func_802C79E0_6D9090(&D_80203FE0[2], -D_803D5530->unk28 >> 1);
    func_802C79E0_6D9090(&D_80203FE0[3], -D_803D5530->unk28 >> 1);

    D_80203FE0[0].unk4 += (D_803D5524->unkB8 << 5);
    D_80203FE0[1].unk4 += (D_803D5524->unkB8 << 5);
    D_80203FE0[2].unk4 += (D_803D5524->unkB8 << 5);
    D_80203FE0[3].unk4 += (D_803D5524->unkB8 << 5);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_714500/func_80302E50_714500.s")
#endif

// only cool_cod + pirana
void func_8030322C_7148DC(s16 idx, s16 angle) {
    s16 temp_v1;
    s32 temp_t2;
    s32 temp_t6;
    struct061 *temp_v0;
    s32 fakematch;

    temp_v0 = &D_80203FE0[idx];
    // sameline for regalloc
    temp_v1 = temp_v0->unk4; temp_t6 = D_80152C78[angle & 0xFF] >> 7;
    temp_t2 = D_80152C78[(angle + 0x40) & 0xFF] >> 7;

    temp_v0->unk2 = ((temp_v1 * (fakematch = temp_t6)) + (temp_v0->unk2 * temp_t2)) >> 8;
    temp_v0->unk4 = ((temp_t2 * temp_v1) - (temp_t6 * temp_v0->unk2)) >> 8;
}


void func_803032DC_71498C(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;
    s16 temp_t1;
    s32 temp_t8;
    s32 temp_t9;
    s32 tmp;

    temp_v0 = D_80203FE0[arg0].unk2 - D_80203FE0[arg1].unk2;
    temp_t1 = D_80203FE0[arg0].unk4 - D_80203FE0[arg1].unk4;

    temp_t8 = D_80152C78[arg2 & 0xFF] >> 7;
    temp_t9 = D_80152C78[(arg2 + 64) & 0xFF] >> 7;
    // fake match to coerce regalloc
    D_80203FE0[arg0].unk2 = D_80203FE0[arg1].unk2 + (((temp_t1 * (temp_t8 = temp_t8)) + (temp_v0 * temp_t9)) >> 8);
    D_80203FE0[arg0].unk4 = D_80203FE0[arg1].unk4 + ((tmp=(temp_t1 * temp_t9) - (temp_t8 * temp_v0)) >> 8);
}

void func_803033D4_714A84(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_t1;
    s16 temp_v0;
    s32 temp_t8;
    s32 temp_t9;
    s32 tmp;

    temp_v0 = D_80203FE0[arg0].unk0 - D_80203FE0[arg1].unk0;
    temp_t1 = D_80203FE0[arg0].unk2 - D_80203FE0[arg1].unk2;
    temp_t8 = D_80152C78[arg2 & 0xFF] >> 7;
    temp_t9 = D_80152C78[(arg2 + 64) & 0xFF] >> 7;
    // fake match to coerce regalloc
    D_80203FE0[arg0].unk0 = D_80203FE0[arg1].unk0 + (((temp_t1 * (temp_t8 = temp_t8)) + (temp_v0 * temp_t9)) >> 8);
    D_80203FE0[arg0].unk2 = D_80203FE0[arg1].unk2 + ((tmp = (temp_t1 * temp_t9) - (temp_t8 * temp_v0)) >> 8);

}
