#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032D680_73ED30.s")
// is this a loop? bunch of macros? what?
// void func_8032D680_73ED30(void) {
//     Mtx *temp_v0;
//     Mtx *temp_v0_2;
//
//     temp_v0_2 = &D_80204278->unk37490;
//
//     D_80204278->unk38A10[0][0] = (f32) ((temp_v0_2->m[0][0] & 0xFFFF0000      ) | ((temp_v0_2->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][0] = (f32) ((temp_v0_2->m[0][0]              << 16) |  (temp_v0_2->m[2][0] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A10[0][1] = (f32) ((temp_v0_2->m[0][2] & 0xFFFF0000      ) | ((temp_v0_2->m[2][2] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][1] = (f32) ((temp_v0_2->m[0][2]              << 16) |  (temp_v0_2->m[2][2] & 0xFFFF)           ) / 65536.0;
//
//     D_80204278->unk38A10[0][2] = (f32) ((temp_v0_2->m[1][0] & 0xFFFF0000      ) | ((temp_v0_2->m[3][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][2] = (f32) ((temp_v0_2->m[1][0]              << 16) |  (temp_v0_2->m[3][0] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A10[0][3] = (f32) ((temp_v0_2->m[1][2] & 0xFFFF0000      ) | ((temp_v0_2->m[3][2] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[1][3] = (f32) ((temp_v0_2->m[1][2]              << 16) |  (temp_v0_2->m[3][2] & 0xFFFF)           ) / 65536.0;
//
//     D_80204278->unk38A10[2][0] = (f32) ((temp_v0_2->m[0][1] & 0xFFFF0000      ) | ((temp_v0_2->m[2][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][1] = (f32) ((temp_v0_2->m[0][3] & 0xFFFF0000      ) | ((temp_v0_2->m[2][3] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][2] = (f32) ((temp_v0_2->m[1][1] & 0xFFFF0000      ) | ((temp_v0_2->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A10[2][3] = (f32) ((temp_v0_2->m[1][3] & 0xFFFF0000      ) | ((temp_v0_2->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;
//
//     temp_v0 = &D_80204278->unk37410;
//     D_80204278->unk38A40[0] = (f32) ((temp_v0->m[0][0] & 0xFFFF0000      ) | ((temp_v0->m[2][0] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A40[1] = (f32) ((temp_v0->m[0][2]              << 16) |  (temp_v0->m[2][2] & 0xFFFF)           ) / 65536.0;
//     D_80204278->unk38A40[2] = (f32) ((temp_v0->m[1][1] & 0xFFFF0000      ) | ((temp_v0->m[3][1] & 0xFFFF0000) >> 16)) / 65536.0;
//     D_80204278->unk38A40[3] = (f32) ((temp_v0->m[1][3] & 0xFFFF0000      ) | ((temp_v0->m[3][3] & 0xFFFF0000) >> 16)) / 65536.0;
//
//     D_80204278->unk38A40[0] *= -(D_80203FD0 * 2);
//     D_80204278->unk38A40[1] *= D_80203FD2 * 2;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032DACC_73F17C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032E150_73F800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032E9E4_740094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73ED30/func_8032F170_740820.s")

void func_8032F8C8_740F78(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    func_8029CEF0_6AE5A0(arg0 << 16, arg1 << 16, arg2 << 16, 512, arg3 + 3, &D_803D2E08, arg3 + 3, 0, 0, 0);
}
