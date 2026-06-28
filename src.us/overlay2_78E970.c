#include <ultra64.h>
#include "common.h"
#include "pp.h"

// ========================================================
// definitions
// ========================================================

void unused_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void unused_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2);
void unused_8037D2E4_78E994(s32 arg0);
void unused_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2);
void unused_8037D320_78E9D0(s32 arg0, s32 arg1);

// ========================================================
// .text
// ========================================================

#ifdef __sgi
void unused_8037D2C0_78E970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void unused_8037D2D4_78E984(s32 arg0, s32 arg1, s32 arg2) {
}

void unused_8037D2E4_78E994(s32 arg0) {
    u8 *nonsense;
    UnpackRNC((RNC_fileptr)nonsense, (u8*)D_800DF220);
}

void unused_8037D310_78E9C0(s32 arg0, s32 arg1, s32 arg2) {
}

void unused_8037D320_78E9D0(s32 arg0, s32 arg1) {
}

void empty_8037D32C_78E9DC(Gfx *arg0, u8 arg1, s32 arg2, u16 arg3, s32 arg4) {
}
#endif
