import sys

from pathlib import Path
from ctypes import (
    Structure,
    byref,
    c_int,
    c_uint8,
    c_uint32,
    c_uint16,
    cdll,
)


class Huffman(Structure):
    _fields_ = [
        ("frequency", c_uint32),
        ("entry_ptr", c_uint16),
        ("code", c_uint32),
        ("code_len", c_uint16),
    ]


def init_huffman_table(table):
    table.clear()
    for _ in range(16):
        table.append(
            Huffman(
                0,  # frequency
                -1,  # entry_ptr
                0,  # code
                0,  # code_len
            )
        )


def make_huffman_codes(table, n):
    huff_bits = 1
    huff_code = 0
    huff_base = 0x80000000

    while huff_bits <= 16:
        for i in range(n):
            if table[i].code_len == huff_bits:
                table[i].code = swap_bits(int(huff_code / huff_base), huff_bits)
                huff_code += huff_base  # won't overflow 32bit int
        huff_bits += 1
        huff_base >>= 1


def swap_bits(in_bits, n):
    out_bits = 0
    for _ in range(n):
        out_bits <<= 1
        if in_bits & 1:
            out_bits |= 1
        in_bits >>= 1
    return out_bits


class RncUnpackerMethod1:
    bit_buff: c_int
    bit_buff_bits: c_int

    input_ptr: int
    output_ptr: int

    raw_huffman_table = []
    pos_huffman_table = []
    len_huffman_table = []

    def __init__(self, data):
        if len(data) < 18:
            raise Exception("File is too small to be an RNC file")
        if data[:3] != b"RNC":
            raise Exception("Header mismatch")
        if data[3] != 1:
            raise Exception("Only RNC Type 1 is currently supported")

        self.uncompressed_size = int.from_bytes(data[4:8], byteorder="big")
        self.input = data[18:]
        self.output = bytearray(self.uncompressed_size)

        try:
            self.librncu = cdll.LoadLibrary(Path(__file__).parent / "librncu.so")
        except Exception as err:
            print("Could not load librncu.so (%s), falling back to Python!" % err)
            self.librncu = None

    def init_unpack(self):
        self.bit_buff = 0
        self.bit_buff_bits = 0

        self.input_ptr = 0
        self.output_ptr = 0

        self.output = bytearray(self.uncompressed_size)

        self.raw_huffman_table.clear()
        self.pos_huffman_table.clear()
        self.len_huffman_table.clear()

    def input_bits(self, n: c_int, discard: bool = False) -> c_int:
        """Read 'n' bytes from bit buffer, pulling from input bytes as required"""
        if self.bit_buff_bits < n:
            new_bits = int.from_bytes(
                self.input[self.input_ptr : self.input_ptr + 4],
                byteorder="little",
            )
            self.bit_buff = (
                (new_bits << self.bit_buff_bits)
                | (self.bit_buff & (1 << self.bit_buff_bits) - 1)
            ) & 0xFFFFFFFF

            self.input_ptr += 2
            self.bit_buff_bits += 16

        bits = 0 if discard else self.bit_buff & ((1 << n) - 1)
        self.bit_buff >>= n
        self.bit_buff_bits -= n

        return bits

    def input_value(self, table) -> c_int:
        for i, t in enumerate(table):
            if t.code_len != 0 and (t.code == (self.bit_buff & (1 << t.code_len) - 1)):
                break

        self.input_bits(t.code_len, discard=True)
        if i < 2:
            return i

        return self.input_bits(i - 1) | (1 << i - 1)

    def input_huffman_table(self, table):
        init_huffman_table(table)

        n = min(self.input_bits(5), 16)
        if n != 0:
            for i in range(n):
                table[i].code_len = self.input_bits(4)
            make_huffman_codes(table, n)

    def unpack_python(self):
        self.init_unpack()

        self.input_bits(2, discard=True)  # ignore lock and key bits

        while self.output_ptr < self.uncompressed_size:
            self.input_huffman_table(self.raw_huffman_table)
            self.input_huffman_table(self.pos_huffman_table)
            self.input_huffman_table(self.len_huffman_table)

            for i in range(self.input_bits(16)):
                if i > 0:
                    ptr = self.input_value(self.pos_huffman_table) + 1
                    length = self.input_value(self.len_huffman_table) + 2
                    for _ in range(length):
                        self.output[self.output_ptr] = self.output[
                            self.output_ptr - ptr
                        ]
                        self.output_ptr += 1

                length = self.input_value(self.raw_huffman_table)
                self.output[self.output_ptr : self.output_ptr + length] = self.input[
                    self.input_ptr : self.input_ptr + length
                ]
                self.input_ptr += length
                self.output_ptr += length

                new_bits = int.from_bytes(
                    self.input[self.input_ptr : self.input_ptr + 3],
                    byteorder="little",
                )
                self.bit_buff = (
                    (new_bits << self.bit_buff_bits)
                    | (self.bit_buff & (1 << self.bit_buff_bits) - 1)
                ) & 0xFFFFFFFF

    def unpack_c(self):
        packed = (c_uint8 * len(self.input)).from_buffer_copy(self.input, 0)
        unpacked = (c_uint8 * self.uncompressed_size)()
        self.librncu.unpack(byref(packed), byref(unpacked), self.uncompressed_size)
        self.output = bytearray(unpacked)

    def unpack(self):
        if self.librncu:
            self.unpack_c()
        else:
            self.unpack_python()
        return self.output


def main():
    if len(sys.argv) < 3:
        print("Usage: %s <infile.rnc> <outfile.bin>" % sys.argv[0])
        sys.exit(1)

    infile: str = sys.argv[1]
    outfile: str = sys.argv[2]

    with open(infile, "rb") as f:
        packed = f.read()

    rnc_unpacker = RncUnpackerMethod1(packed)
    unpacked = rnc_unpacker.unpack()

    with open(outfile, "wb") as f:
        f.write(unpacked)


if __name__ == "__main__":
    main()
