#!/usr/bin/env python3
import argparse
import ast
import json
import math
import re
from pathlib import Path

from animal_rigs import STATIC_ANIMAL_RIGS


REPO_ROOT = Path(__file__).resolve().parents[3]
DATA_ROOT = REPO_ROOT / "src.us" / "data"
OBJECTS_PATH = DATA_ROOT / "objects_7B9BD0.c"
OBJECTS_HEADER = REPO_ROOT / "include" / "objects.h"
ANIMALS_HEADER = REPO_ROOT / "include" / "animals.h"
YAML_PATH = REPO_ROOT / "sssv.us.yaml"

# Some runtime render cases draw hardcoded display lists in addition to the
# object table's displayList fields.
SPECIAL_RENDER_EXTRA_DISPLAY_LISTS = {
    # OBJECT_ACTIVE_TURRET / OBJECT_ACTIVE_MISSILE_TURRET base and gun.
    10: ("D_0100AF90_44860", "D_0100B2C0_44B90"),
    # OBJECT_SPEAKER cone geometry.
    15: ("D_010106E0_49FB0", "D_01011140_4AA10"),
}

VERTEX_RE = re.compile(
    r".*{{{\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*},\s*\d+,\s*"
    r"{\s*(-?\d+),\s*(-?\d+)\s*},\s*"
    r"{\s*(-?\d+),\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*}}},?"
)
SP_VERTEX_RE = re.compile(r".*gsSPVertex\((\w+|0x[0-9A-Fa-f]+),\s*(\d+),\s*(\d+)\),")
SP_1_TRI_RE = re.compile(r".*gsSP1Triangle\((\d+),\s*(\d+),\s*(\d+),\s*(\d+)\),")
SP_2_TRI_RE = re.compile(
    r".*gsSP2Triangles\((\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*"
    r"(\d+),\s*(\d+),\s*(\d+),\s*(\d+)\),"
)
SP_QUAD_RE = re.compile(r".*gsSP1Quadrangle\((\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*(\d+)\),")
PRIM_COLOR_RE = re.compile(
    r".*gsDPSetPrimColor\([^,]+,\s*[^,]+,\s*(0x[0-9A-Fa-f]+|\d+),\s*"
    r"(0x[0-9A-Fa-f]+|\d+),\s*(0x[0-9A-Fa-f]+|\d+),\s*(0x[0-9A-Fa-f]+|\d+)\),"
)
TEXTURE_IMAGE_RE = re.compile(
    r".*gsDPSetTextureImage\(\s*(G_IM_FMT_\w+),\s*(G_IM_SIZ_\w+),\s*"
    r"([^,]+),\s*(\w+|0x[0-9A-Fa-f]+)\s*\),"
)
TEXTURE_TILE_SIZE_RE = re.compile(
    r".*gsDPSetTileSize\(\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*([^,\)]+)\s*\),"
)
SP_TEXTURE_RE = re.compile(
    r".*gsSPTexture\(\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*(G_ON|G_OFF)\s*\),"
)
SEGMENT_SYMBOL_RE = re.compile(r"^D_([0-9A-Fa-f]{2})[0-9A-Fa-f]{6}_")
DISPLAY_LIST_SYMBOL_RE = re.compile(r"^D_[0-9A-Fa-f]{8}_[0-9A-Fa-f]+$")
IMAGE_FORMATS = {"rgba16", "i4", "i8", "ia16", "ci4", "palette"}
NEUTRAL_FIXED_SCALE_SYMBOLS = {
    "D_803F2EBC",
    "D_803F2EC0",
    "D_803F2EC4",
    "D_803F2EC8",
}

BIOME_PREFIXES = {
    "OBJECT_EUROPE_": "Europe",
    "OBJECT_ICE_": "Ice",
    "OBJECT_JUNGLE_": "Jungle",
    "OBJECT_DESERT_": "Desert",
    "OBJECT_CITY_": "City",
}

BIOME_SEGMENTS = {
    "europe_biome": "Europe",
    "ice_biome": "Ice",
    "jungle_biome": "Jungle",
    "desert_biome": "Desert",
    "city_biome": "City",
}

LEVEL_SLOT_SEGMENTS = {
    "data_7F790": "Dan Danger",
    "data_116BD0": "Menu",
}

SEGMENT_LABELS = {
    0x01: "segment 1 / always loaded",
    0x04: "segment 4 / current biome",
    0x05: "segment 5 / special or level assets",
}
BILLBOARD_TABLE_SYMBOL = "D_803B1CDC_7C338C"


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return re.sub(r"//.*", "", text)


def split_top_level_csv(text):
    fields = []
    start = 0
    paren_depth = 0
    brace_depth = 0
    for i, ch in enumerate(text):
        if ch == "(":
            paren_depth += 1
        elif ch == ")":
            paren_depth -= 1
        elif ch == "{":
            brace_depth += 1
        elif ch == "}":
            brace_depth -= 1
        elif ch == "," and paren_depth == 0 and brace_depth == 0:
            fields.append(text[start:i].strip())
            start = i + 1
    tail = text[start:].strip()
    if tail:
        fields.append(tail)
    return fields


def extract_initializer_entries(text, symbol):
    match = re.search(rf"\b{re.escape(symbol)}\s*\[\]\s*=\s*\{{", text)
    if not match:
        raise ValueError(f"Could not find initializer for {symbol}")

    entries = []
    depth = 1
    entry_start = None
    i = match.end()
    while i < len(text) and depth:
        ch = text[i]
        if ch == "{":
            if depth == 1:
                entry_start = i + 1
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 1 and entry_start is not None:
                entries.append(text[entry_start:i].strip())
                entry_start = None
        i += 1
    return entries


def parse_int_token(token, defines=None):
    token = token.strip()
    if defines and token in defines:
        return defines[token]
    if token == "NULL":
        return None
    return int(token, 0)


def parse_s16_token(token, defines=None):
    value = parse_int_token(token, defines)
    if value is None:
        return None
    value &= 0xFFFF
    return value - 0x10000 if value >= 0x8000 else value


def parse_literal_int_token(token):
    token = token.strip()
    if re.fullmatch(r"0x[0-9A-Fa-f]+|\d+", token):
        return int(token, 0)
    return None


def fixed_scale_literal(value):
    return int(round(float(value) * 0x10000))


def replace_fixed_scale_macros(expr):
    return re.sub(
        r"\bFTOFIX32\s*\(\s*([+-]?(?:\d+(?:\.\d*)?|\.\d+))f?\s*\)",
        lambda match: str(fixed_scale_literal(match.group(1))),
        expr,
    )


def eval_int_expr_node(node):
    if isinstance(node, ast.Expression):
        return eval_int_expr_node(node.body)
    if isinstance(node, ast.Constant) and isinstance(node.value, int):
        return node.value
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.USub):
        return -eval_int_expr_node(node.operand)
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.UAdd):
        return eval_int_expr_node(node.operand)
    if isinstance(node, ast.BinOp):
        left = eval_int_expr_node(node.left)
        right = eval_int_expr_node(node.right)
        if isinstance(node.op, ast.Add):
            return left + right
        if isinstance(node.op, ast.Sub):
            return left - right
        if isinstance(node.op, ast.Mult):
            return left * right
        if isinstance(node.op, ast.FloorDiv):
            return c_div(left, right)
        if isinstance(node.op, ast.RShift):
            return left >> right
        if isinstance(node.op, ast.LShift):
            return left << right
    raise ValueError("unsupported integer expression")


def evaluate_fixed_scale_expr(expr):
    expr = replace_fixed_scale_macros(expr)
    for symbol in NEUTRAL_FIXED_SCALE_SYMBOLS:
        expr = re.sub(rf"\b{symbol}\b", str(0x10000), expr)
    if not re.fullmatch(r"[\s0-9A-Fa-fxX()+\-*/<>]+", expr):
        return None
    expr = expr.replace("/", "//")
    try:
        value = eval_int_expr_node(ast.parse(expr, mode="eval"))
    except (SyntaxError, ValueError, ZeroDivisionError):
        return None
    return value / 0x10000


