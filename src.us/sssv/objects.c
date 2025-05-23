#include <ultra64.h>
#include "common.h"


// ESA: func_8004D0E8
s32 load_objects(void) {
    ObjectData *obj;
    s16 i;

    bzero_sssv(&D_801E9EB8, sizeof(D_801E9EB8));

    D_801E9EB8.unk0 = D_803A8528_7B9BD8;
    D_801E9EB8.total= 247;

    obj = D_801E9EB8.unk0;
    for (i = 0; i < 247; i++) {
        if ((obj->collision != NULL) && (((s32)obj->collision & 0xF0000000) == 0)) {
            obj->collision = D_801D9E74 + SEGMENT_OFFSET((s32)obj->collision);
        }
        obj++;
    }

    return 1;
}

// ESA: func_8004D130
struct071 *func_802C93E8_6DAA98(u16 arg0) {
    return &D_801E9EB8.objects[MAX_OBJECTS - arg0];
}

// ESA: func_8004D160
void func_802C941C_6DAACC(void) {
    s16 i;

    for (i = 0; i < 170; i++) {
        D_801E9EB8.objectsPtr[i] = &D_801E9EB8.objects[i];
    }
    D_801E9EB8.unk1A110 = MAX_OBJECTS;
    D_801E9EB8.unk1A112 = MAX_OBJECTS;
    D_801E9EB8.used = 0;
}

// ESA: func_8004D1B8
struct071 *func_802C9488_6DAB38(void) {
    struct071 *obj;

    if (D_801E9EB8.used > MAX_OBJECTS) {
        return NULL;
    }
    obj = D_801E9EB8.objectsPtr[D_801E9EB8.unk1A110--];

    if (D_801E9EB8.unk1A110 < 0) {
        D_801E9EB8.unk1A110 = MAX_OBJECTS;
    }
    D_801E9EB8.used++;

    obj->unk26C = 0; // is initialised?
    return obj;
}

// ESA: func_8004D228
void func_802C9500_6DABB0(struct071 *obj) {
    D_801E9EB8.objectsPtr[D_801E9EB8.unk1A112] = obj;

    // regalloc fix
    do {
        D_801E9EB8.unk1A112--;
    } while ((s64)0);

    if (D_801E9EB8.unk1A112 < 0) {
        D_801E9EB8.unk1A112 = MAX_OBJECTS;
    }
    D_801E9EB8.used--;
}

struct071 *spawn_object(u8 id, s16 x, s16 z, s16 y, s32 xVel, s32 zVel, s32 yVel, s16 zRotation, s16 yRotation, u16 scale) {
    s16 temp_v1;
    struct071 *obj;
    ObjectData *objData;
    struct035 *foo;

    obj = func_802C9488_6DAB38();
    if (obj == NULL) {
        return NULL;
    }

    bzero_sssv((u8 *) obj, sizeof(struct071));

    objData = &D_801E9EB8.unk0[id]; // pointer to 'raw' object data?

    foo = (struct035 *)objData;

    obj->unk16C = foo;

    if (obj->unk16C->unk70 != 0) {
        scale = obj->unk16C->unk70;
    }
    // help
    obj->unk40 = scale;

    // fixes regalloc somehow...
    obj->unk4C.unk1C = foo->unk82.unk4 & 0xFFFFFFFF;
    obj->unk4C.unk1D = foo->unk82.unk5 & 0xFFFFFFFF;
    obj->unk4C.unk1B = foo->unk82.unk3 & 0xFFFFFFFF;

    obj->unk14C = foo->unk8A;
    obj->unk164 = foo->unk89;

    if (foo->unk82.unk7) {
        temp_v1 = func_8031124C_7228FC(x, z) >> 0x10;
        if (y < temp_v1) {
            y = temp_v1;
        }
    }
    temp_v1 = func_80310F58_722608(x, z) >> 0x10;
    if (temp_v1 == 0x4000) {
        obj->unk160 = 0;
    } else if (y >= temp_v1) {
        obj->unk160 = 2;
    } else {
        obj->unk160 = 1;
    }

    obj->unk0 = 1;
    obj->unk17E = x;
    obj->unk180 = z;
    obj->unk182 = y;
    obj->unk1C.w = xVel;
    obj->unk20.w = zVel;
    obj->unk24.w = yVel;
    obj->zRotation = zRotation;
    obj->yRotation = yRotation;
    obj->unk4C.unk19 = 1;

    obj->unk46 = obj->unk16C->mass;

    obj->unk114[0] = 0x7FFF;
    obj->unk114[1] = 0x7FFF;
    obj->unk114[2] = 0x7FFF;
    obj->unk114[3] = 0x7FFF;

    func_802C9BA4_6DB254(obj);
    if ((obj->unk16C->unk15 == 4) && (((zRotation >= 225) && (zRotation < 315)) || ((zRotation >= 45) && (zRotation < 135)))) {
        y = (y + obj->unk32) - (obj->unk42 >> 1);
    }
    obj->position.xPos.h = x;
    obj->position.zPos.h = z;
    obj->position.yPos.h = y;
    obj->unk10.w = x << 0x10;
    obj->unk14.w = z << 0x10;
    obj->unk18 = y << 0x10;

    func_802DADA0_6EC450((Animal*)obj);
    func_802F5C60_707310((Animal*)obj);

    obj->unk162 = 3;

    return obj;
}

