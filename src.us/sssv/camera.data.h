#ifndef CAMERA_DATA_H
#define CAMERA_DATA_H

s16 D_803A6CC0_7B8370 = 0x100;

f32 D_803A6CC4_7B8374 = 1.0f;
f32 D_803A6CC8_7B8378 = 45.0f;
f32 D_803A6CCC_7B837C = 1.0f;

f32 D_803A6CD0_7B8380 = 1.0f;
f32 D_803A6CD4_7B8384 = 0.0f;
f32 D_803A6CD8_7B8388 = 0.0f;

s16 D_803A6CDC_7B838C = 25;
s16 D_803A6CE0_7B8390 = 0;
s16 D_803A6CE4_7B8394 = 0; // used by elephant, lion, husky + rat, "behind view"?
s16 D_803A6CE8_7B8398 = 0;
s16 D_803A6CEC_7B839C = -1;

u8 D_803A6CF0_7B83A0[12] = {
    0x03,
    0x07,
    0x0B,
    0x10,
    0x17,
    0x21,
    0x32,
    0x50,
    0x78,
    0xAA,
    0x00,
    0x00,
};

u8 D_803A6CFC_7B83AC[12] = {
    0x0C,
    0x0E,
    0x0F,
    0x10,
    0x10,
    0x10,
    0x10,
    0x10,
    0x10,
    0x10,
    0x00,
    0x00,
};

u8 D_803A6D08_7B83B8[12] = {
    0x90,
    0x2C,
    0x78,
    0x32,
    0x1E,
    0x14,
    0x10,
    0x10,
    0x10,
    0x10,
    0x00,
    0x00,
};

struct105 D_803A6D14_7B83C4[128] = {
    {
        0x00,
        0x00,
        0xF5,
        0x00,
        0x00,
        0x00,
        0x2E,
        0x09,
    },
};

struct074 D_803A7114_7B87C4[128] = {
    {
        0x01,
        0x29,
        0x0C,
        0xFF,
        0xFFFF,
        0xFFFF,
        0xFFFF,
        0xFFFF,
        0xFFFF,
        0xFFFF,
        0xFFFF,
        0x0000,
    },
};

u8 D_803A7B14_7B91C4[16] = {
    0x03,
    0x02,
    0x08,
    0x08,
    0x04,
    0x10,
    0x40,
    0x40,
    0x01,
    0x40,
    0x20,
    0x20,
    0x04,
    0x10,
    0x40,
    0x40,
};

s16 D_803A7B24_7B91D4[10] = {
    0x0008,
    0x0020,
    0x003C,
    0x005A,
    0x0080,
    0x00A0,
    0x00B8,
    0x00D0,
    0x00E0,
    0x00F0,
};

#endif
