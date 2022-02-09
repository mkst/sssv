#include <ultra64.h>
#include "common.h"


#ifdef NON_MATCHING
void func_80357200_7688B0(void) {
    Animal *a;
    if (D_8028645C <= 100) {
        if ((D_8028645C != 9) && (D_8028645C != 5) && (D_8028645C != 24)) {
            D_8028645C = D_803F2D23;
        } else {
            D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
            D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;


            D_803D5528 = (&D_801D9ED8.animals[gCurrentAnimalIndex])->animal;
            D_803D552C = (&D_801D9ED8.animals[gCurrentAnimalIndex])->animal;
            D_803D5530 = (&D_801D9ED8.animals[gCurrentAnimalIndex])->animal;

            if (0) {}; if (a = D_803D5528 == NULL) {} // helps regalloc

            D_803D5538 = 1;
            D_803D553C = gCurrentAnimalIndex;
            D_803D553A = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7688B0/func_80357200_7688B0.s")
#endif

void func_803572B0_768960(s8 arg0) {
    D_803F2D23 = arg0;
}

s32 func_803572C0_768970(void) {
    D_803F2D20 = 0;
    D_803F2D22 = 1;
    D_803F2D23 = 1;
    D_8028645C = 1;
    return 1;
}
