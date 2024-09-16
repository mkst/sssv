#include <ultra64.h>
#include "common.h"

#if 0
// ESA: func_8005F8F8
void func_802C7C80_6D9330(void) {
    struct089 *src;
    struct035 *dst;

    s16 i;
    u16 animalId;

    memset_bytes((u8 *) D_801D9ED8.unk0, 0, sizeof(D_801D9ED8.unk0));

    for (i = 0; i < 0x44; i++) {
        src = &D_803A05D0_7B1C80[i];
        dst = &D_801D9ED8.unk0[i];

        dst->unk7E = 0xCC;
        dst->unk80 = 2;
        dst->unk8A = 0x7F;
        dst->unkD8 = 0x14;

        dst->class = src->class;
        dst->waterClass = src->waterClass;
        dst->canJump = src->canJump;

        dst->unk74 = dst->unk72 = dst->unkBE = src->unk6;
        // dst->unk74 = src->unk6;
        // dst->unk74 = src->unk6;

        dst->mass = src->unk8;
        dst->armour = src->unkA;
        dst->unk8C = src->unkB;

        dst->unkEB = src->unk51;

        if ((i == EVO) || (i == EVO_TRANSFER)) {
            dst->unk2 = 15;
        } else {
            dst->unk2 = 5;
        }

        dst->unkA8 = src->unk10;
        dst->fallDistance = src->unk16;

        dst->unk7A = dst->unkBA = src->unk22;
        // dst->unk7A = src->unk22;

        dst->unkA4 = src->unkC;
        dst->unkA6 = src->unkE;

        dst->unkAA = src->unk12;
        dst->unkAC = src->unk14;
        dst->unkB0 = src->unk18;
        dst->traction = src->unk1A;
        dst->unkB4 = src->unk1C;
        dst->unkB6 = src->unk1E;

        dst->unkB8 = src->unk20;
        dst->unkBC = src->unk24;

        dst->unk76 = (dst->unk72 * 7) >> 2;
        dst->unkC0 = src->unk26;

        dst->unk78 = (src->unk22 * 5) >> 3;
        dst->unkC2 = src->unk28;

        dst->unk9C = i;

        dst->unkE6 = src->unk2C;
        dst->unkE7 = src->unk2D;
        dst->unkC4 = src->unk2A;

        animalId = i;
        dst->objectType = animalId + 0x100;

        dst->unkC6 = src->unk2E;
        dst->unkC8 = src->unk30;
        dst->unkCA = src->unk32;
        dst->unkCC = src->unk34;

        dst->unkCE = src->unk36;
        dst->unkD0 = src->unk38;
        dst->unkD2 = src->unk3A;

        dst->biome = src->unk40;
        dst->unkE8 = src->unk3C;
        dst->unkD4 = src->unk3E;

        dst->unkDA[0][0] = src->unk42[0][0];
        dst->unkDA[0][1] = src->unk42[0][1];
        dst->unkDA[0][2] = src->unk42[0][2];

        dst->unkDA[1][0] = src->unk42[1][0];
        dst->unkDA[1][1] = src->unk42[1][1];
        dst->unkDA[1][2] = src->unk42[1][2];

        dst->unk82.unk2 = 1;
        dst->unk82.unk3 = 1;
        dst->unk82.unk4 = 1;
        dst->unk82.unk5 = 1;
        dst->unk82.unk6 = 0;

        dst->unkE9 = src->unk4F;
        dst->unkEA = src->unk50;

        if (animalId == DESERT_FOX_ATTACKING) {
            dst->unk8D = 4;
        } else if (animalId == HARD_MOUSE) {
            dst->unk8D = 2;
        }

    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9330/func_802C7C80_6D9330.s")
#endif

Animal2 *spawn_animal(s16 arg0, s16 arg1, s16 arg2, s16 rotation, s16 health, s16 id, s8 arg6) {
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
    D_803D552C->heading = rotation;
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
    D_803D5528->unk3C8.unk2 = load_dynamic_tail(id);
    D_803D552C->unk272 = 0x43F;
    func_802C9BA4_6DB254(D_801D9ED8.animals[slot].animal);
    D_803D552C->energy[0].unk0 = 0x3FF;
    D_803D552C->energy[1].unk0 = 0x3FF;
    if ((arg6 != 0) && (((gCameraId == 0)) || (gCameraId == 1))) {
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
        unload_dynamic_tail(arg0->unk3C8.unk2);
        arg0->unk3C8.unk2 = 0;
    }
    // delete objects
    remove_collision_list(arg0);
    arg0->unk366 = 6;
}
