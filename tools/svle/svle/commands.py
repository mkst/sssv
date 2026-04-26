import struct


STATE_BASE = 0x7F7F
SLOT_BASE = 0x7FBF


STATES = {
    0: "animal_tmp_1",
    1: "animal_tmp_2",
    2: "animal_tmp_3",
    3: "scale_2",
    4: "health",
    5: "random",
    6: "x_pos",
    7: "z_pos",
    8: "y_pos",
    9: "scale",
    10: "timer",
    11: "x_vel",
    12: "z_vel",
    13: "y_vel",
    14: "z_rot",
    15: "y_rot",
    16: "target_ref",
    17: "unk163",
    18: "mass",
    19: "score",
    20: "unk3e",
    21: "state",
    22: "timer_direction",
    23: "gravity",
    24: "cont_stick_x",
    25: "cont_stick_y",
    26: "cont_button_a",
    27: "cont_button_b",
    28: "tasks_completed",
    29: "fov",
    30: "temp",
    31: "eeprom_scores_1",
    32: "object_type",
    33: "audio_freq",
    34: "music_volume",
    35: "eeprom_scores_2",
    36: "level_progress",
}

MATH_OPS = {
    0: "noop",
    1: "add",
    2: "subtract",
    3: "multiply",
    4: "divide",
    5: "and",
    6: "or",
    7: "modulo",
    8: "rshift",
    9: "lshift",
}

UNARY_OPS = {
    0: "abs",
    1: "sqrt",
    2: "signum",
    3: "max",
    4: "min",
    5: "bitwise_not",
}

AI_BEHAVIOR_FLAGS = {
    0x001: "can_attack",
    0x002: "avoid_neutral_animals",
    0x004: "can_flee",
    0x008: "herd_or_follow",
    0x010: "collide_with_stationary_objects",
    0x020: "allow_steep_or_ledge_navigation",
    0x040: "dampen_turn_speed",
    0x080: "stronger_turn_damping",
    0x400: "scripted_player_engagement",
}


ENTITY_REFS = {
    0: "self",
    1: "ref_1",
    2: "ref_2",
    3: "ref_3",
    4: "ref_4",
    5: "ref_5",
    6: "ref_6",
    7: "ref_7",
    8: "held_by",
    9: "current_player",
    10: "next_animal_in_region",
    11: "first_animal_in_region",
    12: "primary_ref",
}

