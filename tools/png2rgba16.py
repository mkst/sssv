# with thanks to pmret (https://raw.githubusercontent.com/pmret/papermario/master/tools/build/img/build.py)
import argparse
import png
from itertools import zip_longest
from math import floor

def pack_color(r, g, b, a):
    r = floor(31 * (r / 255))
    g = floor(31 * (g / 255))
    b = floor(31 * (b / 255))

    s = round(a / 0xFF)
    s |= (r & 0x1F) << 11
    s |= (g & 0x1F) << 6
    s |= (b & 0x1F) << 1

    return s

def iter_in_groups(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)

def png2rgba16(infile, outfile):
    img = png.Reader(infile)

    for row in img.asRGBA()[2]:
        for rgba in iter_in_groups(row, 4):
            color = pack_color(*rgba)
            outfile.write(color.to_bytes(2, byteorder='big'))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('infile', help='input file', type=argparse.FileType('rb'))
    parser.add_argument('outfile', help='output file', type=argparse.FileType('wb'))
    args = parser.parse_args()

    png2rgba16(args.infile.name, args.outfile)