void func_802C9834_6DAEE4(void) {
    reset_objects_state();
    init_and_spawn_evo_microchip();
}

// unused, dupe of func_802C9834_6DAEE4
void func_802C985C_6DAF0C(void) {
    reset_objects_state();
    init_and_spawn_evo_microchip();
}

// ESA: func_8004D558
void reset_objects_state(void) {
    u16 i;

    func_802DAF5C_6EC60C();
    func_802C941C_6DAACC();

    for (i = 0; i <= MAX_OBJECTS; i++) {
        bzero_sssv(&D_801E9EB8.objects[i], sizeof(struct071));
    }
    func_8029F3CC_6B0A7C();
}

// add_reference_to_object
// ESA: func_8004D5C8
void func_802C9900_6DAFB0(struct071 *parent, struct071 *child, u8 idx) {
    parent->unk24C[idx] = child;
}

// update_hitbox_after_rotation?
// ESA: func_8004D5DC
void func_802C9918_6DAFC8(Animal *arg0, s16 newZRotation, s16 newYRotation) {
    s16 width;
    s16 depth;
    s16 height;

    s16 tempSwap;
    s32 prevQuadrant;
    s32 newQuadrant;

    if (arg0->unk16C->unk15 != 4) {
        arg0->yRotation = newYRotation;
        arg0->zRotation = newZRotation;
        return;
    }

    prevQuadrant = ((s16) ((newZRotation + 45) / 90));
    newQuadrant  = ((s16) ((arg0->zRotation + 45) / 90));

    arg0->yRotation = newYRotation;
    arg0->zRotation = newZRotation;

    if ((prevQuadrant & 1) ^ (newQuadrant & 1)) {
        if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
            ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
            arg0->position.yPos.h = (arg0->position.yPos.h - arg0->unk30) + (arg0->unk42 >> 1);
        } else {
            arg0->position.yPos.h = (arg0->position.yPos.h - arg0->unk32) + (arg0->unk42 >> 1);
        }
    }

    depth = arg0->unk16C->unk72;
    width = arg0->unk16C->unk74;
    height = arg0->unk16C->unk7A;

    if (((arg0->zRotation >= 45) && (arg0->zRotation < 135)) ||
        ((arg0->zRotation >= 225) && (arg0->zRotation < 315))) {
        tempSwap = width;
        width = (height / 2);
        height = tempSwap << 1;
    }
    if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
        ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
        tempSwap = depth;
        depth = width;
        width = tempSwap;
    }

    arg0->unk30 = depth;
    arg0->unk32 = width;
    arg0->unk42 = height;

    arg0->unk30 = ((s64)arg0->unk30 * arg0->unk40) >> 0xB;
    arg0->unk32 = ((s64)arg0->unk32 * arg0->unk40) >> 0xB;
    arg0->unk42 = ((s64)arg0->unk42 * arg0->unk40) >> 0xB;
}

