#include <ultra64.h>
#include "common.h"


extern u8 D_803A6070_7B7720[];
extern u8 D_803A6078_7B7728[];
extern u8 D_803A607C_7B772C[];
extern u8 D_803A608C_7B773C[];
extern u8 D_803A6098_7B7748[];
extern u8 D_803A60B0_7B7760[];
extern u8 D_803A60C4_7B7774[];
extern u8 D_803A60DC_7B778C[];
extern u8 D_803A60F0_7B77A0[];
extern u8 D_803A60F8_7B77A8[];
extern u8 D_803A60FC_7B77AC[];
extern u8 D_803A610C_7B77BC[];
extern u8 D_803A6118_7B77C8[];
extern u8 D_803A6120_7B77D0[];
extern u8 D_803A6124_7B77D4[];
extern u8 D_803A6134_7B77E4[];
extern u8 D_803A6138_7B77E8[];
extern u8 D_803A6160_7B7810[];
extern u8 D_803A6174_7B7824[];
extern u8 D_803A618C_7B783C[];
extern u8 D_803A61A0_7B7850[];
extern u8 D_803A61B8_7B7868[];
extern u8 D_803A61CC_7B787C[];
extern u8 D_803A61DC_7B788C[];
extern u8 D_803A61E8_7B7898[];
extern u8 D_803A6208_7B78B8[];
extern u8 D_803A6224_7B78D4[];
extern u8 D_803A6234_7B78E4[];
extern u8 D_803A6240_7B78F0[];
extern u8 D_803A6258_7B7908[];
extern u8 D_803A6264_7B7914[];
extern u8 D_803A6274_7B7924[];
extern u8 D_803A6280_7B7930[];
extern u8 D_803A6288_7B7938[];
extern u8 D_803A628C_7B793C[];
extern u8 D_803A629C_7B794C[];
extern u8 D_803A62A0_7B7950[];
extern u8 D_803A62B0_7B7960[];
extern u8 D_803A62BC_7B796C[];
extern u8 D_803A62CC_7B797C[];
extern u8 D_803A62D8_7B7988[];
extern u8 D_803A62F0_7B79A0[];
extern u8 D_803A62FC_7B79AC[];
extern u8 D_803A6304_7B79B4[];
extern u8 D_803A6308_7B79B8[];
extern u8 D_803A6310_7B79C0[];
extern u8 D_803A6314_7B79C4[];
extern u8 D_803A631C_7B79CC[];
extern u8 D_803A6320_7B79D0[];
extern u8 D_803A6330_7B79E0[];
extern u8 D_803A633C_7B79EC[];
extern u8 D_803A634C_7B79FC[];
extern u8 D_803A6358_7B7A08[];
extern u8 D_803A6360_7B7A10[];
extern u8 D_803A6364_7B7A14[];
extern u8 D_803A6374_7B7A24[];
extern u8 D_803A6378_7B7A28[];
extern u8 D_803A6380_7B7A30[];
extern u8 D_803A6384_7B7A34[];
extern u8 D_803A6394_7B7A44[];
extern u8 D_803A6398_7B7A48[];
extern u8 D_803A63A0_7B7A50[];
extern u8 D_803A63A4_7B7A54[];
extern u8 D_803A63AC_7B7A5C[];

void func_80328258_739908(s16);
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80327BE0_739290.s")
// close but no cigar
// void func_80327BE0_739290(void) {
//     u8 phi_v0;
//     s16 i;
//
//     if ((D_801D9ED8.unkFFB4 == 2) && (D_801D9ED8.unkFFBA == 0)) {
//         func_80328ACC_73A17C();
//     }
//
//     for (i = 0, phi_v0 = D_803E9828[D_803E9822 + i].unk2 & 0xFFu; (phi_v0 != 0xFF) && (i < 6); i++, phi_v0 = D_803E9828[D_803E9822 + i].unk2 ) {
//         if ((D_803E982C[phi_v0].unk3 == 1) || (D_803E982C[phi_v0].unk3 == 2)) {
//             if ((D_803E982C[phi_v0].unk2 != 1) && (D_803E982C[phi_v0].unk2 != 2) && (D_803E982C[phi_v0].unk2 == 7) &&
//                 (D_801D9ED8.unkFFCE || (D_801D9ED8.unkFFC0 && (D_801D9ED8.unkFFD6 == 0)))) {
//                 func_80328258_739908(i);
//                 i = 6; // break out of loop
//             }
//         }
//     }
//
//     D_803E9836 = D_801D9ED8.unkFFBE;
//     D_803E9838 = D_801D9ED8.unkFFC0;
//     D_803E983A = D_801D9ED8.unkFFC2;
//     D_803E983C = D_801D9ED8.unkFFC4;
//     D_801D9ED8.unkFFCE = 0;
// }

