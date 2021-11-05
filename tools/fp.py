import struct
import sys

def main(argv):
    num = int(argv[1], 16)
    i, = struct.unpack(">i", struct.pack(">I", num))
    f, = struct.unpack(">f", struct.pack(">f", 0x10000))
    print (f"FTOFIX32({i * 1.0 / f})")

if __name__ == '__main__':
    main(sys.argv)
