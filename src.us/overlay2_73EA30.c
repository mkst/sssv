#include <ultra64.h>
#include "common.h"


void func_8032D380_73EA30(Vertex *x, Vertex *y, Vertex *res) {
//vector addition
    res->x = x->x + y->x;
    res->y = x->y + y->y;
    res->z = x->z + y->z;
}

void func_8032D3B4_73EA64(Vertex *x, Vertex *y, Vertex *res) {
//vector subtraction
    res->x = x->x - y->x;
    res->y = x->y - y->y;
    res->z = x->z - y->z;
}

void func_8032D3E8_73EA98(Vertex *x, f32 c, Vertex *res) {
//multiply vector by a constant
    res->x = x->x * c;
    res->y = x->y * c;
    res->z = x->z * c;
}

void func_8032D414_73EAC4(Vertex *x, f32 c, Vertex *res) {
//divide vector by a constant
    res->x = x->x / c;
    res->y = x->y / c;
    res->z = x->z / c;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D440_73EAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D494_73EB44.s")

f32 func_8032D504_73EBB4(Vertex *x, Vertex *y) {
//dot product
    f32 x0x1, y0y1, z0z1;

    x0x1 = x->x * y->x;
    y0y1 = x->y * y->y;
    z0z1 = x->z * y->z;

    return x0x1 + y0y1 + z0z1;
}

void func_8032D534_73EBE4(Vertex *x, Vertex *y, Vertex *res) {
//cross product
    res->x = x->y * y->z - x->z * y->y;
    res->y = x->z * y->x - x->x * y->z;
    res->z = x->x * y->y - x->y * y->x;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D5A4_73EC54.s")
