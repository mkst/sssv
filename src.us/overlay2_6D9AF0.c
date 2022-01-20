#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8440_6D9AF0.s")

void func_802C85EC_6D9C9C(void) {
    Animal *a;

    if (D_803F2D50.animalId != EVO_MICROCHIP) {
        D_803E9824 = D_803F2D50.animalId;
        D_803E9820 = D_803A63B0_7B7A60[D_803E9824].unk0;
        D_803E9822 = D_803A63B0_7B7A60[D_803E9824].unk1;
        gCurrentAnimalIndex = D_803D553E;
        a = D_801D9ED8.animals[0].animal;
        func_802C7F88_6D9638(a->xPos, a->zPos, a->yPos, 0, 0x7F, D_803E9824, 1);
        func_80327DA8_739458();
        D_801D9ED8.animals[0].animal->unk366 = 3;
        D_801D9ED8.animals[0].unk0 = &D_801DD800;
        D_801D9ED8.animals[0].animal->unk16C = &D_801DD800;
        D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
        D_801D9ED8.animals[0].animal->unk4A = 0;
    }
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302 = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.unkFFA8 = (D_803F2D50.unk4E << 8) / 360;
    D_803F2AA3 = 0;
    D_803F2AA2 = 0;
}

void func_802C87E0_6D9E90(void) {
    D_80204278->usedHilites = 0;
    D_80204278->unk3891C = 0;
    D_803E1B04 = 0;
    D_803F3310 = 0;
    if (D_803F2D10.unk0 == 0) {
        D_803D5540 = (D_803D5540 + 1) & 0xFF;
        D_803D5542 = (D_803D5542 + 1) % 360;
        D_803D5544 += 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8878_6D9F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C8FC0_6DA670.s")

// huh?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9340_6DA9F0.s")

struct071 *func_802C93E8_6DAA98(u16 arg0) {
    return &D_80203AA8[0-arg0].unk4.w; // probably not right?
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C941C_6DAACC.s")

struct071 *func_802C9488_6DAB38(void) {
    struct071 *obj;

    if (D_801F9EB8.unkA114 >= 170) {
        return NULL;
    }
    obj = D_80203D1C[D_801F9EB8.unkA110--];

    if (D_801F9EB8.unkA110 < 0) {
        D_801F9EB8.unkA110 = 169;
    }
    D_801F9EB8.unkA114 += 1; // used?

    obj->unk26C = 0;
    return obj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9500_6DABB0.s")
// void func_802C9500_6DABB0(struct071 *obj) {
//     D_80203D1C[D_801F9EB8.unkA112--] = obj;
//     if (D_801F9EB8.unkA112 < 0) {
//         D_801F9EB8.unkA112 = 169;
//     }
//     D_801F9EB8.unkA114--;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9564_6DAC14.s")

void func_802C9834_6DAEE4(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

void func_802C985C_6DAF0C(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

void func_802C9884_6DAF34(void) {
    u16 i;

    func_802DAF5C_6EC60C();
    func_802C941C_6DAACC();

    for (i = 0; i < 170; i++) {
        bzero_sssv(&D_801E9EB8[i].unk4, 0x270);

    }
    func_8029F3CC_6B0A7C();
}

void func_802C9900_6DAFB0(struct071 *arg0, s32 arg1, u8 arg2) {
    arg0->unk24C[arg2] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9918_6DAFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9BA4_6DB254.s")
