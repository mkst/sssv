#include <ultra64.h>
#include "common.h"


// ========================================================
// .bss (D_803F2D20 to D_803F2D30)
// ========================================================

static u16  D_803F2D20;        // effectively unused
static s8   D_803F2D22;        // effectively unused
static s8   targetMusicTrack;
s16  D_803F2D24;        // set in func_8029F7D4_6B0E84 but effectively unused

// ========================================================
// .text
// ========================================================

void func_80357200_7688B0(void) {
    if (gCurrentMusicTrack <= 100) {
        if ((gCurrentMusicTrack != MUSIC_TRACK_LEVEL_FAILED) && (gCurrentMusicTrack != MUSIC_TRACK_LEVEL_PASSED) && (gCurrentMusicTrack != MUSIC_TRACK_BOSS_LEVEL_PASSED)) {
            gCurrentMusicTrack = targetMusicTrack;
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
    targetMusicTrack = arg0;
}

s32 func_803572C0_768970(void) {
    D_803F2D20 = 0;
    D_803F2D22 = 1;
    targetMusicTrack = MUSIC_TRACK_1;
    gCurrentMusicTrack = MUSIC_TRACK_1;
    return 1;
}
