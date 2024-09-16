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

// unused. fakematch nonsense.
void func_8012C190(struct014 *arg0, u16 arg1, s16 arg2, s16 arg3) {
    u8 i;
    int new_var2;
    struct014_inner *new_var;

    for (i = 0; i < arg0->unk4; i++) {
        s32 tmp = arg1;
        new_var = &arg0->unk0[i];

        if (arg1 < (*new_var).unk8) {

        } else {
            new_var2 = (*new_var).unk8;
            new_var2 = new_var2 && arg0;
        }
    }
}
