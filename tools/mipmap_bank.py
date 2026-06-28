#!/usr/bin/env python3
import argparse
from pathlib import Path

import png
import yaml


DEFAULT_FORMAT = "rgba16"
DEFAULT_WIDTH = 32
DEFAULT_HEIGHT = 32
DEFAULT_TRAILER_SIZE = 0xE
BYTES_PER_WORD = 4
FORMATS = ("rgba16", "ia16")


def expand_5_to_8(value):
    return (value << 3) | (value >> 2)


def pack_color(r, g, b, a):
    return ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1) | (a >> 7)


def rgb_to_intensity(r, g, b):
    return round((r * 0.2126) + (g * 0.7152) + (b * 0.0722))


def mip_dimensions(width, height):
    dimensions = []
    while width > 0 and height > 0:
        dimensions.append((width, height))
        width //= 2
        height //= 2
    return dimensions


def image_size(width, height, fmt):
    if fmt in ("rgba16", "ia16"):
        return width * height * 2
    raise ValueError(f"Unsupported mipmap format: {fmt}")


def texture_size(width, height, fmt, trailer_size):
    return sum(image_size(w, h, fmt) for w, h in mip_dimensions(width, height)) + trailer_size


def mipmap_row_indexes(width, bytes_per_pixel, y):
    indexes = list(range(width))
    if y % 2 == 0:
        return indexes

    pixels_per_word = BYTES_PER_WORD // bytes_per_pixel
    swapped = []
    for i in range(0, width, pixels_per_word * 2):
        swapped.extend(indexes[i + pixels_per_word:i + (pixels_per_word * 2)])
        swapped.extend(indexes[i:i + pixels_per_word])
    return swapped


def read_rgba16_image(data, width, height):
    expected_size = image_size(width, height, "rgba16")
    if len(data) != expected_size:
        raise ValueError(f"Expected 0x{expected_size:X} bytes, got 0x{len(data):X}")

    rows = []
    bytes_per_pixel = 2
    for y in range(height):
        row = []
        for x in mipmap_row_indexes(width, bytes_per_pixel, y):
            offset = ((y * width) + x) * bytes_per_pixel
            value = int.from_bytes(data[offset:offset + 2], byteorder="big")
            row.extend((
                expand_5_to_8((value >> 11) & 0x1F),
                expand_5_to_8((value >> 6) & 0x1F),
                expand_5_to_8((value >> 1) & 0x1F),
                0xFF if value & 1 else 0,
            ))
        rows.append(row)
    return rows


def read_ia16_image(data, width, height):
    expected_size = image_size(width, height, "ia16")
    if len(data) != expected_size:
        raise ValueError(f"Expected 0x{expected_size:X} bytes, got 0x{len(data):X}")

    rows = []
    bytes_per_pixel = 2
    for y in range(height):
        row = []
        for x in mipmap_row_indexes(width, bytes_per_pixel, y):
            offset = ((y * width) + x) * bytes_per_pixel
            row.extend((data[offset], data[offset + 1]))
        rows.append(row)
    return rows


def write_image_png(path, data, width, height, fmt):
    path.parent.mkdir(parents=True, exist_ok=True)
    if fmt == "rgba16":
        rows = read_rgba16_image(data, width, height)
        writer = png.Writer(width, height, greyscale=False, alpha=True)
    elif fmt == "ia16":
        rows = read_ia16_image(data, width, height)
        writer = png.Writer(width, height, greyscale=True, alpha=True)
    else:
        raise ValueError(f"Unsupported mipmap format: {fmt}")

    with path.open("wb") as f:
        writer.write(f, rows)


def read_png_as_rgba16(path, width, height):
    reader = png.Reader(filename=str(path))
    png_width, png_height, rows = reader.asRGBA()[:3]
    if png_width != width or png_height != height:
        raise ValueError(f"{path} is {png_width}x{png_height}, expected {width}x{height}")

    data = bytearray()
    packed_rows = []
    for row in rows:
        packed_row = []
        pixels = iter(row)
        for pixel in zip(pixels, pixels, pixels, pixels):
            packed_row.append(pixel)
        packed_rows.append(packed_row)

    for y, row in enumerate(packed_rows):
        for x in mipmap_row_indexes(width, 2, y):
            r, g, b, a = row[x]
            data.extend(pack_color(r, g, b, a).to_bytes(2, byteorder="big"))
    return bytes(data)


def read_png_as_ia16(path, width, height):
    reader = png.Reader(filename=str(path))
    png_width, png_height, rows = reader.asRGBA()[:3]
    if png_width != width or png_height != height:
        raise ValueError(f"{path} is {png_width}x{png_height}, expected {width}x{height}")

    data = bytearray()
    packed_rows = []
    for row in rows:
        packed_row = []
        pixels = iter(row)
        for pixel in zip(pixels, pixels, pixels, pixels):
            packed_row.append(pixel)
        packed_rows.append(packed_row)

    for y, row in enumerate(packed_rows):
        for x in mipmap_row_indexes(width, 2, y):
            r, g, b, a = row[x]
            data.extend((rgb_to_intensity(r, g, b), a))
    return bytes(data)


