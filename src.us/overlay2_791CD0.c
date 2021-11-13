#include <ultra64.h>
#include "common.h"

void func_80380620_791CD0(Animal *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    arg0->unk34C = arg1;
    arg0->unk352 = arg2;
    arg0->unk356 = arg3;
    arg0->unk362 = arg4;
}

void func_80380644_791CF4(Animal *arg0) {
    arg0->unk34C = 0;
}

#ifdef NON_MATCHING
// score: 940, jumbled instructions
void func_8038064C_791CFC(void) {
    s32 temp_v0_2 = 0;
    s32 tmp;

    if (D_803F2D10.unk0 == 0) {
        D_803D552C->unk358 = MAX(0, D_803D552C->unk358 - 1);
        if (D_803D552C->unk358 <= 0) {
            D_803D552C->unk363 = 0;
        }
    }
    if (D_803D552C->unk363 != 0) {
        func_80380620_791CD0(D_803D552C, 150, 15, MIN(50, D_803D552C->unk358 >> 1), 10);
        if (!temp_v0_2) {} // regalloc helper
    }
    D_803F63E0 = 0;
    if ((D_803D552C->unk34C != 0) || (D_803D552C->unk34E != 0)) {
        if (D_803D552C->unk34E != 0) {
            D_803D552C->unk34E -= 1;
            tmp = D_80152C78[(((D_803D552C->unk34E << 8) / D_803D552C->unk354) + 64) & 0xFF];
            temp_v0_2 = (tmp >> 7);
            temp_v0_2 = (256 - temp_v0_2);
            temp_v0_2 = ((temp_v0_2 * D_803D552C->unk350) >> 9) + 256;
            D_803F2EB0 = (D_803F2EB0 * temp_v0_2) >> 8;
            D_803F2EB4 = (D_803F2EB4 * temp_v0_2) >> 8;
            D_803F2EB8 = (D_803F2EB8 * temp_v0_2) >> 8;

            tmp = D_80152C78[(u16)((D_803D552C->unk34E << 8) / D_803D552C->unk354) & 0xFF];
            D_803F63E0 = ((tmp >> 7) * D_803D552C->unk350) >> 8;
        } else {
            D_803D552C->unk354 = (((((64 - (func_8012826C() & 0x7F)) * D_803D552C->unk362) >> 6) + 64) * D_803D552C->unk352) >> 6;
            D_803D552C->unk34E = D_803D552C->unk354;
            D_803D552C->unk350 = (((((64 - (func_8012826C() & 0x7F)) * D_803D552C->unk362) >> 6) + 64) * D_803D552C->unk356) >> 6;
        }
        if (D_803D552C->unk34C > 0) {
            D_803D552C->unk34C -= 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_791CD0/func_8038064C_791CFC.s")
#endif
