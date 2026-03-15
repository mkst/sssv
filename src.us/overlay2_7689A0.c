#include <ultra64.h>
#include "common.h"


// ========================================================
// .bss (D_803F2D30 to D_803F2D50)
// ========================================================

GameState gGameState;

// ========================================================
// .text
// ========================================================

// ESA: func_80058368
void func_803572F0_7689A0(void) {
    if (gUiFlowState.unk0 == 0) {
        if ((gAnimalState.animals[gCurrentAnimalIndex].animal->health <= 0) &&
            (gGameState.unk4 == 0) && (D_803F2D50.unkC6 == 0)) {
            gGameState.unk4 = 1;
            gCurrentMusicTrack = MUSIC_TRACK_LEVEL_FAILED;
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 2048;
        }
        if (gGameState.unk4 != 0) {
            gGameState.unk4++;
        }
    }
}

// ESA: func_80058404
// set_level_passed_music
void func_8035739C_768A4C(void) {
    D_803F2D50.unkC6 = 1;
    D_8015517C = 1.0f;
    D_801546E0 = 2048;
    D_801546D8 = 2048;

    if ((gGameState.level == GIVE_A_DOG_A_BONUS) ||
        (gGameState.level == WALRACE_64) ||
        (gGameState.level == EVOS_ESCAPE) ||
        (gGameState.level == PUNCHUP_PYRAMID)) {
        if (gLevelProgress & LEVEL_PROGRESS_COMPLETED) {
            gCurrentMusicTrack = MUSIC_TRACK_LEVEL_PASSED;
        } else {
            gCurrentMusicTrack = MUSIC_TRACK_BOSS_LEVEL_PASSED;
        }
    } else {
        gCurrentMusicTrack = MUSIC_TRACK_LEVEL_PASSED;
    }
}

// ESA: func_80058414
void func_80357438_768AE8(void) {
    if (D_803F2D50.unkC6 != 0) {
        D_803F2D50.unkC6 += 1;
        if (D_803F2D50.unkC6 == 200) {
            func_8038FAB4_7A1164();
        }
    }
}

// ESA: func_80058454
void func_80357480_768B30(void) {
    if (gGameState.unk4 == 160) {
        trigger_level_failed();
    }
    if (gGameState.unk4 == 122) {
        start_sfx_volume_fade(30.0f, 20.0f, 0);
    }
}
