import argparse
import json
import sys

from pathlib import Path

from svle.commands import build_command_workspace, encode_commands


def _level_name_from_cmd_path(path):
    name = path.name
    if name.endswith(".04.bin"):
        return name[:-7]
    return path.stem


def _default_output_path(infile):
    if infile.name.endswith(".04.bin"):
        return infile.with_name(f"{_level_name_from_cmd_path(infile)}.cmd.json")
    if infile.suffix == ".json":
        return infile.with_name(f"{infile.stem}.cmd.json")
    return infile.with_suffix(".cmd.json")


def _sibling_level_json(cmd_path):
    if cmd_path.name.endswith(".04.bin"):
        candidate = cmd_path.with_name(f"{_level_name_from_cmd_path(cmd_path)}.json")
        if candidate.exists():
            return candidate
    return None


def _command_data_from_level_json(level_data, infile):
    cmd = level_data.get("cmd")
    if cmd is not None:
        return encode_commands(cmd)

    sibling = infile.with_suffix(".04.bin")
    if sibling.exists():
        return sibling.read_bytes()

    raise ValueError("Level JSON has no 'cmd' section and no sibling .04.bin was found")


def main(infile, outfile=None, level_json=None):
    level_data = None

    if infile.suffix == ".json" and not infile.name.endswith(".cmd.json"):
        with infile.open("r") as f:
            level_data = json.load(f)
        command_data = _command_data_from_level_json(level_data, infile)
    else:
        command_data = infile.read_bytes()
        if level_json is None:
            level_json = _sibling_level_json(infile)
        if level_json is not None:
            with level_json.open("r") as f:
                level_data = json.load(f)

    if outfile is None:
        outfile = _default_output_path(infile)

    workspace = build_command_workspace(command_data, level_data, infile.name)
    with outfile.open("w") as f:
        json.dump(workspace, f, indent=4)
        f.write("\n")

    return workspace


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Decode an SSSV .04 command section into a rich command workspace JSON.")
    parser.add_argument("infile", type=Path, help="LEVEL.04.bin or LEVEL.json")
    parser.add_argument("outfile", type=Path, nargs="?", help="Output .cmd.json path")
    parser.add_argument("--level-json", type=Path, help="Optional LEVEL.json for object/animal script references")
    args = parser.parse_args()

    try:
        main(args.infile, args.outfile, args.level_json)
    except Exception as e:
        print(f"cmd2j: {e}", file=sys.stderr)
        raise
