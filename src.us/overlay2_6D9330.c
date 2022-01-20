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
//     struct035 *temp_v0;
//     struct089 *temp_v1;
//     s16 phi_a1;
//     s16 i;
//
//     memset_bytes(&D_801D9ED8, 0, 0x3EB0);
//
//     for (i = 0; i < 68; i++) {
//         temp_v0 = &D_801D9ED8.unk0[i]; // + (phi_a1 * 0xEC);
//         temp_v0->unk7E = 0xCC;
//         temp_v0->unk80.bit2 = 1; // = 2;
//         temp_v0->unk8A = 0x7F;
//         temp_v0->unkD8 = 0x14;
//         temp_v1 = &D_803A05D0_7B1C80[i]; // + (phi_a1 * 0x52);
//         // temp_a0 = temp_v1->unk6;
//         temp_v0->unk9E = (u16) temp_v1->unk0;
//         temp_v0->unkA0 = (u16) temp_v1->unk2;
//         temp_v0->unkA2 = (u16) temp_v1->unk4;
//         temp_v0->unkBE = temp_v1->unk6;
//         temp_v0->unk72 = temp_v1->unk6;
//         temp_v0->unk74 = temp_v1->unk6;
//         temp_v0->unk7C = (u16) temp_v1->unk8;
//         temp_v0->unk8B = (u8) temp_v1->unkA;
//         temp_v0->unk8C = (u8) temp_v1->unkB;
//         temp_v0->unkEB = (s8) temp_v1->unk51;
//         if ((i == EVO) || (i == EVO_GLITCHY)) {
//             temp_v0->unk2 = 15;
//         } else {
//             temp_v0->unk2 = 5;
//         }
//         temp_v0->unkA8 = (u16) temp_v1->unk10;
//         temp_v0->unkA6 = (u16) temp_v1->unkE;
//         temp_v0->unkB0 = (s16) temp_v1->unk18;
//         temp_v0->unkAE = (s16) temp_v1->unk16;
//         temp_v0->unkB8 = (u16) temp_v1->unk20;
//         temp_v0->unkAA = (u16) temp_v1->unk12;
//         temp_v0->unkB6 = (u16) temp_v1->unk1E;
//         // temp_t9 = temp_v1->unk22;
//         temp_v0->unkA4 = (u16) temp_v1->unkC;
//         temp_v0->unkB2 = (u16) temp_v1->unk1A;
//         temp_v0->unkBA = temp_v1->unk22;
//         temp_v0->unk7A = temp_v1->unk22;
//         temp_v0->unkAC = (u16) temp_v1->unk14;
//         temp_v0->unkB4 = (u16) temp_v1->unk1C;
//         temp_v0->unkC2 = (s16) temp_v1->unk28;
//         temp_v0->unkBC = (u16) temp_v1->unk24;
//         temp_v0->unk76 = (s16) ((s32) (temp_v0->unk72 * 7) >> 2);
//         temp_v0->unkC0 = (s16) temp_v1->unk26;
//         temp_v0->unkC4 = (s16) temp_v1->unk2A;
//         temp_v0->unkE7 = (s8) temp_v1->unk2D;
//         temp_v0->unkC8 = (s16) temp_v1->unk30;
//         temp_v0->unkC6 = (s16) temp_v1->unk2E;
//         temp_v0->unkCC = (s16) temp_v1->unk34;
//         temp_v0->unk78 = (s16) ((s32) ((temp_v1->unk22 & 0xFFFF) * 5) >> 3);
//         temp_a0_2 = i & 0xFFFF;
//         temp_v0->unkD0 = (s16) temp_v1->unk38;
//         temp_v0->unkCE = (s16) temp_v1->unk36;
//         temp_v0->unk0 = (s16) (temp_a0_2 + 0x100);
//         temp_v0->unkE8 = (s8) temp_v1->unk3C;
//         temp_v0->unkE6 = (s8) temp_v1->unk2C;
//         temp_v0->unkD4 = (s16) temp_v1->unk3E;
//         temp_v0->unkD6 = (s16) temp_v1->unk40;
//         temp_v0->unkCA = (s16) temp_v1->unk32;
//         // temp_v0->unk82 = (u8) (temp_v0->unk82 | 0x20);
//         temp_v0->unkDA[1] = (s16) temp_v1->unk44;
//         temp_v0->unkE0[0] = (s16) temp_v1->unk48;
//         temp_v0->unkD2 = (s16) temp_v1->unk3A;
//         temp_v0->unkDA[2] = (s16) temp_v1->unk46;
//         temp_v0->unkE0[2] = (s16) temp_v1->unk4C;
//         // temp_t9_2 = temp_v0->unk82 | 0x10;
//         temp_t8 = temp_t9_2 | 8;
//         temp_v0->unkDA[0] = (s16) temp_v1->unk42;
//         // temp_v0->unk82 = temp_t9_2;
//         temp_t6 = temp_t8 | 4;
//         // temp_v0->unk82 = temp_t8;
//         temp_v0->unkE0[1] = (s16) temp_v1->unk4A;
//         // temp_v0->unk82 = temp_t6;
//         temp_v0->unk9C = i; // animal id?
//         // temp_v0->unk82 = (u8) (temp_t6 & 0xFD);
//         temp_v0->unkE9 = (s8) temp_v1->unk4F;
//         temp_v0->unkEA = (s8) temp_v1->unk50;
//         if (i == DESERT_FOX_ATTACKING) {
//             temp_v0->unk8D = 4;
//         } else if (i == HARD_MOUSE) {
//             temp_v0->unk8D = 2;
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
