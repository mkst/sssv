#include <ultra64.h>
#include "common.h"

#pragma intrinsic sqrtf

void vector_add(Vertex *x, Vertex *y, Vertex *res) {
    res->x = x->x + y->x;
    res->y = x->y + y->y;
    res->z = x->z + y->z;
}

void vector_subtract(Vertex *x, Vertex *y, Vertex *res) {
    res->x = x->x - y->x;
    res->y = x->y - y->y;
    res->z = x->z - y->z;
}

void vector_multiply_by(Vertex *x, f32 c, Vertex *res) {
    res->x = x->x * c;
    res->y = x->y * c;
    res->z = x->z * c;
}

void vector_divide_by(Vertex *x, f32 c, Vertex *res) {
    res->x = x->x / c;
    res->y = x->y / c;
    res->z = x->z / c;
}

f32 get_magnitude(Vertex *v) {
    f32 x, y, z;
    f32 tmp, ret;

    x = v->x * v->x;
    y = v->y * v->y;
    z = v->z * v->z;
    tmp = x + y + z;
    if (tmp >= 0.0f) {
        ret = sqrtf(tmp);
    } else {
        ret = 0.0f;
    }
    return ret;
}

void normalize_vector(Vertex *x, Vertex *res) {
    f32 mag = get_magnitude(x);
    if (mag != 0.0) {
        vector_divide_by(x, mag, res);
    } else {
        *res = *x;
    }
}

f32 dot_product(Vertex *x, Vertex *y) {
    f32 x0x1, y0y1, z0z1;

    x0x1 = x->x * y->x;
    y0y1 = x->y * y->y;
    z0z1 = x->z * y->z;

    return x0x1 + y0y1 + z0z1;
}

void cross_product(Vertex *x, Vertex *y, Vertex *res) {
    res->x = x->y * y->z - x->z * y->y;
    res->y = x->z * y->x - x->x * y->z;
    res->z = x->x * y->y - x->y * y->x;
}

s16 get_angle_between_vectors(Vertex *x, Vertex *y) {
    s32 pad;
    f32 mm;
    f32 tmp;
    f32 m1, m2;
    s16 ret;

    ret = 1000;
    m1 = get_magnitude(x);
    m2 = get_magnitude(y);
    mm = m1 * m2;
    if (mm != 0.0) {
        tmp = (dot_product(x, y) * 256.0f) / mm;
        if (tmp > 256.0f) {
            tmp = 256.0f;
        } else {
            if (tmp < -256.0f) {
                tmp = -256.0f;
            }
        }
        ret = func_801283AC(tmp);
    }
    return ret;
}
