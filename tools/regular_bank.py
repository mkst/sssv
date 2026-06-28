#!/usr/bin/env python3
import argparse
from pathlib import Path

import png
import yaml


DEFAULT_WIDTH = 32
DEFAULT_HEIGHT = 32
DEFAULT_COLOR_FORMAT = "rgba16"
DEFAULT_MASK_FORMAT = "i4"
COLOR_FORMATS = ("rgba16",)
MASK_FORMATS = ("ia4", "i4")


def expand_5_to_8(value):
    return (value << 3) | (value >> 2)


def pack_color(r, g, b, a):
    return ((r >> 3) << 11) | ((g >> 3) << 6) | ((b >> 3) << 1) | (a >> 7)


def rgb_to_intensity(r, g, b):
    return round((r * 0.2126) + (g * 0.7152) + (b * 0.0722))


def image_size(width, height, fmt):
    if fmt == "rgba16":
        return width * height * 2
    if fmt in ("ia4", "i4"):
        return width * height // 2
    raise ValueError(f"Unsupported regular-bank format: {fmt}")


def texture_size(width, height, color_format, mask_format):
    return image_size(width, height, color_format) + image_size(width, height, mask_format)


def read_rgba16_image(data, width, height):
    expected_size = image_size(width, height, "rgba16")
    if len(data) != expected_size:
        raise ValueError(f"Expected 0x{expected_size:X} bytes, got 0x{len(data):X}")

    rows = []
    offset = 0
    for _ in range(height):
        row = []
        for _ in range(width):
            value = int.from_bytes(data[offset:offset + 2], byteorder="big")
            offset += 2
            row.extend((
                expand_5_to_8((value >> 11) & 0x1F),
                expand_5_to_8((value >> 6) & 0x1F),
                expand_5_to_8((value >> 1) & 0x1F),
                0xFF if value & 1 else 0,
            ))
        rows.append(row)
    return rows


