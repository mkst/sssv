#ifndef OBJECTS_H
#define OBJECTS_H

/*
 * Object IDs are grouped by the ROM segment that provides their display-list
 * data in sssv.us.yaml. ovl_01 is always present; ovl_04 is the active biome;
 * ovl_05 is the active level/slot.
 */

/* ovl_01: segment1 (always loaded, VRAM 0x01000000) */

#define OBJECT_BOULDER              2
#define OBJECT_PALM_TREE_1          3

#define OBJECT_TUNNEL               8
#define OBJECT_BONUS_RING           9
#define OBJECT_BOULDER_NO_GRAVITY   10

#define OBJECT_BLOCK_1              12
#define OBJECT_BLOCK_2              13

#define OBJECT_TREE_TRUNK           16
#define OBJECT_CANNONBALL           17
#define OBJECT_ROCKET               18
#define OBJECT_CHERRY_TREE_1        19

#define OBJECT_FLAT_BLOCK_1         23
#define OBJECT_ACTIVE_SWITCH        24
#define OBJECT_BLOCK_3              25
#define OBJECT_BLUE_FLOWERS_1       26
#define OBJECT_BARREL               27
#define OBJECT_POST                 28

#define OBJECT_CHERRY_TREE_TRUNK    31
#define OBJECT_TREE_TRUNK_2         32
#define OBJECT_MINE                 33
#define OBJECT_POWERCELL_2          34
#define OBJECT_PILLAR               36

#define OBJECT_CANNONBALL_2         38
#define OBJECT_WATER_CANNON_1       39
#define OBJECT_SIGNPOST_1           40
#define OBJECT_WHEEL_SWITCH         41
#define OBJECT_BUTTON               42
#define OBJECT_GRAVITY_SWITCH       43
#define OBJECT_PLANK                44
#define OBJECT_LEVER_SWITCH         45

#define OBJECT_STALAGMITE           47
#define OBJECT_STALACTITES          48

#define OBJECT_FLAME_TORCH          50
#define OBJECT_TREE_TRUNK_3         53
#define OBJECT_TELEPORTER_BASE      54
#define OBJECT_ENTRANCE_TELEPORTER  55
#define OBJECT_EXIT_TELEPORTER      56
#define OBJECT_ENERGY_BALL_PURPLE   58
#define OBJECT_ENERGY_BALL_PURPLE_2 59
#define OBJECT_ENERGY_BALL          60
#define OBJECT_SNOWBALL             61
#define OBJECT_ACTIVE_TURRET        62
#define OBJECT_ACTIVE_MISSILE_TURRET 63

#define OBJECT_PLANT_1              65
#define OBJECT_PLANT_2              66
// potentially dynamic? initiated as empty displaylist
#define OBJECT_BLACK_FOG            67
#define OBJECT_PINE_TREE            68
#define OBJECT_BLUE_FLOWER_1        69
#define OBJECT_BLUE_FLOWER_2        70

#define OBJECT_SEA_MINE             72

#define OBJECT_77                   77
#define OBJECT_POWERCELL            80
#define OBJECT_DEAD_SCIENTIST_1     81
#define OBJECT_DEAD_SCIENTIST_2     82
#define OBJECT_BLOCK_4              83
#define OBJECT_BRIDGE_SECTION_1     84
#define OBJECT_BRIDGE_SECTION_2     85
#define OBJECT_BLOCK_5              86
#define OBJECT_BLOCK_6              87
#define OBJECT_BLOCK_7              88
#define OBJECT_BLOCK_8              89
#define OBJECT_BLOCK_9              90
#define OBJECT_BLOCK_10             91
#define OBJECT_BLOCK_11             92
#define OBJECT_DOOR                 97

#define OBJECT_LEVEL_TOUR_CAMERA    103
#define OBJECT_FARM_SPRAYER         105
#define OBJECT_MOUSE_MASHER         109
#define OBJECT_LOG                  111
#define OBJECT_FAUCET               129
#define OBJECT_PLANET_EARTH         134
#define OBJECT_SPEAKER              141
#define OBJECT_RED_TV               142
#define OBJECT_SIGNPOST_2           161
#define OBJECT_CRATE                162
#define OBJECT_TV_SCREEN            242

