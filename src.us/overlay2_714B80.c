#include <ultra64.h>
#include "common.h"


void func_803034D0_714B80(Animal *animal, u16 radius, s16 heightOffset, u16 index) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp38[2];
    s32 sp34;
    s16 temp_t9;
    s16 temp_t9_2;
    s16 new_var;
    s16 new_var2;
    s32 sp28;
    s32 pad;

    temp_t9 = COS(animal->heading) >> 8;
    temp_t9_2 = SIN(animal->heading) >> 8;

    new_var2 = D_80203FE0[1].unk2;
    new_var = D_80203FE0[1].unk0;

    sp4C = ((D_80203FE0[1].unk2 * temp_t9_2) + (new_var * temp_t9)) >> 7;
    sp48 = ((new_var2 * temp_t9) - (new_var * temp_t9_2)) >> 7;

    sp44 = ((D_80203FE0[2].unk0 * temp_t9) + (D_80203FE0[2].unk2 * temp_t9_2)) >> 7;
    sp40 = ((D_80203FE0[2].unk2 * temp_t9) - (D_80203FE0[2].unk0 * temp_t9_2)) >> 7;

    sp28 = (D_80203FE0[1].unk4 + (D_80203FE0[2].unk4 * 5)) / 192;
    sp34 = ((D_80203FE0[1].unk4 * 5) + D_80203FE0[2].unk4) / 192;

    animal->unkC4[index].pos.xPos.h = ((sp4C * 5) + sp44) / 192;
    if (0) { }
    animal->unkC4[index].pos.zPos.h = ((sp48 * 5) + sp40) / 192;
    animal->unkC4[index].pos.yPos.h = (heightOffset / 32) + sp34;
    animal->unkC4[index].unkC = ((radius * 7) / 32) >> 4;

    animal->unkC4[index+1].pos.xPos.h = ((sp44 * 5) + sp4C) / 192;
    animal->unkC4[index+1].pos.zPos.h = ((sp40 * 5) + sp48) / 192;
    animal->unkC4[index+1].pos.yPos.h = (heightOffset / 32) + sp28;
    animal->unkC4[index+1].unkC = ((radius * 7) / 32) >> 4;
}

void func_80303820_714ED0(Animal *animal, u16 joint1, u16 joint2, u16 boneLength, u16 index) {
    s32 midX;
    s32 midZ;
    s32 midY;

    s16 cosAngle;
    s16 sinAngle;

    midX = (D_80203FE0[joint1].unk0 + D_80203FE0[joint2].unk0) >> 1;
    midZ = (D_80203FE0[joint1].unk2 + D_80203FE0[joint2].unk2) >> 1;
    midY = (D_80203FE0[joint1].unk4 + D_80203FE0[joint2].unk4) >> 1;

    cosAngle = COS(animal->heading) >> 8;
    sinAngle = SIN(animal->heading) >> 8;

    midY /= 32;

    animal->unkC4[index].pos.xPos.h = ((((midX * cosAngle) + (midZ * sinAngle))) >> 7) / 32;
    animal->unkC4[index].pos.zPos.h = ((((midZ * cosAngle) - (midX * sinAngle))) >> 7) / 32;
    animal->unkC4[index].pos.yPos.h = midY;

    animal->unkC4[index].unkC = boneLength / 32;
}

void func_80303990_715040(Animal *animal, u16 joint1, u16 joint2, u16 joint3, u16 joint4, u16 boneLength, u16 jointIndex) {
    s32 midX;
    s32 midZ;
    s32 midY;

    s16 cosAngle;
    s16 sinAngle;

    midX = (D_80203FE0[joint1].unk0 + D_80203FE0[joint2].unk0) >> 1; // average of 1 + 2 X
    midZ = (D_80203FE0[joint1].unk2 + D_80203FE0[joint2].unk2) >> 1; // average of 1 + 2 Z
    midY = (D_80203FE0[joint3].unk4 + D_80203FE0[joint4].unk4) >> 1; // average of 3 + 4 Y

    cosAngle = COS(animal->heading) >> 8;
    sinAngle = SIN(animal->heading) >> 8;

    midY = midY / 32;

    animal->unkC4[jointIndex].pos.xPos.h = ((((midX * cosAngle) + (midZ * sinAngle))) >> 7) / 32;
    animal->unkC4[jointIndex].pos.zPos.h = ((((midZ * cosAngle) - (midX * sinAngle))) >> 7) / 32;
    animal->unkC4[jointIndex].pos.yPos.h = midY;

    animal->unkC4[jointIndex].unkC = boneLength / 32;
}

