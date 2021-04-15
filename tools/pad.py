import argparse


def main(infile, outfile, alignment=16, pad=b'\x00'):
    data = infile.read()
    maligned_bytes = len(data) % alignment
    if alignment < 2 or maligned_bytes == 0: # no alignment required
        outfile.write(data)
    else:
        padding = pad * (alignment - maligned_bytes)
        outfile.write(data + padding)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Pads a file to given alignment with desired padding',
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('infile', type=argparse.FileType('rb'),
                        help='file to read from')
    parser.add_argument('outfile', type=argparse.FileType('wb'),
                        help='file to write to')
    parser.add_argument('--alignment', type=int, default=16,
                        help='alignment to pad to, default 16')
    parser.add_argument('--padding', type=int, default=0,
                        help='padding byte, default 0')
    args = parser.parse_args()
    main(args.infile, args.outfile, max(1, args.alignment), bytes([args.padding]))
