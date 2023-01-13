import sys
import json


try:
    import numpy as np
except ImportError as err:
    print("Please 'pip install numpy' and try again!")
    sys.exit(1)


TARGET_LAYERS = {
    "unk0": "1.0 0.0 0.0", # red,
    "unk1": "0.0 1.0 0.0", # green,
    "unk2": "0.0 0.0 1.0", # blue,
    "unk3": "1.0 1.0 0.0", # yellow,
    "unk4": "1.0 0.0 1.0", # magenta,
    "unk5": "0.0 1.0 1.0", # cyan,
    "unk6": "0.5 0.5 0.25",
    "unk7": "0.5 0.25 0.75",
}


def sssv_to_vrml(data):
    # maps are a 65 * 97 grid
    HEIGHT = 65
    WIDTH = 97

    layers = np.zeros([len(TARGET_LAYERS), HEIGHT, WIDTH])

    colors = list(TARGET_LAYERS.values())
    target_layers = list(TARGET_LAYERS.keys())
    scale = 8.0

    map_data = data["map"]

    for i, entry in enumerate(map_data):
        for j, target_layer in enumerate(target_layers):
            layers[j][i // WIDTH][i % WIDTH] = entry[target_layer] / scale

    out = []
    out.append("#VRML V2.0 utf8")

    for i in range(layers.shape[0]):
        out.append("Shape {")
        out.append("  appearance Appearance {")
        out.append("    material Material {")
        out.append(f"      diffuseColor {colors[i]}")
        out.append("      transparency 0.25")
        out.append("    }")
        out.append("  }")
        out.append("  geometry ElevationGrid {")
        out.append("  height [")

        # NOTE: flip vertical
        for row in layers[i][::-1]:
            r2s = " ".join([f"{x:.5f}" for x in row])
            out.append("    " + r2s)

        out.append("    ]")
        out.append(f"  xDimension {WIDTH}")
        out.append(f"  zDimension {HEIGHT}")
        out.append("  xSpacing 1.0")
        out.append("  zSpacing 1.0")
        out.append("  }")
        out.append("}")
        out.append("")

    # try to add paths as faces? this is too naive
    paths = data["paf"]
    for path in paths:
        out.append("Shape {")
        out.append("  appearance Appearance {")
        out.append("    material Material {")
        out.append("      diffuseColor 1 .65 0 # orange?")
        out.append("    }")
        out.append("  }")
        out.append("  geometry IndexedFaceSet {")
        out.append("    coord Coordinate {")
        out.append("      point [")
        tmp = []
        for waypoint in path:
            x, z, y = waypoint
            y = y / scale
            tmp.append("        " + " ".join(map(str, [x, y, z])))
        out.append(",\n".join(tmp))
        out.append("      ]")
        out.append("    }")
        out.append("    coordIndex [")
        out.append("      " + ", ".join(map(str, range(len(path)))) + ", -1")
        out.append("    ]")
        out.append("  }")
        out.append("}")
        out.append("")

    return "\n".join(out)


def main():
    with open(sys.argv[1], "r") as f:
        data = json.loads(f.read())

    vrml_text = sssv_to_vrml(data)

    with open(sys.argv[2], "w") as f:
        f.write(vrml_text)


if __name__ == "__main__":
    main()
