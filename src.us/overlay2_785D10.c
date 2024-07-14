#include <ultra64.h>
#include "common.h"

#include "camera.h"

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss (D_803F2F00 to D_803F33D0)
// ========================================================

s16  D_803F2F00;
struct060 D_803F2F08[64];

static s16  D_803F3308;
static s16  D_803F330A;
static s16  D_803F330C;
static s16  D_803F330E;

// ========================================================
// .text
// ========================================================


void func_80374660_785D10(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_ret;

    if (((D_803D5530->unk162 & 0xF) == 1) && (D_803D5530->unk161 != 1)) {
        temp_t2 = (D_803D552C->position.xPos.w + (arg0 * COS(D_803D552C->heading) * 2)) + (SIN(D_803D552C->heading) * arg1 * 2);
        temp_t3 = (D_803D552C->position.zPos.w + (arg1 * COS(D_803D552C->heading) * 2)) - (SIN(D_803D552C->heading) * arg0 * 2);
        temp_ret = func_80310EE4_722594((temp_t2 >> 16), (temp_t3 >> 16), D_803D5530->unk160);
        D_803F2F08[D_803B4F30_7C65E0].unk0 = temp_t2;
        D_803F2F08[D_803B4F30_7C65E0].unk4 = temp_t3;
        D_803F2F08[D_803B4F30_7C65E0].unk8 = temp_ret + FTOFIX32(4.0);
        D_803F2F08[D_803B4F30_7C65E0].unkC = arg2;
        D_803F2F08[D_803B4F30_7C65E0].unkE =  D_803D5544;
        D_803B4F30_7C65E0 = (D_803B4F30_7C65E0 + 1) & 0x3F;
        if (D_803B4F34_7C65E4 < 64) {
            D_803B4F34_7C65E4 += 1;
        }
    }
}

void func_803747CC_785E7C(void) {
    D_803B4F34_7C65E4 = 0;
    D_803B4F30_7C65E0 = D_803B4F34_7C65E4;
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
            D_01037A20_712F0,
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
    if (D_803B4F34_7C65E4 > 0) {
        gDPSetTextureImage(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_01037750_71020);
        gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPLoadSync(D_801D9E90++);
        gDPLoadBlock(D_801D9E90++, G_TX_LOADTILE, 0, 0, 255, 1024);
        gDPPipeSync(D_801D9E90++);
        gDPSetTile(D_801D9E90++, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
        gDPSetTileSize(D_801D9E90++, G_TX_RENDERTILE, 0, 0, 4*(31), 4*(31));
        gSPDisplayList(D_801D9E90++, D_01003A58_3D328);

        // could this be replaced with a for loop?
        phi_s2 = (D_803B4F30_7C65E0 - D_803B4F34_7C65E4) & 0x3F;
        phi_s3 = D_803B4F34_7C65E4;

        while (phi_s3 > 0) {
            temp_t5 = (D_803D5544 - D_803F2F08[phi_s2].unkE);
            if (temp_t5 > 400) {
                if (D_803F2D50.segment == SEGMENT_ICE) {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 100, 500 - temp_t5);
                } else {
                    gDPSetEnvColor(D_801D9E90++, 0, 0, 0, 500 - temp_t5);
                }
                if (temp_t5 >= 500) {
                    D_803B4F34_7C65E4 -= 1;
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
