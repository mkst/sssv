
# .cob
datatype_0_format = {
    "id": "H",
    "x": "h",
    "z": "h",
    "y": "h",
    "zRotation": "h",
    "angle": "h",
    # Copied onto Entity.unk3E by the game; low bits select contextual object textures.
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
    "xStart": "B",
    "zStart": "B",
    "yStartOrMode": "B",
    "xEnd": "B",
    "zEnd": "B",
    "yEndOrMode": "B",
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
    "fogMin": "H",
    "fogMax": "H",
    "fogRed": "H",
    "fogGreen": "H",
    "fogBlue": "H",
    "nearClip": "h",
    "farClip": "h",

    "waterTileX": "H",    # 0x10
    "waterTileZ": "H",
    "waterTileWidth": "H",
    "waterTileDepth": "H",
    "unk18": "H",
    "startingAnimalId": "H",
    "unk1C": "H",
    "unk1E": "H",

    "segment": "h",      # 0x20
    "waterWaveMode": "h",
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

    "sourceFovY": "h",    # 0x40
    "primDepthOffset": "h",
    "unk44": "h",
    "unk46": "h",
    "unk48": "h",
    "unk4A": "h",
    "waterMode": "h",
    "startHeading": "h",

    "cameraHeading": "h", # 0x50
    "textureBank": "h",
    "waterPrimRed": "B",
    "waterPrimGreen": "B",
    "waterPrimBlue": "B",
    "waterPrimAlpha": "B",
    "waterEnvRed": "B",
    "waterEnvGreen": "B",
    "waterEnvBlue": "B",
    "waterEnvAlpha": "B",
    "cellLightingModes00": "b",
    "cellLightingModes01": "b",
    "cellLightingModes02": "b",
    "cellLightingModes03": "b",

    "cellLightingModes04": "b", # 0x60
    "cellLightingModes05": "b",
    "cellLightingModes10": "b",
    "cellLightingModes11": "b",
    "cellLightingModes12": "b",
    "cellLightingModes13": "b",
    "cellLightingModes14": "b",
    "cellLightingModes15": "b",
    "cellLightingModes20": "b",
    "cellLightingModes21": "b",
    "cellLightingModes22": "b",
    "cellLightingModes23": "b",
    "cellLightingModes24": "b",
    "cellLightingModes25": "b",

    "cellLightingModes30": "b",
    "cellLightingModes31": "b",
    "cellLightingModes32": "b", # 0x70
    "cellLightingModes33": "b",
    "cellLightingModes34": "b",
    "cellLightingModes35": "b",
    "unk74": "b",
    "useDynamicLightDir": "b",
    "lightDirX": "b",
    "lightDirY": "b",
    "lightDirZ": "b",
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
    "xStart": "B",
    "zStart": "B",
    "yStartOrType": "B",
    "xEnd": "B",
    "zEnd": "B",
    "yEnd": "B",
    "mode": "b",
    "visibility": "b",
}

datatype_13_format_b = {
    "unk0": "B",
    "unk1": "B",
    "unk2": "B",
    "unk3": "B",  # alignment
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
