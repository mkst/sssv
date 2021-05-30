#include <ultra64.h>
#include "common.h"


void func_802F07D0_701E80(void) {
    D_803E1B10[0] = 0;
    D_803E1B10[1] = 0;
    D_803E1B10[4] = 0;
}

void func_802F07E8_701E98(s16 arg0) {
    if ((arg0 == 23) || (arg0 == 24)) {
        if (arg0 == 23) {
            D_803E1B10[4] = 1;
            func_80349778_75AE28();
        }
        if (arg0 == 24) {
            D_803E1B10[4] = 0;
            func_80349748_75ADF8();
        }
    } else if ((arg0 == 6) || (arg0 == 7) || (arg0 == 19) || (arg0 == 20)) {
        if (arg0 == 6) {
            func_8012ABF0();
        }
        if (arg0 == 7) {
            func_8012AC40();
        }
        if (arg0 == 19) {
            func_80349748_75ADF8();
        }
        if (arg0 == 20) {
            func_80349778_75AE28();
        }
    } else {
        if ((D_803E1B10[0] == 0) || (D_803E1B10[0] == 1)) {
            D_803E1B10[0] = 2;
            D_803E1B10[1] = 1;
            D_803E1B10[3] = 0;
            D_803E1B10[2] = arg0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_701E80/func_802F0918_701FC8.s")

s16 func_802F1388_702A38(void) {
    if ((D_803E1B10[0] == 0) || (D_803E1B10[0] == 1)) {
        return 1;
    } else {
        return 0;
    }
}

void func_802F13B8_702A68(void) {
    if (D_803E1B10[4] != 0) {
        func_8039D034_7AE6E4(&D_801D9E7C, 0);
        D_803A50C0_7B6770.unk0 = gScreenWidth * 2;
        D_803A50C0_7B6770.unk2 = gScreenHeight * 2;
        D_803A50C0_7B6770.unk8 = gScreenWidth * 2;
        D_803A50C0_7B6770.unkA = gScreenHeight * 2;
        func_80129594(&D_801D9E7C, D_80204278);
        guPerspective(&D_80204278->unk37550, &D_803E1B10[7], 33.0f, 1.0f, 5.0f, 100.0f, 1.0f);
        guRotateRPY(&D_80204278->unk37590, 0.5f, 0.5f, 0.5f);
        guRotateRPY(&D_80204278->unk37610, 0.9f, 1.0f, 1.0f);
        guLookAt(&D_80204278->unk375D0, -1.0f, 105.0f, -3.0f, -1.0f, 0.0f, -3.0f, 0.0f, 0.0f, 1.0f);

        gSPMatrix(D_801D9E7C++, &D_80204278->unk37550, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37590, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk375D0, G_MTX_NOPUSH | G_MTX_MUL  | G_MTX_PROJECTION);
        gSPMatrix(D_801D9E7C++, &D_80204278->unk37610, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPPerspNormalize(D_801D9E7C++, (u16)D_803E1B10[7]);

        func_80129300(&D_801D9E7C, D_80204278);
        func_80380490_791B40(&D_801D9E7C, D_80204278);

        gSPViewport(D_801D9E7C++, &D_803A50C0_7B6770);

        gDPSetColorImage(D_801D9E7C++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_80204274->unk3BBE8));
        gSPDisplayList(D_801D9E7C++, D_01004270);
        gSPTexture(D_801D9E7C++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCombineLERP(D_801D9E7C++, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0);
        gDPSetRenderMode(D_801D9E7C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

        func_802F30A4_704754();
        gSPSetGeometryMode(D_801D9E7C++, G_LIGHTING);
        gSPDisplayList(D_801D9E7C++, D_01013370);
    }
}
