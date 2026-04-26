#!/usr/bin/env python3
import argparse
import json
import math
import re
import struct
import zlib
from pathlib import Path


CELL_COLUMNS = 4
CELL_ROWS = 6
CELL_SIZE = 0x400
X_ORIGIN = 0x100
Z_ORIGIN = 0x200
TILE_SIZE = 0x40
HEIGHT_SCALE = 8
GEO_RECORD_SIZE = 0x34
MAP_X_POINTS = 65
MAP_Z_POINTS = 97
MAP_X_CELLS = MAP_X_POINTS - 1
MAP_Z_CELLS = MAP_Z_POINTS - 1

FLAG_TRIANGLE = 0x0001
FLAG_CELL_END = 0x0002
FLAG_CULL_BACK = 0x0004
FLAG_TRANSLUCENT = 0x0020
FLAG_ALPHA_COMPARE_DITHER = 0x0040
FLAG_RENDER_MODE_DECAL = 0x4000
REPO_ROOT = Path(__file__).resolve().parents[3]
TEXTURE_ROOT = REPO_ROOT / "levels" / "textures"
BIOME_NAMES = {
    0: "europe",
    1: "ice",
    2: "desert",
    3: "jungle",
    5: "city",
}
LEVEL_TEXTURE_ALIASES = {
    "SECRET_LEVEL": "SMASHING_START",
    "INTRO": "THE_ENGINE_ROOM",
    "CREDITS": "BIG_CELEBRATION_PARADE",
    "EMPTY_LEVEL_1": "PINBALL_BLIZZARD",
    "EMPTY_LEVEL_2": "HAVE_A_NICE_DAY",
}
LEVEL_OBJECT_TEXTURE_ORDER = {
    # Object render type 6 indexes the level texture bank loaded into
    # D_800D5420, not the segment-5 display-list asset order. Battery Farm's
    # block objects use unkC=40, which is slot zero of that runtime bank.
    "HAVE_A_NICE_DAY": [
        "floorboard.rgba16.png",
        "roof_tile.rgba16.png",
    ],
    "THE_BATTERY_FARM": [
        "floorboard.D_05000800_933F0.rgba16.png",
        "roof_tile.D_05000000_92BF0.rgba16.png",
        "dog_bed.D_05001AA0_94690.rgba16.png",
    ],
}
MIPMAP_TEXTURE_WIDTH = 32
MIPMAP_TEXTURE_HEIGHT = 32
MIPMAP_TRAILER_SIZE = 0xE
REGULAR_TEXTURE_WIDTH = 32
REGULAR_TEXTURE_HEIGHT = 32
REGULAR_RGBA16_SIZE = REGULAR_TEXTURE_WIDTH * REGULAR_TEXTURE_HEIGHT * 2
REGULAR_I4_SIZE = REGULAR_TEXTURE_WIDTH * REGULAR_TEXTURE_HEIGHT // 2
REGULAR_TEXTURE_SIZE = REGULAR_RGBA16_SIZE + REGULAR_I4_SIZE
BYTES_PER_WORD = 4
BIOME_REGULAR_BANKS = {
    0: ("europe", "img/levels/europe.rgba16"),
    1: ("ice", "img/levels/ice.rgba16"),
    2: ("desert", "img/levels/desert.rgba16"),
    3: ("jungle", "img/levels/jungle.rgba16"),
    # The runtime remaps city/final biome regular billboards through the
    # Europe regular bank.
    5: ("city", "img/levels/europe.rgba16"),
}


def read_json(path):
    with path.open("r") as f:
        return json.load(f)


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


def expand_5_to_8(value):
    return (value << 3) | (value >> 2)


def png_chunk(chunk_type, data):
    crc = zlib.crc32(chunk_type)
    crc = zlib.crc32(data, crc)
    return struct.pack(">I", len(data)) + chunk_type + data + struct.pack(">I", crc & 0xFFFFFFFF)


def rgba_rows_from_mipmap_image(data, width, height, fmt):
    rows = []
    bytes_per_pixel = 2
    pixels_per_word = BYTES_PER_WORD // bytes_per_pixel
    row_indexes = list(range(width))
    swapped_row_indexes = []
    for i in range(0, width, pixels_per_word * 2):
        swapped_row_indexes.extend(row_indexes[i + pixels_per_word:i + (pixels_per_word * 2)])
        swapped_row_indexes.extend(row_indexes[i:i + pixels_per_word])

    for y in range(height):
        row = bytearray()
        source_x_indexes = swapped_row_indexes if y % 2 else row_indexes
        for source_x in source_x_indexes:
            offset = ((y * width) + source_x) * bytes_per_pixel
            if fmt == "rgba16":
                value = int.from_bytes(data[offset:offset + 2], byteorder="big")
                row.extend((
                    expand_5_to_8((value >> 11) & 0x1F),
                    expand_5_to_8((value >> 6) & 0x1F),
                    expand_5_to_8((value >> 1) & 0x1F),
                    0xFF if value & 1 else 0,
                ))
            elif fmt == "ia16":
                intensity = data[offset]
                alpha = data[offset + 1]
                row.extend((intensity, intensity, intensity, alpha))
            else:
                raise ValueError(f"Unsupported mipmap format: {fmt}")
        rows.append(row)
    return rows


def write_image_png(path, data, width, height, fmt):
    path.parent.mkdir(parents=True, exist_ok=True)
    rows = rgba_rows_from_mipmap_image(data, width, height, fmt)
    write_rgba_png(path, rows, width, height)


