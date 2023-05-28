#include <ultra64.h>
#include "common.h"


// ESA: func_8004D0E8
s32 func_802C9340_6DA9F0(void) {
    struct068 *phi_v0;
    s16 i;

    bzero_sssv(&D_801E9EB8, sizeof(D_801E9EB8));

    D_801E9EB8.unk0 = D_803A8528_7B9BD8;

    D_80203FC4 = 247; // 247 objects

    phi_v0 = D_801E9EB8.unk0;
    for (i = 0; i < 247; i++) {
        if ((phi_v0->unk18 != 0) && (((s32)phi_v0->unk18 & 0xF0000000) == 0)) {
            phi_v0->unk18 = D_801D9E74 + SEGMENT_OFFSET((s32)phi_v0->unk18);
        }
        phi_v0 += 1;
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
        D_801E9EB8.unk19E64[i] = &D_801E9EB8.objects[i];
    }
    D_801E9EB8.unk1A110 = MAX_OBJECTS;
    D_801E9EB8.unk1A112 = MAX_OBJECTS;
    D_801E9EB8.unk1A114 = 0;
}

// ESA: func_8004D1B8
struct071 *func_802C9488_6DAB38(void) {
    struct071 *obj;

    if (D_801E9EB8.unk1A114 > MAX_OBJECTS) {
        return NULL;
    }
    obj = D_80203D1C[D_801E9EB8.unk1A110--];

    if (D_801E9EB8.unk1A110 < 0) {
        D_801E9EB8.unk1A110 = MAX_OBJECTS;
    }
    D_801E9EB8.unk1A114 += 1; // used?

    obj->unk26C = 0; // initialised?
    return obj;
}

// ESA: func_8004D228
void func_802C9500_6DABB0(struct071 *obj) {
    D_80203D1C[D_801E9EB8.unk1A112] = obj;

    // regalloc fix
    do {
        D_801E9EB8.unk1A112--;
    } while ((s64)0);

    if (D_801E9EB8.unk1A112 < 0) {
        D_801E9EB8.unk1A112 = MAX_OBJECTS;
    }
    D_801E9EB8.unk1A114--;
}

