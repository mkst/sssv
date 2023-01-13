import logging
import struct

from .datatypes import *


logger = logging.getLogger(__file__)


def payload_filepath(filepath, payload_type):
    return filepath.with_suffix(f".{payload_type:02}.bin")


def unpack_data_single(data, data_format):
    datatype_entry = data_format.keys()
    datatype_format = "".join(data_format.values())
    entry = struct.unpack(">" + datatype_format, data)
    return dict(zip(datatype_entry, entry))


def unpack_data_without_length(data, data_format):
    datatype_entry = data_format.keys()
    datatype_format = "".join(data_format.values())

    res = []
    for entry in struct.iter_unpack(">" + datatype_format, data):
        res.append(dict(zip(datatype_entry, entry)))
    return res


def unpack_data_with_length(data, data_format):
    datatype_entry = data_format.keys()
    datatype_format = "".join(data_format.values())

    res = []

    if len(data) < 2:
        logger.error("Data is too small!")
        return None

    count, = struct.unpack(">h", data[0:2])
    logger.debug("[ -> ] %i entry(s) to unpack", count)

    for entry in struct.iter_unpack(">" + datatype_format, data[2:]):
        res.append(dict(zip(datatype_entry, entry)))

    if (len(res) != count) and (len(res) != count // 10):
        logger.warning("Expected count differed from actual count!")

    return res


def unpack_datatype_4_helper(data):
    res = []

    default_data_format = datatype_4_format # "Hhhhhh"

    byte_count, = struct.unpack(">h", data[0:2])
    logger.info("[.cmd] Commands: %i byte_count", byte_count)

    ptr = 2
    while ptr < byte_count:
        entry = data[ptr:ptr+10]
        data_type, = struct.unpack(">H", entry[0:2])

        if data_type == 24:
            data_format = datatype_4_format_type_24
        else:
            data_format = default_data_format

        res.append(dict(zip(data_format.keys(), struct.unpack(">" + "".join(data_format.values()), entry))))

        ptr += 10


    return res


def unpack_datatype_0(data):
    """.cob - objects
    H             # number of entries
    HHHHHHHHHH    # each entry
    ...           # etc
    """
    logger.info("[.cob] Objects: %i bytes", len(data))
    return unpack_data_with_length(data, datatype_0_format)


def unpack_datatype_1(data):
    """.can - animals
    H             # number of entries
    HHHHHHHH      # each entry
    ...           # etc
    """
    logger.info("[.can] Animals: %i bytes", len(data))
    return unpack_data_with_length(data, datatype_1_format)


def unpack_datatype_2(data):
    """.joi - linking objects
    H             # number of entries
    HHBB          # entry
    """
    logger.info("[.joi] Linking Objects: %i bytes", len(data))
    return unpack_data_with_length(data, datatype_2_format)


def unpack_datatype_4(data):
    """.cmd
    H             # size of whole section
    """
    logger.info("[.cmd] Unknown: %i bytes", len(data))
    # return unpack_datatype_4_helper(data)
    pass


def unpack_datatype_5(data):
    """.rng"""
    logger.info("[.rng] Unknown: %i bytes", len(data))
    return unpack_data_with_length(data, datatype_5_format)


def unpack_datatype_6(data):
    """.paf - waypoints
    H                    # number of entries
    B BBB BBB BBB...     # length of entry, waypoints...
    B BBB BBB ...
    B BBB BBB BBB BBB...
    """
    logger.info("[.paf] Waypoints: %i bytes", len(data))

    res = []
    entries, = struct.unpack(">h", data[0:2])
    logger.debug("[ -> ] %i entry(s) to unpack", entries)

    ptr = 2 # skip over number of entries
    for i in range(entries):
        num_entries = data[ptr]
        waypoints = []
        ptr += 1
        for _ in range(num_entries):
            # x, y, z
            s = struct.unpack(">3B", data[ptr:ptr+3])
            waypoints.append(s)
            ptr += 3
        res.append(waypoints)

    return res


def unpack_datatype_7(data):
    """.cha - dynamic_objects
    # H                    # number of entries
    # HHHHHHHHHHHHBB       # entry (26 bytes)
    """
    logger.info("[.cha] Hanging Objects: %i bytes", len(data))
    return unpack_data_with_length(data, datatype_7_format)


def unpack_datatype_9(data):
    logger.info("[.map] Collision: %i bytes", len(data))
    return unpack_data_without_length(data, datatype_9_format)


def unpack_datatype_10(data):
    raise NotImplementedError("No handler for Datatype 10")


def unpack_datatype_11(data):
    """.mat - material lut?"""
    logger.info("[.mat] Material LUT: %i bytes", len(data))
    # always 3072 bytes?
    return unpack_data_without_length(data, datatype_11_format)


def unpack_datatype_12(data):
    """.dat - game_state"""
    logger.info("[.dat] Game State: %i bytes", len(data))
    return unpack_data_single(data, datatype_12_format)


def unpack_datatype_13(data):
    """.cam"""
    logger.info("[.cam] Type 13: %i bytes", len(data))
    # two payloads
    length, = struct.unpack(">h", data[0:2])
    payload1_length = length * 0x8
    # D_803A6D14_7B83C4
    payload1 = unpack_data_with_length(data[:2+payload1_length], datatype_13_format_a)
    # D_803A7114_7B87C4
    payload2 = unpack_data_without_length(data[2+payload1_length:], datatype_13_format_b)

    res = [
        payload1,
        payload2,
    ]
    return res


def unpack_datatype_14(data):
    """unknown"""
    logger.info("[.???] Type 14: %i bytes", len(data))
    return unpack_data_without_length(data, datatype_14_format)


def unpack_datatype_15(data):
    """tbd"""
    logger.info("[.???] Type 15: %i bytes", len(data))
    # D_803B1D20_7C33D0
    return unpack_data_with_length(data, datatype_15_format)


def unpack_data(filepath, datatype, data):
    res = []
    # write raw .bin
    with open(payload_filepath(filepath, datatype), "wb") as o:
        o.write(data)
    # dump out to json
    if datatype == 0:
        res = unpack_datatype_0(data)
    elif datatype == 1:
        res = unpack_datatype_1(data)
    elif datatype == 2:
        res = unpack_datatype_2(data)
    elif datatype == 3:
        # end of data sentinel
        pass
    elif datatype == 4:
        res = unpack_datatype_4(data)
        # to be implemented
    elif datatype == 5:
        res = unpack_datatype_5(data)
    elif datatype == 6:
        res = unpack_datatype_6(data)
    elif datatype == 7:
        res = unpack_datatype_7(data)
    # elif datatype == 8:
        # pass
    elif datatype == 9:
        # 65*97*8 => 50440 bytes
        res = unpack_datatype_9(data)
        pass
    elif datatype == 10:
        # level geo
        return None
    elif datatype == 11:
        res = unpack_datatype_11(data)
    elif datatype == 12:
        res = unpack_datatype_12(data)
    elif datatype == 13:
        res = unpack_datatype_13(data)
    elif datatype == 14:
        # 2048 bytes
        # D_803E2930
        res = unpack_datatype_14(data)
    elif datatype == 15:
        # D_803B1D20_7C33D0
        res = unpack_datatype_15(data)
    else:
        raise Exception("Unsupported datatype")

    return res