COMMAND_NAMES = {
    0x00: "end",
    0x01: "if_goto",
    0x02: "watch_condition",
    0x03: "wait_until",
    0x04: "loop_begin",
    0x05: "loop_end",
    0x06: "delay",
    0x07: "wait",
    0x08: "goto",
    0x09: "stop_script",
    0x0A: "wait_0a",
    0x0B: "set_scale_2",
    0x0C: "set_floor_level",
    0x0D: "set_unk20c_20e_210",
    0x0E: "set_target_script",
    0x0F: "set_state",
    0x10: "spawn_object_relative",
    0x11: "spawn_object_at",
    0x12: "activate_spawned_ref",
    0x13: "delete_or_run_target",
    0x14: "set_target_ref",
    0x15: "set_color_a",
    0x16: "set_color_b",
    0x17: "set_effect_params",
    0x18: "set_trail_or_effect",
    0x19: "move_to",
    0x1A: "move_to_alt",
    0x1B: "move_by",
    0x1C: "move_by_alt",
    0x1D: "set_waypoint",
    0x1E: "set_animal_nav",
    0x1F: "set_nav_state_1f",
    0x20: "set_nav_state_20",
    0x21: "set_region_flag",
    0x22: "clear_region_flag",
    0x23: "set_ai_behavior_flags",
    0x24: "start_timer_and_wait",
    0x25: "set_light",
    0x26: "play_sfx",
    0x27: "set_music_track",
    0x28: "noop",
    0x29: "set_camera_unk1e",
    0x2A: "set_camera_unk1c",
    0x2B: "add_score",
    0x2C: "add_health",
    0x2E: "show_effect",
    0x2F: "set_camera_zoom",
    0x30: "noop_30",
    0x31: "spawn_thing",
    0x32: "rotate",
    0x33: "set_unk3e",
    0x34: "update_waypoint",
    0x35: "set_water_level",
    0x36: "set_scale",
    0x37: "clear_message",
    0x38: "return_true",
    0x39: "teleport_to",
    0x3A: "engage_target",
    0x3B: "clear_watched_conditions",
    0x3C: "stop_movement",
    0x3D: "set_game_state_expr",
    0x3E: "screen_transition",
    0x3F: "set_target_state",
    0x40: "face_or_follow_ref",
    0x41: "level_complete",
    0x42: "hide_ref",
    0x43: "show_ref",
    0x44: "show_message",
    0x45: "special",
    0x46: "set_unk23c",
    0x47: "rumble",
    0x48: "call_script",
    0x49: "return_script",
    0x4A: "set_command_index",
    0x4B: "teleport_by",
    0x4C: "set_camera_point",
    0x4D: "effect_on_target",
    0x4E: "effect_at_offset",
    0x4F: "camera_effect",
    0x50: "camera_path",
    0x51: "engage_player_unused",
    0x52: "set_audio_range",
    0x53: "set_entity_flags",
    0x54: "animal_laugh",
    0x55: "hoppa_choppa_action",
    0x56: "copy_entity_ref",
    0x57: "set_collision_flags",
    0x58: "set_camera_clip",
    0x59: "set_weight_for_it_state",
    0x5A: "clear_camera_effect",
    0x5B: "set_unk164",
    0x5C: "engage_other_unused",
    0x5D: "clear_nav_unused",
    0x5E: "move_by_mode_5",
    0x5F: "spawn_animal_relative",
    0x60: "spawn_animal_at",
    0x61: "move_to_mode_5",
    0x62: "set_player_camera_distance",
    0x63: "do_animal_action",
    0x64: "set_trail_colors",
    0x65: "set_game_state_unary",
}

CONDITION_NAMES = {
    0: "region_contains",
    1: "in_water_or_movement_state",
    2: "state_equals",
    3: "water_above_state",
    4: "collision_state",
    5: "movement_finished",
    6: "entity_active",
    7: "global_flag_7",
    8: "global_flag_8",
    9: "distance_at_least",
    11: "target_nearby",
    14: "global_flag_14",
    15: "rotation_finished",
    16: "in_region",
    17: "lt",
    18: "lte",
    19: "eq",
    20: "gte",
    21: "gt",
    22: "is_entity_kind",
    23: "unk5c_equals",
}


def _state_name(value):
    if value < STATE_BASE:
        return value
    idx = value - STATE_BASE
    if idx in STATES:
        return {"state": STATES[idx], "id": value}
    if value >= SLOT_BASE:
        return {"slot": value - SLOT_BASE, "id": value}
    return {"state": f"unknown_{idx}", "id": value}


def _target_ref(value, region=None):
    ref = ENTITY_REFS.get(value, f"ref_{value}")
    if region is None:
        return ref
    return {"ref": ref, "region": region}


def _expr(value):
    return _state_name(value)


def _binary_expr(left, op, right):
    return {"op": MATH_OPS.get(op, op), "args": [left, right]}


def _decode_condition(payload):
    raw0 = payload[0]
    flags = payload[2]
    region = payload[3]
    object_type = payload[4]
    animal_type = payload[5]
    jump, = struct.unpack(">h", payload[6:8])
    left, right, extra = struct.unpack(">hhh", payload[:6])
    cond_type = raw0 & 0x3F
    decoded = {
        "condition": CONDITION_NAMES.get(cond_type, f"condition_{cond_type}"),
        "invert": bool(raw0 & 0x80),
        "continue_chain": bool(raw0 & 0x40),
    }

    if cond_type in (17, 18, 19, 20, 21):
        decoded["left"] = _expr(left)
        decoded["right"] = _expr(right)
    elif cond_type in (2, 9, 23):
        decoded["value"] = _expr(left)
    elif cond_type in (3,):
        decoded["threshold"] = _expr(left)
        decoded["x"] = object_type
        decoded["z"] = animal_type
    elif cond_type in (0, 4, 11, 22):
        decoded["flags"] = {
            "any": bool(flags & 0x08),
            "object": bool(flags & 0x01),
            "unknown_2": bool(flags & 0x02),
            "current_player_or_region": bool(flags & 0x10),
            "animal": bool(flags & 0x04),
            "animal_type": animal_type if flags & 0x20 else None,
            "object_type": object_type if flags & 0x40 else None,
        }
        decoded["region"] = region
    else:
        decoded["args"] = [left, right, extra]

    if raw0 & 0x40:
        decoded["chain_jump"] = jump

    return decoded