def write_rgba_png(path, rows, width, height):
    path.parent.mkdir(parents=True, exist_ok=True)
    scanlines = b"".join(b"\x00" + bytes(row) for row in rows)
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)
    png_data = b"".join((
        b"\x89PNG\r\n\x1a\n",
        png_chunk(b"IHDR", ihdr),
        png_chunk(b"IDAT", zlib.compress(scanlines)),
        png_chunk(b"IEND", b""),
    ))
    path.write_bytes(png_data)


def rgba_rows_from_regular_texture(color_data, alpha_data):
    rows = []
    color_offset = 0
    alpha_offset = 0
    for _ in range(REGULAR_TEXTURE_HEIGHT):
        row = bytearray()
        for _ in range(REGULAR_TEXTURE_WIDTH // 2):
            alpha_byte = alpha_data[alpha_offset]
            alpha_offset += 1
            for alpha_nibble in (alpha_byte >> 4, alpha_byte & 0xF):
                color = int.from_bytes(color_data[color_offset:color_offset + 2], byteorder="big")
                color_offset += 2
                row.extend((
                    expand_5_to_8((color >> 11) & 0x1F),
                    expand_5_to_8((color >> 6) & 0x1F),
                    expand_5_to_8((color >> 1) & 0x1F),
                    (alpha_nibble << 4) | alpha_nibble,
                ))
        rows.append(row)
    return rows


def export_regular_billboard_textures(bank_asset, bank_kind, output_name):
    bank_path = REPO_ROOT / "assets" / f"{bank_asset}.regular"
    output_dir = TEXTURE_ROOT / "billboard" / bank_kind / output_name
    if not bank_path.exists():
        return []

    data = bank_path.read_bytes()
    if len(data) % REGULAR_TEXTURE_SIZE:
        return []

    entries = []
    count = len(data) // REGULAR_TEXTURE_SIZE
    alpha_base = count * REGULAR_RGBA16_SIZE
    for texture_index in range(count):
        color_offset = texture_index * REGULAR_RGBA16_SIZE
        alpha_offset = alpha_base + (texture_index * REGULAR_I4_SIZE)
        color_data = data[color_offset:color_offset + REGULAR_RGBA16_SIZE]
        alpha_data = data[alpha_offset:alpha_offset + REGULAR_I4_SIZE]

        png_path = output_dir / f"{texture_index:02X}.rgba16_i4.png"
        write_rgba_png(
            png_path,
            rgba_rows_from_regular_texture(color_data, alpha_data),
            REGULAR_TEXTURE_WIDTH,
            REGULAR_TEXTURE_HEIGHT,
        )
        entries.append({
            "index": texture_index,
            "format": "rgba16_i4",
            "width": REGULAR_TEXTURE_WIDTH,
            "height": REGULAR_TEXTURE_HEIGHT,
            "url": repo_url(png_path),
        })
    return entries


def repo_url(path):
    return "/" + path.relative_to(REPO_ROOT).as_posix()


def export_mipmap_level0_textures(bank_path, output_dir, fmt):
    if not bank_path.exists():
        return []

    data = bank_path.read_bytes()
    one_texture_size = texture_size(
        MIPMAP_TEXTURE_WIDTH,
        MIPMAP_TEXTURE_HEIGHT,
        fmt,
        MIPMAP_TRAILER_SIZE,
    )
    if len(data) % one_texture_size:
        return []

    entries = []
    count = len(data) // one_texture_size
    texture_offset = 0
    level0_size = image_size(MIPMAP_TEXTURE_WIDTH, MIPMAP_TEXTURE_HEIGHT, fmt)
    skip_size = sum(
        image_size(width, height, fmt)
        for width, height in mip_dimensions(MIPMAP_TEXTURE_WIDTH, MIPMAP_TEXTURE_HEIGHT)[1:]
    ) + MIPMAP_TRAILER_SIZE

    for texture_index in range(count):
        image_data = data[texture_offset:texture_offset + level0_size]
        png_path = output_dir / f"{texture_index:02X}.{fmt}.png"
        write_image_png(png_path, image_data, MIPMAP_TEXTURE_WIDTH, MIPMAP_TEXTURE_HEIGHT, fmt)
        entries.append({
            "index": texture_index,
            "format": fmt,
            "width": MIPMAP_TEXTURE_WIDTH,
            "height": MIPMAP_TEXTURE_HEIGHT,
            "url": repo_url(png_path),
        })
        texture_offset += level0_size + skip_size

    return entries


def texture_entries_for_bank(bank_name, bank_kind, texture_id_base, fmt):
    bank_path = REPO_ROOT / "assets" / "img" / "levels" / f"{bank_name}.mipmap"
    output_dir = TEXTURE_ROOT / bank_kind / bank_name
    entries = export_mipmap_level0_textures(bank_path, output_dir, fmt)
    return {
        str(texture_id_base + entry["index"]): {
            **entry,
            "textureId": texture_id_base + entry["index"],
            "bank": bank_name,
            "bankKind": bank_kind,
        }
        for entry in entries
    }


def png_dimensions(path):
    data = path.read_bytes()[:24]
    if len(data) < 24 or data[:8] != b"\x89PNG\r\n\x1a\n" or data[12:16] != b"IHDR":
        return MIPMAP_TEXTURE_WIDTH, MIPMAP_TEXTURE_HEIGHT
    return struct.unpack(">II", data[16:24])


def level_object_texture_sort_key(path):
    match = re.search(r"D_([0-9A-Fa-f]{8})_", path.name)
    if match:
        return (0, int(match.group(1), 16), path.name)
    return (1, 0, path.name)


def level_object_texture_entries(level_bank, texture_id_base):
    # Runtime object texture ids share the D_800BA760 texture arena. Id 40 is
    # D_800D5420, where load_level_texture_data unpacks per-level object images.
    texture_dir = REPO_ROOT / "assets" / "img" / "levels" / level_bank
    entries = {}
    png_paths = sorted(texture_dir.glob("*.rgba16.png"), key=level_object_texture_sort_key)
    ordered_names = LEVEL_OBJECT_TEXTURE_ORDER.get(level_bank, [])
    ordered_paths = [texture_dir / name for name in ordered_names if (texture_dir / name).exists()]
    ordered_path_names = {path.name for path in ordered_paths}
    texture_paths = ordered_paths + [
        path for path in png_paths
        if path.name not in ordered_path_names
    ]

    for index, png_path in enumerate(texture_paths):
        width, height = png_dimensions(png_path)
        texture_id = texture_id_base + index
        entries[str(texture_id)] = {
            "index": index,
            "format": "rgba16",
            "width": width,
            "height": height,
            "url": repo_url(png_path),
            "textureId": texture_id,
            "bank": level_bank,
            "bankKind": "levelObject",
        }
    return entries


def dynamic_billboard_texture_metadata(segment, level_bank):
    banks = []
    entries = {}

    bank_info = BIOME_REGULAR_BANKS.get(segment)
    if bank_info:
        biome_name, bank_asset = bank_info
        exported_entries = export_regular_billboard_textures(bank_asset, "biome", biome_name)
        entries.update({
            str(entry["index"]): {
                **entry,
                "category": entry["index"],
                "bank": biome_name,
                "bankKind": "biome",
                "source": bank_asset,
            }
            for entry in exported_entries
        })
        banks.append({
            "kind": "biome",
            "name": biome_name,
            "source": bank_asset,
            "format": "rgba16_i4",
            "categoryBase": 0,
            "count": len(exported_entries),
        })

    level_bank_asset = f"img/levels/{level_bank}"
    exported_entries = export_regular_billboard_textures(level_bank_asset, "level", level_bank)
    if exported_entries:
        entries.update({
            str(8 + entry["index"]): {
                **entry,
                "category": 8 + entry["index"],
                "bank": level_bank,
                "bankKind": "level",
                "source": level_bank_asset,
            }
            for entry in exported_entries
        })
        banks.append({
            "kind": "level",
            "name": level_bank,
            "source": level_bank_asset,
            "format": "rgba16_i4",
            "categoryBase": 8,
            "count": len(exported_entries),
        })

    return {
        "version": 1,
        "banks": banks,
        "entries": entries,
        "notes": [
            "Dynamic billboard categories 0-7 use the biome regular bank loaded by load_dynamic_texture_billboard_texture_pair().",
            "Dynamic billboard categories 8-11 use the level regular bank selected by textureBank and represented by this level's aliased regular asset.",
            "Category 0 animates between the first three entries at runtime; the browser currently displays entry 0.",
        ],
    }


def texture_metadata(level_name, level_data):
    level_config = normalize_level_config(level_data.get("dat", {}))
    segment = level_config.get("segment", 0)
    biome_name = BIOME_NAMES.get(segment)
    entries = {}
    banks = []

    if biome_name:
        rgba_bank = f"{biome_name}.rgba16"
        ia_bank = f"{biome_name}.ia16"
        rgba_entries = texture_entries_for_bank(rgba_bank, "biome", 0, "rgba16")
        # The runtime loads the level mipmap bank immediately after the biome
        # RGBA16 bank, and loads biome IA16 after that. func_80346878_757F28
        # treats texture IDs below 32 as RGBA and IDs 32+ as IA.
        level_texture_base = 20
        level_bank = LEVEL_TEXTURE_ALIASES.get(level_name, level_name)
        level_entries = texture_entries_for_bank(level_bank, "level", level_texture_base, "rgba16")
        ia_texture_base = 32
        ia_entries = texture_entries_for_bank(ia_bank, "biome", ia_texture_base, "ia16")
        level_object_texture_base = 40
        level_object_entries = level_object_texture_entries(level_bank, level_object_texture_base)
        entries.update(rgba_entries)
        entries.update(level_entries)
        entries.update(ia_entries)
        entries.update(level_object_entries)
        banks.extend([
            {
                "kind": "biome",
                "name": rgba_bank,
                "format": "rgba16",
                "textureIdBase": 0,
                "count": len(rgba_entries),
            },
            {
                "kind": "level",
                "name": level_bank,
                "format": "rgba16",
                "textureIdBase": level_texture_base,
                "count": len(level_entries),
            },
            {
                "kind": "biome",
                "name": ia_bank,
                "format": "ia16",
                "textureIdBase": ia_texture_base,
                "count": len(ia_entries),
            },
        ])
        if level_object_entries:
            banks.append({
                "kind": "levelObject",
                "name": level_bank,
                "format": "rgba16",
                "textureIdBase": level_object_texture_base,
                "count": len(level_object_entries),
            })
    else:
        level_texture_base = 0
        level_bank = LEVEL_TEXTURE_ALIASES.get(level_name, level_name)
        level_entries = texture_entries_for_bank(level_bank, "level", level_texture_base, "rgba16")
        level_object_texture_base = 40
        level_object_entries = level_object_texture_entries(level_bank, level_object_texture_base)
        entries.update(level_entries)
        entries.update(level_object_entries)
        banks.append({
            "kind": "level",
            "name": level_bank,
            "format": "rgba16",
            "textureIdBase": level_texture_base,
            "count": len(level_entries),
        })
        banks.append({
            "kind": "levelObject",
            "name": level_bank,
            "format": "rgba16",
            "textureIdBase": level_object_texture_base,
            "count": len(level_object_entries),
        })

    return {
        "version": 1,
        "tileSize": MIPMAP_TEXTURE_WIDTH,
        "level": level_bank,
        "biome": biome_name,
        "banks": banks,
        "entries": entries,
        "dynamicBillboards": dynamic_billboard_texture_metadata(
            segment,
            level_bank,
        ),
        "notes": [
            "Texture IDs mirror the runtime D_800BA760 arena: biome RGBA16, level RGBA16, biome IA16, then per-level object RGBA16 textures.",
            "Only the top 32x32 mip level is exported for browser rendering; odd rows apply N64 word swapping, but smaller mips and trailer bytes are not represented.",
        ],
    }


def read_define_names(header_path, prefix):
    names = {}
    pattern = re.compile(rf"^#define\s+({re.escape(prefix)}[A-Z0-9_]+)\s+(\d+)\b")
    for line in header_path.read_text().splitlines():
        match = pattern.match(line.strip())
        if not match:
            continue
        name, value = match.groups()
        names.setdefault(int(value), []).append(name.removeprefix(prefix))
    return names


def read_camera_mode_names(header_path):
    names = {}
    pattern = re.compile(r"^#define\s+(CAMERA_MODE_[A-Z0-9_]+)\s+(\d+)\b")
    for line in header_path.read_text().splitlines():
        match = pattern.match(line.strip())
        if not match:
            continue
        name, value = match.groups()
        names[int(value)] = name.removeprefix("CAMERA_MODE_")
    return names


def read_camera_mode_lookup(camera_path):
    text = camera_path.read_text()
    match = re.search(r"D_803A7B3C_7B91EC\[458\]\s*=\s*\{(.*?)\};", text, re.S)
    if not match:
        return []
    values = [int(value, 0) for value in re.findall(r"0x[0-9A-Fa-f]+|-?\d+", match.group(1))]
    return [
        {
            "cameraMode": values[i],
            "cameraModeParam": values[i + 1] if values[i + 1] < 0x8000 else values[i + 1] - 0x10000,
        }
        for i in range(0, len(values) - 1, 2)
    ]


def read_animal_names(header_path):
    names = {}
    pattern = re.compile(r"^#define\s+([A-Z0-9_]+)\s+(\d+)\b")
    for line in header_path.read_text().splitlines():
        if line.strip() == "// classes":
            break
        match = pattern.match(line.strip())
        if not match:
            continue
        name, value = match.groups()
        names.setdefault(int(value), []).append(name)
    return names


def name_entities(entries, names):
    res = []
    for entry in entries:
        item = dict(entry)
        matches = names.get(item.get("id"), [])
        if matches:
            item["name"] = matches[0]
            if len(matches) > 1:
                item["aliases"] = matches
        return_item = item
        res.append(return_item)
    return res


def load_name_tables():
    return {
        "animals": read_animal_names(REPO_ROOT / "include" / "animals.h"),
        "objects": read_define_names(REPO_ROOT / "include" / "objects.h", "OBJECT_"),
        "camera_modes": read_camera_mode_names(REPO_ROOT / "include" / "camera_enums.h"),
        "camera_lookup": read_camera_mode_lookup(REPO_ROOT / "src.us" / "sssv" / "camera.c"),
    }


LEVEL_CONFIG_ALIASES = {
    "unk2": "fogMin",
    "unk4": "fogMax",
    "unk6": "fogRed",
    "unk8": "fogGreen",
    "unkA": "fogBlue",
    "unkC": "nearClip",
    "unkE": "farClip",
    "unk10": "waterTileX",
    "unk12": "waterTileZ",
    "unk14": "waterTileWidth",
    "unk16": "waterTileDepth",
    "unk22": "waterWaveMode",
    "unk40": "sourceFovY",
    "unk42": "primDepthOffset",
    "unk4C": "waterMode",
    "unk4E": "startHeading",
    "unk50": "cameraHeading",
    "unk52": "textureBank",
    "unk54": "waterPrimRed",
    "unk55": "waterPrimGreen",
    "unk56": "waterPrimBlue",
    "waterPrimaryAlpha": "waterPrimAlpha",
    "unk58": "waterEnvRed",
    "unk59": "waterEnvGreen",
    "unk5A": "waterEnvBlue",
    "unk75": "useDynamicLightDir",
    "unk76": "lightDirX",
    "unk77": "lightDirY",
    "unk78": "lightDirZ",
}


for row in range(4):
    for col in range(6):
        LEVEL_CONFIG_ALIASES[f"unk{0x5C + row * 6 + col:02X}"] = f"cellLightingModes{row}{col}"


def normalize_level_config(config):
    normalized = dict(config)
    for old_name, new_name in LEVEL_CONFIG_ALIASES.items():
        if new_name not in normalized and old_name in normalized:
            normalized[new_name] = normalized[old_name]
    return normalized


def signed_vertex_byte(value):
    return value - 256 if value > 127 else value


def geo_vertex_normal(red, green, blue):
    # Lit level geo writes these three bytes into Vtx.n.n[]; unlit geo uses
    # the same bytes as Vtx.v.cn[] colors. Browser coordinates are x/y/z,
    # while the game Vtx order here is x/z/y.
    nx = signed_vertex_byte(red)
    nz = signed_vertex_byte(green)
    ny = signed_vertex_byte(blue)
    length = math.sqrt((nx * nx) + (ny * ny) + (nz * nz))
    if not length:
        return (0.0, 1.0, 0.0)
    return (nx / length, ny / length, nz / length)


def cell_uses_lighting(level_config, cell_x, cell_z):
    return level_config.get(f"cellLightingModes{cell_x}{cell_z}", 1) == 0


def parse_geo_record(data, offset, cell_x, cell_z, face_index, level_config):
    flags, texture, variant = struct.unpack_from(">HBB", data, offset)
    vertex_count = 3 if flags & FLAG_TRIANGLE else 4
    vertices = []
    lit = cell_uses_lighting(level_config, cell_x, cell_z)

    for i in range(4):
        base = offset + 4 + (i * 0xC)
        u, v, red, green, blue, local_x, local_y, local_z, alpha = struct.unpack_from(
            ">hhBBBbhBB", data, base
        )
        vertices.append(
            {
                "position": [
                    (local_x * TILE_SIZE) + (cell_x * CELL_SIZE) + X_ORIGIN,
                    local_y * HEIGHT_SCALE,
                    (local_z * TILE_SIZE) + (cell_z * CELL_SIZE) + Z_ORIGIN,
                ],
                "local": [local_x, local_y, local_z],
                "uv": [u, v],
                "color": [red, green, blue, 0 if texture >= 32 else alpha],
                "normal": geo_vertex_normal(red, green, blue) if lit else None,
            }
        )

    return {
        "index": face_index,
        "cell": [cell_x, cell_z],
        "flags": flags,
        "flagNames": decode_flags(flags),
        "texture": texture,
        "variant": variant,
        "lit": lit,
        "vertices": vertices[:vertex_count],
    }


def decode_flags(flags):
    names = []
    if flags & FLAG_TRIANGLE:
        names.append("triangle")
    if flags & FLAG_CELL_END:
        names.append("cell_end")
    if flags & FLAG_CULL_BACK:
        names.append("cull_back")
    if flags & FLAG_TRANSLUCENT:
        names.append("translucent")
    if flags & FLAG_ALPHA_COMPARE_DITHER:
        names.append("alpha_compare_dither")
    if flags & FLAG_RENDER_MODE_DECAL:
        names.append("render_mode_decal")
    unknown = flags & ~(
        FLAG_TRIANGLE
        | FLAG_CELL_END
        | FLAG_CULL_BACK
        | FLAG_TRANSLUCENT
        | FLAG_ALPHA_COMPARE_DITHER
        | FLAG_RENDER_MODE_DECAL
    )
    if unknown:
        names.append(f"unknown_0x{unknown:04X}")
    return names


def parse_geo(data, level_config):
    faces = []
    offset = 0
    face_index = 0

    for cell_z in range(CELL_ROWS):
        for cell_x in range(CELL_COLUMNS):
            while offset + GEO_RECORD_SIZE <= len(data):
                face = parse_geo_record(data, offset, cell_x, cell_z, face_index, level_config)
                faces.append(face)
                offset += GEO_RECORD_SIZE
                face_index += 1
                if face["flags"] & FLAG_CELL_END:
                    break

    trailing = len(data) - offset
    return faces, trailing


def mesh_from_faces(faces):
    positions = []
    colors = []
    normals = []
    uvs = []
    indices = []
    face_meta = []

    for face in faces:
        base = len(positions) // 3
        for vertex in face["vertices"]:
            positions.extend(vertex["position"])
            color = vertex["color"]
            colors.extend([color[0] / 255.0, color[1] / 255.0, color[2] / 255.0, color[3] / 255.0])
            normal = vertex["normal"]
            normals.extend(normal if normal else [0.0, 1.0, 0.0])
            uvs.extend(vertex["uv"])

        if len(face["vertices"]) == 3:
            indices.extend([base + 2, base + 1, base])
        else:
            indices.extend([base + 2, base + 1, base, base + 2, base + 3, base + 1])

        face_meta.append(
            {
                "firstIndex": len(indices) - (3 if len(face["vertices"]) == 3 else 6),
                "indexCount": 3 if len(face["vertices"]) == 3 else 6,
                "cell": face["cell"],
                "flags": face["flags"],
                "flagNames": face["flagNames"],
                "texture": face["texture"],
                "variant": face["variant"],
                "lit": face["lit"],
            }
        )

    return {
        "positions": positions,
        "colors": colors,
        "normals": normals,
        "uvs": uvs,
        "indices": indices,
        "faces": face_meta,
    }


def map_mesh(level_data):
    map_data = level_data.get("map", [])
    material_data = level_data.get("mat", [])
    positions = []
    upper_positions = []
    colors = []
    upper_colors = []
    friction_colors = []
    height_offset_colors = []
    landing_colors = []
    surface_state_colors = []
    indices = []
    upper_indices = []
    flow_positions = []
    flow_colors = []
    collision_positions = []
    collision_colors = []

    for x in range(MAP_X_POINTS):
        for z in range(MAP_Z_POINTS):
            entry = map_data[(x * MAP_Z_POINTS) + z]
            world_x = (x + 4) * TILE_SIZE
            world_z = (z + 8) * TILE_SIZE
            floor_y = entry["unk0"] * HEIGHT_SCALE
            upper_y = entry["unk1"] * HEIGHT_SCALE
            positions.extend([world_x, floor_y, world_z])
            upper_positions.extend([world_x, upper_y, world_z])
            water = entry["unk6"] * 4
            material = entry["unk3"] or entry["unk2"]
            material_entry = material_data[material] if material < len(material_data) else None
            colors.extend(color_for_map_entry(entry["unk0"], water, material))
            upper_colors.extend(color_for_upper_map_entry(entry["unk1"], entry["unk3"]))
            friction = material_byte(material_entry, "unk0")
            friction_colors.extend(color_for_friction(entry["unk0"], friction))
            height_offset_colors.extend(color_for_unsigned_material_value(entry["unk0"], material_entry, "unk2"))
            landing_colors.extend(color_for_landing_response(entry["unk0"], material_entry))
            surface_state_colors.extend(color_for_surface_state(entry["unk0"], material_entry))

    for x in range(MAP_X_CELLS):
        for z in range(MAP_Z_CELLS):
            entry = map_data[(x * MAP_Z_POINTS) + z]
            floor_y = entry["unk0"] * HEIGHT_SCALE
            upper_y = entry["unk1"] * HEIGHT_SCALE
            add_flow_arrow(flow_positions, flow_colors, x, z, max(floor_y, upper_y), entry["unk7"])
            add_collision_edges(collision_positions, collision_colors, x, z, floor_y, upper_y, entry["unk5"])

    for x in range(MAP_X_CELLS):
        for z in range(MAP_Z_CELLS):
            a = (x * MAP_Z_POINTS) + z
            b = a + MAP_Z_POINTS
            c = a + 1
            d = b + 1
            diagonal_flip = map_data[a]["unk4"] & 1
            upper_diagonal_flip = map_data[a]["unk4"] & 2
            if diagonal_flip:
                indices.extend([a, c, d, a, d, b])
            else:
                indices.extend([a, c, b, b, c, d])
            if upper_diagonal_flip:
                upper_indices.extend([a, c, d, a, d, b])
            else:
                upper_indices.extend([a, c, b, b, c, d])

    return {
        "positions": positions,
        "colors": colors,
        "frictionColors": friction_colors,
        "heightOffsetColors": height_offset_colors,
        "landingColors": landing_colors,
        "surfaceStateColors": surface_state_colors,
        "indices": indices,
        "upper": {
            "positions": upper_positions,
            "colors": upper_colors,
            "indices": upper_indices,
        },
        "flow": {
            "positions": flow_positions,
            "colors": flow_colors,
        },
        "collision": {
            "positions": collision_positions,
            "colors": collision_colors,
        },
    }


def water_mesh(level_data):
    map_data = level_data.get("map", [])
    positions = []
    colors = []
    indices = []

    for x in range(MAP_X_POINTS):
        for z in range(MAP_Z_POINTS):
            entry = map_data[(x * MAP_Z_POINTS) + z]
            positions.extend([(x + 4) * TILE_SIZE, entry["unk6"] * 8, (z + 8) * TILE_SIZE])
            colors.extend([0.08, 0.48, 0.78, 0.46])

    for x in range(MAP_X_CELLS):
        for z in range(MAP_Z_CELLS):
            a = (x * MAP_Z_POINTS) + z
            b = a + MAP_Z_POINTS
            c = a + 1
            d = b + 1
            if max(map_data[a]["unk6"], map_data[b]["unk6"], map_data[c]["unk6"], map_data[d]["unk6"]) == 0:
                continue
            indices.extend([a, c, b, b, c, d])

    return {
        "positions": positions,
        "colors": colors,
        "indices": indices,
    }


def color_for_map_entry(height, water, material):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.2]
    if water:
        return [0.0, 0.42, 0.75, 0.55]
    palette = [
        [0.35, 0.55, 0.28, 0.55],
        [0.48, 0.42, 0.36, 0.55],
        [0.56, 0.56, 0.62, 0.55],
        [0.72, 0.62, 0.34, 0.55],
        [0.32, 0.48, 0.52, 0.55],
        [0.58, 0.38, 0.38, 0.55],
    ]
    return palette[material % len(palette)]


