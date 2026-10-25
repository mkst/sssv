#include <ultra64.h>
#include "common.h"

// ESA: func_8005F8F8
void func_802C7C80_6D9330(void) {
    s16 i;

    memset_bytes((u8 *) gAnimalState.unk0, 0, sizeof(gAnimalState.unk0));

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        gAnimalState.unk0[i].class = D_803A05D0_7B1C80[i].class;

        gAnimalState.unk0[i].frictionMultiplier = 0xCC;
        gAnimalState.unk0[i].unk80 = 2;
        gAnimalState.unk0[i].maxHealth = 0x7F;
        gAnimalState.unk0[i].criticalHealthThreshold = 0x14;

        gAnimalState.unk0[i].waterClass = D_803A05D0_7B1C80[i].waterClass;
        gAnimalState.unk0[i].jumpFlags = D_803A05D0_7B1C80[i].jumpFlags;

        gAnimalState.unk0[i].width = gAnimalState.unk0[i].depth = gAnimalState.unk0[i].radius = D_803A05D0_7B1C80[i].bodyHalfExtent;
        gAnimalState.unk0[i].mass = D_803A05D0_7B1C80[i].mass & 0xFFFF;
        gAnimalState.unk0[i].armour = D_803A05D0_7B1C80[i].armour;
        gAnimalState.unk0[i].collisionDamageFactor = D_803A05D0_7B1C80[i].collisionDamageFactor;
        gAnimalState.unk0[i].footstepSoundCooldown = D_803A05D0_7B1C80[i].footstepSoundCooldown;

        if (i == EVO || i == EVO_TRANSFER) {
            gAnimalState.unk0[i].objectCategory = 15;
        } else {
            gAnimalState.unk0[i].objectCategory = 5;
        }

        gAnimalState.unk0[i].walkSpeed = D_803A05D0_7B1C80[i].walkSpeed;
        gAnimalState.unk0[i].jumpVelocity = D_803A05D0_7B1C80[i].jumpVelocity;
        gAnimalState.unk0[i].swimSpeed = D_803A05D0_7B1C80[i].swimSpeed;
        gAnimalState.unk0[i].flightLiftVelocity = D_803A05D0_7B1C80[i].flightLiftVelocity;
        gAnimalState.unk0[i].flightSpeed = D_803A05D0_7B1C80[i].flightSpeed;
        gAnimalState.unk0[i].fallDistance = D_803A05D0_7B1C80[i].fallDistance;
        gAnimalState.unk0[i].turnRate = D_803A05D0_7B1C80[i].turnRate;
        gAnimalState.unk0[i].traction = D_803A05D0_7B1C80[i].traction;
        gAnimalState.unk0[i].unkB4 = D_803A05D0_7B1C80[i].unk1C;
        gAnimalState.unk0[i].unkB6 = D_803A05D0_7B1C80[i].unk1E;
        gAnimalState.unk0[i].footHeight = D_803A05D0_7B1C80[i].footHeight;
        gAnimalState.unk0[i].height = D_803A05D0_7B1C80[i].height;
        gAnimalState.unk0[i].unkBC = D_803A05D0_7B1C80[i].unk24;

        gAnimalState.unk0[i].collideHeight = gAnimalState.unk0[i].height;
        gAnimalState.unk0[i].bodyHeight = ((gAnimalState.unk0[i].depth) * 7) >> 2;
        gAnimalState.unk0[i].headHeight = ((gAnimalState.unk0[i].collideHeight) * 5) >> 3;

        gAnimalState.unk0[i].maxCarryWeight = D_803A05D0_7B1C80[i].maxCarryWeight;
        gAnimalState.unk0[i].jumpLiftVelocity = D_803A05D0_7B1C80[i].jumpLiftVelocity;
        gAnimalState.unk0[i].swimLiftVelocity = D_803A05D0_7B1C80[i].swimLiftVelocity;
        gAnimalState.unk0[i].scoreTier = D_803A05D0_7B1C80[i].scoreTier;
        gAnimalState.unk0[i].jumpCooldown = D_803A05D0_7B1C80[i].jumpCooldown;
        gAnimalState.unk0[i].unkC6 = D_803A05D0_7B1C80[i].unk2E;
        gAnimalState.unk0[i].unkC8 = D_803A05D0_7B1C80[i].unk30;

        gAnimalState.unk0[i].unkCA = D_803A05D0_7B1C80[i].unk32;
        gAnimalState.unk0[i].unkCC = D_803A05D0_7B1C80[i].unk34;
        gAnimalState.unk0[i].unkCE = D_803A05D0_7B1C80[i].unk36;
        gAnimalState.unk0[i].unkD0 = D_803A05D0_7B1C80[i].unk38;
        gAnimalState.unk0[i].unkD2 = D_803A05D0_7B1C80[i].unk3A;
        gAnimalState.unk0[i].unkE8 = D_803A05D0_7B1C80[i].unk3C;
        gAnimalState.unk0[i].unkD4 = D_803A05D0_7B1C80[i].unk3E;
        gAnimalState.unk0[i].animalType = i;
        gAnimalState.unk0[i].objectType = gAnimalState.unk0[i].animalType + 0x100;
        gAnimalState.unk0[i].behaviourFlags.unk2 = 1;
        gAnimalState.unk0[i].biome = D_803A05D0_7B1C80[i].biome;

        gAnimalState.unk0[i].unkDA[0][0] = D_803A05D0_7B1C80[i].unk42[0][0];
        gAnimalState.unk0[i].unkDA[0][1] = D_803A05D0_7B1C80[i].unk42[0][1];
        gAnimalState.unk0[i].unkDA[0][2] = D_803A05D0_7B1C80[i].unk42[0][2];

        gAnimalState.unk0[i].unkDA[1][0] = D_803A05D0_7B1C80[i].unk42[1][0];
        gAnimalState.unk0[i].unkDA[1][1] = D_803A05D0_7B1C80[i].unk42[1][1];
        gAnimalState.unk0[i].unkDA[1][2] = D_803A05D0_7B1C80[i].unk42[1][2];

        gAnimalState.unk0[i].behaviourFlags.unk3 = 1;
        gAnimalState.unk0[i].behaviourFlags.unk4 = 1;
        gAnimalState.unk0[i].behaviourFlags.unk5 = 1;
        gAnimalState.unk0[i].behaviourFlags.unk6 = 0u;

        gAnimalState.unk0[i].stompCycleLength = D_803A05D0_7B1C80[i].stompCycleLength;
        gAnimalState.unk0[i].stompEffectScale = D_803A05D0_7B1C80[i].stompEffectScale;

        if (gAnimalState.unk0[i].animalType == DESERT_FOX_ATTACKING) {
            gAnimalState.unk0[i].contactDamage = 4;
        } else if (gAnimalState.unk0[i].animalType == HARD_MOUSE) {
            gAnimalState.unk0[i].contactDamage = 2;
        }
    }
}

