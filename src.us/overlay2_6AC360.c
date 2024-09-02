#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

struct063 D_803C0740[65+8][97+32]; // data is [65][97]

// ========================================================
// .text
// ========================================================

void func_8029ACB0_6AC360(void) {
}

// esa: func_8001B1CC ?
s32 func_8029ACB8_6AC368(s32 arg0, s32 arg1) {
    return 1;
}

// process_level_collision_data
void func_8029ACC8_6AC378(void) {
    s32 i, j;
    s32 idx;
    struct063 *src;

    for (i = 0; i < 65; i++) {
        for (j = 0; j < 97; j++) {
            idx = (i * 97) + (j * 1);
            src = (struct063 *)&D_80100000[idx*2];
            D_803C0740[i + 4][j + 8] = *src;
        }
    }

    for (i = 0; i < 72; i++) {
        for (j = 0; j < 128; j++) {
            D_803C0740[i][j].unk6 *= 2;
        }
    }

    for (j = 0; j < 128; j++) {
        D_803C0740[0][j].unk0 = 0xFF;
        D_803C0740[1][j].unk0 = 0xFF;
        D_803C0740[2][j].unk0 = 0xFF;
        D_803C0740[3][j].unk0 = 0xFF;

        D_803C0740[69][j].unk0 = 0xFF;
        D_803C0740[70][j].unk0 = 0xFF;
        D_803C0740[71][j].unk0 = 0xFF;
        D_803C0740[72][j].unk0 = 0xFF;
    }

    D_803E1D30[240].unk1 = 0xFF;
    D_803E1D30[240].unk2 = 0xFF;

    D_803E1D30[241].unk1 = 0xFF;
    D_803E1D30[241].unk2 = 0;

    D_803E1D30[242].unk1 = 0xFF;
    D_803E1D30[242].unk2 = 0xFF;

    for (i = 0; i < 72; i++) {
        D_803C0740[i][8].unk1 = 0x80;

        D_803C0740[i][7].unk3 = 0xF0;
        D_803C0740[i][7].unk5 |= 0x88;

        D_803C0740[i][104].unk1 = 0x80;
        D_803C0740[i][104].unk3 = 0xF0;
        D_803C0740[i][104].unk5 |= 0x44;
    }
}
