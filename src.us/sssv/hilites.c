#include <ultra64.h>
#include "common.h"

void func_8034A320_75B9D0(void) {
    Mtx m;

    if (D_80204278->usedHilites < 100) {
        guLookAtHilite(&m,
            &D_80204278->lookAts[D_80204278->usedHilites],
            &D_80204278->hilites[D_80204278->usedHilites],
            D_803F2C44,
            D_803F2C48,
            D_803F2C4C,
            ((f32)*(s32*)&D_803D5530->xPos / 65536.0),
            ((f32)*(s32*)&D_803D5530->zPos / 65536.0),
            ((f32)*(s32*)&D_803D5530->yPos / 65536.0),
            D_80204200,
            D_80204204,
            D_80204208,
            -60.0f, 0.0f, 60.0f,
            -60.0f, 0.0f, 60.0f,
            32, 32);

        gSPLookAtX(D_801D9E88++, (s32)&D_80204278->lookAts[D_80204278->usedHilites] & 0x1FFFFFFF);
        gSPLookAtY(D_801D9E88++, ((s32)&D_80204278->lookAts[D_80204278->usedHilites] & 0x1FFFFFFF) + 16);
        gDPSetTileSize(D_801D9E88++, G_TX_RENDERTILE,
            (D_80204278->hilites[D_80204278->usedHilites].h.x1 & 0xfff),
            (D_80204278->hilites[D_80204278->usedHilites].h.y1 & 0xfff),
            (D_80204278->hilites[D_80204278->usedHilites].h.x1 + 124) & 0xfff,
            (D_80204278->hilites[D_80204278->usedHilites].h.y1 + 124) & 0xfff
            );

        D_80204278->usedHilites += 1;
    } else {
        rmonPrintf("Sorry, no more space for extra hilites.\n");
    }
}
