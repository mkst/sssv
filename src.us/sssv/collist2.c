#include <ultra64.h>
#include "common.h"


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
        if (a->unk4C.unk25) {
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

void func_802DA90C_6EBFBC(Animal *arg0) {
    s16 temp_t6;
    s16 temp_t9;

    s16 i;

    s16 sp48[4];

    s16 temp_a2;
    s16 var_a1;
    s16 var_v0;
    s16 temp_a3;

    u8 var_t1;

    var_v0 = 0;
    var_t1 = 0;

    temp_a2 = arg0->xPos.h >> 0xA;
    temp_a3 = arg0->zPos.h >> 0xA;
    temp_t6 = (arg0->xPos.h >> 6) & 0xF;
    temp_t9 = (arg0->zPos.h >> 6) & 0xF;


    if ((temp_a2 >= 0) && (temp_a2 < 5) && (temp_a3 >= 0) && (temp_a3 < 8)) {
        sp48[var_v0++] = temp_a2 + (temp_a3 * 5);
    }
    if (temp_t6 < 4) {
        if ((temp_a2 > 0) && (temp_a2 < 6) && (temp_a3 >= 0) && (temp_a3 < 8)) {
            sp48[var_v0++] = (temp_a2 + (temp_a3 * 5)) - 1;
        }
    } else if ((temp_t6 > 11) && (temp_a2 < 4) && (temp_a2 >= -1) && (temp_a3 >= 0) && (temp_a3 < 8)) {
        var_t1 = 1;
        sp48[var_v0++] = temp_a2 + (temp_a3 * 5) + 1;
    }
    if (temp_t9 < 4) {
        if ((temp_a3 > 0) && (temp_a3 < 9) && (temp_a2 >= 0) && (temp_a2 < 5)) {
            sp48[var_v0++] = (temp_a2 + (temp_a3 * 5)) - 5;
        }
    } else if ((temp_t9 > 11) && (temp_a3 < 7) && (temp_a3 >= -1) && (temp_a2 >= 0) && (temp_a2 < 5)) {
        sp48[var_v0++] = temp_a2 + (temp_a3 * 5) + 5;
        var_t1 = (var_t1 | 2);
    }

    if (var_v0 == 3) {
        switch (var_t1) {
        case 0:
            sp48[var_v0++] = (temp_a2 + (temp_a3 * 5)) - 6;
            break;
        case 1:
            sp48[var_v0++] = (temp_a2 + (temp_a3 * 5)) - 4;
            break;
        case 2:
            sp48[var_v0++] = temp_a2 + (temp_a3 * 5) + 4;
            break;
        case 3:
            sp48[var_v0++] = temp_a2 + (temp_a3 * 5) + 6;
            break;
        }
    }


    for (;var_v0 < 4; var_v0++) {
        sp48[var_v0] = 0x7FFF; // fill remaining slots
    }

    var_a1 = 0;
    for (; var_a1 < 4; var_a1++) {
        if (sp48[var_a1] != arg0->unk114[var_a1]) {
            break;
        }
    }

    if (var_a1 != 4) {
        func_802DAD18_6EC3C8(arg0); // delete

        for (var_a1 = 0; var_a1 < 4; var_a1++) {
            if (sp48[var_a1] != 0x7FFF) { // used

                arg0->unk114[var_a1] = sp48[var_a1];

                arg0->unk11C[var_a1].next = D_803DA110[sp48[var_a1]].next;
                D_803DA110[sp48[var_a1]].next = &arg0->unk11C[var_a1];
                arg0->unk11C[var_a1].prev = &D_803DA110[sp48[var_a1]];
                if (arg0->unk11C[var_a1].next != NULL) {
                    arg0->unk11C[var_a1].next->prev = &arg0->unk11C[var_a1];
                }

                arg0->unk11C[var_a1].animal = arg0;
            }
        }
    }
}

// delete_objects
void func_802DAD18_6EC3C8(Animal *arg0) {
    struct065 *tmp;
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

void func_802DADA0_6EC450(Animal *arg0) {
    Animal *temp_v0;
    Animal **phi_v0;
    s16 i;

    if (arg0->unk16C->unk80.unk11) {
        phi_v0 = &D_803DA2F0;
        arg0->unk26D = 1;
    } else {
        phi_v0 = &D_803DA2F4;
        arg0->unk26D = 2;
    }

    if (arg0->unk16C->objectType < OB_TYPE_ANIMAL_OFFSET) {
        arg0->unk198 = *phi_v0;
        *phi_v0 = arg0;
    }

    for (i = 0; i < 4; i++) {
        arg0->unk114[i] = 0x7FFF;
        arg0->unk11C[i].next = 0;
        arg0->unk11C[i].prev = 0;
        arg0->unk11C[i].animal = 0;
    }

    func_802DA90C_6EBFBC(arg0);
}

void func_802DAE5C_6EC50C(struct071 *obj) {
    struct071 **o;

    func_802DAD18_6EC3C8(obj);
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
            rmonPrintf("collist2. Object has been deleted but was not in list. %d.\n", obj->unk26D);
            rmonPrintf("psMoveObj %p ID %d XYZ %d %d %d\n", obj, obj->unk16C->objectType, obj->xPos.h, obj->zPos.h, obj->yPos.h);
            SSSV_ASSERT(FALSE, "../src/collist2.c", 436);
        } else {
            *o = obj->unk198;
        }
    }
    obj->unk198 = NULL;
    obj->unk26D = 0U;
}

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
void func_802DAFAC_6EC65C(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd) {
    struct071 *obj;
    s32 x0 = xStart;
    s32 y0 = yStart;
    s32 x1 = xEnd;
    s32 y1 = yEnd;

    for (obj = D_803DA2F4; obj != NULL; obj = obj->unk198) {
        if (((s16)((x0 + x1 + 1) << 6) >= obj->xPos.h) &&
            ((s16)((x0         ) << 6) <= obj->xPos.h) &&
            ((s16)((y0 + y1 + 1) << 6) >= obj->zPos.h) &&
            ((s16)((y0         ) << 6) <= obj->zPos.h)) {
              obj->unk4C.unk26 = 1;
        }
    }
}