def color_for_upper_map_entry(height, material):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.08]
    if material:
        return [0.85, 0.48, 0.96, 0.32]
    return [0.48, 0.82, 0.88, 0.22]


def color_for_friction(height, friction):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.2]
    if friction is None:
        return [0.4, 0.4, 0.4, 0.55]

    # Runtime formulas treat 16 as the high-grip end; lower values slide more.
    grip = max(0.0, min(1.0, friction / 16.0))
    slippery = 1.0 - grip
    cold = [0.18, 0.62, 0.95]
    neutral = [0.86, 0.82, 0.52]
    hot = [0.92, 0.24, 0.18]
    if grip < 0.5:
        t = grip * 2.0
        rgb = [cold[i] * (1.0 - t) + neutral[i] * t for i in range(3)]
    else:
        t = (grip - 0.5) * 2.0
        rgb = [neutral[i] * (1.0 - t) + hot[i] * t for i in range(3)]
    alpha = 0.66 + (slippery * 0.14)
    return [rgb[0], rgb[1], rgb[2], alpha]


def material_byte(material_entry, key):
    if material_entry is None:
        return None
    return material_entry[key] & 0xFF


def color_for_unsigned_material_value(height, material_entry, key):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.2]
    if material_entry is None:
        return [0.4, 0.4, 0.4, 0.55]

    value = material_byte(material_entry, key)
    amount = min(1.0, value / 128.0)
    neutral = [0.36, 0.39, 0.38]
    high = [0.92, 0.54, 0.18]
    rgb = [neutral[i] * (1.0 - amount) + high[i] * amount for i in range(3)]
    return [rgb[0], rgb[1], rgb[2], 0.62 + amount * 0.18]


