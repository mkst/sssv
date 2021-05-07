#include <ultra64.h>
#include "common.h"


s32 func_80362B00_7741B0(Animal *a) {
    if ((a->unk4A != 0) || (a->unk366 == 5) || (a->unk366 == 2)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B38_7741E8(Animal *a) {
    if (a->unk16C->unkA0 & 4) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B60_774210(Animal *a) {
    s32 tmp = a->unk162 & 0xF;
    if ((tmp == 4) || (tmp == 5) || (tmp == 6) || (tmp == 7)) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362B9C_77424C(Animal *a) {
    if ((a->unk16C->unkA0 & 0xC00) != 0) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362BC4_774274(Animal *a) {
    if ((a->unk16C->unk9E & 0xE0) != 0) {
        return 1;
    } else {
        return 0;
    }
}

s32 func_80362BEC_77429C(Animal *a) {
    if (a->unk162 == 2) {
        return 1;
    } else {
        return 0;
    }
}

void func_80362C10_7742C0(Animal *arg0) {
    if (func_80305084_716734(arg0->xPos - arg0->unk2A4, arg0->zPos - arg0->unk2A6, arg0->unk2D4, arg0->unk2D8) > 100) {
        if (arg0->unk2DC == 0) {
            arg0->unk275 = 10;
            arg0->unk2D4 = arg0->xPos - arg0->unk2A4;
            arg0->unk2D8 = arg0->zPos - arg0->unk2A6;
            arg0->unk2DC = 1;
        } else {
            arg0->unk2A0 = 6;
            arg0->unk275 = -1;
            arg0->unk2DC = 0;
        }
    }
}

// contains jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80362CC4_774374.s")
// contains jump table
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_803633C4_774A74.s")

void func_80363738_774DE8(Animal *arg0, Animal *arg1, u16 arg2) {
    if (arg0->unk320 == 0) {
        arg0->unk28E = 0;
        arg0->unk28C = 9;
        arg0->unk298.h = arg2;
        arg0->unk294.w = arg1;
        func_80363DB4_775464(arg0, arg1, -1, arg2);
    } else {
        func_803638E8_774F98(arg0);
    }
}

void func_8036379C_774E4C(Animal *arg0) {
    arg0->unk28C = 10;
    arg0->unk290 = 0;
    func_8037B784_78CE34(arg0);
    arg0->unk2AC = arg0->unk320;
}

void func_803637D4_774E84(Animal *arg0, Animal *arg1, u16 arg2) {
    arg0->unk28C = 8;
    arg0->unk298.h = arg2;
    arg0->unk294.w = arg1;
    arg0->unk29A.b = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    func_80363CC8_775378(arg0);
    func_80309E4C_71B4FC(arg1);
    arg0->unk270 = 1;
}

void func_80363844_774EF4(Animal *arg0, s16 arg1) {
    arg0->unk28C = 6;
    arg0->unk294.h[0] = arg1;
    func_80363FB8_775668(arg0, arg1, -0x80, -1);
}

void func_80363880_774F30(Animal *arg0, Animal *arg1) {
    arg0->unk28C = 7;
    arg0->unk294.w = arg1;
    func_80363E88_775538(arg0, arg1);
}

void func_803638A8_774F58(Animal *arg0, Animal *arg1, s16 arg2) {
    arg0->unk28C = 5;
    arg0->unk294.w = arg1;
    arg0->unk298.h = arg2;
    func_80363DB4_775464(arg0, arg1, -1, arg2);
}

void func_803638E8_774F98(Animal *arg0) {
    arg0->unk28C = 0;
    arg0->unk2CC = 0;
    func_80363CC8_775378(arg0);
}

// these two have weird offsets on unk294
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_8036390C_774FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_7741B0/func_80363A0C_7750BC.s")
// void func_80363A0C_7750BC(Animal *arg0, u8 arg1, u8 arg2, s8 arg3, u8 arg4, u8 arg5) {
//     s32 sp2C;
//     s16 temp_t4;
//     s16 temp_v0;
//     s32 temp_a0;
//     s8 temp_t6;
//     void *temp_v1;
//
//     temp_a0 = D_803E8E60[arg1];
//     sp2C = temp_a0;
//     temp_v0 = func_80319B4C_72B1FC(temp_a0, arg0->xPos, arg0->zPos, arg0->yPos);
//     arg0->unk28C = (u16)1;
//     temp_t4 = temp_v0;
//     arg0->unk294.b[0] = (s8) temp_t4;
//     arg0->unk294 = arg1;
//     temp_t6 = (arg3 * 0x10) | (arg0->unk296 & 0xFF0F);
//     arg0->unk294.b[2] = temp_t6;
//     arg0->unk298 = arg2;
//     arg0->unk294.b[2] = (s8) ((arg4 & 0xF) | (temp_t6 & 0xF0));
//     arg0->unk294.b[3] = arg5;
//     arg0->unk29C = sp2C;
//     temp_v1 = sp2C + (temp_t4 * 3);
//     func_80363C48_7752F8(arg0, (s16) ((temp_v1->unk1 << 6) + 0x20), (s16) ((temp_v1->unk2 << 6) + 0x20), (s16) ((temp_v1->unk3 << 6) + 0x20), (?32) arg2, (?32) arg5);
//     arg0->unk294.b[1] += arg3; //(s8) (arg0->unk295 + arg3);
// }

void func_80363B34_7751E4(Animal *arg0, u16 arg1) {
    arg0->unk28C = 3;
    arg0->unk294.b[0] = arg1;
    func_80363C48_7752F8(arg0, arg0->xPos, arg0->zPos, -1, 10, 32);
    arg0->unk290 = func_8012826C() & 3;
}

void func_80363B98_775248(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5) {
    arg0->unk28C = 2;
    arg0->unk294.h[1] = xPos;
    arg0->unk298.h = zPos;
    arg0->unk29A.h = arg3;
    arg0->unk294.b[0] = arg4;
    arg0->unk294.b[1] = arg5;
    func_80363C48_7752F8(arg0, xPos, zPos, arg3, arg4, arg5);
}

void func_80363C0C_7752BC(Animal *arg0, u8 arg1) {
    arg0->unk28C = 4;
    arg0->unk28E = 1;
    arg0->unk290 = 30;
    arg0->unk294.b[0] = arg1;
    func_80363CC8_775378(arg0);
}

void func_80363C48_7752F8(Animal *arg0, s16 xPos, s16 zPos, s16 arg3, s8 arg4, u8 arg5) {
    arg0->unk2A0 = 1;
    arg0->unk2A4 = xPos;
    arg0->unk2A6 = zPos;
    arg0->unk2A8 = arg3;
    arg0->unk2A1 = arg4;
    arg0->unk2A2 = arg5;
    arg0->unk2AC = 0;
    arg0->unk274 = 2;
    arg0->unk275 = arg4;
    arg0->unk278 = xPos;
    arg0->unk27A = zPos;
    arg0->unk27C = arg3;
    arg0->unk2D4 = arg0->xPos - xPos;
    arg0->unk2D8 = arg0->zPos - zPos;
    arg0->unk2DC = 0;
}

void func_80363CC8_775378(Animal *arg0) {
    arg0->unk2A0 = 0;
    arg0->unk2A1 = 0;
    arg0->unk2AC = 0;
    arg0->unk274 = 0;
    arg0->unk275 = 0;
}

void func_80363CE0_775390(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 2;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    if (func_80362BC4_774274(arg1) || func_80362B60_774210(arg1)) {
        arg0->unk27C = arg1->yPos + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363DB4_775464(Animal *arg0, Animal *arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 8;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    if (func_80362BC4_774274(arg1) || func_80362B60_774210(arg0->unk2AC)) {
        arg0->unk27C = arg1->yPos + (arg1->unk42 >> 1) + arg2;
    } else {
        arg0->unk27C = arg2;
    }
    arg0->unk274 = 2;
    arg0->unk275 = arg3;
}

void func_80363E88_775538(Animal *arg0, Animal *arg1) {
    arg0->unk2AC = arg1;
    arg0->unk2A0 = 3;
    arg0->unk2B0 = arg1 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg1->xPos;
    arg0->unk27A = arg1->zPos;
    arg0->unk274 = 2;
    arg0->unk275 = -1;
}

void func_80363EDC_77558C(Animal *arg0, s16 arg1, Animal *arg2) {
    arg0->unk2A8 = arg1;
    arg0->unk2AC = arg2;
    arg0->unk2A0 = 4;
    arg0->unk2A1 = 16;
    arg0->unk2B0 = arg2 == D_801DDD8C[gCurrentAnimalIndex].unk0;
    arg0->unk278 = arg2->xPos;
    arg0->unk27A = arg2->zPos;
    arg0->unk274 = 3;
    arg0->unk275 = 16;
    if (func_80362BC4_774274(arg2) || func_80362B60_774210(arg2)) {
        arg0->unk27C = arg2->yPos + (arg2->unk42 >> 1) + arg1;
    } else {
        arg0->unk27C = arg1;
    }
}

void func_80363FB8_775668(Animal *arg0, u16 arg1, s16 arg2, s16 arg3) {
    arg0->unk2A8 = arg2;
    arg0->unk2A1 = arg3;
    arg0->unk2A0 = 5;
    arg0->unk2AC = 0;
    arg0->unk276 = arg1;
    arg0->unk27C = arg2;
    arg0->unk275 = arg3;
    arg0->unk274 = 1;
}

void func_80363FF0_7756A0(Animal *arg0) {
    switch (arg0->unk28C) {
    case 0:
        func_803638E8_774F98(arg0);
        break;
    case 1:
        func_80363A0C_7750BC(arg0, arg0->unk294.ub[0], arg0->unk298.ub[0], (s8)(arg0->unk294.h[1] >> 12), arg0->unk294.ub[2] & 0xF, arg0->unk294.ub[3]);
        break;
    case 2:
        func_80363B98_775248(arg0, arg0->unk294.h[1], arg0->unk298.h, arg0->unk29A.h, arg0->unk294.b[0], arg0->unk294.ub[1]);
        break;
    case 3:
        func_80363B34_7751E4(arg0, arg0->unk294.ub[0]);
        break;
    case 4:
        func_80363C0C_7752BC(arg0, arg0->unk294.ub[0]);
        break;
    case 5:
        func_803638A8_774F58(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 6:
        func_80363844_774EF4(arg0, arg0->unk294.h[0]);
        break;
    case 7:
        func_80363880_774F30(arg0, arg0->unk294.w);
        break;
    case 8:
        func_803637D4_774E84(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 9:
        func_80363738_774DE8(arg0, arg0->unk294.w, arg0->unk298.h);
        break;
    case 10:
        func_803638E8_774F98(arg0);
        break;
    }
}

void func_80364120_7757D0(u8 arg0, s16 arg1, s16 arg2, Animal *arg3) {
    // skill A
    if (arg0 == 0) {
        switch (D_803D5524->unk9C) {
        case SEAGULL:
            break;
        case LION:
            animal_jump();
            break;
        case HIPPO:
            func_802F0780_701E30(0, 0, 0);
            break;
        case RACING_DOG:
            func_802EF074_700724(arg1);
            break;
        case FLYING_DOG:
            func_802EEF9C_70064C(0, 0, 0);
            break;
        case FOX:
            func_802E89AC_6FA05C();
            break;
        case FROG:
            animal_jump();
            break;
        case RABBIT:
            animal_jump();
            break;
        case KING_RAT:
            func_8035FE6C_77151C(60);
            break;
        case PARROT:
            func_80314600_725CB0();
            break;
        case MOUSE:
            animal_jump();
            break;
        case RACING_MOUSE:
            func_8031FBE8_731298(arg1);
            break;
        case MOUSE2:
            animal_jump();
            break;
        case RACING_FOX:
            func_802E89AC_6FA05C();
            break;
        case RACING_TORTOISE:
            func_803563C8_767A78(arg1);
            break;
        case PIRANA:
            animal_jump();
            break;
        case DOG:
            animal_jump();
            break;
        case RAT:
            rat_drop_mine();
            break;
        case SHEEP:
            animal_jump();
            break;
        case RAM:
            animal_jump();
            break;
        case SPRINGY_THINGY:
            animal_jump();
            break;
        case SPRINGY_RAM:
            animal_jump();
            break;
        case PENGUIN:
            animal_jump();
            break;
        case POLAR_BEAR:
            func_80368D18_77A3C8();
            break;
        case POLAR_TANK:
            func_80368CF0_77A3A0();
            break;
        case HUSKY:
            animal_jump();
            break;
        case SKI_HUSKY:
            func_8036C05C_77D70C(arg1);
            break;
        case WALRUS:
            func_80376CF8_7883A8(arg1);
            break;
        case CAMEL:
            animal_jump();
            break;
        case CANNON_CAMEL:
            func_8036F740_780DF0(D_803D5530->yRotation);
            break;
        case POGO_KANGAROO:
            animal_jump();
            break;
        case BOXING_KANGAROO:
            animal_jump();
            break;
        case DESERT_FOX:
            animal_jump();
            break;
        case ARMED_DESERT_FOX:
            animal_jump();
            break;
        case SCORPION:
            func_803791AC_78A85C();
            break;
        case GORILLA:
            animal_jump();
            break;
        case ELEPHANT:
            func_8037D268_78E918(arg1);
            break;
        case HYENA:
            animal_jump();
            break;
        case HYENA_BIKER:
            func_8035A5A4_76BC54(arg1);
            break;
        case CHAMELEON:
            func_8035C10C_76D7BC();
            break;
        case COOL_COD:
            break;
        }
    } else {
        // skill B
        switch (D_803D5524->unk9C) {
        case SEAGULL:
        case LION:
            lion_roar();
            break;
        case HIPPO:
            drop_sticky_mine();
            break;
        case RACING_DOG:
            func_802EEDE0_700490(arg3);
            break;
        case FLYING_DOG:
            func_802EEFEC_70069C(0, 0, 0);
            break;
        case FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case FIRE_FOX:
            flying_fox_fire_missile(arg3);
            break;
        case FROG:
            frog_croak();
            break;
        case POLAR_BEAR_DEFENDING:
            func_80368D60_77A410(arg1);
            break;
        case RABBIT:
            func_803021A8_713858();
            break;
        case HELI_RABBIT:
            heli_rabbit_drop_bomb(0, 0, 0);
            break;
        case MOUSE:
            func_8031FB30_7311E0(arg1);
            break;
        case RACING_MOUSE:
            func_8031FB78_731228(arg1);
            break;
        case MOUSE2:
            func_8031FB30_7311E0(arg1);
            break;
        case BEAR:
            func_80327B94_739244(arg1);
            break;
        case RACING_FOX:
            func_802E88C0_6F9F70(arg1);
            break;
        case TORTOISE_TANK:
            func_803562C8_767978(arg1);
            break;
        case RACING_TORTOISE:
            func_80356348_7679F8(arg1);
            break;
        case PIRANA:
            func_80382CC0_794370(arg1);
            break;
        case DOG:
            func_802EEF74_700624();
            break;
        case RAT:
            rat_bite();
            break;
        case SHEEP:
            func_8037FEDC_79158C();
            break;
        case RAM:
            ram_headbutt();
            break;
        case SPRINGY_RAM:
            ram_headbutt();
            break;
        case PENGUIN:
            penguin_throw_snowball(arg3);
            break;
        case POLAR_BEAR:
            func_80368D60_77A410(arg1);
            break;
        case POLAR_TANK:
            polar_tank_drop_mine();
            break;
        case HUSKY:
            func_8036C014_77D6C4(arg1);
            break;
        case SKI_HUSKY:
            ski_husky_fire_missile(arg3);
            break;
        case WALRUS:
            walrus_fire_missile(arg3);
            break;
        case CAMEL:
            func_8036F50C_780BBC(arg3);
            break;
        case CANNON_CAMEL:
            camel_cannon_fire_cannon(arg3);
            break;
        case POGO_KANGAROO:
            func_80372698_783D48();
            break;
        case BOXING_KANGAROO:
            func_80372604_783CB4();
            break;
        case DESERT_FOX:
            func_803745C4_785C74(arg1);
            break;
        case ARMED_DESERT_FOX:
            func_8037460C_785CBC();
            break;
        case SCORPION:
            func_80379148_78A7F8(arg3);
            break;
        case HYENA:
            func_8035A590_76BC40(arg1);
            break;
        case HYENA_BIKER:
            biker_hyena_fire_missile(arg3);
            break;
        case CHAMELEON:
            func_8035C180_76D830(arg1);
            break;
        case CHAMELEON_DEFENDING:
            func_8035C180_76D830(arg1);
            break;
        case COOL_COD:
            break;
        }
    }
}
