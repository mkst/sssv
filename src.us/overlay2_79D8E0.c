#include <ultra64.h>
#include "common.h"


void func_8038C230_79D8E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    s16 phi_v1;

    if (D_803D5530->movementState == MOVEMENT_STATE_SINKING) {
        if (gUiFlowState.unk0 == 0) {
            if (D_803D5538 != 0) {
                phi_v1 = (gAnimalState.stickMag + (D_803D554B >> 2)) << (arg2 + 2);
            } else {
                phi_v1 = (D_803D552C->unk368 >> 2) << (arg2 + 2);
            }
            phi_v1 += (((SIN(D_803D5540 << arg3) >> 7) * (4 - gAnimalState.stickMag)) >> (8 - arg1));
            D_803D552C->unk35C += phi_v1;
            D_803D552C->unk35C -= D_803D552C->unk35A >> 4;
            D_803D552C->unk35C = ((D_803D552C->unk35C * 0xF) >> 4);
            D_803D552C->unk35A += D_803D552C->unk35C;
        }

        build_spring_bounce_matrix(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], arg0, (D_803D552C->unk35A * arg4) / 24.0);
        gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    }
}

// 'boing'? used by SPRINGY_THINGY/SPRINGY_RAM, FROG and POGO_KANGAROO
// e.g.
// func_8038C484_79DB34(2, 1, 3, -0.38f, 3000);  // SPRINGY_THINGY
// func_8038C484_79DB34(2, 1, 3, -0.18f, 0);     // POGO_KANGAROO
// func_8038C484_79DB34(2, 1, 3, -0.38f, -3000); // FROG
void func_8038C484_79DB34(s16 springyness, s16 shift, s16 rate, f32 multiplier, s16 defaultVelocity) {
    s16 phi_v1;

    if ((D_803D5530->movementState == MOVEMENT_STATE_GROUND) || (D_803D5530->movementState == MOVEMENT_STATE_FLYING)) {
        if ((D_803D552C->movementMode == MOVEMENT_MODE_NORMAL) || (D_803D552C->movementMode == MOVEMENT_MODE_INJURED) || (D_803D552C->movementMode == MOVEMENT_MODE_CRITICAL)) {
              if (gUiFlowState.unk0 == 0) {
                // dampen
                if (D_803D552C->unk35A < -2500) {
                    D_803D552C->unk35A = ((D_803D552C->unk35A + 2500) >> 2) - 2500;
                }
                if (D_803D552C->unk35A > 2500) {
                    D_803D552C->unk35A = ((D_803D552C->unk35A - 2500) >> 2) + 2500;
                }
                if (D_803D5538 != 0) {
                    phi_v1 = (gAnimalState.stickMag + (D_803D554B >> 2)) << (shift + 2);
                } else {
                    phi_v1 = (D_803D552C->unk368 >> 2) << (shift + 2);
                }
                phi_v1 += ((((SIN(D_803D5540 << rate) >> 7) * (4 - gAnimalState.stickMag)) >> (8 - springyness)));
                D_803D552C->unk35C += phi_v1;
                D_803D552C->unk35C -= D_803D552C->unk35A >> 4;
                D_803D552C->unk35C = (D_803D552C->unk35C * 0xF) >> 4;
                D_803D552C->unk35A += D_803D552C->unk35C;
              }
              build_spring_bounce_matrix(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs], 0, (D_803D552C->unk35A * multiplier) / 24.0);
              gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&gDisplayListContext->modelViewMtx[gDisplayListContext->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
              return;
        }
    }
    if ((D_803D5530->movementState != MOVEMENT_STATE_WATER_SWIM) && (D_803D5530->movementState != MOVEMENT_STATE_SINKING) && (D_803D5530->movementState != MOVEMENT_STATE_DRIFTING)) {
        D_803D552C->unk35A = defaultVelocity;
    }
}
