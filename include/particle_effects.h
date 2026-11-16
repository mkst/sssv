#ifndef PARTICLE_EFFECTS_H
#define PARTICLE_EFFECTS_H

// Component flags for func_802D7BE0_6E9290; these are not particle IDs.
#define EXPLOSION_FX_FIRE               0x01 // Fire burst, scattered flames, and rumble.
#define EXPLOSION_FX_RISING_PARTICLES   0x02 // Two upward-moving type-48 particles per group; visual role unresolved.
#define EXPLOSION_FX_SMOKING_DEBRIS     0x04 // Five type-40 particles per group, which emit gray type-20 particles.
#define EXPLOSION_FX_COLORED_DEBRIS     0x08 // Shard sprites (types 71-76), tinted with the supplied color.
#define EXPLOSION_FX_NUTS_AND_BOLTS     0x10 // Hardware sprites (types 77-82), also tinted with the supplied color.
#define EXPLOSION_FX_BUBBLES            0x20 // Four rising type-28 bubbles per group.
#define EXPLOSION_FX_NO_SOUND           0x40 // Suppress this helper's SFX_UNKNOWN_75; rumble is independent.

// SMOKING_DEBRIS also reduces the extra COLORED_DEBRIS / NUTS_AND_BOLTS particles.

#endif
