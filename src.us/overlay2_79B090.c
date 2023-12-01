#include <ultra64.h>
#include "common.h"


void func_803899E0_79B090(Animal *arg0) {
    s32 phi_v0;

    if (arg0->unk6C == NULL) {
        if (arg0->unk160 == 2) {
            phi_v0 = D_803E1D30[D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk3].unkB;
        } else {
            phi_v0 = D_803E1D30[D_803C0740[arg0->position.xPos.h >> 6][arg0->position.zPos.h >> 6].unk2].unkB;
        }
        if (phi_v0 != arg0->unk4C.unk10) {
            if (phi_v0 < arg0->unk4C.unk10) {
                if ((ABS(arg0->xVelocity.w) > 32768) || (ABS(arg0->zVelocity.w) > 32768) || (ABS(arg0->yVelocity.w) > 327680)) {
                    arg0->unk4C.unk10 -= 1;
                }
            } else {
                arg0->unk4C.unk10 += 1;
            }
        }
    }
}
