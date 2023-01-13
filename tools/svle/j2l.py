import json
import sys
import struct

from pathlib import Path

from svle.common import KEY_ORDER
from svle.pack import *
from svle.rnc import compress_rnc
from svle.sizes import *


def main(infile, outpath):
    with infile.open("r") as f:
        data = json.load(f)

    level_name = infile.stem

    res = bytes()
    outfile = outpath / infile.with_suffix(".bin").name

    for section in KEY_ORDER:
        res += section.to_bytes(1, byteorder="big")
        packed = pack_data(infile, data, section)

        # end of data sentinel
        if section == 3:
            res += packed
        else:
            res += compress_rnc(packed)

    with open("/tmp/bastard.bin", "wb") as f:
        f.write(res)

    # compress final file
    compressed = compress_rnc(res)

    if level_name in SIZES:
        level_size = SIZES[level_name]
        padding_required = level_size - len(compressed)
        if padding_required < 0:
            logger.warning("Level data is larger than original!")
        elif padding_required >0:
            logger.info("Padding file with %i byte(s) to match original length", padding_required)
            compressed += bytes(padding_required)

    with open(outfile, "wb") as f:
        f.write(compressed)


if __name__ == '__main__':
    logging.basicConfig(handlers=[logging.StreamHandler()],
        level=logging.INFO,
        format='%(asctime)s.%(msecs)03d %(levelname)s %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S')
    main(Path(sys.argv[1]), Path(sys.argv[2]))
