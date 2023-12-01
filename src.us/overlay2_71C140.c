#include <ultra64.h>
#include "common.h"


// ========================================================
// definitions
// ========================================================

s32  func_8030AAE0_71C190(struct071 *arg0);
s32  func_8030EBF0_7202A0(void);
s16  func_803102BC_72196C(void);

// ========================================================
// .data
// ========================================================

// ========================================================
// .bss
// ========================================================

s16  D_803E4C50; // unused

s16  D_803E4C52;
s16  D_803E4C54;
s16  D_803E4C56;
s16  D_803E4C58;
s32  D_803E4C5C;
s32  D_803E4C60;
s32  D_803E4C64;
s16  D_803E4C68;
s16  D_803E4C6A;
s16  D_803E4C6C;
s16  D_803E4C6E;
s16  D_803E4C70;
s16  D_803E4C72;
s16  D_803E4C74;
s16  D_803E4C76;
u8   D_803E4C78;
u8   D_803E4C79;
u8   D_803E4C7A;
s32  D_803E4C7C;
s32  D_803E4C80;
s16  D_803E4C84;
s16  D_803E4C86;
Animal *D_803E4C88;
Animal *D_803E4C8C;
void   *D_803E4C90;
Animal *D_803E4C94;

// ========================================================
// .text
// ========================================================

// ESA: func_8003030C
s32 func_8030AA90_71C140(Animal *arg0) {
    if (!arg0->unk4C.unk1D) {
        return 0;
    }
    if (!arg0->unk4C.unk1C) {
        return func_8030E8AC_71FF5C(arg0);
    }
    return func_8030AAE0_71C190(arg0);
}

#if 0
// ESA: func_80030364
s32 func_8030AAE0_71C190(struct071 *arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    u8  sp25;
    u8  sp24; // pad
    s32 sp20;
    s32 sp1C;

    s32 temp_t9;
    s32 phi_a3;
    s32 phi_a3_2;

    func_803899E0_79B090(arg0);
    D_803E4C94 = arg0;
    D_803E4C52 = arg0->position.xPos.h;
    D_803E4C54 = arg0->position.zPos.h;

    if ((arg0->unk162 & 0x10) != 0) {
        D_803E4C5C = arg0->position.xPos.w;
        D_803E4C60 = arg0->position.zPos.w;
        D_803E4C64 = arg0->position.yPos.w;
        D_803E4C56 = D_803E4C84;
        D_803E4C58 = D_803E4C54;
        phi_a3 = D_803E4C84;
        // phi_t0 = D_803E4C54;
    } else {
        D_803E4C5C = (arg0->position.xPos.w + arg0->unk18);
        D_803E4C60 = (arg0->position.zPos.w + arg0->unk1C.w);
        D_803E4C64 = (arg0->position.yPos.w + arg0->unk20.w);
        D_803E4C56 = D_803E4C5C >> 0x10;
        D_803E4C58 = D_803E4C60 >> 0x10;
        phi_a3 = D_803E4C52;
    }

    D_803E4C68 = (phi_a3 >> 6);
    D_803E4C6A = (D_803E4C54 >> 6);
    D_803E4C6C = (D_803E4C56 >> 6);
    D_803E4C6E = (D_803E4C58 >> 6);
    D_803E4C70 = (phi_a3 & 0x3F);
    D_803E4C72 = (D_803E4C54 & 0x3F);
    D_803E4C74 = (D_803E4C56 & 0x3F);
    D_803E4C76 = (D_803E4C58 & 0x3F);

    D_803E4C7C = arg0->unk1C.w;
    D_803E4C80 = arg0->unk20.w;
    D_803E4C78 = D_803E4C94->unk160;

    sp25 = func_80310E10_7224C0(D_803E4C68, D_803E4C6A);
    sp2E = func_8030B494_71CB44();
    sp26 = func_80310030_7216E0();
    sp2C = func_8030EA98_720148();
    sp2A = func_8030EBF0_7202A0();
    sp28 = func_803102BC_72196C();
    temp_t9 = sp25 == 0;
    sp20 = temp_t9;
    phi_a3_2 = temp_t9;
    if (temp_t9 == 0) {
        sp1C = temp_t9;
        sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
        phi_a3_2 = sp1C;
    }
    if ((sp2E == 0) &&
        (sp26 == 0) &&
        (sp2C == 0) &&
        (sp2A == 0) &&
        (sp28 == 0) &&
        ((u8)sp20 != 0)) {
        func_8030E208_71F8B8();
    } else if ((sp2E != 1) &&
               (sp26 != 1) &&
               (sp2C != 1) &&
               (sp2A != 1) &&
               (sp28 != 1) &&
               (sp2E != 2) &&
               (sp26 != 2) &&
               (sp2C != 2) &&
               (sp2A != 2) &&
               (sp28 != 2)) {

        D_803E4C5C = (D_803E4C94->position.xPos.w + D_803E4C94->newPosition.yPos.w);
        D_803E4C60 = D_803E4C94->position.zPos.w;
        D_803E4C7C = D_803E4C94->newPosition.yPos.w;
        D_803E4C80 = 0;
        D_803E4C56 = D_803E4C5C >> 0x10;
        D_803E4C58 = D_803E4C60 >> 0x10;
        D_803E4C78 = (u8) D_803E4C94->unk160;
        D_803E4C6C = (D_803E4C5C >> 0x10) >> 6;
        D_803E4C6E = (D_803E4C60 >> 0x10) >> 6;
        D_803E4C74 = (D_803E4C5C >> 0x10) & 0x3F;
        D_803E4C76 = (D_803E4C60 >> 0x10) & 0x3F;
        sp20 = phi_a3_2;
        if (phi_a3_2 == 0) {
            sp1C = phi_a3_2;
            sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
        }
        sp1C = phi_a3_2;
        phi_a3_2 = phi_a3_2;
        if ((func_8030B494_71CB44() == 0) &&
            ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
            ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
            ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
            ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
            ((u8)sp20 != 0)) {
            D_803E4C60 = D_803E4C94->position.zPos.w;
            func_8030E208_71F8B8();
            func_80313064_724714();
        } else {
            D_803E4C5C = D_803E4C94->position.xPos.w;
            D_803E4C60 = (D_803E4C94->position.zPos.w + D_803E4C94->zVelocity.w);
            D_803E4C7C = 0;
            D_803E4C80 = D_803E4C94->zVelocity.w;
            D_803E4C56 = (D_803E4C5C >> 0x10);
            D_803E4C58 = (D_803E4C60 >> 0x10);
            D_803E4C78 = (u8) D_803E4C94->unk160;
            D_803E4C6C = (D_803E4C56 >> 6);
            D_803E4C6E = (D_803E4C58 >> 6);
            D_803E4C74 = (D_803E4C56 & 0x3F);
            D_803E4C76 = (D_803E4C58 & 0x3F);
            sp20 = phi_a3_2;
            if (sp20 == 0) {
                sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
            }
            if ((func_8030B494_71CB44() == 0) &&
                ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
                ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
                ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
                ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
                ((u8)sp20 != 0)) {
                D_803E4C5C = D_803E4C94->position.xPos.w;
                func_8030E208_71F8B8();
                func_80312D94_724444();
            } else {
                func_8030E69C_71FD4C();
                func_80313334_7249E4();
            }
        }
    } else if ((sp2E != 1) &&
               (sp26 != 1) &&
               (sp2C != 1) &&
               (sp2A != 1) &&
               (sp28 != 1)) {

        D_803E4C5C = (D_803E4C94->position.xPos.w + D_803E4C94->newPosition.yPos.w);
        D_803E4C60 = D_803E4C94->position.zPos.w;
        D_803E4C7C = D_803E4C94->newPosition.yPos.w;
        D_803E4C80 = 0;
        D_803E4C56 = (D_803E4C5C >> 0x10);
        D_803E4C58 = (D_803E4C60 >> 0x10);
        sp20 = phi_a3_2;
        D_803E4C78 = (u8) D_803E4C94->unk160;
        D_803E4C6C = (D_803E4C56 >> 6);
        D_803E4C6E = (D_803E4C58 >> 6);
        D_803E4C74 = (D_803E4C56 & 0x3F);
        D_803E4C76 = (D_803E4C58 & 0x3F);
        if (phi_a3_2 == 0) {
            sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
        }
        if ((func_8030B494_71CB44() == 0) &&
            ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
            ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
            ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
            ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
            ((u8)sp20 != 0)) {
            D_803E4C60 = D_803E4C94->position.zPos.w;
            func_8030E208_71F8B8();
            func_80313064_724714();
        } else {
            func_8030E69C_71FD4C();
            func_80313334_7249E4();
        }
    } else if ((sp2E != 2) &&
               (sp26 != 2) &&
               (sp2C != 2) &&
               (sp2A != 2) &&
               (sp28 != 2)) {

        D_803E4C5C = D_803E4C94->position.xPos.w;
        D_803E4C60 = (D_803E4C94->position.zPos.w + D_803E4C94->zVelocity.w);
        D_803E4C7C = 0;
        D_803E4C80 = D_803E4C94->zVelocity.w;
        D_803E4C56 = D_803E4C5C >> 0x10;
        D_803E4C58 = D_803E4C60 >> 0x10;
        D_803E4C78 = D_803E4C94->unk160;
        D_803E4C6C = (D_803E4C5C >> 0x10) >> 6;
        D_803E4C6E = (D_803E4C60 >> 0x10) >> 6;
        D_803E4C74 = (D_803E4C5C >> 0x10) & 0x3F;
        D_803E4C76 = (D_803E4C60 >> 0x10) & 0x3F;
        sp20 = phi_a3_2;
        if (phi_a3_2 == 0) {
            sp20 = func_80310E10_7224C0(D_803E4C6C, D_803E4C6E) != 0;
        }
        if ((func_8030B494_71CB44() == 0) &&
            ((sp26 == 0) || (func_80310030_7216E0() == 0)) &&
            ((sp2C == 0) || (func_8030EA98_720148() == 0)) &&
            ((sp2A == 0) || (func_8030EBF0_7202A0() == 0)) &&
            ((sp28 == 0) || (func_803102BC_72196C() == 0)) &&
            ((u8)sp20 != 0)) {
            D_803E4C5C = D_803E4C94->position.xPos.w;
            func_8030E208_71F8B8();
            func_80312D94_724444();
        } else {
            func_8030E69C_71FD4C();
            func_80313334_7249E4();
        }
    } else {
        func_8030E69C_71FD4C(); // sp2E
        func_80313334_7249E4();
    }
    return D_803E4C84;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_71C140/func_8030AAE0_71C190.s")
#endif

// ESA: func_80030AA8 (tbd)
s32 func_8030B494_71CB44(void) {
    s16 sp3E;
    s16 sp3C;
    s16 sp3A; // pad
    s16 sp38; // pad
    s16 sp36;
    s16 ret = 0;


    if ((D_803E4C68 != D_803E4C6C) || (D_803E4C6A != D_803E4C6E)) {
        if (D_803E4C6A == D_803E4C6E) {
            if (D_803E4C68 < D_803E4C6C) {
                sp3C = (((D_803E4C76 * D_803E4C74) + (D_803E4C72 * (0x40 - D_803E4C70))) / (D_803E4C74 + (0x40 - D_803E4C70)));
                sp3E = 0;
                sp36 = 1;
            } else {
                sp3C = (((D_803E4C76 * (0x40 - D_803E4C74)) + (D_803E4C72 * D_803E4C70)) / ((0x40 - D_803E4C74) + D_803E4C70));
                sp3E = 0x3F;
                sp36 = 2;
            }
        } else {
            if (D_803E4C68 == D_803E4C6C) {
                if (D_803E4C6A < D_803E4C6E) {
                    sp3E = ((D_803E4C74 * D_803E4C76) + (D_803E4C70 * (0x40 - D_803E4C72))) / (D_803E4C76 + (0x40 - D_803E4C72));
                    sp3C = 0;
                    sp36 = 3;
                } else {
                    sp3E = ((D_803E4C74 * (0x40 - D_803E4C76)) + (D_803E4C70 * D_803E4C72)) / ((0x40 - D_803E4C76) + D_803E4C72);
                    sp3C = 0x3F;
                    sp36 = 4;
                }
            }
            else if (D_803E4C6A < D_803E4C6E) {
                if (D_803E4C68 < D_803E4C6C) {
                    sp36 = 5;
                    sp3E = 0;
                    sp3C = 0;
                } else {
                    sp36 = 6;
                    sp3E = 0x3F;
                    sp3C = 0;
                }
            }

            else if (D_803E4C68 < D_803E4C6C) {
                sp36 = 7;
                sp3E = 0;
                sp3C = 0x3F;
            } else {
                sp36 = 8;
                sp3E = 0x3F;
                sp3C = 0x3F;
            }
        }

        ret = func_8030BE20_71D4D0(sp36, sp3E, sp3C);
        if (ret != 0) {
            return ret;
        }

        switch (D_803E4C94->unk160) {
        case 0:
            if ((D_803C0740[D_803E4C6C][D_803E4C6E].unk3) != 0) {
                if (func_8030BC50_71D300(D_803E4C6C, D_803E4C6E, sp3E, sp3C, &D_803E4C78) != 0) {
                    if ((sp36 != 3) && (sp36 != 4)) {
                        ret = 1;
                    }
                    if ((sp36 != 1) && (sp36 != 2)) {
                        ret = 2;
                    }
                }
            }
            break;
        case 1:
            if (D_803C0740[D_803E4C6C][D_803E4C6E].unk3 == 0) {
                switch (sp36) {
                case 1:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E, 0x3F, sp3C, &D_803E4C94->unk160) != 0) {
                        ret = 1;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 2:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E, 0, sp3C, &D_803E4C79) != 0) {
                        ret = 1;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 3:
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E - 1, sp3E, 0x3F, &D_803E4C79) != 0) {
                        ret = 2;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 4:
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E + 1, sp3E, 0, &D_803E4C79) != 0) {
                        ret = 2;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 5:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E - 1, 0x3F, 0x3F, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 6:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E - 1, 0, 0x3F, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 7:
                    if (func_8030BD50_71D400(D_803E4C6C - 1, D_803E4C6E + 1, 0x3F, 0, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                case 8:
                    if (func_8030BD50_71D400(D_803E4C6C + 1, D_803E4C6E + 1, 0, 0, &D_803E4C79) != 0) {
                        ret = 3;
                    } else {
                        D_803E4C78 = 0;
                    }
                    break;
                }
            }
            break;
        case 2:
            if ((D_803C0740[D_803E4C6C][D_803E4C6E].unk3) == 0) {
                if (D_803E4C94->unk163 & 2) {
                    if (((func_8031124C_7228FC(D_803E4C56, D_803E4C58) >> 0x10) - (func_80310F58_722608(D_803E4C52, D_803E4C54) >> 0x10)) < -9) {
                        ret = 3;
                    }
                }
                D_803E4C78 = 0;
            }
            break;
        }
    }

    return ret;
}

