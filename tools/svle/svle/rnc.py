import os
import tempfile

from pathlib import Path


# TODO: use subprocess
def execute_command(cmd):
    cmd_string = " ".join(cmd) + " >/dev/null"
    os.system(cmd_string)
    return True


def decompress_rnc(data, rnc_binary_path="../../tools/rnc_propack_source/rnc64"):
    with tempfile.TemporaryDirectory() as temp_dir:
        filepath = Path(temp_dir) / "tmp.rnc"
        destpath = Path(temp_dir) / "tmp.bin"

        with filepath.open("wb") as o:
            o.write(data)

        cmd = [
            f"{rnc_binary_path}",
            "u",
            f"{filepath}",
            f"{destpath}",
        ]
        execute_command(cmd)

        with destpath.open("rb") as f:
            uncompressed = f.read()

    return uncompressed


def compress_rnc(data, rnc_binary_path="../../tools/rnc_propack_source/rnc64"):
    with tempfile.TemporaryDirectory() as temp_dir:
        filepath = Path(temp_dir) / "tmp.bin"
        destpath = Path(temp_dir) / "tmp.rnc"

        with filepath.open("wb") as o:
            o.write(data)

        cmd = [
            f"{rnc_binary_path}",
            "p",
            f"{filepath}",
            f"{destpath}",
            "/f",  # force compression of files smaler than 18 bytes
        ]
        execute_command(cmd)

        with destpath.open("rb") as f:
            compressed = f.read()

    return compressed
