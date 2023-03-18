#include <ultra64.h>
#include "common.h"


s32 func_80319280_72A930(Animal *arg0, Vertex *arg1, Vertex *arg2,
                         Animal *arg3, Vertex *arg4, Vertex *arg5,
                         f32 arg6, f32 arg7) {

    Vertex sp8C;
    Vertex sp80;
    Vertex sp74;
    Vertex sp68;
    Vertex sp5C;
    s16 sp5A;
    s16 sp58;

    f32 var_f2;
    f32 var_f12;

    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    s16 sp3E;
    s16 sp3C;
    s16 temp_t0;
    s16 temp_t1;

    temp_t0 = arg0->unk44;
    temp_t1 = arg3->unk44;

    if ((arg0->unk16C->unk80.unk12) && (arg3->unk16C->unk80.unk12)) {
        if ((arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
            temp_t0 *= 3;
        }
        if ((arg3->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (arg3->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
            temp_t1 *= 3;
        }
    }
    if ((temp_t1 * 3) < temp_t0) {
        sp3E = 1;
    } else {
        sp3E = !arg0->unk4C.unk27;
    }
    if ((temp_t0 * 3) < temp_t1) {
        sp3C = 1;
    } else {
        sp3C = !arg3->unk4C.unk27;
    }
    if (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
        sp3C = 1;
    }
    vector_subtract(arg4, arg1, &sp68);
    normalize_vector(&sp68, &sp74);
    sp5A = get_angle_between_vectors(&sp74, arg2);
    sp58 = get_angle_between_vectors(&sp74, arg5);

    if ((sp5A == 1000) || (sp5A == 0)) {
        sp8C.x = 0.0f;
        sp8C.y = 0.0f;
        sp8C.z = 0.0f;
    } else {
        cross_product(&sp74, arg2, &sp68);
        cross_product(&sp68, &sp74, &sp8C);
        normalize_vector(&sp8C, &sp68);
        sp8C = sp68; // struct copy
    }

    if ((sp58 == 1000) || (sp58 == 0)) {
        sp80.x = 0.0f;
        sp80.y = 0.0f;
        sp80.z = 0.0f;
    } else {
        cross_product(&sp74, arg5, &sp68);
        cross_product(&sp68, &sp74, &sp80);
        normalize_vector(&sp80, &sp68);
        sp80 = sp68; // struct copy
    }

    if (sp5A == 1000) {
        var_f2 = 0.0f;
    } else {
        var_f2 = get_magnitude(arg2);
    }

    if (sp58 == 1000) {
        var_f12 = 0.0f;
    } else {
        var_f12 = get_magnitude(arg5);
    }

    if (sp5A != 1000) {
        if (sp5A == 0) {
            sp4C = var_f2;
            sp44 = 0.0f;
        } else {
            sp4C = (D_80152350.unk384[sp5A] * var_f2) / 256;
            sp44 = (D_80152350.unk2D0[sp5A] * var_f2) / 256;
        }
    } else {
        sp4C = 0.0f;
        sp44 = 0.0f;
    }

    if (sp58 != 1000) {
        if (sp58 == 0) {
            sp48 = var_f12;
            sp40 = 0.0f;
        } else {
            sp48 = (D_80152350.unk384[sp58] * var_f12) / 256;
            sp40 = (D_80152350.unk2D0[sp58] * var_f12) / 256;
        }
    } else {
        sp48 = 0.0f;
        sp40 = 0.0f;
    }
    func_8031977C_72AE2C(arg0->unk44, &sp4C,
                         arg3->unk44, &sp48,
                         arg6, sp3E, sp3C);

    if (sp3E == 0) {
        sp44 *= arg7;
    }

    if (sp3C == 0) {
        sp40 *= arg7;
    }

    vector_multiply_by(&sp74, sp4C, &sp5C);
    if (sp44 != 0.0f) {
        vector_multiply_by(&sp8C, sp44, &sp8C);
        vector_add(&sp5C, &sp8C, arg2);
    } else {
        *arg2 = sp5C; // struct copy
    }

    vector_multiply_by(&sp74, sp48, &sp5C);
    if (sp40 != 0.0f) {
        vector_multiply_by(&sp80, sp40, &sp80);
        vector_add(&sp5C, &sp80, arg5);
    } else {
        *arg5 = sp5C; // struct copy
    }
    return 1;
}

void func_8031977C_72AE2C(s32 arg0, f32 *arg1, s32 arg2, f32 *arg3, f32 arg4, s16 arg5, s16 arg6) {
    s32 tmp = arg0 + arg2;

    if (arg6 != 0) {
        *arg1 = *arg3 + ((*arg3 - *arg1) * arg4);
    } else if (arg5 != 0) {
        *arg3 = *arg1 + ((*arg1 - *arg3) * arg4);
    } else {
        f32 tmp1;
        f32 tmp2 = ((arg0 * *arg1) + (*arg3 * arg2)) / tmp;

        *arg1 = *arg1 - tmp2;
        *arg3 = *arg3 - tmp2;

        tmp1 = *arg1;
        *arg1 = (((arg0 * *arg1) + (((2 * *arg3) - *arg1) * arg2)) * arg4) / tmp;
        *arg3 = (((arg2 * *arg3) + (((2 * tmp1) - *arg3) * arg0)) * arg4) / tmp;
        *arg1 = *arg1 + tmp2;
        *arg3 = *arg3 + tmp2;
    }
}

void func_803198B0_72AF60(void) {
    s16 temp_s3;
    s16 temp_s6;
    s16 temp_s7;
    s16 temp_v1;

    s16 k;
    s16 j;
    s16 i; // sp42

    for (i = 0; i < 65; i++){
        D_803E95B8[i] = 0;
    }

    for (i = 0; D_803E93B0[i].unk2 != 245; i++) {
        temp_v1 = D_803E93B0[i].unk0;
        temp_s7 = D_803E93B0[i].unk3;
        temp_s6 = D_803E93B0[i].unk1;
        temp_s3 = D_803E93B0[i].unk4;

        for (j = temp_v1; j <= temp_s7; j++) {
            for (k = temp_s6; k <= temp_s3; k++) {
                D_803E95B8[i] |= (s64)1 << (s16)((j >> 4) + ((k >> 4) * 5));
            }
        }
    }
}
