#include <ultra64.h>
#include "common.h"


void func_802F2B20_7041D0(void) {
    s16 i;
    for (i = 0; i < 5; i++) {
        D_803E1B20[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F2B54_704204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F2DF8_7044A8.s")
// urgh
// void func_802F2DF8_7044A8(void) {
//     D_803A52A0_7B6950 = D_803E1B8A = 80;
//     D_803A52A4_7B6954 = D_803E1B8C = 80;
//     D_803A52A8_7B6958 = D_803E1B8E = 80;
//     D_803A52AC_7B695C = D_803E1B90 = 200;
//     D_803A52B0_7B6960 = D_803E1B92 = 200;
//     D_803A52B4_7B6964 = D_803E1B94 = 200;
//     D_803E1B99 = 0;
//     D_803E1B9A = 0;
//     D_803E1B9B = 0;
//     D_803E1B96 = 0;
//     D_803E1B97 = 0;
//     D_803E1B98 = 0;
//     D_803E1BA4 = 0;
//     D_803E1BA2 = 0;
//     D_803E1BA6 = 0;
//     D_803A52B8_7B6968 = 1;
// }

void func_802F2EEC_70459C(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6) {
    D_803E1B99 = D_803A52A0_7B6950;
    D_803E1B9A = D_803A52A4_7B6954;
    D_803E1B9B = D_803A52A8_7B6958;
    D_803E1B96 = D_803A52AC_7B695C;
    D_803E1B97 = D_803A52B0_7B6960;
    D_803E1B98 = D_803A52B4_7B6964;
    D_803E1B8A = (s16)arg0 - D_803E1B99; // these casts are required
    D_803E1B8C = (s16)arg1 - D_803E1B9A; // these casts are required
    D_803E1B8E = (s16)arg2 - D_803E1B9B; // these casts are required
    D_803E1B90 = (s16)arg3 - D_803E1B96;
    D_803E1B92 = (s16)arg4 - D_803E1B97;
    D_803E1B94 = (s16)arg5 - D_803E1B98;
    D_803E1BA2 = arg6;
    D_803E1BA4 = 0;
    D_803A52B8_7B6968 = 0;
}

void func_802F301C_7046CC(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7) {
    D_803E1BAE = arg0;
    D_803E1BB0 = arg1;
    D_803E1BB2 = arg2;
    D_803E1BB4 = arg3;
    D_803E1BB6 = arg4;
    D_803E1BB8 = arg5;
    D_803E1BA6 = 1;
    D_803E1BA8 = 0;
    D_803E1BAA = arg6;
    D_803E1BAC = arg7;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F30A4_704754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7041D0/func_802F5088_706738.s")

// ambient light?
void func_802F5964_707014(Gfx* *arg0) {
    gSPNumLights((*arg0)++, 1);
    gSPLight((*arg0)++, &D_80204278->unk3B640, 1);
    gSPLight((*arg0)++, &D_80204278->unk3B638, 2);
}
