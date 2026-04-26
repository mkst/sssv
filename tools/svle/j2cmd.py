import argparse
import json
import sys

from pathlib import Path

from svle.commands import encode_commands


def _default_output_path(infile):
    name = infile.name
    if name.endswith(".cmd.json"):
        return infile.with_name(f"{name[:-9]}.04.bin")
    return infile.with_suffix(".04.bin")


def main(infile, outfile=None):
    with infile.open("r") as f:
        workspace = json.load(f)

    if outfile is None:
        outfile = _default_output_path(infile)

    outfile.write_bytes(encode_commands(workspace))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Encode an SSSV command workspace JSON back to a .04.bin section.")
    parser.add_argument("infile", type=Path, help="LEVEL.cmd.json")
    parser.add_argument("outfile", type=Path, nargs="?", help="Output LEVEL.04.bin path")
    args = parser.parse_args()

    try:
        main(args.infile, args.outfile)
    except Exception as e:
        print(f"j2cmd: {e}", file=sys.stderr)
        raise
