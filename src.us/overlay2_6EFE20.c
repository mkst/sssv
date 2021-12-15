#include <ultra64.h>
#include "common.h"


// --- fake file split ---


void func_802DE770_6EFE20(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC += arg2;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 += arg3;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 += arg4;
}

void func_802DE7F4_6EFEA4(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 i;

    for (i = D_803E00C0[arg0].unk16; i < D_803E00C0[arg0].unk16 + D_803E00C0[arg0].unk14; i++) {
        D_803DA300[i].unk0 += arg1;
        D_803DA300[i].unk4 += arg2;
        D_803DA300[i].unk8 += arg3;
    }
}

void func_802DE890_6EFF40(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk0 = arg2;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk4 = arg3;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk8 = arg4;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unkC = arg5;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk10 = arg6;
    D_803DA300[D_803E00C0[arg0].unk16 + arg1].unk14 = arg7;
}

void func_802DE914_6EFFC4(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4) {
    struct051 *tmp = &D_803E00C0[arg0];
    tmp->unk20 = arg1;
    tmp->unk24 = arg2;
    tmp->unk28 = arg3;
    tmp->unk2C = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6EFE20/func_802DE950_6F0000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6EFE20/func_802E072C_6F1DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6EFE20/func_802E3C88_6F5338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6EFE20/func_802E414C_6F57FC.s")

void func_802E497C_6F602C(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    struct088 *tmp;

    tmp = &D_803DA300[D_803E00C0[arg0].unk16];

    *arg1 = (tmp->unk0 - *(s32*)&D_803D5530->xPos) >> 14;
    *arg2 = (tmp->unk4 - *(s32*)&D_803D5530->zPos) >> 14;
    *arg3 = (tmp->unk8 - *(s32*)&D_803D5530->yPos) >> 14;

    if ((ABS(*arg3) < 100) &&
        (ABS(*arg1) < 100) &&
        (ABS(*arg2) < 100)) {
        *arg3 = 100;
    }
}

void func_802E4A78_6F6128(s16 arg0) {
    D_803E00C0[arg0].unk2F = 1;
    D_803E1B06 = 15;
    D_803E1B08 = arg0;
}

void func_802E4AB8_6F6168(void) {
    s16 i;
    for (i = 0; i < 120; i++) {
        if (D_803E00C0[i].unk2F == 2) {
            D_803E00C0[i].unk2F = 1;
        }
    }
}

// load_dynamic_tail
s32 func_802E4B0C_6F61BC(s16 animalId) {
    switch (animalId) {
    case MOUSE:
    case RACING_MOUSE:
    case MOUSE2:
    case HELI_MOUSE:
    case RAT:
        return func_802DD090_6EE740(6, FTOFIX32(3.125), 1, 3, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case KING_RAT:
        return func_802DD090_6EE740(6, FTOFIX32(6.25), 1, 32, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case HUSKY:
    case SKI_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 11, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case CRAZY_HUSKY:
        return func_802DD090_6EE740(4, FTOFIX32(6.875), 1, 12, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case POGO_KANGAROO:
    case BOXING_KANGAROO:
        return func_802DD090_6EE740(4, FTOFIX32(15.0), 1, 13, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case SCORPION:
        return func_802DD090_6EE740(7, FTOFIX32(5.90625), 1, 14, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case ELEPHANT:
        return func_802DD090_6EE740(5, FTOFIX32(16.40625), 1, 16, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    case LION:
        return func_802DD090_6EE740(4, FTOFIX32(15.625), 1, 35, 0, *(s32*)&D_803D5530->xPos, *(s32*)&D_803D5530->zPos, *(s32*)&D_803D5530->yPos, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    default:
        return 0;
    }
}

void func_802E4EB4_6F6564(s16 arg0) {
    if (arg0 != 0) {
        D_803E00C0[arg0].unk2E = 0;
    }
    if ((D_803E1B02 >= 2) && D_803E00C0[D_803E1B02 - 1].unk2E == 0) {
        D_803E1B02--;
    }
}

void func_802E4F20_6F65D0(s32 img) {
    gDPSetTextureImage(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, img);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(D_801D9E88++);
    gDPLoadBlock(D_801D9E88++, G_TX_LOADTILE, 0, 0, 1024, 0);
    gDPTileSync(D_801D9E88++);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
    gDPSetTile(D_801D9E88++, G_IM_FMT_IA, G_IM_SIZ_16b, 8, 0x0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);
}
