import os
import sys
import struct
import re
import argparse

# Examples:
#
# displaylist with included vtxs
#  python3 tools/dl2ply.py src.us/data/126F70.c out.ply
# displaylist with external vtxs
#  python3 tools/dl2ply.py src/data/6972D0.c out.ply --vtx src/data/D_802EEED0.inc.c
# displaylist with raw vtxs
#  python3 tools/dl2ply.py 51370.c out.ply --vtx assets/50FB0.bin --raw


# Formats info:
# .obj: http://learnwebgl.brown37.net/modelers/obj_data_format.html
# .ply: https://web.archive.org/web/20161204152348/http://www.dcs.ed.ac.uk/teaching/cs4/www/graphics/Web/ply.html


def load_vtx_file(path):
    res = []
    with open(path, 'rb') as f:
        data = f.read()
    vtxs = struct.iter_unpack('>hhhHhhBBBB', data)
    for vtx in vtxs:
        x, y, z, flg, t, c, r, g, b, a = vtx
        res.append((x, y, z, r, g, b))
    return res


def parse_vtx_file(path):
    res = []

    if not os.path.exists(path):
        print("WARNING: Could not find %s" % path)
        return res

    print("Parsing %s" % path)
    with open(path, 'r') as f:
        lines = f.readlines()

    for line in lines:
        if match := re.match(r".*{{{ *(-*[0-9]+), *(-*[0-9]+), *(-*[0-9]+) *}, ([0-9]+), *{ *(-*[0-9]+), *(-*[0-9]+) *}, *{ *(-*[0-9]+), *(-*[0-9]+), *(-*[0-9]+), *(-*[0-9]+) *}}},*", line):
            x, y, z = int(match.group(1)), int(match.group(2)), int(match.group(3))
            # flg = match.group(4)
            # t, c = int(match.group(5)), int(match.group(6))
            r, g, b, a = int(match.group(7)), int(match.group(8)), int(match.group(9)), int(match.group(10))
            res.append((x, y, z, r, g, b))
    return res

# definitions from gbi.h
def tri(v0, v1, v2, flag):
    if flag == 0:
        tri1 = v0, v1, v2
    elif flag == 1:
        tri1 = v1, v2, v0
    else:
        tri1 = v2, v0, v1
    return tri1

def quad(v0, v1, v2, v3, flag):
    if flag == 0:
        tri1 = v0, v1, v2
        tri2 = v0, v2, v3
    elif flag == 1:
        tri1 = v1, v2, v3
        tri2 = v1, v3, v0
    elif flag == 2:
        tri1 = v2, v3, v0
        tri2 = v2, v0, v1
    else:
        tri1 = v3, v0, v1
        tri2 = v3, v1, v2
    return tri1, tri2

def parse_display_list_file(path, include):
    last_offset = 0
    offset = 0
    r = g = b = None
    tris = []
    vtxs = []
    colors = {}

    print("Parsing %s" % path)

    with open(path, 'r') as f:
        lines = f.readlines()
    for line in lines:
        tri1 = tri2 = None
        # single triangle
        if match := re.match(r".*gsSP1Triangle\(([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+)\),", line):
            tri1 = tri(int(match.group(1)), int(match.group(2)), int(match.group(3)), int(match.group(4)))
        # two triangles
        elif match := re.match(r".*gsSP2Triangles\(([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+)\),", line):
            tri1 = tri(int(match.group(1)), int(match.group(2)), int(match.group(3)), int(match.group(4)))
            tri2 = tri(int(match.group(5)), int(match.group(6)), int(match.group(7)), int(match.group(8)))
        # quad
        elif match := re.match(r".*gsSP1Quadrangle\(([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+)\),", line):
            tri1, tri2 = quad(int(match.group(1)), int(match.group(2)), int(match.group(3)), int(match.group(4)), int(match.group(5)))
        # new vertex, so bump our offset
        elif match := re.match(r".*gsSPVertex\(([0-9A-z_]+), ([0-9]+), ([0-9]+)\),", line):
            next_offset = int(match.group(2))
            offset += last_offset
            last_offset = next_offset
        # include decompiled vertexes
        elif match := re.match(r"#include \"(.*\.inc\.c)\"", line):
            vtx_file = match.group(1)
            vtxs += parse_vtx_file(os.path.join(include, vtx_file))
        elif match := re.match(r".*gsDPSetPrimColor\(([0-9]+), ([0-9]+), ([0-9A-Fx]+), ([0-9A-Fx]+), ([0-9A-Fx]+), ([0-9A-Fx]+)\),", line):
            r, g, b = int(match.group(3), 16), int(match.group(4), 16), int(match.group(5), 16)

        if tri1 is not None:
            tri1 = list(map(lambda x: offset + x, tri1))
            if tri2 is not None:
                tri2 = list(map(lambda x: offset + x, tri2))
                tris.append((tri1, tri2))
            else:
                tris.append((tri1,))
            if r is not None:
                for v in tri1:
                    colors[v] = r, g, b
                if tri2 is not None:
                    for v in tri2:
                        colors[v] = r, g, b

    return tris, vtxs, colors


