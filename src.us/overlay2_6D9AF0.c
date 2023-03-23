#include <ultra64.h>
#include "common.h"

// DMA intro
void func_802C8440_6D9AF0(void) {
    func_803572C0_768970();
    func_803747CC_785E7C();
    func_802DD040_6EE6F0(0);
    memset_bytes((u8 *)&D_801D9ED8.animals, 0U, sizeof(D_801D9ED8.animals));
    memset_bytes((u8 *)&D_801D9ED8.unk4040, 0U, sizeof(D_801D9ED8.unk4040));
    D_803D553E = 0;
    func_802C7C80_6D9330(); // load all stats
    D_803E9820 = 27;
    D_803E9822 = 0;
    D_803E9824 = EVO_MICROCHIP;
    gCurrentAnimalIndex = 0;
    func_80327DA8_739458(); // waypoints?
    spawn_animal(0, 0, 0, 0, 0x7F, EVO_MICROCHIP, 1);
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
    D_803D5548 = D_803D554A = 0;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302 = (D_803F2D50.unk4E * 256) / 360;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.unk4E * 256) / 360;
    D_803F6450 = 1;
    D_803F2CE6 = 0;
    D_803D5558 = 0;
}

void func_802C85EC_6D9C9C(void) {
    Animal *a;

    if (D_803F2D50.animalId != EVO_MICROCHIP) {
        D_803E9824 = D_803F2D50.animalId;
        D_803E9820 = D_803A63B0_7B7A60[D_803E9824].unk0;
        D_803E9822 = D_803A63B0_7B7A60[D_803E9824].unk1;
        gCurrentAnimalIndex = D_803D553E;
        a = D_801D9ED8.animals[0].animal;
        spawn_animal(a->xPos.h, a->zPos.h, a->yPos.h, 0, 0x7F, D_803E9824, 1);
        func_80327DA8_739458();
        D_801D9ED8.animals[0].animal->unk366 = 3;
        D_801D9ED8.animals[0].unk0 = &D_801DD800;
        D_801D9ED8.animals[0].animal->unk16C = &D_801DD800;
        D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
        D_801D9ED8.animals[0].animal->unk4A = 0;
    }
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk302 = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.unkFFA8 = (D_803F2D50.unk4E << 8) / 360;
    D_803F2AA3 = 0;
    D_803F2AA2 = 0;
}

void func_802C87E0_6D9E90(void) {
    D_80204278->usedHilites = 0;
    D_80204278->usedVtxs = 0;
    D_803E1B04 = 0;
    D_803F3310 = 0;
    if (D_803F2D10.unk0 == 0) {
        D_803D5540 = (D_803D5540 + 1) & 0xFF;
        D_803D5542 = (D_803D5542 + 1) % 360;
        D_803D5544 += 1;
    }
}