def color_for_landing_response(height, material_entry):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.2]
    if material_entry is None:
        return [0.4, 0.4, 0.4, 0.55]

    # Runtime treats values below 17 as no bounce, otherwise value - 16.
    response = max(0, material_byte(material_entry, "unk3") - 16)
    amount = min(1.0, response / 16.0)
    base = [0.36, 0.39, 0.38]
    hot = [0.96, 0.32, 0.28]
    rgb = [base[i] * (1.0 - amount) + hot[i] * amount for i in range(3)]
    return [rgb[0], rgb[1], rgb[2], 0.58 + amount * 0.22]


def color_for_surface_state(height, material_entry):
    if height == 0xFF:
        return [0.05, 0.05, 0.05, 0.2]
    if material_entry is None:
        return [0.4, 0.4, 0.4, 0.55]

    value = material_entry["unkB"]
    if value == 0:
        return [0.36, 0.39, 0.38, 0.55]
    color = hsv_to_rgb(((value * 37) % 360) / 360.0, 0.72, 0.92)
    return [color[0], color[1], color[2], 0.76]


def hsv_to_rgb(h, s, v):
    i = int(h * 6)
    f = (h * 6) - i
    p = v * (1 - s)
    q = v * (1 - f * s)
    t = v * (1 - (1 - f) * s)
    i %= 6
    if i == 0:
        return [v, t, p]
    if i == 1:
        return [q, v, p]
    if i == 2:
        return [p, v, t]
    if i == 3:
        return [p, q, v]
    if i == 4:
        return [t, p, v]
    return [v, p, q]


