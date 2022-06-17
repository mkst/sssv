#include <ultra64.h>
#include "common.h"

u8 ai_map_europe[MAX_EUROPE_ANIMALS][MAX_EUROPE_ANIMALS] = {

/*
    0   AI_IGNORE
    1   AI_FLEE         e.g. sheep vs dog
    2   AI_ATTACK       e.g. dog vs sheep
    3   AI_SAME_ANIMAL  e.g. dog vs dog
    4   AI_HERD         e.g. sheep / springy thingy
    5   AI_LEAD_HERD    e.g. ram / springy ram
    6   AI_FOLLOWER     e.g. penguin vs king penguin
    7   AI_LEADER       e.g. king penguin vs penguin
    8   AI_INVISIBLE    e.g. sneaky chameleon
*/

/*CROW*/            { 3, 2, 2, 0, 1, 0, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, },
/*DOG*/             { 0, 3, 0, 0, 2, 0, 2, 0, 2, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, },
/*RACING_DOG*/      { 0, 0, 3, 0, 2, 0, 2, 0, 2, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, },
/*FLYING_DOG*/      { 2, 0, 0, 3, 2, 2, 2, 0, 2, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, },
/*FOX*/             { 0, 2, 2, 0, 3, 0, 2, 0, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, },
/*FIRE_FOX*/        { 0, 2, 2, 2, 0, 3, 2, 0, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, },
/*FROG*/            { 2, 2, 2, 0, 2, 0, 3, 0, 0, 2, 2, 1, 1, 2, 0, 0, 0, 0, 0, },
/*COD*/             { 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, },
/*KING_RAT*/        { 0, 2, 2, 0, 2, 0, 2, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7, },
/*MOUSE*/           { 0, 0, 0, 0, 2, 1, 2, 0, 2, 3, 0, 0, 0, 2, 0, 2, 2, 0, 2, },
/*RACING_MOUSE*/    { 0, 0, 0, 0, 2, 1, 2, 0, 2, 0, 3, 0, 0, 2, 0, 2, 2, 0, 2, },
/*BEAR*/            { 0, 2, 2, 0, 2, 0, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 0, 2, 2, },
/*MYSTERY_BEAR*/    { 0, 2, 2, 0, 2, 0, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 0, 2, 2, },
/*RACING_FOX*/      { 0, 2, 2, 0, 3, 0, 2, 0, 2, 2, 2, 1, 1, 3, 2, 2, 2, 2, 2, },
/*SHEEP*/           { 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 4, 5, 4, 5, 1, },
/*RAM*/             { 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 3, 0, 0, 2, },
/*SPRINGY_THINGY*/  { 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 4, 5, 4, 5, 1, },
/*SPRINGY_RAM*/     { 0, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 3, 2, },
/*RAT*/             { 0, 2, 2, 0, 2, 0, 2, 0, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, },
};

u8 ai_map_jungle[MAX_JUNGLE_ANIMALS][MAX_JUNGLE_ANIMALS] = {
/*PIRANA*/          { 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, },
/*GORILLA*/         { 1, 3, 0, 2, 2, 2, 0, 0, 0, 2, 2, 8, },
/*CHAMELEON*/       { 1, 1, 3, 2, 2, 1, 0, 0, 0, 2, 2, 3, },
/*HYENA*/           { 1, 2, 2, 3, 3, 2, 2, 0, 0, 2, 2, 8, },
/*HYENA_BIKER*/     { 1, 2, 2, 3, 3, 2, 2, 0, 0, 2, 2, 8, },
/*LION*/            { 1, 2, 0, 2, 2, 3, 2, 0, 0, 0, 0, 8, },
/*HIPPO*/           { 1, 0, 0, 2, 2, 1, 3, 0, 1, 2, 2, 8, },
/*ELEPHANT*/        { 1, 0, 0, 0, 0, 0, 0, 3, 0, 2, 2, 8, },
/*PARROT*/          { 1, 0, 2, 2, 0, 2, 2, 2, 3, 0, 0, 8, },
/*TORTOISE_TANK*/   { 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 8, },
/*RACING_TORTOISE*/ { 1, 2, 2, 2, 2, 1, 2, 1, 0, 3, 3, 8, },
/*CHAMELEON_DEFEND*/{ 1, 1, 3, 1, 1, 1, 0, 0, 0, 2, 2, 3, },
};

u8 ai_map_ice[MAX_ICE_ANIMALS][MAX_ICE_ANIMALS] = {
/*PENGUIN*/         { 4, 6, 2, 1, 1, 0, 0, 0, 0, 0, 0, },
/*KING_PENGUIN*/    { 7, 3, 2, 2, 2, 0, 0, 0, 0, 0, 0, },
/*WALRUS*/          { 2, 2, 3, 2, 2, 0, 0, 2, 2, 2, 0, },
/*HUSKY*/           { 2, 2, 2, 3, 3, 2, 2, 2, 1, 2, 0, },
/*SKI_HUSKY*/       { 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 0, },
/*POLAR_BEAR*/      { 0, 0, 0, 2, 2, 3, 3, 2, 1, 2, 0, },
/*POLAR_TANK*/      { 0, 0, 0, 2, 2, 3, 3, 2, 2, 2, 0, },
/*RABBIT*/          { 0, 0, 2, 2, 1, 2, 1, 3, 3, 0, 0, },
/*HELI_RABBIT*/     { 0, 0, 2, 2, 2, 2, 2, 3, 3, 0, 0, },
/*SEAGULL*/         { 0, 0, 2, 2, 2, 2, 2, 0, 0, 3, 0, },
/*COOL_COD*/        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, },
};

