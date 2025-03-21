#include <ultra64.h>
#include "common.h"


void func_803034D0_714B80(Animal *arg0, u16 arg1, s16 arg2, u16 index) {
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

    temp_t9 = COS(arg0->heading) >> 8;
    temp_t9_2 = SIN(arg0->heading) >> 8;

    new_var2 = D_80203FE0[1].unk2;
    new_var = D_80203FE0[1].unk0;

    sp4C = ((D_80203FE0[1].unk2 * temp_t9_2) + (new_var * temp_t9)) >> 7;
    sp48 = ((new_var2 * temp_t9) - (new_var * temp_t9_2)) >> 7;

    sp44 = ((D_80203FE0[2].unk0 * temp_t9) + (D_80203FE0[2].unk2 * temp_t9_2)) >> 7;
    sp40 = ((D_80203FE0[2].unk2 * temp_t9) - (D_80203FE0[2].unk0 * temp_t9_2)) >> 7;

    sp28 = (D_80203FE0[1].unk4 + (D_80203FE0[2].unk4 * 5)) / 192;
    sp34 = ((D_80203FE0[1].unk4 * 5) + D_80203FE0[2].unk4) / 192;

    arg0->unkC4[index].pos.xPos.h = ((sp4C * 5) + sp44) / 192;
    if (0) { }
    arg0->unkC4[index].pos.zPos.h = ((sp48 * 5) + sp40) / 192;
    arg0->unkC4[index].pos.yPos.h = (arg2 / 32) + sp34;
    arg0->unkC4[index].unkC = ((arg1 * 7) / 32) >> 4;

    arg0->unkC4[index+1].pos.xPos.h = ((sp44 * 5) + sp4C) / 192;
    arg0->unkC4[index+1].pos.zPos.h = ((sp40 * 5) + sp48) / 192;
    arg0->unkC4[index+1].pos.yPos.h = (arg2 / 32) + sp28;
    arg0->unkC4[index+1].unkC = ((arg1 * 7) / 32) >> 4;
}

void func_80303820_714ED0(Animal *arg0, u16 joint1, u16 joint2, u16 boneLength, u16 index) {
    s32 midX;
    s32 midZ;
    s32 midY;

    s16 cosAngle;
    s16 sinAngle;

    midX = (D_80203FE0[joint1].unk0 + D_80203FE0[joint2].unk0) >> 1;
    midZ = (D_80203FE0[joint1].unk2 + D_80203FE0[joint2].unk2) >> 1;
    midY = (D_80203FE0[joint1].unk4 + D_80203FE0[joint2].unk4) >> 1;

    cosAngle = COS(arg0->heading) >> 8;
    sinAngle = SIN(arg0->heading) >> 8;

    midY /= 32;

    arg0->unkC4[index].pos.xPos.h = ((((midX * cosAngle) + (midZ * sinAngle))) >> 7) / 32;
    arg0->unkC4[index].pos.zPos.h = ((((midZ * cosAngle) - (midX * sinAngle))) >> 7) / 32;
    arg0->unkC4[index].pos.yPos.h = midY;

    arg0->unkC4[index].unkC = boneLength / 32;
}

void func_80303990_715040(Animal *arg0, u16 joint1, u16 joint2, u16 joint3, u16 joint4, u16 boneLength, u16 jointIndex) {
    s32 midX;
    s32 midZ;
    s32 midY;

    s16 cosAngle;
    s16 sinAngle;

    midX = (D_80203FE0[joint1].unk0 + D_80203FE0[joint2].unk0) >> 1; // average of 1 + 2 X
    midZ = (D_80203FE0[joint1].unk2 + D_80203FE0[joint2].unk2) >> 1; // average of 1 + 2 Z
    midY = (D_80203FE0[joint3].unk4 + D_80203FE0[joint4].unk4) >> 1; // average of 3 + 4 Y

    cosAngle = COS(arg0->heading) >> 8;
    sinAngle = SIN(arg0->heading) >> 8;

    midY = midY / 32;

    arg0->unkC4[jointIndex].pos.xPos.h = ((((midX * cosAngle) + (midZ * sinAngle))) >> 7) / 32;
    arg0->unkC4[jointIndex].pos.zPos.h = ((((midZ * cosAngle) - (midX * sinAngle))) >> 7) / 32;
    arg0->unkC4[jointIndex].pos.yPos.h = midY;

    arg0->unkC4[jointIndex].unkC = boneLength / 32;
}

