#include <ultra64.h>
#include "common.h"


s16 distance_from_player(s16 x, s16 z, s16 y) {
    Animal *a = D_801D9ED8.animals[gCurrentAnimalIndex].animal;
    return ABS(x - a->position.xPos.h) + ABS(z - a->position.zPos.h) + ABS(y - a->position.yPos.h);
}