def read_png_as_image(path, width, height, fmt):
    if fmt == "rgba16":
        return read_png_as_rgba16(path, width, height)
    if fmt == "ia16":
        return read_png_as_ia16(path, width, height)
    raise ValueError(f"Unsupported mipmap format: {fmt}")


def relative_to(path, base):
    return path.relative_to(base).as_posix()


def default_edit_dir(bank_path):
    if bank_path.suffix == ".mipmap":
        return bank_path.with_suffix("")
    return bank_path.parent / bank_path.name


def unpack(args):
    bank_path = args.bank
    data = bank_path.read_bytes()
    one_texture_size = texture_size(args.width, args.height, args.format, args.trailer_size)

    if args.count is None:
        if len(data) % one_texture_size != 0:
            raise ValueError(
                f"{bank_path} is 0x{len(data):X} bytes, which is not a multiple "
                f"of one 0x{one_texture_size:X}-byte texture"
            )
        count = len(data) // one_texture_size
    else:
        count = args.count
        expected_size = one_texture_size * count
        if len(data) != expected_size:
            raise ValueError(f"{bank_path} is 0x{len(data):X} bytes, expected 0x{expected_size:X}")

    manifest_path = args.manifest or bank_path.with_suffix(bank_path.suffix + ".yaml")
    edit_dir = args.output_dir or default_edit_dir(bank_path)
    manifest_base = manifest_path.parent

    textures = []
    offset = 0
    dimensions = mip_dimensions(args.width, args.height)

    for texture_index in range(count):
        texture_id = f"{texture_index:02X}"
        texture_dir = edit_dir / texture_id
        levels = []

        for level, (width, height) in enumerate(dimensions):
            size = image_size(width, height, args.format)
            path = texture_dir / f"level{level}.{args.format}.png"
            write_image_png(path, data[offset:offset + size], width, height, args.format)
            offset += size
            levels.append({
                "level": level,
                "width": width,
                "height": height,
                "path": relative_to(path, manifest_base),
            })

        trailer_path = texture_dir / "trailer.bin"
        trailer_path.write_bytes(data[offset:offset + args.trailer_size])
        offset += args.trailer_size

        textures.append({
            "id": texture_id,
            "levels": levels,
            "trailer": relative_to(trailer_path, manifest_base),
        })

    manifest = {
        "version": 1,
        "format": args.format,
        "width": args.width,
        "height": args.height,
        "trailer_size": args.trailer_size,
        "textures": textures,
    }

    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    with manifest_path.open("w") as f:
        yaml.safe_dump(manifest, f, sort_keys=False)


def pack(args):
    manifest_path = args.manifest
    with manifest_path.open("r") as f:
        manifest = yaml.safe_load(f)

    fmt = manifest["format"]
    if fmt not in FORMATS:
        raise ValueError(f"Unsupported mipmap format: {fmt}")

    manifest_base = manifest_path.parent
    data = bytearray()

    for texture in manifest["textures"]:
        for level in texture["levels"]:
            path = manifest_base / level["path"]
            data.extend(read_png_as_image(path, level["width"], level["height"], fmt))

        trailer_path = manifest_base / texture["trailer"]
        trailer = trailer_path.read_bytes()
        expected_size = manifest["trailer_size"]
        if len(trailer) != expected_size:
            raise ValueError(f"{trailer_path} is 0x{len(trailer):X} bytes, expected 0x{expected_size:X}")
        data.extend(trailer)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(data)


def init_argparse():
    parser = argparse.ArgumentParser(description="Unpack and pack SSSV mipmap texture banks")
    subparsers = parser.add_subparsers(dest="command", required=True)

    unpack_parser = subparsers.add_parser("unpack", help="Create editable PNGs from a raw .mipmap bank")
    unpack_parser.add_argument("bank", type=Path)
    unpack_parser.add_argument("--manifest", type=Path)
    unpack_parser.add_argument("--output-dir", type=Path)
    unpack_parser.add_argument("--format", default=DEFAULT_FORMAT, choices=FORMATS)
    unpack_parser.add_argument("--width", type=int, default=DEFAULT_WIDTH)
    unpack_parser.add_argument("--height", type=int, default=DEFAULT_HEIGHT)
    unpack_parser.add_argument("--count", type=int)
    unpack_parser.add_argument("--trailer-size", type=int, default=DEFAULT_TRAILER_SIZE)
    unpack_parser.set_defaults(func=unpack)

    pack_parser = subparsers.add_parser("pack", help="Rebuild a raw .mipmap bank from editable PNGs")
    pack_parser.add_argument("manifest", type=Path)
    pack_parser.add_argument("output", type=Path)
    pack_parser.set_defaults(func=pack)

    return parser


def main():
    parser = init_argparse()
    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
