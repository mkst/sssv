#include <ultra64.h>
#include "common.h"


// ESA: func_8006013C
void init_and_spawn_evo_microchip(void) {
    func_803572C0_768970();
    func_803747CC_785E7C();
    reset_dynamic_tails(0);
    memset_bytes((u8 *)&D_801D9ED8.animals, 0U, sizeof(D_801D9ED8.animals));
    memset_bytes((u8 *)&D_801D9ED8.unk4040, 0U, sizeof(D_801D9ED8.unk4040));
    D_803D553E = 0;
    func_802C7C80_6D9330(); // load all stats
    D_803E9820 = 27;
    D_803E9822 = 0;
    gCurrentAnimalId = EVO_MICROCHIP;
    gCurrentAnimalIndex = 0;
    func_80327DA8_739458(); // waypoints?
    spawn_animal(0, 0, 0, 0, 0x7F, EVO_MICROCHIP, 1);
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
    D_803D5548 = D_803D554A = 0;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->heading = (D_803F2D50.unk4E * 256) / 360;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.unk4E * 256) / 360;
    D_803F6450 = 1;
    D_803F2CE6 = 0;
    D_803D5558 = 0;
}

void func_802C85EC_6D9C9C(void) {
    Animal *a;

    if (D_803F2D50.animalId != EVO_MICROCHIP) {
        gCurrentAnimalId = D_803F2D50.animalId;
        D_803E9820 = D_803A63B0_7B7A60[gCurrentAnimalId].unk0;
        D_803E9822 = D_803A63B0_7B7A60[gCurrentAnimalId].unk1;
        gCurrentAnimalIndex = D_803D553E;
        a = D_801D9ED8.animals[0].animal;
        spawn_animal(a->position.xPos.h, a->position.zPos.h, a->position.yPos.h, 0, 0x7F, gCurrentAnimalId, 1);
        func_80327DA8_739458();
        D_801D9ED8.animals[0].animal->unk366 = 3;
        D_801D9ED8.animals[0].unk0 = &D_801D9ED8.unk0[62];           // weird offset?
        D_801D9ED8.animals[0].animal->unk16C = &D_801D9ED8.unk0[62]; // weird offset?
        D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 1;
        D_801D9ED8.animals[0].animal->unk4A = 0;
    }
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->heading = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->yRotation = (D_803F2D50.unk4E << 8) / 360;
    D_801D9ED8.unkFFA8 = (D_803F2D50.unk4E << 8) / 360;
    D_803F2AA3 = 0;
    D_803F2AA2 = 0;
}

void func_802C87E0_6D9E90(void) {
    D_80204278->usedHilites = 0;
    D_80204278->usedVtxs = 0;
    D_803E1B04 = 0;
    gScorpionVtxIdx = 0;
    if (D_803F2D10.unk0 == 0) {
        D_803D5540 = (D_803D5540 + 1) & 0xFF;
        D_803D5542 = (D_803D5542 + 1) % 360;
        D_803D5544 += 1;
    }
}

// ESA: func_80060510
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
                        } else if ((D_803F2D10.unk0 == 0) && (D_803D552C->unk365 != ATTACK_EVO_CHIP_2)) {
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
                    D_803D5530->newPosition.xPos.w = D_803D5530->position.xPos.w + D_803D5530->xVelocity.w;
                    D_803D5530->newPosition.zPos.w = D_803D5530->position.zPos.w + D_803D5530->zVelocity.w;
                    D_803D5530->newPosition.yPos.w = D_803D5530->position.yPos.w + D_803D5530->yVelocity.w;
                    func_80328520_739BD0();
                }
            }
            if (D_801D9ED8.animals[i].animal != NULL) {
                switch (D_801D9ED8.animals[i].unk0->unk9C) {
                case LION:
                    func_802F1730_702DE0();
                    break;
                case HIPPO:
                    update_hippo();
                    break;
                case RACING_HIPPO:
                    func_802F036C_701A1C();
                    break;
                case RACING_DOG:
                    func_802EA7F0_6FBEA0();
                    break;
                case FLYING_DOG:
                    update_flying_dog();
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
                    update_crazy_bear();
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
                    update_sheep_or_ram();
                    break;
                case SPRINGY_THINGY:
                case SPRINGY_RAM:
                    update_springy_thingy_or_springy_ram();
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
                    update_gorilla();
                    break;
                case ELEPHANT:
                    update_elephant();
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
                    update_evo_microchip();
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
                    update_desert_fox_attacking();
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