// ESA: func_80031060
s32 func_8030BC50_71D300(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4) {
    s16 phi_v0;

    s32 sp20;
    s32 sp1C;

    phi_v0 = D_803E4C94->position.yPos.h;
    func_80311554_722C04((arg0 << 6) + arg2, (arg1 << 6) + arg3, &sp1C, &sp20);

    sp20 = sp20 >> 16;
    sp1C = sp1C >> 16;

    if (phi_v0 < sp20) {
        phi_v0 = sp20;
    }

    if ((phi_v0 + 10) > sp1C) {
        *arg4 = 2;
        return 0;
    }

    if ((phi_v0 + D_803E4C94->unk42) < sp1C) {
        *arg4 = 1;
        return 0;
    }
    return 1;
}

// ESA: func_80031134
s32 func_8030BD50_71D400(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4) {
    s16 temp_v1;
    s16 temp_a2;

    s16 temp_a0;
    s16 temp_a1;

    temp_a0 = (arg0 << 6) + arg2;
    temp_a1 = (arg1 << 6) + arg3;

    temp_v1 = D_803E4C94->position.yPos.h;
    temp_a2 = func_8031124C_7228FC(temp_a0, temp_a1) >> 0x10;

    if (temp_v1 < temp_a2) {
        temp_v1 = temp_a2;
    }

    if ((s16) (func_80310F58_722608(temp_a0, temp_a1) >> 0x10) < (temp_v1 + D_803E4C94->unk42)) {
        return 1;
    }
    return 0;
}