void func_80303B18_7151C8(Animal *animal, u16 arg1, s16 arg2, u16 arg3, u16 arg4) {
    s32 tmp0;
    s32 tmp2;
    s32 tmp4;

    s16 temp_t2;
    s16 temp_t7;

    tmp0 = D_80203FE0[arg1].unk0;
    tmp2 = D_80203FE0[arg1].unk2;
    tmp4 = D_80203FE0[arg1].unk4 + arg2;

    temp_t2 = COS(animal->heading) >> 8;
    temp_t7 = SIN(animal->heading) >> 8;

    tmp4 = tmp4 / 32;

    animal->unkC4[arg4].pos.xPos.h = (((temp_t2 * tmp0) + (tmp2 * temp_t7)) >> 7) / 32;
    animal->unkC4[arg4].pos.zPos.h = (((temp_t2 * tmp2) - (tmp0 * temp_t7)) >> 7) / 32;
    animal->unkC4[arg4].pos.yPos.h = tmp4;
    animal->unkC4[arg4].unkC = arg3 / 32;
}

void func_80303C44_7152F4(Animal *animal, u16 index, s16 arg2, s16 arg3) {
    Animal *temp_v0 = D_803D552C->unk320;
    animal->unkC4[index].pos.xPos.h = ((SIN(D_803D552C->heading) >> 7) * arg2) >> 8;
    animal->unkC4[index].pos.zPos.h = ((COS(D_803D552C->heading) >> 7) * arg2) >> 8;
    animal->unkC4[index].pos.yPos.h = temp_v0->unk74[0].pos.yPos.h + arg3;
    animal->unkC4[index].unkC = (temp_v0->unk74[0].unkC * 3) >> 2;
}

void func_80303D00_7153B0(Animal *animal, u16 arg1, u16 arg2) {
    animal->unkC4[0].pos.xPos.h = 0;
    animal->unkC4[0].pos.zPos.h = 0;
    animal->unkC4[0].pos.yPos.h = arg2 / 32;
    animal->unkC4[0].unkC = arg1 / 32;
    animal->unkC4[1].unkC = 0;
}

// set_end_collision_index ?
void func_80303D50_715400(Animal *animal, u16 idx) {
    animal->unkC4[idx].unkC = 0;
}

#ifdef __sgi
void func_80303D68_715418(Animal *animal, u16 index, DisplayList *arg2) {
    guTranslate(
        &arg2->modelViewMtx[arg2->usedModelViewMtxs],
        animal->unkC4[index].pos.xPos.h + animal->position.xPos.h,
        animal->unkC4[index].pos.zPos.h + animal->position.zPos.h,
        animal->unkC4[index].pos.yPos.h + animal->position.yPos.h);

    gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guScale(&arg2->modelViewMtx[arg2->usedModelViewMtxs], (f64)animal->unkC4[index].unkC * 1.0f, (f64)animal->unkC4[index].unkC * 1.0f, (f64)animal->unkC4[index].unkC * 1.0f);

    gSPMatrix(gOpaqueDL++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gOpaqueDL++, D_01003618_3CEE8);
    gDPSetPrimColor(gOpaqueDL++, 0, 0, 255, 0, 0, 255);
    gSPDisplayList(gOpaqueDL++, D_01037700_70FD0);
    gSPPopMatrix(gOpaqueDL++, G_MTX_MODELVIEW);
}

void func_80303F90_715640(Animal *animal, DisplayList *dl) {
    s16 i;
    for (i = 0; (i < 5) && (animal->unkC4[i].unkC != 0); i++) {
        func_80303D68_715418(animal, i, dl);
    }
}
#endif

// ESA: func_8001C944
// check if x/z inside animals hitbox and returns vertical boundaries if inside
s32 func_8030400C_7156BC(Animal *animal, s16 x, s16 z, s32 *upperBoundary, s32 *lowerBoundary) {
    s32 temp_t2;
    s32 temp_t3;
    s16 i;
    struct043 *hitbox;

    s16 tmp1;
    s16 tmp2;

    s16 dist;

    s32 res;

    res = 0;

    *lowerBoundary = 0x40000000;
    *upperBoundary = 0;

    x = x - animal->position.xPos.h;
    z = z - animal->position.zPos.h;

    i = 1;
    hitbox = &animal->unkC4[i];

    while ((i < 5) && (hitbox->unkC != 0)) {
        tmp1 = x - hitbox->pos.xPos.h;
        tmp2 = z - hitbox->pos.zPos.h;
        dist = SQ(tmp1) + SQ(tmp2);

        if (dist < SQ(hitbox->unkC)) {
            temp_t2 = (animal->position.yPos.w + hitbox->pos.yPos.w) + (hitbox->unkC << 0x10);
            temp_t3 = (animal->position.yPos.w + hitbox->pos.yPos.w) - (hitbox->unkC << 0x10);

            if (res != 0) {
                *upperBoundary = MAX(*upperBoundary, temp_t2);
                *lowerBoundary = MIN(*lowerBoundary, temp_t3);
            } else {
                *upperBoundary = temp_t2;
                *lowerBoundary = temp_t3;
                res = 1;
            }
        }
        hitbox++;
        i++;
    }

    return res;
}
