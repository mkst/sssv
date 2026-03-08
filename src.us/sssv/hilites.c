#include <ultra64.h>
#include "common.h"

void add_hilite(void) {
    Mtx m;

    if (gDisplayListContext->usedHilites < 100) {
        guLookAtHilite(&m,
            &gDisplayListContext->lookAts[gDisplayListContext->usedHilites],
            &gDisplayListContext->hilites[gDisplayListContext->usedHilites],
            gCameraEyeWorldX,
            gCameraEyeWorldZ,
            gCameraEyeWorldY,
            ((f32)D_803D5530->position.xPos.w / 65536.0),
            ((f32)D_803D5530->position.zPos.w / 65536.0),
            ((f32)D_803D5530->position.yPos.w / 65536.0),
            D_80204200,
            D_80204204,
            D_80204208,
            -60.0f, 0.0f, 60.0f,
            -60.0f, 0.0f, 60.0f,
            32, 32);

        gSPLookAtX(gOpaqueDL++, (s32)&gDisplayListContext->lookAts[gDisplayListContext->usedHilites] & 0x1FFFFFFF);
        gSPLookAtY(gOpaqueDL++, ((s32)&gDisplayListContext->lookAts[gDisplayListContext->usedHilites] & 0x1FFFFFFF) + 16);
        gDPSetTileSize(gOpaqueDL++, G_TX_RENDERTILE,
            (gDisplayListContext->hilites[gDisplayListContext->usedHilites].h.x1 & 0xfff),
            (gDisplayListContext->hilites[gDisplayListContext->usedHilites].h.y1 & 0xfff),
            (gDisplayListContext->hilites[gDisplayListContext->usedHilites].h.x1 + 124) & 0xfff,
            (gDisplayListContext->hilites[gDisplayListContext->usedHilites].h.y1 + 124) & 0xfff
            );

        gDisplayListContext->usedHilites += 1;
    } else {
        osSyncPrintf("Sorry, no more space for extra hilites.\n");
    }
}