def decode_flow(value):
    x_magnitude = (value >> 4) & 7
    z_magnitude = value & 7
    x_sign = -1 if value & 0x80 else 1
    z_sign = -1 if value & 0x08 else 1
    return x_sign * x_magnitude, z_sign * z_magnitude


def add_flow_arrow(positions, colors, x, z, y, value):
    flow_x, flow_z = decode_flow(value)
    if flow_x == 0 and flow_z == 0:
        return

    center_x = (x + 4.5) * TILE_SIZE
    center_z = (z + 8.5) * TILE_SIZE
    length = max(18.0, ((flow_x * flow_x + flow_z * flow_z) ** 0.5) * 9.0)
    magnitude = max(1.0, (flow_x * flow_x + flow_z * flow_z) ** 0.5)
    dir_x = flow_x / magnitude
    dir_z = flow_z / magnitude
    perp_x = -dir_z
    perp_z = dir_x
    base_x = center_x - (dir_x * length * 0.36)
    base_z = center_z - (dir_z * length * 0.36)
    tip_x = center_x + (dir_x * length * 0.64)
    tip_z = center_z + (dir_z * length * 0.64)
    arrow_y = y + 28
    head = min(18.0, length * 0.42)
    spread = head * 0.48

    add_colored_line(positions, colors, base_x, arrow_y, base_z, tip_x, arrow_y, tip_z, [0.50, 0.88, 1.0, 0.92])
    add_colored_line(
        positions,
        colors,
        tip_x,
        arrow_y,
        tip_z,
        tip_x - (dir_x * head) + (perp_x * spread),
        arrow_y,
        tip_z - (dir_z * head) + (perp_z * spread),
        [0.50, 0.88, 1.0, 0.92],
    )
    add_colored_line(
        positions,
        colors,
        tip_x,
        arrow_y,
        tip_z,
        tip_x - (dir_x * head) - (perp_x * spread),
        arrow_y,
        tip_z - (dir_z * head) - (perp_z * spread),
        [0.50, 0.88, 1.0, 0.92],
    )