def _decode_ai_behavior_flags(value):
    flags = [name for bit, name in AI_BEHAVIOR_FLAGS.items() if value & bit]
    unknown = value & ~sum(AI_BEHAVIOR_FLAGS)
    decoded = {
        "value": value,
        "flags": flags,
    }
    if unknown:
        decoded["unknown_bits"] = unknown
    return decoded


def _decode_special(args):
    action = args[0]
    names = {
        100: "set_evo_dialog_state_0",
        101: "set_evo_dialog_state_1",
        102: "set_evo_dialog_state_2",
        300: "try_swap_animal",
        400: "set_unk_f6450",
        500: "set_camera_vector",
        600: "enable_camera_vector",
        700: "set_messages_enabled",
        800: "set_message_wait_enabled",
        900: "terminal_background",
        1000: "cos_to_slot",
        1100: "sin_to_slot",
        1200: "set_camera_mode",
        1300: "set_camera_flag_4",
        1400: "reset_camera",
    }
    return {"special": names.get(action, action), "args": args[1:]}


def _decode_payload(cmd_type, payload):
    s = struct.unpack(">hhhh", payload)
    b = struct.unpack(">BBBBBBBB", payload)
    sb = struct.unpack(">BbbbbBB", payload[:7])
    decoded = {"args": list(s)}

    if cmd_type in (0x01, 0x02, 0x03):
        decoded = _decode_condition(payload)
    elif cmd_type in (0x04, 0x06, 0x08, 0x0B, 0x1F, 0x20, 0x21, 0x22, 0x24, 0x29, 0x2A, 0x33, 0x3E, 0x3F, 0x4A, 0x5B, 0x62):
        decoded = {"value": _expr(s[0])}
    elif cmd_type in (0x0C, 0x35):
        decoded = {
            "x_start": b[0] + 4,
            "z_start": b[1] + 8,
            "x_end": b[2],
            "z_end": b[3],
            "value": _expr(s[2]),
        }
    elif cmd_type == 0x0E:
        decoded = {"script": s[0]}
    elif cmd_type == 0x10:
        decoded = {
            "object_id": b[0],
            "offset": {"x": struct.unpack(">b", payload[1:2])[0], "z": struct.unpack(">b", payload[2:3])[0], "y": struct.unpack(">b", payload[3:4])[0]},
            "rotation_offset": {"z": struct.unpack(">b", payload[5:6])[0], "y": struct.unpack(">b", payload[4:5])[0]},
            "speed_y": b[6],
        }
    elif cmd_type in (0x11, 0x60):
        decoded = {"id": b[0], "pos": {"x": s[1], "z": s[2], "y": s[3]}}
    elif cmd_type == 0x14:
        decoded = {"target": _target_ref(s[0], s[1])}
    elif cmd_type in (0x19, 0x1A, 0x39, 0x61):
        decoded = {"pos": {"x": s[0], "z": s[1], "y": s[2]}, "speed": s[3]}
    elif cmd_type in (0x1B, 0x1C, 0x4B, 0x5E):
        decoded = {"offset": {"x": _expr(s[0]), "z": _expr(s[1]), "y": _expr(s[2])}, "speed": _expr(s[3])}
    elif cmd_type == 0x23:
        decoded = {"ai_behavior_flags": _decode_ai_behavior_flags(s[0])}
    elif cmd_type in (0x25,):
        decoded = {"rgb": list(b[:6]), "intensity": _expr(s[3])}
    elif cmd_type == 0x26:
        decoded = {"sfx_id": s[0], "volume": s[1], "pitch": s[2], "at_location": bool(b[6])}
    elif cmd_type == 0x27:
        decoded = {"track": struct.unpack(">b", payload[:1])[0]}
    elif cmd_type in (0x2B, 0x2C, 0x2F):
        decoded = {"value": _expr(s[0]), "mode": s[1]}
    elif cmd_type == 0x32:
        decoded = {"flags": b[0], "duration": b[1], "z_rot": _expr(s[1]), "y_rot": _expr(s[3])}
    elif cmd_type in (0x3A, 0x40, 0x42, 0x43):
        decoded = {"target": _target_ref(s[0]), "arg": s[1]}
    elif cmd_type == 0x3D:
        expr = _expr(s[0])
        high_op = b[7] >> 4
        low_op = b[7] & 0x0F
        if high_op:
            expr = _binary_expr(expr, high_op, _expr(s[1]))
        if low_op:
            expr = _binary_expr(expr, low_op, _expr(s[2]))
        decoded = {"dest": _state_name(STATE_BASE + b[6]), "expr": expr}
    elif cmd_type == 0x44:
        decoded = {"message": s[0], "value": s[1]}
    elif cmd_type == 0x45:
        decoded = _decode_special(list(s))
    elif cmd_type == 0x47:
        decoded = {"duration": _expr(s[0]), "strength": s[1], "decay": b[3], "global": bool(b[4])}
    elif cmd_type == 0x48:
        decoded = {"script": s[0]}
    elif cmd_type == 0x4C:
        decoded = {"index": s[0], "x": _expr(s[1]), "z": _expr(s[2])}
    elif cmd_type in (0x4D, 0x4E, 0x4F):
        decoded = {"effect": list(b)}
    elif cmd_type == 0x56:
        decoded = {"dest_ref": _target_ref(s[0]), "dest_slot": s[1], "source_ref": _target_ref(s[2]), "source_slot": s[3]}
    elif cmd_type == 0x58:
        decoded = {"near": _expr(s[0]), "far": _expr(s[1])}
    elif cmd_type == 0x5F:
        decoded = {
            "animal_id": b[0],
            "offset": {"x": sb[1], "z": sb[2], "y": sb[3]},
            "rotation_offset": {"z": sb[5], "y": sb[4]},
            "speed_y": b[6],
        }
    elif cmd_type == 0x63:
        decoded = {"primary": not bool(s[0]), "arg1": _expr(s[1]), "arg2": _expr(s[2]), "target": _target_ref(s[3])}
    elif cmd_type == 0x64:
        decoded = {"primary_rgb": list(b[:3]), "env_rgb": list(b[3:6])}
    elif cmd_type == 0x65:
        decoded = {"dest": _state_name(STATE_BASE + b[0]), "op": UNARY_OPS.get(b[1], b[1]), "args": [_expr(s[1]), _expr(s[2])]}

    return decoded