// ESA: func_800311DC (TBD)
s16 func_8030BE20_71D4D0(s16 arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;
    s16 var_t1;
    s16 var_a1;
    s16 var_v0;
    s16 temp_t8;


    temp_v0 = D_803E4C94->position.yPos.h;

    switch (arg0) {
    case 1:
        temp_t8 = ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - arg2)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg2)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg2) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - arg2))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * (0x40 - arg2)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * arg2)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, temp_t8 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, temp_t8 + (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
        return 0;

    case 2:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg2)) + (D_803C0740[D_803E4C68][D_803E4C6A+1].unk1 * arg2)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68][D_803E4C6A+1].unk1 * arg2) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg2))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - arg2)) + (D_803C0740[D_803E4C68][D_803E4C6A+1].unk0 * arg2)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
        return 0;

    case 3:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg1)) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * arg1) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - arg1))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * arg1)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
        return 0;

    case 4:
        temp_t8 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * arg1) ) >> 3;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * arg1) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - arg1))) >> 3);
        } else {
            var_t1 = MAX(temp_v0, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - arg1)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * arg1)) >> 3);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
        return 0;
    case 5:

        temp_t8 = D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * 8;

        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 6:

        temp_t8 = D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 7:
        temp_t8 = D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    case 8:
        temp_t8 = D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * 8;
        if (D_803E4C78 == 2) {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * 8);
        } else {
            var_t1 = MAX(temp_v0, D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * 8);
        }

        var_v0 = var_a1 = temp_t8;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x40) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x10) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 0x80) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 0x20) {
            var_v0 = MAX(var_v0, (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk1 * 8) + temp_t8);
        }

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 4) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 1) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 8) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk5 & 2) {
            var_a1 = MIN(var_a1, temp_t8 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A - 1].unk3].unk2 * 8));
        }
        if ((var_v0 == temp_t8) && (var_a1 == temp_t8)) {
            return 0;
        }
        if ((var_t1 < (var_v0 - 0xA)) && (var_a1 < (var_t1 + D_803E4C94->unk42))) {
            return 3;
        }
        return 0;
    }

    return 0;
}

// ESA: func_8003421C
void func_8030DD34_71F3E4(void) {
    s32 sp5C;
    s32 sp58;

    s32 var_t0;
    s32 var_t1;

    s32 sp4C;
    s32 sp48;

    Animal *var_v1;

    D_803E4C84 = 1;
    D_803E4C88 = NULL;
    D_803E4C8C = NULL;
    var_v1 = D_803E4C90 = NULL;

    if (((!D_803E4C8C->unk16C) && (!D_803E4C8C->unk16C))) {};  // regalloc helper!

    D_803E4C7A = 0;
    D_803E4C86 = 0;

    var_t0 = 0;          // max?
    var_t1 = 0x7FFF8000; // min?

    if (D_803E4C94->unk4C.unk1B != 0) {
        // ido is fun.
        func_8029B000_6AC6B0(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10, (D_803E4C94->unk42 << 0xF) + D_803E4C64, D_803E4C94, D_803E4C94->unk68, &D_803E4C88, &sp4C, D_803E4C94->unk70, &D_803E4C8C, &sp48); var_v1 = D_803E4C8C;
    }
    if (D_803E4C88 != NULL) {
        var_t0 = sp4C;
    }
    if (var_v1 != NULL) {
        var_t1 = sp48;
    }

    switch (D_803E4C78) {                              /* irregular */
    case 0:
        sp5C = func_8031124C_7228FC(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10) - (D_803E4C94->unk4C.unk10 << 0x10);
        if (sp5C >= var_t0) {
            var_t0 = sp5C;
        }
        break;
    case 1:
        func_80311554_722C04(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10, &sp58, &sp5C);
        sp5C -= D_803E4C94->unk4C.unk10 << 0x10;
        if (D_803C0740[D_803E4C5C >> 0x16][D_803E4C60 >> 0x16].unk4 & 4) {
            sp58 -= (D_803E1D30[D_803C0740[D_803E4C5C >> 0x16][D_803E4C60 >> 0x16].unk3].unk2 & 0xFFFF) << 0x13;
        }
        if (var_t0 < sp5C) {
            var_t0 = sp5C;
        }
        if (sp58 < var_t1) {
            var_t1 = sp58;
        }
        break;
    case 2:
        sp58 = func_80310F58_722608(D_803E4C5C >> 0x10, D_803E4C60 >> 0x10);
        sp58 = sp58 - (D_803E4C94->unk4C.unk10 << 0x10);
        if (sp58 >= var_t0) {
            var_t0 = sp58;
        }
        break;
    }

    if ((var_t1 - var_t0) < (D_803E4C94->unk42 << 0x10)) {
        D_803E4C84 = 0;
        D_803E4C64 = var_t0;

        if (((var_t0 != sp4C) || (D_803E4C88 == NULL) || (D_803E4C88->unk16C->unk2 != 5)) && ((var_t1 != sp48) || (D_803E4C8C == NULL) || (D_803E4C8C->unk16C->unk2 != 5))) {
            D_803E4C86 = 0x40 - (((var_t1 - var_t0) >> 0xA) / D_803E4C94->unk42);
        }
        if ((D_803E4C88 != NULL) && (var_t0 == sp4C)) {
            D_803E4C7A = 1;
            D_803E4C90 = D_803E4C94->unk68;
        }
    } else {
        if (var_t1 < ((D_803E4C94->unk42 << 0x10) + D_803E4C64)) {
            D_803E4C84 = 2;
            D_803E4C64 = var_t1 - (D_803E4C94->unk42 << 0x10);
        } else if (D_803E4C64 < var_t0) {
            D_803E4C64 = var_t0;
            D_803E4C84 = 0;
            if ((D_803E4C88 != NULL) && (var_t0 == sp4C)) {
                D_803E4C7A = 1;
                D_803E4C90 = D_803E4C88;
            }
        }
    }
}

