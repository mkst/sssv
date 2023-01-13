import logging
import struct
import logging

from .datatypes import *
from .common import *


logger = logging.getLogger(__file__)


def pack_data_with_length(values, values_format):
    packed = bytes()
    packed += len(values).to_bytes(2, byteorder="big")
    fmt = "".join(values_format.values())
    for entry in values:
        packed += struct.pack(">" + fmt, *entry.values())
    return packed


def pack_data_without_length(values, values_format):
    packed = bytes()
    fmt = "".join(values_format.values())
    for entry in values:
        packed += struct.pack(">" + fmt, *entry.values())
    return packed


def pack_data_single(values, values_format):
    packed = bytes()
    fmt = "".join(values_format.values())
    packed = struct.pack(">" + fmt, *values.values())
    return packed


def pack_datatype_0(values):
    logger.info("[.cob] Type  0: Objects: %i entry(s)", len(values))
    return pack_data_with_length(values, datatype_0_format)


def pack_datatype_1(values):
    logger.info("[.can] Type  1: Animals: %i entry(s)", len(values))
    return pack_data_with_length(values, datatype_1_format)


def pack_datatype_2(values):
    logger.info("[.joi] Type  2: Linking Objects: %i entry(s)", len(values))
    return pack_data_with_length(values, datatype_2_format)


def pack_datatype_4(data):
    raise NotImplementedError("No handler for Datatype 4")


def pack_datatype_5(values):
    logger.info("[.rng] Type  5: Unknown: %i", len(values))
    return pack_data_with_length(values, datatype_5_format)


def pack_datatype_6(values):
    logger.info("[.paf] Type  6: Waypoints: %i", len(values))
    packed = bytes()
    packed += len(values).to_bytes(2, byteorder="big")
    for entries in values:
        logger.debug("[ -> ] %i entry(s) to pack", entries)

        packed += len(entries).to_bytes(1, byteorder="big")
        for entry in entries:
            packed += struct.pack(">3B", *entry)
    # force 2-byte alignment
    if len(packed) % 2 != 0:
        packed += b"\x00"
    return packed


def pack_datatype_7(values):
    logger.info("[.cha] Type  7: Hanging Objects: %i entry(s)", len(values))
    return pack_data_with_length(values, datatype_7_format)


def pack_datatype_9(values):
    logger.info("[.map] Type  9: Collision: %i entry(s)", len(values))
    return pack_data_without_length(values, datatype_9_format)


def pack_datatype_10(data):
    raise NotImplementedError("No handler for Datatype 10")


def pack_datatype_11(values):
    """.mat - material lut?"""
    logger.info("[.mat] Type 11: Material LUT: %i entry(s)", len(values))
    return pack_data_without_length(values, datatype_11_format)


def pack_datatype_12(values):
    logger.info("[.dat] Type 12: Game State: %i entry(s", len(values))
    return pack_data_single(values, datatype_12_format)


def pack_datatype_13(values):
    logger.info("[.cam] Type 13: %i + %i", len(values[0]), len(values[1]))
    packed = bytes()
    packed += pack_data_with_length(values[0], datatype_13_format_a)
    packed += pack_data_without_length(values[1], datatype_13_format_b)
    return packed


def pack_datatype_14(values):
    logger.info("[.???] Type 14: %i entry(s)", len(values))
    return pack_data_without_length(values, datatype_14_format)


def pack_datatype_15(values):
    """tbd - hanging?"""
    logger.info("[.???] Type 15: %i entry(s)", len(values))
    return pack_data_with_length(values, datatype_15_format)


def pack_data(infile, data, section):
    packed = None

    key = PAYLOAD_TYPES.get(section, str(section))
    values = data.get(key)

    if values is None:
        with open(payload_filepath(infile, section), "rb") as f:
            packed = f.read()
        return packed

    if section == 0:
        packed = pack_datatype_0(values)
    elif section == 1:
        packed = pack_datatype_1(values)
    elif section == 2:
        packed = pack_datatype_2(values)
    elif section == 3:
        packed = bytes()  # empty
    elif section == 4:
        packed = pack_datatype_4(values)
    elif section == 5:
        packed = pack_datatype_5(values)
    elif section == 6:
        packed = pack_datatype_6(values)
    elif section == 7:
        packed = pack_datatype_7(values)
    # there is no type 8
    elif section == 9:
        packed = pack_datatype_9(values)
    elif section == 10:
        packed = pack_datatype_10(values)
    elif section == 11:
        packed = pack_datatype_11(values)
    elif section == 12:
        packed = pack_datatype_12(values)
    elif section == 13:
        packed = pack_datatype_13(values)
    elif section == 14:
        packed = pack_datatype_14(values)
    elif section == 15:
        packed = pack_datatype_15(values)
    else:
        raise Exception("Unsupported section type: %i" % section)

    return packed
