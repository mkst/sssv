#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
    uint32_t frequency;
    uint16_t entry_ptr;
    uint32_t code;
    uint16_t code_len;
} Huffman;

typedef struct {
    uint8_t *input;
    uint8_t *output;
    uint32_t bit_buff;
    uint32_t bit_buff_bits;
    uint32_t input_ptr;
    uint32_t output_ptr;
    Huffman  raw_huffman_table[16];
    Huffman  pos_huffman_table[16];
    Huffman  len_huffman_table[16];
} RncUnpackerMethod1;

uint32_t read_word_be(uint8_t *src, uint32_t offset) {
    return (src[offset + 0] << 24) | (src[offset + 1] << 16) | (src[offset + 2] << 8) | src[offset + 3] << 0;
}

uint32_t read_word_le(uint8_t *src, uint32_t offset) {
    return (src[offset + 3] << 24) | (src[offset + 2] << 16) | (src[offset + 1] << 8) | src[offset + 0] << 0;
}

uint32_t input_bits(RncUnpackerMethod1 *rum, uint32_t n) {
    if (rum->bit_buff_bits < n) {
        uint32_t new_bits = read_word_le(rum->input, rum->input_ptr);
        rum->bit_buff = (new_bits << rum->bit_buff_bits) | (rum->bit_buff & (1 << rum->bit_buff_bits) - 1);
        rum->input_ptr += 2;
        rum->bit_buff_bits += 16;
    }

    uint32_t bits = rum->bit_buff & (1 << n) - 1;
    rum->bit_buff >>= n;
    rum->bit_buff_bits -= n;

    return bits;
}

uint32_t swap_bits(uint32_t in_bits, uint8_t n) {
    uint32_t out_bits = 0;
    for (uint8_t i = 0; i < n; i++) {
        out_bits <<= 1;
        if (in_bits & 1) {
            out_bits |= 1;
        }
        in_bits >>= 1;
    }
    return out_bits;
}

void init_huffman_table(Huffman *table) {
    for (uint8_t i = 0; i < 16; i++) {
        table[i].frequency = 0;
        table[i].entry_ptr = -1;
        table[i].code = 0;
        table[i].code_len = 0;
    }
}

void make_huffman_codes(Huffman *table, uint8_t n) {
    uint32_t huff_bits = 1;
    uint32_t huff_code = 0;
    uint32_t huff_base = 0x80000000;

    while (huff_bits <= 16) {
        for (uint8_t i = 0; i < n; i++) {
            if (table[i].code_len == huff_bits) {
                table[i].code = swap_bits(huff_code / huff_base, huff_bits);
                huff_code += huff_base;
            }
        }
        huff_bits++;
        huff_base >>= 1;
    }
}

void input_huffman_table(RncUnpackerMethod1 *rum, Huffman *table) {
    init_huffman_table(table);
    uint32_t n = input_bits(rum, 5);
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (uint8_t i = 0; i < n; i++) {
            table[i].code_len = input_bits(rum, 4);
        }
        make_huffman_codes(table, n);
    }
}

uint32_t input_value(RncUnpackerMethod1 *rum, Huffman *table) {
    uint32_t i = 0;

    for (; i < 16; i++) {
        if ((table[i].code_len != 0) && (table[i].code == (rum->bit_buff & (1 << table[i].code_len) - 1))) {
            break;
        }
    }

    input_bits(rum, table[i].code_len);

    if (i < 2) {
        return i;
    }

    return input_bits(rum, i - 1) | (1 << i - 1);
}

// expects RNC payload without header
int unpack(uint8_t *input, uint8_t *output, uint32_t output_len) {
    RncUnpackerMethod1 *rum = (RncUnpackerMethod1 *) calloc(1, sizeof(RncUnpackerMethod1));
    rum->input = input;
    rum->output = output;

    input_bits(rum, 2); // ignore lock and key bits

    while (rum->output_ptr < output_len) {
        input_huffman_table(rum, rum->raw_huffman_table);
        input_huffman_table(rum, rum->pos_huffman_table);
        input_huffman_table(rum, rum->len_huffman_table);

        uint32_t count = input_bits(rum, 16);

        for (uint32_t i = 0; i < count; i++) {
            if (i > 0) {
                uint32_t ptr = input_value(rum, rum->pos_huffman_table) + 1;
                uint32_t length = input_value(rum, rum->len_huffman_table) + 2;
                for (uint32_t j = 0; j < length; j++) {
                    rum->output[rum->output_ptr] = rum->output[rum->output_ptr - ptr];
                    rum->output_ptr++;
                }
            }
            uint32_t length = input_value(rum, rum->raw_huffman_table);
            for (uint32_t j = 0; j < length; j++) {
                rum->output[rum->output_ptr++] = rum->input[rum->input_ptr++];
            }

            uint32_t new_bits = read_word_le(input, rum->input_ptr);
            rum->bit_buff = (new_bits << rum->bit_buff_bits) | (rum->bit_buff & (1 << rum->bit_buff_bits) - 1);
        }
    }
    free(rum);
}

// gcc tools/rncu.c -o tools/rncu.so --shared -O3 -fPIC