/* ovl_04: europe_biome */

#define OBJECT_EUROPE_30            30
#define OBJECT_EUROPE_COMPUTER      107
#define OBJECT_EUROPE_RACING_MOUSE  164
#define OBJECT_EUROPE_238           238
#define OBJECT_EUROPE_239           239

/* ovl_04: ice_biome */

#define OBJECT_ICE_ICEBERG          96
#define OBJECT_ICE_OBELISK          115
#define OBJECT_KING_PENGUIN_STATUE  120
#define OBJECT_ICE_IGLOO            144

/* ovl_04: jungle_biome */

#define OBJECT_JUNGLE_37            37
#define OBJECT_JUNGLE_78            78
#define OBJECT_JUNGLE_95            95
#define OBJECT_JUNGLE_98            98
#define OBJECT_JUNGLE_99            99
#define OBJECT_JUNGLE_101           101
#define OBJECT_JUNGLE_HOVERBUG      194

/* ovl_04: desert_biome */

#define OBJECT_DESERT_CACTUS        4
#define OBJECT_DESERT_PALM_TREE     35
#define OBJECT_DESERT_75            75
#define OBJECT_DESERT_PALM_TREE_2   157
#define OBJECT_DESERT_DINOSAUR      160
#define OBJECT_DESERT_244           244

/* ovl_04: city_biome */

#define OBJECT_CITY_100             100
#define OBJECT_EVIL_BRAIN           145
#define OBJECT_STATUE_OF_LIBERTY    199
#define OBJECT_CITY_200             200
#define OBJECT_CITY_TAXI            201
#define OBJECT_SUBMARINE            202
#define OBJECT_TANK                 203
#define OBJECT_FIGHTER_JET          205
#define OBJECT_BOMBER               206
#define OBJECT_AMBULANCE            207
#define OBJECT_HOVERCRAFT           208
#define OBJECT_SATELITE_DISH        209
#define OBJECT_SATELITE_POLE        210
#define OBJECT_CITY_211             211
#define OBJECT_CITY_212             212
#define OBJECT_CITY_213             213
#define OBJECT_CITY_218             218
#define OBJECT_CITY_EVIL_BRAIN_CASING    224
#define OBJECT_CITY_225             225
#define OBJECT_CITY_TAXI_2          226
#define OBJECT_CITY_SPACESTATION_DOOR    227
#define OBJECT_CITY_SPACESTATION_DOOR_2  228
#define OBJECT_CITY_STREET_LIGHT         229

/* ovl_05: data_7F790 (Dan Danger) */

#define OBJECT_DAN_1                135

/* ovl_05: DMA_INTRO */

#define OBJECT_INTRO_DMA_LOGO       125

/* ovl_05: SMASHING_START */

#define OBJECT_SMASHING_START_SPACESHIP    74
#define OBJECT_SMASHING_START_ASTEROID     136
#define OBJECT_SMASHING_START_SIGNPOST     137
#define OBJECT_SMASHING_START_BROKEN_GLASS 150
#define OBJECT_SMASHING_START_DASHBOARD    180
#define TROPHY_SMASHING_START              237
#define OBJECT_SMASHING_START_CAPSULE      240

/* ovl_05: HAVE_A_NICE_DAY */

#define OBJECT_HAVE_A_NICE_DAY_HOUSE 117
#define OBJECT_HAVE_A_NICE_DAY_TREE_1 139
#define OBJECT_HAVE_A_NICE_DAY_TREE_2 169

/* ovl_05: HONEYMOON_LAGOON */

#define OBJECT_HONEYMOON_LAGOON_OBJECT_46       46
#define OBJECT_HONEYMOON_LAGOON_BIG_MACHINE_ARM 49
#define TROPHY_HONEYMOON_LAGOON     76

/* ovl_05: THE_BATTERY_FARM */

#define OBJECT_THE_BATTERY_FARM_DOG_KENNEL       1
#define OBJECT_THE_BATTERY_FARM_CARROT           7
#define OBJECT_THE_BATTERY_FARM_CHAIR            51
#define OBJECT_THE_BATTERY_FARM_TABLE            52
#define OBJECT_THE_BATTERY_FARM_DOG_BED          73

