#include <ultra64.h>

#include "common.h"

// ========================================================
// definitions
// ========================================================

s32 func_8030400C_7156BC(Animal*, s16, s16, s32*, s32*);
s32 func_8032B1E0_73C890(Animal*, s16, s16, s32*, s32*);

// ========================================================
// .data
// ========================================================

// AnimalInteractionTable
u16 D_803A0510_7B1BC0[] = {
    518,    // b0000 0010 0000 0110
    47654,  // b1011 1010 0010 0110
    518,    // b0000 0010 0000 0110
    0,      // b0000 0000 0000 0000
    0,      // b0000 0000 0000 0000
    44582,  // b1010 1110 0010 0110 <= All animals are [5]
    512,    // b0000 0010 0000 0000
    512,    // b0000 0010 0000 0000
    512,    // b0000 0010 0000 0000
    0,      // b0000 0000 0000 0000
    512,    // b0000 0010 0000 0000
    0,      // b0000 0000 0000 0000
    512,    // b0000 0010 0000 0000
    518,    // b0000 0010 0000 0110
    514,    // b0000 0010 0000 0010
    0       // b0000 0000 0000 0000 <= EVO interacts with none?
};


// ========================================================
// .bss
// ========================================================

// ========================================================
// .text
// ========================================================

// ESA: func_800397B0
u8 func_8029B000_6AC6B0(s16 xPos, s16 zPos, s32 yPos, Animal *sourceAnimal, Animal *targetAnimal1, Animal **highestHitAnimal, s32 *yMax,
                                                                            Animal *targetAnimal2, Animal **lowestHitAnimal, s32 *yMin) {
    s32 collisionYMax;
    s32 collisionYMin;

    s32 pad[6];

    s32 zDist;
    s32 xDist;
    s32 minDist;
    s16 idx;
    Animal *animal;
    s32 maxDist;
    s32 isCollision;

    CollisionNode *var_s2;

    *yMax = -1;
    *yMin = -1;

    *highestHitAnimal = NULL;
    *lowestHitAnimal = NULL;

    maxDist = 0;
    minDist = 0x40000000;

    idx = (s16)(xPos >> 0xA) + ((s16) (zPos >> 0xA) * 5);
    var_s2 = D_803DA110[idx].next;

    if ((idx < 0) || (idx >= 40)) {
        // out of bounds
        return 0;
    }

    while (var_s2 != NULL) {
        animal = var_s2->animal;
        if (animal == sourceAnimal) {
            // ignore self-collisions
            var_s2 = var_s2->next;
            continue;
        }

        if ((sourceAnimal->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO)) && (sourceAnimal->unk365 == ATTACK_EVO_CHIP_1)) {
            if ((D_803A0510_7B1BC0[5] & (1 << (0xF - animal->unk16C->unk2))) == 0) {
                var_s2 = var_s2->next;
                continue;
            }
        } else {
            if (!(D_803A0510_7B1BC0[sourceAnimal->unk16C->unk2] & (1 << (0xF - animal->unk16C->unk2)) )) {
                var_s2 = var_s2->next;
                continue;
            }
        }

        if ((sourceAnimal->unk16C->unk2 == 5) && (animal == sourceAnimal->unk320)) {
            // being carried?
            var_s2 = var_s2->next;
            continue;
        }
        if (((animal->unk15C != 0) && (sourceAnimal == animal->owner)) ||
            ((sourceAnimal->unk15C != 0) && (animal == sourceAnimal->owner))) {
                var_s2 = var_s2->next;
                continue;
        }

        isCollision = 0;
        if ((animal->unk16C->unk2 == 5) && (sourceAnimal->unk16C->unk2 == 5)) {
            if ((animal->unk16C->unkE6 < sourceAnimal->unk16C->unkE6) || (func_8030AA08_71C0B8(animal, sourceAnimal) != 0) || (animal->unk366 == MOVEMENT_MODE_DEACTIVATED) || (sourceAnimal->unk366 == MOVEMENT_MODE_DEACTIVATED)) {
                if (animal->unk16C->unkE6 >= sourceAnimal->unk16C->unkE6) {
                    if (((xPos >= (animal->position.xPos.h - animal->unk34)) && (xPos < (animal->position.xPos.h + animal->unk34))) &&
                        ((zPos >= (animal->position.zPos.h - animal->unk34)) && (zPos < (animal->position.zPos.h + animal->unk34)))) {
                        isCollision = func_8030400C_7156BC(animal, xPos, zPos, &collisionYMax, &collisionYMin);
                    }
                } else if ((((sourceAnimal->unk162 != 1) || (sourceAnimal->unk68 != NULL)) && (sourceAnimal->yVelocity.w < FTOFIX32(-6.0))) || ((animal->unk366 == MOVEMENT_MODE_DEACTIVATED)) || (animal->unk366 == MOVEMENT_MODE_2)) {

                    xDist = xPos - animal->position.xPos.h;
                    zDist = zPos - animal->position.zPos.h;
                    if ((SQ(xDist) + SQ(zDist)) <= SQ(animal->unk30 * 2)) {
                        isCollision = 1;
                        collisionYMax = animal->position.yPos.w + (animal->unk42 << 0x10);
                        collisionYMin = animal->position.yPos.w;
                    }
                }
            }
        } else {
            if (((xPos >= (animal->position.xPos.h - animal->unk30)) && (xPos < (animal->position.xPos.h + animal->unk30))) &&
                ((zPos >= (animal->position.zPos.h - animal->unk32)) && (zPos < (animal->position.zPos.h + animal->unk32)))) {
                isCollision = func_8032B1E0_73C890(animal, xPos, zPos, &collisionYMax, &collisionYMin);
            }
        }

        if (isCollision) {
            animal->unk4C.unk19 = 1;
            if (animal == targetAnimal1) {
                if (collisionYMax >= maxDist) {
                    maxDist = collisionYMax;
                    *yMax = collisionYMax;
                    *highestHitAnimal = targetAnimal1;
                }
            } else if (animal == targetAnimal2) {
                if (minDist >= collisionYMin) {
                    minDist = collisionYMin;
                    *yMin = collisionYMin;
                    *lowestHitAnimal = targetAnimal2;
                }
            } else if (sourceAnimal == animal->unk68) {
                if (collisionYMin < minDist) {
                    minDist = collisionYMin;
                    *yMin = collisionYMin;
                    *lowestHitAnimal = animal;
                }
            } else if (sourceAnimal == animal->unk70) {
                if (maxDist < collisionYMax) {
                    maxDist = collisionYMax;
                    *yMax = collisionYMax;
                    *highestHitAnimal = animal;
                }
            } else if (yPos < ((collisionYMin + collisionYMax) >> 1)) {
                if (collisionYMin < minDist) {
                    minDist = collisionYMin;
                    *yMin = collisionYMin;
                    *lowestHitAnimal = animal;
                }
            } else if (maxDist < collisionYMax) {
                maxDist = collisionYMax;
                *yMax = collisionYMax;
                *highestHitAnimal = animal;
            }
        }
        var_s2 = var_s2->next;
    }

    return (*highestHitAnimal != NULL);
}

