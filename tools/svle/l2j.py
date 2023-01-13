import json
import os
import struct
import sys
import logging

from pathlib import Path

from svle.unpack import *
from svle.common import *
from svle.rnc import decompress_rnc


RNC_HEADER_LENGTH = 18


def main(infile, outdir):
    with open(infile, "rb") as f:
        data = f.read()

    # handle whether or not infile is compressed
    if data[:3] == b"RNC":
        logger.info("Unpacking %s", infile)
        data = decompress_rnc(data)

    outfile = outdir / infile.with_suffix(".json").name

    res = {}
    ptr = 0
    while ptr < len(data):
        payload_type = data[ptr]
        ptr += 1

        assert payload_type in KEY_ORDER, f"Unsupported payload_type: {payload_type}"

        if payload_type == 3:
            # leftover buffer junk?
            with open(payload_filepath(outfile, payload_type), "wb") as o:
                o.write(data[ptr:])
            break

        assert data[ptr:ptr+3] == b'RNC', "Payload was not an RNC chunk!"
        rnc_start = ptr
        ptr += 3

        # read Method
        rnc_type = data[ptr]
        ptr += 1
        assert rnc_type in (1, 2), "Unexpected RNC method : {rnc_type}"

        # read UncompressedSize
        uncompressed_size, = struct.unpack(">i", data[ptr:ptr+4])
        ptr += 4

        # read CompressedSize
        compressed_size, = struct.unpack(">i", data[ptr:ptr+4])
        ptr += 4

        # skip over the rest of the header
        ptr += 6

        # is there any alignment to worry about?
        compressed_length = compressed_size + RNC_HEADER_LENGTH

        uncompressed = decompress_rnc(data[rnc_start:rnc_start+compressed_length])

        segment = unpack_data(outfile, payload_type, uncompressed)

        if segment is not None:
            key = PAYLOAD_TYPES.get(payload_type, str(payload_type))
            res[key] = segment

        ptr += compressed_size

    with open(outfile, "w") as o:
        json.dump(res, o, indent=4)


if __name__ == '__main__':
    logging.basicConfig(handlers=[logging.StreamHandler()],
        level=logging.INFO,
        format='%(asctime)s.%(msecs)03d %(levelname)s %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S')
    main(Path(sys.argv[1]), Path(sys.argv[2]))
