import subprocess

from pathlib import Path
from typing import Optional

from segtypes.n64.segment import N64Segment
from segtypes.n64.rgba16 import N64SegRgba16
from util import options
from util import log

class N64SegRnc(N64Segment):
    def __init__(self, segment, rom_start, rom_end):
        super().__init__(segment, rom_start, rom_end)
        if len(self.args) > 0:
            self.subtype = self.args[0]
            if self.subtype == 'rgba16':
                if len(self.args) < 3:
                    log.error(f'Error: {self.name} is missing width and height parameters')
                self.width = self.args[1]
                self.height = self.args[2]
                # append type to filename
                self.name += '.rgba16'
        else:
            self.subtype = None
        # append .rnc
        self.name += '.rnc'


    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f'{self.name}'

    def split(self, rom_bytes):
        # stage 1: decompression
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        # create path to temporary file
        tmp_path = path.parent / (path.name + '.tmp')
        # write out RNC file
        with open(tmp_path, 'wb') as f:
            f.write(rom_bytes[self.rom_start : self.rom_end])
        # build path to rnc64 binary
        rnc64 = options.get_base_path() / 'tools' / 'rnc_propack_source' / 'rnc64'
        # run rnc64
        args = [rnc64, 'u', tmp_path, path]
        subprocess.run(args, capture_output=True, check=True)
        # remove temporary file
        tmp_path.unlink()
        # stage 2: decoding
        if self.subtype is not None:
            with open(path, 'rb') as infile:
                data = infile.read()
            segment = [0, self.subtype, self.name, *self.args[1:]]
            if self.subtype == 'rgba16':
                seg = N64SegRgba16(segment, 0, len(data))
            else:
                log.error(f'Error: Unsupported subtype: {self.subtype}')
            seg.split(data)
            path.unlink()
