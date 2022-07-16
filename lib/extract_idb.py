import argparse
import logging
import re
from pathlib import Path


logger = logging.getLogger(__name__)


def parse_options(options):
    res = {}

    # we really only care about size
    opts = [
        # ("cmpsize", r"cmpsize\(([1-9][0-9]+)\)", int),
        ("size", r"size\(([1-9][0-9]+)\)", int),
    ]

    for (key, regex, cast) in opts:
        if match := re.search(regex, options):
            value = cast(match.group(1))
        else:
            value = 0
        res[key] = value

    return res


def load_file(file_path):
    logger.info("Loading data from %s", file_path)
    with open(file_path, "rb") as f:
        data = f.read()
    return {
        "data": data,
        "offset": 14,  # FIXME
    }

def main(idb_file, data_file=None, single_file=None, output_dir=None):
    data_files = {}

    file_data = idb_file.read()
    idb_file.close()

    if data_file is not None:
        data_files[data_file] = load_file(data_file)

    lines = file_data.split("\n")

    for i, line in enumerate(lines):
        if len(line.strip()) == 0:
            continue  # break?

        try:
            typ, perms, owner, group, file_name, archive_name, *options, data_file_name = line.split(" ")
        except ValueError:
            logger.warning("Skipping unexpected line format '%s'", line)
            continue

        assert file_name == archive_name, "expected source / destination files to match"

        if typ != "f":
            # ignore non-files
            continue

        options = " ".join(options)
        options = parse_options(options)

        if data_file is not None:
            data_file_name = data_file

        if data_file_name not in data_files:
            if not Path(data_file_name).exists():
                logger.fatal("Could not find '%s' to read from", data_file_name)
                return False
            data_files[data_file_name] = load_file(data_file_name)

        data = data_files[data_file_name]["data"]
        offset = data_files[data_file_name]["offset"]

        file_name_length = data[offset]
        offset += 1

        raw_file_name = data[offset:offset+file_name_length].decode("utf8")
        offset += file_name_length

        assert file_name == raw_file_name, ".idb filename (%s) did not match data filename (%s)" % (file_name, raw_file_name)

        size = options.get("cmpsize", 0) or options["size"]

        file_data = data[offset:offset+size]
        offset += size + 1

        out_file_path = Path(file_name)
        if output_dir is not None:
            out_file_path = output_dir / out_file_path

        out_file_path.parent.mkdir(parents=True, exist_ok=True)

        if single_file is None or file_name.endswith(single_file):
            with open(out_file_path, "wb") as f:
                logger.info("Writing %i bytes to %s", len(file_data), out_file_path.absolute())
                f.write(file_data)

        data_files[data_file_name]["offset"] = offset


if __name__ == '__main__':
    logging.basicConfig(handlers=[logging.StreamHandler()],
                        level=logging.INFO,
                        format=('%(asctime)s.%(msecs)03d %(levelname)s %(filename)s ' +
                                '%(funcName)s %(message)s'),
                        datefmt='%Y-%m-%d %H:%M:%S')

    parser = argparse.ArgumentParser()

    parser.add_argument("idb", type=argparse.FileType("r"))
    parser.add_argument("--data-file-path", type=str)
    parser.add_argument("--single-file", type=str)
    parser.add_argument("--output-dir", type=str)
    args = parser.parse_args()

    main(args.idb,
         data_file=args.data_file_path,
         output_dir=args.output_dir,
         single_file=args.single_file)