def parse_object_id_token(token, defines, fallback_id):
    try:
        return parse_int_token(token, defines)
    except ValueError:
        # The table is ordered by object ID. This lets the exporter keep working
        # if a newly named OBJECT_* token has not been added to objects.h yet.
        return fallback_id


def default_object_name(object_id):
    return f"OBJECT_{object_id}"


def pretty_label(value):
    return value.replace("_", " ").title()


def classify_yaml_segment(segment_name):
    if segment_name == "segment1":
        return {
            "scope": "global",
            "label": "Global",
            "shortLabel": "Global",
            "source": "sssv.us.yaml segment1",
            "segment": segment_name,
        }
    if segment_name in BIOME_SEGMENTS:
        biome = BIOME_SEGMENTS[segment_name]
        return {
            "scope": "biome",
            "biome": biome,
            "label": f"{biome} biome",
            "shortLabel": biome,
            "source": f"sssv.us.yaml {segment_name}",
            "segment": segment_name,
        }
    if segment_name:
        label = LEVEL_SLOT_SEGMENTS.get(segment_name, pretty_label(segment_name))
        return {
            "scope": "level",
            "level": segment_name,
            "label": label,
            "shortLabel": label,
            "source": f"sssv.us.yaml {segment_name}",
            "segment": segment_name,
        }
    return None


def availability_for_name(name, section, level):
    if section == "global":
        return {
            "scope": "global",
            "label": "Global",
            "shortLabel": "Global",
            "source": "include/objects.h segment1 section",
        }
    if section == "biome":
        biome = None
        for prefix, label in BIOME_PREFIXES.items():
            if name.startswith(prefix):
                biome = label
                break
        return {
            "scope": "biome",
            "biome": biome,
            "label": f"{biome} biome" if biome else "Biome-specific",
            "shortLabel": biome or "Biome",
            "source": "include/objects.h biome section",
        }
    if section == "level":
        label = pretty_label(level) if level else "Level-specific"
        return {
            "scope": "level",
            "level": level,
            "label": label,
            "shortLabel": label,
            "source": "include/objects.h level section",
        }
    return {
        "scope": "unknown",
        "label": "Unknown",
        "shortLabel": "Unknown",
        "source": "include/objects.h",
    }


def merge_availability(candidates, fallback):
    candidates = [candidate for candidate in candidates if candidate]
    if not candidates:
        return dict(fallback)

    keyed = {}
    for candidate in candidates:
        key = (candidate.get("scope"), candidate.get("segment"), candidate.get("biome"), candidate.get("level"))
        keyed.setdefault(key, candidate)
    unique = list(keyed.values())

    scope_priority = {"global": 0, "biome": 1, "level": 2, "unknown": 3}
    primary = sorted(unique, key=lambda item: scope_priority.get(item.get("scope"), 9))[0]
    result = dict(primary)
    result["sources"] = unique
    if len({item.get("scope") for item in unique}) > 1:
        result["mixedAssetScopes"] = True
    return result


def read_object_defines(path):
    defines = {}
    metadata_by_name = {}
    section = "unknown"
    current_level = None
    define_re = re.compile(r"^#define\s+([A-Z0-9_]+)\s+(\d+)\b")
    for line in path.read_text().splitlines():
        stripped = line.strip()
        lower = stripped.lower()
        if "ovl_01" in lower or "segment1" in lower:
            section = "global"
            current_level = None
        elif "ovl_04" in lower or "biome specific" in lower:
            section = "biome"
            current_level = None
        elif "ovl_05" in lower or "level specific" in lower:
            section = "level"
            current_level = None
            match = re.search(r"ovl_05:\s*([^)/*]+)", stripped)
            if match:
                current_level = match.group(1).strip()
        elif section == "level" and stripped.startswith("//"):
            current_level = stripped[2:].strip().split()[0] or None

        match = define_re.match(stripped)
        if match:
            name = match.group(1)
            defines[name] = int(match.group(2))
            metadata_by_name[name] = availability_for_name(name, section, current_level)
    names_by_id = {}
    for name, value in defines.items():
        names_by_id.setdefault(value, []).append(name)
    return defines, names_by_id, metadata_by_name


def read_simple_defines(path):
    defines = {}
    define_re = re.compile(r"^#define\s+([A-Z0-9_]+)\s+(\d+)\b")
    for line in path.read_text().splitlines():
        if match := define_re.match(line.strip()):
            defines[match.group(1)] = int(match.group(2))
    return defines


def read_numeric_array(path, symbol):
    text = strip_comments(path.read_text())
    match = re.search(
        rf"\b(?:u8|u16|s16|s32|struct077)\s+{re.escape(symbol)}\s*(?:\[[^\]]*\])?\s*=\s*\{{",
        text,
    )
    if not match:
        raise ValueError(f"Could not find numeric array {symbol} in {path.relative_to(REPO_ROOT)}")

    depth = 1
    start = match.end()
    i = start
    while i < len(text) and depth:
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
        i += 1
    body = text[start:i - 1]
    return [
        int(token, 0)
        for token in re.findall(r"-?0x[0-9A-Fa-f]+|-?\d+", body)
    ]


def yaml_data_key_for_path(path):
    rel = path.relative_to(DATA_ROOT).with_suffix("").as_posix()
    return f"data/{rel}"


def read_yaml_data_segments(path):
    data_segments = {}
    current_segment = None
    segment_re = re.compile(r"^  - name:\s*([^#]+)")
    data_re = re.compile(r"\[\s*0x[0-9A-Fa-f]+\s*,\s*\.data\s*,\s*([^,\]\s]+)")

    for line in path.read_text().splitlines():
        segment_match = segment_re.match(line)
        if segment_match:
            current_segment = segment_match.group(1).strip()
            continue
        if current_segment is None:
            continue
        data_match = data_re.search(line)
        if data_match:
            data_segments[data_match.group(1).strip()] = current_segment
    return data_segments


def eval_simple_expr(value):
    value = value.strip()
    if re.fullmatch(r"0x[0-9A-Fa-f]+|\d+", value):
        return int(value, 0)
    match = re.fullmatch(r"(?:0x[0-9A-Fa-f]+|\d+)\s*\*\s*\((?:0x[0-9A-Fa-f]+|\d+)\)", value)
    if match:
        left, right = re.split(r"\s*\*\s*", value, maxsplit=1)
        return int(left, 0) * int(right.strip("() "), 0)
    return None


def symbol_for_image(path_token, fmt):
    base = "img_" + re.sub(r"[^0-9A-Za-z_]", "_", path_token.removeprefix("img/"))
    return f"{base}_{fmt}__png"


def repo_url(path):
    return "/" + path.relative_to(REPO_ROOT).as_posix()


def read_yaml_texture_entries(path):
    textures = {}
    current_segment = None
    current_level_texture_index = {}
    segment_re = re.compile(r"^  - name:\s*([^#]+)")
    inline_re = re.compile(
        r"\[\s*0x[0-9A-Fa-f]+\s*,\s*([a-z0-9_]+)\s*,\s*([^,\]\s]+)\s*,\s*(\d+)\s*,\s*(\d+)"
    )
    block = []

    def add_entry(fmt, image_path, width, height):
        if fmt not in IMAGE_FORMATS or not image_path.startswith("img/"):
            return
        asset_path = REPO_ROOT / "assets" / f"{image_path}.{fmt}.png"
        url = repo_url(asset_path) if asset_path.exists() else None
        fallback_url = None
        match = re.match(r"img/levels/([^/]+)/", image_path)
        if match and fmt in {"rgba16", "ia16"}:
            level = match.group(1)
            key = (level, fmt)
            index = current_level_texture_index.get(key, 0)
            current_level_texture_index[key] = index + 1
            fallback = REPO_ROOT / "levels" / "textures" / "level" / level / f"{index:02X}.{fmt}.png"
            if fallback.exists():
                fallback_url = repo_url(fallback)
                if url is None:
                    url = fallback_url
        entry = {
            "symbol": symbol_for_image(image_path, fmt),
            "format": fmt,
            "width": int(width),
            "height": int(height),
            "asset": image_path,
            "url": url,
            "fallbackUrl": fallback_url,
            "segment": current_segment,
        }
        textures[entry["symbol"]] = entry

    for raw_line in path.read_text().splitlines():
        line = raw_line.strip()
        segment_match = segment_re.match(raw_line)
        if segment_match:
            current_segment = segment_match.group(1).strip()
            continue
        if block:
            block.append(line.rstrip(","))
            if line.startswith("]"):
                fields = [field.strip() for field in block if field.strip() not in ("[", "]")]
                if len(fields) >= 5:
                    add_entry(fields[1], fields[2], fields[3], fields[4])
                block = []
            continue
        if line.startswith("- ["):
            if line == "- [":
                block = ["["]
                continue
            if match := inline_re.search(line):
                add_entry(match.group(1), match.group(2), match.group(3), match.group(4))
    return textures