// ESA: func_800345D0
void func_8030E208_71F8B8(void) {
    u8  pad;
    u8  sp3E; // FIXME: this should be s16

    func_8030DD34_71F3E4();
    if (func_802B75CC_6C8C7C(D_803E4C94, 0, D_803E4C5C, D_803E4C60, D_803E4C64, &sp3E, 0) == 0) {
        D_803E4C94->position.xPos.w = D_803E4C5C;
        D_803E4C94->position.zPos.w = D_803E4C60;
        D_803E4C94->position.yPos.w = D_803E4C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        if ((D_803E4C86 >= 0x20) && (D_803E4C94->unk4B < 0x20)) {
            play_sound_effect_at_location(0x17, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
        }
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else {
            if (D_803E4C84 == 0) {
                D_803E4C94->unk54 |= 0xA; //var_t3;
            } else if (D_803E4C84 == 2) {
                D_803E4C94->unk54 |= 0xA;
            }
        }
    } else if (sp3E == 0) {
        D_803E4C94->position.xPos.w = D_803E4C5C;
        D_803E4C94->position.zPos.w = D_803E4C60;
        D_803E4C94->position.yPos.w = D_803E4C64 + D_803A05B4_7B1C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = (u8) D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else if (D_803E4C84 == 0) {
            D_803E4C94->unk54 |= 0xA;
        }
    } else {
        D_803E4C5C = D_803E4C94->position.xPos.w;
        D_803E4C60 = D_803E4C94->position.zPos.w;
        D_803E4C64 = D_803E4C94->position.yPos.w;
        D_803E4C78 = D_803E4C94->unk160;
        D_803E4C94->xVelocity.w = 0;
        D_803E4C94->zVelocity.w = 0;
        D_803E4C94->yVelocity.w = 0;
        func_8030DD34_71F3E4();
        D_803E4C94->position.xPos.w = D_803E4C5C;
        D_803E4C94->position.zPos.w = D_803E4C60;
        D_803E4C94->position.yPos.w = D_803E4C64;
        D_803E4C94->unk160 = D_803E4C78;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = (u8) D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = (Animal *) D_803E4C90;
        if (D_803E4C90 != NULL) {
            func_802FD674_70ED24(D_803E4C94, (Animal *) D_803E4C90);
        } else {
            if (D_803E4C84 == 0) {
                D_803E4C94->unk54 |= 0xA;
            } else if (D_803E4C84 == 2) {
                D_803E4C94->unk54 |= 0xA;
            }
        }
    }
    if (D_803E4C94->unk4B > 0) {
        if ((D_803E4C94->unk70 != NULL) && (D_803E4C94->unk70->unk4C.unk1D)) { //  & 4
            D_803E4C94->unk70->yVelocity.w += D_803E4C94->unk4B << 0xA;
        }
    }
    if ((D_803E4C94->unk6C != NULL) && (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        if (D_803E4C94->unk6C->unk16C->objectType == 54) {
            func_8029B870_6ACF20(D_803E4C94, D_803E4C94->unk6C);
        }
        if ( D_803E4C94->unk6C->unk16C->objectType == OBJECT_TELEPORTER_ACTIVE) {
            func_8029BA70_6AD120(D_803E4C94, D_803E4C94->unk6C);
        }
    }
}

// ESA: func_80034930
void func_8030E69C_71FD4C(void) {
    D_803E4C5C = D_803E4C94->position.xPos.w;
    D_803E4C60 = D_803E4C94->position.zPos.w;
    D_803E4C64 = D_803E4C94->position.yPos.w + D_803E4C94->yVelocity.w;
    D_803E4C78 = D_803E4C94->unk160;
    func_8030DD34_71F3E4();
    D_803E4C94->position.xPos.w = D_803E4C5C;
    D_803E4C94->position.zPos.w = D_803E4C60;
    D_803E4C94->position.yPos.w = D_803E4C64;
    D_803E4C94->unk160 = D_803E4C78;
    D_803E4C94->unk161 = D_803E4C7A;
    D_803E4C94->unk4B = D_803E4C86;
    D_803E4C94->unk68 = D_803E4C88;
    D_803E4C94->unk70 = D_803E4C8C;
    D_803E4C94->unk6C = D_803E4C90;

    if (D_803E4C90 != 0) {
        func_802FD674_70ED24(D_803E4C94, D_803E4C90);
    } else {
        if (D_803E4C84 == 0) {
            D_803E4C94->unk54 |= 0xA;
        } else if (D_803E4C84 == 2) {
            D_803E4C94->unk54 |= 0xA;
        }
    }

    if (D_803E4C94->unk4B > 0) {
        if ((D_803E4C94->unk70 != 0) && (D_803E4C94->unk70->unk4C.unk1D)) {
            D_803E4C94->unk70->yVelocity.w += D_803E4C94->unk4B << 0xA;
        }
    }

    if ((D_803E4C94->unk6C != NULL) && (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal)) {
        if (D_803E4C94->unk6C->unk16C->objectType == 54) {
            func_8029B870_6ACF20(D_803E4C94, D_803E4C94->unk6C);
        }
        if (D_803E4C94->unk6C->unk16C->objectType == OBJECT_TELEPORTER_ACTIVE) {
            func_8029BA70_6AD120(D_803E4C94, D_803E4C94->unk6C);
        }
    }
}

// ESA: func_80034AFC
s16 func_8030E8AC_71FF5C(struct071 *arg0) {
    u8 pad;
    u8 sp2E;

    D_803E4C94 = arg0;
    D_803E4C5C = D_803E4C94->position.xPos.w;
    D_803E4C60 = D_803E4C94->position.zPos.w;
    D_803E4C64 = D_803E4C94->position.yPos.w + D_803E4C94->yVelocity.w;
    D_803E4C56 = D_803E4C5C >> 16;
    D_803E4C58 = D_803E4C60 >> 16;
    D_803E4C78 = D_803E4C94->unk160;
    func_8030DD34_71F3E4();
    if ((func_802B75CC_6C8C7C(D_803E4C94, 0, D_803E4C5C, D_803E4C60, D_803E4C64, &sp2E, 0) == 0) || (sp2E != 0)) {
        D_803E4C94->position.yPos.w = D_803E4C64;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = D_803E4C90;
        if (D_803E4C90 != 0) {
            func_802FD674_70ED24(D_803E4C94, D_803E4C90);
        }
    } else {
        D_803E4C94->position.yPos.w = (D_803E4C64 + D_803A05B4_7B1C64);
        D_803E4C94->yVelocity.w = 0;
        D_803E4C94->unk161 = D_803E4C7A;
        D_803E4C94->unk4B = D_803E4C86;
        D_803E4C94->unk68 = D_803E4C88;
        D_803E4C94->unk70 = D_803E4C8C;
        D_803E4C94->unk6C = D_803E4C90;
        if (D_803E4C90 != 0) {
            func_802FD674_70ED24(D_803E4C94, D_803E4C90);
        }
    }
    return D_803E4C84;
}

// ESA: func_80034C5C
s32 func_8030EA98_720148(void) {
    s32 sp24;
    s32 sp20;
    s32 phi_v1;

    if (D_803E4C78 == 1) {
        func_80311554_722C04(D_803E4C56, D_803E4C58, &sp24, &sp20);
        if (D_803C0740[D_803E4C6C][D_803E4C6E].unk4 & 4) {
            phi_v1 = D_803E1D30[D_803C0740[D_803E4C6C][D_803E4C6E].unk3].unk2 << 3;
        } else {
            phi_v1 = 0;
        }
        if ((((sp24 - sp20) - phi_v1) >> 16) < D_803E4C94->unk42) {
            return 3;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// ESA: func_80034D20
s32 func_8030EB88_720238(s16 arg0, s16 arg1) {
    s32 pad;
    s32 sp20;
    s32 sp1C;

    func_80311554_722C04(arg0, arg1, &sp20, &sp1C);
    if (((sp20 - sp1C) >> 16) < D_803E4C94->unk42) {
        return 3;
    }
    return 0;
}

// ESA: func_80034D7C
s32 func_8030EBF0_7202A0(void) {
    s16 sp3E;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    u8 sp37;

    func_80311A2C_7230DC(D_803E4C56, D_803E4C58, &sp3A, &sp38, D_803E4C78);

    if ((((D_803E4C94->unk162 & 0xF) != 1) && ((D_803E4C94->unk162 & 0xF) != 6)) || (D_803E4C94->unk161 == 0)) {
        sp38 = 0;
        sp3A = 0;
    }

    if ((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) {
        if ((D_803E4C74 + D_803E4C94->unk30) >= 0x40) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) != 0) && (func_8030BC50_71D300((s16) (D_803E4C6C + 1), D_803E4C6E, 0, D_803E4C76, &sp37) != 0)) {
                    return 1;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, 0x3F, D_803E4C76, &sp37) != 0) {
                        return 1;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C+1][D_803E4C6E].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC((s16) ((D_803E4C56 & 0xFFC0) + 0x41), D_803E4C58) >> 0x10) - (func_80310F58_722608((D_803E4C52 & 0xFFC0) + 0x3F, D_803E4C54) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56 + D_803E4C94->unk30, D_803E4C58) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, sp37) >> 0x10)) && (D_803E4C7C != 0) && (sp3E < -0x17) && (sp3E < sp3A)) {
              return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E >= 0x18) && (sp3A < sp3E)) {
              return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56 + D_803E4C94->unk30, D_803E4C58) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 + D_803E4C94->unk30, D_803E4C58, D_803E4C78) >> 0x10)) && (D_803E4C7C != 0) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
        }
    }

    if ((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) {
        if ((D_803E4C74 - D_803E4C94->unk30) < 0) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C - 1, D_803E4C6E, 0x3F, D_803E4C76, &sp37) != 0)) {
                    return 1;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, 0, D_803E4C76, &sp37) != 0) {
                        return 1;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C - 1][D_803E4C6E].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC((s16) ((D_803E4C56 & 0xFFC0) - 1), D_803E4C58) >> 0x10) - (func_80310F58_722608((s16) ((D_803E4C52 & 0xFFC0) + 1), D_803E4C54) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56 - D_803E4C94->unk30, D_803E4C58) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, sp37) >> 0x10)) && (D_803E4C7C != 0) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56 - D_803E4C94->unk30, D_803E4C58) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56 - D_803E4C94->unk30, D_803E4C58, D_803E4C78) >> 0x10)) && (D_803E4C7C != 0) && (sp3E >= 0x18) && (sp3A < sp3E)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3E < -0x17) && (sp3E < sp3A)) {
                return 3;
            }
        }
    }

    if ((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) {
        if ((D_803E4C76 + D_803E4C94->unk32) >= 0x40) {
            sp37 = D_803E4C78;

            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C, (s16) (D_803E4C6E + 1), D_803E4C74, 0, &sp37) != 0)) {
                    return 2;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, D_803E4C76 , 0x3F, &sp37) != 0) {
                        return 2;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E+1].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC(D_803E4C56, (s16) ((D_803E4C58 & 0xFFC0) + 0x41)) >> 0x10) - (func_80310F58_722608(D_803E4C52, (s16) ((D_803E4C54 & 0xFFC0) + 0x3F)) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56, D_803E4C58 + D_803E4C94->unk32) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, sp37) >> 0x10)) && (D_803E4C80 != 0) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56, D_803E4C58 + D_803E4C94->unk32) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 + D_803E4C94->unk32, D_803E4C78) >> 0x10)) && (D_803E4C80 != 0) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
        }
    }

    if ((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) {
        if ((D_803E4C76 - D_803E4C94->unk32) < 0) {
            sp37 = D_803E4C78;
            switch (D_803E4C78) {
            case 0:
                if (((D_803C0740[D_803E4C6C][D_803E4C6E - 1].unk3) != 0) && (func_8030BC50_71D300(D_803E4C6C, D_803E4C6E - 1, D_803E4C74, 0x3F, &sp37) != 0)) {
                    return 2;
                }
                break;
            case 1:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E-1].unk3) == 0) {
                    if (func_8030BD50_71D400(D_803E4C6C, D_803E4C6E, D_803E4C74, 0, &sp37) != 0) {
                        return 2;
                    }
                    sp37 = 0;
                }
                break;
            case 2:
                if ((D_803C0740[D_803E4C6C][D_803E4C6E-1].unk3) == 0) {
                    if (D_803E4C94->unk163 & 2) {
                        if (((func_8031124C_7228FC(D_803E4C56, (s16) ((D_803E4C58 & 0xFFC0) - 1)) >> 0x10) - (func_80310F58_722608(D_803E4C52, (s16) ((D_803E4C54 & 0xFFC0) + 1)) >> 0x10)) < -9) {
                            return 3;
                        }
                    }
                    sp37 = 0;
                }
                break;
            }

            switch (sp37) {
            case 1:
                if (func_8030EB88_720238(D_803E4C56, D_803E4C58 - D_803E4C94->unk32) == 3) {
                    return 3;
                }
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 0:
                func_80311BF8_7232A8(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            case 2:
                func_80311AA8_723158(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C);
                break;
            }

            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, sp37) >> 0x10)) && (D_803E4C80 != 0) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
        } else {
            if ((D_803E4C78 == 1) && (func_8030EB88_720238(D_803E4C56, D_803E4C58 - D_803E4C94->unk32) == 3)) {
                return 3;
            }
            func_80311A2C_7230DC(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, &sp3E, &sp3C, D_803E4C78);
            if (((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58 - D_803E4C94->unk32, D_803E4C78) >> 0x10)) && (D_803E4C80 != 0) && (sp3C >= 0x18) && (sp38 < sp3C)) {
                return 3;
            }
            if ((D_803E4C94->unk163 & 2) && (sp3C < -0x17) && (sp3C < sp38)) {
                return 3;
            }
        }
    }

    return 0;
}