u8 ai_map_desert[MAX_DESERT_ANIMALS][MAX_DESERT_ANIMALS] = {
/*CAMEL*/           { 3, 3, 1, 2, 2, 2, 2, 2, },
/*CANNON_CAMEL*/    { 3, 3, 1, 2, 2, 2, 2, 2, },
/*SCORPION*/        { 2, 2, 3, 2, 2, 2, 2, 2, },
/*BOXING_KANGAROO*/ { 2, 2, 1, 3, 3, 2, 0, 0, },
/*POGO_KANGAROO*/   { 2, 2, 1, 3, 3, 2, 0, 0, },
/*VULTURE*/         { 2, 2, 1, 2, 2, 3, 2, 2, },
/*DESERT_FOX*/      { 2, 2, 2, 0, 0, 2, 3, 4, },
/*ARMED_DESERT_FOX*/{ 2, 2, 2, 0, 0, 2, 4, 4, },
};

u8 D_803A4B78_7B6228[] = {
    0x09, // SEAGULL
    0x05, // LION
    0x06, // HIPPO
    0x00, // RACING_HIPPO
    0x02, // RACING_DOG
    0x03, // FLYING_DOG
    0x04, // FOX
    0x05, // FIRE_FOX
    0x06, // FROG
    0x05, // POLAR_BEAR_DEFENDING
    0x07, // RABBIT
    0x08, // HELI_RABBIT
    0x07, // COD
    0x08, // KING_RAT
    0x08, // PARROT
    0x08, // PARROT_ATTACKING
    0x09, // MOUSE
    0x0a, // HARD_MOUSE
    0x0a, // RACING_MOUSE
    0x05, // VULTURE
    0x09, // MOUSE2
    0x09, // HELI_MOUSE
    0x0b, // BEAR
    0x0b, // CRAZY_BEAR
    0x0c, // MYSTERY_BEAR
    0x09, // SEAGULL2
    0x0d, // RACING_FOX
    0x09, // TORTOISE_TANK
    0x0a, // RACING_TORTOISE
    0x09, // TORTOISE_TANK_DEFENDING
    0x00, // PIRANA
    0x01, // DOG
    0x12, // RAT
    0x0e, // SHEEP
    0x0f, // RAM
    0x10, // SPRINGY_THINGY
    0x11, // SPRINGY_RAM
    0x00, // PENGUIN
    0x05, // POLAR_BEAR
    0x06, // POLAR_TANK
    0x03, // HUSKY
    0x03, // CRAZY_HUSKY
    0x04, // SKI_HUSKY
    0x00, // CROW
    0x02, // WALRUS
    0x05, // VULTURE2
    0x00, // CAMEL
    0x01, // CANNON_CAMEL
    0x00, // CROW_DIVER
    0x04, // POGO_KANGAROO
    0x03, // BOXING_KANGAROO
    0x06, // DESERT_FOX
    0x07, // ARMED_DESERT_FOX
    0x02, // SCORPION
    0x01, // GORILLA
    0x06, // DESERT_FOX_ATTACKING
    0x07, // ELEPHANT
    0x03, // HYENA
    0x04, // HYENA_BIKER
    0x02, // CHAMELEON
    0x0b, // SNEAKY_CHAMELEON
    0x63, // EVO_MICROCHIP
    0x63, // EVO_TRANSFER
    0x63, // EVO
    0x01, // KING_PENGUIN
    0x0a, // RACING_TORTOISE_DEFENDING
    0x0a, // COOL_COD
    0x64, // EVO_SHELLSUIT

    // so whats all this for?
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08,
    0x00, 0x08, 0x00, 0x0a,
    0x00, 0x10, 0x00, 0x10,
    0x00, 0x12, 0x00, 0x08,
    0x00, 0x24, 0x00, 0x5a,
    0xff, 0xe0, 0x00, 0x2c,
    0x00, 0x48, 0xff, 0xd8,
    0xff, 0xee, 0xff, 0xf8,
    0xff, 0xec, 0xff, 0xf0,
    0xff, 0xf0, 0xff, 0xf8,
    0xff, 0xf8, 0xff, 0xf8,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x22,
    0x00, 0x20, 0x00, 0x20,
    0x00, 0x1a, 0x00, 0x54,
    0x00, 0x5c, 0xff, 0xe2,
    0x00, 0x5c, 0x00, 0x94,
    0xff, 0xb0, 0x00, 0x14,
    0x00, 0x50, 0xff, 0xc0,
    0xff, 0xf8, 0xff, 0xf8,
    0xff, 0xca, 0xff, 0xcc,
    0xff, 0xd6, 0xff, 0xec,
    0xff, 0xec, 0xff, 0xea,
    0xff, 0xd0, 0x00, 0x30,
    0x00, 0x54, 0xff, 0xc8,
    0x00, 0x34, 0x00, 0x60,
    0xff, 0xfc, 0x00, 0x04,
};