void func_80327DA0_739450(void) {
}

void func_80327DA8_739458(void) {
    switch (D_803E9820 - 1) {
    case 0:
        D_803E9828 = D_803A6070_7B7720; // 0x0001FF00
        D_803E982C = (struct104 *)D_803A6078_7B7728;
        break;
    case 1:
        D_803E9828 = D_803A607C_7B772C; // 0x000200FF
        D_803E982C = D_803A608C_7B773C;
        break;
    case 2:
        D_803E9828 = D_803A6098_7B7748; // 0x001F0001
        D_803E982C = D_803A60B0_7B7760;
        break;
    case 3:
        D_803E9828 = D_803A60C4_7B7774; // 0x00060002
        D_803E982C = D_803A60DC_7B778C;
        break;
    case 4:
        D_803E9828 = D_803A60F0_7B77A0; // 0x0008FF00
        D_803E982C = D_803A60F8_7B77A8;
        break;
    case 5:
        D_803E9828 = D_803A60FC_7B77AC; // 0x000A00FF
        D_803E982C = D_803A610C_7B77BC;
        break;
    case 6:
        D_803E9828 = D_803A6118_7B77C8; // 0x000CFF00
        D_803E982C = D_803A6120_7B77D0;
        break;
    case 7:
        D_803E9828 = D_803A6124_7B77D4; // 0x000EFF00
        D_803E982C = D_803A6134_7B77E4;
        break;
    case 8:
        D_803E9828 = D_803A6138_7B77E8; // 0x00100001
        D_803E982C = D_803A6160_7B7810;
        break;
    case 9:
        D_803E9828 = D_803A6174_7B7824; // 0x00160001
        D_803E982C = D_803A618C_7B783C;
        break;
    case 10:
        D_803E9828 = D_803A61A0_7B7850; // 0x001B0001
        D_803E982C = D_803A61B8_7B7868;
        break;
    case 11:
        D_803E9828 = D_803A61CC_7B787C; // 0x002000FF
        D_803E982C = D_803A61DC_7B788C;
        break;
    case 12:
        D_803E9828 = D_803A61E8_7B7898; // 0x00210002
        D_803E982C = D_803A6208_7B78B8;
        break;
    case 13:
        D_803E9828 = D_803A6224_7B78D4; // 0x002500FF
        D_803E982C = D_803A6234_7B78E4;
        break;
    case 14:
        D_803E9828 = D_803A6240_7B78F0; // 0x002600FF
        D_803E982C = D_803A6258_7B7908;
        break;
    case 15:
        D_803E9828 = D_803A6264_7B7914; // 0x002800FF
        D_803E982C = D_803A6274_7B7924;
        break;
    case 16:
        D_803E9828 = D_803A6280_7B7930; // 0x002CFF00
        D_803E982C = D_803A6288_7B7938;
        break;
    case 17:
        D_803E9828 = D_803A628C_7B793C; // 0x002DFF00
        D_803E982C = D_803A629C_7B794C;
        break;
    case 18:
        D_803E9828 = D_803A62A0_7B7950; // 0x002E00FF
        D_803E982C = D_803A62B0_7B7960;
        break;
    case 19:
        D_803E9828 = D_803A62BC_7B796C; // 0x003200FF
        D_803E982C = D_803A62CC_7B797C;
        break;
    case 20:
        D_803E9828 = D_803A62D8_7B7988; // 0x003300FF
        D_803E982C = D_803A62F0_7B79A0;
        break;
    case 21:
        D_803E9828 = D_803A62FC_7B79AC; // 0x0035FF00
        D_803E982C = D_803A6304_7B79B4;
        break;
    case 22:
        D_803E9828 = D_803A6308_7B79B8; // 0x0036FF00
        D_803E982C = D_803A6310_7B79C0;
        break;
    case 23:
        D_803E9828 = D_803A6314_7B79C4; // 0x0038FF00
        D_803E982C = D_803A631C_7B79CC;
        break;
    case 24:
        D_803E9828 = D_803A6320_7B79D0; // 0x003900FF
        D_803E982C = D_803A6330_7B79E0;
        break;
    case 25:
        D_803E9828 = D_803A633C_7B79EC; // 0x003B00FF
        D_803E982C = D_803A634C_7B79FC;
        break;
    case 26:
        D_803E9828 = D_803A6358_7B7A08; // 0x003DFF00
        D_803E982C = D_803A6360_7B7A10;
        break;
    case 27:
        D_803E9828 = D_803A6364_7B7A14; // 0x0000FF00
        D_803E982C = D_803A6374_7B7A24;
        break;
    case 28:
        D_803E9828 = D_803A6378_7B7A28; // 0x001EFF00
        D_803E982C = D_803A6380_7B7A30;
        break;
    case 29:
        D_803E9828 = D_803A6384_7B7A34; // 0x002BFF00
        D_803E982C = D_803A6394_7B7A44;
        break;
    case 30:
        D_803E9828 = D_803A6398_7B7A48; // 0x0042FF00
        D_803E982C = D_803A63A0_7B7A50;
        break;
    case 31:
        D_803E9828 = D_803A63A4_7B7A54; // 0x0043FF00
        D_803E982C = D_803A63AC_7B7A5C;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328258_739908.s")
// miles away
// void func_80328258_739908(s16 arg0) {
//     struct104 *temp_v1;
//
//     func_8032AA94_73C144();
//     temp_v1 = &D_803E982C[D_803E9828[D_803E9822 + arg0].unk2]; // ->unk2
//     D_803E9822 = temp_v1->unk1;
//     D_803E9824 = &D_803E9828[D_803E9822];
//
//     D_803D5520 = &D_801D9ED8.unk0[D_803E9824];
//     D_803D5524 = *D_803D5520;
//     D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C = &D_801D9ED8.unk0[D_803E9824];
//
//     func_803283DC_739A8C();
//     func_802B2EA8_6C4558();
//
//     D_803D5530->unk46 = (u16) D_803D5530->unk16C->mass;
//     func_802C9BA4_6DB254(D_801D9ED8.animals[gCurrentAnimalIndex].animal);
//
//     switch (temp_v1->unk0) {
//     case 0:
//         break;
//     case 1:
//         func_802DBA58_6ED108(15, D_803D552C);
//         break;
//     case 2:
//         func_802DBA58_6ED108(15, D_803D552C);
//         break;
//     }
// }

void func_803283DC_739A8C(void) {
    func_803284C4_739B74();

    if (D_803D5524->unk9C != ELEPHANT) {
        D_803D552C->unk308 = 0;
    }
    D_803D552C->unk30A = 0;
    D_803D552C->unk30C = 0;
    D_803D552C->unk30E = 0;

    switch (D_803E9824) { // current animal id
    case FLYING_DOG:
        D_803D552C->unk302 = 0;
        D_803D5530->unk28 = 0;
        D_803D5530->yPos.h += 35;
        break;
    case FOX:
        break;
    case FIRE_FOX:
        D_803D552C->unk302 = 0;
        D_803D5530->unk28 = 0;
        D_803D5530->yPos.h += 35;
        break;
    default:
    case FROG:
    case TORTOISE_TANK:
        break;
    }
}

Camera* func_803284C4_739B74(void) {
    struct035 *temp_v1;
    Camera *temp_v0;

    temp_v1 = D_803D5524;
    temp_v0 = &D_803F28E0[D_803F2A98];
    temp_v0->unk4E = temp_v1->unkCA;
    temp_v0->unk54 = temp_v1->unkD0;
    temp_v0->unk56 = temp_v1->unkD2;
    temp_v0->unk58 = temp_v1->unkCC;
    temp_v0->unk60 = temp_v1->unkCE;
    return temp_v0;
}

void func_80328520_739BD0(void) {
    switch (D_803D552C->unk366) {
    case 1:
        if (D_803D5530->health <= 0) {
            D_803D552C->unk366 = 2U;
            func_80328918_739FC8();
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        }
        break;
    case 3:
        if (D_803D5530->health <= 0) {
            D_803D552C->unk366 = 5U;
            func_80328918_739FC8();
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            switch (D_803D5524->unkE6) {
            case 0:
                D_803F2D30.score += 50;
                break;
            case 1:
                D_803F2D30.score += 100;
                break;
            case 2:
                D_803F2D30.score += 200;
                break;
            case 3:
                D_803F2D30.score += 350;
                break;
            case 4:
                D_803F2D30.score += 500;
                break;
            }
            if (D_803D5530->unk246 != 0) {
                func_803153B0_726A60(D_803D5530, &D_803E4D40[D_803D5530->unk246 - 1], 0);
                func_803191B0_72A860(D_803D5530);
            }
        } else if (D_803D5524->unkD8 >= D_803D5530->health) {
            D_803D552C->unk366 = 4U;
            D_803D552C->unk328 = D_803D5544;
        }
        break;
    case 4:
        if (D_803D5524->unkD8 < D_803D5530->health) {
            D_803D552C->unk366 = 3U;
        } else if (D_803D5530->health <= 0) {
            D_803D552C->unk366 = 5U;
            func_80328918_739FC8();
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.0f);
            if (D_803D5544 >= 2) {
                switch (D_803D5524->unkE6) {
                case 0:
                    D_803F2D30.score += 50;
                    break;
                case 1:
                    D_803F2D30.score += 100;
                    break;
                case 2:
                    D_803F2D30.score += 200;
                    break;
                case 3:
                    D_803F2D30.score += 350;
                    break;
                case 4:
                    D_803F2D30.score += 500;
                    break;
                }
            }
            if (D_803D5530->unk246 != 0) {
                func_803153B0_726A60(D_803D5530, &D_803E4D40[D_803D5530->unk246 - 1], 0);
                func_803191B0_72A860(D_803D5530);
            }
        }
        break;
    case 5:
        if (D_803D5530->health > 0) {
            D_803D552C->unk366 = 4U;
            D_803D552C->unk328 = D_803D5544;
            D_803D552C->unk36A = 1;
        }
        break;
    case 6:
        break;
    }
}

void func_80328918_739FC8(void) {
    D_803D552C->unk328 = D_803D5544;
    D_803D552C->unk36A = 1;
    D_803D552C->unk348 = 0;
    D_803D552C->unk34A = 0;
    D_803D552C->unk358 = 0;
    D_803D552C->unk363 = 0;
    D_803D552C->unk369 = 0;
    D_803D552C->unk365 = ATTACK_NONE;
    D_803D552C->unk36E = 0;
    D_803D552C->unk364 = 0;
    D_803D552C->unk2EC = 0;

    if (D_803D5524->unk9C == CHAMELEON_DEFENDING) {
        load_animal(CHAMELEON);
    }

    D_803D552C->unk30A = 0;
    D_803D552C->unk34C = 0;
    D_803D552C->unk356 = 0;
    D_803D5530->unk46 = D_803D5530->unk16C->mass;
    func_802C9BA4_6DB254(D_803D5530);

    switch (D_803D5530->state) {
    case 3:
    case 4:
    case 5:
    case 6:
        D_803D5530->state = 2;
        break;
    case 22:
    case 23:
    case 24:
        D_803D5530->state = 21;
        break;
    case 42:
        D_803D5530->state = 41;
        break;
    case 62:
    case 63:
        D_803D5530->state = 61;
        break;
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
        D_803D5530->state = 101;
        break;
    case 122:
    case 123:
        D_803D5530->state = 121;
        break;
    case 142:
    case 143:
    case 144:
        D_803D5530->state = 141;
        break;
    case 162:
        D_803D5530->state = 161;
        break;
    case 182:
    case 183:
    case 184:
    case 185:
        D_803D5530->state = 181;
        break;
    case 202:
    case 203:
    case 204:
        D_803D5530->state = 201;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328ACC_73A17C.s")

s32 func_80329BAC_73B25C(s16 arg0, s16 arg1) {
    s16 sp66;
    s16 sp64;
    s16 sp62;
    s16 sp60;
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    s16 sp58;
    s16 sp56;
    s16 sp54;
    u8  sp53;
    u8  sp52;

    if (D_801D9ED8.animals[arg1].animal->unk4B > 20) {
        return 0;
    }

    sp64 = D_801D9ED8.animals[arg0].animal->xPos.h;
    sp66 = D_801D9ED8.animals[arg0].animal->zPos.h;
    sp62 = D_801D9ED8.animals[arg0].animal->yPos.h + (D_801D9ED8.animals[arg0].animal->unk42 / 3);
    sp53 = D_801D9ED8.animals[arg0].animal->unk160;

    sp5A = D_801D9ED8.animals[arg1].animal->xPos.h;
    sp5C = D_801D9ED8.animals[arg1].animal->zPos.h;
    sp58 = D_801D9ED8.animals[arg1].animal->yPos.h + (D_801D9ED8.animals[arg1].animal->unk42 / 3);
    sp52 = D_801D9ED8.animals[arg1].animal->unk160;

    sp60 = D_801D9ED8.animals[arg0].animal->unk42 / 4;
    sp5E = (D_801D9ED8.animals[arg0].animal->unk42 * 6) / 4;

    sp56 = D_801D9ED8.animals[arg1].animal->unk42 / 4;
    sp54 = (D_801D9ED8.animals[arg1].animal->unk42 * 6) / 4;

    if (((s16)D_803F2D50.segment == 0) &&
        (D_803F2D50.unk52 == 7) &&
        func_803233A0_734A50(
            sp64,
            sp66,
            sp62,
            sp5A,
            sp5C,
            sp58)
        ) {
        return 0;
    }
    if (func_8033C9CC_74E07C(sp64, sp66, sp62 + sp60, sp53, sp5A, sp5C, sp58 + sp56, sp52, 0, 0) == 0) {
        return 1;
    }
    if (func_8033C9CC_74E07C(sp5A, sp5C, sp58 + sp54, sp52, sp64, sp66, sp62 + sp60, sp53, 0, 0) == 0) {
        return 1;
    }

    if (func_8033C9CC_74E07C(sp64, sp66, sp62 + sp5E, sp53, sp5A, sp5C, sp58 + sp56, sp52, 0, 0) == 0) {
        return 1;
    }
    if (func_8033C9CC_74E07C(sp5A, sp5C, sp58 + sp54, sp52, sp64, sp66, sp62 + sp5E, sp53, 0, 0) == 0) {
        return 1;
    }
    return 0;
}

void func_80329F44_73B5F4(void) {
    s32 phi_a0;
    s32 phi_a1;
    s16 tmp;
    s16 upd;
    s16 sp1A;
    s16 sp18;

    upd = 32;
    phi_a0 = tmp = func_8032A164_73B814(1, 0);
    if ((tmp >= 0) && (tmp < upd)) {
        sp1A = 1;
        sp18 = 0;
        upd = tmp;
    }
    tmp = func_8032A164_73B814(-1, 0);
    if ((tmp >= 0) && (tmp < upd)) {
        sp1A = -1;
        sp18 = 0;
        upd = tmp;
    }
    tmp = func_8032A164_73B814(0, 1);
    if ((tmp >= 0) && (tmp < upd)) {
        sp1A = 0;
        sp18 = 1;
        upd = tmp;
    }
    tmp = func_8032A164_73B814(0, -1);
    if ((tmp >= 0) && (tmp < upd)) {
        sp1A = 0;
        sp18 = -1;
        upd = tmp;
    }
    // original value has changed
    if (upd != 32) {
        phi_a1 = ((sp1A * 40) << 16) / 20;
        phi_a0 = ((sp18 * 40) << 16) / 20;
    } else {
        s16 xpos = D_801D9ED8.animals[0].animal->xPos.h & 0x3F;
        s16 zpos = D_801D9ED8.animals[0].animal->zPos.h & 0x3F;

        phi_a1 = FTOFIX32(1.0);
        phi_a0 = FTOFIX32(1.0);
        if (xpos >= 32) {
            phi_a1 = -FTOFIX32(1.0);
        }
        if (zpos >= 32) {
            phi_a0 = -FTOFIX32(1.0);
        }
    }
    D_801D9ED8.animals[0].animal->unk308 = phi_a1 >> 8;
    D_801D9ED8.animals[0].animal->unk30A = phi_a0 >> 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032A164_73B814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032A710_73BDC0.s")
// miles away
// void func_8032A710_73BDC0(void) {
//     s16 temp_a0;
//     s16 temp_t0;
//     s16 temp_v0_6;
//     s16 temp_v1;
//     s16 temp_v1_2;
//     s16 temp_v1_3;
//     Animal *temp_a1;
//     struct036 *temp_a2;
//     void *temp_t7;
//     void *temp_t9;
//     void *temp_t9_2;
//     void *temp_v0;
//     Animal *temp_v0_2;
//     s8 *temp_v0_7;
//     Animal *temp_v0_8;
//     s16 phi_v0;
//
//     // temp_v0 = D_803D552C;
//     temp_t0 = D_803D552C->unk30E;
//     D_803D552C->unk320 = 0;
//     func_8032AA94_73C144();
//     temp_a2 = &D_801D9ED8 + temp_t0; // + ( * 8);
//     temp_v0_2 = temp_a2->animal;
//     temp_v1 = temp_v0_2->health;
//     temp_v0_2->health = (s16) D_801D9ED8.animals->health;
//     D_801D9ED8.animals->health = temp_v1;
//     temp_v1_2 = temp_v0_2->skillAEnergy;
//     temp_v0_2->skillAEnergy = (s16) D_801D9ED8.animals->skillAEnergy;
//     D_801D9ED8.animals->skillAEnergy = temp_v1_2;
//     temp_v1_3 = temp_v0_2->skillBEnergy;
//     temp_v0_2->skillBEnergy = (s16) D_801D9ED8.animals->skillBEnergy;
//     D_801D9ED8.animals->skillBEnergy = temp_v1_3;
//     D_801D9ED8.animals->unk4A = (u8)0;
//     temp_a2->animal->unk4A = (u8)0;
//     temp_a1 = D_801D9ED8.animals;
//     temp_a1->unk4F = (u8) (((((u32) (temp_a2->animal->unk4C << 0x1A) >> 0x1F) << 5) & 0x20) | (temp_a1->unk4F & 0xFFDF));
//     temp_v0_2 = temp_a2->animal;
//     temp_v0_2->unk4F = (u8) (((((u32) (temp_a1->unk4C << 0x1A) >> 0x1F) << 5) & 0x20) | (temp_v0_2->unk4F & 0xFFDF));
//     D_803D5520 = &D_801D9ED8.animals;
//     D_803D5524 = (s32) D_801D9ED8.unk3EB0;
//     temp_t7 = D_801D9ED8.animals;
//     D_803D5528 = temp_t7;
//     D_803D552C = temp_t7;
//     D_803D5530 = temp_t7;
//     if (gCurrentAnimalIndex == 0) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = (u16)0;
//     D_803D553A = (u16)0;
//     D_803D5520 = &D_801DD800;
//     D_803D5530->unk16C = &D_801DD800;
//     gCurrentAnimalIndex = temp_t0;
//     D_803D5520 = (void *) temp_a2->unk3EB0;
//     D_803D5524 = (void *) temp_a2->unk3EB0;
//     temp_t9 = temp_a2->animal;
//     D_803D5528 = temp_t9;
//     D_803D552C = temp_t9;
//     D_803D5530 = temp_t9;
//     if (temp_t0 == gCurrentAnimalIndex) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = temp_t0;
//     D_803D553A = (u16)0;
//     D_803D552C->unk366 = (u8)1;
//     D_803D552C->unk328 = (u16) D_803D5544;
//     D_803D552C->unk36A = (u8)2;
//     D_803D5530->unk163 = (u8) D_801D9ED8.animals->unk163;
//     D_803D5530->unk18C = (u8) D_801D9ED8.animals->unk18C;
//     phi_v0 = (u16)0;
// loop_7:
//     temp_v0_6 = phi_v0 + 1;
//     // (D_803D5530 + phi_v0)->unk18D = (u8) (D_801D9ED8.animals + phi_v0)->unk18D;
//     phi_v0 = temp_v0_6;
//     if ((s32) temp_v0_6 < 4) {
//         goto loop_7;
//     }
//     D_803D5530->unk18C = (u8) D_801D9ED8.animals->unk18C;
//     D_803E9824 = (u16) temp_a2->unk3EB0->unk9C;
//     temp_a0 = (s16) D_803E9824;
//     temp_v0_7 = (temp_a0 * 2) + &D_803A63B0_7B7A60;
//     D_803E9820 = temp_v0_7[0];
//     D_803E9822 = temp_v0_7[1];
//     check_and_set_species_encountered(temp_a0); //, &D_803D5538, temp_a2, (u8)1);
//     func_80327DA8_739458();
//     func_803283DC_739A8C();
//     func_802B2EA8_6C4558();
//     func_802C9BA4_6DB254(D_803D5530);
//     D_803D5520 = &D_801D9ED8.animals;
//     D_803D5524 = (s32) D_801D9ED8.unk3EB0;
//     temp_t9_2 = D_801D9ED8.animals;
//     D_803D5528 = temp_t9_2;
//     D_803D552C = temp_t9_2;
//     D_803D5530 = temp_t9_2;
//     if (gCurrentAnimalIndex == 0) {
//         D_803D5538 = (u8)1;
//     } else {
//         D_803D5538 = (u8)0;
//     }
//     D_803D553C = (u16)0;
//     D_803D553A = (u16)0;
//     play_sound_effect_at_location(SFX_UNKNOWN_40, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h,  D_803D5530->yPos.h, 1.0f);
// }

void func_8032AA94_73C144(void) {
    func_80321920_732FD0(D_803D552C->unk320, 0, 0);
    D_803D552C->unk320 = 0;
    if (D_803D5530->state == 0xDD) {
        func_802E4AB8_6F6168();
    }
}

void load_animal(s16 animalId) {
    *D_803D5520 = &D_801D9ED8.unk0[animalId];
    D_803D5530->unk16C =  &D_801D9ED8.unk0[animalId];

    D_803E9824 = animalId;

    D_803E9820 = D_803A63B0_7B7A60[D_803E9824].unk0;
    D_803E9822 = D_803A63B0_7B7A60[D_803E9824].unk1;
    func_80327DA8_739458();
    D_803D5530->unk46 = D_803D5530->unk16C->mass;
    func_802C9BA4_6DB254(D_803D5530);
    D_803D5524 = *D_803D5520;
}

// load animal info screen if first time player is transferring into an animal
void check_and_set_species_encountered(s16 animal_id) {
    if ((D_803E4D28 & 8) == 0) {
        // if first time visiting then load TV info screen
        if (((D_8023F260.speciesSeen[(s8) (animal_id >> 3)] & (1 << (s8)(animal_id % 7))) == 0) && (D_803E1BC0 == 0)) {
            D_8023F260.speciesSeen[(s8) (animal_id >> 3)] |= (1 << (s8)(animal_id % 7));
            func_8038F694_7A0D44();
        }
    }
}

void set_species_as_encountered(s16 animal_id) {
    D_8023F260.speciesSeen[(s8) (animal_id >> 3)] |= (1 << (s8) (animal_id % 7));
}

// funny effect 1: weird continuous growing/shrinking
#ifdef NON_MATCHING
void func_8032AC98_73C348(void) {
    Animal *a;
    s16 i;

    for (i = 0; i < D_803D553E; i++) {
        a = D_801D9ED8.animals[i].animal;
        if (a != NULL) {
            if ((D_801D9ED8.animals[i].unk0->unk9C != EVO_GLITCHY) &&
                (a->unk366 != 6)) {
                D_803D5520 = &D_801D9ED8.animals[i].unk0;
                D_803D5524 = D_801D9ED8.animals[i].unk0;

                D_803D552C = a;
                D_803D5528 = a;
                D_803D5530 = a;

                if (D_803D5528 == NULL) {} // helps regalloc

                if (gCurrentAnimalIndex == i) {
                    D_803D5538 = 1;
                } else {
                    D_803D5538 = 0;
                }
                D_803D553C = i;
                D_803D553A = 0;

                func_80380620_791CD0(D_803D552C, 2000, 20, 512, 0);
                D_803D552C->unk348 = 512;
                D_803D552C->unk34A = 512;
                D_803D552C->unk36B = 100;
            }
        }
  }
    if ((D_803A6CE4 & (4 | 2)) == 0) {
        D_803A6CE4 |= 2;
    } else {
        D_803A6CE4 |= 4;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032AC98_73C348.s")
#endif

// funny effect 2: infinite a+b energy? flips camera
void func_8032AE34_73C4E4(void) {
    s16 i;

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        D_801D9ED8.unk0[i].unkDA[0] = 1;
        D_801D9ED8.unk0[i].unkE0[0] = 1;
    }
    if ((D_803A6CE4 & 5) == 0) {
        D_803A6CE4 |= 1;
    } else {
        D_803A6CE4 |= 4;
    }
}

// funny effect 3: tiny body / big head
void func_8032AEA0_73C550(void) {
    struct035 *tmp;
    s16 i;

    if ((D_803A6CE4 & 8) != 0) {
        func_803421E0_753890(100);
        return;
    }

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        tmp = &D_801D9ED8.unk0[i];
        tmp->unkC8 = tmp->unkC8 / 3;
        tmp->unkA4 = tmp->unkA4 / 3;
        tmp->unkAA = tmp->unkAA / 3;
        tmp->unkAC = tmp->unkAC / 3;
        tmp->unkC2 = tmp->unkC2 / 3;
        tmp->unkC4 = tmp->unkC4 / 3;
        // different scaling factor?
        tmp->unkD0 = tmp->unkD0 / 2;
        tmp->unkD2 = tmp->unkD2 / 2;
    }

    D_803A6CE4 |= (8 | 4);
}

// funny effect 4: turns bear into unibear
#ifdef NON_MATCHING
void func_8032B084_73C734(void) {
    Animal *a;
    s32 id = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->unk0;
    if (id == 0x116) {
        D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
        D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

        a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        D_803D5528 = a;
        D_803D552C = a;
        D_803D5530 = a;

        if (D_803D5528 == NULL) {};

        D_803D5538 = 1;
        D_803D553C = gCurrentAnimalIndex;
        D_803D553A = 0;

        load_animal(MYSTERY_BEAR);
        func_802B2EA8_6C4558();
        D_803A6CE4_7B8394 |= 4;
    } else if (id == 0x118) {
        D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
        D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

        a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
        D_803D5528 = a;
        D_803D552C = a;
        D_803D5530 = a;

        if (D_803D5528 == NULL) {};

        D_803D5538 = 1;
        D_803D553C = gCurrentAnimalIndex;
        D_803D553A = 0;

        load_animal(BEAR);
        func_802B2EA8_6C4558();
        D_803A6CE4_7B8394 &= ~4;
    } else {
        func_803421E0_753890(100);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_8032B084_73C734.s")
#endif

// cheat 5: nothing?
void func_8032B1C8_73C878(void) {
    D_803A6CE4 &= ~(1 | 2 | 4);
}