void func_802C8878_6D9F28(void) {
    u16 i;
    Animal *a;

    func_803747F4_785EA4();
    func_80357200_7688B0();

    D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
    D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

    D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    a = D_803D5528;
    D_803D5530 = a;
    D_803D552C = a;

    D_803D5538 = 1;
    D_803D553C = gCurrentAnimalIndex;
    D_803D553A = 0;

    func_80327BE0_739290();
    func_8030A8EC_71BF9C();

    gDPSetTextureLUT(D_801D9E88++, G_TT_RGBA16);

    for (i = 0; i < D_803D553E; i++) {
        if ((D_801D9ED8.animals[i].animal != 0) &&
            (D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) &&
            (D_801D9ED8.animals[i].animal->unk366 != 6)) {
            if (i == gCurrentAnimalIndex) {
                add_multiple_lights();
                clear_used_lights();
            }

            D_803D5520 = &D_801D9ED8.animals[i];
            D_803D5524 = D_801D9ED8.animals[i].unk0;

            D_803D5528 = D_801D9ED8.animals[i].animal;
            a = D_803D5528;
            D_803D5530 = a;
            D_803D552C = a;

            if (1) {}; // required!

            if (i == gCurrentAnimalIndex) {
                D_803D5538 = 1;
            } else {
                D_803D5538 = 0;
            }
            D_803D553C = i;
            D_803D553A = 0;

            func_802FB49C_70CB4C(D_803D5530);
            if (D_803F2D10.unk0 == 0) {
                if (D_803D5530->unk4A == 0) {
                    if (i == gCurrentAnimalIndex) {
                        func_8035E200_76F8B0();
                        if (D_803D552C->unk366 == 2) {
                            func_802AA1EC_6BB89C();
                        } else if (D_803D5524->unk9C != EVO) {
                            if (D_803F2D10.unk0 == 0) {
                                func_802A78CC_6B8F7C();
                                func_802AAAB0_6BC160();
                                func_8038C760_79DE10();
                            }
                        } else if ((D_803F2D10.unk0 == 0) && (D_803D552C->unk365 != 0xA)) {
                            func_802AA424_6BBAD4();
                        }
                    } else if ((D_803D5530->xVelocity.w != 0) || (D_803D5530->zVelocity.w != 0) || (D_803D5530->yVelocity.w != 0) || (D_803D5530->unk68 != 0) || (D_803D5530->unk70 != 0) || (D_803D5530->unk162 != 1)) {
                        if (D_803D552C->unk366 == 5) {
                            func_802AA1EC_6BB89C();
                        } else {
                            func_80309F38_71B5E8();
                            func_802A935C_6BAA0C();
                            func_802AA0A0_6BB750();
                        }
                    } else if (D_803D552C->unk366 != 5) {
                        func_80309F38_71B5E8();
                        func_802A935C_6BAA0C();
                        func_802AA0A0_6BB750();
                    }
                    D_803D5530->unk10.w = D_803D5530->xPos.w + D_803D5530->xVelocity.w;
                    D_803D5530->unk14.w = D_803D5530->zPos.w + D_803D5530->zVelocity.w;
                    D_803D5530->unk18.w = D_803D5530->yPos.w + D_803D5530->yVelocity.w;
                    func_80328520_739BD0();
                }
            }
            if (D_801D9ED8.animals[i].animal != NULL) {
                switch (D_801D9ED8.animals[i].unk0->unk9C) {
                case LION:
                    func_802F1730_702DE0();
                    break;
                case HIPPO:
                    func_802EF0C0_700770();
                    break;
                case RACING_HIPPO:
                    func_802F036C_701A1C();
                    break;
                case RACING_DOG:
                    func_802EA7F0_6FBEA0();
                    break;
                case FLYING_DOG:
                    func_802EBB34_6FD1E4();
                    break;
                case FOX:
                    func_802E5000_6F66B0();
                    break;
                case FIRE_FOX:
                    func_802E620C_6F78BC();
                    break;
                case FROG:
                    func_80302200_7138B0();
                    break;
                case RABBIT:
                    func_80300210_7118C0();
                    break;
                case HELI_RABBIT:
                    func_80301248_7128F8();
                    break;
                case PARROT:
                case PARROT_ATTACKING:
                    func_80313790_724E40();
                    break;
                case MOUSE:
                case MOUSE2:
                    func_8031C7A0_72DE50();
                    break;
                case RACING_MOUSE:
                    func_8031D624_72ECD4();
                    break;
                case HARD_MOUSE:
                    func_8031E6A0_72FD50();
                    break;
                case HELI_MOUSE:
                    func_8031F858_730F08();
                    break;
                case BEAR:
                    func_80323680_734D30();
                    break;
                case CRAZY_BEAR:
                    func_803250A8_736758();
                    break;
                case MYSTERY_BEAR:
                    func_80326260_737910();
                    break;
                case RACING_FOX:
                    func_802E7394_6F8A44();
                    break;
                case TORTOISE_TANK:
                    func_80352380_763A30();
                    break;
                case RACING_TORTOISE:
                    func_80354188_765838();
                    break;
                case TORTOISE_TANK_DEFENDING:
                case RACING_TORTOISE_DEFENDING:
                    func_80355130_7667E0();
                    break;
                case DOG:
                    func_802ED108_6FE7B8();
                    break;
                case KING_RAT:
                case RAT:
                    func_8035E430_76FAE0();
                    break;
                case SHEEP:
                case RAM:
                    func_8035FE90_771540();
                    break;
                case SPRINGY_THINGY:
                case SPRINGY_RAM:
                    func_80360D94_772444();
                    break;
                case PENGUIN:
                case KING_PENGUIN:
                    func_80364780_775E30();
                    break;
                case POLAR_BEAR_DEFENDING:
                case POLAR_BEAR:
                    func_80365F10_7775C0();
                    break;
                case POLAR_TANK:
                    func_803677C4_778E74();
                    break;
                case HUSKY:
                case CRAZY_HUSKY:
                    func_8036A05C_77B70C();
                    break;
                case SKI_HUSKY:
                    func_80368DD0_77A480();
                    break;
                case WALRUS:
                    func_80374C70_786320();
                    break;
                case VULTURE:
                case VULTURE2:
                    func_8036C0B0_77D760();
                    break;
                case CAMEL:
                case CANNON_CAMEL:
                    func_8036D700_77EDB0();
                    break;
                case BOXING_KANGAROO:
                    func_8036F7A0_780E50();
                    break;
                case POGO_KANGAROO:
                    func_80370C84_782334();
                    break;
                case DESERT_FOX:
                case ARMED_DESERT_FOX:
                    func_803726E0_783D90();
                    break;
                case SCORPION:
                    func_80376D40_7883F0();
                    break;
                case GORILLA:
                    func_803791E0_78A890();
                    break;
                case ELEPHANT:
                    func_8037B800_78CEB0();
                    break;
                case HYENA:
                    func_80358E3C_76A4EC();
                    break;
                case HYENA_BIKER:
                    func_803574E0_768B90();
                    break;
                case CHAMELEON:
                case SNEAKY_CHAMELEON:
                    func_8035A5F0_76BCA0();
                    break;
                case EVO_MICROCHIP:
                case EVO:
                    func_8035C1A0_76D850();
                    break;
                case SEAGULL:
                case SEAGULL2:
                    func_80380920_791FD0();
                    break;
                case PIRANA:
                    func_80382050_793700();
                    break;
                case COOL_COD:
                    func_80382CF0_7943A0();
                    break;
                case DESERT_FOX_ATTACKING:
                    func_80373788_784E38();
                    break;
                case EVO_SHELLSUIT:
                    func_80389B30_79B1E0();
                    break;
                }
            }
            if (i == gCurrentAnimalIndex) {
                // (re)set lights?
                add_single_light(&D_801D9E88);
            }
            if (D_803D552C->unk366 != 6) {
                func_802DA90C_6EBFBC(D_803D5530);
            }
        }
    }
    D_80286562 = D_80286560;
}