def add_collision_edges(positions, colors, x, z, floor_y, upper_y, flags):
    if flags == 0:
        return

    x0 = (x + 4) * TILE_SIZE
    x1 = x0 + TILE_SIZE
    z0 = (z + 8) * TILE_SIZE
    z1 = z0 + TILE_SIZE
    lower_color = [1.0, 0.58, 0.20, 0.92]
    upper_color = [0.95, 0.38, 1.0, 0.92]

    edge_defs = [
        (0x01, floor_y + 12, x0, z0, x0, z1, lower_color),
        (0x02, floor_y + 12, x1, z0, x1, z1, lower_color),
        (0x04, floor_y + 12, x0, z0, x1, z0, lower_color),
        (0x08, floor_y + 12, x0, z1, x1, z1, lower_color),
        (0x10, upper_y + 18, x0, z0, x0, z1, upper_color),
        (0x20, upper_y + 18, x1, z0, x1, z1, upper_color),
        (0x40, upper_y + 18, x0, z0, x1, z0, upper_color),
        (0x80, upper_y + 18, x0, z1, x1, z1, upper_color),
    ]
    for bit, y_pos, start_x, start_z, end_x, end_z, color in edge_defs:
        if flags & bit:
            add_colored_line(positions, colors, start_x, y_pos, start_z, end_x, y_pos, end_z, color)


