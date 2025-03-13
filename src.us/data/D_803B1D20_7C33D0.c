#include <ultra64.h>

#include "common.h"

// Type 15 level data is written into this array (via load_level_data_sections)
// but the data is never read back
// NOTE: all levels have the same data for this section:
//   0001 0000 f500 0000 0a00
//   0, 1, 0, 0, 245, 0, 0, 10, 0

// could be struct105 (camera waypoint related) similar to e.g. D_803A6D14_7B83C4
u8 D_803B1D20_7C33D0[512] = {
    5,   4, 240, 18, 16, 0, 70, 0,
    12, 20, 240, 20, 30, 0, 50, 0,
    0,   0, 245,  0,  0, 0,  1, 0,
};