// ESA: func_80035DE8
s32 func_80310030_7216E0(void) {
    s16 sp36;
    s16 sp34;
    s16 sp32;
    s16 sp30;

    s32 pad;

    func_80311A2C_7230DC(D_803E4C52, D_803E4C54, &sp32, &sp30, D_803E4C94->unk160);

    if ((((D_803E4C94->unk162 & 0xF) != 1) && ((D_803E4C94->unk162 & 0xF) != 6)) || (D_803E4C94->unk161 == 1)) {
        sp30 = 0;
        sp32 = 0;
    }
    func_80311A2C_7230DC(D_803E4C56, D_803E4C58, &sp36, &sp34, D_803E4C78);
    if ((D_803E4C64 >> 0x10) < (func_80310EE4_722594(D_803E4C56, D_803E4C58, D_803E4C78) >> 0x10)) {
        if (((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) && (sp36 < -0x17) && (sp36 < sp32)) {
            return 3;
        }
        if (((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0))) && (sp36 >= 0x18) && (sp32 < sp36)) {
            return 3;
        }
        if (((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) && (sp34 < -0x17) && (sp34 < sp30)) {
            return 3;
        }
        if (((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0))) && (sp34 >= 0x18) && (sp30 < sp34)) {
            return 3;
        }
    }

    if ((D_803E4C94->unk163 & 2) != 0) {
        if ((D_803E4C7C >= 0) && (sp36 >= 0x18) && (sp32 < sp36)) {
            return 3;
        }
        if ((D_803E4C7C <= 0) && (sp36 < -0x17) && (sp36 < sp32)) {
            return 3;
        }
        if ((D_803E4C80 >= 0) && (sp34 >= 0x18) && (sp30 < sp34)) {
            return 3;
        }
        if ((D_803E4C80 <= 0) && (sp34 < -0x17) && (sp34 < sp30)) {
            return 3;
        }
    }
    return 0;
}

// ESA: func_800360AC
s16 func_803102BC_72196C(void) {
    s16 var_t1;
    s16 var_a2;
    s16 sp12;
    s16 var_v1;
    s16 temp_t7;
    u8 spD;


    sp12 = D_803E4C94->position.yPos.h;
    spD = 0;

    if ((D_803E4C94->unk162 == 1) && (D_803E4C94->unk6C == NULL)) {
        if (D_803E4C78 == 2) {
            if (D_803E1D30[D_803C0740[D_803E4C56 >> 6][D_803E4C58 >> 6].unk3].unk0 == 0) {
                spD = 1;
            }
        } else if (D_803E1D30[D_803C0740[D_803E4C56 >> 6][D_803E4C58 >> 6].unk2].unk0 == 0) {
            spD = 1;
        }
    }

    if (((D_803E4C7C > 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0) && (spD == 0))) && ((D_803E4C74 + D_803E4C94->unk30) >= 0x40)) {

        temp_t7 = ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3;

        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * D_803E4C72)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3);
        }

        // store originals
        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x20) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 0x10) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 2) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk5 & 1) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
    }

    if (((D_803E4C7C < 0) || ((D_803E4C7C == 0) && (D_803E4C80 != 0) && (spD == 0))) && ((D_803E4C74 - D_803E4C94->unk30) < 0)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * D_803E4C72)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C72)) + (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * D_803E4C72)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x10) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 0x20) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 1) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk5 & 2) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 - 1][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 1;
        }
    }

    if (((D_803E4C80 > 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0) && (spD == 0))) && ((D_803E4C76 + D_803E4C94->unk32) >= 0x40)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C70)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk0 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk0 * D_803E4C70)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 1].unk1 * D_803E4C70)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x80) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 0x40) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 8) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk5 & 4) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 1].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
    }

    if (((D_803E4C80 < 0) || ((D_803E4C80 == 0) && (D_803E4C7C != 0) && (spD == 0))) && ((D_803E4C76 - D_803E4C94->unk32) < 0)) {
        temp_t7 = ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * D_803E4C70)) >> 3;
        var_t1 = MAX(sp12, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk0 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk0 * D_803E4C70)) >> 3);

        if ((D_803E4C94->unk160 == 2) && (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3 != 0)) {
            var_t1 = MAX(var_t1, ((D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk1 * (0x40 - D_803E4C70)) + (D_803C0740[D_803E4C68 + 1][D_803E4C6A + 0].unk1 * D_803E4C70)) >> 3);
        }

        var_v1 = var_a2 = temp_t7;

        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 0x40) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 0x80) {
            var_v1 = MAX(var_v1, temp_t7 + (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk1 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk5 & 4) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A + 0].unk3].unk2 * 8));
        }
        if (D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk5 & 8) {
            var_a2 = MIN(var_a2, temp_t7 - (D_803E1D30[D_803C0740[D_803E4C68 + 0][D_803E4C6A - 1].unk3].unk2 * 8));
        }

        if (((var_v1 != temp_t7) || (var_a2 != temp_t7)) && (var_t1 < (var_v1 - 0xA)) && (var_a2 < (var_t1 + D_803E4C94->unk42))) {
            return 2;
        }
    }

    return 0;
}

// ESA: func_80036FB4
s32 func_80310E10_7224C0(s16 arg0, s16 arg1) {
    s16 i;

    if ((D_803E4C94->unk18C == 0) || ((D_803E4C94->unk163 & 4) == 0)) {
        return 1;
    }

    for (i = 0; i < D_803E4C94->unk18C; i++) {
        if ((arg0 >= D_803E93B0[D_803E4C94->unk18D[i]].unk0) && (arg0 <= D_803E93B0[D_803E4C94->unk18D[i]].unk3) &&
            (arg1 >= D_803E93B0[D_803E4C94->unk18D[i]].unk1) && (arg1 <= D_803E93B0[D_803E4C94->unk18D[i]].unk4)) {
            return 1;
        }
    }
    return 0;
}

// ESA: func_80037098
s32 func_80310EE4_722594(s16 x, s16 z, u8 arg2) {
    switch (arg2) {
    case 0:
    case 1:
        return func_8031124C_7228FC(x, z);
    case 2:
        return func_80310F58_722608(x, z);
    }
}

