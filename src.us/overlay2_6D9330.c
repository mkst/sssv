#include <ultra64.h>
#include "common.h"

#ifdef NON_MATCHING
// ESA: func_8005F8F8
// 970
void func_802C7C80_6D9330(void) {
    s16 i;
    int isEvoTransfer;

    memset_bytes((u8 *) gAnimalState.unk0, 0, sizeof(gAnimalState.unk0));

    for (i = 0; i < AID_MAX_ANIMALS; i++) {

        gAnimalState.unk0[i].class = D_803A05D0_7B1C80[i].class;

        gAnimalState.unk0[i].unk7E = 0xCC;
        gAnimalState.unk0[i].unk80 = 2;
        gAnimalState.unk0[i].unk8A = 0x7F;
        gAnimalState.unk0[i].unkD8 = 0x14;

        gAnimalState.unk0[i].waterClass = D_803A05D0_7B1C80[i].waterClass;
        gAnimalState.unk0[i].canJump = D_803A05D0_7B1C80[i].canJump;

        gAnimalState.unk0[i].unkBE = D_803A05D0_7B1C80[i].unk6;
        gAnimalState.unk0[i].unk72 = D_803A05D0_7B1C80[i].unk6;
        gAnimalState.unk0[i].unk74 = D_803A05D0_7B1C80[i].unk6;
        gAnimalState.unk0[i].mass = D_803A05D0_7B1C80[i].unk8;
        gAnimalState.unk0[i].armour = D_803A05D0_7B1C80[i].unkA;
        gAnimalState.unk0[i].unk8C = D_803A05D0_7B1C80[i].unkB;
        gAnimalState.unk0[i].unkEB = D_803A05D0_7B1C80[i].unk51;

        isEvoTransfer = i == EVO_TRANSFER;
        if (i == EVO || isEvoTransfer) {
            gAnimalState.unk0[i].unk2 = 15;
        } else {
            gAnimalState.unk0[i].unk2 = 5;
        }

        gAnimalState.unk0[i].unkAC = D_803A05D0_7B1C80[i].unk14;
        gAnimalState.unk0[i].unkA6 = D_803A05D0_7B1C80[i].unkE;
        gAnimalState.unk0[i].unkA8 = D_803A05D0_7B1C80[i].unk10;
        gAnimalState.unk0[i].unkAA = D_803A05D0_7B1C80[i].unk12;
        gAnimalState.unk0[i].unkB4 = D_803A05D0_7B1C80[i].unk1C;
        gAnimalState.unk0[i].fallDistance = D_803A05D0_7B1C80[i].unk16;
        gAnimalState.unk0[i].unkB0 = D_803A05D0_7B1C80[i].unk18;
        gAnimalState.unk0[i].unkA4 = D_803A05D0_7B1C80[i].unkC;
        gAnimalState.unk0[i].unkBA = D_803A05D0_7B1C80[i].unk22;
        gAnimalState.unk0[i].unk7A = gAnimalState.unk0[i].unkBA;
        gAnimalState.unk0[i].unkB8 = D_803A05D0_7B1C80[i].unk20;
        gAnimalState.unk0[i].traction = D_803A05D0_7B1C80[i].unk1A;
        gAnimalState.unk0[i].unkBC = D_803A05D0_7B1C80[i].unk24;
        gAnimalState.unk0[i].unkB6 = D_803A05D0_7B1C80[i].unk1E;

        gAnimalState.unk0[i].unk76 = ((gAnimalState.unk0[i].unk72) * 7) >> 2;
        gAnimalState.unk0[i].unk78 = ((gAnimalState.unk0[i].unk7A) * 5) >> 3;

        gAnimalState.unk0[i].unkC0 = D_803A05D0_7B1C80[i].unk26;
        gAnimalState.unk0[i].unkC2 = D_803A05D0_7B1C80[i].unk28;
        gAnimalState.unk0[i].unkC4 = D_803A05D0_7B1C80[i].unk2A;
        gAnimalState.unk0[i].unkE6 = D_803A05D0_7B1C80[i].unk2C;
        gAnimalState.unk0[i].unkE7 = D_803A05D0_7B1C80[i].unk2D;
        gAnimalState.unk0[i].unkC6 = D_803A05D0_7B1C80[i].unk2E;
        gAnimalState.unk0[i].unkC8 = D_803A05D0_7B1C80[i].unk30;

        gAnimalState.unk0[i].unkCA = D_803A05D0_7B1C80[i].unk32;
        gAnimalState.unk0[i].unkCC = D_803A05D0_7B1C80[i].unk34;
        gAnimalState.unk0[i].unkCE = D_803A05D0_7B1C80[i].unk36;
        gAnimalState.unk0[i].unkD0 = D_803A05D0_7B1C80[i].unk38;
        gAnimalState.unk0[i].unkD2 = D_803A05D0_7B1C80[i].unk3A;
        gAnimalState.unk0[i].objectType = (i & 0xFFFF) + 0x100;
        gAnimalState.unk0[i].unkD4 = D_803A05D0_7B1C80[i].unk3E;
        gAnimalState.unk0[i].unkE8 = D_803A05D0_7B1C80[i].unk3C;
        gAnimalState.unk0[i].unk82.unk2 = 1;
        gAnimalState.unk0[i].biome = D_803A05D0_7B1C80[i].unk40;

        gAnimalState.unk0[i].unkDA[0][0] = D_803A05D0_7B1C80[i].unk42[0][0];
        gAnimalState.unk0[i].unkDA[0][1] = D_803A05D0_7B1C80[i].unk42[0][1];
        gAnimalState.unk0[i].unkDA[0][2] = D_803A05D0_7B1C80[i].unk42[0][2];

        gAnimalState.unk0[i].unkDA[1][0] = D_803A05D0_7B1C80[i].unk42[1][0];
        gAnimalState.unk0[i].unkDA[1][1] = D_803A05D0_7B1C80[i].unk42[1][1];
        gAnimalState.unk0[i].unkDA[1][2] = D_803A05D0_7B1C80[i].unk42[1][2];

        gAnimalState.unk0[i].unk9C = i;
        gAnimalState.unk0[i].unk82.unk3 = 1;
        gAnimalState.unk0[i].unk82.unk4 = 1;
        gAnimalState.unk0[i].unk82.unk5 = 1;
        gAnimalState.unk0[i].unk82.unk6 = 0u;

        gAnimalState.unk0[i].unkE9 = D_803A05D0_7B1C80[i].unk4F;
        gAnimalState.unk0[i].unkEA = D_803A05D0_7B1C80[i].unk50;

        if ((i & 0xFFFF) == DESERT_FOX_ATTACKING) {
            gAnimalState.unk0[i].unk8D = 4;
        } else if ((i & 0xFFFF) == HARD_MOUSE) {
            gAnimalState.unk0[i].unk8D = 2;
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

    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if (gAnimalState.animals[i].animal->unk366 == MOVEMENT_MODE_DELETED) {
            break;
        }
    }

    if (i == gNumAnimalsInLevel) {
        slot = gNumAnimalsInLevel;
        gNumAnimalsInLevel++;
    } else {
        slot = i;
    }

    memset_bytes(&gAnimalState.animals[slot], 0, sizeof(Animal2));
    memset_bytes(&gAnimalState.unk4040[slot], 0, sizeof(Animal));

    // setup pointer
    gAnimalState.animals[slot].unk0 = &gAnimalState.unk0[id];
    gAnimalState.animals[slot].animal = &gAnimalState.unk4040[slot];

    D_803D5520 = &gAnimalState.animals[slot];
    D_803D5524 = &gAnimalState.unk0[id];

    sp1C = D_803D5530 = gAnimalState.animals[slot].animal;
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
        sp1C->unk366 = MOVEMENT_MODE_NORMAL;
    } else if (health > 0) {
        sp1C->unk366 = MOVEMENT_MODE_INJURED;
    } else {
        sp1C->unk366 = MOVEMENT_MODE_DEACTIVATED;
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

    i = sample_ground_height_at_xz(arg0, arg1) >> 0x10;
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
    func_802DADA0_6EC450(gAnimalState.animals[slot].animal);
    D_803D5528->unk3C8.unk2 = load_dynamic_tail(id);
    D_803D552C->unk272 = 0x43F;
    func_802C9BA4_6DB254(gAnimalState.animals[slot].animal);
    D_803D552C->energy[0].unk0 = 0x3FF;
    D_803D552C->energy[1].unk0 = 0x3FF;
    if ((arg6 != 0) && (((gCameraId == 0)) || (gCameraId == 1))) {
        func_803284C4_739B74();
    }
    return &gAnimalState.animals[slot];
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
    arg0->unk366 = MOVEMENT_MODE_DELETED;
}