#ifdef NON_MATCHING
struct071 *spawn_object(u8 id, s16 x, s16 z, s16 y, s32 xVel, s32 zVel, s32 yVel, s16 zRotation, s16 yRotation, u16 scale) {
    s16 temp_v1;
    struct071 *obj;
    struct068 *tmp;
    struct035 *tmp2;

    obj = func_802C9488_6DAB38();
    if (obj == 0) {
        return NULL;
    }

    bzero_sssv((u8 *) obj, sizeof(struct071));

    tmp = &D_801E9EB8.unk0[id]; // this is wrong
    obj->unk16C = tmp2 = (struct035 *)tmp;

    if (obj->unk16C->unk70 != 0) {
        scale = obj->unk16C->unk70;
    }
    // help
    obj->unk40 = scale;

    obj->unk4C.unk1C = tmp2->unk82.unk4;
    obj->unk4C.unk1D = tmp2->unk82.unk5;
    obj->unk4C.unk1B = tmp2->unk82.unk3;

    obj->unk14C = tmp2->unk8A;
    obj->unk164 = tmp2->unk89;

    if (tmp2->unk82.unk7) {
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

    obj->unk114 = 0x7FFF;
    obj->unk116 = 0x7FFF;
    obj->unk118 = 0x7FFF;
    obj->unk11A = 0x7FFF;

    func_802C9BA4_6DB254(obj);
    if ((obj->unk16C->unk15 == 4) && (((zRotation >= 225) && (zRotation < 315)) || ((zRotation >= 45) && (zRotation < 135)))) {
        y = (y + obj->unk32) - (obj->unk42 >> 1);
    }
    obj->xPos.h = x;
    obj->zPos.h = z;
    obj->yPos.h = y;
    obj->unk10.w = x << 0x10;
    obj->unk14.w = z << 0x10;
    obj->unk18 = y << 0x10;

    func_802DADA0_6EC450(obj);
    func_802F5C60_707310(obj);
    obj->unk162 = 3;
    return obj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sssv/objects/spawn_object.s")
#endif

void func_802C9834_6DAEE4(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

void func_802C985C_6DAF0C(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

// ESA: func_8004D558
void func_802C9884_6DAF34(void) {
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

// ESA: func_8004D5DC
void func_802C9918_6DAFC8(Animal *arg0, s16 arg1, s16 arg2) {
    s16 var_t0;
    s16 var_t1;
    s16 var_t2;

    s16 temp_t5;
    s32 temp_t8;
    s32 temp_t9;

    if (arg0->unk16C->unk15 != 4) {
        arg0->yRotation = arg2;
        arg0->zRotation = arg1;
        return;
    }

    temp_t8 = ((s16) ((arg1 + 45) / 90));
    temp_t9 = ((s16) ((arg0->zRotation + 45) / 90));

    arg0->yRotation = arg2;
    arg0->zRotation = arg1;

    if ((temp_t8 & 1) ^ (temp_t9 & 1)) {
        if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
            ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
            arg0->yPos.h = (arg0->yPos.h - arg0->unk30) + (arg0->unk42 >> 1);
        } else {
            arg0->yPos.h = (arg0->yPos.h - arg0->unk32) + (arg0->unk42 >> 1);
        }
    }

    var_t1 = arg0->unk16C->unk72;
    var_t0 = arg0->unk16C->unk74;
    var_t2 = arg0->unk16C->unk7A;

    if (((arg0->zRotation >= 45) && (arg0->zRotation < 135)) ||
        ((arg0->zRotation >= 225) && (arg0->zRotation < 315))) {
        temp_t5 = var_t0;
        var_t0 = (var_t2 / 2);
        var_t2 = temp_t5 << 1;
    }
    if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
        ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
        temp_t5 = var_t1;
        var_t1 = var_t0;
        var_t0 = temp_t5;
    }

    arg0->unk30 = var_t1;
    arg0->unk32 = var_t0;
    arg0->unk42 = var_t2;

    arg0->unk30 = ((s64)arg0->unk30 * arg0->unk40) >> 0xB;
    arg0->unk32 = ((s64)arg0->unk32 * arg0->unk40) >> 0xB;
    arg0->unk42 = ((s64)arg0->unk42 * arg0->unk40) >> 0xB;
}

// ESA: func_8004D86C
void func_802C9BA4_6DB254(struct071 *arg0) {
    s16 temp_t9;
    s16 i;
    s16 var_t1;
    s16 var_t2;
    s16 var_v1;

    if (arg0->unk40 == 0) {
        arg0->unk40 = 0x800;
    }

    var_t1 = arg0->unk16C->unk72;
    var_v1 = arg0->unk16C->unk74;
    var_t2 = arg0->unk16C->unk7A;

    if ((arg0->unk16C->unk15 == 4)) {
        if (((arg0->zRotation >= 0x2E) && (arg0->zRotation < 0x88)) || ((arg0->zRotation >= 0xE2) && (arg0->zRotation < 0x13C))) {
            temp_t9 = var_v1;
            var_v1 = var_t2 / 2;
            var_t2 = temp_t9 * 2;
        }
    }

    if (((arg0->yRotation >= 0x2E) && (arg0->yRotation < 0x88)) || ((arg0->yRotation >= 0xE2) && (arg0->yRotation < 0x13C))) {
        temp_t9 = var_t1;
        var_t1 = var_v1;
        var_v1 = temp_t9;
    }

    arg0->unk30 = var_t1;
    arg0->unk32 = var_v1;
    arg0->unk42 = var_t2;

    arg0->unk34 = arg0->unk16C->unk76;
    arg0->unk36 = arg0->unk16C->unk78;

    arg0->unk34 = ((s64)arg0->unk34 * arg0->unk40) >> 11;
    arg0->unk36 = ((s64)arg0->unk36 * arg0->unk40) >> 11;

    if ((arg0->unk16C->objectType >= 0x80) && (((((Animal*) arg0)->unk366 == 5)) || (((Animal*) arg0)->unk366 == 2))) {
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
        arg0->unk74[i][0] = arg0->unk16C->unk20[i][0] << 0x10;
        arg0->unk74[i][1] = arg0->unk16C->unk20[i][1] << 0x10;
        arg0->unk74[i][2] = arg0->unk16C->unk20[i][2] << 0x10;
        arg0->unk74[i][3] = arg0->unk16C->unk20[i][3];

        arg0->unk74[i][0] = ((s64)arg0->unk74[i][0] * arg0->unk40) >> 11;
        arg0->unk74[i][1] = ((s64)arg0->unk74[i][1] * arg0->unk40) >> 11;
        arg0->unk74[i][2] = ((s64)arg0->unk74[i][2] * arg0->unk40) >> 11;
        arg0->unk74[i][3] = ((s64)arg0->unk74[i][3] * arg0->unk40) >> 11;
    }
}
