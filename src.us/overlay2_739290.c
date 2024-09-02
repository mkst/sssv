#include <ultra64.h>
#include "common.h"

#include "camera.h"

// ========================================================
// definitions
// ========================================================

typedef struct {
    u16 unk0;
    u8  unk2[6];
} struct101; // size 0x8

typedef struct {
    u8 unk0;    // new index
    u8 unk1;    // call func_802DBA58_6ED108 if 1 or 2
    u8 unk2;    // if it's 7, we can press dpad-down to change animal?
    u8 unk3;    // 1 or 2 allows changing
} struct114; // size 0x4

// ========================================================
// .data
// ========================================================

struct101 D_803A6070_7B7720[1] = {
    {LION,              {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6078_7B7728[1] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A607C_7B772C[2] = {
    {HIPPO,             {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {RACING_HIPPO,      {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A608C_7B773C[3] = {
    {0x01, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6098_7B7748[3] = {
    {DOG,               {0x00, 0x01, 0xFF, 0x00, 0x00, 0x00}},
    {RACING_DOG,        {0x02, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {FLYING_DOG,        {0x03, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A60B0_7B7760[5] = {
    {0x01, 0x02, 0x04, 0x01},
    {0x02, 0x02, 0x03, 0x01},
    {0x00, 0x02, 0x03, 0x01},
    {0x00, 0x02, 0x04, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A60C4_7B7774[3] = {
    {FOX,               { 0x00, 0x02, 0xFF, 0x00, 0x00, 0x00}},
    {FIRE_FOX,          { 0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {RACING_FOX,        { 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A60DC_7B778C[5] = {
    {0x01, 0x02, 0x03, 0x01},
    {0x00, 0x02, 0x04, 0x01},
    {0x02, 0x01, 0x04, 0x01},
    {0x00, 0x01, 0x03, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A60F0_7B77A0[1] = {
    {FROG,              {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A60F8_7B77A8[1] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A60FC_7B77AC[2] = {
    {RABBIT,            {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {HELI_RABBIT,       {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A610C_7B77BC[3] = {
    {0x01 ,0x01, 0x03, 0x01},
    {0x00 ,0x02, 0x04, 0x01},
    {0x00 ,0x00, 0x00, 0x00},
};

struct101 D_803A6118_7B77C8[1] = {
    {COD,               {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6120_7B77D0[1] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6124_7B77D4[2] = {
    {PARROT,            {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {PARROT_ATTACKING,  {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6134_7B77E4[1] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6138_7B77E8[5] = {
    {MOUSE,             {0x00, 0x01, 0xFF, 0x00, 0x00, 0x00}},
    {RACING_MOUSE,      {0x02, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {HELI_MOUSE,        {0x03, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {MOUSE2,            {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {HARD_MOUSE,        {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6160_7B7810[5] = {
    {0x01, 0x02, 0x06, 0x01},
    {0x02, 0x02, 0x03, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x02, 0x04, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6174_7B7824[3] = {
    {BEAR,              {0x00, 0x01, 0xFF, 0x00, 0x00, 0x00}},
    {CRAZY_BEAR,        {0x02, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {MYSTERY_BEAR,      {0x03, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A618C_7B783C[5] = {
    {0x01, 0x01, 0x05, 0x01},
    {0x02, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A61A0_7B7850[3] = {
    {TORTOISE_TANK,     {0x00, 0x01, 0xFF, 0x00, 0x00, 0x00}},
    {RACING_TORTOISE,   {0x02, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {TORTOISE_TANK_DEFENDING, {0x03, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A61B8_7B7868[5] = {
    {0x01, 0x01, 0x06, 0x01},
    {0x02, 0x01, 0x05, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x01, 0x06, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A61CC_7B787C[2] = {
    {RAT,               {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {KING_RAT,          {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A61DC_7B788C[3] = {
    {0x01, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A61E8_7B7898[4] = {
    {SHEEP,             {0x00, 0x02, 0xFF, 0x00, 0x00, 0x00}},
    {SPRINGY_THINGY,    {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {RAM,               {0x03, 0x04, 0xFF, 0x00, 0x00, 0x00}},
    {SPRINGY_RAM,       {0x05, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6208_7B78B8[7] = {
    {0x01, 0x02, 0x06, 0x01},
    {0x00, 0x02, 0x05, 0x01},
    {0x02, 0x02, 0x04, 0x01},
    {0x00, 0x02, 0x03, 0x01},
    {0x03, 0x02, 0x06, 0x01},
    {0x02, 0x02, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6224_7B78D4[2] = {
    {PENGUIN,           {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {KING_PENGUIN,      {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6234_7B78E4[3] = {
    {0x01, 0x02, 0x06, 0x01},
    {0x00, 0x02, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6240_7B78F0[3] = {
    {POLAR_BEAR,        {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {POLAR_TANK,        {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {POLAR_BEAR_DEFENDING, {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6258_7B7908[3] = {
    {0x01, 0x01, 0x04, 0x01},
    {0x00, 0x01, 0x03, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6264_7B7914[2] = {
    {HUSKY,             {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {SKI_HUSKY,         {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6274_7B7924[3] = {
    {0x01, 0x01, 0x04, 0x01},
    {0x00, 0x01, 0x03, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6280_7B7930[] = {
    {WALRUS,            {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6288_7B7938[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A628C_7B793C[] = {
    {VULTURE2,          {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {VULTURE,           {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A629C_7B794C[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A62A0_7B7950[] = {
    {CAMEL,             {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {CANNON_CAMEL,      {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A62B0_7B7960[] = {
    {0x01, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A62BC_7B796C[] = {
    {BOXING_KANGAROO,   {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {POGO_KANGAROO,     {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A62CC_7B797C[] = {
    {0x01, 0x01, 0x03, 0x01},
    {0x00, 0x01, 0x04, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A62D8_7B7988[] = {
    {DESERT_FOX,        {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {ARMED_DESERT_FOX,  {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {DESERT_FOX_ATTACKING, {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A62F0_7B79A0[] = {
    {0x01, 0x01, 0x06, 0x01},
    {0x00, 0x01, 0x05, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A62FC_7B79AC[] = {
    {SCORPION,          {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6304_7B79B4[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6308_7B79B8[] = {
    {GORILLA,           {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6310_7B79C0[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6314_7B79C4[] = {
    {ELEPHANT,          {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A631C_7B79CC[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6320_7B79D0[] = {
    {HYENA,             {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {HYENA_BIKER,       {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6330_7B79E0[] = {
    {0x01, 0x01, 0x04, 0x01},
    {0x00, 0x01, 0x03, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A633C_7B79EC[] = {
    {CHAMELEON,         {0x00, 0xFF, 0x00, 0x00, 0x00, 0x00}},
    {SNEAKY_CHAMELEON,  {0x01, 0xFF, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A634C_7B79FC[] = {
    {0x01, 0x01, 0x04, 0x01},
    {0x00, 0x01, 0x03, 0x01},
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6358_7B7A08[] = {
    {EVO_MICROCHIP,     {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6360_7B7A10[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6364_7B7A14[] = {
    {SEAGULL,           {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {SEAGULL2,          {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6374_7B7A24[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6378_7B7A28[] = {
    {PIRANA,            {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6380_7B7A30[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6384_7B7A34[] = {
    {CROW,              {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {CROW_DIVER,        {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A6394_7B7A44[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A6398_7B7A48[] = {
    {COOL_COD,          {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A63A0_7B7A50[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct101 D_803A63A4_7B7A54[] = {
    {EVO_SHELLSUIT,     {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00}},
};
struct114 D_803A63AC_7B7A5C[] = {
    {0x00, 0x00, 0x00, 0x00},
};

struct082 D_803A63B0_7B7A60[] = {
    {0x1C, 0x00},   // SEAGULL
    {0x01, 0x00},   // LION
    {0x02, 0x00},   // HIPPO
    {0x02, 0x01},   // RACING_HIPPO
    {0x03, 0x01},   // RACING_DOG
    {0x03, 0x02},   // FLYING_DOG
    {0x04, 0x00},   // FOX
    {0x04, 0x01},   // FIRE_FOX
    {0x05, 0x00},   // FROG
    {0x0F, 0x02},   // POLAR_BEAR_DEFENDING
    {0x06, 0x00},   // RABBIT
    {0x06, 0x01},   // HELI_RABBIT
    {0x07, 0x00},   // COD
    {0x0C, 0x01},   // KING_RAT
    {0x08, 0x00},   // PARROT
    {0x08, 0x01},   // PARROT_ATTACKING
    {0x09, 0x00},   // MOUSE
    {0x09, 0x04},   // HARD_MOUSE
    {0x09, 0x01},   // RACING_MOUSE
    {0x12, 0x01},   // VULTURE
    {0x09, 0x02},   // MOUSE2
    {0x09, 0x03},   // HELI_MOUSE
    {0x0A, 0x00},   // BEAR
    {0x0A, 0x01},   // CRAZY_BEAR
    {0x0A, 0x02},   // MYSTERY_BEAR
    {0x1C, 0x01},   // SEAGULL2
    {0x04, 0x02},   // RACING_FOX
    {0x0B, 0x00},   // TORTOISE_TANK
    {0x0B, 0x01},   // RACING_TORTOISE
    {0x0B, 0x02},   // TORTOISE_TANK_DEFENDING
    {0x1D, 0x00},   // PIRANA
    {0x03, 0x00},   // DOG
    {0x0C, 0x00},   // RAT
    {0x0D, 0x00},   // SHEEP
    {0x0D, 0x02},   // RAM
    {0x0D, 0x01},   // SPRINGY_THINGY
    {0x0D, 0x03},   // SPRINGY_RAM
    {0x0E, 0x00},   // PENGUIN
    {0x0F, 0x00},   // POLAR_BEAR
    {0x0F, 0x01},   // POLAR_TANK
    {0x10, 0x00},   // HUSKY
    {0x10, 0x01},   // CRAZY_HUSKY
    {0x10, 0x02},   // SKI_HUSKY
    {0x1E, 0x00},   // CROW
    {0x11, 0x00},   // WALRUS
    {0x12, 0x00},   // VULTURE2
    {0x13, 0x00},   // CAMEL
    {0x13, 0x01},   // CANNON_CAMEL
    {0x1E, 0x01},   // CROW_DIVER
    {0x14, 0x00},   // POGO_KANGAROO
    {0x14, 0x01},   // BOXING_KANGAROO
    {0x15, 0x00},   // DESERT_FOX
    {0x15, 0x01},   // ARMED_DESERT_FOX
    {0x16, 0x00},   // SCORPION
    {0x17, 0x00},   // GORILLA
    {0x15, 0x02},   // DESERT_FOX_ATTACKING
    {0x18, 0x00},   // ELEPHANT
    {0x19, 0x00},   // HYENA
    {0x19, 0x01},   // HYENA_BIKER
    {0x1A, 0x00},   // CHAMELEON
    {0x1A, 0x01},   // SNEAKY_CHAMELEON
    {0x1B, 0x00},   // EVO_MICROCHIP
    {0x1B, 0x01},   // EVO_TRANSFER
    {0x1B, 0x02},   // EVO
    {0x0E, 0x01},   // KING_PENGUIN
    {0x0B, 0x03},   // RACING_TORTOISE_DEFENDING
    {0x1F, 0x00},   // COOL_COD
    {0x20, 0x00},   // EVO_SHELLSUIT

    {0x00, 0x00},   // ~~~ all unused ~~~
    {0x00, 0x00},   //

    {0x03, 0x04},   // ... is this another array?
    {0x09, 0x0A},
    {0x0C, 0x0D},
    {0x20, 0x00},
    {0x12, 0x13},
    {0x14, 0x15},
    {0x16, 0x20},
    {0x00, 0x00},
    {0x0E, 0x0F},
    {0x10, 0x11},
    {0x06, 0x1C},
    {0x1F, 0x20},
    {0x01, 0x02},
    {0x17, 0x18},
    {0x19, 0x1A},
    {0x08, 0x0B},
    {0x1D, 0x20},
    {0x00, 0x00},
    {0x03, 0x04},
    {0x09, 0x0C},
    {0x0D, 0x20},
};

// ========================================================
// .bss
// ========================================================

u8 overlay2_739290_padding_pre[0x10];

s16  D_803E9820;
s16  D_803E9822;
s16  gCurrentAnimalId;
struct101 *D_803E9828;  // struct is 8 bytes
struct114 *D_803E982C;  // struct is 4 bytes
static s32  D_803E9830; // unused
static s16  D_803E9834; // unused
static u16  D_803E9836; // curDPadUp
static u16  D_803E9838; // curDPadDown
static u16  D_803E983A; // curDPadLeft
static u16  D_803E983C; // curDPadRight

// FIXME: are these somehow defined in overlay2_72C680 where they are used...?
Collision D_803E9840[9];
s16  D_803F28C2; // TBD

// ========================================================
// .text
// ========================================================

// ESA: func_8007F0E0
void func_80327BE0_739290(void) {
    s16 i;
    s16 tmp;

    // R trigger && previously L/R triggers were not pressed
    if ((D_801D9ED8.curLRTrigger == R_TRIGGER) && (D_801D9ED8.prevLRTrigger == NO_TRIGGER)) {
        // try_swap_animal() ?
        func_80328ACC_73A17C();
    }

    for (i = 0; (D_803E9828[D_803E9822].unk2[i] != 0xFF) && (i < 6); i++) {
        if ((D_803E982C[D_803E9828[D_803E9822].unk2[i]].unk3 == 1) || (D_803E982C[D_803E9828[D_803E9822].unk2[i]].unk3 == 2)) {
            tmp = D_803E982C[D_803E9828[D_803E9822].unk2[i]].unk2;
            if ((tmp != 1) && (tmp != 2) && (tmp == 7) &&
                (D_801D9ED8.unkFFCE || (D_801D9ED8.curDPadDown && (D_801D9ED8.prevDPadDown == 0)))) {
                func_80328258_739908(i);
                i = 6; // break out of loop
            }
        }
    }

    D_803E9836 = D_801D9ED8.curDPadUp;
    D_803E9838 = D_801D9ED8.curDPadDown;
    D_803E983A = D_801D9ED8.curDPadLeft;
    D_803E983C = D_801D9ED8.curDPadRight;
    D_801D9ED8.unkFFCE = 0;
}

void func_80327DA0_739450(void) {
}

// ESA: func_8007F278
void func_80327DA8_739458(void) {
    switch (D_803E9820 - 1) {
    case 0:
        D_803E9828 = D_803A6070_7B7720; // 0x0001FF00
        D_803E982C = D_803A6078_7B7728;
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
    case 26: // evo microchip?
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

// ESA: func_8007F540
void func_80328258_739908(s16 idx) {
    u8 sp1F;

    func_8032AA94_73C144();

    sp1F = D_803E982C[D_803E9828[D_803E9822].unk2[idx]].unk1;

    D_803E9822 = D_803E982C[D_803E9828[D_803E9822].unk2[idx]].unk0;
    gCurrentAnimalId = D_803E9828[D_803E9822].unk0;
    D_803D5520->unk0 = &D_801D9ED8.unk0[gCurrentAnimalId];
    D_803D5524 = D_803D5520->unk0;
    D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C = &D_801D9ED8.unk0[gCurrentAnimalId];

    func_803283DC_739A8C();
    func_802B2EA8_6C4558();
    D_803D5530->unk46 = D_803D5530->unk16C->mass;
    func_802C9BA4_6DB254(D_801D9ED8.animals[gCurrentAnimalIndex].animal);

    switch (sp1F) {
    case 1:
        func_802DBA58_6ED108(0xF, D_803D552C);
        break;
    case 2:
        func_802DBA58_6ED108(0xF, D_803D552C);
        break;
    case 0:
        break;
    }
}

// ESA: func_8007F684
void func_803283DC_739A8C(void) {
    func_803284C4_739B74();

    if (D_803D5524->unk9C != ELEPHANT) {
        D_803D552C->unk308 = 0;
    }
    D_803D552C->unk30A = 0;
    D_803D552C->unk30C = 0;
    D_803D552C->unk30E = 0;

    switch (gCurrentAnimalId) { // current animal id
    case FLYING_DOG:
        D_803D552C->heading = 0;
        D_803D5530->unk28 = 0;
        D_803D5530->position.yPos.h += 35;
        break;
    case FOX:
        break;
    case FIRE_FOX:
        D_803D552C->heading = 0;
        D_803D5530->unk28 = 0;
        D_803D5530->position.yPos.h += 35;
        break;
    default:
    case FROG:
    case TORTOISE_TANK:
        break;
    }
}

// ESA: func_8007F78C
Camera* func_803284C4_739B74(void) {
    struct035 *temp_v1;
    Camera *camera;

    temp_v1 = D_803D5524;
    camera = &gCameras[gCameraId];
    camera->unk4E = temp_v1->unkCA;
    camera->unk54 = temp_v1->unkD0;
    camera->unk56 = temp_v1->unkD2;
    camera->unk58 = temp_v1->unkCC;
    camera->unk60 = temp_v1->unkCE;
    return camera;
}

// ESA: func_8007F7F4
void func_80328520_739BD0(void) {
    switch (D_803D552C->unk366) {
    case 1:
        if (D_803D5530->health <= 0) {
            D_803D552C->unk366 = 2U;
            func_80328918_739FC8();
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
            func_80321920_732FD0(D_803D552C->unk320, 0, 0);
        }
        break;
    case 3:
        if (D_803D5530->health <= 0) {
            D_803D552C->unk366 = 5U;
            func_80328918_739FC8();
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
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
                load_commands_into_object(D_803D5530, &D_803E4D40[D_803D5530->unk246 - 1], 0);
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
            play_sound_effect_at_location(SFX_DEACTIVATE_ANIMAL, 0x7000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
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
                load_commands_into_object(D_803D5530, &D_803E4D40[D_803D5530->unk246 - 1], 0);
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

// ESA: func_8007FB40
void func_80328918_739FC8(void) {
    D_803D552C->unk328 = D_803D5544;
    D_803D552C->unk36A = 1;
    D_803D552C->unk348 = 0;
    D_803D552C->unk34A = 0;
    D_803D552C->laughterThreshold = 0;
    D_803D552C->isLaughing = 0;
    D_803D552C->unk369 = 0;
    D_803D552C->unk365 = ATTACK_NONE;
    D_803D552C->unk36E = 0;
    D_803D552C->unk364 = 0;
    D_803D552C->unk2EC = 0;

    if (D_803D5524->unk9C == SNEAKY_CHAMELEON) {
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

#if 0
// ESA: func_8007FD90
// CURRENT (9821)
void func_80328ACC_73A17C(void) {
    s16 temp_a0;
    s16 currentDist;
    s16 i;

    s16 bestDistance;
    s16 yPos;
    s16 zPos;
    s16 xPos;

    u16 animalId;

    // s16 sp8E;
    // s16 sp8C;
    // s16 sp8A;
    // s16 sp88;
    s16 sp86;

    u8 doSwap; // can swap?
    u8 tmp;
    s16 tempAnimalIndex;

    // s16 sp84;
    // s16 sp82;
    s16 sp80; // index of animal to swap with
    s16 sp7A;
    s16 sp78;

    Animal *currentAnimal;
    Animal *otherAnimal;

    s32 sp40; // curently sp70!?

    if (((D_803F2D50.unk52 != 3) || (D_803F2D50.segment != 2)) &&
        ((D_803F2D50.unk52 != 5) || (D_803F2D50.segment != 0)) &&
        ((D_803F2D50.unk52 != 4) || (D_803F2D50.segment != 1)) &&
        (D_803F2D50.segment != 5U)) {

        sp40 = gCurrentAnimalIndex;
        animalId = D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C;

        if (((D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C != EVO))) {


            if (((D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk320 == NULL) || (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk320->unk16C->unk82.unk2 == 0)) &&
                (animalId != VULTURE) && (animalId != SEAGULL2) && (animalId != POLAR_BEAR_DEFENDING) &&
                (animalId != PARROT_ATTACKING) && (animalId != HARD_MOUSE) && (animalId != CRAZY_BEAR) &&
                (animalId != TORTOISE_TANK_DEFENDING) && (animalId != CRAZY_HUSKY) && (animalId != CROW_DIVER) &&
                (animalId != DESERT_FOX_ATTACKING) && (animalId != SNEAKY_CHAMELEON) && (animalId != RACING_TORTOISE_DEFENDING) &&
                (D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A <= 0)) {

                currentAnimal = D_801D9ED8.animals[gCurrentAnimalIndex].animal;

                xPos = currentAnimal->position.xPos.h;
                zPos = currentAnimal->position.zPos.h;
                yPos = currentAnimal->position.yPos.h;
                sp86 = (currentAnimal->unk42 >> 1) + yPos;

                bestDistance = 129;

                // iterate over all animals in the level
                for (i = 0; i < D_803D553E; i++) {
                    // why not start with i = 1 ?
                    if (i != 0) {
                        if (i != gCurrentAnimalIndex) {
                            otherAnimal = D_801D9ED8.animals[i].animal;
                            if ((otherAnimal != NULL) && (otherAnimal->unk366 == 5) && (otherAnimal->unk4A == 0)) {
                                if ((ABS(otherAnimal->position.xPos.h - xPos) < 0x81) &&
                                    (ABS(otherAnimal->position.zPos.h - zPos) < 0x81) &&
                                    (ABS(((otherAnimal->unk42 >> 1) + otherAnimal->position.yPos.h) - sp86) < 0x81)) {

                                    currentDist = MAX(MAX(ABS(otherAnimal->position.xPos.h - xPos), ABS(otherAnimal->position.zPos.h - zPos)), (ABS(otherAnimal->position.yPos.h - yPos) * 2));
                                    // new candidate
                                    if (currentDist < bestDistance) {
                                        if (func_80329BAC_73B25C(gCurrentAnimalIndex, i) != 0) {
                                            // new closest animal
                                            bestDistance = currentDist;
                                            sp80 = i;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                // any animals close?
                if (bestDistance < 0x81) {
                    if (sp40 != 0) {
                        Animal *a;

                        func_8032AA94_73C144();

                        D_801D9ED8.animals[0].animal->health = D_801D9ED8.animals[gCurrentAnimalIndex].animal->health;
                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = 0;

                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->yVelocity.w -= 0x4000;

                        temp_a0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0;
                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0 = D_801D9ED8.animals[0].animal->energy[0].unk0;
                        D_801D9ED8.animals[0].animal->energy[0].unk0 = temp_a0;

                        temp_a0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0;
                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0 = D_801D9ED8.animals[0].animal->energy[1].unk0;
                        D_801D9ED8.animals[0].animal->energy[1].unk0 = temp_a0;

                        D_801D9ED8.animals[0].animal->unk4A = 0;
                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 0;

                        tmp = D_801D9ED8.animals[0].animal->unk4C.unk1A;
                        D_801D9ED8.animals[0].animal->unk4C.unk1A = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4C.unk1A;
                        D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4C.unk1A = tmp;

                        D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
                        D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
                        D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
                        D_803D552C = D_803D5528;
                        D_803D5530 = D_803D5528;

                        if (1) {};

                        D_803D5538 = 1;
                        D_803D553C = gCurrentAnimalIndex; //??
                        D_803D553A = 0;

                        D_803D552C->unk366 = 5;

                        func_80328918_739FC8();
                        func_802C9BA4_6DB254((struct071 *) D_803D5530);

                        tempAnimalIndex = gCurrentAnimalIndex;
                        gCurrentAnimalIndex = 0;
                        D_803D5536 = tempAnimalIndex;

                        D_803D5520 = &D_801D9ED8.animals[0];
                        D_803D5524 = D_801D9ED8.animals[0].unk0;
                        D_803D5528 = D_801D9ED8.animals[0].animal;
                        D_803D552C = D_803D5528;
                        D_803D5530 = D_803D5528;

                        if (gCurrentAnimalIndex == 0) {
                            D_803D5538 = 1;
                        } else {
                            D_803D5538 = 0;
                        }

                        D_803D553C = 0;
                        D_803D553A = 0;

                        D_803D552C->unk366 = 1;
                        D_803D552C->unk328 = D_803D5544;
                        D_803D552C->unk36A = 2;

                        D_803D5520->unk0 = &D_801D9ED8.unk0[62];
                        D_803D5530->unk16C = &D_801D9ED8.unk0[62];

                        gCurrentAnimalId = EVO;
                        D_803E9820 = 27;
                        D_803E9822 = 2;

                        func_80327DA8_739458();
                        func_803283DC_739A8C();

                        D_803D552C->unk308 = D_801D9ED8.animals[D_803D5536].animal->position.xPos.h;
                        D_803D552C->unk30A = D_801D9ED8.animals[D_803D5536].animal->position.zPos.h;
                        D_803D552C->unk30C = D_801D9ED8.animals[D_803D5536].animal->position.yPos.h + (D_801D9ED8.animals[D_803D5536].unk0->unkBA / 2) ;
                        D_803D5530->position.xPos.h = D_803D552C->unk308;
                        D_803D5530->position.zPos.h = D_803D552C->unk30A;
                        D_803D5530->position.yPos.h = D_803D552C->unk30C;
                        D_803D552C->unk365 = ATTACK_EVO_CHIP_2;
                        D_803D552C->unk32A = D_803D5544;
                        D_803D552C->unk320 = D_801D9ED8.animals[sp80].animal;
                        D_803D552C->unk30E = sp80;
                        D_803D5530->unk163 = D_801D9ED8.animals[D_803D5536].animal->unk163;
                        D_803D5530->unk18C = D_801D9ED8.animals[D_803D5536].animal->unk18C;

                        for (i = 0; i < 4; i++) {
                            D_803D5530->unk18D[i] = D_801D9ED8.animals[D_803D5536].animal->unk18D[i];
                        }

                        D_803D5530->unk18C = D_801D9ED8.animals[D_803D5536].animal->unk18C;
                        D_803D5530->unk160 = D_801D9ED8.animals[D_803D5536].animal->unk160;
                        func_802B2EA8_6C4558();

                        play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    } else {
                        D_803D5520 = &D_801D9ED8.animals[0];
                        D_803D5524 = D_801D9ED8.animals[0].unk0;
                        D_803D5528 = D_801D9ED8.animals[0].animal;
                        D_803D552C = D_803D5528;
                        D_803D5530 = D_803D5528;

                        if (sp40 == 0) {
                            D_803D5538 = 1;
                        } else {
                            D_803D5538 = 0;
                        }

                        D_803D553C = 0;
                        D_803D553A = 0;

                        D_803D5520->unk0 = &D_801D9ED8.unk0[62]; // D_801DD8EC
                        D_803D5530->unk16C = &D_801D9ED8.unk0[62];

                        gCurrentAnimalId = EVO;
                        D_803E9820 = 27;
                        D_803E9822 = 2;

                        func_80327DA8_739458();
                        D_803D552C->unk308 = D_801D9ED8.animals[0].animal->position.xPos.h;
                        D_803D552C->unk30A = D_801D9ED8.animals[0].animal->position.zPos.h;
                        D_803D552C->unk30C = D_801D9ED8.animals[0].animal->position.yPos.h + (D_801D9ED8.animals[0].unk0->unkBA / 2);
                        D_803D552C->unk365 = ATTACK_EVO_CHIP_2;
                        D_803D552C->unk32A = D_803D5544;
                        D_803D552C->unk320 = D_801D9ED8.animals[sp80].animal;
                        D_803D552C->unk30E = sp80;
                        play_sound_effect_at_location(SFX_UNKNOWN_56, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                    }
                } else {
                    temp_a0 = (func_80310EE4_722594(D_801D9ED8.animals[sp40].animal->position.xPos.h, D_801D9ED8.animals[sp40].animal->position.zPos.h, D_801D9ED8.animals[sp40].animal->unk160) >> 0x10);
                    currentAnimal = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
                    temp_a0 = currentAnimal->position.yPos.h - temp_a0;

                    if ((D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == FIRE_FOX) ||
                        (D_801D9ED8.animals[gCurrentAnimalIndex].unk0->unk9C == FLYING_DOG)) {
                        if (temp_a0 < 0x80) {
                            func_80311A2C_7230DC(currentAnimal->position.xPos.h, currentAnimal->position.zPos.h, &sp7A, &sp78, currentAnimal->unk160);

                            if ((ABS(sp7A) < 12) && (ABS(sp78) < 12)) {
                                doSwap = 1;
                                D_801D9ED8.animals[gCurrentAnimalIndex].animal->xVelocity.w = 0;
                                D_801D9ED8.animals[gCurrentAnimalIndex].animal->zVelocity.w = 0;
                            } else {
                                doSwap = 0;
                            }
                        } else {
                            doSwap = 0;
                        }
                    } else if ((currentAnimal->xVelocity.w != 0) || (currentAnimal->zVelocity.w != 0) || (currentAnimal->yVelocity.w > 0) ||
                        (((currentAnimal->unk162 != 1)) && (currentAnimal->unk162 != 6)) ||
                        (((currentAnimal->unk6C != NULL)) && ((currentAnimal->unk6C->unk16C->objectType != OBJECT_BUTTON)) && ((currentAnimal->unk6C->unk16C->objectType != OBJECT_FLAT_BLOCK_1) || (temp_a0 >= 0x20)))) {
                        // logic feels weird, should it all be inverted?
                        doSwap = 0;
                    } else {
                        doSwap = 1;
                    }

                    if (doSwap != 0) {
                        if (gCurrentAnimalIndex != 0) {
                            // swap health
                            temp_a0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->health;
                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->health = D_801D9ED8.animals[0].animal->health;
                            D_801D9ED8.animals[0].animal->health = temp_a0;

                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->yVelocity.w -= 0x4000;

                            temp_a0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0;
                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[0].unk0 = D_801D9ED8.animals[0].animal->energy[0].unk0;
                            D_801D9ED8.animals[0].animal->energy[0].unk0 = temp_a0;

                            temp_a0 = D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0;
                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->energy[1].unk0 = D_801D9ED8.animals[0].animal->energy[1].unk0;
                            D_801D9ED8.animals[0].animal->energy[1].unk0 = temp_a0;

                            D_801D9ED8.animals[0].animal->unk4A = 0;
                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4A = 0;

                            tmp = D_801D9ED8.animals[0].animal->unk4C.unk1A;
                            D_801D9ED8.animals[0].animal->unk4C.unk1A = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4C.unk1A;
                            D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk4C.unk1A = tmp;

                            D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
                            D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;
                            D_803D5528 = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
                            D_803D552C = D_803D5528;
                            D_803D5530 = D_803D5528;

                            D_803D5538 = 1;
                            D_803D553C = gCurrentAnimalIndex;
                            D_803D553A = 0;

                            D_803D552C->unk366 = 5;

                            func_80328918_739FC8();

                            D_803D5530->health = 0;

                            tempAnimalIndex = gCurrentAnimalIndex;
                            gCurrentAnimalIndex = 0;
                            D_803D5536 = tempAnimalIndex;

                            D_803D5520 = &D_801D9ED8.animals[0];
                            D_803D5524 = D_801D9ED8.animals[0].unk0;
                            D_803D5528 = D_801D9ED8.animals[0].animal;
                            D_803D552C = D_803D5528;
                            D_803D5530 = D_803D5528;

                            if (gCurrentAnimalIndex == 0) {
                                D_803D5538 = 1;
                            } else {
                                D_803D5538 = 0;
                            }
                            D_803D553C = 0;
                            D_803D553A = 0;

                            D_803D552C->unk366 = 1;
                            D_803D552C->unk328 = D_803D5544;
                            D_803D552C->unk36A = 2;
                            D_803D5530->unk163 = D_801D9ED8.animals[D_803D5536].animal->unk163;
                            D_803D5530->unk18C = D_801D9ED8.animals[D_803D5536].animal->unk18C;

                            for (i = 0; i < 4; i++) {
                                D_803D5530->unk18D[i] = D_801D9ED8.animals[D_803D5536].animal->unk18D[i];
                            }

                            D_803D5530->unk18C = D_801D9ED8.animals[D_803D5536].animal->unk18C;
                            D_803D5520->unk0 = &D_801D9ED8.unk0[62];
                            D_803D5530->unk16C = &D_801D9ED8.unk0[62];
                            gCurrentAnimalId = EVO;
                            D_803E9820 = 27;
                            D_803E9822 = 2;
                            func_80327DA8_739458();
                            func_803283DC_739A8C();
                            D_801D9ED8.animals[0].animal->position.xPos.w = D_801D9ED8.animals[D_803D5536].animal->position.xPos.w;
                            D_801D9ED8.animals[0].animal->position.zPos.w = D_801D9ED8.animals[D_803D5536].animal->position.zPos.w;
                            D_801D9ED8.animals[0].animal->position.yPos.w = D_801D9ED8.animals[D_803D5536].animal->position.yPos.w + (D_801D9ED8.animals[D_803D5536].unk0->unkBA << 0xF) ;
                            D_801D9ED8.animals[0].animal->unk160 = D_801D9ED8.animals[D_803D5536].animal->unk160;
                            D_801D9ED8.animals[0].animal->unk68 = D_801D9ED8.animals[D_803D5536].animal->unk68;
                            D_801D9ED8.animals[0].animal->unk70 = D_801D9ED8.animals[D_803D5536].animal->unk70;
                            D_803D552C->unk365 = ATTACK_EVO_CHIP_1;
                            D_803D552C->unk32A = D_803D5544;
                            D_803D5530->yRotation = (D_801D9ED8.animals[D_803D5536].animal->yRotation + 150) & 0xFF;
                            D_803D552C->heading = (D_801D9ED8.animals[D_803D5536].animal->heading + 150) & 0xFF;
                            func_80329F44_73B5F4();
                            func_802B2EA8_6C4558();

                            play_sound_effect_at_location(SFX_EVO_TRANSFER, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
                        }
                    } else {
                        // cannot transfer
                        func_8032C508_73DBB8(SFX_UNKNOWN_16, 0x4000, 0, 1.0f);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_739290/func_80328ACC_73A17C.s")
#endif

// ESA: func_80080C0C
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

    sp64 = D_801D9ED8.animals[arg0].animal->position.xPos.h;
    sp66 = D_801D9ED8.animals[arg0].animal->position.zPos.h;
    sp62 = D_801D9ED8.animals[arg0].animal->position.yPos.h + (D_801D9ED8.animals[arg0].animal->unk42 / 3);
    sp53 = D_801D9ED8.animals[arg0].animal->unk160;

    sp5A = D_801D9ED8.animals[arg1].animal->position.xPos.h;
    sp5C = D_801D9ED8.animals[arg1].animal->position.zPos.h;
    sp58 = D_801D9ED8.animals[arg1].animal->position.yPos.h + (D_801D9ED8.animals[arg1].animal->unk42 / 3);
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

// ESA: func_80080EB0
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
        s16 xpos = D_801D9ED8.animals[0].animal->position.xPos.h & 0x3F;
        s16 zpos = D_801D9ED8.animals[0].animal->position.zPos.h & 0x3F;

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

// ESA: func_80081044
s16 func_8032A164_73B814(s16 arg0, s16 arg1) {
    s32 pad;
    s16 sp62;
    s16 sp60;
    s16 sp5E;
    s16 sp5C;

    s32 pad2;
    u8  sp57;
    s16 sp54;

    s16 sp34;
    s16 sp30;

    s16 temp_t0;
    s16 temp_t1;

    struct065 *var_a1;

    sp5E = D_801D9ED8.animals[0].animal->position.xPos.h;
    sp34 = sp5E + (arg0 << 6);
    temp_t0 = sp34 >> 6;

    sp5C = D_801D9ED8.animals[0].animal->position.zPos.h;
    sp30 = sp5C + (arg1 << 6);
    temp_t1 = sp30 >> 6;

    sp57 = D_801D9ED8.animals[0].animal->unk160;

    if ((temp_t0 < 2) || (temp_t0 >= 70)) {
        // outside of level
        return -1;
    }

    if ((temp_t1 < 2) || (temp_t1 >= 126)) {
        // outside of level
        return -1;
    }

    switch (sp57) {
    case 2:
        if (D_803C0740[temp_t0][temp_t1].unk3 == 0) {
            return -1;
        }
        func_80311A2C_7230DC(sp34, sp30, &sp62, &sp60, sp57);

        if (ABS(sp62) > 18) {
            return -1;
        }
        if (ABS(sp60) > 18) {
            return -1;
        }
        sp54 = ABS(func_80310EE4_722594(sp5E, sp5C, sp57) - func_80310EE4_722594(sp34, sp30, sp57)) >> 0x10;
        break;
    case 1:
        if (D_803C0740[temp_t0][temp_t1].unk3 == 0) {
            return -1;
        }
        func_80311A2C_7230DC(sp34, sp30, &sp62, &sp60, sp57);

        if (ABS(sp62) > 18) {
            return -1;
        }
        if (ABS(sp60) > 18) {
            return -1;
        }
        sp54 = ABS(func_80310EE4_722594(sp5E, sp5C, sp57) - func_80310EE4_722594(sp34, sp30, sp57)) >> 0x10;
        break;
    case 0:
        if (D_803C0740[temp_t0][temp_t1].unk3 != 0) {
            return -1;
        }
        func_80311A2C_7230DC(sp34, sp30, &sp62, &sp60, sp57);

        if (ABS(sp62) > 18) {
            return -1;
        }
        if (ABS(sp60) > 18) {
            return -1;
        }
        sp54 = ABS(func_80310EE4_722594(sp5E, sp5C, sp57) - func_80310EE4_722594(sp34, sp30, sp57)) >> 0x10;
        break;
    }

    for (var_a1 = D_803DA110[(s16) ((temp_t0 >> 4) + ((temp_t1 >> 4) * 5))].next; var_a1 != NULL; var_a1 = var_a1->next) {
        if ((var_a1->animal != D_801D9ED8.animals[D_803D5536].animal) && (var_a1->animal != D_801D9ED8.animals[0].animal)) {
            if ((ABS(var_a1->animal->position.xPos.h - sp34) < MAX(0x20, var_a1->animal->unk30)) && (ABS(var_a1->animal->position.zPos.h - sp30) < MAX(0x20, var_a1->animal->unk30))){
                return -1;
            }
        }
    }
    return sp54;
}

// ESA: func_800813C8
void func_8032A710_73BDC0(void) {
    s16 swapIdx;
    s16 temp_v1;
    s16 i;
    u8 tmp;

    swapIdx = D_803D552C->unk30E;
    D_803D552C->unk320 = NULL;
    func_8032AA94_73C144();

    temp_v1 = D_801D9ED8.animals[swapIdx].animal->health;
    D_801D9ED8.animals[swapIdx].animal->health = D_801D9ED8.animals[0].animal->health;
    D_801D9ED8.animals[0].animal->health = temp_v1;

    temp_v1 = D_801D9ED8.animals[swapIdx].animal->energy[0].unk0;
    D_801D9ED8.animals[swapIdx].animal->energy[0].unk0 = D_801D9ED8.animals[0].animal->energy[0].unk0;
    D_801D9ED8.animals[0].animal->energy[0].unk0 = temp_v1;

    temp_v1 = D_801D9ED8.animals[swapIdx].animal->energy[1].unk0;
    D_801D9ED8.animals[swapIdx].animal->energy[1].unk0 = D_801D9ED8.animals[0].animal->energy[1].unk0;
    D_801D9ED8.animals[0].animal->energy[1].unk0 = temp_v1;

    D_801D9ED8.animals[0].animal->unk4A = 0;
    D_801D9ED8.animals[swapIdx].animal->unk4A = 0;

    tmp = D_801D9ED8.animals[0].animal->unk4C.unk1A;
    D_801D9ED8.animals[0].animal->unk4C.unk1A = D_801D9ED8.animals[swapIdx].animal->unk4C.unk1A;
    D_801D9ED8.animals[swapIdx].animal->unk4C.unk1A = tmp;

    D_803D5520 = &D_801D9ED8.animals[0];
    D_803D5524 = D_801D9ED8.animals[0].unk0;
    D_803D5528 = D_801D9ED8.animals[0].animal;
    D_803D552C = D_803D5528;
    D_803D5530 = D_803D5528;

    if (gCurrentAnimalIndex == 0) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = 0;
    D_803D553A = 0;

    D_803D5520->unk0 = &D_801D9ED8.unk0[62];
    D_803D5530->unk16C = &D_801D9ED8.unk0[62];

    gCurrentAnimalIndex = swapIdx;
    D_803D5520 = &D_801D9ED8.animals[swapIdx];
    D_803D5524 = D_801D9ED8.animals[swapIdx].unk0;
    D_803D5528 = D_801D9ED8.animals[swapIdx].animal;
    D_803D552C = D_803D5528;
    D_803D5530 = D_803D5528;

    if (gCurrentAnimalIndex == swapIdx) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = swapIdx;
    D_803D553A = 0;

    D_803D552C->unk366 = 1;
    D_803D552C->unk328 = D_803D5544;
    D_803D552C->unk36A = 2;
    D_803D5530->unk163 = D_801D9ED8.animals[0].animal->unk163;
    D_803D5530->unk18C = D_801D9ED8.animals[0].animal->unk18C;

    for (i = 0; i < 4; i++) {
        D_803D5530->unk18D[i] = D_801D9ED8.animals[0].animal->unk18D[i];
    }

    D_803D5530->unk18C = D_801D9ED8.animals[0].animal->unk18C;
    gCurrentAnimalId = D_801D9ED8.animals[swapIdx].unk0->unk9C;
    D_803E9820 = D_803A63B0_7B7A60[gCurrentAnimalId].unk0;
    D_803E9822 = D_803A63B0_7B7A60[gCurrentAnimalId].unk1;
    check_and_set_species_encountered(gCurrentAnimalId);
    func_80327DA8_739458();
    func_803283DC_739A8C();
    func_802B2EA8_6C4558();
    func_802C9BA4_6DB254((struct071 *) D_803D5530);

    D_803D5520 = &D_801D9ED8.animals[0];
    D_803D5524 = D_801D9ED8.animals[0].unk0;
    D_803D5528 = D_801D9ED8.animals[0].animal;
    D_803D552C = D_803D5528;
    D_803D5530 = D_803D5528;

    if (gCurrentAnimalIndex == 0) {
        D_803D5538 = 1;
    } else {
        D_803D5538 = 0;
    }
    D_803D553C = 0;
    D_803D553A = 0;
    play_sound_effect_at_location(40, 0x5000, 0, D_803D5530->position.xPos.h, D_803D5530->position.zPos.h, D_803D5530->position.yPos.h, 1.0f);
}

void func_8032AA94_73C144(void) {
    func_80321920_732FD0(D_803D552C->unk320, 0, 0);
    D_803D552C->unk320 = 0;
    if (D_803D5530->state == 0xDD) {
        func_802E4AB8_6F6168();
    }
}

void load_animal(s16 animalId) {
    D_803D5520->unk0 = &D_801D9ED8.unk0[animalId];
    D_803D5530->unk16C = &D_801D9ED8.unk0[animalId];

    gCurrentAnimalId = animalId;

    D_803E9820 = D_803A63B0_7B7A60[gCurrentAnimalId].unk0;
    D_803E9822 = D_803A63B0_7B7A60[gCurrentAnimalId].unk1;
    func_80327DA8_739458();
    D_803D5530->unk46 = D_803D5530->unk16C->mass;
    func_802C9BA4_6DB254(D_803D5530);
    D_803D5524 = D_803D5520->unk0;
}

// Load New Animal Cutscene (NAC) if first time player is transferring into an animal
// NOTE: There is a bug where seen species overlap.
//       The modulo operation should be % 8, not % 7 to yield 64 possible values (rather than 56)
void check_and_set_species_encountered(s16 animal_id) {
    if ((D_803E4D28 & 8) == 0) {
        // if first time visiting then load TV info screen
        if (((D_8023F260.speciesSeen[(s8) (animal_id >> 3)] & (1 << (s8)(animal_id % 7))) == 0) && (gInputMode == INPUT_MODE_USER)) {
            D_8023F260.speciesSeen[(s8) (animal_id >> 3)] |= (1 << (s8)(animal_id % 7));
            trigger_new_animal_cutscene();
        }
    }
}

void set_species_as_encountered(s16 animal_id) {
    D_8023F260.speciesSeen[(s8) (animal_id >> 3)] |= (1 << (s8) (animal_id % 7));
}

// funny effect 1: weird continuous growing/shrinking
void func_8032AC98_73C348(void) {
    Animal *a;
    s16 i;

    for (i = 0; i < D_803D553E; i++) {
        if (1) {};
        if (D_801D9ED8.animals[i].animal != NULL) {
            if ((D_801D9ED8.animals[i].unk0->unk9C != EVO_TRANSFER) && (D_801D9ED8.animals[i].animal->unk366 != 6)) {
                D_803D5520 = &D_801D9ED8.animals[i];
                D_803D5524 = D_801D9ED8.animals[i].unk0;

                a = D_801D9ED8.animals[i].animal;
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
                D_803D552C->lastHpLost = 100;
            }
        }
  }
    if ((D_803A6CE4_7B8394 & (4 | 2)) == 0) {
        D_803A6CE4_7B8394 |= 2;
    } else {
        D_803A6CE4_7B8394 |= 4;
    }
}

// funny effect 2: infinite a+b energy? flips camera
void func_8032AE34_73C4E4(void) {
    s16 i;

    for (i = 0; i < AID_MAX_ANIMALS; i++) {
        D_801D9ED8.unk0[i].unkDA[0][0] = 1;
        D_801D9ED8.unk0[i].unkDA[1][0] = 1;
    }
    if ((D_803A6CE4_7B8394 & 5) == 0) {
        D_803A6CE4_7B8394 |= 1;
    } else {
        D_803A6CE4_7B8394 |= 4;
    }
}

// funny effect 3: tiny body / big head
void func_8032AEA0_73C550(void) {
    struct035 *tmp;
    s16 i;

    if ((D_803A6CE4_7B8394 & 8) != 0) {
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

    D_803A6CE4_7B8394 |= (8 | 4);
}

// funny effect 4: turns bear into unibear
void func_8032B084_73C734(void) {
    Animal *a;
    s32 id;
    id = D_801D9ED8.animals[gCurrentAnimalIndex].animal->unk16C->objectType;
    if (id == OB_TYPE_ANIMAL_OFFSET+BEAR) {
        a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;

        D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
        D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

        D_803D5528 = a;
        if (D_803D5528 == NULL) {}; // fakematch
        D_803D552C = a;
        D_803D5530 = a;

        D_803D5538 = 1;
        D_803D553C = gCurrentAnimalIndex;
        D_803D553A = 0;

        load_animal(MYSTERY_BEAR);
        func_802B2EA8_6C4558(); // reset animal state?
        D_803A6CE4_7B8394 |= 4;
    } else if (id == OB_TYPE_ANIMAL_OFFSET+MYSTERY_BEAR) {
        a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;

        D_803D5520 = &D_801D9ED8.animals[gCurrentAnimalIndex];
        D_803D5524 = D_801D9ED8.animals[gCurrentAnimalIndex].unk0;

        D_803D5528 = a;
        if (D_803D5528 == NULL) {}; // fakematch
        D_803D552C = a;
        D_803D5530 = a;

        D_803D5538 = 1;
        D_803D553C = gCurrentAnimalIndex;
        D_803D553A = 0;

        load_animal(BEAR);
        func_802B2EA8_6C4558(); // reset animal state?
        D_803A6CE4_7B8394 &= ~4;
    } else {
        func_803421E0_753890(100); // do something to camera
    }
}

// cheat 5: nothing?
void func_8032B1C8_73C878(void) {
    D_803A6CE4_7B8394 &= ~(1 | 2 | 4);
}