def generate_obj(vtxs, triangles, scale=1/32.0):
    out = []
    out.append("o MyModel")
    for vtx in vtxs:
        x, y, z, r, g, b = vtx
        out.append(f"v {x*scale} {y*scale} {z*scale} {r/255.0} {g/255.0} {b/255.0}")
    # no smoothing
    out.append("s off")
    for tripair in triangles:
        for tri in tripair:
            x, y, z = tri
            # 1-indexing
            out.append(f"f {x+1} {y+1} {z+1}")

    return "\n".join(out)


def generate_ply(vtxs, triangles, colors, scale=1/32.0):
    out = []
    header = []

    tri_count = 0

    for i, vtx in enumerate(vtxs):
        x, y, z, r, g, b = vtx
        if i in colors:
            r, g, b = colors[i]
        out.append(f"{x*scale} {y*scale} {z*scale} {r} {g} {b}")

    for tripair in triangles:
        for tri in tripair:
            x, y, z = tri
            # tris
            out.append(f"3 {x} {y} {z}")
            tri_count += 1

    header.append("ply")
    header.append("format ascii 1.0")
    header.append("comment exported by mkst")
    header.append(f"element vertex {len(vtxs)}")
    header.append("property float x")
    header.append("property float y")
    header.append("property float z")
    header.append("property uchar red")
    header.append("property uchar green")
    header.append("property uchar blue")
    header.append(f"element face {tri_count}")
    header.append("property list uchar int vertex_index")
    header.append("end_header")

    return "\n".join(header + out)


def export_displaylist(dl_file, vtx_file, raw_vtx, fmt, include, no_color):
    tris, vtxs, colors = parse_display_list_file(dl_file, include)

    if no_color:
        colors = {}

    if vtx_file is not None:
        if raw_vtx:
            vtxs += load_vtx_file(vtx_file)
        else:
            vtxs += parse_vtx_file(vtx_file)

    print("Found %i tris (%i vertexes)" % (len(tris), len(vtxs)))
    if fmt == 'ply':
        res = generate_ply(vtxs, tris, colors)
    else:
        res = generate_obj(vtxs, tris)

    return res


if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('infile', help='displaylist file', type=argparse.FileType('r'))
    parser.add_argument('outfile', help='exported model file', type=argparse.FileType('w'))
    parser.add_argument('--vtx', help='vertex file', type=str)
    parser.add_argument('--raw', action='store_true', default=False)
    parser.add_argument('--format', default='ply')
    parser.add_argument('--include', default='src')
    parser.add_argument('--no-color', action='store_true', default=False)

    args = parser.parse_args()

    if args.format not in ('obj', 'ply'):
        print("Error: Unsupported format")
        sys.exit(1)

    res = export_displaylist(args.infile.name, args.vtx, args.raw, args.format, args.include, args.no_color)

    args.outfile.write(res)
