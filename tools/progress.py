import argparse
import os
import re
import sys
import subprocess

from pathlib import Path

def update_previous(entries, vram_end):
    if len(entries) > 0:
        last_entry = entries[-1]
        last_entry["vram_end"] = vram_end
        if len(last_entry["functions"]) > 0:
            last_entry["functions"][-1]["vram_end"] = vram_end


def parse_map(mapfile, target_start, target_end):
    files = []
    in_section = False

    while True:
        line = mapfile.readline()
        if line is None:
            break
        # --
        if not in_section:
            if match := re.match(rf" +(0x[0-9a-fA-F]+) +{target_start} ", line):
                section_vram_start = int(match.group(1), 16)
                in_section = True
        else:
            # end of section
            if match := re.match(rf" +(0x[0-9a-fA-F]+) +{target_end} ", line):
                section_vram_end = int(match.group(1), 16)
                update_previous(files, section_vram_end)
                in_section = False
                break

            #  build/lib/libultra_rom.a:initialize.o(.text)
            if match := re.match(rf" build/(.*\.a):(.*).o\(.text\)", line):
                lib_path = match.group(1)
                new_filename = match.group(2)
                continue

            # build/src.us/main_C770.c.o(.text)
            if match := re.match(rf" build/(.*).o\(.text\)", line):
                lib_path = ""
                new_filename = match.group(1)
                continue

            # .text          0x00000000801378c0      0x290 build/lib/libultra_rom.a(initialize.o)
            if match := re.match(rf" .text +(0x[0-9a-fA-F]+) +(0x[0-9a-fA-F]+) build/{lib_path}\({new_filename}.o\)", line):
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
            if match := re.match(rf" .text +(0x[0-9a-fA-F]+) +(0x[0-9a-fA-F]+) build/{new_filename}", line):
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

            if match := re.match(rf" +(0x[0-9a-fA-F]+) +L8(.*)", line):
                continue

            # function entry
            if match := re.match(rf" +(0x[0-9a-fA-F]+) +(.*)", line):
                function_vram_start = int(match.group(1), 16)
                function_name = match.group(2)
                function = dict(
                    name=function_name,
                    vram_start=function_vram_start,
                    vram_end=0,
                )
                # --
                aliased_function = False
                if len(files[-1]["functions"]) > 0:
                    prev_function_vram_start = files[-1]["functions"][-1]["vram_start"]
                    files[-1]["functions"][-1]["vram_end"] = function_vram_start
                    if prev_function_vram_start == function_vram_start:
                        # e.g. bzero/_bzero
                        aliased_function = True

                if not aliased_function:
                    files[-1]["functions"].append(function)
    return files


def parse_file(basedir, filename, file_funcs, includes, non_matching=False):
    updates = []

    pattern = re.compile(r'#pragma GLOBAL_ASM\(".*\/([^\/]+)\.s"\)')
    c_path = (basedir / filename).with_suffix(".c")
    if c_path.is_file():
        global_asms = []
        # cpp src.us/overlay2_6AB090.c  -I include/2.0I -I include -DNON_MATCHING
        extra_args = ["-DNON_MATCHING"] if non_matching else []
        cmd = ["cpp", str(c_path), *includes, *extra_args]
        res = subprocess.run(cmd, capture_output=True, check=True, text=True)
        lines = res.stdout.split("\n")
        for line in lines:
            if match := pattern.match(line):
                global_asms.append(match.group(1))
        for function in file_funcs:
            if function["name"] not in global_asms:
                updates.append(function["name"])
    return updates


def generate_csv(functions, version, section):
    ret = []
    ret.append("version,section,filename,function,offset,length,language")
    for function in functions:
        name = function["name"]
        filename = os.path.basename(function["filename"])
        language = function["language"]
        offset = function["vram_start"]
        length = function["size"]
        ret.append(f"{version},{section},{filename},{name},{offset},{length},{language}")
    return "\n".join(ret)


def create_progress(basedir, mapfile, target_start, target_end, section_name, version, includes, non_matching):
    files = parse_map(mapfile, target_start, target_end)
    all_functions = []

    for file in files:
        file_funcs = file["functions"]
        filename = file["filename"]
        c_functions = parse_file(basedir, filename, file_funcs, includes, non_matching)
        for file_func in file_funcs:
            file_func["filename"] = filename
            file_func["size"] = file_func["vram_end"] - file_func["vram_start"]
            # --
            assert file_func["size"] > 0
            # --
            if file_func["name"] in c_functions:
                file_func["language"] = "c"
            else:
                # mark library functions as (matched) c
                file_func["language"] = "asm" if file["filetype"] == "code" else "c"
            all_functions.append(file_func)

    csv = generate_csv(all_functions, version, section_name)
    print(csv)


def main():
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('basedir', type=Path,
                        help="base directory (containing src/)")
    parser.add_argument('mapfile', type=argparse.FileType('r'),
                        help=".map file to be parsed")
    parser.add_argument('target_start', type=str,
                        help="start of section")
    parser.add_argument('target_end', type=str,
                        help="end of section")
    parser.add_argument('section_name', type=str,
                        help="section name for csv")
    parser.add_argument('--version', type=str, default='us',
                        help="ROM version, us/eu")
    parser.add_argument('--includes', type=str,
                        help="comma-separated includes for cpp")
    parser.add_argument('--non-matching', action='store_true', default=False,
                        help="-DNON_MATCHING")
    args = parser.parse_args()

    if args.includes is None:
        includes = ["-I", "include", "-I", "include/2.0", "-I", "include/2.0/PR"]
    else:
        includes = args.includes.split(",")

    create_progress(args.basedir, args.mapfile, args.target_start, args.target_end, args.section_name, args.version, includes, args.non_matching)

if __name__ == '__main__':
    main()
