#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7C80_6D9330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7F88_6D9638.s")

void func_802C83CC_6D9A7C(Animal *arg0) {
    if (arg0->unk320 != 0) {
        func_802B34B8_6C4B68(arg0->unk320);
    }
    if (arg0->unk3CA != 0) {
        func_802E4EB4_6F6564(arg0->unk3CA);
        arg0->unk3CA = 0;
    }
    func_802DAD18_6EC3C8(arg0);
    arg0->unk366 = 6;
}
