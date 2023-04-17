#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F2F00 to D_803F33D0)
// ========================================================

s16  D_803F2F00;
struct060 D_803F2F08[64];

s16  D_803F3308;
s16  D_803F330A;
s16  D_803F330C;
s16  D_803F330E;
s16  D_803F3310;

u8   D_803F3312[0x18]; // padding

// FIXME: I don't think these are really declared here
s16  D_803F3330[200];
s16  D_803F34C0[0x1780];
s16  D_803F63C0;
u8   D_803F63C2;

// ========================================================
// .text
// ========================================================


void func_80374660_785D10(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_ret;

    if (((D_803D5530->unk162 & 0xF) == 1) && (D_803D5530->unk161 != 1)) {
        temp_t2 = (D_803D552C->xPos.w + (arg0 * D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * 2)) + (D_80152C78[D_803D552C->unk302 & 0xFF] * arg1 * 2);
        temp_t3 = (D_803D552C->zPos.w + (arg1 * D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] * 2)) - (D_80152C78[D_803D552C->unk302 & 0xFF] * arg0 * 2);
        temp_ret = func_80310EE4_722594((temp_t2 >> 16), (temp_t3 >> 16), D_803D5530->unk160);
        D_803F2F08[D_803B4F30].unk0 = temp_t2;
        D_803F2F08[D_803B4F30].unk4 = temp_t3;
        D_803F2F08[D_803B4F30].unk8 = temp_ret + FTOFIX32(4.0);
        D_803F2F08[D_803B4F30].unkC = arg2;
        D_803F2F08[D_803B4F30].unkE =  D_803D5544;
        D_803B4F30 = (D_803B4F30 + 1) & 0x3F;
        if (D_803B4F34 < 64) {
            D_803B4F34 += 1;
        }
    }
}

void func_803747CC_785E7C(void) {
    D_803B4F34 = 0;
    D_803B4F30 = D_803B4F34;
    D_803F330E = -1;
}

void func_803747F4_785EA4(void) {
    u16 temp_t5;
    s16 phi_s2;
    s16 phi_s3;

    if (D_803F330E >= 0) {
        func_8034C8F8_75DFA8(
            D_803F3308,
            D_803F330A,
            D_803F330C + 0xA,
            0,
            D_01037A20,
            D_803F330E * 30,
            D_803F330E * 30,
            ((12 - D_803F330E) * 0x9B) / 12,
            0xFF,
            0xFF,
            0xFF,
            0,
            0);

        if (++D_803F330E > 12) {
            D_803F330E = -1;
        }
    }
    if (D_803B4F34 > 0) {
        gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01037750_71020);
        gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPLoadSync(D_801D9E90++);
        gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 255, 1024);
        gDPPipeSync(D_801D9E90++);
        gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
        gSPDisplayList(D_801D9E90++, D_01003A58);

        // could this be replaced with a for loop?
        phi_s2 = (D_803B4F30 - D_803B4F34) & 0x3F;
        phi_s3 = D_803B4F34;

        while (phi_s3 > 0) {
            temp_t5 = (D_803D5544 - D_803F2F08[phi_s2].unkE);
            if (temp_t5 > 400) {
                if (D_803F2D50.segment == SEGMENT_ICE) {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 100, 500 - temp_t5);
                } else {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 0, 500 - temp_t5);
                }
                if (temp_t5 >= 500) {
                    D_803B4F34 -= 1;
                }
            } else {
                if (D_803F2D50.segment == SEGMENT_ICE) {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 65, 100);
                } else {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 0, 100);
                }
            }
            func_8032E9E4_740094(&D_801D9E90, D_803F2F08[phi_s2].unk0, D_803F2F08[phi_s2].unk4, D_803F2F08[phi_s2].unk8, 0x20, 0x20, D_803F2F08[phi_s2].unkC, (s32) (D_803F2F08[phi_s2].unkC * D_803A6CC0_7B8370) >> 8);
            phi_s3--;
            phi_s2 = ((phi_s2 + 1) & 0x3F);
        }
        gSPTexture(D_801D9E90++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPSetDepthSource(D_801D9E90++, G_ZS_PIXEL);
        gDPSetTexturePersp(D_801D9E90++, G_TP_PERSP);
    }
}

void func_80374C38_7862E8(s16 arg0, s16 arg1, s16 arg2) {
    D_803F3308 = arg0;
    D_803F330A = arg1;
    D_803F330C = arg2;
    D_803F330E = 2;
}