void func_802C8FC0_6DA670(OSContPad *cont) {

    if (D_803D6110 != 0) {
        D_803D6110--;
    }

    if (D_803F2D10.unk0 == 0) {
        // save current controller input
        D_801D9ED8.unkFFBA = D_801D9ED8.unkFFB4;
        D_801D9ED8.unkFFBC = D_801D9ED8.unkFFB6;
        D_801D9ED8.unkFFB8 = D_801D9ED8.unkFFB2;
        D_801D9ED8.unkFFD0 = D_801D9ED8.unkFFC2;
        D_801D9ED8.unkFFD2 = D_801D9ED8.unkFFC4;
        D_801D9ED8.unkFFD4 = D_801D9ED8.unkFFBE;
        D_801D9ED8.unkFFD6 = D_801D9ED8.unkFFC0;
    }
    if ((D_803F2D10.unk0 != 0) || (D_803D6110 != 0) || (D_803F2AA3 != 0) ||
        (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk364 == 17)) {
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
        D_801D9ED8.unkFFC6 = 0;
        D_801D9ED8.unkFFC8 = 0;
        D_801D9ED8.unkFFCA = 0;
        D_801D9ED8.unkFFCC = 0;
        return;
    }

    if (cont->button & A_BUTTON) {
        D_801D9ED8.unkFFB2 = 1U;
    } else {
        D_801D9ED8.unkFFB2 = 0U;
    }
    if (cont->button & B_BUTTON) {
        D_801D9ED8.unkFFB6 = 1U;
    } else {
        D_801D9ED8.unkFFB6 = 0U;
    }
    if (cont->button & CONT_UP) {
        D_801D9ED8.unkFFBE = 1U;
    } else {
        D_801D9ED8.unkFFBE = 0U;
    }
    if (cont->button & CONT_DOWN) {
        D_801D9ED8.unkFFC0 = 1U;
    } else {
        D_801D9ED8.unkFFC0 = 0U;
    }
    if (cont->button & CONT_LEFT) {
        D_801D9ED8.unkFFC2 = 1U;
    } else {
        D_801D9ED8.unkFFC2 = 0U;
    }
    if (cont->button & CONT_RIGHT) {
        D_801D9ED8.unkFFC4 = 1U;
    } else {
        D_801D9ED8.unkFFC4 = 0U;
    }

    if ((D_803F2AA2 == 0) && (D_803F2AA3 == 0)) {
        if (cont->button & L_TRIG) {
            D_801D9ED8.unkFFB4 = 1U;
        } else if (cont->button & R_TRIG) {
            D_801D9ED8.unkFFB4 = 2U;
        } else {
            D_801D9ED8.unkFFB4 = 0U;
        }
    }

    func_8033E7C8_74FE78(cont);

    D_801D9ED8.unkFFD8 = cont->stick_x;
    D_801D9ED8.unkFFD9 = cont->stick_y;

    if (cont->button & U_CBUTTONS) {
        D_801D9ED8.unkFFC6 = 1;
    } else {
        D_801D9ED8.unkFFC6 = 0;
    }
    if (cont->button & D_CBUTTONS) {
        D_801D9ED8.unkFFC8 = 1;
    } else {
        D_801D9ED8.unkFFC8 = 0;
    }
    if (cont->button & L_CBUTTONS) {
        D_801D9ED8.unkFFCA = 1;
    } else {
        D_801D9ED8.unkFFCA = 0;
    }
    if (cont->button & R_CBUTTONS) {
        D_801D9ED8.unkFFCC = 1;
    } else {
        D_801D9ED8.unkFFCC = 0;
    }

    if (D_803F2D30.unk4) {
        // reset inputs
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
        D_801D9ED8.unkFFC6 = 0;
        D_801D9ED8.unkFFC8 = 0;
        D_801D9ED8.unkFFCA = 0;
        D_801D9ED8.unkFFCC = 0;
    }
    if (D_803D554A) {
        // reset inputs
        D_801D9ED8.unkFFB2 = 0U;
        D_801D9ED8.unkFFB6 = 0U;
        D_801D9ED8.unkFFB4 = 0U;
        D_801D9ED8.unkFFBE = 0U;
        D_801D9ED8.unkFFC0 = 0U;
        D_801D9ED8.unkFFC2 = 0U;
        D_801D9ED8.unkFFC4 = 0U;
        D_801D9ED8.unkFFD8 = 0;
        D_801D9ED8.unkFFD9 = 0;
    }
}

