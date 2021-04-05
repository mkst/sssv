#include <ultra64.h>
#include "common.h"


void func_803572F0_7689A0(void) {
    if (D_803F2D10.unk0 == 0) {
        if ((D_801DDD8C[gCurrentAnimalIndex].unk0->health <= 0) &&
            (D_803F2D30.unk4 == 0) && (D_803F2E16 == 0)) {
            D_803F2D30.unk4 = 1;
            D_8028645C = 9;
            D_8015517C = 1.0f;
            D_801546E0 = 2048;
            D_801546D8 = 2048;
        }
        if (D_803F2D30.unk4 != 0) {
            D_803F2D30.unk4 += 1;
        }
    }
}

void func_8035739C_768A4C(void) {
    D_803F2E16 = 1;
    D_8015517C = 1.0f;
    D_801546E0 = 2048;
    D_801546D8 = 2048;

    if ((gLevelIndex == GIVE_A_DOG_A_BONUS) ||
        (gLevelIndex == WALRACE_64) ||
        (gLevelIndex == EVOS_ESCAPE) ||
        (gLevelIndex == PUNCHUP_PYRAMID)) {
        if ((D_803E4D28 & 2) != 0) {
            D_8028645C = 5;
        } else {
            D_8028645C = 24;
        }
    } else {
        D_8028645C = 5;
    }
}

void func_80357438_768AE8(void) {
    if (D_803F2D50.unkC6 != 0) {
        D_803F2D50.unkC6 += 1;
        if (D_803F2D50.unkC6 == 200) {
            func_8038FAB4_7A1164();
        }
    }
}

void func_80357480_768B30(void) {
    if (D_803F2D34 == 160) {
        func_8038FA00_7A10B0();
    }
    if (D_803F2D34 == 122) {
        func_8013385C(30.0f, 20.0f, 0);
    }
}
