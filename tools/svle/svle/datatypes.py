
# .cob
datatype_0_format = {
    "id": "H",
    "x": "h",
    "z": "h",
    "y": "h",
    "zRotation": "h",
    "angle": "h",
    "unkC": "H",
    "scale": "H",
    "commandReferenceIdx": "h", # referenceId ?
    "unk12": "h",
    "commandsLength": "B",
    "unk15": "B",
}

# .can
datatype_1_format = {
    "id": "h",
    "x": "h",
    "z": "h",
    "y": "h",
    "rotation": "h",
    "health": "h",
    "unkC": "h",
    "unkE": "h",
}

# .joi
datatype_2_format = {
    "unk0": "H",
    "unk2": "H",
    "referenceIdx": "H",
}

# .cmd
# format is dynamic based upon the type...
datatype_4_format = {
    "type": "H",
    "unk2": "h", # id?
    "unk4": "h",
    "unk6": "h",
    "unk8": "h",
}

datatype_4_format_type_24 = {
    "type": "H",
    "id": "H",
    "unk4": "B",
    "unk5": "b",
    "unk6": "B",
    "unk7": "B",
    "unk8": "H",
}

# .rng
datatype_5_format = {
    "unk0": "B",
    "unk1": "B",
    "unk2": "B",
    "unk3": "B",
    "unk4": "B",
    "unk5": "B",
    "alignment": "H",
}

# .paf
# nested data handled separately

# .cha
datatype_7_format = {
    "id": "h",
    "x": "h",
    "z": "h",
    "y": "h",
    "unk8": "h",
    "unkA": "h",
    "unkC": "h",
    "unkE": "h",    # start object?
    "unk10": "h",
    "unk12": "h",
    "unk14": "h",
    "unk16": "h",   # end object?
    "unk18": "b",
    "unk19": "b",
}

# .??? ignored

# level collision/flags
datatype_9_format = {
    "unk0": "B", # floor?
    "unk1": "B", # roofs?
    "unk2": "B",
    "unk3": "B",
    "unk4": "B",
    "unk5": "B",
    "unk6": "B", # water
    "unk7": "B",
}

# level geo

# .mat
datatype_11_format = {
    "unk0": "b",
    "unk1": "b",
    "unk2": "b",
    "unk3": "b",
    "unk4": "b",
    "unk5": "b",
    "unk6": "b",
    "unk7": "b",
    "unk8": "b",
    "unk9": "b",
    "unkA": "b",
    "unkB": "b",
}

# .dat
datatype_12_format = {
    "unk0": "H",         # 0x00
    "unk2": "H",
    "unk4": "H",
    "unk6": "H",
    "unk8": "H",
    "unkA": "H",
    "unkC": "h",
    "unkE": "h",

    "unk10": "H",        # 0x10
    "unk12": "H",
    "unk14": "H",
    "unk16": "H",
    "unk18": "H",
    "startingAnimalId": "H",
    "unk1C": "H",
    "unk1E": "H",

    "segment": "h",      # 0x20
    "unk22": "h",
    "unk24": "h",
    "unk26": "h",
    "unk28": "h",
    "unk2A": "h",
    "unk2C": "h",
    "unk2E": "h",

    "unk30": "h",        # 0x30
    "unk32": "h",
    "unk34": "h",
    "unk36": "h",
    "unk38": "h",
    "unk3A": "h",
    "unk3C": "h",
    "unk3E": "h",

    "unk40": "h",        # 0x40
    "unk42": "h",
    "unk44": "h",
    "unk46": "h",
    "unk48": "h",
    "unk4A": "h",
    "unk4C": "h",
    "unk4E": "h", # rotation?

    "unk50": "h",        # 0x50
    "textureBank": "h",
    "unk54": "B",
    "unk55": "B",
    "unk56": "B",
    "waterPrimaryAlpha": "B",
    "unk58": "B",
    "unk59": "B",
    "unk5A": "B",
    "waterEnvAlpha": "B",
    "unk5C": "b",
    "unk5D": "b",
    "unk5E": "b",
    "unk5F": "b",

    "unk60": "b",        # 0x60
    "unk61": "b",
    "unk62": "b",
    "unk63": "b",
    "unk64": "b",
    "unk65": "b",
    "unk66": "b",
    "unk67": "b",
    "unk68": "b",
    "unk69": "b",
    "unk6A": "b",
    "unk6B": "b",
    "unk6C": "b",
    "unk6D": "b",
    "unk6E": "b",
    "unk6F": "b",

    "unk70": "b",        # 0x70
    "unk71": "b",
    "unk72": "b",
    "unk73": "b",
    "unk74": "b",
    "unk75": "b",
    "unk76": "b",  # lights (dir x)
    "unk77": "b",  # lights (dir y)
    "unk78": "b",  # lights (dir z)
    "unk79": "b",  # tbd
    "unk7A": "h",
    "unk7C": "h",
    "unk7E": "h",

    "unk80": "h",        # 0x80
    "unk82": "h",
    "unk84": "h",
    "unk86": "h",
    "unk88": "h",
    "unk8A": "h",
    "unk8C": "h",
    "unk8E": "h",

    "unk90": "h",
    "unk92": "h",
    "unk94": "h",
    "unk96": "h",
    "unk98": "h",
    "unk9A": "h",
    "unk9C": "h",
    "unk9E": "h",
}

# .cam
datatype_13_format_a = {
    "unk0": "h",
    "unk2": "h",
    "unk4": "h",
    "unk6": "h",
}

datatype_13_format_b = {
    "unk0": "H",
    "unk2": "H",
    "unk4": "H",
    "unk6": "H",
    "unk8": "H",
    "unkA": "H",
    "unkC": "H",
    "unkE": "H",
    "unk10": "H",
    "unk12": "H",
}

# ?
datatype_14_format = {
    "unk0": "I",
    "unk4": "I",
    "unk8": "I",
    "unkC": "I",
}

# ?
datatype_15_format = {
    "unk0": "B",
    "unk1": "B",
    "unk2": "B",
    "unk3": "B",
    "unk4": "B",
    "unk5": "B",
    "unk6": "B",
    "unk7": "B",
}