// ESA: func_800370FC
s32 func_80310F58_722608(s16 arg0, s16 arg1) {
    s16 temp_t0;
    s16 temp_v0;

    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t9;

    s16 _x;
    s16 _y;

    _x = arg0 >> 6;
    _y = arg1 >> 6;

    if (D_803C0740[_x][_y].unk3 == 0) {
        return 0x40000000;
    }
    if (_x < 0) {
        return D_803C0740[0][MIN(MAX(0, _y), 128)].unk1 << 0x13;
    }
    if (_x >= 0x48) {
        return D_803C0740[0][MIN(MAX(0, _y), 128)].unk1 << 0x13;
    }
    if (_y < 0) {
        return D_803C0740[_x][0].unk1 << 0x13;
    }
    if (_y >= 0x80) {
        return D_803C0740[_x + 1][-1].unk1 << 0x13;
    }

    temp_v0 = arg0 & 0x3F;
    temp_t0 = arg1 & 0x3F;

    if (D_803C0740[_x + 0][_y + 0].unk4 & 2) {
        if (temp_v0 < temp_t0) {
            temp_t3 = D_803C0740[_x + 0][_y + 0].unk1 << 0xD;
            temp_t4 = D_803C0740[_x + 0][_y + 1].unk1 << 0xD;
            temp_t5 = D_803C0740[_x + 1][_y + 1].unk1 << 0xD;
            return (temp_t3 << 6) + ((temp_t5 - temp_t4) * temp_v0) + ((temp_t4 - temp_t3) * temp_t0);
        } else {
            temp_t3 = D_803C0740[_x + 0][_y + 0].unk1 << 0xD;
            temp_t5 = D_803C0740[_x + 1][_y + 1].unk1 << 0xD;
            temp_t6 = D_803C0740[_x + 1][_y + 0].unk1 << 0xD;
            return ((temp_t3 << 6)) + ((temp_t6 - temp_t3) * temp_v0) + ((temp_t5 - temp_t6) * temp_t0);
        }
    } else if ((temp_v0 + temp_t0) < 0x40) {
        temp_t3 = D_803C0740[_x + 0][_y + 0].unk1 << 0xD;
        temp_t4 = D_803C0740[_x + 0][_y + 1].unk1 << 0xD;
        temp_t6 = D_803C0740[_x + 1][_y + 0].unk1 << 0xD;
        return ((temp_t3 << 6)) + ((temp_t6 - temp_t3) * temp_v0)  + ((temp_t4 - temp_t3) * temp_t0);
    } else {
        temp_t4 = D_803C0740[_x + 0][_y + 1].unk1 << 0xD;
        temp_t5 = D_803C0740[_x + 1][_y + 1].unk1 << 0xD;
        temp_t6 = D_803C0740[_x + 1][_y + 0].unk1 << 0xD;
        return ((temp_t5 << 6)) + ((temp_t4 - temp_t5) * (0x40 - temp_v0)) + ((temp_t6 - temp_t5) * (0x40 - temp_t0));
    }
}

// ESA: func_800373B0
s32 func_8031124C_7228FC(s16 x, s16 y) {
    s16 temp_t0;
    s16 temp_v0;

    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t9;

    s16 _x;
    s16 _y;

    _x = x >> 6;
    _y = y >> 6;

    if (_x < 0) {
        return D_803C0740[0][MIN(MAX(0, _y), 128)].unk0 << 0x13;
    }
    if (_x >= 0x48) {
        return D_803C0740[0][MIN(MAX(0, _y), 128)].unk0 << 0x13;
    }
    if (_y < 0) {
        return D_803C0740[_x + 0][0].unk0 << 0x13;
    }
    if (_y >= 0x80) {
        return D_803C0740[_x + 1][-1].unk0 << 0x13;
    }

    temp_v0 = x & 0x3F;
    temp_t0 = y & 0x3F;

    if (D_803C0740[_x][_y].unk4 & 1) {
        if (temp_v0 < temp_t0) {
            temp_t3 = D_803C0740[_x + 0][_y + 0].unk0 << 0xD;
            temp_t4 = D_803C0740[_x + 0][_y + 1].unk0 << 0xD;
            temp_t6 = D_803C0740[_x + 1][_y + 1].unk0 << 0xD;
            return (temp_t3 << 6) + (((temp_t6) - temp_t4) * temp_v0) + ((temp_t4 - temp_t3) * temp_t0);
        } else {
            temp_t3 = D_803C0740[_x + 0][_y + 0].unk0 << 0xD;
            temp_t6 = D_803C0740[_x + 1][_y + 1].unk0 << 0xD;
            temp_t5 = D_803C0740[_x + 1][_y + 0].unk0 << 0xD;
            return (temp_t3 << 6) + ((temp_t5 - temp_t3) * temp_v0) + (((temp_t6) - temp_t5) * temp_t0);
        }
    } else if ((temp_v0 + temp_t0) < 0x40) {
        temp_t3 = D_803C0740[_x + 0][_y + 0].unk0 << 0xD;
        temp_t4 = D_803C0740[_x + 0][_y + 1].unk0 << 0xD;
        temp_t5 = D_803C0740[_x + 1][_y + 0].unk0 << 0xD;
        return (temp_t3 << 6) + (((temp_t5) - temp_t3) * temp_v0) + (((temp_t4) - temp_t3) * temp_t0);
    } else {
        temp_t4 = D_803C0740[_x + 0][_y + 1].unk0 << 0xD;
        temp_t6 = D_803C0740[_x + 1][_y + 1].unk0 << 0xD;
        temp_t5 = D_803C0740[_x + 1][_y + 0].unk0 << 0xD;
        return (temp_t6 << 6) + ((temp_t4 - temp_t6) * (0x40 - temp_v0) + ((temp_t5 - temp_t6) * (0x40 - temp_t0)));
    }
}

// ESA: func_800376A0
void func_80311554_722C04(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3) {
    s16 temp_t0;
    s16 temp_t2;
    s16 temp_t3;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_t8;
    s32 temp_t9;
    s16 temp_v0;

    temp_v0 = arg0 >> 6;
    temp_t3 = arg1 >> 6;

    if (temp_v0 < 0) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[0][MIN(MAX(0, temp_t3), 128)].unk1 << 0x13;
        return;
    }

    if (temp_v0 >= 0x48) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[0][MIN(MAX(0, temp_t3), 128)].unk1 << 0x13;
        return;
    }

    if (temp_t3 < 0) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[temp_v0][0].unk1 << 0x13;
        return;
    }
    if (temp_t3 >= 0x80) {
        *arg2 = 0x40000000;
        *arg3 = D_803C0740[temp_v0+1][-1].unk1 << 0x13;
        return;
    }

    temp_t0 = arg0 & 0x3F;
    temp_t2 = arg1 & 0x3F;

    if ((D_803C0740[temp_v0][temp_t3].unk4 & 1) != 0) {
        if (temp_t0 < temp_t2) {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
            temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
            *arg3 = (temp_t8 << 6) + ((temp_t7 - temp_t9) * temp_t0) + ((temp_t9 - temp_t8) * temp_t2);
        } else {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
            temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
            *arg3 = (temp_t8 << 6) + ((temp_t6 - temp_t8) * temp_t0) + ((temp_t7 - temp_t6) * temp_t2);
        }
    } else if ((temp_t0 + temp_t2) < 0x40) {
        temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk0 << 0xD;
        temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
        temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
        *arg3 = (temp_t8 << 6) + ((temp_t6 - temp_t8) * temp_t0) + ((temp_t9 - temp_t8) * temp_t2);
    } else {
        temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk0 << 0xD;
        temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk0 << 0xD;
        temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk0 << 0xD;
        *arg3 = (temp_t7 << 6) + ((temp_t9 - temp_t7) * (0x40 - temp_t0)) + ((temp_t6 - temp_t7) * (0x40 - temp_t2));
    }

    if (D_803C0740[temp_v0 + 0][temp_t3 + 0].unk3 == 0) {
        *arg2 = 0x40000000;
        return;
    }
    if ((D_803C0740[temp_v0 + 0][temp_t3 + 0].unk4 & 2) != 0) {
        if (temp_t0 < temp_t2) {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk1 << 0xD;
            temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk1 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk1 << 0xD;
            *arg2 = (temp_t8 << 6) + ((temp_t7 - temp_t9) * temp_t0) + ((temp_t9 - temp_t8) * temp_t2);
        } else {
            temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk1 << 0xD;
            temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk1 << 0xD;
            temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk1 << 0xD;
            *arg2 = (temp_t8 << 6) + ((temp_t6 - temp_t8) * temp_t0) + ((temp_t7 - temp_t6) * temp_t2);
        }
    } else if ((temp_t0 + temp_t2) < 0x40) {
        temp_t8 = D_803C0740[temp_v0 + 0][temp_t3 + 0].unk1 << 0xD;
        temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk1 << 0xD;
        temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk1 << 0xD;
        *arg2 = (temp_t8 << 6) + ((temp_t6 - temp_t8) * temp_t0) + ((temp_t9 - temp_t8) * temp_t2);
    } else {
        temp_t9 = D_803C0740[temp_v0 + 0][temp_t3 + 1].unk1 << 0xD;
        temp_t7 = D_803C0740[temp_v0 + 1][temp_t3 + 1].unk1 << 0xD;
        temp_t6 = D_803C0740[temp_v0 + 1][temp_t3 + 0].unk1 << 0xD;
        *arg2 = (temp_t7 << 6) + ((temp_t9 - temp_t7) * (0x40 - temp_t0)) + ((temp_t6 - temp_t7) * (0x40 - temp_t2));
    }
}

// ESA: func_80037C10
void func_80311A2C_7230DC(s16 xPos, s16 zPos, s16 *xVel, s16 *zVel, u8 arg4) {
    switch (arg4) {
    case 1:
        func_80311BF8_7232A8(xPos, zPos, xVel, zVel);
        break;
    case 0:
        func_80311BF8_7232A8(xPos, zPos, xVel, zVel);
        break;
    case 2:
        func_80311AA8_723158(xPos, zPos, xVel, zVel);
        break;
    }
}

