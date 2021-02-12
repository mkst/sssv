import argparse
import sys


def main(infile, outfile, alignment=16, pad=b'\x00'):
    with open(infile, 'rb') as f:
        data = f.read()
    with open(outfile, 'wb') as o:
        maligned_bytes = len(data) % alignment
        if alignment < 2 or maligned_bytes == 0: # no alignment required
            o.write(data)
        else:
            padding = pad * (alignment - maligned_bytes)
            o.write(data + padding)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Pads a file to given alignment with desired padding',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('infile', type=str,
                        help='infile')
    parser.add_argument('outfile', type=str,
                        help='outfile')
    parser.add_argument('--alignment', type=int, default=16,
                        help='alignment to pad to, default 16')
    parser.add_argument('--padding', type=int, default=0,
                        help='padding byte, default 0')
    args = parser.parse_args()
    # dont be dumb
    if args.alignment < 1:
        args.alignment = 1;
    main(args.infile, args.outfile, args.alignment, bytes([args.padding]))