// unused?
s32 func_8029B56C_6ACC1C(s16 xPos, s16 zPos, s16 *height, struct063 terrain[73][129]) {
    s16 cell_offset_x;
    s16 cell_offset_z;

    s16 nw;
    s16 ne;
    s16 se;
    s16 sw;

    s32 changed;

    // Each grid cell is likely 64x64 game units.
    s16 a0 = xPos >> 6;
    s16 a1 = zPos >> 6;

    if ((a0 < 0) || (a0 >= 72) || (a1 < 0) || (a1 >= 128)) {
        // out of bounds
        return 0;
    }

    if (terrain[a0][a1].unk3 != 0) {
        // terrain is valid for height calculation
        sw = terrain[a0 + 0][a1 + 0].unk1 << 3;
        nw = terrain[a0 + 0][a1 + 1].unk1 << 3;
        ne = terrain[a0 + 1][a1 + 1].unk1 << 3;
        se = terrain[a0 + 1][a1 + 0].unk1 << 3;

        cell_offset_x = xPos & 0x3F; //  X offset within the cell (0 to 63)
        cell_offset_z = zPos & 0x3F; //  Z offset within the cell (0 to 63)

        if ((D_803C0740[a0][a1].unk4 & 1)) {
            if (cell_offset_x < cell_offset_z) {
                *height = sw + ((((ne - nw) * cell_offset_x) + ((nw - sw) * cell_offset_z)) >> 6);
            } else {
                *height = sw + ((((se - sw) * cell_offset_x) + ((ne - se) * cell_offset_z)) >> 6);
            }
        } else {
            if ((cell_offset_x + cell_offset_z) < 64) {
                *height = (((sw << 6) + ((se - sw) * cell_offset_x) + ((nw - sw) * cell_offset_z)) >> 6);
            } else {
                *height = (((ne << 6) + ((nw - ne) * (0x40 - cell_offset_x)) + ((se - nw) * (0x40 - cell_offset_z))) >> 6);
            }
        }
        changed = 1;
        // apply additional offset
        *height -= D_803E1D30[D_803C0740[a0][a1].unk3].unk2 << 3;
    } else {
        changed = 0;
    }

    return changed;
}