// ESA: func_80037C8C
void func_80311AA8_723158(s16 arg0, s16 arg1, s16 *arg2, s16 *arg3) {
    s16 x;
    s16 y;

    u8 x0y1;
    u8 x1y1;
    u8 x1y0;
    u8 x0y0;

    *arg2 = *arg3 = 0;

    x = arg0 >> 6;
    y = arg1 >> 6;

    if ((x >= 0) && (x < 72)) {
        if ((y >= 0) && (y < 128)) {
            x0y0 = D_803C0740[x][y].unk1;
            x0y1 = D_803C0740[x][y+1].unk1;
            x1y1 = D_803C0740[x+1][y+1].unk1;
            x1y0 = D_803C0740[x+1][y].unk1;

            if ((D_803C0740[x][y].unk4 & 0x2) != 0) {
                if ((s16)(arg0 & 0x3F) < (s16)(arg1 & 0x3F)) {
                    *arg2 = (x0y1 - x1y1) * 2;
                    *arg3 = (x0y0 - x0y1) * 2;
                } else {
                    *arg2 = (x0y0 - x1y0) * 2;
                    *arg3 = (x1y0 - x1y1) * 2;
                }
            } else if (((s16)(arg0 & 0x3F) + (s16)(arg1 & 0x3F)) < 64) {
                *arg2 = (x0y0 - x1y0) * 2;
                *arg3 = (x0y0 - x0y1) * 2;
            } else {
                *arg2 = (x0y1 - x1y1) * 2;
                *arg3 = (x1y0 - x1y1) * 2;
            }
        }
    }
}

// ESA: func_80037DA4
void func_80311BF8_7232A8(s16 xPos, s16 zPos, s16 *xVel, s16 *zVel) {
    u8 x0y1;
    u8 x1y1;
    u8 x1y0;
    u8 x0y0;

    s16 x;
    s16 y;

    *xVel = *zVel = 0;

    x = xPos >> 6;
    y = zPos >> 6;

    if ((x >= 0) && (x < 72) &&
        (y >= 0) && (y < 128)) {

        x0y0 = D_803C0740[x+0][y+0].unk0;
        x0y1 = D_803C0740[x+0][y+1].unk0;
        x1y1 = D_803C0740[x+1][y+1].unk0;
        x1y0 = D_803C0740[x+1][y+0].unk0;
        if (D_803C0740[x][y].unk4 & 0x1) {
            if ((s16) (xPos & 0x3F) < (s16) (zPos & 0x3F)) {
                *xVel = (x0y1 - x1y1) * 2;
                *zVel = (x0y0 - x0y1) * 2;
            } else {
                *xVel = (x0y0 - x1y0) * 2;
                *zVel = (x1y0 - x1y1) * 2;
            }
        } else if (((s16) (xPos & 0x3F) + (s16) (zPos & 0x3F)) < 64) {
            *xVel = (x0y0 - x1y0) * 2;
            *zVel = (x0y0 - x0y1) * 2;
        } else {
            *xVel = (x0y1 - x1y1) * 2;
            *zVel = (x1y0 - x1y1) * 2;
        }
    }
}

// ESA: func_80037EB8
s16 func_80311D48_7233F8(Animal *arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 res;

    D_803E4C94 = arg0;
    res = 0;

    func_80311A2C_7230DC(D_803E4C94->position.xPos.h, D_803E4C94->position.zPos.h, &sp2E, &sp2C, D_803E4C94->unk160);

    if (D_803E4C94->xVelocity.w > 0) {
        if (sp2E <= -24) {
            func_80312D94_724444();
            res = 1;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2E <= -12) {
                D_803E4C94->xVelocity.w = 0;
            } else if (sp2E < 0) {
                D_803E4C94->xVelocity.w = (D_803E4C94->xVelocity.w * (24 + (sp2E * 2))) / 24;
            }
        }
    } else if (D_803E4C94->xVelocity.w < 0) {
        if (sp2E >= 24) {
            func_80312D94_724444();
            res = 1;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2E >= 12) {
                D_803E4C94->xVelocity.w = 0;
            } else if (sp2E > 0) {
                D_803E4C94->xVelocity.w = (D_803E4C94->xVelocity.w * (24 - (sp2E * 2))) / 24;
            }
        }
    }

    if (D_803E4C94->zVelocity.w > 0) {
        if (sp2C <= -24) {
            func_80313064_724714();
            res = 2;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2C <= -12) {
                D_803E4C94->zVelocity.w = 0;
            } else if (sp2C < 0) {
                D_803E4C94->zVelocity.w = (D_803E4C94->zVelocity.w * (24 + (sp2C * 2))) / 24;
            }
        }
    } else if (D_803E4C94->zVelocity.w < 0) {
        if (sp2C >= 24) {
            func_80313064_724714();
            res = 2;
        } else if (D_803E4C94->yVelocity.w <= 0) {
            if (sp2C >= 12) {
                D_803E4C94->zVelocity.w = 0;
            } else if (sp2C > 0) {
                D_803E4C94->zVelocity.w = (D_803E4C94->zVelocity.w * (24 - (sp2C * 2))) / 24;
            }
        }
    }
    return res;
}

s32 func_80312054_723704(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x > 71) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x - 1][y + 0].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 0][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 0][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x10)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x1)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x - 1][y + 0].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x - 1][y + 0].unk5 & 0x20)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x - 1][y + 0].unk5 & 0x2)) && ((var_a3 & 0x80) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_803123A4_723A54(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x > 70) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 1][y + 0].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 1][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 1][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x20)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x2)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 1][y + 0].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x + 1][y + 0].unk5 & 0x10)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x + 1][y + 0].unk5 & 0x1)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_803126F4_723DA4(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x >= 72) || (y > 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 0][y - 1].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 0].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 0].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 0].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x40)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 0x4)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 0][y - 1].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x][y - 1].unk5 & 0x80)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x][y - 1].unk5 & 0x8)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

s32 func_80312A44_7240F4(s16 x, s16 y, s16 arg2, s16 arg3, s8 arg4, u8 arg5) {
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t6;
    s16 temp_t8;
    s16 temp_t1;
    s16 temp_v0;
    s16 var_a3;
    s16 var_v0;

    if (arg2 < 0) {
        arg2 = 0;
    }
    if (arg2 > 63) {
        arg2 = 63;
    }
    if ((x <= 0) || (y <= 0)) {
        return 0;
    }
    if ((x >= 72) || (y >= 127)) {
        return 0;
    }

    var_v0 = D_803C0740[x + 0][y + 0].unk4;
    var_a3 = D_803C0740[x + 0][y + 1].unk4;
    if (arg5 == 0) {
        var_a3 = 0;
        var_v0 = 0;
    }

    temp_t6 = D_803C0740[x + 0][y + 1].unk0 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk0 * 8;
    if ((arg3 < (s16) (temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6))) && ((var_v0 & 0x40) == 0)) {
        return 3;
    }

    temp_t6 = D_803C0740[x + 0][y + 1].unk1 * 8;
    temp_t8 = D_803C0740[x + 1][y + 1].unk1 * 8;

    temp_t1 = D_803C0740[x][y].unk3;
    if (temp_t1 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_t1].unk1 * 8) + temp_t0) < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if (temp_t0 < arg3) {
            if ((arg4 == 1) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
            if (((D_803C0740[x][y].unk5 & 0x80)) && ((var_v0 & 0x20) == 0)) {
                return 3;
            }
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_t1].unk2 * 8))) {
            if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
                return 3;
            }
        } else if ((arg4 == 2) && ((var_v0 & 0x80) == 0)) {
            return 3;
        } else if (((D_803C0740[x][y].unk5 & 8)) && ((var_v0 & 0x10) == 0)) {
            return 3;
        }
    }

    temp_v0 = D_803C0740[x + 0][y + 1].unk3;
    if (temp_v0 != 0) {
        temp_t0 = temp_t6 + (((temp_t8 - temp_t6) * arg2) >> 6);
        if (((D_803E1D30[temp_v0].unk1 * 8) + temp_t0) < arg3) {
            return 2;
        } else if (temp_t0 < arg3) {
            if (((D_803C0740[x + 0][y + 1].unk5 & 0x40)) && ((var_a3 & 0x20) == 0)) {
                return 3;
            }
            return 2;
        } else if (arg3 < (temp_t0 - (D_803E1D30[temp_v0].unk2 * 8))) {
            return 1;
        } else if (((D_803C0740[x + 0][y + 1].unk5 & 4)) && ((var_a3 & 0x10) == 0)) {
            return 3;
        }
        return 1;
    }
    return 0;
}

