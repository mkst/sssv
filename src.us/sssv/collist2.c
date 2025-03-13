#include <ultra64.h>
#include "common.h"


// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

CollisionNode D_803DA110[40]; // gridCollisionLists

Animal *D_803DA2F0;
static Animal *D_803DA2F4; // object?

// ========================================================
// .text
// ========================================================

// ESA: func_800627BC
void func_802DA7F0_6EBEA0(void) {
    void (*func)(void *);
    Animal *a;
    Animal *tmp;

    a = D_803DA2F0;
    while (a != NULL) {
        func = a->unk16C->unk84;
        if (func != NULL) {
            func(a);
        }
        func_802FB270_70C920(a);
        tmp = a;
        if (tmp->unk26C != 0) {
            a = a->unk198;
            func_802DAE5C_6EC50C(tmp);
            func_802C9500_6DABB0(tmp);
        } else {
            func_802DA90C_6EBFBC(tmp);
            a = a->unk198;
        }
    }

    a = D_803DA2F4;
    while (a != NULL) {
        func = a->unk16C->unk84;
        if (func != NULL) {
            func(a);
        }
        if (a->unk4C.unk19) {
            func_802FB270_70C920(a);
            tmp = a;
            if (tmp->unk26C != 0) {
                a = a->unk198;
                func_802DAE5C_6EC50C(tmp);
                func_802C9500_6DABB0(tmp);
            } else {
                func_802DA90C_6EBFBC(tmp);
                a = a->unk198;
            }
        } else {
            a = a->unk198;
        }
    }
}

// ESA: func_800628F4
// update_animal_collision_grid
void func_802DA90C_6EBFBC(Animal *arg0) {
    s16 subCellX;
    s16 subCellZ;

    s16 i;

    s16 newGridCells[4];

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
            newGridCells[cellCount++] = (gridX + (gridZ * 5)) - 6;
            break;
        case 1:
            newGridCells[cellCount++] = (gridX + (gridZ * 5)) - 4;
            break;
        case 2:
            newGridCells[cellCount++] = gridX + (gridZ * 5) + 4;
            break;
        case 3:
            newGridCells[cellCount++] = gridX + (gridZ * 5) + 6;
            break;
        }
    }

    for (;cellCount < 4; cellCount++) {
        newGridCells[cellCount] = 0x7FFF; // fill remaining slots
    }

    matchingCells = 0;
    for (; matchingCells < 4; matchingCells++) {
        if (newGridCells[matchingCells] != arg0->unk114[matchingCells]) {
            break;
        }
    }

    if (matchingCells != 4) {
        remove_collision_list(arg0); // delete

        for (matchingCells = 0; matchingCells < 4; matchingCells++) {
            if (newGridCells[matchingCells] != 0x7FFF) { // used

                arg0->unk114[matchingCells] = newGridCells[matchingCells];

                arg0->unk11C[matchingCells].next = D_803DA110[newGridCells[matchingCells]].next;
                D_803DA110[newGridCells[matchingCells]].next = &arg0->unk11C[matchingCells];
                arg0->unk11C[matchingCells].prev = &D_803DA110[newGridCells[matchingCells]];
                if (arg0->unk11C[matchingCells].next != NULL) {
                    arg0->unk11C[matchingCells].next->prev = &arg0->unk11C[matchingCells];
                }

                arg0->unk11C[matchingCells].animal = arg0;
            }
        }
    }
}

// ESA: func_80062CB4
void remove_collision_list(Animal *arg0) {
    CollisionNode *tmp;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (arg0->unk114[i] != 0x7FFF) {
            tmp = &arg0->unk11C[i];

            tmp->prev->next = tmp->next;
            if (tmp->next != 0) {
                tmp->next->prev = tmp->prev;
            }

            tmp->prev = NULL;
            tmp->next = NULL;
            tmp->animal = NULL;

            arg0->unk114[i] = 0x7FFF;
        }
    }
}

// ESA: func_80062D38
void func_802DADA0_6EC450(Animal *arg0) {
    Animal **animal;
    s16 i;

    if (arg0->unk16C->unk82.unk1) {
        animal = &D_803DA2F0;
        arg0->unk26D = 1;
    } else {
        animal = &D_803DA2F4;
        arg0->unk26D = 2;
    }

    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        arg0->unk198 = *animal;
        *animal = arg0;
    }

    for (i = 0; i < 4; i++) {
        arg0->unk114[i] = 0x7FFF;
        arg0->unk11C[i].next = 0;
        arg0->unk11C[i].prev = 0;
        arg0->unk11C[i].animal = 0;
    }

    func_802DA90C_6EBFBC(arg0);
}

// ESA: func_80062E04
void func_802DAE5C_6EC50C(struct071 *obj) {
    struct071 **o;

    remove_collision_list(obj);
    switch (obj->unk26D) {
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
            o = &(*o)->unk198;
        }

        if (*o == NULL) {
            osSyncPrintf("collist2. Object has been deleted but was not in list. %d.\n", obj->unk26D);
            osSyncPrintf("psMoveObj %p ID %d XYZ %d %d %d\n", obj, obj->unk16C->objectType, obj->position.xPos.h, obj->position.zPos.h, obj->position.yPos.h);
            SSSV_ASSERT(FALSE, "../src/collist2.c", 436);
        } else {
            *o = obj->unk198;
        }
    }
    obj->unk198 = NULL;
    obj->unk26D = 0U;
}

// ESA: func_80062EB0
void func_802DAF5C_6EC60C(void) {
    s16 i;

    for (i = 0; i < 40; i++) {
        D_803DA110[i].next = NULL;
        D_803DA110[i].prev = NULL;
        D_803DA110[i].animal = NULL;
    }

    D_803DA2F0 = NULL;
    D_803DA2F4 = NULL;
}

// update_object_floor_collision ?
// ESA: func_80062EF4
void func_802DAFAC_6EC65C(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd) {
    struct071 *obj;
    s32 x0 = xStart;
    s32 y0 = yStart;
    s32 x1 = xEnd;
    s32 y1 = yEnd;

    for (obj = D_803DA2F4; obj != NULL; obj = obj->unk198) {
        if (((s16)((x0 + x1 + 1) << 6) >= obj->position.xPos.h) &&
            ((s16)((x0         ) << 6) <= obj->position.xPos.h) &&
            ((s16)((y0 + y1 + 1) << 6) >= obj->position.zPos.h) &&
            ((s16)((y0         ) << 6) <= obj->position.zPos.h)) {
              obj->unk4C.unk19 = 1;
        }
    }
}