def resolve_texture_metadata(symbol, textures):
    if symbol in textures:
        return dict(textures[symbol])
    for key, entry in textures.items():
        prefix = re.sub(r"_[a-z0-9]+__png$", "", key)
        if symbol.startswith(prefix) and symbol.endswith("__png"):
            return dict(entry, symbol=symbol, yamlSymbol=key, fuzzyMatch=True)
    return {
        "symbol": symbol,
        "resolved": False,
    }

def segment_for_symbol(symbol):
    match = SEGMENT_SYMBOL_RE.match(symbol)
    if not match:
        return None
    segment_id = int(match.group(1), 16)
    return {
        "id": segment_id,
        "hex": f"0x{segment_id:02X}",
        "label": SEGMENT_LABELS.get(segment_id, f"segment {segment_id}"),
    }


def merge_segments(segments):
    unique = {}
    for segment in segments:
        if segment:
            unique.setdefault(segment["id"], segment)
    return [unique[key] for key in sorted(unique)]


def object_availability(entry, names_by_id, metadata_by_name, asset_availability):
    names = object_names(entry, names_by_id)
    metadata = {}
    for name in names:
        if name in metadata_by_name:
            metadata[name] = metadata_by_name[name]

    primary = None
    if entry["idToken"] in metadata:
        primary = metadata[entry["idToken"]]
    elif names:
        primary = metadata.get(names[0])

    if primary is None:
        primary = {
            "scope": "unknown",
            "label": "Unknown",
            "shortLabel": "Unknown",
            "source": "object table token",
        }

    result = merge_availability(asset_availability, primary)
    result["aliases"] = metadata
    if len({item.get("scope") for item in metadata.values()}) > 1:
        result["ambiguousAliases"] = True
    return result


def object_names(entry, names_by_id):
    names = list(names_by_id.get(entry["id"], []))
    if not names and entry["idToken"] != str(entry["id"]):
        names.append(entry["idToken"])
    if not names:
        names.append(default_object_name(entry["id"]))
    if entry["idToken"] not in names and entry["idToken"] != str(entry["id"]):
        names.append(entry["idToken"])
    return names

def build_symbol_index(root):
    symbols = {}
    symbol_re = re.compile(r"^\s*(?:const\s+)?(?:Gfx|Vtx)\s+(\w+)\s*\[", re.M)
    for path in root.glob("*.c"):
        text = path.read_text(errors="replace")
        for symbol in symbol_re.findall(text):
            symbols.setdefault(symbol, path)
    return symbols


def parse_object_table(defines):
    text = strip_comments(OBJECTS_PATH.read_text())
    entries = []
    for index, raw_entry in enumerate(extract_initializer_entries(text, "D_803A8528_7B9BD8")):
        fields = split_top_level_csv(raw_entry)
        if len(fields) < 43:
            continue
        object_id = parse_object_id_token(fields[0], defines, index)
        if object_id is None:
            continue
        display_lists = [field if field not in ("0", "NULL") else None for field in fields[2:5]]
        scale_override = (parse_int_token(fields[32], defines) << 8) | parse_int_token(fields[33], defines)
        runtime_scale = scale_override or 0x800
        entries.append({
            "index": index,
            "id": object_id,
            "idToken": fields[0],
            "type": parse_int_token(fields[1], defines),
            "renderType": parse_int_token(fields[1], defines) & 0xFF,
            "displayLists": display_lists,
            "billboardSetIndex": parse_int_token(fields[6], defines),
            "collisionIndex": parse_int_token(fields[10], defines),
            "scale": {
                "override": scale_override,
                "runtime": runtime_scale,
                "factor": runtime_scale / 0x800,
            },
            "bounds": {
                "widthRadius": parse_int_token(fields[34], defines),
                "depthRadius": parse_int_token(fields[35], defines),
                "height": parse_int_token(fields[38], defines),
            },
            "rawFields": fields,
        })
    return entries


def extract_plain_array_values(text, symbol):
    match = re.search(rf"\b{re.escape(symbol)}\s*\[[^\]]*\]\s*=\s*\{{(.*?)\}};", text, re.S)
    if not match:
        return []
    return split_top_level_csv(strip_comments(match.group(1)))


def iter_c_calls(text, name):
    needle = f"{name}("
    start = 0
    while True:
        call_start = text.find(needle, start)
        if call_start < 0:
            return
        args_start = call_start + len(needle)
        depth = 1
        index = args_start
        while index < len(text) and depth:
            ch = text[index]
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            index += 1
        if depth == 0:
            yield text[args_start:index - 1], text.count("\n", 0, call_start) + 1
        start = index


def source_condition_before(text, call_start_line):
    lines = text.splitlines()
    index = call_start_line - 1
    line = lines[index].strip() if 0 <= index < len(lines) else ""
    prefix = line.split("func_802C78B0_6D8F60", 1)[0].strip()
    if prefix.startswith("if "):
        return prefix.rstrip("{").strip()
    prev = lines[index - 1].strip() if index > 0 else ""
    if prev.startswith("if ") and prev.endswith("{"):
        return prev[:-1].strip()
    return None


def source_section(text, anchor=None):
    if not anchor:
        return text, 1
    if anchor.startswith("//"):
        match = re.search(rf"^\s*{re.escape(anchor)}\s*$", text, re.M)
        if not match:
            return text, 1
        start = match.start()
    else:
        start = text.find(anchor)
        if start < 0:
            return text, 1
    section_start_line = text.count("\n", 0, start) + 1
    next_section = re.search(r"^//\s+[A-Z0-9_ ]+\s*$", text[start + len(anchor):], re.M)
    if next_section:
        end = start + len(anchor) + next_section.start()
        return text[start:end], section_start_line
    return text[start:], section_start_line


def extract_render_calls_from_source(path, anchor=None):
    if not path.exists():
        return [], [f"missing animal source {path.relative_to(REPO_ROOT)}"]
    full_text = path.read_text(errors="replace")
    text, line_offset = source_section(full_text, anchor)
    calls = []
    warnings = []
    for args_text, line_no in iter_c_calls(text, "func_802C78B0_6D8F60"):
        source_line = line_no + line_offset - 1
        fields = split_top_level_csv(args_text)
        if len(fields) != 10:
            warnings.append(f"{path.relative_to(REPO_ROOT)}:{source_line}: expected 10 render-call args, got {len(fields)}")
            continue
        display_list = fields[9].strip()
        if display_list.startswith("&"):
            display_list = display_list[1:].strip()
        joint0 = parse_literal_int_token(fields[0])
        joint1 = parse_literal_int_token(fields[1])
        center_scale = parse_literal_int_token(fields[5])
        roll = parse_literal_int_token(fields[6])
        mirror = parse_literal_int_token(fields[7])
        orientation_mode = parse_literal_int_token(fields[8])
        call = {
            "line": source_line,
            "joint0": joint0,
            "joint1": joint1,
            "joint0Expr": fields[0],
            "joint1Expr": fields[1],
            "scaleXExpr": fields[2],
            "scaleZExpr": fields[3],
            "scaleYExpr": fields[4],
            "centerScale": center_scale,
            "roll": roll,
            "mirror": mirror,
            "orientationMode": orientation_mode,
            "centerScaleExpr": fields[5],
            "rollExpr": fields[6],
            "mirrorExpr": fields[7],
            "orientationModeExpr": fields[8],
            "displayList": display_list,
            "condition": source_condition_before(text, line_no),
        }
        if not DISPLAY_LIST_SYMBOL_RE.match(display_list):
            call["unresolvedDisplayListExpr"] = fields[9]
        calls.append(call)
    return calls, warnings


