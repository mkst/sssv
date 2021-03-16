#include <ultra64.h>
#include "common.h"

/*
RNC Header:

3 bytes   signature "RNC"
1 byte    version
4 bytes   unpacked data length
4 bytes   packed data length
2 bytes   CRC-16 of packed data
2 bytes   CRC-16 of unpacked data
2 bytes   overlap size (used for inplace unpacking) (unused here)

via https://wiki.multimedia.cx/index.php/RNC_ProPack
*/

typedef struct {
    /* 0x00 */ u8  signature[3];    // always 'RNC';
    /* 0x03 */ u8  version;         // 0 or 1;
    /* 0x04 */ u32 unpackedLength;
    /* 0x08 */ u32 packedLength;
    /* 0x0C */ u16 packedCRC;
    /* 0x0E */ u16 unpackedCRC;
    /* 0x10 */ u16 overlap;
} RNCHeader; // size 0x14 (due to alignment...) RNC header is only 18 bytes

typedef struct {
    /* 0x00 */ u32 l1;
    /* 0x04 */ u16 l2;
    /* 0x08 */ u32 l3;
    /* 0x0C */ u16 bit_depth;
} HuffTable; // size 0x10

extern HuffTable D_8022E0E0[16];
extern HuffTable D_8022E1E0[16];
extern HuffTable D_8022E2E0[16];

s32  unpack_data_m1(u8 *src, u8* dst);
s32  unpack_data_m2(u8 *src, u8* dst);
void func_8012B648(u8 *src, u8 *dst);
u16  input_bits_m1(u8 count);
u16  input_bits_m2(u8 count);
void make_huftable(HuffTable *src, u8 count);
u16  decode_table_data(HuffTable *data);
u16  decode_match_count(void);
u16  decode_match_offset(void);
u32  reverse_word(u8 *arg0);
u16  reverse_short(u8 *arg0);
void clear_table(HuffTable *data, u8 count);
void func_8012BC00(HuffTable *data, u8 count);
void func_8012BCEC(HuffTable *data, u8 count);
s32  func_8012BF5C(HuffTable *data, u8 count);
s32  inverse_bits(u32 value, u8 count);

u16 rnc_decompress(u8 *src, u8* dst) {
    RNCHeader *hdr = (RNCHeader*) src;
    u16 res;

    if ((hdr->signature[0] != 'R') ||
        (hdr->signature[1] != 'N') ||
        (hdr->signature[2] != 'C')) {
        return 0xFFFF; // -1
    }

    switch (hdr->version) {
        case 0:
            res = 0; // no compression
            break;
        case 1:      // all files appear to be this type
            res = unpack_data_m1(src, dst);
            break;
        case 2:      // method 2
            res = unpack_data_m2(src, dst);
            break;
        default:
            res = 0xFFFE; // -2
    }

    return res;
}

