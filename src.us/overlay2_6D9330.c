#include <ultra64.h>
#include "common.h"

#if 0
// ESA: func_8005F8F8
void func_802C7C80_6D9330(void) {
    s32 temp_a0_2;
    struct035 *temp_v0;
    struct089 *temp_v1;
    u16 temp_a0;
    u16 temp_t9;
    s16 i;
    u8 temp_t6;
    u8 temp_t8;
    u8 temp_t9_2;

    memset_bytes((u8 *) &D_801D9ED8, 0U, 0x3EB0U); // D_801D9ED8.unk0 ?

    for (i = 0; i < 0x44; i++) {
        temp_v1 = &D_803A05D0_7B1C80[i];

        D_801D9ED8.unk0[i].unk7E = 0xCC;
        D_801D9ED8.unk0[i].unk80 = 2;
        D_801D9ED8.unk0[i].unk8A = 0x7F;
        D_801D9ED8.unk0[i].unkD8 = 0x14;

        D_801D9ED8.unk0[i].class = temp_v1->class;
        D_801D9ED8.unk0[i].waterClass = temp_v1->waterClass;
        D_801D9ED8.unk0[i].canJump = temp_v1->canJump;

        D_801D9ED8.unk0[i].unkBE = temp_v1->unk6;
        D_801D9ED8.unk0[i].unk72 = temp_v1->unk6;
        D_801D9ED8.unk0[i].unk74 = temp_v1->unk6;

        D_801D9ED8.unk0[i].mass = temp_v1->unk8;
        D_801D9ED8.unk0[i].armour = temp_v1->unkA;

        D_801D9ED8.unk0[i].unk8C = temp_v1->unkB;
        D_801D9ED8.unk0[i].unkEB = temp_v1->unk51;

        if ((i == EVO) || (i == EVO_TRANSFER)) {
            D_801D9ED8.unk0[i].unk2 = 15;
        } else {
            D_801D9ED8.unk0[i].unk2 = 5;
        }

        D_801D9ED8.unk0[i].unkA6 = temp_v1->unkE;
        D_801D9ED8.unk0[i].unkB0 = temp_v1->unk18;
        D_801D9ED8.unk0[i].unkA8 = temp_v1->unk10;
        D_801D9ED8.unk0[i].unkAA = temp_v1->unk12;
        D_801D9ED8.unk0[i].fallDistance = temp_v1->unk16;
        D_801D9ED8.unk0[i].traction = temp_v1->unk1A;
        D_801D9ED8.unk0[i].unkB4 = temp_v1->unk1C;
        D_801D9ED8.unk0[i].unkA4 = temp_v1->unkC;

        D_801D9ED8.unk0[i].unkB8 = temp_v1->unk20;
        D_801D9ED8.unk0[i].unkBA = temp_v1->unk22;
        D_801D9ED8.unk0[i].unkAC = temp_v1->unk14;
        D_801D9ED8.unk0[i].unk7A = temp_v1->unk22;
        D_801D9ED8.unk0[i].unkC2 = temp_v1->unk28;
        D_801D9ED8.unk0[i].unkB6 = temp_v1->unk1E;
        D_801D9ED8.unk0[i].unk76 = (D_801D9ED8.unk0[i].unk72 * 7) >> 2;
        D_801D9ED8.unk0[i].unkBC = temp_v1->unk24;
        D_801D9ED8.unk0[i].unkC0 = temp_v1->unk26;
        // temp_a0_2 = temp_v1->unk22 * 5;
        D_801D9ED8.unk0[i].unkC8 = temp_v1->unk30;
        D_801D9ED8.unk0[i].unkC4 = temp_v1->unk2A;
        D_801D9ED8.unk0[i].unkE7 = temp_v1->unk2D;
        D_801D9ED8.unk0[i].unkC6 = temp_v1->unk2E;
        D_801D9ED8.unk0[i].unkCC = temp_v1->unk34;
        D_801D9ED8.unk0[i].unk78 = (temp_v1->unk22 * 5) >> 3;
        // temp_a0_2 = i & 0xFFFF;
        D_801D9ED8.unk0[i].unkD0 = temp_v1->unk38;
        D_801D9ED8.unk0[i].unkCE = temp_v1->unk36;

        D_801D9ED8.unk0[i].objectType = (u16)(i) + 0x100;

        D_801D9ED8.unk0[i].unkE6 = temp_v1->unk2C;
        D_801D9ED8.unk0[i].unkE8 = temp_v1->unk3C;

        D_801D9ED8.unk0[i].unkD4 = temp_v1->unk3E;
        D_801D9ED8.unk0[i].biome = temp_v1->unk40;
        D_801D9ED8.unk0[i].unkCA = temp_v1->unk32;
        // D_801D9ED8.unk0[i].unk82 = (u8) (D_801D9ED8.unk0[i].unk82 | 0x20);

        D_801D9ED8.unk0[i].unk82.unk2 = 1;
        D_801D9ED8.unk0[i].unkDA[0][1] = temp_v1->unk44;

        D_801D9ED8.unk0[i].unkDA[0][0] = temp_v1->unk42;
        D_801D9ED8.unk0[i].unkDA[0][2] = temp_v1->unk46;
        D_801D9ED8.unk0[i].unkDA[1][2] = temp_v1->unk4C;
        D_801D9ED8.unk0[i].unkDA[1][0] = temp_v1->unk48;

        D_801D9ED8.unk0[i].unkDA[1][1] = temp_v1->unk4A;

        D_801D9ED8.unk0[i].unkD2 = temp_v1->unk3A;

        D_801D9ED8.unk0[i].unk9C = i;

        D_801D9ED8.unk0[i].unk82.unk3 = 1;
        D_801D9ED8.unk0[i].unk82.unk4 = 1;
        D_801D9ED8.unk0[i].unk82.unk5 = 1;
        D_801D9ED8.unk0[i].unk82.unk6 = 0;

        D_801D9ED8.unk0[i].unkE9 = temp_v1->unk4F;
        D_801D9ED8.unk0[i].unkEA = temp_v1->unk50;

        if (i == DESERT_FOX_ATTACKING) {
            D_801D9ED8.unk0[i].unk8D = 4;
        } else if (i == HARD_MOUSE) {
            D_801D9ED8.unk0[i].unk8D = 2;
        }

    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7C80_6D9330.s")
#endif

struct050 *spawn_animal(s16 arg0, s16 arg1, s16 arg2, s16 rotation, s16 health, s16 id, s8 arg6) {
    Animal *sp1C;
    s16 slot;
    s16 i;

    for (i = 0; i < D_803D553E; i++) {
        if (D_801D9ED8.animals[i].animal->unk366 == 6) {
            break;
        }
    }

    if (i == D_803D553E) {
        slot = D_803D553E;
        D_803D553E++;
    } else {
        slot = i;
    }

    memset_bytes(&D_801D9ED8.animals[slot], 0, sizeof(Animal2));
    memset_bytes(&D_801D9ED8.unk4040[slot], 0, sizeof(Animal));

    // setup pointer
    D_801D9ED8.animals[slot].unk0 = &D_801D9ED8.unk0[id];
    D_801D9ED8.animals[slot].animal = &D_801D9ED8.unk4040[slot];

    D_803D5520 = &D_801D9ED8.animals[slot];
    D_803D5524 = &D_801D9ED8.unk0[id];

    sp1C = D_803D5530 = D_801D9ED8.animals[slot].animal;
    D_803D552C = sp1C;
    D_803D5528 = sp1C;

    if (!D_803D5528) {};

    if (slot == gCurrentAnimalIndex) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = slot;
    D_803D553A = 0;
    if (arg6 != 0) {
        sp1C->unk366 = 1;
    } else if (health > 0) {
        sp1C->unk366 = 3;
    } else {
        sp1C->unk366 = 5;
    }

    D_803D552C->unk31A = 0;
    D_803D5530->yRotation = rotation;
    D_803D552C->unk302 = rotation;
    D_803D552C->unk2F2 = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->unk2F6 = 0;
    D_803D552C->unk2F8 = 0;
    D_803D552C->state = 2; // not state..?
    D_803D5530->unk162 = 1;
    D_803D5530->unk160 = 0;
    D_803D5530->unk16C = D_803D5524;
    D_803D5530->health = MIN(health, D_803D5524->unk8A);
    D_803D5530->unk4C.unk1B = 1;
    D_803D5530->unk4C.unk1C = 1;
    D_803D5530->unk4C.unk1D = 1;
    D_803D552C->unk31C = func_801282C4();

    i = func_8031124C_7228FC(arg0, arg1) >> 0x10;
    if (arg2 < i) {
        // dont spawn below ground level
        arg2 = i;
    }

    i = func_80310F58_722608(arg0, arg1) >> 0x10;
    if (i == 0x4000) {
        D_803D5530->unk160 = 0;
    } else if (arg2 >= i) {
        D_803D5530->unk160 = 2;
    } else {
        D_803D5530->unk160 = 1;
    }

    func_802B2EA8_6C4558();
    D_803D5530->position.xPos.w = arg0 << 16;
    D_803D5530->position.zPos.w = arg1 << 16;
    D_803D5530->position.yPos.w = arg2 << 16;
    D_803D5530->xVelocity.w = 0;
    D_803D5530->zVelocity.w = 0;
    D_803D5530->yVelocity.w = -1;
    D_803D5530->unk46 = D_803D5530->unk16C->mass;
    func_802DADA0_6EC450(D_801D9ED8.animals[slot].animal);
    D_803D5528->unk3C8.unk2 = func_802E4B0C_6F61BC(id);
    D_803D552C->unk272 = 0x43F;
    func_802C9BA4_6DB254(D_801D9ED8.animals[slot].animal);
    D_803D552C->energy[0].unk0 = 0x3FF;
    D_803D552C->energy[1].unk0 = 0x3FF;
    if ((arg6 != 0) && (((D_803F2A98 == 0)) || (D_803F2A98 == 1))) {
        func_803284C4_739B74();
    }
    return &D_801D9ED8.animals[slot];
}

// ESA: func_800600E0
void func_802C83CC_6D9A7C(Animal *arg0) {
    if (arg0->unk320 != 0) {
        // decrement linked animal reference id?
        func_802B34B8_6C4B68(arg0->unk320);
    }
    // unload dynamic tail if applicable
    if (arg0->unk3C8.unk2 != 0) {
        func_802E4EB4_6F6564(arg0->unk3C8.unk2);
        arg0->unk3C8.unk2 = 0;
    }
    // delete objects
    func_802DAD18_6EC3C8(arg0);
    arg0->unk366 = 6;
}
