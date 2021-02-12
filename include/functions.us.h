#ifndef FUNCTIONS_US_H
#define FUNCTIONS_US_H

#include "functions.h"


void func_80125950(s32 arg0);
void func_80125980(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_8012635C(s32 arg0, s32 arg1, struct005 *arg2);

// core/controller.c
u32  func_80128200(void);
void func_8012822C(s32 time);
u16  func_8012826C(void);
void func_801282C4(void);
s16  func_8012835C(s16 idx);
s16  func_801283AC(s16 arg0);
s8   func_8012840C(u8 idx);
s8   func_80128424(u8 idx);
s16  func_8012844C(s16 arg0);
s16  func_801284B8(s16 arg0, s16 arg1);
f32  func_801286B8(f32 arg0, f32 arg1);
s16  func_80128C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// core/string.c
u16  func_80128DD0(u8 *arg0);
void func_80128E18(u8 *dst, u8 *src);


void dma_read(u32 devAddr, void *vAddr, s32 nbytes);
void func_80129210(void);
void func_8012923C(void);
void func_80129AD0(void);
void func_80129B10(s32);
void func_8012A260(void);
void func_8012A400(void);
void func_8012A870(void);
void func_8012ABF0(void);
void func_8012AC40(void);
void func_80129300(Gfx**, s32);
void func_80129DC0(void);
void func_8012AC8C(void);
void func_8012AD30(Gfx*, u8, u8, u16, u8, u8, u8, u8, u8);

// core/rnc.c
u16  func_8012B0F0(u8 *arg0);
u32  func_8012BB6C(u8 *arg0);
s32  func_8012C010(u32 arg0, u8 arg1);

void func_8012C070(u8);
void func_8012C1F0(Gfx*);
void func_8012C214(s32, s32, s32, s32);
void func_8012C248(u8, u8, u8, u8);
void func_8012C978(s32, s32, u16, s32, f32, f32);
void func_8012DEF8(s32, s32, u16, s32, f32, f32);
void func_80131070(void);
s32  func_80131BF0(s32);
void func_80130C04(void);
s32  func_80130E10(u8 *arg0);
void func_80130E44(void);
s32  func_801323B8(s16);

// main_E3C0.c
void func_80132CC0(s32 arg0);
void func_80133738(void);
void func_8013385C(f32, f32, f32);
void func_80133B74(s16 arg0);
void func_80133BA0(s16 arg0);
void func_80133E44(void);
void func_80133E84(void);

void func_801337DC(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8013307C(s32, s32, s32, f32, s32);
void func_80135604(void);

// main_123E0.c
s32  func_80136CE0(void); // initialise controllers?
void func_80136F64(void);
void func_801370A4(void);
void func_801370F4(void);
void func_8013713C(void);
void func_80137204(s16 arg0);
void func_8013724C(s16 arg0);
void func_80137840(void);


void func_80137294(void);
void func_80139200(f32);
void func_80139330(f32);
void func_80296310_6A79C0(void);
s32  func_80296320_6A79D0(void);
void func_80296544_6A7BF4(void);

void func_802B3FAC_6C565C(void);

void func_802C9340_6DA9F0(void);
void func_802C9834_6DAEE4(void);
void func_802CB360_6DCA10(void);

void func_80304170_715820(void);
void func_80304194_715844(void);

void func_8031B390_72CA40(s32);
void func_80352280_763930(void);
void func_80352310_7639C0(void);

void func_8038BA30_79D0E0(void);

#endif