def decode_commands(data):
    if len(data) < 2:
        raise ValueError("Command data is too small")

    byte_count, = struct.unpack(">H", data[:2])
    if byte_count != len(data):
        raise ValueError(f"Command byte count {byte_count} does not match {len(data)} bytes")
    if (byte_count - 2) % 10:
        raise ValueError(f"Command payload length {byte_count - 2} is not a multiple of 10")

    commands = []
    for index, ptr in enumerate(range(2, byte_count, 10)):
        entry = data[ptr:ptr + 10]
        cmd_type, = struct.unpack(">H", entry[:2])
        payload = entry[2:]
        command = {
            "index": index,
            "type": cmd_type,
            "op": COMMAND_NAMES.get(cmd_type, f"cmd_{cmd_type:02x}"),
            "raw": entry.hex(),
        }
        command.update(_decode_payload(cmd_type, payload))
        commands.append(command)

    return {
        "byte_count": byte_count,
        "command_count": len(commands),
        "commands": commands,
    }


def encode_commands(value):
    if isinstance(value, (bytes, bytearray)):
        return bytes(value)

    if isinstance(value, list):
        commands = value
    else:
        commands = value["commands"]

    payload = bytearray()
    for command in commands:
        raw = command.get("raw")
        if raw is None:
            raise NotImplementedError("Command encoding currently requires each command to keep its raw bytes")
        entry = bytes.fromhex(raw)
        if len(entry) != 10:
            raise ValueError(f"Command {command.get('index')} raw entry is {len(entry)} bytes, expected 10")
        payload.extend(entry)

    byte_count = len(payload) + 2
    return struct.pack(">H", byte_count) + bytes(payload)



