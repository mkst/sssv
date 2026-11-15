#include <ultra64.h>
#include "common.h"


// ========================================================
// .bss
// ========================================================

CollisionNode gCollisionGridHeads[40]; // gridCollisionLists

Entity *D_803DA2F0;        // TODO: static once func_8029F7D4_6B0E84 is matched
static Entity *D_803DA2F4;

// ========================================================
// .text
// ========================================================

// ESA: func_800627BC
void func_802DA7F0_6EBEA0(void) {
    void (*func)(void *);
    Entity *e;
    Entity *tmp;

    e = D_803DA2F0;
    while (e != NULL) {
        func = e->unk16C->updateCallback;
        if (func != NULL) {
            func(e);
        }
        func_802FB270_70C920(e);
        tmp = e;
        if (tmp->unk26C != 0) {
            e = e->nextCollisionUpdateEntity;
            unregister_entity_collision(tmp);
            func_802C9500_6DABB0(tmp);
        } else {
            update_entity_collision_grid(tmp);
            e = e->nextCollisionUpdateEntity;
        }
    }

    e = D_803DA2F4;
    while (e != NULL) {
        func = e->unk16C->updateCallback;
        if (func != NULL) {
            func(e);
        }
        if (e->unk4C.unk19) {
            func_802FB270_70C920(e);
            tmp = e;
            if (tmp->unk26C != 0) {
                e = e->nextCollisionUpdateEntity;
                unregister_entity_collision(tmp);
                func_802C9500_6DABB0(tmp);
            } else {
                update_entity_collision_grid(tmp);
                e = e->nextCollisionUpdateEntity;
            }
        } else {
            e = e->nextCollisionUpdateEntity;
        }
    }
}

// ESA: func_800628F4
// update_animal_collision_grid
void update_entity_collision_grid(Entity *arg0) {
    s16 subCellX;
    s16 subCellZ;

    s16 newGridCells[5];

    s16 gridX;
    s16 matchingCells;
    s16 cellCount;
    s16 gridZ;

    u8 cornerFlag;

    cellCount = 0;
    cornerFlag = 0;

    gridX = arg0->position.xPos.h >> 0xA;
    gridZ = arg0->position.zPos.h >> 0xA;
    subCellX = (arg0->position.xPos.h >> 6) & 0xF;
    subCellZ = (arg0->position.zPos.h >> 6) & 0xF;

    if ((gridX >= 0) && (gridX < 5) && (gridZ >= 0) && (gridZ < 8)) {
        newGridCells[cellCount++] = gridX + (gridZ * 5);
    }
    if (subCellX < 4) {
        if ((gridX > 0) && (gridX < 6) && (gridZ >= 0) && (gridZ < 8)) {
            newGridCells[cellCount++] = (gridX + (gridZ * 5)) - 1;
        }
    } else if ((subCellX > 11) && (gridX < 4) && (gridX >= -1) && (gridZ >= 0) && (gridZ < 8)) {
        cornerFlag = 1;
        newGridCells[cellCount++] = gridX + (gridZ * 5) + 1;
    }
    if (subCellZ < 4) {
        if ((gridZ > 0) && (gridZ < 9) && (gridX >= 0) && (gridX < 5)) {
            newGridCells[cellCount++] = (gridX + (gridZ * 5)) - 5;
        }
    } else if ((subCellZ > 11) && (gridZ < 7) && (gridZ >= -1) && (gridX >= 0) && (gridX < 5)) {
        newGridCells[cellCount++] = gridX + (gridZ * 5) + 5;
        cornerFlag = (cornerFlag | 2);
    }

    if (cellCount == 3) {
        switch (cornerFlag) {
        case 0:
            newGridCells[cellCount++] = (gridX - 1) + ((gridZ - 1) * 5);
            break;
        case 1:
            newGridCells[cellCount++] = (gridX + 1) + ((gridZ - 1) * 5);
            break;
        case 2:
            newGridCells[cellCount++] = (gridX - 1) + ((gridZ + 1) * 5);
            break;
        case 3:
            newGridCells[cellCount++] = (gridX + 1) + ((gridZ + 1) * 5);
            break;
        }
    }

    for (;cellCount < 4; cellCount++) {
        newGridCells[cellCount] = 0x7FFF; // fill remaining slots
    }

    matchingCells = 0;
    for (; matchingCells < 4; matchingCells++) {
        if (newGridCells[matchingCells] != arg0->collisionGridCells[matchingCells]) {
            break;
        }
    }

    if (matchingCells != 4) {
        remove_collision_list(arg0); // delete

        for (matchingCells = 0; matchingCells < 4; matchingCells++) {
            if (newGridCells[matchingCells] != 0x7FFF) { // used

                arg0->collisionGridCells[matchingCells] = newGridCells[matchingCells];

                arg0->collisionGridNodes[matchingCells].next = gCollisionGridHeads[newGridCells[matchingCells]].next;
                gCollisionGridHeads[newGridCells[matchingCells]].next = &arg0->collisionGridNodes[matchingCells];
                arg0->collisionGridNodes[matchingCells].prev = &gCollisionGridHeads[newGridCells[matchingCells]];
                if (arg0->collisionGridNodes[matchingCells].next != NULL) {
                    arg0->collisionGridNodes[matchingCells].next->prev = &arg0->collisionGridNodes[matchingCells];
                }

                arg0->collisionGridNodes[matchingCells].animal = (Animal*)arg0;
            }
        }
    }
}

