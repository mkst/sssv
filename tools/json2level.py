import json
import sys
import struct

LEVEL_NAME = "levels/SMASHING_START"

SECTION_ORDER = [12, 11, 9, 4, 0, 1, 2, 5, 7, 6, 10, 13, 14, 15, 3]

payload_types = {
    0: "objects",
    1: "animals",
    6: "waypoints",
    7: "dynamic_objects",
    12: "game_state",
}

def pack_list_data(format, values):
    packed = b''
    packed += len(values).to_bytes(2, byteorder="big")
    for entry in values:
        packed += struct.pack(">" + format, *entry.values())
    return packed

def pack_datatype_0(values):
    datatype_0_format = "hhhhhhhhhhh"
    return pack_list_data(datatype_0_format, values)

def pack_datatype_1(values):
    datatype_1_format = "hhhhhhhh"
    return pack_list_data(datatype_1_format, values)

def pack_datatype_2(values):
    datatype_2_format = "hhbb"
    return pack_list_data(datatype_2_format, values)

def pack_datatype_6(values):
    packed = b''
    packed += len(values).to_bytes(2, byteorder="big")
    for entries in values:
        packed += len(entries).to_bytes(1, byteorder="big")
        for entry in entries:
            packed += struct.pack(">3B", *entry)
    # force 2-byte alignment
    if len(packed) % 2 != 0:
        packed += b'\x00'
    return packed

def pack_datatype_7(values):
    datatype_7_format = "hhhhhhhhhhhhbb"
    return pack_list_data(datatype_7_format, values)

def pack_datatype_12(values):
    datatype_12_format = (
        "hhhhhhhh" +            # 0x00
        "hhhhhhhh" +            # 0x10
        "hhhhhhhh" +            # 0x20
        "hhhhhhhh" +            # 0x30
        "hhhhhhhh" +            # 0x40
        "hhhhhhbbbb" +          # 0x50
        "bbbbbbbbbbbbbbbb" +    # 0x60
        "bbbbbbhhhhh" +         # 0x70
        "hhhhhhhh" +            # 0x80
        "hhhhhhhh")             # 0x90
    packed = struct.pack(">" + datatype_12_format, *values.values())
    return packed


def pack_data(section):
    packed = None

    key = payload_types.get(section, str(section))
    values = data[key]
    if section == 0:
        packed = pack_datatype_0(values)
    elif section == 1:
        packed = pack_datatype_1(values)
    elif section == 2:
        packed = pack_datatype_2(values)
    elif section == 6:
        packed = pack_datatype_6(values)
    elif section == 12:
        packed = pack_datatype_12(values)

    if packed is not None:
        with open(f"{LEVEL_NAME}_{section}.bin", "wb") as o:
            o.write(packed)

with open(sys.argv[1], "r") as f:
    data = json.load(f)

for section in SECTION_ORDER:
    pack_data(section)