s32 unpack_data_m1(u8 *src, u8* dst) {
    u16 rs;
    u16 match_count;
    u16 data_length;
    u16 subchunks;
    u8* match_offset;
    u32 rw;

    func_8012B648(src, dst);
    input_bits_m1(2);
    while ((u32) D_8022E0DC < (u32) D_8022E0D4) {
        make_huftable(D_8022E0E0, 16); // raw_table
        make_huftable(D_8022E1E0, 16); // len_table
        make_huftable(D_8022E2E0, 16); // pos_table
        subchunks = input_bits_m1(16);
goto foo;
        // is this all skipped?!
        while (subchunks != 0) {
            match_offset = (D_8022E0DC - decode_table_data(D_8022E1E0)) - 1;
            match_count = decode_table_data(D_8022E2E0) + 2;
            while (match_count--) {
                *D_8022E0DC++ = *match_offset++;
            }
foo:
        data_length = decode_table_data(D_8022E0E0);
        while (data_length--) {
            *D_8022E0DC++ = *D_8022E3E0++;
        }

        rs = reverse_short(D_8022E3E0 + 1);
        rw = reverse_word(D_8022E3E0 + 2) << 16;
        D_8022E0D8 = (((*D_8022E3E0 + rw + (rs << 8)) << D_8022E3E4) +
                      (D_8022E0D8 & ((1 << D_8022E3E4) - 1)));
        subchunks--;
        };
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core/rnc/unpack_data_m2.s")

void func_8012B648(u8 *src, u8 *dst) {
    u32 sp2C;
    u32 sp28;
    u32 sp24;
    u32 tmp4;

    D_8022E3E0 = src + 18; // skip over header
    D_8022E0DC = dst;

    src += 4; // what we skipping here?
    sp24 = reverse_word(src);
    sp28 = reverse_word(src);
    sp2C = reverse_word(src);
    tmp4 = reverse_word(src);

    D_8022E0D4 = dst + ((((tmp4 >> 16) & 0xFF00) >> 8) + (((sp2C >> 16) & 0x00FF) << 8) +
                        ((((sp28 & 0xFFFF) << 8) + ((sp24 & 0xFF00) >> 8)) << 16));
    D_8022E3E4 = 0;
}

u16 input_bits_m1(u8 count) {
    u16 bits, prev_bits;

    bits = 0;
    prev_bits = 1;

    while (count--) {
        // if no bits to process, get more
        if (D_8022E3E4 == 0) {
            D_8022E0D8 = reverse_word(D_8022E3E0);
            D_8022E3E4 = 16; // 16 bits to process
            D_8022E3E0 += 2; // increment by 2 bytes
        }
        if (D_8022E0D8 & 1) {
            bits |= prev_bits;
        }
        prev_bits <<= 1;
        D_8022E0D8 >>= 1;
        D_8022E3E4 -= 1;
    }

    return bits;
}

u16 input_bits_m2(u8 count) {
    u16 bits = 0;

    while (count--) {
        // if no bits to process, get more
        if (D_8022E3E4 == 0) {
            D_8022E0D0 = *D_8022E3E0;
            D_8022E3E0 += 1; // increment 1 byte
            D_8022E3E4 = 8;  // 8 bits to process
        }
        bits <<= 1;
        if ((D_8022E0D0 & 0x80)) {
            bits += 1;
        }
        D_8022E0D0 <<= 1;
        D_8022E3E4 -= 1;
    }

    return bits;
}

void make_huftable(HuffTable *src, u8 count) {
    u8 leaf_nodes;
    u8 i;
    HuffTable *ht;

    clear_table(src, count);

    leaf_nodes = input_bits_m1(5);
    if (leaf_nodes != 0) {
        if (leaf_nodes > 16) {
            leaf_nodes = 16;
        }
        ht = src;
        for (i = 0; i < leaf_nodes; i++) {
            ht->bit_depth = input_bits_m1(4);
            ht++;
        }
        func_8012BC00(src, leaf_nodes);
    }
}

u16 decode_table_data(HuffTable *data) {
    u8 i;
    u16 bit_depth;
    HuffTable *h;

    i = 0;
    h = data;
    while (((*h).bit_depth == 0) || ((*h).l3 != (D_8022E0D8 & ((1 << (*h).bit_depth) - 1)))) {
        h++;
        i += 1;
    }

    input_bits_m1(h->bit_depth);
    if (i < 2) {
        return i;
    }

    return input_bits_m1(i - 1) | (1 << (i - 1));
}

u16 decode_match_count(void) {
    u16 res = input_bits_m2(1) + 4;
    if (input_bits_m2(1) == 0) {
        return res;
    } else {
        return input_bits_m2(1) + ((res - 1) << 1);
    }
}

u16 decode_match_offset(void) {
    u16 match_offset;
    u8 *temp_v1;

    match_offset = 0;
    if (input_bits_m2(1)) {
        match_offset = input_bits_m2(1);
        if (input_bits_m2(1)) {
            match_offset = (input_bits_m2(1) + (match_offset * 2)) | 4;
            if (input_bits_m2(1) == 0) {
                match_offset = input_bits_m2(1) + (match_offset * 2);
            }
        } else {
            if (match_offset == 0) {
                match_offset = (input_bits_m2(1) + 2);
            }
        }
    }
    return *D_8022E3E0++ + (match_offset << 8) + 1;
}

// turns "abcd" => "dcba"
u32 reverse_word(u8 *arg0) {
    return arg0[0] | (arg0[1] << 8) | (arg0[2] << 16) | (arg0[3] << 24);
}

u16 reverse_short(u8 *arg0) {
    return arg0[0] | (arg0[1] << 8);
}

void clear_table(HuffTable *data, u8 count) {
    while (count--) {
        data->l1 = 0;
        data->l2 = 0xFFFF;
        data->l3 = 0;
        data->bit_depth = 0;
        data++;
    }
}

// proc_20
void func_8012BC00(HuffTable *data, u8 count) {
    HuffTable * ht;
    u16 bits_count;
    u16 i;
    u32 div;
    u32 val;

    bits_count = 1;
    val = 0;
    div = 0x80000000;

    while (bits_count <= 16) {
        ht = data;
        for (i = 0; i < count; i++) {
            if (ht->bit_depth == bits_count) {
                ht->l3 = inverse_bits(val / div, bits_count);
                val += div;
            }
            ht++; // next table
        }
        bits_count++;
        div >>= 1;
    }
}

// proc_16
void func_8012BCEC(HuffTable *data, u8 count) {
    u16 i;
    u16 used;
    u16 max;
    u32 tmp[16];


    for (i = 0; i < 16; i++) {
        tmp[i] = data[i].l1;
    }

    used = 0;

    for (i = 0; i < count; i++) {
        if (data[i].l1 != 0) {
            used += 1;
            max = i;
        }
    }
    if (used != 0) {
        if (used == 1) {
            data[max].bit_depth += 1;
            return;
        }
        while (func_8012BF5C(data, count)) {
            data[D_8022E3E6].l1 += data[D_8022E3E8].l1;
            data[D_8022E3E8].l1 = 0;
            data[D_8022E3E6].bit_depth += 1;

            while (data[D_8022E3E6].l2 != 0xFFFF) {
                D_8022E3E6 = data[D_8022E3E6].l2;
                data[D_8022E3E6].bit_depth += 1;
            }

            data[D_8022E3E6].l2 = D_8022E3E8;
            data[D_8022E3E8].bit_depth += 1;

            while (data[D_8022E3E8].l2 != 0xFFFF) {
                D_8022E3E8 = data[D_8022E3E8].l2;
                data[D_8022E3E8].bit_depth += 1;
            }
        }
        for (i = 0; i < 16; i++) {
            data[i].l1 = tmp[i];
        }
        func_8012BC00(data, count);
    }
}

//proc_17
s32 func_8012BF5C(HuffTable *data, u8 count) {
    u8 i;
    u32 l1;
    u32 phi_v0;
    u32 phi_v1;

    phi_v0 = 0xFFFFFFFF;
    phi_v1 = 0xFFFFFFFF;

    for (i = 0; i < count; i++){
        l1 = data[i].l1;
        if (l1 != 0) {
            if (l1 < phi_v0) {
                phi_v1 = phi_v0;
                D_8022E3E8 = D_8022E3E6;
                phi_v0 = l1;
                D_8022E3E6 = i;
            } else if (l1 < phi_v1) {
                phi_v1 = l1;
                D_8022E3E8 = i;
            }
        }
    }

    if ((phi_v0 == -1) || (phi_v1 == -1)) {
        return 0;
    } else {
        return 1;
    }
}

s32 inverse_bits(u32 value, u8 count) {
    s32 bits = 0;

    while (count--) {
        bits <<= 1;
        if (value & 1) {
            bits |= 1;
        }
        value >>= 1;
    }
    return bits;
}