// ESA: func_80062CB4
void remove_collision_list(Entity *arg0) {
    CollisionNode *tmp;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (arg0->collisionGridCells[i] != 0x7FFF) {
            tmp = &arg0->collisionGridNodes[i];

            tmp->prev->next = tmp->next;
            if (tmp->next != 0) {
                tmp->next->prev = tmp->prev;
            }

            tmp->prev = NULL;
            tmp->next = NULL;
            tmp->animal = NULL;

            arg0->collisionGridCells[i] = 0x7FFF;
        }
    }
}

// ESA: func_80062D38
void register_entity_collision(Entity *arg0) {
    Entity **entity;
    s16 i;

    if (arg0->unk16C->behaviourFlags.unk1) {
        entity = &D_803DA2F0;
        arg0->collisionUpdateListId = 1;
    } else {
        entity = &D_803DA2F4;
        arg0->collisionUpdateListId = 2;
    }

    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        arg0->nextCollisionUpdateEntity = *entity;
        *entity = arg0;
    }

    for (i = 0; i < 4; i++) {
        arg0->collisionGridCells[i] = 0x7FFF;
        arg0->collisionGridNodes[i].next = 0;
        arg0->collisionGridNodes[i].prev = 0;
        arg0->collisionGridNodes[i].animal = NULL;
    }

    update_entity_collision_grid(arg0);
}

// ESA: func_80062E04
void unregister_entity_collision(Entity *obj) {
    Entity **o;

    remove_collision_list(obj);
    switch (obj->collisionUpdateListId) {
    case 1:
        o = &D_803DA2F0;
        break;
    case 2:
        o = &D_803DA2F4;
        break;
    default:
        o = NULL;
        break;
    }

    if (o != NULL) {

        while ((*o != NULL) && (*o != obj)) {
            o = &(*o)->nextCollisionUpdateEntity;
        }

        if (*o == NULL) {
            osSyncPrintf("collist2. Object has been deleted but was not in list. %d.\n", obj->collisionUpdateListId);
            osSyncPrintf("psMoveObj %p ID %d XYZ %d %d %d\n", obj, obj->unk16C->objectType, obj->position.xPos.h, obj->position.zPos.h, obj->position.yPos.h);
            SSSV_ASSERT(FALSE, "../src/collist2.c", 436);
        } else {
            *o = obj->nextCollisionUpdateEntity;
        }
    }
    obj->nextCollisionUpdateEntity = NULL;
    obj->collisionUpdateListId = 0;
}

// ESA: func_80062EB0
void reset_collision_lists(void) {
    s16 i;

    for (i = 0; i < 40; i++) {
        gCollisionGridHeads[i].next = NULL;
        gCollisionGridHeads[i].prev = NULL;
        gCollisionGridHeads[i].animal = NULL;
    }

    D_803DA2F0 = NULL;
    D_803DA2F4 = NULL;
}

// update_object_floor_collision ?
// ESA: func_80062EF4
void func_802DAFAC_6EC65C(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd) {
    Entity *obj;
    s32 x0 = xStart;
    s32 y0 = yStart;
    s32 x1 = xEnd;
    s32 y1 = yEnd;

    for (obj = D_803DA2F4; obj != NULL; obj = obj->nextCollisionUpdateEntity) {
        if (((s16)((x0 + x1 + 1) << 6) >= obj->position.xPos.h) &&
            ((s16)((x0         ) << 6) <= obj->position.xPos.h) &&
            ((s16)((y0 + y1 + 1) << 6) >= obj->position.zPos.h) &&
            ((s16)((y0         ) << 6) <= obj->position.zPos.h)) {
            obj->unk4C.unk19 = 1;
        }
    }
}