// ESA: func_8004D86C
void func_802C9BA4_6DB254(Animal *arg0) {
    s16 tempSwap;
    s16 i;
    s16 width;
    s16 depth;
    s16 height;

    if (arg0->unk40 == 0) {
        arg0->unk40 = 1 << 11; // 0x800
    }

    width = arg0->unk16C->unk72;
    depth = arg0->unk16C->unk74;
    height = arg0->unk16C->unk7A;

    if ((arg0->unk16C->unk15 == 4)) {
        if (((arg0->zRotation > 45)  && (arg0->zRotation <= 135)) ||
            ((arg0->zRotation > 225) && (arg0->zRotation <= 315))) {
            tempSwap = depth;
            depth = height / 2;
            height = tempSwap * 2;
        }
    }

    if (((arg0->yRotation > 45)  && (arg0->yRotation <= 135)) ||
        ((arg0->yRotation > 225) && (arg0->yRotation <= 315))) {
        tempSwap = width;
        width = depth;
        depth = tempSwap;
    }

    arg0->unk30 = width;
    arg0->unk32 = depth;
    arg0->unk42 = height;

    arg0->unk34 = arg0->unk16C->unk76;
    arg0->unk36 = arg0->unk16C->unk78;

    // fixed-point scaling (0x800 => 1.0)
    arg0->unk34 = ((s64)arg0->unk34 * arg0->unk40) >> 11;
    arg0->unk36 = ((s64)arg0->unk36 * arg0->unk40) >> 11;

    if ((arg0->unk16C->objectType >= 128) && ((arg0->unk366 == MOVEMENT_MODE_DEACTIVATED) || (arg0->unk366 == MOVEMENT_MODE_2))) {
        // override height?
        arg0->unk42 = arg0->unk16C->unkBC;
    }

    arg0->unk44 = arg0->unk46;

    arg0->unk4C.pad0 = arg0->unk16C->mass / 2;

    arg0->unk30 = ((s64)arg0->unk30 * arg0->unk40) >> 11;
    arg0->unk32 = ((s64)arg0->unk32 * arg0->unk40) >> 11;

    arg0->unk42 = ((s64)arg0->unk42 * arg0->unk40) >> 11;
    arg0->unk44 = ((s64)arg0->unk44 * arg0->unk40) >> 11;

    arg0->unk4C.pad0 = ((s64)arg0->unk4C.pad0 * arg0->unk40) >> 11;

    for (i = 0; i < 5; i++) {
        arg0->unk74[i].pos.xPos.w = arg0->unk16C->unk20[i][0] << 0x10;
        arg0->unk74[i].pos.zPos.w = arg0->unk16C->unk20[i][1] << 0x10;
        arg0->unk74[i].pos.yPos.w = arg0->unk16C->unk20[i][2] << 0x10;
        arg0->unk74[i].unkC       = arg0->unk16C->unk20[i][3];

        arg0->unk74[i].pos.xPos.w = ((s64)arg0->unk74[i].pos.xPos.w * arg0->unk40) >> 11;
        arg0->unk74[i].pos.zPos.w = ((s64)arg0->unk74[i].pos.zPos.w * arg0->unk40) >> 11;
        arg0->unk74[i].pos.yPos.w = ((s64)arg0->unk74[i].pos.yPos.w * arg0->unk40) >> 11;
        arg0->unk74[i].unkC       = ((s64)arg0->unk74[i].unkC * arg0->unk40) >> 11;
    }
}