def unique_display_lists_from_calls(calls):
    seen = set()
    result = []
    for call in calls:
        symbol = call.get("displayList")
        if not symbol or symbol in seen or not DISPLAY_LIST_SYMBOL_RE.match(symbol):
            continue
        seen.add(symbol)
        result.append(symbol)
    return result


def read_billboard_sets(path):
    text = path.read_text()
    pointer_symbols = [
        token.strip()
        for token in extract_plain_array_values(text, BILLBOARD_TABLE_SYMBOL)
        if token.strip()
    ]
    sets = []
    for index, symbol in enumerate(pointer_symbols):
        values = extract_plain_array_values(text, symbol)
        billboards = []
        for offset in range(0, len(values), 5):
            first = values[offset].strip() if offset < len(values) else ""
            if not first:
                continue
            if parse_s16_token(first) == 9999:
                break
            if offset + 4 >= len(values):
                break
            x, z, y, size, category = (
                parse_s16_token(values[offset + i])
                for i in range(5)
            )
            billboards.append({
                "x": x,
                "z": z,
                "y": y,
                "size": size,
                "category": category,
            })
        sets.append({
            "index": index,
            "symbol": symbol,
            "billboards": billboards,
        })
    return sets


def vertex_offset(symbol):
    if symbol.startswith("0x"):
        return int(symbol, 16)
    match = re.search(r"_([0-9A-Fa-f]+)$", symbol)
    if match:
        return int(match.group(1), 16)
    return None


def tri(v0, v1, v2, flag):
    if flag == 0:
        return [v0, v1, v2]
    if flag == 1:
        return [v1, v2, v0]
    return [v2, v0, v1]


def quad(v0, v1, v2, v3, flag):
    if flag == 0:
        return [v0, v1, v2], [v0, v2, v3]
    if flag == 1:
        return [v1, v2, v3], [v1, v3, v0]
    if flag == 2:
        return [v2, v3, v0], [v2, v0, v1]
    return [v3, v0, v1], [v3, v1, v2]


def parse_vtx_include(path):
    vertices = []
    if not path.exists():
        return vertices, [f"missing vertex include {path.relative_to(REPO_ROOT)}"]
    warnings = []
    for line in path.read_text(errors="replace").splitlines():
        match = VERTEX_RE.match(line)
        if not match:
            continue
        x, y, z, u, v, r, g, b, a = (int(value) for value in match.groups())
        vertices.append((x, y, z, u, v, r, g, b, a))
    return vertices, warnings


def parse_display_list_source(path):
    text = path.read_text(errors="replace")
    lines = text.splitlines()
    vertices = []
    warnings = []
    for line in lines:
        match = re.match(r'\s*#include\s+"(.*\.inc\.c)"', line)
        if not match:
            continue
        included, include_warnings = parse_vtx_include(REPO_ROOT / "src.us" / match.group(1))
        vertices.extend(included)
        warnings.extend(include_warnings)
    return lines, vertices, warnings


