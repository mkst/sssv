import json
import os
import struct
import sys
from pathlib import Path

# LEVEL_NAME = "levels/SMASHING_START"

# super work-in-progress

RNC_HEADER_LENGTH = 18

payload_types = {
    0: "objects",
    1: "animals",
    6: "waypoints",
    7: "dynamic_objects",
    12: "game_state",
}

#
default_script_struct = "hhhhh"
script_structs = {
    12: "hhbbbbh",
    16: "hhbbbbbb",

}


def unpack_datatype_0(data):
    # H             # number of entries
    # HHHHHHHHHH    # each entry
    # ...           # etc

    res = []
    entries, = struct.unpack(">h", data[0:2])
    datatype_10_format = "hhhhhhhhhhh"
    for i, s in enumerate(struct.iter_unpack(">" + datatype_10_format, data[2:])):
        id, x, z, y, unk8, angle, unkC, scale, unk10, unk12, unk14 = s
        entry = {
            "id": id,
            "x": x,
            "z": z,
            "y": y,
            "unk8": unk8,
            "angle": angle,
            "unkC": unkC,
            "scale": scale,
            "unk10": unk10,
            "unk12": unk12,
            "unk14": unk14,
        }
        res.append(entry)
    return res


def unpack_datatype_1(data):
    # H             # number of entries
    # HHHHHHHH      # each entry
    # ...           # etc

    res = []
    entries, = struct.unpack(">h", data[0:2])
    for i, s in enumerate(struct.iter_unpack(">hhhhhhhh", data[2:])):
        id, x, z, y, rotation, health, unkC, unkE = s
        entry = {
            "id": id,
            "x": x,
            "z": z,
            "y": y,
            "rotation": rotation,
            "health": health,
            "unkC": unkC,
            "unkE": unkE,
            }
        res.append(entry)
    return res


def unpack_datatype_2(data):
    # H                    # number of entries
    # HHBB                 # entry
    res = []
    entries, = struct.unpack(">h", data[0:2])
    datatype_2_format = "hhbb"
    for i, s in enumerate(struct.iter_unpack(">" + datatype_2_format, data[2:])):
        unk0, unk2, unk4, unk5 = s
        entry = {
            "unk0": unk0,
            "unk2": unk2,
            "unk4": unk4,
            "unk5": unk5,
        }
        res.append(entry)
    return res


def unpack_datatype_6(data):
    # H                    # number of entries
    # B BBB BBB BBB...     # length of entry, waypoints...
    # B BBB BBB ...
    # B BBB BBB BBB BBB...

    res = []
    entries, = struct.unpack(">h", data[0:2])

    ptr = 2 # skip over number of entries
    for i in range(entries):
        num_entries = data[ptr]
        waypoints = []
        ptr += 1
        for i in range(num_entries):
            # x, y, z
            s = struct.unpack(">3B", data[ptr:ptr+3])
            waypoints.append(s)
            ptr += 3
        res.append(waypoints)

    return res


def unpack_datatype_7(data):
    # H                    # number of entries
    # HHHHHHHHHHHHBB       # entry (26 bytes)
    res = []
    entries, = struct.unpack(">h", data[0:2])
    datatype_7_format = "hhhhhhhhhhhhbb"
    for i, s in enumerate(struct.iter_unpack(">" + datatype_7_format, data[2:])):
        id, x, z, y, unk8, unkA, unkC, unkE, unk10, unk12, unk14, unk16, unk18, unk19 = s
        entry = {
            "id": id,
            "x": x,
            "z": z,
            "y": y,
            "unk8": unk8,
            "unkA": unkA,
            "unkC": unkC,
            "unkE": unkE,     # start object?
            "unk10": unk10,
            "unk12": unk12,
            "unk14": unk14,
            "unk16": unk16,   # end object?
            "unk18": unk18,
            "unk19": unk19,
        }
        res.append(entry)
    return res

def unpack_datatype_10(data):
    res = []
    length = struct.unpack(">i", data[0:4])
    print("length?", length)

    ptr = 4
    while ptr < len(data):
        # if ptr >= len(data):
            # break
        # read flags
        flags = struct.unpack(">bbbb", data[ptr:ptr+4])
        ptr += 4

        count = 3 if flags[0] & 1 else 4
        # print("numVtxs", count)
        if (flags[0] & 0x20) or (flags[0] & 0x10) or (flags[0] & 0x200) or (flags[0] & 0x8000):
            for i in range(count):
                t0, t1, r, g, b, x, y, z, a = struct.unpack(">hhbbbbhbb", data[ptr:ptr+0xC])
                x = (x << 6) + 0x100
                y = y << 3
                z = (z << 6) + 0x200
                res.append([x, y, z, t0, t1, r, g, b, a])
                print([x, y, z, t0, t1, r, g, b, a])
                ptr += 0xC
        else:
            ptr += 0x30

    return res