def add_colored_line(positions, colors, x0, y0, z0, x1, y1, z1, color):
    positions.extend([x0, y0, z0, x1, y1, z1])
    colors.extend(color)
    colors.extend(color)


def default_camera_path(level_json):
    return level_json.with_suffix(".13.bin")


def camera_height_filter_name(value):
    return {
        240: "any_height",
        241: "ground_state_2",
        242: "ground_state_1",
        243: "ground_state_0_or_2",
        244: "ground_state_0_or_1",
        245: "sentinel",
    }.get(value)


def decode_camera_distance_flags(value):
    return {
        "min": struct.unpack("b", bytes([(value >> 4) & 0xFF]))[0],
        "max": struct.unpack("b", bytes([(value << 4) & 0xFF]))[0] >> 4,
        "followHeading": (value >> 8) & 1,
    }


def enrich_camera_region(region, settings, name_tables):
    mode_index = region["mode"]
    setting_index = region["visibility"]
    lookup = name_tables["camera_lookup"]
    if 0 <= mode_index < len(lookup):
        region.update(lookup[mode_index])
        region["cameraModeName"] = name_tables["camera_modes"].get(region["cameraMode"], str(region["cameraMode"]))
    else:
        region["cameraMode"] = None
        region["cameraModeParam"] = None
        region["cameraModeName"] = "UNKNOWN"

    if 0 <= setting_index < len(settings):
        region["settings"] = settings[setting_index]
    else:
        region["settings"] = None

    # Runtime only passes the settings anchor bytes into func_80340E08_7524B8
    # for these camera-mode indices; other modes pass zeroes explicitly.
    region["usesAnchor"] = mode_index in (2, 12, 33, 40)
    region["heightFilter"] = camera_height_filter_name(region["yStartOrType"])
    return region


