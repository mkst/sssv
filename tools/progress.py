import argparse
import os
import re
import sys
import subprocess


def parse_map(mapfile, section, ending=None):
    functions = {}
    files = {}

    in_code = False

    filename = None
    function = None
    total_size = None

    previous_offset = 0

    while True:
        line = mapfile.readline()
        if not line:
            break

        if not in_code:
            if re.match(f"^{section} ", line):
                in_code = True
                split_line = line.split()
                if len(split_line) > 2:
                    # should we take file offset from individual offsets?
                    total_size = int(split_line[1], 16) + int(split_line[2], 16)
                else:
                    # try nextline
                    line = mapfile.readline()
                    split_line = line.split()
                    if len(split_line) < 2:
                        print("Could not determine total size, aborting")
                        sys.exit(1)
                    total_size = int(split_line[0], 16) + int(split_line[1], 16)
                continue
        else:
            if (ending and line.startswith(ending)) or (ending is None and len(line) in [0, 1, 2]):
                in_code = False  # kinda pointless
                if function and total_size:
                    functions[function]["length"] = total_size - functions[function]["offset"]
                else:
                    print("No function / unable to determine total size")
                break
            if re.match(r" .*build/.*\(\.text\)", line):
                # skip
                continue
            match = re.match(r"^ \.text +(0x[0-9A-z]+) +(0x[0-9A-z]+) +.*build/(.*)\.[a-z]+\.o", line)
            if match:
                # offset = match.group(1)
                # filesize = match.group(2)
                filename = match.group(3)
                files[filename] = []
                continue
            # should we use regex?
            split_line = line.split()
            if len(split_line) == 2:
                offset, new_function = split_line
                offset = int(offset, 16)
            else:
                continue
            if new_function.startswith("L8"):
                # skip label entries
                continue
            if offset < previous_offset:
                # sanity
                continue
            if function:
                # not 100% accurate due to nops but.. it'll do for now
                functions[function]["length"] = offset - functions[function]["offset"]
            functions[new_function] = {"offset": offset, "filename": filename, "language": "asm"}
            files[filename].append(new_function)
            function = new_function
            previous_offset = offset

    return (files, functions)


def parse_file(basedir, filename, file_funcs, includes, non_matching=False):
    updates = []

    pattern = re.compile(r'#pragma GLOBAL_ASM\(".*\/([^\/]+)\.s"\)')
    c_path = os.path.join(basedir, filename + ".c")
    if os.path.isfile(c_path):
        global_asms = []
        # cpp src.us/overlay2_6AB090.c  -I include/2.0I -I include -DNON_MATCHING
        extra_args = ["-DNON_MATCHING"] if non_matching else []
        cmd = ["cpp", c_path, *includes, *extra_args]
        res = subprocess.run(cmd, capture_output=True, check=True, text=True)
        lines = res.stdout.split("\n")
        for line in lines:
            match = pattern.match(line)
            if match:
                global_asms.append(match.group(1))
        for function in file_funcs:
            if function not in global_asms:
                updates.append(function)
    return updates


def generate_csv(files, functions, version, section):
    ret = []
    ret.append("version,section,filename,function,offset,length,language")
    for filename, funcs in files.items():
        basename = os.path.basename(filename)
        for func in funcs:
            language = functions[func]["language"]
            offset = functions[func]["offset"]
            length = functions[func]["length"]
            ret.append(f"{version},{section},{basename},{func},{offset},{length},{language}")
    return "\n".join(ret)


def main(basedir, mapfile, section, ending, version, includes, non_matching=False):
    files, functions = parse_map(mapfile, section, ending)
    for filename, file_funcs in files.items():
        c_functions = parse_file(basedir, filename, file_funcs, includes, non_matching)
        for c_function in c_functions:
            functions[c_function]["language"] = "c"
    section_name = section[1:].split("_")[-1]  # .main_lib -> lib
    csv = generate_csv(files, functions, version, section_name)
    print(csv)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Create progress csv based on map file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('basedir', type=str,
                        help="base directory (containing src/)")
    parser.add_argument('mapfile', type=argparse.FileType('r'),
                        help=".map file to be parsed")
    parser.add_argument('section', type=str,
                        help=".text section of the map")
    parser.add_argument('--ending', type=str,
                        help="section name that marks the end of 'section'")
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

    main(args.basedir, args.mapfile, args.section, args.ending, args.version, includes, args.non_matching)
