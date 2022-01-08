import json
import sys
import os

# section order is consistent across all level files:
SECTION_ORDER = [12, 11, 9, 4, 0, 1, 2, 5, 7, 6, 10, 13, 14, 15, 3]

LEVEL_NAME = "levels/SMASHING_START"

rnc_path = "./tools/rnc_propack_source/rnc64"

data = b''

for section in SECTION_ORDER:
    filename = f"{LEVEL_NAME}_{section}"
    if os.path.exists(f"{filename}.bin"):
        if section == 3:
            # final section is not compressed
            with open(f"{filename}.bin", "rb") as f:
                file_data = f.read()
        else:
            cmd = f"{rnc_path} p {filename}.bin {filename}.rnc /f > /dev/null"
            os.system(cmd)
            with open(f"{filename}.rnc", "rb") as f:
                file_data = f.read()
        data += section.to_bytes(1, byteorder="big")
        data += file_data
    else:
        print(f"Error: Could not find {filename}...")
        # TODO: sys.exit(1) ?


with open(f"{LEVEL_NAME}.bin", "wb") as o:
    o.write(data)

cmd = f"{rnc_path} p {LEVEL_NAME}.bin {LEVEL_NAME}.rnc /f > /dev/null"
os.system(cmd)