def _command_branch_target(command):
    if command["type"] == 0x08 and isinstance(command.get("value"), int):
        return command["value"] + 1
    if command["type"] in (0x01, 0x03) and "chain_jump" in command:
        return command["chain_jump"] + 1
    return None


def _command_script_target(command):
    if command["type"] in (0x0E, 0x48) and isinstance(command.get("script"), int):
        return command["script"]
    return None


def _collect_level_entry_points(level_data):
    refs = {"objects": [], "animals": []}
    entries = set()

    if not level_data:
        return entries, refs

    for index, obj in enumerate(level_data.get("cob", [])):
        entry = obj.get("commandReferenceIdx")
        if isinstance(entry, int) and entry >= 0:
            entries.add(entry)
            refs["objects"].append({
                "index": index,
                "id": obj.get("id"),
                "entry": entry,
            })

    for index, animal in enumerate(level_data.get("can", [])):
        entry = animal.get("unkC")
        if isinstance(entry, int) and entry >= 0:
            entries.add(entry)
            refs["animals"].append({
                "index": index,
                "id": animal.get("id"),
                "entry": entry,
            })

    return entries, refs


def collect_script_entry_points(decoded, level_data=None):
    commands = decoded["commands"]
    entries, refs = _collect_level_entry_points(level_data)
    entries.add(0)

    references = []
    for command in commands:
        target = _command_script_target(command)
        if target is not None:
            entries.add(target)
            references.append({
                "from": command["index"],
                "kind": command["op"],
                "target": target,
            })

        target = _command_branch_target(command)
        if target is not None:
            entries.add(target)
            references.append({
                "from": command["index"],
                "kind": command["op"],
                "target": target,
            })

    valid_entries = sorted(entry for entry in entries if 0 <= entry < len(commands))
    return valid_entries, {
        "entry_points": valid_entries,
        "references": references,
        "objects": refs["objects"],
        "animals": refs["animals"],
    }


def split_scripts(decoded, level_data=None):
    commands = decoded["commands"]
    entries, refs = collect_script_entry_points(decoded, level_data)
    entry_set = set(entries)
    scripts = []

    terminal_reasons = {
        0x08: "goto",
        0x09: "stop_script",
        0x49: "return_script",
    }
    soft_terminal_reasons = {
        0x00: "end_marker",
        0x0A: "wait_or_pause",
    }

    for entry in entries:
        indices = []
        end_reason = "end_of_commands"
        confidence = "medium"
        i = entry

        while i < len(commands):
            if i != entry and i in entry_set:
                end_reason = "next_entry_point"
                confidence = "medium"
                break

            command = commands[i]
            indices.append(i)

            if command["type"] in terminal_reasons:
                end_reason = terminal_reasons[command["type"]]
                confidence = "high"
                break

            if command["type"] in soft_terminal_reasons:
                end_reason = soft_terminal_reasons[command["type"]]
                confidence = "low"
                break

            i += 1

        scripts.append({
            "name": f"script_{entry:03d}",
            "entry": entry,
            "end": indices[-1] if indices else entry,
            "end_reason": end_reason,
            "confidence": confidence,
            "commands": indices,
        })

    return scripts, refs


def build_command_workspace(data, level_data=None, source=None):
    decoded = decode_commands(data)
    scripts, refs = split_scripts(decoded, level_data)

    return {
        "format": "sssv-cmd-workspace-v1",
        "source": source,
        "byte_count": decoded["byte_count"],
        "command_count": decoded["command_count"],
        "commands": decoded["commands"],
        "scripts": scripts,
        "refs": refs,
    }
