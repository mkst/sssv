#include <ultra64.h>
#include "common.h"

u8 bss_padding_chameleon_pre[0x220];

extern u8 D_04009BF0_FAC50[]; // palette

#pragma GLOBAL_ASM("asm/nonmatchings/sssv/animals/chameleon/func_8035A5F0_76BCA0.s")


void func_8035BDC0_76D470(void) {
    static u16 D_803F2EA0; // .bss
    u16 *palette;
    s16 temp_t7;
    s16 temp_t8;
    s16 i;

    if (D_803F2EA0 != D_803D5544) {
        D_803F2EA0 = D_803D5544;

        palette = (u16*)(D_801D9EC4 + SEGMENT_OFFSET(D_04009BF0_FAC50));

        temp_t7 = ((D_80152C78[D_803D5540 & 0xFF] >> 7) + 0x100) >> 1;
        temp_t8 = ((D_80152C78[((s16)(((D_803D5544 & 0xFFF) * 7) >> 3) + 0x40) & 0xFF] >> 7) + 0x100) >> 1;

        for (i = 0; i < 7; i++) {
            // rgba16
            palette[i+1] = ((s16)(((i * 7) * temp_t7) / 1536) << 11) | ((s16)((((i * 18) * temp_t7) / 1536) + 13) << 6) | ((s16)(((i * 7) * temp_t7) / 1536) << 1) | 1;
            palette[i+8] = ((s16)(((i * 7) * temp_t8) / 1536) << 11) | ((s16)((((i * 18) * temp_t8) / 1536) + 13) << 6) | ((s16)(((i * 7) * temp_t8) / 1536) << 1) | 1;
        }
    }
}

void func_8035C018_76D6C8(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CHAMELEON_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_8035C08C_76D73C(void) {
    if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) &&
        (D_803D552C->unk365 != ATTACK_CHAMELEON_2)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CHAMELEON_1;
    }
}

void func_8035C0CC_76D77C(void) {
    if ((D_803D552C->unk365 != ATTACK_CHAMELEON_1) && (D_803D552C->unk365 != ATTACK_CHAMELEON_2)) {
        D_803D552C->unk32A = D_803D5544;
        D_803D552C->unk365 = ATTACK_CHAMELEON_2;
    }
}

void func_8035C10C_76D7BC(void) {
    D_803D552C->unk32A = D_803D5544;
    D_803D552C->unk365 = ATTACK_CHAMELEON_TONGUE;
    play_sound_effect_at_location(SFX_RAM_HEADBUTT, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
}

void func_8035C180_76D830(s16 arg0) {
    D_803D552C->unk2EC = arg0;
}

u8 bss_padding_chameleon_post[0x28930];