def unpack_datatype_11(data):
    datatype_11_format = "bbbbbbbbbbbb" # 0xC big
    res = []
    for entry in struct.iter_unpack(">" + datatype_11_format, data):
        res.append(entry)
    return res

def unpack_datatype_12(data):
    datatype_12_format = (
        "hhhhhhhh" +
        "hhhhhhhh" +
        "hhhhhhhh" +
        "hhhhhhhh" +
        "hhhhhhhh" +
        "hhhhhhbbbb" +
        "bbbbbbbbbbbbbbbb" +
        "bbbbbbhhhhh" +
        "hhhhhhhh" +
        "hhhhhhhh")
    x = struct.unpack(">" + datatype_12_format, data)

    names = [
        "unk0",         # 0x00
        "unk2",
        "unk4",
        "unk6",
        "unk8",
        "unkA",
        "unkC",
        "unkE",
        "unk10",        # 0x10
        "unk12",
        "unk14",
        "unk16",
        "unk18",
        "animalId",
        "unk1C",
        "unk1E",
        "biome",        # 0x20
        "unk22",
        "unk24",
        "unk26",
        "unk28",
        "unk2A",
        "unk2C",
        "unk2E",
        "unk30",        # 0x30
        "unk32",
        "unk34",
        "unk36",
        "unk38",
        "unk3A",
        "unk3C",
        "unk3E",
        "unk40",        # 0x40
        "unk42",
        "unk44",
        "unk46",
        "unk48",
        "unk4A",
        "unk4C",
        "unk4E", # rotation?
        "unk50",        # 0x50
        "unk52",
        "unk54",
        "unk56",
        "unk58",
        "unk5A",
        "unk5C",
        "unk5D",
        "unk5E",
        "unk5F",
        "unk60",        # 0x60
        "unk61",
        "unk62",
        "unk63",
        "unk64",
        "unk65",
        "unk66",
        "unk67",
        "unk68",
        "unk69",
        "unk6A",
        "unk6B",
        "unk6C",
        "unk6D",
        "unk6E",
        "unk6F",
        "unk70",        # 0x70
        "unk71",
        "unk72",
        "unk73",
        "unk74",
        "unk75",
        "unk76",
        "unk78",
        "unk7A",
        "unk7C",
        "unk7E",
        "unk80",        # 0x80
        "unk82",
        "unk84",
        "unk86",
        "unk88",
        "unk8A",
        "unk8C",
        "unk8E",
        "unk90",
        "unk92",
        "unk94",
        "unk96",
        "unk98",
        "unk9A",
        "unk9C",
        "unk9E",
    ]

    assert len(x) == len(names)

    entry = dict(zip(names, x))
    return entry

