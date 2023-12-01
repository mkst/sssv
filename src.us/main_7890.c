#include <ultra64.h>
#include "common.h"

typedef struct {
    u8  pad0[0x8];
    u16 unk8;
    u8  padA[0x2];
} struct014_inner; // size 0xC

typedef struct {
    struct014_inner *unk0;
    u8  unk4;
} struct014;


#ifdef NON_MATCHING
void func_8012C190(struct014 *arg0, u16 arg1, s16 arg2, s16 arg3) {
    u8 i;

    for (i = 0; i < arg0->unk4; i++) {
        // (arg0->unk0 + (i * 0xC))->unk8
        if (arg1 >= arg0->unk0[i].unk8) {
            if (arg0 && arg0 && arg0) {}
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main_7890/func_8012C190.s")
#endif
