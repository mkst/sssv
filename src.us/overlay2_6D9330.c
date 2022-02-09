#include <ultra64.h>
#include "common.h"


#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7C80_6D9330.s")
// void func_802C7C80_6D9330(void) {
//     s16 temp_a1;
//     u16 temp_a0_2;
//     u16 temp_a0;
//     u16 temp_t9;
//     u8 temp_t6;
//     u8 temp_t8;
//     u8 temp_t9_2;
//     s16 phi_a1;
//     s16 i;
//
//     memset_bytes(&D_801D9ED8, 0, 0x3EB0);
//
//     for (i = 0; i < 68; i++) {
//         D_801D9ED8.unk0[i].unk7E = 0xCC;
//         D_801D9ED8.unk0[i].unk80.bit2 = 1; // = 2;
//         D_801D9ED8.unk0[i].unk8A = 0x7F;
//         D_801D9ED8.unk0[i].unkD8 = 0x14;
//
//         D_801D9ED8.unk0[i].class = D_803A05D0_7B1C80[i].class;
//         D_801D9ED8.unk0[i].waterClass = D_803A05D0_7B1C80[i].waterClass;
//         D_801D9ED8.unk0[i].canJump = D_803A05D0_7B1C80[i].canJump;
//         D_801D9ED8.unk0[i].unkBE = D_803A05D0_7B1C80[i].unk6;
//         D_801D9ED8.unk0[i].unk72 = D_803A05D0_7B1C80[i].unk6;
//         D_801D9ED8.unk0[i].unk74 = D_803A05D0_7B1C80[i].unk6;
//         D_801D9ED8.unk0[i].mass =  D_803A05D0_7B1C80[i].unk8;
//         D_801D9ED8.unk0[i].armour = D_803A05D0_7B1C80[i].unkA;
//         D_801D9ED8.unk0[i].unk8C = D_803A05D0_7B1C80[i].unkB;
//         D_801D9ED8.unk0[i].unkEB = D_803A05D0_7B1C80[i].unk51;
//         if ((i == EVO) || (i == EVO_GLITCHY)) {
//             D_801D9ED8.unk0[i].unk2 = 15;
//         } else {
//             D_801D9ED8.unk0[i].unk2 = 5;
//         }
//         D_801D9ED8.unk0[i].unkA6 = D_803A05D0_7B1C80[i].unkE;
//         D_801D9ED8.unk0[i].unkA8 = D_803A05D0_7B1C80[i].unk10;
//         D_801D9ED8.unk0[i].unkAA = D_803A05D0_7B1C80[i].unk12;
//         D_801D9ED8.unk0[i].unkB0 = D_803A05D0_7B1C80[i].unk18;
//         D_801D9ED8.unk0[i].fallDistance = D_803A05D0_7B1C80[i].unk16;
//         D_801D9ED8.unk0[i].unkB8 = D_803A05D0_7B1C80[i].unk20;
//         D_801D9ED8.unk0[i].unkB6 = D_803A05D0_7B1C80[i].unk1E;
//         D_801D9ED8.unk0[i].unkA4 = D_803A05D0_7B1C80[i].unkC;
//         D_801D9ED8.unk0[i].traction = D_803A05D0_7B1C80[i].unk1A;
//         D_801D9ED8.unk0[i].unkBA = D_803A05D0_7B1C80[i].unk22;
//         D_801D9ED8.unk0[i].unk7A = D_803A05D0_7B1C80[i].unk22;
//         D_801D9ED8.unk0[i].unkAC = D_803A05D0_7B1C80[i].unk14;
//         D_801D9ED8.unk0[i].unkB4 = D_803A05D0_7B1C80[i].unk1C;
//         D_801D9ED8.unk0[i].unkC2 = D_803A05D0_7B1C80[i].unk28;
//         D_801D9ED8.unk0[i].unkBC = D_803A05D0_7B1C80[i].unk24;
//         D_801D9ED8.unk0[i].unk76 = (s16) ((s32) (D_801D9ED8.unk0[i].unk72 * 7) >> 2);
//         D_801D9ED8.unk0[i].unkC0 = D_803A05D0_7B1C80[i].unk26;
//         D_801D9ED8.unk0[i].unkC4 = D_803A05D0_7B1C80[i].unk2A;
//         D_801D9ED8.unk0[i].unkE7 = D_803A05D0_7B1C80[i].unk2D;
//         D_801D9ED8.unk0[i].unkC8 = D_803A05D0_7B1C80[i].unk30;
//         D_801D9ED8.unk0[i].unkC6 = D_803A05D0_7B1C80[i].unk2E;
//         D_801D9ED8.unk0[i].unkCC = D_803A05D0_7B1C80[i].unk34;
//         D_801D9ED8.unk0[i].unk78 = (s16) ((s32) ((D_803A05D0_7B1C80[i].unk22 & 0xFFFF) * 5) >> 3);
//         D_801D9ED8.unk0[i].unkD0 = D_803A05D0_7B1C80[i].unk38;
//         D_801D9ED8.unk0[i].unkCE = D_803A05D0_7B1C80[i].unk36;
//         D_801D9ED8.unk0[i].unk0 = (i + 0x100);
//         D_801D9ED8.unk0[i].unkE8 = (s8) D_803A05D0_7B1C80[i].unk3C;
//         D_801D9ED8.unk0[i].unkE6 = (s8) D_803A05D0_7B1C80[i].unk2C;
//         D_801D9ED8.unk0[i].unkD4 = D_803A05D0_7B1C80[i].unk3E;
//         D_801D9ED8.unk0[i].biome = D_803A05D0_7B1C80[i].unk40;
//         D_801D9ED8.unk0[i].unkCA = D_803A05D0_7B1C80[i].unk32;
//         // D_801D9ED8.unk0[i].unk82 = (u8) (D_801D9ED8.unk0[i].unk82 | 0x20);
//         D_801D9ED8.unk0[i].unkDA[1] = D_803A05D0_7B1C80[i].unk44;
//         D_801D9ED8.unk0[i].unkE0[0] = D_803A05D0_7B1C80[i].unk48;
//         D_801D9ED8.unk0[i].unkD2 = D_803A05D0_7B1C80[i].unk3A;
//         D_801D9ED8.unk0[i].unkDA[2] = D_803A05D0_7B1C80[i].unk46;
//         D_801D9ED8.unk0[i].unkE0[2] = D_803A05D0_7B1C80[i].unk4C;
//         // temp_t9_2 = D_801D9ED8.unk0[i].unk82 | 0x10;
//         // temp_t8 = temp_t9_2 | 8;
//         D_801D9ED8.unk0[i].unkDA[0] = D_803A05D0_7B1C80[i].unk42;
//         D_801D9ED8.unk0[i].unk80.bit4 = 1; // = D_801D9ED8.unk0[i].unk80.bit2; // | 0x10; // temp_t9_2;
//         // temp_t6 = temp_t8 | 4;
//         D_801D9ED8.unk0[i].unk80.bit3 = 1; //temp_t8;
//         D_801D9ED8.unk0[i].unkE0[1] = D_803A05D0_7B1C80[i].unk4A;
//         D_801D9ED8.unk0[i].unk80.bit2 = 1; //2 = temp_t6;
//         D_801D9ED8.unk0[i].unk80.pad = 0xfd; //(u8) (temp_t6 & 0xFD);
//         D_801D9ED8.unk0[i].unkE9 = D_803A05D0_7B1C80[i].unk4F;
//         D_801D9ED8.unk0[i].unkEA = D_803A05D0_7B1C80[i].unk50;
//
//         D_801D9ED8.unk0[i].unk9C = i; // animal id?
//         if (i == DESERT_FOX_ATTACKING) {
//             D_801D9ED8.unk0[i].unk8D = 4;
//         } else if (i == HARD_MOUSE) {
//             D_801D9ED8.unk0[i].unk8D = 2;
//         }
//     }
// }

