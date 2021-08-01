#include <ultra64.h>
#include "common.h"


// reset/initialise displaylist struct offset?
void func_80131070(void) {
    D_8023F3E0 = 0;
}

void func_8013107C(struct018 *arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4, s32 arg5) {
    struct031 *temp_s0;

    D_801D9E7C = arg0->unk4E0; // 1248
    temp_s0 = &arg0->unk0[D_8023F3E0];
    switch (arg3) {
        case 0:
            temp_s0->unk40 = arg1;
            temp_s0->unk44 = arg2;
            temp_s0->unk14 = 0;
            temp_s0->unk20 = D_8014D460;
            temp_s0->unk28 = &D_8015B790;
            temp_s0->unk38 = NULL;
            temp_s0->unk3C = NULL;
            temp_s0->unk48 = NULL;
            temp_s0->unk4C = 0;
            break;
        case 2:
            temp_s0->unk40 = arg1;
            temp_s0->unk44 = arg2;
            temp_s0->unk14 = 6;
            temp_s0->unk20 = &D_8014F1D0; // ucode code start
            temp_s0->unk28 = &D_8015D710; // ucode data start
            temp_s0->unk38 = &D_800EF0D0;
            temp_s0->unk3C = &D_800FF0D0;
            temp_s0->unk48 = &D_802043E0;
            temp_s0->unk4C = 0xC00;
            break;
        case 3:
            temp_s0->unk40 = arg1;
            temp_s0->unk44 = arg2;
            temp_s0->unk14 = 6;
            temp_s0->unk20 = &D_8014F1D0; // ucode code start
            temp_s0->unk28 = &D_8015D710; // ucode data start
            temp_s0->unk38 = &D_800EF0D0;
            temp_s0->unk3C = &D_800FF0D0;
            temp_s0->unk48 = &D_802043E0;
            temp_s0->unk4C = 0xC00;
            break;
    }

    temp_s0->unk10 = 1;
    temp_s0->unk18 = D_8014D390;
    temp_s0->unk1C = D_8014D460 - D_8014D390; // ucode size?
    temp_s0->unk24 = 0x1000;
    temp_s0->unk2C = 0x800;
    temp_s0->unk30 = &D_800DEE20;
    temp_s0->unk34 = 0x80;
    temp_s0->unk0 = 0;
    temp_s0->unk8 = arg5;   // 99
    temp_s0->unk50 = &D_8028D060;
    temp_s0->unk54 = arg4;
    temp_s0->unkC = arg0->unk3BBE8;

    osDpSetStatus(DPC_CLR_CLOCK_CTR | DPC_CLR_CMD_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_TMEM_CTR); // 0x3C0
    osSendMesg(osScGetCmdQ(&D_801603D0), temp_s0, 1);
    D_8023F3E0 += 1;
}