def read_ia4_mask(data, width, height):
    expected_size = image_size(width, height, "ia4")
    if len(data) != expected_size:
        raise ValueError(f"Expected 0x{expected_size:X} bytes, got 0x{len(data):X}")

    rows = []
    offset = 0
    for _ in range(height):
        row = []
        for _ in range(width // 2):
            value = data[offset]
            offset += 1
            for nibble in (value >> 4, value & 0xF):
                intensity = expand_3_to_8((nibble >> 1) & 0x7)
                alpha = 0xFF if nibble & 1 else 0
                row.extend((intensity, alpha))
        rows.append(row)
    return rows


def read_i4_mask(data, width, height):
    expected_size = image_size(width, height, "i4")
    if len(data) != expected_size:
        raise ValueError(f"Expected 0x{expected_size:X} bytes, got 0x{len(data):X}")

    rows = []
    offset = 0
    for _ in range(height):
        row = []
        for _ in range(width // 2):
            value = data[offset]
            offset += 1
            for nibble in (value >> 4, value & 0xF):
                intensity = (nibble << 4) | nibble
                row.extend((intensity, 0xFF))
        rows.append(row)
    return rows


def expand_3_to_8(value):
    return (value << 5) | (value << 2) | (value >> 1)


def write_png(path, rows, width, height, greyscale=False):
    path.parent.mkdir(parents=True, exist_ok=True)
    writer = png.Writer(width, height, greyscale=greyscale, alpha=True)
    with path.open("wb") as f:
        writer.write(f, rows)


def apply_mask_to_color_rows(color_rows, mask_rows, mask_format):
    rows = []
    for color_row, mask_row in zip(color_rows, mask_rows):
        row = []
        color_pixels = iter(color_row)
        mask_pixels = iter(mask_row)
        for r, g, b, _a in zip(color_pixels, color_pixels, color_pixels, color_pixels):
            mask_intensity, mask_alpha = next(mask_pixels), next(mask_pixels)
            if mask_format == "i4":
                alpha = mask_intensity
            elif mask_format == "ia4":
                alpha = mask_alpha
            else:
                raise ValueError(f"Unsupported mask format: {mask_format}")
            row.extend((r, g, b, alpha))
        rows.append(row)
    return rows


def read_png_rgba(path, width, height):
    reader = png.Reader(filename=str(path))
    png_width, png_height, rows = reader.asRGBA()[:3]
    if png_width != width or png_height != height:
        raise ValueError(f"{path} is {png_width}x{png_height}, expected {width}x{height}")
    return rows


def read_png_as_rgba16(path, width, height):
    data = bytearray()
    for row in read_png_rgba(path, width, height):
        pixels = iter(row)
        for r, g, b, a in zip(pixels, pixels, pixels, pixels):
            data.extend(pack_color(r, g, b, a).to_bytes(2, byteorder="big"))
    return bytes(data)


def read_png_as_ia4(path, width, height):
    data = bytearray()
    for row in read_png_rgba(path, width, height):
        pixels = iter(row)
        pending = None
        for r, g, b, a in zip(pixels, pixels, pixels, pixels):
            intensity = rgb_to_intensity(r, g, b) >> 5
            alpha = 1 if a > 128 else 0
            nibble = (intensity << 1) | alpha
            if pending is None:
                pending = nibble
            else:
                data.append((pending << 4) | nibble)
                pending = None
        if pending is not None:
            data.append(pending << 4)
    return bytes(data)


def read_png_as_i4(path, width, height):
    data = bytearray()
    for row in read_png_rgba(path, width, height):
        pixels = iter(row)
        pending = None
        for r, g, b, _a in zip(pixels, pixels, pixels, pixels):
            nibble = round(15 * (rgb_to_intensity(r, g, b) / 0xFF))
            if pending is None:
                pending = nibble
            else:
                data.append((pending << 4) | nibble)
                pending = None
        if pending is not None:
            data.append(pending << 4)
    return bytes(data)


def relative_to(path, base):
    return path.relative_to(base).as_posix()


def default_edit_dir(bank_path):
    if bank_path.suffix == ".regular":
        return bank_path.with_suffix("")
    return bank_path.parent / bank_path.name


def unpack(args):
    bank_path = args.bank
    data = bank_path.read_bytes()
    one_texture_size = texture_size(args.width, args.height, args.color_format, args.mask_format)

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

    color_size = image_size(args.width, args.height, args.color_format)
    mask_size = image_size(args.width, args.height, args.mask_format)
    textures = []
    color_bank_size = count * color_size
    for texture_index in range(count):
        texture_id = f"{texture_index:02X}"
        texture_dir = edit_dir / texture_id

        color_offset = texture_index * color_size
        color_path = texture_dir / f"color.{args.color_format}.png"
        color_rows = read_rgba16_image(data[color_offset:color_offset + color_size], args.width, args.height)
        write_png(
            color_path,
            color_rows,
            args.width,
            args.height,
        )

        mask_offset = color_bank_size + (texture_index * mask_size)
        mask_path = texture_dir / f"mask.{args.mask_format}.png"
        if args.mask_format == "ia4":
            mask_rows = read_ia4_mask(data[mask_offset:mask_offset + mask_size], args.width, args.height)
        else:
            mask_rows = read_i4_mask(data[mask_offset:mask_offset + mask_size], args.width, args.height)
        write_png(mask_path, mask_rows, args.width, args.height, greyscale=True)

        preview_path = texture_dir / f"preview.{args.color_format}_{args.mask_format}.png"
        write_png(
            preview_path,
            apply_mask_to_color_rows(color_rows, mask_rows, args.mask_format),
            args.width,
            args.height,
        )

        textures.append({
            "id": texture_id,
            "color": relative_to(color_path, manifest_base),
            "mask": relative_to(mask_path, manifest_base),
            "preview": relative_to(preview_path, manifest_base),
        })

    manifest = {
        "version": 1,
        "width": args.width,
        "height": args.height,
        "color_format": args.color_format,
        "mask_format": args.mask_format,
        "textures": textures,
    }

    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    with manifest_path.open("w") as f:
        yaml.safe_dump(manifest, f, sort_keys=False)


def pack(args):
    manifest_path = args.manifest
    with manifest_path.open("r") as f:
        manifest = yaml.safe_load(f)

    color_format = manifest["color_format"]
    mask_format = manifest["mask_format"]
    if color_format not in COLOR_FORMATS:
        raise ValueError(f"Unsupported color format: {color_format}")
    if mask_format not in MASK_FORMATS:
        raise ValueError(f"Unsupported mask format: {mask_format}")

    width = manifest["width"]
    height = manifest["height"]
    manifest_base = manifest_path.parent
    color_data = bytearray()
    mask_data = bytearray()

    for texture in manifest["textures"]:
        color_data.extend(read_png_as_rgba16(manifest_base / texture["color"], width, height))
        mask_path = manifest_base / texture["mask"]
        if mask_format == "ia4":
            mask_data.extend(read_png_as_ia4(mask_path, width, height))
        else:
            mask_data.extend(read_png_as_i4(mask_path, width, height))

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(bytes(color_data) + bytes(mask_data))


def init_argparse():
    parser = argparse.ArgumentParser(description="Unpack and pack SSSV regular texture banks")
    subparsers = parser.add_subparsers(dest="command", required=True)

    unpack_parser = subparsers.add_parser("unpack", help="Create editable PNGs from a raw .regular bank")
    unpack_parser.add_argument("bank", type=Path)
    unpack_parser.add_argument("--manifest", type=Path)
    unpack_parser.add_argument("--output-dir", type=Path)
    unpack_parser.add_argument("--color-format", default=DEFAULT_COLOR_FORMAT, choices=COLOR_FORMATS)
    unpack_parser.add_argument("--mask-format", default=DEFAULT_MASK_FORMAT, choices=MASK_FORMATS)
    unpack_parser.add_argument("--width", type=int, default=DEFAULT_WIDTH)
    unpack_parser.add_argument("--height", type=int, default=DEFAULT_HEIGHT)
    unpack_parser.add_argument("--count", type=int)
    unpack_parser.set_defaults(func=unpack)

    pack_parser = subparsers.add_parser("pack", help="Rebuild a raw .regular bank from editable PNGs")
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