void func_80303B18_7151C8(Animal *arg0, u16 arg1, s16 arg2, u16 arg3, u16 arg4) {
    s32 tmp0;
    s32 tmp2;
    s32 tmp4;

    s16 temp_t2;
    s16 temp_t7;

    tmp0 = D_80203FE0[arg1].unk0;
    tmp2 = D_80203FE0[arg1].unk2;
    tmp4 = D_80203FE0[arg1].unk4 + arg2;

    temp_t2 = COS(arg0->heading) >> 8;
    temp_t7 = SIN(arg0->heading) >> 8;

    tmp4 = tmp4 / 32;

    arg0->unkC4[arg4].pos.xPos.h = (((temp_t2 * tmp0) + (tmp2 * temp_t7)) >> 7) / 32;
    arg0->unkC4[arg4].pos.zPos.h = (((temp_t2 * tmp2) - (tmp0 * temp_t7)) >> 7) / 32;
    arg0->unkC4[arg4].pos.yPos.h = tmp4;
    arg0->unkC4[arg4].unkC = arg3 / 32;
}

void func_80303C44_7152F4(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    Animal *temp_v0 = D_803D552C->unk320;
    arg0->unkC4[arg1].pos.xPos.h = ((SIN(D_803D552C->heading) >> 7) * arg2) >> 8;
    arg0->unkC4[arg1].pos.zPos.h = ((COS(D_803D552C->heading) >> 7) * arg2) >> 8;
    arg0->unkC4[arg1].pos.yPos.h = temp_v0->unk74[0].pos.yPos.h + arg3;
    arg0->unkC4[arg1].unkC = (temp_v0->unk74[0].unkC * 3) >> 2;
}

void func_80303D00_7153B0(Animal *arg0, u16 arg1, u16 arg2) {
    arg0->unkC4[0].pos.xPos.h = 0;
    arg0->unkC4[0].pos.zPos.h = 0;
    arg0->unkC4[0].pos.yPos.h = arg2 / 32;
    arg0->unkC4[0].unkC = arg1 / 32;
    arg0->unkC4[1].unkC = 0;
}

// set_end_collision_index ?
void func_80303D50_715400(Animal *arg0, u16 idx) {
    arg0->unkC4[idx].unkC = 0;
}

void func_80303D68_715418(Animal *arg0, u16 arg1, DisplayList *arg2) {
    guTranslate(
        &arg2->modelViewMtx[arg2->usedModelViewMtxs],
        arg0->unkC4[arg1].pos.xPos.h + arg0->position.xPos.h,
        arg0->unkC4[arg1].pos.zPos.h + arg0->position.zPos.h,
        arg0->unkC4[arg1].pos.yPos.h + arg0->position.yPos.h);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    guScale(&arg2->modelViewMtx[arg2->usedModelViewMtxs], (f64)arg0->unkC4[arg1].unkC * 1.0f, (f64)arg0->unkC4[arg1].unkC * 1.0f, (f64)arg0->unkC4[arg1].unkC * 1.0f);

    gSPMatrix(D_801D9E88++, OS_K0_TO_PHYSICAL(&arg2->modelViewMtx[arg2->usedModelViewMtxs++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(D_801D9E88++, D_01003618_3CEE8);
    gDPSetPrimColor(D_801D9E88++, 0, 0, 255, 0, 0, 255);
    gSPDisplayList(D_801D9E88++, D_01037700_70FD0);
    gSPPopMatrix(D_801D9E88++, G_MTX_MODELVIEW);
}

// unused
void func_80303F90_715640(Animal *arg0, DisplayList *arg1) {
    s16 i;
    for (i = 0; (i < 5) && (arg0->unkC4[i].unkC != 0); i++) {
        func_80303D68_715418(arg0, i, arg1);
    }
}

// ESA: func_8001C944
// check if x/z inside animals hitbox and returns vertical boundaries if inside
s32 func_8030400C_7156BC(Animal *arg0, s16 x, s16 z, s32 *upperBoundary, s32 *lowerBoundary) {
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

    x = x - arg0->position.xPos.h;
    z = z - arg0->position.zPos.h;

    i = 1;
    hitbox = &arg0->unkC4[i];

    while ((i < 5) && (hitbox->unkC != 0)) {
        tmp1 = x - hitbox->pos.xPos.h;
        tmp2 = z - hitbox->pos.zPos.h;
        dist = SQ(tmp1) + SQ(tmp2);

        if (dist < SQ(hitbox->unkC)) {
            temp_t2 = (arg0->position.yPos.w + hitbox->pos.yPos.w) + (hitbox->unkC << 0x10);
            temp_t3 = (arg0->position.yPos.w + hitbox->pos.yPos.w) - (hitbox->unkC << 0x10);

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