def parse_camera_payload(path, name_tables):
    if not path.exists():
        return {"regions": [], "settings": []}

    data = path.read_bytes()
    if len(data) < 2:
        return {"regions": [], "settings": []}

    count = struct.unpack_from(">h", data, 0)[0]
    regions = []
    offset = 2
    for i in range(count):
        if offset + 8 > len(data):
            break
        x0, z0, y0_or_type, x1, z1, y1, mode, visibility = struct.unpack_from(">BBBBBBBB", data, offset)
        regions.append(
            {
                "index": i,
                "xStart": x0,
                "zStart": z0,
                "yStartOrType": y0_or_type,
                "xEnd": x1,
                "zEnd": z1,
                "yEnd": y1,
                "mode": mode,
                "cameraModeIndex": mode,
                "visibility": visibility,
                "settingsIndex": visibility,
            }
        )
        offset += 8

    settings = []
    for i in range(count):
        if offset + 20 > len(data):
            break
        values = struct.unpack_from(">BBBBHHHHHHHH", data, offset)
        setting = {
            "index": i,
            "anchorX": values[0],
            "anchorZ": values[1],
            "anchorY": values[2],
            "unk0": values[0],
            "unk1": values[1],
            "unk2": values[2],
            "unk3": values[3],
            "visibilityMasks": list(values[4:12]),
            "unk4": values[4],
            "unk6": values[5],
            "unk8": values[6],
            "unkA": values[7],
            "unkC": values[8],
            "unkE": values[9],
            "unk10": values[10],
            "unk12": values[11],
        }
        setting.update(decode_camera_distance_flags(setting["unk12"]))
        settings.append(setting)
        offset += 20

    for region in regions:
        enrich_camera_region(region, settings, name_tables)

    return {"regions": regions, "settings": settings}


def compact_entities(level_data, name_tables):
    return {
        "objects": name_entities(level_data.get("cob", []), name_tables["objects"]),
        "animals": name_entities(level_data.get("can", []), name_tables["animals"]),
        "links": level_data.get("joi", []),
        "regions": level_data.get("rng", []),
        "dynamicObjects": level_data.get("cha", []),
        "paths": level_data.get("paf", []),
        "camera": level_data.get("camera", {"regions": [], "settings": []}),
        "levelConfig": normalize_level_config(level_data.get("dat", {})),
    }


def default_geo_path(level_json):
    return level_json.with_suffix(".10.bin")


def main():
    parser = argparse.ArgumentParser(description="Export SSSV level data to browser-friendly JSON.")
    parser.add_argument("level_json", type=Path, help="Path to a levels/*.json file from tools/svle/l2j.py")
    parser.add_argument("out_json", type=Path, nargs="?", help="Output JSON path")
    parser.add_argument("--geo-bin", type=Path, help="Override type-10 geometry payload path")
    args = parser.parse_args()

    level_json = args.level_json
    level_data = read_json(level_json)
    level_config = normalize_level_config(level_data.get("dat", {}))
    geo_path = args.geo_bin or default_geo_path(level_json)
    geo_data = geo_path.read_bytes()
    faces, trailing = parse_geo(geo_data, level_config)
    name_tables = load_name_tables()
    level_data["camera"] = parse_camera_payload(default_camera_path(level_json), name_tables)

    out = {
        "version": 1,
        "level": level_json.stem,
        "source": {
            "json": str(level_json),
            "geo": str(geo_path),
        },
        "units": {
            "tile": TILE_SIZE,
            "heightScale": HEIGHT_SCALE,
            "cellSize": CELL_SIZE,
            "geoOrigin": [X_ORIGIN, 0, Z_ORIGIN],
            "mapPoints": [MAP_X_POINTS, MAP_Z_POINTS],
            "mapCells": [MAP_X_CELLS, MAP_Z_CELLS],
        },
        "stats": {
            "geoBytes": len(geo_data),
            "geoRecords": len(faces),
            "trailingBytes": trailing,
            "triangles": sum(1 if len(face["vertices"]) == 3 else 2 for face in faces),
        },
        "geo": mesh_from_faces(faces),
        "textures": texture_metadata(level_json.stem, level_data),
        "map": map_mesh(level_data),
        "water": water_mesh(level_data),
        "entities": compact_entities(level_data, name_tables),
    }

    out_json = args.out_json or level_json.with_suffix(".view.json")
    out_json.parent.mkdir(parents=True, exist_ok=True)
    with out_json.open("w") as f:
        json.dump(out, f, separators=(",", ":"))

    print(f"Wrote {out_json}")
    print(
        f"{out['stats']['geoRecords']} geo records, "
        f"{out['stats']['triangles']} triangles, "
        f"{out['stats']['trailingBytes']} trailing byte(s)"
    )


if __name__ == "__main__":
    main()