/* ovl_05: STINKY_SEWERS */

#define OBJECT_STINKY_SEWERS_TOILET_SEAT 130
#define OBJECT_STINKY_SEWERS_TOILET      131
#define OBJECT_STINKY_SEWERS_TURD        140

/* ovl_05: RAT_O_MATIC */

#define OBJECT_RAT_O_MATIC_WATERWHEEL 57
#define TROPHY_OBJECT_RAT_O_MATIC     165

/* ovl_05: ROCKY_HARD_PLACE */

#define TROPHY_ROCKY_HARD_PLACE     71


/* ovl_05: GIVE_A_DOG_A_BONUS */

#define TROPHY_GADAB                233


/* ovl_05: SOMETHING_FISHY */

#define OBJECT_SOMETHING_FISHY_PENTAGON_POT 146
#define OBJECT_SOMETHING_FISHY_MINE         174
#define OBJECT_SOMETHING_FISHY_FISH_1       158
#define OBJECT_SOMETHING_FISHY_FISH_2       159
#define OBJECT_SOMETHING_FISHY_FISH_3       173
#define OBJECT_SOMETHING_FISHY_TROLLEY      181
#define OBJECT_SOMETHING_FISHY_SKULL        182
#define OBJECT_SOMETHING_FISHY_CHEST_LID    183
#define OBJECT_SOMETHING_FISHY_CHEST_BASE   184
#define OBJECT_SOMETHING_FISHY_FISH_BONES   185
#define OBJECT_SOMETHING_FISHY_LIMPIT       215
#define OBJECT_SOMETHING_FISHY_STARFISH     216

/* ovl_05: PINBALL_BLIZZARD */

#define OBJECT_PB_UFO               102
#define OBJECT_PB_UFO_GLASS         113

/* ovl_05: WALRACE_64 */

#define TROPHY_WALRACE_64              175
#define OBJECT_WALRACE_64_CHEERLEADER  176
#define OBJECT_WALRACE_64_BUOY         189

/* ovl_05: WEIGHT_FOR_IT */

#define TROPHY_WEIGHT_FOR_IT        5

/* ovl_05: SWAMP_OF_ETERNAL_STENCH */

#define TROPHY_SWAMP_OF_ETERNAL_STENCH 20

/* ovl_05: EVOS_ESCAPE */

#define OBJECT_EE_TURRET            118
#define OBJECT_EVOS_ESCAPE_ARROW    177
#define OBJECT_EE_GORILLA_STATUE    220
#define OBJECT_EE_LION_BUST         221
#define TROPHY_EVOS_ESCAPE          235

/* ovl_05: FUN_IN_THE_SUN */

#define OBJECT_FUN_IN_THE_SUN_138   138

/* ovl_05: HOT_CROSS_BUNS */

#define OBJECT_HCB_SCORPION_TAIL    114

/* ovl_05: PUNCHUP_PYRAMID */
#define OBJECT_BORASSIC_PARK_SKULL  190
#define OBJECT_BORASSIC_PARK_CLAW   191
#define OBJECT_BORASSIC_PARK_FLY    192
#define OBJECT_BORASSIC_PARK_195    195

/* ovl_05: PUNCHUP_PYRAMID */

#define OBJECT_PUNCHUP_PYRAMID_KANGAROO_STATUE   119
#define OBJECT_PUNCHUP_PYRAMID_ENTRANCE 152
#define TROPHY_PUNCHUP_PYRAMID      234

/* ovl_05: FAT_BEAR_MOUNTAIN */

#define TROPHY_FAT_BEAR_MOUNTAIN    129

/* ovl_05: JUNGLE_JUMPS */

#define TROPHY_JUNGLE_JUMPS         133



/* ovl_05: BIG_CELEBRATION_PARADE */

#define OBJECT_BCP_BRAIN_SURROUND   222
#define OBJECT_BCP_OBJECT_223       223
#define OBJECT_BCP_SHRINK_RAY       230


#endif
