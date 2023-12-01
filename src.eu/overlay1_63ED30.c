#include <ultra64.h>
#include "common.h"

extern Gfx D_801582E0[];
extern u8  D_80304388[];

void func_801356E0(s32 x, s32 y, u8 x_size, u8 y_size, Gfx **dl, u8 *arg5, f32 arg6, f32 arg7, u8 arg8);
typedef struct {
    u8 img[0x800];
} NewscasterTile;

void func_80299E00_63ED30(u8 size) {
  u8 *sp54;
  u8 j;
  u8 i;
  s32 sp4C;
  u8 sp4B;

  j = 0; // x
  i = 0; // y
  sp4C = 0; // image offset

  gSPDisplayList(D_801D9E9C++, &D_801582E0);

  func_801356E0(
      1,
      1,
      1,
      1,
      &D_801D9E9C,
      D_80304388 + 0x62000 + 0, // newscaster
      1.0f,
      1.0f,
      8);

  for (i = 0; i < 8; i++) {
      for (j = 0; j < 10; j++) {
          // draw black rectangle
          gDPSetPrimColor(D_801D9E9C++, 0, 0, 0, 0, 0, 255);
          gDPFillRectangle(D_801D9E9C++,
          /* ulx */ (j << 5) + (15 - (size / 2)),
          /* uly */ (i << 5) + (15 - (size / 2)),
          /* lrx */ (j << 5) + (17 - (size / 2)) + size,
          /* lry */ (i << 5) + (17 - (size / 2)) + size
          );

          // sp4B = (size << 3) - 1;
          sp4B = (-1) - ((-size) << 3);
          gDPSetPrimColor(D_801D9E9C++, 0, 0, sp4B, sp4B, sp4B, 0xFF);

          sp54 = D_80304388 + 0x62000 + sp4C;
          func_801356E0(
              (j << 5) + (16 - (size / 2)),
              (i << 5) + (16 - (size / 2)),
              size,
              size,
              &D_801D9E9C,
              sp54,
              size,
              size,
              16);

          sp4C += sizeof(NewscasterTile);
      }
  }

  gDPSetPrimColor(D_801D9E9C++, 0, 0, 255, 255, 255, 255);
}

void func_8029A144_63F074(s32 *arg0, s32 *arg1) {
    u8 spF;
    u8 spE;
    u8 spD;
    u8 spC;

    s32 *src = arg0; // sp8
    s32 *dst = arg1; // sp4

    spE = 8;
    while (spE--) {
        spF = 10;
        while (spF--) {
            spC = 32;
            while (spC--) {
                spD = 16;
                while (spD--) {
                    *dst++ = *src++;
                }
                src += 0x240 / 4; // 144
            }
            src += -0x4FC0 / 4; // 5104
        }
        src += 0x4D80 / 4; // 4960
    }
}