def unpack_data(datatype, data):
    res = []

    with open(f"{LEVEL_NAME}_{datatype}.bin", "wb") as o:
        o.write(data)

    if datatype == 0:
        print("[0]  - Objects, e.g. level01.cob")
        res = unpack_datatype_0(data)
    elif datatype == 1:
        print("[1]  - Animals, e.g. level01.can")
        res = unpack_datatype_1(data)
    elif datatype == 2:
        # 6 bytes per entry, link objects together?
        print("[2]  - Unknown, e.g. level01.joi")
        res = unpack_datatype_2(data)
    elif datatype == 4:
        print("[4]  - Unknown, e.g. level01.cmd")
        length, = struct.unpack(">h", data[0:2])
        for i, x in enumerate(struct.iter_unpack(">hhhhh", data[2:])):
            res.append(x)
    elif datatype == 5:
        print("[5]  - Unknown, e.g. level01.rng")
        length, = struct.unpack(">h", data[0:2])
        # 8 bytes per entry?
        # print(length, "entries")
        # print(len(data[2:]))
        # e.g. 64 bytes
        # copied into D_803E93B0
        for i, x in enumerate(struct.iter_unpack(">bbbbbbbb", data[2:])):
            res.append(x)
            # print("\t", i, x)
    elif datatype == 6:
        print("[6]  - Waypoints (Path Thingies), e.g. level01.paf")
        res = unpack_datatype_6(data)
    elif datatype == 7:
        print("[7]  - Dynamic objects? e.g. ropes?")
        res = unpack_datatype_7(data)
    elif datatype == 9:
        print("[9]  - Unknown, e.g. level01.map")
        # print("data length: ", len(data))
        # size 50440 bytes
        for i, s in enumerate(struct.iter_unpack(">BBBBBBBB", data)):
            res.append(s)
    elif datatype == 10:
        print("[10] - Unknown, vtx data?", len(data), (len(data) - 4)/0x34)
        # print("data length: ", len(data))
        # with open("datatype10", "wb") as o:
            # o.write(data)
        # size 0x34
        # print((len(data) - 4) / 0x34) # ?
        # res = unpack_datatype_10(data)
        pass
    elif datatype == 11:
        print("[11] - Unknown, e.g. level01.mat")
        # 3072 bytes
        # straight copy into D_803E1D30, what is this?
        res = unpack_datatype_11(data)
    elif datatype == 12:
        print("[12] - Game state (struct000), e.g. level01.dat")
        res = unpack_datatype_12(data)
    elif datatype == 13:
        print("[13] - Unknown (2 payloads), e.g. level01.cam")
        p1 = []
        p2 = []
        # two payloads
        length, = struct.unpack(">h", data[0:2])
        payload1_length = length * 0x8
        # D_803A6D14_7B83C4
        payload1 = data[2:2+payload1_length]
        for i, x in enumerate(struct.iter_unpack(">hhhh", payload1)):
            p1.append(x)
        res.append(p1)
        # D_803A7114_7B87C4
        payload2 = data[2+payload1_length:]
        # print("[payload 2]")
        for i, x in enumerate(struct.iter_unpack(">HHHHHHHHHH", payload2)):
            p2.append(x)
            # print("\t", i, x)
        res.append(p2)
    elif datatype == 14:
        print("[14] - Unknown (D_803E2930)")
        # 2048 bytes
        for i, x in enumerate(struct.iter_unpack(">IIII", data)):
            res.append(x)
    elif datatype == 15:
        # always [0, 0, 245, 0, 0, 0, 10, 0]
        # unused?
        print("[15] - Unknown (D_803B1D20_7C33D0)")
        length, = struct.unpack(">h", data[0:2])
        # copy into D_803B1D20_7C33D0
        for i, x in enumerate(struct.iter_unpack(">BBBBBBBB", data[2:])):
            res.append(x)
    else:
        raise Exception("Unsupported datatype")

    return res

def main(infile, outfile):
    with open(infile, "rb") as f:
        data = f.read()

    infile_path = Path(outfile)
    global LEVEL_NAME
    LEVEL_NAME = Path("/".join(infile_path.parts[:-1])) / Path(infile_path.name).stem

    KEY_ORDER = [12, 11, 9, 4, 0, 1, 2, 5, 7, 6, 10, 13, 14, 15, 3]

    res = {}
    ptr = 0
    while ptr < len(data):
        payload_type = data[ptr]

        if payload_type not in KEY_ORDER:
            raise Exception(f"Unsupported payload_type: {payload_type}")
            break

        if payload_type == 3:
            # leftover buffer junk?
            res[3] = data[ptr+1]
            with open(f"{LEVEL_NAME}_{payload_type}.bin", "wb") as o:
                o.write(data[ptr+1:])
            break

        ptr += 1

        # read RNC header
        if data[ptr:ptr+3] == b'RNC':
            rnc_start = ptr

            ptr += 3
            # read Method
            rnc_type = data[ptr]
            if rnc_type not in (1, 2):
                raise Exception(f"Unexpected RNC method : {rnc_type}")
            ptr += 1

            # read UncompressedSize
            uncompressed_size, = struct.unpack(">i", data[ptr:ptr+4])
            ptr += 4
            # read CompressedSize
            compressed_size, = struct.unpack(">i", data[ptr:ptr+4])
            ptr += 4
            # ignore rest of header
            ptr += 6

            # is there any alignment to worry about?
            compressed_length = compressed_size + RNC_HEADER_LENGTH

            rnc_payload = data[rnc_start:rnc_start+compressed_length]

            tmpfile = f"/tmp/rnc_{rnc_start:08X}_{payload_type:02}"

            with open(f"{tmpfile}.RNC", "wb") as o:
                o.write(rnc_payload)
            # uncompress via rnc64?
            cmd = f"./tools/rnc_propack_source/rnc64 u {tmpfile}.RNC tmp.BIN >/dev/null"
            os.system(cmd)
            # read in
            with open(f"tmp.BIN", "rb") as f:
                uncompressed = f.read()
            os.system("rm -f tmp.BIN")
            os.system(f"rm {tmpfile}.RNC")

            segment = unpack_data(payload_type, uncompressed)

            if segment is not None:
                key = payload_types.get(payload_type, str(payload_type))
                res[key] = segment

            ptr += compressed_size
        else:
            raise Exception("Payload was not RNC chunk!")

    # print(f"writing to {outfile}")
    with open(outfile, "w") as o:
        json.dump(res, o, indent=4)

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
