KEY_ORDER = [12, 11, 9, 4, 0, 1, 2, 5, 7, 6, 10, 13, 14, 15, 3]

PAYLOAD_TYPES = {
    0: "cob",
    1: "can",
    2: "joi",
    4: "cmd",
    5: "rng",
    6: "paf",
    7: "cha",
    9: "map",
    11: "mat",
    12: "dat",
    13: "cam",
}

def payload_filepath(filepath, payload_type):
    return filepath.with_suffix(f".{payload_type:02}.bin")