Animal2 *spawn_animal(s16 arg0, s16 arg1, s16 arg2, s16 rotation, s16 health, s16 id, s8 arg6) {
    Animal *sp1C;
    s16 slot;
    s16 i;

    for (i = 0; i < gNumAnimalsInLevel; i++) {
        if (gAnimalState.animals[i].animal->movementMode == MOVEMENT_MODE_DELETED) {
            break;
        }
    }

    if (i == gNumAnimalsInLevel) {
        slot = gNumAnimalsInLevel;
        gNumAnimalsInLevel++;
    } else {
        slot = i;
    }

    memset_bytes((u8*)&gAnimalState.animals[slot], 0, sizeof(Animal2));
    memset_bytes((u8*)&gAnimalState.unk4040[slot], 0, sizeof(Animal));

    // setup pointer
    gAnimalState.animals[slot].unk0 = &gAnimalState.unk0[id];
    gAnimalState.animals[slot].animal = &gAnimalState.unk4040[slot];

    D_803D5520 = &gAnimalState.animals[slot];
    D_803D5524 = &gAnimalState.unk0[id];

    sp1C = D_803D5530 = gAnimalState.animals[slot].animal;
    D_803D552C = sp1C;
    D_803D5528 = sp1C;
#ifdef __sgi
    if (!D_803D5528) {};
#endif
    if (slot == gCurrentAnimalIndex) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = slot;
    D_803D553A = 0;
    if (arg6 != 0) {
        sp1C->movementMode = MOVEMENT_MODE_NORMAL;
    } else if (health > 0) {
        sp1C->movementMode = MOVEMENT_MODE_INJURED;
    } else {
        sp1C->movementMode = MOVEMENT_MODE_DEACTIVATED;
    }

    D_803D552C->unk31A = 0;
    D_803D5530->yRotation = rotation;
    D_803D552C->heading = rotation;
    D_803D552C->gaitPhase = 0;
    D_803D552C->unk2F4 = 0;
    D_803D552C->gaitPhaseOffset = 0;
    D_803D552C->prevGaitPhaseOffset = 0;
    D_803D552C->state = 2; // not state..?
    D_803D5530->movementState = MOVEMENT_STATE_GROUND;
    D_803D5530->unk160 = 0;
    D_803D5530->unk16C = D_803D5524;
    D_803D5530->Info.health = MIN(health, D_803D5524->maxHealth);
    D_803D5530->unk4C.unk1B = 1;
    D_803D5530->unk4C.unk1C = 1;
    D_803D5530->unk4C.unk1D = 1;
    D_803D552C->ambientPhaseSeed = func_801282C4();

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
    D_803D552C->aiFlags = AI_FLAG_CAN_ATTACK | AI_FLAG_AVOID_NEUTRAL_ANIMALS | AI_FLAG_CAN_FLEE | AI_FLAG_HERD_OR_FOLLOW | AI_FLAG_COLLIDE_WITH_STATIC | AI_FLAG_ALLOW_STEEP_NAVIGATION | AI_FLAG_SCRIPTED_PLAYER_ENGAGEMENT;
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
    arg0->movementMode = MOVEMENT_MODE_DELETED;
}
