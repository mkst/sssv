#include <ultra64.h>
#include "common.h"


// ========================================================
// .bss (D_803F2D20 to D_803F2D50)
// ========================================================
u16  D_803F2D20;
s8   D_803F2D22;
s8   D_803F2D23;
s16  D_803F2D24;
s32  D_803F2D28;
s32  D_803F2D2C;

// bss split?
struct001 D_803F2D30;

// ========================================================
// .text
// ========================================================

void func_80357200_7688B0(void) {
    if (D_8028645C <= 100) {
        if ((D_8028645C != MUSIC_TRACK_LEVEL_FAILED) && (D_8028645C != MUSIC_TRACK_LEVEL_PASSED) && (D_8028645C != MUSIC_TRACK_BOSS_LEVEL_PASSED)) {
            D_8028645C = D_803F2D23;
        } else {
            Animal *a;
            D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
            D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

            D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
            a = D_803D5528;
            D_803D552C = a;
            D_803D5530 = a;

            D_803D5538 = 1;
            D_803D553C = gCurrentAnimalIndex;
            D_803D553A = 0;
        }
    }
}

void set_music_track(s8 arg0) {
    D_803F2D23 = arg0;
}

s32 func_803572C0_768970(void) {
    D_803F2D20 = 0;
    D_803F2D22 = 1;
    D_803F2D23 = MUSIC_TRACK_1;
    D_8028645C = MUSIC_TRACK_1;
    return 1;
}