s32 func_802C9340_6DA9F0(void) {
    struct068 *phi_v0;
    s16 i;

    bzero_sssv(&D_801E9EB8, sizeof(D_801E9EB8));

    D_801E9EB8.unk0 = D_803A8528_7B9BD8;

    D_80203FC4 = 247; // 247 objects

    phi_v0 = D_801E9EB8.unk0;
    for (i = 0; i < 247; i++) {
        if ((phi_v0->unk18 != 0) && (((s32)phi_v0->unk18 & 0xF0000000) == 0)) {
            phi_v0->unk18 = D_801D9E74 + SEGMENT_OFFSET((s32)phi_v0->unk18);
        }
        phi_v0 += 1;
    }

    return 1;
}

struct071 *func_802C93E8_6DAA98(u16 arg0) {
    return &D_801E9EB8.objects[MAX_OBJECTS - arg0];
}

void func_802C941C_6DAACC(void) {
    s16 i;

    for (i = 0; i < 170; i++) {
        D_801E9EB8.unk19E64[i] = &D_801E9EB8.objects[i];
    }
    D_801E9EB8.unk1A110 = MAX_OBJECTS;
    D_801E9EB8.unk1A112 = MAX_OBJECTS;
    D_801E9EB8.unk1A114 = 0;
}

struct071 *func_802C9488_6DAB38(void) {
    struct071 *obj;

    if (D_801E9EB8.unk1A114 > MAX_OBJECTS) {
        return NULL;
    }
    obj = D_80203D1C[D_801E9EB8.unk1A110--];

    if (D_801E9EB8.unk1A110 < 0) {
        D_801E9EB8.unk1A110 = MAX_OBJECTS;
    }
    D_801E9EB8.unk1A114 += 1; // used?

    obj->unk26C = 0; // initialised?
    return obj;
}

void func_802C9500_6DABB0(struct071 *obj) {
    D_80203D1C[D_801E9EB8.unk1A112] = obj;

    // regalloc fix
    do {
        D_801E9EB8.unk1A112--;
    } while ((s64)0);

    if (D_801E9EB8.unk1A112 < 0) {
        D_801E9EB8.unk1A112 = MAX_OBJECTS;
    }
    D_801E9EB8.unk1A114--;
}