def parse_display_list_mesh(path, textures=None, scale=1 / 32.0, origin_offset=(0.0, 0.0, 0.0)):
    lines, vertices, warnings = parse_display_list_source(path)
    textures = textures or {}
    vertex_offsets = {}
    for line in lines:
        match = SP_VERTEX_RE.match(line)
        if not match:
            continue
        symbol = match.group(1)
        offset = vertex_offset(symbol)
        if offset is None:
            warnings.append(f"could not derive vertex offset from {symbol}")
            offset = 0
        vertex_offsets[symbol] = offset

    if not vertex_offsets:
        return empty_mesh(), [], warnings

    vtx_offset_start = min(vertex_offsets.values())
    current_offset = 0
    current_color = None
    current_texture = None
    texture_enabled = False
    colors = {}
    triangle_groups = []
    batch_groups = []

    def texture_key(texture):
        if not texture or not texture_enabled:
            return None
        return texture.get("symbol")

    def add_triangle_group(group):
        if not group:
            return
        triangle_groups.append(group)
        key = texture_key(current_texture)
        if not batch_groups or batch_groups[-1]["textureKey"] != key:
            batch_groups.append({
                "textureKey": key,
                "texture": current_texture if key else None,
                "groups": [],
            })
        batch_groups[-1]["groups"].append(group)

    for line in lines:
        tri1 = tri2 = None
        if match := SP_1_TRI_RE.match(line):
            tri1 = tri(*(int(value) for value in match.groups()))
        elif match := SP_2_TRI_RE.match(line):
            values = [int(value) for value in match.groups()]
            tri1 = tri(*values[:4])
            tri2 = tri(*values[4:])
        elif match := SP_QUAD_RE.match(line):
            values = [int(value) for value in match.groups()]
            tri1, tri2 = quad(*values)
        elif match := SP_VERTEX_RE.match(line):
            current_offset = (vertex_offsets[match.group(1)] - vtx_offset_start) // 16
        elif match := PRIM_COLOR_RE.match(line):
            r, g, b, _a = (int(value, 0) for value in match.groups())
            current_color = (r, g, b)
        elif match := TEXTURE_IMAGE_RE.match(line):
            fmt, size, width, symbol = match.groups()
            current_texture = resolve_texture_metadata(symbol, textures)
            current_texture["displayFormat"] = fmt
            current_texture["displaySize"] = size
            parsed_width = eval_simple_expr(width)
            if parsed_width is not None:
                current_texture.setdefault("width", parsed_width)
        elif match := TEXTURE_TILE_SIZE_RE.match(line):
            if current_texture:
                _tile, _uls, _ult, lrs, lrt = match.groups()
                parsed_lrs = eval_simple_expr(lrs)
                parsed_lrt = eval_simple_expr(lrt)
                if parsed_lrs is not None and parsed_lrt is not None:
                    current_texture.setdefault("tileWidth", (parsed_lrs // 4) + 1)
                    current_texture.setdefault("tileHeight", (parsed_lrt // 4) + 1)
        elif match := SP_TEXTURE_RE.match(line):
            texture_enabled = match.group(5) == "G_ON"

        if tri1 is None:
            continue

        group = []
        for triangle in (tri1, tri2):
            if triangle is None:
                continue
            indices = [current_offset + idx for idx in triangle]
            group.append(indices)
            if current_color is not None:
                for idx in indices:
                    colors[idx] = current_color
        add_triangle_group(group)

    mesh = mesh_from_vertices(vertices, triangle_groups, colors, scale, origin_offset)
    batches = []
    for batch in batch_groups:
        batches.append({
            "texture": batch["texture"],
            "mesh": mesh_from_vertices(vertices, batch["groups"], colors, scale, origin_offset, batch["texture"]),
        })
    if not batches and mesh["indices"]:
        batches.append({"texture": None, "mesh": mesh})
    return mesh, batches, warnings


def empty_mesh():
    return {
        "positions": [],
        "colors": [],
        "normals": [],
        "uvs": [],
        "indices": [],
        "stats": {"vertices": 0, "triangles": 0},
    }


def signed_vertex_byte(value):
    return value - 256 if value > 127 else value


def vertex_normal(r, g, b):
    # N64 Vtx cn bytes are color when lighting is off, and normal+alpha when
    # lighting is on. Export both interpretations; viewers choose by material.
    nx = signed_vertex_byte(r)
    ny = signed_vertex_byte(g)
    nz = signed_vertex_byte(b)
    length = math.sqrt((nx * nx) + (ny * ny) + (nz * nz))
    if not length:
        return (0.0, 1.0, 0.0)

    # SSSV object vertices are exported with game x/z/y mapped to Three x/y/z.
    return (nx / length, nz / length, ny / length)


def mesh_from_vertices(vertices, triangle_groups, override_colors, scale, origin_offset, texture=None):
    positions = []
    colors = []
    normals = []
    uvs = []
    indices = []
    for i, vertex in enumerate(vertices):
        x, y, z, u, v, r, g, b, a = vertex
        normals.extend(vertex_normal(r, g, b))
        if i in override_colors:
            r, g, b = override_colors[i]
        # SSSV display-list object vertices use the game's x/z/y convention.
        # Three.js uses Y-up, so local vertex Z becomes browser Y.
        positions.extend([
            (x * scale) + origin_offset[0],
            (z * scale) + origin_offset[1],
            (y * scale) + origin_offset[2],
        ])
        colors.extend([r / 255.0, g / 255.0, b / 255.0, a / 255.0])
        if texture and texture.get("width") and texture.get("height"):
            uvs.extend([u / (32.0 * texture["width"]), 1.0 - (v / (32.0 * texture["height"]))])
        else:
            uvs.extend([u, v])

    for group in triangle_groups:
        for triangle in group:
            indices.extend(triangle)

    return {
        "positions": positions,
        "colors": colors,
        "normals": normals,
        "uvs": uvs,
        "indices": indices,
        "stats": {
            "vertices": len(vertices),
            "triangles": len(indices) // 3,
        },
    }


def vector_sub(a, b):
    return (a[0] - b[0], a[1] - b[1], a[2] - b[2])


def vector_add(a, b):
    return (a[0] + b[0], a[1] + b[1], a[2] + b[2])


def vector_mul(a, scalar):
    return (a[0] * scalar, a[1] * scalar, a[2] * scalar)


def vector_dot(a, b):
    return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2])


def vector_cross(a, b):
    return (
        (a[1] * b[2]) - (a[2] * b[1]),
        (a[2] * b[0]) - (a[0] * b[2]),
        (a[0] * b[1]) - (a[1] * b[0]),
    )


def vector_length(a):
    return math.sqrt(vector_dot(a, a))


def vector_normalize(a, fallback=(1.0, 0.0, 0.0)):
    length = vector_length(a)
    if length <= 0.000001:
        return fallback
    return (a[0] / length, a[1] / length, a[2] / length)


def animal_joint_to_viewer(point, scale):
    # LimbConfig stores game x/z/y. The viewers use Three's x/y/z with game y as up.
    return (point[0] * scale, point[2] * scale, point[1] * scale)


def animal_part_basis(joint0, joint1, mirror=False, flip_up=False):
    x_axis = vector_normalize(vector_sub(joint1, joint0))
    up = (0.0, 1.0, 0.0)
    if abs(vector_dot(x_axis, up)) > 0.96:
        up = (1.0, 0.0, 0.0)
    z_axis = vector_normalize(vector_cross(x_axis, up), (0.0, 0.0, 1.0))
    y_axis = vector_normalize(vector_cross(z_axis, x_axis), up)
    if flip_up:
        y_axis = vector_mul(y_axis, -1.0)
    if mirror:
        z_axis = vector_mul(z_axis, -1.0)
    return x_axis, y_axis, z_axis


def game_axis_to_viewer(axis):
    return (axis[0], axis[2], axis[1])


def animal_part_game_basis(raw_joint0, raw_joint1, mirror=0, orientation_mode=0, flip_up=False):
    dx = raw_joint1[0] - raw_joint0[0]
    dz = raw_joint1[1] - raw_joint0[1]
    dy = raw_joint1[2] - raw_joint0[2]

    if dx == 0 and dz == 0:
        if orientation_mode == 1:
            side = (0.0, 1.0, 0.0)
            up = (1.0, 0.0, 0.0)
        else:
            side = (1.0, 0.0, 0.0)
            up = (0.0, -1.0, 0.0)
    else:
        side = (float(dz), float(-dx), 0.0)
        if orientation_mode == 1:
            if side[1] < 0:
                side = (-float(dz), -side[1], 0.0)
        elif dz < 0:
            side = (-float(dz), -side[1], 0.0)
        up = (
            (side[1] * dy) / -256.0,
            (dy * side[0]) / 256.0,
            ((dx * side[1]) - (dz * side[0])) / 256.0,
        )
        if vector_length(up) <= 0.000001:
            up = (0.0, 0.0, 1.0)

    if mirror in (1, 3):
        side = vector_mul(side, -1.0)
    if mirror in (2, 3):
        up = vector_mul(up, -1.0)
    if flip_up:
        up = vector_mul(up, -1.0)

    x_axis = vector_normalize(game_axis_to_viewer((dx, dz, dy)))
    y_axis = vector_normalize(game_axis_to_viewer(up))
    z_axis = vector_normalize(game_axis_to_viewer(side))
    return x_axis, y_axis, z_axis


def rotate_side_up_axes(side_axis, up_axis, roll):
    if not roll:
        return side_axis, up_axis
    sin_roll = trig_index256(roll, math.sin) / 256.0
    cos_roll = trig_index256(roll, math.cos) / 256.0
    rotated_side = vector_add(vector_mul(up_axis, sin_roll), vector_mul(side_axis, cos_roll))
    rotated_up = vector_sub(vector_mul(up_axis, cos_roll), vector_mul(side_axis, sin_roll))
    return vector_normalize(rotated_side), vector_normalize(rotated_up)


def animal_part_runtime_frame(
    joint0,
    joint1,
    raw_joint0,
    raw_joint1,
    part_scale=(1.0, 1.0, 1.0),
    render_mirror=0,
    orientation_mode=0,
    flip_up=False,
    center_scale=0,
    roll=0,
    scale=1.0 / 32.0,
):
    midpoint_raw = (
        (raw_joint0[0] + raw_joint1[0]) / 2.0,
        (raw_joint0[1] + raw_joint1[1]) / 2.0,
        (raw_joint0[2] + raw_joint1[2]) / 2.0,
    )
    centered_raw = (
        midpoint_raw[0] * (1.0 + (center_scale / 16.0)),
        midpoint_raw[1] * (1.0 + (center_scale / 16.0)),
        midpoint_raw[2] * (1.0 + (center_scale / 8.0)),
    )
    midpoint = animal_joint_to_viewer(centered_raw, scale)

    x_axis, y_axis, z_axis = animal_part_game_basis(raw_joint0, raw_joint1, render_mirror, orientation_mode, flip_up)
    z_axis, y_axis = rotate_side_up_axes(z_axis, y_axis, roll)
    x_axis = vector_mul(x_axis, part_scale[0])
    y_axis = vector_mul(y_axis, part_scale[1])
    z_axis = vector_mul(z_axis, part_scale[2])
    return midpoint, x_axis, y_axis, z_axis


def transform_mesh_to_animal_part(
    mesh,
    joint0,
    joint1,
    mirror=False,
    flip_up=False,
    part_scale=(1.0, 1.0, 1.0),
    raw_joint0=None,
    raw_joint1=None,
    transform_mode="viewer",
    render_mirror=0,
    orientation_mode=0,
    center_scale=0,
    roll=0,
    scale=1.0 / 32.0,
):
    if transform_mode in {"gameMatrix", "sceneMatrix"} and raw_joint0 is not None and raw_joint1 is not None:
        midpoint, x_axis, y_axis, z_axis = animal_part_runtime_frame(
            joint0,
            joint1,
            raw_joint0,
            raw_joint1,
            part_scale,
            render_mirror,
            orientation_mode,
            flip_up,
            center_scale,
            roll,
            scale,
        )
    else:
        midpoint = vector_mul(vector_add(joint0, joint1), 0.5)
        x_axis, y_axis, z_axis = animal_part_basis(joint0, joint1, mirror, flip_up)
        x_axis = vector_mul(x_axis, part_scale[0])
        y_axis = vector_mul(y_axis, part_scale[1])
        z_axis = vector_mul(z_axis, part_scale[2])
    positions = []
    source = mesh.get("positions") or []
    for index in range(0, len(source), 3):
        local = (source[index], source[index + 1], source[index + 2])
        world = vector_add(
            midpoint,
            vector_add(
                vector_add(vector_mul(x_axis, local[0]), vector_mul(y_axis, local[1])),
                vector_mul(z_axis, local[2]),
            ),
        )
        positions.extend(world)

    normals = []
    source_normals = mesh.get("normals") or []
    for index in range(0, len(source_normals), 3):
        local = (source_normals[index], source_normals[index + 1], source_normals[index + 2])
        world = vector_normalize(vector_add(
            vector_add(vector_mul(x_axis, local[0]), vector_mul(y_axis, local[1])),
            vector_mul(z_axis, local[2]),
        ))
        normals.extend(world)

    return {
        **mesh,
        "positions": positions,
        "normals": normals,
    }


def animal_part_matrix(
    joint0,
    joint1,
    mirror=False,
    flip_up=False,
    part_scale=(1.0, 1.0, 1.0),
    raw_joint0=None,
    raw_joint1=None,
    transform_mode="viewer",
    render_mirror=0,
    orientation_mode=0,
    center_scale=0,
    roll=0,
    scale=1.0 / 32.0,
):
    if transform_mode in {"gameMatrix", "sceneMatrix"} and raw_joint0 is not None and raw_joint1 is not None:
        midpoint, x_axis, y_axis, z_axis = animal_part_runtime_frame(
            joint0,
            joint1,
            raw_joint0,
            raw_joint1,
            part_scale,
            render_mirror,
            orientation_mode,
            flip_up,
            center_scale,
            roll,
            scale,
        )
    else:
        midpoint = vector_mul(vector_add(joint0, joint1), 0.5)
        x_axis, y_axis, z_axis = animal_part_basis(joint0, joint1, mirror, flip_up)
        x_axis = vector_mul(x_axis, part_scale[0])
        y_axis = vector_mul(y_axis, part_scale[1])
        z_axis = vector_mul(z_axis, part_scale[2])
    return [
        x_axis[0], x_axis[1], x_axis[2], 0.0,
        y_axis[0], y_axis[1], y_axis[2], 0.0,
        z_axis[0], z_axis[1], z_axis[2], 0.0,
        midpoint[0], midpoint[1], midpoint[2], 1.0,
    ]


def mesh_bounds(mesh):
    positions = mesh.get("positions") or []
    if not positions:
        return None
    xs = positions[0::3]
    ys = positions[1::3]
    zs = positions[2::3]
    return {
        "min": [min(xs), min(ys), min(zs)],
        "max": [max(xs), max(ys), max(zs)],
    }


def merge_bounds(bounds):
    bounds = [item for item in bounds if item]
    if not bounds:
        return None
    return {
        "min": [min(item["min"][axis] for item in bounds) for axis in range(3)],
        "max": [max(item["max"][axis] for item in bounds) for axis in range(3)],
    }


def object_matches(entry, requested):
    if not requested:
        return True
    wanted = {value.upper() for value in requested}
    aliases = {entry["idToken"].upper(), default_object_name(entry["id"]).upper()}
    return (
        str(entry["id"]) in wanted
        or bool(aliases & wanted)
    )


def animal_matches(entry, requested):
    if not requested:
        return True
    wanted = {value.upper() for value in requested}
    return str(entry["id"]) in wanted or entry["name"].upper() in wanted


def animal_part_scale(part_spec):
    scale = part_spec.get("partScale", 1.0)
    if isinstance(scale, (int, float)):
        return (float(scale), float(scale), float(scale))
    if len(scale) != 3:
        return (1.0, 1.0, 1.0)
    return tuple(float(value) for value in scale)


def render_call_scale(call):
    if not call:
        return None
    # Runtime argument order is X/Z/Y in game space.  Meshes have already been
    # converted to viewer X/Y/Z, so the local scale tuple becomes X/Y/Z.
    scale_x = evaluate_fixed_scale_expr(call.get("scaleXExpr", ""))
    scale_z = evaluate_fixed_scale_expr(call.get("scaleZExpr", ""))
    scale_y = evaluate_fixed_scale_expr(call.get("scaleYExpr", ""))
    if scale_x is None or scale_y is None or scale_z is None:
        return None
    return (scale_x, scale_y, scale_z)


def render_call_center_scale(call):
    if not call:
        return 0
    if call.get("centerScale") is not None:
        return call["centerScale"]
    expr = call.get("centerScaleExpr")
    if expr == "D_803F2ED0":
        return 0
    value = parse_literal_int_token(expr or "")
    return value or 0


def render_call_roll(call):
    if not call:
        return 0
    if call.get("roll") is not None:
        return call["roll"]
    value = parse_literal_int_token(call.get("rollExpr") or "")
    return value or 0


def combine_part_scales(*scales):
    result = (1.0, 1.0, 1.0)
    for scale in scales:
        if scale is None:
            continue
        result = (
            result[0] * scale[0],
            result[1] * scale[1],
            result[2] * scale[2],
        )
    return result


def render_call_for_part(render_calls, part_spec, mirror):
    fallback = None
    for call in render_calls:
        if call.get("displayList") != part_spec["displayList"]:
            continue
        if call.get("joint0") != part_spec["joint0"] or call.get("joint1") != part_spec["joint1"]:
            continue
        if fallback is None:
            fallback = call
        render_mirror = call.get("mirror")
        if render_mirror is not None and bool(render_mirror) == bool(mirror):
            return call
    return fallback


def c_div(numerator, denominator):
    if denominator == 0:
        return 0
    return int(numerator / denominator)


def trig_index256(angle_index, fn):
    return int(round(fn((angle_index & 0xFF) * math.tau / 256.0) * 256))


def source_animation_pose_from_frame(entry, base_joints):
    pose = entry.get("sourcePose") or {}
    path = REPO_ROOT / pose.get("header", entry["source"])
    parents = read_numeric_array(path, pose["parents"])
    children = read_numeric_array(path, pose["children"])
    lengths = read_numeric_array(path, pose["lengths"])
    frame_symbol = pose["frame"]
    frame = read_numeric_array(path, frame_symbol)

    if len(frame) < 3:
        raise ValueError(f"animation frame {frame_symbol} has no root position")

    joints = {int(index): list(point) for index, point in base_joints.items()}
    joints[0] = frame[:3]
    frame_cursor = 3
    applied_bones = []
    for index in range(min(len(parents), len(children), len(lengths))):
        parent = parents[index]
        child = children[index]
        if parent == child:
            break
        if frame_cursor + 1 >= len(frame):
            break
        if parent not in joints:
            frame_cursor += 2
            continue

        yaw = frame[frame_cursor]
        pitch = frame[frame_cursor + 1]
        frame_cursor += 2
        length = lengths[index]

        horizontal = c_div(trig_index256(yaw, math.sin) * length, 256)
        delta_y = c_div(trig_index256(yaw, math.cos) * length, 256)
        delta_x = c_div(trig_index256(pitch, math.sin) * horizontal, 256)
        delta_z = c_div(trig_index256(pitch, math.cos) * horizontal, 256)

        source = joints[parent]
        joints[child] = [
            source[0] + delta_x,
            source[1] + delta_z,
            source[2] + delta_y,
        ]
        applied_bones.append(f"{parent}->{child}")

    return joints, {
        "type": pose["type"],
        "header": pose.get("header", entry["source"]),
        "parents": pose["parents"],
        "children": pose["children"],
        "lengths": pose["lengths"],
        "frame": frame_symbol,
        "function": "func_802DB670_6ECD20/func_802DB494_6ECB44",
        "appliedBones": applied_bones,
        "note": "Root plus yaw/pitch/length bones mirrored from the runtime animation-frame pose path.",
    }


def source_pose_joints(entry, warnings, base_joints=None):
    pose = entry.get("sourcePose")
    if not pose:
        return None, None
    if pose.get("apply") is False:
        return None, {
            "type": pose.get("type"),
            "applied": False,
            "note": pose.get("note", "Reference only; viewer placement uses the curated neutral rig."),
        }
    if pose.get("type") == "animation-frame":
        try:
            return source_animation_pose_from_frame(entry, base_joints or entry["joints"])
        except (KeyError, ValueError) as exc:
            warnings.append(f"animal {entry['name']}: could not mirror source animation frame: {exc}")
            return None, None
    warnings.append(f"animal {entry['name']}: unsupported source pose {pose.get('type')}")
    return None, None


def export_animals(requested, symbol_index, yaml_data_segments, texture_entries, warnings, referenced_textures):
    animal_defines = read_simple_defines(ANIMALS_HEADER)
    animals = []
    for rig in STATIC_ANIMAL_RIGS:
        animal_id = animal_defines.get(rig["name"], rig["id"])
        entry = {**rig, "id": animal_id}
        if not animal_matches(entry, requested):
            continue

        source_path = REPO_ROOT / entry["source"]
        render_calls, render_call_warnings = extract_render_calls_from_source(source_path, entry.get("sourceAnchor"))
        warnings.extend(f"animal {entry['name']}: {warning}" for warning in render_call_warnings)
        extracted_display_lists = unique_display_lists_from_calls(render_calls)
        placed_display_lists = {
            part["displayList"]
            for part in entry["parts"]
        }
        unplaced_display_lists = [
            symbol
            for symbol in extracted_display_lists
            if symbol not in placed_display_lists
        ]

        raw_joints = dict(entry["joints"])
        source_joints, source_pose = source_pose_joints(entry, warnings, raw_joints)
        if source_joints:
            raw_joints.update(source_joints)

        scale = entry.get("scale", 1.0 / 32.0)
        joints = {
            int(index): animal_joint_to_viewer(point, scale)
            for index, point in raw_joints.items()
        }
        raw_joints = {int(index): point for index, point in raw_joints.items()}
        parts = []
        asset_segments = []
        part_bounds = []
        for slot, part_spec in enumerate(entry["parts"], start=1):
            symbol = part_spec["displayList"]
            asset_segment = segment_for_symbol(symbol)
            asset_segments.append(asset_segment)
            path = symbol_index.get(symbol)
            if path is None:
                warnings.append(f"animal {entry['name']} part {slot}: unresolved symbol {symbol}")
                continue
            source_key = yaml_data_key_for_path(path)
            source_segment = yaml_data_segments.get(source_key)
            source_availability = classify_yaml_segment(source_segment)
            if source_availability is None:
                warnings.append(f"animal {entry['name']} part {slot} {symbol}: no sssv.us.yaml segment for {source_key}")

            joint0 = joints.get(part_spec["joint0"])
            joint1 = joints.get(part_spec["joint1"])
            if joint0 is None or joint1 is None:
                warnings.append(f"animal {entry['name']} part {slot} {symbol}: missing rig joint")
                continue

            mesh, batches, mesh_warnings = parse_display_list_mesh(path, textures=texture_entries, scale=scale)
            warnings.extend(
                f"animal {entry['name']} part {slot} {symbol}: {warning}"
                for warning in mesh_warnings
            )
            mirror = bool(part_spec.get("mirror"))
            flip_up = bool(part_spec.get("flipUp"))
            render_call = render_call_for_part(render_calls, part_spec, mirror)
            manual_part_scale = animal_part_scale(part_spec)
            render_scale = render_call_scale(render_call)
            part_scale = combine_part_scales(manual_part_scale, render_scale)
            render_mirror = render_call.get("mirror") if render_call and render_call.get("mirror") is not None else int(mirror)
            orientation_mode = render_call.get("orientationMode") if render_call and render_call.get("orientationMode") is not None else int(part_spec.get("orientationMode", 0))
            center_scale = render_call_center_scale(render_call)
            roll = render_call_roll(render_call)
            transform_mode = part_spec.get("transform") or entry.get("transform") or "gameMatrix"
            transform_args = {
                "mirror": mirror,
                "flip_up": flip_up,
                "part_scale": part_scale,
                "raw_joint0": raw_joints.get(part_spec["joint0"]),
                "raw_joint1": raw_joints.get(part_spec["joint1"]),
                "transform_mode": transform_mode,
                "render_mirror": render_mirror,
                "orientation_mode": orientation_mode,
                "center_scale": center_scale,
                "roll": roll,
                "scale": scale,
            }
            part_matrix = animal_part_matrix(joint0, joint1, **transform_args)
            bounds_mesh = transform_mesh_to_animal_part(mesh, joint0, joint1, **transform_args)
            export_mesh = mesh if transform_mode == "sceneMatrix" else bounds_mesh
            transformed_batches = []
            for batch in batches:
                texture = batch.get("texture")
                if texture:
                    referenced_textures.setdefault(texture["symbol"], texture)
                    if not texture.get("url"):
                        warnings.append(f"animal {entry['name']} part {slot} {symbol}: texture {texture['symbol']} has no exported PNG")
                    if texture.get("resolved") is False:
                        warnings.append(f"animal {entry['name']} part {slot} {symbol}: texture {texture['symbol']} not found in sssv.us.yaml")
                transformed_batches.append({
                    **batch,
                    "mesh": batch["mesh"] if transform_mode == "sceneMatrix" else transform_mesh_to_animal_part(batch["mesh"], joint0, joint1, **transform_args),
                })
            if not transformed_batches and export_mesh["indices"]:
                transformed_batches.append({"texture": None, "mesh": export_mesh})

            bounds = mesh_bounds(bounds_mesh)
            part_bounds.append(bounds)
            parts.append({
                "slot": slot,
                "name": part_spec.get("name"),
                "displayList": symbol,
                "assetSegment": asset_segment,
                "sourceSegment": source_segment,
                "sourceAvailability": source_availability,
                "source": path.relative_to(REPO_ROOT).as_posix(),
                "joint0": part_spec["joint0"],
                "joint1": part_spec["joint1"],
                "mirror": mirror,
                "flipUp": flip_up,
                "transform": transform_mode,
                "matrix": part_matrix if transform_mode == "sceneMatrix" else None,
                "centerScale": center_scale,
                "roll": roll,
                "renderMirror": render_mirror,
                "orientationMode": orientation_mode,
                "centerScaleExpr": render_call.get("centerScaleExpr") if render_call else None,
                "rollExpr": render_call.get("rollExpr") if render_call else None,
                "renderScale": list(render_scale) if render_scale else None,
                "manualPartScale": list(manual_part_scale),
                "partScale": list(part_scale),
                "mesh": export_mesh,
                "batches": transformed_batches,
                "bounds": bounds,
            })

        bounds = merge_bounds(part_bounds)
        animals.append({
            "index": 10000 + animal_id,
            "kind": "animal",
            "id": animal_id,
            "name": entry["name"],
            "aliases": [entry["name"]],
            "idToken": entry["name"],
            "availability": {
                "scope": "animal",
                "label": "Animal",
                "shortLabel": "Animal",
                "source": entry["source"],
            },
            "assetSegments": merge_segments(asset_segments),
            "scale": {"factor": 1.0},
            "bounds3": bounds,
            "parts": parts,
            "rig": {
                "source": entry["source"],
                "sourceAnchor": entry.get("sourceAnchor"),
                "joints": {str(index): list(point) for index, point in joints.items()},
                "sourceRenderCalls": render_calls,
                "sourceDisplayLists": extracted_display_lists,
                "placedDisplayLists": sorted(placed_display_lists),
                "unplacedDisplayLists": unplaced_display_lists,
                "sourcePose": source_pose,
                "note": "Static neutral pose approximation; animation is not exported.",
            },
        })
    return animals


def dump_animal_part_stubs(requested):
    animal_defines = read_simple_defines(ANIMALS_HEADER)
    output = []
    warnings = []
    for rig in STATIC_ANIMAL_RIGS:
        animal_id = animal_defines.get(rig["name"], rig["id"])
        entry = {**rig, "id": animal_id}
        if not animal_matches(entry, requested):
            continue
        calls, call_warnings = extract_render_calls_from_source(REPO_ROOT / entry["source"], entry.get("sourceAnchor"))
        warnings.extend(call_warnings)
        parts = []
        seen = set()
        for call in calls:
            symbol = call.get("displayList")
            if not DISPLAY_LIST_SYMBOL_RE.match(symbol or ""):
                continue
            key = (call["joint0"], call["joint1"], symbol)
            if key in seen:
                continue
            seen.add(key)
            part = {
                "joint0": call["joint0"],
                "joint1": call["joint1"],
                "displayList": symbol,
                "sourceLine": call["line"],
            }
            if call.get("condition"):
                part["condition"] = call["condition"]
            if call.get("centerScale") is not None:
                part["centerScale"] = call["centerScale"]
            if call.get("roll") is not None:
                part["roll"] = call["roll"]
            if call.get("mirror"):
                part["mirror"] = call["mirror"]
            if call.get("orientationMode"):
                part["orientationMode"] = call["orientationMode"]
            parts.append(part)
        output.append({
            "id": animal_id,
            "name": entry["name"],
            "source": entry["source"],
            "sourceAnchor": entry.get("sourceAnchor"),
            "parts": parts,
        })
    return {
        "kind": "animal-render-call-stubs",
        "animals": output,
        "warnings": warnings,
    }


def export_objects(requested, output_path):
    defines, names_by_id, metadata_by_name = read_object_defines(OBJECTS_HEADER)
    objects = parse_object_table(defines)
    billboard_sets = read_billboard_sets(OBJECTS_PATH)
    symbol_index = build_symbol_index(DATA_ROOT)
    yaml_data_segments = read_yaml_data_segments(YAML_PATH)
    texture_entries = read_yaml_texture_entries(YAML_PATH)
    selected = [entry for entry in objects if object_matches(entry, requested)]
    warnings = []
    output_objects = []
    referenced_textures = {}

    for entry in selected:
        parts = []
        asset_segments = []
        asset_availability = []
        display_lists = list(entry["displayLists"])
        display_lists.extend(SPECIAL_RENDER_EXTRA_DISPLAY_LISTS.get(entry["renderType"], ()))
        for slot, symbol in enumerate(display_lists, start=1):
            if symbol is None:
                continue
            asset_segment = segment_for_symbol(symbol)
            asset_segments.append(asset_segment)
            path = symbol_index.get(symbol)
            if path is None:
                warnings.append(f"object {entry['idToken']} displayList{slot}: unresolved symbol {symbol}")
                continue
            source_key = yaml_data_key_for_path(path)
            source_segment = yaml_data_segments.get(source_key)
            source_availability = classify_yaml_segment(source_segment)
            if source_availability:
                asset_availability.append(source_availability)
            else:
                warnings.append(
                    f"object {entry['idToken']} displayList{slot} {symbol}: no sssv.us.yaml segment for {source_key}"
                )
            scale = entry["scale"]["factor"] / 32.0
            # Runtime object rendering translates display lists to y + height / 2.
            origin_offset = (0.0, (entry["bounds"]["height"] * entry["scale"]["factor"]) / 64.0, 0.0)
            mesh, batches, mesh_warnings = parse_display_list_mesh(
                path,
                textures=texture_entries,
                scale=scale,
                origin_offset=origin_offset,
            )
            warnings.extend(
                f"object {entry['idToken']} displayList{slot} {symbol}: {warning}"
                for warning in mesh_warnings
            )
            for batch in batches:
                texture = batch.get("texture")
                if not texture:
                    continue
                referenced_textures.setdefault(texture["symbol"], texture)
                if not texture.get("url"):
                    warnings.append(
                        f"object {entry['idToken']} displayList{slot} {symbol}: texture {texture['symbol']} has no exported PNG"
                    )
                if texture.get("resolved") is False:
                    warnings.append(
                        f"object {entry['idToken']} displayList{slot} {symbol}: texture {texture['symbol']} not found in sssv.us.yaml"
                    )
            parts.append({
                "slot": slot,
                "displayList": symbol,
                "assetSegment": asset_segment,
                "sourceSegment": source_segment,
                "sourceAvailability": source_availability,
                "source": path.relative_to(REPO_ROOT).as_posix(),
                "originOffset": list(origin_offset),
                "mesh": mesh,
                "batches": batches,
            })
        names = object_names(entry, names_by_id)
        billboard_set = (
            billboard_sets[entry["billboardSetIndex"]]
            if entry["type"] == 8 and 0 <= entry["billboardSetIndex"] < len(billboard_sets)
            else None
        )
        output_objects.append({
            "index": entry["index"],
            "id": entry["id"],
            "name": entry["idToken"] if entry["idToken"] in names else names[0],
            "aliases": names,
            "idToken": entry["idToken"],
            "type": entry["type"],
            "renderType": entry["renderType"],
            "displayLists": [symbol for symbol in display_lists if symbol],
            "billboards": billboard_set["billboards"] if billboard_set else [],
            "billboardSet": {
                "index": billboard_set["index"],
                "symbol": billboard_set["symbol"],
            } if billboard_set else None,
            "availability": object_availability(entry, names_by_id, metadata_by_name, asset_availability),
            "assetSegments": merge_segments(asset_segments),
            "scale": entry["scale"],
            "bounds": entry["bounds"],
            "collisionIndex": entry["collisionIndex"],
            "parts": parts,
        })

    output_animals = export_animals(
        requested,
        symbol_index,
        yaml_data_segments,
        texture_entries,
        warnings,
        referenced_textures,
    )

    data = {
        "version": 1,
        "kind": "objects+animals",
        "coordinateSystem": "three-y-up-from-sssv-xzy-runtime-origin",
        "source": OBJECTS_PATH.relative_to(REPO_ROOT).as_posix(),
        "objectCount": len(output_objects),
        "animalCount": len(output_animals),
        "textures": {
            "referenced": referenced_textures,
            "resolvedCount": sum(1 for item in referenced_textures.values() if item.get("url")),
            "unresolvedCount": sum(1 for item in referenced_textures.values() if not item.get("url")),
        },
        "billboardSets": billboard_sets,
        "objects": output_objects,
        "animals": output_animals,
        "warnings": warnings,
    }

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(data, indent=2) + "\n")
    return data


def main():
    parser = argparse.ArgumentParser(description="Export SSSV object display lists as browser-friendly JSON.")
    parser.add_argument("--object", action="append", default=[], help="Object id or OBJECT_* name. Repeatable.")
    parser.add_argument("--output", default="tools/svle/object_viewer/objects.view.json", type=Path)
    parser.add_argument("--dump-animal-part-stubs", action="store_true", help="Print source-derived animal part dictionaries and exit.")
    args = parser.parse_args()

    if args.dump_animal_part_stubs:
        print(json.dumps(dump_animal_part_stubs(args.object), indent=2))
        return

    data = export_objects(args.object, args.output)
    mesh_count = sum(len(obj["parts"]) for obj in data["objects"])
    animal_mesh_count = sum(len(animal["parts"]) for animal in data.get("animals", []))
    triangle_count = sum(
        part["mesh"]["stats"]["triangles"]
        for obj in data["objects"]
        for part in obj["parts"]
    ) + sum(
        part["mesh"]["stats"]["triangles"]
        for animal in data.get("animals", [])
        for part in animal["parts"]
    )
    print(
        f"Exported {data['objectCount']} objects, {mesh_count} object meshes, "
        f"{data.get('animalCount', 0)} animals, {animal_mesh_count} animal meshes, "
        f"{triangle_count} triangles to {args.output}"
    )
    if data["warnings"]:
        print(f"Warnings: {len(data['warnings'])}")


if __name__ == "__main__":
    main()