// handle_x_velocity_something
// ESA: func_80038E68
void func_80312D94_724444(void) {
    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if (ABS(D_803E4C94->xVelocity.h) > 10) {
            do_rumble(0, 0x19, 0x37, 5, 0);
        } else if (ABS(D_803E4C94->xVelocity.h) > 3) {
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }

    if ((ABS(D_803E4C94->xVelocity.w) >= FTOFIX32(6.0)) && (D_803E4C94->unk16C->unk82.unk2)) {
        func_802DBA58_6ED108(8, D_803D552C);
        spawn_dizzy_starts_small();
    }

    if ((D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FLYING_DOG) || (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FIRE_FOX)) {
        if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h >> 1) - 4), -1, 0);
        } else {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h >> 2) - 4), -1, 0);
        }

    } else if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+HELI_RABBIT) {
        func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->xVelocity.h) - 4), -1, 0);
    }

    if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+WALRUS) {
        D_803E4C94->xVelocity.w = -(D_803E4C94->xVelocity.w >> 2);
    } else {
        D_803E4C94->xVelocity.w = -((D_803E4C94->xVelocity.w * 3) >> 2);
    }

    D_803E4C94->unk54 |= (2|8);
}

// handle_z_velocity_something
// ESA: func_800390D4
void func_80313064_724714(void) {

    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if (ABS(D_803E4C94->zVelocity.h) > 10) {
            do_rumble(0, 0x19, 0x37, 5, 0);
        } else if (ABS(D_803E4C94->zVelocity.h) > 3) {
            do_rumble(0, 0xD, 0x19, 5, 0);
        }
    }

    if ((ABS(D_803E4C94->zVelocity.w) >= FTOFIX32(6.0)) && (D_803E4C94->unk16C->unk82.unk2)) {
        func_802DBA58_6ED108(9, D_803D552C);
        spawn_dizzy_starts_small();
    }

    if ((D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FLYING_DOG) || (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+FIRE_FOX)) {
        if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h >> 1) - 4), -1, 0);
        } else {
            func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h >> 2) - 4), -1, 0);
        }

    } else if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+HELI_RABBIT) {
        func_802B38FC_6C4FAC(D_803E4C94, MAX(0, ABS(D_803E4C94->zVelocity.h) - 4), -1, 0);
    }

    if (D_803E4C94->unk16C->objectType == OB_TYPE_ANIMAL_OFFSET+WALRUS) {
        D_803E4C94->zVelocity.w = -(D_803E4C94->zVelocity.w >> 2);
    } else {
        D_803E4C94->zVelocity.w = -((D_803E4C94->zVelocity.w * 3) >> 2);
    }

    D_803E4C94->unk54 |= (2|8);
}

// some collision?
// ESA: func_80039340
void func_80313334_7249E4(void) {
    if (D_803E4C94 == D_801D9ED8.animals[gCurrentAnimalIndex].animal) {
        if ((ABS(D_803E4C94->xVelocity.h) + ABS(D_803E4C94->zVelocity.h)) > 15) {
            do_rumble(0, 25, 55, 5, 0);
        } else if ((ABS(D_803E4C94->xVelocity.h) + ABS(D_803E4C94->zVelocity.h)) > 5) {
            do_rumble(0, 13, 25, 5, 0);
        }
    }
    D_803E4C94->xVelocity.h = 0;
    D_803E4C94->zVelocity.h = 0;
    D_803E4C94->unk54 |= (2|8);
}

// CURRENT (765)
#if 0
// ESA: func_800393F8
s32 func_80313448_724AF8(Animal *arg0, s32 arg1, s32 arg2, s32 arg3) {

    s16 tmp1;
    s16 tmp2;

    D_803E4C94 = arg0;

    D_803E4C52 = arg0->position.xPos.h;
    D_803E4C54 = arg0->position.zPos.h;

    D_803E4C5C = arg0->position.xPos.w + arg1;
    D_803E4C60 = arg0->position.zPos.w + arg2;
    D_803E4C64 = arg0->position.yPos.w + arg3;

#pragma _permuter sameline start
    tmp2 = D_803E4C56 = D_803E4C5C >> 16; \
    tmp1 = D_803E4C60 >> 16; \
    D_803E4C58 = D_803E4C60 >> 16; \
    D_803E4C68 = D_803E4C52 >> 6; \
    D_803E4C6A = D_803E4C54 >> 6;
#pragma _permuter sameline end

    D_803E4C6C = tmp2 >> 6;
    D_803E4C6E = tmp1 >> 6;

    D_803E4C70 = D_803E4C52 & 0x3F; // take bottom 6 bits
    D_803E4C72 = D_803E4C54 & 0x3F; // take bottom 6 bits
    D_803E4C74 = tmp2 & 0x3F; // take bottom 6 bits
    D_803E4C76 = tmp1 & 0x3F; // take bottom 6 bits

    D_803E4C7C = D_803D5530->xVelocity.w;
    D_803E4C80 = D_803D5530->zVelocity.w;
    D_803E4C78 = arg0->unk160;

    if (((func_8030B494_71CB44()) == 0) && (func_8030EA98_720148() == 0)) {
        D_803E4C94->position.xPos.w = D_803E4C5C;
        D_803E4C94->position.zPos.w = D_803E4C60;
        D_803E4C94->position.yPos.w = D_803E4C64;
        D_803E4C94->unk160 = D_803E4C78;
        return 1;
    } else {
        return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_71C140/func_80313448_724AF8.s")
#endif

#if 0
s32 D_803A5590_7B6C40[] = {
    0x00000300, 0x00000300, 0x00000300, 0x000006D6,
    0x00000708, 0x0000073A, 0x000007A0, 0x00000850,
    0x00000900, 0x00000938, 0x00000970, 0x000009A8,
    0x000009E0, 0x00000A18, 0x00000A50, 0x00000A88,
    0x00000AC0, 0x00000B00, 0x00000B0A, 0x00000B14,
    0x00000B1E, 0x00000B28, 0x00000B32, 0x00000B3C,
    0x00000B46, 0x00000B50, 0x00000B5A, 0x00000B64,
    0x00000B6E, 0x00000B78, 0x00000B82, 0x00000B8C,
    0x00000B96, 0x00000BA0, 0x00000BAA, 0x00000BC0,
    0x00000BC0, 0x00000BB6, 0x00000BAC, 0x00000BA2,
    0x00000B98, 0x00000B8E, 0x00000B84, 0x00000B7A,
    0x00000B70, 0x00000B66, 0x00000B5C, 0x00000B52,
    0x00000B48, 0x00000B3E, 0x00000B34, 0x00000B2A,
    0x00000B20, 0x00000B16, 0x00000B00, 0x00000AC8,
    0x00000A90, 0x00000A58, 0x00000A20, 0x000009E8,
    0x000009B0, 0x00000978, 0x00000940, 0x00000900,
    0x00000850, 0x000007A0, 0x0000073A, 0x00000708,
    0x000006D6, 0x00000300, 0x00000300, 0x00000300
};
#endif

void func_803135FC_724CAC(Animal *arg0)
{
    s32 temp_t1;
    int new_var2;
    s32 temp_t2;
    s32 temp_v0;
    s32 phi_a2;
    s32 phi_a3;

    temp_v0 = arg0->position.xPos.h >> 6;
    new_var2 = temp_v0;

    if (temp_v0 < 36) {
        phi_a2 = D_803A5590_7B6C40[temp_v0 - 1];
        phi_a3 = D_803A5590_7B6C40[temp_v0];
    }
    else {
        phi_a2 = D_803A5590_7B6C40[temp_v0];
        phi_a3 = D_803A5590_7B6C40[temp_v0 + 1];
    }

    if ((phi_a2 < (arg0->position.yPos.h + arg0->unk42)) || (phi_a3 < (arg0->position.yPos.h + arg0->unk42))) {
        new_var2 = arg0->position.xPos.h - (temp_v0 << 6);
        temp_t2 = phi_a2 + (((phi_a3 - phi_a2) * new_var2) >> 6);
        if (temp_t2 < (arg0->position.yPos.h + arg0->unk42)) {
            arg0->position.yPos.h = temp_t2 - arg0->unk42;
            arg0->yVelocity.w = MIN(arg0->yVelocity.w, 0);
        }
    }
}

// ESA: func_8003950C
void func_803136B0_724D60(Animal *arg0) {
    arg0->unk160 = func_803136FC_724DAC(arg0->position.xPos.h, arg0->position.zPos.h, (arg0->position.yPos.h + (arg0->unk42 >> 1)));
}

// ESA: func_80039554
u8 func_803136FC_724DAC(s16 x, s16 z, s16 y) {
    if (D_803C0740[x >> 6][z >> 6].unk3 == 0) {
        return 0;
    }
    if ((func_80310F58_722608(x, z) >> 16) < y) {
        return 2;
    } else {
        return 1;
    }
}
