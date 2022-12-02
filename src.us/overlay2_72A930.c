#include <ultra64.h>
#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72A930/func_80319280_72A930.s")
// s32 func_80319280_72A930(Animal *arg0, Vertex *arg1, Vertex *arg2,
//                          Animal *arg3, Vertex *arg4, Vertex *arg5,
//                          f32 arg6, f32 arg7) {
//
//     Vertex sp8C;
//     Vertex sp80;
//     Vertex sp74;
//     Vertex sp68;
//     Vertex sp5C;
//     s16 sp5A;
//     s16 sp58;
//
//     s16 sp3E;
//     s16 sp3C;
//     s16 temp_t0;
//     s16 temp_t1;
//
//     f32 tmp0;
//     f32 tmp1;
//     f32 tmp2;
//     f32 tmp3;
//
//     temp_t0 = arg0->unk44;
//     temp_t1 = arg3->unk44;
//     if ((arg0->unk16C->unk80.bit) && (arg3->unk16C->unk80.bit)) {
//         if ((arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || ((arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING)))) {
//             temp_t0 = temp_t0 * 3;
//         }
//         if ((arg3->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+HARD_MOUSE)) || (arg3->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+RACING_TORTOISE_DEFENDING))) {
//             temp_t1 = temp_t1 * 3;
//         }
//     }
//     if ((temp_t1 * 3) < temp_t0) {
//         sp3E = 1;
//     } else {
//         sp3E = ((u32) (arg0->unk4C << 0x1B) >> 0x1F) == 0;
//     }
//     if ((temp_t0 * 3) < temp_t1) {
//         sp3C = 1;
//     } else {
//         sp3C = ((u32) (arg3->unk4C << 0x1B) >> 0x1F) == 0;
//     }
//     if (arg0->unk16C->objectType == (OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) {
//         sp3C = 1;
//     }
//     vector_subtract(arg4, arg1, &sp68);
//     normalize_vector(&sp68, &sp74);
//     sp5A = get_angle_between_vectors(&sp74, arg2);
//     sp58 = get_angle_between_vectors(&sp74, arg5);
//
//     if ((sp5A == 1000) || (sp5A == 0)) {
//         sp8C.x = 0.0f;
//         sp8C.y = 0.0f;
//         sp8C.z = 0.0f;
//     } else {
//         cross_product(&sp74, arg2, &sp68);
//         cross_product(&sp68, &sp74, &sp8C);
//         normalize_vector(&sp8C, &sp68);
//         sp8C = sp68;
//     }
//
//     if ((sp58 == 1000) || (sp58 == 0)) {
//         sp80.x = 0.0f;
//         sp80.x = 0.0f;
//         sp80.x = 0.0f;
//     } else {
//         cross_product(&sp74, arg5, &sp68);
//         cross_product(&sp68, &sp74, &sp80);
//         normalize_vector(&sp80, &sp68);
//         sp80 = sp68;
//     }
//
//     if (sp5A == 1000) {
//         tmp0 = 0.0f;
//     } else {
//         tmp0 = get_magnitude(arg2);
//     }
//
//     if (sp58 == 1000) {
//         tmp1 = 0.0f;
//     } else {
//         tmp1 = get_magnitude(arg5);
//     }
//
//     if (sp5A != 1000) {
//         if (sp5A == 0) {
//             tmp2 = 0.0f;
//         } else {
//             tmp0 = (D_80152350.unk384[sp5A] * tmp0) / 256.0f;
//             tmp2 = (D_80152350.unk2D0[sp5A] * tmp0) / 256.0f;
//         }
//     } else {
//         tmp0 = 0.0f;
//         tmp2 = 0.0f;
//     }
//
//     if (sp58 != 1000) {
//         if (sp58 == 0) {
//             tmp3 = 0.0f;
//         } else {
//             tmp1 = (D_80152350.unk384[sp58] * tmp1) / 256.0f;
//             tmp3 = (D_80152350.unk2D0[sp58] * tmp1) / 256.0f;
//         }
//     } else {
//         tmp1 = 0.0f;
//         tmp3 = 0.0f;
//     }
//     func_8031977C_72AE2C(arg0->unk44, &tmp0,
//                          arg3->unk44, &tmp1,
//                          arg6, sp3E, sp3C);
//
//     if (sp3E == 0) {
//         tmp2 = tmp2 * arg7;
//     }
//
//     if (sp3C == 0) {
//         tmp3 = tmp3 * arg7;
//     }
//
//     vector_multiply_by(&sp74, tmp0, &sp5C);
//     if (tmp2 != 0.0f) {
//         vector_multiply_by(&sp8C, tmp2, &sp8C);
//         vector_add(&sp5C, &sp8C, arg2);
//     } else {
//         *arg2 = sp5C;
//     }
//
//     vector_multiply_by(&sp74, tmp1, &sp5C);
//     if (tmp3 != 0.0f) {
//         vector_multiply_by(&sp80, tmp3, &sp80);
//         vector_add(&sp5C, &sp80, arg5);
//     } else {
//         *arg5 = sp5C;
//     }
//     return 1;
// }

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_72A930/func_803198B0_72AF60.s")