// spawn animal?
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7F88_6D9638.s")
#if 0
struct050 *func_802C7F88_6D9638(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s8 arg6) {
    s16 sp2A;
    struct050 *sp24;
    void *sp20;
    Animal *sp1C;
    s16 temp_v0;
    s16 temp_v0_8;
    s16 temp_v1;
    s32 temp_v1_3;
    s16 temp_v1_4;
    u8 temp_v0_3;
    void *temp_a0;
    void *temp_a0_2;
    struct050 *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1_2;
    s16 phi_v0;
    s16 used;
    s16 phi_t0;
    s16 i;

    used = 0;
    for (i = 0; i < D_803D553E; i++) {
        if (D_801D9ED8.animals[i].animal->unk366 != 6) {
            used = i; //++;
        }
    }

    if (used == D_803D553E) {
        D_803D553E++;
        phi_t0 = D_803D553E;
    } else {
        phi_t0 = used;
    }

    temp_v0_2 = &D_801D9ED8 + (phi_t0 * 8);
    temp_a0 = temp_v0_2->unk3EB0;
    sp20 = temp_a0;
    sp24 = temp_v0_2;
    sp2A = phi_t0;
    memset_bytes(temp_a0, 0, 8); //, &D_801D9ED8);
    temp_a0_2 = &D_801D9ED8 + (phi_t0 * 0x3D4) + 0x4040;
    sp1C = temp_a0_2;
    memset_bytes(temp_a0_2, 0, 0x3D4); //, &D_801D9ED8);
    temp_v1_2 = &D_801D9ED8.unk0[arg5]; // + (arg5 * 0xEC);
    sp24->unk3EB0 = temp_v1_2;
    sp24->animal->unk0 = sp1C;
    D_803D5520 = sp20;
    D_803D5524 = temp_v1_2;
    D_803D5530 = sp1C;
    D_803D552C = sp1C;
    D_803D5528 = sp1C;
    if (phi_t0 == gCurrentAnimalIndex) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = phi_t0;
    D_803D553A = 0;
    if (arg6 != 0) {
        sp1C->unk366 = 1;
    } else if ((s32) arg4 > 0) {
        sp1C->unk366 = 3;
    } else {
        sp1C->unk366 = 5;
    }
    D_803D552C->unk31A = 0;
    D_803D5530->yRotation = arg3;
    D_803D552C->unk302 = arg3;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2F6 = 0;
    D_803D552C->unk2F8 = 0;
    D_803D552C->state = 2; // not state..?
    D_803D5530->unk162 = 1;
    D_803D5530->unk160 = 0;
    D_803D5530->unk16C = D_803D5524;
    D_803D5530->health = MIN(arg4, D_803D5524->unk8A);
#if 0
    D_803D5530->unk4F = (u8) (D_803D5530->unk4F | 0x10);
    D_803D5530->unk4F = (u8) (D_803D5530->unk4F | 8);
    D_803D5530->unk4F = (u8) (D_803D5530->unk4F | 4);
#endif
    D_803D552C->unk31C = func_801282C4(); //1, arg3, &D_803D5530, &D_801D9ED8);

    temp_v1_3 = func_8031124C_7228FC(arg0, arg1) >> 0x10;
    if (arg2 < (s16)temp_v1_3) {
        arg2 = temp_v1_3;
    }

    temp_v1_3 = func_80310F58_722608(arg0, arg1) >> 0x10;
    if ((s16) temp_v1_3 == 0x4000) {
        D_803D5530->unk160 = 0;
    } else if (arg2 >= (s16) temp_v1_3) {
        D_803D5530->unk160 = 2;
    } else {
        D_803D5530->unk160 = 1;
    }
    func_802B2EA8_6C4558();
    D_803D5530->xPos = arg0 << 16;
    D_803D5530->zPos = arg1 << 16;
    D_803D5530->yPos = arg2 << 16;
    D_803D5530->xVelocity.w = 0;
    D_803D5530->zVelocity.w = 0;
    D_803D5530->yVelocity.w = -1;
    // temp_v0_7 = D_803D5530;
    D_803D5530->unk46 = (u16) D_803D5530->unk16C->mass;
    func_802DADA0_6EC450(sp24->animal);
    D_803D5528->unk3C8.unk2 = func_802E4B0C_6F61BC(arg5);
    D_803D552C->unk272 = 0x43F;
    func_802C9BA4_6DB254(sp24->animal);
    D_803D552C->skillAEnergy[0] = 0x3FF;
    D_803D552C->skillBEnergy[0] = 0x3FF;
    if ((arg6 != 0) && (((D_803F2A98 == 0)) || (D_803F2A98 == 1))) {
        func_803284C4_739B74();
    }
    return sp20;
}
#endif

void func_802C83CC_6D9A7C(Animal *arg0) {
    if (arg0->unk320 != 0) {
        func_802B34B8_6C4B68(arg0->unk320);
    }
    if (arg0->unk3C8.unk2 != 0) {
        func_802E4EB4_6F6564(arg0->unk3C8.unk2);
        arg0->unk3C8.unk2 = 0;
    }
    func_802DAD18_6EC3C8(arg0);
    arg0->unk366 = 6;
}