#if 0
struct071 *func_802C9564_6DAC14(u8 id, s16 x, s16 z, s16 y, s32 arg4, s32 arg5, s32 arg6, s16 zRotation, s16 yRotation, u16 scale) {
    s16 temp_v1;
    struct071 *obj;
    struct068 *tmp;

    obj = func_802C9488_6DAB38();
    if (obj == 0) {
        return NULL;
    }

    bzero_sssv((u8 *) obj, sizeof(struct071));

    tmp = &D_801E9EB8.unk0[id]; // this is wrong
    obj->unk16C = (struct035 *)tmp;

    if (obj->unk16C->unk70 != 0) {
        scale = obj->unk16C->unk70;
    }
    // help
    obj->unk40 = scale;

    obj->unk4C.unk29 = obj->unk16C->unk82.unk4;
    obj->unk4C.unk30 = obj->unk16C->unk82.unk5;
    obj->unk4C.unk28 = obj->unk16C->unk82.unk3;

    obj->unk14C = obj->unk16C->unk8A;
    obj->unk164 = obj->unk16C->unk89;

    if (obj->unk16C->unk82.unk7) {
        temp_v1 = func_8031124C_7228FC(x, z) >> 0x10;
        if (y < temp_v1) {
            y = temp_v1;
        }
    }
    temp_v1 = func_80310F58_722608(x, z) >> 0x10;
    if (temp_v1 == 0x4000) {
        obj->unk160 = 0;
    } else if (y >= temp_v1) {
        obj->unk160 = 2;
    } else {
        obj->unk160 = 1;
    }

    obj->unk0 = 1;
    obj->unk17E = x;
    obj->unk180 = z;
    obj->unk182 = y;
    obj->unk1C.w = arg4;
    obj->unk20.w = arg5;
    obj->unk24.w = arg6;
    obj->zRotation = zRotation;
    obj->yRotation = yRotation;
    obj->unk4C.unk26 = 1;

    obj->unk46 = obj->unk16C->mass;

    obj->unk114 = 0x7FFF;
    obj->unk116 = 0x7FFF;
    obj->unk118 = 0x7FFF;
    obj->unk11A = 0x7FFF;

    func_802C9BA4_6DB254(obj);
    if ((obj->unk16C->unk15 == 4) && (((zRotation >= 225) && (zRotation < 315)) || ((zRotation >= 45) && (zRotation < 135)))) {
        y = (y + obj->unk32) - (obj->unk42 >> 1);
    }
    obj->xPos.h = x;
    obj->zPos.h = z;
    obj->yPos.h = y;
    obj->unk10.w = x << 0x10;
    obj->unk14.w = z << 0x10;
    obj->unk18 = y << 0x10;

    func_802DADA0_6EC450(obj);
    func_802F5C60_707310(obj);
    obj->unk162 = 3;
    return obj;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_6D9AF0/func_802C9564_6DAC14.s")
#endif

void func_802C9834_6DAEE4(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

void func_802C985C_6DAF0C(void) {
    func_802C9884_6DAF34();
    func_802C8440_6D9AF0();
}

void func_802C9884_6DAF34(void) {
    u16 i;

    func_802DAF5C_6EC60C();
    func_802C941C_6DAACC();

    for (i = 0; i <= MAX_OBJECTS; i++) {
        bzero_sssv(&D_801E9EB8.objects[i], sizeof(struct071));
    }
    func_8029F3CC_6B0A7C();
}

// add_reference_to_object
void func_802C9900_6DAFB0(struct071 *parent, struct071 *child, u8 idx) {
    parent->unk24C[idx] = child;
}

void func_802C9918_6DAFC8(Animal *arg0, s16 arg1, s16 arg2) {
    s16 var_t0;
    s16 var_t1;
    s16 var_t2;

    s16 temp_t5;
    s32 temp_t8;
    s32 temp_t9;

    if (arg0->unk16C->unk15 != 4) {
        arg0->yRotation = arg2;
        arg0->zRotation = arg1;
        return;
    }

    temp_t8 = ((s16) ((arg1 + 45) / 90));
    temp_t9 = ((s16) ((arg0->zRotation + 45) / 90));

    arg0->yRotation = arg2;
    arg0->zRotation = arg1;

    if ((temp_t8 & 1) ^ (temp_t9 & 1)) {
        if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
            ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
            arg0->yPos.h = (arg0->yPos.h - arg0->unk30) + (arg0->unk42 >> 1);
        } else {
            arg0->yPos.h = (arg0->yPos.h - arg0->unk32) + (arg0->unk42 >> 1);
        }
    }

    var_t1 = arg0->unk16C->unk72;
    var_t0 = arg0->unk16C->unk74;
    var_t2 = arg0->unk16C->unk7A;

    if (((arg0->zRotation >= 45) && (arg0->zRotation < 135)) ||
        ((arg0->zRotation >= 225) && (arg0->zRotation < 315))) {
        temp_t5 = var_t0;
        var_t0 = (var_t2 / 2);
        var_t2 = temp_t5 << 1;
    }
    if (((arg0->yRotation >= 45) && (arg0->yRotation < 135)) ||
        ((arg0->yRotation >= 225) && (arg0->yRotation < 315))) {
        temp_t5 = var_t1;
        var_t1 = var_t0;
        var_t0 = temp_t5;
    }

    arg0->unk30 = var_t1;
    arg0->unk32 = var_t0;
    arg0->unk42 = var_t2;

    arg0->unk30 = ((s64)arg0->unk30 * arg0->unk40) >> 0xB;
    arg0->unk32 = ((s64)arg0->unk32 * arg0->unk40) >> 0xB;
    arg0->unk42 = ((s64)arg0->unk42 * arg0->unk40) >> 0xB;
}

void func_802C9BA4_6DB254(struct071 *arg0) {
    s16 temp_t9;
    s16 i;
    s16 var_t1;
    s16 var_t2;
    s16 var_v1;

    if (arg0->unk40 == 0) {
        arg0->unk40 = 0x800;
    }

    var_t1 = arg0->unk16C->unk72;
    var_v1 = arg0->unk16C->unk74;
    var_t2 = arg0->unk16C->unk7A;

    if ((arg0->unk16C->unk15 == 4)) {
        if (((arg0->zRotation >= 0x2E) && (arg0->zRotation < 0x88)) || ((arg0->zRotation >= 0xE2) && (arg0->zRotation < 0x13C))) {
            temp_t9 = var_v1;
            var_v1 = var_t2 / 2;
            var_t2 = temp_t9 * 2;
        }
    }

    if (((arg0->yRotation >= 0x2E) && (arg0->yRotation < 0x88)) || ((arg0->yRotation >= 0xE2) && (arg0->yRotation < 0x13C))) {
        temp_t9 = var_t1;
        var_t1 = var_v1;
        var_v1 = temp_t9;
    }

    arg0->unk30 = var_t1;
    arg0->unk32 = var_v1;
    arg0->unk42 = var_t2;

    arg0->unk34 = arg0->unk16C->unk76;
    arg0->unk36 = arg0->unk16C->unk78;

    arg0->unk34 = ((s64)arg0->unk34 * arg0->unk40) >> 11;
    arg0->unk36 = ((s64)arg0->unk36 * arg0->unk40) >> 11;

    if ((arg0->unk16C->objectType >= 0x80) && (((((Animal*) arg0)->unk366 == 5)) || (((Animal*) arg0)->unk366 == 2))) {
        arg0->unk42 = arg0->unk16C->unkBC;
    }

    arg0->unk44 = arg0->unk46;

    arg0->unk4C.pad0 = arg0->unk16C->mass / 2;

    arg0->unk30 = ((s64)arg0->unk30 * arg0->unk40) >> 11;
    arg0->unk32 = ((s64)arg0->unk32 * arg0->unk40) >> 11;

    arg0->unk42 = ((s64)arg0->unk42 * arg0->unk40) >> 11;
    arg0->unk44 = ((s64)arg0->unk44 * arg0->unk40) >> 11;

    arg0->unk4C.pad0 = ((s64)arg0->unk4C.pad0 * arg0->unk40) >> 11;

    for (i = 0; i < 5; i++) {
        arg0->unk74[i][0] = arg0->unk16C->unk20[i][0] << 0x10;
        arg0->unk74[i][1] = arg0->unk16C->unk20[i][1] << 0x10;
        arg0->unk74[i][2] = arg0->unk16C->unk20[i][2] << 0x10;
        arg0->unk74[i][3] = arg0->unk16C->unk20[i][3];

        arg0->unk74[i][0] = ((s64)arg0->unk74[i][0] * arg0->unk40) >> 11;
        arg0->unk74[i][1] = ((s64)arg0->unk74[i][1] * arg0->unk40) >> 11;
        arg0->unk74[i][2] = ((s64)arg0->unk74[i][2] * arg0->unk40) >> 11;
        arg0->unk74[i][3] = ((s64)arg0->unk74[i][3] * arg0->unk40) >> 11;
    }
}
