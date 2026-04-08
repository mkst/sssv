#include <ultra64.h>
#include "common.h"

#include "overlay2_6EC720.h"


void interpolate_bone_from_previous_pose(u16 src, u16 dst, s16 yawIndex, s16 pitchIndex, u16 boneLength, u16 interpStep);
void func_802DB5C0_6ECC70(s16 arg0, s16 arg1, s16 arg2, u16 arg3);
void func_802DB494_6ECB44(u16 arg0, u16 arg1, s16 arg2, s16 arg3, u16 arg4);

/* only called with arg5 < 32 */
void interpolate_bone_from_previous_pose(u16 src, u16 dst, s16 yawIndex, s16 pitchIndex, u16 boneLength, u16 interpStep) {
    s16 targetX;
    s16 targetZ;
    s16 targetY;

    s16 prevX;
    s16 prevZ;
    s16 prevY;

    s16 targetWeight;
    s16 previousWeight;

    u16 prevLength;
    u16 targetLength;

    s32 idx;

    s16 angleBetween;

    f32 tmp;

    targetZ = (D_80152350.unk2D0[yawIndex] * boneLength) / 256;
    targetY = (D_80152350.unk384[yawIndex] * boneLength) / 256;

    targetX = (D_80152350.unk2D0[pitchIndex] * targetZ) / 256;
    targetZ = (D_80152350.unk384[pitchIndex] * targetZ) / 256;

    // diff = prev joint location?
    prevX = D_802040F0[dst].unk0 - D_802040F0[src].unk0;
    prevZ = D_802040F0[dst].unk2 - D_802040F0[src].unk2;
    prevY = D_802040F0[dst].unk4 - D_802040F0[src].unk4;

    tmp = SQ((f32) targetX) + SQ((f32) targetZ) + SQ((f32) targetY);
    targetLength = (s32) sqrtf(tmp);

    tmp = SQ((f32) prevX) + SQ((f32) prevZ) + SQ((f32) prevY);
    prevLength = (s32) sqrtf(tmp);

    idx = targetLength * prevLength;
    if (idx == 0) {
        idx = 1;
    }
    angleBetween = func_801283AC((((targetX * prevX) + (targetZ * prevZ) + (targetY * prevY)) * 256) / idx);

    if (angleBetween == 180) {
        angleBetween = 179;
    }
    angleBetween = angleBetween >> 2;

    if (interpStep < 17) {
        idx = interpStep + (angleBetween * 17);
        targetWeight = D_803A2D90_7B4440[idx*2 + 0];
        previousWeight = D_803A2D90_7B4440[idx*2 + 1];
    } else {
        interpStep = (32 - interpStep);
        idx = interpStep + (angleBetween * 17);
        previousWeight = D_803A2D90_7B4440[idx*2 + 0];  // NOTE: swapped!
        targetWeight = D_803A2D90_7B4440[idx*2 + 1];    // NOTE: swapped!
    }

    D_80203FE0[dst].unk0 = D_80203FE0[src].unk0 + (((targetWeight * targetX) + (previousWeight * prevX)) / 256);
    D_80203FE0[dst].unk2 = D_80203FE0[src].unk2 + (((targetWeight * targetZ) + (previousWeight * prevZ)) / 256);
    D_80203FE0[dst].unk4 = D_80203FE0[src].unk4 + (((targetWeight * targetY) + (previousWeight * prevY)) / 256);
    if ((D_80203FE0[dst].unk0 == D_80203FE0[src].unk0) &&
        (D_80203FE0[dst].unk2 == D_80203FE0[src].unk2) &&
        (D_80203FE0[dst].unk4 == D_80203FE0[src].unk4)) {
        D_80203FE0[dst].unk0++;
    }
}

void func_802DB494_6ECB44(u16 src, u16 dst, s16 yawIndex, s16 pitchIndex, u16 boneLength) {
    s16 tmp1, tmp2, tmp3;

    tmp1 = (D_80152350.unk2D0[yawIndex] * boneLength) / 256;
    tmp3 = (D_80152350.unk384[yawIndex] * boneLength) / 256;
    tmp2 = (D_80152350.unk2D0[pitchIndex] * tmp1) / 256;
    tmp1 = (D_80152350.unk384[pitchIndex] * tmp1) / 256;

    D_80203FE0[dst].unk0 = D_80203FE0[src].unk0 + tmp2;
    D_80203FE0[dst].unk2 = D_80203FE0[src].unk2 + tmp1;
    D_80203FE0[dst].unk4 = D_80203FE0[src].unk4 + tmp3;
}

void func_802DB5C0_6ECC70(s16 arg0, s16 arg1, s16 arg2, u16 arg3) {
    D_80203FE0[0].unk0 = ((D_80203FE0[0].unk0 * (32 - arg3)) + (arg3 * arg0)) >> 5;
    D_80203FE0[0].unk2 = ((D_80203FE0[0].unk2 * (32 - arg3)) + (arg3 * arg1)) >> 5;
    D_80203FE0[0].unk4 = ((D_80203FE0[0].unk4 * (32 - arg3)) + (arg3 * arg2)) >> 5;
}

void func_802DB670_6ECD20(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3) {
    if (D_803F2ECC < 31) {
        func_802DB5C0_6ECC70(arg3[0], arg3[1], arg3[2], D_803F2ECC);
        arg3 += 3; // increment 6 bytes
        while (*arg0 != *arg1) {
            interpolate_bone_from_previous_pose(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++, D_803F2ECC);
            arg3 += 2; // increment 4 bytes
        }
    } else {
        D_80203FE0[0].unk0 = arg3[0];
        D_80203FE0[0].unk2 = arg3[1];
        D_80203FE0[0].unk4 = arg3[2];
        arg3 += 3; // increment 6 bytes
        while (*arg0 != *arg1) {
            func_802DB494_6ECB44(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++);
            arg3 += 2; // increment 4 bytes
        }
    }
}

void func_802DB7C4_6ECE74(u8 *arg0, u8 *arg1, s16 *arg2, s16 *arg3) {
    if (D_803F2ECC < 31) {
        while (*arg0 != *arg1) {
            interpolate_bone_from_previous_pose(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++, D_803F2ECC);
            arg3 += 2;
        }
    } else {
        while (*arg0 != *arg1) {
            func_802DB494_6ECB44(*arg0++, *arg1++, arg3[0], arg3[1], *arg2++);
            arg3 += 2;
        }
    }
}

void backup_joint_positions(void) {
    u16 i;

    if (D_803F2ECC < 31) {
        for (i = 0; i < 34; i++) {
            D_802040F0[i].unk0 = D_80203FE0[i].unk0;
            D_802040F0[i].unk2 = D_80203FE0[i].unk2;
            D_802040F0[i].unk4 = D_80203FE0[i].unk4;
        }
    }
}
