#include <ultra64.h>
#include "common.h"


void func_8032D380_73EA30(Vertex *arg0, Vertex *arg1, Vertex *arg2) {
//vector addition
    arg2->x = (arg0->x + arg1->x);
    arg2->y = (arg0->y + arg1->y);
    arg2->z = (arg0->z + arg1->z);
}

void func_8032D3B4_73EA64(Vertex *arg0, Vertex *arg1, Vertex *arg2) {
//vector subtraction
    arg2->x = (arg0->x - arg1->x);
    arg2->y = (arg0->y - arg1->y);
    arg2->z = (arg0->z - arg1->z);
}

void func_8032D3E8_73EA98(Vertex *arg0, f32 arg1, Vertex *arg2) {
//multiply vector by a constant
    arg2->x = (arg0->x * arg1);
    arg2->y = (arg0->y * arg1);
    arg2->z = (arg0->z * arg1);
}

void func_8032D414_73EAC4(Vertex *arg0, f32 arg1, Vertex *arg2) {
//divide vector by a constant
    arg2->x = (arg0->x / arg1);
    arg2->y = (arg0->y / arg1);
    arg2->z = (arg0->z / arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D440_73EAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D494_73EB44.s")

f32 func_8032D504_73EBB4(Vertex *arg0, Vertex *arg1) {
    //dot product
    f32 x0x1, y0y1, z0z1;

    x0x1 = arg0->x * arg1->x;
    y0y1 = arg0->y * arg1->y;
    z0z1 = arg0->z * arg1->z;
    
    return (x0x1) + (y0y1) + (z0z1);
}

void func_8032D534_73EBE4(Vertex *arg0, Vertex *arg1, Vertex *arg2) {
//cross product
    arg2->x = ((arg0->y * arg1->z) - (arg0->z * arg1->y));
    arg2->y = ((arg0->z * arg1->x) - (arg0->x * arg1->z));
    arg2->z = ((arg0->x * arg1->y) - (arg0->y * arg1->x));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_73EA30/func_8032D5A4_73EC54.s")