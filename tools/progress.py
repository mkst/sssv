import argparse
import os
import re
import sys

from pathlib import Path

# do not include these files matching these names towards progress
IGNORE_LIST = [
    "rspbootText",
    "gspSprite2DText",
    "gspSprite2D_fifoText",
    "gspF3DEX_fifoText",
    "aspMainText",
]


def update_previous(entries, vram_end):
    if len(entries) > 0:
        last_entry = entries[-1]
        last_entry["vram_end"] = vram_end
        if len(last_entry["functions"]) > 0:
            last_entry["functions"][-1]["vram_end"] = vram_end


def parse_map(mapfile, target_start, target_end):
    files = []
    in_section = False

    lib_path = ""

    for line in mapfile.readlines():
        if not in_section:
            if match := re.match(rf"\s+(0x[0-9a-fA-F]+)\s+{target_start} ", line):
                # section_vram_start = int(match.group(1), 16)
                in_section = True
        else:
            # end of section
            if match := re.match(rf"\s+(0x[0-9a-fA-F]+)\s+{target_end} ", line):
                section_vram_end = int(match.group(1), 16)
                update_previous(files, section_vram_end)
                in_section = False
                break

            #                 0x00000000803a04e0                . = ALIGN (., 0x10)
            if match := re.match(r"\s+(0x[0-9a-fA-F]+)\s+\.\s+=\s+ALIGN.*$", line):
                file_vram_start = int(match.group(1), 16)
                update_previous(files, file_vram_start)
                continue

            #  build/lib/libultra_rom.a:initialize.o(.text*)
            if match := re.match(r"\s+build/(.*\.a):(.*).o\(.text\*?\)", line):
                lib_path = match.group(1)
                new_filename = match.group(2)
                continue

            # build/src.us/main_C770.c.o(.text*)
            if match := re.match(r"\s+build/(.*).o\(.text\*?\)", line):
                lib_path = ""
                new_filename = match.group(1)
                continue

            # .text          0x00000000801378c0      0x290 build/lib/libultra_rom.a(initialize.o)
            if match := re.match(
                rf"\s\.text\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+build/{lib_path}\({new_filename}.o\)",
                line,
            ):
                file_vram_start = int(match.group(1), 16)
                file_size = int(match.group(2), 16)
                update_previous(files, file_vram_start)
                # add new
                entry = dict(
                    filename=new_filename,
                    filetype="lib",
                    functions=[],
                    vram_start=file_vram_start,
                    vram_end=0,
                    size=file_size,
                )
                files.append(entry)

            # .text          0x0000000080131070      0x220 build/src.us/main_C770.c.o
            if match := re.match(
                rf"\s+.text\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+build/{new_filename}",
                line,
            ):
                file_vram_start = int(match.group(1), 16)
                file_size = int(match.group(2), 16)
                update_previous(files, file_vram_start)
                # add new
                entry = dict(
                    filename=new_filename,
                    filetype="code",
                    functions=[],
                    vram_start=file_vram_start,
                    vram_end=0,
                    size=file_size,
                )
                files.append(entry)
                continue

            # linker entry
            if match := re.match(r"\s+(0x[0-9a-fA-F]+)\s+.*_OFFSET\s+=\s+\.$", line):
                continue

            # function entry
            if match := re.match(r"\s+(0x[0-9a-fA-F]+)\s+(.*)", line):
                function_vram_start = int(match.group(1), 16)
                function_name = match.group(2)
                function = dict(
                    name=function_name,
                    vram_start=function_vram_start,
                    vram_end=0,
                )
                # --
                if len(files[-1]["functions"]) > 0:
                    prev_function_vram_start = files[-1]["functions"][-1]["vram_start"]
                    files[-1]["functions"][-1]["vram_end"] = function_vram_start
                    if prev_function_vram_start == function_vram_start:
                        # e.g. bzero/_bzero
                        prev_function_vram_name = files[-1]["functions"][-1]["name"]
                        # in-place replace for NON_MATCHING
                        if function_name == f"{prev_function_vram_name}.NON_MATCHING":
                            files[-1]["functions"][-1] = function
                        continue

                files[-1]["functions"].append(function)
    return files


def generate_csv(functions, version, section):
    ret = []
    ret.append("version,section,filename,function,offset,length,language")
    for function in functions:
        name = function["name"]
        filename = os.path.basename(function["filename"])
        language = function["language"]
        offset = function["vram_start"]
        length = function["size"]
        ret.append(
            f"{version},{section},{filename},{name},{offset},{length},{language}"
        )
    return "\n".join(ret)


def create_progress(mapfile, target_start, target_end, section_name, version):
    files = parse_map(mapfile, target_start, target_end)
    all_functions = []

    for file in files:
        file_funcs = file["functions"]
        filename = file["filename"]
        if any([re.search(ignore, filename) for ignore in IGNORE_LIST]):
            sys.stderr.write(f"Skipping {filename}\n")
            continue

        for file_func in file_funcs:
            file_func["filename"] = filename
            file_func["size"] = file_func["vram_end"] - file_func["vram_start"]
            # --
            assert file_func["size"] > 0
            # --
            if not file_func["name"].endswith(".NON_MATCHING"):
                file_func["language"] = "c"
            else:
                # mark library functions as (matched) c
                file_func["language"] = "asm" if file["filetype"] == "code" else "c"
            all_functions.append(file_func)

    csv = generate_csv(all_functions, version, section_name)
    sys.stdout.write(csv)


def main():
    parser = argparse.ArgumentParser(
        description="Create progress csv based on map file",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "mapfile", type=argparse.FileType("r"), help=".map file to be parsed"
    )
    parser.add_argument("target_start", type=str, help="start of section")
    parser.add_argument("target_end", type=str, help="end of section")
    parser.add_argument("section_name", type=str, help="section name for csv")
    parser.add_argument("--version", type=str, default="us", help="ROM version, us/eu")
    args = parser.parse_args()

    create_progress(
        args.mapfile,
        args.target_start,
        args.target_end,
        args.section_name,
        args.version,
    )


if __name__ == "__main__":
    main()
